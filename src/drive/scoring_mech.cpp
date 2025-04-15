#include "main.h"
#include "algorithm"
using namespace std;

Scoring_Mech::Scoring_Mech(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp, std::initializer_list<std::int8_t> intake_mtr_grp, int8_t intake_color_sensor_grp) 
    : neutral_stake_mtr(neutral_stake_mtr_grp)
    , neutral_stake_rot(neutral_stake_rot_grp) 
    , intake_mtr(intake_mtr_grp)
    , color_sensor(intake_color_sensor_grp) {}


void Scoring_Mech::initialize() {
    neutral_stake_rot.set_position(36000);
    //neutral_stake_rot.set_position(33000);
    neutral_stake_mtr.move_velocity(0);
    neutral_stake_rot.set_data_rate(5);
    intake_mtr.set_encoder_units_all(pros::v5::MotorUnits::counts);
    intake_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
    color_sensor.set_integration_time(5);
    color_sensor.set_led_pwm(100);
    set_brake_mode('H');
}

void Scoring_Mech::neutral_stake_control() {
    if (master.get_digital(DIGITAL_A) && neutral_stake_position != 3) {
        neutral_stake_mtr.move_velocity(600);
        timeout = 0;
        while (neutral_stake_rot.get_position() > angle_positions[neutral_stake_position + 1] + up_thresholds[neutral_stake_position] and timeout < 3000) {
            pros::delay(5);
            timeout += 5;

        }
        neutral_stake_position++;
        neutral_stake_mtr.move_velocity(0);
        //pros::delay(500);
        //cout << neutral_stake_rot.get_position() << endl;
    } 
    else if (master.get_digital(DIGITAL_Y) && neutral_stake_position != 0) {
        neutral_stake_mtr.move_velocity(-600);
        timeout = 0;
        while (neutral_stake_rot.get_position() < angle_positions[neutral_stake_position - 1] - down_thresholds[neutral_stake_position-1] and timeout < 3000) {
            pros::delay(5);
            timeout += 5;
        }
        neutral_stake_position--;
        neutral_stake_mtr.move_velocity(0);
        //pros::delay(500);
        //cout << neutral_stake_rot.get_position() << endl;

    } 
    else if (master.get_digital(DIGITAL_B) && neutral_stake_position == 1) {
        /*current_outtaking = 1;
        intake_mtr.move_velocity(-200);
        pros::delay(200);
        intake_mtr.move_velocity(0);
        current_outtaking = 0;*/
        neutral_stake_mtr.move_velocity(600);
        while (neutral_stake_rot.get_position() > 26000) {
            pros::delay(5);
        } 
        about_to_score = 1;
    }
    else {
        neutral_stake_mtr.move_velocity(0);
    }
    
}

int Scoring_Mech::neutral_stake_task() {
    while (true) {
        scoring_mech.neutral_stake_control();
        pros::delay(5);
    }
    return 1;
}


void Scoring_Mech::move1(double voltage) {
    neutral_stake_mtr.move_velocity(voltage);
}


void Scoring_Mech::set_brake_mode(char brake_type) {
   if (brake_type == 'H'){
      neutral_stake_mtr.move_velocity(0);
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_HOLD);
   }
   else if (brake_type == 'C'){
      neutral_stake_mtr.move_velocity(0);
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_COAST);
   } else {
      neutral_stake_mtr.move_velocity(0);
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_BRAKE);
   }
}

void Scoring_Mech::set_up() {
    neutral_stake_mtr.move_velocity(600);
    while (neutral_stake_rot.get_position() > angle_positions[1] + up_thresholds[0]) {
        pros::delay(5);
    }
    neutral_stake_mtr.move_velocity(0);
}

void Scoring_Mech::score() {
    neutral_stake_mtr.move_velocity(600);
    while(neutral_stake_rot.get_position() > angle_positions[2] + up_thresholds[1]) {
        pros::delay(5);
    }
    neutral_stake_mtr.move_velocity(0);
}


void Scoring_Mech::intake_control() {
    if (master.get_digital(DIGITAL_L1) && (current_outtaking == 0)){
        intake_mtr.move_velocity(600);
    } else if ((master.get_digital(DIGITAL_L2)) && (current_outtaking == 0)) {
        intake_mtr.move_velocity(-600);
    } else if (current_outtaking == 0){
        intake_mtr.move_velocity(0);
    }
}

int Scoring_Mech::intake_task() {
    while (true) {
        scoring_mech.intake_control();
        pros::delay(10);
    }
    return 1;
}

void Scoring_Mech::intake_move(double velocity) {
    intake_mtr.move_velocity(velocity);
}


// use intake rotations
void Scoring_Mech::red_color_sort() { 
    color_sensor.set_led_pwm(100); 
    pros::delay(500);
    color_sensor.set_integration_time(5);
    int current_rotation = 0;
    while (!driverControl) {
        if ((color_sensor.get_hue() <= 230 and color_sensor.get_hue() >= 210) && (color_sensor.get_saturation() <= 0.8 and color_sensor.get_saturation() >= 0.55) && color_sensor.get_proximity() >= 250) {
            current_rotation = intake_mtr.get_position();
            while (intake_mtr.get_position() - current_rotation < 405) {
                pros::delay(5);
                continue;
            } 
            current_outtaking = 1;
            intake_mtr.move_velocity(0);
            pros::delay(500);
            intake_mtr.move_velocity(600);
            current_outtaking = 0; 
        } 
        pros::delay(5);
    }
}

int Scoring_Mech::red_color_sort_task() {
    scoring_mech.red_color_sort();
    return 1;
}
  
void Scoring_Mech::blue_color_sort() {
    color_sensor.set_led_pwm(100); 
    pros::delay(500);
    color_sensor.set_integration_time(5);
    int current_rotation = 0;
    while (!driverControl) {
        if ((color_sensor.get_hue() <= 10 or color_sensor.get_hue() >= 350) && (color_sensor.get_saturation() >= 0.6) && color_sensor.get_proximity() >= 250) {
            current_rotation = intake_mtr.get_position();
            while (intake_mtr.get_position() - current_rotation < 375) {
                pros::delay(5);
                continue;
            } 
            current_outtaking = 1;
            intake_mtr.move_velocity(0);
            pros::delay(500);
            intake_mtr.move_velocity(600);
            current_outtaking = 0;
        } 
        pros::delay(5);
    }
}

int Scoring_Mech::blue_color_sort_task() {
    scoring_mech.blue_color_sort();
    return 1;
}

/*void Scoring_Mech::neutral_stake_stopper() {
    cout << 108 << endl;
    pros::delay(2000);
    while (true) {
        //cout << neutral_stake_mtr.get_actual_velocity() << endl;
        if (neutral_stake_rot.get_angle() > 34000 || neutral_stake_rot.get_angle() < 1000) {
            //cout << "Hello" << endl;
            //pros::delay(2000);
            if (neutral_stake_mtr.get_actual_velocity() > 0) {
                neutral_stake_mtr.move_velocity(0);
                pros::delay(5);
            } else {
                pros::delay(20);
            }
        }
    }
}

int Scoring_Mech::neutral_stake_stopper_task() {
    scoring_mech.neutral_stake_stopper();
    return 1;
}*/

void Scoring_Mech::intake_detector() {
    int target_velocity;
    while (!driverControl) {
        if (intake_mtr.get_target_velocity() >= 100 && intake_mtr.get_actual_velocity() <= 50) {
            target_velocity = intake_mtr.get_target_velocity();
            intake_mtr.move_velocity(-300);
            pros::delay(100);
            intake_mtr.move_velocity(target_velocity);
            pros::delay(500);
        }
        pros::delay(10);
    }
}

int Scoring_Mech::intake_detector_task() {
    scoring_mech.intake_detector();
    return 1;
}

/*void Scoring_Mech::rush_helper() {
    scoring_mech.move2(400);
    pros::delay(200);
    scoring_mech.intake_move(600);
    pros::delay(200);
    scoring_mech.move2(0);
}

int Scoring_Mech::rush_helper_task() {
    scoring_mech.rush_helper();
    return 1;
}*/

#include "main.h"
#include "algorithm"
using namespace std;

Scoring_Mech::Scoring_Mech(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp, std::initializer_list<std::int8_t> intake_mtr_grp, int8_t intake_color_sensor_grp) 
    : neutral_stake_mtr(neutral_stake_mtr_grp)
    , neutral_stake_rot(neutral_stake_rot_grp) 
    , intake_mtr(intake_mtr_grp)
    , color_sensor(intake_color_sensor_grp) {}

void Scoring_Mech::neutral_stake_control() {
    double LOADING_ANGLE = 32800;
    double LOADING_UP_ANGLE_TRESHOLD = 1200;
    int LOADING_UP_VELOCITY = 100;
    int LOADING_UP_FULL_VELOCITY = 400;
    
    int LOADING_DOWN_ACCURATE_VELOCITY = 100;
    int LOADING_DOWN_FULL_VELOCITY = 600;
    double LOADING_DOWN_ANGLE_TRESHOLD = 1800; 
    double SAFE_ANGLE_DOWN = 27000;
    double DESCORE_ANGLE = 23000;

    if (master.get_digital(DIGITAL_A)) {
        neutral_stake_position = 1;
        int timeout = 0;
        if (neutral_stake_rot.get_angle() > LOADING_ANGLE + LOADING_UP_ANGLE_TRESHOLD 
                || neutral_stake_rot.get_angle() < LOADING_UP_ANGLE_TRESHOLD) {
            timeout = 0;
            while ((neutral_stake_rot.get_angle() > LOADING_ANGLE + LOADING_UP_ANGLE_TRESHOLD 
                    || neutral_stake_rot.get_angle() < LOADING_UP_ANGLE_TRESHOLD)
                    && (timeout < 3000)) {
                neutral_stake_mtr.move_velocity(-LOADING_UP_VELOCITY);
                pros::delay(10);
                timeout += 10;
            }
        } 
        
        else if (neutral_stake_rot.get_angle() < LOADING_ANGLE - LOADING_DOWN_ANGLE_TRESHOLD) {
            timeout = 0;
            while ((neutral_stake_rot.get_angle() < SAFE_ANGLE_DOWN) 
                    && (timeout < 3000)) {
                neutral_stake_mtr.move_velocity(LOADING_DOWN_FULL_VELOCITY);
                pros::delay(10);
                timeout += 10;
            }

            neutral_stake_mtr.move_velocity(0);
            pros::delay(100);
            while (neutral_stake_rot.get_angle() < LOADING_ANGLE - LOADING_DOWN_ANGLE_TRESHOLD
                    && (timeout < 3000)) {
                neutral_stake_mtr.move_velocity(LOADING_DOWN_ACCURATE_VELOCITY);
                pros::delay(10);
                timeout += 10;
            }
        }
    }
    else if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_position == 1){
            current_outtaking = 1;
            //cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(-200);
            pros::delay(180);
            //cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(0);
            pros::delay(100);
            neutral_stake_position = 0;
            current_outtaking = 0;
        }
        neutral_stake_mtr.move_velocity(-400);
    }
    else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(400);
    } 
    else if (master.get_digital(DIGITAL_R2)) {
        if (neutral_stake_position == 1){
            current_outtaking = 1;
            //cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(-200);
            pros::delay(90);
            //cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(0);
            pros::delay(100);
            neutral_stake_position = 0;
            current_outtaking = 0;
        }
        while (neutral_stake_rot.get_angle() > DESCORE_ANGLE 
        || neutral_stake_rot.get_angle() < LOADING_UP_ANGLE_TRESHOLD) {
            neutral_stake_mtr.move_velocity(-LOADING_UP_FULL_VELOCITY);
            pros::delay(10);
        }
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

void Scoring_Mech::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    neutral_stake_position = 0;
    current_outtaking = 0;
    neutral_stake_mtr.move_velocity(0);
    neutral_stake_rot.set_data_rate(5);

    intake_mtr.move_velocity(0);
    intake_mtr.set_zero_position(0);
    intake_mtr.set_encoder_units_all(pros::v5::MotorUnits::counts);
    intake_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    color_sensor.set_integration_time(5);
    driveControl = false;
    //color_sensor(11, 5);
    set_brake_mode('H');
}

void Scoring_Mech::move1() {

}

void Scoring_Mech::move2(double voltage) {
    neutral_stake_mtr.move_velocity(-voltage);
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
    neutral_stake_mtr.move_velocity(0);
    set_brake_mode('H');
}



double Scoring_Mech::neutral_stake_get_speed() {
    return neutral_stake_mtr.get_actual_velocity();
}



void Scoring_Mech::intake_control() {
    //move(0);
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


double Scoring_Mech::intake_get_speed() {
    return intake_mtr.get_actual_velocity();
}

double Scoring_Mech::intake_get_rotation() {
    return intake_mtr.get_position();
}

void Scoring_Mech::intake_move(double velocity) {
    intake_mtr.move_velocity(velocity);
}


// use intake rotations
void Scoring_Mech::red_color_sort() { 
    color_sensor.set_led_pwm(100); 
    color_sensor.set_integration_time(5);
    int current_rotation = 0;
    while (true) {
        while (!driveControl) {
            if ((color_sensor.get_hue() <= 230 and color_sensor.get_hue() >= 210) && (color_sensor.get_saturation() <= 0.8 and color_sensor.get_saturation() >= 0.55) && color_sensor.get_proximity() >= 250) {
                current_rotation = intake_mtr.get_position();
                while (intake_mtr.get_position() - current_rotation < 385) {
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
        pros::delay(20);
    }
}

int Scoring_Mech::red_color_sort_task() {
    scoring_mech.red_color_sort();
    return 1;
}
  
void Scoring_Mech::blue_color_sort() {
    color_sensor.set_led_pwm(100); 
    color_sensor.set_integration_time(5);
    int current_rotation = 0;
    while (true) {
        while (!driveControl) {
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
        pros::delay(20);
    }
}

int Scoring_Mech::blue_color_sort_task() {
    scoring_mech.blue_color_sort();
    return 1;
}

void Scoring_Mech::driveControl_changer() {
    while (true) {
        if (master.get_digital(DIGITAL_UP)) {
            if (scoring_mech.driveControl) {
                cout << 1 << endl;
                scoring_mech.driveControl = false;
            } else {
                cout << 2 << endl;
                scoring_mech.driveControl = true;
            } pros::delay(500);
        }
        pros::delay(20);
    }
}

int Scoring_Mech::driveControl_changer_task() {
    scoring_mech.driveControl_changer();
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

void Scoring_Mech::rush_helper() {
    scoring_mech.move2(400);
    pros::delay(200);
    scoring_mech.intake_move(600);
    pros::delay(200);
    scoring_mech.move2(0);
}

int Scoring_Mech::rush_helper_task() {
    scoring_mech.rush_helper();
    return 1;
}











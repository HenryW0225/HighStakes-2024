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
    double LOADING_DOWN_ANGLE_TRESHOLD = 1600; 
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
            cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(-200);
            pros::delay(90);
            cout << "miving intake motors: " << intake_get_speed() << endl;
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
            cout << "miving intake motors: " << intake_get_speed() << endl;
            intake_mtr.move_velocity(-200);
            pros::delay(90);
            cout << "miving intake motors: " << intake_get_speed() << endl;
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
    intake_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
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
    //int current_rotation = 0;
    while (true) {
        //cout << color_sensor.get_hue() << " " << color_sensor.get_saturation() << " " << color_sensor.get_proximity() << endl;
        //pros::delay(250);

        if ((color_sensor.get_hue() <= 220 and color_sensor.get_hue() >= 215) and (color_sensor.get_saturation() <= 0.7 and color_sensor.get_saturation() >= 0.6) and color_sensor.get_proximity() >= 250) {
            //current_rotation = intake_mtr.get_position();
            //pros::delay(100);
            intake_mtr.move_velocity(8);
            
            while (color_sensor.get_proximity() >= 250) {
                //cout << intake_mtr.get_position() - current_rotation << endl;
                pros::delay(0.1);
                continue;
            }
            intake_mtr.move_velocity(0);
            pros::delay(500);
            intake_mtr.move_velocity(600);
        } 
        pros::delay(1);
    }
}

int Scoring_Mech::red_color_sort_task() {
    scoring_mech.red_color_sort();
    return 1;
}
  
void Scoring_Mech::blue_color_sort() {
    color_sensor.set_led_pwm(100);
    while (true) {
        if ((color_sensor.get_hue() <= 5 or color_sensor.get_hue() >= 350) && (color_sensor.get_saturation() >= 0.6)) {
            pros::delay(71);
            intake_mtr.move_velocity(0);
            pros::delay(300);
            intake_mtr.move_velocity(600);
        } pros::delay(0.1);
    }
}

int Scoring_Mech::blue_color_sort_task() {
    scoring_mech.blue_color_sort();
    return 1;
}













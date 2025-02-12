#include "main.h"
#include "algorithm"
using namespace std;

Neutral_Stake::Neutral_Stake(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp) 
    : neutral_stake_mtr(neutral_stake_mtr_grp)
    , neutral_stake_rot(neutral_stake_rot_grp) {}

void Neutral_Stake::neutral_stake_control() {
    
    double LOADING_ANGLE = 32800;
    double LOADING_UP_ANGLE_TRESHOLD = 1500;
    int LOADING_UP_VELOCITY = 100;
    int LOADING_UP_FULL_VELOCITY = 400;
    
    int LOADING_DOWN_ACCURATE_VELOCITY = 100;
    int LOADING_DOWN_FULL_VELOCITY = 600;
    double LOADING_DOWN_ANGLE_TRESHOLD = 1250; 
    double SAFE_ANGLE_DOWN = 27000;
    double DESCORE_ANGLE = 22000;
    
    if (master.get_digital(DIGITAL_A)) {
        neutral_stake_position = 1;
        cout << "Before: " << neutral_stake_rot.get_angle() << endl;
        if (neutral_stake_rot.get_angle() > LOADING_ANGLE + LOADING_UP_ANGLE_TRESHOLD 
                || neutral_stake_rot.get_angle() < LOADING_UP_ANGLE_TRESHOLD) {
            cout << "Inside Condition 1" << endl; 
            while (neutral_stake_rot.get_angle() > LOADING_ANGLE + LOADING_UP_ANGLE_TRESHOLD 
                    || neutral_stake_rot.get_angle() < LOADING_UP_ANGLE_TRESHOLD) {
                neutral_stake_mtr.move_velocity(-LOADING_UP_VELOCITY);
                pros::delay(10);
            }
            cout << "Loading up: " << neutral_stake_rot.get_angle() << endl;
        }
        else if (neutral_stake_rot.get_angle() <  LOADING_ANGLE - LOADING_DOWN_ANGLE_TRESHOLD) {
            cout << "Inside condition 2" << endl;
            while (neutral_stake_rot.get_angle() < SAFE_ANGLE_DOWN) {
                neutral_stake_mtr.move_velocity(LOADING_DOWN_FULL_VELOCITY);
                pros::delay(10);
            }

            neutral_stake_mtr.move_velocity(0);
            pros::delay(100);
            while (neutral_stake_rot.get_angle() < LOADING_ANGLE - LOADING_DOWN_ANGLE_TRESHOLD) {
                neutral_stake_mtr.move_velocity(LOADING_DOWN_ACCURATE_VELOCITY);
                pros::delay(10);
            }
            
            cout << "Loading down: " << neutral_stake_rot.get_angle() << endl;
        }
    } else if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_position == 1){
            intake.move(-250);
            pros::delay(120);
            intake.move(0);
            pros::delay(100);
            neutral_stake_position = 0;
        }
        neutral_stake_mtr.move_velocity(-400);
        pros::delay(10);
    }
    else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(400);
        pros::delay(10);
    } 
    else if (master.get_digital(DIGITAL_R2)) {
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

void Neutral_Stake::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    neutral_stake_position = 0;
    //neutral_stake_stopper = 0;
    neutral_stake_mtr.move_velocity(0);
    neutral_stake_rot.set_data_rate(5);
    set_brake_mode('H');
    cout << "Initialize: " << neutral_stake_rot.get_angle() << endl;
}

void Neutral_Stake::move1() {
    while (neutral_stake_rot.get_angle() >= 33400 or neutral_stake_rot.get_angle() <= 2000) {
        neutral_stake_mtr.move_velocity(-600);
    } neutral_stake_mtr.move_velocity(0);
}

void Neutral_Stake::move2(double voltage) {
    neutral_stake_mtr.move_velocity(-voltage);
}

void Neutral_Stake::set_brake_mode(char brake_type) {
   if (brake_type == 'H'){
      neutral_stake_mtr.move_velocity(0);
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_HOLD);
   }
   else if (brake_type == 'C'){
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_COAST);
   } else {
      neutral_stake_mtr.set_brake_mode_all(MOTOR_BRAKE_BRAKE);
   }
}

void Neutral_Stake::set_up() {
     while (neutral_stake_rot.get_angle() >= 34200 or neutral_stake_rot.get_angle() <= 2000) {
            neutral_stake_mtr.move_velocity(-600);
    } if (neutral_stake_rot.get_angle() <= 30000) {
        while (neutral_stake_rot.get_angle() <= 31500) {
            neutral_stake_mtr.move_velocity(600);
        } 
    }
    neutral_stake_mtr.move_velocity(0);
    set_brake_mode('H');
}


/*if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_position == 1) {
            intake.move(-120);
            pros::delay(120);
            intake.move(0);
            pros::delay(100);
            neutral_stake_position = 0;
        }
        if (master.get_digital(DIGITAL_R2) and neutral_stake_rot.get_angle() < 21000 and neutral_stake_rot.get_angle() > 5000) {
            neutral_stake_mtr.move_velocity(0);
        } else {
            neutral_stake_mtr.move_velocity(-400);
        }
    }
    else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(400);
    }
    else {
        neutral_stake_mtr.move_velocity(0);
    }


    //int time = 0;
    if (master.get_digital(DIGITAL_A) and (neutral_stake_rot.get_angle() > 34000 or neutral_stake_rot.get_angle() < 5000)) {
        //cout << 1 << endl;
        while (neutral_stake_rot.get_angle() < 5000) {
            neutral_stake_mtr.move_velocity(-100);
        }
        while (neutral_stake_rot.get_angle() > 33750) {
            neutral_stake_mtr.move_velocity(-100);
        }
        neutral_stake_position = 1;
    } 
    
    else if (master.get_digital(DIGITAL_A) and neutral_stake_rot.get_angle() < 32000) {
        while (neutral_stake_rot.get_angle() < 32250) {
            neutral_stake_mtr.move_velocity(100);
        }
        neutral_stake_position = 1;
    }*/




    /*if (master.get_digital(DIGITAL_A) and (neutral_stake_rot.get_angle() > 34000 or neutral_stake_rot.get_angle() < 5000)) {
        while (neutral_stake_rot.get_angle() > 33750) {
            neutral_stake_mtr.move_velocity(-100);
        }
        neutral_stake_position = 1;
        double direction = -1;
        int time = 0;
        double error = 0.16 * abs(33500 - neutral_stake_rot.get_angle()); 
        if (error > 400) {
            error = 400;
        }
        if (neutral_stake_rot.get_angle() < 33500 and neutral_stake_rot.get_angle() > 5000) {
            direction = 1;
        }
        while (abs(neutral_stake_rot.get_angle() - 33500) > 500 and time < 3000) {
            neutral_stake_mtr.move_velocity(direction*error*error*error*error/64000000);
            time += 5;
            pros::delay(5);
        } 
        neutral_stake_position = 0;
    } */
    
    
    /*if (master.get_digital(DIGITAL_R2)) {
        neutral_stake_stopper = 1 - neutral_stake_stopper;
    }
    if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_position == 1) {
            intake.move(-120);
            pros::delay(120);
            intake.move(0);
            pros::delay(65);
            neutral_stake_position = 0;
        } 
        
        if (master.get_digital(DIGITAL_R2) and neutral_stake_rot.get_angle() < 21000 and neutral_stake_rot.get_angle() > 5000) {
            neutral_stake_mtr.move_velocity(0);
        } else {
            neutral_stake_mtr.move_velocity(-400);
        }
        
    } else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(400);
    } else {
        neutral_stake_mtr.move_velocity(0);
    } //int time_limit

    if (master.get_digital(DIGITAL_A)) {
        int time = 0;
        while ((neutral_stake_rot.get_angle() > 33500 or neutral_stake_rot.get_angle() < 2000) and time < 800000) {
            if (neutral_stake_rot.get_angle() < 34200) {
                neutral_stake_mtr.move_velocity(-75);
            } else {
                neutral_stake_mtr.move_velocity(-300);
            } time += 5;
        } time = 0;
        while (neutral_stake_rot.get_angle() < 31500 and time < 800000) {
            if (neutral_stake_rot.get_angle() > 30800) {
                neutral_stake_mtr.move_velocity(75);
            } else {
                neutral_stake_mtr.move_velocity(300);
            } time += 5;
        } 
        neutral_stake_position = 1;
        neutral_stake_mtr.move_velocity(0);
        neutral_stake.set_brake_mode('H');
    }*/

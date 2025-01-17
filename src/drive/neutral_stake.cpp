#include "main.h"

Neutral_Stake::Neutral_Stake(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp) 
    : neutral_stake_mtr(neutral_stake_mtr_grp)
    , neutral_stake_rot(neutral_stake_rot_grp) {}


void Neutral_Stake::neutral_stake_control() {
    if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_rot.get_angle() >= 23000 or neutral_stake_rot.get_angle() <= 2000) {
            if (neutral_stake_position == 1) {
                intake.move(-120);
                pros::delay(45);
                intake.move(0);
                neutral_stake_position = 0;
            }
            neutral_stake_mtr.move_velocity(-600);
        } else {
            neutral_stake_mtr.move_velocity(0);
        }
    } else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(600);
    } else {
        neutral_stake_mtr.move_velocity(0);
    }
    if (master.get_digital(DIGITAL_A)) {
        while (neutral_stake_rot.get_angle() >= 33800 or neutral_stake_rot.get_angle() <= 2000) {
            neutral_stake_mtr.move_velocity(-600);
        } if (neutral_stake_rot.get_angle() <= 30500) {
            while (neutral_stake_rot.get_angle() <= 31800) {
                neutral_stake_mtr.move_velocity(600);
            } 
        }
        neutral_stake_mtr.move_velocity(0);
        set_brake_mode('H');
        
        neutral_stake_position = 1;
        
        /*if (neutral_stake_position == 0) {
            while (neutral_stake_rot.get_angle() <= 3850 or neutral_stake_rot.get_angle() >= 34000) {
                neutral_stake.move(325);
            }
            while (neutral_stake_rot.get_angle() >= 3900) {
                neutral_stake.move(-325);
            } neutral_stake_position = 1;
        } else {
            while (neutral_stake_rot.get_angle() <= 12000) {
                neutral_stake.move(350);
            } neutral_stake_position = 0;
        }*/
    } 
}

void Neutral_Stake::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    neutral_stake_position = 0;
    neutral_stake_mtr.move_velocity(0);
    set_brake_mode('H');
}

void Neutral_Stake::move1() {
    while (neutral_stake_rot.get_angle() >= 20000 or neutral_stake_rot.get_angle() <= 1000) {
        neutral_stake_mtr.move_velocity(-600);
    } neutral_stake_mtr.move_velocity(0);
}

void Neutral_Stake::move2(double voltage) {
    neutral_stake_mtr.move_velocity(voltage);
}

void Neutral_Stake::set_brake_mode(char brake_type) {
   if (brake_type == 'H'){
      neutral_stake_mtr.move_velocity(0);
      neutral_stake_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
   }
   else if (brake_type == 'C'){
      neutral_stake_mtr.set_brake_mode(MOTOR_BRAKE_COAST);
   } else {
      neutral_stake_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
   }
}

/*float Neutral_Stake::get_angle() {
    return neutral_stake_rot.get_angle();
}*/

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


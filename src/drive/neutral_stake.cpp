#include "main.h"

Neutral_Stake::Neutral_Stake(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp) 
    : neutral_stake_mtr(neutral_stake_mtr_grp)
    , neutral_stake_rot(neutral_stake_rot_grp) {}

int target = 0;
bool targetReached = false;

void Neutral_Stake::neutral_stake_control() {
    if (master.get_digital(DIGITAL_B)) {
        if (neutral_stake_position == 1) {
            intake.move(-120);
            pros::delay(140);
            intake.move(0);
            neutral_stake_position = 0;
        }
        neutral_stake_mtr.move_velocity(-600);
    } else if (master.get_digital(DIGITAL_Y)) {
        neutral_stake_mtr.move_velocity(600);
    } else {
        neutral_stake_mtr.move_velocity(0);
    }
    if (master.get_digital(DIGITAL_A)) {
        int settle_time = 0;
int direction = 0;
bool targetReached = false;

const int target_angle = 33500;
const int lower_angle_limit = 2000;
const int max_speed = 500;
const int min_speed = 25;
const int scaling_factor = 2000;
const int settle_threshold = 200;
const int settle_tolerance = 200;
const int additional_direction_speed = 60;

while (!targetReached) {
    int current_angle = neutral_stake_rot.get_angle();

    // Determine direction
    if (current_angle >= target_angle || current_angle < lower_angle_limit) {
        direction = -1;
    } else {
        direction = 1;
    }

    // Calculate speed using a scaled P-loop
    int distance = std::abs(current_angle - target_angle);
    int scaled_speed = std::min(max_speed, std::max(min_speed, distance / scaling_factor));
    int final_speed = direction * (scaled_speed + additional_direction_speed);

    // Debug output for speed
    printf("Speed: %d\n", final_speed);

    // Move the motor with the calculated speed
    neutral_stake_mtr.move_velocity(final_speed);

    // Check if the target angle is within the acceptable range
    if (current_angle < target_angle + settle_tolerance && current_angle > target_angle - settle_tolerance) {
        settle_time += 5;
    } else if (settle_time != 0) {
        settle_time = 0;
    }

    // Mark as target reached if settled for sufficient time
    if (settle_time > settle_threshold) {
        printf("Angle reached: %d\n", current_angle);
        targetReached = true;
    }
}

// Set final position status
neutral_stake_position = 1;
    } 
}

void Neutral_Stake::initialize() {
    neutral_stake_rot.reset_position();
    neutral_stake_rot.reset();
    //neutral_stake_rot.set_integration_time(10);
    neutral_stake_position = 0;
    neutral_stake_mtr.move_velocity(0);
    set_brake_mode('H');
    /*
    pros::Task liftControlTask([]{
        while (true) {
            neutral_stake.liftControl();
            pros::delay(10);
        }
    });
    */
}

void Neutral_Stake::move1() {
    while (neutral_stake_rot.get_angle() >= 20000 or neutral_stake_rot.get_angle() <= 1000) {
        neutral_stake_mtr.move_velocity(-600);
    } neutral_stake_mtr.move_velocity(0);
}   
void Neutral_Stake::move3() {
    while (neutral_stake_rot.get_angle() >= 16600 or neutral_stake_rot.get_angle() <= 1000) {
        neutral_stake_mtr.move_velocity(-600);
    } neutral_stake_mtr.move_velocity(0);
} 

void Neutral_Stake::move2(double voltage) {
    neutral_stake_mtr.move_velocity((-1)*voltage);
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

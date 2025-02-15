#include "main.h"

//Intake::Intake(std::initializer_list<std::int8_t> intake_grp, int8_t color_sensor_grp, pros::adi::DigitalOut color_grp) 
Intake::Intake(std::initializer_list<std::int8_t> intake_grp)
    : intake_mtr(intake_grp) {}
    // color_sensor(color_sensor_grp)
    //, color(color_grp) {}

void Intake::intake_control() {
    move(0);
    if (master.get_digital(DIGITAL_L1)){
        intake_mtr.move_velocity(600);
    } else if (master.get_digital(DIGITAL_L2)) {
        intake_mtr.move_velocity(-600);
    } else {
        intake_mtr.move_velocity(0);
    }
}

int Intake::intake_task() {
    while(1) {
        intake.intake_control();
        pros::delay(10);
    }
    return 1;
}
    

void Intake::initialize() {
    intake_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

float Intake::get_speed() {
    return intake_mtr.get_actual_velocity();
}

void Intake::move(double velocity) {
    intake_mtr.move_velocity(velocity);
}
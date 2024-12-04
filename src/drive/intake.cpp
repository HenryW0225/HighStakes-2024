#include "main.h"

//Intake::Intake(std::initializer_list<std::int8_t> intake_grp, int8_t color_sensor_grp, pros::adi::DigitalOut color_grp) 
Intake::Intake(std::initializer_list<std::int8_t> intake_grp)
    : intake(intake_grp) {}
    // color_sensor(color_sensor_grp)
    //, color(color_grp) {}

//int int_ran = 0;
//int iran = 0;
//int run = 1;

void Intake::intake_control() {
    move(0);
    if (master.get_digital(DIGITAL_L1)){
        intake.move_velocity(600);
    } else if (master.get_digital(DIGITAL_L2)) {
        intake.move_velocity(-600);
    }
}
    /*run = 1;
    if (master.get_digital(DIGITAL_L1)){
        intake.move_velocity(600);
        if (iran == 0) {iran = 1;}
        if (iran == 1) {}
        }
    if (master.get_digital(DIGITAL_L2)){
        intake.move_velocity(-600); 
        }
    if (int_ran == 1){
        int_ran = 0;
        run = 0;
    }
    if (iran == 1){
        run = 0;
    }
    if ((master.get_digital(DIGITAL_L2) && intake.get_actual_velocity() > 5 && intake.get_actual_velocity() < 300 && run == 1)){
        intake.move(-120);
        int_ran = 1;
        pros::delay(50);
    }*/


/*int Intake::color_sort_red() {
    while (true) {
        if (color_sensor.get_hue() <= 270 and color_sensor.get_hue() >= 210) {
            pros::delay(500);
            double speed = intake.get_actual_velocity();
            intake.move_velocity(0);
            pros::delay(150);
            intake.move_velocity(speed);
        } pros::delay(util::DELAY_TIME);
    }
}

int Intake::color_sort_blue() {
     while (true) {
        if (color_sensor.get_hue() <= 30 and color_sensor.get_hue() >= 330) {
            pros::delay(500);
            double speed = intake.get_actual_velocity();
            intake.move_velocity(0);
            pros::delay(150);
            intake.move_velocity(speed);
        } pros::delay(util::DELAY_TIME);
    }
}*/

void Intake::initialize() {
    intake.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

float Intake::get_speed() {
    return intake.get_actual_velocity();
}

void Intake::move(double velocity) {
    intake.move_velocity(velocity);
}
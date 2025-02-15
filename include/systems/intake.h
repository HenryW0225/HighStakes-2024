#include "main.h"

class Intake{
    public:
    pros::MotorGroup intake_mtr;
    //pros::Optical color_sensor;
    Intake(std::initializer_list<std::int8_t> intake_grp);

    void intake_control();
    //int color_sort_red();
    //int color_sort_blue();
    float get_speed();
    void initialize();
    void move(double velocity);

    static int intake_task();

};
#include "main.h"

class Scoring_Mech{
    public:
    bool driveControl = false;
    int neutral_stake_position = 0;
    int current_outtaking = 0;
    pros::MotorGroup neutral_stake_mtr;
    pros::Rotation neutral_stake_rot;
    pros::MotorGroup intake_mtr;
    pros::Optical color_sensor;
    //pros::Optical color_sensor(const std::uint8_t port, double time);
    Scoring_Mech(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp, std::initializer_list<std::int8_t> intake_mtr_grp, int8_t intake_color_sensor_grp);
    
    void initialize();

    void neutral_stake_control();
    void move1();
    void move2(double velocity);
    void set_brake_mode(char brake_type);
    double neutral_stake_get_speed();
    void set_up();

    void intake_control();
    double intake_get_speed();
    double intake_get_rotation();
    void intake_move(double velocity);


    static int neutral_stake_task();
    static int intake_task();
    static int red_color_sort_task();
    void red_color_sort();
    static int blue_color_sort_task();
    void blue_color_sort();
};
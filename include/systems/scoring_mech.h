#include "main.h"

class Scoring_Mech{
    public:
    int neutral_stake_position;
    int current_outtaking;
    int current_intaking;
    pros::MotorGroup neutral_stake_mtr;
    pros::Rotation neutral_stake_rot;
    pros::MotorGroup intake_mtr;
    pros::Optical color_sensor;
    //pros::Optical color_sensor(const std::uint8_t port, double time);
    Scoring_Mech(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp, std::initializer_list<std::int8_t> intake_mtr_grp, int8_t intake_color_sensor_grp);
    
    void initialize();

    void neutral_stake_control();
    int LOADING_ANGLE = 32800;
    int LOADING_UP_ANGLE_TRESHOLD = 950;
    int LOADING_UP_VELOCITY = 100;
    int LOADING_UP_FULL_VELOCITY = 400;
    int ABOVE_POSITIVE_ANGLE = 1000;
    
    int LOADING_DOWN_VELOCITY;
    int LOADING_DOWN_ANGLE_TRESHOLD = 2000; 
    int DESCORE_ANGLE = 22000;

    static int neutral_stake_task();
    void move1();
    void move2(double velocity);
    void move3(int timeout, int velocity);
    void set_brake_mode(char brake_type);
    void set_up();

    void intake_control();
    static int intake_task();
    void intake_move(double velocity);
    bool driverControl;

    static int rush_helper_task();
    void rush_helper();
    static int intake_detector_task();
    void intake_detector();
    static int neutral_stake_stopper_task();
    void neutral_stake_stopper();
    static int red_color_sort_task();
    void red_color_sort();
    static int blue_color_sort_task();
    void blue_color_sort();
};
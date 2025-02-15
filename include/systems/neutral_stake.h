#include "main.h"

class Neutral_Stake{
    public:
    int neutral_stake_position = 0;
    pros::MotorGroup neutral_stake_mtr;
    pros::Rotation neutral_stake_rot;
    Neutral_Stake(std::initializer_list<std::int8_t> neutral_stake_mtr_grp, int8_t neutral_stake_rot_grp);

    void neutral_stake_control();
    void initialize();
    void move1();
    void move2(double velocity);
    void set_brake_mode(char brake_type);
    //float get_angle();
    void set_up();

    static int neutral_stake_task();
};
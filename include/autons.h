#include "main.h"

class Drive;
class Neutral_Stake;
class Intake;
class Pneumatics;

extern Drive chassis;
extern Neutral_Stake neutral_stake;
extern Intake intake;
extern Pneumatics pneumatics;

void default_constants();

void drive_test();
void turn_test();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();

void redLeftQual();
void redRightQual();
void redLeftElim();
void redRightElim();
void blueRightQual();
void blueLeftQual();
void blueRightElim();
void blueLeftElim();
<<<<<<< Updated upstream
void skills();
=======
void skills();
void auton_setup();
void test();
void blueSWPGoal();
>>>>>>> Stashed changes

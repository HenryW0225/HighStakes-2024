#include "main.h"
#include <iostream>


//new stuff
//int color_stop = 0;
//Motor Definitions
pros::adi::DigitalOut clench('A');
pros::adi::DigitalOut climb('F');
pros::adi::DigitalOut doinker('G');
pros::Motor left_front_mtr(-1, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_middle_mtr(-4, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor left_back_mtr(-7, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_front_mtr(20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_middle_mtr(3, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor right_back_mtr(6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
//pros::Motor intake_mtr(-7, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
//pros::Motor neutral_stake_mtr(11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
//pros::Rotation neutral_stake_rot(21);
pros::Optical color_sensor(12);


//Chassis constructor
Drive chassis( 
  //Specify your drive setup below. There are eight options:
  //ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
  TANK_TWO_ROTATION,
  //Left Motors:
  {left_front_mtr.get_port(), left_middle_mtr.get_port(), left_back_mtr.get_port()},
  //Right Motors:
  {right_front_mtr.get_port(), right_middle_mtr.get_port(), right_back_mtr.get_port()},
  //IMU Port:
  18,
  //Wheel diameter (4" omnis are actually closer to 4.125"):
  2.75,
  //External Gear Ratio
  0.75,
  //Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
  360,
  //Remaining inputs are for position tracking
  //If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.
  //If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
  //If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
  5,
  //Input the Forward Tracker diameter (reverse it to make the direction switch):
  -2,
  //Input Forward Tracker center distance (In.) (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
  //For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
  0,
  //Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
  2,
  //Sideways tracker diameter (reverse to make the direction switch):
  2,
  //Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
  2.6
);

Neutral_Stake neutral_stake(
  {17, -10}, 
  9
);

Intake intake(
  {-8}
	//{intake_mtr.get_port(), color_sensor1.get_port(), color1}
);

Pneumatics pneumatics(
	{clench, climb, doinker}
);


void initialize() {
	chassis.initialize();
	intake.initialize();
  neutral_stake.initialize();
	pneumatics.clench_initialize();
	pneumatics.climb_initialize();
  pneumatics.doinker_initialize();
  //pros::Task intake_task(color_sort_red);
  //pros::Task intake_task(color_sort_blue);
  
}

int color_sort_red() {
  color_sensor.set_led_pwm(100);
  while (true) {
    if (color_sensor.get_hue() <= 225 and color_sensor.get_hue() >= 185) {
      pros::delay(87);
      /*while (color_sensor.get_hue() <= 210 and color_sensor.get_hue() >= 195) {
        pros::delay(0.01);
      }*/
      // color_stop = 1;
      intake.move(0);
      pros::delay(400);
      //color_stop = 0;
      intake.move(600);
    } pros::delay(0.1);
  }
}

int color_sort_blue() {
  color_sensor.set_led_pwm(100);
  while (true) {
    if (color_sensor.get_hue() <= 30 or color_sensor.get_hue() >= 335) {
      pros::delay(86);
      /*while (color_sensor.get_hue() <= 210 and color_sensor.get_hue() >= 195) {
        pros::delay(0.01);
      }*/
      // color_stop = 1;
      intake.move(0);
      pros::delay(350);
      //color_stop = 0;
      intake.move(600);
    } pros::delay(1);
  }
}


void disabled() {}

int current_auton_selection = 0;
bool auto_started = false;

void competition_initialize() {
  while(auto_started == false){            //Changing the names below will only change their names on the
    pros::screen::erase();                 //brain screen for auton selection.
    switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
      case 0:
        pros::screen::print(TEXT_LARGE, 50, 50, "RedSWP");
        break;
      case 1:
       pros::screen::print(TEXT_LARGE, 50, 50, "RedBasicQual");
        break;
      case 2:
        pros::screen::print(TEXT_LARGE, 50, 50, "Red Right Elim");
        break;
      case 3:
        pros::screen::print(TEXT_LARGE, 50, 50, "Red Left Elim");
        break;
      case 4:
        pros::screen::print(TEXT_LARGE, 50, 50, "BlueSWP");
        break;
      case 5:
        pros::screen::print(TEXT_LARGE, 50, 50, "BlueBasicQual");
        break;
      case 6:
        pros::screen::print(TEXT_LARGE, 50, 50, "Blue Rigt Elim");
        break;
      case 7:
        pros::screen::print(TEXT_LARGE, 50, 50, "Blue Left Elim");
        break;
      case 8:
        pros::screen::print(TEXT_LARGE, 50, 50, "Skills");
        break;
    }
    if(pros::screen::touch_status().touch_status == TOUCH_PRESSED){
      current_auton_selection ++;
      while(pros::screen::touch_status().touch_status == TOUCH_PRESSED  || pros::screen::touch_status().touch_status == TOUCH_HELD) {pros::delay(10);}
    } else if (current_auton_selection == 9){
      current_auton_selection = 0;
    }
    pros::Task::delay(10);
    }
}
void autonomous() {
  chassis.set_brake_mode('H');
  redRightQual();

  /*auto_started = true;
  chassis.set_brake_mode('H');
  switch(current_auton_selection){  
    case 0:
      redLeftQual(); //This is the default auton, if you don't select from the brain.
      break;        //Change these to be your own auton functions in order to use the auton selector.
    case 1:         //Tap the screen to cycle through autons.
      redRightQual();
      break;
    case 2:
      redRightElim();
      break;
    case 3:
      redLeftElim();
      break;
    case 4:
      blueRightQual(); 
      break;     
    case 5:     
      blueLeftQual();
      break;
    case 6:
      blueRightElim();
      break;
    case 7:
      blueLeftElim();
      break;
    case 8:
      skills();
      break;
 }
 chassis.set_brake_mode('C');*/
}

void opcontrol(void) {
  std::printf("X: %s","hi");
   float x, y, heading;
  std::string x_str, y_str, heading_str;
  chassis.set_brake_mode('C');
  neutral_stake.set_brake_mode('H');
  
  chassis.set_coordinates(0,0,0);
  
  while (1) {
    chassis.arcade_control();
    neutral_stake.neutral_stake_control();
    // if (color_stop == 0) {
    // intake.intake_control();
    //}
    intake.intake_control();
		pneumatics.clench_control();
    pneumatics.doinker_control();
    //pneumatics.climb_control();
    pros::delay(util::DELAY_TIME); 
  }
}

#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(14, 0.6, 0, 0.5, 0);
  chassis.set_heading_constants(2, 0.25, 0, 0, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(14, .225, 0, 1, 0);
  chassis.set_swing_constants(14, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).

  chassis.set_drive_exit_conditions(2, 100, 3500);
  chassis.set_turn_exit_conditions(2.5, 50, 2500);
  chassis.set_swing_exit_conditions(2, 50, 2000);
}

void odom_constants(){
  default_constants();
}

void test() {
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(2000);
  chassis.drive_to_point(0, 96,8,2);
  pros::delay(2500);
  printf("X: %f Y: %f Heading: %f\n", 0-chassis.get_X_position(), 24-chassis.get_Y_position(), chassis.get_absolute_heading());
std::string x_str, y_str, heading_str;
    x_str = std::to_string(chassis.get_X_position());
    y_str = std::to_string(chassis.get_Y_position());
    heading_str = std::to_string(chassis.get_absolute_heading());
    pros::screen::draw_rect(0,0,480,240);
    pros::screen::set_pen(pros::Color::white);
    pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 125, y_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 175, heading_str.c_str()); 
  chassis.turn_to_point(-96,96,0,6);
  chassis.drive_to_point(-96, 96,8,2);
  pros::delay(2500);
  printf("X: %f Y: %f Heading: %f\n", -24-chassis.get_X_position(), 24-chassis.get_Y_position(), chassis.get_absolute_heading());
    x_str = std::to_string(chassis.get_X_position());
    y_str = std::to_string(chassis.get_Y_position());
    heading_str = std::to_string(chassis.get_absolute_heading());
    pros::screen::draw_rect(0,0,480,240);
    pros::screen::set_pen(pros::Color::white);
    pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 125, y_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 175, heading_str.c_str());
  chassis.turn_to_point(-96,0,0,6);
  chassis.drive_to_point(-96, 0, 8,2);
  pros::delay(2500);
    x_str = std::to_string(chassis.get_X_position());
    y_str = std::to_string(chassis.get_Y_position());
    heading_str = std::to_string(chassis.get_absolute_heading());
    pros::screen::draw_rect(0,0,480,240);
    pros::screen::set_pen(pros::Color::white);
    pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 125, y_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 175, heading_str.c_str());
  printf("X: %f Y: %f Heading: %f\n", -24-chassis.get_X_position(), 0-chassis.get_Y_position(), chassis.get_absolute_heading());
  chassis.turn_to_point(0,0,0,6);
  chassis.drive_to_point(0, 0, 8,2);
  pros::delay(2500);
    x_str = std::to_string(chassis.get_X_position());
    y_str = std::to_string(chassis.get_Y_position());
    heading_str = std::to_string(chassis.get_absolute_heading());
    pros::screen::draw_rect(0,0,480,240);
    pros::screen::set_pen(pros::Color::white);
    pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 125, y_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 175, heading_str.c_str());
  printf("X: %f Y: %f Heading: %f\n", 0-chassis.get_X_position(), 0-chassis.get_Y_position(), chassis.get_absolute_heading());
  chassis.turn_to_point(0,96,0,6);
   x_str = std::to_string(chassis.get_X_position());
    y_str = std::to_string(chassis.get_Y_position());
    heading_str = std::to_string(chassis.get_absolute_heading());
    pros::screen::draw_rect(0,0,480,240);
    pros::screen::set_pen(pros::Color::white);
    pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 125, y_str.c_str());
    pros::screen::print(TEXT_LARGE, 50, 175, heading_str.c_str());
  printf("X: %f Y: %f Heading: %f\n", 0-chassis.get_X_position(), 0-chassis.get_Y_position(), chassis.get_absolute_heading());
}

void drive_test(){
  default_constants();
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  default_constants();
  chassis.turn_to_angle(5, 8);
  chassis.turn_to_angle(30, 8);
  chassis.turn_to_angle(90, 8);
  chassis.turn_to_angle(225, 8);
  chassis.turn_to_angle(0, 8);
}

void swing_test(){
  default_constants();
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  default_constants();
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    pros::screen::erase();
    char *text = new char[16];
    std::sprintf(text, "X: %f", chassis.get_X_position());
    pros::screen::print(TEXT_MEDIUM, 0,50, text);
    delete [] text;
    text = new char[16];
    std::sprintf(text, "Y: %f", chassis.get_Y_position());
    pros::screen::print(TEXT_MEDIUM, 0, 70, text);
    delete [] text;
    text = new char[16];
    std::sprintf(text, "Heading: %f", chassis.get_absolute_heading());
    pros::screen::print(TEXT_MEDIUM, 0, 90, text);
  }
}

void tank_odom_test(){
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  
  chassis.turn_to_point(24, 0);
  pros::delay(500);
  chassis.turn_to_point(0, -24);
  pros::delay(500);
  chassis.turn_to_point(-24, 0);
  pros::delay(500);
  chassis.turn_to_point(0, 24);
  pros::delay(500);

  /*pros::delay(4000);
  chassis.drive_to_point(0, 96, 9, 6, 1, 350, 2500);
  pros::delay(150);
  chassis.turn_to_point(-48, 96);
  pros::delay(150);
  chassis.drive_to_point(-48, 96, 9, 6, 1, 350, 1350);*/
  
  chassis.drive_to_point(0, 24);
  pros::delay(100);
  chassis.turn_to_point(24, 24);
  pros::delay(100);
  chassis.drive_to_point(24, 24);
  pros::delay(100);
  chassis.turn_to_point(24, 0);
  pros::delay(100);
  chassis.drive_to_point(24, 0);
  pros::delay(100);
  chassis.turn_to_point(0, 0);
  pros::delay(100);
  chassis.drive_to_point(0, 0);
  pros::delay(100);
  chassis.turn_to_point(0, 24);
  pros::delay(100);
}

void testH() {
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  //pros::delay(100);
  //pneumatics.clench_v(1);
  //pros::delay(500);
  //scoring_mech.intake_move(600);

  chassis.drive_to_point(0, -36, 6, 2);
  pros::delay(500);
  pneumatics.clench_v(1);
  pros::delay(1000);
  chassis.turn_to_point(-24, -36);
  scoring_mech.intake_move(600);
  pros::delay(1500);
  chassis.drive_to_point(-24, -36);
  pros::delay(2500);
  chassis.turn_to_point(24, 0);
  //chassis.drive_with_voltage(-1.5, 1.5);
  /*chassis.drive_to_point(0, 96, 6, 2, 1.5, 100, 3500);
  chassis.turn_to_point(-48, 96, 0, 6);
  chassis.drive_to_point(-48, 96, 6, 2);*/
  /*chassis.turn_to_point(-96, 0, 0, 6);
  chassis.drive_to_point(-96, 0, 6, 0, 2.5, 50, 3500);
  chassis.turn_to_point(0, 0, 0, 6);
  chassis.drive_to_point(0, 0, 6, 0, 2.5, 50, 3500);
  chassis.turn_to_point(0, 96, 0, 6);*/
  /*chassis.drive_to_point(0, 24, 8, 0);
  chassis.turn_to_point(24, 24, 0, 8);
  chassis.drive_to_point(24, 24, 8, 0);
  chassis.turn_to_point(24, 0, 0, 8);
  chassis.drive_to_point(24, 0, 8, 0);
  chassis.turn_to_point(0, 0, 0, 8);
  chassis.drive_to_point(0, 0, 8, 0);
  chassis.turn_to_point(0, 24, 0, 8);*/



  /*chassis.drive_to_point(0, 96, 8, 2, 1.5, 50, 3500);
  chassis.turn_to_point(96, 96, 0, 8, 2, 50, 3500);
  chassis.drive_to_point(96, 96, 8, 2, 1.5, 50, 3500);
  chassis.turn_to_point(96, 0, 0, 8, 2, 50, 3500);
  chassis.drive_to_point(96, 0, 8, 2, 1.5, 50, 3500);
  chassis.turn_to_point(0, 0, 0 , 8, 2, 50, 3500);
  chassis.drive_to_point(0, 0, 8, 2, 1.5, 50, 3500);
  chassis.turn_to_point(0, 96, 0, 8, 2, 50, 3500);*/

  /*chassis.turn_to_point(24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, -24, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(-24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, 24, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, -24, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(-24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, 24, 0, 8);
  pros::delay(500);*/
  /*chassis.turn_to_point(24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, -24, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(-24, 0, 0, 8);
  pros::delay(500);
  chassis.turn_to_point(0, 24, 0, 8);*/




  //chassis.drive_with_voltage(-3, 3);
  
  /*chassis.drive_to_point(0, 7, 6, 0);
  pros::delay(100);
  scoring_mech.move2(600);
  pros::delay(350);
  scoring_mech.move2(0);
  scoring_mech.set_brake_mode('C');
  chassis.drive_to_point(0, -5);*/

  //scoring_mech.intake_move(600);
  //pros::delay(10000);
  //chassis.turn_to_point(24, 0, 0, 11, 2, 50, 1000);
  //chassis.turn_to_point(24, 0);
  //chassis.turn_to_point(24, 0, 0, 11, 2, 50, 1000);
  //chassis.calculate();
  //chassis.drive_to_point(0, 24, 8, 0, 1, 50, 1200);
  //chassis.drive_to_point(0, 96, 8, 0, 1, 50, 3000);
  /*chassis.turn_to_point(-96, 96, 1, 8, 1, 50, 2500);
  chassis.drive_to_point(-96, 96, 8, 0, 1, 50, 2500);
  chassis.turn_to_point(-96, 0, 1, 8, 1, 50, 2500);
  chassis.drive_to_point(-96, 0, 8, 0, 1, 50, 2500);
  chassis.turn_to_point(0, 0, 1, 8, 1, 50, 2500);
  chassis.drive_to_point(0, 0, 8, 0, 1, 50, 2500);*/
  //pros::delay(1000);
  //chassis.drive_to_point(24, 24);
}

void auton_setup() {
  //std::cout << "We are in auton setup" << std::endl;
  //redLeftQual

  //calculate position
  odom_constants();
  chassis.set_brake_mode('C');
  chassis.set_coordinates(0, 0, 0);
  //std::cout << chassis.get_X_position() << " " << chassis.get_Y_position() << " " << chassis.Gyro.get_heading() << std::endl;
  pros::delay(500);
  chassis.calculate();

}

void redLeftQual(){
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  //pros::delay(1750);
  scoring_mech.move1(600);
  pros::delay(410);
  scoring_mech.move1(0);
  //pros::delay(10);
  scoring_mech.set_brake_mode('C');
  //chassis.drive_distance(-12, 10);
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.move1(-600);
  chassis.turn_to_point(15, -36, 0, 12, 1, 50, 650);
  chassis.drive_to_point(2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(350);
  scoring_mech.move1(0);
  chassis.turn_to_point(-23, 31);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-23, 31, 8, 0, 1, 50, 775);
  chassis.turn_to_point(-29, 38, 0, 14, 1, 50, 600);
  chassis.drive_to_point(-29, 38, 14, 0, 1, 100, 700);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-26, 22, 0, 14, 1, 50, 700);
  pros::delay(250);
  chassis.drive_to_point(-26, 22, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-28, -7, 0, 14, 1, 50, 675);
  pros::delay(100);
  chassis.drive_to_point(-28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(-48, -22, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(-35, -14);
  chassis.drive_to_point(-40.5, -29.5, 5, 0);
  pros::delay(350);
  chassis.drive_to_point(-23.5, -2.5, 10, 0, 1, 50, 400);
  pros::delay(150);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(12, 36, 1, 10, 1, 50, 1000);
  scoring_mech.intake_move(600);
  pros::delay(150);
  scoring_mech.move1(60);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(12, 36, 7, 0, 1, 50, 1500);
 
}

void redRightQual(){
  odom_constants();
  chassis.set_coordinates(-11, -14.5, 239);
  pros::delay(1500);
  scoring_mech.move1(600);
  pros::delay(410);
  scoring_mech.move1(0);
  //pros::delay(10);
  scoring_mech.set_brake_mode('C');
  chassis.drive_distance(-12, 10);
  chassis.drive_to_point(-5.9, -12, 13, 0, 1, 50, 450);
  chassis.turn_to_point(-14.5, -36, 0, 12, 1, 50, 660);
  chassis.drive_to_point(-2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(75);
  scoring_mech.move1(-600);
  pros::delay(300);
  chassis.turn_to_point(26, 22, 1, 10, 1, 50, 800);
  scoring_mech.move1(0);
  scoring_mech.intake_move(-300);
  pros::delay(200);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(26, 22, 8, 0, 1, 50, 500);
  chassis.turn_to_point(28, -7, 0, 14, 1, 50, 675);
  pros::delay(50);
  chassis.drive_to_point(28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(48, -28.5, 0, 14, 1, 50, 575);
  chassis.set_drive_exit_conditions(1, 50, 900);
  pros::delay(25);
  chassis.drive_to_point(35, -19.5);
  chassis.drive_to_point(42, -25.5, 5, 0);
  pros::delay(300);
  /*chassis.drive_to_point(34, -14);
  pros::delay(200);
  chassis.drive_to_point(38.5, -19, 4, 0);
  pros::delay(200);
  chassis.drive_to_point(34, -14);
  pros::delay(600);
  chassis.drive_to_point(38.5, -19, 4, 0);
  pros::delay(200);*/
  chassis.drive_to_point(23.5, -2.5, 10, 0, 1, 50, 400);
  pros::delay(50);
  scoring_mech.intake_move(15);
  chassis.turn_to_point(-12, 36, 1, 10, 1, 50, 1100);
  scoring_mech.intake_move(600);
  pros::delay(400);
  scoring_mech.move1(60);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-12, 36, 7, 0, 1, 50, 1250);
}

void redLeftElim(){
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move1(600);
  pros::delay(600);
  scoring_mech.move1(0);
  scoring_mech.set_brake_mode('C');
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.move1(-600);
  chassis.turn_to_point(13.5, -36, 0, 12, 1, 50, 650);
  chassis.drive_to_point(2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  scoring_mech.move1(0);
  chassis.turn_to_point(-25, 30.5);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-25, 30.5, 8, 0, 1, 50, 775);
  chassis.turn_to_point(-32, 37.5, 0, 14, 1, 50, 600);
  pros::delay(50);
  chassis.drive_to_point(-32, 37.5, 14, 0, 1, 100, 700);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-26, 22, 0, 14, 1, 50, 700);
  pros::delay(200);
  chassis.drive_to_point(-26, 22, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-28, -7, 0, 14, 1, 50, 675);
  pros::delay(50);
  chassis.drive_to_point(-28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(-48, -24, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(-35, -13);
  chassis.drive_to_point(-40.5, -17, 5, 0);
  pros::delay(250);
  chassis.drive_to_point(-23.5, -2.5, 10, 0, 1, 50, 400);
  scoring_mech.intake_move(25);
  chassis.turn_to_point(12, 0, 1, 10, 1, 50, 1000);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(12, 0, 14, 0, 1, 50, 700);
  chassis.turn_to_point(21, 0, 1, 14, 1, 50, 600);
  chassis.drive_to_point(21, 0, 3.5, 0, 1, 50, 650);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(72, 0, 7, 0);
}


void redRightElim(){
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, 96, 14, 2);
  chassis.turn_to_point(96, 96, 0, 14);
  chassis.drive_to_point(96, 96, 14, 2);
  chassis.drive_to_point(0, 96, 14, 2);
  chassis.turn_to_point(0, 192, 0, 14);
  chassis.drive_to_point(0, 0, 14, 2);
  //pros::Task rush_task(Scoring_Mech::rush_helper);
  chassis.drive_distance(25);
}


void blueRightQual(){
  odom_constants();
  chassis.set_coordinates(-11, -14.5, 239);
  scoring_mech.move1(600);
  pros::delay(410);
  scoring_mech.move1(0);
  //pros::delay(10);
  scoring_mech.set_brake_mode('C');
  chassis.drive_to_point(-5.9, -12, 13, 0, 1, 50, 500);
  scoring_mech.move1(-600);
  chassis.turn_to_point(-14.5, -36, 0, 12, 1, 50, 660);
  chassis.drive_to_point(-2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(350);
  scoring_mech.move1(0);
  chassis.turn_to_point(25.5, 29);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(25.5, 29, 8, 0, 1, 50, 775);
  chassis.turn_to_point(29, 35, 0, 14, 1, 50, 600);
  chassis.drive_to_point(29, 35, 14, 0, 1, 100, 700);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(26, 22, 0, 14, 1, 50, 700);
  scoring_mech.intake_move(-300);
  pros::delay(225);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(26, 22, 14, 0, 1, 50, 500);

  /*
  pros::delay(1000);
  chassis.turn_to_point(-24, 24);
  chassis.drive_to_point(-24, 24);
  scoring_mech.move2(100);
  */
  chassis.turn_to_point(28, -7, 0, 14, 1, 50, 675);
  pros::delay(100);
  chassis.drive_to_point(28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(48, -27, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(35, -17);
  chassis.drive_to_point(40.5, -23, 5, 0);
  pros::delay(400);
  chassis.drive_to_point(23.5, -2.5, 10, 0, 1, 50, 400);
  pros::delay(100);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-12, 36, 1, 10, 1, 50, 1050);
  scoring_mech.intake_move(600);
  pros::delay(300);
  scoring_mech.move1(60);
  chassis.drive_to_point(-12, 36, 7, 0, 1, 50, 1500);
}


void blueLeftQual() {
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move1(600);
  pros::delay(410);
  scoring_mech.move1(0);
  //pros::delay(10);
  scoring_mech.set_brake_mode('C');
  chassis.drive_distance(-12, 10);
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  chassis.turn_to_point(11, -36, 0, 12, 1, 50, 500);
  chassis.drive_to_point(2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(125);
  scoring_mech.move1(-600);
  pros::delay(650);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  pros::delay(100);
  chassis.turn_to_point(-24, 20, 1, 10, 1, 200, 800);
  chassis.drive_to_point(-24, 20, 8, 0, 1, 50, 750);
  chassis.turn_to_point(-28, -7, 0, 14, 1, 50, 750);
  pros::delay(300);
  //scoring_mech.intake_move(-300);
  //pros::delay(100);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(-28, -7, 14, 0, 1, 50, 750);
  chassis.turn_to_point(-48, -25, 0, 14, 1, 50, 550);
  pros::delay(75);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(-35, -13);
  chassis.drive_to_point(-41, -18.5, 5, 0, 1, 50, 1000);
  pros::delay(800);
  chassis.drive_to_point(-23.5, -2.5, 10, 0, 1, 50, 400);
  scoring_mech.intake_move(600);
  pros::delay(400);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(0, 24);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(0, 24);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24, 5, 0, 1, 50, 1200);
  scoring_mech.move1(150);
}


void blueRightElim(){
  odom_constants();
  chassis.set_coordinates(-11, -14.5, 239);
  scoring_mech.move1(600);
  pros::delay(410);
  scoring_mech.move1(0);
  //pros::delay(10);
  scoring_mech.set_brake_mode('C');
  chassis.drive_to_point(-5.9, -12, 13, 0, 1, 50, 475);
  scoring_mech.move1(-600);
  chassis.turn_to_point(-15, -36, 0, 12, 1, 50, 675);
  chassis.drive_to_point(-2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(300);
  scoring_mech.move1(0);
  chassis.turn_to_point(25.5, 29);
  scoring_mech.intake_move(550);
  chassis.drive_to_point(25.5, 29, 8, 0, 1, 50, 775);
  chassis.turn_to_point(32, 36.5, 0, 14, 1, 50, 600);
  chassis.drive_to_point(32, 36.5, 14, 0, 1, 100, 700);
  scoring_mech.intake_move(25);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(27.5, 24, 1, 9, 1, 50, 400);
  scoring_mech.intake_move(550);
  pros::delay(300);
  scoring_mech.intake_move(-600);
  pros::delay(50);
  scoring_mech.intake_move(550);
  chassis.drive_to_point(27.5, 24, 10, 0, 1, 50, 450);

  /*
  pros::delay(1000);
  chassis.turn_to_point(-24, 24);
  chassis.drive_to_point(-24, 24);
  scoring_mech.move2(100);
  */
  chassis.turn_to_point(28, -7, 0, 14, 1, 50, 675);
  pros::delay(100);
  chassis.drive_to_point(28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(48, -27, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(35, -16);
  chassis.drive_to_point(40.5, -20, 6, 0);
  pros::delay(200);
  chassis.drive_to_point(23.5, -2.5, 10, 0, 1, 50, 400);
  scoring_mech.intake_move(25);
  chassis.turn_to_point(-12, 0, 1, 10, 1, 50, 1000);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-12, 0, 14, 0, 1, 50, 700);
  chassis.turn_to_point(-21, 0, 1, 14, 1, 50, 600);
  chassis.drive_to_point(-21, 0, 5, 0, 1, 50, 700);
  pros::delay(350);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-72, 0, 7, 0);

}



void blueLeftElim() {

  odom_constants();
  chassis.set_coordinates(0, 7.5, 0);
  pros::delay(100);
  chassis.drive_to_point(0, -24, 5, 0, 1, 200, 1200);
  pros::delay(100);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(24, -24);
  scoring_mech.intake_move(600);
  pros::delay(200);
  chassis.drive_to_point(24, -24);
  pros::delay(400);
  chassis.drive_to_point(15, -24);
  pneumatics.clench_v(0);
  pros::delay(50);
  scoring_mech.move1(54);
  pros::delay(350);
  scoring_mech.move1(0);
  pros::delay(100);
  chassis.drive_to_point(24, -24, 13, 0, 1, 200, 500);
  chassis.turn_to_point(24, 0, 0, 13, 1, 200, 700);
  scoring_mech.intake_move(-100);
  chassis.drive_to_point(24, 0);
  chassis.turn_to_point(48, 24);
  scoring_mech.intake_move(200);
  chassis.drive_to_point(48, 24, 5.5, 0, 1, 200, 1500);
  pros::delay(200);
  chassis.turn_to_point(24, 0, 0, 10);
  chassis.drive_to_point(24, -36, 10, 0);
  chassis.turn_to_point(42, -42, 0, 6);
  chassis.drive_to_point(39.5, -39.5, 4, 0, 1, 200, 1200);
  scoring_mech.intake_move(-180);
  pros::delay(180);
  scoring_mech.intake_move(0);
  pros::delay(100);
  while (scoring_mech.neutral_stake_rot.get_angle() > 23000) {
    scoring_mech.move1(70);
  }
  scoring_mech.move1(0);
}


void skills() {
  /*odom_constants();
  chassis.set_brake_mode(MOTOR_BRAKE_COAST);
  chassis.drive_timeout = 800;
  chassis.turn_timeout = 680;
  chassis.drive_max_voltage = 14;
  chassis.turn_max_voltage = 13;
  chassis.drive_settle_time = 65;
  chassis.turn_settle_time = 56;

  chassis.set_coordinates(0, -61, 0); //the middle of the field is 0,0
  scoring_mech.intake_move(600);
  pros::delay(250);
  scoring_mech.intake_move(0);
  chassis.drive_timeout = 500;
  chassis.drive_to_point(0, -56);
  chassis.drive_timeout = 800;
  chassis.turn_to_point(-23, -64);
  chassis.drive_to_point(23, -48, 8, 0);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(24, -31);
  scoring_mech.intake_move(550);
  chassis.drive_to_point(24,-31);
  pros::delay(10);
  chassis.turn_to_point(48.5, 22);
  scoring_mech.move1();
  scoring_mech.move1();
  chassis.drive_to_point(48.5, 23, 10, 0, 1, 50, 1000);  //std::cout << chassis.get_X_position() << chassis.get_Y_position() << std::endl;
  pros::delay(150);
  chassis.turn_to_angle(13);
  //chassis.drive_to_point(40.5, 0, 13, 1, 1, 100, 1000);
  chassis.drive_distance(-21);
  pros::delay(50);
  scoring_mech.move1(0); 
  scoring_mech.intake_move(-600); 
  pros::delay(150);
  scoring_mech.intake_move(0); //move intake back
  scoring_mech.move1(35);
  chassis.turn_to_point(72, -1, 0, 10, 1, 75, 1000);
  scoring_mech.intake_move(550); 
  scoring_mech.move1(0);//move the neutral stake up slightly
  chassis.drive_to_point(61, 0, 8, 0, 1, 75, 1000);
  scoring_mech.move1(600); 
  scoring_mech.move1(600,600 ); scoring_mech.move1(0);
  scoring_mech.move2(-600); pros::delay(150);
  chassis.drive_to_point(49 , 0, 13, 0);
  pros::delay(20);
  chassis.turn_to_point(49, -48);
  chassis.drive_to_point(49, -48, 8, 0.5, 1, 50, 1000);
  scoring_mech.move2(0);
  pros::delay(50);
  chassis.drive_to_point(49, -63, 6, 0.75);
  pros::delay(50);
  chassis.turn_to_point(66, -50);
  chassis.drive_to_point(66, -50);
  scoring_mech.move2(0);
  pros::delay(25);
  chassis.turn_to_point(47, 0);
  scoring_mech.intake_move(0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(60, -60);
  pros::delay(25);

  chassis.drive_distance(10);
  chassis.turn_to_point(-10, -48);
  chassis.drive_to_point(-10, -48, 9, 0, 1, 75, 1100);
  pros::delay(50);
  chassis.turn_to_point(24, -52, 0, 8, 1, 100, 1200);
  
  chassis.drive_to_point(-24, -48, 7, 0);
  pros::delay(50);
  pneumatics.clench_v(1);
  chassis.set_coordinates(-27, -52, chassis.get_absolute_heading());
  pros::delay(50);

  scoring_mech.intake_move(550);
  chassis.turn_to_point(-25, -32, 0, 10, 1, 75, 900);
  chassis.drive_to_point(-25,-32);
  pros::delay(50);
  chassis.turn_to_point(-48, 24);
  scoring_mech.move1();
  
  chassis.drive_to_point(-48, 24, 9, 0, 1, 50, 1100);
  pros::delay(150);
  chassis.turn_to_angle(350);
  chassis.drive_distance(-22);
  pros::delay(50);
  scoring_mech.move2(0); 
  scoring_mech.intake_move(-600); 

  pros::delay(150);
  scoring_mech.intake_move(0); //move intake back
  scoring_mech.move2(30);
  chassis.turn_to_point(-72, 1, 0, 10, 1, 75, 900);
  scoring_mech.intake_move(550); 
  scoring_mech.move2(0);//move the neutral stake up slightly
  chassis.drive_to_point(-61, 0, 7, 0);
  scoring_mech.move2(600); scoring_mech.move3(600, 450); 
  scoring_mech.move2(0);
  
  scoring_mech.move2(-600); pros::delay(100);
  chassis.drive_to_point(-47.5, 0, 13, 0);
  pros::delay(10);
  chassis.turn_to_point(-48.5, -24, 0, 8);
  chassis.drive_to_point(-47.5, -48, 8, 0, 1, 50, 900);
  scoring_mech.move2(0);
  pros::delay(25);
  chassis.drive_to_point(-47.5, -63, 6, 1);
  pros::delay(20);
  chassis.turn_to_point(-62, -54);
  pros::delay(10);
  chassis.drive_to_point(-62, -54);
  scoring_mech.move2(0);
  pros::delay(25);
  chassis.turn_to_point(-24, 0, 0, 10, 1, 25, 800);
  pneumatics.clench_v(0);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(-62, -62);
  
  chassis.drive_distance(8, 13, 1, 50, 650, 0.713, 0, 0.45, 0);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(0, -5, 0, 8, 1, 70, 600);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(0, -5, 7, 0, 1, 75, 1500);
  chassis.drive_to_point(15, 15, 7, 0, 1, 25, 575);
  pros::delay(10);
  scoring_mech.intake_move(100);
  chassis.drive_to_point(26, 26, 6, 0);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(71, 0, 1, 12, 1, 75, 800);
  chassis.drive_to_point(-1, 49, 7, 0, 1, 75, 1000);
  chassis.drive_distance(-4);
  pros::delay(20);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(550);
  pros::delay(150);
  chassis.turn_to_point(-16, 29);
  chassis.drive_to_point(-24, 29);
  chassis.set_coordinates(-20, 29, chassis.get_absolute_heading());
  pros::delay(30);

  chassis.turn_to_point(-48, 43);
  pros::delay(10);
  chassis.drive_to_point(-44, 34);
  pros::delay(30);
  chassis.turn_to_point(-47, 58);
  chassis.drive_to_point(-47, 53);
  pros::delay(30);
  /*chassis.turn_to_point(-62, 50);
  chassis.drive_to_point(-60, 50);
  chassis.turn_to_point(-72, 72, 0, 12, 1, 50, 375);
  scoring_mech.intake_move(-30);
  chassis.drive_distance(-5);
  chassis.turn_to_point(-62, 50);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-62, 50);
  pros::delay(130);
  chassis.drive_distance(-3);
  chassis.turn_to_angle(172);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-58, 58);
  scoring_mech.intake_move(0);
  chassis.drive_distance(29);

  chassis.turn_to_point(30, 58);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(30, 58, 10, 0, 1, 75, 1100);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(72,72);
  scoring_mech.move2(38);
  pros::delay(50);
  chassis.drive_to_point(71, 62, 16, 0, 1, 75, 1100);
  scoring_mech.intake_move(-200);
  chassis.drive_distance(-3);
  chassis.turn_to_angle(42, 12);
  scoring_mech.move2(0);
  chassis.drive_distance(-40);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(0, 0, 4.5, 0, 1, 25, 1300);
  chassis.drive_distance(4, 8);
  scoring_mech.move2(-200);*/
}



void blueSWPGoal(){
  chassis.drive_to_point(0, 8, 14, 0, 1, 200, 500);
  //scoring_mech.intake_move(400);
  chassis.drive_to_point(0, 18, 14, 0, 1, 200, 500);
  pros::delay(500);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-60, 40, 0, 14, 1, 500, 700);
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-24, 24, 14, 0, 1, 500, 700);
  pros::delay(100);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(600);
  pros::delay(1000);
  chassis.turn_to_point(-48, 20, 0, 14, 1, 500, 700);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-48, 20, 14, 0, 1, 500, 700);
  pros::delay(600);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-40, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-48, 41, 14, 0, 1, 500, 700);
  pneumatics.clench_v(1);
  pros::delay(400);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-48, 14, 14, 0, 1, 500, 700);
  pneumatics.clench_v(0);
  pros::delay(200);
  chassis.turn_to_point(45,-20, 0, 14, 1, 500, 700);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(45,-20, 14, 0, 1, 500, 700);
  chassis.turn_to_point(40,29);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(40,29, 14, 0);
  pros::delay(500);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(100,20);
  chassis.drive_to_point(24,26);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(0,48);
}
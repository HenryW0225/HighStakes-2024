#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(14, 0.6, 0, 0.5, 0);
  chassis.set_heading_constants(2, .05, 0, 10, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(14, .25, 0, 1, 0);
  chassis.set_swing_constants(14, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 100, 1250);
  chassis.set_turn_exit_conditions(2.5, 50, 1250);
  chassis.set_swing_exit_conditions(2, 50, 2000);
}

void odom_constants(){
  default_constants();
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

void test() {
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(100);
  chassis.drive_to_point(0, -36, 6, 2);
  pros::delay(500);
  pneumatics.clench_v(1);
  pros::delay(1000);
  chassis.turn_to_point(24, -36);
  scoring_mech.intake_move(600);
  pros::delay(1500);
  chassis.drive_to_point(24, -36);
  pros::delay(2500);
  chassis.turn_to_point(-24, 0);
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



  /*chassis.drive_to_point(0, 96, 8, 0, 2, 50, 3500);
  chassis.turn_to_point(96, 96, 0, 8, 2, 50, 3500);
  chassis.drive_to_point(96, 96, 8, 0, 2, 50, 3500);
  chassis.turn_to_point(96, 0, 0, 8, 2, 50, 3500);
  chassis.drive_to_point(96, 0, 8, 0, 2, 50, 3500);
  chassis.turn_to_point(0, 0, 0 , 8, 2, 50, 3500);
  chassis.drive_to_point(0, 0, 8, 0, 2, 50, 3500);
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

  //color sort testing
  /*pneumatics.clench_v(1);
  pros::delay(2000);
  scoring_mech.intake_move(600);*/

  //scoring in corner
  /*odom_constants();
  chassis.set_coordinates(-24, 0, 225);
  pneumatics.clench_v(1);
  pros::delay(500);
  scoring_mech.intake_move(600);
  chassis.set_drive_exit_conditions(1, 200, 750);
  chassis.drive_to_point(-33, -9, 12, 0);
  chassis.drive_to_point(-40, -16, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-33, -9, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-40, -16, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-33, -9, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-40, -16, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-33, -9, 7, 0);
  pros::delay(250);*/

  //SWP
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(11, -3, 0, 6, 1, 500, 1000);
  pros::delay(1000);
  chassis.drive_to_point(11, -3, 6, 0, 1, 500, 1000);
  pros::delay(1000);
  chassis.turn_to_angle(120);*/

  // red rush
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(13, 0, 6, 0);
  chassis.turn_to_angle(22.5, 6);*/

  // blue rush
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(13, 0, 6, 0);
  chassis.turn_to_angle(338.5, 6);*/
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
  //6th ring
  /*chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(12, 0);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(12, 0, 10, 0, 1, 50, 600);
  chassis.drive_to_point(20, 0, 4, 0, 1, 50, 550);
  pros::delay(200);
  chassis.drive_to_point(40, 0);
  pros::delay(50);
  scoring_mech.intake_move(25);
  chassis.turn_to_point(24, 24);
  scoring_mech.intake_move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(24, 24, 4, 0, 1, 50, 1000);*/




  //SWP
  /*odom_constants();
  chassis.set_coordinates(11, -3, 121.326);
  scoring_mech.move2(600);
  pros::delay(500);
  scoring_mech.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 500);
  scoring_mech.move2(-600);
  scoring_mech.set_brake_mode('C');
  pros::delay(25);
  chassis.turn_to_point(15.8, -34, 0, 12, 1, 175, 500);
  scoring_mech.move2(0);
  chassis.drive_to_point(-4, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  chassis.turn_to_point(-24.5, 45.3);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-24.5, 45.3, 10, 0);
  pros::delay(25);
  chassis.turn_to_point(-24, 38);
  pros::delay(300);
  chassis.drive_to_point(-24, 38);
  chassis.turn_to_point(20, 14);
  pros::delay(75);
  chassis.drive_to_point(9, 20);
  pneumatics.clench_v(0);
  chassis.drive_to_point(20, 14, 12, 0, 1, 125, 325);
  pros::delay(210);
  scoring_mech.intake_move(135);
  chassis.drive_to_point(26, 2, 13, 0, 1, 150, 930);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(4, -36);
  chassis.drive_to_point(48, 36, 7, 0, 1, 200, 1200);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(325);
  chassis.turn_to_point(65, 35.5);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(65, 35.5);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(31, 36, 0, 13, 1, 250, 1000);
  scoring_mech.move2(125);
  scoring_mech.intake_move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(28, 36, 7, 0);*/


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
  /*chassis.turn_to_point(-24, -2.5);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.turn_to_point(20, -24);
  chassis.drive_distance(-20);*/
  /*
  chassis.turn_to_point(-12, 0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-12, 0);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(-24, 0, 4, 0, 1, 50, 600);
  pros::delay(400);
  chassis.drive_to_point(-40, 0, 8, 0, 1, 50, 1000);*/


  //6th ring
  /*chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(-12, 0);
  scoring_mech.intake_move(600);
  pros::delay(50);
  chassis.drive_to_point(-12, 0, 10, 0, 1, 50, 600);
  chassis.drive_to_point(-21, 0, 4, 0, 1, 50, 500);
  pros::delay(500);
  chassis.drive_to_point(-40, 0);
  pros::delay(50);
  chassis.drive_to_point(-24, 0);
  scoring_mech.intake_move(50);
  chassis.turn_to_point(-24, 24);
  scoring_mech.intake_move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-24, 24, 4, 0, 1, 50, 1000);*/



  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  //pros::delay(2000);
  chassis.turn_to_angle(-34,12);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  scoring_mech.move2(600);
  pros::delay(500);
  scoring_mech.move2(-600);
  chassis.drive_distance(-10,12);
  scoring_mech.move2(0);
  chassis.set_coordinates(0, 0, 326);
  pros::delay(50);
  chassis.turn_to_point(1.75,18,0,14,1,50,600);
  chassis.drive_to_point(2,7.5,14,0,1,50,375);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(-1,-5.5,14,0, 1, 150, 650);
  pneumatics.doinker_v(0);
  scoring_mech.intake_move(130);
  chassis.turn_to_point(8,13,0,14,1,50,250);
  chassis.drive_to_point(8,13.6,14,0,1,300,750);
  scoring_mech.intake_move(1);
  chassis.turn_to_point(-36, 58,0,11,1,300,850);
  scoring_mech.intake_move(-200);
  pros::delay(120);
  scoring_mech.intake_move(1);
  //pros::delay(5);
  chassis.drive_to_point(24, -6, 5.5,0,1,300, 1100);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(300);
  //scoring_mech.intake_move(0);
  chassis.turn_to_point(26, -31,0,14,1,300,700);
  scoring_mech.intake_move(600);
  pros::delay(100);
  chassis.drive_to_point(26, -31, 13, 0, 1, 200, 750);
  scoring_mech.intake_move(0);
  chassis.set_turn_exit_conditions(1, 100, 900);
  chassis.turn_to_point(-5, -43);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(-5, -43);
  //chassis.turn_to_point(-13, -45, 0, 13, 1, 200, 700);
  chassis.drive_to_point(-13, -45, 5, 0, 1, 200, 1200);
  pros::delay(300);
  chassis.drive_to_point(3, -39);
  pros::delay(450);
  scoring_mech.intake_move(-600);
  chassis.turn_to_point(39, -2);
  scoring_mech.move2(100);
  chassis.drive_to_point(39, -2);
  scoring_mech.move2(600);*/


  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  chassis.turn_to_angle(-34,12);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  scoring_mech.move2(600);
  pros::delay(475);
  scoring_mech.move2(-600);
  chassis.drive_distance(-10,12);
  scoring_mech.move2(0);
  chassis.set_coordinates(0, 0, 326);
  pros::delay(50);
  chassis.turn_to_point(1.5,18,0,14,1,50,600);
  chassis.drive_to_point(2,7.5,14,0,1,50,235);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(-1,-5.5,14,0, 1, 150, 650);
  pneumatics.doinker_v(0);
  pros::delay(150);
  scoring_mech.intake_move(130);
  chassis.turn_to_point(6, 14, 0, 13, 1, 200, 400);
  chassis.drive_to_point(6, 14, 10, 0);
  //chassis.turn_to_point(8, 13, 0, 13, 1, 50, 250);
  //chassis.drive_to_point(8, 13.6, 13, 0, 1, 300, 750);
  pros::delay(30);
  scoring_mech.intake_move(1);
  chassis.turn_to_point(-36, 58,0,11,1,300,850);
  scoring_mech.intake_move(-200);
  pros::delay(100);
  scoring_mech.intake_move(1);
  //pros::delay(5);
  chassis.drive_to_point(24, -6, 5.75, 0,1,300, 1100);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(300);
  //scoring_mech.intake_move(0);
  chassis.turn_to_point(26, -31,0,14,1,300,700);
  scoring_mech.intake_move(600);
  pros::delay(100);
  chassis.drive_to_point(26, -31, 13, 0, 1, 200, 750);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-5, -43, 13, 0 , 1, 200, 650);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-5, -43);
  chassis.turn_to_point(-10, -45, 0, 13, 1, 200, 500);
  chassis.drive_to_point(-10, -45, 6.7, 0, 1, 200, 700);
  pros::delay(100);
  chassis.drive_to_point(-5, -43);
  pros::delay(100);
  scoring_mech.intake_move(-600);
  chassis.turn_to_point(45, 16);
  //chassis.set_brake_mode('C');
  scoring_mech.move2(30);
  chassis.drive_to_point(45, 16, 7, 0, 1, 200, 2000);*/


  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  //pros::delay(2000);
  chassis.turn_to_angle(-34,12);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  scoring_mech.move2(600);
  pros::delay(500);
  scoring_mech.move2(-600);
  chassis.drive_distance(-10,12);
  scoring_mech.move2(0);
  chassis.set_coordinates(0, 0, 326);
  pros::delay(50);
  chassis.turn_to_point(1.75,18,0,14,1,50,600);
  chassis.drive_to_point(2,7.5,14,0,1,50,375);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(-1,-5.5,14,0, 1, 150, 650);
  pneumatics.doinker_v(0);
  scoring_mech.intake_move(130);
  chassis.turn_to_point(8,13,0,14,1,50,250);
  chassis.drive_to_point(8,13.6,14,0,1,300,750);
  pros::delay(30);
  scoring_mech.intake_move(1);
  chassis.turn_to_point(-36, 58,0,11,1,300,850);
  scoring_mech.intake_move(-200);
  pros::delay(120);
  scoring_mech.intake_move(1);
  //pros::delay(5);
  chassis.drive_to_point(24, -6, 5.5,0,1,300, 1100);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(400);
  //scoring_mech.intake_move(0);
  chassis.turn_to_point(26, -31,0,14,1,300,700);
  scoring_mech.intake_move(600);
  pros::delay(1000);
  chassis.drive_to_point(26,-31,10,0);
  pros::delay(1200);
  chassis.turn_to_point(36, 22);
  scoring_mech.move2(45);
  chassis.drive_to_point(36, 22, 5.5, 0, 1, 200, 3000);*/

}


void redLeftElim(){
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move1(600);
  pros::delay(410);
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
  /*chassis.turn_to_point(12, 36, 1, 10, 1, 50, 1000);
  scoring_mech.intake_move(600);
  pros::delay(150);
  scoring_mech.move2(60);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(12, 36, 7, 0, 1, 50, 1500);*/
  //6th ring
  /*chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(12, 0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(12, 0, 10, 0, 1, 50, 600);
  chassis.turn_to_point(21, 0, 1, 14, 1, 50, 500);
  chassis.drive_to_point(21, 0, 5, 0, 1, 50, 600);
  pros::delay(400);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(72, 0, 7, 0);*/




  /*
  //7 ring 2 top
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move2(600);
  pros::delay(410);
  scoring_mech.move2(0);
  scoring_mech.set_brake_mode('C');
  //pros::delay(10);
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.move2(-600);
  chassis.turn_to_point(9.15, -36, 0, 12, 1, 50, 450);
  chassis.drive_to_point(2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(350);
  scoring_mech.move2(0);
  chassis.turn_to_point(-23, 31);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-23, 31, 8, 0, 1, 50, 775);
  chassis.turn_to_point(-29, 38, 0, 14, 1, 50, 600);
  chassis.drive_to_point(-29, 38, 14, 0, 1, 100, 700);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-26, 22, 0, 14, 1, 50, 700);
  chassis.drive_to_point(-26, 22, 14, 0, 1, 50, 500);
  chassis.turn_to_point(-28, -7, 0, 14, 1, 50, 675);
  pros::delay(100);
  chassis.drive_to_point(-28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(-48, -23, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(-35, -15);
  chassis.drive_to_point(-38.5, -19, 4, 0);
  scoring_mech.intake_move(60);
  chassis.drive_to_point(-23.5, -2.5, 10, 0, 1, 50, 400);
  scoring_mech.intake_move(0);

  //6th ring
  chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(12, 0);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(12, 0, 10, 0, 1, 50, 600);
  chassis.drive_to_point(21, 0, 6, 0, 1, 50, 400);
  pros::delay(750);
  chassis.drive_to_point(72, 0, 8, 0, 1, 50, 1000);
  pros::delay(350);
  chassis.turn_to_point(96, -24);
  chassis.drive_to_point(96, -24, 6, 0);*/

  
  //chassis.turn_to_point(0, 0);
  //chassis.turn_to_point(0, 0);

  //ladder touch
  /*chassis.turn_to_point(4, 28);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(4, 28, 10, 0, 1, 50, 925);
  chassis.turn_to_point(24, 48);
  scoring_mech.move2(400);
  pros::delay(500);
  scoring_mech.move2(100);*/


  /*chassis.drive_to_point(-36, -15, 4.5, 0);
  pros::delay(25);
  chassis.drive_to_point(-32, -11);
  pros::delay(150);
  chassis.drive_to_point(-36, -15, 4.5, 0);
  pros::delay(25);
  chassis.drive_to_point(-32, -11);
  pros::delay(150);
  chassis.turn_to_point(24, 0);
  chassis.drive_to_point(24, 0, 13, 0, 1, 200, 1000);*/
  /*
  //7 ring 2 top :)
  odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move2(600);
  pros::delay(475);
  scoring_mech.move2(-600);
  //pros::delay(10);
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.set_brake_mode('C');
  chassis.turn_to_point(8.4, -36, 0, 12, 1, 50, 475);
  chassis.drive_to_point(2, 15, 14, 0, 1, 50, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 200, 600);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  scoring_mech.move2(0);
  chassis.turn_to_point(-23, 31.5);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-23, 31.5);
  chassis.turn_to_point(-29, 36.5, 0, 14, 1, 50, 700);
  chassis.drive_to_point(-29, 36.5, 14, 0, 1, 50, 600);
  chassis.drive_to_point(-23, 31.5, 14, 0, 1, 50, 600);
  chassis.turn_to_point(-24, 22, 0, 13, 1, 50, 650);
  chassis.drive_to_point(-24, 22, 14, 0, 1, 50, 525);
  chassis.turn_to_point(-24, -3, 0, 14, 1, 50, 700);
  pros::delay(50);
  chassis.drive_to_point(-24, -3);
  chassis.turn_to_point(-48, -27, 0, 14, 1, 50, 750);
  chassis.drive_to_point(-32, -11, 14, 0, 1, 50, 500);
  chassis.drive_to_point(-36, -15, 4, 0, 1, 50, 500);
  pros::delay(200);
  chassis.drive_to_point(-24, -3, 14, 0, 1, 50, 900);
  pros::delay(100);
  
  /*chassis.drive_to_point(-36, -15, 4, 0);
  pros::delay(25);
  chassis.drive_to_point(-28, -7);
  pros::delay(150);
  chassis.drive_to_point(-36, -15, 4, 0);
  pros::delay(25);
  chassis.drive_to_point(-28, -7);
  pros::delay(150);*/
  /*chassis.turn_to_point(16, 0, 0, 13, 1, 50, 800);
  chassis.drive_to_point(16, 0, 13, 0, 1, 50, 1000);
  chassis.turn_to_point(24, 0);
  chassis.drive_to_point(24, 0, 8, 0, 1, 50, 500);
  pros::delay(300);
  chassis.drive_to_point(36, 0);
  pros::delay(200);
  chassis.turn_to_point(0, 0);*/

  /*
  //goes to touch ladder instead of grabbing the 6/7 ring
  chassis.turn_to_point(12, 36);
  chassis.drive_to_point(12, 36);
  neutral_stake.move2(150);
  */







  //blue side - not reflected yet :(
  //BLUE SIDE
  /*odom_constants();
  chassis.set_coordinates(11, -14.5, 121.326);
  scoring_mech.move2(600);
  pros::delay(475);
  scoring_mech.move2(-600);
  //pros::delay(10);
  chassis.drive_to_point(5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.set_brake_mode('C');
  chassis.turn_to_point(8.4, -36, 0, 12, 1, 50, 475);
  chassis.drive_to_point(2, 15, 14, 0, 1, 50, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 200, 600);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  scoring_mech.move2(0);
  chassis.turn_to_point(-23, 31.5);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-23, 31.5);
  chassis.turn_to_point(-29, 36.5, 0, 14, 1, 50, 700);
  chassis.drive_to_point(-29, 36.5, 14, 0, 1, 50, 600);
  chassis.drive_to_point(-23, 31.5, 14, 0, 1, 50, 600);
  chassis.turn_to_point(-24, 22, 0, 13, 1, 50, 650);
  chassis.drive_to_point(-24, 22, 14, 0, 1, 50, 525);
  chassis.turn_to_point(-24, -3, 0, 14, 1, 50, 700);
  pros::delay(50);
  chassis.drive_to_point(-24, -3);
  chassis.turn_to_point(-48, -27, 0, 14, 1, 50, 750);
  chassis.drive_to_point(-32, -11, 14, 0, 1, 50, 500);
  chassis.drive_to_point(-36, -15, 4, 0, 1, 50, 500);
  pros::delay(200);
  chassis.drive_to_point(-24, -3, 14, 0, 1, 50, 900);
  pros::delay(100);
  
  /*chassis.drive_to_point(-36, -15, 4, 0);
  pros::delay(25);
  chassis.drive_to_point(-28, -7);
  pros::delay(150);
  chassis.drive_to_point(-36, -15, 4, 0);
  pros::delay(25);
  chassis.drive_to_point(-28, -7);
  pros::delay(150);*/
  /*chassis.turn_to_point(16, 0, 0, 13, 1, 50, 800);
  chassis.drive_to_point(16, 0, 13, 0, 1, 50, 1000);
  chassis.turn_to_point(24, 0);
  chassis.drive_to_point(24, 0, 8, 0, 1, 50, 500);
  pros::delay(300);
  chassis.drive_to_point(36, 0);
  pros::delay(200);
  chassis.turn_to_point(0, 0);*/

  /*
  //goes to touch ladder instead of grabbing the 6/7 ring
  chassis.turn_to_point(12, 36);
  chassis.drive_to_point(12, 36);
  neutral_stake.move2(150);
  */












  /*chassis.set_brake_mode('C');
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.calculate();*/
  //5 ring (2 top)
  //chassis.set_coordinates(0, 0, 0);
  // odom_constants();
  /*chassis.drive_to_point(0, 96, 9, 0, 3, 200, 3000);
  chassis.turn_to_point(-96, 96);
  chassis.drive_to_point(-96, 96, 9, 0, 3, 200, 3000);*/
  
  //color sort test
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(1);
  
  scoring_mech.intake_move(600);
  pros::delay(60000);*/
  //chassis.drive_to_point(0, 96, 3, 0, 1, 200, 5000);
  //scoring_mech.intake_move(600);
  

  /*chassis.turn_to_point(-30, 51.5);
  pros::delay(25);
  chassis.drive_to_point(-30, 51.5);
  pros::delay(200);
  //chassis.drive_to_point(-36, 49);
  //pros::delay(400);

  //scoring_mech.intake_move(-600);
  //scoring_mech.intake_move(0);
  chassis.drive_to_point(-23, 50.5);
  //1```````````````````````````````````````````````````````````````````````````````scoring_mech.intake_move(600);
  chassis.turn_to_point(-21, 39);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(-21, 39);
  pros::delay(200);
  chassis.turn_to_point(-24, 12);
  //pros::delay(150);
  //chassis.drive_to_point(-24, -3);
  chassis.drive_to_point(-24, 12);
  chassis.turn_to_point(-48, -12);
  //scoring_mech.intake_move(-600);
  chassis.drive_to_point(-32, 4, 12, 0);
  chassis.drive_to_point(-40, -4, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-32, 4, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-40, -4, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-32, 4, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-40, -4, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-32, 4, 7, 0);
  pros::delay(250);*/















  /*odom_constants();
  chassis.set_coordinates(11, -3, 120);
  scoring_mech.move2(600);
  pros::delay(625);
  scoring_mech.move2(-600);
  pros::delay(200);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 500);
  scoring_mech.move2(0);
  chassis.turn_to_point(15.8, -34, 0, 12, 1, 175, 500);
  chassis.drive_to_point(-4, 34, 6.1, 0);
  pros::delay(40);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(-15, 50, 0, 9, 1, 200, 1100);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-15, 50);
  chassis.turn_to_point(-24, 49);
  chassis.drive_to_point(-24, 49);
  pros::delay(200);
  chassis.drive_to_point(-34, 49);
  pros::delay(250);
  scoring_mech.intake_move(-600);
  //scoring_mech.intake_move(0);
  chassis.drive_to_point(-15, 50);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(-24, 36);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(-24, 36);
  pros::delay(75);
  //chassis.drive_to_point(-24, -3);
  chassis.turn_to_point(-24, -2);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(-48, -12, 5, 0, 1, 200, 650);
  pros::delay(50);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(-24, -8);
  pros::delay(50);
  chassis.drive_to_point(-48, -12, 1.5, 0, 1, 200, 500);
  pros::delay(125);
  chassis.turn_to_point(12, 0);
  chassis.drive_to_point(12, 0);*/






  /*odom_constants();
  chassis.set_coordinates(-11, -3, 240);
  scoring_mech.move2(600);
  pros::delay(650);
  scoring_mech.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(-5.9, 0, 13, 0, 1, 150, 500);
  scoring_mech.move2(-600);
  pros::delay(150);
  scoring_mech.set_brake_mode('C');
  chassis.turn_to_point(-15.8, -34, 0, 12, 1, 175, 500);
  scoring_mech.move2(0);
  chassis.drive_to_point(4, 34, 6.1, 0);
  pros::delay(40);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(15, 50, 0, 9, 1, 200, 1100);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(15, 50);
  chassis.turn_to_point(24, 49);
  chassis.drive_to_point(24, 49);
  pros::delay(400);
  chassis.drive_to_point(34, 49);
  pros::delay(600);
  scoring_mech.intake_move(-600);
  //scoring_mech.intake_move(0);
  chassis.drive_to_point(15, 50);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(24, 36);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(24, 36);
  pros::delay(150);
  //chassis.drive_to_point(-24, -3);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(-48, -12, 5, 0, 1, 200, 650);
  pros::delay(50);
  scoring_mech.intake_move(600);
  pros::delay(200);
  chassis.drive_to_point(-24, -8);
  pros::delay(50);
  chassis.drive_to_point(-48, -12, 1.5, 0, 1, 200, 500);*/









  /*
  chassis.drive_to_point(9, 19);
  pneumatics.clench_v(0);
  chassis.drive_to_point(20, 12, 12, 0, 1, 125, 325);
  pros::delay(225);
  scoring_mech.intake_move(240);
  chassis.drive_to_point(26, 0, 13, 0, 1, 150, 950);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(9, -34);
  chassis.drive_to_point(44, 34, 6.1, 0);
  //pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(270);
  chassis.turn_to_point(65, 34);
  scoring_mech.intake_move(600);
  //pros::delay(100);
  chassis.drive_to_point(65, 34);
  scoring_mech.intake_move(2);
  chassis.turn_to_point(31, 36, 0, 13, 1, 250, 1000);
  scoring_mech.intake_move(600);
  pros::delay(20);
  //chassis.set_brake_mode('C');
  chassis.drive_to_point(31, 36);*/

  /*
  chassis.set_coordinates(0, -8, 0);
  odom_constants();
  chassis.drive_to_point(0, -33, 5, 0, 3, 50, 1300);
  pros::delay(100);
  pneumatics.clench_v(1);
  pros::delay(300);
  chassis.turn_to_point(24, -57);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(18, -49);
  pros::delay(325);
  chassis.turn_to_point(27, -52.5);
  chassis.drive_to_point(27, -52.5);
  pros::delay(450);
  chassis.turn_to_point(24, -36);
  chassis.drive_to_point(24, -36);
  pros::delay(350);
  scoring_mech.intake_move(-400);
  chassis.drive_to_point(24, 0);*/
}


void redRightElim(){

  default_constants();
  chassis.set_coordinates(0,0,0);
  chassis.turn_timeout = 700;
  chassis.drive_timeout= 500;
  chassis.drive_distance(-25,12);
  chassis.set_coordinates(chassis.get_X_position(),chassis.get_Y_position(), 0);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(16,-51);
  chassis.drive_to_point(16,-51);
  //chassis.set_coordinates();
  //pros::Task rush_helper(Scoring_Mech::rush_helper_task);






  /*odom_constants();
  chassis.set_coordinates(-22,2,20);
  pros::delay(25);
  scoring_mech.move2(89);
  //scoring_mech.move2(80);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(0, 36, 14, 0, 1, 200, 670);
  pros::delay(300);
  //scoring_mech.move2(-40);
  //chassis.turn_to_angle(280,14,1,150,500,0.277,0,0.81,15);
  chassis.turn_to_point(24, 56);
  pros::delay(200);
  scoring_mech.move2(-200);
  pros::delay(150);
  chassis.drive_to_point(-24, 24, 6, 0, 1, 250, 750);
  pros::delay(50);
  pneumatics.clench_v(1); 
  pros::delay(250);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(4, 28.5, 0, 13, 1, 200, 500);
  chassis.drive_to_point(4, 28.5, 7, 0, 1, 200, 650);
  //pros::delay(100);
  chassis.drive_to_point(-10, 27, 13, 0, 1, 200, 500);
  pros::delay(600);
  pneumatics.clench_v(0);
  chassis.turn_to_point(18, -3.75, 0, 13, 1, 200, 700);
  //scoring_mech.move2(-115);
  chassis.drive_to_point(18, -3.75);
  //scoring_mech.intake_move(-600);
  //pros::delay(100);
  //scoring_mech.move2(0);
  scoring_mech.intake_move(125);
  chassis.drive_to_point(24, -28, 5, 0, 1, 200, 750);
  //pros::delay(100);
  //scoring_mech.intake_move(600);
  pros::delay(25);
  scoring_mech.move2(52);
  scoring_mech.intake_move(20);
  chassis.drive_to_point(-8, -8, 13, 0, 1, 200, 850);
  scoring_mech.move2(0);
  /*pros::delay(1000);
  scoring_mech.intake_move(-600);
  chassis.turn_to_point(-40, 40);

  scoring_mech.move2(50);
  pros::delay(100);
  chassis.drive_to_point(-40, 40);*/

  //pros::delay(200);
  /*chassis.turn_to_point(17.25, 39.5, 0, 10, 1, 200, 950);
  //scoring_mech.move2(0);
  scoring_mech.intake_move(200);
  chassis.drive_to_point(17.25, 39.5, 8, 0, 1, 200, 1200);
  scoring_mech.intake_move(0);
  //chassis.turn_to_point(27, 60, 0, 9, 1, 200, 1000);
  //scoring_mech.intake_move(0);
  //chassis.drive_distance(4.15);
  chassis.left_swing_to_angle(62);
  scoring_mech.intake_move(-180);
  pros::delay(180);
  scoring_mech.intake_move(0);
  pros::delay(50);
  while (scoring_mech.neutral_stake_rot.get_angle() > 22500) {
    scoring_mech.move2(75);
  } 
  scoring_mech.move2(0);*/
  //scoring_mech.move2(600);



  /*pneumatics.clench_v(0);
  chassis.drive_to_point(4, 30, 13, 0, 1, 200, 600);
  chassis.turn_to_point(18, 0, 0, 13, 1, 200, 700);
  //scoring_mech.move2(-115);
  chassis.drive_to_point(18, 0);
  //scoring_mech.intake_move(-600);
  //pros::delay(100);
  //scoring_mech.move2(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(24, -24, 5, 0, 1, 200, 900);
  //pros::delay(100);
  //scoring_mech.intake_move(600);
  pros::delay(75);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(16, 0, 13, 0, 1, 200, 850);
  scoring_mech.move2(48);
  //pros::delay(200);
  chassis.turn_to_point(18, 40, 0, 10, 1, 200, 950);
  scoring_mech.move2(0);
  scoring_mech.intake_move(300);
  chassis.drive_to_point(18, 40, 8, 0, 1, 200, 1200);
  chassis.turn_to_point(27, 56, 0, 9, 1, 200, 1000);
  scoring_mech.intake_move(0);
  chassis.drive_distance(2.5);
  scoring_mech.intake_move(-120);
  pros::delay(120);
  scoring_mech.intake_move(0);
  pros::delay(100);
  scoring_mech.move2(600);
  //chassis.drive_to_point(20, -12, 1, 0, 1, 200, 325);
  //pros::delay(500);*/





  /*
  scoring_mech.intake_move(0);
  chassis.turn_to_point(13, -24);
  chassis.drive_to_point(16, 0);
  pneumatics.clench_v(0);
  pros::delay(50);
  chassis.turn_to_point(0, 0);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(0, -24);
  chassis.drive_to_point(0, 34);
  scoring_mech.move2(-600);
  chassis.turn_to_point(4, 26);
  pros::delay(150);
  scoring_mech.move2(0);*/

  
  
  
  
  
  /*

  chassis.drive_distance(8,14);
  scoring_mech.intake_move(600);
  pros::delay(800);
  chassis.drive_to_point(0,10,14,0,1,200,600);
  chassis.drive_distance(8,0,14,0);
  chassis.drive_distance(-15);
  pros::delay(1000);
  scoring_mech.move2(100);
  pneumatics.clench_v(0);
  chassis.turn_to_point(24,-35,0,14,1,150,600);
  chassis.drive_distance(-25,14);*/

  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 345);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(0, 36,10,0);
  pneumatics.doinker_v(1);
  scoring_mech.intake_move(5);
  chassis.drive_to_point(0, 15,14,0);
  pros::delay(200);
  pneumatics.doinker_v(0);
  pros::delay(200);
  chassis.turn_to_point(0, -10, 0,14);
  pros::delay(50);
  chassis.drive_to_point(-10, 40,14,0);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(600);
  pros::delay(550);
  pneumatics.clench_v(0);
  chassis.drive_to_point(5, 24,14,0);
  chassis.turn_to_point(36, 10,0,14);
  chassis.drive_to_point(-30, 18,14,0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-18, 10, 0, 14);
  chassis.drive_to_point(-18, 10, 10,0);
  pros::delay(400);
  chassis.turn_to_point(-12, -6,0,14);
  chassis.drive_to_point(-12, -6,10,0);
  pros::delay(1000);
  chassis.turn_to_point(2, -20,0,14);
  pneumatics.doinker_v(1); 
  chassis.drive_distance(12);
  chassis.turn_to_point(-5, 25,0,14);
  pros::delay(300);
  scoring_mech.intake_move(600);
  pneumatics.clench_v(0); 
  pneumatics.doinker_v(0);
  chassis.drive_to_point(-5, 25,14,0);
  chassis.turn_to_point(-10, -30,0,14);*/

  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  //chassis.d
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  scoring_mech.intake_move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -30);
  chassis.drive_to_point(-24, -30);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  scoring_mech.intake_move(0);
  pros::delay(500);
  chassis.turn_to_point(-24, -16);
  pros::delay(200);
  chassis.drive_distance(-16);
  scoring_mech.intake_move(-120);
  pros::delay(100);
  scoring_mech.intake_move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(24, -4);
  chassis.drive_to_point(-3, 1);*/
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
  /*
  chassis.turn_to_point(-12, 24, 1, 12, 1, 50, 1200);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-12, 24, 12, 0, 1, 50, 1000);
  chassis.turn_to_point(-24, 24);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-24, 24, 3, 0, 1, 50, 800);
  scoring_mech.move2(200);*/

  

  //6th ring
  /*chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(-12, 0);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(-12, 0, 10, 0, 1, 50, 600);
  chassis.drive_to_point(-21, 0, 4, 0, 1, 50, 500);
  pros::delay(500);
  chassis.drive_to_point(-40, 0);
  scoring_mech.intake_move(600);*/
  /*pros::delay(50);
  scoring_mech.intake_move(50);
  chassis.turn_to_point(-24, 24);
  scoring_mech.intake_move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-24, 24, 4, 0, 1, 50, 1000);*/

  /*odom_constants();
  chassis.set_coordinates(-11, -3, 240);
  scoring_mech.move2(600);
  pros::delay(475);
  scoring_mech.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(-5.9, 0, 13, 0, 1, 150, 550);
  scoring_mech.move2(-500);
  scoring_mech.set_brake_mode('C');
  chassis.turn_to_point(-15.8, -34, 0, 12, 1, 175, 500);
  scoring_mech.move2(0);
  chassis.drive_to_point(4, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(180);
  chassis.turn_to_point(25.5, 41);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(25.5, 41, 8, 0);
  pros::delay(200);
  chassis.turn_to_point(24.5, 38);
  chassis.drive_to_point(24.5, 38);
  pros::delay(125);
  chassis.turn_to_point(-20, 12);
  chassis.drive_to_point(-9, 19);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-20, 12, 12, 0, 1, 125, 325);
  pros::delay(225);
  scoring_mech.intake_move(125);
  chassis.drive_to_point(-26, 0, 13, 0, 1, 150, 950);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-9, -34);
  chassis.drive_to_point(-44, 34, 6.1, 0);
  //pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(270);
  chassis.turn_to_point(-63, 34);
  scoring_mech.intake_move(600);
  //pros::delay(100);
  chassis.drive_to_point(-63, 34);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-31, 36, 0, 13, 1, 250, 1000);
  scoring_mech.intake_move(600);
  pros::delay(20);
  //chassis.set_brake_mode('C');
  chassis.drive_to_point(-31, 36);*/

  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(16);
  //chassis.drive_to_point(0, 15, 14,0);
  //chassis.turn_to_point(100, 15);
  chassis.turn_to_angle(90);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-5, 16, 9, 0,1, 400, 800);
  scoring_mech.intake_move(-120);
  pros::delay(375);
  scoring_mech.intake_move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 5, 14, 0, 1, 400, 800);
  chassis.turn_to_point(78, 54);
  scoring_mech.intake_move(-120);
  chassis.drive_to_point(78, 54, 14, 0, 1, 200, 1000);
  pros::delay(150);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(150, 54);
  chassis.drive_to_point(44, 54, 14, 0,1, 400, 800);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(-120);
  pros::delay(175);
  //chassis.drive_to_point(40, 37, 14, 0);
  chassis.turn_to_point(45, 55);
  chassis.drive_to_point(45, 52, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(40,40, 10, 0);
  chassis.turn_to_point(52,56);
  chassis.drive_to_point(50,51, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-50,115);
  chassis.drive_distance(17);*/
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


  /*odom_constants();
  chassis.set_coordinates(11, -3, 121.326);
  scoring_mech.move2(600);
  pros::delay(475);
  scoring_mech.move2(-600);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 500);
  chassis.turn_to_point(13, -34, 0, 12, 1, 175, 470);
  chassis.drive_to_point(-2, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  scoring_mech.move2(0);
  chassis.turn_to_point(-20, 34);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-20, 34);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(-16, 34);
  chassis.turn_to_point(-25, 12);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-25, 12);
  pros::delay(200);
  chassis.set_drive_exit_conditions(1, 200, 750);
  chassis.turn_to_point(-35, 2);
  chassis.drive_to_point(-35, 2, 12, 0);
  chassis.drive_to_point(-42, -5, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-35, 2, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-42, -5, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-35, 2, 7, 0);
  pros::delay(250);
  chassis.drive_to_point(-42, -5, 5, 0);
  pros::delay(50);
  chassis.drive_to_point(-35, 2, 7, 0);
  pros::delay(250);
  chassis.turn_to_point(24, 48);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(24, 48);
  scoring_mech.move2(150);
  pros::delay(300);
  scoring_mech.move2(0);*/







  //2 ring
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  //pros::delay(2000);
  chassis.turn_to_angle(42,14);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  scoring_mech.move2(600);
  pros::delay(500);
  scoring_mech.move2(0);
  //pros::delay(200);
  chassis.drive_distance(-10,14);
  chassis.set_coordinates(0, 0, 42);
  pros::delay(50);
  scoring_mech.move2(-600);
  chassis.turn_to_point(-13,18,0,14,1,50,475);
  chassis.drive_to_point(-9,4,14,0,1,50, 175);
  scoring_mech.move2(0);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(2.75, -5, 14, 0);
  scoring_mech.move2(0);
  pneumatics.doinker_v(0);
  pros::delay(25);
  scoring_mech.intake_move(385);
  chassis.turn_to_point(-4.5,16,0,14,1,50,250);
  //pros::delay(650);
  chassis.drive_to_point(-4.5,16,14,0,1,300,475);
  scoring_mech.intake_move(2);
  chassis.turn_to_point(36, 58.5,0,14,1,300,700);
  scoring_mech.intake_move(-120);
  pros::delay(90);
  scoring_mech.intake_move(2);
  chassis.drive_to_point(-27, -7.5, 6.25,0,1,300,1300);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(275);
  //scoring_mech.intake_move(0);
  chassis.turn_to_point(-26, -29,0,14,1,300,700);
  scoring_mech.intake_move(600);
  pros::delay(350);
  chassis.drive_to_point(-26, -29, 14, 0, 1, 200, 750);
  chassis.set_turn_exit_conditions(1, 100, 900);
  chassis.turn_to_point(5, -46.5);
  //scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(5, -46.5);
  //chassis.turn_to_point(-13, -45, 0, 13, 1, 200, 700);
  chassis.drive_to_point(13, -47, 4, 0, 1, 200, 1200);
  pros::delay(175);
  chassis.drive_to_point(-3, -39);
  pros::delay(300);
  scoring_mech.move2(25);
  scoring_mech.intake_move(-600);
  chassis.turn_to_point(-39, -2);
  scoring_mech.move2(75);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-39, -2);
  scoring_mech.move2(600);*/






  //2 ring
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  pros::delay(2500);
  chassis.turn_to_angle(42,14);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  scoring_mech.move2(500);
  pros::delay(500);
  scoring_mech.move2(-600);
  //pros::delay(200);
  chassis.drive_distance(-10,14);
  scoring_mech.move2(0);
  chassis.set_coordinates(0, 0, 42);
  pros::delay(50);
  chassis.turn_to_point(-10,18,0,14,1,50,475);
  chassis.drive_to_point(-9,4,14,0,1,50, 175);
  scoring_mech.move2(0);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(2.75, -5, 14, 0);
  pneumatics.doinker_v(0);
  pros::delay(100);
  scoring_mech.intake_move(165);
  chassis.turn_to_point(-4.5,16,0,14,1,50,250);
  chassis.drive_to_point(-4.5,16,14,0,1,300,700);
  scoring_mech.intake_move(2);
  chassis.turn_to_point(36, 53,0,14,1,300,700);
  scoring_mech.intake_move(-120);
  pros::delay(120);
  scoring_mech.intake_move(2);
  chassis.drive_to_point(-27, -7.5, 6.25,0,1,300,1300);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(300);
  //scoring_mech.intake_move(0);
  chassis.turn_to_point(-30, -26,0,14,1,300,700);
  scoring_mech.intake_move(600);
  pros::delay(600);
  chassis.drive_to_point(-30, -26, 9, 0, 1, 200, 750);
  pros::delay(700);
  chassis.turn_to_point(-36, 22);
  scoring_mech.move2(45);
  chassis.drive_to_point(-36, 22, 5.5, 0, 1, 200, 3000);*/
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


  /*chassis.turn_to_point(-12, 36, 1, 10, 1, 50, 1050);
  scoring_mech.intake_move(600);
  pros::delay(300);
  scoring_mech.move2(60);
  chassis.drive_to_point(-12, 36, 7, 0, 1, 50, 1500);*/


  /*
  odom_constants();
  chassis.set_coordinates(-11, -14.5, 239);
  scoring_mech.move2(600);
  pros::delay(465);
  scoring_mech.move2(-600);
  //pros::delay(10);
  chassis.drive_to_point(-5.9, -12, 13, 0, 1, 50, 450);
  scoring_mech.set_brake_mode('C');
  scoring_mech.move2(-600);
  chassis.turn_to_point(-9.15, -36, 0, 12, 1, 50, 450);
  chassis.drive_to_point(-2, 15, 14, 0, 1, 75, 375);
  chassis.drive_to_point(0, 22, 5, 0, 1, 75, 550);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(350);
  scoring_mech.move2(0);
  chassis.turn_to_point(23, 31);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(23, 31, 8, 0, 1, 50, 775);
  chassis.turn_to_point(29, 38, 0, 14, 1, 50, 600);
  chassis.drive_to_point(29, 38, 14, 0, 1, 100, 700);
  //chassis.drive_to_point(-23, 31, 14, 0, 1, 50, 500);
  chassis.turn_to_point(26, 22, 0, 14, 1, 50, 700);
  chassis.drive_to_point(26, 22, 14, 0, 1, 50, 500);
  chassis.turn_to_point(28, -7, 0, 14, 1, 50, 675);
  pros::delay(100);
  chassis.drive_to_point(28, -7, 14, 0, 1, 50, 900);
  chassis.turn_to_point(48, -23, 0, 14, 1, 50, 550);
  chassis.set_drive_exit_conditions(1, 50, 600);
  chassis.drive_to_point(35, -15);
  chassis.drive_to_point(38.5, -19, 4, 0);
  scoring_mech.intake_move(60);
  chassis.drive_to_point(23.5, -2.5, 10, 0, 1, 50, 400);
  scoring_mech.intake_move(0);

  //6th ring
  chassis.set_turn_exit_conditions(1, 50, 900);
  chassis.turn_to_point(-12, 0);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.drive_to_point(-12, 0, 10, 0, 1, 50, 600);
  chassis.drive_to_point(-21, 0, 6, 0, 1, 50, 400);
  pros::delay(750);
  chassis.drive_to_point(-72, 0, 8, 0, 1, 50, 1000);
  pros::delay(350);
  chassis.turn_to_point(-96, -24);
  chassis.drive_to_point(-96, -24, 6, 0);*/
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.right_swing_to_angle(326,14);
  scoring_mech.move2(600);
  pros::delay(525);
  scoring_mech.move2(-600);
  chassis.drive_distance(-10,14);
  chassis.set_coordinates(0, 0, -34);
  pros::delay(15);
  chassis.turn_to_point(1.5,18,0,14,1,50,300);
  scoring_mech.move2(0);
  chassis.drive_to_point(3.5,6,14,0,1,50,250);
  pneumatics.doinker_v(1);
  pros::delay(100);
  chassis.drive_to_point(-1,-3,14,0, 1, 150, 400);
  pneumatics.doinker_v(0);
  scoring_mech.intake_move(600);
  pros::delay(50);
  chassis.turn_to_point(7,11.6,0,14,1,50,250);
  chassis.drive_to_point(7,11.6,14,0);
  //chassis.drive_to_point(6,8,14,0,1,50,250);
  scoring_mech.intake_move(10);
  chassis.turn_to_point(-36, 48,0,11,1,300,700);
  pros::delay(5);
  chassis.drive_to_point(21, -2, 4,0,1,300,1250);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(125);
  chassis.turn_to_point(23.5, -31,0,14,1,300,700);
  pros::delay(100);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(23.5,-31,10,0);
  pros::delay(1500);
  chassis.drive_to_point(23.5, 12);

  chassis.turn_to_point(1.5, -32.5, 0,14,1,300,700);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(1.5,-32.5,14,0);
  chassis.turn_to_point(-15, -47,0,14,1,300,700);
  chassis.drive_to_point(-15,-47, 6,0,1,300,400);
  pros::delay(50);
  scoring_mech.intake_move(600);
  pros::delay(150);
  chassis.set_brake_mode('C');
  chassis.turn_to_point(-10.3, -47);
  scoring_mech.move2(600);
  pros::delay(345);
  scoring_mech.move2(0);
  chassis.drive_to_point(43, 3, 5, 0, 1, 200, 2000);*/
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

  /*odom_constants();
  chassis.set_coordinates(22,2,340);
  pros::delay(25);
  scoring_mech.move2(89);
  //scoring_mech.move2(80);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(0, 36, 14, 0, 1, 200, 670);
  pros::delay(300);
  //scoring_mech.move2(-40);
  //chassis.turn_to_angle(280,14,1,150,500,0.277,0,0.81,15);
  chassis.turn_to_point(-24, 56);
  pros::delay(200);
  scoring_mech.move2(-200);
  pros::delay(150);
  chassis.drive_to_point(24, 24, 6, 0, 1, 250, 750);
  pros::delay(50);
  pneumatics.clench_v(1); 
  pros::delay(250);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(-4, 28.5, 0, 13, 1, 200, 500);
  chassis.drive_to_point(-4, 28.5, 7, 0, 1, 200, 650);
  //pros::delay(100);
  chassis.drive_to_point(10, 27, 13, 0, 1, 200, 500);
  pros::delay(600);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-18, -3.75, 0, 13, 1, 200, 700);
  //scoring_mech.move2(-115);
  chassis.drive_to_point(-18, -3.75);
  //scoring_mech.intake_move(-600);
  //pros::delay(100);
  //scoring_mech.move2(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-24, -28, 5, 0, 1, 200, 800);
  //pros::delay(100);
  //scoring_mech.intake_move(600);
  pros::delay(25);
  scoring_mech.move2(52);
  scoring_mech.intake_move(30);
  chassis.drive_to_point(8, -8, 13, 0, 1, 200, 850);
  scoring_mech.move2(0);
  /*pros::delay(1000);
  scoring_mech.intake_move(-600);
  chassis.turn_to_point(-40, 40);

  scoring_mech.move2(50);
  pros::delay(100);
  chassis.drive_to_point(-40, 40);

  //pros::delay(200);
  chassis.turn_to_point(-16.75, 42, 0, 10, 1, 200, 950);
  //scoring_mech.move2(0);
  scoring_mech.intake_move(200);
  chassis.drive_to_point(-16.75, 42, 8, 0, 1, 200, 1200);
  scoring_mech.intake_move(0);
  //chassis.turn_to_point(27, 60, 0, 9, 1, 200, 1000);
  //scoring_mech.intake_move(0);
  //chassis.drive_distance(4.15);
  chassis.right_swing_to_angle(320);
  scoring_mech.intake_move(-180);
  pros::delay(180);
  scoring_mech.intake_move(0);
  pros::delay(50);
  while (scoring_mech.neutral_stake_rot.get_angle() > 22500) {
    scoring_mech.move2(75);
  } 
  scoring_mech.move2(0);*/
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
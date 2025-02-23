#include "main.h"



void default_constants(){
  /*chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(0, .4, 0, 1, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .4, .018, 3, 15);
  chassis.set_swing_constants(12, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 50, 1000);
  chassis.set_turn_exit_conditions(4, 50, 1000);
  chassis.set_swing_exit_conditions(1, 50, 1000);*/
  
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(14, 1.5, 0, 10, 0);
  chassis.set_heading_constants(0, .16, 0, 7.5, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .4, .018, 3, 15);
  chassis.set_swing_constants(14, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 210, 950);
  chassis.set_turn_exit_conditions(1, 175, 600);
  chassis.set_swing_exit_conditions(2, 50, 1000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 13;
  chassis.drive_kp = 0.713;
  chassis.drive_kd = 0.45;
  chassis.drive_settle_error = 1;
  chassis.drive_settle_time = 210;
  chassis.turn_max_voltage = 13;
  chassis.turn_kp = 0.26;
  chassis.turn_ki = 0;
  chassis.turn_kd = 0.81;
  chassis.turn_settle_error = 1;

  //old constants
  /*chassis.drive_max_voltage = 11;
  chassis.drive_kp = 0.55;
  chassis.drive_kd = 0.39;
  chassis.drive_settle_error = 2.5;
  chassis.drive_settle_time = 50;
  chassis.turn_max_voltage = 11;
  chassis.turn_kp = 0.3;
  chassis.turn_ki = 0;
  chassis.turn_kd = 0.25;
  chassis.turn_settle_error = 3;
  chassis.turn_settle_time = 50;

  
   chassis.drive_max_voltage = 14;
  chassis.drive_kp = 0.414;
  chassis.drive_kd = 0.39;
  chassis.drive_settle_error = 0.5;
  chassis.drive_settle_time = 50;
  chassis.turn_max_voltage = 14;
  chassis.turn_kp = 0.31;
  chassis.turn_ki = 0;
  chassis.turn_kd = 2.5;
  chassis.turn_settle_error = 3;
  chassis.turn_settle_time = 50;*/
  
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
    //delete [] text;
    //text = new char[16];
    //std::sprintf(text, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    //pros::screen::print(TEXT_MEDIUM, 0, 110, text);
    /*delete [] text;
    text = new char[16];
    std::sprintf(text, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    pros::screen::print(TEXT_MEDIUM, 0, 130, text);
    pros::delay(20);*/
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);

  //chassis.turn_to_point(24, 0, 1, 5);
  //std::cout << "X: " << chassis.get_X_position() << " Y: " << chassis.get_Y_position() << " H: " << chassis.get_absolute_heading() << std::endl;
  //while (true) {
    //std::cout << "X: " << chassis.get_X_position() << " Y: " << chassis.get_Y_position() << " H: " << chassis.get_absolute_heading() << std::endl;
    //pros::delay(200);
  //}
  
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

void auton_setup() {
  //redLeftQual
  
  //color sort testing
  pneumatics.clench_v(1);
  pros::delay(500);
  scoring_mech.intake_move(600);
  
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
  //SWP
  odom_constants();
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
  chassis.drive_to_point(28, 36, 7, 0);


}


void redRightQual(){
  odom_constants();
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
  scoring_mech.move2(600);


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
  pros::delay(1000);
  chassis.drive_to_point(0, 96, 3, 0, 1, 200, 5000);*/
  //scoring_mech.intake_move(600);
  
  odom_constants();
  chassis.set_coordinates(11, -3, 121.326);
  scoring_mech.move2(600);
  pros::delay(500);
  scoring_mech.move2(-600);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 470);
  scoring_mech.set_brake_mode('C');
  chassis.turn_to_point(13, -34, 0, 12, 1, 175, 470);
  chassis.drive_to_point(-2, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(250);
  scoring_mech.move2(0);
  chassis.turn_to_point(-18, 50, 0, 9, 1, 200, 1050);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-18, 50);
  chassis.turn_to_point(-27, 50.5);
  pros::delay(25);
  chassis.drive_to_point(-27, 50.5);
  pros::delay(200);
  //chassis.drive_to_point(-36, 49);
  //pros::delay(400);

  //scoring_mech.intake_move(-600);
  //scoring_mech.intake_move(0);
  chassis.drive_to_point(-18, 50);
  //1```````````````````````````````````````````````````````````````````````````````scoring_mech.intake_move(600);
  chassis.turn_to_point(-21, 39);
  //scoring_mech.intake_move(600);
  chassis.drive_to_point(-21, 39);
  chassis.drive_to_point(-18, 50);
  chassis.turn_to_point(-24, -2);
  //pros::delay(150);
  //chassis.drive_to_point(-24, -3);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  //scoring_mech.intake_move(-600);
  chassis.drive_to_point(-48, -12, 7.5, 0, 1, 200, 600);
  pros::delay(400);
  chassis.drive_to_point(-24, -8);
  chassis.turn_to_point(12, 12, 0, 13, 1, 200, 1050);
  chassis.drive_to_point(12, 12);















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
  odom_constants();
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
  chassis.turn_to_point(17.25, 39.5, 0, 10, 1, 200, 950);
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
  scoring_mech.move2(0);
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
  chassis.drive_to_point(-31, 36);

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
  scoring_mech.move2(0);







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
  chassis.drive_to_point(43, 3, 5, 0, 1, 200, 2000);
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
  scoring_mech.move2(54);
  pros::delay(350);
  scoring_mech.move2(0);
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
    scoring_mech.move2(70);
  }
  scoring_mech.move2(0);

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
  odom_constants();
  chassis.set_brake_mode(MOTOR_BRAKE_COAST);
  chassis.drive_timeout = 850;
  chassis.turn_timeout = 760;
  chassis.drive_max_voltage = 13;
  chassis.turn_max_voltage = 12;
  chassis.drive_settle_time = 85;
  chassis.turn_settle_time = 105;
  chassis.turn_max_voltage = 10;

  chassis.set_coordinates(0, -61, 0); //the middle of the field is 0,0
  scoring_mech.intake_move(600);
  pros::delay(300);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(0, -48);
  chassis.turn_to_point(-24, -48, 2, 13, 3, 250, 1000, 0.33, 0, 1.2, 0);
  chassis.drive_to_point(24, -48, 6, 0);
  pneumatics.clench_v(1);
  pros::delay(25);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(24, -24);
  chassis.drive_to_point(24, -24); //first ring
  pros::delay(25);
  chassis.turn_to_point(48, -24);
  chassis.drive_to_point(50, -24); //second ring
  pros::delay(25);
  chassis.turn_to_point(58, 0);
  scoring_mech.move1(); //two method calls so that first one works
  scoring_mech.move1();      //you can replace with your own method
  chassis.drive_to_point(58, 0);                                                  //overshoots y
  chassis.turn_to_point(72,-4); //THIS IS ALL REALLY SLOW SO CHANGE !
  //start neutral stake
  chassis.drive_to_point(63.5, 0);  //I ONLY DID THIS FOR ACCURACYs
  scoring_mech.intake_move(-600);
  pros::delay(200);
  scoring_mech.intake_move(0);
  scoring_mech.move2(-600);
  pros::delay(600);
  scoring_mech.move2(0);
  scoring_mech.move2(600);
  chassis.drive_distance(-10);
  pros::delay(100);
  scoring_mech.intake_move(600);
  //end neutral stake
  chassis.turn_to_point(47, -48, 2, 10, 3, 150, 1500, 0.32, 0, 1.2, 0); 
  chassis.drive_to_point(47, -48, 10, 1, 1, 50, 1000);
  pros::delay(50);
  chassis.drive_to_point(47, -63, 6, 0.75);
  pros::delay(25);
  chassis.turn_to_point(60, -52);
  chassis.drive_to_point(60, -52);
  scoring_mech.move2(0);
  pros::delay(25);
  chassis.turn_to_point(48, -24);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(60, -60);
  pros::delay(25);
  pneumatics.clench_v(0);
  pros::delay(25);
  chassis.drive_distance(8, 6);
  chassis.turn_to_point(48, -48);
  chassis.drive_to_point(48, -48);
  chassis.turn_to_point(100, -48, 1, 10, 3, 250, 1200, 0.33, 0, 1.2, 0);
  chassis.drive_to_point(-15, -48, 8, 0, 1, 150, 1800); //drive to second quadrant
  chassis.drive_distance(-7, 6, 1, 150, 1300, 0.58, 0, 0.43, 0); 
  chassis.set_coordinates(-24, -48, chassis.get_absolute_heading());
  pros::delay(100);
  pneumatics.clench_v(1);
  scoring_mech.intake_move(600);

  //start scoring for second quadrant
  pros::delay(25);
  chassis.turn_to_point(-24, -24);
  chassis.drive_to_point(-24, -24, 10, 0, 1, 250, 1000);
  pros::delay(25);
  chassis.turn_to_point(-48, -24);
  chassis.drive_to_point(-48, -24);
  pros::delay(25);
  chassis.turn_to_point(-58, 0);
  chassis.drive_to_point(-58, 0);
  pros::delay(25);
  chassis.drive_distance(-5);
  chassis.turn_to_point(-45, -48, 0, 8, 1, 100, 1200);
  chassis.drive_to_point(-45, -48, 10, 0.05, 1, 100, 1000);
  pros::delay(25);
  chassis.drive_to_point(-45, -61, 6, 0.1);
  pros::delay(25);
  chassis.turn_to_point(-60, -52);
  chassis.drive_to_point(-62, -50);
  pros::delay(25);
  chassis.drive_distance(-5, 6);
  chassis.turn_to_point(-36, -36);
  chassis.drive_to_point(-66, -66);
  scoring_mech.intake_move(0);
  pneumatics.clench_v(0);
  chassis.set_coordinates(-58, -60, chassis.get_absolute_heading());
  pros::delay(100);

  chassis.turn_to_point(-47, -50);
  chassis.drive_to_point(-47, -50, 8, 0, 1, 50, 1000);
  chassis.turn_to_point(-48, 24, 0, 8, 1, 100, 1000);
  scoring_mech.intake_move(600);
  scoring_mech.move1(); //change with your own code and only call the method once!
  scoring_mech.move1();
  scoring_mech.move1();
  scoring_mech.move1();
  chassis.drive_to_point(-48, 24, 11, 0.05, 1, 100, 1350);
  pros::delay(120);

  //start of neutral stake
  chassis.turn_to_point(-48,0);
  chassis.drive_to_point(-48, -3, 8, 0.0, 1, 100, 1200);
  chassis.turn_to_point(-72, -2);
  chassis.drive_to_point(-63, 0);
  scoring_mech.intake_move(-600);
  pros::delay(200);
  scoring_mech.intake_move(0);
  scoring_mech.move2(-600);
  pros::delay(600);
  scoring_mech.move2(0);
  scoring_mech.move2(600);
  chassis.drive_distance(-10);
  pros::delay(100);
  scoring_mech.intake_move(600);
  //end of neutral stake

  chassis.turn_to_point(-49, 48);
  chassis.drive_to_point(-49, 46, 8, 0.1, 1, 100, 1000);
  scoring_mech.move2(0);
  pros::delay(175);
  scoring_mech.intake_move(0);
  
  //--can insert supplement code here if needed--//   
  
  chassis.turn_to_point(-72, 25); 
  chassis.drive_to_point(-26, 55, 8, 0);
  
  pros::delay(50);
  pneumatics.clench_v(1);               //get blue goal
  pros::delay(50);
  chassis.turn_to_point(-63, 63, 1, 8);
  pneumatics.doinker_v(1);
  chassis.drive_to_point(-58, 62, 12, 0.1, 1, 50, 1000);
  chassis.turn_to_point(0, 0, 0, 10, 1, 50, 1500);
  chassis.turn_to_angle(135);           //sweep out rings
  chassis.drive_to_point(-61, 61);
  pneumatics.clench_v(0);
  pros::delay(50);
  chassis.turn_to_point(-48, 48);
  chassis.drive_to_point(-48,48);
  chassis.turn_to_point(-100, 49);
  chassis.drive_to_point(0,49, 10, 0, 1, 100, 1200);
  pneumatics.clench_v(1);
  pros::delay(75);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(48, 48);
  chassis.drive_to_point(48, 48);
  pros::delay(25);
  
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.turn_to_point(72,66);
  chassis.drive_to_point(68, 57);
  chassis.turn_to_point(0,0);
  pneumatics.clench_v(0);//drop off last goal


  //----SUPPLEMENT CODE----//
  /* This is for getting that blue goal using doinker instead of using clamp
  chassis.turn_to_point(-24, 60);
  pneumatics.doinker_v(1);
  chassis.drive_to_point(-29, 54);
  chassis.turn_to_point(-60, 60, 0, 6, 1, 75, 1000);
  pneumatics.doinker_v(0);
  chassis.drive_to_point(-55, 60,11, 0, 1, 50, 1275);
  chassis.drive_distance(-10);*/
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
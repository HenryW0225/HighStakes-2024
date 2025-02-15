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
  //SWP
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(11, -3, 0, 6, 1, 500, 1000);
  pros::delay(1000);
  chassis.drive_to_point(11, -3, 6, 0, 1, 500, 1000);
  pros::delay(1000);
  chassis.turn_to_angle(120);*/

  //rush
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(13, 0, 6, 0);
  chassis.turn_to_angle(20, 6);
}

void redLeftQual(){
  //SWP
  odom_constants();
  chassis.set_coordinates(11, -3, 121.326);
  neutral_stake.move2(600);
  pros::delay(500);
  neutral_stake.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 500);
  neutral_stake.move2(-600);
  neutral_stake.set_brake_mode('C');
  pros::delay(25);
  chassis.turn_to_point(15.8, -34, 0, 12, 1, 175, 500);
  neutral_stake.move2(0);
  chassis.drive_to_point(-4, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(-24, 46.5);
  intake.move(600);
  chassis.drive_to_point(-24, 46.5, 9, 0);
  pros::delay(50);
  chassis.turn_to_point(-24, 38);
  pros::delay(300);
  chassis.drive_to_point(-24, 38);
  pros::delay(100);
  chassis.turn_to_point(20, 14);
  chassis.drive_to_point(9, 20);
  pneumatics.clench_v(0);
  chassis.drive_to_point(20, 14, 12, 0, 1, 125, 325);
  pros::delay(200);
  intake.move(140);
  chassis.drive_to_point(26, 2, 13, 0, 1, 150, 930);
  intake.move(8);
  chassis.turn_to_point(4, -36);
  chassis.drive_to_point(48, 36, 6.7, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(300);
  chassis.turn_to_point(65, 34);
  intake.move(600);
  pros::delay(50);
  chassis.drive_to_point(65, 34);
  intake.move(25);
  chassis.turn_to_point(31, 36, 0, 13, 1, 250, 1000);
  intake.move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(31, 36, 11, 0);


}


void redRightQual(){

  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  chassis.turn_to_angle(-34,12);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  neutral_stake.move2(600);
  pros::delay(500);
  neutral_stake.move2(-600);
  chassis.drive_distance(-10,12);
  neutral_stake.move2(0);
  chassis.set_coordinates(0, 0, 326);
  pros::delay(50);
  chassis.turn_to_point(1.75,18,0,14,1,50,600);
  chassis.drive_to_point(2,7.5,14,0,1,50,375);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(-1,-5.5,14,0, 1, 150, 650);
  pneumatics.doinker_v(0);
  intake.move(130);
  chassis.turn_to_point(8,13,0,14,1,50,250);
  chassis.drive_to_point(8,13.6,14,0,1,300,750);
  pros::delay(30);
  intake.move(1);
  chassis.turn_to_point(-36, 58,0,11,1,300,850);
  intake.move(-200);
  pros::delay(120);
  intake.move(1);
  //pros::delay(5);
  chassis.drive_to_point(24, -6, 5.5,0,1,300,1100);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(400);
  //intake.move(0);
  chassis.turn_to_point(26, -31,0,14,1,300,700);
  intake.move(600);
  pros::delay(1200);
  chassis.drive_to_point(26,-31,10,0);
  pros::delay(1200);
  chassis.turn_to_point(36, 22);
  neutral_stake.move2(45);
  chassis.drive_to_point(36, 22, 5.5, 0, 1, 200, 3000);

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
  
  intake.move(600);
  pros::delay(1000);
  chassis.drive_to_point(0, 96, 3, 0, 1, 200, 5000);*/
  //intake.move(600);
  
  odom_constants();
  chassis.set_coordinates(11, -3, 121.326);
  neutral_stake.move2(600);
  pros::delay(475);
  neutral_stake.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 470);
  neutral_stake.move2(-600);
  neutral_stake.set_brake_mode('C');
  chassis.turn_to_point(15.8, -34, 0, 12, 1, 175, 470);
  chassis.drive_to_point(-4, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(175);
  neutral_stake.move2(0);
  chassis.turn_to_point(-18, 50, 0, 9, 1, 200, 1050);
  intake.move(600);
  chassis.drive_to_point(-18, 50);
  chassis.turn_to_point(-27, 50);
  pros::delay(25);
  chassis.drive_to_point(-27, 50);
  pros::delay(200);
  //chassis.drive_to_point(-36, 49);
  //pros::delay(400);

  //intake.move(-600);
  //intake.move(0);
  chassis.drive_to_point(-18, 50);
  //1```````````````````````````````````````````````````````````````````````````````intake.move(600);
  chassis.turn_to_point(-24, 36);
  //intake.move(600);
  chassis.drive_to_point(-24, 36);
  chassis.turn_to_point(-24, -2);
  //pros::delay(150);
  //chassis.drive_to_point(-24, -3);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  //intake.move(-600);
  chassis.drive_to_point(-48, -12, 7.5, 0, 1, 200, 600);
  pros::delay(400);
  chassis.drive_to_point(-24, -8);
  chassis.turn_to_point(12, 12, 0, 13, 1, 200, 1050);
  chassis.drive_to_point(12, 12);















  /*odom_constants();
  chassis.set_coordinates(11, -3, 120);
  neutral_stake.move2(600);
  pros::delay(625);
  neutral_stake.move2(-600);
  pros::delay(200);
  //pros::delay(10);
  chassis.drive_to_point(5.9, 0, 13, 0, 1, 150, 500);
  neutral_stake.move2(0);
  chassis.turn_to_point(15.8, -34, 0, 12, 1, 175, 500);
  chassis.drive_to_point(-4, 34, 6.1, 0);
  pros::delay(40);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(-15, 50, 0, 9, 1, 200, 1100);
  intake.move(600);
  chassis.drive_to_point(-15, 50);
  chassis.turn_to_point(-24, 49);
  chassis.drive_to_point(-24, 49);
  pros::delay(200);
  chassis.drive_to_point(-34, 49);
  pros::delay(250);
  intake.move(-600);
  //intake.move(0);
  chassis.drive_to_point(-15, 50);
  intake.move(600);
  chassis.turn_to_point(-24, 36);
  //intake.move(600);
  chassis.drive_to_point(-24, 36);
  pros::delay(75);
  //chassis.drive_to_point(-24, -3);
  chassis.turn_to_point(-24, -2);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  intake.move(-600);
  chassis.drive_to_point(-48, -12, 5, 0, 1, 200, 650);
  pros::delay(50);
  intake.move(600);
  pros::delay(150);
  chassis.drive_to_point(-24, -8);
  pros::delay(50);
  chassis.drive_to_point(-48, -12, 1.5, 0, 1, 200, 500);
  pros::delay(125);
  chassis.turn_to_point(12, 0);
  chassis.drive_to_point(12, 0);*/






  /*odom_constants();
  chassis.set_coordinates(-11, -3, 240);
  neutral_stake.move2(600);
  pros::delay(650);
  neutral_stake.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(-5.9, 0, 13, 0, 1, 150, 500);
  neutral_stake.move2(-600);
  pros::delay(150);
  neutral_stake.set_brake_mode('C');
  chassis.turn_to_point(-15.8, -34, 0, 12, 1, 175, 500);
  neutral_stake.move2(0);
  chassis.drive_to_point(4, 34, 6.1, 0);
  pros::delay(40);
  pneumatics.clench_v(1);
  pros::delay(250);
  chassis.turn_to_point(15, 50, 0, 9, 1, 200, 1100);
  intake.move(600);
  chassis.drive_to_point(15, 50);
  chassis.turn_to_point(24, 49);
  chassis.drive_to_point(24, 49);
  pros::delay(400);
  chassis.drive_to_point(34, 49);
  pros::delay(600);
  intake.move(-600);
  //intake.move(0);
  chassis.drive_to_point(15, 50);
  intake.move(600);
  chassis.turn_to_point(24, 36);
  //intake.move(600);
  chassis.drive_to_point(24, 36);
  pros::delay(150);
  //chassis.drive_to_point(-24, -3);
  chassis.drive_to_point(-24, -2);
  chassis.turn_to_point(-48, -12);
  intake.move(-600);
  chassis.drive_to_point(-48, -12, 5, 0, 1, 200, 650);
  pros::delay(50);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(-24, -8);
  pros::delay(50);
  chassis.drive_to_point(-48, -12, 1.5, 0, 1, 200, 500);*/









  /*
  chassis.drive_to_point(9, 19);
  pneumatics.clench_v(0);
  chassis.drive_to_point(20, 12, 12, 0, 1, 125, 325);
  pros::delay(225);
  intake.move(240);
  chassis.drive_to_point(26, 0, 13, 0, 1, 150, 950);
  intake.move(0);
  chassis.turn_to_point(9, -34);
  chassis.drive_to_point(44, 34, 6.1, 0);
  //pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(270);
  chassis.turn_to_point(65, 34);
  intake.move(600);
  //pros::delay(100);
  chassis.drive_to_point(65, 34);
  intake.move(2);
  chassis.turn_to_point(31, 36, 0, 13, 1, 250, 1000);
  intake.move(600);
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
  intake.move(600);
  chassis.drive_to_point(18, -49);
  pros::delay(325);
  chassis.turn_to_point(27, -52.5);
  chassis.drive_to_point(27, -52.5);
  pros::delay(450);
  chassis.turn_to_point(24, -36);
  chassis.drive_to_point(24, -36);
  pros::delay(350);
  intake.move(-400);
  chassis.drive_to_point(24, 0);*/
}


void redRightElim(){
  odom_constants();
  chassis.set_coordinates(-22,2,20);
  pros::delay(25);
  neutral_stake.move2(108);
  //intake.move(600);
  chassis.drive_to_point(0, 36, 13, 0, 1, 200, 1000);
  pros::delay(200);
  //neutral_stake.move2(-40);
  //chassis.turn_to_angle(280,14,1,150,500,0.277,0,0.81,15);
  chassis.turn_to_point(24, 54);
  pros::delay(125);
  chassis.drive_to_point(-24, 24, 6, 0, 1, 250, 500);
  neutral_stake.move2(-200);
  pros::delay(50);
  pneumatics.clench_v(1); 
  pros::delay(300);
  intake.move(600);
  chassis.turn_to_point(4, 30, 0, 13, 1, 200, 500);
  chassis.drive_to_point(4, 30, 13, 0, 1, 200, 650);
  //pros::delay(100);
  chassis.drive_to_point(-10, 27, 13, 0, 1, 200, 500);
  pros::delay(350);
  pneumatics.clench_v(0);
  chassis.drive_to_point(4, 30, 13, 0, 1, 200, 600);
  chassis.turn_to_point(18, 0, 0, 13, 1, 200, 700);
  //neutral_stake.move2(-115);
  chassis.drive_to_point(18, 0);
  //intake.move(-600);
  //pros::delay(100);
  //neutral_stake.move2(0);
  intake.move(600);
  chassis.drive_to_point(24, -24, 5, 0, 1, 200, 900);
  //pros::delay(100);
  //intake.move(600);
  pros::delay(75);
  intake.move(0);
  chassis.drive_to_point(16, 0, 13, 0, 1, 200, 850);
  neutral_stake.move2(45);
  //pros::delay(200);
  chassis.turn_to_point(21, 43, 0, 10, 1, 200, 950);
  neutral_stake.move2(0);
  intake.move(300);
  chassis.drive_to_point(21, 43, 8, 0, 1, 200, 1200);
  intake.move(0);
  chassis.turn_to_point(25, 56, 0, 9, 1, 200, 1000);
  chassis.drive_distance(3);
  intake.move(-120);
  pros::delay(120);
  intake.move(0);
  pros::delay(100);
  neutral_stake.move2(600);
  //chassis.drive_to_point(20, -12, 1, 0, 1, 200, 325);
  //pros::delay(500);
  /*
  intake.move(0);
  chassis.turn_to_point(13, -24);
  chassis.drive_to_point(16, 0);
  pneumatics.clench_v(0);
  pros::delay(50);
  chassis.turn_to_point(0, 0);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(0, -24);
  chassis.drive_to_point(0, 34);
  neutral_stake.move2(-600);
  chassis.turn_to_point(4, 26);
  pros::delay(150);
  neutral_stake.move2(0);*/

  
  
  
  
  
  /*

  chassis.drive_distance(8,14);
  intake.move(600);
  pros::delay(800);
  chassis.drive_to_point(0,10,14,0,1,200,600);
  chassis.drive_distance(8,0,14,0);
  chassis.drive_distance(-15);
  pros::delay(1000);
  neutral_stake.move2(100);
  pneumatics.clench_v(0);
  chassis.turn_to_point(24,-35,0,14,1,150,600);
  chassis.drive_distance(-25,14);*/

  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 345);
  intake.move(600);
  chassis.drive_to_point(0, 36,10,0);
  pneumatics.doinker_v(1);
  intake.move(5);
  chassis.drive_to_point(0, 15,14,0);
  pros::delay(200);
  pneumatics.doinker_v(0);
  pros::delay(200);
  chassis.turn_to_point(0, -10, 0,14);
  pros::delay(50);
  chassis.drive_to_point(-10, 40,14,0);
  pneumatics.clench_v(1);
  intake.move(600);
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
  intake.move(600);
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
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -30);
  chassis.drive_to_point(-24, -30);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  intake.move(0);
  pros::delay(500);
  chassis.turn_to_point(-24, -16);
  pros::delay(200);
  chassis.drive_distance(-16);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(24, -4);
  chassis.drive_to_point(-3, 1);*/
}


void blueRightQual(){
  odom_constants();
  chassis.set_coordinates(-11, -3, 240);
  neutral_stake.move2(600);
  pros::delay(625);
  neutral_stake.move2(0);
  //pros::delay(10);
  chassis.drive_to_point(-5.9, 0, 13, 0, 1, 150, 550);
  neutral_stake.move2(-500);
  neutral_stake.set_brake_mode('C');
  chassis.turn_to_point(-15.8, -34, 0, 12, 1, 175, 500);
  neutral_stake.move2(0);
  chassis.drive_to_point(4, 34, 6.1, 0);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(180);
  chassis.turn_to_point(25.5, 44);
  intake.move(600);
  chassis.drive_to_point(25.5, 44, 8, 0);
  pros::delay(200);
  chassis.turn_to_point(24.5, 38);
  chassis.drive_to_point(24.5, 38);
  pros::delay(125);
  chassis.turn_to_point(-20, 12);
  chassis.drive_to_point(-9, 19);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-20, 12, 12, 0, 1, 125, 325);
  pros::delay(225);
  intake.move(240);
  chassis.drive_to_point(-26, 0, 13, 0, 1, 150, 950);
  intake.move(0);
  chassis.turn_to_point(-9, -34);
  chassis.drive_to_point(-44, 34, 6.1, 0);
  //pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(270);
  chassis.turn_to_point(-65, 34);
  intake.move(600);
  //pros::delay(100);
  chassis.drive_to_point(-65, 34);
  intake.move(2);
  chassis.turn_to_point(-31, 36, 0, 13, 1, 250, 1000);
  intake.move(600);
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
  intake.move(-120);
  pros::delay(375);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 5, 14, 0, 1, 400, 800);
  chassis.turn_to_point(78, 54);
  intake.move(-120);
  chassis.drive_to_point(78, 54, 14, 0, 1, 200, 1000);
  pros::delay(150);
  intake.move(0);
  chassis.turn_to_point(150, 54);
  chassis.drive_to_point(44, 54, 14, 0,1, 400, 800);
  pneumatics.clench_v(1);
  intake.move(-120);
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
  //2 ring
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.set_turn_exit_conditions(1, 50, 250);
  //pros::delay(2000);
  chassis.turn_to_angle(36,14);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  neutral_stake.move2(500);
  pros::delay(525);

  neutral_stake.move2(-600);
  //pros::delay(200);
  chassis.drive_distance(-10,14);
  neutral_stake.move2(0);
  chassis.set_coordinates(0, 0, 36);
  pros::delay(50);
  chassis.turn_to_point(-11,18,0,14,1,50,475);
  chassis.drive_to_point(-9,4,14,0,1,50,300);
  neutral_stake.move2(0);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(2,-2,14,0);
  pneumatics.doinker_v(0);
  intake.move(165);
  chassis.turn_to_point(-4.5,16,0,14,1,50,250);
  chassis.drive_to_point(-4.5,16,14,0,1,300,700);
  intake.move(2);
  chassis.turn_to_point(36, 44.5,0,14,1,300,700);
  intake.move(-300);
  pros::delay(60);
  intake.move(2);
  chassis.drive_to_point(-27, -7.5, 6.25,0,1,300,1300);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(300);
  //intake.move(0);
  chassis.turn_to_point(-28, -32,0,14);
  intake.move(600);
  pros::delay(500);
  chassis.drive_to_point(-28, -32,14,0);
  pros::delay(700);
  chassis.turn_to_point(-34, 22);
  neutral_stake.move2(45);
  chassis.drive_to_point(-34, 22, 5.5, 0, 1, 200, 2750);
}


void blueRightElim(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.right_swing_to_angle(326,14);
  neutral_stake.move2(600);
  pros::delay(525);
  neutral_stake.move2(-600);
  chassis.drive_distance(-10,14);
  chassis.set_coordinates(0, 0, -34);
  pros::delay(15);
  chassis.turn_to_point(1.5,18,0,14,1,50,300);
  neutral_stake.move2(0);
  chassis.drive_to_point(3.5,6,14,0,1,50,250);
  pneumatics.doinker_v(1);
  pros::delay(100);
  chassis.drive_to_point(-1,-3,14,0, 1, 150, 400);
  pneumatics.doinker_v(0);
  intake.move(600);
  pros::delay(50);
  chassis.turn_to_point(7,11.6,0,14,1,50,250);
  chassis.drive_to_point(7,11.6,14,0);
  //chassis.drive_to_point(6,8,14,0,1,50,250);
  intake.move(10);
  chassis.turn_to_point(-36, 48,0,11,1,300,700);
  pros::delay(5);
  chassis.drive_to_point(21, -2, 4,0,1,300,1250);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(125);
  chassis.turn_to_point(23.5, -31,0,14,1,300,700);
  pros::delay(100);
  intake.move(600);
  chassis.drive_to_point(23.5,-31,10,0);
  pros::delay(1500);
  chassis.drive_to_point(23.5, 12);

  chassis.turn_to_point(1.5, -32.5, 0,14,1,300,700);
  intake.move(-600);
  chassis.drive_to_point(1.5,-32.5,14,0);
  chassis.turn_to_point(-15, -47,0,14,1,300,700);
  chassis.drive_to_point(-15,-47, 6,0,1,300,400);
  pros::delay(50);
  intake.move(600);
  pros::delay(150);
  chassis.set_brake_mode('C');
  chassis.turn_to_point(-10.3, -47);
  neutral_stake.move2(600);
  pros::delay(345);
  neutral_stake.move2(0);
  chassis.drive_to_point(43, 3, 5, 0, 1, 200, 2000);
}



void blueLeftElim() {
  //not mirrored
  odom_constants();
  chassis.turn_to_angle(315);
  chassis.drive_distance(-53);
  chassis.drive_distance(4);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-17, 6);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(400);
  chassis.drive_distance(24);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-12);
  pneumatics.clench_v(0);
  chassis.drive_distance(14);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-18);
  pneumatics.clench_v(1);
  pros::delay(500);
  chassis.drive_distance(16);
}


void skills() {
  odom_constants();
  chassis.set_brake_mode(MOTOR_BRAKE_COAST);
  chassis.drive_timeout = 900;
  chassis.turn_timeout = 750;
  chassis.drive_max_voltage = 10;
  chassis.turn_max_voltage = 10;
  chassis.set_coordinates(0, -60, 0);
  intake.move(600);
  pros::delay(350);
  intake.move(0);
  chassis.drive_to_point(0, -48);
  intake.move(600);
  chassis.turn_to_point(-24, -48, 2, 10, 3, 250, 1500, 0.33, 0, 1.2, 0);
  chassis.drive_to_point(24, -48, 6, 0);
  pneumatics.clench_v(1);
  pros::delay(75);
  chassis.turn_to_point(24, -24);
  chassis.drive_to_point(24, -24); //first ring
  pros::delay(75);
  chassis.turn_to_point(48, -24);
  chassis.drive_to_point(50, -25); //second ring
  pros::delay(150);
  chassis.turn_to_point(59, 0);
  neutral_stake.move1();
  neutral_stake.move1();
  neutral_stake.move2(0);
  //driving to neutral stake
  chassis.drive_to_point(59, 0);
  chassis.turn_to_point(100, 0);
  chassis.drive_to_point(62, 0);
  chassis.turn_to_point(72,0);
  chassis.drive_to_point(65,0);
  intake.move(0);
  intake.move(-600);
  pros::delay(200);
  intake.move(0);
  neutral_stake.move2(600);
  pros::delay(650);
  neutral_stake.move2(0);
  pros::delay(50);
  neutral_stake.move2(-600);
  pros::delay(725);
  neutral_stake.move2(0);
  intake.move(600);
  chassis.drive_to_point(59, 0);
  pros::delay(100);
  chassis.turn_to_point(46, 26);
  chassis.drive_to_point(46, 26); //third ring 
  pros::delay(15);
  chassis.turn_to_point(48, -48, 2, 8, 3, 150, 3000, 0.37, 0, 1.2, 0);
  chassis.drive_to_point(48, -48, 9, 0);
  pros::delay(15);
  chassis.drive_to_point(48, -60, 6, 0);
  pros::delay(15);
  chassis.turn_to_point(60, -48);
  chassis.drive_to_point(60, -48);
  pros::delay(15);
  chassis.turn_to_point(48, -24);
  intake.move(0);
  chassis.drive_to_point(64, -64);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_distance(8, 6);
  chassis.turn_to_point(48, -48);
  chassis.drive_to_point(48, -48);
  chassis.turn_to_point(100, -48, 1, 6, 3, 250, 2000, 0.33, 0, 1.2, 0);
  chassis.drive_to_point(-24, -28, 7.5, 0, 1.5, 150, 3000); //drive to second quadrant
  pneumatics.clench_v(1);
  intake.move(600);
  //start scoring for second quadrant
  pros::delay(15);
  chassis.turn_to_point(-24, -24);
  chassis.drive_to_point(-24, -24, 10, 0, 1, 250, 1500);
  pros::delay(15);
  chassis.turn_to_point(-48, -20);
  chassis.drive_to_point(-48, -20);
  pros::delay(15);
  chassis.turn_to_point(-59, 0);
  neutral_stake.move1();
  neutral_stake.move1();
  chassis.drive_to_point(-59, 0, 8, 1, 250, 1500, 0.58, 0, 0.43, 0);

  //second quardrant neutral stake starts here
  //TAKE OUT IF INCONSISTENT!!!!
  /*chassis.turn_to_point(-100, 0);
  chassis.drive_to_point(-62, 0);
  chassis.turn_to_point(-72,0);
  chassis.drive_to_point(-67,0);
  intake.move(0);
  intake.move(-600);
  pros::delay(200);
  intake.move(0);
  neutral_stake.move2(-600);
  pros::delay(650);
  neutral_stake.move2(0);
  pros::delay(50);
  neutral_stake.move2(600);
  pros::delay(725);
  neutral_stake.move2(0);
  intake.move(600);
  chassis.drive_to_point(-59, 0);
  pros::delay(100);
  chassis.turn_to_point(-48, 24);
  chassis.drive_to_point(-48, 24);
  pros::delay(75);*/
  //second quadrant neutral stake stops here
  
  //going for 3 things in the corner
  chassis.turn_to_point(-48, -48, 2, 8, 3, 150, 3000, 0.37, 0, 1.2, 0);
  chassis.drive_to_point(-48, -48);
  pros::delay(15);
  chassis.drive_to_point(-48, -60, 6, 0);
  pros::delay(15);
  chassis.turn_to_point(-60, -48);
  chassis.drive_to_point(-65, -43);
  pros::delay(15);
  chassis.drive_distance(-5, 6);
  chassis.turn_to_point(-48, -24);
  intake.move(0);
  chassis.drive_to_point(-66, -66);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_distance(10);
  chassis.turn_to_point(-66, -66);
  neutral_stake.move2(100);
  pros::delay(550);
  neutral_stake.move2(0);
  chassis.drive_to_point(-10,10);
  neutral_stake.move2(-100);
  pros::delay(250);
  neutral_stake.move2(0);
}


void blueSWPGoal(){
  chassis.drive_to_point(0, 8, 14, 0, 1, 200, 500);
  //intake.move(400);
  chassis.drive_to_point(0, 18, 14, 0, 1, 200, 500);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(-60, 40, 0, 14, 1, 500, 700);
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-24, 24, 14, 0, 1, 500, 700);
  pros::delay(100);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(1000);
  chassis.turn_to_point(-48, 20, 0, 14, 1, 500, 700);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-48, 20, 14, 0, 1, 500, 700);
  pros::delay(600);
  intake.move(0);
  chassis.turn_to_point(-40, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-48, 41, 14, 0, 1, 500, 700);
  pneumatics.clench_v(1);
  pros::delay(400);
  intake.move(600);
  chassis.drive_to_point(-48, 14, 14, 0, 1, 500, 700);
  pneumatics.clench_v(0);
  pros::delay(200);
  chassis.turn_to_point(45,-20, 0, 14, 1, 500, 700);
  intake.move(-600);
  chassis.drive_to_point(45,-20, 14, 0, 1, 500, 700);
  chassis.turn_to_point(40,29);
  intake.move(600);
  chassis.drive_to_point(40,29, 14, 0);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(100,20);
  chassis.drive_to_point(24,26);
  pneumatics.clench_v(1);
  intake.move(600);
  chassis.drive_to_point(0,48);
}
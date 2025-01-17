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
  chassis.set_drive_exit_conditions(2, 50, 1000);
  chassis.set_turn_exit_conditions(4, 50, 1000);
  chassis.set_swing_exit_conditions(2, 50, 1000);
}


/*void new_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .39, .017, 3.3, 15);
  chassis.set_swing_constants(14, 0.25, .01, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 20, 3000);
  chassis.set_turn_exit_conditions(3, 15, 1000);
  chassis.set_swing_exit_conditions(3, 25, 3000);
}*/

void odom_constants(){
  default_constants();
  /*chassis.drive_max_voltage = 14;
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

  //speed = 9
  chassis.drive_max_voltage = 6;
  chassis.drive_kp = 0.52;
  chassis.drive_kd = 0.43;
  chassis.drive_settle_error = 1;
  chassis.drive_settle_time = 350;
  chassis.turn_max_voltage = 6;
  chassis.turn_kp = 0.16;
  chassis.turn_ki = 0;
  chassis.turn_kd = 1;
  chassis.turn_settle_error = 1;
  chassis.turn_settle_time = 500;

  //new constants; speed = 6
  /*chassis.drive_max_voltage = 6;
  chassis.drive_kp = 0.52;
  chassis.drive_kd = 0.43;
  chassis.drive_settle_error = 1;
  chassis.drive_settle_time = 350;
  chassis.turn_max_voltage = 6;
  chassis.turn_kp = 0.16;
  chassis.turn_ki = 0;
  chassis.turn_kd = 1;
  chassis.turn_settle_error = 1;
  chassis.turn_settle_time = 500;*/


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
  chassis.turn_settle_time = 50;*/


  /*
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
  chassis.turn_settle_time = 50;
  */

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


  /*odom_constants();
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, 0, 0, 6);
  pros::delay(1000);
  chassis.turn_to_point(0, -24, 0, 6);
  pros::delay(1000);
  chassis.turn_to_point(-24, 0, 0, 6);
  pros::delay(1000);
  chassis.turn_to_point(0, 24, 0, 6);*/

  
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

void redLeftQual(){
  //SWP
  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  //chassis.drive_to_point(0, 19);
  chassis.left_swing_to_angle(49);
  //chassis.left_swing_to_point(9, 32);
  neutral_stake.move2(600);
  pros::delay(600);
  neutral_stake.move2(-600);
  pros::delay(15);
  chassis.turn_to_point(36, 28);
  chassis.drive_to_point(-35, 0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-35, -20);
  intake.move(600);
  chassis.drive_to_point(-35, -20);
  pros::delay(10);
  intake.move(0);
  chassis.turn_to_point(-12, 0);
  intake.move(600);
  chassis.drive_to_point(-12, 0);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-12, 24);
  chassis.drive_to_point(-12, 24);
  pros::delay(75);
  chassis.drive_to_point(-12, 36);
  pros::delay(25);
  intake.move(0);
  chassis.turn_to_point(12, 24);
  chassis.drive_to_point(-32, 46);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-36, 72);
  intake.move(600);
  pros::delay(25);
  chassis.drive_to_point(-36, 72);
  pros::delay(40);
  intake.move(0);
  chassis.turn_to_point(-36, 24);
  intake.move(600);
  chassis.drive_to_point(-36, 28);


  /*
  chassis.turn_to_point(-50, -22);
  intake.move(600);
  chassis.drive_to_point(-53, -20);
  pros::delay(300);
  chassis.turn_to_point(-54, -26);
  chassis.drive_to_point(-54, -26);
  pros::delay(350);
  chassis.turn_to_point(-30, -24);
  chassis.drive_to_point(-30, -24);
  pros::delay(125);
  intake.move(0);
  chassis.turn_to_point(-18, 24);
  chassis.drive_to_point(-24, 0);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_to_point(-18, 24);
  chassis.turn_to_point(0, 0);
  chassis.drive_to_point(-36, 48);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-36, 72);
  intake.move(600);
  chassis.drive_to_point(-36, 72);
  pros::delay(150);
  intake.move(0);
  chassis.turn_to_point(-36, 0);
  intake.move(600);
  chassis.drive_to_point(-36, 24, 7, 0);
  pneumatics.clench_v(0);*/


  //SWP
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -36.5);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -60);
  intake.move(600);
  chassis.drive_to_point(17, -53);
  pros::delay(400);
  chassis.turn_to_point(24, -54);
  chassis.drive_to_point(24, -54);
  pros::delay(400);
  chassis.turn_to_point(24, -41);
  chassis.drive_to_point(24, -41);
  pros::delay(200);
  intake.move(0);
  chassis.turn_to_point(0, -9);
  intake.move(600);
  chassis.drive_to_point(0, -9);
  chassis.turn_to_point(-24, -9);
  pneumatics.clench_v(0);
  pros::delay(150);
  chassis.drive_to_point(-24, -9);
  pros::delay(350);
  chassis.turn_to_point(-38, -12);
  chassis.drive_to_point(-38, -12);
  pros::delay(200);
  intake.move(0);
  chassis.drive_to_point(-24, -9);
  chassis.turn_to_point(-24, -48);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-24, 8, 3, 0);
  intake.move(600);*/


  
  /*
  chassis.drive_to_point(0, -27.5);
  pros::delay(100);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(28.5, -29);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(28.5, -29,14,0);
  pros::delay(1100);
  chassis.turn_to_point(-24, -5);
  intake.move(0);
  chassis.drive_to_point(0, -15);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_to_point(-24, -5);
  chassis.turn_to_point(-2, 20);
  chassis.drive_to_point(-40, -30, 10, 0, 1, 300, 600);
  chassis.set_brake_mode(MOTOR_BRAKE_HOLD);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(-58, -23);
  intake.move(600);                           
  chassis.drive_to_point(-58, -23,12,0, 1, 300, 600);
  pros::delay(1000);
  chassis.turn_to_point(-12, -33);
  chassis.turn_to_point(-12, -33);
  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0,13.5,14,0);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(-120);
  pros::delay(375);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(-120);
  chassis.drive_to_point(-49, 37, 14, 0, 1, 200, 800);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(1);
  intake.move(-120);
  pros::delay(175);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-45,55);
  chassis.drive_to_point(-45,51, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(-40,40, 10, 0);
  chassis.turn_to_point(-52,56);
  chassis.drive_to_point(-50,51, 10, 0);
  pros::delay(400);
  chassis.drive_to_point(-29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(50,115);
  chassis.drive_distance(17);*/
}


void redRightQual(){
  //if alliance can score on alliance wall stake
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  // set up with back facing the mobile goal
  */

  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  chassis.right_swing_to_angle(330);
  neutral_stake.move2(600);
  pros::delay(625);
  neutral_stake.move2(-600);
  pros::delay(40);
  chassis.turn_to_point(-36, 28);
  chassis.drive_to_point(34, 0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(35, -20);
  intake.move(600);
  chassis.drive_to_point(35, -20);
  pros::delay(20);
  intake.move(0);
  chassis.turn_to_point(12, 0);
  intake.move(600);
  chassis.drive_to_point(12, 0);
  chassis.turn_to_point(12, 24);
  chassis.drive_to_point(12, 24);
  pros::delay(250);
  chassis.drive_to_point(12, 40);
  pros::delay(40);
  intake.move(0);
  chassis.turn_to_point(36, 4);
  intake.move(600);
  chassis.drive_to_point(36, 4);
  chassis.turn_to_point(60, 4);
  chassis.drive_to_point(56, 4);
  

}


void redLeftElim(){
  //5 ring (2 top)
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, 96, 9, 0, 3, 200, 3000);
  chassis.turn_to_point(-96, 96);
  chassis.drive_to_point(-96, 96, 9, 0, 3, 200, 3000);

  /*
  chassis.set_coordinates(0, -8, 0);
  odom_constants();
  
  chassis.drive_to_point(0, -33, 6, 0, 3, 50, 1300);
  pros::delay(75);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -57);
  intake.move(600);
  chassis.drive_to_point(18, -49);
  pros::delay(325);
  chassis.turn_to_point(27, -52.5);
  chassis.drive_to_point(27, -52.5);
  pros::delay(600);
  chassis.turn_to_point(24, -42);
  chassis.drive_to_point(24, -42);
  pros::delay(100);
  chassis.turn_to_point(24, -36);
  chassis.drive_to_point(24, -36);
  pros::delay(350);
  chassis.drive_to_point(24, -12);
  chassis.turn_to_point(48, 12);
  intake.move(-400);
  chassis.drive_to_point(38, 2, 6, 0);
  pros::delay(50);
  intake.move(600);*/


  /*
  chassis.turn_to_point(24, -47.25);
  chassis.drive_to_point(24, -47.25);
  pros::delay(75);
  intake.move(0);
  chassis.turn_to_point(-6, -9);
  intake.move(600);
  chassis.drive_to_point(-6, -9, 8, 0, 1.5, 60, 1750);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.turn_to_point(-23, -9);
  chassis.drive_to_point(-23, -9, 6, 0);
  chassis.turn_to_point(-37, -14);
  pros::delay(250);
  chassis.drive_to_point(-37, -14);
  pros::delay(85);
  intake.move(7);
  chassis.drive_to_point(-24, -10);
  chassis.turn_to_point(-24, -48);
  chassis.drive_to_point(-24, 8, 4, 0, 3, 50, 900);
  chassis.drive_distance(2);
  intake.move(600);*/





  /*
  //6 ring(1 top)
  odom_constants();
  chassis.set_coordinates(0, -10, 0);
  chassis.drive_to_point(0, -36, 8, 0);
  pros::delay(100);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -60);
  intake.move(600);
  chassis.drive_to_point(21, -53);
  pros::delay(275);
  chassis.turn_to_point(23.5, -55);
  chassis.drive_to_point(23.5, -55);
  pros::delay(275);
  chassis.turn_to_point(24, -44);
  chassis.drive_to_point(24, -44);
  pros::delay(30);
  intake.move(0);
  chassis.turn_to_point(0, -14);
  intake.move(600);
  chassis.drive_to_point(0, -14);
  chassis.turn_to_point(-24, -14);
  chassis.drive_to_point(-24, -14);
  pros::delay(500);
  chassis.drive_to_point(-48, -14);*/

  
  
  //going for corner stake
  /*chassis.turn_to_point(39, -8);
  pneumatics.doinker_v(1);
  chassis.drive_to_point(39, -8);
  chassis.turn_to_point(24, -3);
  //chassis.right_swing_to_angle(330);
  pneumatics.doinker_v(0);
  pros::delay(50);
  chassis.drive_to_point(24, -3);
  chassis.turn_to_point(0, -5);
  chassis.drive_to_point(0, -5, 5, 0);
  chassis.turn_to_point(-24, -12);
  chassis.drive_to_point(-24, -12);
  pros::delay(300);
  chassis.drive_distance(12);*/

  

 

  


  
  /*chassis.drive_to_point(0, -28);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -29);
  intake.move(-120);
  pros::delay(500);
  chassis.turn_to_point(27, -29);
  chassis.drive_to_point(27, -29);
  pros::delay(500);
  chassis.turn_to_point(27, -45);
  chassis.drive_to_point(27, -45);
  pros::delay(500);
  chassis.drive_to_point(27, -39);
  chassis.turn_to_point(22, -46);
  chassis.drive_to_point(22, -46);
  pneumatics.clench_v(0);
  /*chassis.set_coordinates(0, 0, 0);
  intake.move(0);
  pros::delay(500);
  chassis.turn_to_point(24, -16);
  pros::delay(200);
  chassis.drive_distance(-16);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(2, 0);
  intake.move(0);*/

  
  
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(600);
  chassis.drive_to_point(-49,37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-47,60);
  chassis.drive_to_point(-48,55, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(-44,51, 10, 0);
  chassis.turn_to_point(-50,56);
  chassis.drive_to_point(-52,55.5, 10, 0);
  pros::delay(500);
  // this is when its different from redSWP
  chassis.drive_to_point(-17.5,20, 14, 0,1, 400, 800);
  chassis.turn_to_point(50,10);*/

  /*
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(600);
  chassis.drive_to_point(-49,37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-47,60);
  chassis.drive_to_point(-48,55, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(-44,51, 10, 0);
  chassis.turn_to_point(-50,56);
  chassis.drive_to_point(-52,55.5, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(-42,48, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(50,115);
  chassis.drive_to_point(-24,60, 14, 0,1, 400, 800);*/

  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -27);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -28);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -28);
  chassis.drive_to_point(-24, -28);
  pros::delay(1200);
  chassis.turn_to_point(0, -28);
  chassis.drive_to_point(0, -28);
  chassis.turn_to_point(24, -52);
  chassis.drive_to_point(8, -35);
  pneumatics.clench_v(0);
  
  odom_constants();
  chassis.set_coordinates(0, 0, 180);
  chassis.drive_to_point(0, 27);
  pneumatics.clench_v(1);
  pros::delay(25);
  chassis.drive_to_point(0, 36);
  intake.move(127);
  chassis.set_coordinates(0, 0, 180);
  pros::delay(25);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(-26, 0);
  pros::delay(25);
  chassis.turn_to_point(-26, 24);
  chassis.drive_to_point(-26, 18);
  chassis.drive_to_point(-26, 14);
  chassis.turn_to_point(-22, 18);
  chassis.drive_to_point(-22, 18);
  chassis.drive_to_point(-26, 14);
  chassis.turn_to_point(12, -14);
  chassis.drive_to_point(12, -14);
  chassis.turn_to_point(24, -14);
  chassis.drive_to_point(24, -14);
  chassis.turn_to_point(72, 0);
  chassis.drive_to_point(72, 0);
  pneumatics.clench_v(0);
  chassis.turn_to_point(72, -24);
  chassis.drive_to_point(72, 14);
  pneumatics.clench_v(1);
  chassis.drive_to_point(72, 24);
  intake.move(0);*/




  /*chassis.set_coordinates(24, 20, 0);
  chassis.drive_to_point(24, 38);
  pneumatics.clench_v(1);
  chassis.turn_to_point(40, 48);
  intake.move(120);
  chassis.drive_to_point(40, 48);
  pros::delay(200);
  chassis.turn_to_point(51, 64);
  chassis.drive_to_point(51, 64);
  chassis.turn_to_point(48, 54, 0, 6);
  chassis.drive_to_point(48, 54);
  chassis.turn_to_point(44, 64, 0, 6);
  chassis.drive_to_point(44, 64);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(9, 39, 0, 6);
  pneumatics.clench_v(0);
  chassis.drive_to_point(9, 39);
  intake.move(120);
  pros::delay(200);
  chassis.turn_to_point(2, 48, 0, 7);
  chassis.drive_to_point(-2, 10);
  intake.move(120);*/
}


void redRightElim(){

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
  chassis.turn_to_point(-10, -30,0,14);


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
  chassis.drive_distance(17);

  //not mirrored

  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, 14.5, 14,0);
  chassis.turn_to_point(100,14.5);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-5,14.5, 9, 0, 1, 400, 600);
  intake.move(-600);
  pros::delay(275);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 3, 9, 0,1, 400, 800);
  chassis.turn_to_point(56, 40);
  intake.move(-600);
  chassis.drive_to_point(53, 39, 14, 0, 1, 400, 1200);
  intake.move(0);
  chassis.turn_to_point(150,42);
  chassis.drive_to_point(29,37, 14, 0,1, 400, 600);
  pneumatics.clench_v(1);
  intake.move(-120);
  //pros::delay(25);
  chassis.drive_to_point(40, 37, 14, 0);
  chassis.turn_to_point(44,54);
  chassis.drive_to_point(44,51, 10, 0);
  pros::delay(250);
  chassis.drive_to_point(40,40, 10, 0, 1, 400, 800);
  chassis.turn_to_point(52,56);
  chassis.drive_to_point(51,53, 10, 0);
  pros::delay(300);
  chassis.drive_to_point(29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-50,115);
  chassis.drive_distance(15);
  intake.move(0);
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0,15.5,14,0);
  chassis.turn_to_point(110, 17);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-6, 15, 11, 0,1, 400, 800);
  intake.move(-120);
  pros::delay(325);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 5, 14, 0,1, 400, 800);
  chassis.turn_to_point(52,40);
  intake.move(-120);
  chassis.drive_to_point(49, 40, 14, 0);
  intake.move(0);
  chassis.turn_to_point(150,42);
  chassis.drive_to_point(30, 40, 14, 0,1, 400, 800);
  pneumatics.clench_v(1);
  chassis.turn_to_point(42,55);
  pros::delay(15);
  intake.move(-120);
  pros::delay(50);
  chassis.drive_to_point(42,51, 11, 0);
  pros::delay(200);
  chassis.drive_to_point(40,45, 11, 0);
  chassis.turn_to_point(49, 53);
  chassis.drive_to_point(48,51, 11, 0);
  pros::delay(200);
  chassis.drive_to_point(29,37, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-50,115);
  chassis.drive_distance(17, 14);*/
}


void blueLeftQual() {
  //not mirrored
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -26.5, 7, 0);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -27.5, 7, 0);
  pros::delay(50);
  chassis.turn_to_point(24, -25);
  intake.move(600);
  pros::delay(300);
  chassis.drive_to_point(24, -25);
  pros::delay(1000);
  intake.move(0);
  chassis.turn_to_point(-24, -5);
  chassis.drive_to_point(0, -15);
  pneumatics.clench_v(0);
  pros::delay(150);
  chassis.drive_to_point(-24, -5);
  chassis.turn_to_point(0, 20);
  chassis.drive_to_point(-28, -15, 7, 0, 1, 200, 600);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.drive_to_point(-29, -16, 7, 0, 1, 200, 400);
  chassis.turn_to_point(-51, -21);
  intake.move(600);
  chassis.drive_to_point(-51, -21);
  pros::delay(2000);
  chassis.turn_to_point(-29, -23);
  chassis.drive_to_point(-29, -23);
  chassis.turn_to_point(-24, -28);
  chassis.drive_to_point(-24, -28);
  intake.move(-120);
  pneumatics.clench_v(0);




  /*
  chassis.drive_to_point(0, -28);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -29);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(24, -29);
  chassis.drive_to_point(24, -29);
  pros::delay(1200);
  chassis.turn_to_point(0, -28);
  chassis.drive_to_point(0, -28);
  chassis.turn_to_point(-24, -52);
  chassis.drive_to_point(-10, -36);
  pneumatics.clench_v(0);
  intake.move(0);*/
}


void blueRightElim(){

  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -30, 6, 0, 3, 50, 1500);
  pros::delay(50);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -58);
  pros::delay(10);
  intake.move(600);
  chassis.drive_to_point(18, -50.5);
  pros::delay(300);
  chassis.turn_to_point(27, -53.5);
  chassis.drive_to_point(27, -53.5);
  pros::delay(550);
  chassis.turn_to_point(24, -44);
  chassis.drive_to_point(24, -44);
  pros::delay(75);
  intake.move(0);
  chassis.turn_to_point(-6, -9);
  intake.move(600);
  chassis.drive_to_point(-6, -9, 8, 0, 1.5, 60, 1750);
  chassis.turn_to_point(-24, -9);
  pneumatics.clench_v(0);
  pros::delay(100);
  chassis.drive_to_point(-24, -9, 6, 0);
  chassis.turn_to_point(-37, -12);
  pros::delay(225);
  chassis.drive_to_point(-37, -12);
  pros::delay(100);
  intake.move(5);
  chassis.drive_to_point(-24, -10);
  chassis.turn_to_point(-24, -48);
  chassis.drive_to_point(-24, 8, 4, 0, 3, 50, 900);
  chassis.drive_distance(2);
  intake.move(600);



  /*
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, 24);
  pros::delay(50);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.turn_to_point(24, 0);
  chassis.drive_to_point(24, 0);
  chassis.turn_to_point(0, 0);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(0, 24);*/

  /*

  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -26);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -27);
  intake.move(-120);
  pros::delay(500);
  chassis.turn_to_point(-29, -27);
  chassis.drive_to_point(-29, -27);
  pros::delay(500);
  chassis.turn_to_point(-29, -43);
  chassis.drive_to_point(-29, -43);
  pros::delay(500);
  chassis.drive_to_point(-29, -37);
  chassis.turn_to_point(-24, -44);
  chassis.drive_to_point(-24, -44);
  pneumatics.clench_v(0);*/





  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -28);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -29);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(-24, -29);
  chassis.drive_to_point(-24, -29);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  intake.move(0);
  pros::delay(500);
  chassis.turn_to_point(24, -16);
  pros::delay(200);
  chassis.drive_distance(-16);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(2, 0);
  intake.move(0);*/
  //not mirrored
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(-100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(5,15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0,5, 9, 0,1, 400, 800);
  chassis.turn_to_point(-52,40);
  intake.move(600);
  chassis.drive_to_point(-49,37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(-150,42);
  chassis.drive_to_point(-29,37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(300);
  chassis.drive_to_point(-40,37, 14, 0);
  chassis.turn_to_point(-47,60);
  chassis.drive_to_point(-48,55, 10, 0);
  pros::delay(250);
  chassis.drive_to_point(-44,51, 10, 0);
  chassis.turn_to_point(-50,56);
  chassis.drive_to_point(-52,55.5, 10, 0);
  pros::delay(250);
  // this is when its different from redSWP
  chassis.drive_to_point(-17.5,20, 14, 0,1, 400, 800);
  chassis.turn_to_point(50,10);*/
  
  
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,13.5);
  chassis.turn_to_point(100,19);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-5, 15, 9, 0,1, 400, 800);
  intake.move(600);
  pros::delay(400);
  intake.move(0);
  chassis.set_coordinates(0, 0, 0);
  pneumatics.clench_v(0);
  chassis.drive_to_point(0, 5, 9, 0,1, 400, 800);
  chassis.turn_to_point(52, 40);
  intake.move(600);
  chassis.drive_to_point(49, 37, 14, 0);
  pros::delay(0);
  intake.move(0);
  chassis.turn_to_point(150, 42);
  chassis.drive_to_point(29, 37, 14, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(40, 37, 14, 0);
  chassis.turn_to_point(47, 60);
  chassis.drive_to_point(48, 55, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(44, 51, 10, 0);
  chassis.turn_to_point(50, 56);
  chassis.drive_to_point(52, 55.5, 10, 0);
  pros::delay(500);
  chassis.drive_to_point(42, 48, 14, 0,1, 400, 800);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-50, 115);
  chassis.drive_to_point(24, 60, 14, 0,1, 400, 800);*/



  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0,8, 14, 0, 1, 200, 500);
  //intake.move(400);
  chassis.drive_to_point(0,18, 14, 0, 1, 200, 500);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_point(-60, 40, 0, 14, 1, 500, 700);
  chassis.set_coordinates(0,0,0);
  chassis.turn_to_point(24, -24, 0, 14, 1, 500, 700);
  chassis.drive_to_point(-24, 24, 14, 0, 1, 500, 700);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-48, 23, 0, 14, 1, 500, 700);
  intake.move(600);
  chassis.drive_to_point(-48, 23, 14, 0, 1, 500, 700);
  pros::delay(400);
  chassis.turn_to_point(12,0);
  intake.move(-600);
  chassis.drive_to_point(12,0, 14, 0, 1, 500, 700);
  chassis.turn_to_point(48,29);
  intake.move(600);
  chassis.drive_to_point(48,29, 14, 0, 1, 500, 700);
  pros::delay(500);
  chassis.turn_to_point(51,47);
  chassis.drive_to_point(51,47);
  pros::delay(400);
  chassis.drive_to_point(51,40);
  chassis.turn_to_point(47,49);
  chassis.drive_to_point(47,49);
  pros::delay(800);
  chassis.drive_to_point(44,40, 14, 0, 1, 200, 500);
  intake.move(0);*/
  /*
  chassis.set_coordinates(-24, 20, 0);
  chassis.drive_to_point(-24, 38);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-40, 48);
  intake.move(120);
  chassis.drive_to_point(-40, 48);
  pros::delay(200);
  chassis.turn_to_point(-51, 64);
  chassis.drive_to_point(-51, 64);
  chassis.turn_to_point(-48, 54, 0, 6);
  chassis.drive_to_point(-48, 54);
  chassis.turn_to_point(-44, 64, 0, 6);
  chassis.drive_to_point(-44, 64);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(-9, 39, 0, 6);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-9, 39);
  intake.move(120);
  pros::delay(200);
  chassis.turn_to_point(-2, 48, 0, 7);
  chassis.drive_to_point(2, 10);
  intake.move(120);
  */
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -32);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -36);
  intake.move(120);
  chassis.turn_to_point(-24, -36);
  chassis.drive_to_point(-24, -36);*/
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

  /*odom_constants();
  chassis.turn_to_angle(45);
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
  chassis.turn_to_angle(270);
  chassis.drive_distance(-18);
  pneumatics.clench_v(1);
  pros::delay(500);
  chassis.drive_distance(16);*/


  /*
  intake.move(-600);
  pros::delay(200);
  chassis.drive_distance(-8);
  intake.move(600);
  chassis.turn_to_angle(180);
  chassis.drive_distance(8);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-12);
  pneumatics.clench_v(1);
  intake.move(600);
  chassis.
  chassis.drive_distance(-12);
  pros::delay(100);
  chassis.left_swing_to_angle(330);
  pros::delay(100);
  chassis.drive_distance(-15);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(75);
  pros::delay(100);
  chassis.drive_distance(25);
  pros::delay(1000);
  chassis.turn_to_angle(180);
  chassis.drive_distance(-4);
  pneumatics.clench_v(0);

  chassis.drive_distance(4);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-12);*/

  /*
  chassis.turn_to_angle(30);
  pros::delay(100);
  chassis.drive_distance(30);*/
  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -48);
  chassis.turn_to_point(-8, -36);
  chassis.drive_to_point(10, -57);
  pneumatics.clench_v(1);
  pros::delay(200);*/
  /*
  chassis.drive_to_point()
  chassis.drive_to_point(0, -28);
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -29);
  intake.move(-120);
  pros::delay(1000);
  chassis.turn_to_point(24, -29);
  chassis.drive_to_point(24, -29);
  pros::delay(1200);
  chassis.set_coordinates(0, 0, 0);
  intake.move(0);
  pros::delay(500);
  chassis.turn_to_point(24, -16);
  pros::delay(200);
  chassis.drive_distance(-16);
  intake.move(-120);
  pros::delay(100);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_point(-24, 0);
  chassis.drive_to_point(2, 0);
  intake.move(0);*/
}





void skills() {
  //neutral_stake.move(120);
  /*odom_constants();
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.drive_distance(-2);
  intake.move(120);
  pros::delay(1000);
  chassis.drive_distance(14);
  pneumatics.clench_v(0);
  chassis.turn_to_angle(270);
  chassis.drive_distance(-20);
  pneumatics.clench_v(1);
  pros::delay(25);
  chassis.drive_distance(-4);
  chassis.turn_to_angle(0);
  chassis.drive_distance(24);
  pros::delay(350);
  chassis.turn_to_angle(90);
  chassis.drive_distance(24);
  pros::delay(350);
  chassis.turn_to_angle(180);
  chassis.drive_distance(20);
  pros::delay(250);
  chassis.drive_distance(8);
  pros::delay(250);
  chassis.turn_to_angle(60);*/

  chassis.set_coordinates(0, -62, 0);
  odom_constants();
  pneumatics.clench_v(1);
  chassis.drive_to_point(0, -65, 7, 0, 1, 50, 300);
  intake.move(600);
  pros::delay(250);
  chassis.drive_to_point(0, -48);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-24, -48);
  intake.move(0);
  chassis.drive_to_point(20, -48);
  pros::delay(100);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -24);
  intake.move(600);
  chassis.drive_to_point(24, -24);
  pros::delay(10);
  intake.move(0);
  chassis.turn_to_point(42, 0);
  intake.move(600);
  chassis.drive_to_point(42, 0);
  chassis.turn_to_point(48, 24);
  chassis.drive_to_point(48, 24);
  pros::delay(150);
  chassis.turn_to_point(42, 0);
  chassis.drive_to_point(42, 0);
  chassis.turn_to_point(72, 0);
  neutral_stake.set_up();
  chassis.drive_to_point(64, 0, 7, 0);
  pros::delay(150);
  intake.move(0);
  neutral_stake.move1();
  pros::delay(100);
  neutral_stake.move2(-600);
  pros::delay(50);
  chassis.drive_to_point(48, 0);
  neutral_stake.move2(0);
  chassis.turn_to_point(48, -24);
  intake.move(600);
  chassis.drive_to_point(48, -24);
  pros::delay(200);
  chassis.drive_to_point(48, -48);
  pros::delay(200);
  chassis.drive_to_point(48, -60);
  pros::delay(200);
  chassis.turn_to_point(60, -48);
  chassis.drive_to_point(60, -48);
  pros::delay(250);
  chassis.turn_to_point(48, -24);
  chassis.drive_to_point(72, -72, 7, 0);
  intake.move(0);
  pros::delay(100);
  pneumatics.clench_v(0);
  chassis.drive_to_point(60, -48);
  chassis.turn_to_point(72, -48);
  chassis.drive_to_point(-20, -48);
  pneumatics.clench_v(1);
  




  /*chassis.set_coordinates(0, 0, 0);
  odom_constants();
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.drive_to_point(0, -8, 5, 0, 1, 100, 600);
  intake.move(120);
  pros::delay(1000);
  chassis.drive_to_point(0, 13);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-24, 13);
  chassis.drive_to_point(18, 13);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(24, 36);
  chassis.drive_to_point(24, 36);
  pros::delay(250);
  chassis.turn_to_point(44, 60);
  chassis.drive_to_point(44, 60);
  chassis.turn_to_point(48, 84);
  chassis.drive_to_point(48, 84);
  pros::delay(600);
  chassis.turn_to_point(24, 84);
  chassis.drive_to_point(24, 84);
  pros::delay(600);
  chassis.turn_to_point(45, 56);
  chassis.drive_to_point(45, 56);
  pros::delay(250);
  chassis.turn_to_point(60, 56.5);
  pros::delay(700);
  neutral_stake.set_up();
  pros::delay(1000);
  chassis.drive_to_point(61, 56.5);
  pros::delay(1300);
  intake.move(0);
  chassis.drive_to_point(65, 56.5, 6, 0, 1, 150, 500);
  neutral_stake.move1();
  pros::delay(500);
  chassis.drive_to_point(49, 56.5);
  neutral_stake.move2(-500);
  chassis.turn_to_point(49, 36);
  intake.move(120);
  pros::delay(200);
  neutral_stake.move2(0);
  chassis.turn_to_point(49, 36);
  pros::delay(100);
  chassis.drive_to_point(49, 36);
  pros::delay(400);
  chassis.drive_to_point(49, 12);
  pros::delay(350);
  chassis.drive_to_point(49, 0);
  pros::delay(300);
  chassis.turn_to_point(61, 13);
  pros::delay(25);
  chassis.drive_to_point(61, 13);
  pros::delay(125);
  intake.move(0);
  chassis.turn_to_point(51, 24);
  chassis.drive_to_point(70, -2, 8, 0,1, 200, 1000);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.turn_to_point(48, 13);
  chassis.drive_to_point(48, 13);
  chassis.turn_to_point(72, 13);
  chassis.drive_to_point(-18, 13);
  pneumatics.clench_v(1);
  pros::delay(100);
  intake.move(120);
  pros::delay(600);
  chassis.turn_to_point(-24, 36);
  chassis.drive_to_point(-24, 36);
  pros::delay(500);
  chassis.turn_to_point(-51, 36);
  pros::delay(100);
  chassis.drive_to_point(-51, 36);
  pros::delay(600);
  chassis.turn_to_point(-51, 12);
  chassis.drive_to_point(-51, 12);
  pros::delay(350);
  chassis.drive_to_point(-51, 0);
  pros::delay(300);
  chassis.turn_to_point(-62, 13);
  pros::delay(25);
  chassis.drive_to_point(-62, 13);
  pros::delay(350);
  intake.move(0);
  chassis.turn_to_point(-51, 24);
  chassis.drive_to_point(-70, -2, 8, 0,1, 200, 1000);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.turn_to_point(-48, 13);
  chassis.drive_to_point(-48, 13);
  chassis.turn_to_point(-45, 56);
  chassis.drive_to_point(-45, 56);
  chassis.turn_to_point(-60, 58);
  pros::delay(700);
  neutral_stake.set_up();
  pros::delay(1000);
  chassis.drive_to_point(-61, 58);
  pros::delay(650);
  intake.move(0);
  chassis.drive_to_point(-66, 58, 6, 0, 1, 150, 500);
  neutral_stake.move1();
  pros::delay(500);*/
  

  

  /*chassis.turn_to_point(48, 36);
  chassis.drive_to_point(48, 36);
  pros::delay(250);
  chassis.turn_to_point(24, 32);
  chassis.drive_to_point(24, 32);
  pros::delay(350);
  chassis.turn_to_point(46, 36);
  chassis.drive_to_point(46, 36);
  pros::delay(250);
  chassis.turn_to_point(46, 14);
  chassis.drive_to_point(46, 14);
  pros::delay(150);
  chassis.drive_to_point(46, 0);
  pros::delay(200);
  chassis.turn_to_point(60, 12);
  pros::delay(25);
  chassis.drive_to_point(60, 12);
  pros::delay(200);
  chassis.turn_to_point(56, 24);
  chassis.drive_to_point(64, 0, 3, 0,1, 200, 650);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(250);
  chassis.drive_to_point(60, 12);
  pros::delay(200);
  chassis.turn_to_point(72, 12);
  pros::delay(50);
  chassis.turn_to_point(72, 12);
  chassis.drive_to_point(-16, 12);
  pneumatics.clench_v(1);
  pros::delay(100);
  intake.move(120);
  chassis.turn_to_point(-24, 36);
  chassis.drive_to_point(-24, 36);
  pros::delay(350);
  chassis.turn_to_point(-46, 36);
  chassis.drive_to_point(-46, 36);
  pros::delay(250);
  chassis.turn_to_point(-46, 14);
  chassis.drive_to_point(-46, 14);
  pros::delay(150);
  chassis.drive_to_point(-46, 0);
  pros::delay(200);
  chassis.turn_to_point(-60, 12);
  pros::delay(25);
  chassis.drive_to_point(-60, 12);
  pros::delay(200);
  chassis.turn_to_point(-56, 24);
  chassis.drive_to_point(-64, 0, 5, 0,1, 200, 600);
  intake.move(0);
  pneumatics.clench_v(0);
  pros::delay(200);

  //chassis.turn_to_point()

  //chassis.turn_to_point(96, 0);
  //chassis.drive_to_point(60, 0);*/

}




void blueSWPGoal(){
  /*chassis.drive_to_point(0, 8, 14, 0, 1, 200, 500);
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
  chassis.drive_to_point(0,48);*/
}

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

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 6;
  chassis.drive_kp = 0.713;
  chassis.drive_kd = 0.45;
  chassis.drive_settle_error = 1;
  chassis.drive_settle_time = 350;
  chassis.turn_max_voltage = 6;
  chassis.turn_kp = 0.277;
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
  odom_constants(); 
  chassis.drive_distance(24);
  pros::delay(100);
  chassis.turn_to_angle(90);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(180);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(270);
   pros::delay(100);
  chassis.drive_distance(24);
   pros::delay(100);
  chassis.turn_to_angle(360);
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
  float x, y, heading;
  std::string x_str, y_str, heading_str;
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  /*
  //chassis.turn_to_point(24,0,0,6);
  x = chassis.get_X_position();
     y = chassis.get_Y_position();
     heading = chassis.get_absolute_heading();
     x_str = std::to_string(x);
        y_str = std::to_string(y);
        heading_str = std::to_string(heading);
        pros::screen::draw_rect(0,0,480,240);
        pros::screen::set_pen(pros::Color::white);
        pros::screen::print(TEXT_LARGE, 50, 50, x_str.c_str());
        pros::screen::print(TEXT_LARGE, 50, 120, y_str.c_str());
        pros::screen::print(TEXT_LARGE, 50, 200, heading_str.c_str());
        */
  //chassis.turn_to_angle(90,6);
  /*
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(96,0,0,6);
  chassis.drive_to_point(96,0,6,0,0.5,100,4000);
  chassis.turn_to_point(96,96,0,6);
  chassis.drive_to_point(96,96,6,0,0.5,100,4000);
  chassis.turn_to_point(0,0,0,6);d

  chassis.drive_to_point(96,0,9,0);
  chassis.turn_to_point(0,0,0,14);
  chassis.drive_to_point(0,0,9,0);
  chassis.turn_to_point(0,48,0,14);
  */

  chassis.drive_to_point(0,24);
  printf("X: %f, Y: %f, Heading: %f\n", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  chassis.turn_to_point(24,24);
  chassis.drive_to_point(24,24);
  printf("X: %f, Y: %f, Heading: %f\n", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  chassis.turn_to_point(24,0);
  chassis.drive_to_point(24,0);
  printf("X: %f, Y: %f, Heading: %f\n", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  
  chassis.turn_to_point(0,0);
  chassis.drive_to_point(0,0);
  printf("X: %f, Y: %f, Heading: %f\n", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  
  chassis.turn_to_point(0,24);
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
    pros::delay(20);
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
  chassis.set_coordinates(0,0,0);
  pros::delay(500);
  chassis.drive_to_point(0,24,10,0);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(24,24,0,10);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(24,24,10,0);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(24,0,0,10);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(24,0,10,0);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(0,0,0,10);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.drive_to_point(0,0,10,0);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl; 
  chassis.turn_to_point(0,24,0,10);
  pros::delay(500);
  std::cout << chassis.get_X_position() << "," << chassis.get_Y_position() << std::endl;
}
void redSWP(){
  //SWP
  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  //chassis.drive_to_point(0, 19);
  chassis.left_swing_to_angle(49);
  //chassis.left_swing_to_point(9, 32);
  neutral_stake.move2(600);
  pros::delay(725);
  neutral_stake.move2(-600);
  pros::delay(15);
  chassis.turn_to_point(36, 28);
  chassis.drive_to_point(-35, 0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-35, -23);
  intake.move(600);
  chassis.drive_to_point(-35, -23);
  pros::delay(10);
  intake.move(0);
  chassis.turn_to_point(-12, 0);
  intake.move(600);
  chassis.drive_to_point(-12, 0);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-12, 21.6);
  chassis.drive_to_point(-12, 21.6,5,0);
  pros::delay(75);
  chassis.turn_to_point(-12.5, 40);
  chassis.drive_to_point(-12.5, 40);
  pros::delay(25);
  intake.move(0);
  chassis.turn_to_point(12, 28);
  chassis.drive_to_point(-34, 48);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-34, 73);
  intake.move(600);
  pros::delay(25);
  chassis.drive_to_point(-34, 73);
  pros::delay(40);
  intake.move(0);
  chassis.turn_to_point(-35, 26);
  intake.move(600);
  chassis.drive_to_point(-35, 26,14,0);


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
  // works for blueRight qual as well
  //if alliance can score on alliance wall stake
  /*odom_constants();
  chassis.set_coordinates(0, 0, 0);
  // set up with back facing the mobile goal
  */
 /*
  odom_constants();
  chassis.drive_distance(-14, 0, 10, 0);
  pros::delay(100);
  chassis.right_swing_to_angle(19.5);
  pros::delay(100);
  chassis.drive_distance(-16, 0, 10, 0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(650);
  chassis.turn_to_angle(270);
  pros::delay(100);
  chassis.drive_distance(26, 0, 10, 0);
  pros::delay(2000);
  chassis.turn_to_angle(90);
  pros::delay(100);
  intake.move(600);
  chassis.drive_distance(70,0,4.5,0);
  pros::delay(100);
  chassis.drive_distance(70,0,4.5,0);
  pneumatics.clench_v(0);
*/
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.right_swing_to_angle(326,14);
  neutral_stake.move2(600);
  pros::delay(560);
  neutral_stake.move2(-600);
  chassis.drive_distance(-10,14);
  chassis.set_coordinates(0, 0, -34);
  pros::delay(150);
  chassis.turn_to_point(1.5,18,0,14,1,50,300);
  neutral_stake.move2(0);
  chassis.drive_to_point(3.5,6,14,0,1,50,250);
  pneumatics.doinker_v(1);
  pros::delay(100);
  chassis.drive_to_point(-7,-7,14,0);
  pneumatics.doinker_v(0);
  intake.move(450);
  pros::delay(50);
  chassis.turn_to_point(8,10,0,14,1,50,250);
  chassis.drive_to_point(8,10,14,0);
  intake.move(0);
  chassis.turn_to_point(-36, 50,0,14,1,300,700);
  chassis.drive_to_point(30,-7,14,0,1,300,700);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(30, -28,0,14,1,300,700);
  intake.move(600);
  chassis.drive_to_point(30,-28,14,0);
  pros::delay(400);
  chassis.turn_to_point(5, -28,0,14,1,300,700);
  intake.move(-600);
  chassis.drive_to_point(5,-28,14,0);
  chassis.turn_to_point(-15, -48,0,14,1,300,700);
  chassis.drive_to_point(-15,-48,14,0,1,300,700);
  pros::delay(50);
  intake.move(600);
  pros::delay(200);
  chassis.drive_to_point(55,10,14,0);
  /*
  chassis.turn_to_point(30, 15,0,14);
  chassis.drive_to_point(30,0,14,0);
  intake.move(-600);
  chassis.drive_to_point(30,15,14,0);

/*
  Robot #1 Basic Qual
  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  //intake.move(600);
  //pros::delay(100000);
  chassis.right_swing_to_angle(326);
  Neutral_Stake.move2(600);
  pros::delay(750);
  Neutral_Stake.move2(-600);
  pros::delay(40);
  chassis.turn_to_point(-36, 33);
  chassis.drive_to_point(34, 0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(33, -25);
  intake.move(600);
  chassis.drive_to_point(33, -25);
  pros::delay(600);
  chassis.turn_to_point(12, 0);
  intake.move(300);
  chassis.drive_to_point(12, 0);
  chassis.turn_to_point(12, 21.6);
  chassis.drive_to_point(12, 21.6,12,0,0.5,50,700);
  intake.move(0);
  chassis.turn_to_angle(90);
  intake.move(-600);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_angle(0);
  intake.move(600);
  chassis.turn_to_point(13.5, 49);
  chassis.drive_to_point(13.5, 49);
  pros::delay(500);
  intake.move(-600);
  chassis.drive_to_point(36, 4);
  chassis.turn_to_point(60, 4);
  chassis.drive_to_point(56, 4);
*/
}
void redLeftElim(){
  odom_constants();
   chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -28.5,14,0);
  pros::delay(75);
  pneumatics.clench_v(1);
  chassis.turn_to_point(22, -47,0,14,1,300,600);
  intake.move(600);
  chassis.drive_to_point(22, -47,14,0,1,300,600);
  pros::delay(500);
  chassis.turn_to_point(41, -47,0,14,1,300,600);
  chassis.drive_to_point(31, -47,14,0,1,300,600);
  pros::delay(1000);
  intake.move(0);
  chassis.drive_to_point(0, -34,14,0);
  chassis.turn_to_point(28, -27,0,14);
   intake.move(600);
   chassis.drive_to_point(28, -27,14,0,1,300,600);
   pros::delay(1000);
   chassis.turn_to_point(-8, 1,0,14,1,300,600);
  intake.move(600);
  chassis.drive_to_point(-8, 1,14,0,1,300,600);
  chassis.turn_to_point(-27, 1,0,14,1,300,600);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-27, 1, 9, 0);
  pros::delay(60);
  chassis.turn_to_point(-38, -5,0,14,1,300,600);
  intake.move(600);
  chassis.drive_to_point(-38, -5,14,0,1,300,600); 
  pros::delay(60);
  intake.move(5);
  chassis.drive_to_point(-21.5, 0.5);
  chassis.turn_to_point(-26, -52,0,14);
  //pneumatics.clench_v(1);
  chassis.drive_to_point(-26, 14, 6, 0);
  intake.move(600);
  //5 ring (2 top)
  /*
  chassis.set_coordinates(0, 0, 0);
  odom_constants();
  chassis.drive_to_point(0, -35.5, 6, 0);
  pros::delay(50);
  pneumatics.clench_v(1);
  chassis.turn_to_point(24, -60);
  pros::delay(10);
  intake.move(600);
  chassis.drive_to_point(17, -53);
  pros::delay(250);
  chassis.turn_to_point(24, -54);
  chassis.drive_to_point(24, -54);
  pros::delay(275);
  chassis.turn_to_point(24, -43);
  chassis.drive_to_point(24, -43);
  pros::delay(75);
  intake.move(0);
  chassis.turn_to_point(-8, -9);
  intake.move(600);
  chassis.drive_to_point(-8, -9);
  chassis.turn_to_point(-24, -9);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-24, -9, 9, 0);
  chassis.turn_to_point(-37, -12);
  pros::delay(100);
  chassis.drive_to_point(-37, -12);
  pros::delay(60);
  intake.move(5);
  chassis.drive_to_point(-23, -9);
  chassis.turn_to_point(-23, -48);
  pneumatics.clench_v(1);
  chassis.drive_to_point(-23, 8, 4, 0);
  intake.move(600);

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
  chassis.set_coordinates(0,0,345);
  intake.move(600);
  chassis.drive_to_point(0, 36,10,0);
  pneumatics.doinker_v(1);
  intake.move(5);
  chassis.drive_to_point(0, 15,14,0);
  pneumatics.doinker_v(0);
  pros::delay(200);
  chassis.turn_to_point(0, -10,0,14);
  pros::delay(50);
  chassis.drive_to_point(-10, 40,14,0);
  pneumatics.clench_v(1);
  intake.move(600);
  pros::delay(700);
  pneumatics.clench_v(0);
  chassis.drive_to_point(5, 24,14,0);
  chassis.turn_to_point(36, 10,0,14);
  chassis.drive_to_point(-30, 18,14,0);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-18, 10,0,14);
  chassis.drive_to_point(-18, 10,10,0);
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
  chassis.turn_to_point(0,-25,0,14);
}

void blueSWP(){
  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  //chassis.drive_to_point(0, 19);
  chassis.right_swing_to_angle(334);
  //chassis.left_swing_to_point(9, 32);
  neutral_stake.move2(600);
  pros::delay(700);
  neutral_stake.move2(-600);
  pros::delay(50);
  chassis.turn_to_point(-36, 35);
  chassis.drive_to_point(35, -5);
  pneumatics.clench_v(1);
  chassis.turn_to_point(33, -23);
  intake.move(600);
  chassis.drive_to_point(33, -23);
  pros::delay(10);
  intake.move(0);
  chassis.turn_to_point(12, 0);
  intake.move(600);
  chassis.drive_to_point(12, 0);
  pneumatics.clench_v(0);
  chassis.turn_to_point(13, 22);
  intake.move(600);
  chassis.drive_to_point(13, 21.6,4,0);
  pros::delay(25);
  chassis.turn_to_point(13.5, 38);
  intake.move(100);
  chassis.drive_to_point(13.5, 38);
  pros::delay(75);
  intake.move(2);
  chassis.turn_to_point(-12, 28);
  chassis.drive_to_point(34, 48);
  pneumatics.clench_v(1);
  chassis.turn_to_point(36, 73);
  intake.move(600);
  pros::delay(25);
  chassis.drive_to_point(36, 73);
  pros::delay(40);
  intake.move(0);
  chassis.turn_to_point(37, 26,0,14);
  intake.move(600);
  chassis.drive_to_point(37, 26,14,0);
}
void blueLeftQual(){
  // works for redLeft as well
  odom_constants();
  chassis.set_coordinates(0, 14, 0);
  chassis.left_swing_to_angle(50);
  neutral_stake.move2(600);
  pros::delay(725);
  neutral_stake.move2(-600);
  pros::delay(40);
  chassis.turn_to_point(36, 33);
  chassis.drive_to_point(-35, 0,12,0,0.5,50,1000);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-35, -22);
  neutral_stake.move2(0);
  intake.move(600);
  chassis.drive_to_point(-35, -22);
  pros::delay(300);
  chassis.turn_to_point(-12, 0);
  intake.move(600);
  chassis.drive_to_point(-12, 0);
  chassis.turn_to_point(-12, 21.6);
  chassis.drive_to_point(-12, 21.6,12,0,0.5,50,700);
  intake.move(0);
  chassis.turn_to_angle(270);
  intake.move(-600);
  pros::delay(500);
  intake.move(0);
  chassis.turn_to_angle(0);
  intake.move(600);
  chassis.turn_to_point(-13, 40.5);
  chassis.drive_to_point(-13, 40.5);
  pros::delay(800);
  intake.move(0);
  chassis.turn_to_point(-36, 4);
  intake.move(-600);
  chassis.drive_to_point(-36, 4);
  chassis.turn_to_point(-60, 4);
  chassis.drive_to_point(-56, 4);  
}
void blueLeftElim(){
  odom_constants();
  chassis.set_coordinates(0,0,15);
  chassis.drive_to_point(0, 36,14,0);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(0, 20,14,0);
  pneumatics.doinker_v(0);
  pros::delay(200);
  chassis.turn_to_point(0, 0,0,14);
  pros::delay(50);
  chassis.drive_to_point(10, 40,14,0);
  pneumatics.clench_v(1);
  intake.move(600);
  chassis.turn_to_point(9,30,0,14);
  chassis.drive_to_point(9, 30,14,0);
  pros::delay(700);
  pneumatics.clench_v(0);
  chassis.turn_to_point(-36, 30,0,14);
  chassis.drive_to_point(30, 20,14,0);
  pneumatics.clench_v(1);
  /*
  intake.move(600);
  pros::delay(700);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-5, 24,14,0);
  chassis.turn_to_point(-36, 10,0,14);
  chassis.drive_to_point(30, 18,14,0);
  pneumatics.clench_v(1);
  //colorsorter
  chassis.turn_to_point(18, 10,0,14);
  chassis.drive_to_point(18, 10,10,0);
  pros::delay(400);
  chassis.turn_to_point(12, -6,0,14);
  chassis.drive_to_point(12, -6,10,0);
  pros::delay(1000);
  chassis.turn_to_point(-2, -20,0,14);
  pneumatics.doinker_v(1); 
  chassis.drive_distance(12);
  chassis.turn_to_point(5, 25,0,14);
  pros::delay(300);
  intake.move(600);
  pneumatics.clench_v(0); 
  pneumatics.doinker_v(0);
  chassis.drive_to_point(5, 25,14,0);
  chassis.turn_to_point(0,-25,0,14);
  */
}
void oneInch(){
  intake.move(600);
  pros::delay(1000000);
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, 6);
}

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
<<<<<<< Updated upstream
  chassis.set_drive_constants(14, 1.5, 0, 10, 0);
  chassis.set_heading_constants(0, .16, 0, 7.5, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .4, .018, 3, 15);
  chassis.set_swing_constants(14, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(2, 50, 1000);
  chassis.set_turn_exit_conditions(4, 50, 1000);
  chassis.set_swing_exit_conditions(2, 50, 1000);
=======
  chassis.set_drive_constants(10.5, 0.515, 0, 0.5, 0);
  chassis.set_heading_constants(1, 0.65, 0, 0, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .225, 0, 1, 0);
  chassis.set_swing_constants(10.5, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).

  chassis.set_drive_exit_conditions(1.5, 100, 1000);
  chassis.set_turn_exit_conditions(3, 50, 800);
  chassis.set_swing_exit_conditions(2, 50, 2000);
>>>>>>> Stashed changes
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
  //chassis.right_swing_to_angle(326,14);
  chassis.set_turn_exit_conditions(1, 50, 250);
  chassis.turn_to_angle(-34,14);
  chassis.set_turn_exit_conditions(1, 50, 1000);
  neutral_stake.move2(600);
  pros::delay(550);
  neutral_stake.move2(-600);
  chassis.drive_distance(-10,14);
  neutral_stake.move2(0);
  chassis.set_coordinates(0, 0, -34);
  pros::delay(60);
  chassis.turn_to_point(1.75,18,0,14,1,50,300);
  chassis.drive_to_point(2,7.5,14,0,1,50,250);
  pneumatics.doinker_v(1);
  pros::delay(50);
  chassis.drive_to_point(-1,-5.5,14,0, 1, 150, 650);
  pneumatics.doinker_v(0);
  intake.move(115);
  chassis.turn_to_point(8,13,0,14,1,50,250);
  chassis.drive_to_point(8,13.6,14,0,1,300,700);
  intake.move(1);
  chassis.turn_to_point(-36, 54,0,11,1,300,700);
  pros::delay(5);
  chassis.drive_to_point(24, -4, 5.5,0,1,300,1100);
  pros::delay(25);
  pneumatics.clench_v(1);
  pros::delay(150);
  intake.move(0);
  chassis.turn_to_point(26, -31,0,14,1,300,700);
  intake.move(600);
  pros::delay(150);
  chassis.drive_to_point(26,-31,10,0);
  pros::delay(400);
  chassis.turn_to_point(-15, -45, 0,14,1,300,700);
  chassis.drive_to_point(-15,-45, 4, 0, 1, 300, 1200);
   intake.move(-600);
  //chassis.turn_to_point(30, -50, 0,14,1,300,700);
  pros::delay(100);
  chassis.drive_distance(8,14);
  intake.move(600);
  pros::delay(800);
  chassis.drive_to_point(26,-31,14,0,1,250,750);
  chassis.turn_to_point(50, 5, 0,14,1,300,650);
  chassis.drive_distance(30);
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
}


void redRightElim(){
  odom_constants();
<<<<<<< Updated upstream
  chassis.set_coordinates(-22,2,20);
  neutral_stake.move2(108);
  intake.move(600);
  chassis.drive_to_point(0, 42,14,0);
  pros::delay(50);
  neutral_stake.move2(-40);
  chassis.turn_to_angle(280,14);
  pros::delay(100);
  intake.move(0);
  //chassis.turn_to_angle(0,14);
  neutral_stake.move2(0);
  chassis.turn_to_point(50,150,0,14,1,300,700);
  chassis.drive_to_point(-40,35,5.5,0,1,300,700);
  pneumatics.clench_v(1); 
  pros::delay(50);
  intake.move(600);
  chassis.turn_to_point(-8,36,0,14,1,150,600);
  chassis.drive_to_point(-8, 36,14,0,1,300,700);
  pros::delay(1200);
  intake.move(0);
  chassis.turn_to_point(-5,0,0,14,1,150,600);
  intake.move(-600);
  chassis.drive_to_point(-5,0,14,0);
  chassis.drive_to_point(0,0,14,0);
  chassis.turn_to_point(24,-1,0,14,1,150,600);
  pneumatics.doinker_v(1);
  intake.move(600);
  chassis.drive_to_point(24, -1,2,0);
  //chassis.drive_distance(10,14);
  chassis.turn_to_point(35,60,0,14,1,150,600);
  intake.move(600);
  pneumatics.doinker_v(0);
  chassis.turn_to_point(24,-1,0,14,1,150,600);
  chassis.drive_distance(25,14);
  pros::delay(200);
  chassis.turn_to_point(0,60,0,14,1,150,600);
  chassis.drive_distance(40,5);
}
void auton_setup() {
  // blue SWP
  
  odom_constants();
  chassis.turn_to_angle(-32.25);
  
  // red SWP
  /*
  odom_constants();
  chassis.turn_to_angle(32.25);
  

  //rush
  /*
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_distance(13, 0, 6, 0);
  chassis.turn_to_angle(20, 6);
=======
  chassis.set_coordinates(0,0,0);
  chassis.drive_to_point(0,-20,14,0,2,100,1200);
  chassis.drive_distance(-4,9,2,35,300,0.515,0,0.5,0);
  //chassis.drive_distance(-21,0,6,0);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(22,-41.5,0,14,3,50,700);
  pros::Task intake_task(Scoring_Mech::intake_helper_task);
  pros::delay(250);
  chassis.drive_to_point(21,-41.5,14,0,2,50,1400);
  pneumatics.doinker_right_v(1);
  pros::delay(90);
  chassis.drive_distance(3.5,9,2,50,350,0.515,0,0.5,0);
  chassis.turn_to_point(17.75,-50,0,14,3,50,250);
  pneumatics.doinker_left_v(1);
  pros::delay(105);
  chassis.turn_to_point(25,-50,0,14,3,50,300);
  chassis.drive_to_point(7,-7,14,0,2,50,1300);
  pneumatics.doinker_right_v(0);
  pneumatics.doinker_left_v(0);
  pros::delay(90);
  chassis.turn_to_point(29.5,-50,0,14,3,50,300);
  scoring_mech.intake_move(600);
  chassis.drive_distance(12,14,2,50,450,0.515,0,0.5,0);
  chassis.turn_to_point(-20,-50,0,14,2,50,300);
  chassis.drive_distance(12,14,2,50,450,0.515,0,0.5,0);
  pros::delay(100);
  chassis.turn_to_point(-31.5,-26,0,14,2,50,350);
  pros::Task neutralstake_task(Scoring_Mech::neutral_stake_helper_task);
  chassis.drive_to_point(-30,-26,14,0,2,50,1400);
  pros::delay(450);
  chassis.turn_to_point(-39,-43,0,14,3,50,400);
  pros::Task neutralstake2_task(Scoring_Mech::neutral_stake2_helper_task);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-39,-43,12,0,1.5,50,1400);
  pros::Task neutralstake3_task(Scoring_Mech::neutral_stake3_helper_task);
  

  /*
  scoring_mech.intake_move(0);
  chassis.drive_to_point(16.8,-40.2,14,0,2,150,2000);
  pneumatics.doinker_right_v(1);
  pros::delay(90);
  chassis.turn_to_point(19,-50,0,14);
  pneumatics.doinker_left_v(1);
  pros::delay(90);
  chassis.drive_to_point(10,-10,14,0,2,150,1500);
  pneumatics.doinker_left_v(0);
  pneumatics.doinker_right_v(0);
  pros::delay(70);
  chassis.turn_to_point(26,-50,0,14);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(12,-22,14,0,2,150,1000);
  chassis.turn_to_point(-48,-78,0,14);
  chassis.drive_to_point(0,-28,14,0,2,150,1000);
  chassis.turn_to_point(-48,-33,0,14);
  chassis.drive_to_point(-25,-29,14,0,2,150,1500);
  */
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
>>>>>>> Stashed changes
  */
}

void redSWP(){ 
  chassis.drive_timeout = 700;
  chassis.turn_timeout = 700;
  chassis.turn_settle_time = 250;
  odom_constants();
  chassis.set_coordinates(11.41,-9.73,122.25);
  neutral_stake.move2(600);
  pros::delay(500);
  neutral_stake.move2(0);
  chassis.drive_to_point(7,-9,13,0,1,200,575);
  neutral_stake.move2(-250);
  //pros::delay(85);
  chassis.turn_to_point(24,-85,0,14,1,250,650);
  neutral_stake.move2(-600);
  chassis.drive_to_point(5,13,14,0,1,200,700);
  chassis.drive_to_point(0,19.5,5,0,1,200,500);
  neutral_stake.move2(0);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(-12,41.5,0,10,1,300,800);
  intake.move(600);
  chassis.drive_to_point(-12,41,14,0,1,200,675);
  chassis.turn_to_point(-40,41,0,14,1,200,500);
  chassis.drive_to_point(-29,41,14,0,1,300,700);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(-27.5,30,0,14,1,200,500);
   intake.move(600);
  chassis.drive_to_point(-27.5,22,14,0,1,210,550);
  chassis.drive_to_point(-27.5,30,14,0,1,150,350);
  pros::delay(500);
  chassis.turn_to_point(17,6,0,14,1,250,550);
  pneumatics.clench_v(0);
  chassis.drive_to_point(12,6.5,14,0,1,300,750);
  chassis.drive_to_point(24,-3,4,0,1,250,600);
  pros::delay(100);
  chassis.drive_to_point(33,-9.5,4,0,1,250,600);
  pros::delay(75);
  intake.move(0);
  chassis.turn_to_point(24,-35,0,14,1,250,550);
  chassis.drive_to_point(35,14,14,0,1,250,650);
  chassis.drive_to_point(46,23,5,0,1,250,600);
  pneumatics.clench_v(1);
  intake.move(4);
  pros::delay(50);
  chassis.turn_to_point(68,22,0,14,1,250,550);
  neutral_stake.move2(50);
  intake.move(600);
  chassis.drive_to_point(68,22,14,0,1,300,750);
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(48,43,0,14,1,230,550);
  intake.move(600);
  chassis.set_brake_mode('C');
<<<<<<< Updated upstream
  chassis.drive_distance(33,0,14,0);
  intake.move(0);
  /*
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
  */
=======
  chassis.drive_to_point(-72, 0, 7, 0);

}



void blueLeftElim() {
  odom_constants();
  chassis.set_coordinates(0,0,0);
  pros::delay(1000);
  chassis.turn_to_point(-11,-11,0,5,0.5,300,3000);
  chassis.drive_to_point(-11,-11,5,0,0.5,300,3000);
  printf("X: %f Y: %f\n, Heading: %f\n", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  odom_constants();
  chassis.set_coordinates(35,0,45);
  
  //chassis.drive_to_point(0,-20,14,0,2,100,1200);
  chassis.drive_distance(-23,14,2,50,1000,0.515,0,0.5,0);
  //chassis.drive_distance(-21,0,6,0);
  pneumatics.clench_v(1);
  pros::delay(50);
  pros::Task intake_task(Scoring_Mech::intake_helper_task);
  chassis.turn_to_point(-19,-38,0,14,3,50,675);
  pros::delay(275);
  chassis.drive_to_point(-19,-38,14,0,2,50,1400);
  pneumatics.doinker_left_v(1);
  pros::delay(90);
  chassis.turn_to_point(-18,-50,0,14,3,50,350);
  chassis.drive_distance(3.9,9,2,50,600,0.515,0,0.5,0);
  pneumatics.doinker_right_v(1);
  pros::delay(155);
  chassis.turn_to_point(-25,-50,0,14,3,50,350);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(0,0,14,0,2,50,1450);
  //chassis.right_swing_to_angle(180,-14);
  scoring_mech.intake_move(0);
  pneumatics.doinker_right_v(0);
  pneumatics.doinker_left_v(0);
  pros::delay(90);
  chassis.turn_to_point(-42,-50,0,14,3,50,300);
  scoring_mech.intake_move(600);
  chassis.drive_distance(10,14,2,50,450,0.515,0,0.5,0);
  chassis.turn_to_point(20,-90,0,14,2,50,300);
  chassis.drive_distance(14.5,14,2,50,600,0.515,0,0.5,0);
  pros::delay(650);
  chassis.turn_to_point(31.5,-26.5,0,14,2,50,450);
  pros::Task neutralstake_task(Scoring_Mech::neutral_stake_helper_task);
  chassis.drive_to_point(30,-26.5,14,0,2,50,1400);
  scoring_mech.intake_move(600);
  pros::delay(400);
  chassis.turn_to_point(40,-42.5,0,14,3,50,450);
  scoring_mech.intake_move(0);
  pros::Task neutralstake2_task(Scoring_Mech::neutral_stake2_helper_task);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(40,-42.5,12,0,1.5,50,1550);
  pros::Task neutralstake3_task(Scoring_Mech::neutral_stake3_helper_task);
>>>>>>> Stashed changes
}
void blueSWP(){
  chassis.drive_timeout = 700;
  chassis.turn_timeout = 700;
  chassis.turn_settle_time = 250;
  odom_constants();
  chassis.set_coordinates(-11.41,-9.23,237.75);

  neutral_stake.move2(600);
  pros::delay(500);
  neutral_stake.move2(0);
  chassis.drive_to_point(-7,-9,13,0,1,200,575); 
  neutral_stake.move2(-250);
  chassis.turn_to_point(-24,-70,0,14,1,250,650);
  neutral_stake.move2(-600);
  chassis.drive_to_point(-5,13,14,0,1,200,700);
  chassis.drive_to_point(0,19.5,5,0,1,200,500);
  neutral_stake.move2(0);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(14,40,0,10,1,300,800);
  intake.move(600);
  chassis.drive_to_point(14,40,14,0,1,200,675);
  chassis.turn_to_point(40,40,0,14,1,200,500);
  chassis.drive_to_point(29,40,14,0,1,300,700); 
  pros::delay(100);
  intake.move(0);
  chassis.turn_to_point(27,30,0,14,1,200,500);
  intake.move(600);
  chassis.drive_to_point(27,25,14,0,1,210,550);
  chassis.drive_to_point(27,30,14,0,1,150,350);
  pros::delay(500); 
  chassis.turn_to_point(-17,12,0,14,1,250,550);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-12,7.5,14,0,1,300,750);
  chassis.drive_to_point(-24,-3,4,0,1,250,600);
  pros::delay(100);
  chassis.drive_to_point(-33,-9.5,4,0,1,250,600);
  pros::delay(75);
  intake.move(4);
  chassis.turn_to_point(-24,-40,0,14,1,250,550);
  chassis.drive_to_point(-35,14,14,0,1,250,650);
  chassis.drive_to_point(-46,23,5,0,1,250,600);
  pneumatics.clench_v(1);
  pros::delay(50);
  chassis.turn_to_point(-68,23,0,14,1,250,550);
  neutral_stake.move2(50);
  intake.move(600);
  chassis.drive_to_point(-68,23,14,0,1,300,750);
  pros::delay(85);
  intake.move(0);
  chassis.turn_to_point(-48,46,0,14,1,200,500);
  intake.move(600);
  chassis.set_brake_mode('C');
  chassis.drive_distance(33,0,14,0);
  intake.move(0);

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
<<<<<<< Updated upstream
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
void blueLeftQual(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.left_swing_to_angle(57,14);
  neutral_stake.move3();
  chassis.drive_distance(-10,14); 
  neutral_stake.move2(-600);
  chassis.set_coordinates(0, 0, 57);
  pros::delay(100);
  neutral_stake.move2(-250);
  chassis.turn_to_point(-10,18,0,14,1,50,300);
  chassis.drive_distance(5);
  neutral_stake.move2(0);
  pneumatics.doinker_v(1);
  pros::delay(100);
  chassis.drive_to_point(2,-2,14,0);
  pneumatics.doinker_v(0);
  intake.move(150);
  pros::delay(100);
  chassis.turn_to_point(-2,13,0,14,1,50,250);
  chassis.drive_to_point(-2,13,14,0,1,300,700);
  pros::delay(100);
  intake.move(2);
  chassis.turn_to_point(36, 30,0,11,1,300,700);
  chassis.drive_to_point(-24, -4, 5,0,1,300,1250);
  pneumatics.clench_v(1);
  pros::delay(150);
  chassis.turn_to_point(-30, -30,0,11);
  intake.move(600);
  chassis.drive_to_point(-30, -30,12,0);
  pros::delay(800);
  intake.move(-50);
  chassis.turn_to_point(-33, 10,0,11);
  intake.move(600);
  chassis.drive_to_point(-30, 8,6,0);
  intake.move(-600);
  chassis.drive_to_point(-30, 16,4.5,0);
  /*
  /*
  // Robot #1
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
  */
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
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, 6);
}
void driveIntake(){
  pros::delay(500);
  pneumatics.clench_v(1);
  intake.move(600);
}
=======
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
  default_constants();
  chassis.set_coordinates(14.088, -4.959, 148.533);
  scoring_mech.move1(600);
  chassis.drive_to_point(17, -10, 8, 0, 1.75, 50, 1000);
  pros::delay(70);
  scoring_mech.move1(0);
  chassis.drive_distance(-8,12,2,50,650,0.515,0,0.5,0);
  chassis.turn_to_point(27, -40,0,14,3,50,300);
  chassis.drive_distance(-30,9,2,50,1600,0.515,0,0.5,0);
  scoring_mech.move1(-600);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(17.2,34,0,14,3,50,500);
  scoring_mech.move1(0);
  chassis.drive_to_point(17.2,34,14,0,2,50,1500);
  pneumatics.doinker_left_v(1);
  pros::delay(150);
  chassis.turn_to_point(17,48,0,14,3,50,450);
  chassis.drive_distance(6.5,7,2,50,600,0.515,0,0.5,0);
  pneumatics.doinker_right_v(1);
  pros::delay(100);
  chassis.turn_to_point(22.5,44.5,0,14,3,50,450);
  chassis.drive_to_point(-6, 14, 12, 0, 1.75, 50, 1250);
  pneumatics.doinker_right_v(0);
  pneumatics.doinker_left_v(0);
  pros::delay(100);
  scoring_mech.intake_move(600);
  chassis.turn_to_point(48,40,0,14,3,50,450);
  chassis.drive_distance(14,14,2,50,550,0.515,0,0.5,0);
  pros::delay(790);
  chassis.turn_to_point(-2,55,0,14,2,50,400);
  chassis.drive_distance(7,14,2,50,550,0.515,0,0.5,0);
  pros::delay(790);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-26,26,0,14,2,50,500);
  pneumatics.clench_v(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-26, 26, 12, 0, 1.75, 50, 1250);
  pros::delay(75);
  scoring_mech.intake_move(9);
  pros::delay(75);
  chassis.turn_to_point(-20,0,0,14,2,50,450);
  chassis.drive_distance(-17,7,2,50,1600,0.515,0,0.5,0);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.heading_max_voltage = 0;
  scoring_mech.intake_move(600);
  chassis.drive_distance(17,12,2,50,1200,0.515,0,0.5,0);
  chassis.turn_to_point(24,32,0,14,2,50,300);
  //pros::Task neutralstake3_task(Scoring_Mech::neutral_stake3_helper_task);
  chassis.drive_distance(27,14,2,50,1600,0.515,0,0.5,0);
 /**/
}
>>>>>>> Stashed changes

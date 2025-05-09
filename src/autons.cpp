#include "main.h"

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  //0.52
  chassis.set_drive_constants(10.5, 0.6, 0, 0.5, 0);
  chassis.set_heading_constants(1, 0.65, 0, 0, 0); //was 6 0.4 0 1 0
  chassis.set_turn_constants(12, .285, 0, 0.9, 0);
  chassis.set_swing_constants(10.5, 0.10, .005, 2.8, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 100, 1000);
  chassis.set_turn_exit_conditions(3, 50, 800);
  chassis.set_swing_exit_conditions(2, 50, 2000);
}

void odom_constants(){
  default_constants();
}

void test() {
  default_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.drive_to_point(0, -36, 4, 0, 2.5, 50, 2000);
  pros::delay(200);
  pneumatics.clench_v(1);
  pros::delay(200);
  chassis.turn_to_point(-24, -36);
  scoring_mech.intake_move(600);
  pros::delay(750);
  chassis.drive_to_point(-24, -36, 8, 0.5);
  pros::delay(1500);
  chassis.turn_to_point(24, 0);
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
    /*pros::screen::erase();
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
    pros::screen::print(TEXT_MEDIUM, 0, 90, text);*/
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

void auton_setup() {
  odom_constants();
  chassis.set_brake_mode('C');
  chassis.set_coordinates(0, 0, 0);
  pros::delay(500);
  chassis.calculate();

}

void redLeftQual(){
  //redSWP
  default_constants();
  chassis.set_coordinates(14.088, -4.959, 148.533);
  scoring_mech.move1(500);
  chassis.drive_to_point(18, -11.5, 12, 0, 1.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(-8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-18, 39, 0, 7, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-18, 39, 10, 0);
  chassis.turn_to_point(-26, 40.5, 0, 12, 2, 10, 500);
  chassis.drive_to_point(-26, 40.5, 10, 0);
  chassis.turn_to_point(-22, 26, 0, 10, 1.5, 100, 950);
  chassis.drive_to_point(-22, 26, 12, 0, 3, 10, 500);
  chassis.turn_to_point(10, 0);
  chassis.drive_to_point(10, 0);
  chassis.turn_to_point(24, 0);
  pros::delay(50);
  pneumatics.clench_v(0);
  chassis.drive_to_point(16, 0, 10, 0);
  pros::delay(75);
  chassis.drive_to_point(32, 0, 12, 0);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(16, -24);
  pros::Task laddertouch_task(Scoring_Mech::neutral_stake_score_task);
  chassis.drive_to_point(48, 24, 6.5, 0.25);
  pneumatics.clench_v(1);
  chassis.turn_to_point(68, 24, 0, 10, 2.5, 50, 1200);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(68, 24, 8, 0);
  chassis.turn_to_point(0, 24);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(40, 30, 6.25 , 2.5);
  scoring_mech.move1(50);


  //1+5 touch
  /*default_constants();
  chassis.set_coordinates(14.088, -4.959, 148.533);
  scoring_mech.move1(500);
  chassis.drive_to_point(18, -11.5, 12, 0, 1.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(-8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  //pros::delay(100);
  pneumatics.clench_v(1);
  //pros::delay(150);
  chassis.turn_to_point(-18, 39, 0, 7, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-18, 39, 10, 0);
  chassis.turn_to_point(-24, 40.5, 0, 12, 2, 10, 500);
  pros::delay(150);
  chassis.drive_to_point(-24, 40.5, 10, 0);
  pros::delay(350);
  chassis.turn_to_point(-24, 28, 0, 10, 1.5, 100, 1000);
  chassis.drive_to_point(-24, 28, 12, 0, 2.5, 50, 500);
  chassis.turn_to_point(-32, -10, 0, 12, 2, 50, 900);
  pros::delay(100);
  chassis.drive_to_point(-32, -10, 12, 0, 2, 50, 1300);
  chassis.turn_to_point(-48, -26, 0, 12, 2, 50, 750);
  chassis.drive_to_point(-42, -20, 2, 0, 1.5, 50, 1000);
  chassis.drive_to_point(-27, -5, 10, 0);
  //pros::delay(100);
  chassis.drive_to_point(-36, -14, 12, 0, 2, 50, 750);
  pros::delay(200);
  chassis.drive_to_point(-23, -1, 12, 0, 3, 50, 600);
  pros::delay(100);
  pros::Task laddertouch_task(Scoring_Mech::neutral_stake_score_task);
  chassis.turn_to_point(6, 30);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(6, 30);
  scoring_mech.move1(50);
  pros::delay(500);
  scoring_mech.move1(15);*/
}

void redRightQual(){
  default_constants();
  chassis.set_coordinates(-14.088, -4.959, 211.467);
  scoring_mech.move1(500);
  chassis.drive_to_point(-18, -11.5, 12, 0, 2, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  //pros::delay(100);
  pneumatics.clench_v(1);
  //pros::delay(150);
  chassis.turn_to_point(20, 24, 0, 10, 1.5, 100, 1000);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(20, 24, 8, 0, 2, 50, 1000);
   chassis.turn_to_point(32, -10, 0, 12, 2, 50, 750);
  pros::delay(100);
  chassis.drive_to_point(32, -10, 12, 0, 1, 50, 1100);
  chassis.turn_to_point(48, -26, 0, 12, 2, 50, 750);
  chassis.drive_to_point(42, -20, 2, 0, 1.5, 50, 1000);
  chassis.drive_to_point(27, -5, 10, 0);
  //pros::delay(100);
  chassis.drive_to_point(36, -14, 12, 0, 2, 50, 750);
  chassis.drive_to_point(23, 1, 12, 0, 3, 50, 600);
  pros::delay(100);
  pros::Task laddertouch_task_2(Scoring_Mech::neutral_stake_score_task);
  chassis.turn_to_point(-6, 30);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(-6, 30);
  scoring_mech.move1(50);
  pros::delay(500);
  scoring_mech.move1(15);
}

void redLeftElim(){
  /*default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(500);
  chassis.turn_to_point(9.350, 3.072, 0, 6, 0.5, 250, 1500);
  pros::delay(250);
  chassis.drive_to_point(9.350, 3.072, 6, 0, 0.5, 250, 1500);
  pros::delay(250);
  chassis.turn_to_point(14.5, -5.5, 0, 6, 0.5, 250, 2000);
  pros::delay(500);
  chassis.drive_to_point(14.5, -5.5, 6, 0, 0.5, 250, 2000);
  pros::delay(500);
  chassis.turn_to_angle(149, 5);*/

  // 1 + 6
  default_constants();
  chassis.set_coordinates(14.088, -4.959, 148.533);
  scoring_mech.move1(500);
  chassis.drive_to_point(18, -11.5, 12, 0, 2, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(-8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-18, 39, 0, 7, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-18, 39, 10, 0);
  chassis.turn_to_point(-26, 40.5, 0, 12, 2, 10, 500);
  chassis.drive_to_point(-26, 40.5, 10, 0);
  chassis.turn_to_point(-24, 28, 0, 10, 2, 50, 1000);
  chassis.drive_to_point(-24, 28, 12, 0, 2.5, 50, 500);
  chassis.turn_to_point(-32, -9, 0, 12, 2, 50, 800);
  chassis.drive_to_point(-32, -9, 12, 0, 2, 50, 1000);
  chassis.turn_to_point(-48, -25, 0, 10, 2, 50, 1000);
  chassis.drive_to_point(-42, -19, 2, 0, 2, 50, 1000);
  chassis.drive_to_point(-27, -4, 10, 0);
  //pros::delay(100);
  chassis.drive_to_point(-36, -13, 12, 0, 2, 50, 750);
  scoring_mech.intake_move(0);
  chassis.drive_to_point(-24, -1, 12, 0, 2.5, 50, 750);
  chassis.turn_to_point(24, 0, 0, 10, 2, 50, 1000);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(14, 0, 11.75, 0.25);
  chassis.drive_to_point(20, 0, 11.75, 0.25);
  pros::delay(150);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(72, 1.5, 6, 0.5);
  pros::delay(100);
}


void redRightElim(){
  /*default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(100);
  chassis.turn_to_point(10.289, -7.198, 0, 6, 0.5, 250, 1500);
  pros::delay(100);
  chassis.drive_to_point(10.289, -7.198, 6, 0, 0.5, 250, 1500);
  pros::delay(100);
  chassis.turn_to_angle(19, 6);
  pros::delay(100);
  chassis.drive_to_point(12, -2.5, 6, 0, 0.5, 250, 1500);
  pros::delay(100);*/

  // red rush
  /*default_constants();
  chassis.set_coordinates(11.5, -2.493, 18.522);
  pros::Task rush_task(Scoring_Mech::rush_helper_task);
  chassis.drive_to_point(23, 28, 12, 0, 2.5, 50, 2500, 1, 0, 0.5, 0, 0, 0, 0, 0);
  chassis.drive_to_point(20, 15, 10, 2, 4, 50, 900);
  pneumatics.doinker_left_v(0);
  pneumatics.doinker_right_v(1);
  chassis.turn_to_point(18.5, -4, 0, 8, 1.5, 100, 1000);
  chassis.drive_to_point(21.5, 34, 10, 0, 2.5, 50, 1000);
  pneumatics.doinker_right_v(0);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(56, 0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(36, 0, 8, 2, 5, 50, 1000);
  pneumatics.clench_v(0);
  chassis.drive_to_point(48, -24, 3.5, 2, 1, 50, 1200);
  pros::delay(250);
  scoring_mech.intake_move(10);
  chassis.turn_to_point(48, -24);
  chassis.drive_to_point(10, 14, 11, 1, 2, 10, 900);
  chassis.drive_to_point(2, 22, 3, 0.2, 2, 10, 650);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(36, 36.5, 0, 8, 1.5, 100, 1000);
  pros::Task score_task(Scoring_Mech::neutral_stake_score_task);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(36, 36.5, 8, 0, 1.5, 100, 1000);
  chassis.turn_to_point(48, 48, 0, 10, 1.5, 100, 1000);
  scoring_mech.move1(100);
  chassis.drive_distance(4, 4);
  pros::delay(200);
  scoring_mech.move1(0);*/
  
  // red goal safe
  default_constants();
  chassis.set_coordinates(0, -3.3, 180);
  chassis.drive_to_point(0, 20, 11, 1);
  chassis.drive_to_point(0, 24, 3, 0, 1.5, 50, 150);
  pneumatics.clench_v(1);
  chassis.turn_to_point(48, -24, 0, 12, 2.5, 50, 650);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(32, -8, 12, 0, 2, 10, 1100);
  chassis.drive_to_point(42, -18, 1.75, 0, 1, 50, 1200);
  chassis.drive_to_point(27, -3, 10, 0);
  pros::delay(250);
  chassis.drive_to_point(34, -10, 12, 0, 2, 50, 750);
  scoring_mech.intake_move(50);
  chassis.drive_to_point(24, 0, 12, 0, 2.5, 50, 1000);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(24, 24, 0, 10, 2.5, 50, 1000);
  scoring_mech.intake_move(600);
  pros::Task setup_task_1(Scoring_Mech::neutral_stake_setup_task);
  chassis.drive_to_point(24, 24);
  chassis.turn_to_point(40, 41, 0, 10, 1.5, 100, 1000);
  scoring_mech.intake_move(0);
  pros::delay(50);
  pros::Task score_task_1(Scoring_Mech::neutral_stake_score_task);
  scoring_mech.intake_move(-50);
  chassis.drive_to_point(40, 41, 6, 0, 1.5, 100, 1000);
  scoring_mech.intake_move(600);
  scoring_mech.move1(100);
  pros::delay(200);
  scoring_mech.move1(0);

}


void blueRightQual(){
  // blue SWP
  /*default_constants();
  chassis.set_coordinates(-14.088, -4.959, 211.467);
  scoring_mech.move1(500);
  chassis.drive_to_point(-18, -11.5, 12, 0, 2.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  pneumatics.clench_v(1);
  chassis.turn_to_point(18, 39, 0, 10, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(18, 39, 10, 0);
  chassis.turn_to_point(26, 40.5, 0, 12, 2, 10, 500);
  chassis.drive_to_point(26, 40.5, 10, 0);
  chassis.turn_to_point(22, 26, 0, 10, 1.5, 100, 950);
  chassis.drive_to_point(22, 26, 12, 0, 3, 10, 500);
  chassis.turn_to_point(-10, 0);
  chassis.drive_to_point(-10, 0);
  chassis.turn_to_point(-24, 0);
  pros::delay(50);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-16, 0, 10, 0);
  pros::delay(200);
  chassis.drive_to_point(-32, 0, 12, 0);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-16, -24);
  pros::Task laddertouch_task(Scoring_Mech::neutral_stake_score_task);
  chassis.drive_to_point(-48, 24, 7, 0.25);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-68, 24, 0, 10, 2.5, 100, 1200);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-68, 24, 8, 0);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(0, 24);
  scoring_mech.intake_move(600);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-40, 30, 6.25 , 2.5);
  scoring_mech.move1(50);*/


  // blue 1+5 touch
  default_constants();
  chassis.set_coordinates(-14.088, -4.959, 211.467);
  scoring_mech.move1(500);
  chassis.drive_to_point(-18, -11.5, 12, 0, 2.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  //pros::delay(100);
  pneumatics.clench_v(1);
  //pros::delay(150);
  chassis.turn_to_point(18, 39, 0, 10, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(18, 39, 10, 0);
  chassis.turn_to_point(26, 39, 0, 12, 2, 10, 500);
  pros::delay(150);
  chassis.drive_to_point(26, 39, 10, 0);
  pros::delay(250);
  chassis.turn_to_point(24, 28, 0, 10, 1.5, 100, 1000);
  chassis.drive_to_point(24, 28, 12, 0, 3, 50, 500);
  chassis.turn_to_point(32, -10, 0, 12, 2, 50, 750);
  pros::delay(100);
  chassis.drive_to_point(32, -10, 12, 0, 1, 50, 1100);
  chassis.turn_to_point(48, -26, 0, 12, 2, 50, 750);
  chassis.drive_to_point(42, -20, 2, 0, 1.5, 50, 1000);
  chassis.drive_to_point(27, -5, 10, 0);
  //pros::delay(100);
  chassis.drive_to_point(36, -14, 12, 0, 2, 50, 750);
  chassis.drive_to_point(23, 1, 12, 0, 3, 50, 600);
  pros::delay(100);
  pros::Task laddertouch_task_2(Scoring_Mech::neutral_stake_score_task);
  chassis.turn_to_point(-6, 30);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(-6, 30);
  scoring_mech.move1(50);
  pros::delay(500);
  scoring_mech.move1(15);
}


void blueLeftQual() {
  // blue 1 + 3 touch
  default_constants();
  chassis.set_coordinates(14.088, -4.959, 148.533);
  scoring_mech.move1(500);
  chassis.drive_to_point(18, -11.5, 12, 0, 1.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(-8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  //pros::delay(100);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-20, 24, 0, 10, 1.5, 100, 1000);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-20, 24, 8, 0, 2, 50, 1000);
  chassis.turn_to_point(-32, -8, 0, 12, 2, 50, 900);
  chassis.drive_to_point(-32, -8, 12, 0, 2, 50, 1300);
  chassis.turn_to_point(-48, -24, 0, 12, 1.5, 100, 1000);
  chassis.drive_to_point(-42, -18, 2, 0, 1.5, 50, 1000);
  pros::delay(100);
  chassis.drive_to_point(-25, -2, 10, 0);
  pros::delay(250);
  chassis.drive_to_point(-36, -12, 12, 0, 2, 50, 750);
  pros::delay(200);
  chassis.drive_to_point(-23, 1, 12, 0, 3, 50, 600);
  pros::delay(100);
  pros::Task laddertouch_task(Scoring_Mech::neutral_stake_score_task);
  chassis.turn_to_point(6, 30);
  scoring_mech.intake_move(-600);
  chassis.drive_to_point(6, 30);
  scoring_mech.move1(50);
  pros::delay(500);
  scoring_mech.move1(15);
}


void blueRightElim(){
  /*default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(500);
  chassis.turn_to_point(-9.350, 3.072, 0, 6, 0.5, 250, 1500);
  pros::delay(250);
  chassis.drive_to_point(-9.350, 3.072, 6, 0, 0.5, 250, 1500);
  pros::delay(250);
  chassis.turn_to_point(-14, -5.5, 0, 6, 0.5, 250, 2000);
  pros::delay(500);
  chassis.drive_to_point(-14, -5.5, 6, 0, 0.5, 250, 2000);
  pros::delay(500);
  chassis.turn_to_angle(207, 5);*/

  // blue 1 + 6
  default_constants();
  chassis.set_coordinates(-14.088, -4.959, 211.467);
  scoring_mech.move1(500);
  chassis.drive_to_point(-18, -11.5, 12, 0, 2.5, 50, 750);
  scoring_mech.move1(0);
  chassis.drive_to_point(8, 39.5, 6, 1, 2, 50, 1100);
  scoring_mech.move1(-600);
  pneumatics.clench_v(1);
  chassis.turn_to_point(18, 39, 0, 10, 1.5, 100, 1000);
  scoring_mech.move1(0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(18, 39, 10, 0);
  chassis.turn_to_point(26, 39, 0, 12, 2, 10, 500);
  chassis.drive_to_point(26, 39, 10, 0);
  chassis.turn_to_point(24, 28, 0, 10, 1.5, 100, 1000);
  chassis.drive_to_point(24, 28, 12, 0, 3, 50, 500);
  chassis.turn_to_point(32, -10, 0, 12, 2, 50, 750);
  chassis.drive_to_point(32, -10, 12, 0, 1, 50, 1100);
  chassis.turn_to_point(48, -26, 0, 12, 2, 50, 750);
  chassis.drive_to_point(42, -20, 2, 0, 1.5, 50, 1000);
  chassis.drive_to_point(27, -5, 10, 0);
  chassis.drive_to_point(36, -14, 12, 0, 2, 50, 750);
  chassis.drive_to_point(23, 1, 12, 0, 3, 50, 600);
  pros::delay(100);
  chassis.turn_to_point(-24, 0, 0, 12, 2, 50, 1000);
  chassis.drive_to_point(-14, 0, 11.75, 0.25);
  chassis.drive_to_point(-20, 0, 11.75, 0.25);
  pros::delay(150);
  chassis.set_brake_mode('C');
  chassis.drive_to_point(-72, 1.5, 6, 0.5);
  pros::delay(100);
  //chassis.turn_to_point(48, 24);*/
}



void blueLeftElim() {
  /*default_constants();
  chassis.set_coordinates(0, 0, 0);
  pros::delay(100);
  chassis.turn_to_point(-10.289, -7.198, 0, 6, 0.5, 250, 1500);
  pros::delay(100);
  chassis.drive_to_point(-10.289, -7.198, 6, 0, 0.5, 250, 1500);
  pros::delay(100);
  chassis.turn_to_angle(340, 6);
  pros::delay(100);
  chassis.drive_to_point(-12, -2.5, 6, 0, 0.5, 250, 1500);
  pros::delay(100);*/


  // blue rush
  /*default_constants();
  chassis.set_coordinates(-11.5, -2.493, 341.478);
  pros::Task rush_task(Scoring_Mech::rush_helper_task);
  chassis.drive_to_point(-23, 28, 12, 0, 2.5, 50, 2500, 1, 0, 0.5, 0, 0, 0, 0, 0);
  chassis.drive_to_point(-20, 15, 10, 2, 4, 50, 900);
  pneumatics.doinker_right_v(0);
  pneumatics.doinker_left_v(1);
  chassis.turn_to_point(-18.5, -4, 0, 8, 1.5, 100, 1000);
  chassis.drive_to_point(-21.5, 34, 10, 0, 2.5, 50, 1000);
  pneumatics.doinker_left_v(0);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(-56, 0);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-36, 0, 8, 2, 5, 50, 1000);
  pneumatics.clench_v(0);
  chassis.drive_to_point(-48, -24, 3.5, 2, 1, 50, 1200);
  pros::delay(200);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-48, -24);
  chassis.drive_to_point(-10, 14, 11, 1, 2, 10, 900);
  chassis.drive_to_point(-2, 22, 3, 0.2, 2, 10, 650);
  pros::delay(50);
  pneumatics.clench_v(1);
  pros::delay(100);
  chassis.turn_to_point(-38, 38, 0, 8, 1.5, 100, 1000);
  pros::Task score_task(Scoring_Mech::neutral_stake_score_task);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-38, 38, 8, 0, 1.5, 100, 1000);
  chassis.turn_to_point(-48, 49.5, 0, 10, 1.5, 100, 1000);
  scoring_mech.move1(100);
  chassis.drive_distance(3.5, 4);
  pros::delay(200);
  scoring_mech.move1(0);*/

  // blue goal safe
  default_constants();
  chassis.set_coordinates(0, -3.3, 180);
  chassis.drive_to_point(0, 20, 11, 1);
  chassis.drive_to_point(0, 24, 3, 0, 1.5, 50, 150);
  pneumatics.clench_v(1);
  chassis.turn_to_point(-48, -24, 0, 12, 2.5, 50, 650);
  scoring_mech.intake_move(600);
  chassis.drive_to_point(-32, -8, 12, 0, 2, 10, 1100);
  chassis.drive_to_point(-42, -18, 1.75, 0, 1, 50, 1200);
  chassis.drive_to_point(-27, -3, 10, 0);
  pros::delay(250);
  chassis.drive_to_point(-34, -10, 12, 0, 2, 50, 750);
  scoring_mech.intake_move(50);
  chassis.drive_to_point(-24, 0, 12, 0, 2.5, 50, 1000);
  scoring_mech.intake_move(0);
  chassis.turn_to_point(-24, 24, 0, 10, 2.5, 50, 1000);
  scoring_mech.intake_move(600);
  pros::Task setup_task_1(Scoring_Mech::neutral_stake_setup_task);
  chassis.drive_to_point(-24, 24);
  chassis.turn_to_point(-40, 41, 0, 10, 1.5, 100, 1000);
  scoring_mech.intake_move(0);
  pros::delay(50);
  pros::Task score_task_1(Scoring_Mech::neutral_stake_score_task);
  scoring_mech.intake_move(-50);
  chassis.drive_to_point(-40, 41, 6, 0, 1.5, 100, 1000);
  scoring_mech.intake_move(600);
  scoring_mech.move1(100);
  pros::delay(200);
  scoring_mech.move1(0);


}


void skills() {

}


void blueSWPGoal() {

}

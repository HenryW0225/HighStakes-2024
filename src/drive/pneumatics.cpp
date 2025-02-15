#include "main.h"


Pneumatics::Pneumatics(pros::adi::DigitalOut clench_port, pros::adi::DigitalOut doinker_port)
   : clench(clench_port),
   doinker(doinker_port) {}


void Pneumatics::clench_control() {
  if (master.get_digital(DIGITAL_R1)){
       clench_down = !clench_down;
       clench.set_value(clench_down);
       while (master.get_digital(DIGITAL_R1)) {
           pros::delay(util::DELAY_TIME);
       }
   }
}


void Pneumatics::clench_initialize() {
   clench.set_value(0);
}


void Pneumatics::clench_v(int value) {
   clench.set_value(value);
}


void Pneumatics::doinker_control() {
  if (master.get_digital(DIGITAL_X)){
       doinker_open = !doinker_open;
       doinker.set_value(doinker_open);
       while (master.get_digital(DIGITAL_X)) {
           pros::delay(util::DELAY_TIME);
       }
   }
}


void Pneumatics::doinker_initialize() {
   doinker.set_value(0);
}


void Pneumatics::doinker_v(int value) {
   doinker.set_value(value);
}
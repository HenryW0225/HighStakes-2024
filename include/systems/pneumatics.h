#include "main.h"

class Pneumatics{
   public:
   pros::adi::DigitalOut clench;
   //pros::adi::DigitalOut climb;
   pros::adi::DigitalOut doinker;
   Pneumatics(pros::adi::DigitalOut clench_port, pros::adi::DigitalOut doinker_port);

   void clench_initialize();
   void clench_control();
   void clench_v(int value);

   void doinker_initialize();
   void doinker_control();
   void doinker_v(int value);

   static int clench_task();
   static int doinker_task();
   
};
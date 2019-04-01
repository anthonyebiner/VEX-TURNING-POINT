#include "declareStuff.hpp"

 void redFrontAuton1(){
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, -0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4_ft, 0_ft, 0_deg}}, "C");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0.5_ft, 0_deg}}, "D");

   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   IntakeM.move(127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   drive.turnAngle(-82_deg);

   pros::delay(0);

   shootBarage();

   drive.turnAngle(33_deg);

   pros::delay(0);

   IntakeM.move(-127);

   driveController.setTarget("C");
   driveController.waitUntilSettled();
 }

 void redFrontAuton2(){

 }

 void redBackAuton1(){

 }

 void redBackAuton2(){

 }

 void blueFrontAuton1(){
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4_ft, 0_ft, 0_deg}}, "C");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0.5_ft, 0_deg}}, "D");

   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   IntakeM.move(127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   drive.turnAngle(82_deg);

   pros::delay(0);

   shootBarage();

   drive.turnAngle(-33_deg);

   pros::delay(0);

   IntakeM.move(-127);

   driveController.setTarget("C");
   driveController.waitUntilSettled();
 }

 void blueFrontAuton2(){

 }

 void blueBackAuton1(){
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2_ft, 0_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.2_ft, 0_ft, 0_deg}}, "C");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.7_ft, 0.83_ft, 0_deg}}, "D");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.5_ft, 0_ft, 0_deg}}, "E");

   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   IntakeM.move(127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   drive.turnAngle(94_deg);
   drive.waitUntilSettled();

   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   IntakeM.move(0);

   drive.turnAngle(95_deg);
   drive.waitUntilSettled();

   driveController.setTarget("C", true);
   driveController.waitUntilSettled();

   goalHeight = 2;
   lift.setTarget(heights[goalHeight]);

   pros::delay(500);

   driveController.setTarget("D");
   driveController.waitUntilSettled();

   goalHeight = 4;
   lift.setTarget(heights[goalHeight]);

   pros::delay(2000);

   driveController.setTarget("B", true);
   driveController.waitUntilSettled();
 }

 void blueBackAuton2(){


 }

 /*
 Commands
 drive.turnAngle(#_deg);

 driveController.generatePath({Point{yinit_ft, xinit_ft, #init_deg}, Point{yinit_ft, xinit_ft, #init_deg}}, "A");
 driveController.setTarget("A");
 driveController.waitUntilSettled();

 Example:

 drive.turnAngle(-90_deg); //makes a quarter turn counterclockwise

 driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A"); //generates a path to drive forward 3 ft
 driveController.setTarget("A", true); //executes previous path backwards (true refers to goind backwards), robot drives backwards 3 ft
 driveController.waitUntilSettled(); //waits until path has executed
 */


 void autonomous() {
   flywheel.moveVoltage(velocityToVoltage(fastVelocity));
   blueBackAuton1();

 }

#include "declareStuff.hpp"

 void redFrontAuton1(){
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, -0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4_ft, 0_ft, 0_deg}}, "C");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0.5_ft, 0_deg}}, "D");//Hi Anthony, Henry is a stand up guy.

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
   IntakeM.move(127);
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4_ft, 0_ft, 0_deg}}, "A");
   driveController.setTarget("A");
   driveController.waitUntilSettled();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.1_ft, 0.5_ft, 0_deg}}, "B");
   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.5_ft, 0_ft, 0_deg}}, "C");
   driveController.setTarget("C");
   driveController.waitUntilSettled();

   drive.turnAngle(-55_deg);
   drive.waitUntilSettled();

   shootBarage();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2.3_ft, 0.4_ft, 0_deg}}, "E");
   driveController.setTarget("E");
   driveController.waitUntilSettled();

   drive.turnAngle(60_deg);
   drive.waitUntilSettled();

   drive.moveDistance(4_ft);
   drive.waitUntilSettled();
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
   IntakeM.move(127);
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4_ft, 0_ft, 0_deg}}, "A");
   driveController.setTarget("A");
   driveController.waitUntilSettled();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.1_ft, 0_ft, 0_deg}}, "B");
   driveController.setTarget("B", true);
   driveController.waitUntilSettled();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.5_ft, 0_ft, 0_deg}}, "C");
   driveController.setTarget("C");
   driveController.waitUntilSettled();

   drive.turnAngle(64_deg);
   drive.waitUntilSettled();

   shootBarage();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2.3_ft, -0.4_ft, 0_deg}}, "E");
   driveController.setTarget("E");
   driveController.waitUntilSettled();

   drive.turnAngle(-60_deg);
   drive.waitUntilSettled();

   drive.moveDistance(4_ft);
   drive.waitUntilSettled();
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
   flywheel.moveVoltage(velocityToVoltage(415));
   redBackAuton1();

 }

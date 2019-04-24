#include "declareStuff.hpp"

 void redFrontAuton1(){         //Use this autonomous. This includes the minute autonomous
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0_ft, 0_deg}}, "A"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, -0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.0_ft, 0_ft, 0_deg}}, "C");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0.5_ft, 0_deg}}, "D");//Hi Anthony, Henry is a stand up guy.
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.75_ft, 0_ft, 0_deg}}, "E"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, 0.75_ft, 0_deg}}, "F"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.0_ft, 0_ft, 0_deg}}, "G");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, -1.5_ft, 0_deg}}, "H");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.5_ft, 0_ft, 0_deg}}, "I");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{7.0_ft, 0_ft, 0_deg}}, "J");

   IntakeM.move(127);

   driveController.setTarget("A");
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);
   driveController.waitUntilSettled();
   driveController.setTarget("D",true);
   driveController.waitUntilSettled();
   driveController.setTarget("E");
   driveController.waitUntilSettled();
   drive.turnAngle(-80_deg);
   driveController.setTarget("C",true);
   pros::delay(0);
   shootBarageFront();
   driveController.setTarget("F");
   driveController.waitUntilSettled();
   driveController.setTarget("H",true);
   driveController.waitUntilSettled();
   drive.turnAngle(25_deg); //originally 25
   drive.waitUntilSettled();
   IntakeM.move(127);
   shootBarageFront2();
   drive.turnAngle(-25_deg);
   drive.waitUntilSettled();
   driveController.setTarget("I",true);
   driveController.waitUntilSettled();
   drive.turnAngle(80_deg);
   drive.waitUntilSettled();
   driveController.setTarget("J");
   driveController.waitUntilSettled();
   


   /*
   IntakeM.move(-127);
   driveController.setTarget("G");                //Stop 15 Second Auton at this time
   driveController.waitUntilSettled();
   IntakeM.move(127);
   driveController.setTarget("G",true);
   driveController.waitUntilSettled();
   drive.turnAngle(180);
   driveController.waitUntilSettled();
   drive.turnAngle(33_deg);

   pros::delay(0);

   IntakeM.move(-127);

   driveController.setTarget("C");
   driveController.waitUntilSettled();
   */
 }

 void redFrontAuton2(){ //do not use this autonomous
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0_ft, 0_deg}}, "A"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, -0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.9_ft, 0_ft, 0_deg}}, "C");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0.5_ft, 0_deg}}, "D");//Hi Anthony, Henry is a stand up guy.
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.75_ft, 0_ft, 0_deg}}, "E"); //hello aiden
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   IntakeM.move(127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
   driveController.setTarget("D",true);
   driveController.waitUntilSettled();
   driveController.setTarget("E");
   driveController.waitUntilSettled();
   drive.turnAngle(-85_deg);
   driveController.setTarget("C",true);
   pros::delay(0);
   shootBarageFront();
   pros::delay(1000);
   drive.turnAngle(-5_deg);
   drive.waitUntilSettled();
   driveController.setTarget("A");
   driveController.waitUntilSettled();
   driveController.setTarget("A",true);
   drive.turnAngle(45);
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
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0_ft, 0_deg}}, "A"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.0_ft, 0_ft, 0_deg}}, "C");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, -0.5_ft, 0_deg}}, "D");//Hi Anthony, Henry is a stand up guy.
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.75_ft, 0_ft, 0_deg}}, "E"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, -0.75_ft, 0_deg}}, "F"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.0_ft, 0_ft, 0_deg}}, "G");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, 1.0_ft, 0_deg}}, "H");

   IntakeM.move(127);

   driveController.setTarget("A");
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);
   driveController.waitUntilSettled();
   driveController.setTarget("D",true);
   driveController.waitUntilSettled();
   driveController.setTarget("E");
   driveController.waitUntilSettled();
   drive.turnAngle(86_deg);
   driveController.setTarget("C",true);
   pros::delay(0);
   shootBarageFront();
   driveController.setTarget("F");
   driveController.waitUntilSettled();
   driveController.setTarget("H",true);
   driveController.waitUntilSettled();
   /*stop here for 15 second auton
   drive.turnAngle(-33_deg); //originally 25
   drive.waitUntilSettled();
   IntakeM.move(127);
   shootBarageFront2();
   */
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

   drive.turnAngle(61_deg);
   drive.waitUntilSettled();

   shootBarage();

   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2.3_ft, -0.4_ft, 0_deg}}, "E");
   driveController.setTarget("E");
   driveController.waitUntilSettled();

   drive.turnAngle(-59_deg);
   drive.waitUntilSettled();

   drive.moveDistance(4_ft);
   drive.waitUntilSettled();
 }

 void blueBackAuton2(){ //hit the red side's flags
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, 2.5_ft, 0_deg}}, "A"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, -0.5_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.0_ft, 0_ft, 0_deg}}, "C");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.75_ft, 0.5_ft, 0_deg}}, "D");//Hi Anthony, Henry is a stand up guy.
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{0.75_ft, 0_ft, 0_deg}}, "E"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, 0.75_ft, 0_deg}}, "F"); //hello aiden
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.0_ft, 0_ft, 0_deg}}, "G");//backwards after forward, backward, froward
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{4.5_ft, -1.0_ft, 0_deg}}, "H");

   IntakeM.move(-127);
   goalHeight = 1;
   lift.setTarget(heights[goalHeight]);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
   pros::delay(1000);
   drive.turnAngle(90_deg);
   drive.waitUntilSettled();
   IntakeM.move(127);
   driveController.setTarget("C");
   driveController.waitUntilSettled();
   drive.turnAngle(-25_deg);
   shootBarage();

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
  redFrontAuton1();
 }

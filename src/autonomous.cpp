#include "declareStuff.hpp"

 void redFrontAuton1(){

 }

 void redFrontAuton2(){

 }

 void redBackAuton1(){

 }

 void redBackAuton2(){

 }

 void blueFrontAuton1(){
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 0_ft, 0_deg}}, "A");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{1.5_ft, 0_ft, 0_deg}}, "B");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2_ft, -0.3_ft, 0_deg}}, "C");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{2_ft, 0.3_ft, 0_deg}}, "D");

   ////////////////////////////////////////////////////////////////////////////////////////////

   IntakeM.move(127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();

   driveController.setTarget("A", true);
   driveController.waitUntilSettled();

   drive.turnAngle(90_deg);

   IntakeM.move(0);

   shootBall(530);

   driveController.setTarget("B");
   driveController.waitUntilSettled();

   shootBall(450);

   driveController.setTarget("C");
   driveController.waitUntilSettled();

   driveController.setTarget("D", true);
   driveController.waitUntilSettled();

   driveController.setTarget("A", true);
   driveController.waitUntilSettled();

   drive.turnAngle(45_deg);

   IntakeM.move(-127);

   driveController.setTarget("A");
   driveController.waitUntilSettled();
 }

 void blueFrontAuton2(){

 }

 void blueBackAuton1(){

 }

 void blueBackAuton2(){

 }

 void autonomous() {
   blueFrontAuton1();   
 }

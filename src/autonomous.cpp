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

 }

 void blueFrontAuton2(){

 }

 void blueBackAuton1(){

 }

 void blueBackAuton2(){

 }

 void autonomous() {
   autonRunning = true;
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.5_ft, 0_ft, 0_deg}}, "A");
   driveController.setTarget("A");
   driveController.waitUntilSettled();
   drive.turnAngle(180_deg);

   autonRunning = false;
 }

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
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3.5_ft, 0_ft, 0_deg}}, "Cap");
   driveController.generatePath({Point{0_ft, 0_ft, 0_deg}, Point{3_ft, 2_ft, 70_deg}}, "Flag");
   driveController.setTarget("Cap");
   driveController.waitUntilSettled();
   driveController.setTarget("Flag", true);
   driveController.waitUntilSettled();

   autonRunning = false;
 }

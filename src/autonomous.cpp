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
   blueFrontAuton1();
 }

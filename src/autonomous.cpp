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
   /*
   if(autonColor == 1 && autonSide == 1 && autonNumber == 1){
     redFrontAuton1();
   }else if(autonColor == 1 && autonSide == 1 && autonNumber == 2){
     redFrontAuton2();
   }else if(autonColor == 1 && autonSide == 2 && autonNumber == 1){
     redBackAuton1();
   }else if(autonColor == 1 && autonSide == 2 && autonNumber == 2){
     redBackAuton2();
   }else if(autonColor == 2 && autonSide == 1 && autonNumber == 1){
     blueFrontAuton1();
   }else if(autonColor == 2 && autonSide == 1 && autonNumber == 2){
     blueFrontAuton2();
   }else if(autonColor == 2 && autonSide == 2 && autonNumber == 1){
     blueBackAuton1();
   }else if(autonColor == 2 && autonSide == 2 && autonNumber == 2){
     blueBackAuton2();
   }
   */
   //shootBall(-400.0);
   /*turnLeft(.17, 150);
   delay(1000);
   IntakeM.move_velocity(-200);
   drive(1100,1100,1100,1100);
   delay(1000);
   IntakeM.move_velocity(0);
   //turnRight(.25,150);
   drive(-750,-750,-750,-750);
   //turnRight(.17, 150);
   shootBall(-440);*/

   shootBall(-525);
   drive(1300,1300,1300,1300);
   drive(-1300,-1300,-1300,-1300);
   /*turnLeft(.25, 150);
   drive(1000,1000,1000,1000);
   moveForward(1500, 0);*/
   autonRunning = false;
 }

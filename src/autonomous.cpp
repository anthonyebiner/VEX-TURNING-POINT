#include "declareStuff.hpp"

 void redFrontAuton1(){
   BackRightM.move_absolute(896.599976,60);
   BackLeftM.move_absolute(901.400024,60);
   while(fabs(BackRightM.get_position()-(896.599976))>5);
   while(fabs(BackLeftM.get_position()-(901.400024))>5);
   delay(400);
   BackRightM.move_absolute(-60.599998,60);
   BackLeftM.move_absolute(-67.599998,60);
   while(fabs(BackRightM.get_position()-(-60.599998))>5);
   while(fabs(BackLeftM.get_position()-(-67.599998))>5);
   delay(400);
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
 }

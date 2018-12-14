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
   if(auton == 1){
     redFrontAuton1();
   }else if(auton == 2){
     redFrontAuton2();
   }else if(auton == 3){
     redBackAuton1();
   }else if(auton == 4){
     redBackAuton2();
   }else if(auton == 5){
     blueFrontAuton1();
   }else if(auton == 6){
     blueFrontAuton2();
   }else if(auton == 7){
     blueBackAuton1();
   }else if(auton == 8){
     blueBackAuton2();
   }
 }

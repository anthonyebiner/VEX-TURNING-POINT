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

   driveController.moveTo({Point{0_ft, 0_ft, 0_deg}, Point{1_ft, 1_ft, 0_deg}});

   autonRunning = false;
 }

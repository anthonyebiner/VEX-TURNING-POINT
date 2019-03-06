#include "declareStuff.hpp"

float velocityToVoltage(int velocity){
  return velocity*21;
}

void testFlywheel(){
  printf("Started \n");
  for(int i = 0; i <= 12000; i+= 500){
    flywheel.moveVoltage(i);
    pros::delay(2250);
    printf("%f \n", flywheel.getActualVelocity());
  }
  flywheel.moveVoltage(0);
  printf("Ended \n");
}

void testFlywheelVoltage(){
  flywheel.moveVoltage(11000);
  for(int i = 0; i <= 80; i++){
    printf("%f \n", flywheel.getActualVelocity());
    pros::delay(250);
  }
}

void testFlywheelVelocity(){
  flywheel.moveVelocity(500);
  for(int i = 0; i <= 80; i++){
    printf("%f \n", flywheel.getActualVelocity());
    pros::delay(250);
  }
}

#include "declareStuff.hpp"

float velocityToVoltage(int velocity){
  return velocity*21;
}

void wait(int ms){
  for(int i = 0; i <= ms; i+=5){
    pros::delay(5);
    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX));
  }
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

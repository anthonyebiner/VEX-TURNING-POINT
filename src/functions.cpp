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

void indexerOut(){
  IntakeM.move(-127);
  pros::delay(250);
  IntakeM.move(0);
  goalHeight = 0;
  lift.setTarget(heights[goalHeight]);
  pros::delay(250);
}

void indexerIn(){
  IntakeM.move(-127);
  pros::delay(150);
  IntakeM.move(0);
  goalHeight = 1;
  lift.setTarget(heights[goalHeight]);
}

void shootBall(){
  IntakeM.move(127);
  pros::delay(400);
  IntakeM.move(0);
}

void shootTwoBallsDriving(void* param){
  flywheel.moveVoltage(velocityToVoltage(550));

  IntakeM.move(-127);
  pros::delay(100);
  IntakeM.move(0);

  goalHeight = 0;
  lift.setTarget(heights[goalHeight]);

  pros::delay(100);

  IntakeM.move(127);
  pros::delay(400);
  IntakeM.move(0);

  pros::delay(100);

  IntakeM.move(127);
  pros::delay(400);
  IntakeM.move(0);

  goalHeight = 1;
  lift.setTarget(heights[goalHeight]);

  flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
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

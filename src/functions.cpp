#include "declareStuff.hpp"

float distanceToDegreesFront(int distance){
  float degrees = 0;
  degrees = 360*((distance)/(3.14159*frontWheelDiameter));
  return degrees;
}

float distanceToDegreesBack(int distance){
  float degrees = 0;
  degrees = 360*((distance)/(3.14159*backWheelDiameter));
  return degrees;
}

int distanceToFlags(){
  vision_object_s_t flag = VisionSensor.get_by_size(0);
  delay(200);
  return flag.height; //test -- remove later
  //return ((midFlagHeight)/(tanf(FOV/360*3.14159-atan((1-(2*(FOV-flag.top_coord-flag.height))/VISION_FOV_HEIGHT)*tanf(FOV/360*3.14159)))));
}

float velocityHigh(){
  float arrayIndex = distanceToFlags()/distanceSeperation;
  int down = arrayIndex;
  int up = down + 1;
  int sloap = (highVelocities[up]-highVelocities[down])/(up-down);
  float adjust = sloap * (distanceToFlags()%distanceSeperation)/distanceSeperation;
  return (highVelocities[down] + adjust);
}

float velocityMid(){
  float arrayIndex = distanceToFlags()/distanceSeperation;
  int down = arrayIndex;
  int up = down + 1;
  int sloap = (midVelocities[up]-midVelocities[down])/(up-down);
  float adjust = sloap * (distanceToFlags()%distanceSeperation)/distanceSeperation;
  return (midVelocities[down] + adjust);
}


/////////////////////////////////////////////////////////////////////////////////////////


void moveForward(int distance, int velocity){
  FrontRightM.move_relative(distanceToDegreesFront(distance), velocity);
  FrontLeftM.move_relative(distanceToDegreesFront(distance), velocity);
  BackRightM.move_relative(distanceToDegreesBack(distance), velocity);
  BackLeftM.move_relative(distanceToDegreesBack(distance), velocity);
}

void moveBackward(int distance, int velocity){
  FrontRightM.move_relative(-distanceToDegreesFront(distance), velocity);
  FrontLeftM.move_relative(-distanceToDegreesFront(distance), velocity);
  BackRightM.move_relative(-distanceToDegreesBack(distance), velocity);
  BackLeftM.move_relative(-distanceToDegreesBack(distance), velocity);
}

void turnLeft(int degrees, int velocity){

}

void turnRight(int degrees, int velocity){

}

void shootBall(float targetVelocity){
  Flywheel1M.move_velocity(targetVelocity);
  Flywheel2M.move_velocity(targetVelocity);
  while(Flywheel1M.get_actual_velocity() - targetVelocity > 1 && Flywheel2M.get_actual_velocity() - targetVelocity > 1){
    if(!MasterC.get_digital(DIGITAL_X) && !MasterC.get_digital(DIGITAL_B) && !MasterC.get_digital(DIGITAL_A)){
      control = true;
      return;
    }
    delay(5);
  }
  IntakeM.move(100);
  while(Flywheel1M.get_actual_velocity() - targetVelocity < 1 && Flywheel2M.get_actual_velocity() - targetVelocity < 1){
    if(!MasterC.get_digital(DIGITAL_X) && !MasterC.get_digital(DIGITAL_B) && !MasterC.get_digital(DIGITAL_A)){
      control = true;
      IntakeM.move(0);
      return;
    }
    delay(5);
  }
  delay(250);
  IntakeM.move(0);
}

void alignBack(){
  while(BackLeftM.get_actual_velocity()<-5 && BackRightM.get_actual_velocity()<-5){
    FrontLeftM.move(-60);
    FrontRightM.move(-60);
    BackLeftM.move(-60);
    BackRightM.move(-60);
    delay(5);
  }
}

void alignFront(){
  while(BackLeftM.get_actual_velocity()>5 && BackRightM.get_actual_velocity()>5){
    FrontLeftM.move(60);
    FrontRightM.move(60);
    BackLeftM.move(60);
    BackRightM.move(60);
    delay(5);
  }
}

void centerShot(){
  vision_object_s_t flag = VisionSensor.get_by_sig(0, 1);
  int error = centerShotTolerance + 1;
  while(abs(error) > centerShotTolerance){
    error=flag.x_middle_coord-(VISION_FOV_WIDTH/2);
    FrontLeftM.move(-error/kp);
    FrontRightM.move(error/kp);
    BackLeftM.move(-error/kp);
    BackRightM.move(error/kp);
    if(!MasterC.get_digital(DIGITAL_X) && !MasterC.get_digital(DIGITAL_B) && !MasterC.get_digital(DIGITAL_A)){
      control = true;
      return;
    }
    delay(5);
  }
}

void shootHigh(){
  control = false;
  centerShot();
  shootBall(velocityHigh());
  control = true;
}

void shootMid(){
  control = false;
  centerShot();
  shootBall(velocityMid());
  control = true;
}

void scoreCapLow(){
  control = false;
  while(MasterC.get_digital(DIGITAL_R2)){

  }
  control = true;
}

void scoreCapHigh(){
  control = false;
  while(MasterC.get_digital(DIGITAL_R1)){

  }
  control = true;
}

void resetPositions(){
  FrontRightM.tare_position();
  FrontLeftM.tare_position();
  BackRightM.tare_position();
  BackLeftM.tare_position();
  IntakeM.tare_position();
  LiftM.tare_position();
  Flywheel1M.tare_position();
  Flywheel2M.tare_position();
}

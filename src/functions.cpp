#include "declareStuff.hpp"
void shootBall(float targetVelocity){
  MasterC.rumble("-");
  Flywheel1M.move_velocity(targetVelocity);
  Flywheel2M.move_velocity(targetVelocity);
  while(fabs(Flywheel1M.get_actual_velocity() - targetVelocity) > 3){
    if(!MasterC.get_digital(DIGITAL_X) && !MasterC.get_digital(DIGITAL_B) && !MasterC.get_digital(DIGITAL_A) && !MasterC.get_digital(DIGITAL_Y) && !autonRunning){
      control = true;
      return;
    }
    int power = MasterC.get_analog(ANALOG_LEFT_Y);
    int turn = MasterC.get_analog(ANALOG_LEFT_X);
    int left = power + turn;
    int right = power - turn;
    FrontRightM.move(right);
    FrontLeftM.move(left);
    BackLeftM.move(left);
    BackRightM.move(right);
    delay(5);
  }
  IntakeM.move(-100);
  delay(250);
  while(fabs(Flywheel1M.get_actual_velocity() - targetVelocity) < 50){
    if(!MasterC.get_digital(DIGITAL_X) && !MasterC.get_digital(DIGITAL_B) && !MasterC.get_digital(DIGITAL_A) && !MasterC.get_digital(DIGITAL_Y) && !autonRunning){
      control = true;
      IntakeM.move(0);
      return;
    }
    delay(5);
  }
  delay(100);
  IntakeM.move(0);
  Flywheel1M.move_velocity(0);
  Flywheel2M.move_velocity(0);
  MasterC.rumble("-");
}\

void shootBarage(){
  control = false;
  shootBall(-500);
  delay(900);
  IntakeM.move(-100);
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

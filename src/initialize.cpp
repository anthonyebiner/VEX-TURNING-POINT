#include "headerTest.hpp"
Motor FrontRightM(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor FrontLeftM(2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor BackRightM(3, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
Motor BackLeftM(4, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor IntakeM(5, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor LiftM(6, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor Flywheel1M(7, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
Motor Flywheel2M(8, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

Vision VisionSensor(9);

Controller MasterC(CONTROLLER_MASTER);
Controller PartnerC(CONTROLLER_PARTNER);

int frontWheelDiameter = 6;
int backWheelDiameter = 8;

int midFlagHeight = 28;
int visionHeight = 11;
int FOV = 47;
int sizeOfVisionField = 212;

int centerShotTolerance = 5;
int kp = 1;

int distanceSeperation = 10; //inches
int highVelocities [10] = {10,15,20,25,30,35,40,45,50,55}; //fill these in
int midVelocities [10] = {5,10,15,20,25,30,35,40,45,50}; //fill these in


void initialize() {
	resetPositions();
	Flywheel1M.set_brake_mode(MOTOR_BRAKE_COAST);
	Flywheel2M.set_brake_mode(MOTOR_BRAKE_COAST);
	IntakeM.set_brake_mode(MOTOR_BRAKE_BRAKE);
	LiftM.set_brake_mode(MOTOR_BRAKE_HOLD);
	FrontLeftM.set_brake_mode(MOTOR_BRAKE_HOLD);
	FrontRightM.set_brake_mode(MOTOR_BRAKE_HOLD);
	BackRightM.set_brake_mode(MOTOR_BRAKE_HOLD);
	BackLeftM.set_brake_mode(MOTOR_BRAKE_HOLD);
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

void disabled() {

}

void competition_initialize() {

}

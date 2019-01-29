#include "declareStuff.hpp"
Motor FrontRightM(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor FrontLeftM(2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor BackRightM(3, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor BackLeftM(4, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor IntakeM(5, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor LiftM(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor Flywheel1M(7, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
Motor Flywheel2M(8, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

Vision VisionSensor(9);

Controller MasterC(CONTROLLER_MASTER);
Controller PartnerC(CONTROLLER_PARTNER);

int frontWheelDiameter = 6;
int backWheelDiameter = 8;

int midFlagHeight = 28;
int visionHeight = 11;
int FOV = 47;

int centerShotTolerance = 5;
int kp = 1;

int distanceSeperation = 10; //inches
int highVelocities [10] = {10,15,20,25,30,35,40,45,50,55}; //fill these in
int midVelocities [10] = {5,10,15,20,25,30,35,40,45,50}; //fill these in

int autonColor=1;
int autonSide=1;
int autonNumber=1;

bool autonRunning = false;

vision_signature_s_t Red = Vision::signature_from_utility(1, 8103, 8763, 8432, -361, 353, -4, 9, 0);
vision_signature_s_t Blue = Vision::signature_from_utility(2, -2979, -2465, -2722, 9615, 10923, 10268, 9, 0);
vision_signature_s_t Green = Vision::signature_from_utility(3, -2979, -2465, -2722, 9615, 10923, 10268, 9, 0); //update later

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

	VisionSensor.set_signature(1, &Red);
	VisionSensor.set_signature(2, &Blue);
	VisionSensor.set_signature(3, &Green);

	vision_color_code_t redFlag = VisionSensor.create_color_code(1, 3);
	vision_color_code_t blueFlag = VisionSensor.create_color_code(2, 3);

	initGraphics();
}

void disabled() {

}

void competition_initialize() {

}

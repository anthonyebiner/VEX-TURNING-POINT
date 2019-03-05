#include "declareStuff.hpp"
Motor FrontRightM(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor FrontLeftM(2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor BackRightM(3, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor BackLeftM(4, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor IntakeM(5, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
Motor LiftM(6, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor Flywheel1M(9, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
Motor Flywheel2M(10, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

Controller MasterC(CONTROLLER_MASTER);

bool autonRunning = false;

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

void disabled() {

}

void competition_initialize() {

}

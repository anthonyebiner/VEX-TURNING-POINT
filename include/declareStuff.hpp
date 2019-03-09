#ifndef headerTest
#define headerTest
#include "main.h"

extern Motor FrontRightM;
extern Motor FrontLeftM;
extern Motor BackRightM;
extern Motor BackLeftM;
extern Motor IntakeM;
extern Motor LiftM;
extern Motor Flywheel1M;
extern Motor Flywheel2M;

extern Controller MasterC;

extern ControllerButton intakeInButton;
extern ControllerButton intakeOutButton;
extern ControllerButton runFlywheelFastButton;
extern ControllerButton runFlywheelMediumButton;
extern ControllerButton runFlywheelSlowButton;
extern ControllerButton barrageButton;
extern ControllerButton liftUpButton;
extern ControllerButton liftDownButton;

extern AsyncPosIntegratedController lift;
extern ChassisControllerIntegrated drive;

extern MotorGroup flywheel;

extern AsyncMotionProfileController driveController;

extern int fastVelocity;
extern int mediumVelocity;
extern int slowVelocity;
extern int defaultVelocity;

extern const int NUM_HEIGHTS;
extern const int height1;
extern const int height2;
extern const int height3;
extern const int height4;

extern const int heights[];

extern int goalHeight;

float velocityToVoltage(int velocity);
void wait(int ms);
void indexerOut();
void indexerIn();
void shootBall();
void shootTwoBallsDriving();
void testFlywheel();
#endif

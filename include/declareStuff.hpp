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

extern Vision VisionSensor;

extern Controller MasterC;
extern Controller PartnerC;
extern bool control;
extern int autonColor;
extern int autonSide;
extern int autonNumber;

extern int frontWheelDiameter;
extern int backWheelDiameter;

extern int midFlagHeight;
extern int visionHeight;
extern int FOV;

extern int centerShotTolerance;
extern int kp;

extern int distanceSeperation;
extern int highVelocities[];
extern int midVelocities[];

extern int velocity;

extern int distanceToFlags();

extern void moveForward();
extern void moveBackward();
extern void turnLeft();
extern void turnRight();

extern void alignBack();
extern void alignFront();
extern void centerShot();
extern void shootHigh();
extern void shootMid();
extern void scoreCapLow();
extern void scoreCapHigh();
extern void shootDefault();

extern void resetPositions();

extern void initGraphics();
#endif

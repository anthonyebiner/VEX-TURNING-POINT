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
extern vision_signature_s_t Red;
extern vision_signature_s_t Blue;
extern vision_signature_s_t Green;
extern vision_color_code_t redFlag;
extern vision_color_code_t blueFlag;

extern Controller MasterC;
extern Controller PartnerC;
extern bool control;
extern bool autonRunning;
extern int autonColor;
extern int autonSide;
extern int autonNumber;

extern float frontWheelDiameter;
extern float backWheelDiameter;

extern int midFlagHeight;
extern int visionHeight;

extern int centerShotTolerance;
extern int kp;

extern int distanceSeperation;
extern int highVelocities[];
extern int midVelocities[];

extern int frontVelocity;
extern int backVelocity;

extern int distanceToFlags();

extern void moveForward(int distance, int velocity);
extern void drive(int fr, int fl, int bl, int br);
extern void moveBackward(int distance, int velocity);
extern void turnLeft(float turn, int velocity);
extern void turnRight(float turn, int velocity);

extern void alignBack();
extern void alignFront();
extern void centerShot();
extern void shootHigh();
extern void shootMid();
extern void scoreCapLow();
extern void scoreCapHigh();
extern void shootDefault();
extern void waitUntilSettled();

void shootBall(float targetVelocity);
void shootBarage();

extern void resetPositions();

extern void initGraphics();
#endif

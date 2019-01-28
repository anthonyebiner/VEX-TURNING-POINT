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
vision_signature_s_t RED_SIG = {1, {255, 255, 255}, 8103, 8763, 8432, -361, 353, -4, 9, 0};
vision_signature_s_t BLUEFLAG = {2, {255, 255, 255}, -2979, -2465, -2722, 9615, 10923, 10268, 9, 0};

extern Controller MasterC;
extern Controller PartnerC;
extern bool control;
extern bool autonRunning;
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

extern void moveForward(int distance, int velocity);
extern void moveBackward(int distance, int velocity);
extern void turnLeft(int degrees, int velocity);
extern void turnRight(int degrees, int velocity);

extern void alignBack();
extern void alignFront();
extern void centerShot();
extern void shootHigh();
extern void shootMid();
extern void scoreCapLow();
extern void scoreCapHigh();
extern void shootDefault();

void shootBall(float targetVelocity);

extern void resetPositions();

extern void initGraphics();
#endif

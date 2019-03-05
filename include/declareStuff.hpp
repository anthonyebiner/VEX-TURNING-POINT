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
extern Controller PartnerC;
extern bool control;
extern bool autonRunning;

extern int frontVelocity;
extern int backVelocity;

void shootBall(float targetVelocity);
void shootBarage();
#endif

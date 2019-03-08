/*
*			    .ue~~%u.     cuuu....uK      .--~*teu.        .ue~~%u.      .xH888888Hx.
*			  .d88   z88i    888888888      dF     988Nx    .d88   z88i   .H8888888888888:
*			 x888E  *8888    8*888**"      d888b   `8888>  x888E  *8888   888*"""?""*88888X
*			:8888E   ^""     >  .....      ?8888>  98888F :8888E   ^""   'f     d8x.   ^%88k
*			98888E.=tWc.     Lz"  ^888Nu    "**"  x88888~ 98888E.=tWc.   '>    <88888X   '?8
*			98888N  '888N    F     '8888k        d8888*`  98888N  '888N   `:..:`888888>    8>
*			98888E   8888E   ..     88888>     z8**"`   : 98888E   8888E         `"*88     X
*			'8888E   8888E  @888L   88888    :?.....  ..F '8888E   8888E    .xHHhx.."      !
*			 ?888E   8888" '8888F   8888F   <""888888888~  ?888E   8888"   X88888888hx. ..!
*			  "88&   888"   %8F"   d888"    8:  "888888*    "88&   888"   !   "*888888888"
*			    ""==*""      ^"===*%"`      ""    "**"`       ""==*""            ^"***"`

Team:								6526D

Programmer(s):			Anthony Ebiner
Conception Date: 		10/15/2018
Purpose:						Competition code for 6526D
*/
#include "declareStuff.hpp"

int fastVelocity = 525;
int mediumVelocity = 480;
int slowVelocity = 450;
int defaultVelocity = 500;

const int NUM_HEIGHTS = 5;
const int height0 = 70;
const int height1 = -20;
const int height2 = -100;
const int height3 = -200;
const int height4 = -300;

const int heights[NUM_HEIGHTS] = {height0, height1, height2, height3, height4};

int goalHeight = 0;

bool control = true;

bool decelerating;
void decelerate(void* param){
  decelerating = true;
  int sped = Flywheel1M.get_actual_velocity();
  while(intakeInButton.isPressed()){
    sped -= 3;
    if(sped < -50){
      sped = -50;
    }
    flywheel.moveVoltage(velocityToVoltage(sped));
    pros::delay(5);
  }
  decelerating = false;
}

//starts user control
void opcontrol() {
  flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
  IntakeM.move(127);

  while(true){
    if((runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed() || runFlywheelSlowButton.isPressed())
       && intakeInButton.isPressed()){
      IntakeM.move(127);
    }else if((runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed() || runFlywheelSlowButton.isPressed())){
  		IntakeM.move(0);
    }else if(!(runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed() || runFlywheelSlowButton.isPressed())){
  		IntakeM.move(127);
    }

    if (liftUpButton.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {
      goalHeight++;
      lift.setTarget(heights[goalHeight]);
    } else if (liftDownButton.changedToPressed() && goalHeight > 1) {
      goalHeight--;
      lift.setTarget(heights[goalHeight]);
    }

/*
    if(runFlywheelFastButton.isPressed()){
      flywheel.moveVoltage(velocityToVoltage(fastVelocity));
    }else if(runFlywheelMediumButton.isPressed()){
      flywheel.moveVoltage(velocityToVoltage(mediumVelocity));
    }else if(runFlywheelSlowButton.isPressed()){
      flywheel.moveVoltage(velocityToVoltage(slowVelocity));
    }else if(intakeInButton.isPressed() && !decelerating){
      pros::Task decelerateTask (decelerate, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
    }else if(!decelerating){
      Flywheel1M.move(0);
      Flywheel2M.move(0);
    }
*/

    if(runFlywheelFastButton.changedToPressed()){
      flywheel.moveVoltage(velocityToVoltage(fastVelocity));
      IntakeM.move(-127);
      wait(100);
      IntakeM.move(0);
      goalHeight = 0;
      lift.setTarget(heights[goalHeight]);
    }else if(runFlywheelFastButton.changedToReleased()){
      flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
      IntakeM.move(-127);
      wait(150);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
    }else if(runFlywheelMediumButton.changedToPressed()){
      flywheel.moveVoltage(velocityToVoltage(mediumVelocity));
      IntakeM.move(-127);
      wait(100);
      IntakeM.move(0);
      goalHeight = 0;
      lift.setTarget(heights[goalHeight]);
    }else if(runFlywheelMediumButton.changedToReleased()){
      flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
      IntakeM.move(-127);
      wait(150);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
    }else if(runFlywheelSlowButton.changedToPressed()){
      flywheel.moveVoltage(velocityToVoltage(slowVelocity));
      IntakeM.move(-127);
      wait(100);
      IntakeM.move(0);
      goalHeight = 0;
      lift.setTarget(heights[goalHeight]);
    }else if(runFlywheelSlowButton.changedToReleased()){
      flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
      IntakeM.move(-127);
      wait(150);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
    }


    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX));


    if(abs(fastVelocity) - fabs(Flywheel1M.get_actual_velocity()) < 20 && runFlywheelFastButton.isPressed()){
      MasterC.rumble("-");
    }else if(abs(mediumVelocity) - fabs(Flywheel1M.get_actual_velocity()) < 20 && runFlywheelMediumButton.isPressed()){
      MasterC.rumble("-");;
    }else if(abs(slowVelocity) - fabs(Flywheel1M.get_actual_velocity()) < 20 && runFlywheelSlowButton.isPressed()){
      MasterC.rumble("-");;
    }


    pros::delay(5);
  }
}

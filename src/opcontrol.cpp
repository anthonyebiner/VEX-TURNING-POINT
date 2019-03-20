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
int defaultVelocity = 500;

bool twoBalls = false;

const int NUM_HEIGHTS = 5;
const int height0 = -50;
const int height1 = 100;
const int height2 = 300;
const int height3 = 1200;
const int height4 = 1600;

const int heights[NUM_HEIGHTS] = {height0, height1, height2, height3, height4};

int goalHeight = 0;

bool control = true;


//starts user control
void opcontrol() {
  goalHeight = 0;
  lift.setTarget(heights[goalHeight]);

  pros::delay(250);

  goalHeight = 1;
  lift.setTarget(heights[goalHeight]);

  //flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
  IntakeM.move(127);

  while(true){
    if(barrageButton.isPressed() && intakeInButton.changedToPressed()){
      IntakeM.move(127);
      wait(100);
      flywheel.moveVoltage(0);
      wait(500);
      flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
    }else if((barrageButton.isPressed() || runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed()) && intakeInButton.isPressed()){
      IntakeM.move(127);
    }else if(!(barrageButton.isPressed() || runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed()) && intakeOutButton.isPressed()){
  		IntakeM.move(-127);
    }else if(!(barrageButton.isPressed() || runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed()) && intakeInButton.isPressed()){
  		IntakeM.move(0);
    }else if((barrageButton.isPressed() || runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed())){
  		IntakeM.move(0);
    }else if(goalHeight > 1){
  		IntakeM.move(0);
    }else if(!twoBalls){
  		IntakeM.move(127);
    }else{
      IntakeM.move(0);
    }

    if (liftUpButton.changedToPressed() && goalHeight < NUM_HEIGHTS - 1) {
      goalHeight++;
      lift.setTarget(heights[goalHeight]);
    } else if (liftDownButton.changedToPressed() && goalHeight > 1) {
      goalHeight--;
      lift.setTarget(heights[goalHeight]);
    }

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
      wait(250);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
      wait(300);
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
      wait(250);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
      wait(300);
    }else if(barrageButton.changedToPressed()){
      flywheel.moveVoltage(velocityToVoltage(fastVelocity));
      IntakeM.move(-127);
      wait(100);
      IntakeM.move(0);
      goalHeight = 0;
      lift.setTarget(heights[goalHeight]);
    }else if(barrageButton.changedToReleased()){
      flywheel.moveVoltage(velocityToVoltage(defaultVelocity));
      IntakeM.move(-127);
      wait(250);
      IntakeM.move(0);
      goalHeight = 1;
      lift.setTarget(heights[goalHeight]);
      wait(300);
    }


    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX));


    if(abs(fastVelocity - Flywheel1M.get_actual_velocity()) < 20 && runFlywheelFastButton.isPressed()){
      MasterC.rumble("-");
    }else if(abs(mediumVelocity - Flywheel1M.get_actual_velocity()) < 20 && runFlywheelMediumButton.isPressed()){
      MasterC.rumble("-");;
    }


    if(twoBallsButton.changedToReleased()){
      twoBalls = !twoBalls;
    }else if((barrageButton.isPressed() || runFlywheelFastButton.isPressed() || runFlywheelMediumButton.isPressed()) && intakeInButton.isPressed()){
      twoBalls = false;
    }

    pros::delay(5);
  }
}

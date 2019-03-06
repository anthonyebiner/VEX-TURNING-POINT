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

int fastVelocity = 500;
int mediumVelocity = 470;
int slowVelocity = 430;
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
  while(true){
  	if(intakeInButton.isPressed()){
  		IntakeM.move(127);

  	}else if(intakeOutButton.isPressed()){
			IntakeM.move(-127);

  	}else{
  		IntakeM.move(0);
		}


    if(abs(MasterC.getAnalog(ControllerAnalog::rightY))<15){
      LiftM.move_velocity(0);

    }else{
      LiftM.move(MasterC.getAnalog(ControllerAnalog::rightY));
    }


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


    drive.arcade(MasterC.getAnalog(ControllerAnalog::leftY), MasterC.getAnalog(ControllerAnalog::leftX));


    if(abs(525) - fabs(Flywheel1M.get_actual_velocity()) < 5 && runFlywheelFastButton.isPressed()){
      MasterC.rumble("-");
    }else if(abs(480) - fabs(Flywheel1M.get_actual_velocity()) < 5 && runFlywheelSlowButton.isPressed()){
      MasterC.rumble("-");;
    }


    pros::delay(5);
  }
}

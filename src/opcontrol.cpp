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

Code Version:				V10
Last Modified: 			11/12/2018
*/
#include "headerTest.hpp"

int velocity = -550;
bool control = true;

int adjust = 1; //number divided by motor power in order to keep recording a managable speed
bool recording = false; //are we recording

void record(void* param){
  int accuracy = 5; //accurracy of motors in degrees
  MasterC.print(0, 0, "record started",NULL);
  recording = true; //recording has started
  adjust = 4; //slow down drive

  int positionsTemp = 0; //clear number of positions
  float motorPosTemp [100][10] = {}; //clear saved motor positions

  resetPositions(); //reset absolute motor positions

  //save positions when user presses R1
  while(!MasterC.get_digital(DIGITAL_UP)){ //exit position saver when user presses L1
    if(MasterC.get_digital(DIGITAL_DOWN)){ //saves positions
      control = false;
      motorPosTemp[positionsTemp][0] = FrontRightM.get_position();
      motorPosTemp[positionsTemp][1] = FrontLeftM.get_position();
      motorPosTemp[positionsTemp][2] = BackRightM.get_position();
      motorPosTemp[positionsTemp][3] = BackLeftM.get_position();
      motorPosTemp[positionsTemp][4] = IntakeM.get_position();
      motorPosTemp[positionsTemp][5] = LiftM.get_position();
      MasterC.print(0, 0, "positions: %d", motorPosTemp[positionsTemp][0]);
      positionsTemp++; //say that we now have one more position
      while(MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until button is released so that we don't save multiple positions
      control = true;
    }
    delay(5);
  }
  while(MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until L1 is released
  while(MasterC.get_digital(DIGITAL_UP)){delay(5);} //wait until R1 is released

  MasterC.print(0, 0, "play?", NULL);
  resetPositions();
  //Replay autonomous if user presses L1
  while(!MasterC.get_digital(DIGITAL_UP) && !MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until user makes a selection
  if(MasterC.get_digital(DIGITAL_UP)){ //replays autonomous
    for(int i = 0; i < 100; i++){ //loops through each position up to the number of saved positions
      FrontRightM.move_absolute(motorPosTemp[i][0], 100); //moves the motor to the saved positions
      FrontLeftM.move_absolute(motorPosTemp[i][1], 100); //all the motors move at once
      BackRightM.move_absolute(motorPosTemp[i][2], 100);
      BackLeftM.move_absolute(motorPosTemp[i][3], 100);
      IntakeM.move_absolute(motorPosTemp[i][4], 100);
      LiftM.move_absolute(motorPosTemp[i][5], 50);
      MasterC.print(0, 0, "Running: %d", i);
      delay(5000);
    }
  }
  MasterC.print(0, 0, "Finished", NULL);
  while(MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until L1 is released
  while(MasterC.get_digital(DIGITAL_UP)){delay(5);} //wait until R1 is released
/*
  MasterC.print(0, 0, "Transfer?",NULL);
  //Save autonomus if user presses L1
  while(!MasterC.get_digital(DIGITAL_UP) && !MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until user makes a selection
  if(MasterC.get_digital(DIGITAL_UP)){
    //transferRecordedAuton(accuracy, positionsTemp, motorPosTemp); //transfers saved positions to autonomus.cpp
  }
*/
  adjust = 1; //return drive to normal speed
  recording = false; //recording has ended
}

//starts methods
void opcontrol() {

  while(true){
    if(control){
    	if(MasterC.get_digital(DIGITAL_L1)){
    		IntakeM.move(127);
  		}else if(MasterC.get_digital(DIGITAL_L2)){
  			IntakeM.move(-127);
  		}else{
  			IntakeM.move(0);
  		}

    	if(MasterC.get_digital(DIGITAL_X)){
    		LiftM.move(127);
    	}else if(MasterC.get_digital(DIGITAL_B)){
  			LiftM.move(-127);
  		}else{
  			LiftM.move(0);
  		}

      int power = MasterC.get_analog(ANALOG_LEFT_Y);
      int turn = MasterC.get_analog(ANALOG_LEFT_X);
      if(recording){
        if(power < 100 && power > -100){
          power = 0;
        }
        if(turn < 100 && turn > -100){
          turn = 0;
        }
      }
      int left = power + turn;
      int right = power - turn;
      FrontRightM.move(right/adjust);
   		FrontLeftM.move(left/adjust);
   		BackLeftM.move(left/adjust);
   		BackRightM.move(right/adjust);
    }


    if(MasterC.get_digital(DIGITAL_R1)){
      velocity = velocity - 10;
      while(MasterC.get_digital(DIGITAL_R1)){}
      MasterC.print(0, 0, "target: %d", abs(velocity));
    }else if(MasterC.get_digital(DIGITAL_R2)){
      velocity = velocity + 10;
      while(MasterC.get_digital(DIGITAL_R2)){}
      MasterC.print(0, 0, "target: %d", abs(velocity));
    }

    if(MasterC.get_digital(DIGITAL_A)){
      Flywheel1M.move_velocity(velocity);
      Flywheel2M.move_velocity(velocity);
    }else if(MasterC.get_digital(DIGITAL_X)){
      //shootHigh();
      while(MasterC.get_digital(DIGITAL_X)){delay(5);}
    }else if(MasterC.get_digital(DIGITAL_B)){
      //shootMid();
      while(MasterC.get_digital(DIGITAL_B)){delay(5);}
    }else{
      Flywheel1M.move(0);
      Flywheel2M.move(0);
    }

    if(abs(velocity) - abs(Flywheel1M.get_actual_velocity()) < 5){
      MasterC.rumble("-");
    }
    delay(2);

    if(MasterC.get_digital(DIGITAL_UP) && !recording && !competition::is_connected()){
      while(MasterC.get_digital(DIGITAL_UP)){};
      Task recordTask (record, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
    }

    if(MasterC.get_digital(DIGITAL_LEFT)){
      MasterC.print(0,0, "distance: %d", distanceToFlags());
    }
  }
}

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

int velocity = -500;
bool control = true;

int adjust = 1; //number divided by motor power in order to keep recording at a managable speed
bool recording = false; //are we recording

int positionsTemp;
float motorPosTemp [100][10];

void record(void* param){
  MasterC.rumble("-");
  MasterC.clear();
  MasterC.print(0, 0, "Press down to save; up to stop",NULL);
  recording = true; //recording has started
  adjust = 4; //slow down drive

  positionsTemp = 0; //clear number of positions
  motorPosTemp [99][9] = {}; //clear saved motor positions

  resetPositions(); //reset absolute motor positions

  //save positions when user presses up
  while(!MasterC.get_digital(DIGITAL_UP)){ //exit position saver when user presses down
    if(MasterC.get_digital(DIGITAL_DOWN)){ //saves positions
      control = false;
      MasterC.rumble(".");
      //motorPosTemp[positionsTemp][0] = FrontRightM.get_position();
      //motorPosTemp[positionsTemp][1] = FrontLeftM.get_position();
      motorPosTemp[positionsTemp][2] = BackRightM.get_position();
      motorPosTemp[positionsTemp][3] = BackLeftM.get_position();
      //motorPosTemp[positionsTemp][4] = IntakeM.get_position();
      //motorPosTemp[positionsTemp][5] = LiftM.get_position();
      MasterC.clear();
      MasterC.print(0, 0, "positions: %d", motorPosTemp[positionsTemp][0]);
      positionsTemp++; //say that we now have one more position
      while(MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until button is released so that we don't save multiple positions
      control = true;
    }
    delay(5);
  }
  MasterC.clear();
  MasterC.print(0, 0, "Finished", NULL);
  while(MasterC.get_digital(DIGITAL_DOWN)){delay(5);} //wait until down is released
  while(MasterC.get_digital(DIGITAL_UP)){delay(5);} //wait until up is released
  adjust = 1; //return drive to normal speed
  MasterC.rumble("-");
  recording = false; //recording has ended
}

bool decelerating;
void decelerate(void* param){
  decelerating = true;
  int sped = Flywheel1M.get_actual_velocity();
  while(MasterC.get_digital(DIGITAL_L1)){
    sped += 5;
    if(sped > 50){
      sped = 55;
    }
    Flywheel1M.move_velocity(sped);
    Flywheel2M.move_velocity(sped);
    delay(5);
  }
  decelerating = false;
}

//starts user control
void opcontrol() {

  while(true){
    if(control){
    	if(MasterC.get_digital(DIGITAL_L1)){
    		IntakeM.move(-127);
  		}else if(MasterC.get_digital(DIGITAL_L2)){
  			IntakeM.move(127);
  		}else{
  			IntakeM.move(0);
  		}

      if(abs(MasterC.get_analog(ANALOG_RIGHT_Y))<15){
        LiftM.move_velocity(0);
      }else{
        LiftM.move(MasterC.get_analog(ANALOG_RIGHT_Y));
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

/*
      if(MasterC.get_digital(DIGITAL_R1)){
        velocity = velocity - 10;
        while(MasterC.get_digital(DIGITAL_R1)){}
        MasterC.clear();
        MasterC.print(0, 0, "target: %d", abs(velocity));
      }else if(MasterC.get_digital(DIGITAL_R2)){
        velocity = velocity + 10;
        while(MasterC.get_digital(DIGITAL_R2)){}
        MasterC.clear();
        MasterC.print(0, 0, "target: %d", abs(velocity));
      }*/

      if(MasterC.get_digital(DIGITAL_A)){
        Flywheel1M.move_velocity(velocity);
        Flywheel2M.move_velocity(velocity);
      }else if(MasterC.get_digital(DIGITAL_X)){
        //shootHigh();
        while(MasterC.get_digital(DIGITAL_X)){delay(5);}
      }else if(MasterC.get_digital(DIGITAL_B)){
        //shootMid();
        while(MasterC.get_digital(DIGITAL_B)){delay(5);}
      }else if(MasterC.get_digital(DIGITAL_Y)){
        shootDefault();
        while(MasterC.get_digital(DIGITAL_Y)){delay(5);}
      }else if(MasterC.get_digital(DIGITAL_L1) && !decelerating){
        Task decelerateTask (decelerate, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
      }else if(!decelerating){
        Flywheel1M.move(0);
        Flywheel2M.move(0);
      }
    }

    if(abs(velocity) - fabs(Flywheel1M.get_actual_velocity()) < 5){
      MasterC.rumble("-");
    }

    /*
    if(MasterC.get_digital(DIGITAL_UP) && !recording && !competition::is_connected()){
      while(MasterC.get_digital(DIGITAL_UP)){};
      Task recordTask (record, NULL, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "");
    }

    if(MasterC.get_digital(DIGITAL_DOWN) && !recording && !competition::is_connected()){
      while(MasterC.get_digital(DIGITAL_DOWN)){};
      for(int i = 0; i<positionsTemp; i++){
          //printf("FrontRightM.move_absolute(%f,100);\n", motorPosTemp[i][0]);
          //printf("FrontLeftM.move_absolute(%f,100);\n", motorPosTemp[i][1]);
          printf("BackRightM.move_absolute(%f,60);\n", motorPosTemp[i][2]);
          printf("BackLeftM.move_absolute(%f,60);\n", motorPosTemp[i][3]);
          //printf("IntakeM.move_absolute(%f,100);\n", motorPosTemp[i][4]);
          //printf("LiftM.move_absolute(%f,50);\n", motorPosTemp[i][5]);
          //printf("while(fabs(FrontRightM.get_position()-%f)>5);\n", motorPosTemp[i][0]);
          //printf("while(fabs(FrontLeftM.get_position()-%f)>5);\n", motorPosTemp[i][1]);
          printf("while(fabs(BackRightM.get_position()-(%f))>5);\n", motorPosTemp[i][2]);
          printf("while(fabs(BackLeftM.get_position()-(%f))>5);\n", motorPosTemp[i][3]);
          //printf("while(fabs(IntakeM.get_position()-%f)>5);\n", motorPosTemp[i][4]);
          //printf("while(fabs(LiftM.get_position()-%f)>5);\n", motorPosTemp[i][5]);
          printf("delay(400);\n");
      }
    }
    */
    delay(5);
  }
}

#include "declareStuff.hpp"

 float motorPos [100][10];
 int positions;
 int accuracy;

 void transferRecordedAuton(int accuracyNew, int positionsNew, float motorPosNew [100][10]){
   positions = positionsNew;
   accuracy = accuracyNew;
   for(int i = 0; i<100; i++){
     for(int a = 0; a<10; a++){
       motorPos[i][a] = motorPosNew[i][a];
     }
   }
 }

 void autonomous() {
   for(int i = 0; i < positions; i++){
     FrontRightM.move_absolute(motorPos[i][0], 100);
     FrontLeftM.move_absolute(motorPos[i][1], 100);
     BackRightM.move_absolute(motorPos[i][2], 100);
     BackLeftM.move_absolute(motorPos[i][3], 100);
     IntakeM.move_absolute(motorPos[i][4], 100);
     LiftM.move_absolute(motorPos[i][5], 50);
     while(fabs(FrontRightM.get_position()-motorPos[i][0])>accuracy && fabs(FrontLeftM.get_position()-motorPos[i][1])>accuracy
           && fabs(BackRightM.get_position()-motorPos[i][2])>accuracy && fabs(BackLeftM.get_position()-motorPos[i][3])>accuracy
           && fabs(IntakeM.get_position()-motorPos[i][4])>accuracy && fabs(LiftM.get_position()-motorPos[i][5])>accuracy){delay(5);}
   }
 }

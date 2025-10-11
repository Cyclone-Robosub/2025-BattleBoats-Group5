#include "motors.h"
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

void loop() {

  float properDistance=14;
  int gradientConstant=20;
  int speed=100;

  float frontDist = readDistanceCMFront();
  float rightDist = readDistanceCMRight();

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");


  gradient=properDistance-rightDist;


/*
//ALL THE CONSTANT WILL BE CHANGED
  if (frontDist < 15) {     //These parameters can be changed

      turnLeft(speed);

  }else{
    if(gradient > 0){
      adjustLeft(speed,gradient * gradientConstant);
    }else{
      if(gradient < 0){
        adjustRight(speed,-gradient * gradientConstant);
      
      }else{driveForward(speed);}
    }
  }
*/
delay(100);}
    

 

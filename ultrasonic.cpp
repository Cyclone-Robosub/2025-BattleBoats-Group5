#include "ultrasonic.h"

void ultrasonicInit() {
  // configure ultrasonic pins
  pinMode(TRIG1_PIN, OUTPUT);
  pinMode(ECHO1_PIN, INPUT);

  pinMode(TRIG2_PIN, OUTPUT);
  pinMode(ECHO2_PIN, INPUT);
}




float readDistanceCMFront() {
  // Set TRIG low 
  
  float totalDistance=0;

  // use the average distance to deal with the noise
  for(int i=0;i<3;i++){
  
  digitalWrite(TRIG1_PIN, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG1_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1_PIN, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO1_PIN, HIGH);
  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;

  //If time out, return a very large number.
  if(duration_us==0){distance=400.0;}

  totalDistance+=distance;
  }
  
  return totalDistance/3;
}


float readDistanceCMRight() {
  // Set TRIG low 
  
  float totalDistance=0;

  // use the average distance to deal with the noise
  for(int i=0;i<3;i++){
  
  digitalWrite(TRIG2_PIN, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG2_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2_PIN, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO2_PIN, HIGH);
  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;

  //If time out, return a very large number.
  if(duration_us==0){distance=400.0;}

  totalDistance+=distance;
  }
  
  return totalDistance/3;
}
#include "ultrasonic.h"

void ultrasonicInit() {
  // configure ultrasonic pins
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);

  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
}




float readDistanceCMFront() {
  // Set TRIG low 
  
  float totalDistance=0;

  // use the average distance to deal with the noise
  for(int i=0;i<3;i++){
  
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PIN1, HIGH,3000UL);
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
  
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PIN2, HIGH,3000UL);
  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;

  //If time out, return a very large number.
  if(duration_us==0){distance=400.0;}

  totalDistance+=distance;
  }
  
  return totalDistance/3;
}
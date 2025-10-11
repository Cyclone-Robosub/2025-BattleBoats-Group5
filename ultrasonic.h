#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG1_PIN 2         //front
#define ECHO1_PIN 3

#define TRIG2_PIN 4        //right
#define ECHO2_PIN 5

void ultrasonicInit();
float readDistanceCMFront();
float readDistanceCMRight();

#endif

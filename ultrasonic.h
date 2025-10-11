#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG1_PIN 13         //front
#define ECHO1_PIN 2

#define TRIG2_PIN 11        //right
#define ECHO2_PIN 12

void ultrasonicInit();
float readDistanceCMFront();
float readDistanceCMRight();

#endif

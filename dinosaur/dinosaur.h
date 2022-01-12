// Header file for dinosaur.ino

#ifndef DINOSAUR_H  // include guard
#define DINOSAUR_H

#define ledPin 2
#define trigPin 3
#define echoPin 4
#define buzzerPin 5
#define ldrPin A2

int ambientLight = 0;
int distance = 0;  // in cm
const int presetDistance = 15;  // in cm
int wheelPos = 90;  // in degrees
int wheelPos_2 = 90;  // in degrees

#endif  // DINOSAUR_H

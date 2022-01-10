// Header file for dinosaur.ino

#define ledPin 2
#define trigPin 3
#define echoPin 4
#define buzzerPin 5
#define ldrPin A2

int ambientLight = 0;
int distance = 0;
const int presetDistance = 15;  // cm
int wheelPos = 90;
int wheelPos_2 = 90;

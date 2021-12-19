/*
University of Southampton Malaysia - FEEG2001 Systems Design and Computing
Semester 1 Summative Design Assessment - The Arduino Dinosaur
Arduino Sketch v0.5 - Group 14
Last modified:  1 December 2021 (Wednesday)
*/

#include <Servo.h>

const int ledPin=2, trigPin=3, echoPin=4, buzzerPin=5, ldrPin=A1;
unsigned int ldrValue, ambientLight, distance, presetDistance = 15, wheelPos = 90, wheelPos_2=90;
Servo wheelServo, wheelServo_2, jawServo, handServo, legServo;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ldrPin, INPUT);
    wheelServo.attach(9);
    wheelServo_2.attach(8);
    jawServo.attach(10);
    handServo.attach(11);
    legServo.attach(12);
    reset_wheel(wheelServo, wheelServo_2);
    jawServo.write(0);
    handServo.write(0);
    legServo.write(30);
    Serial.println("DINOSAUR IS ALIVE");
    delay(1000);
    
    //calibrate here before evey run
//    for (int i; i<=5 ; i++){
//      Serial.print("LDR TEST: ");
//      Serial.println( i);
//      Serial.print( " AMBIENT LIGHT INTENSITY: ");
//      Serial.println(analogRead(ldrPin));
//      delay(1000);
//    }
//
//    Serial.println("PLEASE CALIBRATE LDR BEFORE USE");
//    //Calibrate here before every run
//    ambientLight = 150;
//    Serial.println("LET THE HUNT BEGIN!");
//    delay(5000);
    
}


void loop() {
    distance = calcDistance();
    distanceLed(); 
//    //HAND TRACKING
    if (distance <= 30 && distance != 0) {
        buzz(1000, 40);
      keepDistance(wheelServo, wheelServo_2, &wheelPos, &wheelPos_2, 5);
      } else if (distance>200 && wheelServo.read()>=180){
        reset_wheel(wheelServo,wheelServo_2);
      }
//    if (distance != 0) {ldr();}

}
//
// Calculate the distance using HC-SR04 ultrasonic sensor
int calcDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    // duration in μs = 10^-6s; speed of sound = 343m/s = 34300cm/s; distance in cm.
    int x = (duration*0.0343)/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    return x;
}

// Light up eye LED if distance <= presetDistance
void distanceLed() {
    digitalWrite(ledPin, distance <= presetDistance ? HIGH : LOW);
}

// Activate buzzer if distance <= presentDistance
void buzz(int freq, int dur) {
    distance <= presetDistance ? tone(buzzerPin, freq, dur) : noTone(buzzerPin);
}

// Detect if object (hand) is present in mouth
void ldr() {
  if (analogRead(ldrPin)<ambientLight-50){
    Serial.println("HAND DETECTED");
    bite(legServo,60, "LEG");
    bite(handServo, 60, "JAW");
    bite(jawServo,60, "HAND");
    bite(legServo,30, "LEG");
    bite(jawServo,0, "JAW");
    bite(handServo,0, "HAND");

  }

    
}

// Jaw and hand servo movement if hand present between mouth

void bite(Servo servoName, int end_val, char part_name[]){
  Serial.print(part_name);
  Serial.println(" IS MOVING!");
  servoName.write(end_val);
  delay(1000);
}
// Maintain the preset distance with the object
void keepDistance(Servo servoName, Servo servoName2,int* posServo, int* posServo_2, int increment) {
    if (*posServo > 0 && *posServo < 180) {
        servoName.write(distance <= presetDistance ? *posServo-=increment : *posServo+=increment);
        servoName2.write(distance <= presetDistance ? *posServo_2+=increment : *posServo_2-=increment);
    } else if (*posServo == 0 || *posServo == 180) {
        servoName.write(distance <= presetDistance ? (*posServo == 0 ? 0 : *posServo-=increment) : (*posServo == 180 ? 180 : *posServo+=increment));
        servoName2.write(distance <= presetDistance ? (*posServo_2 == 180 ? 180 : *posServo_2+=increment) : (*posServo_2 == 0 ? 0 : *posServo_2-=increment));
    }
    Serial.println(*posServo);
    Serial.println(*posServo_2);
}

void reset_wheel(Servo servoName, Servo servoName_2){
  Serial.println("RESETING WHEEL");
  for (int i=servoName.read(); i<=90; i++){
    servoName.write(i);
    servoName_2.write(180-i);
    delay(10);
  }
}
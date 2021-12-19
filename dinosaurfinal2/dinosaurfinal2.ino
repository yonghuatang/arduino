/*
University of Southampton Malaysia - FEEG2001 Systems Design and Computing
Semester 1 Summative Design Assessment - The Arduino Dinosaur
Arduino Sketch v0.4 - Group 14
Last modified:  30 November 2021 (Tuesday)
*/

#include <Servo.h>

const int ledPin=2, trigPin=3, echoPin=4, buzzerPin=5, ldrPin=A0;
unsigned int ldrValue, ambientLight, distance, presetDistance = 15, wheelPos = 90, wheelPos_2=90, jawPos=0, handPos=0;
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
    wheelServo.write(wheelPos);
    jawServo.write(0);
    handServo.write(0);
    legServo.write(0);
    ambientLight = analogRead(ldrPin);
}

void loop() {
//    calcDistance();
//    distanceLed();
//    buzz(1234, 40);
//    ldr();
//    if (distance <= 30) {keepDistance(wheelServo, wheelServo_2, &wheelPos,&wheelPos_2, 5);}
//    delay(1000);
}

// Calculate the distance using HC-SR04 ultrasonic sensor
void calcDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    // duration in μs = 10^-6s; speed of sound = 343m/s = 34300cm/s; distance in cm.
    distance = (duration*0.0343)/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
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
    ldrValue = analogRead(ldrPin);
    if (ldrValue <= ambientLight - 40) {
        bite(jawServo, 0, 40);
//        bite(handServo, 0, 40);
        pitch(legServo, 40, 70);
    } else {
        jawServo.write(0);
//        handServo.write(0);
        legServo.write(0);
    }
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);
    Serial.print("Ambient Light Value: ");
    Serial.println(ambientLight);
}

// Jaw and hand servo movement if hand present between mouth
void bite(Servo servoName, int start, int final) {
    
    for (int i=start; i<=final; i++) {
        servoName.write(i);
        delay(10);
    }
    for (int i=final; i>=start; i--) {
        servoName.write(i);
        delay(10);
    }
}

// Leg servo movement if hand present between mouth
void pitch(Servo servoName, int start, int final) {
  
    for (int i=final; i>=start; i-=5) {
        servoName.write(i);
        delay(10);
    }
    for (int i=start; i<=final; i+=5) {
        servoName.write(i);
        delay(10);
    }
}

// Maintain the preset distance with the object
void keepDistance(Servo servoName, Servo servoName2,int* posServo, int* posServo_2, int increment) {
    if (*posServo > 0 && *posServo < 180) {
        servoName.write(distance <= presetDistance ? *posServo-=increment : *posServo+=increment);
        servoName2.write(distance <= presetDistance ? *posServo_2+=increment : *posServo_2-=increment);
    } else if (*posServo == 0 || *posServo == 180) {
        servoName.write(distance <= presetDistance ? (*posServo == 0 ? 0 : *posServo-=increment) : (*posServo == 0 ? *posServo+=increment : 180));
        servoName2.write(distance <= presetDistance ? (*posServo_2 == 180 ? 180 : *posServo_2+=increment) : (*posServo_2 == 180 ? *posServo_2-=increment : 0));
    }
    Serial.println(*posServo);
    Serial.println(*posServo_2);
}

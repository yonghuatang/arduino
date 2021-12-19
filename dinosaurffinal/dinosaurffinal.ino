/*
University of Southampton Malaysia - FEEG2001 Systems Design and Computing
Semester 1 Summative Design Assessment - The Arduino Dinosaur
Arduino Sketch v0.3 - Group 14
Last modified: 28 November 2021 (Sunday)
Github: kaizer222 - https://github.com/kaizer222/dino_design_2021
*/

#include <Servo.h>

const int ledPin=2, trigPin=3, echoPin=4, buzzerPin=5, ldrPin=A0;
unsigned int ldrValue, ambientLight, distance, presetDistance = 15, wheelPos = 70;
Servo wheelServo, jawServo, handServo, legServo;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ldrPin, INPUT);
    wheelServo.attach(9);
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
    calcDistance();
    distanceLed();
    buzz(1000, 40);
    ldr();
    if (distance <= 30) {keepDistance(wheelServo, &wheelPos, 2);}
    delay(50);
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
    if (ldrValue <= ambientLight - 30) {
        bite(jawServo, 0, 20);
        bite(handServo, 0, 40);
        pitch(legServo, 30, 60);
    } else {
        jawServo.write(0);
        handServo.write(0);
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
    for (int i=final; i>=start; i--) {
        servoName.write(i);
        delay(10);
    }
    for (int i=start; i<=final; i++) {
        servoName.write(i);
        delay(10);
    }
}

// Maintain the preset distance with the object
void keepDistance(Servo servoName, int* posServo, int increment) {
    if (*posServo > 0 && *posServo < 140) {
        servoName.write(distance <= presetDistance ? *posServo-=increment : *posServo+=increment);
    } else if (*posServo == 0 || *posServo == 140) {
        servoName.write(distance <= presetDistance ? (*posServo == 0 ? 0 : *posServo-=increment) : (*posServo == 0 ? *posServo+=increment : 140));
    }
    Serial.println(*posServo);
}

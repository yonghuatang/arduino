#include <Servo.h>

const int echoPin=4, trigPin=3, buzzerPin=9;
unsigned int distance;
int posuhf=70;
int presetDistance = 15;
Servo myservo;

void calcDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    // duration is in μs = 10^-6s; speed of sound = 343m/s = 34300cm/s; distance in cm.
    distance = (duration*0.0343)/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, INPUT);
    myservo.attach(10);
    myservo.write(posuhf);
    Serial.println("Ultrasound sensor HC-SR04");
    delay(1500);
}

void loop() {
    calcDistance();
    buzz();
    if (distance<=30) {
        keepDistance(myservo, &posuhf);
    }
    delay(50);
}

void buzz() {
    if (distance <= 150) {
        tone(buzzerPin, 60, 10);
    } else {
        noTone;
    }
}

void keepDistance(Servo servoName, int* posServo) {
  if (*posServo > 0 && *posServo < 140) {
        servoName.write(distance <= presetDistance ? *posServo+=2 : *posServo-=2);
    } else if (*posServo == 0 || *posServo == 140) {
        servoName.write(distance <= presetDistance ? (*posServo == 0 ? *posServo+=2 : 140) : (*posServo == 0 ? 0 : *posServo-=2));
    }
  Serial.println(*posServo);
}

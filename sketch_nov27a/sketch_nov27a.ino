#include <Servo.h>
const int echoPin=2, trigPin=3;
int pos = 0, distance=0, presetDistance=15;

Servo myservo;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myservo.attach(9);
    myservo.write(pos);
}

void loop() {
    // put your main code here, to run repeatedly:
    calcDistance();
    keepDistance(myservo, &pos);
    delay(50);
}


int calcDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    // duration is in μs = 10^-6s; speed of sound = 343m/s = 34300cm/s; distance in cm.
    distance = (duration*0.0343)/2;
    Serial.print("Distance: ");  // print distance in serial monitor for debugging
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
}

void keepDistance(Servo servoName, int* posServo) {
    if (*posServo > 0 && *posServo < 140) {
        servoName.write(distance <= presetDistance ? ++*posServo : --*posServo);
    } else if (*posServo == 0 || *posServo == 140) {
        servoName.write(distance <= presetDistance ? (*posServo == 0 ? ++*posServo : 140) : (*posServo == 0 ? 0 : --*posServo));
    }
    Serial.print("Servo position: ")
    Serial.println(*posServo);
}

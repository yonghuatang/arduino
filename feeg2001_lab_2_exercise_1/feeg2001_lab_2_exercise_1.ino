#define echoPin 2
#define trigPin 3
#define speakerPin 9

// this is a comment

/* multiline comment */

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(speakerPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Ultrasonic Sensor HC-SR04 Test");
    delay(1000);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    (distance < 20) ? tone(speakerPin, 1500, 20) : noTone(speakerPin);
}

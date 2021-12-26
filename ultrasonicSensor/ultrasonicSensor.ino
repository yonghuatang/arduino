const int echoPin = 2, trigPin = 3, speakerPin = 9;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(speakerPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Ultrasonic Sensor HC-SR04 and Piezoeletric Buzzer Test");
    delay(1000);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // why??
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

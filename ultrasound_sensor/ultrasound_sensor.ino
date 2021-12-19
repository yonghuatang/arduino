const int echoPin=4, trigPin=3;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.println("Ultrasound sensor HC-SR04");
    delay(1500);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    // duration is in μs = 10^-6s; speed of sound = 343m/s = 34300cm/s; distance in cm.
    int distance = (duration*0.0343)/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(10);
}

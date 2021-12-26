const int sensorPin = A0, ledPin = 9;
int sensorValue = 0;

void setup() {
    pinMode(ledPin, OUTPUT);  // PWM
    Serial.begin(9600);
    Serial.println("Potentiometer and LED test");
    delay(500);
}

void loop() {
    sensorValue = map(analogRead(sensorPin), 0, 1023, 0, 255);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    analogWrite(ledPin, sensorValue);
    delay(100);
}

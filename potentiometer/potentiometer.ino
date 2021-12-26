const int sensorPin = A0, ledPin = 9;
int sensorValue = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    digitalWrite(ledPin, HIGH);
    analogWrite(ledPin, sensorValue/7);
    digitalWrite(ledPin, LOW);
    analogWrite(ledPin, sensorValue/7);
    delay(200);
}

const int ledPin = 2;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // simulate PMW
    for (int i=0; i<=5; i++) {
        for (int k=0; k<=100; k++) {
            digitalWrite(ledPin, HIGH);
            delay(5-i);
            digitalWrite(ledPin, LOW);
            delay(i);
        }
    }
}

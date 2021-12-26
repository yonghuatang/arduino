const int ledPins[] = {5, 6, 9, 10, 11};

void setup() {
    for (const int pin : ledPins) {pinMode(pin, OUTPUT);}
}

void loop() {
    for (const int pin : ledPins) {
        digitalWrite(pin, HIGH);
        delay(50);
    }
    for (const int pin : ledPins) {
        digitalWrite(pin, LOW);
        delay(50);
    }
}

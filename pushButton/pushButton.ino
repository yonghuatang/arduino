const int button = 2;
bool buttonState;

void setup() {
    pinMode(button, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    buttonState = digitalRead(button);
    if (buttonState) {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    Serial.print("Button state: ");
    Serial.println(buttonState);
    delay(100);
}

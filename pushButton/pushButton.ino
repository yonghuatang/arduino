const int button = 2;
bool buttonState;

void setup() {
    pinMode(button, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(button);
    digitalWrite(LED_BUILTIN, (buttonState ? HIGH : LOW));
    Serial.print("Button state: ");
    Serial.println(buttonState);
    delay(100);
}

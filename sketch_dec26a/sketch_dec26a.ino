void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    delay(100);
    Serial.println(__DATE__);
    Serial.println(__TIME__);
}

void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("Hello world");
    bool ledStatus = digitalRead(LED_BUILTIN);
    Serial.println(ledStatus);
    digitalWrite(LED_BUILTIN, !ledStatus);
    delay(900);
}

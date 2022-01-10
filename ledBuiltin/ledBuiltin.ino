void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    delay(500);
    Serial.println(__DATE__);
    Serial.println(__TIME__);
    
    Serial.println("Please input your name: ");
    String s;
    while (Serial.available() == 0) {}
    s = Serial.readString();
    Serial.print("Welcome back! ");
    Serial.println(s);
    
}

void loop() {
    Serial.println("Hello world");
    bool ledStatus = digitalRead(LED_BUILTIN);
    Serial.println(ledStatus);
    digitalWrite(LED_BUILTIN, !ledStatus);
    delay(1000);
}

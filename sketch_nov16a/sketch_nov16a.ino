void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // simulate PMW
    for(int i=0; i<=10; i++){
        for(int k=0; k<=100; k++){
            digitalWrite(LED_BUILTIN, HIGH);
            delay(10-i);
            digitalWrite(LED_BUILTIN, LOW);
            delay(i);
        }
    }
}

const int pin1 = 5, pin2 = 6, pin3 = 9, pin4 = 10, pin5 = 11;

void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(pin5, OUTPUT);
}

void loop() {
    
}

void blink() {
    int val = 0;
    for (int i=0; i<10; i++) {
        val += 10;
        analogWrite(pin1, val);
        delay(200);
    }
    for (int i=0; i<10; i++) {
        val -= 10;
        analogWrite(pin1, val);
        delay(200);
        analogWrite(pin2, val);
        delay(200);
    }
}

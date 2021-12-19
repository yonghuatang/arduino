#include <Servo.h>

Servo s;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    s.attach(2);

}

void loop() {
    // put your main code here, to run repeatedly:
    for (int i=40; i<=80; ++i) {
        s.write(i);
        Serial.println(i);
        delay(50);
    }
    for (int i=80; i>=40; --i) {
        s.write(i);
        Serial.println(i);
        delay(50);
    }
}

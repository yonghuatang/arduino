#include "vector.h"

void setup() {
    Serial.begin(9600);
}

void loop() {
    vector v(2,3,4);
    Serial.println(v.getX());
}

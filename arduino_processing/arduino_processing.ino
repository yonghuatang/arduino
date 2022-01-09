// sketch_220108a.pde

void setup() {
    Serial.begin(9600);
}

void loop() {
    static int i = 0;
    Serial.println(i++);
    delay(1000);
}

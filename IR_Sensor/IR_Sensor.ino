const int sensorPin = A0;
int val, distance, sum;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("Infrared Distance Sensor");
    delay(1000);
}

void loop() {
    sum = 0;
    for (int i=0; i<=10; i++) {
        val = analogRead(sensorPin);
        distance = 12343.85 * pow(val, -1.15);  // distance in cm; for accurate sensor measurements, calibration is required
        sum += distance;
        delay(10);
    }
    distance = sum / 10;
    Serial.print("Distance: ");
    Serial.println(distance);
    digitalWrite(LED_BUILTIN, (distance <= 15 ? HIGH : LOW));
}    

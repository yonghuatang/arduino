/* SHP 2013 */

int val;    // store analog value read from IR sensor
int distance;     // use int instead of float as it's cheaper on the memory budget
int sum = 0;

void setup() {
  pinMode(13, OUTPUT); // use pin 13 for LED
  Serial.begin(9600);
  Serial.println("Infrared Distance Sensor!");
}

void loop() {
  sum = 0;    // reset the value of sum
  // sample 10 readings
  for (int i = 0; i <= 10; i++) {
    val = analogRead(A0); // read the value from the IR sensor
    distance = 12343.85 * pow(val, -1.15);    // distance in cm; for accurate sensor measurements, calibration is required
    sum += distance;
    delay(10);   // sampling interval
  }
  
  // average the 10 readings
  distance = sum/10;
  
  Serial.println(distance);    // Use print out to check sensor functionality
  digitalWrite(13, distance <= 15 ? HIGH : LOW);
  }    

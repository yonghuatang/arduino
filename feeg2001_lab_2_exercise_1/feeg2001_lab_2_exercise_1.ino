#define echoPin 2
#define trigPin 3
#define speakerPin 9

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    tone(speakerPin, 666, 20);
  }
}

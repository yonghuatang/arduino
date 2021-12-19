# define led LED_BUILTIN
const int pin1 = 1;

void setup() {
  pinMode(led, OUTPUT);
 }

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(pin1, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  digitalWrite(pin1, LOW);
  delay(500);
}

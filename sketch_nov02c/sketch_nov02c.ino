# define led LED_BUILTIN

void setup() {
  pinMode(led, OUTPUT);
 }

void loop() {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
}

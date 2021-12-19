#define led LED_BUILTIN
const int button = 11;
int val = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  }

void loop() {
  val = digitalRead(button);
  if (val == HIGH) {
    analogWrite(led, 255);
    delay(1000);
    analogWrite(led, 100);
    delay(1000);
  }

}

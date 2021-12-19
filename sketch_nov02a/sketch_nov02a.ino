#define ledPin 2;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
 }

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(ledPin, LOW);
    delay(500);
}

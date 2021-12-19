const int pushButton = 2, ledPin = 3;
int buttonState;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    digitalWrite(ledPin, buttonState);
    delay(100);
}

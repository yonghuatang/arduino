const int pin1 = 5;
const int pin2 = 6;
//const int pin3 = 9;
//const int pin4 = 10;
//const int pin5 = 11;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
//  pinMode(pin3, OUTPUT);
//  pinMode(pin4, OUTPUT);
//  pinMode(pin5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<10; i++) {
    val += 10;
    analogWrite(pin1, val);
    delay(200);
    analogWrite(pin2, val);
    delay(200);
  }
  
  for (int i=0; i<10; i++) {
    val -=10;
    analogWrite(pin1, val);
    delay(200);
    analogWrite(pin2, val);
    delay(200);
  }
}

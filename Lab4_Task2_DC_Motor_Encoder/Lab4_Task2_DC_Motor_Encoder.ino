// Encoder code adapted from http://bildr.org/2012/08/rotary-encoder-arduino/
// these pins cannot be changed; pins 2/3 are the UNO's external interrupt pins int0/int1
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;  // declare as volatile variables changed within interrupt service routine
volatile long encoderValue = 0;
// long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
    Serial.begin(9600);
    pinMode(encoderPin1, INPUT); 
    pinMode(encoderPin2, INPUT);
    // digitalWrite(encoderPin1, HIGH); //turn internal pullup resistor on
    // digitalWrite(encoderPin2, HIGH); //turn internal pullup resistor on
    // call updateEncoder() when any high/low change seen on int0 (pin 2), or int1 (pin 3)
    attachInterrupt(0, updateEncoder, CHANGE); 
    attachInterrupt(1, updateEncoder, CHANGE);
}

void loop() {
    Serial.println(encoderValue);
    delay(500); // just here to slow down the output, and show it will work even during a delay
}

void updateEncoder() {
    int MSB = digitalRead(encoderPin1); // MSB = most significant bit ("leftmost bit")
    int LSB = digitalRead(encoderPin2); // LSB = least significant bit
    // some bitwise math here...
    int encoded = (MSB << 1) | LSB; //combine the 2 encoder values into a single number
    int sum  = (lastEncoded << 2) | encoded; //combine current encoded value with the previous encoded value
    // 8 possible state transitions for a 2-bit encoder
    // Gray code encoded, i.e. only one bit changes at a time
    if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
    if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
    lastEncoded = encoded; // store this value for next time
}

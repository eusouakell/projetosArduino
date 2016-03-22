const int redLed1=5;
const int redLed2=4;
const int greenLed=3;

const int switchPin=2;

void setup() {
  Serial.begin(9600);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed, OUTPUT);

  pinMode(switchPin, INPUT);
}

void loop() {
  int switchState;

  switchState=digitalRead(switchPin);
  if(switchState==LOW){
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, LOW);
    delay(250);
    digitalWrite(redLed2, HIGH);
    digitalWrite(redLed1, LOW);
    delay(250);
  }
  else{
     digitalWrite(redLed1, LOW);
     digitalWrite(redLed2, LOW);
     digitalWrite(greenLed, HIGH);
  }
}

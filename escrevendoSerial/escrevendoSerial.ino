// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledRed= 9;
int switchRed = 8;
/*int ledGreen= 11;
int switchGreen = 10;
int ledYellow= 9;
int switchYellow = 8;
int ledBlue= 7;
int switchBlue = 6;*/




// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(switchRed,INPUT);
  //pinMode(ledGreen, OUTPUT);
  //pinMode(switchGreen,INPUT);
  //pinMode(ledYellow, OUTPUT);
  //pinMode(switchYellow,INPUT);
  //pinMode(ledBlue, OUTPUT);
  //pinMode(switchBlue,INPUT);
  
    
}

// the loop routine runs over and over again forever:
void loop() {
 int switchStateRed,switchStateGreen,switchStateYellow,switchStateBlue;

  switchStateRed=digitalRead(switchRed);
  if(switchStateRed==HIGH){ 
    digitalWrite(ledRed,HIGH);
    delay(300);
    digitalWrite(ledRed,LOW);
    Serial.println("FRENTE");
  }
 /* switchStateGreen=digitalRead(switchGreen);
  if(switchStateGreen==HIGH){ 
    digitalWrite(ledGreen,HIGH);
    delay(300);
    digitalWrite(ledGreen,LOW);
    Serial.println("TRAS");
  }
  switchStateYellow=digitalRead(switchYellow);
  if(switchStateYellow==HIGH){ 
    digitalWrite(ledYellow,HIGH);
    delay(300);
    digitalWrite(ledYellow,LOW);
    Serial.println("DIREITA");
  }
  switchStateBlue=digitalRead(switchBlue);
  if(switchStateBlue==HIGH){ 
    digitalWrite(ledBlue,HIGH);
    delay(300);
    digitalWrite(ledBlue,LOW);
    Serial.println("ESQUERDA");
  }*/

}

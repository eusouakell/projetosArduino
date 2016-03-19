int farolEsquerda = 4;
int farolDireita = 5;
// integer variable led is declared

void setup() {                  // the setup() method is executed only once
  pinMode(farolEsquerda, OUTPUT);         // the led PIN is declared as digital output
  pinMode(farolDireita, OUTPUT);         // the led PIN is declared as digital output
}

void loop() {                   // the loop() method is repeated
  digitalWrite(farolEsquerda, HIGH);      // switching on the led 
  digitalWrite(farolDireita, HIGH);      // switching on the led 
  delay(1000);                  // stopping the program for 1000 milliseconds
  digitalWrite(farolEsquerda, LOW);       // switching off the led 
  digitalWrite(farolDireita, LOW);       // switching off the led 
  delay(1000);                  // stopping the program for 1000 milliseconds
}

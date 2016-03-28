const int buzzer = 8;
/*Criamos uma constante que armazena o número da porta*/
void setup() {
  pinMode(buzzer,OUTPUT);
}
void loop() {
  tone(buzzer,1500);  
  delay(1000);
  noTone(buzzer);
  delay(1000);
}

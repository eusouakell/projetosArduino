int ledPin=10;
// Essa funcao eh executa somente uma vez, eh nela que chamamos as outras funcoes
void setup(){
    pinMode(ledPin, OUTPUT);
}

//Executa continuamente enquanto o Arduino estiver ligado
void loop(){
  digitalWrite(ledPin,HIGH) ;
  delay(250); 
  digitalWrite(ledPin,LOW) ;
  delay(5000); 
}

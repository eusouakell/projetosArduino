#include <Ultrasonic.h>


int trig = 6; // Pino "trig" do sonar
int distancia = 0; // Recebe a leitura do sonar.
int echo = 5; // Pino "echo" do sonar
Ultrasonic ultrasonic(6,5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trig, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trig, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trig, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    int distancia = (ultrasonic.Ranging(CM));
 
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(1000); //espera 1 segundo para fazer a leitura novamente

}

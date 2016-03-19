#include <Ultrasonic.h>
#include <SoftwareSerial.h>
#include <Servo.h>

boolean farolOnOff = 0;
int beep = 13;    //pino do beep 13
int dados = 0;    //recebe dados do PC
int ledFarol = 7; //7
int piscaE = 8;   //8
int piscaD = 10;  //10
int velocidade = 160; // define velocidade de deslocamento do robo
int trig = 6; // Pino "trig" do sonar
int distancia = 0; // Recebe a leitura do sonar.
int echo = 5; // Pino "echo" do sonar
int rodaEsqT=6;
int rodaEsqF=9;
int rodaDirT=3;
int rodaDirF=5;
int controladora=0;
Ultrasonic ultrasonic(6,5);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    
  pinMode(rodaEsqF,OUTPUT);// rodas esquerdas para tras
  pinMode(rodaEsqT,OUTPUT);// rodas esquerdas para frente
  pinMode(rodaDirF,OUTPUT);// rodas direitas para tras
  pinMode(rodaDirT,OUTPUT);// rodas direitas para frente
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(beep,OUTPUT); //Beep
  pinMode(ledFarol,OUTPUT);
  pinMode(piscaE,OUTPUT);
  pinMode(piscaD,OUTPUT);
  start();
}

void loop() {
  
  frente();
  
  
}

void frente(){
  analogWrite(rodaDirT,0);
  analogWrite(rodaDirF,velocidade);
  analogWrite(rodaEsqT,0);
  analogWrite(rodaEsqF,velocidade);
}

void re(){
 analogWrite(rodaEsqT,velocidade);
 analogWrite(rodaDirT,velocidade);
}

void pare(){
 digitalWrite(rodaEsqT,LOW);
 digitalWrite(rodaDirT,LOW);
 digitalWrite(rodaEsqF,LOW);
 digitalWrite(rodaDirF,LOW);
}

void start()
{
  digitalWrite(ledFarol,HIGH);
  delay(1*1000);
  digitalWrite(ledFarol,LOW);  
  digitalWrite(piscaD,HIGH);
  delay(1*1000);
  digitalWrite(piscaD,LOW);
  digitalWrite(piscaE,HIGH);
  delay(1*1000);
  digitalWrite(piscaE,LOW);
  delay(1*1000);  
  tone(beep, 1500);
  delay(1*1000);
  noTone(beep);
}


void sonar(){
  //seta o pino trig com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trig, LOW);
  // delay de 2 microssegundos
    delay(2);
  //seta o pino trig com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trig, HIGH);
  //delay de 10 microssegundos
    delay(10);
  //seta o pino trig com pulso baixo novamente
    digitalWrite(trig, LOW);
  // função Ranging, faz a conversão do tempo de resposta do echo em centimetros, e armazena na variavel distancia
    int distancia = (ultrasonic.Ranging(CM));
 
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(1*1000); //espera 1 segundo para fazer a leitura novamente
}


#define LEDESQ 8
#define LEDDIR 10
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDESQ,OUTPUT);
  pinMode(LEDDIR,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LEDESQ, LOW);
  digitalWrite(LEDDIR, LOW);
  for(int x=0;x<3;x++){
    digitalWrite(LEDESQ,HIGH);
    digitalWrite(LEDDIR, HIGH);
    delay(1000*1.5);
    digitalWrite(LEDESQ,LOW);
    digitalWrite(LEDDIR, LOW);
    delay(1000*1);
  }

  delay(1000*1);
  
  for(int x=0;x<3;x++){
    digitalWrite(LEDESQ,HIGH);
    digitalWrite(LEDDIR, HIGH);
    delay(1000*4);
    digitalWrite(LEDESQ,LOW);
    digitalWrite(LEDDIR, LOW);
    delay(1000*1);
  }

  delay(1000*1);
  
  for(int x=0;x<3;x++){
    digitalWrite(LEDESQ,HIGH);
    digitalWrite(LEDDIR,HIGH);
    delay(1000*1.5);
    digitalWrite(LEDESQ,LOW);
    digitalWrite(LEDDIR, LOW);
    delay(1000*1);
  }
  
}

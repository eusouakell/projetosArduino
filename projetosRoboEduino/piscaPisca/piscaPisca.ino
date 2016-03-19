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
  for(int x=0;x<15;x--){
    digitalWrite(LEDESQ,HIGH);
    digitalWrite(LEDDIR, LOW);
    delay(1000*1);
    digitalWrite(LEDESQ,LOW);
    digitalWrite(LEDDIR, HIGH);
    delay(1000*1);
  }
  
  
  
}

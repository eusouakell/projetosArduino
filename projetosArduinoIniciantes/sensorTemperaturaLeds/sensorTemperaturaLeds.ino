const int sensorPin=A0;
const float baseLineTemp=23;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  Serial.print("Temperatura Base: ");
  Serial.print(baseLineTemp);
  Serial.println("C");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal= analogRead(sensorPin);
  float voltage=((float)sensorVal/1023)*5.0;
  float temperatura = (voltage - 0.05)*100;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("C");
  
  float diferenca= baseLineTemp-temperatura;
  Serial.print("Diferenca: ");
  Serial.print(diferenca);
  Serial.println("C");
  delay(2000);
  
  if(temperatura<baseLineTemp+2){
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
  }
  else{
    if(temperatura>=baseLineTemp+2 && temperatura<baseLineTemp+3){
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      
    }
    else{
     if(temperatura>=baseLineTemp+3 && temperatura<baseLineTemp+4){
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
     }
     else{
      if(temperatura>=4 && temperatura<baseLineTemp+5){
       digitalWrite(7,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(5,HIGH);
       digitalWrite(4,LOW);
       digitalWrite(3,LOW);
      }
      else{
         if(temperatura>=5 && temperatura<baseLineTemp+6){
          digitalWrite(7,HIGH);
          digitalWrite(6,HIGH);
          digitalWrite(5,HIGH);
          digitalWrite(4,HIGH);
          digitalWrite(3,LOW);
        }
        else{
            if(temperatura>=baseLineTemp+6){
              digitalWrite(7,HIGH);
              digitalWrite(6,HIGH);
              digitalWrite(5,HIGH);
              digitalWrite(4,HIGH);
              digitalWrite(3,HIGH);
            }
        }
      }
     }
    }
  }
 }

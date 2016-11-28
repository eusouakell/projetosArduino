#include <CurieBLE.h>

#define NARIZ 8
#define BARRIGAVERDE 9
#define BARRIGAAMARELO 10
#define BARRIGAVERMELHO 11
#define OLHODIREITO 12
#define OLHOESQUERDO 13

BLEPeripheral blePeripheral; 
BLEService controlarLEDS("19B10010-E8F2-537E-4F6C-D104768A1214"); 
BLEUnsignedIntCharacteristic statusLED("19B10011-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

int dado = 0;
int ultimoDado = 0;

void setup() {
  Serial.begin(9600);
  blePeripheral.setLocalName("Controlando LEDS First Robot");
  blePeripheral.setAdvertisedServiceUuid(controlarLEDS.uuid());

  // adicionar servicos e as caracteristicas
  blePeripheral.addAttribute(controlarLEDS);
  blePeripheral.addAttribute(statusLED);

  // inicializar serviço
  blePeripheral.begin();

  pinMode(BARRIGAVERDE,OUTPUT);
  pinMode(BARRIGAVERMELHO,OUTPUT);
  pinMode(BARRIGAAMARELO,OUTPUT);
  pinMode(NARIZ,OUTPUT);
  pinMode(OLHODIREITO,OUTPUT);
  pinMode(OLHOESQUERDO,OUTPUT);

  digitalWrite(BARRIGAVERDE, LOW);
  digitalWrite(BARRIGAVERMELHO, LOW);
  digitalWrite(BARRIGAAMARELO, LOW);
  digitalWrite(NARIZ, LOW);
  digitalWrite(OLHODIREITO, LOW);
  digitalWrite(OLHOESQUERDO, LOW);
  Serial.begin(9600);

}

void loop() {
  //ouvir a interface para realizar conexao
  BLECentral central = blePeripheral.central();
  // se o no centrar estiver conectado
  if (central) {
    Serial.print("Conectado a: ");
    //printa na interface serial o MAC do no central
    Serial.println(central.address());
    //enquanto ouver essa conexao
    while (central.connected()) {
      if (statusLED.written())
      {
        dado = statusLED.value();
        Serial.print("dado recebido ");
        Serial.println(dado);
        if (dado != ultimoDado)
        {          
          if (dado== 1)  
          {
            digitalWrite(OLHOESQUERDO, HIGH);
            digitalWrite(OLHODIREITO, HIGH);
          }
          if(dado==2){
            digitalWrite(NARIZ, HIGH);            
          }
          if(dado==3){
             digitalWrite(BARRIGAVERMELHO, HIGH);
             digitalWrite(BARRIGAAMARELO, HIGH);
             digitalWrite(BARRIGAVERDE, HIGH);
          }
          if(dado==4){
            digitalWrite(OLHOESQUERDO, LOW);
            digitalWrite(OLHODIREITO, LOW);
          }
          if(dado==5){
            digitalWrite(NARIZ, LOW);      
          }
          if(dado==6){
            digitalWrite(BARRIGAVERMELHO, LOW);
            digitalWrite(BARRIGAAMARELO, LOW);
            digitalWrite(BARRIGAVERDE, LOW);
          }
        }
        ultimoDado = dado;
      }
    }
    delay(100);
  }
 }


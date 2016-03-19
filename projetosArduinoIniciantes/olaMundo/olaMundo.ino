//Essa funcao eh executada uma unica vez, colocamos nela as configuracoes
void setup(){
  Serial.begin(9600);
}
//essa funcao eh executada logo em seguida ao setup e fica em execucao enqnt a placa estah alimentada
void loop(){
  Serial.println("Hello world");
  delay(1000);
}

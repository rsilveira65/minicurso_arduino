int PINO_LDR = A4;
int VALOR_LIGA=14;
void setup() {
Serial.begin(9600);

}

void loop() {
int valor = analogRead(PINO_LDR);
Serial.println(valor);
delay(200);
}

/*


void loop() {
int valor = analogRead(PINO_LDR);
Serial.println(valor);
if (valor > VALOR_lIGA){
  digitalWrite(LED,HIGH);
  
}else{
  digitalWrite(LED,LOW);
}

}
*/



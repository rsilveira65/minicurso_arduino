//      (BOTAO)
//    GND  PINO 3

int LED = 13; //pino do led 13
int TEMPO = 1000; // 1 segundo
int INTERRUPCAO = 2;

int AUX = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(INTERRUPCAO, INPUT);
  digitalWrite(INTERRUPCAO, HIGH);
  attachInterrupt(0,liga,LOW); 
}

void loop() {

if (AUX==1){
    digitalWrite(LED, HIGH);   
    delay(TEMPO);             
    digitalWrite(LED, LOW);    
    delay(TEMPO);
} 
}
void liga(){
  if (AUX==1){
    AUX=0;
  }else{
    AUX =1;
  } 
}


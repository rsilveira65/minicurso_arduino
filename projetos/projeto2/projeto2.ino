int passo =1;
int vermelho =12, amarelo =11, verde =10;
int botao=2;
int TEMPO = 5000;

void setup() {
pinMode(botao,INPUT);
pinMode(verde,OUTPUT);
pinMode(amarelo,OUTPUT);
pinMode(vermelho,OUTPUT);
irVermelho();
}

void loop() {
  if(passo==1){
    p1();
    passo=2;
    delay(TEMPO);   
  }
  if (passo ==2){
    p2();
    passo=3;
    delay(TEMPO);
  }
   if (passo ==3){
    p3();
    passo=1;
    delay(5000);
  }
}

void irVermelho(){
  p1();
  passo=1;
}

void p3(){
  digitalWrite(vermelho,LOW);
  digitalWrite(amarelo,HIGH);
  digitalWrite(verde,LOW);
}
void p2(){
  digitalWrite(vermelho,LOW);
  digitalWrite(amarelo,LOW);
  digitalWrite(verde,HIGH);
}
void p1(){
  digitalWrite(vermelho,HIGH);
  digitalWrite(amarelo,LOW);
  digitalWrite(verde,LOW);
}

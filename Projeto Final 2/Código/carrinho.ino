
/* 
  PROJETO FINAL 2:
  AUTOR: Rafael Silveira
*/
// variáveis

int MOTOR = 10;  //pino para ligacao no CH1 do rele
int BUZZER = 2;     //ligacao no positivo do buzzer
char c;
int gatilho = 9; // pino TRIG do sensor ultrassônico
int echo = 8; // pino ECHO do sensor ultrassônico
float tempo; // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm; // para armazenar a distância em centímetros
int DISTANCIA = 30; //distancia em cm minima de um obstaculo
int TEMPO_SEG = 10; //tempo inicial para comecar
void setup() {
  
  Serial.begin(9600);
  pinMode(MOTOR, OUTPUT);
  pinMode(BUZZER, OUTPUT); 
  pinMode(gatilho,OUTPUT);
  digitalWrite(gatilho,LOW);
  delayMicroseconds(10);
  pinMode(echo,INPUT);
}


void loop() {
  int despertador = contador(TEMPO_SEG);  //contador para comecar apos X segundos
  if (despertador ==1){
  
      while (true){
        //beep(1);
        int resp_sensor = ultrassonico();
        
        if (resp_sensor< DISTANCIA){
              digitalWrite(MOTOR,LOW);
              beep(1);
              delay(1000);
              beep(0);
              
        }else{
          digitalWrite(MOTOR,HIGH);
          
        }

    }
  }
}

 
int ultrassonico() {
 // disparar pulso ultrassônico
 digitalWrite(gatilho, HIGH);
 delayMicroseconds(10);
 digitalWrite(gatilho, LOW);
 
 // medir tempo de ida e volta do pulso ultrassônico
 tempo = pulseIn(echo, HIGH);
 
 // calcular as distâncias em centímetros
 distancia_cm = tempo / 29.4 / 2;
 
 Serial.print("Distancia: ");
 Serial.print(distancia_cm);
 Serial.println(" cm");

 return distancia_cm;
}

int contador(int tempo){
  
  Serial.println(tempo);
  while (tempo != 0){
    Serial.println(tempo);
    beep(1);
    delay(1000);
    beep(0);
    tempo= tempo -1;
  }
  return 1;
  
}
void beep(int liga){
  if (liga){
    digitalWrite(BUZZER,HIGH);
    Serial.println("BEEP");
  }else{
    digitalWrite(BUZZER,LOW);
    Serial.println(":x");
  }
    
}



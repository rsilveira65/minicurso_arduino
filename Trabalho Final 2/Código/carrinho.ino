
int MOTOR_1 = 10;
int MOTOR_2 = 7;
int BUZZER=2;
int VCC=3;
char c;
// variáveis
int gatilho = 9; // pino TRIG do sensor ultrassônico
int echo = 8; // pino ECHO do sensor ultrassônico
float tempo; // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm; // para armazenar a distância em centímetros
int TEMPO_SEG= 10;
int DISTANCIA = 30; //distancia em cm

void setup() {                
  Serial.begin(9600);
  pinMode(VCC,INPUT);
  digitalWrite(VCC,HIGH);
  pinMode(MOTOR_1, OUTPUT);
  pinMode(MOTOR_2, OUTPUT); 
  pinMode(BUZZER, OUTPUT); 
  pinMode(gatilho,OUTPUT);
  digitalWrite(gatilho,LOW);
  delayMicroseconds(10);
  pinMode(echo,INPUT);
}


void loop() {
  int despertador = contador(TEMPO_SEG);
  if (despertador ==1){
  
      while (true){
        //beep(1);
        int resp_sensor = ultrassonico();
        
        if (resp_sensor< DISTANCIA){
              digitalWrite(MOTOR_1,LOW);
              
        }else{
          digitalWrite(MOTOR_1,HIGH);
          
        
    
  }

}
}
}

 
// laço principal (executado indefinidamente)
int ultrassonico() {
 // disparar pulso ultrassônico
 digitalWrite(gatilho, HIGH);
 delayMicroseconds(10);
 digitalWrite(gatilho, LOW);
 
 // medir tempo de ida e volta do pulso ultrassônico
 tempo = pulseIn(echo, HIGH);
 
 // calcular as distâncias em centímetros e polegadas
 distancia_cm = tempo / 29.4 / 2;
 
 // apresentar resultados no display LCD

 Serial.print("Distancia: ");
 Serial.print(distancia_cm);
 Serial.println(" cm");

 
 // aguardar um pouquinho antes de começar tudo de novo
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



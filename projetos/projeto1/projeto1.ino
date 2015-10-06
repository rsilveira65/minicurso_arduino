int LED = 13; //pino do led 13
int TEMPO = 50; // 1 segundo
void setup() {
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(TEMPO);              // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(TEMPO);              // espera
}

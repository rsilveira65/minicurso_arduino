/*
iCoffee - Rafael Silveira

 */

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char server[] = "www.icoffee.sacomp.com.br"; 
char inString[32];
int stringPos = 0; 
boolean startRead = false; // is reading?
IPAddress ip(149, 202, 20, 100);
int rele = 3;

EthernetClient client;

void setup() {
  Serial.begin(9600);
  pinMode(rele,OUTPUT);
  Ethernet.begin(mac);
  delay(1000);
  Serial.println("conectando");
  if (client.connect(server, 80)) {
    Serial.println("connectado");
    client.println("GET /api.php?info=1 HTTP/1.1");
    client.println("Host: www.icoffee.sacomp.com.br");
    client.println("Connection: close");
    client.println();
  }
  else {
    Serial.println("connexao falhou");
  }
}

void loop(){

  if (client.available()) {
     String valorLido = lePagina();
     if (valorLido =="0"){
       Serial.println("cafeteira desligada");
       digitalWrite(rele,1);
     }else{
       Serial.println("cafeteira ligada");
       digitalWrite(rele,0);
     }
     
     
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("desconectado");
    client.stop();

    delay(1000);
    Serial.println("conectando");
      if (client.connect(server, 80)) {
          Serial.println("connectado");
          client.println("GET /api.php?info=1 HTTP/1.1");
          client.println("Host: www.icoffee.sacomp.com.br");
          client.println("Connection: close");
          client.println();
      }
      else {
          Serial.println("connexao falhou");
      }
  }
}


String lePagina(){
  //read the page, and capture & return everything between '<' and '>'

  stringPos = 0;
  memset( &inString, 0, 32 ); //clear inString memory

  while(true){

    if (client.available()) {
      char c = client.read();

      if (c == '[' ) { //'<' is our begining character
        startRead = true; //Ready to start reading the part 
      }else if(startRead){

        if(c != ']'){ //'>' is our ending character
          inString[stringPos] = c;
          stringPos ++;
        }else{
          //got what we need here! We can disconnect now
          startRead = false;
          client.stop();
          client.flush();
          Serial.println("disconnecting.");
          return inString;

        }

      }
    }

  }

}

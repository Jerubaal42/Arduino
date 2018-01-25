#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

const byte littleBrother[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN,CSN_PIN);

char dataToSend[10]="Message 0";
char txNum='a';

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis=100;

void setup() {
 Serial.begin(9600);
 Serial.println("SimpleTx Starting");
 radio.begin();
 radio.setDataRate(RF24_250KBPS);
 radio.setRetries(3,5);
 radio.openWritingPipe(littleBrother);
}

void loop() {
  currentMillis=millis();
  if (currentMillis-prevMillis>=txIntervalMillis){
    senddata();
    prevMillis=millis();
  }
}

//-----------------------

void senddata() {
  bool rslt;
  rslt=radio.write(&txNum,sizeof(txNum));
  Serial.print("Data Sent");
  Serial.print(dataToSend);
  if(rslt){
    Serial.println("Acknowledge received");
    updateMessage();
  }
  else{
    Serial.println("Tx has failed you");
  }
}

void updateMessage() {
   txNum += 1;
   if(txNum>'h'){
     txNum='a';
  }
  dataToSend[8]=txNum;
}


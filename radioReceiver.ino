#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_NeoPixel.h>

#define CE_PIN 9
#define CSN_PIN 10
#define PIN 6
#define NUMPIXELS 16

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

const byte littleBrother[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[10];
bool newData = false;
int pixcolor = 0;

void setup() {
  Serial.begin(9600);
  pixel.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1,littleBrother);
  radio.startListening();
}

void loop() {
  getData();
  showData();
}

//---------------------------------

void getData() {
  if (radio.available()){
    radio.read(&dataReceived,sizeof(dataReceived));
    newData=true;
  }
}

void showData() {
  if (newData==true){
    Serial.println(dataReceived);
      if (dataReceived[0]<='d'){
        if (dataReceived[0]<='b'){
          if (dataReceived[0]=='a'){
            Serial.println("a");
            if (pixcolor==2){
              pixel.setPixelColor(0,pixel.Color(255,0,0,0));
              pixel.setPixelColor(8,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(0,pixel.Color(0,255,0,0));
              pixel.setPixelColor(8,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(0,pixel.Color(0,0,255,0));
              pixel.setPixelColor(8,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
          else{
            Serial.println("b");
            if (pixcolor==2){
              pixel.setPixelColor(1,pixel.Color(255,0,0,0));
              pixel.setPixelColor(9,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(1,pixel.Color(0,255,0,0));
              pixel.setPixelColor(9,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(1,pixel.Color(0,0,255,0));
              pixel.setPixelColor(9,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
        }
        else{
          if (dataReceived[0]=='c'){
            Serial.println("c");
            if (pixcolor==2){
              pixel.setPixelColor(2,pixel.Color(255,0,0,0));
              pixel.setPixelColor(10,pixel.Color(0,255,0,0));            
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(2,pixel.Color(0,255,0,0));
              pixel.setPixelColor(10,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(2,pixel.Color(0,0,255,0));
              pixel.setPixelColor(10,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
          else{
            Serial.println("d");
            if (pixcolor==2){
              pixel.setPixelColor(3,pixel.Color(255,0,0,0));
              pixel.setPixelColor(11,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(3,pixel.Color(0,255,0,0));
              pixel.setPixelColor(11,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(3,pixel.Color(0,0,255,0));
              pixel.setPixelColor(11,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
        }
      }
      else{
        if (dataReceived[0]<='f'){
          if (dataReceived[0]=='e'){
            Serial.println("e");
            if (pixcolor==2){
              pixel.setPixelColor(4,pixel.Color(255,0,0,0));
              pixel.setPixelColor(12,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(4,pixel.Color(0,255,0,0));
              pixel.setPixelColor(12,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(4,pixel.Color(0,0,255,0));
              pixel.setPixelColor(12,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
          else{
            Serial.println("f");
            if (pixcolor==2){
              pixel.setPixelColor(5,pixel.Color(255,0,0,0));
              pixel.setPixelColor(13,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(5,pixel.Color(0,255,0,0));
              pixel.setPixelColor(13,pixel.Color(0,0,255,0));
              
              pixel.show();
            }
            else{
              pixel.setPixelColor(5,pixel.Color(0,0,255,0));
              pixel.setPixelColor(13,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
        }
        else{
          if (dataReceived[0]=='g'){
            Serial.println("g");
            if (pixcolor==2){
              pixel.setPixelColor(6,pixel.Color(255,0,0,0));
              pixel.setPixelColor(14,pixel.Color(0,255,0,0));
              pixel.show();
            }
            else if (pixcolor==1){
              pixel.setPixelColor(6,pixel.Color(0,255,0,0));
              pixel.setPixelColor(14,pixel.Color(0,0,255,0));
              pixel.show();
            }
            else{
              pixel.setPixelColor(6,pixel.Color(0,0,255,0));
              pixel.setPixelColor(14,pixel.Color(255,0,0,0));
              pixel.show();
            }
          }
          else{
            Serial.println("h");
            if (pixcolor==2){
              pixel.setPixelColor(7,pixel.Color(255,0,0,0));
              pixel.setPixelColor(15,pixel.Color(0,255,0,0));
              pixel.show();
              pixcolor=0;
            }
            else if (pixcolor==1){
              pixel.setPixelColor(7,pixel.Color(0,255,0,0));
              pixel.setPixelColor(15,pixel.Color(0,0,255,0));
              pixel.show();
              pixcolor+=1;
            }
            else{
              pixel.setPixelColor(7,pixel.Color(0,0,255,0));
              pixel.setPixelColor(15,pixel.Color(255,0,0,0));
              pixel.show();
              pixcolor+=1;
            }
          }
        }
      }
    newData=false;
  }
}

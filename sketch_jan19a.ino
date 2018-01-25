
#include <IRLibAll.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_RGBW + NEO_KHZ800);

#define MY_PROTOCOL NEC
#define FORWARDHO 0xA10C840B
#define TURNRIGHT 0xA10C240B
#define ELSEWHERE 0xA10C440B
#define STOPCHILD 0xA10CC40B
#define LTBL 0xA10C3807
#define LDGM 0xA10CB807
#define MUTE 0xA10CD807
#define APPR 0xA10C5807
#define DISA 0xA10C1807
#define SCAN 0xA10C040B

IRrecvPCI receiver(2);
IRdecode decoder;

Servo lefty;
Servo right;

int Previous=0x00000000;
int Light=0;
int i=0;
int x=0;
int COLOUR=0;

void setup() {
  receiver.enableIRIn();
  strip.begin();
  strip.show();
}

void loop() {
  if (receiver.getResults()) {
    decoder.decode();
    if(decoder.protocolNum==MY_PROTOCOL) {
      if(decoder.value==0xFFFFFFFF) {
        decoder.value=Previous;
      }
      switch(decoder.value) {
        case FORWARDHO:right.attach(10);lefty.attach(9);break;
        case TURNRIGHT:right.attach(10);lefty.detach();break;
        case ELSEWHERE:right.detach();lefty.attach(9);break;
        case STOPCHILD:right.detach();lefty.detach();break;
        case LTBL:if (Light<255) Light=Light+51;break;
        case LDGM:if (Light>0) Light=Light-51;break;
        case MUTE:if (Light==0){Light=255;}else{Light=0;};break;
        case APPR:judge(2,Light);break;
        case DISA:judge(1,Light);break;
        case SCAN:judge(0,255);right.detach();lefty.detach();delay(5000);judge(random(1,3),255);break;
      }
      Previous=decoder.value;
    }
    receiver.enableIRIn();
  }
}

void judge(int COLOUR,int light){
    for(i=0;i<strip.numPixels();i++){
      if(COLOUR==0){
        strip.setPixelColor(i,light,light,light,0);
        strip.show();
      //  delay(5000);
      //  COLOUR=random(1,2);
      }
      if(COLOUR==2){
        strip.setPixelColor(i,light,0,0,0);
        strip.show();
      }
      if(COLOUR==1){
        strip.setPixelColor(i,0,light,0,0);
        strip.show();
      }
    }
}
/*
 * FFFFFFFF = Repeat Previous
 * A10CE00F = TiVo Button
 * A10C0807 = Power
 * A10C8807 = Live TV
 * A10C2C03 = Input
 * A10CC807 = Info
 * A10C220D = Window
 * A10C6C03 = Guide
 * A10C9807 = Select
 * A10C2807 = Up
 * A10C6807 = Down
 * A10CE807 = Left
 * A10CA807 = Right
 * A10C5807 = Approve
 * A10C1807 = Disapprove
 * A10CD807 = Mute
 * A10C040B = Record
 * A10C3807 = Volume Up
 * A10CB807 = Volume Down
 * A10C7807 = Channel Up
 * A10CF807 = Channel Down
 * A10C840B = Play
 * A10CC40B = Pause
 * A10C440B = Rewind
 * A10C240B = Fast Forward
 * A10CA40B = Murdered Button
 * A10C640B = Skip Back
 * A10CE40B = Skip Forward
 * A10C140B = 1
 * A10C940B = 2
 * A10C540B = 3
 * A10CD40B = 4
 * A10C340B = 5
 * A10CB40B = 6
 * A10C740B = 7
 * A10CF40B = 8
 * A10C0C03 = 9
 * A10C8C03 = 0
 * A10C4C03 = Clear
 * A10CCC03 = Enter/Last
 */

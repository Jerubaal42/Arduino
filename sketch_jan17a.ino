#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint16_t i=0; i<strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, strip.Color(255,0,0));
      strip.show();
      delay(500);
  }
  for(uint16_t i=0; i<strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, strip.Color(0,255,0));
      strip.show();
      delay(500);
  }
  for(uint16_t i=0; i<strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, strip.Color(0,0,255));
      strip.show();
      delay(500);
  }
}

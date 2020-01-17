#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 64

#define CUBE_SIZE 4

#define RED cube.Color(255,0,0)
#define GREEN cube.Color(0,255,0)
#define BLUE cube.Color(0,0,255)
#define WHITE cube.Color(255,255,255)
#define BLACK cube.Color(0,0,0)

Adafruit_NeoPixel cube(LED_COUNT,LED_PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  // put your setup code here, to run once:
  cube.begin();
  cube.show();
  cube.setBrightness(50);
  for (int i=0;i<LED_COUNT;i++){
    cube.setPixelColor(i,BLACK);
  }
}

void loop() {
  layer(3);
}
  
void layer(int slice){
  int i;
  int x;
  if (slice == 0){
    i=0;
    x=16;
  }else if(slice == 1){
    i=16;
    x=32;
  }else if(slice == 2){
    i=32;
    x=48;
  }else if(slice == 3){
    i=48;
    x=64;
  }
  for (i;i<x;i++){
    cube.setPixelColor(i,RED);
    cube.show();
    }
}

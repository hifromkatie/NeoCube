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

int front[16]= {3,4,11,12,16,17,18,19,35,36,43,44,48,49,50,51};
int back[16]= {0,7,8,15,28,29,30,31,32,39,40,47,60,61,62,63};
int left[16]= {0,1,2,3,19,20,27,28,32,33,34,35,51,52,59,60};
int right[16]={12,13,14,15,16,23,24,31,44,45,46,47,48,55,56,63};

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
  //layer(3);
  edge(3);
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

void edge(int side){
  //0 front
  //1 back
  //2 left
  //3 right
  if (side ==0){
    for (int i=0;i<16;i++){
      cube.setPixelColor(front[i],BLUE);
    }    
  }else if(side ==1){
    for (int i=0;i<16;i++){
      cube.setPixelColor(back[i],BLUE);
    }  
  }else if(side ==2){
    for (int i=0;i<16;i++){
      cube.setPixelColor(left[i],BLUE);
    } 
  }else if (side ==3){
    for (int i=0;i<16;i++){
      cube.setPixelColor(right[i],BLUE);
    } 
  }
  cube.show();
}

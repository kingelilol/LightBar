#define F_CPU 12000000UL
#include <util/delay.h>
#include <avr/io.h>

#define COLORDIF 100
#define LED_PIN PB5

#include "Globals.h"
#include "SK6812.h"
#include "walker.h"

//GRBW
inline char cap(int i){
  if(i>=255)return 255;
  if(i<=0)return 0;
  return i;
}
void dimDown(){
  for(int i=0;i<SIZE;++i){
    data[i].g =(int)data[i].g*3/4;
    data[i].r =(int)data[i].r*3/4;
    data[i].b =(int)data[i].b*3/4;
    data[i].w = cap(255-data[i].r-data[i].g-data[i].b-COLORDIF);
  }
}

void collision(walker **objects,int s){
  // for(int i=0;i<s;++i){
  //   for(int j=0;j<s;++j){
  //     if(j==i)continue;
  //     if(abs(objects[i]->getPos()-objects[j]->getPos())%(SIZE)<=1){
  //       objects[i]->turn();
  //     }
  //   }
  // }
  for(int i=0;i<s;++i){
    for(int j=i+1;j<s;++j){
      if(j==i)continue;
      objects[i]->colide(objects[j]);
    }
  }
}
int main(){
  DDRB |= (1<<LED_PIN);

  walker *walkers[6];
  //             g,  r,  b,  w
  walker w1( 0,255,  0,  0,  0,1);
  walker w2(10,  0,255,  0,  0,2);
  walker w3(20,  0,  0,255,  0,3);
  walker w4(30,  0,  0,  0,255,4);
  walker w5(40,255,255,  0,  0,5);
  walker w6(50,  0,255,255,  0,6);

  walkers[0]=&w1;
  walkers[1]=&w2;
  walkers[2]=&w3;
  walkers[3]=&w4;
  walkers[4]=&w5;
  walkers[5]=&w6;

  uint8_t counter=0;
  while(1){
    dimDown();
    //collision(walkers,6);
    for(int i=0;i<6;++i)walkers[i]->next(counter);
    sendData();
    //_delay_ms(100);
    ++counter;
  }
  return 0;
}

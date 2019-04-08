/*
 * Copyright (c) 2019 Elias Harrer
 * Released under the MIT license. Read 'LICENSE' for more information.
 */
#include "Globals.h"
#include "walker.h"
#include <stdlib.h>


walker::walker(int pos,struct color col,int ste):pos(pos),ownColor(col),steps(ste){
}
walker::walker(int pos,uint8_t g,uint8_t r,uint8_t b,uint8_t w,int ste):pos(pos),steps(ste){
  ownColor.g=g;
  ownColor.r=r;
  ownColor.b=b;
  ownColor.w=w;
}
void walker::next(int c){
    data[pos]=data[pos]+ownColor;
  if(c%steps==0){
    if(steps>0)++pos;
    else --pos;
    //if(pos>=SIZE||pos<=0)steps*=-1;
    if(pos<0)pos=SIZE;
    else if(pos>=SIZE)pos=0;
  }
}
bool walker::colide(walker* other){
  if(this==other)return false;
  char dir = (this->getSteps()>0)?1:-1;
  if((abs(this->getPos()+dir-other->getPos())<=1)&&((dir>0)!=(other->getSteps()>0))){
    this->turn();
    other->turn();
  }
  return false;
}
int walker::getPos(){
  return pos;
}
int walker::getSteps(){
  return steps;
}
void walker::turn(){
  steps*=-1;
}
void walker::reset(){
  pos=0;
}

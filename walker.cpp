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
  ownColor.b=g;
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
  if(abs(other->getPos()-this->getPos())%(SIZE)<=1){
    other->turn();
    this->turn();
    return true;
  }
  return false;
}
int walker::getPos(){
  return pos;
}
void walker::turn(){
  steps*=-1;
}
void walker::reset(){
  pos=0;
}

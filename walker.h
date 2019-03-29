#ifndef WALKER_H
#define WALKER_H
#include "Globals.h"

class walker{
 private:
  int pos;
  int steps;
  struct color ownColor;
 public:
  walker(int pos,struct color col,int ste);
  walker(int pos,uint8_t g,uint8_t r,uint8_t b,uint8_t w,int ste);
  void turn();
  void next(int c);
  int getPos();
  bool colide(walker* other);
  ~walker();
  void reset();
};

#endif

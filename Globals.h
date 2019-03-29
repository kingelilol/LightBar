#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H
#include <stdint.h>

#define SIZE 300

struct color{
  uint8_t g,r,b,w;
  color operator+(const color& c2){
    color c;
    c.g = (g+c2.g>255)?255:g+c2.g;
    c.r = (r+c2.r>255)?255:r+c2.r;
    c.b = (b+c2.b>255)?255:b+c2.b;
    c.w = (w+c2.w>255)?255:w+c2.w;
    return c;
  }
};

extern color data[SIZE];
#endif

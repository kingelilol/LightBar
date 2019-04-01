#include <avr/io.h>
#define F_CPU 12000000UL
#include <util/delay.h>
#include "Globals.h"
//on my hardware the delays are a liltle bit funky
//The right delys shold be the comented delays
//you can find more info at https://cdn-shop.adafruit.com/product-files/2757/p2757_SK6812RGBW_REV01.pdf
#define T0H //delay_us(0.3)
#define T0L _delay_us(0.9)//_delay_us(0.9)
#define T1H _delay_us(0.6)//_delay_us(0.6)
#define T1L _delay_us(0.3)//_delay_us(0.6)
#define TRES _delay_us(80)
#define SET_HIGH PORTB|=(1<<PB5)
#define SET_LOW PORTB=0


static inline void send_byte(uint8_t byte){
  for(uint8_t i=0;i<8;++i){
    if(byte & 0x80){
      SET_HIGH;
      T1H;
      SET_LOW;
      T1L;
    }else{
      SET_HIGH;
      T0H;
      SET_LOW;
      T0L;
    }
    byte <<=1;
  }
}

void sendData(){
  for(int j=0;j<SIZE;++j){
    send_byte(data[j].g);
    send_byte(data[j].r);
    send_byte(data[j].b);
    send_byte(data[j].w);
  }
  SET_LOW;
  TRES;
}

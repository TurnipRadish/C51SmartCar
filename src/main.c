#include "REG52.H"
#include "../inc/motor.h"
// #include "../inc/dir.h"

unsigned int cnt = 0;
unsigned int per = 50 * 100;

sbit L_D = P1 ^ 0;
sbit ML_D = P1 ^ 1;
sbit MR_D = P1 ^ 2;
sbit R_D = P1 ^ 3;

void delay(unsigned int t) { // —”≥ŸtŒ¢√Ó
  unsigned int i, j;
  for(i = 0; i < t; ++i)
    for (j = 0; j < 1000; ++j);
}

void main() {
  // Timer0_Init();
  while (1) {
    R_Move_Stop();
    L_Move_Stop();

    if (L_D || ML_D) {
      R_Move_Back();
      delay(10);
    }else{
      R_Move_Stop();
      L_Move_Stop();
    }
    
    if (R_D || MR_D) {
      L_Move_Back();
      delay(10);
    }
    else {
      R_Move_Stop();
      L_Move_Stop();
    }
   
    // cnt++;
    // if (cnt > 100 * 100) cnt = 0;
    // if (cnt < per) {
    //   LED1 = 1;
    //   L_Move_Back();
    // } else {
    //   LED1 = 0;
    //   L_Move_Stop();
    // }
  }
 
}
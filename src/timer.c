#include "REG52.H"
#include "../inc/motor.h"

sbit D1 = P1 ^ 0;
sbit D2 = P1 ^ 1;
sbit D3 = P1 ^ 2;
sbit D4 = P1 ^ 3;

void DelayMs(unsigned int t) { // —”≥Ÿt∫¡√Î
  unsigned int i, j;
  for(i = 0; i < t; ++i)
    for (j = 0; j < 1000; ++j);
}

void DelayUs(unsigned int t) { // —”≥ŸtŒ¢√Î
  unsigned int i;
  for(i = 0; i < t; ++i);
}

int DelayMsAutoStopR(unsigned int t) {
  unsigned int i, j;
  for(i = 0; i < t; ++i)
    for (j = 0; j < 1000; ++j) {
      if (D1 == 1 || D2 == 1) {
        L_Motor_Stop();
        R_Motor_Stop();
        return 1;
        break;  
      }
    }
  return 0;
}

int DelayMsAutoStopL(unsigned int t) {
  unsigned int i, j;
  for(i = 0; i < t; ++i)
    for (j = 0; j < 1000; ++j) {
      if (D3 == 1 || D4 == 1) {
          L_Motor_Stop();
          R_Motor_Stop();
        return 1;
        break;  
      }
    }
  return 0;
}

bit DelayMsUntil(bit condition, unsigned delay_ms) {
  unsigned int i, j;
  for(i = 0; i < delay_ms; ++i)
    for (j = 0; j < 1000; ++j) {
      if (D2 == 1 || D3 == 1) return 1;
    }
  return 0;
}
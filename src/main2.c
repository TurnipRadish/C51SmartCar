#include "REG52.H"
#include "../inc/motor.h"
#include "../inc/car2.h"
#include "../inc/timer.h"

sbit Start = P3 ^ 2;
unsigned int Launch = 0;

sbit BEEF = P3 ^ 7;

sbit D1 = P1 ^ 0;
sbit D2 = P1 ^ 1;
sbit D3 = P1 ^ 2;
sbit D4 = P1 ^ 3;

// void PlayBeef() {
//   BEEF = !BEEF;
//   DelayUs(100);
// }

void Run() {
  unsigned int i = 0, j = 0, t = 0;
  if (D2 == 0 && D3 == 0) {
    
    if (1) {
      CarF();
    }
  }
  else if (D2 == 0 && D3 == 1) {
    CarRF();
    CarSpeed(90, 0);
  }
  else if (D2 == 1 && D3 == 0) {
    CarLF();
    CarSpeed(0, 90);
  }
  else if (D2 == 1 && D3 == 1) {
    CarSpeed(40, 40);
    CarF();
  }

  if ((D1 == 1 && D4 == 0)) {
      // DelayMs(10);
      CarStop();DelayMs(5);
      CarLStop();
      t = 80u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          if (D1 == 0 && D2 == 1 && D3 == 1) {
            t = 0;
            break;
          }
        }
      }
      CarStop();
      DelayMs(5);
    } 
    else if ((D1 == 0 && D4 == 1)) {
      // DelayMs(10);
      CarStop();DelayMs(5);
      CarRStop();
      t = 80u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          if (D2 == 1 && D3 == 1 && D4 == 0) {
            t = 0;
            break;
          }
        }
      }
      CarStop();
      DelayMs(5);
    }
}

void main() {
  Timer0_Init();
  CarStop();
  while (1) {
    if (!Launch) {
      Start = P3 ^ 2;
      if (!Start) {
        // CarSpeed(40, 40);
        // L_Motor_Forward();
        // R_Motor_Forward();
        Launch = 1;
        Start = 1;
      }
    }
    else
    {
      Run();
    }
  }
 
}
#include "REG52.H"
#include "../inc/motor.h"
#include "../inc/car3.h"
#include "../inc/timer.h"
// #include "../inc/check_block.h"

sbit Start = P3 ^ 2;
unsigned int Launch = 0;

sbit BEEF = P3 ^ 7;

sbit D1 = P1 ^ 0;
sbit D12 = P2 ^ 2;
sbit D2 = P1 ^ 1;
sbit D3 = P1 ^ 2;
sbit D4 = P1 ^ 3;
sbit D34 = P2 ^ 3;

unsigned int beef_cnt = 0;
bit beef_enable = 0;
void PlayBeef() {
  if (beef_enable == 0) beef_cnt = 0;
  else beef_cnt++;
  if (beef_cnt > 50) {
    BEEF = !BEEF;
    beef_cnt = 0;
  }
}

void Run() {
  unsigned int i = 0, j = 0, t = 0;
  if (D2 == 0 && D3 == 0) {
    if ((D12 == 0 && D34 == 0) || (D12 == 1 && D34 == 1)) {
      CarF(70, 70);
    }
    if (D12 == 1) CarLF(90);
    else if (D34 == 1) CarRF(90);
  }
  
  if (D2 == 0 && D3 == 1) {
    CarRF(70);
  }
  
  if (D2 == 1 && D3 == 0) {
    CarLF(70);
  }
  
  if (D1 == 0 && D2 == 1 && D3 == 1 && D4 == 0) {
    if ((D12 == 0 && D34 == 0) || (D12 == 1 && D34 == 1)) {
      CarF(50, 50);
    }
    if (D12 == 1) CarLF(90);
    else if (D34 == 1) CarRF(90);
  }

  if ((D1 == 1 && D4 == 0)) {
    if (D2 == 1 || D3 == 1) {
      CarLF(70);
      beef_enable=1;
      DelayMs(5);
      CarLStop(70, 70);
      DelayMs(40);
      // for(i = 0; i < 5; ++i)
      //   for (j = 0; j < 1000; ++j) PlayBeef();
      beef_enable=0;
    }
      CarF(40, 40);
      DelayMs(5);
      CarLF(70);DelayMs(5);
      CarLStop(70, 70);
      t = 80u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          if (D1 == 0 && D2 == 1 && D3 == 1) {
            t = 0;
            break;
          }
        }
      }
      CarF(40, 40);
      DelayMs(5);
    } 
    else if ((D1 == 0 && D4 == 1)) {
      if (D2 == 1 || D3 == 1) {
        CarRF(70);
        beef_enable=1; 
        DelayMs(5); 
        CarRStop(70, 70);
        DelayMs(40);
        beef_enable=0;
      }
      CarF(40, 40);
      DelayMs(5);
      CarRF(70);DelayMs(5);
      CarRStop(70, 70);
      t = 80u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          if (D2 == 1 && D3 == 1 && D4 == 0) {
            t = 0;
            break;
          }
        }
      }
      CarF(40, 40);
      DelayMs(5);
    }
}

void Car3Main() {
  Timer0_Init();
  // Timer1_Init();
  CarStop();
  // CheckBlockInit();
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
      // CheckBlockMain();
      PlayBeef();
      Run();
    }
  }
 
}
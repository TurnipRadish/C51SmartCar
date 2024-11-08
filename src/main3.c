#include "REG52.H"
#include "../inc/motor.h"
#include "../inc/car3.h"
#include "../inc/timer.h"
#include "../inc/check_block.h"

sbit Start = P3 ^ 2;
unsigned int Launch = 0;

sbit BEEF = P3 ^ 7;

sbit D1 = P1 ^ 2;
sbit D12 = P1 ^ 3;
sbit D2 = P1 ^ 4;
sbit D3 = P1 ^ 5;
sbit D34 = P1 ^ 6;
sbit D4 = P1 ^ 7;

unsigned int beef_cnt = 0;
bit beef_enable = 0;
void PlayBeef() {
  // if (beef_enable == 0) beef_cnt = 0;
  // else beef_cnt++;
  // if (beef_cnt > 1) {
    BEEF = !BEEF;
    // beef_cnt = 0;
  // }
}

void Run() {
  unsigned int i = 0, j = 0, t = 0;
  if (GetDistance() <= 50) {
    // CarStop(); DelayMs(100);
    // CarRStop(70, 70); t = 50;
    // for (i = 0; i < t; ++i) {
    //   for (j = 0; j < 1000u; ++j) {
    //     PlayBeef();
    //     if (D12 == 1) {
    //       t = 0; break;
    //     }
    //     if (D1 == 0 && D2 == 1 && D3 == 1) {
    //       t = 0; break;
    //     }
    //   }
    // }
  }

  if (D2 == 0 && D3 == 0) {
    // if (GetDistance() <= 150) {
    if (0) {
      CarStop(); DelayMs(50);
      CarRStop(90, 90); DelayMs(90);
      // for (i = 0; i < t; ++i) for; (j = 0; j < 1000u; ++j) {
      //   PlayBeef();
      //   if (D12 == 1) {
      //     t = 0; break;
      //   }
      //   if (D2 == 1 && D3 == 1 && D4 == 0) {
      //     t = 0; break;
      //   }
      // }
    } else {
      if ((D12 == 0 && D34 == 0) || (D12 == 1 && D34 == 1)) {
        CarF(100, 100); DelayMs(5);
      }
      if (D12 == 1) {
        CarLF(100); t = 60; for (i = 0; i < t; ++i) for (j = 0; j < 1000u; ++j) {
          if (D2 == 1 && D3 == 1) { t = 0; break; }
        }
      }
      else if (D34 == 1) {
        CarRF(100); t = 60; for (i = 0; i < t; ++i) for (j = 0; j < 1000u; ++j) {
          if (D2 == 1 && D3 == 1) { t = 0; break; }
        }
      }
    }
  }
  
  if (D2 == 0 && D3 == 1) {
    CarRF(90); 
    if (D34 == 1) R_Motor_Stop(); DelayMs(5);
    DelayMs(5);
  }
  
  if (D2 == 1 && D3 == 0) {
    if (D12 == 1) L_Motor_Stop(); DelayMs(5);
    CarLF(90); DelayMs(5);
  }
  
  if (D1 == 0 && D2 == 1 && D3 == 1 && D4 == 0) {
    // if (GetDistance() <= 150) {
    if (0) {
      CarStop(); DelayMs(40);
      CarRStop(90, 90);  DelayMs(90);
      // for (i = 0; i < t; ++i) for (j = 0; j < 1000u; ++j) {
      //   PlayBeef();
      //   if (D2 == 1 && D3 == 1 && D4 == 0) {
      //     t = 0; break;
      //   }
      // }
    } else {
      if ((D12 == 0 && D34 == 0) || (D12 == 1 && D34 == 1)) {
        CarF(100, 100); 
      }
      if (D12 == 1) {
        CarLF(100); L_Motor_Stop(); DelayMs(10);
      }
      else if (D34 == 1) {
        CarRF(100); R_Motor_Stop(); DelayMs(10);
      }
    }
  }

  if ((D1 == 1 && D4 == 0)) {
    if (D2 == 1 || D3 == 1) {
      CarF(40, 40); DelayMs(20); L_Motor_Stop(); DelayMs(2);
      beef_enable=1;
      CarLStop(90, 90);
      t = 100u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          PlayBeef();
          if (D34 == 1) {
            t = 0; break;
          }
          if (D1 == 0 && D2 == 1 && D3 == 1) {
            t = 0; break;
          }
        }
      }
      // for(i = 0; i < 5; ++i)
      //   for (j = 0; j < 1000; ++j) PlayBeef();
      beef_enable=0;
    } else {
      CarF(90, 90); 
      DelayMs(20);
      CarLF(90); L_Motor_Stop(); DelayMs(2);
      CarLStop(90, 90);
      t = 80u;
      beef_enable = 1;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          PlayBeef();
          if (D34 == 1) {
            t = 0; break;
          }
          if (D1 == 0 && D2 == 1 && D3 == 1) {
            t = 0; break;
          }
        }
      }
      beef_enable = 0;
      CarF(90, 90);
      DelayMs(5);
    }
  } 
  else if ((D1 == 0 && D4 == 1)) {
    if (D2 == 1 || D3 == 1) {
      CarF(40, 40); DelayMs(20); R_Motor_Stop(); DelayMs(2);
      beef_enable=1;
      CarRStop(90, 90);
      t = 150u;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          PlayBeef();
          if (D12 == 1) {
            t = 0; break;
          }
          if (D2 == 1 && D3 == 1 && D4 == 0) {
            t = 0; break;
          }
        }
      }
      // for(i = 0; i < 5; ++i)
      //   for (j = 0; j < 1000; ++j) PlayBeef();
      beef_enable=0;
    } else {
      CarF(90, 90);
      DelayMs(20);
      CarRF(90); R_Motor_Stop(); DelayMs(2);
      CarRStop(90, 90);
      t = 10,0u;
      beef_enable = 1;
      for (i = 0; i < t; ++i) {
        for (j = 0; j < 1000u; ++j) {
          PlayBeef();
          if (D12 == 1) {
            t = 0; break;
          }
          if (D2 == 1 && D3 == 1 && D4 == 0) {
            t = 0;
            break;
          }
        }
      }
      beef_enable = 0;
      CarF(90, 90);
      DelayMs(5);
    }
  }
}

void Car3Main() {
  Timer0_Init();
  // Timer1_Init();
  CarStop();
  CheckBlockInit();
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
      // CheckBlockTick();
      // PlayBeef();
      Run();
    }
  }
 
}
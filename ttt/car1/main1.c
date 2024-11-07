// #include "REG52.H"
// // #include "../inc/xunji.h"
// #include "../inc/motor.h"
// #include "../inc/car.h"
// #include "../inc/timer.h"

// sbit Start = P3 ^ 2;
// unsigned int Launch = 0;
// bit LastStart = 1;

// sbit BEEF = P3 ^ 7;

// sbit D1 = P1 ^ 0;
// sbit D2 = P1 ^ 1;
// sbit D3 = P1 ^ 2;
// sbit D4 = P1 ^ 3;

// void PlayBeef() {
//   BEEF = !BEEF;
//   DelayUs(100);
// }

// void LLow() {
//   unsigned int i;
//   CarStop();
//   DelayMs(50);
//   CarLF();
//   CarSpeed(0, 60);
//   for (i = 0; i < 30 * 1000; ++i) if (D3 == 1 || D4 == 1) {
//     break;
//   }
//   CarStop();
// }

// void RLow() {
//   unsigned int i;
//   CarStop();
//   DelayMs(50);
//   CarRF();
//   CarSpeed(60, 0);
//   for (i = 0; i < 10 * 1000; ++i) if (D2 == 1 || D1 == 1) {
//     break;
//   }
//   CarStop();
// }

// void LHigh() {
//   unsigned int i, j, delay;
//   CarStop();
//   DelayMs(10);
//   CarF();
//   DelayMs(5);
//   R_Motor_Stop();
//   DelayMs(10);
//   CarLStop();
//   delay = 200;
//   for (i = 0; i < delay; ++i) {
//     for(j = 0; j < 1000; ++j) if (D3 == 1) {delay = 0; break;}
//   }
//   CarStop();
//   // DelayMsAutoStopL(30);
//   // if (DelayMsAutoStopL(50) == 1) {
//   //   RLow();
    
//   // }
// }

// void RHigh() {
//   unsigned int i, j, delay;
//   CarStop();
//   DelayMs(10);
//   CarF();
//   DelayMs(5);
//   L_Motor_Stop();
//   DelayMs(10);
//   CarRStop();
//   delay = 200;
//   for (i = 0; i < delay; ++i) {
//     for(j = 0; j < 1000; ++j) if (D2 == 1) {delay = 0; break;}
//   }
//   // for(i = 0; i < 1000 * 1000; ++i) if (D2 == 1 || D3 == 1) {
//   //   CarRF();
//   //   CarSpeed(70, 0);
//   //   for(i = 0; i < 30 * 1000; ++i) if (D2 == 1) {
//   //     break;
//   //   }
//   //   break;
//   // }
//   CarStop();
//   // if (DelayMsAutoStopR(50) == 1) {
//   //   LLow();
//   // }
// }

// void RFastHigh() {
//   CarStop();
//   DelayMs(50);
//   CarRStop();
//   DelayMs(30);
// }

// void LFastHigh() {
//   CarStop();
//   DelayMs(50);
//   CarLStop();
//   DelayMs(30);
// }

// void Track() 
// {
//   if (D1 == 1 && D2 == 1 && D3 == 1 && D4 == 1) {
//     CarF();
//     DelayMs(1);
//     CarStop();
//     DelayMs(5);
//   } else if (D1 == 0 && D2 == 0 && D3 == 0 && D4 == 0) {
//     CarF();
//     DelayMs(1);
//     CarStop();
//     DelayMs(5);
//   }
  
//   if (D1 == 0 && D2 == 0 && D3 == 1 && D4 == 0) {
//     RHigh();
//   }
//   else if (D1 == 0 && D2 == 1 && D3 == 0 && D4 == 0) {
//     LHigh();
//   }
//   else if (D1 == 0 && D2 == 0 && D3 == 0 && D4 == 1) {
//     // RFastHigh();
//     RHigh();
//   }
//   else if (D1 == 1 && D2 == 0 && D3 == 0 && D4 == 0) {
//     // LFastHigh();
//     LHigh();
//   }
//   else if (D1 == 1 && D2 == 1 && D3 == 0 && D4 == 0) {
//     LHigh();
//   }
//   else if (D1 == 0 && D2 == 0 && D3 == 1 && D4 == 1) {
//     RHigh();
//   }
//   else if (D1 == 0 && D2 == 1 && D3 == 1 && D4 == 0) {
//     LHigh();
//   }
// }

// int ds = 0;

// void Track1() {
//   if (D1 == 1) ds -= 2;
//   if (D2 == 1) ds -= 1;
//   if (D3 == 1) ds += 1;
//   if (D4 == 1) ds += 2;
//   if (ds < -1000) ds = -1000;
//   else if (ds > 1000) ds = 1000;
//   if (ds < -100) {
//     LHigh();
//     ds += 2;
//   } else if (ds > 100) {
//     RHigh();
//     ds -= 2;
//   } else {
//     CarF();
//     if (ds < 0) ds += 50;
//     else if (ds > 0) ds -= 50;
//   }
// }

// int lsp = 0, rsp = 0;

// void ChangeSpeed(int l, int r) {
//   if (l < -10) {
//     L_Motor_Backward();
//   } else if (l > 10) {
//     L_Motor_Forward();
//   } else L_Motor_Stop();

//   if (r < -10) {
//     R_Motor_Backward();
//   } else if (r > 10) {
//     R_Motor_Forward();
//   } else R_Motor_Stop();

//   l = l < 0 ? -l : l; if (l > 100) l = 100;
//   r = r < 0 ? -r : r; if (r > 100) r = 100;
//   CarSpeed(l, r);
// }

// void LSpeedDelta(int d) {
//   lsp += d; if (lsp > 100) lsp = 100; else if (lsp < -100) lsp = -100;
// }

// void RSpeedDelta(int d) {
//   rsp += d; if (rsp > 100) rsp = 100; else if (rsp < -100) rsp = -100;
// }

// unsigned int cnt = 0;

// void Track2() {
//   if (D1 == 1) ds -= 3;
//   if (D2 == 1) ds -= 1;
//   if (D3 == 1) ds += 1;
//   if (D4 == 1) ds += 3;
//   if (ds < -1000) ds = -1000;
//   else if (ds > 1000) ds = 1000;
  
//   if (ds < -500) {
//     LHigh();
//     ds += 2;
//   } else if (ds > -500 && ds < -100) {
//     // cnt++;
//     // if (cnt > 250u) {
//     //   LSpeedDelta(-1); RSpeedDelta(2);
//     //   cnt = 0u; ChangeSpeed(lsp, rsp);
      
//     // }
//     CarLF();
//     ds += 1;
//   } else if (ds > 100 && ds < 500) {
//     // cnt++;
//     // if (cnt > 250u) {
//     //   LSpeedDelta(2); RSpeedDelta(-1);
//     //   cnt = 0u; ChangeSpeed(lsp, rsp);
      
//     // }
//     CarRF();
//     ds -= 1;
    
//   } else if (ds > 500) {
//     RHigh();
//     ds -= 2;
//   } else {
//     // cnt++;
//     // if (cnt > 100u) {
//     //   if (lsp > 45) lsp--;
//     //   if (rsp > 45) rsp--;
//     //   ChangeSpeed(lsp, rsp);
//     // }
//     ChangeSpeed(40, 40);
//     L_Motor_Forward();
//     R_Motor_Forward();
//   }
// }

// void Track3() {
//   if (D1 == 1) ds -= 3;
//   if (D2 == 1) ds -= 1;
//   if (D3 == 1) ds += 1;
//   if (D4 == 1) ds += 3;
//   if (ds < -500) ds = -100;
//   else if (ds > 500) ds = 100;
//   if (ds < -100) {
//     LHigh();
//     ds = 0;
//   } else if (ds > 100) {
//     RHigh();
//     ds = 0;
//   } else {
//     CarF();
//     if (ds < 0) ds += 1;
//     else if (ds > 0) ds -= 1;
//   }
// }

// void main() {
//   // SetInit();
//   Timer0_Init();
//     // CarSpeed(50, 50);
//     //   L_Motor_Forward();
//     //   R_Motor_Stop();
//     //   DelayMs(300);
//     //   R_Motor_Forward();
//     //   L_Motor_Stop();
//     //   DelayMs(300);
//     //   R_Motor_Stop();
//     //   L_Motor_Stop();
//     //   DelayMs(300);
//     //   L_Motor_Backward();
//     //   R_Motor_Stop();
//     //   DelayMs(300);
//     //   R_Motor_Backward();
//     //   L_Motor_Stop();
//     //   DelayMs(300);
//     //   R_Motor_Stop();
//     //   L_Motor_Stop();
    
//   while (1) {
//     // CarF();
//     //MoveFront(500);
//     if (!Launch) {
//       Start = P3 ^ 2;
//       // if (Start) LED1 = 0;
//       if (!Start) {
//         ChangeSpeed(40, 40);
//         L_Motor_Forward();
//         R_Motor_Forward();
//         Launch = 1;
//         Start = 1;
//         // DelayMs(2000);
//       }
//     }
//     else
//     {
//       // Track3();
//       Track2();
//       // cnt++;
//       // if (cnt >= 1000u) {
//       //   LSpeedDelta(-1); RSpeedDelta(1); cnt = 0u;
//       // }

//       // ChangeSpeed(lsp, rsp);
//       // ChangeSpeed(35, -35);
      
//     }
//   }
 
// }
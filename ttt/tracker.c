// #include "REG52.H"
// #include "../inc/motor.h"
// #include "../inc/timer.h"
// #include "../inc/control.h"
// #define S_VOID 0u
// #define S_L 1u
// #define S_R 2u
// #define S_F 3u
// #define S_B 4u
// #define S_STOP 6u
// #define S_FINISH 7u
// #define S_DOING 8u

// sbit LED1 = P1 ^ 7;
// unsigned int ForwardTimer = 0;

// unsigned int Forward(unsigned int T, unsigned int S) {
//   if (S == S_VOID) {
//     ForwardTimer = 0;
//     return S_VOID;
//   }

//   ForwardTimer++;
//   Straight(0);
 
//   if (D_Block(1) || (D_Block(2) && !D_Block(3))) {
//     DelayMs(1000); 
//     ForwardTimer = 0;
//     return S_L;
//   } else if (D_Block(4) || (!D_Block(2) && D_Block(3))) {
//     DelayMs(1000);
//     ForwardTimer = 0;
//     return S_R;
//   }

//   if (ForwardTimer > T) {
//     ForwardTimer = 0;
//     return S_FINISH;
//   } else return S_DOING;
// }

// unsigned int Backward(unsigned int T, unsigned int S) {
//   if (S == S_VOID) {
//     ForwardTimer = 0;
//     return S_VOID;
//   }
//   ForwardTimer++;
//   Straight(1);

//   if (D_Block(2) && D_Block(3)) {
//     return S_FINISH;
//   }

//   if (ForwardTimer > T) {
//     ForwardTimer = 0;
//     return S_FINISH;
//   } else return S_DOING;
// }

// unsigned int TrackerCheck() {
//   if (D_Block(2) && D_Block(3)) {
//     SetStatus(S_F);
//   } 
//   else if (D_Block(2) && !D_Block(3)) {
//     SetStatus(S_L);
//   }
//   else if (!D_Block(2) && D_Block(3)) {
//     SetStatus(S_R);
//   }
//   else if (!D_Block(2) && !D_Block(3)) {
//     //SetStatus(S_VOID);
//     if (D_Block(1)) {
//       DelayMs(1000);
//       SetStatus(S_L);
//     }
//     // else if (D_Block(4)) SetStatus(S_R);
//   }
//   else {
//     Stop();
//   }
//   // if (D_Block(2) && D_Block(3)) {
//   //   return S_F;
//   //   // if (D_Block(1) && !D_Block(4)) return S_L;
//   //   // else if (!D_Block(1) && D_Block(4)) return S_R;
//   //   // else if (!D_Block(1) && !D_Block(4)) return S_F; // 中黑两白
//   //   // else return S_F; // 全黑
//   //   // else return S_VOID;
//   // } 
//   // // else if (!D_Block(2) && D_Block(3)) {
//   // //   return S_R;
//   // // } 
//   // // else if (D_Block(2) && !D_Block(3)) {
//   // //   return S_L;
//   // // }
//   // // else if (!D_Block(2) && !D_Block(3)) {
//   // //   if (D_Block(1) && !D_Block(4)) return S_L;
//   // //   else if (!D_Block(1) && D_Block(4)) return S_R;
//   // //   else if (!D_Block(1) && !D_Block(4)) return S_VOID; // 全白，后退？ 
//   // //   else if (D_Block(1) && D_Block(4)) return S_VOID; // 中间白两边黑，后退？
//   // //   // else return S_VOID;
//   // // }
//   // else return S_VOID;
// }

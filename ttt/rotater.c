// #include "REG52.H"
// #include "../inc/motor.h"
// #include "../inc/timer.h"
// #define S_FINISH 7u
// #include "../inc/control.h"
// #define S_DOING 8u
// #define S_VOID 0u
// #define S_F 3u
// #define S_R 2u

// unsigned int RotatorTimer = 0;

// unsigned int RotateAngle(bit Dir, unsigned int Angle, unsigned int S) {
//   if (S == S_VOID) {
//     RotatorTimer = 0;
//     return S_VOID;
//   }
//   RotatorTimer++;
//   Rotate(Dir);
//   if (Dir) {
//     if (D_Block(4)) {
//       RotatorTimer = 0;
//       DelayMs(1000);
//       return S_R;
//     }
//     if ((!D_Block(2) && D_Block(3)) || (D_Block(2) && D_Block(3))) {
//       RotatorTimer = 0;
//       return S_F;
//     }
//   }
  
//   // if ((D_Block(4) || D_Block(3)) && Dir) {
//   //   RotatorTimer = 0;
//   //   return S_FINISH;
//   // } 
//   // if ((D_Block(1) || D_Block(2)) && !Dir) {
//   //   RotatorTimer = 0;
//   //   return S_FINISH;
//   // } 
//   if (RotatorTimer > (Angle * 50)) {
//     RotatorTimer = 0;
//     return S_FINISH;
//   } else {
//     return S_DOING;
//   }
  
// }
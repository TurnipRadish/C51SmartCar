// #include "REG52.H"
// #include "../inc/motor.h"
// #include "../inc/rotater.h"
// #include "../inc/control.h"
// #include "../inc/tracker.h"
// #include "../inc/timer.h"
// #define S_VOID 0u
// #define S_L 1u
// #define S_R 2u
// #define S_F 3u
// #define S_B 4u
// #define S_STOP 6u
// #define S_FINISH 7u
// #define S_DOING 8u
// #define LongToBin(n) \
// (\
// ((n >> 21) & 0x80) | \
// ((n >> 18) & 0x40) | \
// ((n >> 15) & 0x20) | \
// ((n >> 12) & 0x10) | \
// ((n >> 9) & 0x08) | \
// ((n >> 6) & 0x04) | \
// ((n >> 3) & 0x02) | \
// ((n ) & 0x01) \
// )
// #define Bin(n) LongToBin(0x##n##l)

// unsigned int MaxMotionTime = 0;
// const unsigned int InitMaxMotionTime = 200;
// unsigned int CurMotionTime = 0;
// const unsigned int InitCurMotionTime = 60;
// unsigned int TrackingStatus = 0;
// const unsigned int InitTrackingStutus = S_F;

// unsigned int TrackingTimer = 1;

// sbit L_D = P1 ^ 0;
// sbit ML_D = P1 ^ 1;
// sbit MR_D = P1 ^ 2;
// sbit R_D = P1 ^ 3;

// sbit BEEF = P3 ^ 7;
// sbit LED1 = P1 ^ 7;

// bit D_Block(unsigned int N) {
//   switch (N)
//   {
//   case 1:
//     return L_D;
//     break;
//   case 2:
//     return ML_D;
//     break;
//   case 3:
//     return MR_D;  
//     break;
//   case 4:
//     return R_D;
//     break;
//   default:
//     return 0;
//     break;
//   }
// }

// void SetInit() {
//   MaxMotionTime = InitMaxMotionTime;
//   CurMotionTime = InitCurMotionTime;
//   TrackingStatus = InitTrackingStutus;
// }

// void SetStatus(unsigned int S) {
//   TrackingStatus = S;
// }

// void Stop() {
//   L_Move_Stop();
//   R_Move_Stop();
// }

// void Straight(bit Dir) {
//   if (TrackingTimer > CurMotionTime) {
//     L_Move_Stop();
//     R_Move_Stop();
//   }
//   else {
//     if (!Dir) {
//       L_Move_Back(); R_Move_Back();
//     } else {
//       L_Move_Forward(); R_Move_Forward(); 
//     }
//   }
// }

// void Rotate(bit Dir) {
//   if (TrackingTimer > CurMotionTime) {
//     L_Move_Stop();
//     R_Move_Stop();
//   } else {
//     if (!Dir) {
//       L_Move_Forward(); R_Move_Back();
//     } else {
//       L_Move_Back(); R_Move_Forward(); 
//     }
//   }
// }

// unsigned int lock = 0;

// void Tick() {
//   TrackingTimer++;
//   if (TrackingTimer > MaxMotionTime || TrackingTimer < 0) {
//     TrackingTimer = 0;
//   }

//   // StatusTransition();

//   // if (TrackingStatus != S_STOP && TrackingStatus != S_VOID) {
//   //   lock = 0;
//   // }
  
//   if (TrackingStatus == S_STOP) {
//     GlobalInit();
//   } else if (TrackingStatus == S_F) {
//     LED1 = 1;
//     switch (Forward(1000, TrackingStatus)) {
//       case S_VOID: TrackingStatus = S_VOID; break;
//       case S_L: TrackingStatus = S_L; break;
//       case S_R: TrackingStatus = S_R; break;
//       case S_FINISH: TrackingStatus = S_F; break;
//     }
//   } else if (TrackingStatus == S_L) {
//     LED1 = 0;
//     switch (RotateAngle(1, 20, TrackingStatus)) {
//       case S_VOID: TrackingStatus = S_VOID; break;
//       case S_F: TrackingStatus = S_F; break;  
//       case S_R: TrackingStatus = S_R; break; 
//       case S_FINISH: TrackingStatus = S_L; break;
//     }
//   } else if (TrackingStatus == S_R) {
//     LED1 = 1;
//     if (RotateAngle(0, 50, TrackingStatus) == S_FINISH) TrackingStatus = S_VOID;
//   } else if (TrackingStatus == S_B) {
//     switch (Backward(1000, TrackingStatus)) {
//       case S_VOID: TrackingStatus = S_VOID; break;
//       default TrackingStatus = S_VOID;
//     } 
//   } else if (TrackingStatus == S_VOID) {
//     LED1 = 1;
//     // DelayMs(100);
//     TrackerCheck();
//   }
// }
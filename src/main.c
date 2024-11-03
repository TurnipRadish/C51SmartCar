#include "REG52.H"
#include "../inc/motor.h"
#include "../inc/timer.h"
#include "../inc/tracking.h"

sbit Start = P3 ^ 2;

sbit LED1 = P1 ^ 4;
sbit BEEF = P3 ^ 7;

unsigned int Launch = 0;

void GlobalInit() { // 总初始化
  // Timer0_Init();
  R_Move_Stop();
  L_Move_Stop();
}

void PlayBeef() {
  BEEF = !BEEF;
  DelayUs(100);
}

void main() {
  GlobalInit();
  while (1) {
    //MoveFront(500);
    // if (!Start) {
    //   DelayUs(50);
    //   if (!Start) {
    //     Launch = !Launch;
    //     PlayBeef();
    //   }
    //   DelayUs(100);
    // }
    if (1) {
      TrackingTick();
    }
    
    
    // 若四个探头均未被遮挡
    // if (L_D == 0 && ML_D == 0 && MR_D == 0 && R_D == 0) {
    //   //MoveFront(200);// 直走
    //   L_Move_Back();
    //   R_Move_Back();
    //   DelayMs(50);
    //   L_Move_Stop();
    //   R_Move_Stop();
    //   DelayMs(1000);
    // }
    
    // if (L_D == 1 && ML_D == 0 && MR_D == 0 && R_D == 0) {
    //   //MoveRight(100);
    //   L_Move_Stop();
    //   R_Move_Back();
    // }
    // else if (L_D == 0 && ML_D == 1 && MR_D == 0 && R_D == 0) {
    //   //MoveRight(50);
    //   L_Move_Stop();
    //   R_Move_Back();
    //   DelayMs(50);
    //   L_Move_Stop();
    //   R_Move_Stop();
    //   DelayMs(1000);
    // }
    // else if (L_D == 1 && ML_D == 1 && MR_D == 0 && R_D == 0) {
    //   R_Move_Forward();
    //   L_Move_Back();
    //   DelayMs(100);
    //   L_Move_Stop();
    //   R_Move_Stop();
    //   DelayMs(1000);
    // }

    // if (L_D == 0 && ML_D == 0 && MR_D == 0 && R_D == 1 ) {
    //   //MoveLeft(100);
    //   R_Move_Stop();
    //   L_Move_Back();
    // }
    // else if (L_D == 0 && ML_D == 0 && MR_D == 1 && R_D == 0) {
    //   //MoveLeft(50);
    //   R_Move_Stop();
    //   L_Move_Back();
    //   DelayMs(50);
    //   L_Move_Stop();
    //   R_Move_Stop();
    //   DelayMs(1000);
    // }
    // else if (L_D == 0 && ML_D == 0 && MR_D == 1 && R_D == 1) {
    //   L_Move_Forward();
    //   R_Move_Back();
    //   DelayMs(100);
    //   L_Move_Stop();
    //   R_Move_Stop();
    //   DelayMs(1000);
    // }
    
  }
 
}
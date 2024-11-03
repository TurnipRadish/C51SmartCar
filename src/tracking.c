#include "REG52.H"
#include <MATH.H>
#include "../inc/motor.h"
#include "../inc/timer.h"
#define S_L 1u
#define S_R 2u
#define S_F 3u
#define S_B 4u
#define S_MOTION 5u
#define S_STOP 6u
#define LongToBin(n) \
(\
((n >> 21) & 0x80) | \
((n >> 18) & 0x40) | \
((n >> 15) & 0x20) | \
((n >> 12) & 0x10) | \
((n >> 9) & 0x08) | \
((n >> 6) & 0x04) | \
((n >> 3) & 0x02) | \
((n ) & 0x01) \
)
#define Bin(n) LongToBin(0x##n##l)
#define UNTIL_VOID 0u
#define UNTIL_ML_D 1u
#define UNTIL_MR_D 2u
#define UNTIL_F 3u
#define MODIFY_VOID 0u
#define MODIFY_HIGH 1u
#define MODIFY_LOW 2u

sbit L_D = P1 ^ 0;
sbit ML_D = P1 ^ 1;
sbit MR_D = P1 ^ 2;
sbit R_D = P1 ^ 3;

sbit BEEF = P3 ^ 7;

const unsigned int InitMotionTime = 150;

unsigned int TrackingTimer = 0;
unsigned int HeadStatus = 0xff;
unsigned int TrackingStatus = S_F;
unsigned int UntilFlag = 0;
unsigned int ModifyFlag = 0;

unsigned int MaxMotionTime = 200;
unsigned int CurMotionTime = 200;

void HeadStatusUpdate() {
  HeadStatus += (unsigned int)L_D << 3;
  HeadStatus += (unsigned int)ML_D << 2;
  HeadStatus += (unsigned int)MR_D << 1;
  HeadStatus +=  (unsigned int)R_D << 0;
}

void Stop() {
  L_Move_Stop();
  R_Move_Stop();
  CurMotionTime = InitMotionTime;
  ModifyFlag = MODIFY_VOID;
}

void Straight() {
  if (TrackingTimer > CurMotionTime) {
    L_Move_Stop();
    R_Move_Stop();
  }
  else {
    L_Move_Back();
    R_Move_Back();
  }
  
}

void Rotate(bit Dir) {
  if (TrackingTimer > CurMotionTime) {
    L_Move_Stop();
    R_Move_Stop();
  } else {
    if (!Dir) {
      L_Move_Forward(); R_Move_Back();
    } else {
      L_Move_Back(); R_Move_Forward(); 
    }
  }
}

void StatusTransition() {
  HeadStatusUpdate();
  if (TrackingStatus == S_F) {
    if (ML_D && MR_D) { // 循迹
    // 调速机构
    CurMotionTime = InitMotionTime;
      //CurMotionTime > InitMotionTime ? (CurMotionTime -= 1) : InitMotionTime;

      if (L_D && R_D) { // 横道
        
      } else if (L_D && !R_D) { // 左急弯
        // DelayMs(2);
        TrackingStatus = S_L;
        ModifyFlag = MODIFY_HIGH;
      } else if (!L_D && R_D) { // 右急弯
        // DelayMs(2);
        TrackingStatus = S_R;
        ModifyFlag = MODIFY_HIGH;
      } else { // 循迹正常
        TrackingStatus = S_F;
      }
    } else if (ML_D && !MR_D) { // 左弯
      if (L_D && !R_D) { // 左急弯
        // DelayMs(2);
        TrackingStatus = S_L;
        ModifyFlag = MODIFY_HIGH;
      } else if (!L_D && R_D) { // 右急弯
        // // DelayMs(2);
        // TrackingStatus = S_R;
        // ModifyFlag = MODIFY_HIGH;
      } else { // 循迹正常
        TrackingStatus = S_L;
        ModifyFlag = MODIFY_LOW;
      }
    } else if (!ML_D && MR_D) { // 右弯
    if (L_D && !R_D) { // 左急弯
        // DelayMs(2);
        // TrackingStatus = S_L;
        // ModifyFlag = MODIFY_HIGH;
      } else if (!L_D && R_D) { // 右急弯
        // DelayMs(2);
        TrackingStatus = S_R;
        ModifyFlag = MODIFY_HIGH;
      } else { // 循迹正常
        TrackingStatus = S_R;
        ModifyFlag = MODIFY_LOW;
      }
    } else if (!ML_D && !MR_D) {
      if (!L_D && !R_D) { // 悬空
        TrackingStatus = S_STOP;
      }
    }
  } else if (TrackingStatus == S_L) {
    // 调速机构
    CurMotionTime = InitMotionTime;
    // if (ModifyFlag == MODIFY_LOW) { // 低速
    //   CurMotionTime = InitMotionTime;
    // } else if (ModifyFlag == MODIFY_HIGH) { // 高速
    //   CurMotionTime < (MaxMotionTime) ? (CurMotionTime += 1) : CurMotionTime;
    // }
    // else { // 加速
    //   CurMotionTime < (0.7 * MaxMotionTime) ? (CurMotionTime += 1) : CurMotionTime;
    // }

    if (ML_D && MR_D) { // 循迹
      TrackingStatus = S_F;
    } else if (!ML_D && !MR_D) { // 脱轨
      if (!L_D && !R_D) { // 悬空
        // TrackingStatus = S_STOP;
        // 保持现状
        // if (UntilFlag == UNTIL_F) {

        // }
      } else if (L_D && !R_D) { // 左急弯
        // DelayMs(2);
        TrackingStatus = S_L;
        ModifyFlag = MODIFY_HIGH;
      } else if (!L_D && R_D) { // 右急弯
        // DelayMs(2);
        // TrackingStatus = S_R;
        // ModifyFlag = MODIFY_HIGH;
      }
    } else if (ML_D && !MR_D) { // 过右
      TrackingStatus = S_L;
      ModifyFlag = MODIFY_LOW;
    } else if (!ML_D && MR_D) { // 过左
      TrackingStatus = S_R;
      ModifyFlag = MODIFY_LOW;
    }
  } else if (TrackingStatus == S_R) {
    // 调速机构
    CurMotionTime = InitMotionTime;
    // if (ModifyFlag == MODIFY_LOW) { // 低速
    //   CurMotionTime = InitMotionTime;
    // } else if (ModifyFlag == MODIFY_HIGH) { // 高速
    //   CurMotionTime < (MaxMotionTime) ? (CurMotionTime += 1) : CurMotionTime;
    // }
    // else { // 加速
    //   CurMotionTime < (0.7 * MaxMotionTime) ? (CurMotionTime += 1) : CurMotionTime;
    // }
    
    if (ML_D && MR_D) {
      TrackingStatus = S_F;
    } else if (!ML_D && !MR_D) { // 脱轨
      if (!L_D && !R_D) { // 悬空
        // TrackingStatus = S_STOP;
        // 保持现状
      } else if (L_D && !R_D) { // 左急弯
        // DelayMs(2);
        // TrackingStatus = S_L;
        // ModifyFlag = MODIFY_HIGH;
      } else if (!L_D && R_D) { // 右急弯
        // DelayMs(2);
        TrackingStatus = S_R;
        ModifyFlag = MODIFY_HIGH;
      }
    } else if (ML_D && !MR_D) { // 过右
      TrackingStatus = S_L;
      ModifyFlag = MODIFY_LOW;
    } else if (!ML_D && MR_D) { // 过左
      TrackingStatus = S_R;
      ModifyFlag = MODIFY_LOW;
    }
  } else if (TrackingStatus == S_STOP) {
    if (ML_D && MR_D) {
      TrackingStatus = S_F;
    }
  }
}

void TrackingTick() {
  TrackingTimer++;
  if (TrackingTimer > MaxMotionTime || TrackingTimer < 0) {
    TrackingTimer = 0;
  }

  StatusTransition();
  if (TrackingStatus == S_STOP) {
    Stop();
  } else if (TrackingStatus == S_F) {
    Straight();
  } else if (TrackingStatus == S_L) {
    Rotate(1);
  } else if (TrackingStatus == S_R) {
    Rotate(0);
  }
}



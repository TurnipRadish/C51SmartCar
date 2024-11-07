#include "REG52.H"
#include "../inc/motor.h"

sbit L_EN = P2^0;
sbit R_EN = P2^1;

unsigned char counter0 = 0, lspeed = 0, rspeed = 0;

void Timer0_Init(void)        //100微秒@11.0592MHz
{
    // TMOD &= 0xF0;            //设置定时器模式
    // TMOD |= 0x01;            //设置定时器模式
    TMOD = 0x11;
    TL0 = 0xA4;                //设置定时初始值
    TH0 = 0xFF;                //设置定时初始值
    TF0 = 0;                //清除TF0标志
    TR0 = 1;            //定时器0开始计时
    ET0 = 1;
    EA = 1;    
    PT0 = 1;
}

void Timer0_Serve() interrupt 1
{
  TL0 = 0xA4;                //设置定时初始值
  TH0 = 0xFF;           //设置定时初始值 
  
  counter0 ++;
  if(counter0 > 100)
  {
    counter0 = 0;
  }
  if(counter0 < lspeed)
  {
    L_EN = 1;
  }
  else
  {
    L_EN = 0;
  }
  if(counter0 < rspeed)
  {
    R_EN = 1;
  }
  else
  {
    R_EN = 0;
  }
}

void CarF(unsigned int l, unsigned int r) 
{
  lspeed = l; rspeed = r;
  L_Motor_Forward();
  R_Motor_Forward();
}

void CarB() 
{
  lspeed = rspeed = 40;
  L_Motor_Backward();
  R_Motor_Backward();
}

void CarStop() 
{
  lspeed = rspeed = 0;
  L_Motor_Stop();
  R_Motor_Stop();
}

void CarLF(unsigned int r)
{
  lspeed = 0;
  rspeed = r;
  R_Motor_Forward();
  // L_Motor_Stop();
}

void CarRF(unsigned int l)
{
  lspeed = l;
  rspeed = 0;
  L_Motor_Forward();
  // R_Motor_Stop();
}

void CarLB()
{
  lspeed = rspeed = 40;
  R_Motor_Backward();
  L_Motor_Stop();
}

void CarRB()
{
  lspeed = rspeed = 40;
  L_Motor_Backward();
  R_Motor_Stop();
}

void CarLStop(unsigned int l, unsigned int r)
{
  lspeed = l; rspeed = r;
  R_Motor_Forward();
  L_Motor_Backward();
}

void CarRStop(unsigned int l, unsigned int r)
{
  lspeed = l; rspeed = r;
  L_Motor_Forward();
  R_Motor_Backward();
}



#include "REG52.H"
sbit LED0 = P1^3;

// sbit L_EN = P0^7;
sbit L_Forward = P3^5;
sbit L_Backward = P3^6;

// sbit R_EN = P0^2;
sbit R_Forward = P3^3;
sbit R_Backward = P3^4;

unsigned char coutern = 0, compare = 0;

void L_Move_Forward()//左轮前进
{
	L_Forward = 1;
	L_Backward = 0;
}

void R_Move_Forward()//右轮前进
{  
	R_Forward = 1;
	R_Backward = 0;
}
//
void L_Move_Back()//左轮后退
{
	L_Forward = 0;
	L_Backward = 1;
}

void R_Move_Back()//右轮后退
{
	R_Forward = 0;
	R_Backward = 1;
}

void L_Move_Stop()//左轮停
{
	L_Forward = 0;
	L_Backward = 0;
}

void R_Move_Stop()//右轮停
{
	R_Forward = 0;
	R_Backward = 0;
}

void Timer0_Init(void)        //100微秒@11.0592MHz
{
    // TMOD &= 0xF0;            //设置定时器模式
    // TMOD |= 0x01;            //设置定时器模式
    TMOD = 0x01;
    TL0 = 0xA4;                //设置定时初始值
    TH0 = 0xFF;                //设置定时初始值
    TF0 = 0;                //清除TF0标志
    TR0 = 1;            //定时器0开始计时
    ET0 = 1;
    EA = 1;    
    PT0=0;
}

void Timer0_Serve() interrupt 1
{
  LED0 = !LED0;

    TL0 = 0xA4;                //设置定时初始值
    TH0 = 0xFF;           //设置定时初始值 
    compare = 10;
    coutern ++;
    if(coutern > 100)
    {
        coutern = 0;
    }
    if(coutern < compare)
    {
        L_Move_Back();
        R_Move_Forward();
    }
    else
    {
        L_Move_Stop();
        R_Move_Stop();
    }
}

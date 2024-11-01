#include "REG52.H"
sbit LED0 = P1^3;

// sbit L_EN = P0^7;
sbit L_Forward = P3^5;
sbit L_Backward = P3^6;

// sbit R_EN = P0^2;
sbit R_Forward = P3^3;
sbit R_Backward = P3^4;

unsigned char coutern = 0, compare = 0;

void L_Move_Forward()//����ǰ��
{
	L_Forward = 1;
	L_Backward = 0;
}

void R_Move_Forward()//����ǰ��
{  
	R_Forward = 1;
	R_Backward = 0;
}
//
void L_Move_Back()//���ֺ���
{
	L_Forward = 0;
	L_Backward = 1;
}

void R_Move_Back()//���ֺ���
{
	R_Forward = 0;
	R_Backward = 1;
}

void L_Move_Stop()//����ͣ
{
	L_Forward = 0;
	L_Backward = 0;
}

void R_Move_Stop()//����ͣ
{
	R_Forward = 0;
	R_Backward = 0;
}

void Timer0_Init(void)        //100΢��@11.0592MHz
{
    // TMOD &= 0xF0;            //���ö�ʱ��ģʽ
    // TMOD |= 0x01;            //���ö�ʱ��ģʽ
    TMOD = 0x01;
    TL0 = 0xA4;                //���ö�ʱ��ʼֵ
    TH0 = 0xFF;                //���ö�ʱ��ʼֵ
    TF0 = 0;                //���TF0��־
    TR0 = 1;            //��ʱ��0��ʼ��ʱ
    ET0 = 1;
    EA = 1;    
    PT0=0;
}

void Timer0_Serve() interrupt 1
{
  LED0 = !LED0;

    TL0 = 0xA4;                //���ö�ʱ��ʼֵ
    TH0 = 0xFF;           //���ö�ʱ��ʼֵ 
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

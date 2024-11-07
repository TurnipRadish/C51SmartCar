#include <reg52.h>
#include "../inc/timer.h"
sbit Trig = P3 ^ 0;
sbit Echo = P3 ^ 1;

//数码管段选和位选
sbit du = P2 ^ 6;
sbit we = P2 ^ 7;

typedef unsigned int u16;
typedef unsigned int u8;
u16 time;  //定义时间
u16 s;	   //定义距离
u16 distance[4];

u8 code digitron[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

u16 display_interval = 0;
void display() {
  display_interval++;
  if (display_interval == 100) {
    P0=0xff;
    we=1;
    P0=0xf7;
    we=0;
    du=1;
    P0=digitron[distance[3]];	//个位
    du=0;
  } else if (display_interval == 200) {
    P0=0xff;
    we=1;
    P0=0xfb;
    we=0;
    du=1;
    P0=digitron[distance[2]];	//十位
    du=0;
  } else if (display_interval == 300) {
    P0=0xff;
    we=1;
    P0=0xfd;
    we=0;
    du=1;
    P0=digitron[distance[1]];	//百位
    du=0;
  } else if (display_interval >= 400) {
    P0=0xff;
    we=1;
    P0=0xfe;
    we=0;
    du=1;
    P0=digitron[distance[0]];	//千位
    du=0;
    display_interval = 0;
  }
}

void Timer1_Init()
{
	TMOD &= 0x0f; // clear timer1 field
  TMOD |= 0x10; // set timer1 to 0001, no affect on timer0
	TH1 = 0;		//高八位数
	TL1 = 0;		//低八位数
	TR1 = 0;		//定时器开关
}

u8 cout_interval = 0;
void CheckBlockInit() {
  for (cout_interval = 0; cout_interval < 2; ++cout_interval) Trig = 1;
  Trig = 0;
}

void cout()
{
  //通过20us高电平激活超声波模块
  cout_interval++;
  if (cout_interval <= 2) {
    Trig = 1;
  } else if (cout_interval > 2) {
    cout_interval = 0;
    Trig = 0;
  }
	  
  if (!Echo) { //等待接收超声波口Echo=0;
    TR1 = 1; //打开定时器
  }
  if (Echo) {
    TR1 = 0;		  //关闭定时器
    time = TH1 * 256 + TL1;	//定时器16位
    s = (time * 1.7) / 100 ;
    TH1 = 0;
    TL1 = 0;
  }
}

void deal()
{
	distance[0]=s/1000;		 //计算千位
	distance[1]=s%1000/100;		 //计算百位
	distance[2]=s%1000%100/10;	 //计算十位
	distance[3]=s-s/10*10;		//计算个位

}

void CheckBlockMain()
{
  cout();
  deal();
  display();
}
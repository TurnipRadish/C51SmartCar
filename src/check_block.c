#include  "REG52.H"
typedef unsigned int u16;

u16 time;  //?¡§???¡À??
u16 s = 0;	   //?¡§???¨¤??
u16 distance[4];

sbit Trig =P1^0;
sbit Echo=P1^1;

void delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
	  j = 239;
    do
    {
      while (--j);
    } while (--i);
	}
}	

unsigned char code digitron[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x77,~0x7c,~0x39,~0x5e,~0x79,~0x71,~0x00};

void display() {
  P2=0x07;
  P0=digitron[distance[3]];	
  delay(1);
  P2=0xff;

  P2=0x0b;
  P0=digitron[distance[2]];	
  delay(1);
  P2=0xff;

  P2=0x0d;
  P0=digitron[distance[1]];	
  delay(1);
  P2=0xff;
    
  P2=0x0e;
  P0=digitron[distance[0]];	
  delay(1);
  P2=0xff;
}

void Timer1_Init()
{
	TMOD &= 0x0f;	   
	TH1=0;		
	TL1=0;
	TR1=0;		
}

void cout()
{
	Trig=1;
	delay(2);
	Trig=0;

	while(!Echo); 
	TR1=1;	  
	while(Echo);
	TR1=0;		  
	time=TH1*256+TL1;	
	s=(time*1.7)/100 ;
	TH1=0;
	TL1=0;
}

void deal()
{
	distance[0]=s/1000;		 //?????¡ì??
	distance[1]=s%1000/100;		 //????¡ã???
	distance[2]=s%1000%100/10;	 //????????
	distance[3]=s-s/10*10;		//????????

}

u16 GetDistance() {
  return s;
}

void CheckBlockTick() {
  cout();
  deal();
  display();
}

void CheckBlockInit() {
  Timer1_Init();
} 

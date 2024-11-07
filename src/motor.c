#include "REG52.H"

sbit R_Forward = P3^5;
sbit R_Backward = P3^6;
sbit L_Forward = P3^3;
sbit L_Backward = P3^4;

void L_Motor_Backward()
{
	L_Forward = 1;
	L_Backward = 0;
}

void R_Motor_Backward()
{  
	R_Forward = 1;
	R_Backward = 0;
}
//
void L_Motor_Forward()
{
	L_Forward = 0;
	L_Backward = 1;
}

void R_Motor_Forward()
{
	R_Forward = 0;
	R_Backward = 1;
}

void L_Motor_Stop()
{
	L_Forward = 0;
	L_Backward = 0;
}

void R_Motor_Stop()
{
	R_Forward = 0;
	R_Backward = 0;
}

void All_Motor_Forward() 
{
  L_Motor_Forward();
  R_Motor_Forward();
}


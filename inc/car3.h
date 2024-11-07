#ifndef __CAR3_H__
#define __CAR3_H__

void Timer0_Init(void);
void CarB();
void CarF(unsigned int l, unsigned int r);
void CarLF(unsigned int r);
void CarRF(unsigned int l);
void CarLB();
void CarRB();
void CarLStop(unsigned int l, unsigned int r);
void CarRStop(unsigned int l, unsigned int r);
void CarStop();

void Car3Main();

#endif

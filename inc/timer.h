#ifndef __TIMER_H__
#define __TIMER_H__

void DelayUs(unsigned int t);
void DelayMs(unsigned int t);
int DelayMsAutoStopR(unsigned int t);
int DelayMsAutoStopL(unsigned int t);
bit DelayMsUntil(bit condition, unsigned delay_ms);

#endif

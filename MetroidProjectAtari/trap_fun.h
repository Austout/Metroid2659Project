#ifndef VBL_TRAP_H
#define VBL_TRAP_H
#include "psg.h"
#include <stdio.h>
extern volatile unsigned int vsyncFlag;
extern volatile unsigned long keyValues[8];
unsigned int isKeyDown(unsigned int value);
void setVsync(unsigned int flag);
extern unsigned long time;
void addTime();
int getTime();
void addBuff(signed int value);
void trap0_vbl();
void trapIKBR();
unsigned long getMouseXlocation();
unsigned long getMouseYlocation();
void setMouseXlocation(unsigned long  X);
void setMouseYlocation(unsigned long  Y);
unsigned int isLeftClickDown();
extern unsigned int lastValue;
#endif
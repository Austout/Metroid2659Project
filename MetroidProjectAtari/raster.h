#ifndef LOL_H
#define LOL_H

#include <OSBIND.H>
#include <stdlib.h>
#include <stdio.h>

struct Block
{
	int x;
	int y;
	unsigned long pixels[32];
};

void set_video_base(unsigned long *frameBuffer);

unsigned long *get_video_base();

void getColors(int colors[16]);

void clearScreen(unsigned long *base);

void renderBackSplash(unsigned long screen[],unsigned long *base );

void renderBitmap(int x, int y, unsigned long block[],unsigned long *base);

void renderBitmapEquals(int x, int y, unsigned long block[],unsigned long *base );

void getBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void setBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void setBitmapRowOr(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void renderBitmapWithSize(int x, int y,int ySize, unsigned long block[],unsigned long *base);

void renderBitmapWithSizeXOR(int x, int y,int ySize, unsigned long block[],unsigned long *base);

void renderBitmapXOR(int x, int y, unsigned long block[],unsigned long *base );

void setScreenMoveP(int);

void loadColors(int colors[16]);
#endif
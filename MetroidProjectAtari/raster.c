#include "raster.h"

/* Purpose: gets the current video base NOTE: must not be in super during call.
Parameters: none
returns: the address of the current video base
*/
unsigned long *get_video_base(){
	long old_ssp = Super(0);
	unsigned char frameHi, frameMi;
	unsigned long frameBuffer = 0x0L;
	unsigned char * frame = (unsigned char *) 0xFFFF8201;
	
	frameHi = *frame;
	
	frame = (unsigned char *) 0xFFFF8203;
	
	frameMi = *frame;
	
	frameBuffer = ((unsigned long) frameHi << 16);
	frameBuffer |= ((unsigned long) frameMi << 8);
	Super(old_ssp);
	return (unsigned long *) frameBuffer;
}
/* Purpose: sets the current video base NOTE: must not be in super during call.
Parameters: frameBuffer (which address the video buffer should be set to)
returns: none
*/
void set_video_base(unsigned long *frameBuffer){
	long old_ssp = Super(0);
	long videoAddress = (long) frameBuffer;
	unsigned int inputToSetScreen = videoAddress >> 8;
	setScreenMoveP(inputToSetScreen);
	Super(old_ssp);
}
/* Purpose: renders a bitmap to the video base using |= NOTE: olny renders a 16x16 image, does this in color
Parameters: x (x position to render at), y (y position to render at), block (a unsigned long array of the block to render),
base (the video base to be rendered to).
Returns: none
*/
void renderBitmap(int x, int y, unsigned long block[],unsigned long *base ){
	int index;
	unsigned long offsetWord = (x & 15);
    volatile unsigned long bitmaskLong = (1 << offsetWord) - 1;
    unsigned long firstLong,secondLong;
    bitmaskLong = bitmaskLong << 16;
    bitmaskLong += (1 << offsetWord) - 1;
	base += ((y*40) + (x >> 3)) & 0xFFFFFFFE; /* makes sure each block is at correct long FFFE because of 8+ pixel error */
	for(index = 0; index < 32; index++){ /* every block has a size of 16x16*/
		firstLong = block[index] & bitmaskLong;
		if(x >= 0){
			*base |= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
			index++;
			*base |= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
		}else{ 
			base += 2;
			index++;
		}
		secondLong = block[index] & bitmaskLong;
		if(x <= 304){
			*base |= firstLong << (16 - offsetWord);
			base++;
			*base |= secondLong << (16 - offsetWord);
		}else{ base++;}
		base += 37;
	}
}
/* Purpose: renders a bitmap to the video base using |= with a specifed y size NOTE: renders in color
Parameters: x (x position to render at), y (y position to render at), ySize (the y size to render),
block (a unsigned long array of the block to render),base (the video base to be rendered to).
Returns: none
*/
void renderBitmapWithSize(int x, int y,int ySize, unsigned long block[],unsigned long *base){
	int index;
	unsigned long offsetWord = (x & 15);
    volatile unsigned long bitmaskLong = (1 << offsetWord) - 1;
    unsigned long firstLong,secondLong;
    bitmaskLong = bitmaskLong << 16;
    bitmaskLong += (1 << offsetWord) - 1;
	base += ((y*40) + (x >> 3)) & 0xFFFFFFFE; /* makes sure each block is at correct long FFFE because of 8+ pixel error */
	for(index = 0; index < (ySize << 1); index++){ /* every block has a size of 16x16*/
		firstLong = block[index] & bitmaskLong;
		if(x >= 0){
			*base |= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
			index++;
			*base |= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
		}else{ 
			base += 2;
			index++;
		}
		secondLong = block[index] & bitmaskLong;
		if(x <= 304){
			*base |= firstLong << (16 - offsetWord);
			base++;
			*base |= secondLong << (16 - offsetWord);
		}else{ base++;}
		base += 37;
	}
}
/* Purpose: renders or derenders a bitmap to the video base using ^= with a specifed y size NOTE: renders in color
Parameters: x (x position to render at), y (y position to render at), ySize (the y size to render),
block (a unsigned long array of the block to render),base (the video base to be rendered to).
Returns: none
*/
void renderBitmapWithSizeXOR(int x, int y,int ySize, unsigned long block[],unsigned long *base){
	int index;
	unsigned long offsetWord = (x & 15);
    volatile unsigned long bitmaskLong = (1 << offsetWord) - 1;
    unsigned long firstLong,secondLong;
    bitmaskLong = bitmaskLong << 16;
    bitmaskLong += (1 << offsetWord) - 1;
	base += ((y*40) + (x >> 3)) & 0xFFFFFFFE; /* makes sure each block is at correct long FFFE because of 8+ pixel error */
	for(index = 0; index < (ySize << 1); index++){ /* every block has a size of 16x16*/
		firstLong = block[index] & bitmaskLong;
		if(x >= 0){
			*base ^= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
			index++;
			*base ^= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
		}else{ 
			base += 2;
			index++;
		}
		secondLong = block[index] & bitmaskLong;
		if(x <= 304){
			*base ^= firstLong << (16 - offsetWord);
			base++;
			*base ^= secondLong << (16 - offsetWord);
		}else{ base++;}
		base += 37;
	}
}
/* Purpose: renders a bitmap to the video base using = NOTE: olny renders a 16x16 image, does this in color
Parameters: x (x position to render at), y (y position to render at), block (a unsigned long array of the block to render),
base (the video base to be rendered to).
Returns: none
*/
void renderBitmapEquals(int x, int y, unsigned long block[],unsigned long *base ){
	int index;
	unsigned long offsetWord = (x & 15);
    volatile unsigned long bitmaskLong = (1 << offsetWord) - 1;
    unsigned long firstLong,secondLong;
    bitmaskLong = bitmaskLong << 16;
    bitmaskLong += (1 << offsetWord) - 1;
	base += ((y*40) + (x >> 3)) & 0xFFFFFFFE; /* makes sure each block is at correct long FFFE because of 8+ pixel error (odd word error) */
	for(index = 0; index < 32; index++){ /* every block has a size of 16x16*/
		firstLong = block[index] & bitmaskLong;
		if(x >= 0){
			*base = ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
			index++;
			*base = ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
		}else{ 
			base += 2;
			index++;
		}
		secondLong = block[index] & bitmaskLong;
		if(x <= 304){
			*base = firstLong << (16 - offsetWord);
			base++;
			*base = secondLong << (16 - offsetWord);
		}else{ base++;}
		base += 37;
	}
}
/* Purpose: gets a specifed amount of rows 
Parameters: y (y position to start grabbing at), ySize (the amount of rows to grab), base (the base to grab frames from),
Returns: block (a long array of all the values grabbed)
*/
void getBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base ){
	int Ypos,Xpos,indexCounter =0;
	base += (y*40); 
	for(Ypos = 0; Ypos < ySize; Ypos++){
		for(Xpos = 0; Xpos < 40; Xpos++){
			block[Xpos + indexCounter] = *base;
			base++;
		}
		indexCounter += 40;
	}
}
/* Purpose: sets a specifed amount of rows using equals
Parameters: y (y position to start at), ySize (the amount of rows to set), base (the base to write frames to),
block (a unsigned long array of the slice to render)
Returns: none
*/
void setBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base ){
	int Ypos,Xpos,indexCounter = 0;
	base += (y*40);
	for(Ypos = 0; Ypos < ySize; Ypos++){
		for(Xpos = 0; Xpos < 40; Xpos++){
			*base = block[Xpos + indexCounter];
			base++;
		}
		indexCounter += 40;
	}
}
/* Purpose: sets a specifed amount of rows using or
Parameters: y (y position to start at), ySize (the amount of rows to set), base (the base to write frames to),
block (a unsigned long array of the slice to render)
Returns: none
*/
void setBitmapRowOr(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base ){
	int Ypos,Xpos,indexCounter = 0;
	base += (y*40);
	for(Ypos = 0; Ypos < ySize; Ypos++){
		for(Xpos = 0; Xpos < 40; Xpos++){
			*base |= block[Xpos + indexCounter];
			base++;
		}
		indexCounter += 40;
	}
}
/* Purpose: to render a color image of size 320x200
Parameters: screen (a unsigned long array of the image to render), base (the video base to render to)
Returns: none
*/
void renderBackSplash(unsigned long screen[],unsigned long *base ){
	int index;
	for(index = 0; index < 8000; index++){
		*base = screen[index];
		base++;
	}
}
/* Purpose: renders or derenders a 16x16 bitmap to the video base using ^= NOTE: renders in color
Parameters: x (x position to render at), y (y position to render at),
block (a unsigned long array of the block to render),base (the video base to be rendered to).
Returns: none
*/
void renderBitmapXOR(int x, int y, unsigned long block[],unsigned long *base ){
	int index;
	unsigned long offsetWord = (x & 15);
    volatile unsigned long bitmaskLong = (1 << offsetWord) - 1;
    unsigned long firstLong,secondLong;
    bitmaskLong = bitmaskLong << 16;
    bitmaskLong += (1 << offsetWord) - 1;
	base += ((y*40) + (x >> 3)) & 0xFFFFFFFE; /* makes sure each block is at correct long FFFE because of 8+ pixel error */
	for(index = 0; index < 32; index++){ /* every block has a size of 16x16*/
		firstLong = block[index] & bitmaskLong;
		if(x >= 0){
			*base ^= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
			index++;
			*base ^= ((block[index] | bitmaskLong) ^ bitmaskLong) >> offsetWord;
			base++;
		}else{ 
			base += 2;
			index++;
		}
		secondLong = block[index] & bitmaskLong;
		if(x <= 304){
			*base ^= firstLong << (16 - offsetWord);
			base++;
			*base ^= secondLong << (16 - offsetWord);
		}else{ base++;}
		base += 37;
	}
}
/*Purpose: to load an array of colors into the color pallets NOTE: cannot be in super during call
Parameters: colors (an integer array representing the color values to move into the color pallets)
returns: none
*/

void loadColors(int colors[16]){
	long old_sup = Super(0);
	int index;
	int *firstAddress = (0x00FF8240);
	for(index = 0; index < 16; index++){
		*firstAddress = colors[index];
		firstAddress++;
	}
	Super(old_sup);
}
/*Purpose: to get all of the values in the color pallets prior to running the program NOTE: cannot be in super during call
Parameters: None
returns: colors (an array of integers representing the colors currently in the color pallets)
*/
void getColors(int colors[16]){
	long old_sup = Super(0);
	int index;
	int *firstAddress = (0x00FF8240);
	for(index = 0; index < 16; index++){
		colors[index] = *firstAddress;
		firstAddress++;
	}
	Super(old_sup);
}
/* Purpose : clears all bits in the video base.
Parameters: the base to clear
Returns: the video base
*/
void clearScreen(unsigned long *base){
	int index;
	for(index = 0; index < 8000; index++){
		*base = 0x00000000;
		base++;
	}
}
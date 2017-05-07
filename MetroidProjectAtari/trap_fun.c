#include "trap_fun.h"

volatile unsigned int vsyncFlag;
unsigned long keyValues[] = {0,0,0,0,0,0,0,0};
unsigned int lastValue = 0;
unsigned long time = 0;
unsigned int stateIKBR = 0;
unsigned long mouseXlocation = 128;
unsigned long mouseYlocation = 128;
unsigned long mousePress = 0;
/* Purpose: sets the Vsync flag to flag and updates music NOTE: this should be called by the VBL ISR
Parameters: flag (the flag to set vsyncFlag to)
returns: none
*/
void setVsync(unsigned int flag){
	vsyncFlag = flag;
	update_music();
}
/* Purpose: adds a keycode to the buffer and handels mouse movements
Parameters: value (that should be loaded into the buffer or the value of the mouse))
returns: none
*/
void addBuff(signed int value){
	int negitive = ((char) value) < 0;
	if(stateIKBR == 0 && value >= 248){
		mousePress = value & 0x0003;
		stateIKBR = 2;
	}else if(stateIKBR == 0 && value < 248){
		unsigned int lower = value & 0x000F; 
		unsigned int index = (value & 0x0070) >> 4; 
		if(value < 128){
			keyValues[index] |= (0x00000001 << lower); 
		}else{
			keyValues[index] &= ~(0x00000001 << lower);
		}
	}else{
		if(stateIKBR == 1){
			mouseYlocation += ((char) value);
		}else{
			mouseXlocation += ((char) value);
		}
		stateIKBR--;
	}
}

void addTime(){
	time++;
}
int getTime(){
	return time;
}
unsigned long getMouseXlocation(){
	return mouseXlocation;
}
unsigned long getMouseYlocation(){
	return mouseYlocation;
}
void setMouseXlocation(unsigned long  X){
	mouseXlocation = X;
}
void setMouseYlocation(unsigned long  Y){
	mouseYlocation = Y;
}
unsigned int isLeftClickDown(){
	return mousePress & 0x0002;
}
/*Purpose: checks if a certin key is down NOTE: key is evaluated using scan codes */
unsigned int isKeyDown(unsigned int value){
	unsigned int lower = value & 0x000F; 
	unsigned int index = (value & 0x0070) >> 4;
	return keyValues[index] & (0x00000001 << lower); 
}
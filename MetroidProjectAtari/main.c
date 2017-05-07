#include "main.h"
/*
Name: Austin Eaton
Email: aeato254@mtroyal.ca
Class: 2659
Instructor: Paul Pospisil
*/


const struct Model defaultModel = {{160,127,0,1,30},
	{{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0}}, 
	{{20,20,0,1,0,0,24,16},{280,17,0,2,0,0,16,30},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}}
};
struct Model model1 = {{160,127,0,1,30},
	{{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0}}, 
	{{20,20,0,1,0,0,24,16},{280,17,0,2,0,0,16,30},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}}
};
struct Model model2 = {{160,127,0,1,30},
	{{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0},
{0,0,0,0},{0,0,0,0}}, 
	{{20,20,0,1,0,0,24,16},{280,17,0,2,0,0,16,30},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}}
};


char secondFrameBuffer[32256];
char emptyFrameBuffer[32256];

unsigned long behindMouse[1280];
unsigned long behindMouse2[1280];

/* this is the basic code for creating a menu
Parameters: base1 (the default base location), base2 (a second frame buffer that can be written to)
colorsToApply (an integer array that has the color values of the background), background (unsigned long values of the background),
buttonsPositions (a list of the button locations [greaterThan,lessThan,returnValue])
returns: the value corrisponding to the button the user pressed, value is defined by buttonsPositions.
*/
int menu(unsigned long *base1, unsigned long *base2,const int colorsToApply[16],const unsigned long background[8000], unsigned int buttonsPositions[9]){
	unsigned long *base;
	unsigned long oldMousePositionY = 32;
	unsigned long oldMousePositionY2 = 32;
	unsigned long *YMousePointer = &oldMousePositionY;
	unsigned long *MousePlace = behindMouse;
	struct Model *modelPtr;
	int currentBase = 2;
	int isDone = 0;
	int index = 0;
	base = base1;
	modelPtr = &model1;
	clearScreen(base1); /*screen is 20x12 blocks */
	clearScreen(base2);
	setMouseXlocation(4);
	setMouseYlocation(4);
	oldMousePositionY = 1;
	oldMousePositionY2 = 1;
	loadColors(colorsToApply);
	*YMousePointer = 1;
	renderBackSplash(background,base1);
	renderBackSplash(background,base2);
	getBitmapRow(*YMousePointer,32,behindMouse,base1);
	getBitmapRow(*YMousePointer,32,behindMouse2,base2);
	set_video_base(base1);
	while(isDone == 0){
		unsigned long Ypos = getMouseYlocation() >> 2;
		unsigned long Xpos = getMouseXlocation() >> 2;
		if((long)getMouseXlocation() < 0 ){
			Xpos =1;
			setMouseXlocation(4);
		}else if((long)getMouseXlocation() > 1212){
			setMouseXlocation(1212);
			Xpos = 303;
		}
		if((long)getMouseYlocation() < 0 ){
			setMouseYlocation(4);
			Ypos = 1;
		}else if((long)getMouseYlocation() > 536){
			setMouseYlocation(536);
			Ypos = 134;
		}
		for(index = 0; index < 9; index += 3){
			if(Ypos > buttonsPositions[index] && Ypos < buttonsPositions[index +1] && isLeftClickDown()){
				isDone = buttonsPositions[index +2];
			}
		}
		if(Ypos > 0 && Ypos < 135 && Xpos > 0 && Xpos < 304 && vsyncFlag != 0){
			if(currentBase == 1){
				YMousePointer = &oldMousePositionY;
				MousePlace = behindMouse;
				base = base1;
				currentBase++;
			}else{
				YMousePointer = &oldMousePositionY2;
				MousePlace = behindMouse2;
				base = base2;
				currentBase--;
			}
			setBitmapRow(*YMousePointer,32,MousePlace,base);
			getBitmapRow(Ypos,32,MousePlace,base);
			*YMousePointer = Ypos;
			setBitmapRowOr(Ypos,32,LaserImage,base);
			set_video_base(base);
			vsyncFlag = 0;
		}
	}
	return isDone;
}
/* loop for the main game, this requires that the keyboard ISR and VBL ISR have been installed
Parameters: base1 (the default base location), base2 (a second frame buffer that can be written to)
returns: isDone (4 if the player won 3 if the player died).
*/

int mainGame(unsigned long *base1, unsigned long *base2){
	const int colors[16] = {0x0000,0x0257,0x0146,0x0037,0x0721,0x0742,0x0240,0x0641,0x0233,0x0466,0x0261,0x0130,0x0320,0x0554,0x0451}; 
	unsigned long *base;
	unsigned long currentTime;
	unsigned long differnce;
	int isDone = 0;
	int currentBase = 2;
	int currentLevelNum = 0;
	struct Model *modelPtr;
	int levelNeedsRedraw = -1; /* used to keep track of which level to deRender, the value is the element number for level array*/
	unsigned long *emptybase = (unsigned long *)((((long) emptyFrameBuffer) & 0xFFFFFF00) + 256); /*maximum jank*/
	int index;
	model1 = defaultModel;
	model2 = model1;
	clearScreen(base1); /*screen is 20x12 blocks */
	clearScreen(base2);
	renderLevel(level[currentLevelNum].levelData,base1);
	renderLevel(level[currentLevelNum].levelData,base2);
	renderSamus(model2.samus,base2);
	renderEnemys(model2.enemys,base2);
	renderSamus(model1.samus,base1);
	renderEnemys(model1.enemys,base1);
	loadColors(colors);
	base = base1;
	set_video_base(base1);
	currentTime = getTime();
	while(isDone == 0){
		if(isKeyDown(0x0001) != 0){
			isDone = 1;
		}
		if (vsyncFlag != 0)
		{
			differnce = getTime() - currentTime;
			currentTime += differnce;
			if(currentBase == 1){
				base = base2;
				modelPtr = &model2;
				currentBase++;
			}else{
				base = base1;
				modelPtr = &model1;
				currentBase--;
			}
			unplotNumbers(40,192,modelPtr->samus.health,base);
			deRenderEnemys(modelPtr->enemys,base);
			deRenderBullets(modelPtr->bullets,base);
			deRenderSamus(modelPtr->samus,base);
			if(levelNeedsRedraw != -1){
				deRenderLevel(base,emptybase);
				renderLevel(level[currentLevelNum].levelData,base);
				levelNeedsRedraw = -1;
			}
			
			if(currentBase == 1){
				model1 = model2;
			}else{
				model2 = model1;
			}
			modelPtr->samus = moveSamus(modelPtr->samus,differnce,level[currentLevelNum].levelData,modelPtr->bullets);
			processBullets(level[currentLevelNum].levelData,modelPtr->bullets);/*TODO pass in delta */
			moveEnemys(modelPtr->samus,level[currentLevelNum].levelData,modelPtr->enemys);
			checkEnemyCollisionsWithPlayer(modelPtr->enemys,&(modelPtr->samus));
			checkEnemyCollisionsWithBullets(modelPtr->enemys,modelPtr->bullets);
			if(modelPtr->samus.health <= 0){
				isDone = 4;
			}

			if(modelPtr->samus.x > 295 && modelPtr->samus.y <= 100){
				deRenderLevel(base,emptybase);
				levelNeedsRedraw = currentLevelNum;
				modelPtr->samus.y += level[currentLevelNum].levelPositions[6];
				currentLevelNum = level[currentLevelNum].levelPositions[2];
				modelPtr->samus.x = 11;
				resetBullets(modelPtr->bullets);
				for(index = 0; index < ENEMYMAX; index++){
					modelPtr->enemys[index] = level[currentLevelNum].enemys[index];
				}
				renderLevel(level[currentLevelNum].levelData,base);
			}
			if(modelPtr->samus.x > 295 && modelPtr->samus.y > 100){
				deRenderLevel(base,emptybase);
				levelNeedsRedraw = currentLevelNum;
				modelPtr->samus.y += level[currentLevelNum].levelPositions[7];
				currentLevelNum = level[currentLevelNum].levelPositions[3];
				modelPtr->samus.x = 11;
				resetBullets(modelPtr->bullets);
				for(index = 0; index < ENEMYMAX; index++){
					modelPtr->enemys[index] = level[currentLevelNum].enemys[index];
				}
				renderLevel(level[currentLevelNum].levelData,base);
			}
			if(modelPtr->samus.x < 10 && modelPtr->samus.y <= 100){
				deRenderLevel(base,emptybase);
				levelNeedsRedraw = currentLevelNum;
				modelPtr->samus.y += level[currentLevelNum].levelPositions[4];
				currentLevelNum = level[currentLevelNum].levelPositions[0];
				modelPtr->samus.x = 290;
				resetBullets(modelPtr->bullets);
				for(index = 0; index < ENEMYMAX; index++){
					modelPtr->enemys[index] = level[currentLevelNum].enemys[index];
				}
				renderLevel(level[currentLevelNum].levelData,base);
			}
			if(modelPtr->samus.x < 10 && modelPtr->samus.y > 100){
				deRenderLevel(base,emptybase);
				levelNeedsRedraw = currentLevelNum;
				modelPtr->samus.y += level[currentLevelNum].levelPositions[5];
				currentLevelNum = level[currentLevelNum].levelPositions[1];
				modelPtr->samus.x = 290;
				resetBullets(modelPtr->bullets);
				for(index = 0; index < ENEMYMAX; index++){
					modelPtr->enemys[index] = level[currentLevelNum].enemys[index];
				}
				renderLevel(level[currentLevelNum].levelData,base);
			}
			plotNumbers(40,192,modelPtr->samus.health,base);
			renderSamus(modelPtr->samus,base);
			renderEnemys(modelPtr->enemys,base);
			renderBullets(modelPtr->bullets,base);
			if(currentLevelNum == 18 && modelPtr->enemys[0].type == 0){
				isDone = 3;
			}
			set_video_base(base);
			vsyncFlag = 0;
		}
	}
	return isDone;
}
int main(){
	long old_sup;
	const int colorsBackSplash[16] = {0x0000,0x0777,0x0555,0x0333,0x0077,0x0033,0x0007,0x0003,0x0770,0x0330,0x0300,0x0000,0x0700,0x0000,0x0000}; 
	const int colorsGameOver[16] =   {0x0000,0x0700,0x0770,0x0030,0x0555,0x0033,0x0007,0x0003,0x0770,0x0330,0x0300,0x0000,0x0700,0x0000,0x0000};
	const int colorsWin[16] =   {0x0000,0x0333,0x0003,0x0555,0x0330,0x0033,0x0300,0x0303,0x0700,0x0770,0x0300,0x0000,0x0700,0x0000,0x0000};
	int originalColors[16];
	unsigned long *base1 = get_video_base();
	unsigned long *base2 = (unsigned long *)((((long) secondFrameBuffer) & 0xFFFFFF00) + 256); /*maximum jank*/
	unsigned long *emptybase = (unsigned long *)((((long) emptyFrameBuffer) & 0xFFFFFF00) + 256); /*maximum jank*/
	int isDone = 1;
	unsigned int buttonsPositionsMainMenu[] = {98,104,2,124,136,3,0,0,0};
	unsigned int buttonsPositionsDeadMenu[] = {80,94,2,111,130,1,0,0,0};
	unsigned int buttonsPositionsWinMenu[] = {46,60,1,0,0,0,0,0,0};
	int choice = 0;
	Vector orig_vector = install_vector(VBL_TRAP,trap0_vbl);
	Vector orig_IKBR_vector = install_vector(IKBR_TRAP,trapIKBR);
	getColors(originalColors);
	start_music();
	clearScreen(emptybase);
	while(isDone == 1){
		isDone = menu(base1,base2,colorsBackSplash,backSplash, buttonsPositionsMainMenu);
		if(isDone == 3){
			break;
		}
		while(isDone == 2){
			isDone = mainGame(base1,base2);
			if(isDone == 4){
				isDone = menu(base1,base2,colorsGameOver,gameOverHex, buttonsPositionsDeadMenu);
			}else if(isDone == 3){
				isDone = menu(base1,base2,colorsWin,winScreenHex, buttonsPositionsWinMenu);
			}
		}
	}
	old_sup = Super(0);
	stop_sound();
	Super(old_sup);
	loadColors(originalColors);
	set_video_base(base1);
	install_vector(IKBR_TRAP,orig_IKBR_vector);
	install_vector(VBL_TRAP,orig_vector);
	return 0;
}

/* installs a ISR into the appropriate Vector
Parameters: num (the vector number), vector (the ISR location in memory)
returns: orig (the original vector at the specified vector number)
*/
Vector install_vector(int num, Vector vector){
	Vector orig;
	Vector *vectp = (Vector *)((long) num << 2);
	long old_spp = Super(0);
	
	orig = *vectp;
	*vectp = vector;
	
	Super(old_spp);
	return orig;
}
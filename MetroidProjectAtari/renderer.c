#include "renderer.h"

/* Purpose: to render the samus player model
Parameters: samus (the current samus model), base (the video base to render to)
Returns: none
*/
void renderSamus(struct Samus samus, unsigned long *base){
	switch(samus.direction){
	case -1: 
		renderBitmap(samus.x, samus.y + 2, samusHeadLeft, base);
		renderBitmap(samus.x + 3, samus.y + 17, samusBodyLeft, base);			
		break;
	case 0:
		renderBitmapWithSize(samus.x + 3, samus.y - 4,37, samusUP, base);
		break;
	case 1:
		renderBitmap(samus.x + 3, samus.y + 2, samusHeadRight, base);
		renderBitmap(samus.x, samus.y + 17, samusBodyRight, base);
		break;
	}
}
/* Purpose: plot a two digit number at said pixel location
Parameters: x (x position to render the numbers at), y (y position to render the numbers at),
number (the two digit number to render), base (video base to write to)
Returns: none
*/
void plotNumbers(int x,int y,int number, unsigned long *base){
	int leadingNumber = number /10;
	int secondNumber = number - (leadingNumber *10);
	plotNumber(x,y,leadingNumber,base);
	plotNumber(x + 8,y,secondNumber,base);
}
/* Purpose: plot a on digit number at said pixel location
Parameters: x (x position to render the numbers at), y (y position to render the numbers at),
number (the one digit number to render), base (video base to write to)
Returns: none
*/
void plotNumber(int x, int y, int Number, unsigned long *base){
	switch(Number){
		case 0:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber0, base);
			break;
		case 1:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber1, base);
			break;
		case 2:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber2, base);
			break;
		case 3:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber3, base);
			break;
		case 4:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber4, base);
			break;
		case 5:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber5, base);
			break;
		case 6:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber6, base);
			break;
		case 7:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber7, base);
			break;
		case 8:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber8, base);
			break;
		case 9:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber9, base);
			break;
		default:
			renderBitmapWithSize(x,y,8,LitteralyTheNumber9, base);
			break;
	}
}
/* Purpose: xor a two digit number at said pixel location
Parameters: x (x position to xor the numbers at), y (y position to xor the numbers at),
number (the two digit number to xor at), base (video base to write to)
Returns: none
*/
void unplotNumbers(int x,int y,int number, unsigned long *base){
	int leadingNumber = number /10;
	int secondNumber = number - (leadingNumber *10);
	unplotNumber(x,y,leadingNumber,base);
	unplotNumber(x + 8,y,secondNumber,base);
}
/* Purpose: plot a on digit number at said pixel location
Parameters: x (x position to render the numbers at), y (y position to render the numbers at),
number (the one digit number to render), base (video base to write to)
Returns: none
*/
void unplotNumber(int x, int y, int Number, unsigned long *base){
	switch(Number){
		case 0:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber0, base);
			break;
		case 1:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber1, base);
			break;
		case 2:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber2, base);
			break;
		case 3:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber3, base);
			break;
		case 4:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber4, base);
			break;
		case 5:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber5, base);
			break;
		case 6:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber6, base);
			break;
		case 7:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber7, base);
			break;
		case 8:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber8, base);
			break;
		case 9:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber9, base);
			break;
		default:
			renderBitmapWithSizeXOR(x,y,8,LitteralyTheNumber9, base);
			break;
	}
}
/* Purpose: plot a reo at said position
Parameters: x (x position to render a reo at), y (y position to render a reo at),
 base (video base to write to)
Returns: none
*/
void renderReo(int x, int y, unsigned long *base){
	renderBitmap(x,y,reoLeft,base);
	renderBitmap(x + 16,y,reoRight,base);
}
/* Purpose: deRender a reo NOTE: uses XOR to derender
Parameters: x (x position to derender a reo at), y (y position to derender a reo at),
base (video base to write to)
Returns: none
*/
void deRenderReo(int x, int y, unsigned long *base){
	renderBitmapXOR(x,y,reoLeft,base);
	renderBitmapXOR(x + 16,y,reoRight,base);
}
/* Purpose: to render all of the enemys that are currently alive
Parameters: enemys (a list of all of the enemys if an enemy type is 0 then that enemy is not rendered),
base (video base to write to)
Returns: none
*/
void renderEnemys(struct Enemy enemys[ENEMYMAX], unsigned long *base){
	int index;
	for(index = 0; index < ENEMYMAX; index++){
		switch(enemys[index].type){
			case 1:
				renderReo(enemys[index].x,enemys[index].y,base);
				break;
			case 2:
				renderBitmapWithSize(enemys[index].x,enemys[index].y,32,SkreeEnemyValues,base);
				break;
			case 3:
			if(enemys[index].damage == 0 || enemys[index].damage == 1){
				renderBitmapWithSize(enemys[index].x,enemys[index].y,64,motherBrainLeft,base);
				renderBitmapWithSize(enemys[index].x + 16,enemys[index].y,64,motherBrainMid,base);
				renderBitmapWithSize(enemys[index].x + 32,enemys[index].y,64,motherBrainRight,base);
				enemys[index].damage += 1;
			}
			break;
			case 4:
			renderBitmap(enemys[index].x,enemys[index].y,zebImage,base);
			break;
		}
	}
}
/* Purpose: to derender all of the enemys that are currently alive
Parameters: enemys (a list of all of the enemys if an enemy type is 0 then that enemy is not derendered),
base (video base to write to)
Returns: none
*/
void deRenderEnemys(struct Enemy enemys[ENEMYMAX], unsigned long *base){
	int index;
	for(index = 0; index < ENEMYMAX; index++){
		switch(enemys[index].type){
			case 1:
				deRenderReo(enemys[index].x,enemys[index].y,base);
				break;
			case 2:
				renderBitmapWithSizeXOR(enemys[index].x,enemys[index].y,32,SkreeEnemyValues,base);
				break;
			case 4:
				renderBitmapXOR(enemys[index].x,enemys[index].y,zebImage,base);
			break;
		}
	}
}
/* Purpose: to derender the samus player model NOTE: it uses xor to derender
Parameters: samus (the current samus model), base (the video base to derender the player model on)
Returns: none
*/
void deRenderSamus(struct Samus samus, unsigned long *base){
	switch(samus.direction){
	case -1: 
		renderBitmapXOR(samus.x, samus.y + 2, samusHeadLeft, base);
		renderBitmapXOR(samus.x+ 3, samus.y + 17, samusBodyLeft, base);			
		break;
	case 0:
		renderBitmapWithSizeXOR(samus.x + 3, samus.y - 4,37, samusUP, base);
		break;
	case 1:
		renderBitmapXOR(samus.x + 3, samus.y + 2, samusHeadRight, base);
		renderBitmapXOR(samus.x, samus.y + 17, samusBodyRight, base);
		break;
	}
}
/* Purpose: to render all of the currently alive bullets
Parameters: bullets (an array representing all current bullets on the screen bullet is dead if x and y speed are 0), 
base (the video base to render to)
Returns: none
*/
void renderBullets(struct Bullet bullets[BULLET_MAX],unsigned long *base){
	int index; 
	for(index = 0; index < BULLET_MAX;index++){
		if(bullets[index].xSpeed != 0 || bullets[index].ySpeed != 0){
			renderBitmapWithSize(bullets[index].x,bullets[index].y,4,bulletData,base);
		}
	}
}
/* Purpose: to derender all of the currently alive bullets NOTE: derenders by using xor
Parameters: bullets (an array representing all current bullets on the screen bullet is dead if x and y speed are 0), 
base (the video base to render to)
Returns: none
*/
void deRenderBullets(struct Bullet bullets[BULLET_MAX],unsigned long *base){
	int index; 
	for(index = 0; index < BULLET_MAX;index++){
		if(bullets[index].xSpeed != 0 || bullets[index].ySpeed != 0){
			renderBitmapWithSizeXOR(bullets[index].x,bullets[index].y,4,bulletData,base);
		}
	}
}
/* Purpose: to render the current level to the screen
Parameters: level (the list of integers corrisponding to the current level),
base (the video base to render to)
Returns: none
*/
void renderLevel(int level[LevelYSize][LevelXSize],unsigned long *base){
	int x,y,z;
	int indexNumbers[20];
	renderBitmapWithSize(20,192,8,LitteralyTheLettersHP,base);
	for(z = 0; z < 12;z++){
		for(x = 0; x < LevelXSize; x++){
			indexNumbers[x] = level[z][x] * 32; /* each differnt block is 32 elements away. */
		}
		for(y =0; y < 16; y++){
			for(x =0; x < LevelXSize ; x++){
				if(indexNumbers[x] > 31){
					*base = allBlocks[indexNumbers[x]];
					base++;
					indexNumbers[x]++;
					*base = allBlocks[indexNumbers[x]];
					base++;
					indexNumbers[x]++;
				}else{
					base+= 2;
				}
			}
		}
	}
}
/* Purpose: to derender the current level to the screen
Parameters: base (the video base to render to) ,source (an empty video base)
Returns: none
*/
void deRenderLevel(unsigned long  *base, unsigned long *source){
	memcpy(base,source,32000);
}
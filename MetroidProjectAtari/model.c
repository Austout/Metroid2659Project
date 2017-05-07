#include "model.h"

int cooldownTime = 0;
/* The following code moves samus depending on which arrow keys are down. the creation of bullets is also done here.
Parameters: samus (the current structure representing Samus), deltaTime (the amount of Vsyncs passed since the last Vsync)
level (the list of intgers corrisponding to the current level), bullets (an array representing all current bullets on the screen)
returns: a structure repersenting the updated position of Samus,
changes the value of bullets if a new bullet needs to be created
*/
struct Samus moveSamus(struct Samus samus,unsigned long deltaTime,int level[LevelYSize][LevelXSize],struct Bullet bullets[BULLET_MAX]){
	if(isKeyDown(0x001E) || isKeyDown(0x004B)){
		if(isCollidingWithLevel(samus.x - 1 - deltaTime,samus.y,SAMUSXSIZE,SAMUSYSIZE,level) == 0){
			samus.x -= (1 + deltaTime);
		}
		samus.direction = -1;
	}else if(isKeyDown(0x0020)  || isKeyDown(0x004D)){
		if(isCollidingWithLevel(samus.x + 1 + deltaTime,samus.y,SAMUSXSIZE,SAMUSYSIZE,level) == 0){
			samus.x += (1 + deltaTime);
		}
		samus.direction = 1;
	}
	if(isCollidingWithLevel(samus.x ,samus.y + (SAMUS_GRAVITY),SAMUSXSIZE,SAMUSYSIZE,level) == 0){
		if(samus.isJumping <= 0){
			samus.y += SAMUS_GRAVITY;
			samus.isJumping = 0;
		}
	}else if(isCollidingWithLevel(samus.x ,samus.y + 1,SAMUSXSIZE,SAMUSYSIZE,level) == 0) {
		if(samus.isJumping <= 0){
			samus.y++;
			samus.isJumping = 0;
		}
	}else{samus.isJumping = -1;}
	if(isKeyDown(0x002C) && samus.isJumping == -1){
		samus.isJumping = 87;
		playJumpSound();
	}
	if(isKeyDown(0x0011) || isKeyDown(0x0048)){
		samus.direction = 0;
	}
	if(isKeyDown(0x0039) && cooldownTime < 0){
		switch(samus.direction){
			case -1: 
				createBullet(samus.x - 5, samus.y +10, samus.direction,bullets);
				break;
			case 0:
				createBullet(samus.x +8, samus.y - 4, samus.direction,bullets);
				break;
			case 1:
				createBullet(samus.x + 14, samus.y +10, samus.direction,bullets);
				break;
		}
		cooldownTime = 10;
	}
	if(samus.isJumping > 0){
		samus.isJumping -= 3 * deltaTime;
		if(isCollidingWithLevel(samus.x,samus.y - (3 * deltaTime) -1,16,32,level) == 0){
			samus.y -= 3 * deltaTime;
		}else{
			samus.isJumping = 0;
		}
	}
	cooldownTime -= deltaTime;
	return samus;
}
/* this code moves bullets according to their speed and direction.
Parameters: level (the list of integers corrisponding to the current level), bullets (an array representing all current bullets on the screen)
returns: moves each bullet in the bullet array according to it's x and y speed. if the bullet collides with something or goes off screen
x and y speed is set to 0.
*/
void processBullets(int level[LevelYSize][LevelXSize],struct Bullet bullets[BULLET_MAX]){
	int index;
	for(index =0; index < BULLET_MAX; index++){
		bullets[index].x += bullets[index].xSpeed;
		bullets[index].y += bullets[index].ySpeed;
		if(bullets[index].x > 315 || bullets[index].x < 0 || bullets[index].y < 5
		|| isCollidingWithLevel(bullets[index].x,bullets[index].y,4,4,level) != 0){
			bullets[index].ySpeed = 0;
			bullets[index].xSpeed = 0;
		}
	}
}
/* this code checks if any bullets are colliding with enemys
Parameters: enemys (a list of all of the enemys if an enemy type is 0 then that enemy is not considered),
bullets (an array representing all current bullets on the screen)
returns: a bullet array representing all current bullets ( bullet x and y speed will be set to 0 if collision is detected),
the enemy type will be set to 0 if the bullet collides with the enemy
x and y speed is set to 0.
*/
void checkEnemyCollisionsWithBullets(struct Enemy enemys[ENEMYMAX],struct Bullet bullets[BULLET_MAX]){
	int index;
	int i; 
	for(index = 0; index < ENEMYMAX; index++){		
		for( i = 0;  i < BULLET_MAX;i++){
			if(enemys[index].type == 3 && (bullets[ i].xSpeed != 0 || bullets[ i].ySpeed != 0) && 
			isColliding(enemys[index].x,enemys[index].y,enemys[index].xSize,enemys[index].ySize,bullets[i].x,bullets[i].y,4,4) == 1){
				bullets[ i].xSpeed = 0;
				bullets[ i].ySpeed = 0;
				enemys[index].health -= 5;
				if(enemys[index].health <= 0){
					enemys[index].type = 0;
					enemys[index].damage = 3;
				}
			}
			if(enemys[index].type != 0 && (bullets[ i].xSpeed != 0 || bullets[ i].ySpeed != 0) && 
			isColliding(enemys[index].x,enemys[index].y,enemys[index].xSize,enemys[index].ySize,bullets[i].x,bullets[i].y,4,4) == 1){
				bullets[ i].xSpeed = 0;
				bullets[ i].ySpeed = 0;
				enemys[index].type = 0;
			}
		}
	}
}
/* purpose: sets all of the bullets feilds to 0
Parameters: bullets (a list repersenting all of the bullets on screen)
Returns: bullet array with all values set to 0*/
void resetBullets(struct Bullet bullets[BULLET_MAX]){
	int i;
	for( i = 0;  i < BULLET_MAX;i++){
		bullets[ i].xSpeed = 0;
		bullets[ i].ySpeed = 0;
		bullets[i].x = 0;
		bullets[i].y = 0;
	}
}
/* Purpose: check if any enemys are colliding with the player
Parameters: enemys (a list of all of the enemys if an enemy type is 0 then that enemy is not considered),
a pointer to samus (samus's health is decremented by 5 if a collision occurs)
Returns: the samus model with updated health.
the enemy type will be set to 0 if the bullet collides with the enemy
*/
void checkEnemyCollisionsWithPlayer(struct Enemy enemys[ENEMYMAX],struct Samus *samus){
	int index;
	for(index = 0; index < 10; index++){
		if(isColliding(samus->x,samus->y,SAMUSXSIZE,SAMUSYSIZE,enemys[index].x,enemys[index].y,enemys[index].xSize,enemys[index].ySize) == 1 
		&& enemys[index].type != 0){
			enemys[index].type = 0;
			samus->health -= 5;
		}
	}
}
/* Purpose: check if two object are colliding with eachother
Parameters: x1 (the x start of object 1), y1 (the y of object 1), xSize1 (x size of object 1), ySize (y size of obj1),
x3 (x position of object 2), y3 (y position of object 2), xSize2 (x size of object 2), ySize2 (y size of object 2)
Returns:an integer, 0 if no collision and 1 if their is a collision
*/
int isColliding(int x1,int y1,int xSize1,int ySize1,int x3,int y3,int xSize2,int ySize2){
	int x2 = x1 + xSize1;
	int y2 = y1 + ySize1;
	int x4 = x3 + xSize2;
	int y4 = y3 + ySize2;/* TODO move these calculations into the loop to reduce processing via short circuiting*/
	if((isBetween(x3,x1,x2) || isBetween(x4,x1,x2)) &&
		(isBetween(y3,y1,y2) || isBetween(y4,y1,y2))){
		return 1;
	}
	return 0;
}
/* Purpose: to check if a varible is between two positions 
Parameters: num (number to check), lower (greater than this num), upper (less than this number).
Returns:an integer, 0 if no collision and 1 if their is a collision
*/
int isBetween(int num, int lower, int upper){
	if(num <= upper && num >= lower){
		return 1;
	}
	return 0;
}
/* Purpose: to move and process each enemy accoriding to it's behaviours. 
Parameters: samus (current model of samus),level (the list of intgers corrisponding to the current level),
enemys (a list of all of the enemys if an enemy type is 0 then that enemy is not considered)
Returns: an updated version of enemys.
*/
void moveEnemys(struct Samus samus,int level[LevelYSize][LevelXSize],struct Enemy enemys[ENEMYMAX]){
	int index;
	int moveDistance;
	struct Enemy tempHolder[ENEMYMAX];
	for(index = 0; index < ENEMYMAX; index++){
		tempHolder[index] = enemys[index];
	}
	for(index = 0; index < ENEMYMAX; index++){
		switch(enemys[index].type){
			case 4: 
				moveDistance = tempHolder[index].x - 4;
				if(isCollidingWithLevel(moveDistance,tempHolder[index].y,tempHolder[index].xSize,tempHolder[index].ySize,level)== 0 && moveDistance> 0){
			 		tempHolder[index].x = moveDistance;
			 	}else{
			 		tempHolder[index].type = 0;
			 	}
			break;
			case 3:
				tempHolder[index].holder -= 1;
				if(tempHolder[index].holder < 0){
					tempHolder[index].holder = 9;
					if(tempHolder[index + 1].type == 0){
						tempHolder[index +1].x = 200;
						tempHolder[index+1].y = 150;
						tempHolder[index +1].type = 4;
					}else if(tempHolder[index +2].type == 0){
						tempHolder[index +2].x = 200;
						tempHolder[index+2].y = 133;
						tempHolder[index +2].type = 4;
					}else if(tempHolder[index +3].type == 0){
						tempHolder[index+3].x = 200;
						tempHolder[index+3].y = 116;
						tempHolder[index+3].type = 4;
					}
				}
			break;
			case 2:
				moveDistance = 	samus.x - tempHolder[index].x;
				if((tempHolder[index].holder == 1 || (moveDistance < 40 && moveDistance > -40)) && tempHolder[index].holder != 2){
					tempHolder[index].holder = 1;
					if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y + 6,tempHolder[index].xSize,tempHolder[index].ySize,level) == 0){
						tempHolder[index].y += 6;
					}else if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y + 1,tempHolder[index].xSize,tempHolder[index].ySize,level) == 0){
						tempHolder[index].y += 1;
					}else{
						tempHolder[index].holder = 2;
					}
					if(samus.x > tempHolder[index].x && isCollidingWithLevel(tempHolder[index].x + 1,tempHolder[index].y,tempHolder[index].xSize,tempHolder[index].ySize,level)== 0){
						tempHolder[index].x += 1;
					}else if(samus.x < tempHolder[index].x && isCollidingWithLevel(tempHolder[index].x - 1,tempHolder[index].y,tempHolder[index].xSize,tempHolder[index].ySize,level)== 0){
						tempHolder[index].x -= 1;
					}
				}
			break;
			case 1:
				moveDistance = (samus.y - tempHolder[index].y) >> 4;
				if(samus.y > tempHolder[index].y + 5){
					if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y + 3,REOXSIZE,REOYSIZE,level) == 0){
						tempHolder[index].y += 3;
					}else if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y + 1,REOXSIZE,REOYSIZE,level) == 0){
						tempHolder[index].y += 1;
					}
				}else if(samus.y < tempHolder[index].y - 5){
					if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y - 3,REOXSIZE,REOYSIZE,level) == 0){
						tempHolder[index].y -= 3;
					}else if(isCollidingWithLevel(tempHolder[index].x,tempHolder[index].y - 1,REOXSIZE,REOYSIZE,level) == 0){
						tempHolder[index].y -= 1;
					}
				}
				if(samus.x > tempHolder[index].x && isCollidingWithLevel(tempHolder[index].x + 1,tempHolder[index].y,REOXSIZE,REOYSIZE,level)== 0){
					tempHolder[index].x += 1;
				}else if(samus.x < tempHolder[index].x && isCollidingWithLevel(tempHolder[index].x - 1,tempHolder[index].y,REOXSIZE,REOYSIZE,level)== 0){
					tempHolder[index].x -= 1;
				}
			break;
			case 0:
			break;
		}
	}
	for(index = 0; index < ENEMYMAX; index++){
		enemys[index] = tempHolder[index];
	}
}
/* Purpose: to move and process each enemy accoriding to it's behaviours. 
Parameters: x (the x position of the bullet to be created), y (the y position of the bullet to be created),
bullets (a list repersenting all of the bullets on screen)
Returns: an updated version of bullets which include the new bullet.
*/
void createBullet(int x,int y,int direction,struct Bullet bullets[BULLET_MAX]){
	int index;
	int xSpeed = BULLET_SPEED * direction;
	int ySpeed = 0;
	if(direction == 0){
		ySpeed = -BULLET_SPEED;
	}
	for(index =0; index < BULLET_MAX && (bullets[index].xSpeed != 0 || bullets[index].ySpeed != 0); index++); /*meant to be one line finds an empty position in array*/
	if(index < 20){
		bullets[index].x = x;
		bullets[index].y = y;
		bullets[index].xSpeed = xSpeed;
		bullets[index].ySpeed = ySpeed;
		playGunShotSound();
	}
}
/* Purpose: check if an object is colliding with the level
Parameters: xPos (the x start of the object), yPos (the y of the object ), xSize1 (x size of the object), ySize (y size the object),
level (the list of intgers corrisponding to the current level),
Returns:an integer, 0 if no collision and 1 if their is a collision
*/
int isCollidingWithLevel(int xPos,int yPos, int xSize, int ySize,int level[LevelYSize][LevelXSize]){
	int currentX1LevelPos = (xPos) >> 4;
	int currentY1LevelPos = (yPos + 1) >> 4; /* +1 so that samus can pass through a 32 y sized area*/	
	int currentX2LevelPos = (xPos + xSize) >> 4;
	int currentY2LevelPos = (yPos + ySize) >> 4;
	if(level[currentY1LevelPos][currentX1LevelPos] != 0 ||
	level[currentY1LevelPos][currentX2LevelPos] != 0 ||
	level[currentY2LevelPos][currentX1LevelPos] != 0 ||
	level[currentY2LevelPos][currentX2LevelPos] != 0){
		return 1;
	}
	if(ySize > 16){
		if(level[currentY1LevelPos + 1][currentX1LevelPos] != 0 ||
		level[currentY1LevelPos + 1][currentX2LevelPos] != 0){
			return 1;
		}
	}
	return 0;
}
#ifndef MODEL_H
#define MODEL_H
/* 
Filename: model
Purpose: to manipulate the values of the game such as enemys and samus
*/
#include "const.h"
#include "raster.h"
#include "renderer.h"
#include "psg.h"
#include "trap_fun.h"

#define SAMUS_GRAVITY 4

struct Model{
	struct Samus samus;
	struct Bullet bullets[BULLET_MAX];
	struct Enemy enemys[ENEMYMAX];
};
void processBullets(int level[LevelYSize][LevelXSize],struct Bullet bullets[BULLET_MAX]);
struct Samus moveSamus(struct Samus samus,unsigned long deltaTime,int level[LevelYSize][LevelXSize],struct Bullet bullets[BULLET_MAX]);
int isCollidingWithLevel(int xPos,int yPos, int xSize, int ySize,int level[LevelYSize][LevelXSize]);
void createBullet(int x,int y,int direction,struct Bullet bullets[BULLET_MAX]);
void moveEnemys(struct Samus samus,int level[LevelYSize][LevelXSize],struct Enemy enemys[ENEMYMAX]);
int isBetween(int num, int lower, int upper);
int isColliding(int x1,int y1,int xSize1,int ySize1,int x3,int y3,int xSize2,int ySize2);
void checkEnemyCollisionsWithPlayer(struct Enemy enemys[ENEMYMAX],struct Samus *samus);
void checkEnemyCollisionsWithBullets(struct Enemy enemys[ENEMYMAX],struct Bullet bullets[BULLET_MAX]);
void resetBullets(struct Bullet myBullets[BULLET_MAX]);
#endif
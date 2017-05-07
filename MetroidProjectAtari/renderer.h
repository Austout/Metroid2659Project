#ifndef RENDERER_H
#define RENDERER_H
#include "const.h"
#include "raster.h"
#include <string.h>
void deRenderBullets(struct Bullet bullets[BULLET_MAX],unsigned long *base);
void renderBullets(struct Bullet bullets[BULLET_MAX],unsigned long *base);
void renderLevel(int level[LevelYSize][LevelXSize],unsigned long *base);
void deRenderLevel(unsigned long *base,unsigned long *source);
void renderSamus(struct Samus a,unsigned long *b);
void deRenderSamus(struct Samus samus, unsigned long *base);
void deRenderReo(int x,int y,unsigned long *base);
void renderReo(int x,int y,unsigned long *base);
void deRenderEnemys(struct Enemy enemys[10], unsigned long *base);
void renderEnemys(struct Enemy enemys[10], unsigned long *base);
void plotNumbers(int x,int y,int number , unsigned long *base);
void plotNumber(int x, int y, int Number, unsigned long *base);
void unplotNumbers(int x,int y,int number , unsigned long *base);
void unplotNumber(int x, int y, int Number, unsigned long *base);
#endif
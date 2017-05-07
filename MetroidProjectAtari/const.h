#ifndef CONST_H
#define CONST_H
/* 
Filename: const
Purpose: a colllection of some important constants that are widely used
*/
#define BULLET_MAX 20
#define BULLET_SPEED 8
#define LevelXSize 20
#define LevelYSize 12
#define SAMUSXSIZE 16
#define SAMUSYSIZE 32
#define NUMBEROFLEVELS 19
#define ENEMYMAX 10
#define REOXSIZE 24
#define REOYSIZE 16

struct Samus{
	int x;
	int y;
	int direction;
	int isJumping;
	int health;
};
struct Bullet{
	int x;
	int y;
	int xSpeed;
	int ySpeed;
};
struct Enemy{
	int x;
	int y;
	int damage;
	int type;
	int health;
	int holder;
	int xSize;
	int ySize;
};
struct Level{
	const int levelData[LevelYSize][LevelXSize];
	struct Enemy enemys[ENEMYMAX];
	const int levelPositions[8];
};
extern const unsigned long samusUP[];
extern const unsigned long allBlocks[];
extern const unsigned long zebImage[];
extern const unsigned long motherBrainLeft[];
extern const unsigned long motherBrainMid[];
extern const unsigned long motherBrainRight[];
extern const unsigned long bulletData[];
extern const unsigned long samusHeadRight[];
extern const unsigned long samusHeadLeft[];
extern const unsigned long reoLeft[];
extern const unsigned long reoRight[];
extern const unsigned long samusBodyRight[];
extern const unsigned long samusBodyLeft[];
extern const unsigned long SkreeEnemyValues[];
extern const unsigned long LitteralyTheLettersHP[];
extern const unsigned long LitteralyTheNumber9[];
extern const unsigned long LitteralyTheNumber8[];
extern const unsigned long LitteralyTheNumber7[];
extern const unsigned long LitteralyTheNumber6[];
extern const unsigned long LitteralyTheNumber5[];
extern const unsigned long LitteralyTheNumber4[];
extern const unsigned long LitteralyTheNumber3[];
extern const unsigned long LitteralyTheNumber2[];
extern const unsigned long LitteralyTheNumber1[];
extern const unsigned long LitteralyTheNumber0[];
extern const struct Level level[NUMBEROFLEVELS];
#endif
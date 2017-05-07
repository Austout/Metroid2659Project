#ifndef _MAIN_H
#define _MAIN_H
#include <OSBIND.H>
#include "raster.h"
#include "renderer.h"
#include "const.h"
#include "model.h"
#include "psg.h"
#include "hexvalues.h"
#include "trap_fun.h"
#include "GameOver.h"
#include "win_scrn.h"

#define VBL_TRAP 28
#define IKBR_TRAP 70

typedef void (*Vector)();
Vector install_vector(int num,Vector vector);
int menu(unsigned long *base1, unsigned long *base2,const int colorsToApply[16],const unsigned long background[8000], unsigned int buttonsPositions[9]);
int mainGame(unsigned long *base1, unsigned long *base2);

#endif
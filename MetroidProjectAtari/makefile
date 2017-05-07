TARGET=proj

$(TARGET): main.o raster_s.o vbl_trap.o raster.o renderer.o model.o const.o psg.o hexvalue.o trap_fun.o gameOver.o win_scrn.o
	cc68x main.o raster_s.o vbl_trap.o raster.o renderer.o model.o const.o psg.o hexvalue.o trap_fun.o gameOver.o win_scrn.o -o $(TARGET).tos -g
all: clean $(TARGET) $(TARGET).tos

clean: 
	$(RM) -f *.o *.tos
main.o: main.c main.h raster.h renderer.h const.h trap_fun.h
	cc68x -c main.c -g
raster.o: raster.c raster.h
	cc68x -c raster.c -g 
raster_s.o: raster.h raster_s.s
	gen -L2 raster_s.s
vbl_trap.o: vbl_trap.s
	gen -L2 vbl_trap.s
trap_fun.o: trap_fun.h trap_fun.c
	cc68x -c trap_fun.c -g
renderer.o: renderer.c renderer.h raster.h const.h
	cc68x -c renderer.c -g
const.o: const.c const.h
	cc68x -c const.c -g
model.o: model.c model.h renderer.h raster.h const.h psg.h
	cc68x -c model.c -g
psg.o: psg.c psg.h
	cc68x -c psg.c -g
hexvalue.o: hexvalue.c hexvalue.h
	cc68x -c hexvalue.c -g
gameOver.o: GameOver.c GameOver.h
	cc68x -c GameOver.c
win_scrn.o: win_scrn.c win_scrn.h
	cc68x -c win_scrn.c

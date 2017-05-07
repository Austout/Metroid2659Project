# 1 "main.c" 1
# 1 "./main.h" 1
# 1 "C:/c68/include/OSBIND.H" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/OSBIND.H" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/OSBIND.H" 2
# 33 "C:/c68/include/OSBIND.H"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/OSBIND.H"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 3 "./main.h" 2
# 1 "./raster.h" 1
# 1 "C:/c68/include/OSBIND.H" 1
# 4 "./raster.h" 2
# 1 "C:/c68/include/stdlib.h" 1
# 18 "C:/c68/include/stdlib.h"
typedef unsigned long  size_t;




typedef char  wchar_t;
# 44 "C:/c68/include/stdlib.h"
typedef struct {
    int		quot;
    int		rem;
} div_t;

typedef struct {
    long	quot;
    long	rem;
} ldiv_t;

 double atof (const char *s) ;
 int atoi (const char *str) ;
 long atol (const char *str) ;
 long int strtol (const char *nptr, char **endptr, int base) ;
 unsigned long int strtoul (const char *nptr, char **endptr, int base) ;
 double strtod (const char *s, char **endptr) ;

 void srand (unsigned int seed) ;
 int rand (void) ;

 void *malloc (size_t n) ;
 void free (void *param) ;
 void *realloc (void *_r, size_t n) ;
 void *calloc (size_t n, size_t sz) ;





 void *alloca (size_t) ;
# 89 "C:/c68/include/stdlib.h"
 void  abort (void) ;


 int atexit (void (*)(void)) ;

 void  exit (int) ;

 char *getenv (const char *tag) ;
 int system (const char *s) ;

 void *bsearch (const void *key, const void *base, size_t num, size_t size, int (*cmp )(const void *, const void *)) ;
 void qsort (void *base, size_t total_elems, size_t size, int (*cmp )(const void *, const void *)) ;

 int abs (int x) ;
 long labs (long x) ;

 div_t div (int num, int denom) ;
 ldiv_t ldiv (long num, long denom) ;

 int mblen (const char *, size_t) ;
 size_t mbstowcs (wchar_t *, const char *, size_t) ;
 int mbtowc (wchar_t *, const char *, size_t) ;
 size_t wcstombs (char *, const wchar_t *, size_t) ;
 int wctomb (char *, wchar_t) ;

 wchar_t *wcscat (wchar_t *, const wchar_t *) ;
 int wcscmp (const wchar_t *, const wchar_t *) ;
 wchar_t *wcscpy (wchar_t *, const wchar_t *) ;
 size_t wcslen (const wchar_t *) ;
 wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t) ;
 int wcsncmp (const wchar_t *, const wchar_t *, size_t) ;
 wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t) ;
# 5 "./raster.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 6 "./raster.h" 2


struct Block
{
	int x;
	int y;
	unsigned long pixels[32];
};

void set_video_base(unsigned long *frameBuffer);

unsigned long *get_video_base();

void getColors(int colors[16]);

void clearScreen(unsigned long *base);

void renderBackSplash(unsigned long screen[],unsigned long *base );

void renderBitmap(int x, int y, unsigned long block[],unsigned long *base);

void renderBitmapEquals(int x, int y, unsigned long block[],unsigned long *base );

void getBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void setBitmapRow(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void setBitmapRowOr(unsigned long y, unsigned long ySize,unsigned long block[],unsigned long *base );

void renderBitmapWithSize(int x, int y,int ySize, unsigned long block[],unsigned long *base);

void renderBitmapWithSizeXOR(int x, int y,int ySize, unsigned long block[],unsigned long *base);

void renderBitmapXOR(int x, int y, unsigned long block[],unsigned long *base );

void setScreenMoveP(int);

void loadColors(int colors[16]);
# 4 "./main.h" 2
# 1 "./renderer.h" 1
# 1 "./const.h" 1
# 18 "./const.h"
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
	const int levelData[12 ][20 ];
	struct Enemy enemys[10 ];
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
extern const struct Level level[19 ];
# 3 "./renderer.h" 2
# 1 "./raster.h" 1
# 4 "./renderer.h" 2
# 1 "C:/c68/include/string.h" 1
# 25 "C:/c68/include/string.h"
 void *memcpy (void *dst, const void *src, size_t size) ;
 void *memmove (void *dst, const void *src, size_t size) ;
 int memcmp (const void *s1, const void *s2, size_t size) ;
 void *memchr (const void *s, int ucharwanted, size_t size) ;
 void *memset (void *s, int ucharfill, size_t size) ;

 char *strcpy (char *dst, const char *src) ;
 char *strncpy (char *dst, const char *src, size_t n) ;
 char *strcat (char *dst, const char *src) ;
 char *strncat (char *dst, const char *src, size_t n) ;
 int strcmp (const char *scan1, const char *scan2) ;
 int strncmp (const char *scan1, const char *scan2, size_t n) ;
 int strcoll (const char *scan1, const char *scan2) ;
 size_t	strxfrm (char *to, const char *from, size_t maxsize) ;
 char *strchr (const char *s, int charwanted) ;
 size_t strcspn (const char *s, const char *reject) ;
 char *strpbrk (const char *s, const char *breakat) ;
 char *strrchr (const char *s, int charwanted) ;
 size_t strspn (const char *s, const char *accept) ;
 char *strstr (const char *s, const char *wanted) ;
 char *strtok (char *s, const char *delim) ;
 size_t strlen (const char *scan) ;
 char *strerror (int errnum) ;
# 54 "C:/c68/include/string.h"
 void *memccpy (void *dst, const void *src, int ucharstop, size_t size) ;
 char *strlwr (char *string) ;
 char *strupr (char *string) ;



 char *strrev (char *string) ;
 char *strdup (const char *s) ;




 char *index (const char *s, int charwanted) ;
 char *rindex (const char *s, int charwanted) ;
 void bcopy (const void *src, void *dst, size_t length) ;
 int bcmp (const void *src, const void *dst, size_t n) ;
 void bzero (void *b, size_t n) ;

 void _bcopy (const void *src, void *dst, unsigned long length) ;
 int  _bcmp (const void *s1, const void *s2, unsigned long length) ;
 void _bzero (void *dst, unsigned long length) ;

 int stricmp ( const char *, const char * ) ;
 int strnicmp ( const char *, const char *, size_t ) ;
 int strcmpi ( const char *, const char * ) ;
 int strncmpi ( const char *, const char *, size_t ) ;
# 5 "./renderer.h" 2

void deRenderBullets(struct Bullet bullets[20 ],unsigned long *base);
void renderBullets(struct Bullet bullets[20 ],unsigned long *base);
void renderLevel(int level[12 ][20 ],unsigned long *base);
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
# 5 "./main.h" 2
# 1 "./const.h" 1
# 6 "./main.h" 2
# 1 "./model.h" 1
# 1 "./const.h" 1
# 7 "./model.h" 2
# 1 "./raster.h" 1
# 8 "./model.h" 2
# 1 "./renderer.h" 1
# 9 "./model.h" 2
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 3 "./psg.h" 2



struct note{
	int frequency;
	unsigned long duration;
	unsigned int volume;
};

void set_frequency(int channel, unsigned int value);

void write_psg(int reg, int val);

int read_psg(int reg);

void set_volume(int channel, int volume);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_envelope(int shape, unsigned int sustain);

void playGunShotSound();

void playJumpSound();

void start_music();

void update_music();
# 10 "./model.h" 2
# 1 "./trap_fun.h" 1
# 1 "./psg.h" 1
# 3 "./trap_fun.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 4 "./trap_fun.h" 2

extern volatile unsigned int vsyncFlag;
extern volatile unsigned long keyValues[8];
unsigned int isKeyDown(unsigned int value);
void setVsync(unsigned int flag);
extern unsigned long time;
void addTime();
int getTime();
void addBuff(signed int value);
void trap0_vbl();
void trapIKBR();
unsigned long getMouseXlocation();
unsigned long getMouseYlocation();
void setMouseXlocation(unsigned long  X);
void setMouseYlocation(unsigned long  Y);
unsigned int isLeftClickDown();
extern unsigned int lastValue;
# 11 "./model.h" 2




struct Model{
	struct Samus samus;
	struct Bullet bullets[20 ];
	struct Enemy enemys[10 ];
};
void processBullets(int level[12 ][20 ],struct Bullet bullets[20 ]);
struct Samus moveSamus(struct Samus samus,unsigned long deltaTime,int level[12 ][20 ],struct Bullet bullets[20 ]);
int isCollidingWithLevel(int xPos,int yPos, int xSize, int ySize,int level[12 ][20 ]);
void createBullet(int x,int y,int direction,struct Bullet bullets[20 ]);
void moveEnemys(struct Samus samus,int level[12 ][20 ],struct Enemy enemys[10 ]);
int isBetween(int num, int lower, int upper);
int isColliding(int x1,int y1,int xSize1,int ySize1,int x3,int y3,int xSize2,int ySize2);
void checkEnemyCollisionsWithPlayer(struct Enemy enemys[10 ],struct Samus *samus);
void checkEnemyCollisionsWithBullets(struct Enemy enemys[10 ],struct Bullet bullets[20 ]);
void resetBullets(struct Bullet myBullets[20 ]);
# 7 "./main.h" 2
# 1 "./psg.h" 1
# 8 "./main.h" 2
# 1 "./hexvalues.h" 1
# 7 "./hexvalues.h"
extern const unsigned long backSplash[];
extern const unsigned long LaserImage[];
# 9 "./main.h" 2
# 1 "./trap_fun.h" 1
# 10 "./main.h" 2
# 1 "./GameOver.h" 1
# 7 "./GameOver.h"
extern const unsigned long gameOverHex[];
# 11 "./main.h" 2
# 1 "./win_scrn.h" 1
# 7 "./win_scrn.h"
extern const unsigned long winScreenHex[];
# 12 "./main.h" 2





typedef void (*Vector)();
Vector install_vector(int num,Vector vector);
int menu(unsigned long *base1, unsigned long *base2,const int colorsToApply[16],const unsigned long background[8000], unsigned int buttonsPositions[9]);
int mainGame(unsigned long *base1, unsigned long *base2);
# 1 "main.c" 2
# 10 "main.c"
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
# 75 "main.c"
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
	clearScreen(base1);
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





int mainGame(unsigned long *base1, unsigned long *base2){
	const int colors[16] = {0x0000,0x0257,0x0146,0x0037,0x0721,0x0742,0x0240,0x0641,0x0233,0x0466,0x0261,0x0130,0x0320,0x0554,0x0451};
	unsigned long *base;
	unsigned long currentTime;
	unsigned long differnce;
	int isDone = 0;
	int currentBase = 2;
	int currentLevelNum = 0;
	struct Model *modelPtr;
	int levelNeedsRedraw = -1;
	unsigned long *emptybase = (unsigned long *)((((long) emptyFrameBuffer) & 0xFFFFFF00) + 256);
	int index;
	model1 = defaultModel;
	model2 = model1;
	clearScreen(base1);
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
			processBullets(level[currentLevelNum].levelData,modelPtr->bullets);
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
				for(index = 0; index < 10 ; index++){
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
				for(index = 0; index < 10 ; index++){
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
				for(index = 0; index < 10 ; index++){
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
				for(index = 0; index < 10 ; index++){
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
	unsigned long *base2 = (unsigned long *)((((long) secondFrameBuffer) & 0xFFFFFF00) + 256);
	unsigned long *emptybase = (unsigned long *)((((long) emptyFrameBuffer) & 0xFFFFFF00) + 256);
	int isDone = 1;
	unsigned int buttonsPositionsMainMenu[] = {98,104,2,124,136,3,0,0,0};
	unsigned int buttonsPositionsDeadMenu[] = {80,94,2,111,130,1,0,0,0};
	unsigned int buttonsPositionsWinMenu[] = {46,60,1,0,0,0,0,0,0};
	int choice = 0;
	Vector orig_vector = install_vector(28 ,trap0_vbl);
	Vector orig_IKBR_vector = install_vector(70 ,trapIKBR);
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
	old_sup = _trap_1_wl((short)0x20,(long)(0)) ;
	stop_sound();
	_trap_1_wl((short)0x20,(long)(old_sup)) ;
	loadColors(originalColors);
	set_video_base(base1);
	install_vector(70 ,orig_IKBR_vector);
	install_vector(28 ,orig_vector);
	return 0;
}





Vector install_vector(int num, Vector vector){
	Vector orig;
	Vector *vectp = (Vector *)((long) num << 2);
	long old_spp = _trap_1_wl((short)0x20,(long)(0)) ;

	orig = *vectp;
	*vectp = vector;

	_trap_1_wl((short)0x20,(long)(old_spp)) ;
	return orig;
}

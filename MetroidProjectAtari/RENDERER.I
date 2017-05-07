# 1 "renderer.c" 1
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
# 1 "renderer.c" 2
# 7 "renderer.c"
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





void plotNumbers(int x,int y,int number, unsigned long *base){
	int leadingNumber = number /10;
	int secondNumber = number - (leadingNumber *10);
	plotNumber(x,y,leadingNumber,base);
	plotNumber(x + 8,y,secondNumber,base);
}





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





void unplotNumbers(int x,int y,int number, unsigned long *base){
	int leadingNumber = number /10;
	int secondNumber = number - (leadingNumber *10);
	unplotNumber(x,y,leadingNumber,base);
	unplotNumber(x + 8,y,secondNumber,base);
}





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





void renderReo(int x, int y, unsigned long *base){
	renderBitmap(x,y,reoLeft,base);
	renderBitmap(x + 16,y,reoRight,base);
}





void deRenderReo(int x, int y, unsigned long *base){
	renderBitmapXOR(x,y,reoLeft,base);
	renderBitmapXOR(x + 16,y,reoRight,base);
}





void renderEnemys(struct Enemy enemys[10 ], unsigned long *base){
	int index;
	for(index = 0; index < 10 ; index++){
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





void deRenderEnemys(struct Enemy enemys[10 ], unsigned long *base){
	int index;
	for(index = 0; index < 10 ; index++){
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





void renderBullets(struct Bullet bullets[20 ],unsigned long *base){
	int index;
	for(index = 0; index < 20 ;index++){
		if(bullets[index].xSpeed != 0 || bullets[index].ySpeed != 0){
			renderBitmapWithSize(bullets[index].x,bullets[index].y,4,bulletData,base);
		}
	}
}





void deRenderBullets(struct Bullet bullets[20 ],unsigned long *base){
	int index;
	for(index = 0; index < 20 ;index++){
		if(bullets[index].xSpeed != 0 || bullets[index].ySpeed != 0){
			renderBitmapWithSizeXOR(bullets[index].x,bullets[index].y,4,bulletData,base);
		}
	}
}





void renderLevel(int level[12 ][20 ],unsigned long *base){
	int x,y,z;
	int indexNumbers[20];
	renderBitmapWithSize(20,192,8,LitteralyTheLettersHP,base);
	for(z = 0; z < 12;z++){
		for(x = 0; x < 20 ; x++){
			indexNumbers[x] = level[z][x] * 32;
		}
		for(y =0; y < 16; y++){
			for(x =0; x < 20  ; x++){
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




void deRenderLevel(unsigned long  *base, unsigned long *source){
	memcpy(base,source,32000);
}

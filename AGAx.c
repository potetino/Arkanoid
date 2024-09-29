/*----------------------------------------------------------------*/
/* Игра Энергетический шар (Арканоид) для ПК11/16к 2024 год       */
/* автор А.Ермаков, консультант А.Кислый, графика app.leonardo.ia */
/*----------------------------------------------------------------*/

$$narg = 1;
#include <stdio.h>
#include <math.h>
#include "bios.h"
#include "FIGB.T"

#define MAXX 314
#define MAXY 240
#define XC MAXX/2
#define YC MAXY/2
#define MAXX1  380
#define MAXY1  280
#define MAXCOLOR 15
#define PI 3.14
#define Q 13
#define T 7
#define N 192

#define sndc0r (*(int*)0161010)
#define sndc1r (*(int*)0161012)
#define sndc2r (*(int*)0161014)
#define sndcsr (*(int*)0161016)

#define snlc0r (*(int*)0161020)
#define snlc1r (*(int*)0161022)
#define snlc2r (*(int*)0161024)
#define snlcsr (*(int*)0161026)

int  MODP;
int  IDENT,ANUM;
int  IDENT1,ANUM1;
int  IDENT2;
char CH;
int  ERR;
struct ARETYP AR;
struct WINTYP VW;
struct PALTYP PAL;
struct PALTYP PAL1;
int  *KEYB   = 0177560;
int  *KEYBUF = 0177562;
int COLOR;

/*-------------------------------------------------*/

int KEYPRESSED()
{
  return(*KEYB & 0200);
}
int READKEY()
{
  return(*KEYBUF);
}
GETCHH()
{
  while(!KEYPRESSED());

  READKEY();
}
BOX (IDENT,X1,Y1,X2,Y2)
int IDENT,X1,Y1,X2,Y2;
{
  GMOVE (IDENT, X1, Y1);
  GLINE (IDENT, X1, Y2);
  GLINE (IDENT, X2, Y2);
  GLINE (IDENT, X2, Y1);
  GLINE (IDENT, X1, Y1);
}
/*------------------------------------------------*/
INIT()
{
  PAL1.PMODPAL = 0;
  PLSAV(&PAL1);
  COLOR = PAL1.PAL[15];
  PAL1.PAL[15] = 0;
  PLMOD (&PAL1);
  *KEYB = 0;
  MODP=PL0+VM40;
  GCREA (MAXX, MAXY, MODP, &IDENT, &ANUM);
  GCREA (MAXX1, MAXY1, MODP, &IDENT1, &ANUM1);
  GWNDW (IDENT, 0,0, MAXX, MAXY);
	VW.AREA=ANUM1;
	VW.ARY=0;
	VW.ARX=0;
	VW.SY1=15;
	VW.SY2=MAXY1+10;
	VW.SX1=2;
	VW.SX2=26;
	VW.DEN=01002;
     VWCRE (&VW);
  VW.WNUM=0;
	VW.AREA=ANUM;
	VW.ARY=0;
	VW.ARX=0;
	VW.SY1=16;
	VW.SY2=MAXY+20;
	VW.SX1=4;
	VW.SX2=24;
	VW.DEN=01002;
     VWCRE (&VW); 

     GROP(IDENT, 0);
}

MESSAGE (STR)
char STR[];
{
  STR[0]=07;
  STR[1]=0360;
  WPRINT (ANUM1, 20, MAXY1-15, STR);
}

FINETEXT (STRZ,STRY,STRX,STRW)
char STRZ[]; 
char STRY[]; 
char STRX[];
char STRW[];
{
  STRZ[0]=07;
  STRZ[1]=0360;
  WPRINT (ANUM1, 5, MAXY1-260, STRZ);

  STRY[0]=07;
  STRY[1]=0360;
  WPRINT (ANUM1, 5, MAXY1-244, STRY);

  STRX[0]=07;
  STRX[1]=0360;
  WPRINT (ANUM1, 5, MAXY1-230, STRX);

  STRW[0]=07;
  STRW[1]=0360;
  WPRINT (ANUM1, 5, MAXY1-214, STRW);
}
/*--------------------------------*/ 
CH0(s,w,t)
int s,w,t;
{
int r,j;
sndcsr = 066;
snlcsr = 034;
snlc0r = 2;
sndc0r = s;
sndc0r = w;
for(r = 0; r < t; ++r)
	for(j = 0; j < 1024; ++j);
snlcsr = 064;
sndcsr = 066;
}

chord(a,b,c,d,y)
int a,b,c,d,y;
{
int g,p;
sndcsr = 0166;
snlcsr = 0134;
snlc1r = 3;
sndc1r = a;
sndc1r = b;
sndcsr = 0266;
snlcsr = 0234;
snlc2r = 3;
sndc2r = c;
sndc2r = d;

for(g = 0; g < y; ++g)
	for(p = 0; p < 1024; ++p);
snlcsr = 0164;
sndcsr = 0166;
snlcsr = 0264;
sndcsr = 0266;
}

PAUSE(time)
int time;
{
int t1,t2;
	for(t1 = 0; t1 < time; ++t1)
		for(t2 = 0; t2 < 1024; ++t2);
}

MUSIC()
{
int i;
		TIMEOF();	
		
	chord(212,212,106,106,64);PAUSE(32);
	chord(212,212,106,106,64);PAUSE(32);

	CH0(131,35,4);PAUSE(4);
	CH0(53,53,4);PAUSE(4);
	CH0(220,39,4);PAUSE(4);
	CH0(53,53,4);PAUSE(4);
	CH0(190,44,4);PAUSE(4);
	CH0(53,53,4);PAUSE(4);
	CH0(103,47,4);PAUSE(4);
	CH0(53,53,6);PAUSE(4);
	CH0(103,47,24);for(i = 0; i < 16; ++i)

	CH0(106,106,4);PAUSE(4);
	chord(179,23,193,17,8);PAUSE(4);
	CH0(106,106,4);PAUSE(4);
	chord(179,23,193,17,8);PAUSE(4);

	CH0(114,119,4);PAUSE(4);
	chord(179,23,238,19,8);PAUSE(4);	
	CH0(114,119,4);PAUSE(4);
	CH0(114,119,4);PAUSE(4);	
	CH0(114,119,4);PAUSE(4);
	chord(179,23,238,19,12);PAUSE(8);

	CH0(106,106,4);PAUSE(4);
	chord(179,23,193,17,8);PAUSE(4);
	CH0(106,106,4);PAUSE(4);
	chord(179,23,193,17,8);PAUSE(4);
	CH0(114,119,4);PAUSE(4);
	chord(179,23,238,19,8,0,0);PAUSE(4);
	CH0(114,119,4);PAUSE(4);
	CH0(114,119,4);PAUSE(4);
	CH0(114,119,4);PAUSE(4);
	chord(179,23,238,19,12);PAUSE(8);

	CH0(124,89,4);PAUSE(4);
	chord(193,17,238,14,4);PAUSE(4);
	CH0(124,89,4);PAUSE(4);
	chord(193,17,238,14,4);PAUSE(4);
	CH0(124,89,4);PAUSE(4);
	chord(238,19,210,15,4);PAUSE(4);
	CH0(124,89,4);PAUSE(4);
	chord(238,19,210,15,4);PAUSE(4);

	CH0(106,106,4);PAUSE(4);	
	chord(179,23,238,19,4);PAUSE(4);

	CH0(106,106,4);PAUSE(4);
	chord(179,23,238,19,4);PAUSE(4);

	CH0(106,106,4);PAUSE(4);
	chord(53,53,95,22,4);PAUSE(4);	
	CH0(106,106,4);PAUSE(4);
	chord(179,23,238,19,8);PAUSE(300);

	TIMEON();
}
/*--------------------------------*/
PIC(MSX)
{
 int q,j,v;
 int n = 64;
 int *buff = malloc(n * sizeof(int));

 FILE *fGE5;
 fGE5 = fopen(MSX, "rn");

  fseek(fGE5, 3866752L, 0);
  fread(buff, 16, 2, fGE5);
  PAL.PMODPAL = VM40;
  for (q=0; q<=15; q++)
   PAL.PAL[q] = ((buff[q] & 03400) >> 3) | 
                ((buff[q] & 0160)  >> 2) |
                ((buff[q] & 7) >> 1);
  PLCRE(&PAL);
  GCREA (256, 212, PAL.PMODPAL, &IDENT2, &ANUM);
  GCLRR(IDENT2);
  VW.WNUM=0;
  VW.AREA=ANUM;
  VW.ARY=0;
  VW.ARX=0;
  VW.SY1=44;
  VW.SY2=255;
  VW.SX1=5;
  VW.SX2=20;
  VW.DEN=0x0202;
  VWCRE (&VW);

  fseek(fGE5, 0L, 0);
  for (q=0; q<212; q++)
   {
    fread(buff, 128, 1, fGE5);
    for (j=0; j<64; ++j)
      buff[j] = ((buff[j] >> 4) & 0x0F0F) | 
                ((buff[j] << 4) & 0xF0F0);
    HBMOVE(ANUM, VPV, q*1, 1, 0, 128, buff, 0, 0);
   }
    fclose(fGE5);
    free(buff);
}


MANUAL()
{
	MESSAGE ("           Удачи и везенья!      ");
	PIC("MANUAL.GE5");
	GETCHH();
  VWKILL(&VW);
  GKILL(IDENT2);
  PLFRE(&PAL); 
}

/*-------------------------------*/
#define MAXST 11
#define MAXFILLINE 18

char STRA[] = "   Игра для ЭВМ ПК11/16к Союз-Неон ";


TITUL()
{
int i;
  GCLRR (IDENT);
  GROP (IDENT, 0);
  MESSAGE    ("   Версия 1.0  сборка 28.09.24  ");
  STRA[0] = 07;
	STRA[1] = 0360;
	WPRINT (ANUM,5,MAXY1-276,STRA);

	PIC("01.GE5");
	MUSIC();

	GETCHH();
  VWKILL(&VW);
  GKILL(IDENT2);
  PLFRE(&PAL); 
}
/*-------------------------------------------------*/

int lvl;
int i,t,k;
int tmp;
int key;
int run;
int PATTERNS[MAXST][MAXFILLINE+1];
int BLGREY[102];
int RACRG[109];
int ADYEL[109];
int ADRED[109];
int ADBLU[109];
int ADGREY[109];
int i1,i2,i3,i4;
int BGX1,BGX2,BGY1,BGY2;
int BRX1,BRX2,BRY1,BRY2;
int BYX1,BYX2,BYY1,BYY2;
int RRX1,RRX2,RRY1,RRY2;
int RBX1,RBX2,RBY1,RBY2;
int RWX1,RWX2,RWY1,RWY2;
int RGX1,RGX2,RGY1,RGY2;
int tmpx, tmpy;
char STRB[];
int del_ix;
int del_iy;
int dx,dy;
char SLIV[12];
char SSCO[12];
int lives;
int score;
float pos,psi;

typedef struct {
		float xb;
		float yb;
		int x;
		int y;
		int width;
		int height;
		float alfa;
		float speed;
} Tball; 
Tball ball;
Tball bl;

typedef struct {
		int rx;
		int ry;
		int rx2;
		int rwidth;
		int rheight;
} TRack; 
TRack racket;

typedef struct {
		int xo;
		int yo;
		int blwidth;
		int blheight;
} TBlock; 
TBlock block[N];
 
srtBall()
{
	int j,l,u;
	int SUMMG = 0;
	int SUMMR = 0;
	int SUMMY = 0;
  BGX1 = XC;
  BGY1 = YC + 30;
  BGX2 = XC + 12;
  BGY2 = YC + 41;
	for(j = 0; j < 55; ++j)
    {
      GFGC(IDENT1, 2);
      GDOT(IDENT1, XC+FIGBRED[SUMMG][0], YC+FIGBRED[SUMMG][1]);
      SUMMG = SUMMG + 1;
    };

  BRX1 = XC + 1;
  BRY1 = YC + 31;
  BRX2 = XC + 8;
  BRY2 = YC + 38;
	for(l = 0; l < 42; ++l)
    {
      GFGC(IDENT1, 3);
      GDOT(IDENT1, XC+FIGBORG[SUMMR][0], YC+FIGBORG[SUMMR][1]);
      SUMMR = SUMMR + 1;
    };

  BYX1 = XC + 1;
  BYY1 = YC + 31;
  BYX2 = XC + 5;
  BYY2 = YC + 35;
	for(u = 0; u < 7; ++u)
    {
      GFGC(IDENT1, 10);
      GDOT(IDENT1, XC+FIGBYEL[SUMMY][0], YC+FIGBYEL[SUMMY][1]);
      SUMMY = SUMMY + 1;
    };

  GVRR(IDENT1,BGX1,BGY1,BGX2,BGY2,&BLGREY);
}

srtRacket()
{
  int j,k,l,p;
	int SUMMRD = 0;
	int SUMMBL = 0;
	int SUMMWN = 0;
	int SUMMGR = 0;

  RRX1 = XC;
  RRY1 = YC + 10;
  RRX2 = XC + 24;
  RRY2 = YC + 13;
	for(j = 0; j < 12; ++j)
    {
      GFGC(IDENT1, 2);
      GDOT(IDENT1, XC+FIGPRD[SUMMRD][0], YC+FIGPRD[SUMMRD][1]);
      SUMMRD = SUMMRD + 1;
    };

  RBX1 = XC;
  RBY1 = YC + 10;
  RBX2 = XC + 26;
  RBY2 = YC + 13;
	for(k = 0; k < 16; ++k)
    {
      GFGC(IDENT1, 8);
      GDOT(IDENT1, XC+FIGPBL[SUMMBL][0], YC+FIGPBL[SUMMBL][1]);
      SUMMBL = SUMMBL + 1;
    };

  RWX1 = XC;
  RWY1 = YC + 10;
  RWX2 = XC + 27;
  RWY2 = YC + 13;
	for(l = 0; l < 26; ++l)
    {
      GFGC(IDENT1, 15);
      GDOT(IDENT1, XC+FIGPWT[SUMMWN][0], YC+FIGPWT[SUMMWN][1]);
      SUMMWN = SUMMWN + 1;
    };  

  RGX1 = XC;
  RGY1 = YC + 10;
  RGX2 = XC + 27;
  RGY2 = YC + 14;
	for(p = 0; p < 54; ++p)
    {
      GFGC(IDENT1, 14);
      GDOT(IDENT1, XC+FIGPGR[SUMMGR][0], YC+FIGPGR[SUMMGR][1]);
      SUMMGR = SUMMGR + 1;
    };
GVRR(IDENT1,RGX1, RGY1, RGX2, RGY2, &RACRG);
}

srtBYellow()
{
	int i;
  int ULX,ULY,ULX1,ULY1;
	int SUMM = 0;
  ULX = XC + 24;
  ULY = YC + 18;
  ULX1 = XC + 45;
  ULY1 = YC + 23;
	for(i = 0; i < 107; ++i)
    {
      GFGC(IDENT1, 10);
      GDOT(IDENT1, XC+FIGYELL[SUMM][0], YC+FIGYELL[SUMM][1]);
      SUMM = SUMM + 1;
    };

  GVRR(IDENT1,ULX,ULY,ULX1,ULY1,&ADYEL);
}

srtBRed()
{
	int i;
	int ULX,ULY,ULX1,ULY1;
	int SUMM = 0;
  ULX = XC;
  ULY = YC + 18;
  ULX1 = XC + 21;
  ULY1 = YC + 23;
	for(i = 0; i < 107; ++i)
    {
      GFGC(IDENT1, 2);
      GDOT(IDENT1, XC+FIGRED[SUMM][0], YC+FIGRED[SUMM][1]);
      SUMM = SUMM + 1;
    };

  GVRR(IDENT1,ULX,ULY,ULX1,ULY1,&ADRED);
}

srtBBlue()
{
	int i;
	int ULX,ULY,ULX1,ULY1;
	int SUMM = 0;
  ULX = XC + 48;
  ULY = YC + 18;
  ULX1 = XC + 69;
  ULY1 = YC + 23;
	for(i = 0; i < 107; ++i)
    {
      GFGC(IDENT1, 8);
      GDOT(IDENT1, XC+FIGBLU[SUMM][0], YC+FIGBLU[SUMM][1]);
      SUMM = SUMM + 1;
    };

  GVRR(IDENT1,ULX,ULY,ULX1,ULY1,&ADBLU);
}

srtBGrey()
{
	int i;
	int ULX,ULY,ULX1,ULY1;
	int SUMM = 0;
  ULX = XC + 72;
  ULY = YC + 18;
  ULX1 = XC + 93;
  ULY1 = YC + 23;
	for(i = 0; i < 107; ++i)
    {
      GFGC(IDENT1, 14);
      GDOT(IDENT1, XC+FIGGREY[SUMM][0], YC+FIGGREY[SUMM][1]);
      SUMM = SUMM + 1;
    };

  GVRR(IDENT1,ULX,ULY,ULX1,ULY1,&ADGREY);
}

moveBall(x,y)
{
		ball.xb = x;
		ball.yb = y;
		ball.x = (int)floor(ball.xb);
		ball.y = (int)floor(ball.yb);
		return (int)ball.x, (int)ball.y;
}

initBall()
{
		moveBall(10,10); 
		ball.alfa = - 1.8;
		ball.speed = 12;
		ball.width = 10;
		ball.height = 10;
}

putBall()
{
  GRVR(IDENT,ball.x,ball.y,&BLGREY);
}

autoMoveBall()
{

if (ball.alfa < 0.2) ball.alfa += PI*2;
if (ball.alfa > PI*2) ball.alfa -= PI*2;

bl = ball;

moveBall((int)floor(ball.xb + cos(ball.alfa) * ball.speed), 
(int)floor(ball.yb + sin(ball.alfa) * ball.speed));

	if ((ball.y <= 12) || (ball.x <= 2) || (ball.x >= MAXX - 14) || (CollisionWall() == TRUE) ||
	 (CollWallOne() == TRUE) || (CollWTWO() == TRUE))
	{
		blockCollision();
		ONEblockCollision();

		if((ball.x != bl.x) && (ball.y != bl.y))
		{
			if(bl.y && ball.x == ball.y && bl.x) bl.alfa = bl.alfa + PI;
			else
			{
				if (ball.x >= MAXX - 14 || ball.x <= 2) bl.alfa = (2*PI - bl.alfa) + PI;
				else bl.alfa = (2*PI - bl.alfa);
			}
		}
			else if (ball.y == bl.y) bl.alfa = (2*PI - bl.alfa) + PI;
			else bl.alfa = (2*PI - bl.alfa);
		    
		ball = bl;	
		autoMoveBall();

	}
	else if ((racket.rx + racket.rwidth / 2 == ball.x && racket.ry - 5 == ball.y) ||
	 (ball.x <= racket.rx + racket.rwidth && racket.rx <= ball.x + ball.width) && 
	 (ball.y <= racket.ry + racket.rheight && racket.ry <= ball.y + ball.height))
	  {
			pos = ball.x - (racket.rx - 4);
			psi = pos / racket.rwidth * 2;
			psi = (psi - 1) * PI / 2 * 0.5;
				if(psi < PI / 2 && psi > - PI * 2)
					{bl.alfa = - 1.6;}
			bl.alfa = - PI / 2 + psi;


		  ball = bl;
	  }

	if (KEYPRESSED()) {
						 key = GETCHH();
					if (key == 0103) {
						!KEYPRESSED();
						!READKEY();
						putRacket();
						moveRacket(racket.rx + 22);
						putRacket();
					}	
					else if (key == 0104) {
						!KEYPRESSED();
						!READKEY();
						putRacket();
						moveRacket(racket.rx - 22);
						putRacket();

					}
					else if (key == 060) 
						{
							run = FALSE;
						}
				}
}

		
delBall(dx,dy)
{
  GRVR(IDENT,dx,dy,&BLGREY);
}

initRacket()
{
	racket.rwidth = 28;
	racket.rheight = 4;
	racket.rx = (MAXX - racket.rwidth) / 2 - 10;
	racket.ry = MAXY - 10;
	racket.rx2 = racket.rx + racket.rwidth;
	racket.rx2 = racket.ry + racket.rheight;
}

putRacket()
{
  GRVR(IDENT,racket.rx, racket.ry, &RACRG);
}

moveRacket(x)
{
		racket.rx = x;
		if (racket.rx < 4)
			  racket.rx = 4;
		if (racket.rx + racket.rwidth >= MAXX - 4 )
			  racket.rx = MAXX - 4 - racket.rwidth;
}

initBlock()
{

for(i=0; i < N; ++i)
	{
		block[i].xo = ((i % 12) + 1) * 23;
		block[i].yo = ((i / 12) + 1) * 12;
		block[i].blwidth = 21;
		block[i].blheight = 5;
	}
}

OnePBlock(lvl)
{
		if (lvl == 1)
		{
  		for(i=24; i < 84; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);		
  			}
  	}
  	if (lvl == 2)
		{
			for(i=24; i < 48; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}			
			for(i=48; i < 96; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  			}
  		for(i=96; i < 120; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}
  	}
  	if (lvl == 3)
		{
  		for(i=12; i < 36; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);	
  			}
  		for(i=37; i < 47; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}
  		for(i=49; i < 59; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}
  		for(i=62; i < 70; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  			}
  		for(i=74; i < 82; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  			}
  		for(i=87; i < 93; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}
  		for(i=99; i < 105; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			}
  		for(i=112; i < 116; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);	
  			}
  		for(i=124; i < 128; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);	
  			}
  	}
		if (lvl == 4)
		{
  		for(i=12; i < 72; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);		
  			}
  	}
}
TwoPBlock(lvl)
{
  	if (lvl == 5)
		{
  		for(i=12; i < N; ++i)
  			{
  				if(i == 16 || i == 20 || i == 29 || i == 31 || i == 41 || i == 43)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);	
  			  }
  			  
  			  else if(i >= 52 && i <= 56 || i >= 64 && i <= 68 || i == 75 || i == 76 || i == 78 || i == 80 || i == 81 || i == 87 || i == 88
  			   || i == 90 || i == 92 || i == 93 || i == 98 || i >= 99 && i <= 106 || i >= 110 && i <= 118 || i == 122 || i >= 124 && i <= 126)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			  }
  			  else if(i == 127 || i == 128 || i == 130 || i == 134 || i == 136 || i == 140 || i == 142 || i == 146 || i == 148 || i == 152 || i == 154
  			  	    || i == 161 || i == 163 || i == 173 || i == 175 )
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  			  }

  			  else if(i == 77 || i == 79 || i == 89 || i == 91)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  			  }
  			}
  	}
 }

 ThreePBlock(lvl)
  {
  	if (lvl == 6)
		{
  		for(i=24; i <120; ++i)
  			{
  				if(i % 2 == 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}
  	  		else
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  	    	}
  	    	
  			}
  	}
  	if (lvl == 7)
		{
  		for(i=12; i <24; ++i)
  			{
  				if(i % 2 == 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}
  	    }
    	for(i=24; i <36; ++i)
  			{
  				if(i % 2 != 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
  	    	}
  	    }     	
  	   for(i=36; i <48; ++i)
  			{
  				if(i % 2 == 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}	
  	    }
  	   for(i=48; i <60; ++i)
  			{
  				if(i % 2 != 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}	
  	    }
  	    for(i=60; i <72; ++i)
  			{
  				if(i % 2 == 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
  	    	}	
  	    }
  	   for(i=72; i <84; ++i)
  			{
  				if(i % 2 != 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
  	    	}	
  	    }
  	   for(i=84; i <96; ++i)
  			{
  				if(i % 2 == 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}	
  	    }
  	   for(i=96; i <108; ++i)
  			{
  				if(i % 2 != 0)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  	    	}	
  	    }
  	}
}

FourPBlock(lvl)
{
  	if (lvl == 8)
    {
  		for(i=12; i < 139; ++i)
			{
  			if (i == 14 || i == 15|| i >= 25 && i <= 28 || i >= 36 && i <= 41 || i >= 48 && i <= 53 || i >= 60 && i <= 65 || i >= 72 && i <= 77
  				|| i >= 85 && i <= 89|| i >= 98 && i <= 101 || i == 111|| i == 112|| i == 113 || i == 124|| i == 125|| i == 137)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);	
  				}
  			
  			else if (i == 20|| i == 21|| i == 31|| i ==34 || i == 42 || i == 47|| i == 59 || i == 71|| i == 83|| i == 94
  				|| i == 105 || i == 116|| i == 127|| i == 138)
  				{
  	    	GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);	
  				}
  		}
  	}
}

FivePBlock(lvl)
{


  	if (lvl == 9)
		{
  		for(i=21; i < 182; ++i)
  			{
  	    	if(i == 21 || i == 22 || i == 34 || i >= 36 && i <= 44 || i == 46 || i == 48 || i == 56 || i == 58 || i == 60 || i >= 62 && i <= 66 || i == 68 || i == 70 ||
						i == 72 || i == 74 || i == 78 || i == 80 || i == 82 || i == 84 || i == 86 || i >= 88 && i <= 90 || i == 92 || i == 94 || i == 96 || i == 98 ||
						i == 100 || i== 102 || i== 104 || i == 106 || i ==108 || i == 110 || i == 112 || i == 114 || i == 116 || i == 118 || i == 120 || i == 122 ||
						i >= 124 && i <= 126 || i == 128 || i == 130 || i == 132 || i == 134 || i == 140 || i == 142 || i == 144 || i == 146 || i == 152 || i == 154 || i == 156 ||
						i >= 158 && i <= 164 || i == 166 || i == 168 || i == 178 || i == 180 || i == 181)
  				{
  	    		GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
  				}						
  			}
  	}
  	if (lvl == 10)
		{
  		for(i= 50; i < 58; ++i)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);	
  			}
  		for(i= 76; i < 164; ++i)
  			if(i >= 76 && i <= 79 || i == 87 || i == 92 || i == 98 || i >= 100 && i <= 103 || i == 105 || i == 109 || i == 111 || i == 113 ||i == 114 ||i == 116 ||i == 118 ||
  				i == 121 ||i == 123 ||i == 125 || i == 126 ||i == 128 ||i == 130 || i == 134 || i >= 136 && i <= 139 || i == 141 ||i == 147 ||i == 152 ||i >= 160 && i <= 163)
  			{
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);	
  			}
  		for(i = 182; i < 190; ++i)
  			{
  			GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);	
  			}
  	}
}



CollisionWall()
{
		if (lvl == 1)
		{
		for(i = 24 ; i < 84; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
		}
		else if (lvl == 2)
		{
		for(i = 24 ; i < 120; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
		}	
		else if (lvl == 3)
		{
		for(i = 12 ; i < 36; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;	

		for(i = 37 ; i < 47; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

		for(i = 49 ; i < 59; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;	

		for(i = 62 ; i < 70; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;

		for(i = 74 ; i < 82; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;

		for(i = 87 ; i < 93; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;

		for(i = 99 ; i < 105; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;	

		for(i = 112 ; i < 116; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;	

		for(i = 124 ; i < 128; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}
				else FALSE;				
		}	

		else if (lvl == 4)
		{
		
		for(i = 12 ; i < 72; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{

		 					return TRUE;}

				else FALSE;	
		
		}	
}

CollWallOne()
{
		if (lvl == 5)
		{
			for(i = 15 ; i < 176; ++i)
				if(i == 16 || i == 20 || i == 29 || i == 31 || i == 41 || i == 43 || i >= 52 && i <= 56 
					|| i >= 64 && i <= 68 || i >= 75 && i <= 81 || i >= 87 && i <= 93 || i >= 98 && i <= 106 || i == 110 || i == 111)
		        {
								if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  						 (ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 								{return TRUE;}

								else {FALSE;}	
		        }
  			else if (i >= 112 && i <= 118 || i == 122 || i >= 124 && i <= 128 || i == 130 || i == 134 || i == 136 || i == 140
  			 || i == 142 || i == 146 || i == 148 || i == 152 || i == 154
  			  	    || i == 161 || i == 163 || i == 173 || i == 175)
		        {
								if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  						 (ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 								{return TRUE;}

								else {FALSE;}	
		        }	
    }

  
}
CollWTWO()
{  
    if (lvl == 6)
		{
		for(i = 24 ; i < 120; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
		}
		if (lvl == 7)
		{
		for(i = 12 ; i < 24; ++i)
			if(i % 2 == 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;

		for(i = 24 ; i < 36; ++i)
			if(i % 2 != 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	

		for(i = 36 ; i < 48; ++i)
			if(i % 2 == 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
		for(i = 48 ; i < 60; ++i)
			if(i % 2 != 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;

		for(i = 60 ; i < 72; ++i)
			if(i % 2 == 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	

		for(i = 72 ; i < 84; ++i)
			if(i % 2 != 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	

		for(i = 84 ; i < 96; ++i)
			if(i % 2 == 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	

		for(i = 96 ; i < 108; ++i)
			if(i % 2 != 0)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
		}

		if (lvl == 8)
		{
			for(i = 12 ; i < 139; ++i)
					{
						if  ( i == 20|| i == 21|| i == 31|| i == 34|| i == 42 || i == 47|| i == 59|| i == 71|| i == 83
  							|| i == 94|| i == 105|| i == 116|| i == 127|| i == 138 || i == 14 || i == 15|| i == 25|| i == 26
  							|| i == 27|| i == 28|| i >= 36 && i <= 41|| i >= 48 && i <= 53|| i >= 60 && i <= 65|| i >= 72 && i <= 77
  							|| i >= 85 && i <= 89|| i >= 98 && i <= 101|| i == 111|| i == 112|| i == 113 || i == 124|| i == 125|| i == 137)
							{
									if 	((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  								(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 									{
		 										return TRUE;
		 									}

											else {FALSE;}	
					    }
					 }
		}
		
		if (lvl == 9)
		{
		for(i = 21 ; i < 182; ++i)
			if(i == 21 || i == 22 || i == 34 || i >= 36 && i <= 44 || i == 46 || i == 48 || i == 56 || i == 58 || i == 60 || i >= 62 && i <= 66 || i == 68 || i == 70 ||
						i == 72 || i == 74 || i == 78 || i == 80 || i == 82 || i == 84 || i == 86 || i >= 88 && i <= 90 || i == 92 || i == 94 || i == 96 || i == 98 ||
						i == 100 || i== 102 || i== 104 || i == 106 || i ==108 || i == 110 || i == 112 || i == 114 || i == 116 || i == 118 || i == 120 || i == 122 ||
						i >= 124 && i <= 126 || i == 128 || i == 130 || i == 132 || i == 134 || i == 140 || i == 142 || i == 144 || i == 146 || i == 152 || i == 154 || i == 156 ||
						i >= 158 && i <= 164 || i == 166 || i == 168 || i == 178 || i == 180 || i == 181)
			{
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else FALSE;	
			}
		}
		if (lvl == 10)
		{
		for(i = 50 ; i < 58; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

		 		else FALSE;	

  	for(i= 76; i < 164; ++i)
  		{
  			if(i >= 76 && i <= 79 || i == 87 || i == 92 || i == 98 || i >= 100 && i <= 103 || i == 105 || i == 109 || i == 111 || i == 113 ||i == 114 ||i == 116 ||i == 118 ||
  						i == 121 ||i == 123 ||i == 125 || i == 126 ||i == 128 ||i == 130 || i == 134 || i >= 136 && i <= 139 || i == 141 ||i == 147 ||i == 152 ||i >= 160 && i <= 163)
  						{
  							if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  					  (ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 							{
		 					     return TRUE;}
								else {FALSE;}
							}			 					  
  		}

		for(i = 182 ; i < 190; ++i)
				if ((ball.x <= block[i].xo + block[i].blwidth && block[i].xo <= ball.x + ball.width) && 
		  			(ball.y <= block[i].yo + block[i].blheight && block[i].yo <= ball.y + ball.height))
		 				{
		 					return TRUE;}

				else {FALSE;}

		}
}

printScore()
{
	score = score + 1;
	sprintf(SSCO, "ОЧКИ = %d", score);
	WPRINT (ANUM1, 136, MAXY1-30, SSCO);
}

blockCollision()
{
	int k;

	if(CollisionWall() == TRUE)
	{
		if((block[i].xo != 0) && (block[i].yo != 0))
		  {
		  	if (lvl == 1)
		  	{
	 			GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
				block[i].xo = 0; block[i].yo = 0;
				printScore();
				}
		  	else if (lvl == 2)
		  	{
		  			if(i >= 24 && i < 48)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								block[i].xo = 0; block[i].yo = 0;
							}
						
						else if(i >= 48 && i < 96)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);
								block[i].xo = 0; block[i].yo = 0;
							}
						else if(i >= 96 && i < 120)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								block[i].xo = 0; block[i].yo = 0;
							}	
							printScore();
				}	
		  	else if (lvl == 3)
		  	{
						if(i >= 12 && i < 36)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);
								block[i].xo = 0; block[i].yo = 0;
								printScore();
							}
						else if(i >= 37 && i < 47 || i >= 49 && i < 59)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								block[i].xo = 0; block[i].yo = 0;
								printScore();
							}
						else if(i >= 62 && i < 70 || i >= 74 && i < 82)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);
								block[i].xo = 0; block[i].yo = 0;
								printScore();
							}		
						else if(i >= 87 && i < 93 || i >= 99 && i < 105)
		  				{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    				GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								block[i].xo = 0; block[i].yo = 0;
								printScore();
							}		
  		      else if(i >= 112 && i < 116 || i >= 124 && i < 128)
  						{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);  							
  	    				block[i].xo = 0; block[i].yo = 0;
  						}														
				}
		  	else if (lvl == 4)
		  	{
		  		if(i >= 12 && i < 72)
		  				{
  					if(i == 12 || i ==14 ||i == 15 || i ==16 ||i == 18 || i ==19 ||i == 20 || i ==22 ||i == 24 || i ==26 ||i == 28 || i ==30 ||
  						i == 34 || i ==36 ||i == 38 || i ==39 ||i == 40 || i ==42 ||i == 43 || i ==44 ||i == 46 || i ==48 ||i == 52 || i ==54 ||
  						i == 56 || i ==58 ||i == 60 || i ==62 ||i == 63 || i ==64 ||i == 66 || i ==67 ||i == 68 || i ==70)
		  					{
	 							GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
								block[i].xo = 0; block[i].yo = 0;
								}	
						else 
								{
								GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								block[i].xo = 0; block[i].yo = 0;
								}							
							}
					printScore();
				}	
        TIMEOF();	
				CH0(193,17,16);
				TIMEON();
			}
	}	
}


ONEblockCollision()
{
	int k;

	if(CollWallOne() == TRUE || CollWTWO() == TRUE)
	{
		if((block[i].xo != 0) && (block[i].yo != 0))
		  {	
				if (lvl == 5)
						{
								if(i == 16 || i == 20 || i == 29 || i == 31 || i == 41 || i == 43)
  			  	    		{
	 							       GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);
								       block[i].xo = 0; block[i].yo = 0;
							      }	
							  else if(i == 52 || i == 53 || i == 54 || i == 55 || i == 56 || i == 64 || i == 65 || i == 66 || i == 67 || i == 68 ||
  			  							i == 75 || i == 76 || i == 78 || i == 80 || i == 81 || i == 87 || i == 88 || i == 90 || i == 92 || i == 93 || i == 98)
  			  	    		{
	 							       GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								       block[i].xo = 0; block[i].yo = 0;
							      }	

  			  	 		else if(i == 99 || i == 100 || i == 101 || i == 102 || i == 103 || i == 104 || i == 105 || i == 106 || i == 110 || i == 111
  			  	 						|| i == 112 || i == 113 || i == 114 || i == 115 || i == 116 || i == 117 || i == 118 || i == 122 || i == 124 || i == 125 || i == 126)
  			  	    		{
	 							       GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								       block[i].xo = 0; block[i].yo = 0;
							      }	

  			  	   	else if(i == 127 || i == 128 || i == 130 || i == 134 || i == 136 || i == 140 || i == 142 || i == 146 || i == 148 || i == 152 || i == 154
  			  	    				|| i == 161 || i == 163 || i == 173 || i == 175)
  			  	    		{
	 							       GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
								       block[i].xo = 0; block[i].yo = 0;
							      }	
							  else if(i == 77 || i == 79 || i == 89 || i == 91)
  			  	    		{
	 							       GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);
								       block[i].xo = 0; block[i].yo = 0;
							      }	
					printScore(); 				
				}	
				else if (lvl == 6)
				{
					if(i >= 24 && i < 120)
		  				{
  							if(i % 2 == 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
  	    					}
  	    				else
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
											block[i].xo = 0; block[i].yo = 0;
  	    					}
  	    		  }
  	    	printScore();
  	    }								
		  	else if (lvl == 7)
				{
					if(i >= 12 && i < 24)
		  				{
  							if(i % 2 == 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);	
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }
					if(i >= 24 && i < 36)
		  				{
  							if(i % 2 != 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }  
  	      if(i >= 36 && i < 48)
		  				{
  							if(i % 2 == 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }
					if(i >= 48 && i < 60)
		  				{
  							if(i % 2 != 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }
					if(i >= 60 && i < 72)
		  				{
  							if(i % 2 == 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }  
  	    	if(i >= 72 && i < 84)
		  				{
  							if(i % 2 != 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADGREY);
  	    							GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }	 
  	    	if(i >= 84 && i < 96)
		  				{
  							if(i % 2 == 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  } 
  	    	if(i >= 96 && i < 108)
		  				{
  							if(i % 2 != 0)
  								{
	 										GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
											block[i].xo = 0; block[i].yo = 0;
											printScore();
  	    					}
  	    		  }  		    	    	    		  
  	    }
		  	else if (lvl == 8)
		  	{
		  		  		if (i == 14 || i == 15|| i == 25|| i == 26|| i == 27|| i == 28|| i == 36|| i == 37|| i == 38|| i == 39|| i == 40|| i == 41|| i == 48
  							|| i == 49|| i == 50|| i == 51|| i == 52|| i == 53|| i == 60|| i == 61|| i == 62|| i == 63|| i == 64|| i == 65|| i == 72|| i == 73
  							|| i == 74|| i == 75|| i == 76|| i == 77|| i == 85|| i == 86|| i == 87|| i == 88|| i == 89|| i == 98|| i == 99|| i == 100|| i == 101
  			  			|| i == 111|| i == 112|| i == 113 || i == 124|| i == 125|| i == 137)
		  						{
	 									GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);
										block[i].xo = 0; block[i].yo = 0;
										printScore();
									}
								else if (i == 20|| i == 21|| i == 31|| i ==34 || i == 42 || i == 47|| i == 59 || i == 71|| i == 83|| i == 94
  							|| i == 105 || i == 116|| i == 127|| i == 138)
									{
										GRVR(IDENT, block[i].xo, block[i].yo, &ADRED);
										block[i].xo = 0; block[i].yo = 0;
									}
				}

		  	else if (lvl == 9)
		  	{
		  		if(i == 21 ||i == 22 || i == 34 || i >= 36 && i <= 44 || i == 46 || i == 48 || i == 56 || i == 58 || i == 60 || i >= 62 && i <= 66 || i == 68 || i == 70 ||
						i == 72 || i == 74 || i == 78 || i == 80 || i == 82 || i == 84 || i == 86 || i >= 88 && i <= 90 || i == 92 || i == 94 || i == 96 || i == 98 ||
						i == 100 || i== 102 || i== 104 || i == 106 || i ==108 || i == 110 || i == 112 || i == 114 || i == 116 || i == 118 || i == 120 || i == 122 ||
						i >= 124 && i <= 126 || i == 128 || i == 130 || i == 132 || i == 134 || i == 140 || i == 142 || i == 144 || i == 146 || i == 152 || i == 154 || i == 156 ||
						i >= 158 && i <= 164 || i == 166 || i == 168 || i == 178 || i == 180 || i == 181)
		  			{
	 						GRVR(IDENT, block[i].xo, block[i].yo, &ADYEL);
							block[i].xo = 0; block[i].yo = 0;
							printScore();
						}
		  	}
		  	else if (lvl == 10)
		  	{
  				if(i >= 76 && i <= 79 || i == 87 || i == 92 || i == 98 || i >= 100 && i <= 103 || i == 105 || i == 109 || i == 111 || i == 113 ||i == 114 ||i == 116 ||i == 118 ||
  				i == 121 ||i == 123 ||i == 125 || i == 126 ||i == 128 ||i == 130 || i == 134 || i >= 136 && i <= 139 || i == 141 ||i == 147 ||i == 152 ||i >= 160 && i <= 163)
  				{
  	    	GRVR(IDENT, block[i].xo, block[i].yo, &ADBLU);	
					block[i].xo = 0; block[i].yo = 0;
					printScore();
					}

				}

        TIMEOF();	
				CH0(193,17,16);
				TIMEON();

			}
	}	
}

start()
{	
	GCLRR (IDENT1); 
	lvlScreen(lvl);
	GCLRR (IDENT);
	GROP(IDENT, 2);

	BOX (IDENT, 1, 12, MAXX-3, MAXY-2);
	initBlock();
	srtRacket();
	srtBall();
	srtBYellow();
	srtBRed();
	srtBBlue();
	srtBGrey();
	putRacket();
	moveBall(racket.rx + racket.rwidth / 2 - 6, racket.ry - 12);
	putBall();
	OnePBlock(lvl);
	TwoPBlock(lvl);
	ThreePBlock(lvl);
	FourPBlock(lvl);
	FivePBlock(lvl);

  if (lvl >= 2 && lvl <= 5)
  	{
  		GPTRN(IDENT1,&PATTERNS[0][1]);
			GFILL(IDENT1,0,200);
 		}

 	PATTERNS[1][1]=4; PATTERNS[1][2]=2;
  PATTERNS[1][3]=0100200; PATTERNS[1][4]=0;

  if (lvl >= 7 && lvl <= 10 )
  	{
  		GPTRN(IDENT1,&PATTERNS[1][1]);
			GFILL(IDENT1,0,200);
 		}

 	lives = 99;
 	sprintf(SLIV, "ЖИЗНИ = %d", lives);
	WPRINT (ANUM1, 16, MAXY1-30, SLIV);
	score = 0;
	sprintf(SSCO, "ОЧКИ = %d", score);
	WPRINT (ANUM1, 136, MAXY1-30, SSCO);
}

lvlScreen(lvl)
{
  GCLRR (IDENT);
  GROP (IDENT, 0);
  if (lvl == 2)
  	{
  		MESSAGE ("                 восход   ");
  		PIC("02.GE5");
  		MUSIC();
  	}
  else if (lvl == 3)
  	{
  		MESSAGE ("                пирамида   ");
  		PIC("03.GE5");
  		MUSIC();
  	}
  else if (lvl == 4)
  	{
  		MESSAGE ("                загадка   ");
  		PIC("04.GE5");
  		MUSIC();
  	}
  else if (lvl == 5)
  	{
  		MESSAGE ("         космические захватчики   ");
  		PIC("05.GE5");
  		MUSIC();
  	}
  else if (lvl == 6)
  	{
  		MESSAGE ("            несокрушимые башни     ");
  		PIC("06.GE5");
  		MUSIC();
  	}  	
  else if (lvl == 7)
  	{
  		MESSAGE ("              звездные сети   ");
  		PIC("07.GE5");
  		MUSIC();
  	}
  else if (lvl == 8)
  	{
  		MESSAGE ("              романтичный   ");
  		PIC("08.GE5");
  		MUSIC();
  	}  
  else if (lvl == 9)
  	{
  		MESSAGE ("               лаберинт   ");
  		PIC("09.GE5");
  		MUSIC();
  	}	
  else if (lvl == 10)
  	{
  		MESSAGE ("               новый мир   ");
  		PIC("10.GE5");
  		MUSIC();
  	}
	GETCHH();
  VWKILL(&VW);
  GKILL(IDENT2);
  PLFRE(&PAL);
}

lvlscore()
{
	++lvl;
	lives = 99;
	score = 0;
	start();
	run = FALSE;
	ball.alfa = - 1.9;
}


ARKANOID()
{
	GCLRR(IDENT);
	PAL.PMODPAL=MODP;
	PLSAV (&PAL);
	tmp=PAL.PAL[15];
	PLMOD(&PAL);
	PAL.PAL[15]=tmp;
	PLMOD(&PAL); 
	GROP(IDENT, 2);

	MANUAL();

	BOX (IDENT, 1, 12, MAXX-3, MAXY-2);
	MESSAGE ("              зеленый старт   ");
	initRacket();
	initBall();
	initBlock();
	srtRacket();
	srtBall();
	srtBYellow();
	srtBRed();
	srtBBlue();
	srtBGrey();
	putRacket();
	moveBall(racket.rx + racket.rwidth / 2 - 6, racket.ry - 12);
	putBall();
	lvl = 1;
	OnePBlock(lvl);

  PATTERNS[0][1]=8; PATTERNS[0][2]=8;
  PATTERNS[0][3]=0; PATTERNS[0][4]=14;
  PATTERNS[0][5]=0; PATTERNS[0][6]=030;
  PATTERNS[0][7]=0; PATTERNS[0][8]=01000;
  PATTERNS[0][9]=0; PATTERNS[0][10]=020000;
  PATTERNS[0][11]=14; PATTERNS[0][12]=0;
  PATTERNS[0][13]=030; PATTERNS[0][14]=0;
  PATTERNS[0][15]=01000; PATTERNS[0][16]=0;
  PATTERNS[0][17]=020000; PATTERNS[0][18]=0;

  GPTRN(IDENT1,&PATTERNS[0][1]);
	GFILL(IDENT1,0,120);

	
 	  lives = 99;
 	  sprintf(SLIV, "ЖИЗНИ = %d", lives);
	  WPRINT (ANUM1, 16, MAXY1-30, SLIV);

	  score = 0;
	  sprintf(SSCO, "ОЧКИ = %d", score);
	  WPRINT (ANUM1, 136, MAXY1-30, SSCO);
		
		run = FALSE;
		while (TRUE) {

				if (run == TRUE)
				{
					 dx = ball.x;
					 dy = ball.y; 
					 autoMoveBall();
					 putBall();
					 delBall(dx,dy);		 

				   if (ball.y >= MAXY)
				   {
					 moveBall(racket.rx + racket.rwidth / 2 - 6, racket.ry - 12);
					 putBall();
					 lives = lives - 1;
					 run = FALSE;
				   }
				   
				   if(lvl == 1)
				   {
				   		if(score >= 60)
				   			{
				   				lvlscore();
				   			}
				   	}
				   else if(lvl == 2)
				   {
				   		if(score >= 96)
				   			{
				   				lvlscore();
				   			}
				   	}
				   else if(lvl == 3)
				   {
				   		if(score >= 72)
				   			{
				   				lvlscore();
				   			}
				   	}
				   else if(lvl == 4)
				   {
				   		if(score >= 60)
				   			{
				   				lvlscore();
				   			}
				   	}
				  else if(lvl == 5)
				   {
				   		if(score >= 67)
				   			{
				   				lvlscore();
				   			}
				   	}
				  else if(lvl == 6)
				   {
				   		if(score >= 96)
				   			{
				   				lvlscore();
				   			}
				   	}
				  else if(lvl == 7)
				   {
				   		if(score >= 48)
				   			{
				   				lvlscore();
				   			}
				   	}	
				  else if(lvl == 8)
				   {
				   		if(score >= 45)
				   			{
				   				lvlscore();
				   			}
				   	}	
				  else if(lvl == 9)
				   {
				   		if(score >= 76)
				   			{
				   				lvlscore();
				   			}
				   	}
				  else if(lvl == 10)
				   {
				   		if(score >= 36)
				   		{
				   			lvl = 11;
				   			break;
				   		}
				   	}				   					   				   				   					   	
				}
				if (run == FALSE)
				{
					sprintf(SLIV, "ЖИЗНИ = %d", lives);
	        WPRINT (ANUM1, 16, MAXY1-30, SLIV);
	      	if(lives <= 0) break;
					if (KEYPRESSED()) {
					key = GETCHH();
					if (key == 060) break;
					else if (key == 0103) {
						putRacket();
						putBall();
						moveRacket(racket.rx + 9);
						putRacket();
						moveBall(racket.rx + racket.rwidth / 2 - 6, racket.ry - 12);
						putBall();
					}	
					else if (key == 0104) {
						putRacket();
						putBall();
						moveRacket(racket.rx - 9);
						putRacket();
						moveBall(racket.rx + racket.rwidth / 2 - 6, racket.ry - 12);
						putBall();
					}	
					else if (key == 040) run = TRUE;
					else continue;
		    	}
		   }			    
	}	
}
/*-------------------------------------------------*/
GAMEOVER()
{

	int i;
	GCLRR (IDENT1);
  GCLRR (IDENT);
  GROP (IDENT, 0);

  	if (lvl != 11) 
  		{
  		MESSAGE ("           Миссия провалена   ");
			PIC("GO.GE5");
			PAUSE(300);
			GKILL (IDENT);
			}
		else 
			{
				GKILL (IDENT);
				PAL.PMODPAL=MODP;
				PLSAV (&PAL);
				tmp=PAL.PAL[15];
				PLMOD(&PAL);
				PAL.PAL[15]=tmp;
				PLMOD(&PAL); 
				GROP(IDENT1, 2);
				MESSAGE ("       Миссия завершина успешно! ");

				FINETEXT ("   Игра Арканоид создана в 2024 г., автор ",
					        "   Александр Ермаков (potetino@gmail.com),",
					        "   консультант А.Кислый, BeginEnd, графика",
					        "   создана нейросетью app.leonardo.ia     ");
				GRVR(IDENT1,170,100,&BLGREY);
				PAUSE(2000);
			}
	VWKILL(&VW);
	*KEYB |= 0100;
	GCLRR (IDENT1);
	PAL1.PAL[15]=COLOR;
	PLMOD (&PAL1);
	GKILL (IDENT1);	
}
/*-------------------------------------------------*/
main()
{
	INIT();
	TITUL();
	ARKANOID();
	GAMEOVER();
}

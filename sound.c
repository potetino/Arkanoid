#define sndc0r (*(int*)0161010)
#define sndc1r (*(int*)0161012)
#define sndc2r (*(int*)0161014)
#define sndcsr (*(int*)0161016)

#define snlc0r (*(int*)0161020)
#define snlc1r (*(int*)0161022)
#define snlc2r (*(int*)0161024)
#define snlcsr (*(int*)0161026)

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
static int i;
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

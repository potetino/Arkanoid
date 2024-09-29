/***************************************************************
		    B I O S . H        20.01.1989
****************************************************************/

#define INT_    int *
#define UNS     unsigned
#define CHAR_	char *

#define	DESP_	struct PRODES *
#define	DESS_	struct SEM *

/****************************************************************/

struct	PRODES	{
		DESP_	PSUCC;
		DESP_	PPRED;
		int	PR0, PR1, PR2, PR3, PR4, PR5, PSP, PPC, PPS;
		int	PUR0, PUR1, PUR2, PUR3, PUR4, PUR5, PUR6, PUR7;
		UNS	PMASK;
		DESP_	PCPRC;
		int	PTIM;
		int	PPRI;
		INT_	PMEM;
		char	PNAME[16];
		UNS	PTIM0, PTIM1;
		DESP_	PDSUCC;
		};

struct	REGDES	{
		UNS	RREG;
		UNS	RMASK;
		int	RCOPY;
		char	RSTAT;
		char	RRQST;
		DESP_	RPROC;
		UNS	RSTRT;
		int	RRESE;
		};

struct	SEM	{
		int	SCNTR;
		INT_	SFRST;
		DESP_	SSUCC;
		DESP_	SPRED;
		};

/****************************************************************/

#undef	DESS_
#undef	DESP_

/****************************************************************/

#define	PAL_	struct PALTYP *
#define	ARE_	struct ARETUP *
#define	FONT_	struct FNTTYP *
#define	WIN_	struct WINTYP *

/****************************************************************/

struct	PALTYP	{
		int	PCODE;
		int	PMODPAL;
		char	PAL[16];
		};

struct	ARETYP	{
		int	ACODE;
		int	ANUM;
		int	LINS;
		int	SLEN;
		int	MODPAL;
		};

struct  WINTYP	{
		int	WCODE;
		int	WNUM;
		int	AREA;
		int	ARY;
		int	ARX;
		int	SY1;
		int	SY2;
		int	SX1;
		int	SX2;
		int	DEN;
		};

struct  FNTYP	{
		int	FCODE;
		int	PAR;
		char	FNNAME[20];
		};

/****************************************************************/

#define	VM1		0
#define	VM2		1
#define	VM40		2
#define	VM41		3

#define	PL0		0
#define	PL1		0x4000
#define	PL2		0x8000
#define	PL3		0xB000

#define	VMASK		0x80
#define	VDX		0x40
#define	VDY		0x20
#define	VVP		0x18
#define	VVV		0x10
#define	VPV		0x08
#define	VCV		0x00

#define	VBIC		6
#define	VBIS		4
#define	VXOR		2
#define	VBYTE		1
#define	VMOV		0

/****************************************************************/

#undef	PAL_
#undef	ARE_
#undef	FONT_
#undef	WIN_

#undef  CHAR_
#undef  INT_
#undef  UNS

/***************************************************************
end of header           B I O S  . H
****************************************************************/

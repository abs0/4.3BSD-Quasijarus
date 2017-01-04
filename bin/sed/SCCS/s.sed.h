h38358
s 00023/00032/00131
d D 4.3 87/12/21 12:27:50 bostic 3 2
c make ANSI C compatible
e
s 00001/00001/00162
d D 4.2 87/09/16 13:42:34 bostic 2 1
c allocate space for file names; bug report 4.3BSD/bin/64
e
s 00163/00000/00000
d D 4.1 85/04/05 09:29:13 ralph 1 0
c date and time created 85/04/05 09:29:13 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * sed -- stream  editor
 */

#define CBRA	1
#define	CCHR	2
#define	CDOT	4
#define	CCL	6
#define	CNL	8
#define	CDOL	10
#define	CEOF	11
#define CKET	12
#define CNULL	13
#define CLNUM	14
#define CEND	16
#define CDONT	17
#define	CBACK	18

#define	STAR	01

#define NLINES	256
#define	DEPTH	20
#define PTRSIZE	200
#define RESIZE	10000
#define	ABUFSIZE	20
#define	LBSIZE	4000
#define	ESIZE	256
#define	LABSIZE	50
#define NBRA	9

FILE	*fin;
D 3
union reptr	*abuf[ABUFSIZE];
union reptr **aptr;
E 3
I 3
struct reptr	*abuf[ABUFSIZE];
struct reptr **aptr;
E 3
char	*lastre;
char	ibuf[BUFSIZ];
char	*cbp;
char	*ebp;
char	genbuf[LBSIZE];
char	*loc1;
char	*loc2;
char	*locs;
char	seof;
char	*reend;
char	*lbend;
char	*hend;
char	*lcomend;
D 3
union reptr	*ptrend;
E 3
I 3
struct reptr	*ptrend;
E 3
int	eflag;
int	dolflag;
int	sflag;
int	jflag;
int	numbra;
int	delflag;
long	lnum;
char	linebuf[LBSIZE+1];
char	holdsp[LBSIZE+1];
char	*spend;
char	*hspend;
int	nflag;
int	gflag;
char	*braelist[NBRA];
char	*braslist[NBRA];
long	tlno[NLINES];
int	nlno;
D 2
char	fname[12][40];
E 2
I 2
char	*fname[12];
E 2
FILE	*fcode[12];
int	nfiles;

#define ACOM	01
#define BCOM	020
#define CCOM	02
#define	CDCOM	025
#define	CNCOM	022
#define COCOM	017
#define	CPCOM	023
#define DCOM	03
#define ECOM	015
#define EQCOM	013
#define FCOM	016
#define GCOM	027
#define CGCOM	030
#define HCOM	031
#define CHCOM	032
#define ICOM	04
#define LCOM	05
#define NCOM	012
#define PCOM	010
#define QCOM	011
#define RCOM	06
#define SCOM	07
#define TCOM	021
#define WCOM	014
#define	CWCOM	024
#define	YCOM	026
#define XCOM	033

char	*cp;
char	*reend;
char	*lbend;

D 3
union	reptr {
	struct reptr1 {
		char	*ad1;
		char	*ad2;
		char	*re1;
		char	*rhs;
		FILE	*fcode;
		char	command;
		char	gfl;
		char	pfl;
		char	inar;
		char	negfl;
	} A;
	struct reptr2 {
		char	*ad1;
		char	*ad2;
		union reptr	*lb1;
		char	*rhs;
		FILE	*fcode;
		char	command;
		char	gfl;
		char	pfl;
		char	inar;
		char	negfl;
	} B;
E 3
I 3
struct	reptr {
	char	*ad1;
	char	*ad2;
	union {
		char	*real_re1;
		struct reptr	*real_lb1;
	} re_lb;
#define	re1	re_lb.real_re1
#define	lb1	re_lb.real_lb1
	char	*rhs;
	FILE	*fcode;
	char	command;
	char	gfl;
	char	pfl;
	char	inar;
	char	negfl;
E 3
} ptrspace[PTRSIZE], *rep;


char	respace[RESIZE];

struct label {
	char	asc[9];
D 3
	union reptr	*chain;
	union reptr	*address;
E 3
I 3
	struct reptr	*chain;
	struct reptr	*address;
E 3
} ltab[LABSIZE];

struct label	*lab;
struct label	*labend;

int	f;
int	depth;

int	eargc;
char	**eargv;

extern	char	bittab[];

D 3
union reptr	**cmpend[DEPTH];
E 3
I 3
struct reptr	**cmpend[DEPTH];
E 3
int	depth;
D 3
union reptr	*pending;
E 3
I 3
struct reptr	*pending;
E 3
char	*badp;
char	bad;
char	*compile();
char	*ycomp();
char	*address();
char	*text();
char	*compsub();
struct label	*search();
char	*gline();
char	*place();
char	compfl;
E 1

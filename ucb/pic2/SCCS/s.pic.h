h19610
s 00004/00004/00169
d D 3.1 85/07/30 15:05:35 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00093/00053/00080
d D 2.1 85/07/23 11:20:29 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00133/00000/00000
d D 1.1 85/07/19 13:59:17 jaap 1 0
c date and time created 85/07/19 13:59:17 by jaap
e
u
U
t
T
I 1
D 2
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint

E 2
#define	dprintf	if(dbg)printf
I 3
#ifndef PI
#define	PI	3.141592654
#endif
E 3

I 2
#define	DEFAULT	0

E 2
#define	HEAD1	1
#define	HEAD2	2
#define	HEAD12	(HEAD1+HEAD2)
#define	INVIS	4
#define	CW_ARC	8	/* clockwise arc */
I 2
D 3
#ifndef PI
E 2
#define	PI	3.141592654
D 2
#define	PI2	PI/2
E 2
I 2
#endif
E 3
#define	DOTBIT	16
#define	DASHBIT	32

#define	CENTER	01	/* text attributes */
#define	LJUST	02
#define	RJUST	04
#define	ABOVE	010
#define	BELOW	020
#define	SPREAD	040
#define	FILL	0100

E 2
#define	SCALE	1.0	/* default scale: units/inch */
#define	WID	0.75	/* default width for boxes and ellipses */
#define	WID2	0.375
#define	HT	0.5	/* default height and line length */
#define	HT2	0.25	/* because no floating init exprs! */
#define	HT5	0.1
#define	HT10	0.05

D 2
#define	MAXOBJ	1200
#define	MAXTEXT	1200
#define	SYMTAB	200
#define	DEV202	1
#define	DEVAPS	2
#define	DEVCAT	3
#define	DEV450	4
#define	DEVVER	5
#define	DEVHAR	6

E 2
/* these have to be like so, so that we can write */
/* things like R & V, etc. */
#define	H	0
#define	V	1
#define	R_DIR	0
#define	U_DIR	1
#define	L_DIR	2
#define	D_DIR	3
#define	ishor(n)	(((n) & V) == 0)
#define	isvert(n)	(((n) & V) != 0)
#define	isright(n)	((n) == R_DIR)
#define	isleft(n)	((n) == L_DIR)
#define	isdown(n)	((n) == D_DIR)
#define	isup(n)		((n) == U_DIR)

D 2
typedef union {		/* the yacc stack type */
	int	i;
	char	*p;
	struct obj *o;
	float	f;
} YYSTYPE;

extern	YYSTYPE	yylval, yyval;

struct attr {	/* attribute of an object */
	int	a_type;
	YYSTYPE	a_val;
E 2
I 2
typedef struct Point {
	float	x;
	float	y;
E 2
};

D 2
struct obj {	/* stores various things in variable length */
E 2
I 2
typedef struct obj {	/* stores various things in variable length */
E 2
	int	o_type;
	int	o_count;	/* number of things */
	int	o_nobj;		/* index in objlist */
	int	o_mode;		/* hor or vert */
D 2
	float	o_x;	/* coord of "center" */
E 2
I 2
	float	o_x;		/* coord of "center" */
E 2
	float	o_y;
D 2
	int	o_nt1;	/* 1st index in text[] for this object */
	int	o_nt2;	/* 2nd; difference is #text strings */
	int	o_attr;	/* various attributes of interest */
	int	o_dotdash;	/* kludge in a dot/dash mode */
E 2
I 2
	int	o_nt1;		/* 1st index in text[] for this object */
	int	o_nt2;		/* 2nd; difference is #text strings */
	int	o_attr;		/* HEAD, CW, INVIS go here */
	int	o_size;		/* linesize */
	int	o_nhead;	/* arrowhead style */
	struct symtab *o_symtab; /* symtab for [...] */
E 2
	float	o_ddval;	/* value of dot/dash expression */
	float	o_val[1];	/* actually this will be > 1 in general */
				/* type is not always FLOAT!!!! */
D 2
};
E 2
I 2
} obj;
E 2

I 2
typedef union {		/* the yacc stack type */
	int	i;
	char	*p;
	obj	*o;
	float	f;
} YYSTYPE;

extern	YYSTYPE	yylval, yyval;

E 2
struct symtab {
	char	*s_name;
	int	s_type;
	YYSTYPE	s_val;
	struct symtab *s_next;
};

D 2
struct text {
	int	t_type;
E 2
I 2
typedef struct {	/* attribute of an object */
	int	a_type;
	int	a_sub;
	YYSTYPE	a_val;
} Attr;

typedef struct {
	int	t_type;		/* CENTER, LJUST, etc. */
	char	t_op;		/* optional sign for size changes */
	char	t_size;		/* size, abs or rel */
E 2
	char	*t_val;
D 2
};
E 2
I 2
} Text;
E 2

I 2
#define	String	01
#define	Macro	02
#define	File	04
#define	Char	010
#define	Thru	020
#define	Free	040

typedef struct {	/* input source */
	int	type;	/* Macro, String, File */
	char	*sp;	/* if String or Macro */
} Src;

extern	Src	src[], *srcp;	/* input source stack */

typedef struct {
	FILE	*fin;
	char	*fname;
	int	lineno;
} Infile;

extern	Infile	infile[], *curfile;

#define	MAXARGS	20
typedef struct {	/* argument stack */
	char	*argstk[MAXARGS];	/* pointers to args */
	char	*argval;	/* points to space containing args */
} Arg;

E 2
extern	int	dbg;
D 2
extern	struct	obj	*objlist[];
extern	int	nobj;
extern	struct	attr	attr[];
extern	int	nattr;
extern	struct	text	text[];
E 2
I 2
extern	obj	**objlist;
extern	int	nobj, nobjlist;
extern	Attr	*attr;
extern	int	nattr, nattrlist;
extern	Text	*text;
extern	int	ntextlist;
E 2
extern	int	ntext;
extern	int	ntext1;
extern	float	curx, cury;
extern	int	hvmode;
extern	int	codegen;
D 2
extern	char	*malloc(), *tostring();
E 2
I 2
extern	char	*malloc(), *realloc(), *tostring(), *grow();
E 2
D 3
extern	float	getfval(), getcomp();
E 3
I 3
extern	float	getfval(), getcomp(), getblkvar();
E 3
extern	YYSTYPE	getvar();
extern	struct symtab *lookup(), *makevar();
I 2
extern	char	*ifstat(), *delimstr(), *sprintgen();
E 2

extern	float	deltx, delty;
extern	int	lineno;
extern	int	synerr;
D 2
extern	int	crop;
extern	int	devtype, res, DX, DY;
E 2

D 2
extern	float	sxmin, sxmax, symin, symax;
E 2
extern	float	xmin, ymin, xmax, ymax;
D 2
extern	struct obj *leftthing(), *boxgen(), *circgen(), *arcgen();
extern	struct obj *linegen(), *splinegen(), *movegen(), *textgen();
extern	struct obj *troffgen(), *rightthing(), *blockgen();
extern	struct	obj *makenode(), *makepos(), *fixpos(), *makebetween();
extern	struct	obj *getpos(), *gethere(), *getfirst(), *getlast(), *getblock();
E 2
I 2
extern	obj	*leftthing(), *boxgen(), *circgen(), *arcgen();
extern	obj	*linegen(), *splinegen(), *movegen(), *textgen(), *plotgen();
extern	obj	*troffgen(), *rightthing(), *blockgen();
extern	obj	*makenode(), *makepos(), *fixpos(), *addpos(), *subpos(), *makebetween();
extern	obj	*getpos(), *gethere(), *getfirst(), *getlast(), *getblock();
E 2

struct pushstack {
	float	p_x;
	float	p_y;
	int	p_hvmode;
	float	p_xmin;
	float	p_ymin;
	float	p_xmax;
	float	p_ymax;
	struct symtab *p_symtab;
};
extern	struct pushstack stack[];
extern	int	nstack;
D 2
extern int cw;
E 2
I 2
extern	int	cw;
E 2

D 2
extern float atof();
E 2
I 2
extern	double	errcheck();
#define	Log10(x) errcheck(log10(x), "log")
#define	Exp(x)	errcheck(exp(x), "exp")
#define	Sqrt(x)	errcheck(sqrt(x), "sqrt")
E 2
E 1

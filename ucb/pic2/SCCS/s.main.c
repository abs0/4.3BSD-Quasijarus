h13162
s 00002/00001/00257
d D 3.1 85/07/30 15:04:55 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00129/00143/00129
d D 2.1 85/07/23 11:20:01 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00272/00000/00000
d D 1.1 85/07/19 13:58:55 jaap 1 0
c date and time created 85/07/19 13:58:55 by jaap
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint
I 3

E 3
D 2

E 2
#include	<stdio.h>
I 2
#include	<signal.h>
E 2
#include	"pic.h"
#include	"y.tab.h"

D 2
struct	obj	*objlist[MAXOBJ];	/* store the elements here */
E 2
I 2
obj	**objlist = 0;	/* store the elements here */
int	nobjlist = 0;		/* size of objlist array */
E 2
int	nobj	= 0;

D 2
struct attr	attr[40];	/* attributes stored here as collected */
E 2
I 2
D 3
Attr	*attr;	/* attributes stored here as collected */
E 3
I 3
Attr	*attr;	/*;attributes stored here as collected */
E 3
int	nattrlist = 0;
E 2
int	nattr	= 0;	/* number of entries in attr_list */

D 2
struct	text	text[MAXTEXT];	/* text strings stored here as collected */
E 2
I 2
Text	*text	= 0;	/* text strings stored here as collected */
int	ntextlist = 0;		/* size of text[] array */
E 2
int	ntext	= 0;
int	ntext1	= 0;	/* record ntext here on entry to each figure */

float	curx	= 0;
float	cury	= 0;

int	hvmode	= R_DIR;	/* R => join left to right, D => top to bottom, etc. */

int	codegen	= 0;	/* 1=>output for this picture; 0=>no output */

float	deltx	= 6;	/* max x value in output, for scaling */
float	delty	= 6;	/* max y value in output, for scaling */
int	dbg	= 0;
D 2
extern	FILE	*yyin,	/* input file pointer */
		*skeldb; /* output pointer for dbg messeges */
E 2
int	lineno	= 0;
char	*filename	= "-";
int	synerr	= 0;
char	*cmdname;
D 2
int	crop	= 1;	/* trim off exterior white space if non-zero */
extern int	useDline;	/* if set, use \D for all lines */
E 2

D 2
/* You may want to change this if you don't have a 202... */

/*
 *#ifdef	APS
 *	int	devtype	= DEVAPS;
 *	int	res	= 723;
 *	int	DX	= 3;
 *	int	DY	= 3;
 *
 *#ifdef 202
 *	int	devtype	= DEV202;
 *	int	res	= 972;	/* default is 202 *
 *	int	DX	= 4;	/* used only for old-style troff *
 *	int	DY	= 4;
 */
#ifdef OLDTROFF
/* mandatory values for graphic systems CAT: */
int	devtype = DEVCAT;
int	res	= 432;
int	DX = 3;
int	DY = 3;
#else
	int	devtype	= DEVHAR;
	int	res	= 1445;	/* default is HARRIS */
	int	DX	= 4;	/* used only for old-style troff */
	int	DY	= 4;
#endif

float	hshift	= 0;	/* move this far left for text (in em's) */
float	vshift	= 0.2;	/* this far down */

float	sxmin;		/* lower limit from s command */
float	symin;
float	sxmax	= 4096;	/* upper */
float	symax	= 4096;

E 2
float	xmin	= 30000;	/* min values found in actual data */
float	ymin	= 30000;
float	xmax	= -30000;	/* max */
float	ymax	= -30000;

main(argc, argv)
D 2
	char **argv;
E 2
I 2
	char *argv[];
E 2
{
I 2
	char buf[20];
	extern int fpecatch();

	signal(SIGFPE, fpecatch);
E 2
	cmdname = argv[0];
	while (argc > 1 && *argv[1] == '-') {
		switch (argv[1][1]) {
D 2
		case 'T':
			if (strcmp(&argv[1][2], "aps") == 0) {
				res = 723;
				devtype = DEVAPS;
				DX = DY = 1;
			} else if (strcmp(&argv[1][2], "cat") == 0) {
				res = 432;
				devtype = DEVCAT;
				DX = DY = 3;
			} else if (strcmp(&argv[1][2], "ver") == 0) {
				res = 200;
				devtype = DEVVER;
				DX = DY = 1;
			} else if (strcmp(&argv[1][2], "450") == 0) {
				res = 240;
				devtype = DEV450;
			} else if (strcmp(&argv[1][2], "har") == 0) {
				res = 1445;
				devtype = DEVHAR;
			} else {
				res = atoi(&argv[1][2]);
			}
			break;
E 2
		case 'd':
D 2
			dbg = 1;
E 2
I 2
			dbg = atoi(&argv[1][2]);
			if (dbg == 0)
				dbg = 1;
E 2
			break;
D 2
		case 'D':
#			ifdef OLDTROFF
			useDline = !useDline;
#			endif
			break;
E 2
		}
		argc--;
		argv++;
	}
D 2
#	ifndef OLDTROFF
	useDline = 1;
#	endif
#
E 2
	setdefaults();
I 2
	objlist = (obj **) grow(objlist, "objlist", nobjlist += 1000, sizeof(obj *));
	text = (Text *) grow(text, "text", ntextlist += 1000, sizeof(Text));
	attr = (Attr *) grow(attr, "attr", nattrlist += 100, sizeof(Attr));

	sprintf(buf, "/%d/", getpid());
	pushsrc(String, buf);
	definition("pid");

	pushsrc(File, curfile = infile);
E 2
	if (argc <= 1) {
D 2
		yyin = stdin;
		getdata(yyin);
E 2
I 2
		curfile->fin = stdin;
		curfile->fname = tostring("-");
		getdata(curfile);
E 2
	} else
		while (argc-- > 1) {
D 2
			if ((yyin = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "pic: can't open %s\n", *argv);
E 2
I 2
			if ((curfile->fin = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", cmdname, *argv);
E 2
				exit(1);
			}
D 2
			filename = *argv;
			getdata(yyin);
			fclose(yyin);
E 2
I 2
			curfile->fname = tostring(*argv);
			getdata(curfile);
			fclose(curfile->fin);
			free(curfile->fname);
E 2
		}
	exit(0);
}

I 2
fpecatch()
{
	fatal("floating point exception");
}

char *grow(ptr, name, num, size)	/* make array bigger */
	char *ptr, *name;
	int num, size;
{
	char *p;

	if (ptr == NULL)
		p = malloc(num * size);
	else
		p = realloc(ptr, num * size);
	if (p == NULL)
		fatal("can't grow %s to %d", name, num * size);
	return p;
}

E 2
static struct {
	char *name;
	float val;
I 2
	short scalable;		/* 1 => adjust when "scale" changes */
E 2
} defaults[] ={
D 2
	"scale", SCALE,
	"lineht", HT,
	"linewid", HT,
	"moveht", HT,
	"movewid", HT,
	"dashwid", HT10,
	"boxht", HT,
	"boxwid", WID,
	"circlerad", HT2,
	"arcrad", HT2,
	"ellipseht", HT,
	"ellipsewid", WID,
	"arrowht", HT5,
	"arrowwid", HT10,
	"textht", HT,
	"textwid", WID,
E 2
I 2
	"scale", SCALE, 1,
	"lineht", HT, 1,
	"linewid", HT, 1,
	"moveht", HT, 1,
	"movewid", HT, 1,
	"dashwid", HT10, 1,
	"boxht", HT, 1,
	"boxwid", WID, 1,
	"circlerad", HT2, 1,
	"arcrad", HT2, 1,
	"ellipseht", HT, 1,
	"ellipsewid", WID, 1,
	"arrowht", HT5, 1,
	"arrowwid", HT10, 1,
	"arrowhead", 2, 0,		/* arrowhead style */
	"textht", 0.0, 1,		/* 6 lines/inch is also a useful value */
	"textwid", 0.0, 1,
E 2
	NULL, 0
};

setdefaults()	/* set default sizes for variables like boxht */
{
	int i;
	YYSTYPE v;

	for (i = 0; defaults[i].name != NULL; i++) {
		v.f = defaults[i].val;
		makevar(tostring(defaults[i].name), VARNAME, v);
	}
}

I 2
resetvar()	/* reset variables listed */
{
	int i, j;
E 2

I 2
	if (nattr == 0) {	/* none listed, so do all */
		setdefaults();
		return;
	}
	for (i = 0; i < nattr; i++) {
		for (j = 0; defaults[j].name != NULL; j++)
			if (strcmp(defaults[j].name, attr[i].a_val.p) == 0) {
				setfval(defaults[j].name, defaults[j].val);
				free(attr[i].a_val.p);
				break;
			}
	}
}

E 2
checkscale(s)	/* if s is "scale", adjust default variables */
	char *s;
{
	int i;
	float scale;

	if (strcmp(s, "scale") == 0) {
		scale = getfval("scale");
		for (i = 1; defaults[i].name != NULL; i++)
D 2
			setfval(defaults[i].name, defaults[i].val * scale);
E 2
I 2
			if (defaults[i].scalable)
				setfval(defaults[i].name, defaults[i].val * scale);
E 2
	}
}

D 2
getdata(fin)
	register FILE *fin;
E 2
I 2
getdata()
E 2
{
D 2
	char buf[1000], buf1[50];
	FILE *svyyin;
	int svlineno;
	char *svfilename, *p;
E 2
I 2
	char *p, buf[1000], buf1[100];
	int ln;
E 2

D 2
	lineno = 0;
	while (fgets(buf, sizeof buf, fin) != NULL) {
		lineno++;
E 2
I 2
	curfile->lineno = 0;
	printf(".lf 1 %s\n", curfile->fname);
	while (fgets(buf, sizeof buf, curfile->fin) != NULL) {
		curfile->lineno++;
E 2
		if (*buf == '.' && *(buf+1) == 'P' && *(buf+2) == 'S') {
			for (p = &buf[3]; *p == ' '; p++)
				;
			if (*p++ == '<') {
D 2
				svyyin = yyin;
				svlineno = lineno;
				svfilename = filename;
E 2
I 2
				Infile svfile;
				svfile = *curfile;
E 2
				sscanf(p, "%s", buf1);
D 2
				if ((yyin = fopen(buf1, "r")) == NULL) {
					fprintf(stderr, "pic: can't open %s\n", buf1);
					exit(1);
				}
				lineno = 0;
				filename = p;
				getdata(yyin);
				fclose(yyin);
				lineno = svlineno;
				yyin = svyyin;
				filename = svfilename;
E 2
I 2
				if ((curfile->fin=fopen(buf1, "r")) == NULL)
					fatal("can't open %s", buf1);
				curfile->fname = tostring(buf1);
				getdata();
				fclose(curfile->fin);
				free(curfile->fname);
				*curfile = svfile;
				printf(".lf %d %s\n", curfile->lineno, curfile->fname);
E 2
				continue;
			}
			reset();
			yyparse();
D 2
			/* yylval now contains 'E' or 'F' from .PE or .PF */
			if (buf[3] == ' ')	/* assume next thing is width */
				deltx = delty = atof(&buf[4]);
			else {
				deltx = xmax - xmin;
				if (deltx <= 0)
					deltx = ymax - ymin;
				deltx /= getfval("scale");
				delty = deltx;
E 2
I 2
			/* yylval.i now contains 'E' or 'F' from .PE or .PF */

			deltx = (xmax - xmin) / getfval("scale");
			delty = (ymax - ymin) / getfval("scale");
			if (buf[3] == ' ') {	/* next things are wid & ht */
				if (sscanf(&buf[4],"%f%f",&deltx,&delty) < 2)
					delty = deltx * (ymax-ymin) / (xmax-xmin);
E 2
			}
D 2
			dprintf("deltx = %.3f\n", deltx);
E 2
I 2
			dprintf("deltx = %g, delty = %g\n", deltx, delty);
E 2
			if (codegen && !synerr) {
				openpl(&buf[3]);	/* puts out .PS, with ht & wid stuck in */
I 2
				printf(".lf %d\n", curfile->lineno+1);
E 2
				print();	/* assumes \n at end */
D 2
				closepl(yylval.p);	/* does the .PE/F */
E 2
I 2
				closepl(yylval.i);	/* does the .PE/F */
E 2
			}
I 2
			printf(".lf %d\n", curfile->lineno+1);
E 2
			fflush(stdout);
D 2
		}
		else
E 2
I 2
		} else if (buf[0] == '.' && buf[1] == 'l' && buf[2] == 'f') {
			if (sscanf(buf+3, "%d %s", &ln, buf1) == 2) {
				free(curfile->fname);
				printf(".lf %d %s\n", curfile->lineno = ln, curfile->fname = tostring(buf1));
			} else
				printf(".lf %d\n", curfile->lineno = ln);
		} else
E 2
			fputs(buf, stdout);
	}
}

reset()
{
D 2
	struct obj *op;
E 2
I 2
	obj *op;
E 2
	int i;
	struct symtab *p;
	extern int nstack;

	for (i = 0; i < nobj; i++) {
		op = objlist[i];
		if (op->o_type == BLOCK)
D 2
			freesymtab(op->o_dotdash);	/* funny place */
E 2
I 2
			freesymtab(op->o_symtab);
E 2
		free(objlist[i]);
	}
	nobj = 0;
	nattr = 0;
	for (i = 0; i < ntext; i++)
D 2
		free(text[i].t_val);
E 2
I 2
		if (text[i].t_val)
			free(text[i].t_val);
E 2
	ntext = ntext1 = 0;
	codegen = synerr = 0;
	nstack = 0;
	curx = cury = 0;
	hvmode = R_DIR;
D 2
	sxmin = symin = 0;
	sxmax = symax = 4096;
E 2
	xmin = ymin = 30000;
	xmax = ymax = -30000;
}
E 1

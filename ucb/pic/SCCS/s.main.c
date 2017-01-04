h59407
s 00004/00000/00266
d D 1.9 86/03/11 14:21:39 slatteng 9 8
c added PRINTER and TYPESETTER environment variable printer selection
e
s 00008/00003/00258
d D 1.8 84/01/02 17:24:32 slatteng 8 7
c add "-" getting standard output option
e
s 00001/00001/00260
d D 1.7 83/12/19 17:03:36 slatteng 7 6
c fix mistyped control
e
s 00002/00001/00259
d D 1.6 83/12/19 16:58:33 slatteng 6 5
c make DEVDIR changeable in makefile
e
s 00001/00001/00259
d D 1.5 83/10/18 17:10:18 slatteng 5 4
c have pic exit with 1 status if syntax error occurs.
e
s 00002/00001/00258
d D 1.4 83/10/07 21:00:03 slatteng 4 3
c convert to "-P" options and new device names
e
s 00010/00002/00249
d D 1.3 83/08/15 16:26:08 slatteng 3 2
c add capability for varying picture boundaries
e
s 00037/00039/00214
d D 1.2 83/08/09 12:04:51 slatteng 2 1
c fix pic to be REALLY device independent.  It now reads in description files
e
s 00253/00000/00000
d D 1.1 83/08/06 14:53:02 slatteng 1 0
c date and time created 83/08/06 14:53:02 by slatteng
e
u
U
t
T
I 2
/* %M%	(Berkeley)	%I%	%E%	*/
E 2
I 1
#include	<stdio.h>
#include	"pic.h"
#include	"y.tab.h"
I 2
#include	"dev.h"
E 2

I 2
D 6

E 6
I 6
D 7
#idndef DEVDIR
E 7
I 7
#ifndef DEVDIR
E 7
E 6
#define DEVDIR	"/usr/lib/font"		/* place to look up device files */
I 6
#endif
E 6

char	*devdir = DEVDIR;
D 4
char	*dev = "var";			/* default typesetter is varian */
E 4
I 4
char	*dev = "va";			/* default typesetter is varian */
I 9
char	*getenv();
E 9
E 4

E 2
struct	obj	*objlist[MAXOBJ];	/* store the elements here */
int	nobj	= 0;

struct attr	attr[40];	/* attributes stored here as collected */
int	nattr	= 0;	/* number of entries in attr_list */

struct	text	text[MAXTEXT];	/* text strings stored here as collected */
int	ntext	= 0;
int	ntext1	= 0;	/* record ntext here on entry to each figure */

float	curx	= 0;
float	cury	= 0;

int	hvmode	= R_DIR;	/* R => join left to right, D => top to bottom, etc. */

int	codegen	= 0;	/* 1=>output for this picture; 0=>no output */

D 3
float	deltx	= 6;	/* max x value in output, for scaling */
float	delty	= 6;	/* max y value in output, for scaling */
E 3
I 3
float	deltx	= 6.0;	/* max x value in output, for scaling */
float	delty	= 6.0;	/* max y value in output, for scaling */
float	xbound	= 8.0;	/* max allowed x value in output */
float	ybound	= 10.0;	/* max allowed y value in output */
E 3
int	dbg	= 0;
extern	FILE	*yyin,	/* input file pointer */
		*skeldb; /* output pointer for dbg messeges */
int	lineno	= 0;
char	*filename	= "-";
int	synerr	= 0;
char	*cmdname;
int	crop	= 1;	/* trim off exterior white space if non-zero */
extern int	useDline;	/* if set, use \D for all lines */
I 2
int	res;		/* resolution of output device (dots/inch) */
int	DX;		/* smallest change in X, and Y for output device */
int	DY;
E 2

D 2
/* You may want to change this if you don't have a 202... */
E 2

D 2
#ifdef	APS
	int	devtype	= DEVAPS;
	int	res	= 723;
	int	DX	= 3;
	int	DY	= 3;
#else
	int	devtype	= DEVVER;
	int	res	= 200;	/* default is 202 */
	int	DX	= 1;	/* used only for old-style troff */
	int	DY	= 1;
#endif

/* mandatory values for graphic systems CAT: */
/*
int	devtype = DEVCAT;
int	res	= 432;
int	DX = 3;
int	DY = 3;
*/

E 2
float	hshift	= 0;	/* move this far left for text (in em's) */
float	vshift	= 0.2;	/* this far down */

float	sxmin;		/* lower limit from s command */
float	symin;
float	sxmax	= 4096;	/* upper */
float	symax	= 4096;

float	xmin	= 30000;	/* min values found in actual data */
float	ymin	= 30000;
float	xmax	= -30000;	/* max */
float	ymax	= -30000;

main(argc, argv)
	char **argv;
{
I 9
	register char *cp;
	if ((cp = getenv("PRINTER")) != NULL) dev = cp;
	if ((cp = getenv("TYPESETTER")) != NULL) dev = cp;
E 9
	cmdname = argv[0];
D 8
	while (argc > 1 && *argv[1] == '-') {
E 8
I 8
	while (argc > 1 && *argv[1] == '-' && argv[1][1]) {
E 8
		switch (argv[1][1]) {
I 2
		case 'F':
			devdir = &argv[1][2];
			break;
E 2
		case 'T':
I 4
		case 'P':
E 4
D 2
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
			} else {
				res = atoi(&argv[1][2]);
			}
E 2
I 2
			dev = &argv[1][2];
E 2
			break;
		case 'd':
			dbg = 1;
			break;
		case 'D':
			useDline = !useDline;
I 3
			break;
		case 'x':
			xbound = atof(&argv[1][2]);
			break;
		case 'y':
			ybound = atof(&argv[1][2]);
E 3
			break;
		}
		argc--;
		argv++;
	}
I 2

	fileinit();
E 2
	setdefaults();
	if (argc <= 1) {
		yyin = stdin;
		getdata(yyin);
	} else
		while (argc-- > 1) {
D 8
			if ((yyin = fopen(*++argv, "r")) == NULL) {
E 8
I 8
			filename = *++argv;
			if ((yyin = fopen(filename, "r")) == NULL) {
			    if (filename[0] != '-' || filename[1]) {
E 8
				fprintf(stderr, "pic: can't open %s\n", *argv);
				exit(1);
I 8
			    } else {
				yyin = stdin;
				filename = "standard input";
			    }
E 8
			}
D 8
			filename = *argv;
E 8
			getdata(yyin);
			fclose(yyin);
		}
D 5
	exit(0);
E 5
I 5
	exit(synerr);
E 5
}
I 2


fileinit()
{
	int fin;
	struct dev device;
	char temp[100];

	sprintf(temp, "%s/dev%s/DESC.out", devdir, dev);
	if ((fin = open(temp, 0)) < 0) {
	    fprintf(stderr, "can't open tables for %s\n", temp);
	    exit(1);
	}
	read(fin, &device, sizeof(struct dev));
	res = device.res;
	DX = device.hor;
	DY = device.vert;
	close(fin);
}

E 2

static struct {
	char *name;
	float val;
} defaults[] ={
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


checkscale(s)	/* if s is "scale", adjust default variables */
	char *s;
{
	int i;
	float scale;

	if (strcmp(s, "scale") == 0) {
		scale = getfval("scale");
		for (i = 1; defaults[i].name != NULL; i++)
			setfval(defaults[i].name, defaults[i].val * scale);
	}
}

getdata(fin)
	register FILE *fin;
{
	char buf[1000], buf1[50];
	FILE *svyyin;
	int svlineno;
	char *svfilename, *p;

	lineno = 0;
	while (fgets(buf, sizeof buf, fin) != NULL) {
		lineno++;
		if (*buf == '.' && *(buf+1) == 'P' && *(buf+2) == 'S') {
			for (p = &buf[3]; *p == ' '; p++)
				;
			if (*p++ == '<') {
				svyyin = yyin;
				svlineno = lineno;
				svfilename = filename;
				sscanf(p, "%s", buf1);
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
				continue;
			}
			reset();
			yyparse();
			/* yylval now contains 'E' or 'F' from .PE or .PF */
			if (buf[3] == ' ')	/* assume next thing is width */
				deltx = delty = atof(&buf[4]);
			else {
				deltx = xmax - xmin;
				if (deltx <= 0)
					deltx = ymax - ymin;
				deltx /= getfval("scale");
				delty = deltx;
			}
			dprintf("deltx = %.3f\n", deltx);
			if (codegen && !synerr) {
				openpl(&buf[3]);	/* puts out .PS, with ht & wid stuck in */
				print();	/* assumes \n at end */
				closepl(yylval.p);	/* does the .PE/F */
			}
			fflush(stdout);
		}
		else
			fputs(buf, stdout);
	}
}

reset()
{
	struct obj *op;
	int i;
	struct symtab *p;
	extern int nstack;

	for (i = 0; i < nobj; i++) {
		op = objlist[i];
		if (op->o_type == BLOCK)
			freesymtab(op->o_dotdash);	/* funny place */
		free(objlist[i]);
	}
	nobj = 0;
	nattr = 0;
	for (i = 0; i < ntext; i++)
		free(text[i].t_val);
	ntext = ntext1 = 0;
	codegen = synerr = 0;
	nstack = 0;
	curx = cury = 0;
	hvmode = R_DIR;
	sxmin = symin = 0;
	sxmax = symax = 4096;
	xmin = ymin = 30000;
	xmax = ymax = -30000;
}
E 1

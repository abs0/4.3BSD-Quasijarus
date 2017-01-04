h26183
s 00001/00000/00073
d D 4.3 85/09/14 16:25:14 bloom 3 2
c lint fixes
e
s 00001/00001/00072
d D 4.2 83/10/13 13:44:19 mosher 2 1
c MAXHEAD increased to 100 allow for really big tables - dm
e
s 00073/00000/00000
d D 4.1 83/02/12 19:06:13 shannon 1 0
c date and time created 83/02/12 19:06:13 by shannon
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/* t..c : external declarations */

# include "stdio.h"
# include "ctype.h"

# define MAXLIN 200
D 2
# define MAXHEAD 30
E 2
I 2
# define MAXHEAD 100
E 2
# define MAXCOL 20
# define MAXCHS 2000
# define MAXRPT 100
# define CLLEN 10
# define SHORTLINE 4
extern int nlin, ncol, iline, nclin, nslin;
extern int style[MAXHEAD][MAXCOL];
extern int ctop[MAXHEAD][MAXCOL];
extern char font[MAXHEAD][MAXCOL][2];
extern char csize[MAXHEAD][MAXCOL][4];
extern char vsize[MAXHEAD][MAXCOL][4];
extern char cll[MAXCOL][CLLEN];
extern int stynum[];
extern int F1, F2;
extern int lefline[MAXHEAD][MAXCOL];
extern int fullbot[];
extern char *instead[];
extern int expflg;
extern int ctrflg;
extern int evenflg;
extern int evenup[];
extern int boxflg;
extern int dboxflg;
extern int linsize;
extern int tab;
extern int pr1403;
extern int linsize, delim1, delim2;
extern int allflg;
extern int textflg;
extern int left1flg;
extern int rightl;
struct colstr {char *col, *rcol;};
extern struct colstr *table[];
extern char *cspace, *cstore;
I 3
extern char *chspace();
E 3
extern char *exstore, *exlim;
extern int sep[];
extern int used[], lused[], rused[];
extern int linestop[];
extern int leftover;
extern char *last, *ifile;
extern int texname;
extern int texct, texmax;
extern char texstr[];
extern int linstart;


extern FILE *tabin, *tabout;
# define CRIGHT 80
# define CLEFT 40
# define CMID 60
# define S1 31
# define S2 32
# define TMP 38
# define SF 35
# define SL 34
# define LSIZE 33
# define SIND 37
# define SVS 36
/* this refers to the relative position of lines */
# define LEFT 1
# define RIGHT 2
# define THRU 3
# define TOP 1
# define BOT 2
E 1

h34123
s 00002/00002/00140
d D 5.2 2012/03/04 02:06:21 msokolov 2 1
c tr handles the full 512-char set now
e
s 00142/00000/00000
d D 5.1 04/09/08 16:42:00 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %E%";
E 2
#endif lint

#include "tdef.h"
#ifdef NROFF
#include "tw.h"
#endif
#include "sdef.h"
#include "d.h"
#include "v.h"
#include <sgtty.h>

int *vlist = (int *)&v;
struct s *frame, *stk, *ejl;
struct s *nxf, *litlev;

#ifdef NROFF
int pipeflg;
int hflg;
int eqflg;
#endif

#ifndef NROFF
int psout_omit_troffencoding;
int psout_8bit_strings;
int psout_hex_strings;
int xsfont;
int xpts;
int verm;
int *pslp;
int psflg;
int ppts;
int pfont;
int paper;
int mpts;
int mfont;
int mcase;
int escm;
int cs;
int code;
int ccs;
int bd;
int back;
#endif

int level;
int stdi;
int waitf;
int nofeed;
int quiet;
int stop;
char ibuf[IBUFSZ];
char xbuf[IBUFSZ];
char *ibufp;
char *xbufp;
char *eibuf;
char *xeibuf;
int cbuf[NC];
int *cp;
int nx;
int mflg;
int ch = 0;
int ibf;
int ttyod;
struct sgttyb ttys;
int iflg;
char *enda;
int rargc;
char **argp;
D 2
char trtab[256];
E 2
I 2
u_short trtab[512];
E 2
int lgf;
int copyf;
int ch0;
int cwidth;
filep ip;
int nlflg;
int *ap;
int donef;
int nflush;
int nchar;
int rchar;
int nfo;
int ifile;
int padc;
int raw;
int ifl[NSO];
int ifi;
int flss;
int nonumb;
int trap;
int tflg;
int ejf;
int lit;
int dilev;
int tlss;
filep offset;
int em;
int ds;
filep woff;
int app;
int ndone;
int lead;
int ralss;
filep nextb;
int *argtop;
int nrbits;
int nform;
int oldmn;
int newmn;
int macerr;
filep apptr;
int diflg;
filep roff;
int wbfi;
int inc[NN];
int fmt[NN];
int evi;
int vflag;
int noscale;
int po1;
int nlist[NTRAP];
int mlist[NTRAP];
int evlist[EVLSZ];
int ev;
int tty;
int sfont;
int sv;
int esc;
int widthp;
int xfont;
int setwdf;
int xbitf;
int over;
int nhyp;
int **hyp;
int *olinep;
int esct;
int ttysave = -1;
int dotT;
char *unlkp;
int no_out;
E 1

h50047
s 00001/00001/00042
d D 4.4 87/10/22 19:41:26 bostic 4 3
c ANSI C; sprintf now returns an int.
e
s 00002/00000/00041
d D 4.3 86/04/23 18:19:23 mckusick 3 2
c fix sequencing numbers (from Keith Muller)
e
s 00002/00000/00039
d D 4.2 83/08/11 21:04:44 sam 2 1
c standardize sccs keyword lines
e
s 00039/00000/00000
d D 4.1 83/05/06 23:50:20 tut 1 0
c date and time created 83/05/06 23:50:20 by tut
e
u
U
t
T
I 2
/*	%M%	%I%	%E%	*/

E 2
I 1
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#define FLAG 003
I 3
#define AFLAG 007
E 3
#define NRFTXT 10000
#define NRFTBL 500
#define NTFILE 20
#define QLEN 512
#define ANSLEN 1024
#define TAGLEN 400
#define NSERCH 20
I 3
#define MXSIG 200		/* max bytes in aggregate signal */
E 3

extern FILE *in;
extern int endpush, sort, labels, keywant, bare;
extern int biblio, science, postpunct;
extern char *smallcaps;
extern char comname;
extern char *keystr;
extern char *convert;
extern int authrev;
extern int nmlen, dtlen;
extern char *rdata[], **search;
extern int refnum;
extern char *reftable[];
extern char *rtp, reftext[];
extern int sep;
extern char tfile[];
extern char gfile[];
extern char ofile[];
extern char hidenam[];
extern char *Ifile; extern int Iline;
extern FILE *fo, *ftemp;
extern char *input(),*lookat();
extern char *class(),*caps(),*revauth();
extern char *artskp(),*fpar();
extern char *trimnl();

D 4
extern char *getenv(), *sprintf(), *strcpy(), *strcat();
E 4
I 4
extern char *getenv(), *strcpy(), *strcat();
E 4
E 1

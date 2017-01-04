h00692
s 00004/00002/00177
d D 5.2 85/07/30 16:40:05 jerry 21 20
c implement namelist
e
s 00007/00001/00172
d D 5.1 85/06/07 23:46:04 kre 20 19
c Add copyright
e
s 00018/00013/00155
d D 1.16 85/05/21 19:24:33 libs 19 18
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00002/00010/00166
d D 1.15 85/05/09 22:50:15 libs 18 15
c call f77_abort() instead of abort() so only get dumps when wanted.
e
s 00001/00001/00175
d R 1.15 85/05/06 17:19:31 libs 17 15
c Call f77_abort() instead of abort() so get dumps only when wanted.
e
s 00001/00001/00175
d R 1.15 85/05/06 15:12:45 libs 16 15
c Call f77_abort instead of abort() so only get coredump when requested.
e
s 00001/00001/00175
d D 1.14 85/05/02 22:11:23 libs 15 14
c don't explicitly initialize units[] to 0, wastes disk space.
e
s 00001/00000/00175
d D 1.13 85/02/19 18:42:13 libs 14 13
c buffer standard error.
e
s 00004/00002/00171
d D 1.12 85/02/14 23:24:39 libs 13 11
c Improve error messages.
e
s 00004/00002/00171
d R 1.12 85/02/14 22:23:35 libs 12 11
c Improve error messages.
e
s 00001/00000/00172
d D 1.11 83/10/28 10:29:27 dlw 11 10
c added sigsetmask(0) before abort(). DLW
e
s 00005/00000/00167
d D 1.10 83/08/25 18:00:25 dlw 10 9
c reset signal for abort() to SIG_DFL. DLW
e
s 00001/00000/00166
d D 1.9 83/04/25 01:31:18 dlw 9 8
c added ioiflg. DLW
e
s 00003/00004/00163
d D 1.8 83/04/21 22:56:09 dlw 8 7
c eliminated init66. DLW
e
s 00002/00001/00165
d D 1.7 83/04/15 22:52:12 dlw 7 6
c declare init66_ in err.c. DLW
e
s 00018/00005/00148
d D 1.6 81/05/08 09:56:01 dlw 6 5
c fixed err prnt bug & added display of non-prnt chars. DLW
e
s 00004/00003/00149
d D 1.5 81/04/28 19:21:44 dlw 5 4
c added init66_ to f_init() routine. DLW
e
s 00003/00003/00149
d D 1.4 81/02/27 16:10:30 dlw 4 3
c fixed declaration for MAXERR. DLW
e
s 00001/00000/00151
d D 1.3 81/02/26 23:36:44 dlw 3 2
c added 'int f_nerr' for external routines. DLW
e
s 00001/00001/00150
d D 1.2 81/02/20 18:29:12 dlw 2 1
c changed to F_ER codes. DLW
e
s 00151/00000/00000
d D 1.1 81/02/18 18:01:16 dlw 1 0
c date and time created 81/02/18 18:01:16 by dlw
e
u
U
t
T
I 1
/*
D 20
char id_err[] = "%W%";
E 20
I 20
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
 *
I 20
 *	%W%	%G%
 */

/*
E 20
D 19
 * file i/o error and initialization routines
E 19
I 19
 * fatal(): i/o error routine
 * flush_(): flush file buffer
E 19
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
D 19
#include "fiodefs.h"
E 19
I 19
#include "fio.h"
E 19

/*
 * global definitions
 */

D 19
char *tmplate = "tmp.FXXXXXX";	/* scratch file template */
char *fortfile = "fort.%d";	/* default file template */

E 19
D 15
unit units[MXUNIT] = 0;	/*unit table*/
E 15
I 15
unit units[MXUNIT];	/*unit table*/
E 15
flag reading;		/*1 if reading,		0 if writing*/
flag external;		/*1 if external io,	0 if internal */
flag sequential;	/*1 if sequential io,	0 if direct*/
D 21
flag formatted;		/*1 if formatted io,	0 if unformatted, -1 if list*/
E 21
I 21
flag formatted;		/*1 if formatted io,	0 if unformatted,
				-1 if list directed, -2 if namelist */
E 21
char *fmtbuf, *icptr, *icend, *fmtptr;
int (*doed)(),(*doned)();
int (*doend)(),(*donewrec)(),(*dorevert)(),(*dotab)();
int (*lioproc)();
int (*getn)(),(*putn)(),(*ungetn)();	/*for formatted io*/
D 19
icilist *svic;		/* active internal io list */
E 19
FILE *cf;		/*current file structure*/
unit *curunit;		/*current unit structure*/
int lunit;		/*current logical unit*/
char *lfname;		/*current filename*/
int recpos;		/*place in current record*/
ftnint recnum;		/* current record number */
int reclen;		/* current record length */
int cursor,scale;
int radix;
ioflag signit,tab,cplus,cblank,elist,errflag,endflag,lquit,l_first;
flag leof;
int lcount,line_len;
I 9
struct ioiflg ioiflg_;	/* initialization flags */
E 9

/*error messages*/

extern char *sys_errlist[];
extern int sys_nerr;

D 4
#include "f_errlist.h"
I 3
int f_nerr = MAXERR - F_ER;
E 4
I 4
extern char *f_errlist[];
extern int f_nerr;
E 4
E 3


fatal(n,s) char *s;
{
	ftnint lu;

	for (lu=1; lu < MXUNIT; lu++)
		flush_(&lu);
	if(n<0)
		fprintf(stderr,"%s: [%d] end of file\n",s,n);
	else if(n>=0 && n<sys_nerr)
		fprintf(stderr,"%s: [%d] %s\n",s,n,sys_errlist[n]);
D 4
	else if(n>=F_ER && n<MAXERR)
E 4
I 4
	else if(n>=F_ER && n<F_MAXERR)
E 4
		fprintf(stderr,"%s: [%d] %s\n",s,n,f_errlist[n-F_ER]);
	else
		fprintf(stderr,"%s: [%d] unknown error number\n",s,n);
	if(external)
	{
		if(!lfname) switch (lunit)
		{	case STDERR: lfname = "stderr";
					break;
			case STDIN:  lfname = "stdin";
					break;
			case STDOUT: lfname = "stdout";
					break;
			default:     lfname = "";
		}
		fprintf(stderr,"logical unit %d, named '%s'\n",lunit,lfname);
	}
	if (elist)
D 18
	{	fprintf(stderr,"lately: %s %s %s %s IO\n",
E 18
I 18
	{	fprintf(stderr,"lately: %s %s %s %s I/O\n",
E 18
			reading?"reading":"writing",
			sequential?"sequential":"direct",
D 21
			formatted>0?"formatted":(formatted<0?"list":"unformatted"),
E 21
I 21
			formatted>0?"formatted":(formatted==0?"unformatted":
				(formatted==LISTDIRECTED?"list":"namelist")),
E 21
			external?"external":"internal");
		if (formatted)
		{	if(fmtbuf) prnt_fmt(n);
			if (external)
			{	if(reading && curunit->useek)
					prnt_ext();  /* print external data */
			}
			else prnt_int();	/* print internal array */
		}
	}
D 18
	f_exit();
	_cleanup();
I 10
#if	vax
	signal(SIGILL, SIG_DFL);
I 11
	sigsetmask(0);
E 11
#else	pdp11
	signal(SIGIOT, SIG_DFL);
#endif
E 10
	abort();
E 18
I 18
	f77_abort(n);
E 18
}

I 19
LOCAL
E 19
prnt_ext()
{	int ch;
	int i=1;
	long loc;
	fprintf (stderr, "part of last data: ");
	loc = ftell(curunit->ufd);
	if(loc)
	{	if(loc==1L) rewind(curunit->ufd);
		else for(;i<12 && last_char(curunit->ufd)!='\n';i++);
D 6
		while(i--) fputc(fgetc(curunit->ufd),stderr);
E 6
I 6
		while(i--) ffputc(fgetc(curunit->ufd),stderr);
E 6
	}
	fputc('|',stderr);
D 6
	for(i=0;i<5 && (ch=fgetc(curunit->ufd)!=EOF);i++) fputc(ch,stderr);
E 6
I 6
	for(i=0;i<5 && (ch=fgetc(curunit->ufd))!=EOF;i++) ffputc(ch,stderr);
E 6
	fputc('\n',stderr);
}

I 19
LOCAL
E 19
prnt_int()
{	char *ep;
	fprintf (stderr,"part of last string: ");
	ep = icptr - (recpos<12?recpos:12);
D 6
	while (ep<icptr) fputc(*ep++,stderr);
E 6
I 6
	while (ep<icptr) ffputc(*ep++,stderr);
E 6
	fputc('|',stderr);
D 6
	while (ep<(icptr+5) && ep<icend) fputc(*ep++,stderr);
E 6
I 6
	while (ep<(icptr+5) && ep<icend) ffputc(*ep++,stderr);
E 6
	fputc('\n',stderr);
}

I 19
LOCAL
E 19
prnt_fmt(n) int n;
{	int i; char *ep;
D 13
	fprintf(stderr, "part of last format: ");
E 13
I 13
	fprintf(stderr, "format: ");
E 13
D 2
	if(n==100)
E 2
I 2
	if(n==F_ERFMT)
E 2
	{	i = fmtptr - fmtbuf;
D 13
		ep = fmtptr - (i<20?i:20);
E 13
I 13
		ep = fmtptr - (i<25?i:25);
		if(ep != fmtbuf) fprintf(stderr, "... ");
E 13
		i = i + 5;
	}
	else
	{	ep = fmtbuf;
		i = 25;
		fmtptr = fmtbuf - 1;
	}
	while(i && *ep)
D 6
	{	fputc((*ep==GLITCH)?'"':*ep,stderr);
E 6
I 6
	{	ffputc((*ep==GLITCH)?'"':*ep,stderr);
E 6
		if(ep==fmtptr) fputc('|',stderr);
		ep++; i--;
	}
I 13
	if(*ep) fprintf(stderr, " ...");
E 13
	fputc('\n',stderr);
I 6
}

I 19
LOCAL
E 19
ffputc(c, f)
int	c;
FILE	*f;
{
	c &= 0177;
	if (c < ' ' || c == 0177)
	{
		fputc('^', f);
		c ^= 0100;
	}
	fputc(c, f);
E 6
}

D 19
/*initialization routine*/
I 7
D 8
short	init66_;
E 8
E 7
f_init()
E 19
I 19
ftnint
flush_(u) ftnint *u;
E 19
D 5
{	ini_std(STDERR, stderr, WRITE);
	ini_std(STDIN, stdin, READ);
	ini_std(STDOUT, stdout, WRITE);
E 5
I 5
D 7
{	extern short init66_;
E 7
I 7
{
E 7
D 8
	ini_std(STDERR, stderr, WRITE, 0);
	ini_std(STDIN, stdin, READ, 0);
	ini_std(STDOUT, stdout, WRITE, init66_);
E 8
I 8
D 19
	ini_std(STDERR, stderr, WRITE);
	ini_std(STDIN, stdin, READ);
	ini_std(STDOUT, stdout, WRITE);
I 14
	setlinebuf(stderr);
E 14
E 8
E 5
}
E 19
I 19
	FILE *F;
E 19

I 19
	if(not_legal(*u))
		return(F_ERUNIT);
	F = units[*u].ufd;
	if(F)
		return(fflush(F));
	else
		return(F_ERNOPEN);
}
E 19
E 1

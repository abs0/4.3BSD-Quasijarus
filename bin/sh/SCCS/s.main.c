h10139
s 00003/00003/00186
d D 4.3 85/03/19 18:46:40 mckusick 3 2
c update dup() to dup2()
e
s 00003/00001/00186
d D 4.2 83/08/11 20:19:40 sam 2 1
c standardize sccs keyword lines
e
s 00187/00000/00000
d D 4.1 82/05/07 19:38:07 mckusick 1 0
c date and time created 82/05/07 19:38:07 by mckusick
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 2

#
/*
 * UNIX shell
 *
 * S. R. Bourne
 * Bell Telephone Laboratories
 *
 */

#include	"defs.h"
D 3
#include	"dup.h"
E 3
#include	"sym.h"
#include	"timeout.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sgtty.h>
I 3
#include	<signal.h>
E 3

UFD		output = 2;
LOCAL BOOL	beenhere = FALSE;
CHAR		tmpout[20] = "/tmp/sh-";
FILEBLK		stdfile;
FILE		standin = &stdfile;
#ifdef stupid
#include	<execargs.h>
#endif

PROC VOID	exfile();




main(c, v)
	INT		c;
	STRING		v[];
{
	REG INT		rflag=ttyflg;

	/* initialise storage allocation */
	stdsigs();
	setbrk(BRKINCR);
	addblok((POS)0);

	/* set names from userenv */
D 3
	getenv();
E 3
I 3
	setupenv();
E 3

	/* look for restricted */
/*	IF c>0 ANDF any('r', *v) THEN rflag=0 FI */

	/* look for options */
	dolc=options(c,v);
	IF dolc<2 THEN flags |= stdflg FI
	IF (flags&stdflg)==0
	THEN	dolc--;
	FI
	dolv=v+c-dolc; dolc--;

	/* return here for shell file execution */
	setjmp(subshell);

	/* number of positional parameters */
	assnum(&dolladr,dolc);
	cmdadr=dolv[0];

	/* set pidname */
	assnum(&pidadr, getpid());

	/* set up temp file names */
	settmp();

	/* default ifs */
	dfault(&ifsnod, sptbnl);

	IF (beenhere++)==FALSE
	THEN	/* ? profile */
		IF *cmdadr=='-'
		    ANDF (input=pathopen(nullstr, profile))>=0
		THEN	exfile(rflag); flags &= ~ttyflg;
		FI
		IF rflag==0 THEN flags |= rshflg FI

		/* open input file if specified */
		IF comdiv
		THEN	estabf(comdiv); input = -1;
		ELSE	input=((flags&stdflg) ? 0 : chkopen(cmdadr));
			comdiv--;
		FI
#ifdef stupid
	ELSE	*execargs=dolv;	/* for `ps' cmd */
#endif
	FI

	exfile(0);
	done();
}

LOCAL VOID	exfile(prof)
BOOL		prof;
{
	REG L_INT	mailtime = 0;
	REG INT		userid;
	struct stat	statb;

	/* move input */
	IF input>0
	THEN	Ldup(input,INIO);
		input=INIO;
	FI

	/* move output to safe place */
	IF output==2
	THEN	Ldup(dup(2),OTIO);
		output=OTIO;
	FI

	userid=getuid();

	/* decide whether interactive */
	IF (flags&intflg) ORF ((flags&oneflg)==0 ANDF gtty(output,&statb)==0 ANDF gtty(input,&statb)==0)
	THEN	dfault(&ps1nod, (userid?stdprompt:supprompt));
		dfault(&ps2nod, readmsg);
		flags |= ttyflg|prompt; ignsig(KILL);
/*
		{
	#include <signal.h>
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		}
*/
	ELSE	flags |= prof; flags &= ~prompt;
	FI

	IF setjmp(errshell) ANDF prof
	THEN	close(input); return;
	FI

	/* error return here */
	loopcnt=breakcnt=peekc=0; iopend=0;
	IF input>=0 THEN initf(input) FI

	/* command loop */
	LOOP	tdystak(0);
		stakchk(); /* may reduce sbrk */
		exitset();
		IF (flags&prompt) ANDF standin->fstak==0 ANDF !eof
		THEN	IF mailnod.namval
			    ANDF stat(mailnod.namval,&statb)>=0 ANDF statb.st_size
			    ANDF (statb.st_mtime != mailtime)
			    ANDF mailtime
			THEN	prs(mailmsg)
			FI
			mailtime=statb.st_mtime;
			prs(ps1nod.namval);
		FI

		trapnote=0; peekc=readc();
		IF eof
		THEN	return;
		FI
		execute(cmd(NL,MTFLG),0);
		eof |= (flags&oneflg);
	POOL
}

chkpr(eor)
char eor;
{
	IF (flags&prompt) ANDF standin->fstak==0 ANDF eor==NL
	THEN	prs(ps2nod.namval);
	FI
}

settmp()
{
	itos(getpid()); serial=0;
	tmpnam=movstr(numbuf,&tmpout[TMPNAM]);
}

Ldup(fa, fb)
	REG INT		fa, fb;
{
D 3
	dup(fa|DUPFLG, fb);
E 3
I 3
	dup2(fa, fb);
E 3
	close(fa);
	ioctl(fb, FIOCLEX, 0);
}
E 1

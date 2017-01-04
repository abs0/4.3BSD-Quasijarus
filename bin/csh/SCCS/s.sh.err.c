h39809
s 00006/00006/00145
d D 5.3 86/05/13 01:02:59 lepreau 5 4
c Fix "cmd not found error handling in script (was seeking just .+1024).
c from elsie!ado
e
s 00003/00003/00148
d D 5.2 85/06/06 13:09:45 edward 4 3
c cleaning up after bozos
e
s 00008/00002/00143
d D 5.1 85/06/04 10:56:52 dist 3 2
c Add copyright
e
s 00006/00003/00139
d D 4.2 84/12/13 14:40:02 edward 2 1
c performance
e
s 00142/00000/00000
d D 4.1 80/10/09 12:40:44 bill 1 0
c date and time created 80/10/09 12:40:44 by bill
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
E 4
I 4
 * All rights reserved.  The Berkeley Software License Agreement
E 4
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
D 2
static	char *sccsid = "%Z%%M% %I% %G%";
E 2
I 2
#ifndef lint
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 3
I 3
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4
I 4
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 4
E 3
E 2

#include "sh.h"
#include <sys/ioctl.h>

/*
 * C Shell
 */

bool	errspl;			/* Argument to error was spliced by seterr2 */
char	one[2] = { '1', 0 };
char	*onev[2] = { one, NOSTR };
/*
 * Print error string s with optional argument arg.
 * This routine always resets or exits.  The flag haderr
 * is set so the routine who catches the unwind can propogate
 * it if they want.
 *
 * Note that any open files at the point of error will eventually
 * be closed in the routine process in sh.c which is the only
 * place error unwinds are ever caught.
 */
I 2
/*VARARGS1*/
E 2
error(s, arg)
	char *s;
{
	register char **v;
	register char *ep;

	/*
	 * Must flush before we print as we wish output before the error
	 * to go on (some form of) standard output, while output after
	 * goes on (some form of) diagnostic output.
	 * If didfds then output will go to 1/2 else to FSHOUT/FSHDIAG.
	 * See flush in sh.print.c.
	 */
	flush();
	haderr = 1;		/* Now to diagnostic output */
	timflg = 0;		/* This isn't otherwise reset */
	if (v = pargv)
		pargv = 0, blkfree(v);
	if (v = gargv)
		gargv = 0, blkfree(v);

	/*
	 * A zero arguments causes no printing, else print
	 * an error diagnostic here.
	 */
	if (s)
		printf(s, arg), printf(".\n");

	didfds = 0;		/* Forget about 0,1,2 */
	if ((ep = err) && errspl) {
		errspl = 0;
		xfree(ep);
	}
	errspl = 0;

	/*
I 5
	 * Go away if -e or we are a child shell
	 */
	if (exiterr || child)
		exit(1);

	/*
E 5
	 * Reset the state of the input.
	 * This buffered seek to end of file will also
	 * clear the while/foreach stack.
	 */
	btoeof();
D 5

	/*
	 * Go away if -e or we are a child shell
	 */
	if (exiterr || child)
		exit(1);
E 5

	setq("status", onev, &shvhed);
	if (tpgrp > 0)
D 2
		ioctl(FSHTTY, TIOCSPGRP, &tpgrp);
E 2
I 2
		(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&tpgrp);
E 2
	reset();		/* Unwind */
}

/*
 * Perror is the shells version of perror which should otherwise
 * never be called.
 */
Perror(s)
	char *s;
{

	/*
	 * Perror uses unit 2, thus if we didn't set up the fd's
	 * we must set up unit 2 now else the diagnostic will disappear
	 */
	if (!didfds) {
		register int oerrno = errno;

D 2
		dcopy(SHDIAG, 2);
E 2
I 2
		(void) dcopy(SHDIAG, 2);
E 2
		errno = oerrno;
	}
	perror(s);
	error(NOSTR);		/* To exit or unwind */
}

bferr(cp)
	char *cp;
{

	flush();
	haderr = 1;
	printf("%s: ", bname);
	error(cp);
}

/*
 * The parser and scanner set up errors for later by calling seterr,
 * which sets the variable err as a side effect; later to be tested,
 * e.g. in process.
 */
seterr(s)
	char *s;
{

	if (err == 0)
		err = s, errspl = 0;
}

/* Set err to a splice of cp and dp, to be freed later in error() */
seterr2(cp, dp)
	char *cp, *dp;
{

	if (err)
		return;
	err = strspl(cp, dp);
	errspl++;
}

/* Set err to a splice of cp with a string form of character d */
seterrc(cp, d)
	char *cp, d;
{
	char chbuf[2];

	chbuf[0] = d;
	chbuf[1] = 0;
	seterr2(cp, chbuf);
}
E 1

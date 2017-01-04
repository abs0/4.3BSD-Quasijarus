h32214
s 00009/00004/00121
d D 7.3 86/12/15 20:26:48 sam 3 2
c lint
e
s 00001/00001/00124
d D 7.2 86/11/20 14:44:11 sam 2 1
c no more TRUE|FALSE
e
s 00125/00000/00000
d D 7.1 86/11/20 12:22:04 sam 1 0
c date and time created 86/11/20 12:22:04 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

#include "../kdb/defs.h"

char	line[LINSIZ];
char	*lp;
char	peekc,lastc = EOR;
D 3
int	eof;
E 3

/* input routines */

eol(c)
	char c;
{
	return (c==EOR || c==';');
}

rdc()
{
	do
D 3
		readchar();
E 3
I 3
		(void) readchar();
E 3
	while (lastc==SP || lastc==TB);
	return (lastc);
}

readchar()
{
	static char *erase = "\b \b";

	if (lp==0) {
		lp=line;
		do {
			(void) kdbreadc(lp);
			if (mkfault)
D 3
				error(0);
E 3
I 3
				error((char *)0);
E 3
			switch (*lp) {
			case CTRL(h): case 0177:
				if (lp > line)
					kdbwrite(erase, 3), lp--;
				break;
			case CTRL(u):
				while (lp > line) 
					kdbwrite(erase, 3), lp--;
				break;
			case CTRL(r):
				kdbwrite("^R\n", 3);
				if (lp > line)
					kdbwrite(line, lp-line);
				break;
			case CTRL(w):
				if (lp <= line)
					break;
				do {
					if (!isspace(*lp))
						goto erasenb;
					kdbwrite(erase, 3);
				} while (--lp > line);
				break;
			erasenb:
				do
					kdbwrite(erase, 3);
				while (--lp > line && !isspace(*lp));
				break;
			default:
				echo(*lp++);
				break;
			}
		} while (lp == line || lp[-1] != EOR);
		*lp=0; lp=line;
	}
	if (lastc = peekc)
		peekc=0;
	else  if (lastc = *lp)
		lp++;
	return (lastc);
}

static
echo(c)
	char c;
{
	char buf[2];

	if (c==0177 || (c<SP && c != TB && c != EOR)) {
		buf[0] = '^';
		buf[1] = c ^ 0100;
		kdbwrite(buf, 2);
	} else
		kdbwrite(&c, 1);
}

nextchar()
{

	if (eol(rdc())) {
		lp--;
		return (0);
	}
	return (lastc);
}

quotchar()
{

	if (readchar()=='\\')
		return (readchar());
	if (lastc=='\'')
		return (0);
	return (lastc);
}

getformat(deformat)
	char *deformat;
{
	register char *fptr;
	register int quote;

D 2
	fptr=deformat; quote=FALSE;
E 2
I 2
	fptr=deformat; quote=0;
E 2
	while ((quote ? readchar()!=EOR : !eol(readchar())))
		if ((*fptr++ = lastc)=='"')
			quote = ~quote;
	lp--;
	if (fptr!=deformat)
		*fptr++ = '\0';
}
E 1

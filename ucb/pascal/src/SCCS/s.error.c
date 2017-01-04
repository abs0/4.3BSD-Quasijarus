h25839
s 00001/00001/00142
d D 5.2 87/12/04 19:06:32 bostic 12 11
c old assignment operator
e
s 00007/00003/00136
d D 5.1 85/06/05 14:08:39 dist 11 10
c Add copyright
e
s 00000/00000/00139
d D 2.1 84/02/08 20:52:32 aoki 10 9
c synchronize to version 2
e
s 00010/00005/00129
d D 1.5 83/10/14 07:28:11 thien 9 4
c lint changes
e
s 00010/00005/00129
d R 1.5 83/10/14 07:25:17 thien 8 4
c 
e
s 00000/00000/00140
d R 1.7 83/10/14 07:17:14 thien 7 6
c 
e
s 00000/00000/00140
d R 1.6 83/09/19 06:58:04 thien 6 5
c Restoring to unlinted version
e
s 00010/00004/00130
d R 1.5 83/08/19 04:56:26 thien 5 4
c The changes were made to allow successful linting
e
s 00000/00001/00134
d D 1.4 82/03/31 11:08:03 peter 4 3
c left over external declaration of the errfile.
e
s 00006/00006/00129
d D 1.3 81/03/18 21:17:40 mckusic 3 2
c mods for new formal routine syntax
e
s 00003/00003/00132
d D 1.2 81/03/08 19:24:43 mckusic 2 1
c merge in onyx changes
e
s 00135/00000/00000
d D 1.1 80/08/27 19:54:57 peter 1 0
c date and time created 80/08/27 19:54:57 by peter
e
u
U
t
T
I 1
D 11
/* Copyright (c) 1979 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

I 9
#ifndef lint
E 9
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
I 9
#endif
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11
E 9
E 2

#include "whoami.h"
#include "0.h"
#ifndef PI1
I 9
#include "tree_ty.h"		/* must be included for yy.h */
E 9
#include "yy.h"
#endif

char	errpfx	= 'E';
extern	int yyline;
/*
 * Panic is called when impossible
 * (supposedly, anyways) situations
 * are encountered.
 * Panic messages should be short
 * as they do not go to the message
 * file.
 */
panic(s)
	char *s;
{

#ifdef DEBUG
#ifdef PI1
	printf("Snark (%s) line=%d\n", s, line);
	abort();
#else
	printf("Snark (%s) line=%d, yyline=%d\n", s, line, yyline);
	abort () ;	/* die horribly */
#endif
#endif
#ifdef PI1
	Perror( "Snark in pi1", s);
#else
	Perror( "Snark in pi", s);
#endif
	pexit(DIED);
}

D 4
extern	char *errfile;
E 4
/*
 * Error is called for
 * semantic errors and
 * prints the error and
 * a line number.
 */

D 9
/*VARARGS*/
E 9
I 9
/*VARARGS1*/
E 9

D 3
error(a1, a2, a3, a4)
E 3
I 3
error(a1, a2, a3, a4, a5)
E 3
	register char *a1;
{
	char errbuf[256]; 		/* was extern. why? ...pbk */
	register int i;

	if (errpfx == 'w' && opt('w') != 0) {
		errpfx = 'E';
		return;
	}
D 9
	Enocascade = 0;
	geterr(a1, errbuf);
E 9
I 9
	Enocascade = FALSE;
	geterr((int) a1, errbuf);
E 9
	a1 = errbuf;
	if (line < 0)
		line = -line;
#ifndef PI1
	if (opt('l'))
		yyoutline();
#endif
	yysetfile(filename);
	if (errpfx == ' ') {
		printf("  ");
		for (i = line; i >= 10; i /= 10)
			pchr( ' ' );
		printf("... ");
	} else if (Enoline)
		printf("  %c - ", errpfx);
	else
		printf("%c %d - ", errpfx, line);
D 3
	printf(a1, a2, a3, a4);
E 3
I 3
	printf(a1, a2, a3, a4, a5);
E 3
	if (errpfx == 'E')
#ifndef PI0
D 2
		eflg++, codeoff();
E 2
I 2
		eflg = TRUE, codeoff();
E 2
#else
D 2
		eflg++;
E 2
I 2
		eflg = TRUE;
E 2
#endif
	errpfx = 'E';
	if (Eholdnl)
D 9
		Eholdnl = 0;
E 9
I 9
		Eholdnl = FALSE;
E 9
	else
		pchr( '\n' );
}

D 9
/*VARAGRS*/
E 9
I 9
/*VARARGS1*/
E 9

D 3
cerror(a1, a2, a3, a4)
E 3
I 3
cerror(a1, a2, a3, a4, a5)
I 9
    char *a1;
E 9
E 3
{

	if (Enocascade)
		return;
	setpfx(' ');
D 3
	error(a1, a2, a3, a4);
E 3
I 3
	error(a1, a2, a3, a4, a5);
E 3
}

#ifdef PI1

/*VARARGS*/

D 3
derror(a1, a2, a3, a4)
E 3
I 3
derror(a1, a2, a3, a4, a5)
I 9
    char *a1, *a2, *a3, *a4, *a5;
E 9
E 3
{

	if (!holdderr)
D 3
		error(a1, a2, a3, a4);
E 3
I 3
		error(a1, a2, a3, a4, a5);
E 3
	errpfx = 'E';
}

char	*lastname, printed, hadsome;

    /*
     *	this yysetfile for PI1 only.
     *	the real yysetfile is in yyput.c
     */
yysetfile(name)
	char *name;
{

	if (lastname == name)
		return;
D 12
	printed =| 1;
E 12
I 12
	printed |= 1;
E 12
	gettime( name );
	printf("%s  %s:\n" , myctime( &tvec ) , name );
	lastname = name;
}
#endif
E 1

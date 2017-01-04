h16119
s 00007/00003/00079
d D 5.1 85/06/05 15:11:44 dist 5 4
c Add copyright
e
s 00000/00000/00082
d D 2.1 84/02/08 20:44:24 aoki 4 3
c synchronize to version 2
e
s 00000/00000/00082
d D 1.3 83/09/19 07:02:14 thien 3 2
c Restoring to unlinted version
e
s 00011/00003/00071
d D 1.2 83/08/19 05:04:41 thien 2 1
c The changes were made to allow successful linting
e
s 00074/00000/00000
d D 1.1 80/08/27 19:57:16 peter 1 0
c date and time created 80/08/27 19:57:16 by peter
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

I 2
#ifndef lint
E 2
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
I 2
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
E 2

#include "whoami.h"
#include "0.h"
I 2
#include "tree_ty.h"	/* must be included for yy.h */
E 2
#include "yy.h"

/*
 * Options processes the option
 * strings which can appear in
 * comments and returns the next character.
 */
options()
{
D 2
	register c, ch;
E 2
I 2
	register c;
#ifdef PI0
	register ch;
#endif
E 2
	register char *optp;
D 2
	int ok;
E 2

	c = readch();
	if (c != '$')
		return (c);
	do {
D 2
		ch = c = readch();
E 2
I 2
		c = readch();
#		ifdef PI0
		ch = c;
#		endif
E 2
		switch (c) {
			case 'b':
				optp = &opt( 'b' );
				c = readch();
				if (!digit(c))
					return (c);
				*optp = c - '0';
				c = readch();
				break;
#		    ifdef PC
			case 'C':
				    /*
				     *	C is a replacement for t, fake it.
				     */
				c = 't';
				/* and fall through */
			case 'g':
#		    endif PC
			case 'k':
			case 'l':
			case 'n':
			case 'p':
			case 's':
			case 't':
			case 'u':
			case 'w':
			case 'z':
				optp = &opt( c );
				c = readch();
				if (c == '+') {
					*optp = 1;
					c = readch();
				} else if (c == '-') {
					*optp = 0;
					c = readch();
				} else {
					return (c);
				}
				break;
			default:
				    return (c);
			}
#ifdef PI0
		send(ROSET, ch, *optp);
#endif
	} while (c == ',');
	if ( opt( 'u' ) )
		setuflg();
	return (c);
}
E 1

h37143
s 00018/00000/00000
d D 5.1 85/08/09 21:45:44 mckusick 1 0
c date and time created 85/08/09 21:45:44 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

# include <stdio.h>

yyerror(s)
	char *s;
{

	fprintf(stderr, "%s\n", s);
}
E 1

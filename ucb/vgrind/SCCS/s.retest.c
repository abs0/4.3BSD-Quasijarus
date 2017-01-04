h42080
s 00009/00001/00063
d D 5.1 85/06/05 09:43:08 dist 2 1
c Add copyright
e
s 00064/00000/00000
d D 4.1 82/10/19 00:52:04 mckusick 1 0
c date and time created 82/10/19 00:52:04 by mckusick
e
u
U
t
T
I 1
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2

#include <ctype.h>

int l_onecase = 0;
char * _start;
char * _escaped;
char * convexp();
char * expmatch();
main()
{
    char reg[132];
    char *ireg;
    char str[132];
    char *match;
    char matstr[132];
    char c;

    while (1) {
	printf ("\nexpr: ");
	scanf ("%s", reg);
	ireg = convexp(reg);
	match = ireg;
	while(*match) {
	    switch (*match) {

	    case '\\':
	    case '(':
	    case ')':
	    case '|':
		printf ("%c", *match);
		break;

	    default:
		if (isalnum(*match))
		    printf("%c", *match);
		else
		    printf ("<%03o>", *match);
		break;
	    }
	    match++;
	}
	printf("\n");
	getchar();
	while(1) {
	    printf ("string: ");
	    match = str;
	    while ((c = getchar()) != '\n')
		*match++ = c;
	    *match = 0;
	    if (str[0] == '#')
		break;
	    matstr[0] = 0;
	    _start = str;
	    _escaped = 0;
	    match = expmatch (str, ireg, matstr);
	    if (match == 0)
		printf ("FAILED\n");
	    else
		printf ("match\nmatstr = %s\n", matstr);
	}

    }
}
E 1

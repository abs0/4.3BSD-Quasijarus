h47151
s 00010/00005/00271
d D 4.7 88/06/18 15:07:38 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00267
d D 4.6 88/05/05 18:33:54 bostic 6 5
c written by Eric Allman; add Berkeley header
e
s 00001/00001/00269
d D 4.5 87/10/22 11:38:49 bostic 5 4
c ANSI C; sprintf now returns an int.
e
s 00007/00001/00263
d D 4.4 86/01/29 16:32:12 mckusick 4 3
c add copyright
e
s 00001/00001/00263
d D 4.3 83/05/28 16:02:44 layer 3 2
c compiler warning
e
s 00012/00011/00252
d D 4.2 83/05/27 00:33:51 layer 2 1
c finished conversion to 4.1c
e
s 00263/00000/00000
d D 4.1 83/03/23 14:59:35 mckusick 1 0
c date and time created 83/03/23 14:59:35 by mckusick
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
E 6
 */

E 4
I 1
#ifndef lint
D 4
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

I 2
# include	<stdio.h>
E 2
# include	"getpar.h"

/**
 **	get integer parameter
 **/

getintpar(s)
char	*s;
{
	register int	i;
	int		n;

	while (1)
	{
		if (testnl() && s)
			printf("%s: ", s);
		i = scanf("%d", &n);
		if (i < 0)
			exit(1);
		if (i > 0 && testterm())
			return (n);
		printf("invalid input; please enter an integer\n");
		skiptonl(0);
	}
}

/**
 **	get floating parameter
 **/

double getfltpar(s)
char	*s;
{
	register int		i;
	double			d;

	while (1)
	{
		if (testnl() && s)
			printf("%s: ", s);
		i = scanf("%lf", &d);
		if (i < 0)
			exit(1);
		if (i > 0 && testterm())
			return (d);
D 2
		printf("invalid input; please enter a float\n");
E 2
I 2
		printf("invalid input; please enter a double\n");
E 2
		skiptonl(0);
	}
}

/**
 **	get yes/no parameter
 **/

D 2
struct cvntab	Yntab[]
E 2
I 2
struct cvntab	Yntab[] =
E 2
{
D 2
	"y",	"es",	1,	0,
	"n",	"o",	0,	0,
E 2
I 2
	"y",	"es",	(int (*)())1,	0,
	"n",	"o",	(int (*)())0,	0,
E 2
	0
};

getynpar(s)
char	*s;
{
	struct cvntab		*r;

	r = getcodpar(s, Yntab);
D 3
	return (r->value);
E 3
I 3
	return ((int) r->value);
E 3
}


/**
 **	get coded parameter
 **/

struct cvntab *getcodpar(s, tab)
char		*s;
struct cvntab	tab[];
{
	char				input[100];
	register struct cvntab		*r;
	int				flag;
	register char			*p, *q;
	int				c;
	int				f;

	flag = 0;
	while (1)
	{
D 2
		flag =| (f = testnl());
E 2
I 2
		flag |= (f = testnl());
E 2
		if (flag)
			printf("%s: ", s);
		if (f)
			cgetc(0);		/* throw out the newline */
		scanf("%*[ \t;]");
		if ((c = scanf("%[^ \t;\n]", input)) < 0)
			exit(1);
		if (c == 0)
			continue;
		flag = 1;

		/* if command list, print four per line */
		if (input[0] == '?' && input[1] == 0)
		{
			c = 4;
			for (r = tab; r->abrev; r++)
			{
				concat(r->abrev, r->full, input);
				printf("%14.14s", input);
				if (--c > 0)
					continue;
				c = 4;
				printf("\n");
			}
			if (c != 4)
				printf("\n");
			continue;
		}

		/* search for in table */
		for (r = tab; r->abrev; r++)
		{
			p = input;
			for (q = r->abrev; *q; q++)
				if (*p++ != *q)
					break;
			if (!*q)
			{
				for (q = r->full; *p && *q; q++, p++)
					if (*p != *q)
						break;
				if (!*p || !*q)
					break;
			}
		}

		/* check for not found */
		if (!r->abrev)
		{
			printf("invalid input; ? for valid inputs\n");
			skiptonl(0);
		}
		else
			return (r);
	}
}


/**
 **	get string parameter
 **/

getstrpar(s, r, l, t)
char	*s;
char	*r;
int	l;
char	*t;
{
	register int	i;
	char		format[20];
	register int	f;

	if (t == 0)
		t = " \t\n;";
D 2
	printf(-1, format, "%%%d[^%s]", l, t);
E 2
I 2
D 5
	sprintf(format, "%%%d[^%s]", l, t);
E 5
I 5
	(void)sprintf(format, "%%%d[^%s]", l, t);
E 5
E 2
	while (1)
	{
		if ((f = testnl()) && s)
			printf("%s: ", s);
		if (f)
			cgetc(0);
		scanf("%*[\t ;]");
		i = scanf(format, r);
		if (i < 0)
			exit(1);
		if (i != 0)
			return;
	}
}


/**
 **	test if newline is next valid character
 **/

testnl()
{
	register char		c;

	while ((c = cgetc(0)) != '\n')
		if ((c >= '0' && c <= '9') || c == '.' || c == '!' ||
				(c >= 'A' && c <= 'Z') ||
				(c >= 'a' && c <= 'z') || c == '-')
		{
D 2
			ungetc(c, 0);
E 2
I 2
			ungetc(c, stdin);
E 2
			return(0);
		}
D 2
	ungetc(c, 0);
E 2
I 2
	ungetc(c, stdin);
E 2
	return (1);
}


/**
 **	scan for newline
 **/

skiptonl(c)
char	c;
{
	while (c != '\n')
		if (!(c = cgetc(0)))
			return;
D 2
	ungetc('\n', 0);
E 2
I 2
	ungetc('\n', stdin);
E 2
	return;
}


/**
 **	test for valid terminator
 **/

testterm()
{
	register char		c;

	if (!(c = cgetc(0)))
		return (1);
	if (c == '.')
		return (0);
	if (c == '\n' || c == ';')
D 2
		ungetc(c, 0);
E 2
I 2
		ungetc(c, stdin);
E 2
	return (1);
}


/*
**  TEST FOR SPECIFIED DELIMETER
**
**	The standard input is scanned for the parameter.  If found,
**	it is thrown away and non-zero is returned.  If not found,
**	zero is returned.
*/

readdelim(d)
char	d;
{
	register char	c;

	while (c = cgetc(0))
	{
		if (c == d)
			return (1);
		if (c == ' ')
			continue;
D 2
		ungetc(c, 0);
E 2
I 2
		ungetc(c, stdin);
E 2
		break;
	}
	return (0);
}
E 1

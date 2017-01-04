h55992
s 00000/00043/00067
d D 5.4 85/10/09 16:04:10 bloom 4 3
c still more fixes from rick@seismo
e
s 00007/00009/00103
d D 5.3 85/06/19 19:22:40 bloom 3 2
c fixes from rick adams
e
s 00014/00017/00098
d D 5.2 85/01/22 14:08:32 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00115/00000/00000
d D 5.1 83/07/02 17:56:53 sam 1 0
c date and time created 83/07/02 17:56:53 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

D 3
#include <stdio.h>
E 3
I 3
#include "uucp.h"
E 3

#define LQUOTE	'('
#define RQUOTE ')'
D 4
#define NOSYSPART	0
#define HASSYSPART	1
E 4

I 3
/*LINTLIBRARY*/
E 3

D 2
/*******
 *	char *
 *	getprm(s, prm)	get next parameter from s
 *	char *s, *prm;
E 2
I 2
/*
 *	get next parameter from s
E 2
 *
 *	return - pointer to next character in s
 */

char *
getprm(s, prm)
register char *s, *prm;
{
	register char *c;
D 3
	char *index();
E 3

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;

	*prm = '\0';
	if (*s == '\0')
D 2
		return(NULL);
E 2
I 2
		return NULL;
E 2

	if (*s == '>' || *s == '<' || *s == '|'
	  || *s == ';' || *s == '&') {
		*prm++ = *s++;
		*prm = '\0';
D 2
		return(s);
E 2
I 2
		return s;
E 2
	}

	/* look for quoted argument */
	if (*s == LQUOTE) {
		if ((c = index(s + 1, RQUOTE)) != NULL) {
			c++;
			while (c != s)
				*prm++ = *s++;
			*prm = '\0';
D 2
			return(s);
E 2
I 2
			return s;
E 2
		}
	}

	/* look for `  ` string */
	if (*s == '`') {
		if ((c = index(s + 1, '`')) != NULL) {
			c++;
			while (c != s)
				*prm++ = *s++;
			*prm = '\0';
D 2
			return(s);
E 2
I 2
			return s;
E 2
		}
	}

	while (*s != ' ' && *s != '\t' && *s != '<'
D 2
	&& *s != '>' && *s != '|' && *s != '\0'
	&& *s != '&' && *s != ';' && *s != '\n')
E 2
I 2
		&& *s != '>' && *s != '|' && *s != '\0'
		&& *s != '&' && *s != ';' && *s != '\n')
E 2
		*prm++ = *s++;
	*prm = '\0';

D 2
	return(s);
E 2
I 2
	return s;
E 2
D 4
}

D 2
/***
 *	split(name, sys, rest)	split into system and file part
 *	char *name, *sys, *rest;
E 2
I 2
/*
 *	split into system and file part
E 2
 *
 *	return codes:
 *		NOSYSPART
 *		HASSYSPART
 */

split(name, sys, rest)
register char *name, *rest;
char *sys;
{
	register char *c;
D 3
	char *index(), *strcpy();
	int i;
E 3
I 3
	register int i;
E 3

	if (*name == LQUOTE) {
		if ((c = index(name + 1, RQUOTE)) != NULL) {
		/* strip off quotes */
			name++;
			while (c != name)
				*rest++ = *name++;
			*rest = '\0';
			*sys = '\0';
D 2
			return(NOSYSPART);
E 2
I 2
			return NOSYSPART;
E 2
		}
	}

	if ((c = index(name, '!')) == NULL) {
		strcpy(rest, name);
		*sys = '\0';
D 2
		return(NOSYSPART);
E 2
I 2
		return NOSYSPART;
E 2
	}

D 3
	*c = '\0';
	for (i = 0; i < 7; i++)
		if ((*sys++ = *name++) == '\0')
			break;
E 3
I 3
	*c++ = '\0';
	strncpy(sys, name, MAXBASENAME);
	sys[MAXBASENAME] = '\0';
E 3

D 3
	strcpy(rest, ++c);
E 3
I 3
	strcpy(rest, c);
E 3
D 2
	return(HASSYSPART);
E 2
I 2
	return HASSYSPART;
E 4
E 2
}
E 1

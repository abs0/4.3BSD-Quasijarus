h41658
s 00002/00000/00096
d D 5.3 85/06/19 19:19:27 bloom 3 2
c lint fix from rick adams
e
s 00011/00012/00085
d D 5.2 85/01/22 14:08:27 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00097/00000/00000
d D 5.1 83/07/02 17:56:50 sam 1 0
c date and time created 83/07/02 17:56:50 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

D 2
#include <stdio.h>
E 2
I 2
#include "uucp.h"
E 2

I 3
/*LINTLIBRARY*/

E 3
D 2
/*******
 *	getargs(s, arps)
 *	char *s, *arps[];
 *
E 2
I 2
/*
E 2
 *	getargs  -  this routine will generate a vector of
 *	pointers (arps) to the substrings in string "s".
 *	Each substring is separated by blanks and/or tabs.
 *
 *	If FANCYARGS is defined, you get the following:
 *	Strings containing blanks may be specified by quoting,
 *	in a manner similar to using the shell.
 *	Control characters are entered by ^X where X is any
 *	character; ^? gets you a rubout and ^^ is a real ^.
 *	Warning (rti!trt): I doubt FANCYARGS is wise, since getargs
 *	is used all over the place.  Its features may be useful
 *	but a separate fancy_getargs() should be called instead.
 *
D 2
 *	return - the number of subfields.
E 2
I 2
 *	return - the number of subfields, or -1 if >= maxargs.
E 2
 */

D 2
getargs(s, arps)
E 2
I 2
getargs(s, arps, maxargs)
E 2
register char *s;
char *arps[];
I 2
int maxargs;
E 2
{
	register int i;
#ifdef	FANCYARGS
	register char *sp;
	register char qchar;
#endif

	i = 0;
#ifndef	FANCYARGS
D 2
	for (;;) {
		arps[i] = NULL;
E 2
I 2
	while (i < maxargs) {
E 2
		while (*s == ' ' || *s == '\t')
			*s++ = '\0';
		if (*s == '\n')
			*s = '\0';
		if (*s == '\0')
			break;
		arps[i++] = s++;
		while (*s != '\0' && *s != ' '
			&& *s != '\t' && *s != '\n')
				s++;
	}
#else
D 2
	for (;;) {
E 2
I 2
	while (i < maxargs) {
E 2
		while (*s == ' ' || *s == '\t')
			++s;
		if (*s == '\n' || *s == '\0')
			break;
		arps[i++] = sp = s;
		qchar = 0;
		while(*s != '\0'  &&  *s != '\n') {
			if (qchar == 0 && (*s == ' ' || *s == '\t')) {
				++s;
				break;
			}
			switch(*s) {
			default:
				*sp++ = *s++;
				break;
			case '^':
				if(*++s == '^')
					*sp++ = '^';
				else if(*s == '?')
					*sp++ = 0177;
				else
					*sp++ = *s & 037;
				s++;
				break;
			case '"':
			case '\'':
				if(qchar == *s) {
					qchar = 0;
					++s;
					break;
				}
				if(qchar)
					*sp++ = *s++;
				else
					qchar = *s++;
				break;
			}
		}
		*sp++ = 0;
	}
D 2
	arps[i] = NULL;
E 2
#endif
D 2
	return(i);
E 2
I 2
	if (i >= maxargs)
		return FAIL;
	arps[i] = NULL;
	return i;
E 2
}
E 1

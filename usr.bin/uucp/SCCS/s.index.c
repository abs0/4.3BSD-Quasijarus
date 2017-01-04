h50662
s 00004/00006/00021
d D 5.2 85/01/22 14:09:12 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00027/00000/00000
d D 5.1 83/07/02 17:57:10 sam 1 0
c date and time created 83/07/02 17:57:10 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>

D 2
/*******
 *	char *
 *	index(str, c)	return pointer to character c
 *	char c, *str;
E 2
I 2
/*
 *	return pointer to character c
E 2
 *
 *	return codes:
 *		NULL  -  character not found
 *		pointer  -  pointer to character
 */

char *
index(str, c)
register char c, *str;
{
	for (; *str != '\0'; str++) {
		if (*str == c)
D 2
			return(str);
E 2
I 2
			return str;
E 2
	}

D 2
	return(NULL);
E 2
I 2
	return NULL;
E 2
}
E 1

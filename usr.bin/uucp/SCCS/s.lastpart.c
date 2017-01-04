h03958
s 00008/00007/00018
d D 5.4 85/06/20 09:54:58 bloom 4 3
c fixes from rick adams
e
s 00001/00001/00024
d D 5.3 85/02/12 09:06:10 ralph 3 2
c return pointer to last name after '/' not '/name'.
e
s 00006/00005/00019
d D 5.2 85/01/22 14:09:19 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00024/00000/00000
d D 5.1 83/07/02 17:57:13 sam 1 0
c date and time created 83/07/02 17:57:13 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

D 4
/*******
 *	char *
 *	lastpart(file)	find last part of file name
 *	char *file;
E 4
I 4
#include "uucp.h"

/*LINTLIBRARY*/

/*
 *	find last part of file name
E 4
 *
 *	return - pointer to last part
 */

char *
lastpart(file)
register char *file;
{
	register char *c;
I 2
D 4
	char *rindex();
E 4
E 2

D 2
	c = file + strlen(file);
	while (c >= file)
		if (*(--c) == '/')
			break;
	return(++c);
E 2
I 2
	c = rindex(file, '/');
D 4
	if (c)
D 3
		return c;
E 3
I 3
		return c + 1;
E 4
I 4
	if (c++)
		return c;
E 4
E 3
	else
		return file;
E 2
}
E 1

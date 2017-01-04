h06552
s 00002/00000/00023
d D 5.4 85/06/19 17:28:08 bloom 4 3
c lint fix from rick adams
e
s 00000/00001/00023
d D 5.3 85/04/10 15:17:52 ralph 3 2
c more changes from rick adams.
e
s 00006/00008/00018
d D 5.2 85/01/22 12:28:43 ralph 2 1
c bug fixes & changes from Rick Adams
e
s 00026/00000/00000
d D 5.1 83/07/02 17:56:19 sam 1 0
c date and time created 83/07/02 17:56:19 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>

I 4
/*LINTLIBRARY*/

E 4
D 2

/*******
E 2
I 2
/*
E 2
 *	anyread		check if anybody can read
D 2
 *	return 0 ok: FAIL not ok
E 2
I 2
 *	return SUCCESS ok: FAIL not ok
E 2
 */
D 2

E 2
anyread(file)
char *file;
{
	struct stat s;

D 2
	if (stat(subfile(file), &s) != 0)
E 2
I 2
	if (stat(subfile(file), &s) < 0)
E 2
		/* for security check a non existant file is readable */
D 2
		return(0);
E 2
I 2
		return SUCCESS;
E 2
	if (!(s.st_mode & ANYREAD))
D 2
		return(FAIL);
	return(0);
E 2
I 2
		return FAIL;
	return SUCCESS;
E 2
}
E 1

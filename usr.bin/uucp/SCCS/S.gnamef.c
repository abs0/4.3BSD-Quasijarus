h38778
s 00002/00001/00039
d D 5.4 85/06/20 09:37:07 bloom 4 3
c fixes from rick adams
e
s 00009/00009/00031
d D 5.3 85/01/22 14:08:48 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00039
d D 5.2 83/07/02 18:05:34 sam 2 1
c include fixes
e
s 00040/00000/00000
d D 5.1 83/07/02 17:57:00 sam 1 0
c date and time created 83/07/02 17:57:00 by sam
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
D 4
#include <sys/types.h>
E 4
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif
I 4

/*LINTLIBRARY*/
E 4

D 3
/*******
 *	gnamef(dirp, filename)	get next file name from directory
 *	DIR *dirp;
 *	char *filename;
E 3
I 3
/*
 *	get next file name from directory
E 3
 *
 *	return codes:
 *		0  -  end of directory read
 *		1  -  returned name
 */

gnamef(dirp, filename)
register DIR *dirp;
register char *filename;
{
	register struct direct *dentp;

D 3
	while (1) {
		if ((dentp = readdir(dirp)) == NULL)
			return(0);
E 3
I 3
	for (;;) {
		if ((dentp = readdir(dirp)) == NULL) {
			return 0;
		}
E 3
		if (dentp->d_ino != 0)
			break;
	}

D 3
	/* Truncate filename.  This may become a problem someday. rti!trt */
E 3
I 3
	/* Truncate filename.  This may become a problem someday. */
E 3
	strncpy(filename, dentp->d_name, NAMESIZE-1);
	filename[NAMESIZE-1] = '\0';
D 3
	return(1);
E 3
I 3
	DEBUG(99,"gnamef returns %s\n",filename);
	return 1;
E 3
}
E 1

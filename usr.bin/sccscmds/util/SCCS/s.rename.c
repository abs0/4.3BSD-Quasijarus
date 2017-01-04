h38082
s 00022/00000/00000
d D 1.1 85/05/03 00:33:26 sam 1 0
c date and time created 85/05/03 00:33:26 by sam
e
u
U
t
T
I 1
# include "../hdr/macros.h"
# include "errno.h"
# include "../hdr/fatal.h"
SCCSID(@(#)rename	2.1);

/*
	rename (unlink/link)
	Calls xlink() and xunlink().
*/

rename(oldname,newname)
char *oldname, *newname;
{
	extern int errno;

	if (unlink(newname) < 0 && errno != ENOENT)
		return(xunlink(newname));

	if (xlink(oldname,newname) == Fvalue)
		return(-1);
	return(xunlink(oldname));
}
E 1

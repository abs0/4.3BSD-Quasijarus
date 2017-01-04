h44865
s 00003/00000/00016
d D 5.3 85/06/23 13:06:19 bloom 3 2
c lint fixes from rick adams
e
s 00002/00004/00014
d D 5.2 85/01/22 14:11:06 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00018/00000/00000
d D 5.1 83/07/02 17:57:35 sam 1 0
c date and time created 83/07/02 17:57:35 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/types.h>

I 3
/*LINTLIBRARY*/

E 3
D 2
/*******
 *	sysacct(bytes, time)	output accounting info
 *	time_t time;
 *	long bytes;
E 2
I 2
/*
 *	output accounting info
E 2
 */

I 3
/*ARGSUSED*/
E 3
sysacct(bytes, time)
time_t time;
long bytes;
{
	return;
}
E 1

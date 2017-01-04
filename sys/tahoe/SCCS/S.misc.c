h36902
s 00005/00003/00011
d R 7.1 88/05/21 18:36:06 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00002/00002/00012
d D 1.2 85/07/29 13:13:28 sam 2 1
c change mtpr parameter order
e
s 00014/00000/00000
d D 1.1 85/07/21 20:20:54 sam 1 0
c date and time created 85/07/21 20:20:54 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../h/types.h"
D 2
#include "../machine/mtpr.h"
E 2
I 2
#include "../tahoe/mtpr.h"
E 2

/*
 * make sure addr is not in cache
 */

uncache(addr)
	char *addr;
{
D 2
	mtpr(addr, PDCS);
E 2
I 2
	mtpr(PDCS, addr);
E 2
}
E 1

h25679
s 00015/00000/00000
d D 4.1 83/02/11 15:44:47 rrh 1 0
c date and time created 83/02/11 15:44:47 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>
#
/* for testing only */
#include "def.h"

testreach()
	{
	VERT v;
	for (v = 0; v < nodenum; ++v)
		fprintf(stderr,"REACH(%d) = %d\n",v,REACH(v));
	}
E 1

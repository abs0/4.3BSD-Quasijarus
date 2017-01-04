h25053
s 00017/00000/00000
d D 4.1 83/02/11 15:44:14 rrh 1 0
c date and time created 83/02/11 15:44:14 by rrh
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
#include "def.h"
int endbuf;

mkgraph()
	{
	if (!parse())
		return(FALSE);
	hash_check();
	hash_free();
	fingraph();
	return(TRUE);
	}
E 1

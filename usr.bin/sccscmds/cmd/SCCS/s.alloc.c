h24347
s 00001/00001/00012
d D 4.2 83/07/03 17:38:09 sam 2 1
c purge sccs.h
e
s 00013/00000/00000
d D 4.1 81/01/15 00:17:47 eric 1 0
c date and time created 81/01/15 00:17:47 by eric
e
u
U
f b 
f i 
t
T
I 1
D 2
# include <sccs.h>
E 2
I 2
#include "../hdr/macros.h"
E 2

SCCSID(%W%);

alloc(i)
	int i;
{
	register char *cp = malloc(i);

	if (cp == 0)
		return (-1);
	return (cp);
}
E 1

h25434
s 00000/00000/00007
d D 4.1 82/05/12 11:14:22 rrh 2 1
c sync to release 4.1
e
s 00007/00000/00000
d D 1.1 82/05/12 11:03:37 rrh 1 0
c date and time created 82/05/12 11:03:37 by rrh
e
u
U
t
T
I 1
static char sccsid[] = "	%M%	%I%	%E%	";

#include <stdio.h>
doemt(code) int code; {
	/* just print a message if not caught */
	fprintf(stderr,"EMT 0%o caught\n",code);
}
E 1

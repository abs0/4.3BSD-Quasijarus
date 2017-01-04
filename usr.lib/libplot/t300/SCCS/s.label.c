h20266
s 00015/00000/00000
d D 4.1 83/06/27 14:09:03 sam 1 0
c date and time created 83/06/27 14:09:03 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "con.h"
label(s)
char *s;
{
	int i,c;
		while((c = *s++) != '\0'){
			xnow += 6;
			spew(c);
		}
		return;
}
E 1

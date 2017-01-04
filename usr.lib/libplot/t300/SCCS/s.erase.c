h19571
s 00011/00000/00000
d D 4.1 83/06/27 14:09:02 sam 1 0
c date and time created 83/06/27 14:09:02 by sam
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
erase(){
	int i;
		for(i=0; i<11*(VERTRESP/VERTRES); i++)
			spew(DOWN);
		return;
}
E 1

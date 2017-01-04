h32285
s 00021/00000/00000
d D 1.1 86/07/05 17:37:39 sam 1 0
c date and time created 86/07/05 17:37:39 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

#include	"vdfmt.h"

/*
**
*/

reset()
{
	indent();
	if(get_yes_no("Confirm delete all operations and reset variables")) {
		print("All operations specified have been deleted.\n");
		exdent(-1);
		_longjmp(reset_environ, 1);
	}
	exdent(1);
}

E 1

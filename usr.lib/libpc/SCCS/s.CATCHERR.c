h49843
s 00002/00002/00013
d D 1.2 81/04/01 22:57:22 mckusic 2 1
c fix dynamic display save
e
s 00015/00000/00000
d D 1.1 81/01/13 13:31:50 mckusick 1 0
c date and time created 81/01/13 13:31:50 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

CATCHERR(err, todo)
	long err;		/* error to be caught */
	struct formalrtn todo;	/* procedure to call to catch error */
{
D 2
	if (todo.cbn == 1)
		_entry[err].entryaddr = todo.entryaddr;
E 2
I 2
	if (todo.fbn == 1)
		_entry[err].fentryaddr = todo.fentryaddr;
E 2
	else
		fputs("procedure not at level 1", stderr);
}
E 1

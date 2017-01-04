h00095
s 00004/00011/00010
d D 1.3 82/11/12 18:58:13 mckusick 3 2
c make error message global var, so routine can be inline expanded
e
s 00008/00002/00013
d D 1.2 81/06/10 00:37:23 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00015/00000/00000
d D 1.1 80/10/30 00:32:49 mckusick 1 0
c date and time created 80/10/30 00:32:49 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 2
#include "h01errs.h"
E 2
I 2
D 3
#define NULL 0
E 3
I 3
char EASRT[] = "Assertion failed\n";
E 3
E 2

D 3
ASRT(cond, stmt)

E 3
I 3
ASRT(cond)
E 3
	short	cond;
D 3
	char	*stmt;
E 3
{
	if (cond)
		return;
D 2
	ERROR(EASRT, stmt);
E 2
I 2
D 3
	if (stmt != NULL) {
		ERROR("Assertion failed: %s\n", stmt);
		return;
	} else {
		ERROR("Assertion failed\n", 0);
		return;
	}
E 3
I 3
	ERROR(EASRT, 0);
	return;
E 3
E 2
}
E 1

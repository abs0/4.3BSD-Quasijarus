h63163
s 00003/00002/00015
d D 1.3 82/11/12 18:58:35 mckusick 3 2
c make error message global var, so routine can be inline expanded
e
s 00001/00002/00016
d D 1.2 81/06/10 00:39:04 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00018/00000/00000
d D 1.1 80/10/30 00:34:05 mckusick 1 0
c date and time created 80/10/30 00:34:05 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
D 2
#include "h01errs.h"
E 2

I 3
char ENIL[] = "Pointer value out of legal range\n";

E 3
char *
NIL(ptr)
D 3

E 3
	char	*ptr;		/* pointer to struct */
{
	if (ptr > _maxptr || ptr < _minptr) {
D 2
		ERROR(ENILPTR, 0);
E 2
I 2
D 3
		ERROR("Pointer value out of legal range\n", 0);
E 3
I 3
		ERROR(ENIL, 0);
E 3
E 2
		return;
	}
	return ptr;
}
E 1

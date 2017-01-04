h59374
s 00003/00001/00012
d D 1.3 82/11/12 18:58:29 mckusick 3 2
c make error message global var, so routine can be inline expanded
e
s 00001/00002/00012
d D 1.2 81/06/10 00:38:19 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00014/00000/00000
d D 1.1 80/10/30 00:33:38 mckusick 1 0
c date and time created 80/10/30 00:33:38 by mckusick
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
char ELINO[] = "Statement count limit of %D exceeded\n";

E 3
LINO()
{
	if (++_stcnt >= _stlim) {
D 2
		ERROR(ESTLIM, _stcnt);
E 2
I 2
D 3
		ERROR("Statement count limit of %D exceeded\n", _stcnt);
E 3
I 3
		ERROR(ELINO, _stcnt);
E 3
E 2
		return;
	}
}
E 1

h45224
s 00001/00002/00015
d D 1.2 81/06/10 00:44:25 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00017/00000/00000
d D 1.1 80/10/30 00:35:48 mckusick 1 0
c date and time created 80/10/30 00:35:48 by mckusick
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

STLIM(limit)

	long	limit;
{
	if (_stcnt >= limit) {
D 2
		ERROR(ESTLIM, _stcnt);
E 2
I 2
		ERROR("Statement count limit of %D exceeded\n", _stcnt);
E 2
		return;
	}
	_stlim = limit;
}
E 1

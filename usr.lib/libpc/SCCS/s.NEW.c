h10458
s 00001/00002/00023
d D 1.3 81/06/10 00:38:49 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00002/00002/00023
d D 1.2 81/03/07 15:58:45 mckusic 2 1
c merge in onyx changes
e
s 00025/00000/00000
d D 1.1 80/10/30 00:33:59 mckusick 1 0
c date and time created 80/10/30 00:33:59 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
D 3
#include "h01errs.h"
E 3

NEW(var, size)
	char	**var;	/* pointer to item being deallocated */
D 2
	int	size;	/* sizeof struct pointed to by var */
E 2
I 2
	long	size;	/* sizeof struct pointed to by var */
E 2
{
	extern	char *malloc();
	char 	*memblk;

D 2
	memblk = malloc(size);
E 2
I 2
	memblk = malloc((int)size);
E 2
	if (memblk == 0) {
D 3
		ERROR(EOUTOFMEM,0);
E 3
I 3
		ERROR("Ran out of memory\n", 0);
E 3
		return;
	}
	*var = memblk;
	if (memblk < _minptr)
		_minptr = memblk;
	if (memblk + size > _maxptr)
		_maxptr = memblk + size;
}
E 1

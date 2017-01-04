h09409
s 00001/00002/00022
d D 1.3 81/06/10 00:37:37 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00004/00002/00020
d D 1.2 81/03/07 15:54:28 mckusic 2 1
c merge in onyx changes
e
s 00022/00000/00000
d D 1.1 80/10/30 00:33:06 mckusick 1 0
c date and time created 80/10/30 00:33:06 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include	"h00vars.h"
D 3
#include	"h01errs.h"
E 3

D 2
DISPOSE(var, size)
E 2
I 2
DISPOSE(var, siz)
E 2
	register char	**var;	/* pointer to pointer being deallocated */
D 2
	int		size;	/* sizeof(bletch) */
E 2
I 2
	long		siz;	/* sizeof(bletch) */
E 2
{
I 2
	register int size = siz;

E 2
	if (*var == 0 || *var + size > _maxptr || *var < _minptr) {
D 3
		ERROR(ENILPTR,0);
E 3
I 3
		ERROR("Pointer value out of legal range\n", 0);
E 3
		return;
	}
	free(*var);
	if (*var == _minptr)
		_minptr += size;
	if (*var + size == _maxptr)
		_maxptr -= size;
	*var = (char *)(0);
}
E 1

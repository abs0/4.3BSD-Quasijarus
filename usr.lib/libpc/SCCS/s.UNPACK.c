h48371
s 00001/00002/00039
d D 1.3 81/06/10 00:44:50 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00005/00005/00036
d D 1.2 81/03/07 16:05:30 mckusic 2 1
c merge in onyx changes
e
s 00041/00000/00000
d D 1.1 80/10/30 00:36:13 mckusick 1 0
c date and time created 80/10/30 00:36:13 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 3
#include "h01errs.h"
E 3

/*
 * unpack(z,a,i)
 *
 * with:	z and a as in pack
 *
 * semantics:	for j := u to v do
 *			a[j-u+i] := z[j]
 */

UNPACK(i, a, z, size_a, lb_a, ub_a, size_z)

D 2
	int	i;	/* subscript into a to begin packing */
E 2
I 2
	long	i;	/* subscript into a to begin packing */
E 2
	char	*a;	/* pointer to structure a */
	char	*z;	/* pointer to structure z */
D 2
	int	size_a;	/* sizeof(a_type) */
	int	lb_a;	/* lower bound of structure a */
	int	ub_a;	/* (upper bound of a) - (lb_a + sizeof(z_type)) */
	int	size_z;	/* sizeof(z_type) */
E 2
I 2
	long	size_a;	/* sizeof(a_type) */
	long	lb_a;	/* lower bound of structure a */
	long	ub_a;	/* (upper bound of a) - (lb_a + sizeof(z_type)) */
	long	size_z;	/* sizeof(z_type) */
E 2
{
	int		subscr;
	register char	*cp;
	register char	*zp = z;
	register char	*limit;

	subscr = i - lb_a;
	if (subscr < 0 || subscr > ub_a) {
D 3
		ERROR(EPACK, i);
E 3
I 3
		ERROR("i = %D: Bad i to unpack(z,a,i)\n", i);
E 3
		return;
	}
	cp = &a[subscr * size_a];
	limit = cp + size_z;
	do	{
		*cp++ = *zp++;
	} while (cp < limit);
}
E 1

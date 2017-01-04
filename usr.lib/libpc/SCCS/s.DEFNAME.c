h44103
s 00002/00003/00014
d D 1.2 81/03/07 15:54:12 mckusic 2 1
c merge in onyx changes
e
s 00017/00000/00000
d D 1.1 80/10/30 00:33:04 mckusick 1 0
c date and time created 80/10/30 00:33:04 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 2

E 2
#include "h00vars.h"

DEFNAME(filep, name, maxnamlen, datasize)

	register struct iorec	*filep;
	char			*name;
D 2
	int			maxnamlen;
	int			datasize;
E 2
I 2
	long			maxnamlen;
	long			datasize;
E 2
{
	filep = GETNAME(filep, name, maxnamlen, datasize);
	filep->funit |= FDEF;
}
E 1

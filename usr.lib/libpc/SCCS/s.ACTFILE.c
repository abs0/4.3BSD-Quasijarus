h24487
s 00013/00000/00000
d D 1.1 80/10/30 00:32:42 mckusick 1 0
c date and time created 80/10/30 00:32:42 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

FILE *
ACTFILE(curfile)

	struct iorec	*curfile;
{
	return curfile->fbuf;
}
E 1

h63741
s 00007/00005/00016
d D 1.3 81/06/17 00:39:46 mckusic 3 2
c change to allow any type of files
e
s 00001/00000/00020
d D 1.2 81/03/07 16:04:37 mckusic 2 1
c merge in onyx changes
e
s 00020/00000/00000
d D 1.1 81/01/16 19:34:08 mckusick 1 0
c date and time created 81/01/16 19:34:08 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

/*
 * Find current location
 */
I 2
D 3
long
E 3
I 3
struct seekptr
E 3
E 2
TELL(curfile)

	register struct iorec	*curfile;
{
D 3
	long loc;
E 3
I 3
	struct seekptr loc;
E 3

D 3
	loc = ftell(curfile);
	if ((curfile->funit | SYNC) == 0)
		loc += 1;
E 3
I 3
	if ((curfile->funit & FREAD) && (curfile->funit & SYNC) == 0) {
		fseek(curfile->fbuf, -curfile->fsize, 1);
		curfile->funit |= SYNC;
	}
	loc.cnt = ftell(curfile->fbuf);
E 3
	return loc;
}
E 1

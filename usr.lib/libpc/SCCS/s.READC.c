h02205
s 00003/00003/00023
d D 1.2 81/06/10 00:43:54 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00026/00000/00000
d D 1.1 80/10/30 00:34:42 mckusick 1 0
c date and time created 80/10/30 00:34:42 by mckusick
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

char
READC(curfile)

	register struct iorec	*curfile;
{
	char			data;

	if (curfile->funit & FWRITE) {
D 2
		ERROR(EREADIT, curfile->pfname);
E 2
I 2
		ERROR("%s: Attempt to read, but open for writing\n",
			curfile->pfname);
E 2
		return;
	}
	IOSYNC(curfile);
	if (curfile->funit & EOFF) {
D 2
		ERROR(EPASTEOF, curfile->pfname);
E 2
I 2
		ERROR("%s: Tried to read past end of file\n", curfile->pfname);
E 2
		return;
	}
	curfile->funit |= SYNC;
	return *curfile->fileptr;
}
E 1

h58298
s 00001/00002/00020
d D 1.2 81/06/10 00:45:29 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00022/00000/00000
d D 1.1 80/10/31 14:45:07 mckusick 1 0
c date and time created 80/10/31 14:45:07 by mckusick
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

APPEND(filep)

	register struct iorec	*filep;
{
	filep = GETNAME (filep, 0, 0, 0);
	filep->fbuf = fopen(filep->fname, "a");
	if (filep->fbuf == NULL) {
D 2
		ERROR(EOPEN, filep->pfname);
E 2
I 2
		PERROR("Could not open ", filep->pfname);
E 2
		return;
	}
	filep->funit |= (EOFF | FWRITE);
	if (filep->fblk > PREDEF) {
		setbuf(filep->fbuf, &filep->buf[0]);
	}
}
E 1

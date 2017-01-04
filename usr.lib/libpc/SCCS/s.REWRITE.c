h10410
s 00001/00002/00023
d D 1.3 81/06/10 00:44:12 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00002/00002/00023
d D 1.2 81/03/07 16:02:51 mckusic 2 1
c merge in onyx changes
e
s 00025/00000/00000
d D 1.1 80/10/30 00:35:27 mckusick 1 0
c date and time created 80/10/30 00:35:27 by mckusick
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

REWRITE(filep, name, maxnamlen, datasize)

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
	filep = GETNAME (filep, name, maxnamlen, datasize);
	filep->fbuf = fopen(filep->fname, "w");
	if (filep->fbuf == NULL) {
D 3
		ERROR(ECREATE, filep->pfname);
E 3
I 3
		PERROR("Could not create ",filep->pfname);
E 3
		return;
	}
	filep->funit |= (EOFF | FWRITE);
	if (filep->fblk > PREDEF) {
		setbuf(filep->fbuf, &filep->buf[0]);
	}
}
E 1

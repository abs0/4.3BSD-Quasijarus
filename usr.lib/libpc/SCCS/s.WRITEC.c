h19780
s 00003/00003/00020
d D 1.4 81/06/10 00:44:59 mckusic 5 4
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00002/00002/00021
d D 1.3 81/03/10 00:40:56 mckusic 4 2
c onyx optimizations
e
s 00000/00000/00023
d R 1.3 81/03/10 00:30:52 mckusic 3 2
c onyx optimizations
e
s 00003/00002/00020
d D 1.2 81/03/07 16:06:00 mckusic 2 1
c merge in onyx changes
e
s 00022/00000/00000
d D 1.1 80/10/30 00:36:21 mckusick 1 0
c date and time created 80/10/30 00:36:21 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
D 5
#include "h01errs.h"
E 5

WRITEC(curfile, d1, d2)

	register struct iorec	*curfile;
D 2
	int			d1, d2;
E 2
I 2
D 4
	long			d1;
E 4
I 4
	char			d1;
E 4
	FILE			*d2;
E 2
{
	if (curfile->funit & FREAD) {
D 5
		ERROR(EWRITEIT, curfile->pfname);
E 5
I 5
		ERROR("%s: Attempt to write, but open for reading\n",
			curfile->pfname);
E 5
		return;
	}
D 2
	fputc(d1, d2);
E 2
I 2
D 4
	fputc((char)d1, d2);
E 4
I 4
	fputc(d1, d2);
E 4
E 2
	if (ferror(curfile->fbuf)) {
D 5
		ERROR(EWRITE, curfile->pfname);
E 5
I 5
		PERROR("Could not write to ", curfile->pfname);
E 5
		return;
	}
}
E 1

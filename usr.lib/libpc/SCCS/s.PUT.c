h11052
s 00003/00003/00018
d D 1.3 81/06/10 00:39:39 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00001/00020
d D 1.2 81/03/07 15:59:43 mckusic 2 1
c merge in onyx changes
e
s 00021/00000/00000
d D 1.1 80/10/30 00:34:30 mckusick 1 0
c date and time created 80/10/30 00:34:30 by mckusick
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

PUT(curfile)

	register struct iorec	*curfile;
{
	if (curfile->funit & FREAD) {
D 3
		ERROR(EWRITEIT, curfile->pfname);
E 3
I 3
		ERROR("%s: Attempt to write, but open for reading\n",
			curfile->pfname);
E 3
		return;
	}
D 2
	fwrite(curfile->fileptr, curfile->fsize, 1, curfile->fbuf);
E 2
I 2
	fwrite(curfile->fileptr, (int)curfile->fsize, 1, curfile->fbuf);
E 2
	if (ferror(curfile->fbuf)) {
D 3
		ERROR(EWRITE, curfile->pfname);
E 3
I 3
		PERROR("Could not write to ", curfile->pfname);
E 3
		return;
	}
}
E 1

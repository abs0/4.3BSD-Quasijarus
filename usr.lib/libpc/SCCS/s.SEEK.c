h14743
s 00001/00000/00020
d D 1.4 81/11/22 17:07:49 mckusic 4 3
c clear EOF and EOLN after performing a seek
e
s 00003/00003/00017
d D 1.3 81/06/17 00:39:50 mckusic 3 2
c change to allow any type of files
e
s 00001/00002/00019
d D 1.2 81/06/10 00:44:20 mckusic 2 1
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00021/00000/00000
d D 1.1 80/10/30 00:35:40 mckusick 1 0
c date and time created 80/10/30 00:35:40 by mckusick
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

/*
 * Random access routine
 */
SEEK(curfile, loc)

	register struct iorec	*curfile;
D 3
	long			loc;
E 3
I 3
	struct seekptr		*loc;
E 3
{
	curfile->funit |= SYNC;
I 4
	curfile->funit &= ~(EOFF | EOLN | SPEOLN);
E 4
D 3
	if (fseek(curfile->fbuf, loc, 0) == -1) {
D 2
		ERROR(ESEEK, curfile->pfname);
E 2
I 2
		PERROR("Could not reset ", curfile->pfname);
E 3
I 3
	if (fseek(curfile->fbuf, loc->cnt, 0) == -1) {
		PERROR("Could not seek ", curfile->pfname);
E 3
E 2
		return;
	}
}
E 1

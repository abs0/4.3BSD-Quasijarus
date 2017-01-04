h14935
s 00002/00003/00022
d D 1.3 81/06/10 00:37:52 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00000/00004/00025
d D 1.2 81/01/24 15:13:27 mckusic 2 1
c set file^ to blank on eof (for text files)
e
s 00029/00000/00000
d D 1.1 80/10/30 00:33:16 mckusick 1 0
c date and time created 80/10/30 00:33:16 by mckusick
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

char *
FNIL(curfile)

	register struct iorec	*curfile;
{
	if (curfile->fblk >= MAXFILES || _actfile[curfile->fblk] != curfile) {
D 3
		ERROR(ENOFILE, 0);
E 3
I 3
		ERROR("Reference to an inactive file\n", 0);
E 3
		return;
	}
	if (curfile->funit & FDEF) {
D 3
		ERROR(EREFINAF, curfile->pfname);
E 3
I 3
		ERROR("%s: Reference to an inactive file\n", curfile->pfname);
E 3
		return;
	}
	if (curfile->funit & FREAD) {
		IOSYNC(curfile);
D 2
		if (curfile->funit & EOFF) {
			ERROR(EPASTEOF, curfile->pfname);
			return;
		}
E 2
	}
	return curfile->fileptr;
}
E 1

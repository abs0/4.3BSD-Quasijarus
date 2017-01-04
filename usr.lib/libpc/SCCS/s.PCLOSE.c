h05437
s 00001/00001/00022
d D 1.6 83/01/21 18:58:04 mckusick 7 6
c fix for prematurely removing temp files
e
s 00006/00021/00017
d D 1.5 82/08/29 21:32:47 mckusick 6 5
c remove restriction on files in dynamic structures
e
s 00003/00003/00035
d D 1.4 81/06/10 00:39:22 mckusic 5 4
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00001/00037
d D 1.3 81/01/15 17:57:43 mckusic 4 3
c fix typo on previous delta
e
s 00004/00000/00034
d D 1.2 81/01/10 17:21:14 mckusic 3 1
c flush and release buffers before closing files
e
s 00002/00000/00034
d R 1.2 81/01/09 13:53:54 mckusic 2 1
c release buffers before closing files
e
s 00034/00000/00000
d D 1.1 80/10/30 00:34:15 mckusick 1 0
c date and time created 80/10/30 00:34:15 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 6
/*
 * Close all files associated with the topmost stack frame.
 */

E 6
#include "h00vars.h"
I 6
#include "libpc.h"
E 6
D 5
#include "h01errs.h"
E 5

PCLOSE(level)

	struct iorec		*level;
{
	register struct iorec	*next;

	next = _fchain.fchain;
	while(next != FILNIL && next->flev <= level) {
D 6
		if (next->fbuf != 0) {
			if ((next->funit & FDEF) == 0) {
I 3
				if (next->fblk > PREDEF) {
D 4
					fflush(next->fblk);
E 4
I 4
					fflush(next->fbuf);
E 4
					setbuf(next->fbuf, NULL);
				}
E 3
				fclose(next->fbuf);
				if (ferror(next->fbuf)) {
D 5
					ERROR(ECLOSE, next->pfname);
E 5
I 5
					ERROR("%s: Close failed\n",
						next->pfname);
E 5
					return;
				}
			}
			if ((next->funit & TEMP) != 0 &&
			    unlink(next->pfname)) {
D 5
				ERROR(EREMOVE, next->pfname);
E 5
I 5
				PERROR("Could not remove ", next->pfname);
E 5
				return;
			}
		}
		_actfile[next->fblk] = FILNIL;
		next = next->fchain;
E 6
I 6
D 7
		next = PFCLOSE(next);
E 7
I 7
		next = PFCLOSE(next, TRUE);
E 7
E 6
	}
	_fchain.fchain = next;
}
E 1

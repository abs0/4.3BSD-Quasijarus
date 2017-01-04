h56814
s 00004/00005/00016
d D 1.2 83/01/21 18:58:15 mckusick 2 1
c fix for prematurely removing temp files
e
s 00021/00000/00000
d D 1.1 80/10/30 00:34:24 mckusick 1 0
c date and time created 80/10/30 00:34:24 by mckusick
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
 * insure that a usable image is in the buffer window
 */
PFLUSH()
{
	register struct iorec	*next;

D 2
	next = _fchain.fchain;
	while(next != FILNIL) {
		if ((next->funit & (FDEF | FREAD)) == 0) {
E 2
I 2
	for (next = _fchain.fchain; next != FILNIL; next = next->fchain) {
		if ((next->funit & (FDEF | FREAD)) != 0)
			continue;
		if (next->fbuf != 0)
E 2
			fflush(next->fbuf);
D 2
		}
		next = next->fchain;
E 2
	}
}
E 1

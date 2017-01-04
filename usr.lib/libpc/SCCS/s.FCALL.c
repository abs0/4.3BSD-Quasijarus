h01842
s 00003/00003/00011
d D 1.4 82/11/12 14:48:27 mckusick 5 3
c make size last arg to blkcpy and blkclr to be compatable with bcopy and bcmp
e
s 00005/00005/00009
d R 1.4 81/06/08 00:37:51 mckusic 4 3
c put display save area back into formal routine structure
e
s 00005/00007/00009
d D 1.3 81/04/01 22:15:43 mckusic 3 2
c mods for dynamically allocating display save area before formal calls
e
s 00006/00011/00010
d D 1.2 81/03/07 15:55:49 mckusic 2 1
c merge in onyx changes
e
s 00021/00000/00000
d D 1.1 80/10/30 00:33:12 mckusick 1 0
c date and time created 80/10/30 00:33:12 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"

I 2
D 3
long *
E 2
FCALL(frtn)
E 3
I 3
FCALL(save, frtn)
	char *save;
E 3
	register struct formalrtn *frtn;
{
D 2
	register struct display *dp;
	register struct display *ds;
	struct display *limit;

	limit = &frtn->disp[2 * frtn->cbn];
	for (dp = &_disply[1], ds = &frtn->disp[frtn->cbn]; ds < limit; )
		*ds++ = *dp++;
	limit = &frtn->disp[frtn->cbn];
	for (ds = &frtn->disp[0], dp = &_disply[1]; ds < limit; )
		*dp++ = *ds++;
	return (long)(frtn->entryaddr);
E 2
I 2
D 3
	blkcpy(frtn->cbn * sizeof(struct display),
	       &_disply[1], &frtn->disp[frtn->cbn]);
	blkcpy(frtn->cbn * sizeof(struct display),
	       &frtn->disp[0], &_disply[1]);
	return (long *)(frtn->entryaddr);
E 3
I 3
D 5
	blkcpy(frtn->fbn * sizeof(struct display), &_disply[1], save);
	blkcpy(frtn->fbn * sizeof(struct display), &frtn->fdisp[0],
		&_disply[1]);
E 5
I 5
	blkcpy(&_disply[1], save, frtn->fbn * sizeof(struct display));
	blkcpy(&frtn->fdisp[0], &_disply[1],
		frtn->fbn * sizeof(struct display));
E 5
E 3
E 2
}
E 1

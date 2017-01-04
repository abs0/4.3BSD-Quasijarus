h47589
s 00002/00002/00039
d D 1.4 84/05/19 13:50:15 mckusick 4 3
c bug fix from Michael Tuke and John Carey
e
s 00002/00003/00039
d D 1.3 81/06/10 00:44:05 mckusic 3 2
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00003/00002/00039
d D 1.2 81/03/07 16:02:23 mckusic 2 1
c merge in onyx changes
e
s 00041/00000/00000
d D 1.1 80/10/30 00:35:19 mckusick 1 0
c date and time created 80/10/30 00:35:19 by mckusick
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

D 2
REMOVE(name, maxnamlen)
E 2
I 2
REMOVE(name, namlim)
E 2

	char			*name;
D 2
	int			maxnamlen;
E 2
I 2
	long			namlim;
E 2
{
	register int	cnt;
I 2
	register int	maxnamlen = namlim;
E 2
	char		namebuf[NAMSIZ];

	/*
	 * trim trailing blanks, and insure that the name 
	 * will fit into the file structure
	 */
D 4
	for (cnt = 0; cnt < maxnamlen; )
		if (name[cnt] == '\0' || name[cnt++] == ' ')
E 4
I 4
	for (cnt = 0; cnt < maxnamlen; cnt++)
		if (name[cnt] == '\0' || name[cnt] == ' ')
E 4
			break;
	if (cnt >= NAMSIZ) {
D 3
		ERROR(ENAMESIZE, name);
E 3
I 3
		ERROR("%s: File name too long\n", name);
E 3
		return;
	}
	maxnamlen = cnt;
	/*
	 * put the name into the buffer with null termination
	 */
	for (cnt = 0; cnt < maxnamlen; cnt++)
		namebuf[cnt] = name[cnt];
	namebuf[cnt] = '\0';
	/*
	 * unlink the file
	 */
	if (unlink(namebuf)) {
D 3
		ERROR(EREMOVE, namebuf);
E 3
I 3
		PERROR("Could not remove ", namebuf);
E 3
		return;
	}
}
E 1

h39013
s 00011/00005/00060
d D 5.4 88/02/18 17:04:31 bostic 10 9
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00003/00064
d D 5.3 87/05/18 12:28:52 edward 9 8
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00066
d D 5.2 85/06/21 17:14:43 mckusick 8 7
c botched copyright
e
s 00007/00001/00060
d D 5.1 85/06/06 10:45:21 dist 7 6
c Add copyright
e
s 00003/00003/00058
d D 2.3 83/08/11 22:20:27 sam 6 5
c standardize sccs keyword lines
e
s 00004/00002/00057
d D 2.2 82/07/28 15:37:22 kurt 5 4
c changed demail to truncate mailbox if unlinking fails 
c 
e
s 00000/00000/00059
d D 2.1 81/07/01 11:10:49 kurt 4 3
c Release to Heidi Stettner
e
s 00004/00001/00055
d D 1.3 81/01/05 17:37:27 kas 3 2
c now honors a flag "keep" to avoid removing your mailbox
e
s 00001/00001/00055
d D 1.2 80/10/17 00:39:12 kas 2 1
c max user name size changed to PATHSIZE
e
s 00056/00000/00000
d D 1.1 80/10/08 09:52:17 kas 1 0
c date and time created 80/10/08 09:52:17 by kas
e
u
U
f b 
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
 */

E 7
I 1
D 6
#
E 6
I 6
D 10
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
E 8
D 7
#endif
E 7
I 7
#endif not lint
E 10
I 10
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 10
E 7
E 6

/*
 * Mail -- a mail program
 *
 * Version 7
 *
 * Local routines that are installation dependent.
 */

#include "rcv.h"
D 6

static char *SccsId = "%W% %G%";
E 6

/*
 * Locate the user's mailbox file (ie, the place where new, unread
 * mail is queued).  In Version 7, it is in /usr/spool/mail/name.
 */

findmail()
{
D 9
	register char *cp;
E 9

D 9
	cp = copy("/usr/spool/mail/", mailname);
	copy(myname, cp);
E 9
I 9
	strcpy(copy("/usr/spool/mail/", mailname), myname);
E 9
	if (isdir(mailname)) {
		stradd(mailname, '/');
		strcat(mailname, myname);
	}
}

/*
 * Get rid of the queued mail.
 */

demail()
{

D 3
	remove(mailname);
E 3
I 3
	if (value("keep") != NOSTR)
		close(creat(mailname, 0666));
D 5
	else
		remove(mailname);
E 5
I 5
	else {
		if (remove(mailname) < 0)
			close(creat(mailname, 0666));
	}
E 5
E 3
}

/*
 * Discover user login name.
 */

username(uid, namebuf)
	char namebuf[];
{
	register char *np;

	if (uid == getuid() && (np = getenv("USER")) != NOSTR) {
D 2
		strncpy(namebuf, np, 9);
E 2
I 2
		strncpy(namebuf, np, PATHSIZE);
E 2
		return(0);
	}
	return(getname(uid, namebuf));
}
E 1

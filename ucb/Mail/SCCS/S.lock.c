h51456
s 00001/00001/00101
d D 5.2 85/06/21 17:12:12 mckusick 8 7
c botched copyright
e
s 00007/00001/00095
d D 5.1 85/06/06 10:37:04 dist 7 6
c Add copyright
e
s 00003/00003/00093
d D 2.4 83/08/11 22:17:35 sam 6 5
c standardize sccs keyword lines
e
s 00000/00000/00096
d D 2.3 82/10/05 22:35:45 eric 5 4
x 2
c restore locking protocol to agree with /bin/mail -- someday v6mail also
e
s 00002/00002/00094
d D 2.2 81/08/12 17:15:12 kurt 4 3
c increased time to discard lock from 30 seconds to 5 minutes for Ernie slowvax
e
s 00000/00000/00096
d D 2.1 81/07/01 11:09:45 kurt 3 2
c Release to Heidi Stettner
e
s 00001/00001/00095
d D 1.2 81/05/18 15:52:15 kurt 2 1
c changed locking protocol to agree with what v6mail uses
e
s 00096/00000/00000
d D 1.1 80/10/08 09:50:40 kas 1 0
c date and time created 80/10/08 09:50:40 by kas
e
u
U
f b 
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 6
#
E 6
I 6
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
E 7
E 6

/*
 * A mailing program.
 *
 * Stuff to do version 7 style locking.
 */

#include "rcv.h"
#include <sys/stat.h>
D 6

static char *SccsId = "%W% %G%";
E 6

D 2
char	*maillock	= ".lock";		/* Lock suffix for mailname */
E 2
I 2
char	*maillock	= ".mail";		/* Lock suffix for mailname */
E 2
char	*lockname	= "/usr/spool/mail/tmXXXXXX";
char	locktmp[30];				/* Usable lock temporary */
static char		curlock[50];		/* Last used name of lock */
static	int		locked;			/* To note that we locked it */

/*
 * Lock the specified mail file by setting the file mailfile.lock.
 * We must, of course, be careful to remove the lock file by a call
 * to unlock before we stop.  The algorithm used here is to see if
 * the lock exists, and if it does, to check its modify time.  If it
D 4
 * is older than 30 seconds, we assume error and set our own file.
E 4
I 4
 * is older than 5 minutes, we assume error and set our own file.
E 4
 * Otherwise, we wait for 5 seconds and try again.
 */

lock(file)
char *file;
{
	register int f;
	struct stat sbuf;
	long curtime;

	if (file == NOSTR) {
		printf("Locked = %d\n", locked);
		return(0);
	}
	if (locked)
		return(0);
	strcpy(curlock, file);
	strcat(curlock, maillock);
	strcpy(locktmp, lockname);
	mktemp(locktmp);
	remove(locktmp);
	for (;;) {
		f = lock1(locktmp, curlock);
		if (f == 0) {
			locked = 1;
			return(0);
		}
		if (stat(curlock, &sbuf) < 0)
			return(0);
		time(&curtime);
D 4
		if (curtime < sbuf.st_ctime + 30) {
E 4
I 4
		if (curtime < sbuf.st_ctime + 300) {
E 4
			sleep(5);
			continue;
		}
		remove(curlock);
	}
}

/*
 * Remove the mail lock, and note that we no longer
 * have it locked.
 */

unlock()
{

	remove(curlock);
	locked = 0;
}

/*
 * Attempt to set the lock by creating the temporary file,
 * then doing a link/unlink.  If it fails, return -1 else 0
 */

lock1(tempfile, name)
	char tempfile[], name[];
{
	register int fd;

	fd = creat(tempfile, 0);
	if (fd < 0)
		return(-1);
	close(fd);
	if (link(tempfile, name) < 0) {
		remove(tempfile);
		return(-1);
	}
	remove(tempfile);
	return(0);
}
E 1

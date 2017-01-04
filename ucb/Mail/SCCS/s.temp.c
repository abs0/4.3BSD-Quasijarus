h51706
s 00011/00005/00068
d D 5.4 88/02/18 17:04:28 bostic 10 9
c written by Kurt Shoens; added Berkeley specific header
e
s 00011/00017/00062
d D 5.3 87/05/18 12:28:50 edward 9 8
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00078
d D 5.2 85/06/21 17:14:23 mckusick 8 7
c botched copyright
e
s 00007/00001/00072
d D 5.1 85/06/06 10:44:31 dist 7 6
c Add copyright
e
s 00003/00003/00070
d D 2.3 83/08/11 22:20:16 sam 6 5
c standardize sccs keyword lines
e
s 00000/00001/00073
d D 2.2 82/06/24 23:54:07 kurt 5 4
c Removed the silly need to set mailname = mailspace since now 
c mailname is an array in its own right. 
c 
e
s 00000/00000/00074
d D 2.1 81/07/01 11:10:33 kurt 4 3
c Release to Heidi Stettner
e
s 00007/00004/00067
d D 1.3 80/10/31 09:18:09 kas 3 2
c Now if you Mail -u unknownUserName, we catch it immediately,
c give error and die
e
s 00001/00001/00070
d D 1.2 80/10/17 00:37:48 kas 2 1
c user name maximum size changed to PATHNAME from 8 in anticipation
c of larger user names in our system
e
s 00071/00000/00000
d D 1.1 80/10/08 09:51:29 kas 1 0
c date and time created 80/10/08 09:51:29 by kas
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

#include "rcv.h"

/*
 * Mail -- a mail program
 *
 * Give names to all the temporary files that we will need.
 */
D 6

static char *SccsId = "%W% %G%";
E 6

char	tempMail[14];
char	tempQuit[14];
char	tempEdit[14];
char	tempSet[14];
char	tempResid[14];
char	tempMesg[14];

tinit()
{
D 9
	register char *cp, *cp2;
E 9
I 9
	register char *cp;
E 9
D 2
	char uname[9];
E 2
I 2
	char uname[PATHSIZE];
E 2
D 9
	register int err = 0;
E 9
	register int pid;
I 9
	uid_t getuid();
E 9

	pid = getpid();
	sprintf(tempMail, "/tmp/Rs%05d", pid);
	sprintf(tempResid, "/tmp/Rq%05d", pid);
	sprintf(tempQuit, "/tmp/Rm%05d", pid);
	sprintf(tempEdit, "/tmp/Re%05d", pid);
	sprintf(tempSet, "/tmp/Rx%05d", pid);
	sprintf(tempMesg, "/tmp/Rx%05d", pid);

	if (strlen(myname) != 0) {
		uid = getuserid(myname);
D 3
		if (uid == -1)
			goto youlose;
E 3
I 3
		if (uid == -1) {
			printf("\"%s\" is not a user of this system\n",
			    myname);
			exit(1);
		}
E 3
	}
	else {
D 9
		uid = getuid() & UIDMASK;
E 9
I 9
		uid = getuid();
E 9
		if (username(uid, uname) < 0) {
D 9
			copy("ubluit", myname);
D 3
youlose:
E 3
			err++;
E 9
I 9
			strcpy(myname, "ubluit");
E 9
			if (rcvmode) {
				printf("Who are you!?\n");
				exit(1);
			}
D 9
		}
D 3
		copy(uname, myname);
E 3
I 3
		else
			copy(uname, myname);
E 9
I 9
		} else
			strcpy(myname, uname);
E 9
E 3
	}
D 5
	mailname = mailspace;
E 5
D 9
	cp = value("HOME");
	if (cp == NOSTR)
E 9
I 9
	if ((cp = value("HOME")) == NOSTR)
E 9
		cp = ".";
D 9
	copy(cp, homedir);
E 9
I 9
	strcpy(homedir, cp);
E 9
	findmail();
D 9
	cp = copy(homedir, mbox);
	copy("/mbox", cp);
	cp = copy(homedir, mailrc);
	copy("/.mailrc", cp);
	cp = copy(homedir, deadletter);
	copy("/dead.letter", cp);
E 9
I 9
	strcpy(copy(homedir, mbox), "/mbox");
	strcpy(copy(homedir, mailrc), "/.mailrc");
	strcpy(copy(homedir, deadletter), "/dead.letter");
E 9
	if (debug) {
		printf("uid = %d, user = %s, mailname = %s\n",
		    uid, myname, mailname);
		printf("deadletter = %s, mailrc = %s, mbox = %s\n",
		    deadletter, mailrc, mbox);
	}
}
E 1

h00204
s 00004/00005/00055
d D 5.2 87/05/02 13:39:12 bostic 8 7
c bug report 4.2BSD/usr.bin/18
e
s 00007/00001/00053
d D 5.1 85/04/30 12:36:15 dist 7 6
c Add copyright
e
s 00002/00002/00052
d D 4.6 83/06/25 02:08:51 sam 6 5
c fixup ACULOG to always compile in routines, just not do record w/o
e
s 00012/00008/00042
d D 4.5 83/06/25 01:13:56 sam 5 4
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00001/00000/00049
d D 4.4 83/06/15 13:52:36 ralph 4 3
c changes for local info, parity, vadic auto dialers
e
s 00000/00000/00049
d D 4.3 81/11/29 22:50:25 sam 3 2
c reformatting
e
s 00001/00001/00048
d D 4.2 81/11/20 10:44:47 sam 2 1
c cosmetics
e
s 00049/00000/00000
d D 4.1 81/05/09 16:45:18 root 1 0
c date and time created 81/05/09 16:45:18 by root
e
u
U
t
T
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 5
/*	%M%	%I%	%E%	*/
#include "tip.h"
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
#endif not lint
E 7
E 5

D 6
#ifdef ACULOG
E 6
I 4
D 5
static char *sccsid = "%W% %G%";
E 4
static FILE *flog = NULL;
E 5
I 5
#include "tip.h"
E 5

I 8
#ifdef ACULOG
E 8
I 5
static	FILE *flog = NULL;

E 5
/*
 * Log file maintenance routines
 */

logent(group, num, acu, message)
D 2
char *group, *num, *acu, *message;
E 2
I 2
	char *group, *num, *acu, *message;
E 2
{
	char *user, *timestamp;
	struct passwd *pwd;
	long t;

	if (flog == NULL)
		return;
D 5
	if (!lock(value(LOCK))) {
		fprintf(stderr, "can't lock up accounting file\r\n");
E 5
I 5
	if (flock(fileno(flog), LOCK_EX) < 0) {
		perror("tip: flock");
E 5
		return;
	}
	if ((user = getlogin()) == NOSTR)
		if ((pwd = getpwuid(getuid())) == NOPWD)
			user = "???";
		else
			user = pwd->pw_name;
	t = time(0);
	timestamp = ctime(&t);
	timestamp[24] = '\0';
	fprintf(flog, "%s (%s) <%s, %s, %s> %s\n",
		user, timestamp, group,
#ifdef PRISTINE
		"",
#else
		num,
#endif
		acu, message);
D 8
	fflush(flog);
E 8
I 8
	(void) fflush(flog);
E 8
D 5
	unlock();
E 5
I 5
	(void) flock(fileno(flog), LOCK_UN);
E 5
}

loginit()
{
D 5
	if ((flog = fopen(value(LOG), "a")) == NULL)
E 5
I 5
D 8

I 6
#ifdef ACULOG
E 8
E 6
	flog = fopen(value(LOG), "a");
	if (flog == NULL)
E 5
D 8
		fprintf(stderr, "can't open log file\r\n");
D 6
}
E 6
#endif
E 8
I 8
		fprintf(stderr, "can't open log file %s.\r\n", value(LOG));
E 8
I 6
}
I 8
#endif
E 8
E 6
E 1

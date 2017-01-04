h59380
s 00002/00001/00104
d D 5.5 87/10/22 19:54:52 bostic 12 11
c ANSI C; sprintf now returns an int.
e
s 00002/00001/00103
d D 5.4 87/09/14 16:08:28 bostic 11 9
c set default BR; fix dereferenced NULL; bug report 4.3BSD/usr.bin/87
e
s 00001/00001/00103
d R 5.4 87/09/14 16:06:49 bostic 10 9
c dereferenced NULL; bug report 4.3BSD/usr.bin/87
e
s 00002/00008/00102
d D 5.3 87/02/09 12:08:31 karels 9 8
c formalize uid swapping and force everywhere
e
s 00008/00002/00102
d D 5.2 86/01/13 19:27:55 karels 8 7
c use setreuid to retain setuid uid for cleanup of lock files
e
s 00007/00001/00097
d D 5.1 85/04/30 12:38:40 dist 7 6
c Add copyright
e
s 00001/00000/00097
d D 4.6 83/06/28 00:32:52 sam 6 5
c must setparity even in cumode
e
s 00003/00002/00094
d D 4.5 83/06/25 01:13:40 sam 5 4
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00001/00000/00095
d D 4.4 83/06/15 13:52:16 ralph 4 3
c changes for local info, parity, vadic auto dialers
e
s 00021/00014/00074
d D 4.3 81/12/16 17:24:43 shannon 3 2
c new cu interface and phone numbers for tip
e
s 00001/00001/00087
d D 4.2 81/11/29 22:49:48 sam 2 1
c reformatting
e
s 00088/00000/00000
d D 4.1 81/11/29 22:06:37 sam 1 0
c date and time created 81/11/29 22:06:37 by sam
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

#include "tip.h"

I 4
D 5
static char *sccsid = "%W% %G%";
E 5
E 4
int	cleanup();
int	timeout();

/*
 * Botch the interface to look like cu's
 */
cumain(argc, argv)
	char *argv[];
{
	register int i;
I 3
	static char sbuf[12];
E 3

D 3
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGHUP, cleanup);
	signal(SIGTERM, cleanup);
	setbuf(stdout, NULL);
	loginit();
	setuid(getuid());
	setgid(getgid());
	vinit();
	boolean(value(VERBOSE)) = 0;
E 3
	if (argc < 2) {
D 3
		printf("usage: cu telno [-t] [-s speed] [-a acu] [-l line]\n");
E 3
I 3
		printf("usage: cu telno [-t] [-s speed] [-a acu] [-l line] [-#]\n");
E 3
		exit(8);
	}
I 3
	CU = DV = NOSTR;
I 11
	BR = DEFBR;
E 11
E 3
	for (; argc > 1; argv++, argc--) {
		if (argv[1][0] != '-')
			PN = argv[1];
D 2
		else switch(argv[1][1]) {
E 2
I 2
		else switch (argv[1][1]) {
E 2

		case 't':
			HW = 1, DU = -1;
			--argc;
			continue;

		case 'a':
			CU = argv[2]; ++argv; --argc;
			break;

		case 's':
D 11
			if (speed(atoi(argv[2])) == 0) {
E 11
I 11
			if (argc < 3 || speed(atoi(argv[2])) == 0) {
E 11
D 3
				printf("cu: unsupported speed %s\n", argv[2]);
E 3
I 3
				fprintf(stderr, "cu: unsupported speed %s\n",
					argv[2]);
E 3
				exit(3);
			}
			BR = atoi(argv[2]); ++argv; --argc;
			break;

		case 'l':
			DV = argv[2]; ++argv; --argc;
			break;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
D 3
			CU[strlen(CU)-1] = argv[1][1];
E 3
I 3
			if (CU)
				CU[strlen(CU)-1] = argv[1][1];
			if (DV)
				DV[strlen(DV)-1] = argv[1][1];
E 3
			break;

		default:
			printf("Bad flag %s", argv[1]);
			break;
		}
	}
I 3
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGHUP, cleanup);
	signal(SIGTERM, cleanup);

E 3
	/*
	 * The "cu" host name is used to define the
	 * attributes of the generic dialer.
	 */
D 3
	if ((i = hunt("cu")) == 0) {
E 3
I 3
D 12
	if ((i = hunt(sprintf(sbuf, "cu%d", BR))) == 0) {
E 12
I 12
	(void)sprintf(sbuf, "cu%d", BR);
	if ((i = hunt(sbuf)) == 0) {
E 12
E 3
		printf("all ports busy\n");
		exit(3);
	}
	if (i == -1) {
		printf("link down\n");
		delock(uucplock);
		exit(3);
	}
I 3
	setbuf(stdout, NULL);
	loginit();
D 8
	setuid(getuid());
	setgid(getgid());
E 8
I 8
D 9
	gid = getgid();
	egid = getegid();
	uid = getuid();
	euid = geteuid();
	setregid(egid, gid);
	setreuid(euid, uid);
E 9
I 9
	user_uid();
E 9
E 8
	vinit();
I 6
	setparity("none");
E 6
	boolean(value(VERBOSE)) = 0;
E 3
	if (HW)
		ttysetup(speed(BR));
	if (connect()) {
		printf("Connect failed\n");
I 8
D 9
		setreuid(uid, euid);
		setregid(gid, egid);
E 9
I 9
		daemon_uid();
E 9
E 8
		delock(uucplock);
		exit(1);
	}
	if (!HW)
		ttysetup(speed(BR));
}
E 1

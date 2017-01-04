h23084
s 00001/00001/00067
d D 5.2 87/04/23 07:39:49 bostic 10 9
c assignment of 'deadfl' to 0 in hunt(); bug report 4.3BSD/usr.bin/56
e
s 00007/00001/00061
d D 5.1 85/04/30 12:36:46 dist 9 8
c Add copyright
e
s 00004/00000/00058
d D 4.8 83/10/20 13:16:18 karels 8 7
c notice failed opens other than timeout
e
s 00020/00030/00038
d D 4.7 83/06/25 01:13:52 sam 7 6
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00017/00004/00051
d D 4.6 83/06/15 13:52:29 ralph 6 5
c changes for local info, parity, vadic auto dialers
e
s 00005/00005/00050
d D 4.5 81/11/29 22:50:11 sam 5 4
c reformatting
e
s 00001/00001/00054
d D 4.4 81/11/20 10:44:39 sam 4 3
c cosmetics
e
s 00007/00008/00048
d D 4.3 81/10/02 23:00:56 sam 3 2
c clean up leftover lock files
e
s 00009/00000/00047
d D 4.2 81/06/16 16:43:12 sam 2 1
c lots of patches to satisfy the DN-11's wants
e
s 00047/00000/00000
d D 4.1 81/05/09 16:45:16 root 1 0
c date and time created 81/05/09 16:45:16 by root
e
u
U
t
T
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif
E 9
I 9
#endif not lint
E 9

E 7
#include "tip.h"
I 6
D 7
#include <sys/stat.h>
E 7
E 6

D 7
#define RD	04
I 6
#define EX	01
E 6

I 6
static char *sccsid = "%W% %G%";
E 7
E 6
extern char *getremote();
extern char *rindex();

D 7
int deadfl;
E 7
I 7
static	jmp_buf deadline;
static	int deadfl;
E 7

dead()
{
I 7

E 7
	deadfl = 1;
I 7
	longjmp(deadline, 1);
E 7
}

hunt(name)
D 4
char *name;
E 4
I 4
	char *name;
E 4
{
	register char *cp;
I 6
D 7
	char string[100];
	struct stat	statbuf;
E 7
I 7
	int (*f)();
E 7
E 6

I 7
	f = signal(SIGALRM, dead);
E 7
D 10
	deadfl = 0;
E 10
D 7
	signal(SIGALRM, dead);
E 7
D 5
	while(cp = getremote(name)){
E 5
I 5
	while (cp = getremote(name)) {
I 10
		deadfl = 0;
E 10
E 5
D 6
		if (access(cp, RD))
			continue;
E 6
		uucplock = rindex(cp, '/')+1;
I 6
D 7
		if(strncmp(uucplock,"ttyd",4) == 0){
			/* reverse dialin line */
			if((stat(cp,&statbuf) != 0) ||
			((statbuf.st_mode & EX) == 0))
				continue;
			sprintf(string,"/usr/lib/uucp/disable %s",uucplock);
			if(system(string)) continue;
			sleep(5); /* insure that phone line is dropped */
		}
E 7
E 6
		if (mlock(uucplock) < 0) {
			delock(uucplock);
			continue;
		}
I 2
		/*
D 6
		 * Straight through call units, such as the BIZCOMP
		 *  and the DF, must indicate they're hardwired in
E 6
I 6
		 * Straight through call units, such as the BIZCOMP,
		 * VADIC and the DF, must indicate they're hardwired in
E 6
		 *  order to get an open file descriptor placed in FD.
		 * Otherwise, as for a DN-11, the open will have to
		 *  be done in the "open" routine.
		 */
		if (!HW)
			break;
E 2
D 7
		alarm(10);
D 5
		if((FD = open(cp, 2)) >= 0){
E 5
I 5
		if ((FD = open(cp, 2)) >= 0){
E 5
			alarm(0);
D 3
			if(deadfl)
				continue;
			ioctl(FD, TIOCEXCL, 0);
			break;
E 3
I 3
D 5
			if(!deadfl) {
E 5
I 5
			if (!deadfl) {
E 5
				ioctl(FD, TIOCEXCL, 0);
I 6
				ioctl(FD, TIOCHPCL, 0);
E 6
				signal(SIGALRM, SIG_DFL);
D 5
				return((int)cp);
E 5
I 5
				return ((int)cp);
E 5
			}
E 7
I 7
		if (setjmp(deadline) == 0) {
			alarm(10);
			FD = open(cp, O_RDWR);
E 7
E 3
		}
		alarm(0);
I 8
		if (FD < 0) {
			perror(cp);
			deadfl = 1;
		}
E 8
D 7
		signal(SIGALRM, dead);
E 7
I 7
		if (!deadfl) {
			ioctl(FD, TIOCEXCL, 0);
			ioctl(FD, TIOCHPCL, 0);
			signal(SIGALRM, SIG_DFL);
			return ((int)cp);
		}
E 7
I 3
		delock(uucplock);
E 3
	}
D 3
	alarm(0);
E 3
D 7
	signal(SIGALRM, SIG_DFL);
E 7
I 7
	signal(SIGALRM, f);
E 7
D 3
	if(deadfl)
		return(-1);
	return((int)cp);
E 3
I 3
D 5
	return(deadfl ? -1 : (int)cp);
E 5
I 5
	return (deadfl ? -1 : (int)cp);
E 5
E 3
}
E 1

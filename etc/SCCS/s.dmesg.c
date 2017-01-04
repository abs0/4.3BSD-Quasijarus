h46543
s 00001/00003/00129
d D 5.5 88/02/01 08:28:40 bostic 8 7
c set ignore; lint fluff
e
s 00002/00002/00130
d D 5.4 86/02/20 11:29:36 karels 7 6
c typo
e
s 00007/00003/00125
d D 5.3 86/02/13 17:37:29 karels 6 5
c bug fix from RSanders@usgs2-multics.arpa
e
s 00014/00015/00114
d D 5.2 86/02/11 19:31:58 karels 5 4
c grot!  what is this timeout for?  ignore syslog pri's
e
s 00010/00001/00119
d D 5.1 85/06/05 09:20:13 dist 4 3
c Add copyright
e
s 00004/00002/00116
d D 4.3 85/03/05 13:43:44 serge 3 2
c exit if can't open scratch file
e
s 00001/00001/00117
d D 4.2 83/01/02 14:56:34 sam 2 1
c sun
e
s 00118/00000/00000
d D 4.1 82/03/01 00:59:39 wnj 1 0
c date and time created 82/03/01 00:59:39 by wnj
e
u
U
t
T
I 1
D 4
static char *sccsid = "%W% (Berkeley) %E%";
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
/*
 *	Suck up system messages
 *	dmesg
 *		print current buffer
 *	dmesg -
 *		print and update incremental history
 */

#include <stdio.h>
#include <sys/param.h>
#include <nlist.h>
#include <signal.h>
I 5
#include <sys/file.h>
E 5
#include <sys/vm.h>
#include <sys/msgbuf.h>

struct	msgbuf msgbuf;
char	*msgbufp;
int	sflg;
int	of	= -1;

struct	msgbuf omesg;
struct	nlist nl[2] = {
	{ "_msgbuf" },
D 2
	{ 0 }
E 2
I 2
	{ "" }
E 2
};

main(argc, argv)
char **argv;
{
	int mem;
	register char *mp, *omp, *mstart;
D 5
	int timeout();
	int samef;
E 5
I 5
D 8
	int samef, sawnl, ignore;
E 8
I 8
	int samef, sawnl, ignore = 0;
E 8
E 5

D 5
	signal(SIGALRM, timeout);
	alarm(30);
E 5
	if (argc>1 && argv[1][0] == '-') {
		sflg++;
		argc--;
		argv++;
	}
	if (sflg) {
D 5
		of = open("/usr/adm/msgbuf", 2);
E 5
I 5
		of = open("/usr/adm/msgbuf", O_RDWR | O_CREAT, 0644);
E 5
I 3
		if (of < 0)
			done("Can't open /usr/adm/msgbuf\n");
E 3
		read(of, (char *)&omesg, sizeof(omesg));
		lseek(of, 0L, 0);
	}
	sflg = 0;
	nlist(argc>2? argv[2]:"/vmunix", nl);
	if (nl[0].n_type==0)
D 3
		done("No namelist\n");
E 3
I 3
		done("Can't get kernel namelist\n");
E 3
	if ((mem = open((argc>1? argv[1]: "/dev/kmem"), 0)) < 0)
D 3
		done("No mem\n");
E 3
I 3
		done("Can't read kernel memory\n");
E 3
	lseek(mem, (long)nl[0].n_value, 0);
	read(mem, &msgbuf, sizeof (msgbuf));
	if (msgbuf.msg_magic != MSG_MAGIC)
		done("Magic number wrong (namelist mismatch?)\n");
I 6
	if (msgbuf.msg_bufx >= MSG_BSIZE)
		msgbuf.msg_bufx = 0;
D 7
	if (omsgbuf.msg_bufx >= MSG_BSIZE)
		omsgbuf.msg_bufx = 0;
E 7
I 7
	if (omesg.msg_bufx >= MSG_BSIZE)
		omesg.msg_bufx = 0;
E 7
E 6
	mstart = &msgbuf.msg_bufc[omesg.msg_bufx];
	omp = &omesg.msg_bufc[msgbuf.msg_bufx];
	mp = msgbufp = &msgbuf.msg_bufc[msgbuf.msg_bufx];
	samef = 1;
	do {
		if (*mp++ != *omp++) {
			mstart = msgbufp;
			samef = 0;
			pdate();
			printf("...\n");
			break;
		}
D 6
		if (mp == &msgbuf.msg_bufc[MSG_BSIZE])
E 6
I 6
		if (mp >= &msgbuf.msg_bufc[MSG_BSIZE])
E 6
			mp = msgbuf.msg_bufc;
D 6
		if (omp == &omesg.msg_bufc[MSG_BSIZE])
E 6
I 6
		if (omp >= &omesg.msg_bufc[MSG_BSIZE])
E 6
			omp = omesg.msg_bufc;
	} while (mp != mstart);
	if (samef && omesg.msg_bufx == msgbuf.msg_bufx)
		exit(0);
	mp = mstart;
I 5
	pdate();
	sawnl = 1;
E 5
	do {
D 5
		pdate();
		if (*mp && (*mp & 0200) == 0)
E 5
I 5
		if (sawnl && *mp == '<')
			ignore = 1;
		if (*mp && (*mp & 0200) == 0 && !ignore)
E 5
			putchar(*mp);
I 5
		if (ignore && *mp == '>')
			ignore = 0;
		sawnl = (*mp == '\n');
E 5
		mp++;
D 6
		if (mp == &msgbuf.msg_bufc[MSG_BSIZE])
E 6
I 6
		if (mp >= &msgbuf.msg_bufc[MSG_BSIZE])
E 6
			mp = msgbuf.msg_bufc;
	} while (mp != msgbufp);
	done((char *)NULL);
}

done(s)
char *s;
{
D 8
	register char *p, *q;

E 8
D 5
	if (s && s!=(char *)omesg.msg_magic && sflg==0) {
E 5
I 5
	if (s) {
E 5
		pdate();
		printf(s);
D 5
	}
	write(of, (char *)&msgbuf, sizeof(msgbuf));
E 5
I 5
	} else if (of != -1)
		write(of, (char *)&msgbuf, sizeof(msgbuf));
E 5
	exit(s!=NULL);
}

pdate()
{
	extern char *ctime();
	static firstime;
	time_t tbuf;

	if (firstime==0) {
		firstime++;
		time(&tbuf);
		printf("\n%.12s\n", ctime(&tbuf)+4);
	}
D 5
}

timeout()
{
	done("Buffer file screwed up\n");
E 5
}
E 1

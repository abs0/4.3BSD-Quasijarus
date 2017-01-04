h27588
s 00007/00001/00098
d D 5.1 85/06/06 09:49:57 dist 9 8
c Add copyright
e
s 00000/00006/00099
d D 4.8 83/06/25 02:09:56 sam 8 7
c remove #if's, now in a library
e
s 00019/00015/00086
d D 4.7 83/06/25 01:13:44 sam 7 6
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00001/00000/00100
d D 4.6 83/06/15 13:52:20 ralph 6 5
c changes for local info, parity, vadic auto dialers
e
s 00004/00004/00096
d D 4.5 81/11/29 22:49:54 sam 5 4
c reformatting
e
s 00004/00004/00096
d D 4.4 81/11/20 10:44:29 sam 4 3
c cosmetics
e
s 00004/00002/00096
d D 4.3 81/10/21 11:41:27 sam 3 2
c fix #ifdef and reversed parameters
e
s 00042/00006/00056
d D 4.2 81/10/09 15:27:58 sam 2 1
c shannon changes to support DF02+DF03 -- require kernel hack
e
s 00062/00000/00000
d D 4.1 81/05/09 16:45:13 root 1 0
c date and time created 81/05/09 16:45:13 by root
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
/*
D 2
 * Dial the DF02-AC
E 2
I 2
 * Dial the DF02-AC or DF03-AC
E 2
 */

I 2
D 8
#if defined(DF02) || defined(DF03)
E 8
E 2
#include "tip.h"
D 2
#if DF02
E 2
D 7
#include <setjmp.h>
E 7

I 6
D 7
static char *sccsid = "%W% %G%";
E 6
static jmp_buf	Sjbuf;
E 7
I 7
static jmp_buf Sjbuf;
E 7
static timeout();

D 2
df_dialer(num, acu)
E 2
I 2
D 8
#if DF02
E 8
df02_dialer(num, acu)
E 2
D 4
char *num, *acu;
E 4
I 4
	char *num, *acu;
E 4
{
I 7

E 7
I 2
D 3
	return(df_dialer(acu, num, 0));
E 3
I 3
D 5
	return(df_dialer(num, acu, 0));
E 5
I 5
	return (df_dialer(num, acu, 0));
E 5
E 3
}
D 8
#endif
E 8

D 8
#if DF03
E 8
df03_dialer(num, acu)
D 4
char *num, *acu;
E 4
I 4
	char *num, *acu;
E 4
{
I 7

E 7
D 3
	return(df_dialer(acu, num, 1));
E 3
I 3
D 5
	return(df_dialer(num, acu, 1));
E 5
I 5
	return (df_dialer(num, acu, 1));
E 5
E 3
}
D 8
#endif
E 8

df_dialer(num, acu, df03)
D 4
char *num, *acu;
int df03;
E 4
I 4
	char *num, *acu;
	int df03;
E 4
{
E 2
	register int f = FD;
D 2
	int c;
E 2
I 2
	struct sgttyb buf;
D 7
	int speed = 0, c = 0;
I 3
#ifdef TIOCMSET
E 3
	int st = MST;		/* Secondary Transmit flag, for speed select */
I 3
#endif
E 7
I 7
	int speed = 0, rw = 2;
	char c = '\0';
E 7
E 3
E 2

	ioctl(f, TIOCHPCL, 0);		/* make sure it hangs up when done */
	if (setjmp(Sjbuf)) {
		printf("connection timed out\r\n");
		df_disconnect();
D 5
		return(0);
E 5
I 5
		return (0);
E 5
	}
	if (boolean(value(VERBOSE)))
		printf("\ndialing...");
	fflush(stdout);
I 2
#ifdef TIOCMSET
	if (df03) {
I 7
		int st = TIOCM_ST;	/* secondary Transmit flag */

E 7
		ioctl(f, TIOCGETP, &buf);
		if (buf.sg_ospeed != B1200) {	/* must dial at 1200 baud */
			speed = buf.sg_ospeed;
			buf.sg_ospeed = buf.sg_ispeed = B1200;
			ioctl(f, TIOCSETP, &buf);
			ioctl(f, TIOCMBIC, &st); /* clear ST for 300 baud */
		} else
			ioctl(f, TIOCMBIS, &st); /* set ST for 1200 baud */
	}
#endif
E 2
	signal(SIGALRM, timeout);
	alarm(5 * strlen(num) + 10);
D 7
	ioctl(f, TIOCFLUSH, 0);
E 7
I 7
	ioctl(f, TIOCFLUSH, &rw);
E 7
	write(f, "\001", 1);
D 2
	sleep(0);		/* this must waste 70 ms. */
E 2
I 2
	sleep(1);
E 2
	write(f, "\002", 1);
	write(f, num, strlen(num));
D 2
	c = 0;
E 2
D 7
	read(f, (char *)&c, 1);
E 7
I 7
	read(f, &c, 1);
E 7
I 2
#ifdef TIOCMSET
	if (df03 && speed) {
		buf.sg_ispeed = buf.sg_ospeed = speed;
		ioctl(f, TIOCSETP, &buf);
	}
#endif
E 2
D 5
	return(c == 'A');
E 5
I 5
	return (c == 'A');
E 5
}

D 7

E 7
df_disconnect()
{
I 7
	int rw = 2;

E 7
	write(FD, "\001", 1);
	sleep(1);
D 7
	ioctl(FD, TIOCFLUSH, 0);
E 7
I 7
	ioctl(FD, TIOCFLUSH, &rw);
E 7
}


df_abort()
{
D 7
	write(FD, "\001", 1);
	sleep(1);
	ioctl(FD, TIOCFLUSH, 0);
E 7
I 7

	df_disconnect();
E 7
}


static
timeout()
{
I 7

E 7
	longjmp(Sjbuf, 1);
}
D 8
#endif
E 8
E 1

h39858
s 00007/00001/00120
d D 5.1 85/04/30 12:32:40 dist 11 10
c Add copyright
e
s 00002/00003/00119
d D 4.10 84/09/12 10:06:18 ralph 10 9
c use sigmask macro
e
s 00010/00002/00112
d D 4.9 83/10/08 13:58:41 sam 9 8
c recognize and handle carrier loss
e
s 00022/00022/00092
d D 4.8 83/06/25 01:14:49 sam 8 7
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00003/00001/00111
d D 4.7 83/06/15 13:53:05 ralph 7 6
c changes for local info, parity, vadic auto dialers
e
s 00001/00001/00111
d D 4.6 82/01/06 10:55:22 shannon 6 5
c fix bugs with beautify and scripting
e
s 00020/00007/00092
d D 4.5 81/12/16 17:25:10 shannon 5 4
c new cu interface and phone numbers for tip
e
s 00003/00003/00096
d D 4.4 81/11/29 22:51:08 sam 4 3
c reformatting
e
s 00000/00000/00099
d D 4.3 81/11/20 10:45:09 sam 3 2
c cosmetics
e
s 00000/00000/00099
d D 4.2 81/06/16 16:44:09 sam 2 1
c lots of patches to satisfy the DN-11's wants
e
s 00099/00000/00000
d D 4.1 81/05/09 16:45:26 root 1 0
c date and time created 81/05/09 16:45:26 by root
e
u
U
t
T
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 11
I 1
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
#endif not lint
E 11

E 8
#include "tip.h"
/*
 * tip
 *
 * lower fork of tip -- handles passive side
 *  reading from the remote host
 */

I 7
D 8
static char *sccsid = "%W% %G%";
E 8
I 8
static	jmp_buf sigbuf;
E 8

E 7
/*
 * TIPOUT wait state routine --
 *   sent by TIPIN when it wants to posses the remote host
 */
intIOT()
{
D 8
	signal(SIGIOT, SIG_IGN);
E 8
I 8

E 8
	write(repdes[1],&ccc,1);
	read(fildes[0], &ccc,1);
D 8
	signal(SIGIOT, intIOT);
	intflag = 1;
E 8
I 8
	longjmp(sigbuf, 1);
E 8
}

/*
 * Scripting command interpreter --
 *  accepts script file name over the pipe and acts accordingly
 */
intEMT()
{
	char c, line[256];
	register char *pline = line;
	char reply;

D 8
	signal(SIGEMT, SIG_IGN);
E 8
	read(fildes[0], &c, 1);
D 4
	while(c != '\n') {
E 4
I 4
	while (c != '\n') {
E 4
		*pline++ = c;
		read(fildes[0], &c, 1);
	}
	*pline = '\0';
	if (boolean(value(SCRIPT)) && fscript != NULL)
		fclose(fscript);
	if (pline == line) {
		boolean(value(SCRIPT)) = FALSE;
		reply = 'y';
	} else {
		if ((fscript = fopen(line, "a")) == NULL)
			reply = 'n';
		else {
			reply = 'y';
			boolean(value(SCRIPT)) = TRUE;
		}
	}
	write(repdes[1], &reply, 1);
D 8
	signal(SIGEMT, intEMT);
	intflag = 1;
E 8
I 8
	longjmp(sigbuf, 1);
E 8
}

intTERM()
{
D 8
	signal(SIGTERM, SIG_IGN);
E 8
I 8

E 8
	if (boolean(value(SCRIPT)) && fscript != NULL)
		fclose(fscript);
	exit(0);
}

intSYS()
{
D 8
	signal(SIGSYS, intSYS);
E 8
I 8

E 8
	boolean(value(BEAUTIFY)) = !boolean(value(BEAUTIFY));
I 5
D 8
	intflag = 1;
E 8
I 8
	longjmp(sigbuf, 1);
E 8
E 5
}

/*
 * ****TIPOUT   TIPOUT****
 */
tipout()
{
I 5
	char buf[BUFSIZ];
	register char *cp;
	register int cnt;
I 9
	extern int errno;
E 9
I 8
	int omask;
E 8

E 5
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGEMT, intEMT);		/* attention from TIPIN */
	signal(SIGTERM, intTERM);	/* time to go signal */
	signal(SIGIOT, intIOT);		/* scripting going on signal */
	signal(SIGHUP, intTERM);	/* for dial-ups */
	signal(SIGSYS, intSYS);		/* beautify toggle */
D 8

D 4
	while(1) {
E 4
I 4
D 5
	while (1) {
E 5
I 5
	for (;;) {
E 5
E 4
		do {
			intflag = 0;
D 5
			read(FD,&ch,1);
			ch &= 0177;
E 5
I 5
			cnt = read(FD, buf, BUFSIZ);
E 5
D 4
		} while(intflag);
E 4
I 4
		} while (intflag);
E 8
I 8
	(void) setjmp(sigbuf);
	for (omask = 0;; sigsetmask(omask)) {
		cnt = read(FD, buf, BUFSIZ);
E 8
E 4
D 5
		write(1, &ch, 1);
E 5
I 5
D 9
		if (cnt <= 0)
			continue;
E 9
I 9
		if (cnt <= 0) {
			/* lost carrier */
			if (cnt < 0 && errno == EIO) {
E 9
I 8
D 10
#define	mask(s)	(1 << ((s) - 1))
I 9
				sigblock(mask(SIGTERM));
E 10
I 10
				sigblock(sigmask(SIGTERM));
E 10
				intTERM();
				/*NOTREACHED*/
			}
			continue;
		}
E 9
D 10
#define	ALLSIGS	mask(SIGEMT)|mask(SIGTERM)|mask(SIGIOT)|mask(SIGSYS)
E 10
I 10
#define	ALLSIGS	sigmask(SIGEMT)|sigmask(SIGTERM)|sigmask(SIGIOT)|sigmask(SIGSYS)
E 10
		omask = sigblock(ALLSIGS);
E 8
		for (cp = buf; cp < buf + cnt; cp++)
			*cp &= 0177;
		write(1, buf, cnt);
E 5
		if (boolean(value(SCRIPT)) && fscript != NULL) {
D 5
			if (boolean(value(BEAUTIFY)) && ch < 040 &&
			    !any(ch, value(EXCEPTIONS)))
E 5
I 5
			if (!boolean(value(BEAUTIFY))) {
D 6
				fputs(buf, fscript);
E 6
I 6
				fwrite(buf, 1, cnt, fscript);
E 6
				continue;
			}
D 8
			for (cp = buf; cp < buf + cnt; cp++) {
D 7
				if (*cp < ' ' && !any(*cp, value(EXCEPTIONS)))
E 7
I 7
				if ((*cp < ' ' || *cp > '~') && !any(*cp, value(EXCEPTIONS)))
E 7
E 5
					continue;
D 5
			putc(ch, fscript);
E 5
I 5
				putc(*cp, fscript);
			}
E 8
I 8
			for (cp = buf; cp < buf + cnt; cp++)
				if ((*cp >= ' ' && *cp <= '~') ||
				    any(*cp, value(EXCEPTIONS)))
					putc(*cp, fscript);
E 8
E 5
		}
	}
}
E 1

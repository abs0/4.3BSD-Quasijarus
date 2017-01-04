h30240
s 00001/00001/00235
d D 5.4 87/10/22 18:12:28 bostic 22 21
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00235
d D 5.3 86/01/07 15:18:42 mckusick 21 20
c make ruptime less technophobic (from whm%arizona.csnet@CSNET-RELAY.ARPA)
e
s 00001/00001/00235
d D 5.2 85/06/18 19:28:22 mckusick 20 19
c rwhod.h moves to /usr/include/protocols
e
s 00014/00002/00222
d D 5.1 85/05/31 09:28:29 dist 19 18
c Add copyright
e
s 00002/00002/00222
d D 4.17 85/02/27 08:23:28 karels 18 17
c read in the whole file (struct whod), not just 1K
e
s 00038/00031/00186
d D 4.16 83/11/17 14:20:16 ralph 17 16
c added -r option to reverse sort order
e
s 00006/00006/00211
d D 4.15 83/11/14 15:44:26 ralph 16 15
c print correct error message and down if time > 11 min.
e
s 00002/00002/00215
d D 4.14 83/07/01 04:17:29 sam 15 14
c can't stand have rwhod.h in /usr/include
e
s 00004/00004/00213
d D 4.13 83/07/01 02:47:27 sam 14 13
c from sun
e
s 00002/00002/00215
d D 4.12 83/05/25 16:49:39 sam 13 11
c up host name length
e
s 00002/00002/00215
d R 4.12 83/05/25 16:40:33 sam 12 11
c up host name length printed
e
s 00001/00002/00216
d D 4.11 83/05/25 15:52:07 sam 11 10
c kludges to avoid new utmp format
e
s 00001/00000/00217
d D 4.10 83/05/05 11:44:54 sam 10 9
c directory not part of protocol, so moved out of rwhod.h
e
s 00001/00001/00216
d D 4.9 83/05/03 19:57:10 sam 9 8
c move from netser forces rwhod.h into /usr/include
e
s 00001/00001/00216
d D 4.8 83/04/21 12:38:45 ralph 8 7
c changed it so 'up' and 'down' line up in columns.
e
s 00002/00002/00215
d D 4.7 82/12/24 21:04:27 sam 7 6
c port not byte swapped; no more asm.sed; 
c move spool area to /usr/spool/rwho so /etc is always changing
e
s 00003/00003/00214
d D 4.6 82/11/14 15:17:28 sam 6 5
c convert to 4.1c sys calls and directory layout
e
s 00074/00003/00143
d D 4.5 82/10/07 15:30:17 ecc 5 4
c added additional sorting options
e
s 00002/00002/00144
d D 4.4 82/05/09 23:59:02 mckusick 4 3
c update to new fs
e
s 00011/00004/00135
d D 4.3 82/04/03 19:45:44 wnj 3 2
c variable width for load averages
e
s 00001/00001/00138
d D 4.2 82/04/03 19:33:05 wnj 2 1
c %5.2f
e
s 00139/00000/00000
d D 4.1 82/04/02 10:29:08 wnj 1 0
c date and time created 82/04/02 10:29:08 by wnj
e
u
U
t
T
I 19
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 19
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% %E%";
E 11
I 11
D 19
static char sccsid[] = "%W% (Berkeley) %E%";
E 11
#endif
E 19
I 19
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19

D 4
#include <sys/types.h>		/* botch in ndir.h */
E 4
I 4
#include <sys/param.h>
E 4
#include <stdio.h>
D 4
#include <ndir.h>
E 4
I 4
D 15
#include <dir.h>
E 4
D 11
#include <utmp.h>
E 11
D 9
#include "rwhod.h"
E 9
I 9
#include <rwhod.h>
E 15
I 15
#include <sys/dir.h>
D 20
#include "../etc/rwhod/rwhod.h"
E 20
I 20
#include <protocols/rwhod.h>
E 20
E 15
E 9

D 16
DIR	*etc;
E 16
I 16
DIR	*dirp;
E 16

#define	NHOSTS	100
int	nhosts;
struct	hs {
	struct	whod *hs_wd;
	int	hs_nusers;
} hs[NHOSTS];
struct	whod awhod;
D 5
int	hscmp();
E 5
I 5
int	hscmp(), ucmp(), lcmp(), tcmp();
E 5

#define	WHDRSIZE	(sizeof (awhod) - sizeof (awhod.wd_we))
I 10
#define	RWHODIR		"/usr/spool/rwho"
E 10

char	*interval();
int	now;
D 22
char	*malloc(), *sprintf();
E 22
I 22
char	*malloc();
E 22
int	aflg;
I 17
int 	rflg = 1;
E 17

I 5
D 16
#define down(h)		(now - (h)->hs_wd->wd_recvtime > 5 * 60)
E 16
I 16
#define down(h)		(now - (h)->hs_wd->wd_recvtime > 11 * 60)
E 16

E 5
main(argc, argv)
	int argc;
	char **argv;
{
	struct direct *dp;
	int f, i, t;
D 18
	char buf[BUFSIZ]; int cc;
E 18
I 18
	char buf[sizeof(struct whod)]; int cc;
E 18
I 17
	char *name;
E 17
	register struct hs *hsp = hs;
	register struct whod *wd;
	register struct whoent *we;
I 3
	int maxloadav = 0;
I 5
	int (*cmp)() = hscmp;
E 5
E 3

I 17
	name = *argv;
	while (*++argv) 
		while (**argv)
			switch (*(*argv)++) {
			case 'a':
				aflg++;
				break;
			case 'l':
				cmp = lcmp;
				break;
			case 'u':
				cmp = ucmp;
				break;
			case 't':
				cmp = tcmp;
				break;
			case 'r':
				rflg = -rflg;
				break;
			case '-':
				break;
			default: 
				fprintf(stderr, "Usage: %s [ -ar [ lut ] ]\n",
					name);
				exit (1);
			}
E 17
	time(&t);
D 17
	argc--, argv++;
again:
D 14
	if (!strcmp(*argv, "-a")) {
E 14
I 14
	if (argc && !strcmp(*argv, "-a")) {
E 14
		aflg++;
		argc--, argv++;
		goto again;
	}
I 5
D 14
	if (!strcmp(*argv, "-l")) {
E 14
I 14
	if (argc && !strcmp(*argv, "-l")) {
E 14
		cmp = lcmp;
		argc--, argv++;
		goto again;
	}
D 14
	if (!strcmp(*argv, "-u")) {
E 14
I 14
	if (argc && !strcmp(*argv, "-u")) {
E 14
		cmp = ucmp;
		argc--, argv++;
		goto again;
	}
D 14
	if (!strcmp(*argv, "-t")) {
E 14
I 14
	if (argc && !strcmp(*argv, "-t")) {
E 14
		cmp = tcmp;
		argc--, argv++;
		goto again;
	}
E 17
E 5
D 7
	if (chdir("/etc") < 0) {
		perror("/etc");
E 7
I 7
	if (chdir(RWHODIR) < 0) {
		perror(RWHODIR);
E 7
		exit(1);
	}
D 16
	etc = opendir(".");
	if (etc == NULL) {
		perror("/etc");
E 16
I 16
	dirp = opendir(".");
	if (dirp == NULL) {
		perror(RWHODIR);
E 16
		exit(1);
	}
D 16
	while (dp = readdir(etc)) {
E 16
I 16
	while (dp = readdir(dirp)) {
E 16
		if (dp->d_ino == 0)
			continue;
		if (strncmp(dp->d_name, "whod.", 5))
			continue;
		if (nhosts == NHOSTS) {
			fprintf(stderr, "too many hosts\n");
			exit(1);
		}
		f = open(dp->d_name, 0);
		if (f > 0) {
D 18
			cc = read(f, buf, BUFSIZ);
E 18
I 18
			cc = read(f, buf, sizeof(struct whod));
E 18
			if (cc >= WHDRSIZE) {
				hsp->hs_wd = (struct whod *)malloc(WHDRSIZE);
				wd = (struct whod *)buf;
				bcopy(buf, hsp->hs_wd, WHDRSIZE);
				hsp->hs_nusers = 0;
I 3
				for (i = 0; i < 2; i++)
					if (wd->wd_loadav[i] > maxloadav)
						maxloadav = wd->wd_loadav[i];
E 3
				we = (struct whoent *)(buf+cc);
				while (--we >= wd->wd_we)
					if (aflg || we->we_idle < 3600)
						hsp->hs_nusers++;
				nhosts++; hsp++;
			}
		}
		(void) close(f);
	}
D 5
	qsort((char *)hs, nhosts, sizeof (hs[0]), hscmp);
E 5
	(void) time(&now);
I 5
	qsort((char *)hs, nhosts, sizeof (hs[0]), cmp);
E 5
	if (nhosts == 0) {
		printf("no hosts!?!\n");
		exit(1);
	}
	for (i = 0; i < nhosts; i++) {
		hsp = &hs[i];
D 5
		if (now - hsp->hs_wd->wd_recvtime > 5 * 60) {
E 5
I 5
		if (down(hsp)) {
E 5
D 13
			printf("%-8.8s%s\n", hsp->hs_wd->wd_hostname,
E 13
I 13
			printf("%-12.12s%s\n", hsp->hs_wd->wd_hostname,
E 13
			    interval(now - hsp->hs_wd->wd_recvtime, "down"));
			continue;
		}
D 2
		printf("%-8.8s%s,  %4d user%s  load %4.2f, %4.2f, %4.2f\n",
E 2
I 2
D 3
		printf("%-8.8s%s,  %4d user%s  load %5.2f, %5.2f, %5.2f\n",
E 3
I 3
D 13
		printf("%-8.8s%s,  %4d user%s  load %*.2f, %*.2f, %*.2f\n",
E 13
I 13
		printf("%-12.12s%s,  %4d user%s  load %*.2f, %*.2f, %*.2f\n",
E 13
E 3
E 2
		    hsp->hs_wd->wd_hostname,
		    interval(hsp->hs_wd->wd_sendtime -
D 6
			hsp->hs_wd->wd_bootime, "  up"),
E 6
I 6
			hsp->hs_wd->wd_boottime, "  up"),
E 6
		    hsp->hs_nusers,
		    hsp->hs_nusers == 1 ? ", " : "s,",
D 3
		    hsp->hs_wd->wd_loadav[0] / 100.0,
		    hsp->hs_wd->wd_loadav[1] / 100.0,
		    hsp->hs_wd->wd_loadav[2] / 100.0);
E 3
I 3
		    maxloadav >= 1000 ? 5 : 4,
			hsp->hs_wd->wd_loadav[0] / 100.0,
		    maxloadav >= 1000 ? 5 : 4,
		        hsp->hs_wd->wd_loadav[1] / 100.0,
		    maxloadav >= 1000 ? 5 : 4,
		        hsp->hs_wd->wd_loadav[2] / 100.0);
E 3
		cfree(hsp->hs_wd);
	}
	exit(0);
}

char *
interval(time, updown)
	int time;
	char *updown;
{
	static char resbuf[32];
	int days, hours, minutes;

D 21
	if (time < 0 || time > 3*30*24*60*60) {
E 21
I 21
	if (time < 0 || time > 365*24*60*60) {
E 21
		(void) sprintf(resbuf, "   %s ??:??", updown);
		return (resbuf);
	}
	minutes = (time + 59) / 60;		/* round to minutes */
	hours = minutes / 60; minutes %= 60;
	days = hours / 24; hours %= 24;
	if (days)
		(void) sprintf(resbuf, "%s %2d+%02d:%02d",
		    updown, days, hours, minutes);
	else
D 8
		(void) sprintf(resbuf, "   %s %2d:%02d",
E 8
I 8
		(void) sprintf(resbuf, "%s    %2d:%02d",
E 8
		    updown, hours, minutes);
	return (resbuf);
}

hscmp(h1, h2)
	struct hs *h1, *h2;
{

D 17
	return (strcmp(h1->hs_wd->wd_hostname, h2->hs_wd->wd_hostname));
E 17
I 17
	return (rflg * strcmp(h1->hs_wd->wd_hostname, h2->hs_wd->wd_hostname));
E 17
I 5
}

/*
 * Compare according to load average.
 */
lcmp(h1, h2)
	struct hs *h1, *h2;
{

	if (down(h1))
		if (down(h2))
			return (tcmp(h1, h2));
		else
D 17
			return (1);
E 17
I 17
			return (rflg);
E 17
	else if (down(h2))
D 17
		return (-1);
E 17
I 17
		return (-rflg);
E 17
	else
D 17
		return (h2->hs_wd->wd_loadav[0] - h1->hs_wd->wd_loadav[0]);
E 17
I 17
		return (rflg * 
			(h2->hs_wd->wd_loadav[0] - h1->hs_wd->wd_loadav[0]));
E 17
}

/*
 * Compare according to number of users.
 */
ucmp(h1, h2)
	struct hs *h1, *h2;
{

	if (down(h1))
		if (down(h2))
			return (tcmp(h1, h2));
		else
D 17
			return (1);
E 17
I 17
			return (rflg);
E 17
	else if (down(h2))
D 17
		return (-1);
E 17
I 17
		return (-rflg);
E 17
	else
D 17
		return (h2->hs_nusers - h1->hs_nusers);
E 17
I 17
		return (rflg * (h2->hs_nusers - h1->hs_nusers));
E 17
}

/*
 * Compare according to uptime.
 */
tcmp(h1, h2)
	struct hs *h1, *h2;
{
	long t1, t2;

D 17
	return (
E 17
I 17
	return (rflg * (
E 17
		(down(h2) ? h2->hs_wd->wd_recvtime - now
D 6
			  : h2->hs_wd->wd_sendtime - h2->hs_wd->wd_bootime)
E 6
I 6
			  : h2->hs_wd->wd_sendtime - h2->hs_wd->wd_boottime)
E 6
		-
		(down(h1) ? h1->hs_wd->wd_recvtime - now
D 6
			  : h1->hs_wd->wd_sendtime - h1->hs_wd->wd_bootime)
E 6
I 6
			  : h1->hs_wd->wd_sendtime - h1->hs_wd->wd_boottime)
E 6
D 17
	);
E 17
I 17
	));
E 17
E 5
}
E 1

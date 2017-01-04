h64760
s 00011/00003/00160
d D 4.5 02/07/19 23:20:32 msokolov 6 5
c support ppp too
e
s 00018/00010/00145
d D 4.4 02/07/07 18:44:01 msokolov 5 4
c change for the new tty/sl attachment design (TIOCSLATTACH)
c now specify the if on the command line (finally!)
e
s 00029/00006/00126
d D 4.3 88/06/30 10:37:59 bostic 4 3
c clean up header; attach Berkeley specific copyright
e
s 00004/00008/00128
d D 4.2 87/08/01 11:44:03 bostic 3 2
c pdp11 port; long/int problem, remove unused variables
e
s 00028/00080/00108
d D 4.1 86/02/17 17:35:00 karels 2 1
c rm source, dest address setting; let ifconfig do it
e
s 00188/00000/00000
d D 1.1 86/02/17 17:02:25 karels 1 0
c from Torek
e
u
U
t
T
I 4
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Rick Adams.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

E 4
I 2
#ifndef lint
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
I 3
D 4
static char sccsid[] = "@(#)slattach.c	4.1 (Berkeley) 2/17/86";
E 3
#endif
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 4
E 2
I 1
#include <stdio.h>
D 2
#include <sys/types.h>
E 2
I 2
#include <sys/param.h>
E 2
#include <sgtty.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <fcntl.h>
I 5
#include <ctype.h>
E 5
D 4

#ifndef lint
static char rcsid[] = "$Header: slattach.c,v 1.1 84/10/04 12:57:12 rick Exp $";
#endif
E 4

D 2
struct	ifreq ifr;
struct	sockaddr_in sin = {AF_INET};

E 2
#define DEFAULT_BAUD	9600
D 3
int	speed;
E 3
D 5
int	slipdisc = SLIPDISC;
E 5

char	devname[32];
D 2
char	hostname[32];
E 2
I 2
D 5
char	hostname[MAXHOSTNAMELEN];
E 5
E 2

D 3
extern int errno;

E 3
main(argc, argv)
	int argc;
	char *argv[];
{
D 3
	register FILE *fp;
E 3
	register int fd;
D 5
	register char *dev = argv[1];
E 5
I 5
	register char *dev = argv[2];
	char *ifname = argv[1];
E 5
	struct sgttyb sgtty;
I 5
	int	ifnum;
E 5
D 3
	int n;
E 3
I 3
	int	speed;
E 3

D 2
	if (argc < 4 || argc > 5)
		error(1, 0, "usage: %s ttyname srcaddr dstaddr [baud]\n",
		      argv[0]);
	speed = argc == 5 ? findspeed(atoi(argv[4])) : findspeed(DEFAULT_BAUD);
	if (speed == 0)
		error(1, errno, "unknown speed %s", argv[4]);
E 2
I 2
D 5
	if (argc < 2 || argc > 3) {
		fprintf(stderr, "usage: %s ttyname [baudrate]\n", argv[0]);
E 5
I 5
	if (argc < 3 || argc > 4) {
		fprintf(stderr, "usage: %s ifname ttyname [baudrate]\n",
			argv[0]);
E 5
		exit(1);
	}
D 5
	speed = argc == 3 ? findspeed(atoi(argv[2])) : findspeed(DEFAULT_BAUD);
E 5
I 5
D 6
	if (ifname[0] != 's' || ifname[1] != 'l' || !isdigit(ifname[2])) {
E 6
I 6
	if (ifname[0] == 's' && ifname[1] == 'l' && isdigit(ifname[2]))
		ifnum = atoi(ifname + 2);
	else if (ifname[0] == 'p' && ifname[1] == 'p' && ifname[2] == 'p' &&
		 isdigit(ifname[3]))
		ifnum = atoi(ifname + 3);
	else {
E 6
		fprintf(stderr, "%s is not a valid interface for %s\n", ifname,
			argv[0]);
		exit(1);
	}
D 6
	ifnum = atoi(ifname + 2);
E 6
	speed = argc == 4 ? findspeed(atoi(argv[3])) : findspeed(DEFAULT_BAUD);
E 5
	if (speed == 0) {
D 5
		fprintf(stderr, "unknown speed %s", argv[2]);
E 5
I 5
		fprintf(stderr, "unknown speed %s\n", argv[3]);
E 5
		exit(1);
	}
E 2
D 5
	if (strncmp("/dev/", dev, 5)) {
E 5
I 5
	if (!index(dev, '/')) {
E 5
D 3
		sprintf(devname, "/dev/%s", dev);
E 3
I 3
		(void)sprintf(devname, "/dev/%s", dev);
E 3
		dev = devname;
	}
D 2
	if ((fd = open(dev, O_RDWR | O_NDELAY)) < 0)
		error(1, errno, "%s: cannot open", dev);
E 2
I 2
	if ((fd = open(dev, O_RDWR | O_NDELAY)) < 0) {
		perror(dev);
		exit(1);
	}
E 2
	sgtty.sg_flags = RAW | ANYP;
	sgtty.sg_ispeed = sgtty.sg_ospeed = speed;
D 2
	if (ioctl(fd, TIOCSETP, &sgtty) < 0)
		error(1, errno, "ioctl(TIOCSETP) on %s", dev);
	if (ioctl(fd, TIOCSETD, &slipdisc) < 0)
		error(1, errno, "ioctl(TIOCSETD)");
	if (ioctl(fd, TIOCGETD, &n) < 0)
		error(1, errno, "ioctl(TIOCGETD)");
E 2
I 2
	if (ioctl(fd, TIOCSETP, &sgtty) < 0) {
		perror("ioctl(TIOCSETP)");
		exit(1);
	}
D 5
	if (ioctl(fd, TIOCSETD, &slipdisc) < 0) {
		perror("ioctl(TIOCSETD)");
E 5
I 5
D 6
	if (ioctl(fd, TIOCSLATTACH, &ifnum) < 0) {
E 6
I 6
	if (ifname[0] == 's' && ioctl(fd, TIOCSLATTACH, &ifnum) < 0) {
E 6
		perror("ioctl(TIOCSLATTACH)");
I 6
		exit(1);
	}
	if (ifname[0] == 'p' && ioctl(fd, TIOCPPPATTACH, &ifnum) < 0) {
		perror("ioctl(TIOCPPPATTACH)");
E 6
E 5
		exit(1);
	}
E 2

D 2
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd < 0)
		error(1, errno, "socket(AF_INET, SOCK_DGRAM)");
	sprintf(ifr.ifr_name, "sl%d", n);

#ifdef sun
	/*
	 * This crap is necessary because sun changed the ioctl handling so
	 * that SIOCSIFDSTADDR ONLY gets handed the value of ifr_data, not
	 * the whole ifr structure like any sane implementation would. This
	 * is clearly a mistake on their part. Fortunately, sizeof (caddr_t)
	 * == sizeof(sin.sin_addr.s_addr) if it's not on your machine, you
	 * lose. 
	 */
	getaddr(argv[3], &sin);
	ifr.ifr_data = (caddr_t) sin.sin_addr.s_addr;
#else vax
	getaddr(argv[3], (struct sockaddr_in *)&ifr.ifr_dstaddr);
#endif vax
	if (ioctl(fd, SIOCSIFDSTADDR, (caddr_t)&ifr) < 0)
		error(1, errno, "ioctl(SIOCSIFDSTADDR)");
	getaddr(argv[2], (struct sockaddr_in *)&ifr.ifr_addr);
	if (ioctl(fd, SIOCSIFADDR, (caddr_t)&ifr) < 0)
		error(1, errno, "ioctl(SIOCSIFADDR)");
E 2
I 2
	if (fork() > 0)
		exit(0);
E 2
	for (;;)
D 3
		sigpause(0);
E 3
I 3
		sigpause(0L);
E 3
}

struct sg_spds {
	int sp_val, sp_name;
}       spds[] = {
#ifdef B50
	{ 50, B50 },
#endif
#ifdef B75
	{ 75, B75 },
#endif
#ifdef B110
	{ 110, B110 },
#endif
#ifdef B150
	{ 150, B150 },
#endif
#ifdef B200
	{ 200, B200 },
#endif
#ifdef B300
	{ 300, B300 },
#endif
#ifdef B600
	{ 600, B600 },
#endif
#ifdef B1200
	{ 1200, B1200 },
#endif
#ifdef B1800
	{ 1800, B1800 },
#endif
#ifdef B2000
	{ 2000, B2000 },
#endif
#ifdef B2400
	{ 2400, B2400 },
#endif
#ifdef B3600
	{ 3600, B3600 },
#endif
#ifdef B4800
	{ 4800, B4800 },
#endif
#ifdef B7200
	{ 7200, B7200 },
#endif
#ifdef B9600
	{ 9600, B9600 },
#endif
#ifdef EXTA
	{ 19200, EXTA },
#endif
#ifdef EXTB
	{ 38400, EXTB },
#endif
	{ 0, 0 }
};

findspeed(speed)
	register int speed;
{
	register struct sg_spds *sp;

	sp = spds;
	while (sp->sp_val && sp->sp_val != speed)
		sp++;
	return (sp->sp_name);
D 2
}

struct in_addr inet_makeaddr();

getaddr(s, sin)
	char *s;
	register struct sockaddr_in *sin;
{
	register struct hostent *hp;
	register struct netent *np;
	int val;

	bzero(sin, sizeof(struct sockaddr_in));
	hp = gethostbyname(s);
	if (hp) {
		sin->sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, (char *) &sin->sin_addr, hp->h_length);
		return;
	}
	np = getnetbyname(s);
	if (np) {
		sin->sin_family = np->n_addrtype;
		sin->sin_addr = inet_makeaddr(np->n_net, INADDR_ANY);
		return;
	}
	sin->sin_family = AF_INET;
	val = inet_addr(s);
	if (val != -1) {
		sin->sin_addr.s_addr = val;
		return;
	}
	val = inet_network(s);
	if (val != -1) {
		sin->sin_addr = inet_makeaddr(val, INADDR_ANY);
		return;
	}
	error(1, 0, "%s: bad value\n", s);
E 2
}
E 1

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

#ifndef lint
char copyright[] =
"@(#) Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "@(#)slattach.c	4.5 (Berkeley) 7/19/02";
#endif /* not lint */

#include <stdio.h>
#include <sys/param.h>
#include <sgtty.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <fcntl.h>
#include <ctype.h>

#define DEFAULT_BAUD	9600

char	devname[32];

main(argc, argv)
	int argc;
	char *argv[];
{
	register int fd;
	register char *dev = argv[2];
	char *ifname = argv[1];
	struct sgttyb sgtty;
	int	ifnum;
	int	speed;

	if (argc < 3 || argc > 4) {
		fprintf(stderr, "usage: %s ifname ttyname [baudrate]\n",
			argv[0]);
		exit(1);
	}
	if (ifname[0] == 's' && ifname[1] == 'l' && isdigit(ifname[2]))
		ifnum = atoi(ifname + 2);
	else if (ifname[0] == 'p' && ifname[1] == 'p' && ifname[2] == 'p' &&
		 isdigit(ifname[3]))
		ifnum = atoi(ifname + 3);
	else {
		fprintf(stderr, "%s is not a valid interface for %s\n", ifname,
			argv[0]);
		exit(1);
	}
	speed = argc == 4 ? findspeed(atoi(argv[3])) : findspeed(DEFAULT_BAUD);
	if (speed == 0) {
		fprintf(stderr, "unknown speed %s\n", argv[3]);
		exit(1);
	}
	if (!index(dev, '/')) {
		(void)sprintf(devname, "/dev/%s", dev);
		dev = devname;
	}
	if ((fd = open(dev, O_RDWR | O_NDELAY)) < 0) {
		perror(dev);
		exit(1);
	}
	sgtty.sg_flags = RAW | ANYP;
	sgtty.sg_ispeed = sgtty.sg_ospeed = speed;
	if (ioctl(fd, TIOCSETP, &sgtty) < 0) {
		perror("ioctl(TIOCSETP)");
		exit(1);
	}
	if (ifname[0] == 's' && ioctl(fd, TIOCSLATTACH, &ifnum) < 0) {
		perror("ioctl(TIOCSLATTACH)");
		exit(1);
	}
	if (ifname[0] == 'p' && ioctl(fd, TIOCPPPATTACH, &ifnum) < 0) {
		perror("ioctl(TIOCPPPATTACH)");
		exit(1);
	}

	if (fork() > 0)
		exit(0);
	for (;;)
		sigpause(0L);
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
}

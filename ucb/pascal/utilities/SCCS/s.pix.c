h52157
s 00014/00002/00109
d D 5.1 85/06/05 16:28:52 dist 5 4
c Add copyright
e
s 00003/00002/00108
d D 1.4 83/01/22 00:41:18 mckusick 4 3
c new names, new headers
e
s 00004/00002/00106
d D 1.3 82/02/01 13:56:34 mckusic 3 2
c merge pdx into the Pascal system
e
s 00008/00022/00100
d D 1.2 81/03/06 22:49:53 mckusic 2 1
c merge in onyx changes
e
s 00122/00000/00000
d D 1.1 81/03/02 17:23:26 wnj 1 0
c date and time created 81/03/02 17:23:26 by wnj
e
u
U
t
T
I 1
D 2
#
E 2
I 2
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

E 2
/*
 * pix - pi then px
 *
 * Bill Joy UCB August 26, 1977
 */
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2

I 2
#include "whoami.h"
#include "objfmt.h"
I 4
#include "config.h"
E 4
E 2
#define	ERRS	1

char	*name;

int	onintr();

#define	ETXTBSY	26

main(argc, argv)
	int argc;
	char *argv[];
{
	register char **av;
	register int ac;
	int i, io, pid, status;
	extern errno;

	do
		io = open("/dev/null", 0);
	while (io >= 0 && io < 3);
	for (io = 3; io < 15; io++)
		close(io);
	if ((signal(2, 1) & 01) == 0)
		signal(2, onintr);
	for (ac = 1; ac < argc; ac++)
		if (dotted(argv[ac], 'p')) {
			ac++;
			break;
		}
	name = "-o/tmp/pixaXXXXX" + 2;
	mktemp(name);
	for (;;) {
		io = creat(name, 0400);
		if (io > 0)
			break;
		if (name[8] == 'z') {
			perror(name);
			exit(1);
		}
		name[8]++;
	}
	pid = fork();
	if (pid == -1) {
		write(2, "No more processes\n", 18);
		onintr();
	}
	if (pid == 0) {
		if (io != 3) {
			write(2, "Impossible error in pix\n", 24);
			onintr();
		}
		argv[ac] = 0;
		argv[0] = name - 2;
D 2
#ifdef CORY
		/* Temporary to allow accounting to distinguish pix's and pi's */
E 2
		do
D 2
			execv("/usr/bin/pix-pi", argv);
E 2
I 2
D 4
			execv(PI_COMP, argv);
E 4
I 4
			execv(pi_comp, argv);
E 4
E 2
		while (errno == ETXTBSY);
D 2
#endif
		do
			execv("/usr/ucb/pi", argv);
		while (errno == ETXTBSY);
		do
			execv("/usr/bin/pi", argv);
		while (errno == ETXTBSY);
E 2
		write(2, "Can't find pi\n", 14);
		onintr();
	}
	close(io);
	do
		i = wait(&status);
	while (i != pid && i != -1);
	if (i == -1 || (status & 0377))
		onintr();
	if (status != 0) {
		if ((status >> 8) == ERRS)
			write(2, "Execution suppressed due to compilation errors\n", 47);
		onintr();
	}
	ac--;
D 3
	argv[ac] = name - 2;
E 3
I 3
	argv[ac] = name;
	ac--;
	argv[ac] = "pix";
E 3
	argv[argc] = 0;
D 2
#ifdef CORY
	/* Temporary to allow accounting to distinguish pix's and px's */
E 2
	do
D 2
		execv("/usr/bin/pix-px", &argv[ac]);
	while (errno == ETXTBSY);
#endif
	do
		execv("/usr/ucb/px", &argv[ac]);
	while (errno == ETXTBSY);
	do
		execv("/usr/bin/px", &argv[ac]);
E 2
I 2
D 3
		execv(PX_INTRP, &argv[ac]);
E 3
I 3
D 4
		execv(PX_DEBUG, &argv[ac]);
E 4
I 4
		execv(px_debug, &argv[ac]);
E 4
E 3
E 2
	while (errno == ETXTBSY);
	write(2, "Can't find px\n", 14);
	onintr();
}

dotted(cp, ch)
	char *cp, ch;
{
	register int i;

	i = strlen(cp);
	return (i > 1 && cp[i - 2] == '.' && cp[i - 1] == ch);
}

onintr()
{

	signal(2, 1);
	unlink(name);
	exit(1);
}
E 1

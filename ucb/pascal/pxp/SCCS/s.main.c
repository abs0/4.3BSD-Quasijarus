h62546
s 00000/00003/00271
d D 5.3 88/06/02 19:19:53 mckusick 8 7
c get rid of sobuf
e
s 00003/00003/00271
d D 5.2 87/03/17 20:23:37 lepreau 7 6
c get rid of old-style asgop syntax
e
s 00016/00003/00258
d D 5.1 85/06/05 15:48:25 dist 6 5
c Add copyright
e
s 00001/00001/00260
d D 2.2 85/01/09 18:17:17 mckusick 5 4
c change interface to gettime() to use one in ../src/subr.c
e
s 00000/00000/00261
d D 2.1 84/02/08 20:23:37 aoki 4 3
c synchronizing at version 2
e
s 00005/00000/00256
d D 1.3 83/05/12 13:52:29 peter 3 2
c accept rmothers -O flag.
e
s 00002/00001/00254
d D 1.2 82/08/13 15:32:26 peter 2 1
c use new char version[]; add `make newversion' entry.
e
s 00255/00000/00000
d D 1.1 81/03/02 21:28:23 peter 1 0
c date and time created 81/03/02 21:28:23 by peter
e
u
U
t
T
I 1
D 6
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 6
/*
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

#include "0.h"

/*
 * This program is described in detail in the "PXP 1.0 Implementation Notes"
 *
 * The structure of pxp is very similar to that of the translator pi.
 * The major new pieces here are a set of profile data maintenance
 * routines in the file pmon.c and a set of pretty printing utility
 * routines in the file pp.c.
 * The semantic routines of pi have been rewritten to do a simple
 * reformatting tree walk, the parsing and scanning remains
 * the same.
 *
 * This version does not place more than one statement per line and
 * is not very intelligent about folding long lines, with only
 * an ad hoc way of folding case label list and enumerated type
 * declarations being implemented.
 */

char	usagestr[] =
	"pxp [ -acdefjntuw_ ] [ -23456789 ] [ -z [ name ... ] ] name.p";
char	*howfile =	"/usr/lib/how_pxp";
char	*stdoutn =	"Standard output";

int	unit =	4;

FILE	*ibuf;
extern	char errout;

/*
 * Main program for pxp.
 * Process options, then call yymain
 * to do all the real work.
 */
FILE *ibp;
main(argc, argv)
	int argc;
	char *argv[];
{
	register char *cp;
	register c;

	if (argv[0][0] == 'a')
D 7
		howfile =+ 9;
E 7
I 7
		howfile += 9;
E 7
	argc--, argv++;
	if (argc == 0) {
		execl("/bin/cat", "cat", howfile, 0);
		goto usage;
	}
	while (argc > 0) {
		cp = argv[0];
		if (*cp++ != '-')
			break;
		while (c = *cp++) switch (c) {
#ifdef DEBUG
			case 'T':
				typetest++;
				continue;
			case 'A':
				testtrace++;
			case 'F':
				fulltrace++;
			case 'E':
				errtrace++;
				continue;
			case 'C':
				yycosts();
				pexit(NOSTART);
			case 'U':
				yyunique++;
				continue;
#endif
			case 'a':
				all++;
				continue;
			case 'c':
				core++;
				continue;
			case 'd':
				nodecl++;
				continue;
			case 'e':
				noinclude = -1;
				continue;
			case 'f':
				full++;
				continue;
			case 'j':
				justify++;
				continue;
			case 'l':
			case 'n':
				togopt(c);
				continue;
			case 'o':
				onefile++;
				continue;
			case 's':
				stripcomm++;
				continue;
			case 't':
				table++;
				continue;
			case 'u':
			case 'w':
				togopt(c);
				continue;
			case 'z':
				profile++;
				pflist = argv + 1;
				pflstc = 0;
				while (argc > 1) {
					if (dotted(argv[1], 'p'))
						break;
					pflstc++, argc--, argv++;
				}
				if (pflstc == 0)
					togopt(c);
				else
					nojunk++;
				continue;
			case '_':
				underline++;
				continue;
I 3
#			ifdef RMOTHERS
			case 'O':
				rmothers++;
				continue;
#			endif RMOTHERS
E 3
			default:
				if (c >= '2' && c <= '9') {
					unit = c - '0';
					continue;
				}
usage:
				Perror("Usage", usagestr);
				exit(1);
		}
		argc--, argv++;
	}
	if (core && !profile && !table)
		profile++;
	if (argc == 0 || argc > 2)
		goto usage;
	if (profile || table) {
		noinclude = 0;
		if (argc == 2) {
			argc--;
			getit(argv[1]);
		} else
			getit(core ? "core" : "pmon.out");
	} else
		noinclude++;
	if (argc != 1)
		goto usage;
	firstname = filename = argv[0];
	if (dotted(filename, 'i')) {
		if (profile || table)
			goto usage;
		noinclude = 1;
		bracket++;
	} else if (!dotted(filename, 'p')) {
		Perror(filename, "Name must end in '.p'");
		exit(1);
	}
	if ((ibuf = fopen(filename, "r")) == NULL)
		perror(filename), pexit(NOSTART);
	ibp = ibuf;
	if (onefile) {
		int onintr();

		cp = (stdoutn = "/tmp/pxp00000") + 13;
		signal(2, onintr);
D 7
		for (c = getpid(); c; c =/ 10)
			*--cp =| (c % 10);
E 7
I 7
		for (c = getpid(); c; c /= 10)
			*--cp |= (c % 10);
E 7
		if (freopen(stdoutn, "w", stdout) == NULL)
bad:
			perror(stdoutn), exit(1);
D 8
	} else {
		extern char _sobuf[BUFSIZ];
		setbuf(stdout, _sobuf);
E 8
	}
	if (profile || opt('l')) {
		opt('n')++;
		yysetfile(filename);
		opt('n')--;
	} else
		lastname = filename;
	errout = 2;
	yymain();
	/* No return */
}

/*
 * Put a header on a top of a page
 */
header()
{
	extern char version[];
	static char reenter;
	extern int outcol;

D 5
	gettime();
E 5
I 5
	gettime(filename);
E 5
	if (reenter) {
		if (outcol)
			putchar('\n');
		putchar('\f');
	}
	reenter++;
	if (profile || table) {
D 2
		printf("Berkeley Pascal PXP -- Version 1.1 (%s)\n\n%s  %s\n\n", version, myctime(&tvec), filename);
E 2
I 2
		printf("Berkeley Pascal PXP -- Version %s\n\n%s  %s\n\n",
			version, myctime(&tvec), filename);
E 2
		printf("Profiled %s\n\n", myctime(&ptvec));
	}
}

char	ugh[] =	"Fatal error in pxp\n";
/*
 * Exit from the Pascal system.
 * We throw in an ungraceful termination
 * message if c > 1 indicating a severe
 * error such as running out of memory
 * or an internal inconsistency.
 */
pexit(c)
	int c;
{
	register char *cp;
	extern int outcol;

	if (stdoutn[0] == '/')
		unlink(stdoutn);
	if (outcol)
		putchar('\n');
	flush();
	if (c == DIED)
		write(2, ugh, sizeof ugh);
	exit(c);
}

onintr()
{

	pexit(DIED);
}

puthedr()
{

	yysetfile(filename);
}
E 1

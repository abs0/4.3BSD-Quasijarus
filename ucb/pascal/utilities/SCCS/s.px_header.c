h25750
s 00000/00002/00146
d D 5.2 85/06/21 15:19:26 mckusick 7 6
c botched copyright
e
s 00016/00000/00132
d D 5.1 85/06/05 16:30:21 dist 6 5
c Add copyright
e
s 00002/00001/00130
d D 1.5 83/04/08 14:54:16 mckusick 5 4
c convert to run on the mc68000
e
s 00003/00002/00128
d D 1.4 83/01/22 00:56:08 mckusick 4 3
c new names, new header files, new .o files
e
s 00074/00032/00056
d D 1.3 82/02/01 13:56:18 mckusic 3 2
c merge pdx into the Pascal system
e
s 00011/00011/00077
d D 1.2 81/03/06 22:50:01 mckusic 2 1
c merge in onyx changes
e
s 00088/00000/00000
d D 1.1 81/03/02 17:23:27 wnj 1 0
c date and time created 81/03/02 17:23:27 by wnj
e
u
U
t
T
I 1
D 2
#include <pagsiz.h>
#include <sys/types.h>
#include <a.out.h>
#include "whoami.h"
#include "objfmt.h"

E 2
/*
I 6
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

/*
E 6
 * pxheader - program to sit in front of interpreter code to make shell mods
 *	      unnecessary to make Pascal obj's look like real programs.
 *
 * This program lives in /usr/lib/px_header
 * Bill Joy UCB February 6, 1978
 */
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2

D 2
extern	errno;
E 2
I 2
D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 2

E 7
D 2
#define	BUFSIZ	BSIZE
E 2
I 2
#include <stdio.h>
#include <sys/types.h>
#include <a.out.h>
I 4
#include "config.h"
E 4
#include "whoami.h"
#include "objfmt.h"

E 2
#define	ETXTBSY	26
D 5
#define	ADDR_LC	HEADER_BYTES - sizeof (struct exec) - sizeof (struct pxhdr)
E 5
I 5
#define	ADDR_LC \
	(START + HEADER_BYTES - sizeof (struct exec) - sizeof (struct pxhdr))
E 5
I 3
#define MAXARGS 512
E 3

I 2
extern	errno;

E 2
main(argc, argv)
	register int argc;
	register char *argv[];
{
D 3
	register int i, j;
	register unsigned short *ip;
	char *largv[512];
	int pv[2];
E 3
I 3
	register int i;
	int codesiz, symtabsiz;
	register char *cp;
	char *largv[MAXARGS];
	int fd, pv[2], pid;
E 3

D 3
	if (argc > 510) {
		error("Too many arguments.\n");
		exit(1);
E 3
I 3
	cp = (char *)(ADDR_LC);
	codesiz = ((struct pxhdr *)(cp))->objsize + sizeof(struct pxhdr);
	symtabsiz = ((struct pxhdr *)(cp))->symtabsize;
	if (argc > MAXARGS - 3)
		error(2, "Too many arguments.\n");
	if (symtabsiz != 0) {
		largv[0] = "pxhdr";
		largv[1] = "/tmp/px00000";
		cp = &largv[1][11];
		for (i = getpid(); i > 0; i /= 10)
			*cp-- = '0' + i % 10;
		fd = creat(largv[1], 0444);
		if (fd < 0)
			error(3, "Cannot create /tmp file\n");
		for (i = 0; i < argc; i++)
			largv[i + 2] = argv[i];
		largv[argc + 2] = 0;
		writeobj(fd, codesiz, symtabsiz);
D 4
		run(PX_DEBUG, largv);
E 4
I 4
		run(px_debug, largv);
E 4
		/* no return */
E 3
	}
D 3
	largv[0] = argv[0];
	largv[1] = "-";
	for (i = 1; i < argc; i++)
E 3
I 3
	largv[0] = "pipe";
	for (i = 0; i < argc; i++)
E 3
		largv[i + 1] = argv[i];
	largv[argc + 1] = 0;
	pipe(pv);
D 3
	i = fork();
	if (i == -1)
		error("Try again.\n");
	if (i == 0) {
		close(pv[0]);
D 2
		ip = (unsigned short *) (ADDR_LC);
		i = ((struct pxhdr *)(ADDR_LC))->objsize + sizeof(struct pxhdr);
E 2
I 2
		ip = (unsigned short *)(ADDR_LC);
		i = ((struct pxhdr *)(ip))->objsize + sizeof(struct pxhdr);
E 2
		while (i != 0) {
			j = (i > 0 && i < BUFSIZ) ? i : BUFSIZ;
			write(pv[1], ip, j);
			ip += BUFSIZ / sizeof ( unsigned short );
			i -= j;
E 3
I 3
	pid = fork();
	if (pid != 0) {
		if (pv[0] != 3) {
			close(3);
			dup(pv[0]);
			close(pv[0]);
E 3
		}
D 3
		exit(1);
E 3
I 3
		close(pv[1]);
D 4
		run(PX_INTRP, largv);
E 4
I 4
		run(px_intrp, largv);
E 4
		/* no return */
E 3
	}
D 3
	close(pv[1]);
	if (pv[0] != 3) {
		close(3);
		dup(pv[0]);
		close(pv[0]);
E 3
I 3
	writeobj(pv[1], codesiz, symtabsiz);
	exit(0);
}

writeobj(fd, codesiz, symtabsiz)
	int fd;
	int codesiz, symtabsiz;
{
	int i;
	register char *cp;

	cp = (char *)(ADDR_LC);
	while (codesiz != 0) {
		i = (codesiz < BUFSIZ) ? codesiz : BUFSIZ;
		write(fd, cp, i);
		cp += i;
		codesiz -= i;
E 3
	}
I 3
	while (symtabsiz != 0) {
		i = (symtabsiz < BUFSIZ) ? symtabsiz : BUFSIZ;
		write(fd, cp, i);
		cp += i;
		symtabsiz -= i;
	}
	close(fd);
}

run(prog, args)
	char *prog;
	char **args;
{
E 3
	for (;;) {
D 3
		execv(PX_INTRP, largv);
E 3
I 3
		execv(prog, args);
E 3
		if (errno != ETXTBSY)
			break;
		sleep(2);
	}
D 3
	error("Px not found.\n");
E 3
I 3
	error(0, prog);
	error(1, " not found.\n");
E 3
}

D 3
error(cp)
E 3
I 3
error(errcode, cp)
	int errcode;
E 3
	register char *cp;
{
	register int i;
	register char *dp;

	dp = cp;
	i = 0;
	while (*dp++)
		i++;
	write(2, cp, i);
D 3
	exit(1);
E 3
I 3
	if (errcode)
		exit(errcode);
E 3
}

exit(i)
{
	_exit(i);
}
E 1

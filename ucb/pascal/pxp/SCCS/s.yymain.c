h31399
s 00001/00001/00182
d D 5.3 87/12/04 19:04:22 bostic 6 5
c old assignment operator
e
s 00000/00006/00183
d D 5.2 85/06/21 16:58:22 mckusick 5 4
c botched copyright
e
s 00016/00003/00173
d D 5.1 85/06/05 15:56:33 dist 4 3
c Add copyright
e
s 00000/00000/00176
d D 2.1 84/02/08 20:23:18 aoki 3 2
c synchronizing at version 2
e
s 00001/00000/00175
d D 1.2 83/05/11 21:49:10 peter 2 1
c since input buffer is variable sized, people who include yy.h need whoami.h.
e
s 00175/00000/00000
d D 1.1 81/03/02 21:29:41 peter 1 0
c date and time created 81/03/02 21:29:41 by peter
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
#
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
/*
 * pi - Pascal interpreter code translator
 *
 * Charles Haley, Bill Joy UCB
 * Version 1.2 November 1978
 *
 *
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 November 1978
 */

I 2
#include "whoami.h"
E 2
#include "0.h"
#include "yy.h"

int	line = 1;

/*
 * Yymain initializes each of the utility
 * clusters and then starts the processing
 * by calling yyparse.
 */
yymain()
{

	/*
	 * Initialize the scanner
	 */
#ifdef PXP
	if (bracket == 0) {
#endif
		if (getline() == -1) {
			Perror(filename, "No lines in file");
			pexit(NOSTART);
		}
#ifdef PXP
	} else
		yyline = 0;
#endif

#ifdef PI
	magic();

#endif
	/*
	 * Initialize the clusters
	 *
	initstring();
	 */
	inithash();
	inittree();
#ifdef PI
	initnl();
#endif

	/*
	 * Process the input
	 */
	yyparse();
#ifdef PI
	magic2();
#ifdef DEBUG
	dumpnl(0);
#endif
#endif
#ifdef PXP
	prttab();
	if (onefile) {
		extern int outcol;

		if (outcol)
			putchar('\n');
		flush();
		if (eflg) {
			writef(2, "File not rewritten because of errors\n");
			pexit(ERRS);
		}
		signal(1, 1);
		signal(2, 1);
		copyfile();
	}
#endif
	pexit(eflg ? ERRS : AOK);
}

#ifdef PXP
copyfile()
{
	register int c;
	char buf[BUFSIZ];

	if (freopen(stdoutn, "r", stdin) == NULL) {
		perror(stdoutn);
		pexit(ERRS);
	}
	if (freopen(firstname, "w", stdout) == NULL) {
		perror(firstname);
		pexit(ERRS);
	}
	while ((c = getchar()) > 0)
		putchar(c);
	if (ferror(stdout))
		perror(stdout);
}
#endif

static
struct {
	int		magic;
	unsigned	txt_size;
	unsigned	data_size;
	unsigned	bss_size;
	unsigned	syms_size;
	unsigned	entry_point;
	unsigned	tr_size;
	unsigned	dr_size;
} header;

#ifdef PI
magic()
{

    /*
     *	this is the size of /usr/lib/npxheader
     */
#define	HEAD_BYTES	1024
	short		buf[HEAD_BYTES / sizeof ( short )];
	unsigned	*ubuf = buf;
	register int	hf, i;

	hf = open("/usr/lib/npx_header", 0);
	if (hf >= 0 && read(hf, buf, HEAD_BYTES) > sizeof header) {
		header.magic = ubuf[0];
		header.txt_size = ubuf[1];
		header.data_size = ubuf[2];
		header.bss_size = ubuf[3];
		header.syms_size = ubuf[4];
		header.entry_point = ubuf[5];
		header.tr_size = ubuf[6];
		header.dr_size = ubuf[7];
		for (i = 0; i < HEAD_BYTES / sizeof ( short ); i++)
			word(buf[i]);
	}
	close(hf);
	word(0404);
}

magic2()
{
	short i;

	if  (header.magic != 0407)
		panic ( "magic2" );
	pflush();
	lseek(ofil, 0l, 0);
	header.data_size = ( unsigned ) lc - header.txt_size;
D 6
	header.data_size =- sizeof header;
E 6
I 6
	header.data_size -= sizeof header;
E 6
	write(ofil, &header, sizeof header);
	lseek(ofil, ( long ) ( HEAD_BYTES - sizeof ( short ) ) , 0);
	i = ( ( unsigned ) lc) - HEAD_BYTES;
	write(ofil, &i, 2);
}
#endif

#ifdef PXP
writef(i, cp)
{

	write(i, cp, strlen(cp));
}
#endif
E 1

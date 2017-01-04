h14892
s 00010/00005/00880
d D 5.4 88/06/30 17:53:17 bostic 12 11
c install approved copyright notice
e
s 00015/00003/00870
d D 5.3 88/03/08 08:30:03 bostic 11 10
c add Berkeley specific header
e
s 00003/00011/00870
d D 5.2 86/10/29 13:50:34 mckusick 10 9
c delete vax specific code
e
s 00007/00001/00874
d D 5.1 85/05/15 11:32:37 dist 9 8
c Add copyright notice
e
s 00001/00001/00874
d D 4.7 84/03/12 16:05:00 ralph 8 7
c fix page accounting computation.
e
s 00005/00006/00870
d D 4.6 83/12/09 12:13:03 ralph 7 6
c provide defaults if -x and -y not specified.
e
s 00004/00001/00872
d D 4.5 83/07/16 23:47:42 sam 6 5
c add useful sccs id's
e
s 00016/00033/00857
d D 4.4 83/05/16 17:20:59 ralph 5 4
c changes for px and py printcap entries.
e
s 00013/00025/00877
d D 4.3 83/04/29 11:53:22 ralph 4 3
c changes for new printer daemon.
e
s 00014/00027/00888
d D 4.2 83/03/17 15:46:18 ralph 3 1
c standardized signal handling
e
s 00014/00027/00888
d R 4.2 83/03/17 15:39:21 ralph 2 1
c 
e
s 00915/00000/00000
d D 4.1 83/03/07 14:50:50 ralph 1 0
c date and time created 83/03/07 14:50:50 by ralph
e
u
U
t
T
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
 */

E 9
I 1
D 3
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sgtty.h>
#include <pwd.h>
#include <sys/vcmd.h>
#include <vfont.h>

E 3
I 3
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
#ifndef lint
I 11
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif
E 9
I 9
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11
E 9

E 6
E 3
/*
 * Cat Simulator for Versatec and Varian
 * Modified for Varian with rotated fonts: wnj 5/30/80.
 *
 * Takes two extra special codes defined by rvsort:
 *	0115 - break for new page, goto (0,0)
 *	0116 - lead 64* following byte
 */ 

D 3
static char *sccsid ="%W% (Berkeley) %G%";
E 3
I 3
D 4
#include <signal.h>
E 4
#include <stdio.h>
#include <sys/vcmd.h>
#include <vfont.h>
E 3

D 4
int	prtmode[] = {VPRINT, 0, 0};
int	pltmode[] = {VPLOT, 0, 0};
E 4
I 4
int	prtmode[] = {VPRINT};
int	pltmode[] = {VPLOT};
E 4

#define DISPATCHSIZE		256	/* must be a power of two */
#define CHARMASK		(DISPATCHSIZE-1)
#define NFONTS			25
#define SPECIALFONT		3
#define DSIZ			((sizeof *dispatch)*DISPATCHSIZE)
#define MAXF			4

#define LOCAL_RAILMAG		".railmag"
#define GLOBAL_RAILMAG		"/usr/lib/vfont/railmag"

/*
 * Here we make up for the fact that we only have 2112
 * bits vertically when we need 2200 (11''*200/in), by
 * a 4% vertical size squashing.
 */
#define CONVERT(n)		((n*(200./432.))*(2112./2200.))
#define RECONVERT(n)		((n*(432./200.))*(2200./2112.))

D 5
#define VA_RASTER_LENGTH	2112

#define VA_BYTES_PER_LINE	(VA_RASTER_LENGTH/8)

E 5
#define NLINES			110
D 5
#define VA_BUFFER_SIZE		(NLINES*VA_BYTES_PER_LINE)
E 5

#define	FF_LINES		1600	/* Scan lines to output before formfeeding. */
D 5
#define	PAGE_LINES		1700	/* 8.5 inches * 200 lines/inch. */
E 5

#define	min(a,b)		(a<b ? a : b)

D 5
char	buffer[VA_BUFFER_SIZE];	/* Big line buffers  */
char	*buf0p = &buffer[0];	/* Zero origin in circular buffer  */
E 5
I 5
char	buffer[NLINES * 264];	/* Big enough for varain */
char	*buf0p = &buffer[0];	/* Zero origin in circular buffer */
E 5

char	*calloc();
char	*nalloc();
char	*allpanic();

struct	header	header;
struct dispatch *dispatch;

struct	fontdes {
	int	fnum;
	int	psize;
	struct	dispatch *disp;
	char	*bits;
} fontdes[NFONTS] = {
	-1,
	-1
};

struct point_sizes {
	int	stupid_code;
	int	real_code;
} point_sizes[] = {
	010, 6,
	0, 7,
	01, 8,
	07, 9,
	02, 10,
	03, 11,
	04, 12,
	05, 14,
	0211, 16,
	06, 18,
	0212, 20,
	0213, 22,
	0214, 24,
	0215, 28,
	0216, 36,
	0, 0
};

D 5
#define VA_FFLINES	2200
#define VP_FFLINES	650
#define VP_EOTLINES	1400

E 5
int	lines;

D 7
int	vc = 1;		/* varian/versatec output file descriptor */
int	varian;		/* 0 for versatec, 1 for varian. */
D 5
int	BYTES_PER_LINE;	/* VA_BYTES_PER_LINE or VP_BYTES_PER_LINE. */
int	BUFFER_SIZE;	/* VA_BUFFER_SIZE or VP_BUFFER_SIZE. */
E 5
I 5
int	BYTES_PER_LINE;	/* number of bytes per raster line. */
int	PAGE_LINES;	/* number of raster lines per page. */
int	BUFFER_SIZE;	/* buffer size. */
E 7
I 7
int	vc = 1;			/* varian/versatec output file descriptor */
int	varian = 1;		/* 0 for versatec, 1 for varian. */
int	BYTES_PER_LINE = 264;	/* number of bytes per raster line. */
int	PAGE_LINES = 1700;	/* number of raster lines per page. */
int	BUFFER_SIZE = NLINES * 264;	/* buffer size. */
E 7
E 5
int	cfnum = -1;
int	cpsize = 10;
int	cfont = 1;
char	*bits;
int	nfontnum = -1;
int	fontwanted = 1;
int	npsize = 10;
int	last_ssize = 02;
int	xpos, ypos;
int	esc, lead, back, verd, mcase, railmag;
double	row, col;
char	*fontname[MAXF];
char	fnbuf[120];
char	*scanline;
int	linecount;

char	asctab[128] = {
	'\0',	/*blank*/
	'h',	/*h*/
	't',	/*t*/
	'n',	/*n*/
	'm',	/*m*/
	'l',	/*l*/
	'i',	/*i*/
	'z',	/*z*/
	's',	/*s*/
	'd',	/*d*/
	'b',	/*b*/
	'x',	/*x*/
	'f',	/*f*/
	'j',	/*j*/
	'u',	/*u*/
	'k',	/*k*/
	'\0',	/*blank*/
	'p',	/*p*/
	'\06',	/*_ 3/4 em dash*/
	';',	/*;*/
	'\0',	/*blank*/
	'a',	/*a*/
	'\05',	/*rule*/
	'c',	/*c*/
	'`',	/*` open*/
	'e',	/*e*/
	'\'',	/*' close*/
	'o',	/*o*/
	'\021',	/*1/4*/
	'r',	/*r*/
	'\022',	/*1/2*/
	'v',	/*v*/
	'-',	/*- hyphen*/
	'w',	/*w*/
	'q',	/*q*/
	'/',	/*/*/
	'.',	/*.*/
	'g',	/*g*/
	'\023',	/*3/4*/
	',',	/*,*/
	'&',	/*&*/
	'y',	/*y*/
	'\0',	/*blank*/
	'%',	/*%*/
	'\0',	/*blank*/
	'Q',	/*Q*/
	'T',	/*T*/
	'O',	/*O*/
	'H',	/*H*/
	'N',	/*N*/
	'M',	/*M*/
	'L',	/*L*/
	'R',	/*R*/
	'G',	/*G*/
	'I',	/*I*/
	'P',	/*P*/
	'C',	/*C*/
	'V',	/*V*/
	'E',	/*E*/
	'Z',	/*Z*/
	'D',	/*D*/
	'B',	/*B*/
	'S',	/*S*/
	'Y',	/*Y*/
	'\0',	/*blank*/
	'F',	/*F*/
	'X',	/*X*/
	'A',	/*A*/
	'W',	/*W*/
	'J',	/*J*/
	'U',	/*U*/
	'K',	/*K*/
	'0',	/*0*/
	'1',	/*1*/
	'2',	/*2*/
	'3',	/*3*/
	'4',	/*4*/
	'5',	/*5*/
	'6',	/*6*/
	'7',	/*7*/
	'8',	/*8*/
	'9',	/*9*/
	'*',	/***/
	'\04',	/*minus*/
	'\01',	/*fi*/
	'\02',	/*fl*/
	'\03',	/*ff*/
	'\020',	/* cent sign */
	'\012',	/*ffl*/
	'\011',	/*ffi*/
	'(',	/*(*/
	')',	/*)*/
	'[',	/*[*/
	']',	/*]*/
	'\013',	/* degree */
	'\014',	/* dagger */
	'=',	/*=*/
	'\017',	/* registered */
	':',	/*:*/
	'+',	/*+*/
	'\0',	/*blank*/
	'!',	/*!*/
	'\07',	/* bullet */
	'?',	/*?*/
	'\015',	/*foot mark*/
	'|',	/*|*/
	'\0',	/*blank*/
	'\016',	/* copyright */
	'\010',	/* square */
	'$',	/*$*/
	'\0',
	'\0',
	'"',	/*"*/
	'#',	/*#*/
	'<',	/*<*/
	'>',	/*>*/
	'@',	/*@*/
	'\\',	/*\\*/
	'^',	/*^*/
	'{',	/*{*/
	'}',	/*}*/
	'~'	/*~*/
};

char spectab[128] = {
	'\0',	/*blank*/
	'w',	/*psi*/
	'h',	/*theta*/
	'm',	/*nu*/
	'l',	/*mu*/
	'k',	/*lambda*/
	'i',	/*iota*/
	'f',	/*zeta*/
	'r',	/*sigma*/
	'd',	/*delta*/
	'b',	/*beta*/
	'n',	/*xi*/
	'g',	/*eta*/
	'u',	/*phi*/
	't',	/*upsilon*/
	'j',	/*kappa*/
	'\0',	/*blank*/
	'p',	/*pi*/
	'@',	/*at-sign*/
	'7',	/*down arrow*/
	'\0',	/*blank*/
	'a',	/*alpha*/
	'|',	/*or*/
	'v',	/*chi*/
	'"',	/*"*/
	'e',	/*epsilon*/
	'=',	/*=*/
	'o',	/*omicron*/
	'4',	/*left arrow*/
	'q',	/*rho*/
	'6',	/*up arrow*/
	's',	/*tau*/
	'_',	/*underrule*/
	'\\',	/*\*/
	'W',	/*Psi*/
	'\07',	/*bell system sign*/
	'\001',	/*infinity*/
	'c',	/*gamma*/
	'\002',	/*improper superset*/
	'\003',	/*proportional to*/
	'\004',	/*right hand*/
	'x',	/*omega*/
	'\0',	/*blank*/
	'(',	/*gradient*/
	'\0',	/*blank*/
	'U',	/*Phi*/
	'H',	/*Theta*/
	'X',	/*Omega*/
	'\005',	/*cup (union)*/
	'\006',	/*root en*/
	'\014',	/*terminal sigma*/
	'K',	/*Lambda*/
	'-',	/*minus*/
	'C',	/*Gamma*/
	'\015',	/*integral sign*/
	'P',	/*Pi*/
	'\032',	/*subset of*/
	'\033',	/*superset of*/
	'2',	/*approximates*/
	'y',	/*partial derivative*/
	'D',	/*Delta*/
	'\013',	/*square root*/
	'R',	/*Sigma*/
	'1',	/*approx =*/
	'\0',	/*blank*/
	'>',	/*>*/
	'N',	/*Xi*/
	'<',	/*<*/
	'\016',	/*slash (longer)*/
	'\034',	/*cap (intersection)*/
	'T',	/*Upsilon*/
	'\035',	/*not*/
	'\023',	/*right ceiling (rt of ")*/
	'\024',	/*left top (of big curly)*/
	'\017',	/*bold vertical*/
	'\030',	/*left center of big curly bracket*/
	'\025',	/*left bottom*/
	'\026',	/*right top*/
	'\031',	/*right center of big curly bracket*/
	'\027',	/*right bot*/
	'\021',	/*right floor (rb of ")*/
	'\020',	/*left floor (left bot of big sq bract)*/
	'\022',	/*left ceiling (lt of ")*/
	'*',	/*multiply*/
	'/',	/*divide*/
	'\010',	/*plus-minus*/
	'\011',	/*<=*/
	'\012',	/*>=*/
	'0',	/*identically equal*/
	'3',	/*not equal*/
	'{',	/*{*/
	'}',	/*}*/
	'\'',	/*' acute accent*/
	'\`',	/*` grave accent*/
	'^',	/*^*/
	'#',	/*sharp*/
	'\036',	/*left hand*/
	'\037',	/*member of*/
	'~',	/*~*/
	'z',	/*empty set*/
	'\0',	/*blank*/
	'Y',	/*dbl dagger*/
	'Z',	/*box rule*/
	'9',	/*asterisk*/
	'[',	/*improper subset*/
	']',	/*circle*/
	'\0',	/*blank*/
	'+',	/*eqn plus*/
	'5',	/*right arrow*/
	'8'	/*section mark*/
};

D 3

E 3
D 4
onintr()
{
D 3
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
E 3
	signal(SIGTERM, SIG_IGN);
	exit(1);
}

E 4
main(argc, argv) 
	int argc;
	char *argv[];
{
D 3
	char *namearg;
	char *hostarg;
	char *acctfile;
E 3
I 3
	char *namearg = NULL;
	char *hostarg = NULL;
	char *acctfile = NULL;
E 3

D 3
	if (signal(SIGINT, SIG_IGN) == SIG_DFL) {
		signal(SIGPIPE, SIG_IGN);
		signal(SIGINT, onintr);
		signal(SIGHUP, onintr);
	} else
		signal(SIGHUP, SIG_IGN);
	if (signal(SIGTERM, SIG_IGN) == SIG_DFL)
		signal(SIGTERM, onintr);
E 3
I 3
D 4
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, onintr);
E 3

E 4
D 5
	varian = 1;	/* Default is the varian */
D 3
	namearg = NULL;
	hostarg = NULL;
	acctfile = NULL;
E 3
	BYTES_PER_LINE = VA_BYTES_PER_LINE;
	BUFFER_SIZE = VA_BUFFER_SIZE;

	if (argv[0][strlen(argv[0])-1] == 'W') { /* Wide: the versatec. */
/*
		varian = 0;
		BYTES_PER_LINE = VP_BYTES_PER_LINE;
		BUFFER_SIZE = VP_BUFFER_SIZE;
*/
		fprintf(stderr, "rvcat: W not implemented\n");
	}

E 5
	while (--argc) {
		if (*(*++argv) == '-')
			switch (argv[0][1]) {
I 5
			case 'x':
				BYTES_PER_LINE = atoi(&argv[0][2]) / 8;
				BUFFER_SIZE = NLINES * BYTES_PER_LINE;
D 7
				varian = 1;	/* Default is the varian */
E 7
				break;
E 5

I 5
			case 'y':
				PAGE_LINES = atoi(&argv[0][2]);
				break;

E 5
			case 'n':
				if (argc > 1) {
					argc--;
					namearg = *++argv;
				}
				break;

			case 'h':
				if (argc > 1) {
					argc--;
					hostarg = *++argv;
				}
				break;
D 5

			default:
				fprintf(stderr, "usage: rvcat[W] [-n name] [-h host] [accounting file]\n");
				exit(2);
E 5
			}
		else
			acctfile = *argv;
	}
	ioctl(vc, VSETSTATE, pltmode);
	readrm();
	ofile();
	ioctl(vc, VSETSTATE, prtmode);
	if (varian)
		write(vc, "\f", 2);
	else
		write(vc, "\n\n\n\n\n", 6);
	account(namearg, hostarg, acctfile);
	exit(0);
}

readrm()
{
	register int i;
	register char *cp;
	register int rmfd;
	char c;

	if ((rmfd = open(LOCAL_RAILMAG, 0)) < 0)
		if ((rmfd = open(GLOBAL_RAILMAG, 0)) < 0) {
			fprintf(stderr, "rvcat: No railmag file\n");
			exit(2);
		}
	cp = fnbuf;
D 3
	for (i = 0; i < 4; i++) {
E 3
I 3
	for (i = 0; i < MAXF; i++) {
E 3
		fontname[i] = cp;
		while (read(rmfd, &c, 1) == 1 && c != '\n')
			*cp++ = c;
		*cp++ = '\0';
	}
	close(rmfd);
}

ofile()
{
	register int c;
	register int i;
	double scol;
	static int initialized;

	lines = 0;
	while ((c = getchar()) != EOF) {
		if (!c)
			continue;
		if (c & 0200) {
			esc += (~c) & 0177;
			continue;
		}
		if (esc) {
			if (back)
				esc = -esc;
			col += esc;
			esc = 0;
			i = CONVERT(col);
			while (i >= NLINES) {
				slop_lines(15);
				i = CONVERT(col);
			}
			ypos = i;
		}
		if ((c & 0377) < 0100)	/*  Purely for efficiency  */
			goto normal_char;
		switch (c) {

		case 0100:
			esc = 0;
			lead = 0;
			linecount = 0;
			verd = 0;
			back = 0;
			mcase = 0;
			railmag = 0;
			if (loadfont(railmag, cpsize) < 0)
				fprintf(stderr, "rvcat: Can't load initial font\n");
			if (initialized)
				goto reset;
			initialized = 1;
			row = 0;
			xpos = CONVERT(row);
			for (c = 0; c < BUFFER_SIZE; c++)
				buffer[c] = 0;
			col = 0;
			ypos = 0;
			break;

		case 0101:	/* lower rail */
			crail(railmag &= ~01);
			break;

		case 0102:	/* upper rail */
			crail(railmag |= 01);
			break;

		case 0103:	/* upper mag */
			crail(railmag |= 02);
			break;

		case 0104:	/* lower mag */
			crail(railmag &= ~02);
			break;

		case 0105:	/* lower case */
			mcase = 0;
			break;

		case 0106:	/* upper case */
			mcase = 0100;
			break;

		case 0107:	/* escape forward */
			back = 0;
			break;

		case 0110:	/* escape backwards */
			back = 1;
			break;

		case 0111:	/* stop */
			break;

		case 0112:	/* lead forward */
			verd = 0;
			break;

		case 0113:	/* undefined */
			break;

		case 0114:	/* lead backward */
			verd = 1;
			break;

		case 0115:	/* undefined */
reset:
			c = lines % PAGE_LINES;
			while (c < FF_LINES) {
				slop_lines(min(FF_LINES - c, NLINES));
				c = lines % PAGE_LINES;
			}
			new_page(PAGE_LINES - c);
			break;

		case 0116:
			lead = (getchar() & 0377) * 64;
			goto leadin;

		case 0117:
			break;

		default:
			if ((c & 0340) == 0140)	/* leading */ {
				lead = (~c) & 037;
leadin:
				if (verd)
					lead = -lead;
				row += lead*3;	/*  Lead is 3 units  */
				xpos = CONVERT(row);
				continue;
			}
			if ((c & 0360) == 0120)	/* size change */ {
				loadfont(railmag, findsize(c & 017));
				continue;
			}
			if (c & 0300)
				continue;

normal_char:
D 5
			if (row < 0 || CONVERT(row) >= VA_RASTER_LENGTH)
E 5
I 5
			if (row < 0 || CONVERT(row) >= BYTES_PER_LINE * 8)
E 5
				continue;
			c = (c & 077) | mcase;
			outc(c);
		}
	}
out:
	slop_lines(NLINES);
}

findsize(code)
	register int code;
{
	register struct point_sizes *psp;

	psp = point_sizes;
	while (psp->real_code != 0) {
		if ((psp->stupid_code & 017) == code)
			break;
		psp++;
	}
	code = 0;
	if (!(last_ssize & 0200) && (psp->stupid_code & 0200))
		code = -55;
	else if ((last_ssize & 0200) && !(psp->stupid_code & 0200))
		code = 55;
	if (back)
		code = -code;
	esc += code;
	last_ssize = psp->stupid_code;
D 4
	return (psp->real_code);
E 4
I 4
	return(psp->real_code);
E 4
}

account(who, from, acctfile)
	char *who, *from, *acctfile;
{
	register FILE *a;

	if (who == NULL || acctfile == NULL)
		return;
	if (access(acctfile, 02) || (a = fopen(acctfile, "a")) == NULL)
		return;
	/*
D 4
	 * Varian accounting is done by 11 inch pages;
E 4
I 4
	 * Varian accounting is done by 8.5 inch pages;
E 4
	 * Versatec accounting is by the (12 inch) foot.
	 */
D 4
	fprintf(a, "t%6.2f\t", (lines / 200.0) / (varian ? 11.0 : 12.0));
E 4
I 4
D 5
	fprintf(a, "t%6.2f\t", (lines / 200.0) / (varian ? 8.5 : 12.0));
E 5
I 5
D 8
	fprintf(a, "t%6.2f\t", (lines / 200.0) / PAGE_LINES);
E 8
I 8
	fprintf(a, "t%6.2f\t", (double)lines / (double)PAGE_LINES);
E 8
E 5
E 4
	if (from != NULL)
		fprintf(a, "%s:", from);
	fprintf(a, "%s\n", who);
	fclose(a);
}

crail(nrail)
	register int nrail;
{
	register int psize;

	psize = cpsize;
	if (fontwanted && psize != npsize)
		psize = npsize;
	loadfont(nrail, psize);
}


loadfont(fnum, size)
	register int fnum;
	register int size;
{
	register int i;
	char cbuf[80];

	fontwanted = 0;
	if (fnum == cfnum && size == cpsize)
		return(0);
	for (i = 0; i < NFONTS; i++)
		if (fontdes[i].fnum == fnum && fontdes[i].psize == size) {
			cfnum = fontdes[i].fnum;
			cpsize = fontdes[i].psize;
			dispatch = &fontdes[i].disp[0];
			bits = fontdes[i].bits;
			cfont = i;
D 4
			return (0);
E 4
I 4
			return(0);
E 4
		}
	if (fnum < 0 || fnum >= MAXF) {
		fprintf(stderr, "rvcat: Internal error: illegal font\n");
		return(-1);
	}
	nfontnum = fnum;
	npsize = size;
	fontwanted++;
D 4
	return (0);
E 4
I 4
	return(0);
E 4
}


getfont()
{
	register int fnum, size, font;
	int d;
	char cbuf[BUFSIZ];
	char *cp = cbuf;
	char *dp;

	if (!fontwanted)
		return(0);
	fnum = nfontnum;
	size = npsize;
	sprintf(cbuf, "%s.%dr", fontname[fnum], size);
	font = open(cbuf, 0);
	if (font == -1) {
I 3
		fprintf(stderr, "rvcat: ");
E 3
		perror(cbuf);
		fontwanted = 0;
D 4
		return (-1);
E 4
I 4
		return(-1);
E 4
	}
	if (read(font, &header, sizeof header)!=sizeof header || header.magic!=0436)
		fprintf(stderr, "rvcat: %s: Bad font file", cbuf);
	else {
		cfont = relfont();
		if (((bits=nalloc(header.size+DSIZ+1,1))== NULL)
			&& ((bits=allpanic(header.size+DSIZ+1))== NULL)) {
				fprintf(stderr, "rvcat: %s: ran out of memory\n", cbuf);
				exit(2);
		} else {
			/*
			 * have allocated one chunk of mem for font, dispatch.
			 * get the dispatch addr, align to word boundary.
			 */
			d = (int) bits+header.size;
			d += 1;
			d &= ~1;
			if (read(font, d, DSIZ)!=DSIZ
			  || read(font, bits, header.size)!=header.size)
				fprintf(stderr, "rvcat: bad font header");
			else {
				close(font);
				cfnum = fontdes[cfont].fnum = fnum;
				cpsize = fontdes[cfont].psize = size;
				fontdes[cfont].bits = bits;
				fontdes[cfont].disp = (struct dispatch *) d;
				dispatch = &fontdes[cfont].disp[0];
				fontwanted = 0;
D 4
				return (0);
E 4
I 4
				return(0);
E 4
			}
		}
	}
	close(font);
	fontwanted = 0;
	return(-1);
}

D 4
int lastloaded	= -1;
E 4
I 4
int lastloaded = -1;
E 4

relfont()
{
	register int newfont;

	newfont = lastloaded;
	/*
	 * optimization for special font.  since we think that usually
	 * there is only one character at a time from any special math
	 * font, make it the candidate for removal.
	 */
	if (fontdes[cfont].fnum != SPECIALFONT || fontdes[cfont].bits==0)
		if (++newfont>=NFONTS)
			newfont = 0;
	lastloaded = newfont;
	if ((int)fontdes[newfont].bits != -1 && fontdes[newfont].bits != 0)
		nfree(fontdes[newfont].bits);
	fontdes[newfont].bits = 0;
D 4
	return (newfont);
E 4
I 4
	return(newfont);
E 4
}

char *
allpanic(nbytes)
	int nbytes;
{
	register int i;

	for (i = 0; i <= NFONTS; i++)
		if (fontdes[i].bits != (char *)-1 && fontdes[i].bits != (char *)0)
			nfree(fontdes[i].bits);
	lastloaded = cfont;
	for (i = 0; i <= NFONTS; i++) {
		fontdes[i].fnum = fontdes[i].psize = -1;
		fontdes[i].bits = 0;
		cfnum = cpsize = -1;
	}
	return(nalloc(nbytes,1));
}

int	M[] = { 0xffffffff, 0xfefefefe, 0xfcfcfcfc, 0xf8f8f8f8,
		0xf0f0f0f0, 0xe0e0e0e0, 0xc0c0c0c0, 0x80808080, 0x0 };
int	N[] = { 0x00000000, 0x01010101, 0x03030303, 0x07070707,
		0x0f0f0f0f, 0x1f1f1f1f, 0x3f3f3f3f, 0x7f7f7f7f, 0xffffffff };
int	strim[] = { 0xffffffff, 0xffffff00, 0xffff0000, 0xff000000, 0 };

outc(code)
	int code;
{
	char c;				/* character to print */
	register struct dispatch *d;	/* ptr to character font record */
	register char *addr;		/* addr of font data */
	int llen;			/* length of each font line */
	int nlines;			/* number of font lines */
	register char *scanp;		/* ptr to output buffer */
	int scanp_inc;			/* increment to start of next buffer */
	int offset;			/* bit offset to start of font data */
	int i;				/* loop counter */
	register int count;		/* font data ptr */
	register unsigned fontdata;	/* font data temporary */
	register int off8;		/* offset + 8 */
	int b0poff;			/* bit offset back towards buf0p */

	if (fontwanted)
		getfont();
	if (railmag == SPECIALFONT) {
		if ((c = spectab[code]) < 0)
			return(0);
	} else if ((c = asctab[code]) < 0)
		return(0);
	d = dispatch+c;
	if (d->nbytes) {
		addr = bits+d->addr;
		llen = (d->down+d->up+7)/8;
		nlines = d->left+d->right;
		if (ypos+d->right >= NLINES)
			slop_lines(ypos+d->right-NLINES+6);
		b0poff = BYTES_PER_LINE*8 - 1 - (xpos+d->down);
		scanp = ((ypos-d->left-1)*BYTES_PER_LINE+b0poff/8)+buf0p;
		if (scanp < &buffer[0])
			scanp += BUFFER_SIZE;
		scanp_inc = BYTES_PER_LINE-llen;
		offset = -(b0poff&07);
		off8 = offset+8;
		for (i = 0; i < nlines; i++) {
			if (scanp >= &buffer[BUFFER_SIZE])
				scanp -= BUFFER_SIZE;
			count = llen;
			if (scanp + count <= &buffer[BUFFER_SIZE])
				do {
					fontdata = *(unsigned *)addr;
					addr += 4;
					if (count < 4)
						fontdata &= ~strim[count];
					*(unsigned *)scanp |= (fontdata << offset) &~ M[off8];
					scanp++;
					*(unsigned *)scanp |= (fontdata << off8) &~ N[off8];
					scanp += 3;
					count -= 4;
				} while (count > 0);
			scanp += scanp_inc+count;
			addr += count;
		}
D 4
		return (1);
E 4
I 4
		return(1);
E 4
	}
D 4
	return (0);
E 4
I 4
	return(0);
E 4
}

slop_lines(ncols)
	int ncols;
{
	register int i, rcols;

	lines += ncols;
	rcols = (&buffer[BUFFER_SIZE] - buf0p) / BYTES_PER_LINE;
	if (rcols < ncols) {
		if (write(vc, buf0p, BYTES_PER_LINE * rcols) < 0)
			exit(1);
D 10
		clear(buf0p, rcols * BYTES_PER_LINE);
E 10
I 10
		bzero(buf0p, rcols * BYTES_PER_LINE);
E 10
		buf0p = buffer;
		ncols -= rcols;
		ypos -= rcols;
		col -= RECONVERT(rcols);
	}
	if (write(vc, buf0p, BYTES_PER_LINE * ncols) < 0)
		exit(1);
D 10
	clear(buf0p, BYTES_PER_LINE * ncols);
E 10
I 10
	bzero(buf0p, BYTES_PER_LINE * ncols);
E 10
	buf0p += BYTES_PER_LINE * ncols;
	if (buf0p >= &buffer[BUFFER_SIZE])
		buf0p -= BUFFER_SIZE;
	ypos -= ncols;
	col -= RECONVERT(ncols);
}

D 10
/*ARGSUSED*/
clear(lp, nbytes)
	int *lp;
	int nbytes;
{
	asm("movc5 $0,(sp),$0,8(ap),*4(ap)");
}

E 10
/* Start a new page by formfeeding, resetting buffer and column counters. */
new_page(lines_left)
	int lines_left;		/* ... on page. */
{
	lines += lines_left;
	buf0p = buffer;		/* Clear out buffer and reset pointers. */
D 10
	clear(buf0p, BYTES_PER_LINE * NLINES);
E 10
I 10
	bzero(buf0p, BYTES_PER_LINE * NLINES);
E 10
	row = 0;
	col = 0;
	xpos = CONVERT(row);
	ypos = 0;
	ioctl(vc, VSETSTATE, prtmode);
	write (vc, "\f", 2);
	ioctl(vc, VSETSTATE, pltmode);
}

char *
nalloc(i, j)
	int i, j;
{
	register char *cp;

	cp = calloc(i, j);
	return(cp);
}

nfree(cp)
	char *cp;
{
	free(cp);
}
E 1

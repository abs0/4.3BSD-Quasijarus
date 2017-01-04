h33274
s 00010/00005/00832
d D 5.4 88/06/30 17:53:24 bostic 12 11
c install approved copyright notice
e
s 00015/00003/00822
d D 5.3 88/03/08 08:30:09 bostic 11 10
c add Berkeley specific header
e
s 00002/00010/00823
d D 5.2 86/10/29 13:50:10 mckusick 10 9
c delete vax specific code
e
s 00007/00001/00826
d D 5.1 85/05/15 11:32:56 dist 9 8
c Add copyright notice
e
s 00001/00001/00826
d D 4.7 84/03/12 16:05:19 ralph 8 7
c fix page accounting computation.
e
s 00005/00005/00822
d D 4.6 83/12/09 12:13:34 ralph 7 6
c provide defaults if -x and -y not specified.
e
s 00004/00001/00823
d D 4.5 83/07/16 23:48:19 sam 6 5
c add useful sccs id's
e
s 00015/00029/00809
d D 4.4 83/05/16 17:21:16 ralph 5 4
c changes for px and py printcap entries.
e
s 00013/00025/00825
d D 4.3 83/04/29 11:52:49 ralph 4 3
c changes for new printer daemon.
e
s 00009/00021/00841
d D 4.2 83/03/17 15:46:34 ralph 3 1
c standardized signal handling
e
s 00009/00021/00841
d R 4.2 83/03/17 15:39:37 ralph 2 1
c 
e
s 00862/00000/00000
d D 4.1 80/11/30 15:56:17 root 1 0
c date and time created 80/11/30 15:56:17 by root
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
/*
 * Cat Simulator for Versatec and Varian
 */ 

D 3
#include <errno.h>
E 3
D 4
#include <signal.h>
E 4
#include <stdio.h>
D 3
#include <sgtty.h>
#include <pwd.h>
E 3
#include <sys/vcmd.h>
#include <vfont.h>

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

#define CONVERT(n)		(n*(200./432.))
#define RECONVERT(n)		(n*(432./200.))

D 5
#define VA_RASTER_LENGTH	2112
#define VP_RASTER_LENGTH	7040
#define VA_BYTES_PER_LINE	(VA_RASTER_LENGTH/8)
#define VP_BYTES_PER_LINE	(VP_RASTER_LENGTH/8)
E 5
#define NLINES			110
D 5
#define VA_BUFFER_SIZE		(NLINES*VA_BYTES_PER_LINE)
#define VP_BUFFER_SIZE		(NLINES*VP_BYTES_PER_LINE)
E 5

D 5
char	buffer[VP_BUFFER_SIZE];	/* Big line buffers  */
char	*buf0p = &buffer[0];	/* Zero origin in circular buffer  */
E 5
I 5
char	buffer[NLINES * 880];	/* Big enough for versatec */
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
int	varian;			/* 0 for versatec, 1 for varian. */
int	BYTES_PER_LINE = 880;	/* number of bytes per raster line. */
int	PAGE_LINES = 2400;	/* number of raster lines per page. */
int	BUFFER_SIZE = NLINES * 880;	/* buffer size. */
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
		varian = 0;
		BYTES_PER_LINE = VP_BYTES_PER_LINE;
		BUFFER_SIZE = VP_BUFFER_SIZE;
	}

E 5
	while (--argc) {
		if (*(*++argv) == '-')
			switch (argv[0][1]) {
I 5
			case 'x':
				BYTES_PER_LINE = atoi(&argv[0][2]) / 8;
				BUFFER_SIZE = NLINES * BYTES_PER_LINE;
				varian = BYTES_PER_LINE == 264;
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
				fprintf(stderr, "usage: vcat[W] [-n name] [-h host] [accounting file]\n");
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
			fprintf(stderr, "vcat: No railmag file\n");
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
			ypos = CONVERT(col);
			esc = 0;
		}
		if ((c & 0377) < 0100)	/*  Purely for efficiency  */
			goto normal_char;
		switch (c) {

		case 0100:
			if (initialized)
				goto out;
			initialized = 1;
			row = 25;
			xpos = CONVERT(row);
			for (c = 0; c < BUFFER_SIZE; c++)
				buffer[c] = 0;
			col = 0;
			esc = 0;
			lead = 0;
			ypos = 0;
			linecount = 0;
			verd = 0;
			back = 0;
			mcase = 0;
			railmag = 0;
			if (loadfont(railmag, cpsize) < 0)
				fprintf(stderr, "vcat: Can't load inital font\n");
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
		case 0116:
		case 0117:
			break;

		default:
			if ((c & 0340) == 0140)	/* leading */ {
				lead = (~c) & 037;
				if (verd)
					lead = -lead;
				row += lead*3;	/*  Lead is 3 units  */
				c = CONVERT(row);
				while (c >= NLINES) {
					slop_lines(15);
					c = CONVERT(row);
				}
				xpos = c;
				continue;
			}
			if ((c & 0360) == 0120)	/* size change */ {
				loadfont(railmag, findsize(c & 017));
				continue;
			}
			if (c & 0300)
				continue;

normal_char:
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
		fprintf(stderr, "vcat: Internal error: illegal font\n");
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

	if (!fontwanted)
		return(0);
	fnum = nfontnum;
	size = npsize;
	sprintf(cbuf, "%s.%d", fontname[fnum], size);
	font = open(cbuf, 0);
	if (font == -1) {
I 3
		fprintf(stderr, "vcat: ");
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
		fprintf(stderr, "vcat: %s: Bad font file", cbuf);
	else {
		cfont = relfont();
		if (((bits=nalloc(header.size+DSIZ+1,1))== NULL)
			&& ((bits=allpanic(header.size+DSIZ+1))== NULL)) {
				fprintf(stderr, "vcat: %s: ran out of memory\n", cbuf);
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
				fprintf(stderr, "vcat: bad font header");
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
		llen = (d->left+d->right+7)/8;
		nlines = d->up+d->down;
		if (xpos+d->down >= NLINES)
			slop_lines(xpos+d->down-NLINES+1);
		scanp = ((xpos-d->up-1)*BYTES_PER_LINE+(ypos-d->left)/8)+buf0p;
		if (scanp < &buffer[0])
			scanp += BUFFER_SIZE;
		scanp_inc = BYTES_PER_LINE-llen;
		offset = -((ypos-d->left)&07);
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

slop_lines(nlines)
	int nlines;
{
	register int i, rlines;

	lines += nlines;
	rlines = (&buffer[BUFFER_SIZE] - buf0p) / BYTES_PER_LINE;
	if (rlines < nlines) {
		if (write(vc, buf0p, BYTES_PER_LINE * rlines) < 0)
			exit(1);
D 10
		clear(buf0p, rlines * BYTES_PER_LINE);
E 10
I 10
		bzero(buf0p, rlines * BYTES_PER_LINE);
E 10
		buf0p = buffer;
		nlines -= rlines;
		xpos -= rlines;
		row -= RECONVERT(rlines);
	}
	if (write(vc, buf0p, BYTES_PER_LINE * nlines) < 0)
		exit(1);
D 10
	clear(buf0p, BYTES_PER_LINE * nlines);
E 10
I 10
	bzero(buf0p, BYTES_PER_LINE * nlines);
E 10
	buf0p += BYTES_PER_LINE * nlines;
	if (buf0p >= &buffer[BUFFER_SIZE])
		buf0p -= BUFFER_SIZE;
	xpos -= nlines;
	row -= RECONVERT(nlines);
	/* ioctl(vc, VSETSTATE, pltmode);  WHY? */
D 10
}

/*ARGSUSED*/
clear(lp, nbytes)
	int *lp;
	int nbytes;
{
	asm("movc5 $0,(sp),$0,8(ap),*4(ap)");
E 10
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

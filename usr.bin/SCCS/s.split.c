h62168
s 00010/00005/00235
d D 4.6 88/06/29 21:54:34 bostic 6 5
c install approved copyright notice
e
s 00106/00086/00134
d D 4.5 87/12/02 17:19:10 bostic 5 4
c reformat to standard, add Berkeley header
e
s 00001/00001/00219
d D 4.4 87/05/18 11:51:17 bostic 4 3
c bug report tahoe/usr.bin/1; number of lines arg handled incorrectly
e
s 00207/00069/00013
d D 4.3 86/11/20 15:30:05 bostic 3 2
c bug report 4.3BSD/usr.bin/13; fix max # of files bug; complete rewrite
e
s 00001/00001/00081
d D 4.2 83/04/29 01:48:11 mckusick 2 1
c added perror
e
s 00082/00000/00000
d D 4.1 80/10/01 17:28:33 bill 1 0
c date and time created 80/10/01 17:28:33 by bill
e
u
U
t
T
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
 */
E 5
I 3

I 5
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 5
#include <sys/param.h>
#include <sys/file.h>
E 3
#include <stdio.h>
I 3
#include <ctype.h>
E 3

D 3
unsigned count = 1000;
int	fnumber;
char	fname[100];
char	*ifil;
char	*ofil;
FILE	*is;
FILE	*os;
E 3
I 3
#define DEFLINE	1000			/* default num lines per file */
#define ERR	-1			/* general error */
#define ERREXIT	0			/* error exit */
#define NO	0			/* no/false */
#define OK	0			/* okay exit */
#define YES	1			/* yes/true */
E 3

D 3
main(argc, argv)
char *argv[];
E 3
I 3
static long	bytecnt,		/* byte count to split on */
		numlines;		/* lines in each file */
static int	ifd = ERR,		/* input file descriptor */
		ofd = ERR;		/* output file descriptor */
static short	file_open;		/* if a file open */
static char	bfr[MAXBSIZE],		/* I/O buffer */
		fname[MAXPATHLEN];	/* file name */

D 5
main(argc,argv)
int	argc;
char	**argv;
E 5
I 5
main(argc, argv)
	int	argc;
	char	**argv;
E 5
E 3
{
D 3
	register i, c, f;
	int iflg = 0;
E 3
I 3
	register int	cnt;		/* general counter */
	long	atol();
	char	*strcpy();
E 3

D 3
	for(i=1; i<argc; i++)
		if(argv[i][0] == '-')
			switch(argv[i][1]) {
		
			case '\0':
				iflg = 1;
				continue;
		
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				count = atoi(argv[i]+1);
				continue;
E 3
I 3
D 5
	for (cnt = 1;cnt < argc;++cnt) {
E 5
I 5
	for (cnt = 1; cnt < argc; ++cnt) {
E 5
		if (argv[cnt][0] == '-')
			switch(argv[cnt][1]) {
D 5
				case 0:		/* stdin by request */
					if (ifd != ERR)
						usage();
					ifd = 0;
					break;
				case 'b':	/* byte count split */
					if (numlines)
						usage();
					if (!argv[cnt][2])
						bytecnt = atol(argv[++cnt]);
					else
						bytecnt = atol(argv[cnt] + 2);
					if (bytecnt <= 0) {
						fputs("split: byte count must be greater than zero.\n",stderr);
						usage();
					}
					break;
				default:
					if (!isdigit(argv[cnt][1]) || bytecnt)
						usage();
D 4
					if ((numlines = atol(argv[cnt] + 2)) <= 0) {
E 4
I 4
					if ((numlines = atol(argv[cnt] + 1)) <= 0) {
E 4
						fputs("split: line count must be greater than zero.\n",stderr);
						usage();
					}
					break;
E 5
I 5
			case 0:		/* stdin by request */
				if (ifd != ERR)
					usage();
				ifd = 0;
				break;
			case 'b':	/* byte count split */
				if (numlines)
					usage();
				if (!argv[cnt][2])
					bytecnt = atol(argv[++cnt]);
				else
					bytecnt = atol(argv[cnt] + 2);
				if (bytecnt <= 0) {
					fputs("split: byte count must be greater than zero.\n", stderr);
					usage();
				}
				break;
			default:
				if (!isdigit(argv[cnt][1]) || bytecnt)
					usage();
				if ((numlines = atol(argv[cnt] + 1)) <= 0) {
					fputs("split: line count must be greater than zero.\n", stderr);
					usage();
				}
				break;
E 5
E 3
			}
D 3
		else if(iflg)
			ofil = argv[i];
		else {
			ifil = argv[i];
			iflg = 2;
E 3
I 3
		else if (ifd == ERR) {		/* input file */
D 5
			if ((ifd = open(argv[cnt],O_RDONLY,0)) < 0) {
E 5
I 5
			if ((ifd = open(argv[cnt], O_RDONLY, 0)) < 0) {
E 5
				perror(argv[cnt]);
				exit(ERREXIT);
			}
E 3
		}
D 3
	if(iflg != 2)
		is = stdin;
	else
		if((is=fopen(ifil,"r")) == NULL) {
D 2
			fprintf(stderr,"cannot open input\n");
E 2
I 2
			perror(ifil);
E 2
			exit(1);
E 3
I 3
		else if (!*fname)		/* output file prefix */
D 5
			strcpy(fname,argv[cnt]);
E 5
I 5
			strcpy(fname, argv[cnt]);
E 5
		else
			usage();
	}
	if (ifd == ERR)				/* stdin by default */
		ifd = 0;
	if (bytecnt)
		split1();
	if (!numlines)
		numlines = DEFLINE;
	split2();
}

/*
 * split1 --
 *	split by bytes
 */
static
split1()
{
	register long	bcnt;		/* byte counter */
	register int	dist,		/* buffer offset */
			len;		/* read length */
	register char	*C;		/* tmp pointer into buffer */

	for (bcnt = 0;;)
D 5
		switch(len = read(ifd,bfr,MAXBSIZE)) {
			case 0:
				exit(OK);
			case ERR:
				perror("read");
				exit(ERREXIT);
			default:
				if (!file_open) {
E 5
I 5
		switch(len = read(ifd, bfr, MAXBSIZE)) {
		case 0:
			exit(OK);
		case ERR:
			perror("read");
			exit(ERREXIT);
		default:
			if (!file_open) {
				newfile();
				file_open = YES;
			}
			if (bcnt + len >= bytecnt) {
				dist = bytecnt - bcnt;
				write(ofd, bfr, dist);
				len -= dist;
				for (C = bfr + dist; len >= bytecnt; len -= bytecnt, C += bytecnt) {
E 5
					newfile();
D 5
					file_open = YES;
E 5
I 5
					write(ofd, C, (int)bytecnt);
E 5
				}
D 5
				if (bcnt + len >= bytecnt) {
					dist = bytecnt - bcnt;
					write(ofd,bfr,dist);
					len -= dist;
					for (C = bfr + dist;len >= bytecnt;len -= bytecnt,C += bytecnt) {
						newfile();
						write(ofd,C,(int)bytecnt);
					}
					if (len) {
						newfile();
						write(ofd,C,len);
					}
					else
						file_open = NO;
					bcnt = len;
E 5
I 5
				if (len) {
					newfile();
					write(ofd, C, len);
E 5
				}
D 5
				else {
					bcnt += len;
					write(ofd,bfr,len);
				}
E 5
I 5
				else
					file_open = NO;
				bcnt = len;
			}
			else {
				bcnt += len;
				write(ofd, bfr, len);
			}
E 5
E 3
		}
D 3
	if(ofil == 0)
		ofil = "x";
E 3
I 3
}
E 3

D 3
loop:
	f = 1;
	for(i=0; i<count; i++)
	do {
		c = getc(is);
		if(c == EOF) {
			if(f == 0)
				fclose(os);
			exit(0);
E 3
I 3
/*
 * split2 --
 *	split by lines
 */
static
split2()
{
	register char	*Ce,			/* start/end pointers */
			*Cs;
	register long	lcnt;			/* line counter */
	register int	len;			/* read length */

	for (lcnt = 0;;)
D 5
		switch(len = read(ifd,bfr,MAXBSIZE)) {
			case 0:
				exit(0);
			case ERR:
				perror("read");
				break;
			default:
				if (!file_open) {
					newfile();
					file_open = YES;
E 5
I 5
		switch(len = read(ifd, bfr, MAXBSIZE)) {
		case 0:
			exit(0);
		case ERR:
			perror("read");
			break;
		default:
			if (!file_open) {
				newfile();
				file_open = YES;
			}
			for (Cs = Ce = bfr; len--; Ce++)
				if (*Ce == '\n' && ++lcnt == numlines) {
					write(ofd, Cs, (int)(Ce - Cs) + 1);
					lcnt = 0;
					Cs = Ce + 1;
					if (len)
						newfile();
					else
						file_open = NO;
E 5
				}
D 5
				for (Cs = Ce = bfr;len--;Ce++)
					if (*Ce == '\n' && ++lcnt == numlines) {
						write(ofd,Cs,(int)(Ce - Cs) + 1);
						lcnt = 0;
						Cs = Ce + 1;
						if (len)
							newfile();
						else
							file_open = NO;
					}
				if (Cs < Ce)
					write(ofd,Cs,(int)(Ce - Cs));
E 5
I 5
			if (Cs < Ce)
				write(ofd, Cs, (int)(Ce - Cs));
E 5
E 3
		}
D 3
		if(f) {
			for(f=0; ofil[f]; f++)
				fname[f] = ofil[f];
			fname[f++] = fnumber/26 + 'a';
			fname[f++] = fnumber%26 + 'a';
			fname[f] = '\0';
			fnumber++;
			if((os=fopen(fname,"w")) == NULL) {
				fprintf(stderr,"Cannot create output\n");
				exit(1);
			}
			f = 0;
E 3
I 3
}

/*
 * newfile --
 *	open a new file
 */
static
newfile()
{
	static long	fnum;		/* file name counter */
	static short	defname;	/* using default name, "x" */
	static char	*fpnt;		/* output file name pointer */

	if (ofd == ERR) {
		if (fname[0]) {
			fpnt = fname + strlen(fname);
			defname = NO;
E 3
		}
D 3
		putc(c, os);
	} while(c != '\n');
	fclose(os);
	goto loop;
E 3
I 3
		else {
			fname[0] = 'x';
			fpnt = fname + 1;
			defname = YES;
		}
		ofd = fileno(stdout);
	}
	/*
	 * hack to increase max files; original code just wandered through
	 * magic characters.  Maximum files is 3 * 26 * 26 == 2028
	 */
#define MAXFILES	676
	if (fnum == MAXFILES) {
		if (!defname || fname[0] == 'z') {
D 5
			fputs("split: too many files.\n",stderr);
E 5
I 5
			fputs("split: too many files.\n", stderr);
E 5
			exit(ERREXIT);
		}
		++fname[0];
		fnum = 0;
	}
	fpnt[0] = fnum / 26 + 'a';
	fpnt[1] = fnum % 26 + 'a';
	++fnum;
D 5
	if (!freopen(fname,"w",stdout)) {
		fprintf(stderr,"split: unable to write to %s.\n",fname);
E 5
I 5
	if (!freopen(fname, "w", stdout)) {
		fprintf(stderr, "split: unable to write to %s.\n", fname);
E 5
		exit(ERR);
	}
}

/*
 * usage --
 *	print usage message and die
 */
static
usage()
{
D 5
	fputs("usage: split [-] [-#] [-b byte_count] [file [prefix]]\n",stderr);
E 5
I 5
	fputs("usage: split [-] [-#] [-b byte_count] [file [prefix]]\n", stderr);
E 5
	exit(ERREXIT);
E 3
}
E 1

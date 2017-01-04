h34419
s 00010/00005/00236
d D 5.4 88/06/29 21:51:16 bostic 10 9
c install approved copyright notice
e
s 00069/00074/00172
d D 5.3 87/12/26 22:04:40 bostic 9 8
c add Berkeley header; format a little better
e
s 00211/00084/00035
d D 5.2 86/11/18 21:21:23 bostic 8 7
c wc has a bug, is too slow; bug report 4.3BSD/ucb/33
e
s 00016/00001/00103
d D 5.1 85/05/31 09:39:12 dist 7 6
c Add copyright
e
s 00007/00101/00097
d D 4.6 83/06/01 07:55:18 mo 6 5
c removed excess features - back to v7 flag list
e
s 00001/00001/00197
d D 4.5 83/04/28 23:19:18 mckusick 5 4
c added perror
e
s 00005/00002/00193
d D 4.4 82/07/15 16:10:58 kre 4 3
c guarantee at least one space between output columns
e
s 00001/00005/00194
d D 4.3 80/11/07 12:10:15 mark 3 2
c fixed previous fix
e
s 00012/00000/00187
d D 4.2 80/11/07 12:06:25 mark 2 1
c fixed bug that core dumped when bad arguments were given
e
s 00187/00000/00000
d D 4.1 80/10/01 17:29:28 bill 1 0
c date and time created 80/10/01 17:29:28 by bill
e
u
U
t
T
I 1
D 7
static char *sccsid = "%W% (Berkeley) %G%";
E 7
I 7
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * Copyright (c) 1980, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

#ifndef lint
char copyright[] =
D 9
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 9
I 9
"%Z% Copyright (c) 1980, 1987 Regents of the University of California.\n\
E 9
 All rights reserved.\n";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

E 7
D 8
/* wc line and word count */
E 8
I 8
/* wc line, word and char count */
E 8

I 8
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/file.h>
E 8
#include <stdio.h>
D 8
long	linect, wordct, charct, pagect;
long	tlinect, twordct, tcharct, tpagect;
D 6
int	baud=300;	/* baud rate */
int	cps=30;		/* # of chars per second */
int	lpp=66;		/* # of lines per page */
E 6
char	*wd = "lwc";
E 8
D 6
int	verbose;
int	uucp;
E 6

D 8
main(argc, argv)
char **argv;
E 8
I 8
#define DEL	0177			/* del char */
D 9
#define ERR	1			/* error exit */
E 9
#define NL	012			/* newline char */
D 9
#define NO	0			/* no/false */
#define OK	0			/* okay exit */
E 9
#define SPACE	040			/* space char */
#define TAB	011			/* tab char */
D 9
#define YES	1			/* yes/true */
E 9

D 9
static long	tlinect,		/* total line count */
		twordct,		/* total word count */
		tcharct;		/* total character count */
static short	doline,			/* if want line count */
		doword,			/* if want word count */
		dochar;			/* if want character count */
E 9
I 9
static long	tlinect, twordct, tcharct;
static int	doline,	doword, dochar;
E 9

main(argc,argv)
D 9
int	argc;
char	**argv;
E 9
I 9
	int argc;
	char **argv;
E 9
E 8
{
D 8
	int i, token;
	register FILE *fp;
	register int c;
	char *p;
E 8
I 8
D 9
	extern char	*optarg;	/* getopt arguments */
	extern int	optind;
	register int	ch;		/* getopt character */
E 9
I 9
	extern int optind;
	register int ch;
E 9
E 8

D 8
	while (argc > 1 && *argv[1] == '-') {
		switch (argv[1][1]) {
D 6
		case 'l': case 'w': case 'c': case 'p': case 't':
E 6
I 6
		case 'l': case 'w': case 'c': 
E 6
			wd = argv[1]+1;
			break;
D 6
		case 's':
I 2
D 3
			if (argc == 2)
				goto usage;
E 3
E 2
			lpp = atoi(argv[1]+2);
I 2
			if (lpp <= 0)
				goto usage;
E 2
			break;
		case 'v':
			verbose++;
			wd = "lwcpt";
			break;
		case 'u':
			uucp++;
			break;
		case 'b':
I 2
D 3
			if (argc == 2)
				goto usage;
E 3
E 2
			baud = atoi(argv[1]+2);
			if (baud == 110)
				cps = 10;
			else
				cps = baud / 10;
I 2
			if (cps <= 0)
				goto usage;
E 2
			break;
E 6
I 2
		default:
		usage:
D 3
			fprintf(stderr, "Usage: wc [-lwcpt] [-v] [-u] [-s pagesize] [-b baudrate]\n");
E 3
I 3
D 6
			fprintf(stderr, "Usage: wc [-lwcpt] [-v] [-u] [-spagesize] [-bbaudrate]\n");
E 6
I 6
			fprintf(stderr, "Usage: wc [-lwc] [files]\n");
E 6
E 3
			exit(1);
E 8
I 8
	/*
	 * wc is unusual in that its flags are on by default, so,
	 * if you don't get any arguments, you have to turn them
	 * all on.
	 */
	if (argc > 1 && argv[1][0] == '-' && argv[1][1]) {
		while ((ch = getopt(argc,argv,"lwc")) != EOF)
			switch((char)ch) {
D 9
				case 'l':
					doline = YES;
					break;
				case 'w':
					doword = YES;
					break;
				case 'c':
					dochar = YES;
					break;
				case '?':
				default:
					fputs("Usage: wc [-lwc] [files]\n",stderr);
					exit(ERR);
E 9
I 9
			case 'l':
				doline = 1;
				break;
			case 'w':
				doword = 1;
				break;
			case 'c':
				dochar = 1;
				break;
			case '?':
			default:
				fputs("usage: wc [-lwc] [files]\n",stderr);
				exit(1);
E 9
			}
		argv += optind;
		argc -= optind;
	}
	else {
		++argv;
		--argc;
D 9
		doline = doword = dochar = YES;
E 9
I 9
		doline = doword = dochar = 1;
E 9
	}

	/* should print "stdin" as the file name, here */
	if (argc <= 1) {
D 9
		if (!*argv || !strcmp(*argv,"-")) {
E 9
I 9
		if (!*argv || !strcmp(*argv, "-")) {
E 9
			cnt((char *)NULL);
			putchar('\n');
E 8
E 2
		}
D 8
		argc--;
		argv++;
E 8
I 8
		else {
			cnt(*argv);
D 9
			printf(" %s\n",*argv);
E 9
I 9
			printf(" %s\n", *argv);
E 9
		}
D 9
		exit(OK);
E 9
I 9
		exit(0);
E 9
E 8
	}

D 6
	if (uucp)
		cps = cps * 9 / 10;	/* 27 cps at 300 baud */

	if (verbose) {
		for (p=wd; *p; p++)
			switch(*p) {
			case 'l':
				printf("lines\t");
				break;
			case 'w':
				printf("words\t");
				break;
			case 'c':
				printf("chars\t");
				break;
			case 'p':
				printf("pages\t");
				break;
			case 't':
				printf("time@%d\t",baud);
				break;
			}
		printf("\n");
	}

E 6
D 8
	i = 1;
	fp = stdin;
E 8
I 8
	/*
	 * cat allows "-" as stdin anywhere in the arg list,
	 * might as well here, too.  Again, should use "stdin"
	 * as the file name.
	 */
E 8
	do {
D 8
		if(argc>1 && (fp=fopen(argv[i], "r")) == NULL) {
D 5
			fprintf(stderr, "wc: can't open %s\n", argv[i]);
E 5
I 5
			perror(argv[i]);
E 5
			continue;
E 8
I 8
D 9
		if (!strcmp(*argv,"-")) {
E 9
I 9
		if (!strcmp(*argv, "-")) {
E 9
			cnt((char *)NULL);
			putchar('\n');
E 8
		}
D 8
		linect = 0;
		wordct = 0;
		charct = 0;
D 6
		pagect = 0;
E 6
		token = 0;
		for(;;) {
			c = getc(fp);
			if (c == EOF)
				break;
			charct++;
			if(' '<c&&c<0177) {
				if(!token) {
					wordct++;
					token++;
E 8
I 8
		else {
			cnt(*argv);
D 9
			printf(" %s\n",*argv);
E 9
I 9
			printf(" %s\n", *argv);
E 9
		}
	} while(*++argv);

	if (doline)
D 9
		printf(" %7ld",tlinect);
E 9
I 9
		printf(" %7ld", tlinect);
E 9
	if (doword)
D 9
		printf(" %7ld",twordct);
E 9
I 9
		printf(" %7ld", twordct);
E 9
	if (dochar)
D 9
		printf(" %7ld",tcharct);
E 9
I 9
		printf(" %7ld", tcharct);
E 9
	puts(" total");
D 9
	exit(OK);
E 9
I 9
	exit(0);
E 9
}

static
cnt(file)
D 9
char	*file;
E 9
I 9
	char *file;
E 9
{
D 9
	register u_char	*C;		/* traveling pointer */
	register short	gotsp;		/* space toggle */
	register int	len;		/* length of read */
	register long	linect,		/* line count */
			wordct,		/* word count */
			charct;		/* character count */
	struct stat	sbuf;		/* stat buffer */
	int	fd;			/* file descriptor */
	u_char	buf[MAXBSIZE];		/* read buffer */
E 9
I 9
	register u_char *C;
	register short gotsp;
	register int len;
	register long linect, wordct,charct;	
	struct stat sbuf;
	int fd;
	u_char buf[MAXBSIZE];
E 9

	linect = wordct = charct = 0;
	if (file) {
D 9
		if ((fd = open(file,O_RDONLY)) < 0) {
E 9
I 9
		if ((fd = open(file, O_RDONLY, 0)) < 0) {
E 9
			perror(file);
D 9
			exit(ERR);
E 9
I 9
			exit(1);
E 9
		}
		if (!doword) {
			/*
			 * line counting is split out because it's a lot
			 * faster to get lines than to get words, since
			 * the word count requires some logic.
			 */
			if (doline) {
D 9
				while(len = read(fd,buf,MAXBSIZE)) {
E 9
I 9
				while(len = read(fd, buf, MAXBSIZE)) {
E 9
					if (len == -1) {
						perror(file);
D 9
						exit(ERR);
E 9
I 9
						exit(1);
E 9
					}
					charct += len;
D 9
					for (C = buf;len--;++C)
E 9
I 9
					for (C = buf; len--; ++C)
E 9
						if (*C == '\n')
							++linect;
E 8
				}
D 8
				continue;
E 8
I 8
				tlinect += linect;
D 9
				printf(" %7ld",linect);
E 9
I 9
				printf(" %7ld", linect);
E 9
				if (dochar) {
					tcharct += charct;
D 9
					printf(" %7ld",sbuf.st_size);
E 9
I 9
					printf(" %7ld", sbuf.st_size);
E 9
				}
				close(fd);
				return;
E 8
			}
D 8
			if(c=='\n') {
				linect++;
E 8
I 8
			/*
			 * if all we need is the number of characters and
			 * it's a directory or a regular or linked file, just
			 * stat the puppy.  We avoid testing for it not being
			 * a special device in case someone adds a new type
			 * of inode.
			 */
			if (dochar) {
D 9
				if (fstat(fd,&sbuf)) {
E 9
I 9
				if (fstat(fd, &sbuf)) {
E 9
					perror(file);
D 9
					exit(ERR);
E 9
I 9
					exit(1);
E 9
				}
				if (sbuf.st_mode & (S_IFREG | S_IFLNK | S_IFDIR)) {
D 9
					printf(" %7ld",sbuf.st_size);
E 9
I 9
					printf(" %7ld", sbuf.st_size);
E 9
					tcharct += sbuf.st_size;
					close(fd);
					return;
				}
E 8
D 6
				if (linect % lpp == 1)
					pagect++;
E 6
			}
D 8
			else if(c!=' '&&c!='\t')
				continue;
			token = 0;
E 8
		}
D 8
		/* print lines, words, chars */
D 6
		wcp(wd, charct, wordct, linect, pagect);
E 6
I 6
		wcp(wd, charct, wordct, linect);
E 6
		if(argc>1) {
			printf(" %s\n", argv[i]);
		} else
			printf("\n");
		fclose(fp);
E 8
I 8
	}
	else
		fd = 0;
	/* do it the hard way... */
D 9
	for (gotsp = YES;len = read(fd,buf,MAXBSIZE);) {
E 9
I 9
	for (gotsp = 1; len = read(fd, buf, MAXBSIZE);) {
E 9
		if (len == -1) {
			perror(file);
D 9
			exit(ERR);
E 9
I 9
			exit(1);
E 9
		}
		charct += len;
D 9
		for (C = buf;len--;++C)
E 9
I 9
		for (C = buf; len--; ++C)
E 9
			switch(*C) {
				case NL:
					++linect;
				case TAB:
				case SPACE:
D 9
					gotsp = YES;
E 9
I 9
					gotsp = 1;
E 9
					continue;
				default:
D 9
#ifdef NOT_DEFINED
E 9
I 9
#ifdef notdef
E 9
					/*
					 * This line of code implements the
					 * original V7 wc algorithm, i.e.
					 * a non-printing character doesn't
					 * toggle the "word" count, so that
					 * "  ^D^F  " counts as 6 spaces,
					 * while "foo^D^Fbar" counts as 8
					 * characters.
					 *
					 * test order is important -- gotsp
					 * will normally be NO, so test it
					 * first
					 */
					if (gotsp && *C > SPACE && *C < DEL) {
D 9
#endif NOT_DEFINED
E 9
I 9
#endif
E 9
					/*
					 * This line implements the manual
					 * page, i.e. a word is a "maximal
					 * string of characters delimited by
					 * spaces, tabs or newlines."  Notice
					 * nothing was said about a character
					 * being printing or non-printing.
					 */
					if (gotsp) {
D 9
						gotsp = NO;
E 9
I 9
						gotsp = 0;
E 9
						++wordct;
					}
			}
	}
	if (doline) {
E 8
		tlinect += linect;
I 8
D 9
		printf(" %7ld",linect);
E 9
I 9
		printf(" %7ld", linect);
E 9
	}
	if (doword) {
E 8
		twordct += wordct;
I 8
D 9
		printf(" %7ld",wordct);
E 9
I 9
		printf(" %7ld", wordct);
E 9
	}
	if (dochar) {
E 8
		tcharct += charct;
D 6
		tpagect += pagect;
E 6
D 8
	} while(++i<argc);
	if(argc > 2) {
D 6
		wcp(wd, tcharct, twordct, tlinect, tpagect);
E 6
I 6
		wcp(wd, tcharct, twordct, tlinect);
E 6
		printf(" total\n");
E 8
I 8
D 9
		printf(" %7ld",charct);
E 9
I 9
		printf(" %7ld", charct);
E 9
E 8
	}
D 8
	exit(0);
E 8
I 8
	close(fd);
E 8
}
D 8

D 6
wcp(wd, charct, wordct, linect, pagect)
E 6
I 6
wcp(wd, charct, wordct, linect)
E 6
register char *wd;
D 6
long charct; long wordct; long linect, pagect;
E 6
I 6
long charct; long wordct; long linect;
E 6
{
	while (*wd) switch (*wd++) {
	case 'l':
		ipr(linect);
		break;

	case 'w':
		ipr(wordct);
		break;

	case 'c':
		ipr(charct);
		break;

D 6
	case 'p':
		ipr(pagect);
		break;

	case 't':
		prttime(charct/cps);
		break;
E 6
	}
}

ipr(num)
long num;
{
D 6
	if (verbose)
		printf("%ld\t", num);
	else
D 4
		printf("%7ld", num);
E 4
I 4
		printf(" %7ld", num);
E 6
I 6
	printf(" %7ld", num);
E 6
E 4
}

E 8
D 6
prttime(secs)
long secs;
{
	int hrs,mins;
	float t;
	long osecs;
	char *units;

	osecs = secs;
	hrs = secs / (60*60);
	secs = secs % (60*60);
	mins = secs / 60;
	secs = secs % 60;

	t = osecs;
	if (hrs) {
		t /= (60*60);
		units = "hr";
	} else if (mins) {
		t /= 60;
		units = "mi";
	} else {
		units = "se";
	}
D 4
	printf("%4.1f %2s\t", t, units);
E 4
I 4
	if (verbose)
		printf("%4.1f %2s\t", t, units);
	else
		printf(" %4.1f %2s", t, units);
E 4
}
E 6
E 1

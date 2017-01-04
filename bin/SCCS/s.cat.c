h56739
s 00039/00004/00224
d D 5.4 02/12/06 22:34:49 msokolov 13 12
c add -7 and -8 options to convert between KOI-7 and KOI-8
e
s 00013/00007/00215
d D 5.3 88/04/24 14:53:42 bostic 12 11
c fix for ANSI C
e
s 00002/00000/00220
d D 5.2 85/12/06 02:05:21 lepreau 11 10
c reset sticky eof on stdin so can handle multiple "-" args
e
s 00008/00002/00212
d D 5.1 85/04/30 14:50:03 dist 10 9
c Add copyright
e
s 00021/00010/00193
d D 4.9 85/02/14 19:17:33 karels 9 8
c don't loop on output errors
e
s 00065/00007/00138
d D 4.8 85/02/12 15:52:41 ralph 8 7
c speedup from lepreau@utah-cs, exit code fix from donn@utah-cs.
e
s 00000/00002/00145
d D 4.7 84/05/02 12:00:02 ralph 7 6
c use optimal buffer size for stdio.
e
s 00004/00001/00143
d D 4.6 83/08/11 19:51:49 sam 6 5
c sccs keyword fixes
e
s 00001/00001/00143
d D 4.5 83/04/26 11:24:06 mckusick 5 4
c added perror
e
s 00002/00001/00142
d D 4.4 82/02/20 11:14:05 root 4 3
c check for regular file before complaining about cat a >> a
e
s 00013/00011/00130
d D 4.3 81/09/14 17:52:02 ecc 3 2
c checked return of fstat for "input == output" protection
e
s 00080/00003/00061
d D 4.2 80/10/10 00:41:25 bill 2 1
c new options version
e
s 00064/00000/00000
d D 4.1 80/10/01 17:25:10 bill 1 0
c date and time created 80/10/01 17:25:10 by bill
e
u
U
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 10
I 6
#ifndef lint
I 12
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 12
D 10
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12
E 10

E 6
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
/*
 * Concatenate files.
 */
I 2
D 6
static	char *Sccsid = "%W% (Berkeley) %G%";
E 6
E 2

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

D 7
char	stdbuf[BUFSIZ];
E 7
I 2
D 8
int	bflg, eflg, nflg, sflg, tflg, vflg;
int	spaced, col, lno, inline;
E 8
I 8
D 9
/* #define OPTSIZE BUFSIZ	/* define this only if not 4.2 BSD */
E 9
I 9
/* #define OPTSIZE BUFSIZ	/* define this only if not 4.2 BSD or beyond */
E 9
E 8
E 2

I 8
D 13
int	bflg, eflg, nflg, sflg, tflg, uflg, vflg;
D 12
int	spaced, col, lno, inline, ibsize, obsize;
E 12
I 12
int	spaced, col, lno, inaline, ibsize, obsize;
E 13
I 13
int	bflg, eflg, nflg, sflg, tflg, uflg, vflg, koi7flg, koi8flg;
int	spaced, col, lno, inaline, ibsize, obsize, outkoi7state;
E 13
E 12

E 8
main(argc, argv)
char **argv;
{
	int fflg = 0;
	register FILE *fi;
	register c;
	int dev, ino = -1;
	struct stat statb;
I 8
	int retval = 0;
E 8

I 2
	lno = 1;
E 2
D 7
	setbuf(stdout, stdbuf);
E 7
	for( ; argc>1 && argv[1][0]=='-'; argc--,argv++) {
		switch(argv[1][1]) {
		case 0:
			break;
		case 'u':
			setbuf(stdout, (char *)NULL);
I 8
			uflg++;
E 8
			continue;
I 2
		case 'n':
			nflg++;
			continue;
		case 'b':
			bflg++;
			nflg++;
			continue;
		case 'v':
			vflg++;
			continue;
		case 's':
			sflg++;
			continue;
		case 'e':
			eflg++;
			vflg++;
			continue;
		case 't':
			tflg++;
			vflg++;
			continue;
I 13
		case '7':
			koi7flg++;
			koi8flg++;
			continue;
		case '8':
			koi8flg++;
			continue;
E 13
E 2
		}
		break;
	}
I 13
	if (vflg && koi8flg) {
		fputs("cat: -v cannot be used together with -7 or -8\n",
			stderr);
		exit(1);
	}
E 13
D 3
	fstat(fileno(stdout), &statb);
	statb.st_mode &= S_IFMT;
	if (statb.st_mode!=S_IFCHR && statb.st_mode!=S_IFBLK) {
		dev = statb.st_dev;
		ino = statb.st_ino;
E 3
I 3
	if (fstat(fileno(stdout), &statb) == 0) {
		statb.st_mode &= S_IFMT;
		if (statb.st_mode!=S_IFCHR && statb.st_mode!=S_IFBLK) {
			dev = statb.st_dev;
			ino = statb.st_ino;
		}
I 9
#ifndef	OPTSIZE
E 9
I 8
		obsize = statb.st_blksize;
I 9
#endif
E 9
E 8
E 3
	}
I 8
	else
		obsize = 0;
E 8
	if (argc < 2) {
		argc = 2;
		fflg++;
	}
	while (--argc > 0) {
		if (fflg || (*++argv)[0]=='-' && (*argv)[1]=='\0')
			fi = stdin;
		else {
			if ((fi = fopen(*argv, "r")) == NULL) {
D 5
				fprintf(stderr, "cat: can't open %s\n", *argv);
E 5
I 5
				perror(*argv);
I 8
				retval = 1;
E 8
E 5
				continue;
			}
		}
D 3
		fstat(fileno(fi), &statb);
		if (statb.st_dev==dev && statb.st_ino==ino) {
			fprintf(stderr, "cat: input %s is output\n",
			   fflg?"-": *argv);
			fclose(fi);
			continue;
E 3
I 3
		if (fstat(fileno(fi), &statb) == 0) {
D 4
			if (statb.st_dev==dev && statb.st_ino==ino) {
E 4
I 4
			if ((statb.st_mode & S_IFMT) == S_IFREG &&
			    statb.st_dev==dev && statb.st_ino==ino) {
E 4
				fprintf(stderr, "cat: input %s is output\n",
				   fflg?"-": *argv);
				fclose(fi);
I 8
				retval = 1;
E 8
				continue;
			}
I 9
#ifndef	OPTSIZE
E 9
I 8
			ibsize = statb.st_blksize;
I 9
#endif
E 9
E 8
E 3
		}
I 8
		else
			ibsize = 0;
E 8
D 2
		while ((c = getc(fi)) != EOF)
			putchar(c);
E 2
I 2
D 13
		if (nflg||sflg||vflg)
E 13
I 13
		if (nflg||sflg||vflg|koi8flg)
E 13
			copyopt(fi);
D 8
		else {
E 8
I 8
		else if (uflg) {
E 8
			while ((c = getc(fi)) != EOF)
				putchar(c);
D 8
		}
E 8
I 8
		} else
D 9
			fastcat(fileno(fi));	/* no flags specified */
E 9
I 9
			retval |= fastcat(fileno(fi));	/* no flags specified */
E 9
E 8
E 2
		if (fi!=stdin)
			fclose(fi);
I 11
		else
			clearerr(fi);		/* reset sticky eof */
E 11
I 8
		if (ferror(stdout)) {
			fprintf(stderr, "cat: output write error\n");
			retval = 1;
			break;
		}
E 8
	}
I 2
D 8
	if (ferror(stdout))
		fprintf(stderr, "cat: output write error\n");
E 2
	return(0);
E 8
I 8
	exit(retval);
E 8
I 2
}

copyopt(f)
	register FILE *f;
{
	register int c;
I 13
	register int inkoi7state = 0;
E 13

top:
	c = getc(f);
	if (c == EOF)
		return;
I 13
	if (koi8flg) {
		if (c == '\016') {
			inkoi7state = 1;
			goto top;
		}
		if (c == '\017') {
			inkoi7state = 0;
			goto top;
		}
		if (c >= 0100 && c <= 0177 && inkoi7state)
			c |= 0200;
	}
	if (koi7flg) {
		if (c >= 0100 && c <= 0177 && outkoi7state) {
			putchar('\017');
			outkoi7state = 0;
		}
		if (c >= 0300 && !outkoi7state) {
			putchar('\016');
			outkoi7state = 1;
		}
		c &= 0177;
	}
E 13
	if (c == '\n') {
D 12
		if (inline == 0) {
E 12
I 12
		if (inaline == 0) {
E 12
			if (sflg && spaced)
				goto top;
			spaced = 1;
		}
D 12
		if (nflg && bflg==0 && inline == 0)
E 12
I 12
		if (nflg && bflg==0 && inaline == 0)
E 12
			printf("%6d\t", lno++);
		if (eflg)
			putchar('$');
		putchar('\n');
D 12
		inline = 0;
E 12
I 12
		inaline = 0;
E 12
		goto top;
	}
D 12
	if (nflg && inline == 0)
E 12
I 12
	if (nflg && inaline == 0)
E 12
		printf("%6d\t", lno++);
D 12
	inline = 1;
E 12
I 12
	inaline = 1;
E 12
	if (vflg) {
		if (tflg==0 && c == '\t')
			putchar(c);
		else {
			if (c > 0177) {
				printf("M-");
				c &= 0177;
			}
			if (c < ' ')
				printf("^%c", c+'@');
			else if (c == 0177)
				printf("^?");
			else
				putchar(c);
		}
	} else
		putchar(c);
	spaced = 0;
	goto top;
I 8
}

fastcat(fd)
register int fd;
{
	register int	buffsize, n, nwritten, offset;
	register char	*buff;
D 13
	struct stat	statbuff;
E 13
	char		*malloc();

#ifndef	OPTSIZE
D 9
	if (ibsize == 0)
		buffsize = BUFSIZ;	/* handle reads from a pipe */
	else if (obsize == 0)
E 9
I 9
	if (obsize)
		buffsize = obsize;	/* common case, use output blksize */
	else if (ibsize)
E 9
		buffsize = ibsize;
	else
D 9
		buffsize = obsize;	/* common case, use output blksize */
E 9
I 9
		buffsize = BUFSIZ;
E 9
#else
	buffsize = OPTSIZE;
#endif

D 9
	if ((buff = malloc(buffsize)) == NULL)
E 9
I 9
	if ((buff = malloc(buffsize)) == NULL) {
E 9
		perror("cat: no memory");
I 9
		return (1);
	}
E 9

	/*
	 * Note that on some systems (V7), very large writes to a pipe
	 * return less than the requested size of the write.
	 * In this case, multiple writes are required.
	 */
	while ((n = read(fd, buff, buffsize)) > 0) {
		offset = 0;
		do {
			nwritten = write(fileno(stdout), &buff[offset], n);
D 9
			if (nwritten <= 0)
E 9
I 9
			if (nwritten <= 0) {
E 9
				perror("cat: write error");
I 9
				exit(2);
			}
E 9
			offset += nwritten;
		} while ((n -= nwritten) > 0);
	}
D 9
	if (n < 0)
		perror("cat: read error");
E 9

	free(buff);
I 9
	if (n < 0) {
		perror("cat: read error");
		return (1);
	}
	return (0);
E 9
E 8
E 2
}
E 1

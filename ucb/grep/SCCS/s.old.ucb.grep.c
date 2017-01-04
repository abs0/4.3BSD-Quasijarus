h59330
s 00006/00001/00464
d D 5.4 87/10/07 17:25:22 bostic 10 9
c implement -o flag; *always* print the file name
e
s 00006/00001/00459
d D 5.3 87/10/07 16:52:14 bostic 9 8
c implement -h flag
e
s 00010/00005/00450
d D 5.2 86/03/04 09:32:27 lepreau 8 7
c returns 2 when things are screwed up; avoid infinite loop too.
e
s 00013/00001/00442
d D 5.1 85/05/31 09:16:16 dist 7 6
c Add copyright
e
s 00024/00009/00419
d D 4.5 85/05/30 12:38:36 mckusick 6 4
c use more reasonable buffering
e
s 00024/00009/00419
d R 4.5 85/05/29 19:18:04 mckusick 5 4
c use more reasonable buffering
e
s 00000/00002/00428
d D 4.4 84/09/17 10:33:23 ralph 4 3
c don't call setbuf.
e
s 00003/00001/00427
d D 4.3 83/08/11 21:30:45 sam 3 2
c standardize sccs keyword lines
e
s 00001/00001/00427
d D 4.2 83/04/29 00:15:19 mckusick 2 1
c added perror
e
s 00428/00000/00000
d D 4.1 82/05/07 14:20:46 mckusick 1 0
c date and time created 82/05/07 14:20:46 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
#endif not lint
E 7
E 3

#include <stdio.h>
I 6
#include <sys/types.h>
#include <sys/stat.h>
E 6
/*
 * grep -- print lines matching (or not matching) a pattern
 */

I 6
#define BLKSIZE 8192
E 6
#define	CCHR	2
#define	CDOT	4
#define	CCL	6
#define	NCCL	8
#define	CDOL	10
#define	CEOF	11

#define	CBRC	14
#define	CLET	15
#define	STAR	01

D 6
#define	LBSIZE	BUFSIZ
E 6
#define	ESIZE	256

char	expbuf[ESIZE];
long	lnum;
D 6
char	linebuf[LBSIZE+1];
E 6
I 6
char	linebuf[BUFSIZ+1];
E 6
int	bflag;
int	nflag;
int	cflag;
int	vflag;
int	nfile;
I 9
int	hflag;
I 10
int	oflag;
E 10
E 9
int	iflag;
int	lflag;
int	wflag;
int	sflag;
int	nsucc;
int	circf;
int	blkno;
D 6
char	ibuf[BUFSIZ];
E 6
long	tln;
I 8
int	retcode = 0;
E 8

main(argc, argv)
char **argv;
{
D 4
	char obuf[BUFSIZ];
E 4

D 4
	setbuf(stdout, obuf);
E 4
	while (--argc > 0 && (++argv)[0][0]=='-') {
		char *cp = argv[0] + 1;
		while (*cp) switch (*cp++) {

		case 'v':
			vflag++;
			continue;

		case 'b':
			bflag++;
			continue;

I 10
		case 'o':
			oflag++;
			continue;

E 10
I 9
		case 'h':
			hflag++;
			continue;

E 9
		case 'i':
		case 'y':	/* -y for compatibility with btl grep */
			iflag++;
			continue;

		case 'l':
			lflag++;
		case 'c':
			cflag++;
			continue;

		case 'w':
			wflag++;
			continue;

		case 's':
			sflag++;
			continue;

		case 'n':
			nflag++;
			continue;

		case 'e':
			--argc;
			++argv;
			goto out;

		default:
D 8
			fprintf(stderr, "Unknown flag\n");
E 8
I 8
			fprintf(stderr, "grep: unknown flag\n");
E 8
			continue;
		}
	}
out:
	if (argc<=0)
		exit(2);
	compile(*argv);
	nfile = --argc;
	if (argc<=0) {
		if (lflag)
			exit(1);
		execute(0);
	}
	else while (--argc >= 0) {
		argv++;
		execute(*argv);
	}
D 8
	exit(nsucc == 0);
E 8
I 8
	exit(retcode != 0 ? retcode : nsucc == 0);
E 8
}

compile(astr)
char *astr;
{
	register c;
	register char *ep, *sp;
	char *lastep;
	int cclcnt;

	ep = expbuf;
	sp = astr;
	if (*sp == '^') {
		circf++;
		sp++;
	}
	if (wflag)
		*ep++ = CBRC;
	for (;;) {
		if (ep >= &expbuf[ESIZE])
			goto cerror;
		if ((c = *sp++) != '*')
			lastep = ep;
		switch (c) {

		case '\0':
			if (wflag)
				*ep++ = CLET;
			*ep++ = CEOF;
			return;

		case '.':
			*ep++ = CDOT;
			continue;

		case '*':
			if (lastep==0)
				goto defchar;
			*lastep |= STAR;
			continue;

		case '$':
			if (*sp != '\0')
				goto defchar;
			*ep++ = CDOL;
			continue;

		case '[':
			*ep++ = CCL;
			*ep++ = 0;
			cclcnt = 1;
			if ((c = *sp++) == '^') {
				c = *sp++;
				ep[-2] = NCCL;
			}
			do {
				*ep++ = c;
				cclcnt++;
				if (c=='\0' || ep >= &expbuf[ESIZE])
					goto cerror;
			} while ((c = *sp++) != ']');
			lastep[1] = cclcnt;
			continue;

		case '\\':
			if ((c = *sp++) == '\0')
				goto cerror;
			if (c == '<') {
				*ep++ = CBRC;
				continue;
			}
			if (c == '>') {
				*ep++ = CLET;
				continue;
			}
		defchar:
		default:
			*ep++ = CCHR;
			*ep++ = c;
		}
	}
    cerror:
D 8
	fprintf(stderr, "RE error\n");
E 8
I 8
	fprintf(stderr, "grep: RE error\n");
	exit(2);
E 8
}

same(a, b)
	register int a, b;
{

	return (a == b || iflag && (a ^ b) == ' ' && letter(a) == letter(b));
}

letter(c)
	register int c;
{

	if (c >= 'a' && c <= 'z')
		return (c);
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (0);
}

execute(file)
{
	register char *p1, *p2;
	register c;
	int f;
	char *ebp, *cbp;
I 6
	static char *buf;
	static int blksize;
	struct stat stb;
E 6

	if (file) {
		if ((f = open(file, 0)) < 0) {
D 2
			fprintf(stderr, "Can't open %s\n", file);
E 2
I 2
			perror(file);
I 8
			retcode = 2;
E 8
E 2
		}
	} else
		f = 0;
D 6
	ebp = ibuf;
	cbp = ibuf;
E 6
I 6
	if (buf == NULL) {
		if (fstat(f, &stb) > 0 && stb.st_blksize > 0)
			blksize = stb.st_blksize;
		else
			blksize = BLKSIZE;
		buf = (char *)malloc(blksize);
		if (buf == NULL) {
D 8
			fprintf(stderr, "egrep: no memory for %s\n", file);
E 8
I 8
			fprintf(stderr, "grep: no memory for %s\n", file);
			retcode = 2;
E 8
			return;
		}
	}
	ebp = buf;
	cbp = buf;
E 6
	lnum = 0;
	tln = 0;
	blkno = -1;
	for (;;) {
		lnum++;
		if((lnum&0377) == 0)
			fflush(stdout);
		p1 = linebuf;
		p2 = cbp;
		for (;;) {
			if (p2 >= ebp) {
D 6
				if ((c = read(f, ibuf, BUFSIZ)) <= 0) {
E 6
I 6
				if ((c = read(f, buf, blksize)) <= 0) {
E 6
					close(f);
					if (cflag) {
						if (lflag) {
							if (tln)
							printf("%s\n", file);
						} else {
							if (nfile > 1)
								printf("%s:", file);
							printf("%ld\n", tln);
						}
					}
					return;
				}
				blkno++;
D 6
				p2 = ibuf;
				ebp = ibuf+c;
E 6
I 6
				p2 = buf;
				ebp = buf+c;
E 6
			}
			if ((c = *p2++) == '\n')
				break;
			if(c)
D 6
			if (p1 < &linebuf[LBSIZE-1])
E 6
I 6
			if (p1 < &linebuf[BUFSIZ-1])
E 6
				*p1++ = c;
		}
		*p1++ = 0;
		cbp = p2;
		p1 = linebuf;
		p2 = expbuf;
		if (circf) {
			if (advance(p1, p2))
				goto found;
			goto nfound;
		}
		/* fast check for first character */
		if (*p2==CCHR) {
			c = p2[1];
			do {
				if (*p1!=c && (!iflag || (c ^ *p1) != ' '
					|| letter(c) != letter(*p1)))
					continue;
				if (advance(p1, p2))
					goto found;
			} while (*p1++);
			goto nfound;
		}
		/* regular algorithm */
		do {
			if (advance(p1, p2))
				goto found;
		} while (*p1++);
	nfound:
		if (vflag)
			succeed(file);
		continue;
	found:
		if (vflag==0)
			succeed(file);
	}
}

advance(alp, aep)
	char *alp, *aep;
{
	register char *lp, *ep, *curlp;
	char *nextep;

	lp = alp;
	ep = aep;
	for (;;) switch (*ep++) {

	case CCHR:
		if (!same(*ep, *lp))
			return (0);
		ep++, lp++;
		continue;

	case CDOT:
		if (*lp++)
			continue;
		return(0);

	case CDOL:
		if (*lp==0)
			continue;
		return(0);

	case CEOF:
		return(1);

	case CCL:
		if (cclass(ep, *lp++, 1)) {
			ep += *ep;
			continue;
		}
		return(0);

	case NCCL:
		if (cclass(ep, *lp++, 0)) {
			ep += *ep;
			continue;
		}
		return(0);

	case CDOT|STAR:
		curlp = lp;
		while (*lp++);
		goto star;

	case CCHR|STAR:
		curlp = lp;
		while (same(*lp, *ep))
			lp++;
		lp++;
		ep++;
		goto star;

	case CCL|STAR:
	case NCCL|STAR:
		curlp = lp;
		while (cclass(ep, *lp++, ep[-1]==(CCL|STAR)));
		ep += *ep;
		goto star;

	star:
		do {
			lp--;
			if (advance(lp, ep))
				return(1);
		} while (lp > curlp);
		return(0);

	case CBRC:
		if (lp == expbuf)
			continue;
#define	uletter(c)	(letter(c) || c == '_')
		if ( ( uletter(*lp) || digit ( * lp ) )  && !uletter(lp[-1]) && !digit(lp[-1]))
			continue;
		return (0);

	case CLET:
		if (!uletter(*lp) && !digit(*lp))
			continue;
		return (0);

	default:
D 8
		fprintf(stderr, "RE botch\n");
E 8
I 8
		fprintf(stderr, "grep: RE botch\n");
		exit(2);
E 8
	}
}

cclass(aset, ac, af)
	char *aset;
{
	register char *set, c;
	register n;

	set = aset;
	if ((c = ac) == 0)
		return(0);
	n = *set++;
	while (--n)
		if (n > 2 && set[1] == '-') {
			if (c >= (set[0] & 0177) && c <= (set[2] & 0177))
				return (af);
			set += 3;
			n -= 2;
		} else
			if ((*set++ & 0177) == c)
				return(af);
	return(!af);
}

succeed(f)
{
	nsucc = 1;
	if (sflag)
		return;
	if (cflag) {
		tln++;
		return;
	}
D 9
	if (nfile > 1)
E 9
I 9
D 10
	if (!hflag && nfile > 1)
E 10
I 10
	if (oflag || !hflag && nfile > 1)
E 10
E 9
		printf("%s:", f);
	if (bflag)
		printf("%d:", blkno);
	if (nflag)
		printf("%ld:", lnum);
	printf("%s\n", linebuf);
}

digit(c)
	char c;
{
	return (c>='0' && c<='9');
}
E 1

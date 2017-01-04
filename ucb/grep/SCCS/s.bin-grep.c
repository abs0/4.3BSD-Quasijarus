h21193
s 00002/00002/00527
d D 4.10 2012/02/27 05:46:38 msokolov 12 11
c fix -b
e
s 00002/00002/00527
d D 4.9 2012/02/20 20:54:46 msokolov 11 10
x 10
c debostication + fix for an ancient buglet
e
s 00024/00027/00502
d D 4.8 88/01/21 12:42:13 bostic 10 7
c allow "-wv" as flags; since there's only one "old" grep now, and 
c ucb/grep used to allow this we have to make it work.
e
s 00048/00007/00522
d R 4.8 87/10/07 18:19:03 bostic 9 7
c make -f work
e
s 00049/00007/00522
d R 4.8 87/10/07 18:18:08 bostic 8 7
c make -f flag work
e
s 00006/00001/00523
d D 4.7 87/10/07 17:25:16 bostic 7 6
c implement -o flag; *always* print the file name
e
s 00000/00002/00524
d D 4.6 84/05/14 14:33:44 ralph 6 5
c don't call setbuf. Use optimal size.
e
s 00003/00001/00523
d D 4.5 83/08/11 19:52:25 sam 5 4
c sccs keyword fixes
e
s 00039/00002/00485
d D 4.4 83/06/30 14:32:34 sam 4 3
c merge of ucb grep from wnj
e
s 00001/00001/00486
d D 4.3 83/04/29 01:20:28 mckusick 3 2
c added perror
e
s 00006/00003/00481
d D 4.2 83/03/17 13:58:37 edward 2 1
c No longer exits after a file open error.  Code borrowed from fgrep.
e
s 00484/00000/00000
d D 4.1 82/05/07 14:21:37 mckusick 1 0
c date and time created 82/05/07 14:21:37 by mckusick
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %E%";
E 11
#endif
E 5

/*
 * grep -- print lines matching (or not matching) a pattern
 *
 *	status returns:
 *		0 - ok, and some matches
 *		1 - ok, but no matches
 *		2 - some error
 */

#include <stdio.h>
#include <ctype.h>
I 12
#include <sys/param.h>
E 12

#define	CBRA	1
#define	CCHR	2
#define	CDOT	4
#define	CCL	6
#define	NCCL	8
#define	CDOL	10
#define	CEOF	11
#define	CKET	12
I 4
#define	CBRC	14
#define	CLET	15
E 4
#define	CBACK	18

#define	STAR	01

#define	LBSIZE	BUFSIZ
#define	ESIZE	256
#define	NBRA	9

char	expbuf[ESIZE];
long	lnum;
char	linebuf[LBSIZE+1];
char	ybuf[ESIZE];
int	bflag;
int	lflag;
int	nflag;
int	cflag;
int	vflag;
int	nfile;
int	hflag	= 1;
I 7
int	oflag;
E 7
int	sflag;
int	yflag;
I 4
int	wflag;
E 4
I 2
int	retcode = 0;
E 2
int	circf;
D 12
int	blkno;
E 12
long	tln;
int	nsucc;
char	*braslist[NBRA];
char	*braelist[NBRA];
char	bittab[] = {
	1,
	2,
	4,
	8,
	16,
	32,
	64,
	128
};

main(argc, argv)
D 10
char **argv;
E 10
I 10
	int argc;
	char **argv;
E 10
{
D 6
	extern char _sobuf[];
	setbuf(stdout, _sobuf);
E 6
D 10
	while (--argc > 0 && (++argv)[0][0]=='-')
		switch (argv[0][1]) {
E 10
I 10
	extern char *optarg;
	extern int optind;
	int ch;
E 10

I 10
	while ((ch = getopt(argc, argv, "iywohsvblcne")) != EOF)
		switch((char)ch) {
E 10
I 4
		case 'i':
E 4
		case 'y':
			yflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
I 4
		case 'w':
			wflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
I 7
		case 'o':
			oflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
E 7
E 4
		case 'h':
			hflag = 0;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 's':
			sflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'v':
			vflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'b':
			bflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'l':
			lflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'c':
			cflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'n':
			nflag++;
D 10
			continue;

E 10
I 10
			break;
E 10
		case 'e':
D 10
			--argc;
			++argv;
E 10
I 10
			argv += optind;
			argc -= optind;
			*argv = optarg;
E 10
			goto out;
D 10

E 10
I 10
		case '?':
E 10
		default:
			errexit("grep: unknown flag\n", (char *)NULL);
D 10
			continue;
E 10
		}
I 10
	argv += optind;
	argc -= optind;

E 10
out:
	if (argc<=0)
		exit(2);
	if (yflag) {
		register char *p, *s;
		for (s = ybuf, p = *argv; *p; ) {
			if (*p == '\\') {
				*s++ = *p++;
				if (*p)
					*s++ = *p++;
			} else if (*p == '[') {
				while (*p != '\0' && *p != ']')
					*s++ = *p++;
			} else if (islower(*p)) {
				*s++ = '[';
				*s++ = toupper(*p);
				*s++ = *p++;
				*s++ = ']';
			} else
				*s++ = *p++;
			if (s >= ybuf+ESIZE-5)
				errexit("grep: argument too long\n", (char *)NULL);
		}
		*s = '\0';
		*argv = ybuf;
	}
	compile(*argv);
	nfile = --argc;
	if (argc<=0) {
		if (lflag)
			exit(1);
		execute((char *)NULL);
	} else while (--argc >= 0) {
		argv++;
		execute(*argv);
	}
D 2
	exit(nsucc == 0);
E 2
I 2
	exit(retcode != 0 ? retcode : nsucc == 0);
E 2
}

compile(astr)
char *astr;
{
	register c;
	register char *ep, *sp;
	char *cstart;
	char *lastep;
	int cclcnt;
	char bracket[NBRA], *bracketp;
	int closed;
	char numbra;
	char neg;

	ep = expbuf;
	sp = astr;
	lastep = 0;
	bracketp = bracket;
	closed = numbra = 0;
	if (*sp == '^') {
		circf++;
		sp++;
	}
I 4
	if (wflag)
		*ep++ = CBRC;
E 4
	for (;;) {
		if (ep >= &expbuf[ESIZE])
			goto cerror;
		if ((c = *sp++) != '*')
			lastep = ep;
		switch (c) {

		case '\0':
I 4
			if (wflag)
				*ep++ = CLET;
E 4
			*ep++ = CEOF;
			return;

		case '.':
			*ep++ = CDOT;
			continue;

		case '*':
D 4
			if (lastep==0 || *lastep==CBRA || *lastep==CKET)
E 4
I 4
			if (lastep==0 || *lastep==CBRA || *lastep==CKET ||
			    *lastep == CBRC || *lastep == CLET)
E 4
				goto defchar;
			*lastep |= STAR;
			continue;

		case '$':
			if (*sp != '\0')
				goto defchar;
			*ep++ = CDOL;
			continue;

		case '[':
			if(&ep[17] >= &expbuf[ESIZE])
				goto cerror;
			*ep++ = CCL;
			neg = 0;
			if((c = *sp++) == '^') {
				neg = 1;
				c = *sp++;
			}
			cstart = sp;
			do {
				if (c=='\0')
					goto cerror;
				if (c=='-' && sp>cstart && *sp!=']') {
					for (c = sp[-2]; c<*sp; c++)
						ep[c>>3] |= bittab[c&07];
					sp++;
				}
				ep[c>>3] |= bittab[c&07];
			} while((c = *sp++) != ']');
			if(neg) {
				for(cclcnt = 0; cclcnt < 16; cclcnt++)
					ep[cclcnt] ^= -1;
				ep[0] &= 0376;
			}

			ep += 16;

			continue;

		case '\\':
D 4
			if((c = *sp++) == '(') {
E 4
I 4
			if((c = *sp++) == 0)
				goto cerror;
			if(c == '<') {
				*ep++ = CBRC;
				continue;
			}
			if(c == '>') {
				*ep++ = CLET;
				continue;
			}
			if(c == '(') {
E 4
				if(numbra >= NBRA) {
					goto cerror;
				}
				*bracketp++ = numbra;
				*ep++ = CBRA;
				*ep++ = numbra++;
				continue;
			}
			if(c == ')') {
				if(bracketp <= bracket) {
					goto cerror;
				}
				*ep++ = CKET;
				*ep++ = *--bracketp;
				closed++;
				continue;
			}

			if(c >= '1' && c <= '9') {
				if((c -= '1') >= closed)
					goto cerror;
				*ep++ = CBACK;
				*ep++ = c;
				continue;
			}

		defchar:
		default:
			*ep++ = CCHR;
			*ep++ = c;
		}
	}
    cerror:
	errexit("grep: RE error\n", (char *)NULL);
}

execute(file)
char *file;
{
	register char *p1, *p2;
	register c;

	if (file) {
D 2
		if (freopen(file, "r", stdin) == NULL)
			errexit("grep: can't open %s\n", file);
E 2
I 2
		if (freopen(file, "r", stdin) == NULL) {
D 3
			fprintf(stderr, "grep: can't open %s\n", file);
E 3
I 3
			perror(file);
E 3
			retcode = 2;
		}
E 2
	}
	lnum = 0;
	tln = 0;
	for (;;) {
		lnum++;
		p1 = linebuf;
		while ((c = getchar()) != '\n') {
			if (c == EOF) {
				if (cflag) {
					if (nfile>1)
						printf("%s:", file);
					printf("%D\n", tln);
					fflush(stdout);
				}
				return;
			}
			*p1++ = c;
			if (p1 >= &linebuf[LBSIZE-1])
				break;
		}
		*p1++ = '\0';
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
				if (*p1!=c)
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

advance(lp, ep)
register char *lp, *ep;
{
	register char *curlp;
	char c;
	char *bbeg;
	int ct;

	for (;;) switch (*ep++) {

	case CCHR:
		if (*ep++ == *lp++)
			continue;
		return(0);

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
		c = *lp++ & 0177;
		if(ep[c>>3] & bittab[c & 07]) {
			ep += 16;
			continue;
		}
		return(0);
	case CBRA:
		braslist[*ep++] = lp;
		continue;

	case CKET:
		braelist[*ep++] = lp;
		continue;

	case CBACK:
		bbeg = braslist[*ep];
		if (braelist[*ep]==0)
			return(0);
		ct = braelist[*ep++] - bbeg;
		if(ecmp(bbeg, lp, ct)) {
			lp += ct;
			continue;
		}
		return(0);

	case CBACK|STAR:
		bbeg = braslist[*ep];
		if (braelist[*ep]==0)
			return(0);
		ct = braelist[*ep++] - bbeg;
		curlp = lp;
		while(ecmp(bbeg, lp, ct))
			lp += ct;
		while(lp >= curlp) {
			if(advance(lp, ep))	return(1);
			lp -= ct;
		}
		return(0);


	case CDOT|STAR:
		curlp = lp;
		while (*lp++);
		goto star;

	case CCHR|STAR:
		curlp = lp;
		while (*lp++ == *ep);
		ep++;
		goto star;

	case CCL|STAR:
		curlp = lp;
		do {
			c = *lp++ & 0177;
		} while(ep[c>>3] & bittab[c & 07]);
		ep += 16;
		goto star;

	star:
		if(--lp == curlp) {
			continue;
		}

		if(*ep == CCHR) {
			c = ep[1];
			do {
				if(*lp != c)
					continue;
				if(advance(lp, ep))
					return(1);
			} while(lp-- > curlp);
			return(0);
		}

		do {
			if (advance(lp, ep))
				return(1);
		} while (lp-- > curlp);
		return(0);
I 4

	case CBRC:
D 11
		if (lp == expbuf)
E 11
I 11
		if (lp == linebuf)
E 11
			continue;
#define	uletter(c)	(isalpha(c) || (c) == '_')
		if (uletter(*lp) || isdigit(*lp))
			if (!uletter(lp[-1]) && !isdigit(lp[-1]))
				continue;
		return (0);

	case CLET:
		if (!uletter(*lp) && !isdigit(*lp))
			continue;
		return (0);
E 4

	default:
		errexit("grep RE botch\n", (char *)NULL);
	}
}

succeed(f)
char *f;
{
	nsucc = 1;
	if (sflag)
		return;
	if (cflag) {
		tln++;
		return;
	}
	if (lflag) {
		printf("%s\n", f);
		fflush(stdout);
		fseek(stdin, 0l, 2);
		return;
	}
D 7
	if (nfile > 1 && hflag)
E 7
I 7
	if (nfile > 1 && hflag || oflag)
E 7
		printf("%s:", f);
	if (bflag)
D 12
		printf("%u:", blkno);
E 12
I 12
		printf("%ld:", (ftell(stdin) - 1) / DEV_BSIZE);
E 12
	if (nflag)
		printf("%ld:", lnum);
	printf("%s\n", linebuf);
	fflush(stdout);
}

ecmp(a, b, count)
char	*a, *b;
{
	register cc = count;
	while(cc--)
		if(*a++ != *b++)	return(0);
	return(1);
}

errexit(s, f)
char *s, *f;
{
	fprintf(stderr, s, f);
	exit(2);
}
E 1

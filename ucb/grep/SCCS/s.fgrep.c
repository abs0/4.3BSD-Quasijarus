h32978
s 00010/00009/00402
d D 4.10 2012/03/03 20:55:48 msokolov 10 9
c -h/-o logic revamped for sanity
e
s 00019/00001/00392
d D 4.9 2012/03/03 18:17:27 msokolov 9 8
c directory recursion added to [ef]grep
e
s 00014/00014/00379
d D 4.8 2012/02/26 06:57:25 msokolov 8 7
c convert to u_char like egrep
e
s 00003/00003/00390
d D 4.7 2012/02/26 03:33:47 msokolov 7 6
c brown paper bag
e
s 00007/00004/00386
d D 4.6 2012/02/21 08:05:44 msokolov 6 5
c found a way to make -i support even less burdensome
e
s 00007/00004/00383
d D 4.5 2012/02/20 21:49:35 msokolov 5 4
c more efficient case folding
e
s 00006/00001/00381
d D 4.4 87/10/07 17:25:20 bostic 4 3
c implement -o flag; *always* print the file name
e
s 00028/00011/00354
d D 4.3 85/05/30 13:44:36 mckusick 3 2
c use more reasonable buffering
e
s 00002/00002/00363
d D 4.2 82/10/20 16:04:53 mckusick 2 1
c use <> for include files
e
s 00365/00000/00000
d D 4.1 80/10/01 17:26:32 bill 1 0
c date and time created 80/10/01 17:26:32 by bill
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
static char *sccsid = "%W% (Berkeley) %E%";
E 7
/*
 * fgrep -- print all lines containing any of a set of keywords
 *
 *	status returns:
 *		0 - ok, and some matches
 *		1 - ok, but no matches
 *		2 - some error
 */

D 2
#include "stdio.h"
# include "ctype.h"
E 2
I 2
#include <stdio.h>
#include <ctype.h>
I 3
#include <sys/param.h>
#include <sys/stat.h>
E 3
E 2

I 8
extern char *malloc();

E 8
I 3
#define BLKSIZE 8192
E 3
#define	MAXSIZ 6000
#define QSIZE 400
struct words {
D 8
	char 	inp;
E 8
I 8
	u_char 	inp;
E 8
	char	out;
	struct	words *nst;
	struct	words *link;
	struct	words *fail;
} w[MAXSIZ], *smax, *q;

long	lnum;
int	bflag, cflag, fflag, lflag, nflag, vflag, xflag, yflag;
D 10
int	hflag	= 1;
I 4
int	oflag;
E 10
E 4
int	sflag;
I 10
int	print_filenames;
E 10
I 9
int	recurse_flag;
int	recurse_symlinks;
E 9
int	retcode = 0;
D 10
int	nfile;
E 10
long	blkno;
int	nsucc;
long	tln;
FILE	*wordf;
D 8
char	*argptr;
E 8
I 8
u_char	*argptr;
E 8

main(argc, argv)
char **argv;
{
	while (--argc > 0 && (++argv)[0][0]=='-')
		switch (argv[0][1]) {

		case 's':
			sflag++;
			continue;

		case 'h':
D 10
			hflag = 0;
E 10
I 10
			print_filenames = -1;
E 10
			continue;

I 4
D 10
		case 'o':
			oflag++;
E 10
I 10
		case 'o':	/* Berkeley */
		case 'H':	/* compat with "modern" systems */
			print_filenames = 1;
E 10
			continue;

E 4
		case 'b':
			bflag++;
			continue;

		case 'c':
			cflag++;
			continue;

		case 'e':
			argc--;
			argv++;
			goto out;

		case 'f':
			fflag++;
			continue;

		case 'l':
			lflag++;
			continue;

		case 'n':
			nflag++;
			continue;

		case 'v':
			vflag++;
			continue;

		case 'x':
			xflag++;
			continue;

		case 'i':		/* Berkeley */
		case 'y':		/* Btl */
			yflag++;
			continue;
I 9

		/*
		 * the semantics of -r vs -R have been chosen
		 * to match Gunnar Ritter's "Heirloom" version
		 */

		case 'r':
			recurse_symlinks++;
			/* FALL THRU */
		case 'R':
			recurse_flag++;
			continue;

E 9
		default:
			fprintf(stderr, "fgrep: unknown flag\n");
			continue;
		}
out:
	if (argc<=0)
		exit(2);
	if (fflag) {
		wordf = fopen(*argv, "r");
		if (wordf==NULL) {
			fprintf(stderr, "fgrep: can't open %s\n", *argv);
			exit(2);
		}
	}
D 8
	else argptr = *argv;
E 8
I 8
	else argptr = (u_char *) *argv;
E 8
	argc--;
	argv++;

	cgotofn();
	cfail();
D 10
	nfile = argc;
E 10
I 10
	if (argc > 1 || recurse_flag)
		print_filenames++;
E 10
	if (argc<=0) {
		if (lflag) exit(1);
I 10
		print_filenames = 0;
E 10
		execute((char *)NULL);
	}
	else while (--argc >= 0) {
D 9
		execute(*argv);
E 9
I 9
		if (recurse_flag)
			recurse(*argv, 1);
		else
			execute(*argv);
E 9
		argv++;
	}
	exit(retcode != 0 ? retcode : nsucc == 0);
}

D 5
# define ccomp(a,b) (yflag ? lca(a)==lca(b) : a==b)
E 5
I 5
D 6
# define ccomp(pat,data) (yflag ? pat==lca(data) : pat==data)
E 6
E 5
D 8
# define lca(x) (isupper(x) ? tolower(x) : x)
E 8
execute(file)
char *file;
{
	register struct words *c;
	register ccount;
D 6
	register char ch;
E 6
I 6
	register ch;
E 6
D 8
	register char *p;
D 3
	char buf[2*BUFSIZ];
E 3
I 3
	static char *buf;
E 8
I 8
	register u_char *p;
	static u_char *buf;
E 8
	static int blksize;
	struct stat stb;
E 3
	int f;
	int failed;
D 8
	char *nlp;
E 8
I 8
	u_char *nlp;
E 8
	if (file) {
		if ((f = open(file, 0)) < 0) {
			fprintf(stderr, "fgrep: can't open %s\n", file);
			retcode = 2;
			return;
		}
	}
	else f = 0;
I 3
	if (buf == NULL) {
		if (fstat(f, &stb) > 0 && stb.st_blksize > 0)
			blksize = stb.st_blksize;
		else
			blksize = BLKSIZE;
D 8
		buf = (char *)malloc(2*blksize);
E 8
I 8
		buf = (u_char *)malloc(2*blksize);
E 8
		if (buf == NULL) {
			fprintf(stderr, "egrep: no memory for %s\n", file);
			retcode = 2;
			return;
		}
	}
E 3
	ccount = 0;
	failed = 0;
	lnum = 1;
	tln = 0;
	blkno = 0;
	p = buf;
	nlp = p;
	c = w;
	for (;;) {
		if (--ccount <= 0) {
D 3
			if (p == &buf[2*BUFSIZ]) p = buf;
			if (p > &buf[BUFSIZ]) {
				if ((ccount = read(f, p, &buf[2*BUFSIZ] - p)) <= 0) break;
E 3
I 3
			if (p == &buf[2*blksize]) p = buf;
			if (p > &buf[blksize]) {
				if ((ccount = read(f, p, &buf[2*blksize] - p)) <= 0) break;
E 3
			}
D 3
			else if ((ccount = read(f, p, BUFSIZ)) <= 0) break;
E 3
I 3
			else if ((ccount = read(f, p, blksize)) <= 0) break;
E 3
			blkno += ccount;
		}
I 6
D 8
		if (yflag)
			ch = lca(*p);
		else
			ch = *p;
E 8
I 8
		ch = *p;
		if (yflag && isupper(ch))
			ch = tolower(ch);
E 8
E 6
		nstate:
D 6
			if (ccomp(c->inp, *p)) {
E 6
I 6
D 7
			if (c->inp, ch) {
E 7
I 7
			if (c->inp == ch) {
E 7
E 6
				c = c->nst;
			}
			else if (c->link != 0) {
				c = c->link;
				goto nstate;
			}
			else {
				c = c->fail;
				failed = 1;
				if (c==0) {
					c = w;
					istate:
D 6
					if (ccomp(c->inp ,  *p)) {
E 6
I 6
D 7
					if (c->inp, ch) {
E 7
I 7
					if (c->inp == ch) {
E 7
E 6
						c = c->nst;
					}
					else if (c->link != 0) {
						c = c->link;
						goto istate;
					}
				}
				else goto nstate;
			}
		if (c->out) {
			while (*p++ != '\n') {
				if (--ccount <= 0) {
D 3
					if (p == &buf[2*BUFSIZ]) p = buf;
					if (p > &buf[BUFSIZ]) {
						if ((ccount = read(f, p, &buf[2&BUFSIZ] - p)) <= 0) break;
E 3
I 3
					if (p == &buf[2*blksize]) p = buf;
					if (p > &buf[blksize]) {
						if ((ccount = read(f, p, &buf[2*blksize] - p)) <= 0) break;
E 3
					}
D 3
					else if ((ccount = read(f, p, BUFSIZ)) <= 0) break;
E 3
I 3
					else if ((ccount = read(f, p, blksize)) <= 0) break;
E 3
					blkno += ccount;
				}
			}
			if ( (vflag && (failed == 0 || xflag == 0)) || (vflag == 0 && xflag && failed) )
				goto nomatch;
	succeed:	nsucc = 1;
			if (cflag) tln++;
			else if (sflag)
				;	/* ugh */
			else if (lflag) {
				printf("%s\n", file);
				close(f);
				return;
			}
			else {
D 4
				if (nfile > 1 && hflag) printf("%s:", file);
E 4
I 4
D 10
				if (nfile > 1 && hflag || oflag) printf("%s:", file);
E 10
I 10
				if (print_filenames > 0) printf("%s:", file);
E 10
E 4
D 3
				if (bflag) printf("%ld:", (blkno-ccount-1)/BUFSIZ);
E 3
I 3
				if (bflag) printf("%ld:", (blkno-ccount-1)/DEV_BSIZE);
E 3
				if (nflag) printf("%ld:", lnum);
				if (p <= nlp) {
D 3
					while (nlp < &buf[2*BUFSIZ]) putchar(*nlp++);
E 3
I 3
					while (nlp < &buf[2*blksize]) putchar(*nlp++);
E 3
					nlp = buf;
				}
				while (nlp < p) putchar(*nlp++);
			}
	nomatch:	lnum++;
			nlp = p;
			c = w;
			failed = 0;
			continue;
		}
		if (*p++ == '\n')
			if (vflag) goto succeed;
			else {
				lnum++;
				nlp = p;
				c = w;
				failed = 0;
			}
	}
	close(f);
	if (cflag) {
D 10
		if (nfile > 1)
E 10
I 10
		if (print_filenames > 0)
E 10
			printf("%s:", file);
		printf("%ld\n", tln);
	}
}

getargc()
{
	register c;
	if (wordf)
D 5
		return(getc(wordf));
	if ((c = *argptr++) == '\0')
E 5
I 5
		c = getc(wordf);
	else if ((c = *argptr++) == '\0')
E 5
		return(EOF);
D 5
	return(c);
E 5
I 5
D 8
	if (yflag)
		return(lca(c));
E 8
I 8
	if (yflag && isupper(c))
		return(tolower(c));
E 8
	else
		return(c);
E 5
}

cgotofn() {
	register c;
	register struct words *s;

	s = smax = w;
nword:	for(;;) {
		c = getargc();
		if (c==EOF)
			return;
		if (c == '\n') {
			if (xflag) {
				for(;;) {
					if (s->inp == c) {
						s = s->nst;
						break;
					}
					if (s->inp == 0) goto nenter;
					if (s->link == 0) {
						if (smax >= &w[MAXSIZ -1]) overflo();
						s->link = ++smax;
						s = smax;
						goto nenter;
					}
					s = s->link;
				}
			}
			s->out = 1;
			s = w;
		} else {
		loop:	if (s->inp == c) {
				s = s->nst;
				continue;
			}
			if (s->inp == 0) goto enter;
			if (s->link == 0) {
				if (smax >= &w[MAXSIZ - 1]) overflo();
				s->link = ++smax;
				s = smax;
				goto enter;
			}
			s = s->link;
			goto loop;
		}
	}

	enter:
	do {
		s->inp = c;
		if (smax >= &w[MAXSIZ - 1]) overflo();
		s->nst = ++smax;
		s = smax;
	} while ((c = getargc()) != '\n' && c!=EOF);
	if (xflag) {
	nenter:	s->inp = '\n';
		if (smax >= &w[MAXSIZ -1]) overflo();
		s->nst = ++smax;
	}
	smax->out = 1;
	s = w;
	if (c != EOF)
		goto nword;
}

overflo() {
	fprintf(stderr, "wordlist too large\n");
	exit(2);
}
cfail() {
	struct words *queue[QSIZE];
	struct words **front, **rear;
	struct words *state;
	int bstart;
	register char c;
	register struct words *s;
	s = w;
	front = rear = queue;
init:	if ((s->inp) != 0) {
		*rear++ = s->nst;
		if (rear >= &queue[QSIZE - 1]) overflo();
	}
	if ((s = s->link) != 0) {
		goto init;
	}

	while (rear!=front) {
		s = *front;
		if (front == &queue[QSIZE-1])
			front = queue;
		else front++;
	cloop:	if ((c = s->inp) != 0) {
			bstart = 0;
			*rear = (q = s->nst);
			if (front < rear)
				if (rear >= &queue[QSIZE-1])
					if (front == queue) overflo();
					else rear = queue;
				else rear++;
			else
				if (++rear == front) overflo();
			state = s->fail;
		floop:	if (state == 0) {
				state = w;
				bstart = 1;
			}
			if (state->inp == c) {
			qloop:	q->fail = state->nst;
				if ((state->nst)->out == 1) q->out = 1;
				if ((q = q->link) != 0) goto qloop;
			}
			else if ((state = state->link) != 0)
				goto floop;
			else if(bstart == 0){
				state = 0;
				goto floop;
			}
		}
		if ((s = s->link) != 0)
			goto cloop;
	}
}
E 1

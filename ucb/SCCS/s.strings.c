h07726
s 00001/00001/00153
d D 5.3 86/12/03 13:04:50 bostic 5 4
c changed to print decimal, not octal offsets
e
s 00115/00098/00039
d D 5.2 86/11/24 17:32:26 bostic 4 3
c tab as a printing character; bug report 4.3BSD/ucb/9
c heavily rewhacked
e
s 00014/00002/00123
d D 5.1 85/05/31 09:34:00 dist 3 2
c Add copyright
e
s 00007/00003/00118
d D 4.2 84/10/18 18:41:45 sam 2 1
c fix reported bug where seek is L_INCR instead of L_SET; also make 
c all seeks use symbolic names for whence
e
s 00121/00000/00000
d D 4.1 80/10/01 17:28:36 bill 1 0
c date and time created 80/10/01 17:28:36 by bill
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 2
#ifndef lint
E 2
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif
E 3
I 3
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

E 2
D 4
#include <stdio.h>
E 4
I 4
#include <sys/types.h>
#include <sys/file.h>
E 4
#include <a.out.h>
I 4
#include <stdio.h>
E 4
#include <ctype.h>
I 2
D 4
#include <sys/file.h>
E 4
E 2

D 4
long	ftell();
E 4
I 4
#define DEF_LEN		4		/* default minimum string length */
#define EOS		(char)NULL	/* end of string */
#define ERR		-1		/* general error */
#define ERREXIT		1		/* error exit */
#define NO		0		/* false/no */
#define OK		0		/* ok exit */
#define YES		1		/* true/yes */
E 4

D 4
/*
 * strings
 */
E 4
I 4
#define ISSTR(ch)	(isascii(ch) && (isprint(ch) || ch == '\t'))
E 4

D 4
struct	exec header;
E 4
I 4
typedef struct exec	EXEC;		/* struct exec cast */
E 4

D 4
char	*infile = "Standard input";
int	oflg;
int	asdata;
long	offset;
int	minlength = 4;
E 4
I 4
static long	foff;			/* offset in the file */
static int	hcnt,			/* head count */
		head_len,		/* length of header */
		read_len;		/* length to read */
static u_char	hbfr[sizeof(EXEC)];	/* buffer for struct exec */
E 4

D 4
main(argc, argv)
	int argc;
	char *argv[];
E 4
I 4
main(argc,argv)
int	argc;
char	**argv;
E 4
{
I 4
	register int	ch,		/* character */
			cnt;		/* general counter */
	register u_char	*C;		/* bfr pointer */
	EXEC	*head;			/* exec header pointer */
	int	minlen = DEF_LEN;	/* minimum string length */
	short	asdata = NO,		/* look in everything */
		oflg;			/* print octal location */
	u_char	*bfr;			/* collection buffer */
	char	*file,			/* file name for error */
		*malloc();
E 4

D 4
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		register int i;
		if (argv[0][1] == 0)
			asdata++;
		else for (i = 1; argv[0][i] != 0; i++) switch (argv[0][i]) {

		case 'o':
			oflg++;
			break;

		case 'a':
			asdata++;
			break;

		default:
			if (!isdigit(argv[0][i])) {
				fprintf(stderr, "Usage: strings [ -a ] [ -o ] [ -# ] [ file ... ]\n");
				exit(1);
E 4
I 4
	/*
	 * for backward compatibility, allow '-' to specify 'a' flag; no
	 * longer documented in the man page or usage string.
	 */
	for (++argv;*argv && **argv ==  '-';++argv) {
		for (cnt = 1;(*argv)[cnt];++cnt)
			switch ((*argv)[cnt]) {
				case 'a':
					asdata = YES;
					break;
				case 'o':
					oflg = YES;
					break;
				default:	/* getopt message compatible */
					if (!isdigit((*argv)[cnt])) {
						fprintf(stderr,"strings: illegal option -- %c\nusage: strings [-ao] [-#] [file ... ]\n",(*argv)[cnt]);
						exit(ERREXIT);
					}
					minlen = atoi(*argv + 1);
					break;
E 4
			}
D 4
			minlength = argv[0][i] - '0';
			for (i++; isdigit(argv[0][i]); i++)
				minlength = minlength * 10 + argv[0][i] - '0';
			i--;
			break;
		}
		argc--, argv++;
E 4
I 4
		if (cnt == 1)
			asdata = YES;
E 4
	}
I 4

	if (!(bfr = (u_char *)malloc((u_int)minlen))) {
		fputs("strings: unable to allocate space.\n",stderr);
		exit(ERREXIT);
	}
	bfr[minlen] = EOS;
	file = "stdin";
E 4
	do {
D 4
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
E 4
I 4
		if (*argv) {
			if (!freopen(*argv,"r",stdin)) {
				perror(*argv);
				exit(ERREXIT);
E 4
			}
D 4
			infile = argv[0];
			argc--, argv++;
E 4
I 4
			file = *argv++;
E 4
		}
D 2
		fseek(stdin, (long) 0, 0);
E 2
I 2
D 4
		fseek(stdin, (long) 0, L_SET);
E 2
		if (asdata ||
		    fread((char *)&header, sizeof header, 1, stdin) != 1 || 
		    N_BADMAG(header)) {
D 2
			fseek(stdin, (long) 0, 0);
E 2
I 2
			fseek(stdin, (long) 0, L_SET);
E 2
			find((long) 100000000L);
			continue;
E 4
I 4
		foff = 0;
		read_len = ERR;
		if (asdata)
			head_len = 0;
		else {
			head = (EXEC *)hbfr;
			if ((head_len = read(fileno(stdin),(char *)head,sizeof(EXEC))) == ERR) {
				perror(file);
				exit(ERREXIT);
			}
			if (head_len == sizeof(EXEC) && !N_BADMAG(*head)) {
				foff = N_TXTOFF(*head) + head->a_text;
				if (fseek(stdin,foff,L_SET) == ERR) {
					perror(file);
					exit(ERREXIT);
				}
				read_len = head->a_data;
				head_len = 0;
			}
			else
				hcnt = 0;
E 4
		}
D 2
		fseek(stdin, (long) N_TXTOFF(header)+header.a_text, 1);
E 2
I 2
D 4
		fseek(stdin, (long) N_TXTOFF(header)+header.a_text, L_SET);
E 2
		find((long) header.a_data);
	} while (argc > 0);
}

find(cnt)
	long cnt;
{
	static char buf[BUFSIZ];
	register char *cp;
	register int c, cc;

	cp = buf, cc = 0;
	for (; cnt != 0; cnt--) {
		c = getc(stdin);
		if (c == '\n' || dirt(c) || cnt == 0) {
			if (cp > buf && cp[-1] == '\n')
				--cp;
			*cp++ = 0;
			if (cp > &buf[minlength]) {
E 4
I 4
		for (cnt = 0;(ch = getch()) != EOF;) {
			if (ISSTR(ch)) {
				if (!cnt)
					C = bfr;
				*C++ = ch;
				if (++cnt < minlen)
					continue;
E 4
				if (oflg)
D 4
					printf("%7D ", ftell(stdin) - cc - 1);
				printf("%s\n", buf);
E 4
I 4
D 5
					printf("%07lo %s",foff - minlen,bfr);
E 5
I 5
					printf("%07ld %s",foff - minlen,bfr);
E 5
				else
					fputs((char *)bfr,stdout);
				while ((ch = getch()) != EOF && ISSTR(ch))
					putchar((char)ch);
				putchar('\n');
E 4
			}
D 4
			cp = buf, cc = 0;
		} else {
			if (cp < &buf[sizeof buf - 2])
				*cp++ = c;
			cc++;
E 4
I 4
			cnt = 0;
E 4
		}
D 4
		if (ferror(stdin) || feof(stdin))
			break;
	}
E 4
I 4
	} while (*argv);
	exit(OK);
E 4
}

D 4
dirt(c)
	int c;
E 4
I 4
/*
 * getch --
 *	get next character from wherever
 */
static
getch()
E 4
{
D 4

	switch (c) {

	case '\n':
	case '\f':
		return (0);

	case 0177:
		return (1);

	default:
		return (c > 0200 || c < ' ');
E 4
I 4
	++foff;
	if (head_len) {
		if (hcnt < head_len)
			return((int)hbfr[hcnt++]);
		head_len = 0;
E 4
	}
I 4
	if (read_len == ERR || read_len-- > 0)
		return(getchar());
	return(EOF);
E 4
}
E 1

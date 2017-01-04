h48094
s 00002/00003/00168
d D 4.5 87/10/06 17:09:20 bostic 5 4
c -df get set even if one or the other already set
e
s 00001/00001/00170
d D 4.4 87/10/06 14:37:35 bostic 4 3
c buf should have been a register
e
s 00138/00131/00033
d D 4.3 87/08/05 12:37:18 bostic 3 2
c well, I needed to understand it, so I rewrote it.  Added getopt(3),
c a usage message, removed the hooks for a 't' flag, replaced its private 
c compare routine with strncmp(2), made it faster (not that anyone would 
c ever notice), and made it lint cleanly.
e
s 00001/00000/00163
d D 4.2 81/07/02 02:07:18 root 2 1
c add exit(0) per day
e
s 00163/00000/00000
d D 4.1 80/10/01 17:27:22 bill 1 0
c date and time created 80/10/01 17:27:22 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
E 3
#include <stdio.h>
#include <ctype.h>

D 3
FILE *dfile;
char *filenam  = "/usr/dict/words";
E 3
I 3
#define	EOS		'\0'
#define	MAXLINELEN	250
#define	YES		1
E 3

D 3
int fold;
int dict;
int tab;
char entry[250];
char word[250];
char key[50];
E 3
I 3
static int	fold, dict, len;
E 3

D 3
main(argc,argv)
char **argv;
E 3
I 3
main(argc, argv)
	int	argc;
	char	**argv;
E 3
{
D 3
	register c;
	long top,bot,mid;
	while(argc>=2 && *argv[1]=='-') {
		for(;;) {
			switch(*++argv[1]) {
			case 'd':
				dict++;
				continue;
			case 'f':
				fold++;
				continue;
			case 't':
				tab = argv[1][1];
				if(tab)
					++argv[1];
				continue;
			case 0:
				break;
			default:
				continue;
			}
E 3
I 3
	extern char	*optarg;
	extern int	optind;
	static char	*filename = "/usr/dict/words";
	register off_t	bot, mid, top;
	register int	c;
	struct stat	sb;
	char	entry[MAXLINELEN], copy[MAXLINELEN];

	while ((c = getopt(argc, argv, "df")) != EOF)
		switch((char)c) {
		case 'd':
			dict = YES;
E 3
			break;
I 3
		case 'f':
			fold = YES;
			break;
		case '?':
		default:
			usage();
E 3
		}
D 3
		argc --;
		argv++;
E 3
I 3
	argv += optind;
	argc -= optind;

	switch(argc) {
D 5
	case 1:	/* if nothing set, default to dictionary order and folding */
		if (!dict && !fold)
			dict = fold = YES;
E 5
I 5
	case 1:	/* if default file, set to dictionary order and folding */
		dict = fold = YES;
E 5
		break;
	case 2:
		filename = argv[1];
		break;
	default:
		usage();
E 3
	}
D 3
	if(argc<=1)
		return;
	if(argc==2) {
		fold++;
		dict++;
	} else
		filenam = argv[2];
	dfile = fopen(filenam,"r");
	if(dfile==NULL) {
		fprintf(stderr,"look: can't open %s\n",filenam);
E 3
I 3

	if (!freopen(filename, "r", stdin)) {
		fprintf(stderr,"look: can't read %s.\n", filename);
E 3
		exit(2);
	}
D 3
	canon(argv[1],key);
	bot = 0;
	fseek(dfile,0L,2);
	top = ftell(dfile);
	for(;;) {
		mid = (top+bot)/2;
		fseek(dfile,mid,0);
		do {
			c = getc(dfile);
			mid++;
		} while(c!=EOF && c!='\n');
		if(!getword(entry))
E 3
I 3
	if (fstat(fileno(stdin), &sb)) {
		perror("look: fstat");
		exit(2);
	}

	len = strlen(*argv);
	canon(*argv, *argv);
	len = strlen(*argv);		/* may have changed */
	if (len > MAXLINELEN - 1) {
		fputs("look: search string is too long.\n", stderr);
		exit(2);
	}

	for (bot = 0, top = sb.st_size;;) {
		mid = (top + bot) / 2;
		(void)fseek(stdin, mid, L_SET);

		for (++mid; (c = getchar()) != EOF && c != '\n'; ++mid);
		if (!getline(entry))
E 3
			break;
D 3
		canon(entry,word);
		switch(compare(key,word)) {
		case -2:
		case -1:
		case 0:
			if(top<=mid)
E 3
I 3
		canon(entry, copy);
		if (strncmp(*argv, copy, len) <= 0) {
			if (top <= mid)
E 3
				break;
			top = mid;
D 3
			continue;
		case 1:
		case 2:
			bot = mid;
			continue;
E 3
		}
D 3
		break;
E 3
I 3
		else
			bot = mid;
E 3
	}
D 3
	fseek(dfile,bot,0);
	while(ftell(dfile)<top) {
		if(!getword(entry))
			return;
		canon(entry,word);
		switch(compare(key,word)) {
		case -2:
			return;
		case -1:
		case 0:
			puts(entry,stdout);
E 3
I 3
	(void)fseek(stdin, bot, L_SET);
	while (ftell(stdin) < top) {
		register int val;

		if (!getline(entry))
			exit(0);
		canon(entry, copy);
		if (!(val = strncmp(*argv, copy, len))) {
			puts(entry);
E 3
			break;
D 3
		case 1:
		case 2:
			continue;
E 3
		}
D 3
		break;
E 3
I 3
		if (val < 0)
			exit(0);
E 3
	}
D 3
	while(getword(entry)) {
		canon(entry,word);
		switch(compare(key,word)) {
		case -1:
		case 0:
			puts(entry,stdout);
			continue;
		}
		break;
E 3
I 3
	while (getline(entry)) {
		canon(entry, copy);
		if (strncmp(*argv, copy, len))
			break;
		puts(entry);
E 3
	}
I 2
	exit(0);
E 2
}

D 3
compare(s,t)
register char *s,*t;
E 3
I 3
/*
 * getline --
 *	get a line
 */
static
getline(buf)
D 4
	char	*buf;
E 4
I 4
	register char	*buf;
E 4
E 3
{
D 3
	for(;*s==*t;s++,t++)
		if(*s==0)
			return(0);
	return(*s==0? -1:
		*t==0? 1:
		*s<*t? -2:
		2);
}
E 3
I 3
	register int	c;
E 3

D 3
getword(w)
char *w;
{
	register c;
	for(;;) {
		c = getc(dfile);
		if(c==EOF)
E 3
I 3
	for (;;) {
		if ((c = getchar()) == EOF)
E 3
			return(0);
D 3
		if(c=='\n')
E 3
I 3
		if (c == '\n')
E 3
			break;
D 3
		*w++ = c;
E 3
I 3
		*buf++ = c;
E 3
	}
D 3
	*w = 0;
E 3
I 3
	*buf = EOS;
E 3
	return(1);
}

D 3
canon(old,new)
char *old,*new;
E 3
I 3
/*
 * canon --
 *	create canonical version of word
 */
static
canon(src, copy)
	register char	*src, *copy;
E 3
{
D 3
	register c;
	for(;;) {
		*new = c = *old++;
		if(c==0||c==tab) {
			*new = 0;
			break;
		}
		if(dict) {
			if(!isalnum(c))
				continue;
		}
		if(fold) {
			if(isupper(c))
				*new += 'a' - 'A';
		}
		new++;
	}
E 3
I 3
	register int	cnt;
	register char	c;

	for (cnt = len + 1; (c = *src++) && cnt; --cnt)
		if (!dict || isalnum(c))
			*copy++ = fold && isupper(c) ? tolower(c) : c;
	*copy = EOS;
}

/*
 * usage --
 *	print a usage message and die
 */
static
usage()
{
	fputs("usage: look [-df] string [file]\n", stderr);
	exit(1);
E 3
}
E 1

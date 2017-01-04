h09765
s 00014/00009/00242
d D 4.9 88/06/18 13:19:18 bostic 13 12
c install approved copyright notice
e
s 00001/00001/00250
d D 4.8 87/12/21 12:37:45 bostic 12 11
c make ANSI C compatible
e
s 00008/00002/00243
d D 4.7 87/11/24 15:54:48 bostic 11 9
c Berkeley code, fix copyright
e
s 00010/00004/00241
d R 4.7 87/11/24 15:51:00 bostic 10 9
c Berkeley code; correct copyright
e
s 00106/00090/00139
d D 4.6 87/11/23 19:16:29 bostic 9 8
c fixes from guy@sun.com; better error messages/checking; fix usage 
c message to be on stderr a la S5; reformat to Berkeley standard
e
s 00027/00014/00202
d D 4.5 87/11/18 16:47:18 bostic 8 6
c add real header; make -s as fast as -l; minor reformatting
e
s 00015/00001/00215
d R 4.5 87/11/18 16:35:18 bostic 7 6
c add real header
e
s 00001/00001/00215
d D 4.4 87/03/12 17:06:01 bostic 6 5
c added newline to usage
e
s 00194/00100/00022
d D 4.3 86/12/11 06:24:06 bostic 5 2
c general speedups with larger buffers and bcmp
e
s 00001/00001/00121
d D 4.2 83/04/29 00:52:15 mckusick 2 1
c added perror
e
s 00122/00000/00000
d D 4.1 80/10/01 17:25:39 bill 1 0
c date and time created 80/10/01 17:25:39 by bill
e
u
U
t
T
I 1
D 8
static char *sccsid = "%W% (Berkeley) %G%";
E 8
I 8
/*
D 13
 * Copyright (c) 1987 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1987 Regents of the University of California.
E 13
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 11
 */
E 8
I 5

I 8
#ifndef lint
char copyright[] =
D 13
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 13
I 13
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 13
 All rights reserved.\n";
D 13
#endif /* !lint */
E 13
I 13
#endif /* not lint */
E 13

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif /* !lint */
E 13
I 13
#endif /* not lint */
E 13

E 8
#include <sys/param.h>
#include <sys/file.h>
#include <sys/stat.h>
E 5
#include <stdio.h>
#include <ctype.h>
I 9
#include <errno.h>
E 9

D 5
FILE	*file1,*file2;
int	eflg;
int	lflg	= 1;
long	line	= 1;
long	chr	= 0;
long	skip1;
long	skip2;
E 5
I 5
#define DIFF	1			/* found differences */
#define ERR	2			/* error during run */
#define NO	0			/* no/false */
#define OK	0			/* didn't find differences */
#define YES	1			/* yes/true */
E 5

D 5
long	otoi();
E 5
I 5
D 9
static int	fd1,			/* descriptor, file 1 */
		fd2,			/* descriptor, file 2 */
E 9
I 9
D 12
static int	fd1, fd2;		/* file descriptors */
E 12
I 12
static int	fd1, fd2,		/* file descriptors */
E 12
E 9
D 8
		silent = NO;		/* if silent on error */
E 8
I 8
		silent = NO;		/* if silent run */
E 8
static short	all = NO;		/* if report all differences */
D 9
static	u_char	buf1[MAXBSIZE],		/* read buffers */
E 9
I 9
static u_char	buf1[MAXBSIZE],		/* read buffers */
E 9
		buf2[MAXBSIZE];
D 9
static char	*file1,			/* name, file 1 */
		*file2;			/* name, file 2 */
E 9
I 9
static char	*file1, *file2;		/* file names */
E 9
E 5

D 5
main(argc, argv)
char **argv;
E 5
I 5
D 9
main(argc,argv)
int	argc;
char	**argv;
E 9
I 9
main(argc, argv)
	int	argc;
	char	**argv;
E 9
E 5
{
D 5
	register c1, c2;
	char *arg;
E 5
I 5
D 9
	extern char	*optarg;	/* getopt externals */
E 9
I 9
	extern char	*optarg;
E 9
	extern int	optind;
D 9
	int	ch;			/* arguments */
E 9
I 9
	int	ch;
E 9
	u_long	otoi();
E 5

D 5
	if(argc < 3)
		goto narg;
	arg = argv[1];
	if(arg[0] == '-' && arg[1] == 's') {
		lflg--;
		argv++;
		argc--;
E 5
I 5
D 9
	while ((ch = getopt(argc,argv,"ls")) != EOF)
E 9
I 9
	while ((ch = getopt(argc, argv, "ls")) != EOF)
E 9
		switch(ch) {
D 9
			case 'l':		/* print all differences */
				all = YES;
				break;
D 8
			case 's':		/* silent return */
E 8
I 8
			case 's':		/* silent run */
E 8
				silent = YES;
				break;
			case '?':
			default:
				usage();
E 9
I 9
		case 'l':		/* print all differences */
			all = YES;
			break;
		case 's':		/* silent run */
			silent = YES;
			break;
		case '?':
		default:
			usage();
E 9
		}
	argv += optind;
	argc -= optind;

	if (argc < 2 || argc > 4)
		usage();

	/* open up files; "-" is stdin */
	file1 = argv[0];
D 9
	if (strcmp(file1,"-") && (fd1 = open(file1,O_RDONLY)) < 0) {
		if (!silent)
			perror(file1);
		exit(ERR);
E 5
	}
E 9
I 9
	if (strcmp(file1, "-") && (fd1 = open(file1, O_RDONLY, 0)) < 0)
		error(file1);
E 9
D 5
	arg = argv[1];
	if(arg[0] == '-' && arg[1] == 'l') {
		lflg++;
		argv++;
		argc--;
E 5
I 5
	file2 = argv[1];
D 9
	if ((fd2 = open(file2,O_RDONLY)) < 0) {
		if (!silent)
			perror(file2);
		exit(ERR);
E 5
	}
E 9
I 9
	if ((fd2 = open(file2, O_RDONLY, 0)) < 0)
		error(file2);
E 9
D 5
	if(argc < 3)
		goto narg;
	arg = argv[1];
	if( arg[0]=='-' && arg[1]==0 )
		file1 = stdin;
	else if((file1 = fopen(arg, "r")) == NULL)
		goto barg;
	arg = argv[2];
	if((file2 = fopen(arg, "r")) == NULL)
		goto barg;
	if (argc>3)
		skip1 = otoi(argv[3]);
	if (argc>4)
		skip2 = otoi(argv[4]);
	while (skip1) {
		if ((c1 = getc(file1)) == EOF) {
			arg = argv[1];
			goto earg;
		}
		skip1--;
E 5
I 5

	/* handle skip arguments */
	if (argc > 2) {
D 9
		skip(otoi(argv[2]),fd1,file1);
E 9
I 9
		skip(otoi(argv[2]), fd1, file1);
E 9
		if (argc == 4)
D 9
			skip(otoi(argv[3]),fd2,file2);
E 9
I 9
			skip(otoi(argv[3]), fd2, file2);
E 9
E 5
	}
D 5
	while (skip2) {
		if ((c2 = getc(file2)) == EOF) {
			arg = argv[2];
			goto earg;
E 5
I 5
	cmp();
I 9
	/*NOTREACHED*/
E 9
}

/*
 * skip --
 *	skip first part of file
 */
static
D 9
skip(dist,fd,fname)
register u_long	dist;			/* length in bytes, to skip */
register int	fd;			/* file descriptor */
char	*fname;				/* file name for error */
E 9
I 9
skip(dist, fd, fname)
	register u_long	dist;		/* length in bytes, to skip */
	register int	fd;		/* file descriptor */
	char	*fname;			/* file name for error */
E 9
{
	register int	rlen;		/* read length */
I 9
	register int	nread;
E 9

D 9
	for (;dist;dist -= rlen) {
		rlen = MIN(dist,sizeof(buf1));
		if (read(fd,buf1,rlen) != rlen) {
			if (!silent)
				printf("cmp: EOF on %s\n",fname);
			exit(DIFF);
E 9
I 9
	for (; dist; dist -= rlen) {
		rlen = MIN(dist, sizeof(buf1));
		if ((nread = read(fd, buf1, rlen)) != rlen) {
			if (nread < 0)
				error(fname);
			else
				endoffile(fname);
E 9
E 5
		}
D 5
		skip2--;
E 5
	}
I 5
}
E 5

D 5
loop:
	chr++;
	c1 = getc(file1);
	c2 = getc(file2);
	if(c1 == c2) {
		if (c1 == '\n')
			line++;
		if(c1 == EOF) {
			if(eflg)
				exit(1);
			exit(0);
E 5
I 5
static
cmp()
{
D 9
	register u_char	*C1,		/* traveling pointers */
			*C2;
E 9
I 9
	register u_char	*C1, *C2;	/* traveling pointers */
E 9
	register int	cnt,		/* counter */
D 9
			len1,		/* read length 1 */
			len2;		/* read length 2 */
E 9
I 9
			len1, len2;	/* read lengths */
E 9
	register long	byte,		/* byte count */
			line;		/* line count */
	short	dfound = NO;		/* if difference found */

D 9
	for (byte = 0,line = 1;;) {
		switch(len1 = read(fd1,buf1,MAXBSIZE)) {
			case -1:
				if (!silent)
					perror(file1);
				exit(ERR);
			case 0:
				/*
				 * read of file 1 just failed, find out
				 * if there's anything left in file 2
				 */
				switch(read(fd2,buf2,1)) {
					case -1:
						if (!silent)
							perror(file2);
						exit(ERR);
					case 0:
						exit(dfound ? DIFF : OK);
					default:
						if (!silent)
							printf("cmp: EOF on %s\n",file1);
						exit(DIFF);
				}
E 9
I 9
	for (byte = 0, line = 1;;) {
		switch(len1 = read(fd1, buf1, MAXBSIZE)) {
		case -1:
			error(file1);
		case 0:
			/*
			 * read of file 1 just failed, find out
			 * if there's anything left in file 2
			 */
			switch(read(fd2, buf2, 1)) {
				case -1:
					error(file2);
				case 0:
					exit(dfound ? DIFF : OK);
				default:
					endoffile(file1);
			}
E 9
E 5
		}
D 5
		goto loop;
E 5
I 5
		/*
		 * file1 might be stdio, which means that a read of less than
		 * MAXBSIZE might not mean an EOF.  So, read whatever we read
		 * from file1 from file2.
		 */
D 9
		if ((len2 = read(fd2,buf2,len1)) == -1)  {
			if (!silent)
				perror(file2);
			exit(ERR);
		}
		if (bcmp(buf1,buf2,len2)) {
E 9
I 9
		if ((len2 = read(fd2, buf2, len1)) == -1)
			error(file2);
		if (bcmp(buf1, buf2, len2)) {
E 9
			if (silent)
				exit(DIFF);
			if (all) {
				dfound = YES;
D 9
				for (C1 = buf1,C2 = buf2,cnt = len2;cnt--;++C1,++C2) {
E 9
I 9
				for (C1 = buf1, C2 = buf2, cnt = len2; cnt--; ++C1, ++C2) {
E 9
					++byte;
					if (*C1 != *C2)
D 9
						printf("%6ld %3o %3o\n",byte,*C1,*C2);
E 9
I 9
						printf("%6ld %3o %3o\n", byte, *C1, *C2);
E 9
				}
			}
D 8
			else
				for (C1 = buf1,C2 = buf2;;++C1,++C2) {
					++byte;
					if (*C1 != *C2) {
						printf("%s %s differ: char %ld, line %ld\n",file1,file2,byte,line);
						exit(DIFF);
					}
					if (*C1 == '\n')
						++line;
E 8
I 8
D 9
			else for (C1 = buf1,C2 = buf2;;++C1,++C2) {
E 9
I 9
			else for (C1 = buf1, C2 = buf2;; ++C1, ++C2) {
E 9
				++byte;
				if (*C1 != *C2) {
D 9
					printf("%s %s differ: char %ld, line %ld\n",file1,file2,byte,line);
E 9
I 9
					printf("%s %s differ: char %ld, line %ld\n", file1, file2, byte, line);
E 9
					exit(DIFF);
E 8
				}
I 8
				if (*C1 == '\n')
					++line;
			}
E 8
		}
		else {
			byte += len2;
			/*
			 * here's the real performance problem, we've got to
			 * count the stupid lines, which means that -l is a
			 * *much* faster version, i.e., unless you really
D 8
			 * *want* to know the line number, run -sl.
E 8
I 8
			 * *want* to know the line number, run -s or -l.
E 8
			 */
D 8
			if (!all)
E 8
I 8
			if (!silent && !all)
E 8
D 9
				for (C1 = buf1,cnt = len2;cnt--;)
E 9
I 9
				for (C1 = buf1, cnt = len2; cnt--;)
E 9
					if (*C1++ == '\n')
						++line;
		}
		/*
		 * couldn't read as much from file2 as from file1; checked
		 * here because there might be a difference before we got
		 * to this point, which would have precedence.
		 */
D 9
		if (len2 < len1) {
			if (!silent)
				printf("cmp: EOF on %s\n",file2);
			exit(DIFF);
		}
E 9
I 9
		if (len2 < len1)
			endoffile(file2);
E 9
E 5
	}
D 5
	if(lflg == 0)
		exit(1);
	if(c1 == EOF) {
		arg = argv[1];
		goto earg;
	}
	if(c2 == EOF)
		goto earg;
	if(lflg == 1) {
		printf("%s %s differ: char %ld, line %ld\n", argv[1], arg,
			chr, line);
		exit(1);
	}
	eflg = 1;
	printf("%6ld %3o %3o\n", chr, c1, c2);
	goto loop;
E 5
I 5
}
E 5

D 5
narg:
	printf("cmp: arg count\n");
	exit(2);
E 5
I 5
/*
 * otoi --
 *	octal/decimal string to u_long
 */
static u_long
otoi(C)
D 9
register char	*C;		/* argument string */
E 9
I 9
	register char	*C;		/* argument string */
E 9
{
D 9
	register u_long	val;	/* return value */
	register int	base;	/* number base */
E 9
I 9
	register u_long	val;		/* return value */
	register int	base;		/* number base */
E 9
E 5

D 5
barg:
	if (lflg)
D 2
	printf("cmp: cannot open %s\n", arg);
E 2
I 2
	perror(arg);
E 2
	exit(2);

earg:
	printf("cmp: EOF on %s\n", arg);
	exit(1);
E 5
I 5
	base = (*C == '0') ? 8 : 10;
D 9
	for (val = 0;isdigit(*C);++C)
E 9
I 9
	for (val = 0; isdigit(*C); ++C)
E 9
		val = val * base + *C - '0';
	return(val);
E 5
}

D 5
long otoi(s)
char *s;
E 5
I 5
/*
I 9
 * error --
 *	print I/O error message and die
 */
static
error(filename)
	char *filename;
{
	extern int errno;
	int sverrno;

	if (!silent) {
		sverrno = errno;
		(void)fprintf(stderr, "cmp: %s: ", filename);
		errno = sverrno;
		perror((char *)NULL);
	}
	exit(ERR);
}

/*
 * endoffile --
 *	print end-of-file message and exit indicating the files were different
 */
static
endoffile(filename)
	char *filename;
{
	/* 32V put this message on stdout, S5 does it on stderr. */
	if (!silent)
		(void)fprintf(stderr, "cmp: EOF on %s\n", filename);
	exit(DIFF);
}

/*
E 9
 * usage --
 *	print usage and die
 */
static
usage()
E 5
{
D 5
	long v;
	int base;

	v = 0;
	base = 10;
	if (*s == '0')
		base = 8;
	while(isdigit(*s))
		v = v*base + *s++ - '0';
	return(v);
E 5
I 5
D 6
	fputs("usage: cmp [-ls] file1 file2 [skip1] [skip2]",stderr);
E 6
I 6
D 9
	fputs("usage: cmp [-ls] file1 file2 [skip1] [skip2]\n",stderr);
E 9
I 9
	fputs("usage: cmp [-ls] file1 file2 [skip1] [skip2]\n", stderr);
E 9
E 6
	exit(ERR);
E 5
}
E 1

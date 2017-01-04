h29025
s 00079/00041/00021
d D 5.4 85/12/14 20:05:53 sam 9 8
c give up and put back old version, but up buffer sizes
e
s 00001/00001/00061
d D 5.3 85/12/14 19:38:00 sam 8 7
c use read to elminate buffering, fread changes tee's semantics
e
s 00001/00001/00061
d D 5.2 85/10/24 17:56:44 bloom 7 6
c stdout was being overwritten in the list of outputs
e
s 00041/00079/00021
d D 5.1 85/10/01 22:09:50 mckusick 6 5
c version using stdio from sam
e
s 00001/00001/00099
d D 4.4 83/08/19 19:50:35 sam 5 3
c give proper exit status on success
e
s 00001/00000/00100
d R 4.4 83/08/18 15:09:22 sam 4 3
c fix exit status
e
s 00002/00001/00098
d D 4.3 83/05/22 18:32:39 sam 3 2
c pagsiz.h must go....
e
s 00001/00001/00098
d D 4.2 82/03/31 22:45:52 mckusic 2 1
c explicit define BUFSIZ as 1024
e
s 00099/00000/00000
d D 4.1 80/10/01 17:28:53 bill 1 0
c date and time created 80/10/01 17:28:53 by bill
e
u
U
t
T
I 6
D 9
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
E 6
I 3
#ifndef lint
I 6
D 9
char copyright[] =
"%Z% Copyright (c) 1985 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 9
E 6
E 3
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 3
#endif
E 3
/*
 * tee-- pipe fitting
 */

I 6
D 9
#include <stdio.h>
E 9
E 6
#include <signal.h>
I 9
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
E 9
D 6
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
E 6
D 3
#include <pagsiz.h>
E 3

I 9
#define	BUFSIZ	8192
int openf[20] = { 1 };
int n = 1;
int t = 0;
int aflag;

char in[BUFSIZ];

char out[BUFSIZ];

extern errno;
long	lseek();

E 9
D 2
#define	BUFSIZ	BSIZE
E 2
I 2
D 6
#define	BUFSIZ	1024
E 2
int openf[20] = { 1 };
int n = 1;
int t = 0;
int aflag;

char in[BUFSIZ];

char out[BUFSIZ];

extern errno;
long	lseek();

E 6
main(argc,argv)
D 6
char **argv;
E 6
I 6
D 9
	int argc;
	char *argv[];
E 9
I 9
char **argv;
E 9
E 6
{
D 6
	int register r,w,p;
	struct stat buf;
	while(argc>1&&argv[1][0]=='-') {
		switch(argv[1][1]) {
E 6
I 6
D 9
	register FILE **openf, **lastf, **fdp;
	register i, cc;
	char buf[8192], *calloc();
	int aflag = 0;

	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch (argv[0][1]) {
E 9
I 9
	int register r,w,p;
	struct stat buf;
	while(argc>1&&argv[1][0]=='-') {
		switch(argv[1][1]) {
E 9
E 6
		case 'a':
			aflag++;
			break;
		case 'i':
D 6
		case 0:
E 6
I 6
D 9
		case '\0':
E 9
I 9
		case 0:
E 9
E 6
			signal(SIGINT, SIG_IGN);
I 6
D 9
			break;
E 9
E 6
		}
D 6
		argv++;
		argc--;
E 6
I 6
D 9
		argv++, argc--;
E 9
I 9
		argv++;
		argc--;
E 9
E 6
	}
D 6
	fstat(1,&buf);
	t = (buf.st_mode&S_IFMT)==S_IFCHR;
	if(lseek(1,0L,1)==-1&&errno==ESPIPE)
		t++;
	while(argc-->1) {
		if(aflag) {
			openf[n] = open(argv[1],1);
			if(openf[n] < 0)
				openf[n] = creat(argv[1],0666);
			lseek(openf[n++],0L,2);
		} else
			openf[n++] = creat(argv[1],0666);
		if(stat(argv[1],&buf)>=0) {
			if((buf.st_mode&S_IFMT)==S_IFCHR)
				t++;
		} else {
			puts("tee: cannot open ");
			puts(argv[1]);
			puts("\n");
			n--;
		}
		argv++;
E 6
I 6
D 9
	lastf = openf = (FILE **)calloc(argc+1, sizeof (FILE *));
	if (openf == 0) {
		fprintf(stderr, "tee: Out of memory.\n");
		exit(-1);
E 9
I 9
	fstat(1,&buf);
	t = (buf.st_mode&S_IFMT)==S_IFCHR;
	if(lseek(1,0L,1)==-1&&errno==ESPIPE)
		t++;
	while(argc-->1) {
		if(aflag) {
			openf[n] = open(argv[1],1);
			if(openf[n] < 0)
				openf[n] = creat(argv[1],0666);
			lseek(openf[n++],0L,2);
		} else
			openf[n++] = creat(argv[1],0666);
		if(stat(argv[1],&buf)>=0) {
			if((buf.st_mode&S_IFMT)==S_IFCHR)
				t++;
		} else {
			puts("tee: cannot open ");
			puts(argv[1]);
			puts("\n");
			n--;
		}
		argv++;
E 9
E 6
	}
D 6
	r = w = 0;
	for(;;) {
		for(p=0;p<BUFSIZ;) {
			if(r>=w) {
				if(t>0&&p>0) break;
				w = read(0,in,BUFSIZ);
				r = 0;
				if(w<=0) {
					stash(p);
D 5
					return;
E 5
I 5
					exit(0);
E 5
				}
			}
			out[p++] = in[r++];
		}
		stash(p);
E 6
I 6
D 7
	*lastf = stdout;	/* default */
E 7
I 7
D 9
	*lastf++ = stdout;	/* default */
E 7
	for (; argc > 0; argc--, argv++) {
		*lastf = fopen(argv[0], aflag ? "a" : "w");
		if (*lastf == NULL)
			fprintf(stderr, "tee: %s: cannot open.\n", argv[0]);
		else
			lastf++;
E 9
I 9
	r = w = 0;
	for(;;) {
		for(p=0;p<BUFSIZ;) {
			if(r>=w) {
				if(t>0&&p>0) break;
				w = read(0,in,BUFSIZ);
				r = 0;
				if(w<=0) {
					stash(p);
					exit(0);
				}
			}
			out[p++] = in[r++];
		}
		stash(p);
E 9
E 6
	}
D 6
}

stash(p)
{
	int k;
	int i;
	int d;
	d = t ? 16 : p;
	for(i=0; i<p; i+=d)
		for(k=0;k<n;k++)
			write(openf[k], out+i, d<p-i?d:p-i);
}

puts(s)
char *s;
{
	while(*s)
		write(2,s++,1);
E 6
I 6
D 8
	while ((cc = fread(buf, 1, sizeof (buf), stdin)) > 0)
E 8
I 8
D 9
	while ((cc = read(fileno(stdin), buf, sizeof (buf))) > 0)
E 8
		for (fdp = openf; fdp < lastf; fdp++)
			fwrite(buf, 1, cc, *fdp);
	exit(0);
E 9
I 9
}

stash(p)
{
	int k;
	int i;
	int d;
	d = t ? 16 : p;
	for(i=0; i<p; i+=d)
		for(k=0;k<n;k++)
			write(openf[k], out+i, d<p-i?d:p-i);
}

puts(s)
char *s;
{
	while(*s)
		write(2,s++,1);
E 9
E 6
}
E 1

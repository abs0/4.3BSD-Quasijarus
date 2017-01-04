h25934
s 00001/00001/00139
d D 5.2 87/04/06 11:57:38 bostic 4 3
c printf wild format
e
s 00015/00001/00125
d D 5.1 85/05/31 09:06:23 dist 3 2
c Add copyright
e
s 00002/00000/00124
d D 4.2 83/02/09 15:13:48 sam 2 1
c silence warning
e
s 00124/00000/00000
d D 4.1 82/10/20 21:12:03 mckusick 1 0
c date and time created 82/10/20 21:12:03 by mckusick
e
u
U
t
T
I 1
D 3
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*%cc -s -O %
 * apply - apply a command to a set of arguments
 *
 *	apply echo * == ls
 *	apply -2 cmp A1 B1 A2 B2   compares A's with B's
 *	apply "ln %1 /usr/fred/dir" *  duplicates a directory
 */
#include <stdio.h>
char	*cmdp;
#define	NCHARS 512
char	cmd[512];
char	defargs=1;
#define	DEFARGCHAR	'%'
char	argchar=DEFARGCHAR;
int	nchars;
I 2
extern	char *getenv();

E 2
main(argc, argv)
	char *argv[];
{
	register n;
	while(argc>2 && argv[1][0]=='-'){
		if(argv[1][1]=='a'){
			argchar=argv[1][2];
			if(argchar=='\0')
				argchar=DEFARGCHAR;
		} else {
			defargs = atoi(&argv[1][1]);
			if(defargs < 0)
				defargs = 1;
		}
		--argc; ++argv;
	}
	if(argc<2){
D 4
		fprintf(stderr, "usage: apply [-14] [-a%] cmd arglist\n");
E 4
I 4
		fprintf(stderr, "usage: apply [-#] [-ac] cmd arglist\n");
E 4
		exit(1);
	}
	argc -= 2;
	cmdp = argv[1];
	argv += 2;
	while(n=docmd(argc, argv)){
		argc -= n;
		argv += n;
	}
}
char
addc(c)
	char c;
{
	if(nchars++>=NCHARS){
		fprintf(stderr, "apply: command too long\n");
		exit(1);
	}
	return(c);
}
char *
addarg(s, t)
	register char *s, *t;
{
	while(*t = addc(*s++))
		*t++;
	return(t);
}
docmd(argc, argv)
	char *argv[];
{
	register char *p, *q;
	register max, i;
	char gotit;
	if(argc<=0)
		return(0);
	nchars = 0;
	max = 0;
	gotit = 0;
	p = cmdp;
	q = cmd;
	while(*q = addc(*p++)){
		if(*q++!=argchar || *p<'1' || '9'<*p)
			continue;
		if((i= *p++-'1') > max)
			max = i;
		if(i>=argc){
	Toofew:
			fprintf(stderr, "apply: expecting argument(s) after `%s'\n", argv[argc-1]);
			exit(1);
		}
		q = addarg(argv[i], q-1);
		gotit++;
	}
	if(defargs!=0 && gotit==0){
		if(defargs>argc)
			goto Toofew;
		for(i=0; i<defargs; i++){
			*q++ = addc(' ');
			q = addarg(argv[i], q);
		}
	}
	i = system(cmd);
	if(i == 127){
		fprintf(stderr, "apply: no shell!\n");
		exit(1);
	}
	return(max==0? (defargs==0? 1 : defargs) : max+1);
}
system(s)
char *s;
{
	int status, pid, w;
	char *shell = getenv("SHELL");

	if ((pid = fork()) == 0) {
		execl(shell ? shell : "/bin/sh", "sh", "-c", s, 0);
		_exit(127);
	}
	if(pid == -1){
		fprintf(stderr, "apply: can't fork\n");
		exit(1);
	}
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1)
		status = -1;
	return(status);
}
E 1

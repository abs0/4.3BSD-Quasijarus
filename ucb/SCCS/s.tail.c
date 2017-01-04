h35353
s 00002/00001/00236
d D 5.3 86/11/13 19:51:39 karels 9 8
c stop following if nobody's looking
e
s 00003/00003/00234
d D 5.2 86/01/10 04:24:10 lepreau 8 7
c grow buffer from 8K to 32K.
e
s 00015/00002/00222
d D 5.1 85/05/31 09:34:34 dist 7 6
c Add copyright
e
s 00020/00016/00204
d D 4.6 85/01/14 16:42:57 bloom 6 5
c it lints
e
s 00006/00002/00214
d D 4.5 84/06/07 16:13:23 ralph 5 4
c fix "tail -10b"
e
s 00008/00005/00208
d D 4.4 83/08/22 16:51:46 karels 4 3
c tail +1f starts at begining (not +10)
e
s 00001/00001/00212
d D 4.3 83/07/01 02:46:43 sam 3 2
c trash
e
s 00002/00002/00211
d D 4.2 83/06/02 16:52:11 ralph 2 1
c fixed piped flag to reflect actual file, not stdin.
e
s 00213/00000/00000
d D 4.1 80/10/06 23:53:23 root 1 0
c date and time created 80/10/06 23:53:23 by root
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
I 6
#ifndef lint
E 6
I 1
D 7
static char *sccsid = "%W% (Berkeley) %G%";
I 6
#endif
E 7
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 7
E 6
/* tail command 
 *
 *	tail where [file]
D 3
 *	where is +_n[type]
E 3
I 3
 *	where is +/-n[type]
E 3
 *	- means n lines before end
 *	+ means nth line from beginning
 *	type 'b' means tail n blocks, not lines
 *	type 'c' means tail n characters
 *	Type 'r' means in lines in reverse order from end
 *	 (for -r, default is entire buffer )
 *	option 'f' means loop endlessly trying to read more
 *		characters after the end of file, on the  assumption
 *		that the file is growing
*/

#include	<stdio.h>
#include	<ctype.h>
#include	<sys/types.h>
#include	<sys/stat.h>
I 6
#include	<sys/file.h>
E 6
#include	<errno.h>

D 5
#define LBIN 4097
E 5
I 5
D 8
#define LBIN 8193
E 8
I 8
#define LBIN 32769
E 8
#undef	BUFSIZ
D 8
#define	BUFSIZ	LBIN-1
E 8
I 8
#define	BUFSIZ	8192
E 8
E 5
struct	stat	statb;
int	follow;
int	piped;
char bin[LBIN];
int errno;

main(argc,argv)
char **argv;
{
	long n,di;
	register i,j,k;
	char	*arg;
	int partial,bylines,bkwds,fromend,lastnl;
	char *p;

D 2
	lseek(0,(long)0,1);
	piped = errno==ESPIPE;
E 2
	arg = argv[1];
	if(argc<=1 || *arg!='-'&&*arg!='+') {
		arg = "-10l";
		argc++;
		argv--;
	}
	fromend = *arg=='-';
	arg++;
D 4
	n = 0;
	while(isdigit(*arg))
		n = n*10 + *arg++ - '0';
E 4
I 4
	if (isdigit(*arg)) {
		n = 0;
		while(isdigit(*arg))
			n = n*10 + *arg++ - '0';
	} else
		n = -1;
E 4
	if(!fromend&&n>0)
		n--;
	if(argc>2) {
D 6
		close(0);
E 6
I 6
		(void)close(0);
E 6
		if(open(argv[2],0)!=0) {
			perror(argv[2]);
			exit(1);
		}
	}
I 2
D 6
	lseek(0,(long)0,1);
E 6
I 6
	(void)lseek(0,(off_t)0,L_INCR);
E 6
	piped = errno==ESPIPE;
E 2
	bylines = -1; bkwds = 0;
	while(*arg)
	switch(*arg++) {

	case 'b':
I 5
		if (n == -1) n = 1;
E 5
		n <<= 9;
		if(bylines!=-1) goto errcom;
		bylines=0;
		break;
	case 'c':
		if(bylines!=-1) goto errcom;
		bylines=0;
		break;
	case 'f':
		follow = 1;
		break;
	case 'r':
D 4
		if(n==0) n = LBIN;
E 4
I 4
		if(n==-1) n = LBIN;
E 4
		bkwds = 1; fromend = 1; bylines = 1;
		break;
	case 'l':
		if(bylines!=-1) goto errcom;
		bylines = 1;
		break;
	default:
		goto errcom;
	}
D 4
	if (n==0) n = 10;
E 4
I 4
	if (n==-1) n = 10;
E 4
	if(bylines==-1) bylines = 1;
	if(bkwds) follow=0;
	if(fromend)
		goto keep;

			/*seek from beginning */

	if(bylines) {
		j = 0;
		while(n-->0) {
			do {
				if(j--<=0) {
					p = bin;
					j = read(0,p,BUFSIZ);
					if(j--<=0)
						fexit();
				}
			} while(*p++ != '\n');
		}
D 6
		write(1,p,j);
E 6
I 6
		(void)write(1,p,j);
E 6
	} else  if(n>0) {
		if(!piped)
D 6
			fstat(0,&statb);
E 6
I 6
			(void)fstat(0,&statb);
E 6
		if(piped||(statb.st_mode&S_IFMT)==S_IFCHR)
			while(n>0) {
				i = n>BUFSIZ?BUFSIZ:n;
				i = read(0,bin,i);
				if(i<=0)
					fexit();
				n -= i;
			}
		else
D 6
			lseek(0,n,0);
E 6
I 6
			(void)lseek(0,(off_t)n,L_SET);
E 6
	}
copy:
	while((i=read(0,bin,BUFSIZ))>0)
D 6
		write(1,bin,i);
E 6
I 6
		(void)write(1,bin,i);
E 6
	fexit();

			/*seek from end*/

keep:
	if(n <= 0)
		fexit();
	if(!piped) {
D 6
		fstat(0,&statb);
E 6
I 6
		(void)fstat(0,&statb);
E 6
D 5
		di = !bylines&&n<LBIN?n:LBIN-1;
E 5
I 5
		/* If by lines, back up 1 buffer: else back up as needed */
D 8
		di = bylines?BUFSIZ:n;
E 8
I 8
		di = bylines?LBIN-1:n;
E 8
E 5
		if(statb.st_size > di)
D 6
			lseek(0,-di,2);
E 6
I 6
			(void)lseek(0,(off_t)-di,L_XTND);
E 6
		if(!bylines)
			goto copy;
	}
	partial = 1;
	for(;;) {
		i = 0;
		do {
			j = read(0,&bin[i],LBIN-i);
			if(j<=0)
				goto brka;
			i += j;
		} while(i<LBIN);
		partial = 0;
	}
brka:
	if(!bylines) {
		k =
		    n<=i ? i-n:
		    partial ? 0:
		    n>=LBIN ? i+1:
		    i-n+LBIN;
		k--;
	} else {
		if(bkwds && bin[i==0?LBIN-1:i-1]!='\n'){	/* force trailing newline */
			bin[i]='\n';
			if(++i>=LBIN) {i = 0; partial = 0;}
		}
		k = i;
		j = 0;
		do {
			lastnl = k;
			do {
				if(--k<0) {
					if(partial) {
D 6
						if(bkwds) write(1,bin,lastnl+1);
E 6
I 6
						if(bkwds) 
						    (void)write(1,bin,lastnl+1);
E 6
						goto brkb;
					}
					k = LBIN -1;
				}
			} while(bin[k]!='\n'&&k!=i);
			if(bkwds && j>0){
D 6
				if(k<lastnl) write(1,&bin[k+1],lastnl-k);
E 6
I 6
				if(k<lastnl) (void)write(1,&bin[k+1],lastnl-k);
E 6
				else {
D 6
					write(1,&bin[k+1],LBIN-k-1);
					write(1,bin,lastnl+1);
E 6
I 6
					(void)write(1,&bin[k+1],LBIN-k-1);
					(void)write(1,bin,lastnl+1);
E 6
				}
			}
		} while(j++<n&&k!=i);
brkb:
		if(bkwds) exit(0);
		if(k==i) do {
			if(++k>=LBIN)
				k = 0;
		} while(bin[k]!='\n'&&k!=i);
	}
	if(k<i)
D 6
		write(1,&bin[k+1],i-k-1);
E 6
I 6
		(void)write(1,&bin[k+1],i-k-1);
E 6
	else {
D 6
		write(1,&bin[k+1],LBIN-k-1);
		write(1,bin,i);
E 6
I 6
		(void)write(1,&bin[k+1],LBIN-k-1);
		(void)write(1,bin,i);
E 6
	}
	fexit();
errcom:
	fprintf(stderr, "usage: tail [+_[n][lbc][rf]] [file]\n");
	exit(2);
}

fexit()
{	register int n;
	if (!follow || piped) exit(0);
	for (;;)
	{	sleep(1);
		while ((n = read (0, bin, BUFSIZ)) > 0)
D 6
			write (1, bin, n);
E 6
I 6
D 9
			(void)write (1, bin, n);
E 9
I 9
			if (write (1, bin, n) < 0)
				exit(1);
E 9
E 6
	}
}
E 1

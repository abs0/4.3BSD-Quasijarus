h33944
s 00010/00005/00151
d D 5.3 88/06/30 17:53:28 bostic 10 9
c install approved copyright notice
e
s 00014/00002/00142
d D 5.2 88/03/08 08:30:14 bostic 9 8
c add Berkeley specific header
e
s 00013/00004/00131
d D 5.1 85/05/15 11:33:08 dist 8 7
c Add copyright notice; fix page accounting computation by ralph
e
s 00040/00027/00095
d D 4.7 83/05/16 17:21:34 ralph 7 6
c fixed partial buffer problems.
e
s 00017/00012/00105
d D 4.6 83/05/16 17:21:34 ralph 6 5
c changes for px and py printcap entries.
e
s 00090/00102/00027
d D 4.5 83/04/29 11:40:15 ralph 5 4
c initial edits
e
s 00044/00021/00085
d D 4.4 81/07/12 00:40:15 fitz 4 3
c check in version checked out by Dan Fitz (kls)
e
s 00001/00001/00105
d D 4.3 81/05/13 00:52:11 fitz 3 2
c exit signal now causes requeueing
e
s 00021/00004/00085
d D 4.2 81/04/23 15:52:08 fitz 2 1
c now form feeds before printing
e
s 00089/00000/00000
d D 4.1 81/02/12 14:46:23 halbert 1 0
c date and time created 81/02/12 14:46:23 by halbert
e
u
U
t
T
I 1
D 8
/*  VDMP: version %I%				updated %G%
 *
E 8
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */
I 9

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 8
 *  reads raster file created by cifplot and dumps it onto the
 *  Varian or Versatec plotter.
D 5
 *  Must be called with vcontrol or by vpd/vad daemon since
 *  it assumes plotter is already opened as device 3.
E 5
I 5
 *  Assumptions:
 *	Input is from device 0.
 *	plotter is already opened as device 1.
 *	error output file is device 2.
E 5
 */
#include <stdio.h>
D 5
#include <signal.h>
E 5
#include <sys/vcmd.h>

I 7
#define IN	0
#define OUT	1

E 7
D 4
#define BUFSIZE		16384
E 4
I 4
#define MAGIC_WORD	0xA5CF4DFA
E 4

I 4
#define BUFSIZE		1024*128
#define BLOCK		1024

E 4
D 5
extern char *ctime();
extern long time();
E 5
I 5
D 6
static char *Sid = "@(#)vdmp.c	4.1\t4/29/83";
E 6
I 6
D 7
static char *Sid = "@(#)vdmp.c	4.2\t5/16/83";
E 7
I 7
D 8
static char *Sid = "@(#)vdmp.c	4.3\t6/24/83";
E 8
I 8
static char *Sid = "@(#)vdmp.c	5.1\t5/15/85";
E 8
E 7
E 6
E 5

D 5
char *Sid = "%W%\t%G%";
int	plotmd[]	= { VPLOT, 0, 0};
int	prtmd[]		= { VPRINT, 0, 0};
char *name = "";
char *banner = "";
E 5
I 5
D 6
int	plotmd[] = { VPLOT, 0, 0 };
int	prtmd[]	= { VPRINT, 0, 0 };
E 6
I 6
int	plotmd[] = { VPLOT };
int	prtmd[]	= { VPRINT };
E 6
E 5

I 4
D 5
int inbuf[BLOCK/sizeof(int)];
E 4
char vpbuf[BUFSIZE];
E 5
I 5
int	inbuf[BLOCK/sizeof(int)];
D 7
char	vpbuf[BUFSIZE];
E 7
I 7
char	buf[BUFSIZE];
E 7
int	lines;
E 5

D 5
int	in;
E 5
I 5
D 6
int	varian = 1;		/* use varian by default */
int	BytesPerLine = 264;	/* Number of bytes per raster line */
E 6
I 6
int	varian;			/* 0 for versatec, 1 for varian. */
int	BYTES_PER_LINE;		/* number of bytes per raster line. */
int	PAGE_LINES;		/* number of raster lines per page. */
E 6
E 5

D 5
#define VARIAN	1
#define VERSATEC 2
E 5
I 5
char	*name, *host, *acctfile;
E 5

D 5
int device = VARIAN;	/* Indicate which device */
int BytesPerLine = 264;	/* Number of bytes per raster line of the output device */

E 5
main(argc, argv)
D 5
char **argv;
E 5
I 5
	int argc;
	char *argv[];
E 5
{
D 5
	extern int onintr();
	int b;
E 5
I 5
	register int n;
E 5

D 4
	for(b=1; argv[b][0] == '-';b++) {
	    switch(argv[b][1]) {
E 4
I 4
D 5
	for(b=0; argv[1][0] == '-';b++) {
	    switch(argv[1][1]) {
E 4
		case 'W':
			device = VERSATEC;
			BytesPerLine = 880;
			break;
		case 'V':
			device = VARIAN;
			BytesPerLine = 264;
			break;
		case 'n':
D 4
			if(argv[++b] != 0)
				name = argv[b];
E 4
I 4
			argc--; argv++;
			if(argv[1] != 0)
				name = argv[1];
E 4
			break;
		case 'b':
D 4
			if(argv[++b] != 0)
E 4
I 4
			argc--; argv++;
			if(argv[1] != 0)
E 4
				banner = argv[b];
			break;
		}
I 4
	    argc--; argv++;
E 4
	    }
I 4
	if(argc < 2) exit(-1);
E 4
I 2
	/* page feed */
	if(device == VARIAN) {
	    ioctl(3, VSETSTATE,prtmd);
	    write(3,"\f",2);
	    }
	if(device == VERSATEC) {
	    ioctl(3, VSETSTATE,prtmd);
	    write(3,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",16);
	    }
I 4
	/* open dump file */
	in = open(argv[1], 0);
	if(in == NULL) {
	    char str[128];
	    sprintf(str,"%s: No such file\n\n\n",argv[1]);
	    ioctl(3, VSETSTATE,prtmd);
	    write(3,str, strlen(str));
	    exit(-1);
	    }
E 4
E 2
	/* write header */
D 4
	{
	    char str[512];
E 4
I 4
	{   char str[512];
E 4
	    long clock;
	    clock = time(0);
D 2
	    sprintf(str,"%s:%s%s\n\0",name,ctime(&clock),banner);
E 2
I 2
D 4
	    sprintf(str,"%s:%s%s\n \0",name,ctime(&clock),banner);
E 4
I 4
	    sprintf(str,"%s:%s%s",name,ctime(&clock),banner);
E 4
E 2
	    ioctl(3, VSETSTATE,prtmd);
D 4
	    write(3,str,strlen(str) & 0xfffffffe); /*makes strlen even*/
E 4
I 4
	    write(3,str,(strlen(str)+1) & 0xfffffffe); /*makes strlen even*/
E 4
	    }
D 4
	while (argc>b) {
		in = open(argv[b++], 0);
		if(in == NULL) {
		    char str[128];
		    sprintf(str,"%s: No such file\n\n\n",argv[b-1]);
		    ioctl(3, VSETSTATE,prtmd);
		    write(3,str, strlen(str));
I 2
		    exit(-1);
E 2
		    }
		  else putplot();
		  }
E 4
I 4
	/* open file for reading */
	b=read(in,inbuf,BLOCK);
	if(inbuf[0] == MAGIC_WORD && b == BLOCK) {
	    /* we have a formatted dump file */
	    inbuf[(BLOCK/sizeof(int))-1] = 0;  /* make sure string terminates */
	    write(3,&(inbuf[4]),(strlen(&(inbuf[4]))+1) & 0xfffe);
	    ioctl(3, VSETSTATE,prtmd);
	    write(3," \n",2);
	    putplot();
	    close(in);
	    }
	  else { 			/* dump file not formatted */
	    /* reset in's seek pointer and plot */
	    close(in);
	    in = open(argv[1], 0);
	    putplot();
	    close(in);
	    }
E 4
I 2
	if(device == VERSATEC) {
	    ioctl(3, VSETSTATE,prtmd);
	    write(3,"\n\n\n\n\n\n\n",8);
	    }
	exit(0);
E 5
I 5
D 6
	if (argv[0][strlen(argv[0]-1)] == 'W') {
		varian = 0;
		BytesPerLine = 880;
E 5
E 2
	}

E 6
I 5
	while (--argc) {
D 7
		if (*(*++argv) == '-') {
E 7
I 7
		if (**++argv == '-') {
E 7
			switch (argv[0][1]) {
I 6
			case 'x':
				BYTES_PER_LINE = atoi(&argv[0][2]) / 8;
				varian = BYTES_PER_LINE == 264;
				break;

			case 'y':
				PAGE_LINES = atoi(&argv[0][2]);
				break;

E 6
			case 'n':
				argc--;
				name = *++argv;
				break;
E 5

I 5
			case 'h':
				argc--;
				host = *++argv;
			}
		} else
			acctfile = *argv;
	}

D 7
	n = read(0, inbuf, BLOCK);
E 7
I 7
	n = read(IN, inbuf, BLOCK);
E 7
	if (inbuf[0] == MAGIC_WORD && n == BLOCK) {
		/* we have a formatted dump file */
		inbuf[(BLOCK/sizeof(int))-1] = 0;  /* make sure string terminates */
D 7
		ioctl(1, VSETSTATE, prtmd);
		write(1, &inbuf[4], (strlen(&inbuf[4])+1) & ~1);
		write(1, "\n", 2);
E 7
I 7
		ioctl(OUT, VSETSTATE, prtmd);
		write(OUT, &inbuf[4], (strlen(&inbuf[4])+1) & ~1);
		write(OUT, "\n", 2);
E 7
	} else				/* dump file not formatted */
D 7
		lseek(0, 0L, 0);	/* reset in's seek pointer and plot */
E 7
I 7
		lseek(IN, 0L, 0);	/* reset in's seek pointer and plot */
E 7

	n = putplot();

	/* page feed */
D 7
	ioctl(1, VSETSTATE, prtmd);
	if (varian) 
		write(1, "\f", 2);
E 7
I 7
	ioctl(OUT, VSETSTATE, prtmd);
	if (varian)
		write(OUT, "\f", 2);
E 7
	else
D 7
		write(1, "\n\n\n\n\n", 6);
E 7
I 7
		write(OUT, "\n\n\n\n\n", 6);
E 7
	account(name, host, acctfile);
D 7
	exit(n != 0);
E 7
I 7
	exit(n);
E 7
}

E 5
putplot()
{
D 2
     int i;
E 2
I 2
D 5
     register int i;
     register char *buf;
E 5
I 5
D 7
	register char *buf;
	register int i, n;
E 7
I 7
	register char *cp;
	register int bytes, n;
E 7
E 5
E 2

I 2
D 5
     buf = &(vpbuf[0]);
E 2
     /* vpd has already opened the Versatec as device 3 */
     ioctl(3, VSETSTATE, plotmd);
D 2
     while( (i=read(in,vpbuf, BUFSIZE)) > 0)
		write(3,vpbuf,i);
E 2
I 2
     while( (i=read(in,buf, BUFSIZE)) > 0)
D 3
		write(3,buf,i);
E 3
I 3
		if(write(3,buf,i)!=i) exit(1);
E 3
E 2
    }
E 5
I 5
D 7
	n = 0;
	buf = vpbuf;
	ioctl(1, VSETSTATE, plotmd);
	while ((i = read(0, buf, BUFSIZE)) > 0)
		if (write(1, buf, i) != i) {
			i = -1;
			break;
		} else
			n += BUFSIZE;
D 6
	lines += n / BytesPerLine;
E 6
I 6
	lines += n / BYTES_PER_LINE;
E 6
	return(i);
E 7
I 7
	cp = buf;
	bytes = 0;
	ioctl(OUT, VSETSTATE, plotmd);
	while ((n = read(IN, cp, sizeof(buf))) > 0) {
		if (write(OUT, cp, n) != n)
			return(1);
		bytes += n;
	}
	/*
	 * Make sure we send complete raster lines.
	 */
	if ((n = bytes % BYTES_PER_LINE) > 0) {
		n = BYTES_PER_LINE - n;
		for (cp = &buf[n]; cp > buf; )
			*--cp = 0;
		if (write(OUT, cp, n) != n)
			return(1);
		bytes += n;
	}
	lines += bytes / BYTES_PER_LINE;
	return(0);
E 7
}

account(who, from, acctfile)
	char *who, *from, *acctfile;
{
	register FILE *a;

	if (who == NULL || acctfile == NULL)
		return;
	if (access(acctfile, 02) || (a = fopen(acctfile, "a")) == NULL)
		return;
	/*
D 7
	 * Varian accounting is done by 11 inch pages;
E 7
I 7
	 * Varian accounting is done by 8.5 inch pages;
E 7
	 * Versatec accounting is by the (12 inch) foot.
	 */
D 6
	fprintf(a, "t%6.2f\t", (lines / 200.0) / (varian ? 11.0 : 12.0));
E 6
I 6
D 8
	fprintf(a, "t%6.2f\t", (lines / 200.0) / PAGE_LINES);
E 8
I 8
	fprintf(a, "t%6.2f\t", (double)lines / (double)PAGE_LINES);
E 8
E 6
	if (from != NULL)
		fprintf(a, "%s:", from);
	fprintf(a, "%s\n", who);
	fclose(a);
}
E 5
E 1

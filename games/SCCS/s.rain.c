h39761
s 00010/00005/00218
d D 5.4 88/06/27 16:35:19 bostic 6 5
c install approved copyright notice
e
s 00183/00146/00040
d D 5.3 88/01/02 19:38:11 bostic 5 3
c reformat; lint clean-ups, ANSI C cleanups, remove float operations 
c check malloc results, only ignore relevant signals
e
s 00178/00146/00040
d R 5.3 88/01/02 19:22:09 bostic 4 3
c reformat; lint clean-ups, ANSI C cleanups, remove float operations 
c check malloc results, only ignore relevant signals
e
s 00067/00022/00119
d D 5.2 85/07/15 18:17:34 mckusick 3 2
c more terminal/system independent (from sun!guy Guy Harris)
e
s 00014/00001/00127
d D 5.1 85/05/29 11:24:26 dist 2 1
c Add copyright
e
s 00128/00000/00000
d D 4.1 82/10/24 18:26:54 mckusick 1 0
c date and time created 82/10/24 18:26:54 by mckusick
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */
E 2
I 1

D 2
static char sccsid[] = "	%M%	%I%	%E%	";
E 2
I 2
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 2

I 3
D 5
#define BSD
E 5
I 5
/*
 * rain 11/3/1980 EPS/CITHEP
 * cc rain.c -o rain -O -ltermlib
 */
E 5

I 5
#include <sys/types.h>
E 5
E 3
#include <stdio.h>
I 3
#ifdef USG
#include <termio.h>
#else
E 3
#include <sgtty.h>
I 3
#endif
E 3
#include <signal.h>
D 5
/* rain 11/3/1980 EPS/CITHEP */
/* cc rain.c -o rain -O -ltermlib */
D 3
#define cursor(col,row) tputs(tgoto(CM,col,row),1,outc)
outc(c)
{
	putchar(c);
}
E 3
I 3
#define cursor(col,row) tputs(tgoto(CM,col,row),1,fputchar)
E 3
extern char *UP;
extern short ospeed;
E 5
I 5

#define	cursor(c, r)	tputs(tgoto(CM, c, r), 1, fputchar)

E 5
I 3
#ifdef USG
D 5
struct termio old_tty;
E 5
I 5
static struct termio sg, old_tty;
E 5
#else
E 3
D 5
struct sgttyb old_tty;
E 5
I 5
static struct sgttyb sg, old_tty;
E 5
I 3
#endif
E 3
D 5
char *LL, *TE, *TI;
main(argc,argv)
int argc;
char *argv[];
E 5
I 5

int	fputchar();
char	*LL, *TE, *tgoto();

main(argc, argv)
	int argc;
	char **argv;
E 5
{
D 5
    extern fputchar();
    char *malloc();
    char *getenv();
    char *tgetstr(), *tgoto();
    float ranf();
    int onsig();
    register int x, y, j;
    static int xpos[5], ypos[5];
    register char *CM, *BC, *DN, *ND;
I 3
    int CO, LI;
E 3
    char *tcp;
    register char *term;
    char tcb[100];
I 3
#ifdef USG
    struct termio sg;
#else
E 3
    struct sgttyb sg;
I 3
#endif
    float cols, lines;
E 5
I 5
	extern short ospeed;
	extern char *UP;
	register int x, y, j;
	register char *CM, *BC, *DN, *ND, *term;
	char *TI, *tcp, *mp, tcb[100],
		*malloc(), *getenv(), *strcpy(), *tgetstr();
	long cols, lines, random();
	int xpos[5], ypos[5], onsig();
E 5

E 3
D 5
    setbuf(stdout,malloc(BUFSIZ));
    if (!(term=getenv("TERM"))) {
	fprintf(stderr,"%s: TERM: parameter not set\n",*argv);
	exit(1);
    }
    if (tgetent(malloc(1024),term)<=0) {
	fprintf(stderr,"%s: %s: unknown terminal type\n",*argv,term);
	exit(1);
    }
    tcp=tcb;
    if (!(CM=tgetstr("cm",&tcp))) {
	fprintf(stderr,"%s: terminal not capable of cursor motion\n",*argv);
	exit(1);
    }
    if (!(BC=tgetstr("bc",&tcp))) BC="\b";
    if (!(DN=tgetstr("dn",&tcp))) DN="\n";
    if (!(ND=tgetstr("nd",&tcp))) ND=" ";
I 3
    if ((CO = tgetnum("co")) == -1)
	CO = 80; 
    if ((LI = tgetnum("li")) == -1)
	LI = 24; 
    cols = CO - 4;
    lines = LI - 4;
E 3
    TE=tgetstr("te",&tcp);
    TI=tgetstr("ti",&tcp);
    UP=tgetstr("up",&tcp);
    if (!(LL=tgetstr("ll",&tcp))) strcpy(LL=malloc(10),tgoto(CM,0,23));
E 5
I 5
	if (!(term = getenv("TERM"))) {
		fprintf(stderr, "%s: TERM: parameter not set\n", *argv);
		exit(1);
	}
	if (!(mp = malloc((u_int)1024))) {
		fprintf(stderr, "%s: out of space.\n", *argv);
		exit(1);
	}
	if (tgetent(mp, term) <= 0) {
		fprintf(stderr, "%s: %s: unknown terminal type\n", *argv, term);
		exit(1);
	}
	tcp = tcb;
	if (!(CM = tgetstr("cm", &tcp))) {
		fprintf(stderr, "%s: terminal not capable of cursor motion\n", *argv);
		exit(1);
	}
	if (!(BC = tgetstr("bc", &tcp)))
		BC = "\b";
	if (!(DN = tgetstr("dn", &tcp)))
		DN = "\n";
	if (!(ND = tgetstr("nd", &tcp)))
		ND = " ";
	if ((cols = tgetnum("co")) == -1)
		cols = 80;
	if ((lines = tgetnum("li")) == -1)
		lines = 24;
	cols -= 4;
	lines -= 4;
	TE = tgetstr("te", &tcp);
	TI = tgetstr("ti", &tcp);
	UP = tgetstr("up", &tcp);
	if (!(LL = tgetstr("ll", &tcp))) {
		if (!(LL = malloc((u_int)10))) {
			fprintf(stderr, "%s: out of space.\n", *argv);
			exit(1);
		}
		(void)strcpy(LL, tgoto(CM, 0, 23));
	}
E 5
I 3
#ifdef USG
D 5
    ioctl(1, TCGETA, &sg);
    ospeed=sg.c_cflag&CBAUD;
E 5
I 5
	ioctl(1, TCGETA, &sg);
	ospeed = sg.c_cflag&CBAUD;
E 5
#else
E 3
D 5
    gtty(1, &sg);
    ospeed=sg.sg_ospeed;
E 5
I 5
	gtty(1, &sg);
	ospeed = sg.sg_ospeed;
E 5
I 3
#endif
E 3
D 5
    for (j=SIGHUP;j<=SIGTERM;j++)
	if (signal(j,SIG_IGN)!=SIG_IGN) signal(j,onsig);
E 5
I 5
	(void)signal(SIGHUP, onsig);
	(void)signal(SIGINT, onsig);
	(void)signal(SIGQUIT, onsig);
	(void)signal(SIGSTOP, onsig);
	(void)signal(SIGTSTP, onsig);
	(void)signal(SIGTERM, onsig);
E 5
I 3
#ifdef USG
D 5
    ioctl(1, TCGETA, &old_tty);	/* save tty bits for exit */
    ioctl(1, TCGETA, &sg);
    sg.c_iflag&=~ICRNL;
    sg.c_oflag&=~ONLCR;
    sg.c_lflag&=~ECHO;
    ioctl(1, TCSETAW, &sg);
E 5
I 5
	ioctl(1, TCGETA, &old_tty);	/* save tty bits for exit */
	ioctl(1, TCGETA, &sg);
	sg.c_iflag &= ~ICRNL;
	sg.c_oflag &= ~ONLCR;
	sg.c_lflag &= ~ECHO;
	ioctl(1, TCSETAW, &sg);
E 5
#else
E 3
D 5
    gtty(1, &old_tty);	/* save tty bits for exit */
    gtty(1, &sg);
    sg.sg_flags&=~(CRMOD|ECHO);
    stty(1, &sg);
E 5
I 5
	gtty(1, &old_tty);		/* save tty bits for exit */
	gtty(1, &sg);
	sg.sg_flags &= ~(CRMOD|ECHO);
	stty(1, &sg);
E 5
D 3
    if (TI) fputs(TI,stdout);
E 3
I 3
#endif
D 5
    if (TI) tputs(TI,1,fputchar);
E 3
    tputs(tgetstr("cl",&tcp),1,fputchar);
    fflush(stdout);
    for (j=5;--j>=0;) {
D 3
	xpos[j]=(int)(76.*ranf())+2;
	ypos[j]=(int)(20.*ranf())+2;
E 3
I 3
	xpos[j]=(int)(cols*ranf())+2;
	ypos[j]=(int)(lines*ranf())+2;
E 3
    }
    for (j=0;;) {
D 3
	x=(int)(76.*ranf())+2;
	y=(int)(20.*ranf())+2;
E 3
I 3
	x=(int)(cols*ranf())+2;
	y=(int)(lines*ranf())+2;
E 3
	cursor(x,y); fputchar('.');
	cursor(xpos[j],ypos[j]); fputchar('o');
	if (j==0) j=4; else --j;
	cursor(xpos[j],ypos[j]); fputchar('O');
	if (j==0) j=4; else --j;
	cursor(xpos[j],ypos[j]-1);
	fputchar('-');
D 3
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
E 3
I 3
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
E 3
	fputs("|.|",stdout);
D 3
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
E 3
I 3
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
E 3
	fputchar('-');
	if (j==0) j=4; else --j;
	cursor(xpos[j],ypos[j]-2); fputchar('-');
D 3
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
E 3
I 3
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
E 3
	fputs("/ \\",stdout);
	cursor(xpos[j]-2,ypos[j]);
	fputs("| O |",stdout);
	cursor(xpos[j]-1,ypos[j]+1);
	fputs("\\ /",stdout);
D 3
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
E 3
I 3
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
E 3
	fputchar('-');
	if (j==0) j=4; else --j;
	cursor(xpos[j],ypos[j]-2); fputchar(' ');
D 3
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
	fputchar(' '); fputs(ND,stdout); fputchar(' ');
E 3
I 3
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
	fputchar(' '); tputs(ND,1,fputchar); fputchar(' ');
E 3
	cursor(xpos[j]-2,ypos[j]);
D 3
	fputchar(' '); fputs(ND,stdout); fputchar(' ');
	fputs(ND,stdout); fputchar(' ');
E 3
I 3
	fputchar(' '); tputs(ND,1,fputchar); fputchar(' ');
	tputs(ND,1,fputchar); fputchar(' ');
E 3
	cursor(xpos[j]-1,ypos[j]+1);
D 3
	fputchar(' '); fputs(ND,stdout); fputchar(' ');
	fputs(DN,stdout); fputs(BC,stdout); fputs(BC,stdout);
E 3
I 3
	fputchar(' '); tputs(ND,1,fputchar); fputchar(' ');
	tputs(DN,1,fputchar); tputs(BC,1,fputchar); tputs(BC,1,fputchar);
E 3
	fputchar(' ');
	xpos[j]=x; ypos[j]=y;
	fflush(stdout);
    }
E 5
I 5
	if (TI)
		tputs(TI, 1, fputchar);
	tputs(tgetstr("cl", &tcp), 1, fputchar);
	(void)fflush(stdout);
	for (j = 4; j >= 0; --j) {
		xpos[j] = random() % cols + 2;
		ypos[j] = random() % lines + 2;
	}
	for (j = 0;;) {
		x = random() % cols + 2;
		y = random() % lines + 2;
		cursor(x, y);
		fputchar('.');
		cursor(xpos[j], ypos[j]);
		fputchar('o');
		if (!j--)
			j = 4;
		cursor(xpos[j], ypos[j]);
		fputchar('O');
		if (!j--)
			j = 4;
		cursor(xpos[j], ypos[j] - 1);
		fputchar('-');
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputs("|.|", stdout);
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputchar('-');
		if (!j--)
			j = 4;
		cursor(xpos[j], ypos[j] - 2);
		fputchar('-');
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputs("/ \\", stdout);
		cursor(xpos[j] - 2, ypos[j]);
		fputs("| O |", stdout);
		cursor(xpos[j] - 1, ypos[j] + 1);
		fputs("\\ /", stdout);
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputchar('-');
		if (!j--)
			j = 4;
		cursor(xpos[j], ypos[j] - 2);
		fputchar(' ');
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputchar(' ');
		tputs(ND, 1, fputchar);
		fputchar(' ');
		cursor(xpos[j] - 2, ypos[j]);
		fputchar(' ');
		tputs(ND, 1, fputchar);
		fputchar(' ');
		tputs(ND, 1, fputchar);
		fputchar(' ');
		cursor(xpos[j] - 1, ypos[j] + 1);
		fputchar(' ');
		tputs(ND, 1, fputchar);
		fputchar(' ');
		tputs(DN, 1, fputchar);
		tputs(BC, 1, fputchar);
		tputs(BC, 1, fputchar);
		fputchar(' ');
		xpos[j] = x;
		ypos[j] = y;
		(void)fflush(stdout);
	}
E 5
}
D 5
onsig(n)
int n;
E 5
I 5

static
onsig()
E 5
{
I 5
	tputs(LL, 1, fputchar);
	if (TE)
		tputs(TE, 1, fputchar);
	(void)fflush(stdout);
E 5
I 3
#ifdef USG
D 5
    struct termio sg;
E 5
I 5
	ioctl(1, TCSETAW, &old_tty);
E 5
#else
E 3
D 5
    struct sgttyb sg;
E 5
I 5
	stty(1, &old_tty);
E 5
D 3
    fputs(LL, stdout);
    if (TE) fputs(TE, stdout);
E 3
I 3
#endif
D 5
    tputs(LL, 1, fputchar);
    if (TE) tputs(TE, 1, fputchar);
E 3
    fflush(stdout);
I 3
#ifdef USG
    ioctl(1, TCSETAW, &old_tty);
#else
E 3
    stty(1, &old_tty);
I 3
#endif
E 3
    kill(getpid(),n);
    _exit(0);
E 5
I 5
	exit(0);
E 5
}
I 5

static
E 5
fputchar(c)
D 5
char c;
E 5
I 5
	char c;
E 5
{
D 5
    putchar(c);
}
float ranf() {
I 3
#ifdef BSD
E 3
    return((float)rand()/2147483647.);
I 3
#else
    return((float)rand()/32767.);
#endif
E 5
I 5
	putchar(c);
E 5
E 3
}
E 1

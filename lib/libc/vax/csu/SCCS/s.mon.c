h05459
s 00002/00002/00171
d D 5.3 86/03/09 21:02:41 donn 14 13
c added LIBC_SCCS condition for sccs ids
e
s 00000/00004/00173
d D 5.2 85/06/21 16:55:11 mckusick 13 12
c get rid of incorrect lint defs
e
s 00009/00001/00168
d D 5.1 85/05/30 14:55:56 dist 12 11
c Add copyright
e
s 00004/00025/00165
d D 4.9 83/07/26 01:00:12 mckusick 11 10
c get rid of special case brk(); integrate into standard brk()
e
s 00001/00001/00189
d D 4.8 83/04/20 15:23:48 mckusick 10 9
c start monitoring in ``monitor''
e
s 00039/00016/00151
d D 4.7 83/03/30 18:44:27 peter 9 8
c add moncontrol(); make it work!
e
s 00005/00002/00162
d D 4.6 83/03/01 22:28:45 mckusick 8 7
c insure that monitor always rounds memory requests up to even values
e
s 00035/00012/00129
d D 4.5 82/12/10 17:10:28 peter 7 6
c use ex scripts instead of /lib/cpp.
e
s 00001/00001/00140
d D 4.4 82/12/04 16:52:05 mckusick 6 5
c use 1/2 text space for count buffers - unique since functions are aligned long
e
s 00001/00077/00140
d D 4.3 82/12/04 16:15:10 mckusick 5 4
c break out "monitor" into separate file for jkf
e
s 00003/00002/00214
d D 4.2 82/05/19 10:06:33 rrh 4 3
c old versions; put these to bed
e
s 00000/00000/00216
d D 4.1 81/11/29 23:32:45 mckusic 3 2
c renumber to version 4
e
s 00000/00004/00216
d D 1.2 81/11/29 17:20:12 mckusic 2 1
c fix comments
e
s 00220/00000/00000
d D 1.1 81/11/29 16:15:19 mckusick 1 0
c date and time created 81/11/29 16:15:19 by mckusick
e
u
U
t
T
I 1
D 12
static	char *sccsid = "%W% (Berkeley) %G%";
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 14
#ifndef lint
E 14
I 14
#if defined(LIBC_SCCS) && !defined(lint)
E 14
static char sccsid[] = "%W% (Berkeley) %G%";
D 14
#endif not lint
E 14
I 14
#endif LIBC_SCCS and not lint
E 14
E 12

D 2
#ifdef DEBUG
#include <stdio.h>
#endif DEBUG

E 2
D 7
#define DENSITY 5	/* density of routines */
#define MINCNT  50	/* minimum number of counters */
E 7
I 7
#define ARCDENSITY	5	/* density of routines */
#define MINARCS		50	/* minimum number of counters */
I 8
#define	HISTFRACTION	2	/* fraction of text space for histograms */
E 8
E 7

I 8

E 8
struct phdr {
	int *lpc;
	int *hpc;
	int ncnt;
};

struct cnt {
	int *pc;
	long ncall;
} *countbase;

I 9
static int cntrs = 0;
static int profiling = 3;
static char *s_sbuf;
static int s_bufsiz;
static int s_scale;
static char *s_lowpc;

E 9
int numctrs;

I 7
D 11
static char		*minsbrk = 0;

E 11
E 7
D 5
/*
 *	C start up routines, for monitoring
 *	Robert Henry, UCB, 20 Oct 81
 *
 *	We make the following (true) assumptions:
 *	1) when the kernel calls start, it does a jump to location 2,
 *	and thus avoids the register save mask.  We are NOT called
 *	with a calls!  see sys1.c:setregs().
 *	2) The only register variable that we can trust is sp,
 *	which points to the base of the kernel calling frame.
 *	Do NOT believe the documentation in exec(2) regarding the
 *	values of fp and ap.
 *	3) We can allocate as many register variables as we want,
 *	and don't have to save them for anybody.
 *	4) Because of the ways that asm's work, we can't have
 *	any automatic variables allocated on the stack, because
 *	we must catch the value of sp before any automatics are
 *	allocated.
 */

char **environ;

/*
 *	etext is added by the loader, and is the end of the text space.
 *	eprol is a local symbol, and labels almost the beginning of text space.
 *	    its name is changed so it doesn't look like a function.
 */

extern	unsigned char	etext;
extern	unsigned char	eprol;
asm( "#define _eprol _$eprol" );

asm( "#define _start start" );
start()
{
	struct kframe {
		int	kargc;
		char	*kargv[1];	/* size depends on kargc */
		char	kargstr[1];	/* size varies */
		char	kenvstr[1];	/* size varies */
	};
	/*
	 *	ALL REGISTER VARIABLES!!!
	 */
D 4
	register struct kframe *kfp;	/* r11 */
E 4
I 4
	register int r11;		/* needed by init */
	register struct kframe *kfp;	/* r10 */
E 4
	register char **targv;
	register char **argv;

#ifdef lint
	kfp = 0;
#else not lint
D 4
	asm("	movl	sp,r11");	/* catch it quick */
E 4
I 4
	asm("	movl	sp,r10");	/* catch it quick */
E 4
#endif not lint
	for (argv = targv = &kfp->kargv[0]; *targv++; /* void */)
		/* void */ ;
	if (targv >= (char **)(*argv))
		--targv;
	environ = targv;
asm("_eprol:");
	_mstartup(&eprol, &etext);
	exit(main(kfp->kargc, argv, environ));
}
asm("#undef _start");
asm("#undef _eprol");

exit(code)
	/* ARGSUSED */
	register int code;	/* r11 */
{
	monitor(0);
	_cleanup();
	asm("	movl r11,r0");
	asm("	chmk $1");
}

E 5
#define	MSG "No space for monitor buffer(s)\n"

D 5
_mstartup(lowpc, highpc)
E 5
I 5
monstartup(lowpc, highpc)
E 5
	char *lowpc;
	char *highpc;
{
	int monsize;
	char *buffer;
	int cntsiz;
D 11
	char *sbrk();
E 11
I 11
	extern char *sbrk();
	extern char *minbrk;
E 11

I 11

E 11
D 7
	cntsiz = (highpc - lowpc) * DENSITY / 100;
	if (cntsiz < MINCNT)
		cntsiz = MINCNT;
E 7
I 7
	cntsiz = (highpc - lowpc) * ARCDENSITY / 100;
	if (cntsiz < MINARCS)
		cntsiz = MINARCS;
E 7
D 6
	monsize = highpc - lowpc + sizeof(struct phdr) +
E 6
I 6
D 8
	monsize = (highpc - lowpc + 1) / 2 + sizeof(struct phdr) +
E 6
		  cntsiz * sizeof(struct cnt);
E 8
I 8
	monsize = (highpc - lowpc + HISTFRACTION - 1) / HISTFRACTION
		+ sizeof(struct phdr) + cntsiz * sizeof(struct cnt);
	monsize = (monsize + 1) & ~1;
E 8
	buffer = sbrk(monsize);
	if (buffer == (char *)-1) {
		write(2, MSG, sizeof(MSG));
		return;
	}
I 7
D 11
	minsbrk = sbrk(0);
E 11
I 11
	minbrk = sbrk(0);
E 11
E 7
	monitor(lowpc, highpc, buffer, monsize, cntsiz);
I 9
D 10
	moncontrol(1);
E 10
E 9
}

/*
 *	This routine is massaged so that it may be jsb'ed to
 */
D 7
asm("#define _mcount mcount");
E 7
I 7
asm(".text");
asm("#the beginning of mcount()");
asm(".data");
E 7
mcount()
{
	register int *selfpc;	/* r11 */
	register long **cntp;   /* r10 */
D 9
	static int profiling = 0;
	static int cntrs = 0;
E 9

D 7
	asm("	forgot to run ex script on gcrt0.s" );
	asm("#define r11 r5");
	asm("#define r10 r4");
E 7
D 13
#ifdef lint
	selfpc = (int *) 0;
#else not lint
E 13
	/*
	 * find the return address for mcount,
	 * and address of counter pointer
	 */
	asm("	movl	(sp),r11");	/* selfpc = ... (jsb frame) */
	asm("	movl	r0,r10");	/* address of count local */
D 13
#endif not lint
E 13
	/*
I 9
	 * check that we aren't recursively invoked.
	 */
	if (profiling)
		goto out;
	profiling++;
	/*
E 9
	 * check that counter is allocated
	 */
	if (*cntp == 0) {
		/*
D 9
		 * check that we are profiling
		 */
		if (countbase == 0)
			goto out;
		/*
		 * and that we aren't recursively invoked.
		 */
		if (profiling)
			goto out;
		/*
E 9
		 * check that a counter is available
		 */
		if (cntrs++ == numctrs)
			goto overflow;
D 9
		profiling = 1;
E 9
		countbase->pc = selfpc;
		*cntp = &countbase->ncall;
		countbase++;
D 9
		profiling = 0;
E 9
	}
	(**cntp)++;
I 9
	profiling--;
E 9
out:
	asm( "	rsb" );
D 7
	asm( "#undef r11" );
	asm( "#undef r10" );
	asm( "#undef _mcount");
E 7

overflow:
#   define	TOLIMIT	"mcount: counter overflow\n"
	write( 2 , TOLIMIT , sizeof( TOLIMIT ) );
	goto out;
}
I 7
asm(".text");
asm("#the end of mcount()");
asm(".data");
E 7

monitor(lowpc, highpc, buf, bufsiz, cntsiz)
	char *lowpc, *highpc;
	char *buf;
	int bufsiz, cntsiz;
{
	register int o;
	struct phdr *php;
	static int ssiz;
	static char *sbuf;

	if (lowpc == 0) {
D 9
		profil(0, 0, 0, 0);
E 9
I 9
		moncontrol(0);
E 9
		o = creat("mon.out", 0666);
		write(o, sbuf, ssiz);
		close(o);
		return;
	}
	sbuf = buf;
	ssiz = bufsiz;
	php = (struct phdr *)&buf[0];
	php->lpc = (int *)lowpc;
	php->hpc = (int *)highpc;
	php->ncnt = cntsiz;
	numctrs = cntsiz;
	countbase = (struct cnt *)(buf + sizeof(struct phdr));
	o = sizeof(struct phdr) + cntsiz * sizeof(struct cnt);
	buf += o;
	bufsiz -= o;
	if (bufsiz <= 0)
		return;
	o = (highpc - lowpc);
	if(bufsiz < o)
		o = ((float) bufsiz / o) * 65536;
	else
		o = 65536;
D 9
	profil(buf, bufsiz, lowpc, o);
E 9
I 9
	s_scale = o;
	s_sbuf = buf;
	s_bufsiz = bufsiz;
	s_lowpc = lowpc;
I 10
	moncontrol(1);
E 10
}

/*
 * Control profiling
 *	profiling is what mcount checks to see if
 *	all the data structures are ready.
 */
moncontrol(mode)
    int mode;
{
    if (mode) {
	/* start */
	profil(s_sbuf, s_bufsiz, s_lowpc, s_scale);
	profiling = 0;
    } else {
	/* stop */
	profil((char *)0, 0, 0, 0);
	profiling = 3;
    }
E 9
I 7
D 11
}

/*
 * This is a stub for the "brk" system call, which we want to
 * catch so that it will not deallocate our data space.
 * (of which the program is not aware)
 */
extern char *curbrk;

brk(addr)
	char *addr;
{

	if (addr < minsbrk)
		addr = minsbrk;
	asm("	chmk	$17");
	asm("	jcc	1f");
	asm("	jmp	cerror");
asm("1:");
	curbrk = addr;
	return (0);
E 11
E 7
}
E 1

h02878
s 00004/00004/00293
d D 5.4 87/08/27 09:11:44 mckusick 25 24
c avoid writing out null's in error messages (4.3BSD/lib/80, adam@gec-mi-at.co.uk)
e
s 00002/00002/00295
d D 5.3 86/03/09 21:02:09 donn 24 23
c added LIBC_SCCS condition for sccs ids
e
s 00000/00005/00297
d D 5.2 85/06/21 16:55:17 mckusick 23 22
c get rid of incorrect lint defs
e
s 00009/00001/00293
d D 5.1 85/05/30 14:55:13 dist 22 21
c Add copyright
e
s 00002/00023/00292
d D 4.13 83/07/26 00:59:40 mckusick 21 20
c get rid of special case brk(); integrate into standard brk()
e
s 00009/00010/00306
d D 4.12 83/04/20 15:23:49 peter 20 19
c mostly fixing a bug with adding to an (int *);
c but also cleaning up some dead code, extra calls to moncontrol(), etc.
e
s 00026/00008/00290
d D 4.11 83/03/30 17:22:17 peter 19 18
c add moncontrol() to provide finer control over profiling
e
s 00014/00018/00284
d D 4.10 83/01/14 13:58:51 mckusick 18 17
c speed-ups and clean-ups
e
s 00006/00004/00296
d D 4.9 83/01/13 18:59:32 mckusick 17 16
c get rid of roundup of hash bucket hit; add HASHFRACTION
e
s 00116/00069/00184
d D 4.8 82/12/10 17:09:38 peter 16 15
c self organizing linked lists.
e
s 00001/00001/00252
d D 4.7 82/12/04 16:52:10 mckusick 15 14
c use 1/2 text space for count buffers - unique since functions are aligned long
e
s 00008/00003/00245
d D 4.6 82/12/04 16:42:25 mckusick 14 13
c base number of counters on DENSITY; use ~20% of textsize
e
s 00010/00082/00238
d D 4.5 82/12/04 16:15:32 mckusick 13 12
c break out "monitor" into separate file for jkf
e
s 00003/00002/00317
d D 4.4 82/05/19 10:06:24 rrh 12 11
c old versions; put these to bed
e
s 00014/00004/00305
d D 4.3 82/03/18 19:13:46 mckusick 11 10
c only allow ``brk'' back to beginning of monitor data area
e
s 00011/00000/00298
d D 4.2 82/03/13 19:56:10 mckusick 10 9
c define a null stub for ``brk'' to prevent dealloaction of gprof's data area
e
s 00000/00000/00298
d D 4.1 81/11/29 23:32:25 mckusic 9 8
c renumber to version 4
e
s 00003/00003/00295
d D 1.8 81/11/25 10:00:15 mckusic 8 7
c 65535 is not ~= 65536 for text sizes >= 65536. (scale factor to profil)
e
s 00017/00014/00281
d D 1.7 81/11/12 14:48:16 mckusic 7 6
c "gmcrt0" becomes "gcrt0"; eliminate stdio in gcrt0.c
e
s 00022/00017/00273
d D 1.6 81/11/10 14:45:33 peter 6 5
c use tolimit for data structure initialization checks;
c some speedups in mcount;
c better recovery in the face of running out of tos[] space.
e
s 00007/00002/00283
d D 1.5 81/11/10 13:21:45 peter 5 4
c _eprol renamed _$eprol so it looks like the label it is.
e
s 00002/00001/00283
d D 1.4 81/11/06 17:22:08 peter 4 3
c addresses should be printed in hex.
e
s 00150/00090/00134
d D 1.3 81/10/20 15:51:34 peter 3 2
c robert makes start() succumb; with help.
e
s 00023/00012/00201
d D 1.2 81/10/17 22:01:10 peter 2 1
c watch for signal catchers, and recursive invokations therefrom.
e
s 00213/00000/00000
d D 1.1 81/10/15 13:47:11 peter 1 0
c date and time created 81/10/15 13:47:11 by peter
e
u
U
t
T
I 1
D 22
static	char *sccsid = "%W% (Berkeley) %G%";
E 22
I 22
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 24
#ifndef lint
E 24
I 24
#if defined(LIBC_SCCS) && !defined(lint)
E 24
static char sccsid[] = "%W% (Berkeley) %G%";
D 24
#endif not lint
E 24
I 24
#endif LIBC_SCCS and not lint
E 24
E 22

I 7
#ifdef DEBUG
E 7
#include <stdio.h>
I 7
#endif DEBUG
E 7

D 3
#include "monitor.h"
E 3
I 3
D 7
#include "gmcrt0.h"
E 7
I 7
D 13
#include "gcrt0.h"
E 13
I 13
#include "gmon.h"
E 13
E 7
E 3

D 3
    /*	froms is actually a bunch of unsigned shorts indexing tos */
E 3
I 3
    /*
D 13
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
I 5
    /*
     *	etext is added by the loader, and is the end of the text space.
     *	eprol is a local symbol, and labels almost the beginning of text space.
     *	    its name is changed so it doesn't look like a function.
     */
E 5
extern	unsigned char	etext;
D 5
asm( "#define _eprol eprol" );
E 5
extern	unsigned char	eprol;
I 5
asm( "#define _eprol _$eprol" );
E 5

asm( "#define _start start" );
start()
{
    struct kframe {
	int	kargc;
	char	*kargv[1];		/* size depends on kargc */
	char	kargstr[1];		/* size varies */
	char	kenvstr[1];		/* size varies */
    };
	/*
	 *	ALL REGISTER VARIABLES!!!
	 */
D 12
    register struct kframe	*kfp;		/* r11 */
E 12
I 12
    register int		r11;		/* init needs r11 */
    register struct kframe	*kfp;		/* r10 */
E 12
    register char		**targv;
    register char		**argv;

#ifdef lint
    kfp = 0;
#else not lint
D 12
    asm( "	movl	sp,r11" );		/* catch it quick */
E 12
I 12
    asm( "	movl	sp,r10" );		/* catch it quick */
E 12
#endif not lint
    for ( argv = targv = &kfp -> kargv[0] ; *targv++ ; /* void */ )
	/* VOID */ ;
    if ( targv >= (char **) ( *argv ) )
	--targv;
    environ = targv;
D 5
asm("eprol:");
E 5
I 5
asm("_eprol:");
E 5
    _mstartup( &eprol , &etext );
    exit( main( kfp -> kargc , argv , environ ) );
}
asm( "#undef _start" );
asm( "#undef _eprol" );

exit( code )
	/* ARGSUSED */
    register int	code;	/* r11 */
{

D 7
    fflush( stdout );
E 7
    _mcleanup();
    _cleanup();
    asm( "	movl r11, r0" );
    asm( "	chmk $1" );
}

    /*
E 13
     *	froms is actually a bunch of unsigned shorts indexing tos
     */
I 18
static int		profiling = 3;
E 18
E 3
static unsigned short	*froms;
static struct tostruct	*tos = 0;
D 16
static unsigned short	tolimit = 0;
E 16
I 16
static long		tolimit = 0;
E 16
static char		*s_lowpc = 0;
static char		*s_highpc = 0;
I 6
static unsigned long	s_textsize = 0;
I 11
D 21
static char		*minsbrk = 0;
E 21
E 11
E 6

D 3
static	int	ssiz;
static	int	*sbuf;
E 3
I 3
static int	ssiz;
D 20
static int	*sbuf;
E 20
I 20
static char	*sbuf;
E 20
I 19
static int	s_scale;
I 20
    /* see profil(2) where this is describe (incorrectly) */
#define		SCALE_1_TO_1	0x10000L
E 20
E 19
E 3

D 3
char	*sbrk();
E 3
#define	MSG "No space for monitor buffer(s)\n"

D 3
	/*ARGSUSED*/
exit(code)
	register int	code;
{
	fflush(stdout);
	_mcleanup();
	_cleanup();
#ifdef lint
	code = code;
#endif lint
	asm("	movl r11, r0");
	asm("	chmk $1");
}

E 3
D 13
_mstartup(lowpc, highpc)
E 13
I 13
monstartup(lowpc, highpc)
E 13
D 3
	char	*lowpc;
	char	*highpc;
E 3
I 3
    char	*lowpc;
    char	*highpc;
E 3
{
D 3
	int	monsize;
	char	*buffer;
	int	textsize;
E 3
I 3
D 6
    int		monsize;
    char	*buffer;
    int		textsize;
    char	*sbrk();
E 6
I 6
    int			monsize;
    char		*buffer;
    char		*sbrk();
I 21
    extern char		*minbrk;
E 21
D 18
    unsigned long	limit;
E 18
E 6
E 3

I 16
	/*
	 *	round lowpc and highpc to multiples of the density we're using
	 *	so the rest of the scaling (here and in gprof) stays in ints.
	 */
    lowpc = (char *)
	    ROUNDDOWN((unsigned)lowpc, HISTFRACTION*sizeof(HISTCOUNTER));
E 16
D 3
	s_lowpc = lowpc;
	s_highpc = highpc;
	textsize = ((char *)highpc - (char *)lowpc);
	monsize = textsize + sizeof(struct phdr);
	buffer = sbrk(monsize);
	if ( buffer == (char *) -1 ) {
	    write(2, MSG, sizeof(MSG));
	    return;
	}
	froms = (unsigned short *) sbrk(textsize);
	if ( froms == (unsigned short *) -1 ) {
	    write(2 , MSG , sizeof(MSG) );
	    froms = 0;
	    return;
	}
	tos = (struct tostruct *) sbrk(textsize);
	if ( tos == (struct tostruct *) -1 ) {
	    write(2 , MSG , sizeof(MSG) );
	    froms = 0;
	    tos = 0;
	    return;
	}
	tolimit = textsize / sizeof(struct tostruct);
	tos[0].link = 0;
	monitor(lowpc, highpc, buffer, monsize);
E 3
I 3
    s_lowpc = lowpc;
I 16
    highpc = (char *)
	    ROUNDUP((unsigned)highpc, HISTFRACTION*sizeof(HISTCOUNTER));
E 16
    s_highpc = highpc;
D 6
    textsize = ( (char *) highpc - (char *) lowpc );
    monsize = textsize + sizeof(struct phdr);
E 6
I 6
    s_textsize = highpc - lowpc;
D 15
    monsize = s_textsize + sizeof(struct phdr);
E 15
I 15
D 16
    monsize = (s_textsize + 1) / 2 + sizeof(struct phdr);
E 16
I 16
    monsize = (s_textsize / HISTFRACTION) + sizeof(struct phdr);
E 16
E 15
E 6
    buffer = sbrk( monsize );
    if ( buffer == (char *) -1 ) {
D 25
	write( 2 , MSG , sizeof(MSG) );
E 25
I 25
	write( 2 , MSG , sizeof(MSG) - 1 );
E 25
	return;
    }
D 6
    froms = (unsigned short *) sbrk( textsize );
E 6
I 6
D 17
    froms = (unsigned short *) sbrk( s_textsize );
E 17
I 17
    froms = (unsigned short *) sbrk( s_textsize / HASHFRACTION );
E 17
E 6
    if ( froms == (unsigned short *) -1 ) {
D 25
	write( 2 , MSG , sizeof(MSG) );
E 25
I 25
	write( 2 , MSG , sizeof(MSG) - 1 );
E 25
	froms = 0;
	return;
    }
D 6
    tos = (struct tostruct *) sbrk(textsize);
E 6
I 6
D 14
    tos = (struct tostruct *) sbrk(s_textsize);
E 14
I 14
D 16
    limit = s_textsize * DENSITY / 100;
    if ( limit < MINCNT ) {
	limit = MINCNT;
E 16
I 16
D 18
    limit = s_textsize * ARCDENSITY / 100;
    if ( limit < MINARCS ) {
	limit = MINARCS;
E 16
    } else if ( limit > 65534 ) {
	limit = 65534;
E 18
I 18
    tolimit = s_textsize * ARCDENSITY / 100;
    if ( tolimit < MINARCS ) {
	tolimit = MINARCS;
    } else if ( tolimit > 65534 ) {
	tolimit = 65534;
E 18
    }
D 18
    tos = (struct tostruct *) sbrk( limit * sizeof( struct tostruct ) );
E 18
I 18
    tos = (struct tostruct *) sbrk( tolimit * sizeof( struct tostruct ) );
E 18
E 14
E 6
    if ( tos == (struct tostruct *) -1 ) {
D 25
	write( 2 , MSG , sizeof(MSG) );
E 25
I 25
	write( 2 , MSG , sizeof(MSG) - 1 );
E 25
	froms = 0;
	tos = 0;
	return;
    }
I 16
D 21
    minsbrk = sbrk(0);
E 21
I 21
    minbrk = sbrk(0);
E 21
E 16
D 6
    tolimit = textsize / sizeof(struct tostruct);
E 6
    tos[0].link = 0;
I 18
    monitor( lowpc , highpc , buffer , monsize , tolimit );
E 18
I 6
D 14
    limit = s_textsize / sizeof(struct tostruct);
E 14
D 19
	/*
D 18
	 *	tolimit is what mcount checks to see if
E 18
I 18
	 *	profiling is what mcount checks to see if
E 18
	 *	all the data structures are ready!!!
D 18
	 *	make sure it won't overflow.
E 18
	 */
D 14
    tolimit = limit > 65534 ? 65534 : limit;
E 14
I 14
D 18
    tolimit = limit;
E 14
E 6
D 13
    monitor( lowpc , highpc , buffer , monsize );
E 13
I 13
    monitor( lowpc , highpc , buffer , monsize , tolimit );
E 18
I 18
    profiling = 0;
E 19
I 19
D 20
    moncontrol(1);
E 20
E 19
E 18
E 13
E 3
}

D 3
_peek()
{
}

E 3
_mcleanup()
{
D 7
    FILE	*fd;
    int		fromindex;
    char	*frompc;
    int		toindex;
E 7
I 7
    int			fd;
    int			fromindex;
I 17
    int			endfrom;
E 17
    char		*frompc;
    int			toindex;
    struct rawarc	rawarc;
E 7
D 6
    int		textsize;
E 6

D 3
    monitor((int (*)())0);
    fd = fopen( "dmon.out" , "w" );
E 3
I 3
D 13
    monitor( (int (*)()) 0 );
E 13
D 7
    fd = fopen( "gmon.out" , "w" );
E 3
    if ( fd == NULL ) {
E 7
I 7
    fd = creat( "gmon.out" , 0666 );
    if ( fd < 0 ) {
E 7
D 2
	perror( "mcount: mon.out2" );
E 2
I 2
D 3
	perror( "mcount: dmon.out" );
E 3
I 3
	perror( "mcount: gmon.out" );
E 3
E 2
	return;
    }
D 3
    fwrite( sbuf , ssiz , 1 , fd );
E 3
I 3
#   ifdef DEBUG
	fprintf( stderr , "[mcleanup] sbuf 0x%x ssiz %d\n" , sbuf , ssiz );
#   endif DEBUG
D 7
    fwrite( sbuf , 1 , ssiz , fd );
E 7
I 7
    write( fd , sbuf , ssiz );
E 7
E 3
D 6
    textsize = s_highpc - s_lowpc;
    for ( fromindex = 0 ; fromindex < textsize>>1 ; fromindex++ ) {
E 6
I 6
D 17
    for ( fromindex = 0 ; fromindex < s_textsize>>1 ; fromindex++ ) {
E 17
I 17
    endfrom = s_textsize / (HASHFRACTION * sizeof(*froms));
    for ( fromindex = 0 ; fromindex < endfrom ; fromindex++ ) {
E 17
E 6
	if ( froms[fromindex] == 0 ) {
	    continue;
	}
D 17
	frompc = s_lowpc + (fromindex<<1);
E 17
I 17
	frompc = s_lowpc + (fromindex * HASHFRACTION * sizeof(*froms));
E 17
	for (toindex=froms[fromindex]; toindex!=0; toindex=tos[toindex].link) {
#	    ifdef DEBUG
D 3
		printf( "[mcleanup] frompc %d selfpc %d count %d\n" ,
E 3
I 3
D 4
		fprintf( stderr , "[mcleanup] frompc %d selfpc %d count %d\n" ,
E 4
I 4
		fprintf( stderr ,
			"[mcleanup] frompc 0x%x selfpc 0x%x count %d\n" ,
E 4
E 3
			frompc , tos[toindex].selfpc , tos[toindex].count );
#	    endif DEBUG
D 7
	    fwrite( &frompc, 1, sizeof frompc, fd );
	    fwrite( &tos[toindex].selfpc, 1, sizeof tos[toindex].selfpc, fd );
	    fwrite( &tos[toindex].count, 1, sizeof tos[toindex].count, fd );
E 7
I 7
	    rawarc.raw_frompc = (unsigned long) frompc;
	    rawarc.raw_selfpc = (unsigned long) tos[toindex].selfpc;
	    rawarc.raw_count = tos[toindex].count;
	    write( fd , &rawarc , sizeof rawarc );
E 7
	}
    }
D 7
    fclose( fd );
E 7
I 7
    close( fd );
E 7
}

D 3
/*
 *	This routine is massaged so that it may be jsb'ed to
 */
E 3
I 3
D 16
    /*
     *	This routine is massaged so that it may be jsb'ed to
     */
E 3
asm("#define _mcount mcount");
E 16
I 16
asm(".text");
I 19
asm(".align 2");
E 19
asm("#the beginning of mcount()");
asm(".data");
E 16
mcount()
{
D 16
    register char		*selfpc;	/* r11 */
    register unsigned short	*frompcindex;	/* r10 */
    register struct tostruct	*top;		/* r9 */
D 2
    /* !!! if you add anything, you have to fix the pushr and popr !!! */
E 2
I 2
    static int			profiling = 0;
E 16
I 16
	register char			*selfpc;	/* r11 => r5 */
	register unsigned short		*frompcindex;	/* r10 => r4 */
	register struct tostruct	*top;		/* r9  => r3 */
	register struct tostruct	*prevtop;	/* r8  => r2 */
	register long			toindex;	/* r7  => r1 */
D 18
	static int			profiling = 0;
E 18
E 16
E 2

D 3
    asm( "	forgot to run ex script on monitor.s" );
E 3
I 3
D 7
    asm( "	forgot to run ex script on gmcrt0.s" );
E 7
I 7
D 16
    asm( "	forgot to run ex script on gcrt0.s" );
E 7
E 3
    asm( "#define r11 r5" );
    asm( "#define r10 r4" );
    asm( "#define r9 r3" );
E 16
D 23
#ifdef lint
D 16
    selfpc = (char *) 0;
    frompcindex = 0;
E 16
I 16
	selfpc = (char *)0;
	frompcindex = 0;
E 16
#else not lint
E 23
	/*
D 2
	 *	we've pushed the old r11, r10, and r9,
	 *	so the return address for a plain old jsb
	 *	which should be at 0(sp) is now at 12(sp)
E 2
I 2
	 *	find the return address for mcount,
	 *	and the return address for mcount's caller.
E 2
	 */
D 16
    asm("	movl (sp), r11");	/* selfpc = ... (jsb frame) */
    asm("	movl 16(fp), r10");	/* frompcindex =     (calls frame) */
E 16
I 16
	asm("	.text");		/* make sure we're in text space */
	asm("	movl (sp), r11");	/* selfpc = ... (jsb frame) */
	asm("	movl 16(fp), r10");	/* frompcindex =     (calls frame) */
E 16
D 23
#endif not lint
E 23
D 2
    /*
     *	check that we are profiling
     */
    if ( tos == 0 ) {
E 2
I 2
	/*
	 *	check that we are profiling
I 3
	 *	and that we aren't recursively invoked.
E 3
	 */
D 3
    if ( profiling || tos == 0 ) {
E 3
I 3
D 6
    if ( tos == 0 ) {
E 6
I 6
D 16
    if ( tolimit == 0 ) {
E 6
E 3
E 2
	goto out;
    }
I 3
    if ( profiling ) {
	goto out;
    }
E 3
I 2
    profiling = 1;
E 16
I 16
D 18
	if (tolimit == 0) {
		goto out;
	}
E 18
	if (profiling) {
		goto out;
	}
D 18
	profiling = 1;
E 18
I 18
	profiling++;
E 18
E 16
	/*
	 *	check that frompcindex is a reasonable pc value.
	 *	for example:	signal catchers get called from the stack,
	 *			not from text space.  too bad.
	 */
D 6
    if ( (char *) frompcindex < s_lowpc || (char *) frompcindex > s_highpc ) {
E 6
I 6
D 16
    frompcindex = (unsigned short *) ( (long) frompcindex - (long) s_lowpc );
    if ( (unsigned long) frompcindex > s_textsize ) {
E 6
	goto done;
    }
E 2
D 6
    frompcindex = &froms[ ( (long) frompcindex - (long) s_lowpc ) >> 1 ];
E 6
I 6
    frompcindex = &froms[ ( (long) frompcindex ) >> 1 ];
E 6
    if ( *frompcindex == 0 ) {
	*frompcindex = ++tos[0].link;
	if ( *frompcindex >= tolimit ) {
	    goto overflow;
E 16
I 16
	frompcindex = (unsigned short *)((long)frompcindex - (long)s_lowpc);
	if ((unsigned long)frompcindex > s_textsize) {
		goto done;
E 16
	}
D 16
	top = &tos[ *frompcindex ];
	top->selfpc = selfpc;
	top->count = 0;
	top->link = 0;
    } else {
	top = &tos[ *frompcindex ];
    }
D 2
    for ( ; /*break*/ ; top = &tos[ top -> link ] ) {
E 2
I 2
    for ( ; /* goto done */ ; top = &tos[ top -> link ] ) {
E 2
	if ( top -> selfpc == selfpc ) {
	    top -> count++;
D 2
	    break;
E 2
I 2
	    goto done;
E 16
I 16
	frompcindex =
D 17
	    &froms[(((long)frompcindex) + sizeof(*froms) - 1) / sizeof(*froms)];
E 17
I 17
	    &froms[((long)frompcindex) / (HASHFRACTION * sizeof(*froms))];
E 17
	toindex = *frompcindex;
	if (toindex == 0) {
		/*
		 *	first time traversing this arc
		 */
		toindex = ++tos[0].link;
		if (toindex >= tolimit) {
			goto overflow;
		}
		*frompcindex = toindex;
		top = &tos[toindex];
		top->selfpc = selfpc;
		top->count = 1;
		top->link = 0;
		goto done;
E 16
E 2
	}
D 16
	if ( top -> link == 0 ) {
	    top -> link = ++tos[0].link;
	    if ( top -> link >= tolimit )
		goto overflow;
	    top = &tos[ top -> link ];
	    top -> selfpc = selfpc;
	    top -> count = 1;
	    top -> link = 0;
D 2
	    break;
E 2
I 2
	    goto done;
E 16
I 16
	top = &tos[toindex];
	if (top->selfpc == selfpc) {
		/*
		 *	arc at front of chain; usual case.
		 */
		top->count++;
		goto done;
E 16
E 2
	}
D 16
    }
E 16
I 16
	/*
	 *	have to go looking down chain for it.
	 *	top points to what we are looking at,
	 *	prevtop points to previous top.
	 *	we know it is not at the head of the chain.
	 */
	for (; /* goto done */; ) {
		if (top->link == 0) {
			/*
			 *	top is end of the chain and none of the chain
			 *	had top->selfpc == selfpc.
			 *	so we allocate a new tostruct
			 *	and link it to the head of the chain.
			 */
			toindex = ++tos[0].link;
			if (toindex >= tolimit) {
				goto overflow;
			}
			top = &tos[toindex];
			top->selfpc = selfpc;
			top->count = 1;
			top->link = *frompcindex;
			*frompcindex = toindex;
			goto done;
		}
		/*
		 *	otherwise, check the next arc on the chain.
		 */
		prevtop = top;
		top = &tos[top->link];
		if (top->selfpc == selfpc) {
			/*
			 *	there it is.
			 *	increment its count
			 *	move it to the head of the chain.
			 */
			top->count++;
			toindex = prevtop->link;
			prevtop->link = top->link;
			top->link = *frompcindex;
			*frompcindex = toindex;
			goto done;
		}

	}
E 16
I 2
done:
D 16
    profiling = 0;
    /* and fall through */
E 16
I 16
D 18
	profiling = 0;
E 18
I 18
	profiling--;
E 18
	/* and fall through */
E 16
E 2
out:
D 16
    asm( "	rsb" );
    asm( "#undef r11" );
    asm( "#undef r10" );
    asm( "#undef r9" );
    asm( "#undef _mcount");
E 16
I 16
	asm("	rsb");
E 16

overflow:
I 6
D 16
    tolimit = 0;
E 16
I 16
D 18
	tolimit = 0;
E 18
I 18
	profiling++; /* halt further profiling */
E 18
E 16
E 6
#   define	TOLIMIT	"mcount: tos overflow\n"
D 16
    write( 2 , TOLIMIT , sizeof( TOLIMIT ) );
D 6
    tos = 0;
    froms = 0;
E 6
    goto out;
E 16
I 16
D 25
	write(2, TOLIMIT, sizeof(TOLIMIT));
E 25
I 25
	write(2, TOLIMIT, sizeof(TOLIMIT) - 1);
E 25
	goto out;
E 16
}
I 16
asm(".text");
asm("#the end of mcount()");
asm(".data");
E 16

D 3
monitor(lowpc, highpc, buf, bufsiz)
	char	*lowpc;
	/*VARARGS1*/
	char	*highpc;
	int *buf, bufsiz;
E 3
I 3
D 13
monitor( lowpc , highpc , buf , bufsiz )
E 13
I 13
/*VARARGS1*/
monitor( lowpc , highpc , buf , bufsiz , nfunc )
E 13
    char	*lowpc;
D 13
    /* VARARGS1 */
E 13
    char	*highpc;
D 20
    int		*buf, bufsiz;
E 20
I 20
    char	*buf;	/* declared ``short buffer[]'' in monitor(3) */
    int		bufsiz;
E 20
I 13
    int		nfunc;	/* not used, available for compatability only */
E 13
E 3
{
D 3
	register o;
E 3
I 3
    register o;
E 3

D 3
	if (lowpc == 0) {
		profil((char *)0, 0, 0, 0);
		return;
	}
	sbuf = buf;
	ssiz = bufsiz;
	((struct phdr *)buf)->lpc = lowpc;
	((struct phdr *)buf)->hpc = highpc;
	((struct phdr *)buf)->ncnt = ssiz;
	o = sizeof(struct phdr);
	buf = (int *) (((int)buf) + o);
	bufsiz -= o;
	if (bufsiz<=0)
		return;
	o = (((char *)highpc - (char *)lowpc)>>1);
	if(bufsiz < o)
		o = ((float) bufsiz / o) * 32768;
	else
		o = 0177777;
	profil(buf, bufsiz, lowpc, o);
E 3
I 3
    if ( lowpc == 0 ) {
I 18
D 19
	profiling++; /* halt profiling */
E 18
	profil( (char *) 0 , 0 , 0 , 0 );
E 19
I 19
	moncontrol(0);
E 19
I 13
	_mcleanup();
E 13
	return;
    }
    sbuf = buf;
    ssiz = bufsiz;
    ( (struct phdr *) buf ) -> lpc = lowpc;
    ( (struct phdr *) buf ) -> hpc = highpc;
    ( (struct phdr *) buf ) -> ncnt = ssiz;
D 20
    o = sizeof(struct phdr);
    buf = (int *) ( ( (int) buf ) + o );
    bufsiz -= o;
E 20
I 20
    bufsiz -= sizeof(struct phdr);
E 20
    if ( bufsiz <= 0 )
	return;
D 8
    o = ( ( (char *) highpc - (char *) lowpc) >> 1 );
E 8
I 8
D 20
    o = ( ( (char *) highpc - (char *) lowpc) );
E 20
I 20
    o = highpc - lowpc;
E 20
E 8
    if( bufsiz < o )
D 8
	o = ( (float) bufsiz / o ) * 32768;
E 8
I 8
D 20
	o = ( (float) bufsiz / o ) * 65536;
E 20
I 20
	s_scale = ( (float) bufsiz / o ) * SCALE_1_TO_1;
E 20
E 8
    else
D 8
	o = 0177777;
E 8
I 8
D 20
	o = 65536;
E 8
D 19
    profil( buf , bufsiz , lowpc , o );
E 19
I 19
    s_scale = o;
E 20
I 20
	s_scale = SCALE_1_TO_1;
E 20
    moncontrol(1);
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
	profil(sbuf + sizeof(struct phdr), ssiz - sizeof(struct phdr),
		s_lowpc, s_scale);
	profiling = 0;
    } else {
	/* stop */
	profil((char *)0, 0, 0, 0);
	profiling = 3;
    }
E 19
E 3
D 21
}
I 10

/*
 * This is a stub for the "brk" system call, which we want to
D 11
 * catch and ignore, so that it will not deallocate our data
 * space. (of which the program is not aware)
E 11
I 11
 * catch so that it will not deallocate our data space.
 * (of which the program is not aware)
E 11
 */
I 11
D 16
asm("#define _curbrk curbrk");
E 16
extern char *curbrk;

E 11
brk(addr)
D 11
	int *addr;
E 11
I 11
	char *addr;
E 11
{
D 11
	;
E 11
I 11

	if (addr < minsbrk)
		addr = minsbrk;
	asm("	chmk	$17");
D 13
	asm("	jcs	cerror");
E 13
I 13
	asm("	jcc	1f");
	asm("	jmp	cerror");
asm("1:");
E 13
	curbrk = addr;
	return (0);
E 21
E 11
}
E 10
D 3

E 3
E 1

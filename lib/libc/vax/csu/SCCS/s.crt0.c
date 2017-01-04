h30906
s 00001/00002/00114
d D 5.4 88/01/18 11:25:22 mckusick 13 12
c use _exit instead of asm's (4.3BSD/lib/16)
e
s 00002/00002/00114
d D 5.3 86/03/09 21:08:06 donn 12 9
c added LIBC_SCCS condition for sccs ids
e
s 00003/00003/00113
d R 5.3 86/03/09 21:01:44 donn 11 9
c added LIBC_SCCS condition for sccs ids
e
s 00001/00000/00116
d R 5.3 86/02/04 17:57:27 karels 10 9
c add call to _stdio_init
e
s 00019/00000/00097
d D 5.2 85/10/21 19:34:19 mckusick 9 8
c add paranoid check for missing file descriptors 0, 1, and 2
e
s 00009/00001/00088
d D 5.1 85/05/30 14:54:35 dist 8 7
c Add copyright
e
s 00007/00001/00082
d D 4.6 83/03/30 17:21:44 peter 7 6
c add null moncontrol() if not compiled for profiling
e
s 00025/00001/00058
d D 4.5 82/12/04 16:16:06 mckusick 6 5
c break out "monitor" into separate file for jkf
e
s 00003/00002/00056
d D 4.4 82/05/19 10:06:18 rrh 5 4
c old versions; put these to bed
e
s 00001/00000/00057
d D 4.3 82/01/13 14:39:07 mckusic 4 3
c make mcount a global
e
s 00002/00007/00055
d D 4.2 82/01/05 15:18:17 mckusic 3 2
c change _start to start
e
s 00000/00000/00062
d D 4.1 81/11/29 23:32:33 mckusic 2 1
c renumber to version 4
e
s 00062/00000/00000
d D 1.1 81/11/29 16:43:24 mckusick 1 0
c date and time created 81/11/29 16:43:24 by mckusick
e
u
U
t
T
I 1
D 8
static	char *sccsid = "%W% (Berkeley) %G%";
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 12
#ifndef lint
E 12
I 12
#if defined(LIBC_SCCS) && !defined(lint)
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif LIBC_SCCS and not lint
E 12
E 8

/*
 *	C start up routine.
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

D 6
char **environ;
E 6
I 6
char **environ = (char **)0;
I 9
static int fd;
E 9
E 6

I 3
asm("#define _start start");
I 6
asm("#define _eprol eprol");
extern	unsigned char	etext;
extern	unsigned char	eprol;
E 6
E 3
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
D 5
	register struct kframe *kfp;	/* r11 */
E 5
I 5
	register int r11;		/* needed for init */
	register struct kframe *kfp;	/* r10 */
E 5
	register char **targv;
	register char **argv;
I 9
	extern int errno;
E 9

#ifdef lint
	kfp = 0;
I 6
	initcode = initcode = 0;
E 6
#else not lint
D 5
	asm("	movl	sp,r11");	/* catch it quick */
E 5
I 5
	asm("	movl	sp,r10");	/* catch it quick */
E 5
#endif not lint
	for (argv = targv = &kfp->kargv[0]; *targv++; /* void */)
		/* void */ ;
	if (targv >= (char **)(*argv))
		--targv;
	environ = targv;
I 6
asm("eprol:");
I 9

#ifdef paranoid
	/*
	 * The standard I/O library assumes that file descriptors 0, 1, and 2
	 * are open. If one of these descriptors is closed prior to the start 
	 * of the process, I/O gets very confused. To avoid this problem, we
	 * insure that the first three file descriptors are open before calling
	 * main(). Normally this is undefined, as it adds two unnecessary
	 * system calls.
	 */
	do	{
		fd = open("/dev/null", 2);
	} while (fd >= 0 && fd < 3);
	close(fd);
#endif paranoid

E 9
#ifdef MCRT0
	monstartup(&eprol, &etext);
#endif MCRT0
I 9
	errno = 0;
E 9
E 6
	exit(main(kfp->kargc, argv, environ));
}
I 6
asm("#undef _start");
asm("#undef _eprol");
E 6

I 6
#ifdef MCRT0
/*ARGSUSED*/
exit(code)
	register int code;	/* r11 */
{
	monitor(0);
	_cleanup();
D 13
	asm("	movl r11,r0");
	asm("	chmk $1");
E 13
I 13
	_exit(code);
E 13
}
#endif MCRT0

#ifdef CRT0
E 6
/*
D 7
 * null mcount, just in case some routine is compiled for profiling
E 7
I 7
 * null mcount and moncontrol,
 * just in case some routine is compiled for profiling
E 7
 */
I 7
moncontrol(val)
	int val;
{

}
E 7
I 4
asm("	.globl	mcount");
E 4
D 3
asm("#define _mcount mcount");
mcount()
{
	asm("	forgot to run ex script on gcrt0.s" );
	asm( "	rsb" );
	asm( "#undef _mcount");
}
E 3
I 3
asm("mcount:	rsb");
I 6
#endif CRT0
E 6
E 3
E 1

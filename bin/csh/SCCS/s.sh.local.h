h41677
s 00001/00001/00050
d D 5.3 86/10/13 16:44:24 sam 9 8
c tahoe has bcopy as well
e
s 00001/00001/00050
d D 5.2 85/06/06 13:08:44 edward 8 7
c cleaning up after bozos
e
s 00007/00001/00044
d D 5.1 85/06/04 11:11:49 dist 7 6
c Add copyright
e
s 00002/00009/00043
d D 4.6 84/12/13 14:39:18 edward 6 5
c performance
e
s 00000/00007/00052
d D 4.5 84/11/21 11:23:40 ralph 5 4
c take out NOFILE & NCARGS since param.h is included
e
s 00008/00000/00051
d D 4.4 84/07/06 22:42:04 sam 4 3
c turn copy() into bcopy(); fix up profiling
e
s 00001/00001/00050
d D 4.3 82/12/30 17:35:21 sam 3 2
c finally works (updated for 4.1c and merged with sun)
e
s 00002/00007/00049
d D 4.2 82/05/07 18:24:22 mckusick 2 1
c update to new fs
e
s 00056/00000/00000
d D 4.1 80/10/09 12:41:22 bill 1 0
c date and time created 80/10/09 12:41:22 by bill
e
u
U
t
T
I 1
D 6
/* %M% %I% %G% */
I 2
/* sh.local.h 4.1 10/9/80 */
E 6
I 6
D 7
/* %W% (Berkeley) %G% */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
E 8
I 8
 * All rights reserved.  The Berkeley Software License Agreement
E 8
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7
E 6
E 2

/*
 * This file defines certain local parameters
 * A symbol should be defined in Makefile for local conditional
 * compilation, e.g. IIASA or ERNIE, to be tested here and elsewhere.
 */

/*
 * Fundamental definitions which may vary from system to system.
 *
 *	BUFSIZ		The i/o buffering size; also limits word size
 *	SHELLPATH	Where the shell will live; initalizes $shell
 *	MAILINTVL	How often to mailcheck; more often is more expensive
D 6
 *	HZ		Cycle of ac power
E 6
 *	OTHERSH		Shell for scripts which don't start with #
 */

D 2
#define	BUFSIZ	512		/* default buffer size */
E 2
I 2
#define	BUFSIZ	1024		/* default buffer size */
E 2
D 3
#define HZ	60		/* for division into seconds */
E 3
I 3
D 6
#define HZ	100		/* for division into seconds */
E 6
E 3
#define	SHELLPATH	"/bin/csh"
#define	OTHERSH		"/bin/sh"
#define FORKSLEEP	10	/* delay loop on non-interactive fork failure */
#define	MAILINTVL	600	/* 10 minutes */

/*
D 5
 * NCARGS and NOFILE are from <sys/param.h> which we choose not
 * to wholly include
 */
#define	NCARGS	10240		/* Max. chars in an argument list */

/*
E 5
 * The shell moves std in/out/diag and the old std input away from units
 * 0, 1, and 2 so that it is easy to set up these standards for invoked
D 6
 * commands.  If possible they should go into descriptors closed by exec.
E 6
I 6
 * commands.
E 6
 */
D 5
#define	NOFILE	20		/* Max number of open files */
E 5
#define	FSHTTY	15		/* /dev/tty when manip pgrps */
#define	FSHIN	16		/* Preferred desc for shell input */
#define	FSHOUT	17		/* ... shell output */
#define	FSHDIAG	18		/* ... shell diagnostics */
#define	FOLDSTD	19		/* ... old std input */

D 6
#define	V7

E 6
#ifdef IIASA
D 6
#undef	HZ
#define	HZ	60
E 6
#undef	OTHERSH
D 2
#endif

#ifdef VMUNIX
#include <pagsiz.h>
#undef BUFSIZ
#define	BUFSIZ	BSIZE
E 2
#endif
I 4

D 9
#ifdef vax
E 9
I 9
#if defined(vax) || defined(tahoe)
E 9
#define	copy(to, from, size)	bcopy(from, to, size)
#endif

#ifdef PROF
#define	exit(n)	done(n)
#endif
E 4
E 1

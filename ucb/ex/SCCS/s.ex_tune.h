h60897
s 00014/00000/00131
d D 7.11 87/03/09 12:46:58 conrad 20 19
c make ex/vi work on vms
e
s 00002/00002/00129
d D 7.10 86/12/01 18:56:42 bostic 19 18
c upped the TUBELINES constant.
e
s 00001/00001/00130
d D 7.9 86/07/26 13:02:42 sam 18 17
c 1.21 change; increase termcap buffer
e
s 00008/00002/00123
d D 7.8 85/05/31 15:58:54 dist 17 15
c Add copyright
e
s 00008/00002/00111
d D 5.1.1.1 85/05/31 11:53:04 dist 16 6
c Add copyright
e
s 00002/00002/00123
d D 7.7 84/10/22 10:25:11 ralph 15 14
c fix TUBELINES to handle 70 line terminals (5620).
e
s 00001/00001/00124
d D 7.6 84/04/10 22:13:00 peter 14 13
c if lisp is set allow `-'s in tagged words (since this is the style);
c and in general allow reasonably long tags.
e
s 00007/00002/00118
d D 7.5 83/07/02 23:27:24 sam 13 12
c purge local/uparm.h; fix from sun for expreserve
e
s 00001/00000/00119
d D 7.4 83/06/17 21:38:56 root 12 11
c monet merge
e
s 00006/00000/00113
d D 7.3 81/09/03 11:45:23 mark 11 10
c updates for Unix/370 and ins/del line on vt100
e
s 00000/00000/00113
d D 7.2 81/07/26 20:04:54 mark 10 9
c fixes for 3b
e
s 00006/00006/00107
d D 7.1 81/07/08 22:31:52 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00002/00002/00111
d D 6.2 80/10/30 20:40:46 mark 8 7
c fixed it to work on terminals with over 48 lines, and fixed bug 
c which allowed setting a huge window
e
s 00000/00000/00113
d D 6.1 80/10/19 01:21:41 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00113
d D 5.1 80/08/20 16:12:20 mark 6 5
c Release 3.5, August 20, 1980
e
s 00005/00004/00108
d D 4.2 80/08/01 20:57:48 mark 5 4
c Bill added more buffers, I put in sccs.
e
s 00006/00004/00106
d D 4.1 80/08/01 00:16:10 mark 4 3
c release 3.4, June 24, 1980
e
s 00004/00005/00106
d D 3.1 80/07/31 23:40:09 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00033/00009/00078
d D 2.1 80/07/31 23:19:58 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00087/00000/00000
d D 1.1 80/07/31 23:00:34 mark 1 0
c date and time created 80/07/31 23:00:34 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 9
D 16
/* Copyright (c) 1980 Regents of the University of California */
/* sccs id:	%W% %G%  */
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 16
E 9
I 9
D 17
/* Copyright (c) 1981 Regents of the University of California */
D 13
/* sccs id:	%W%	%G%  */
E 13
I 13
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 17
E 13
E 9
E 5
/*
 * Definitions of editor parameters and limits
 */

/*
 * Pathnames.
 *
 * Only exstrings is looked at "+4", i.e. if you give
 * "/usr/lib/..." here, "/lib" will be tried only for strings.
 */
D 13
#include "local/uparm.h"
E 13
I 13
#define libpath(file) "/usr/lib/file"
#define loclibpath(file) "/usr/local/lib/file"
#define binpath(file) "/usr/ucb/file"
#define usrpath(file) "/usr/file"
I 20
#ifndef	vms
E 20
#define E_TERMCAP	"/etc/termcap"
I 20
#else
#define E_TERMCAP	"etc:termcap."
#endif
E 20
#define B_CSH		"/bin/csh"
E 13
D 2
#define	EXRECOVER	libpath(ex3.1recover)
#define	EXPRESERVE	libpath(ex3.1preserve)
#define	EXSTRINGS	libpath(ex3.1strings)
E 2
I 2
D 3
#define	EXRECOVER	libpath(ex3.2recover)
#define	EXPRESERVE	libpath(ex3.2preserve)
E 3
I 3
D 4
#define	EXRECOVER	libpath(ex3.3recover)
#define	EXPRESERVE	libpath(ex3.3preserve)
E 4
I 4
D 5
#define	EXRECOVER	libpath(ex3.4recover)
#define	EXPRESERVE	libpath(ex3.4preserve)
E 5
I 5
D 9
#define	EXRECOVER	libpath(ex3.%R%recover)
#define	EXPRESERVE	libpath(ex3.%R%preserve)
E 9
I 9
#define	EXRECOVER	libpath(ex3.7recover)
#define	EXPRESERVE	libpath(ex3.7preserve)
E 9
E 5
E 4
E 3
#ifndef VMUNIX
I 20
#ifndef	vms
E 20
D 3
#define	EXSTRINGS	libpath(ex3.2strings)
E 3
I 3
D 4
#define	EXSTRINGS	libpath(ex3.3strings)
E 4
I 4
D 5
#define	EXSTRINGS	libpath(ex3.4strings)
E 5
I 5
D 9
#define	EXSTRINGS	libpath(ex3.%R%strings)
E 9
I 9
#define	EXSTRINGS	libpath(ex3.7strings)
E 9
E 5
E 4
E 3
#endif
I 20
#endif
E 20
E 2
D 3
#define	MASTERTAGS	libpath(tags)
E 3

/*
 * If your system believes that tabs expand to a width other than
 * 8 then your makefile should cc with -DTABS=whatever, otherwise we use 8.
 */
#ifndef TABS
#define	TABS	8
#endif

/*
 * Maximums
 *
 * The definition of LBSIZE should be the same as BUFSIZ (512 usually).
D 2
 * Most other defitions are quite generous.
E 2
I 2
 * Most other definitions are quite generous.
E 2
 */
/* FNSIZE is also defined in expreserve.c */
#define	FNSIZE		128		/* File name size */
I 2
#ifdef VMUNIX
#define	LBSIZE		1024
#define	ESIZE		512
I 4
#define CRSIZE		1024
E 4
#else
I 11
#ifdef u370
#define LBSIZE		4096
#define ESIZE		512
#define CRSIZE		4096
#else
I 20
#ifdef vms
#define LBSIZE		1024
#define	ESIZE		512
#define	CRSIZE		1024
#else
E 20
E 11
E 2
#define	LBSIZE		512		/* Line length */
#define	ESIZE		128		/* Size of compiled re */
I 4
#define CRSIZE		512
I 11
#endif
E 11
E 4
I 2
#endif
I 20
#endif
E 20
E 2
#define	RHSSIZE		256		/* Size of rhs of substitute */
#define	NBRA		9		/* Number of re \( \) pairs */
D 14
#define	TAGSIZE		32		/* Tag length */
E 14
I 14
#define	TAGSIZE		128		/* Tag length */
E 14
D 3
#define	ONMSZ		32		/* Option name size */
E 3
I 3
#define	ONMSZ		64		/* Option name size */
E 3
#define	GBSIZE		256		/* Buffer size */
#define	UXBSIZE		128		/* Unix command buffer size */
#define	VBSIZE		128		/* Partial line max size in visual */
/* LBLKS is also defined in expreserve.c */
I 2
#ifndef VMUNIX
E 2
#define	LBLKS		125		/* Line pointer blocks in temp file */
I 2
#define	HBLKS		1		/* struct header fits in BUFSIZ*HBLKS */
#else
#define	LBLKS		900
#define	HBLKS		2
#endif
E 2
#define	MAXDIRT		12		/* Max dirtcnt before sync tfile */
D 18
#define TCBUFSIZE	1024		/* Max entry size in termcap, see
E 18
I 18
#define TCBUFSIZE	2048		/* Max entry size in termcap, see
E 18
					   also termlib and termcap */

/*
D 2
 * These are a ridiculously small due to the
E 2
I 2
 * Except on VMUNIX, these are a ridiculously small due to the
E 2
 * lousy arglist processing implementation which fixes core
 * proportional to them.  Argv (and hence NARGS) is really unnecessary,
 * and argument character space not needed except when
 * arguments exist.  Argument lists should be saved before the "zero"
 * of the incore line information and could then
 * be reasonably large.
 */
I 20
#ifndef	vms
E 20
I 12
#undef NCARGS
I 20
#endif
E 20
E 12
I 2
#ifndef VMUNIX
E 2
#define	NARGS	100		/* Maximum number of names in "next" */
D 2
#define	NCARGS	512		/* Maximum arglist chars in "next" */
E 2
I 2
#define	NCARGS	LBSIZE		/* Maximum arglist chars in "next" */
#else
#define	NCARGS	5120
#define	NARGS	(NCARGS/6)
#endif
E 2

/*
 * Note: because the routine "alloca" is not portable, TUBESIZE
 * bytes are allocated on the stack each time you go into visual
D 2
 * and then never freed by the system.  Thus if you have not terminals
E 2
I 2
 * and then never freed by the system.  Thus if you have no terminals
E 2
 * which are larger than 24 * 80 you may well want to make TUBESIZE
 * smaller.  TUBECOLS should stay at 160 since this defines the maximum
 * length of opening on hardcopies and allows two lines of open on
 * terminals like adm3's (glass tty's) where it switches to pseudo
 * hardcopy mode when a line gets longer than 80 characters.
 */
D 2
#define	TUBELINES	36	/* Number of screen lines for visual */
E 2
I 2
#ifndef VMUNIX
D 8
#define	TUBELINES	40	/* Number of screen lines for visual */
E 8
I 8
#define	TUBELINES	60	/* Number of screen lines for visual */
E 8
E 2
#define	TUBECOLS	160	/* Number of screen columns for visual */
D 2
#define	TUBESIZE	2880	/* Maximum screen size for visual */
E 2
I 2
D 8
#define	TUBESIZE	3400	/* Maximum screen size for visual */
E 8
I 8
#define	TUBESIZE	5000	/* Maximum screen size for visual */
E 8
#else
D 15
#define	TUBELINES	66
E 15
I 15
D 19
#define	TUBELINES	70
E 19
I 19
#define	TUBELINES	100
E 19
E 15
#define	TUBECOLS	160
D 15
#define	TUBESIZE	6600	/* 66 * 100 */
E 15
I 15
D 19
#define	TUBESIZE	7000	/* 70 * 100 */
E 19
I 19
#define	TUBESIZE	(TUBELINES * 100)
E 19
E 15
#endif
E 2

/*
 * Output column (and line) are set to this value on cursor addressible
 * terminals when we lose track of the cursor to force cursor
 * addressing to occur.
 */
#define	UKCOL		-20	/* Prototype unknown column */

/*
 * Attention is the interrupt character (normally 0177 -- delete).
 * Quit is the quit signal (normally FS -- control-\) and quits open/visual.
 */
D 4
#define	ATTN	0177
E 4
I 4
D 9
#define	ATTN	(-2)
E 9
I 9
#define	ATTN	(-2)	/* mjm: (char) ??  */
E 9
E 4
#define	QUIT	('\\' & 037)
E 1

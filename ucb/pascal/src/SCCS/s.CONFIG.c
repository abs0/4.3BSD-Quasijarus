h02461
s 00010/00004/00040
d D 5.1 85/06/04 11:32:59 dist 9 8
c Add copyright
e
s 00000/00000/00044
d D 2.7 84/02/08 20:48:57 aoki 8 7
c synchronize to version 2
e
s 00001/00001/00043
d D 2.6 84/02/08 12:05:44 aoki 7 6
c missing ifndef PXP
e
s 00000/00000/00044
d D 2.5 83/09/19 06:57:26 thien 6 5
c Restoring to unlinted version
e
s 00007/00000/00037
d D 2.4 83/08/19 04:54:55 thien 5 4
c The changes were made to allow successful linting
e
s 00002/00002/00035
d D 2.3 82/04/01 15:47:55 peter 4 3
c sizeof("...") returns the size including the trailing null.
e
s 00010/00005/00027
d D 2.2 82/04/01 13:51:31 peter 3 2
c version number and date come from makefile.
e
s 00000/00000/00032
d D 2.1 82/03/31 12:58:14 peter 2 1
c going to version 2.1 for the next distribution.
e
s 00032/00000/00000
d D 1.1 82/03/31 12:53:59 peter 1 0
c date and time created 82/03/31 12:53:59 by peter
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 9
I 1
    /*
     *	make sure you are editing
     *		CONFIG.c
     *	editing config.c won't work
     */
D 9

I 5
#ifndef lint
E 5
static	char *sccsid = "%W% (Berkeley) %E%";
I 5
#endif
E 9
E 5

    /*
     *	the version of translator
     */
D 3
char	*version = "%I% (VERSION %G%)";
E 3
I 3
char	*version = "VERSION (DATE)";
E 3

    /*
     *	the location of the error strings
     *	and the length of the path to it
D 3
     *	(in case of execution of pc0 as a.out)
E 3
I 3
     *	(in case of execution as a.something)
E 3
     */
char	*err_file = "LIBDIR/ERRORSTRINGS";
D 4
int	err_pathlen = sizeof("LIBDIR/");
E 4
I 4
int	err_pathlen = sizeof("LIBDIR/")-1;
E 4

    /*
     *	the location of the short explanation
     *	and the length of the path to it
     *	the null at the end is so pix can change it to pi'x' from pi.
     */
char	*how_file = "LIBDIR/HOWFILE\0";
D 4
int	how_pathlen = sizeof("LIBDIR/");
E 4
I 4
int	how_pathlen = sizeof("LIBDIR/")-1;
E 4
I 3
    
    /*
     *	things about the interpreter.
     *	these are not used by the compiler.
     */
I 5
#ifndef PC
E 5
E 3
char	*px_header = "LIBDIR/px_header";	/* px_header's name */
I 5
#endif

D 7
#ifdef PXP
E 7
I 7
#ifndef PXP
E 7
E 5
D 3
char	*pi_comp = "INTERPDIR/pi";		/* the compiler's name */
char	*px_intrp = "INTERPDIR/px";		/* the interpreter's name */
char	*px_debug = "INTERPDIR/pdx";		/* the debugger's name */
E 3
I 3
char	*pi_comp = "INSTALLDIR/pi";		/* the compiler's name */
char	*px_intrp = "INSTALLDIR/px";		/* the interpreter's name */
char	*px_debug = "INSTALLDIR/pdx";		/* the debugger's name */
I 5
#endif
E 5
E 3
E 1

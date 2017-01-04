h30461
s 00008/00002/00030
d D 5.1 85/06/05 15:43:11 dist 4 3
c Add copyright
e
s 00000/00000/00032
d D 2.1 84/02/08 20:49:04 aoki 3 2
c synchronize to version 2
e
s 00000/00000/00032
d D 1.2 83/09/19 07:08:23 thien 2 1
c changing to unlinted source
e
s 00032/00000/00000
d D 1.1 82/03/31 12:54:30 peter 1 0
c date and time created 82/03/31 12:54:30 by peter
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 4
I 1
    /*
     *	external declarations of things from 
     *		CONFIG.c
     *
     */
D 4

    /*	sccsid: %W% (Berkeley) %E% */
E 4

    /*
     *	the version of translator
     */
extern char	*version;

    /*
     *	the location of the error strings
     *	and the length of the path to it
     *	(in case of execution of pc0 as a.out)
     */
extern char	*err_file;
extern int	err_pathlen;

    /*
     *	the location of the short explanation
     *	and the length of the path to it
     *	the null at the end is so pix can change it to pi'x' from pi.
     */
extern char	*how_file;
extern int	how_pathlen;
extern char	*px_header;
extern char	*pi_comp;
extern char	*px_intrp;
extern char	*px_debug;
E 1

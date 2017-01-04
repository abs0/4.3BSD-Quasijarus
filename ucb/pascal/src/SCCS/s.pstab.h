h64407
s 00007/00001/00033
d D 5.1 85/06/05 15:48:56 dist 6 5
c Add copyright
e
s 00000/00000/00034
d D 2.1 84/02/08 20:42:43 aoki 5 4
c synchronize to version 2
e
s 00018/00003/00016
d D 1.4 83/07/26 09:46:44 peter 4 3
c using checksum on include files and flag day indicators on source files.
e
s 00002/00000/00017
d D 1.3 82/07/29 19:17:28 peter 3 2
c protect against conflicts with library routines and data.
e
s 00000/00005/00017
d D 1.2 80/09/09 14:02:37 peter 2 1
c N_PC moved into <stab.h>
e
s 00022/00000/00000
d D 1.1 80/09/05 15:44:02 peter 1 0
c date and time created 80/09/05 15:44:02 by peter
e
u
U
t
T
I 1
D 6
    /*	static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6

    /*
D 2
     *	the new .stab type for pascal separate compilation type checking
     */
#define	N_PC	0x30	/* global pascal symbol: name,,0,subtype,line */

    /*
E 2
D 4
     *	subtypes within the above type
     *	subtypes N_PSO and N_PSOL are	.stabs	name,,0,subtype,0
     *	others subtypes are		.stabs	name,,0,subtype,line
E 4
I 4
     *	subtypes within the stab type N_PC
     *
     *	subtypes N_PSO and N_PSOL are	.stabs	name,N_PC,0,subtype,checksum
     *	others subtypes are		.stabs	name,N_PC,0,subtype,line
E 4
     */
#define	N_PSO		0x1	/* source file name */
#define	N_PSOL		0x2	/* include file name */
#define	N_PGLABEL	0x3	/* global label */
#define	N_PGCONST	0x4	/* global constant */
#define	N_PGTYPE	0x5	/* global type */
#define	N_PGVAR		0x6	/* global variable */
#define	N_PGFUNC	0x7	/* global function */
#define	N_PGPROC	0x8	/* global procedure */
#define	N_PEFUNC	0x9	/* external function */
#define	N_PEPROC	0xa	/* external procedure */
I 3
#define	N_PLDATA	0xb	/* library variable */
#define	N_PLTEXT	0xc	/* library routine */
I 4

    /*
     *	checksums are used to check if included files have changed.
     *	we also use them to check that .o files are up to date with
     *	the libraries.
     *	if a checksum is less than the flag checksum,
     *	then the checksum (and therefore the .o file) is out of date.
     *	if a checksum is equal to the flag checksum,
     *	then no furthur checking of the checksum is done.
     *	this is for the 2nd and subsequent times a file is stabed.
     *	to declare a flag day, increment this value. (also be sure 
     *  to update this value in ../utilities/externs.awk)
     */
#define	N_FLAGCHECKSUM	1
E 4
E 3
E 1

h26581
s 00001/00001/00024
d D 7.1 86/06/04 23:22:21 mckusick 3 2
c 4.3BSD release version
e
s 00007/00001/00018
d D 1.2 85/06/08 14:56:54 mckusick 2 1
c Add copyright
e
s 00019/00000/00000
d D 1.1 84/07/21 16:04:07 sam 1 0
c date and time created 84/07/21 16:04:07 by sam
e
u
U
f b 
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * Header prepended to each a.out file.
 */
struct exec {
	long	a_magic;	/* magic number */
unsigned long	a_text;		/* size of text segment */
unsigned long	a_data;		/* size of initialized data */
unsigned long	a_bss;		/* size of uninitialized data */
unsigned long	a_syms;		/* size of symbol table */
unsigned long	a_entry;	/* entry point */
unsigned long	a_trsize;	/* size of text relocation */
unsigned long	a_drsize;	/* size of data relocation */
};

#define	OMAGIC	0407		/* old impure format */
#define	NMAGIC	0410		/* read-only text */
#define	ZMAGIC	0413		/* demand load format */
E 1

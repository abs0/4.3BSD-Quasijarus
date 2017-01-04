h31645
s 00007/00001/00038
d D 5.1 85/05/07 12:09:46 dist 2 1
c Add copyright notice
e
s 00039/00000/00000
d D 4.1 83/11/10 14:13:34 ralph 1 0
c date and time created 83/11/10 14:13:34 by ralph
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 *
 *
E 2
 * Displays plot files on an hp2648a graphics terminals.  I have heard
 * that all hp plotting devices use the same control sequences, so this
 * might work for all hp devices capable of plotting.
 */

#include <stdio.h>

#define TERMINAL "/dev/tty"

#define	ENQ	05
#define ACK	06
#define ESC	033
#define GRAPHIC	'*'
#define MODE	'm'
#define PLOT	'p'
#define DISPLAY 'd'
#define PENUP	'a'
#define BINARY	'i'
#define ASCII	'f'
#define CR	'\n'

#define TRUE  1
#define FALSE 0

#define xsc(xi) ((int) (xi - lowx) * scalex + 0.5)
#define ysc(yi) ((int) (yi - lowy) * scaley + 0.5)

extern int shakehands;
extern int currentx;
extern int currenty;
extern int buffcount;
extern int fildes;
extern float lowx;
extern float lowy;
extern float scalex;
extern float scaley;
extern struct sgttyb sarg;
E 1

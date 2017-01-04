h47185
s 00010/00003/00282
d D 3.2 88/03/28 12:08:12 bostic 4 3
c add Berkeley specific headers
e
s 00000/00000/00285
d D 3.1 87/08/11 10:20:38 minshall 3 2
c New version numbering.
e
s 00006/00001/00279
d D 1.2 87/07/17 10:05:58 minshall 2 1
c Install sccs headers and copyright notices.
e
s 00280/00000/00000
d D 1.1 86/11/12 16:44:11 minshall 1 0
c date and time created 86/11/12 16:44:11 by minshall
e
u
U
t
T
I 2
/*
I 4
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 4
 *
D 4
 * %W% (Berkeley) %G%
E 4
I 4
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
 */

E 2
I 1
D 4
#ifndef	lint
E 4
I 4
#ifndef lint
E 4
D 2
static	char	sccsid[] = "@(#)ectype.c	3.1  10/29/86";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
D 4
#endif	/* ndef lint */
E 4
I 4
#endif /* not lint */
E 4

#include "ectype.h"

char	ectype[] = {
/* 0x00 */
    E_SPACE,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0x10 */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0x20 */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0x30 */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0x40 */
    E_SPACE,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
/* 0x50 */
    E_PRINT|E_PUNCT,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
/* 0x60 */
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
/* 0x70 */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
    E_PRINT|E_PUNCT,
/* 0x80 */
    0x00,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0x90 */
    0x00,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xA0 */
    0x00,
    E_PRINT|E_PUNCT,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    E_PRINT|E_LOWER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xB0 */
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xC0 */
    E_PRINT|E_PUNCT,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xD0 */
    E_PRINT|E_PUNCT,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xE0 */
    E_PRINT|E_PUNCT,
    0x00,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    E_PRINT|E_UPPER,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
/* 0xF0 */
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    E_PRINT|E_DIGIT,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};
E 1

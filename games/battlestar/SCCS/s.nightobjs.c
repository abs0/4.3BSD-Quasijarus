h03056
s 00010/00005/00074
d D 5.2 88/06/19 14:11:27 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00068
d D 5.1 88/05/08 15:49:53 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00067
d D 1.3 85/04/24 15:33:07 edward 3 2
c copyright messages
e
s 00058/00058/00009
d D 1.2 85/04/23 10:04:01 edward 2 1
c use macros in place of literal constants
e
s 00067/00000/00000
d D 1.1 85/04/22 15:42:07 edward 1 0
c date and time created 85/04/22 15:42:07 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */

E 3
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

#include "externs.h"

struct objs nightobjs[] = {
D 2
	{ 218, 15 },
	{ 235, 58 },
	{ 92, 39 },
	{ 92, 40 },
	{ 92, 41 },
	{ 92, 43 },
	{ 92, 58 },
	{ 92, 38 },
	{ 181, 12 },
	{ 236, 12 },
	{ 92, 12 },
	{ 216, 3 },
	{ 216, 20 },
	{ 216, 21 },
	{ 168, 3 },
	{ 168, 20 },
	{ 168, 21 },
	{ 170, 3 },
	{ 170, 20 },
	{ 170, 21 },
	{ 124, 9 },
	{ 124, 31 },
	{ 124, 34 },
	{ 144, 9 },
	{ 144, 31 },
	{ 144, 34 },
	{ 113, 9 },
	{ 113, 31 },
	{ 113, 34 },
	{ 161, 9 },
	{ 161, 31 },
	{ 161, 34 },
	{ 169, 9 },
	{ 169, 31 },
	{ 169, 34 },
	{ 182, 9 },
	{ 182, 31 },
	{ 182, 34 },
	{ 198, 9 },
	{ 198, 31 },
	{ 198, 34 },
	{ 212, 9 },
	{ 212, 31 },
	{ 212, 34 },
	{ 216, 9 },
	{ 216, 31 },
	{ 216, 34 },
	{ 226, 9 },
	{ 226, 31 },
	{ 226, 34 },
	{ 228, 9 },
	{ 228, 31 },
	{ 228, 34 },
	{ 68, 14 },
	{ 144, 30 },
	{ 249, 35 },
	{ 250, 35 },
	{ 93, 39 },
E 2
I 2
	{ 218,	PAJAMAS },
	{ 235,	NATIVE },
	{ 92,	PAPAYAS },
	{ 92,	PINEAPPLE },
	{ 92,	KIWI },
	{ 92,	MANGO },
	{ 92,	NATIVE },
	{ 92,	MAN },
	{ 181,	LAMPON },
	{ 236,	LAMPON },
	{ 92,	LAMPON },
	{ 216,	WOODSMAN },
	{ 216,	DEADWOOD },
	{ 216,	MALLET },
	{ 168,	WOODSMAN },
	{ 168,	DEADWOOD },
	{ 168,	MALLET },
	{ 170,	WOODSMAN },
	{ 170,	DEADWOOD },
	{ 170,	MALLET },
	{ 124,	SHIELD },
	{ 124,	HALBERD },
	{ 124,	ELF },
	{ 144,	SHIELD },
	{ 144,	HALBERD },
	{ 144,	ELF },
	{ 113,	SHIELD },
	{ 113,	HALBERD },
	{ 113,	ELF },
	{ 161,	SHIELD },
	{ 161,	HALBERD },
	{ 161,	ELF },
	{ 169,	SHIELD },
	{ 169,	HALBERD },
	{ 169,	ELF },
	{ 182,	SHIELD },
	{ 182,	HALBERD },
	{ 182,	ELF },
	{ 198,	SHIELD },
	{ 198,	HALBERD },
	{ 198,	ELF },
	{ 212,	SHIELD },
	{ 212,	HALBERD },
	{ 212,	ELF },
	{ 216,	SHIELD },
	{ 216,	HALBERD },
	{ 216,	ELF },
	{ 226,	SHIELD },
	{ 226,	HALBERD },
	{ 226,	ELF },
	{ 228,	SHIELD },
	{ 228,	HALBERD },
	{ 228,	ELF },
	{ 68,	CYLON },
	{ 144,	SHOVEL },
	{ 249,	FOOT },
	{ 250,	FOOT },
	{ 93,	PAPAYAS },
E 2
	0
};
E 1

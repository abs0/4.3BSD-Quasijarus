h59602
s 00010/00005/00112
d D 5.2 88/06/19 14:11:10 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00106
d D 5.1 88/05/08 15:49:34 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00105
d D 1.3 85/04/24 15:30:44 edward 3 2
c copyright messages
e
s 00096/00096/00009
d D 1.2 85/04/23 10:03:47 edward 2 1
c use macros in place of literal constants
e
s 00105/00000/00000
d D 1.1 85/04/22 15:41:53 edward 1 0
c date and time created 85/04/22 15:41:53 by edward
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

struct objs dayobjs[] = {
D 2
	{ 236, 59 },
	{ 237, 60 },
	{ 275, 61 },
	{ 275, 62 },
	{ 275, 63 },
	{ 260, 36 },
	{ 266, 49 },
	{ 235, 50 },
	{ 51, 51 },
	{ 59, 51 },
	{ 48, 51 },
	{ 66, 52 },
	{ 65, 52 },
	{ 19, 54 },
	{ 167, 58 },
	{ 21, 0 },
	{ 30, 0 },
	{ 30, 5 },
	{ 260, 1 },
	{ 70, 2 },
	{ 71, 2 },
	{ 72, 2 },
	{ 73, 2 },
	{ 74, 2 },
	{ 75, 2 },
	{ 76, 2 },
	{ 77, 2 },
	{ 78, 2 },
	{ 79, 2 },
	{ 81, 2 },
	{ 82, 2 },
	{ 83, 2 },
	{ 84, 2 },
	{ 85, 2 },
	{ 86, 2 },
	{ 87, 2 },
	{ 88, 2 },
	{ 90, 2 },
	{ 95, 2 },
	{ 96, 2 },
	{ 97, 2 },
	{ 99, 2 },
	{ 100, 2 },
	{ 104, 2 },
	{ 172, 3 },
	{ 172, 20 },
	{ 172, 21 },
	{ 146, 34 },
	{ 146, 31 },
	{ 146, 9 },
	{ 190, 4 },
	{ 190, 45 },
	{ 142, 6 },
	{ 258, 7 },
	{ 258, 8 },
	{ 21, 10 },
	{ 7, 11 },
	{ 216, 13 },
	{ 64, 14 },
	{ 36, 14 },
	{ 49, 14 },
	{ 8, 16 },
	{ 13, 17 },
	{ 20, 22 },
	{ 126, 23 },
	{ 26, 25 },
	{ 256, 25 },
	{ 237, 26 },
	{ 237, 32 },
	{ 218, 28 },
	{ 164, 29 },
	{ 137, 30 },
	{ 11, 36 },
	{ 24, 37 },
	{ 235, 37 },
	{ 93, 38 },
	{ 109, 39 },
	{ 110, 40 },
	{ 152, 40 },
	{ 154, 40 },
	{ 111, 41 },
	{ 149, 43 },
	{ 112, 42 },
	{ 150, 42 },
	{ 151, 42 },
	{ 153, 42 },
	{ 192, 42 },
	{ 204, 42 },
	{ 207, 42 },
	{ 209, 42 },
	{ 213, 42 },
	{ 240, 42 },
	{ 218, 44 },
	{ 130, 46 },
	{ 93, 47 },
	{ 268, 12 },
E 2
I 2
	{ 236,	HORSE },
	{ 237,	CAR },
	{ 275,	POT },
	{ 275,	BAR },
	{ 275,	BLOCK },
	{ 260,	COINS },
	{ 266,	DARK },
	{ 235,	TIMER },
	{ 51,	51 },
	{ 59,	51 },
	{ 48,	51 },
	{ 66,	52 },
	{ 65,	52 },
	{ 19,	BOMB },
	{ 167,	NATIVE },
	{ 21,	KNIFE },
	{ 30,	KNIFE },
	{ 30,	CLEAVER },
	{ 260,	SWORD },
	{ 70,	LAND },
	{ 71,	LAND },
	{ 72,	LAND },
	{ 73,	LAND },
	{ 74,	LAND },
	{ 75,	LAND },
	{ 76,	LAND },
	{ 77,	LAND },
	{ 78,	LAND },
	{ 79,	LAND },
	{ 81,	LAND },
	{ 82,	LAND },
	{ 83,	LAND },
	{ 84,	LAND },
	{ 85,	LAND },
	{ 86,	LAND },
	{ 87,	LAND },
	{ 88,	LAND },
	{ 90,	LAND },
	{ 95,	LAND },
	{ 96,	LAND },
	{ 97,	LAND },
	{ 99,	LAND },
	{ 100,	LAND },
	{ 104,	LAND },
	{ 172,	WOODSMAN },
	{ 172,	DEADWOOD },
	{ 172,	MALLET },
	{ 146,	ELF },
	{ 146,	HALBERD },
	{ 146,	SHIELD },
	{ 190,	TWO_HANDED },
	{ 190,	POTION },
	{ 142,	BROAD },
	{ 258,	MAIL },
	{ 258,	HELM },
	{ 21,	MAID },
	{ 7,	VIPER },
	{ 216,	SHOES },
	{ 64,	CYLON },
	{ 36,	CYLON },
	{ 49,	CYLON },
	{ 8,	ROBE },
	{ 13,	AMULET },
	{ 20,	LASER },
	{ 126,	BATHGOD },
	{ 26,	GRENADE },
	{ 256,	GRENADE },
	{ 237,	CHAIN },
	{ 237,	COMPASS },
	{ 218,	LEVIS },
	{ 164,	MACE },
	{ 137,	SHOVEL },
	{ 11,	COINS },
	{ 24,	MATCHES },
	{ 235,	MATCHES },
	{ 93,	MAN },
	{ 109,	PAPAYAS },
	{ 110,	PINEAPPLE },
	{ 152,	PINEAPPLE },
	{ 154,	PINEAPPLE },
	{ 111,	KIWI },
	{ 149,	MANGO },
	{ 112,	COCONUTS },
	{ 150,	COCONUTS },
	{ 151,	COCONUTS },
	{ 153,	COCONUTS },
	{ 192,	COCONUTS },
	{ 204,	COCONUTS },
	{ 207,	COCONUTS },
	{ 209,	COCONUTS },
	{ 213,	COCONUTS },
	{ 240,	COCONUTS },
	{ 218,	RING },
	{ 130,	BRACELET },
	{ 93,	GIRL },
	{ 268,	LAMPON },
E 2
	0
};
E 1

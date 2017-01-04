h12556
s 00010/00005/00031
d D 3.16 88/06/29 21:37:42 bostic 16 15
c install approved copyright notice
e
s 00013/00007/00023
d D 3.15 88/02/21 13:38:09 bostic 15 14
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00024
d D 3.14 85/04/24 16:16:33 edward 14 13
c copyright messages
e
s 00000/00013/00024
d D 3.13 85/01/18 11:11:10 edward 13 12
c tt_tab moved to ttinit.c
e
s 00002/00000/00035
d D 3.12 84/11/21 00:30:14 edward 12 11
c tth29 added
e
s 00001/00001/00034
d D 3.11 84/05/23 01:58:44 edward 11 10
c new sccs id
e
s 00000/00012/00035
d D 3.10 84/03/23 18:17:07 edward 10 9
c compile with -R
e
s 00001/00001/00046
d D 3.9 84/03/03 22:46:46 edward 9 8
c interrupt driven input
e
s 00001/00001/00046
d D 3.8 83/12/17 12:39:38 edward 8 7
c got rid of pgrp in struct ww_tty
e
s 00002/00000/00045
d D 3.7 83/09/17 17:10:18 edward 7 6
c freedom 100
e
s 00002/00002/00043
d D 3.6 83/09/15 12:23:20 edward 6 5
c reworked tt stuff
e
s 00000/00000/00045
d D 3.5 83/09/15 10:10:01 edward 5 4
c Now uses screen address for all buffers.
e
s 00001/00000/00044
d D 3.4 83/08/17 15:35:32 edward 4 3
c nicer termcap interface and use vs and ve strings in tth19.c
e
s 00001/00000/00043
d D 3.3 83/08/15 18:15:07 edward 3 2
c tt cleanup
e
s 00000/00000/00043
d D 3.2 83/08/11 17:24:27 edward 2 1
i
c last few day's work
e
s 00043/00000/00000
d D 3.1 83/08/09 18:37:49 edward 1 0
c date and time created 83/08/09 18:37:49 by edward
e
u
U
t
T
I 1
D 15
#ifndef lint
D 11
static	char *sccsid = "%W% %E%";
E 11
I 11
static char sccsid[] = "%W% %G%";
E 11
#endif

E 15
I 14
/*
D 15
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 15
I 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 */
I 15

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 15

E 14
#include "ww.h"
I 3
D 13
#include "tt.h"
E 3

D 10
struct ww wwhead = {
	&wwhead, &wwhead
};

struct ww_tty wwnewtty = {
	{ 0, 0, -1, -1, 0 },
	{ -1, -1, -1, -1, -1, -1 },
	{ -1, -1, -1, -1, -1, -1 },
D 8
	0, 0, 0
E 8
I 8
D 9
	0, 0
E 9
I 9
	0, 0, 0
E 9
E 8
};

E 10
int tt_h19();
I 12
int tt_h29();
E 12
I 7
int tt_f100();
E 7
int tt_generic();
struct tt_tab tt_tab[] = {
D 6
	{ "h19", 3, tt_h19 },
	{ "generic", 0, tt_generic },
E 6
I 6
	{ "h19",	3, tt_h19 },
I 12
	{ "h29",	3, tt_h29 },
E 12
I 7
	{ "f100",	4, tt_f100 },
E 7
	{ "generic",	0, tt_generic },
E 6
	0
};
E 13
I 4
D 10
char *tt_strp = tt_strings;
E 10
E 4

int wwbaudmap[] = {
	0,
	50,
	75,
	110,
	134,
	150,
	200,
	300,
	600,
	1200,
	1800,
	2400,
	4800,
	9600,
	19200,
	38400
};
E 1

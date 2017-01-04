h06046
s 00010/00005/00121
d D 3.5 88/06/29 21:35:24 bostic 5 4
c install approved copyright notice
e
s 00013/00007/00113
d D 3.4 88/02/21 13:36:32 bostic 4 3
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00114
d D 3.3 85/04/24 16:23:51 edward 3 2
c copyright messages
e
s 00001/00001/00113
d D 3.2 84/05/23 02:01:08 edward 2 1
c new sccs id
e
s 00114/00000/00000
d D 3.1 84/04/08 12:23:11 edward 1 0
c date and time created 84/04/08 12:23:11 by edward
e
u
U
t
T
I 1
D 4
#ifndef lint
D 2
static	char *sccsid = "%W% %E%";
E 2
I 2
static char sccsid[] = "%W% %G%";
E 2
#endif

E 4
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
I 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

E 3
#include "char.h"

char _cmap[] = {
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^@ - ^C */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^D - ^G */
	_C,		_C|_P,		_C,		_C|_U,	/* ^H - ^K */
	_C|_U,		_C,		_C|_U,		_C|_U,	/* ^L - ^O */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^P - ^S */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^T - ^W */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^U - ^[ */
	_C|_U,		_C|_U,		_C|_U,		_C|_U,	/* ^\ - ^_ */

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,

	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_P|_U,
	_P|_U,		_P|_U,		_P|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,

	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U,
	_C|_U,		_C|_U,		_C|_U,		_C|_U
};

char *_unctrl[] = {
	"^@",	"^A",	"^B",	"^C",	"^D",	"^E",	"^F",	"^G",
	"^H",	"^I",	"^J",	"^K",	"^L",	"^M",	"^N",	"^O",
	"^P",	"^Q",	"^R",	"^S",	"^T",	"^U",	"^V",	"^W",
	"^X",	"^Y",	"^Z",	"^[",	"^\\",	"^]",	"^^",	"^_",
	" ",	"!",	"\"",	"#",	"$",	"%",	"&",	"'",
	"(",	")",	"*",	"+",	",",	"-",	".",	"/",
	"0",	"1",	"2",	"3",	"4",	"5",	"6",	"7",
	"8",	"9",	":",	";",	"<",	"=",	">",	"?",
	"@",	"A",	"B",	"C",	"D",	"E",	"F",	"G",
	"H",	"I",	"J",	"K",	"L",	"M",	"N",	"O",
	"P",	"Q",	"R",	"S",	"T",	"U",	"V",	"W",
	"X",	"Y",	"Z",	"[",	"\\",	"]",	"^",	"_",
	"`",	"a",	"b",	"c",	"d",	"e",	"f",	"g",
	"h",	"i",	"j",	"k",	"l",	"m",	"n",	"o",
	"p",	"q",	"r",	"s",	"t",	"u",	"v",	"w",
	"x",	"y",	"z",	"{",	"|",	"}",	"~",	"^?",
	"\\200","\\201","\\202","\\203","\\204","\\205","\\206","\\207",
	"\\210","\\211","\\212","\\213","\\214","\\215","\\216","\\217",
	"\\220","\\221","\\222","\\223","\\224","\\225","\\226","\\227",
	"\\230","\\231","\\232","\\233","\\234","\\235","\\236","\\237",
	"\\240","\\241","\\242","\\243","\\244","\\245","\\246","\\247",
	"\\250","\\251","\\252","\\253","\\254","\\255","\\256","\\257",
	"\\260","\\261","\\262","\\263","\\264","\\265","\\266","\\267",
	"\\270","\\271","\\272","\\273","\\274","\\275","\\276","\\277",
	"\\300","\\301","\\302","\\303","\\304","\\305","\\306","\\307",
	"\\310","\\311","\\312","\\313","\\314","\\315","\\316","\\317",
	"\\320","\\321","\\322","\\323","\\324","\\325","\\326","\\327",
	"\\330","\\331","\\332","\\333","\\334","\\335","\\336","\\337",
	"\\340","\\341","\\342","\\343","\\344","\\345","\\346","\\347",
	"\\350","\\351","\\352","\\353","\\354","\\355","\\356","\\357",
	"\\360","\\361","\\362","\\363","\\364","\\365","\\366","\\367",
	"\\370","\\371","\\372","\\373","\\374","\\375","\\376","\\377"
};
E 1

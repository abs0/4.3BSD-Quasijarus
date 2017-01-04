h63158
s 00007/00006/00092
d D 7.7 03/04/13 15:18:52 msokolov 15 14
c 8-bit ex
e
s 00007/00000/00091
d D 7.6 87/03/09 12:46:46 conrad 14 13
c make ex/vi work on vms
e
s 00001/00000/00090
d D 7.5 85/08/29 17:33:56 bloom 13 12
c only use .exrc if owned by user or option sourceany is used
e
s 00001/00001/00089
d D 7.4 85/06/07 18:19:05 bloom 12 11
c fix sccsid and copyright for xstr
e
s 00010/00002/00080
d D 7.3 85/05/31 13:53:55 dist 11 9
c Add copyright
e
s 00010/00002/00077
d D 5.1.1.1 85/05/31 11:58:40 dist 10 6
c Add copyright
e
s 00001/00000/00081
d D 7.2 84/04/17 10:05:50 peter 9 8
c add the ``modeline'' binary option to enable the search for modelines.
e
s 00006/00004/00075
d D 7.1 81/07/08 22:29:33 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00079
d D 6.1 80/10/19 01:20:51 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00079
d D 5.1 80/08/20 16:09:48 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00077
d D 4.2 80/08/01 20:39:51 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00004/00002/00074
d D 4.1 80/08/01 00:11:55 mark 4 3
c release 3.4, June 24, 1980
e
s 00020/00010/00056
d D 3.1 80/07/31 23:37:41 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00001/00001/00065
d D 2.1 80/07/31 23:18:22 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00066/00000/00000
d D 1.1 80/07/31 23:00:13 mark 1 0
c date and time created 80/07/31 23:00:13 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
D 10
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 10
E 8
I 8
D 11
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char *sccsid = "%W% (Berkeley) %G%";
E 12
#endif not lint

E 11
E 8
E 5
#include "ex.h"
#include "ex_tty.h"

/*
 * Initialization of option values.
 * The option #defines in ex_vars.h are made
 * from this file by the script makeoptions.
I 3
 *
 * These initializations are done char by char instead of as strings
 * to confuse xstr so it will leave them alone.
E 3
 */
D 3
char	direct[32] =
E 3
I 3
D 15
char	direct[ONMSZ] =
E 15
I 15
u_char	direct[ONMSZ] =
E 15
I 14
#ifdef vms
	{'t', 'm', 'p', ':'}; 
#else
E 14
E 3
D 8
	{ '/', 't', 'm', 'p' };
E 8
I 8
	{'/', 't', 'm', 'p'}; 
I 14
#endif
E 14
E 8
D 3
char	sections[32] = {
	'N', 'H', 'S', 'H',				/* -ms macros */
	'H', ' ', 'H', 'U'				/* -mm macros */
};
char	paragraphs[32] = {
E 3
I 3
D 15
char	paragraphs[ONMSZ] = {
E 15
I 15
u_char	paragraphs[ONMSZ] = {
E 15
E 3
	'I', 'P', 'L', 'P', 'P', 'P', 'Q', 'P',		/* -ms macros */
	'P', ' ', 'L', 'I',				/* -mm macros */
I 8
	'p', 'p', 'l', 'p', 'i', 'p',			/* -me macros */
E 8
	'b', 'p'					/* bare nroff */
};
D 3
char	shell[32] =
E 3
I 3
D 15
char	sections[ONMSZ] = {
E 15
I 15
u_char	sections[ONMSZ] = {
E 15
	'N', 'H', 'S', 'H',				/* -ms macros */
D 8
	'H', ' ', 'H', 'U'				/* -mm macros */
E 8
I 8
	'H', ' ', 'H', 'U',				/* -mm macros */
	'n', 'h', 's', 'h'				/* -me macros */
E 8
};
D 15
char	shell[ONMSZ] =
E 15
I 15
u_char	shell[ONMSZ] =
E 15
E 3
	{ '/', 'b', 'i', 'n', '/', 's', 'h' };
D 3
char	ttytype[16] =
E 3
I 3
D 15
char	tags[ONMSZ] = {
E 15
I 15
u_char	tags[ONMSZ] = {
E 15
	't', 'a', 'g', 's', ' ',
	'/', 'u', 's', 'r', '/', 'l', 'i', 'b', '/', 't', 'a', 'g', 's'
};
D 15
char	ttytype[ONMSZ] =
E 15
I 15
u_char	ttytype[ONMSZ] =
E 15
E 3
	{ 'd', 'u', 'm', 'b' };

short	COLUMNS = 80;
short	LINES = 24;

struct	option options[NOPTS + 1] = {
	"autoindent",	"ai",	ONOFF,		0,	0,	0,
	"autoprint",	"ap",	ONOFF,		1,	1,	0,
	"autowrite",	"aw",	ONOFF,		0,	0,	0,
	"beautify",	"bf",	ONOFF,		0,	0,	0,
	"directory",	"dir",	STRING,		0,	0,	direct,
	"edcompatible",	"ed",	ONOFF,		0,	0,	0,
I 15
	"eightbit",	"eight",ONOFF,		0,	0,	0,
E 15
	"errorbells",	"eb",	ONOFF,		0,	0,	0,
	"hardtabs",	"ht",	NUMERIC,	8,	8,	0,
	"ignorecase",	"ic",	ONOFF,		0,	0,	0,
I 14
#ifndef	UNIX_SBRK
	"linelimit",	"ll",	NUMERIC,	2000,	2000,	0,
#endif
E 14
	"lisp",		0,	ONOFF,		0,	0,	0,
	"list",		0,	ONOFF,		0,	0,	0,
D 2
	"mapinput",	"mi",	ONOFF,		0,	0,	0,
E 2
	"magic",	0,	ONOFF,		1,	1,	0,
I 4
	"mesg",		0,	ONOFF,		1,	1,	0,
I 9
	"modeline",	0,	ONOFF,		0,	0,	0,
E 9
E 4
I 2
D 3
	"mapinput",	"mi",	ONOFF,		0,	0,	0,
E 3
E 2
	"number",	"nu",	ONOFF,		0,	0,	0,
	"open",		0,	ONOFF,		1,	1,	0,
	"optimize",	"opt",	ONOFF,		0,	0,	0,
	"paragraphs",	"para",	STRING,		0,	0,	paragraphs,
	"prompt",	0,	ONOFF,		1,	1,	0,
I 4
	"readonly",	"ro",	ONOFF,		0,	0,	0,
E 4
	"redraw",	0,	ONOFF,		0,	0,	0,
I 3
	"remap",	0,	ONOFF,		1,	1,	0,
E 3
	"report",	0,	NUMERIC,	5,	5,	0,
	"scroll",	"scr",	NUMERIC,	12,	12,	0,
	"sections",	"sect",	STRING,		0,	0,	sections,
	"shell",	"sh",	STRING,		0,	0,	shell,
	"shiftwidth",	"sw",	NUMERIC,	TABS,	TABS,	0,
	"showmatch",	"sm",	ONOFF,		0,	0,	0,
	"slowopen",	"slow",	ONOFF,		0,	0,	0,
I 13
	"sourceany",	0,	ONOFF,		0,	0,	0,
E 13
I 3
D 4
	"tags",		"tag",	STRING,		0,	0,	tags,
E 4
E 3
	"tabstop",	"ts",	NUMERIC,	TABS,	TABS,	0,
I 4
	"taglength",	"tl",	NUMERIC,	0,	0,	0,
	"tags",		"tag",	STRING,		0,	0,	tags,
E 4
D 3
	"ttytype",	"tty",	OTERM,		0,	0,	ttytype,
E 3
	"term",		0,	OTERM,		0,	0,	ttytype,
	"terse",	0,	ONOFF,		0,	0,	0,
I 3
	"timeout",	"to",	ONOFF,		1,	1,	0,
	"ttytype",	"tty",	OTERM,		0,	0,	ttytype,
D 4
	"undomacro",	"um",	ONOFF,		1,	1,	0,
E 4
E 3
	"warn",		0,	ONOFF,		1,	1,	0,
	"window",	"wi",	NUMERIC,	23,	23,	0,
	"wrapscan",	"ws",	ONOFF,		1,	1,	0,
	"wrapmargin",	"wm",	NUMERIC,	0,	0,	0,
	"writeany",	"wa",	ONOFF,		0,	0,	0,
	0,		0,	0,		0,	0,	0,
};
E 1

h57419
s 00038/00037/00008
d D 7.7 03/04/13 15:19:21 msokolov 14 13
c 8-bit ex
e
s 00001/00008/00044
d D 7.6 87/03/09 12:46:28 conrad 13 12
c make ex/vi work on vms
e
s 00014/00013/00038
d D 7.5 85/08/29 17:34:03 bloom 12 11
c only use .exrc if owned by user or option sourceany is used
e
s 00000/00000/00051
d D 7.4 85/05/31 15:59:42 dist 11 10
c Add copyright
e
s 00037/00029/00014
d D 7.3 85/05/31 15:20:41 bloom 10 9
c Add copyright notice 
c 
c Add modeline
e
s 00000/00000/00043
d D 7.2 81/07/26 20:05:00 mark 9 8
c fixes for 3b
e
s 00001/00001/00042
d D 7.1 81/07/08 22:32:53 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00043
d D 6.1 80/10/19 01:22:02 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00043
d D 5.1 80/08/20 16:13:20 mark 6 5
c Release 3.5, August 20, 1980
e
s 00001/00000/00042
d D 4.2 80/08/01 20:42:34 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00029/00027/00013
d D 4.1 80/08/01 00:17:08 mark 4 3
c release 3.4, June 24, 1980
e
s 00018/00015/00022
d D 3.1 80/07/31 23:40:55 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00002/00002/00035
d D 2.1 80/07/31 23:20:21 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00037/00000/00000
d D 1.1 80/07/31 23:00:41 mark 1 0
c date and time created 80/07/31 23:00:41 by mark
e
u
U
t
T
I 5
D 8
/*  sccs id  %W% %G% */
E 8
I 8
D 10
/*  sccs id  %W%	%G% */
E 10
I 10
D 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

E 13
I 13
	/*  sccs id   @(#)  ex_vars.h  @(#)makeoptions	6.4 5/31/85  */
E 13
E 10
E 8
E 5
I 1
#define AUTOINDENT      0
#define AUTOPRINT       1
#define AUTOWRITE       2
#define BEAUTIFY        3
#define DIRECTORY       4
#define EDCOMPATIBLE    5
D 14
#define ERRORBELLS      6
#define HARDTABS        7
#define IGNORECASE      8
#define LISP            9
#define LIST            10
D 2
#define MAPINPUT        11
#define MAGIC           12
E 2
I 2
#define MAGIC           11
D 3
#define MAPINPUT        12
E 2
#define NUMBER          13
#define OPEN            14
#define OPTIMIZE        15
#define PARAGRAPHS      16
#define PROMPT          17
#define REDRAW          18
E 3
I 3
D 4
#define NUMBER          12
#define OPEN            13
#define OPTIMIZE        14
#define PARAGRAPHS      15
#define PROMPT          16
#define REDRAW          17
#define REMAP           18
E 3
#define REPORT          19
#define SCROLL          20
#define SECTIONS        21
#define SHELL           22
#define SHIFTWIDTH      23
#define SHOWMATCH       24
#define SLOWOPEN        25
D 3
#define TABSTOP         26
#define TTYTYPE         27
E 3
I 3
#define TAGS            26
#define TABSTOP         27
E 3
#define TERM            28
#define TERSE           29
D 3
#define WARN            30
#define WINDOW          31
#define WRAPSCAN        32
#define WRAPMARGIN      33
#define WRITEANY        34
E 3
I 3
#define TIMEOUT         30
#define TTYTYPE         31
#define UNDOMACRO       32
#define WARN            33
#define WINDOW          34
#define WRAPSCAN        35
#define WRAPMARGIN      36
#define WRITEANY        37
E 4
I 4
#define MESG            12
D 10
#define NUMBER          13
#define OPEN            14
#define OPTIMIZE        15
#define PARAGRAPHS      16
#define PROMPT          17
#define READONLY        18
#define REDRAW          19
#define REMAP           20
#define REPORT          21
#define SCROLL          22
#define SECTIONS        23
#define SHELL           24
#define SHIFTWIDTH      25
#define SHOWMATCH       26
#define SLOWOPEN        27
#define TABSTOP         28
#define TAGLENGTH       29
#define TAGS            30
#define TERM            31
#define TERSE           32
#define TIMEOUT         33
#define TTYTYPE         34
#define WARN            35
#define WINDOW          36
#define WRAPSCAN        37
#define WRAPMARGIN      38
#define WRITEANY        39
E 10
I 10
#define MODELINE        13
#define NUMBER          14
#define OPEN            15
#define OPTIMIZE        16
#define PARAGRAPHS      17
#define PROMPT          18
#define READONLY        19
#define REDRAW          20
#define REMAP           21
#define REPORT          22
#define SCROLL          23
#define SECTIONS        24
#define SHELL           25
#define SHIFTWIDTH      26
#define SHOWMATCH       27
#define SLOWOPEN        28
D 12
#define TABSTOP         29
#define TAGLENGTH       30
#define TAGS            31
#define TERM            32
#define TERSE           33
#define TIMEOUT         34
#define TTYTYPE         35
#define WARN            36
#define WINDOW          37
#define WRAPSCAN        38
#define WRAPMARGIN      39
#define WRITEANY        40
E 12
I 12
#define SOURCEANY       29
#define TABSTOP         30
#define TAGLENGTH       31
#define TAGS            32
#define TERM            33
#define TERSE           34
#define TIMEOUT         35
#define TTYTYPE         36
#define WARN            37
#define WINDOW          38
#define WRAPSCAN        39
#define WRAPMARGIN      40
#define WRITEANY        41
E 14
I 14
#define EIGHTBIT        6
#define ERRORBELLS      7
#define HARDTABS        8
#define IGNORECASE      9
#define LISP            10
#define LIST            11
#define MAGIC           12
#define MESG            13
#define MODELINE        14
#define NUMBER          15
#define OPEN            16
#define OPTIMIZE        17
#define PARAGRAPHS      18
#define PROMPT          19
#define READONLY        20
#define REDRAW          21
#define REMAP           22
#define REPORT          23
#define SCROLL          24
#define SECTIONS        25
#define SHELL           26
#define SHIFTWIDTH      27
#define SHOWMATCH       28
#define SLOWOPEN        29
#define SOURCEANY       30
#define TABSTOP         31
#define TAGLENGTH       32
#define TAGS            33
#define TERM            34
#define TERSE           35
#define TIMEOUT         36
#define TTYTYPE         37
#define WARN            38
#define WINDOW          39
#define WRAPSCAN        40
#define WRAPMARGIN      41
#define WRITEANY        42
E 14
E 12
E 10
E 4
E 3

D 3
#define	NOPTS	35
E 3
I 3
D 4
#define	NOPTS	38
E 4
I 4
D 10
#define	NOPTS	40
E 10
I 10
D 12
#define	NOPTS	41
E 12
I 12
D 14
#define	NOPTS	42
E 14
I 14
#define	NOPTS	43
E 14
E 12
E 10
E 4
E 3
E 1

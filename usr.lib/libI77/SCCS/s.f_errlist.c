h51156
s 00001/00000/00042
d D 5.2 85/07/30 16:40:10 jerry 8 7
c implement namelist
e
s 00007/00001/00035
d D 5.1 85/06/07 23:46:35 kre 7 6
c Add copyright
e
s 00005/00005/00031
d D 1.6 85/06/04 20:51:29 libs 6 5
c update error messages.
e
s 00001/00001/00035
d D 1.5 85/05/02 22:05:56 libs 5 4
c F_ERSYS may also be opening more than system max. no. of files.
e
s 00002/00001/00034
d D 1.4 85/02/14 22:23:39 libs 4 3
c Improve error messages.
e
s 00001/00000/00034
d D 1.3 83/01/10 13:54:09 dlw 3 2
c added 123. DLW
e
s 00002/00003/00032
d D 1.2 81/02/27 15:18:44 dlw 2 1
c removed 'static' declaration (it was a bug!). DLW
e
s 00035/00000/00000
d D 1.1 81/02/27 13:09:50 dlw 1 0
c date and time created 81/02/27 13:09:50 by dlw
e
u
U
t
T
I 1
/*
D 7
char id_f_errlist[] = "%W%";
E 7
I 7
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
 *
I 7
 *	%W%	%G%
 */

/*
E 7
 * f77 I/O error messages
 */

D 2
static char *f_errlist[] =
E 2
I 2
char *f_errlist[] =
E 2
{
/* 100 */	"error in format",
/* 101 */	"illegal unit number",
D 6
/* 102 */	"formatted io not allowed",
/* 103 */	"unformatted io not allowed",
/* 104 */	"direct io not allowed",
/* 105 */	"sequential io not allowed",
E 6
I 6
/* 102 */	"formatted i/o not allowed",
/* 103 */	"unformatted i/o not allowed",
/* 104 */	"direct i/o not allowed",
/* 105 */	"sequential i/o not allowed",
E 6
/* 106 */	"can't backspace file",
/* 107 */	"off beginning of record",
/* 108 */	"can't stat file",
/* 109 */	"no * after repeat count",
/* 110 */	"off end of record",
/* 111 */	"truncation failed",
/* 112 */	"incomprehensible list input",
/* 113 */	"out of free space",
/* 114 */	"unit not connected",
D 4
/* 115 */	"read unexpected character",
E 4
I 4
/* 115 */	"invalid data for integer format term",
E 4
D 6
/* 116 */	"blank logical input field",
E 6
I 6
/* 116 */	"invalid data for logical format term",
E 6
/* 117 */	"'new' file exists",
/* 118 */	"can't find 'old' file",
D 5
/* 119 */	"unknown system error",
E 5
I 5
/* 119 */	"opening too many files or unknown system error",
E 5
/* 120 */	"requires seek ability",
/* 121 */	"illegal argument",
/* 122 */	"negative repeat count",
I 3
/* 123 */	"illegal operation for unit",
I 4
/* 124 */	"invalid data for d,e,f, or g format term",
I 8
/* 125 */	"illegal input for namelist",
E 8
E 4
E 3
};

D 2
static int f_nerr = (sizeof(f_errlist)/sizeof(char *));

E 2
I 2
int f_nerr = (sizeof(f_errlist)/sizeof(char *));
E 2
E 1

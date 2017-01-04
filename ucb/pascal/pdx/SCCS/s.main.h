h07233
s 00004/00004/00021
d D 5.3 88/01/03 00:33:20 bostic 7 6
c neither K&R or ANSI C allow untyped function declarations
e
s 00001/00001/00024
d D 5.2 85/06/07 19:53:19 mckusick 6 5
c cleanup after dist
e
s 00008/00004/00017
d D 5.1 85/06/06 16:08:09 dist 5 4
c Add copyright
e
s 00001/00000/00020
d D 1.4 82/05/19 20:16:43 linton 4 3
c added "isterm" macro
e
s 00001/00000/00019
d D 1.3 82/01/20 17:04:29 linton 3 2
c added quit routine
e
s 00001/00001/00018
d D 1.2 82/01/18 22:14:57 linton 2 1
c sccsid
e
s 00019/00000/00000
d D 1.1 82/01/18 19:02:37 linton 1 0
c date and time created 82/01/18 19:02:37 by linton
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 2

E 5
/*
I 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

D 6
*
E 6
I 6
/*
E 6
E 5
 * Definitions for main program.
 *
 * The main program just handles the command arguments and then
 * gives control to the command module.  It's also the center of
 * error recovery, since non-fatal errors longjmp into the main routine.
 */

BOOLEAN opt[26];	/* true if command line option given */

#define option(c)	opt[(c)-'a']
I 4
#define isterm(file)	(option('i') || isatty(fileno(file)))
E 4

D 7
main();			/* debugger main routine */
init();			/* read in source and object data */
erecover();		/* does non-local goto for error recovery */
I 3
quit();			/* clean-up before exiting */
E 7
I 7
int main();		/* debugger main routine */
int init();		/* read in source and object data */
int erecover();		/* does non-local goto for error recovery */
int quit();		/* clean-up before exiting */
E 7
E 3
E 1

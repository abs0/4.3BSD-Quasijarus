h48568
s 00003/00002/00039
d D 4.3 83/08/11 20:01:25 sam 3 2
c fix sccs keyword lines
e
s 00000/00003/00041
d D 4.2 81/05/15 00:53:57 root 2 1
c new attempt
e
s 00044/00000/00000
d D 4.1 81/05/14 15:19:48 root 1 0
c date and time created 81/05/14 15:19:48 by root
e
u
U
t
T
I 1
D 3
#
E 3
I 3
#ifndef lint
static	char sccsid[] = "%W% %G%";
#endif
E 3
/*
 *
 *	UNIX debugger
 *
 */

#include	"mac.h"
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
#include	"mode.h"

MSG		VERSION =  "\nVERSION VM/VAX%I%	DATE %G%\n";

MSG		BADMOD	=  "bad modifier";
MSG		BADCOM	=  "bad command";
MSG		BADSYM	=  "symbol not found";
MSG		BADLOC	=  "automatic variable not found";
MSG		NOCFN	=  "c routine not found";
MSG		NOMATCH	=  "cannot locate value";
MSG		NOBKPT	=  "no breakpoint set";
MSG		BADKET	=  "unexpected ')'";
MSG		NOADR	=  "address expected";
MSG		NOPCS	=  "no process";
MSG		BADVAR	=  "bad variable";
D 2
MSG		BADTXT	=  "text address not found";
MSG		BADDAT	=  "data address not found";
MSG		ODDADR	=  "odd address";
E 2
MSG		EXBKPT	=  "too many breakpoints";
MSG		A68BAD	=  "bad a68 frame";
MSG		A68LNK	=  "bad a68 link";
MSG		ADWRAP	=  "address wrap around";
MSG		BADEQ	=  "unexpected `='";
MSG		BADWAIT	=  "wait error: process disappeared!";
MSG		ENDPCS	=  "process terminated";
MSG		NOFORK	=  "try again";
MSG		BADSYN	=  "syntax error";
MSG		NOEOR	=  "newline expected";
MSG		SZBKPT	=  "bkpt: command too long";
MSG		BADFIL	=  "bad file format";
MSG		BADNAM	=  "not enough space for symbols";
MSG		LONGFIL	=  "filename too long";
MSG		NOTOPEN	=  "cannot open";
MSG		BADMAG	=  "bad core magic number";
MSG		TOODEEP =  "$<< nesting too deep";
E 1

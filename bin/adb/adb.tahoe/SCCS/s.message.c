h17506
s 00038/00000/00000
d D 1.1 86/02/25 16:04:45 sam 1 0
c date and time created 86/02/25 16:04:45 by sam
e
u
U
t
T
I 1
#ifndef lint
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
 *
 *	UNIX debugger
 *
 */

#include	"mac.h"
#include	"mode.h"

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
MSG		BADTXT	=  "text address not found";
MSG		BADDAT	=  "data address not found";
MSG		EXBKPT	=  "too many breakpoints";
MSG		ADWRAP	=  "address wrap around";
MSG		BADEQ	=  "unexpected `='";
MSG		BADWAIT	=  "wait error: process disappeared!";
MSG		ENDPCS	=  "process terminated";
MSG		NOFORK	=  "try again";
MSG		BADSYN	=  "syntax error";
MSG		NOEOR	=  "newline expected";
MSG		SZBKPT	=  "bkpt: command too long";
MSG		LONGFIL	=  "filename too long";
MSG		NOTOPEN	=  "cannot open";
MSG		TOODEEP =  "$<< nesting too deep";
E 1

h50195
s 00000/00000/00061
d D 4.2 82/08/17 13:24:59 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00061/00000/00000
d D 4.1 80/10/09 23:57:41 bill 1 0
c date and time created 80/10/09 23:57:41 by bill
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
#
/*
 *
 *	UNIX debugger
 *
 */



#include	"mac.h"
#include	"mode.h"


MSG		BADMOD	=  "bad modifier";
MSG		NOBKPT	=  "no breakpoint set";
MSG		NOPCS	=  "no process";
MSG		BADTXT	=  "text address not found";
MSG		BADDAT	=  "data address not found";
MSG		EXBKPT	=  "too many breakpoints";
MSG		BADWAIT	=  "wait error: process disappeared!";
MSG		ENDPCS	=  "process terminated";
MSG		NOFORK	=  "try again";
MSG		SZBKPT	=  "bkpt: command too long";
MSG		BADMAG	=  "bad core magic number";

STRING		signals[] = {
	"",
	"hangup",
	"interrupt",
	"quit",
	"illegal instruction",
	"trace/BPT",
	"IOT",
	"EMT",
	"floating exception",
	"killed",
	"bus error",
	"memory fault",
	"bad system call",
	"broken pipe",
	"alarm call",
	"terminated",
	"signal 16",
	"stop (signal)",
	"stop (tty)",
	"continue (signal)",
	"child termination",
	"stop (tty input)",
	"stop (tty output)",
	"input available (signal)",
	"cpu timelimit",
	"file sizelimit",
	"signal 26",
	"signal 27",
	"signal 28",
	"signal 29",
	"signal 30",
	"signal 31",
};
int	nsig = sizeof (signals)/sizeof (signals[0]);
E 1

h53876
s 00002/00000/00090
d D 1.4 88/12/22 13:13:53 sam 4 3
c use syscall for doing syswrite stuff -- more portable?
e
s 00002/00002/00088
d D 1.3 88/12/22 12:55:04 sam 3 2
c use jmp_buf
e
s 00003/00002/00087
d D 1.2 87/02/15 16:19:34 lepreau 2 1
c modern syntax for asgops and inits; sccs keywords
e
s 00089/00000/00000
d D 1.1 87/02/15 16:16:42 lepreau 1 0
c date and time created 87/02/15 16:16:42 by lepreau
e
u
U
t
T
I 2
static char Sccsid[] = "%W%	%G%";

E 2
I 1
# include	"../hdr/macros.h"
# include	"../hdr/fatal.h"
I 4
#include <sys/syscall.h>
#define	syswrite(a,b,c)	syscall(SYS_write,a,b,c)
E 4
D 2
SCCSID(@(#)fatal	2.2);
E 2

/*
	General purpose error handler.
	Typically, low level subroutines which detect error conditions
	(an open or create routine, for example) return the
	value of calling fatal with an appropriate error message string.
	E.g.,	return(fatal("can't do it"));
	Higher level routines control the execution of fatal
	via the global word Fflags.
	The macros FSAVE and FRSTR in <fatal.h> can be used by higher
	level subroutines to save and restore the Fflags word.
 
	The argument to fatal is a pointer to an error message string.
	The action of this routine is driven completely from
	the "Fflags" global word (see <fatal.h>).
	The following discusses the interpretation of the various bits
	of Fflags.
 
	The FTLMSG bit controls the writing of the error
	message on file descriptor 2.  The message is preceded
	by the string "ERROR: ", unless the global character pointer
	"Ffile" is non-zero, in which case the message is preceded
	by the string "ERROR [<Ffile>]: ".  A newline is written
	after the user supplied message.
 
	If the FTLCLN bit is on, clean_up is called with an
	argument of 0 (see clean.c).
 
	If the FTLFUNC bit is on, the function pointed to by the global
	function pointer "Ffunc" is called with the user supplied
	error message pointer as argument.
	(This feature can be used to log error messages).
 
	The FTLACT bits determine how fatal should return.
	If the FTLJMP bit is on longjmp(Fjmp) is
D 3
	called (Fjmp is a global vector of 10 words, see
E 3
I 3
	called (Fjmp is a global vector of n words, see
E 3
	setjmp, longjmp documentation).
 
	If the FTLEXIT bit is on the value of userexit(1) is
	passed as an argument to exit(II)
	(see userexit.c).
 
	If none of the FTLACT bits are on
	(the default value for Fflags is 0), the global word
	"Fvalue" (initialized to -1) is returned.
 
	If all fatal globals have their default values, fatal simply
	returns -1.
*/

int	Fcnt;
int	Fflags;
char	*Ffile;
D 2
int	Fvalue	-1;
E 2
I 2
int	Fvalue = -1;
E 2
int	(*Ffunc)();
D 3
int	Fjmp[10];
E 3
I 3
jmp_buf	Fjmp;
E 3


fatal(msg)
char *msg;
{
	++Fcnt;
	if (Fflags & FTLMSG) {
		syswrite(2,"ERROR",5);
		if (Ffile) {
			syswrite(2," [",2);
			syswrite(2,Ffile,length(Ffile));
			syswrite(2,"]",1);
		}
		syswrite(2,": ",2);
		syswrite(2,msg,length(msg));
		syswrite(2,"\n",1);
	}
	if (Fflags & FTLCLN)
		clean_up(0);
	if (Fflags & FTLFUNC)
		(*Ffunc)(msg);
	switch (Fflags & FTLACT) {
	case FTLJMP:
		longjmp(Fjmp, 1);
	case FTLEXIT:
		exit(userexit(1));
	case FTLRET:
		return(Fvalue);
	}
}
E 1

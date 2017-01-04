h37053
s 00002/00000/00086
d D 1.3 88/12/22 13:13:54 sam 3 2
c use syscall for doing syswrite stuff -- more portable?
e
s 00005/00004/00081
d D 1.2 87/02/15 16:19:39 lepreau 2 1
c modern syntax for asgops and inits; sccs keywords
e
s 00085/00000/00000
d D 1.1 87/02/15 16:16:44 lepreau 1 0
c date and time created 87/02/15 16:16:44 by lepreau
e
u
U
t
T
I 2
static char Sccsid[] = "%W%	%G%";

E 2
I 1
# include	"signal.h"
#undef NSIG
# ifdef PWB
#define NSIG 16
# else
#define NSIG 4
# endif
# include	"../hdr/macros.h"
I 3
#include <sys/syscall.h>
#define	syswrite(a,b,c)	syscall(SYS_write,a,b,c)
E 3
D 2
SCCSID(@(#)setsig	2.1);
E 2

/*
	General-purpose signal setting routine.
	All non-ignored, non-caught signals are caught.
	If a signal other than hangup, interrupt, or quit is caught,
	a "user-oriented" message is printed on file descriptor 2 with
	a number for help(I).
	If hangup, interrupt or quit is caught, that signal	
	is set to ignore.
	Termination is like that of "fatal",
	via "clean_up(sig)" (sig is the signal number)
	and "exit(userexit(1))".
 
	If the file "dump.core" exists in the current directory
	the function commits
	suicide to produce a core dump
	(after calling clean_up, but before calling userexit).
*/


D 2
char	*Mesg[NSIG] {
E 2
I 2
char	*Mesg[NSIG] = {
E 2
	0,
	0,	/* Hangup */
	0,	/* Interrupt */
	0,	/* Quit */
# ifdef PWB
	"Illegal instruction",
	"Trace/BPT trap",
	"IOT trap",
	"EMT trap",
	"Floating exception",
	"Killed",
	"Bus error",
	"Memory fault",
	"Bad system call",
	"Broken pipe",
	"Alarm clock",
	"Terminated"
# endif PWB
};


setsig()
{
	extern int setsig1();
	register int j, n;

	for (j=1; j<NSIG; j++)
		if (n=signal(j,setsig1))
			signal(j,n);
}


D 2
static char preface[]	"SIGNAL: ";
static char endmsg[]	" (ut12)\n";
E 2
I 2
static char preface[] = "SIGNAL: ";
static char endmsg[] = " (ut12)\n";
E 2

setsig1(sig)
int sig;
{
# ifndef PWB
	sig = 2;
# endif PWB
	if (Mesg[sig]) {
		syswrite(2,preface,length(preface));
		syswrite(2,Mesg[sig],length(Mesg[sig]));
		syswrite(2,endmsg,length(endmsg));
	}
	else
		signal(sig,1);
	clean_up(sig);
	if(open("dump.core",0) > 0) {
		signal(SIGIOT,0);
		abort();
	}
	exit(userexit(1));
}
E 1

h07944
s 00007/00002/00103
d D 6.2 86/05/12 01:00:58 karels 3 2
c update, correct, rephrase and re-propose
e
s 00000/00001/00105
d D 6.1 86/05/08 12:26:30 mckusick 2 1
c format updates for 4.3BSD
e
s 00106/00000/00000
d D 5.1 86/05/08 00:02:50 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1983 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 2
.\" %M% %I% %E%
E 2
.sh "Timers
.NH 3
Real time
.PP
The system's notion of the current Greenwich time and the current time
zone is set and returned by the call by the calls:
.DS
#include <sys/time.h>

settimeofday(tvp, tzp);
struct timeval *tp;
struct timezone *tzp;

gettimeofday(tp, tzp);
result struct timeval *tp;
result struct timezone *tzp;
.DE
D 3
where the structures are defined in <sys/time.h> as:
E 3
I 3
where the structures are defined in \fI<sys/time.h>\fP as:
E 3
.DS
._f
struct timeval {
	long	tv_sec;	/* seconds since Jan 1, 1970 */
	long	tv_usec;	/* and microseconds */
};

struct timezone {
	int	tz_minuteswest;	/* of Greenwich */
	int	tz_dsttime;	/* type of dst correction to apply */
};
.DE
I 3
The precision of the system clock is hardware dependent.
E 3
Earlier versions of UNIX contained only a 1-second resolution version
of this call, which remains as a library routine:
.DS
time(tvsec)
result long *tvsec;
.DE
returning only the tv_sec field from the \fIgettimeofday\fP call.
.NH 3
Interval time
.PP
The system provides each process with three interval timers,
D 3
defined in <sys/time.h>:
E 3
I 3
defined in \fI<sys/time.h>\fP:
E 3
.DS
._d
#define	ITIMER_REAL	0	/* real time intervals */
#define	ITIMER_VIRTUAL	1	/* virtual time intervals */
#define	ITIMER_PROF	2	/* user and system virtual time */
.DE
The ITIMER_REAL timer decrements
in real time.  It could be used by a library routine to
maintain a wakeup service queue.  A SIGALRM signal is delivered
when this timer expires.
.PP
The ITIMER_VIRTUAL timer decrements in process virtual time.
It runs only when the process is executing.  A SIGVTALRM signal
is delivered when it expires.
.PP
The ITIMER_PROF timer decrements both in process virtual time and when
the system is running on behalf of the process.
It is designed to be used by processes to statistically profile
their execution.
A SIGPROF signal is delivered when it expires.
.PP
A timer value is defined by the \fIitimerval\fP structure:
.DS
._f
struct itimerval {
	struct	timeval it_interval;	/* timer interval */
	struct	timeval it_value;	/* current value */
};
.DE
and a timer is set or read by the call:
.DS
getitimer(which, value);
int which; result struct itimerval *value;

setitimer(which, value, ovalue);
int which; struct itimerval *value; result struct itimerval *ovalue;
.DE
The third argument to \fIsetitimer\fP specifies an optional structure
to receive the previous contents of the interval timer.
A timer can be disabled by specifying a timer value of 0.
.PP
The system rounds argument timer intervals to be not less than the
resolution of its clock.  This clock resolution can be determined
by loading a very small value into a timer and reading the timer back to
see what value resulted.
.PP
The \fIalarm\fP system call of earlier versions of UNIX is provided
as a library routine using the ITIMER_REAL timer.  The process
profiling facilities of earlier versions of UNIX
remain because
it is not always possible to guarantee
the automatic restart of system calls after 
receipt of a signal.
I 3
The \fIprofil\fP call arranges for the kernel to begin gathering
execution statistics for a process:
E 3
.DS
profil(buf, bufsize, offset, scale);
result char *buf; int bufsize, offset, scale;
.DE
I 3
This begins sampling of the program counter, with statistics maintained
in the user-provided buffer.
E 3
E 1

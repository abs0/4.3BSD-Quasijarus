h54440
s 00001/00001/00066
d D 6.4 86/04/28 19:08:43 bloom 5 4
c more comments about syslog, phrasing cleanup
e
s 00002/00003/00065
d D 6.3 86/04/17 19:54:06 bloom 4 3
c clean up diction
e
s 00002/00002/00066
d D 6.2 86/04/17 17:59:39 bloom 3 2
c fix spelling
e
s 00000/00000/00068
d D 6.1 86/04/17 16:46:23 mckusick 2 1
c 4.3BSD beta release document
e
s 00068/00000/00000
d D 5.1 86/04/17 16:46:14 mckusick 1 0
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
.NH 1
Line printer Administration
.PP
The
.I lpc
program provides local control over line printer activity.
The major commands and their intended use will be described.
The command format and remaining commands are described in
.IR lpc (8).
.LP
\fBabort\fP and \fBstart\fP
.IP
.I Abort
terminates an active spooling daemon on the local host immediately and
then disables printing (preventing new daemons from being started by
.IR lpr ).
D 3
This is normally used to forciblly restart a hung line printer daemon
E 3
I 3
This is normally used to forcibly restart a hung line printer daemon
E 3
(i.e., \fIlpq\fP reports that there is a daemon present but nothing is
happening).  It does not remove any jobs from the queue
(use the \fIlprm\fP command instead).
.I Start
enables printing and requests \fIlpd\fP to start printing jobs.
.LP
\fBenable\fP and \fBdisable\fP
.IP
\fIEnable\fP and \fIdisable\fP allow spooling in the local queue to be
turned on/off.
This will allow/prevent
.I lpr
from putting new jobs in the spool queue.  It is frequently convenient
to turn spooling off while testing new line printer filters since the
.I root
user can still use
.I lpr
to put jobs in the queue but no one else can.
The other main use is to prevent users from putting jobs in the queue
when the printer is expected to be unavailable for a long time.
.LP
\fBrestart\fP
.IP
.I Restart
allows ordinary users to restart printer daemons when
.I lpq
reports that there is no daemon present.
.LP
\fBstop\fP
.IP
.I Stop
D 4
is used to halt a spooling daemon after the current job completes;
E 4
I 4
halts a spooling daemon after the current job completes;
E 4
this also disables printing.  This is a clean way to shutdown a
D 4
printer in order to perform
D 3
maintenence, etc.  Note that users can still enter jobs in a
E 3
I 3
maintenance, etc.  Note that users can still enter jobs in a
E 4
I 4
printer to do maintenance, etc.  Note that users can still enter jobs in a
E 4
E 3
spool queue while a printer is
.IR stopped .
.LP
\fBtopq\fP
.IP
.I Topq
places jobs at the top of a printer queue.  This can be used
to reorder high priority jobs since
.I lpr
D 5
only only provides first-come-first-serve ordering of jobs.
E 5
I 5
only provides first-come-first-serve ordering of jobs.
E 5
E 1

h64249
s 00005/00005/00109
d D 6.3 86/04/17 19:53:46 bloom 4 3
c clean up diction
e
s 00002/00002/00112
d D 6.2 86/04/17 17:53:43 bloom 3 2
c fix spelling
e
s 00000/00000/00114
d D 6.1 86/04/17 16:44:27 mckusick 2 1
c 4.3BSD beta release document
e
s 00114/00000/00000
d D 5.1 86/04/17 16:44:14 mckusick 1 0
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
Commands
.NH 2
D 3
lpd \- line printer dameon
E 3
I 3
lpd \- line printer daemon
E 3
.PP
The program
.IR lpd (8),
usually invoked at boot time from the /etc/rc file, acts as
a master server for coordinating and controlling
the spooling queues configured in the printcap file.
When
.I lpd
is started it makes a single pass through the
.I printcap
D 4
database restarting any printers which have jobs.
E 4
I 4
database restarting any printers that have jobs.
E 4
In normal operation
.I lpd
listens for service requests on multiple sockets,
one in the UNIX domain (named ``/dev/printer'') for
local requests, and one in the Internet domain
(under the ``printer'' service specification)
for requests for printer access from off machine;
see \fIsocket\fP\|(2) and \fIservices\fP\|(5)
for more information on sockets and service
specifications, respectively.
.I Lpd
spawns a copy of itself to process the request; the master daemon
continues to listen for new requests.
.PP
Clients communicate with 
.I lpd
using a simple transaction oriented protocol.
Authentication of remote clients is done based
on the ``privilege port'' scheme employed by
\fIrshd\fP\|(8C) and \fIrcmd\fP\|(3X).
The following table shows the requests 
understood by
.IR lpd .
In each request the first byte indicates the
``meaning'' of the request, followed by the name
of the printer to which it should be applied.  Additional
qualifiers may follow, depending on the request.
.DS
.TS
l l.
Request	Interpretation
_
^Aprinter\en	check the queue for jobs and print any found
^Bprinter\en	receive and queue a job from another machine
^Cprinter [users ...] [jobs ...]\en	return short list of current queue state
^Dprinter [users ...] [jobs ...]\en	return long list of current queue state
^Eprinter person [users ...] [jobs ...]\en	remove jobs from a queue
.TE
.DE
.PP
The \fIlpr\fP\|(1) command
is used by users to enter a print job in a local queue and to notify
the local
.I lpd
that there are new jobs in the spooling area.
.I Lpd
D 4
either schedules the job to be printed locally, or in the
case of remote printing, attempts to forward
E 4
I 4
either schedules the job to be printed locally, or if
printing remotely, attempts to forward
E 4
the job to the appropriate machine.
If the printer cannot be opened or the destination
machine is unreachable, the job will remain queued until it is
possible to complete the work.
.NH 2
lpq \- show line printer queue
.PP
The \fIlpq\fP\|(1)
program works recursively backwards displaying the queue of the machine with
the printer and then the queue(s) of the machine(s) that lead to it.
.I Lpq
has two forms of output: in the default, short, format it
gives a single line of output per queued job; in the long 
D 4
format it shows the list of files, and their sizes, which
E 4
I 4
format it shows the list of files, and their sizes, that
E 4
comprise a job.
.NH 2
lprm \- remove jobs from a queue
.PP
The \fIlprm\fP\|(1) command deletes jobs from a spooling
queue.  If necessary, \fIlprm\fP will first kill off a
D 4
running daemon which is servicing the queue, restarting
E 4
I 4
running daemon that is servicing the queue and restart
E 4
it after the required files are removed.  When removing
jobs destined for a remote printer, \fIlprm\fP acts
similarly to \fIlpq\fP except it first checks locally
for jobs to remove and then
tries to remove files in queues off-machine.
.NH 2
lpc \- line printer control program
.PP
The
.IR lpc (8)
program is used by the system administrator to control the
operation of the line printer system.  
For each line printer configured in /etc/printcap,
.I lpc
may be used to:
.IP \(bu
disable or enable a printer,
.IP \(bu
disable or enable a printer's spooling queue,
.IP \(bu
rearrange the order of jobs in a spooling queue,
.IP \(bu
find the status of printers, and their associated
D 3
spooling queues and printer dameons.
E 3
I 3
spooling queues and printer daemons.
E 3
E 1

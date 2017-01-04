h29946
s 00002/00002/00030
d D 6.3 86/06/05 09:51:48 karels 4 3
c formatting glitches
e
s 00004/00004/00028
d D 6.2 86/06/04 23:52:51 karels 3 2
c updates for 4.3
e
s 00000/00000/00032
d D 6.1 86/05/26 13:24:25 mckusick 2 1
c 4.3BSD beta release document
e
s 00032/00000/00000
d D 5.1 86/05/26 13:24:14 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
D 3
.\" Copyright (c) 1983 Regents of the University of California.
E 3
I 3
.\" Copyright (c) 1983,1986 Regents of the University of California.
E 3
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.nr H2 1
D 3
.ds RH Goals
E 3
I 3
.\".ds RH Goals
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Goals\s0
.PP
The networking system was designed with the goal of supporting
multiple \fIprotocol families\fP and addressing styles.  This required
information to be ``hidden'' in common data structures which
could be manipulated by all the pieces of the system, but which
required interpretation only by the protocols which ``controlled''
it.  The system described here attempts to minimize
the use of shared data structures to those kept by a suite of
protocols (a \fIprotocol family\fP), and those used for rendezvous
between ``synchronous'' and ``asynchronous'' portions of the
system (e.g. queues of data packets are filled at interrupt
time and emptied based on user requests).
.PP
A major goal of the system was to provide a framework within
which new protocols and hardware could be easily be supported.
To this end, a great deal of effort has been extended to
create utility routines which hide many of the more
complex and/or hardware dependent chores of networking.
Later sections describe the utility routines and the underlying
data structures they manipulate.
D 3
.ds RH "Address representation
.bp
E 3
I 3
D 4
.\".ds RH "Address representation
'ne 2i
E 4
E 3
E 1

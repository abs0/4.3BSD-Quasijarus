h51419
s 00002/00002/00037
d D 6.3 86/06/05 09:51:35 karels 4 3
c formatting glitches
e
s 00010/00007/00029
d D 6.2 86/06/04 23:52:37 karels 3 2
c updates for 4.3
e
s 00000/00000/00036
d D 6.1 86/05/26 13:23:53 mckusick 2 1
c 4.3BSD beta release document
e
s 00036/00000/00000
d D 5.1 86/05/26 13:23:49 mckusick 1 0
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
D 3
.ds RH Introduction
E 3
I 3
.\".ds RH Introduction
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Introduction\s0
.PP
This report describes the internal structure of
facilities added to the
4.2BSD version of the UNIX operating system for
D 3
the VAX.  The system facilities provide
E 3
I 3
the VAX,
as modified in the 4.3BSD release.
The system facilities provide
E 3
a uniform user interface to networking
within UNIX.  In addition, the implementation 
introduces a structure for network communications which may be
used by system implementors in adding new networking
facilities.  The internal structure is not visible
to the user, rather it is intended to aid implementors
of communication protocols and network services by
providing a framework which
promotes code sharing and minimizes implementation effort.
.PP
The reader is expected to be familiar with the C programming
D 3
language and system interface, as described in the \fI4.2BSD
System Manual\fP [Joy82a].  Basic understanding of network
E 3
I 3
language and system interface, as described in the
\fIBerkeley Software Architecture Manual, 4.3BSD Edition\fP [Joy86].
Basic understanding of network
E 3
communication concepts is assumed; where required
any additional ideas are introduced.
.PP
The remainder of this document
provides a description of the system internals,
avoiding, when possible, those portions which are utilized only
by the interprocess communication facilities.
D 3
.ds RH Overview
.bp
E 3
I 3
D 4
.\".ds RH Overview
'ne 2i
E 4
E 3
E 1

h36118
s 00002/00002/00056
d D 6.3 86/06/05 09:51:41 karels 4 3
c formatting glitches
e
s 00004/00004/00054
d D 6.2 86/06/04 23:52:42 karels 3 2
c updates for 4.3
e
s 00000/00000/00058
d D 6.1 86/05/26 13:24:06 mckusick 2 1
c 4.3BSD beta release document
e
s 00058/00000/00000
d D 5.1 86/05/26 13:24:00 mckusick 1 0
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
.ds RH Overview
E 3
I 3
.\".ds RH Overview
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Overview\s0
.PP
If we consider
the International Standards Organization's (ISO)
Open System Interconnection (OSI) model of
network communication [ISO81] [Zimmermann80],
the networking facilities
described here correspond to a portion of the
session layer (layer 3) and all of the transport and
network layers (layers 2 and 1, respectively).
.PP
The network layer provides possibly imperfect
data transport services with minimal addressing
structure.
Addressing at this level is normally host to host,
with implicit or explicit routing optionally supported
by the communicating agents. 
.PP
At the transport
layer the notions of reliable transfer, data sequencing,
flow control, and service addressing are normally
included.  Reliability is usually managed by 
explicit acknowledgement of data delivered.  Failure
to acknowledge a transfer results in retransmission of
the data.  Sequencing may be handled by tagging
each message handed to the network layer by a
\fIsequence number\fP and maintaining
state at the endpoints of communication to utilize
received sequence numbers in reordering data which
arrives out of order.
.PP
The session layer facilities may provide forms of
addressing which are mapped into formats required
by the transport layer, service authentication
and client authentication, etc.  Various systems
also provide services such as data encryption and
address and protocol translation.
.PP
The following sections begin by describing some of the common
data structures and utility routines, then examine
the internal layering.  The contents of each layer
and its interface are considered.  Certain of the
interfaces are protocol implementation specific.  For
these cases examples have been drawn from the Internet [Cerf78]
protocol family.  Later sections cover routing issues,
the design of the raw socket interface and other
miscellaneous topics.
D 3
.ds RH Goals
.bp
E 3
I 3
D 4
.\".ds RH Goals
'ne 2i
E 4
E 3
E 1

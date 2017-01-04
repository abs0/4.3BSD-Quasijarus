h32051
s 00002/00001/00044
d D 6.3 86/06/05 09:53:19 karels 4 3
c formatting glitches
e
s 00013/00007/00032
d D 6.2 86/06/04 23:54:38 karels 3 2
c updates for 4.3
e
s 00000/00000/00039
d D 6.1 86/05/26 13:27:26 mckusick 2 1
c 4.3BSD beta release document
e
s 00039/00000/00000
d D 5.1 86/05/26 13:27:21 mckusick 1 0
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
.ds RH "Out of band data
E 3
I 3
.\".ds RH "Out of band data
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Out of band data\s0
.PP
Out of band data is a facility peculiar to the stream socket
abstraction defined.  Little agreement appears to exist as
to what its semantics should be.  TCP defines the notion of
``urgent data'' as in-line, while the NBS protocols [Burruss81]
and numerous others provide a fully independent logical
transmission channel along which out of band data is to be
sent.
In addition, the amount of the data which may be sent as an out
of band message varies from protocol to protocol; everything
from 1 bit to 16 bytes or more.
.PP
A stream socket's notion of out of band data has been defined
as the lowest reasonable common denominator (at least reasonable
in our minds);
clearly this is subject to debate.  Out of band data is expected
to be transmitted out of the normal sequencing and flow control
constraints of the data stream.  A minimum of 1 byte of out of
band data and one outstanding out of band message are expected to
be supported by the protocol supporting a stream socket.
D 3
It is a protocols perogative to support larger sized messages, or
E 3
I 3
It is a protocol's prerogative to support larger-sized messages, or
E 3
more than one outstanding out of band message at a time.
.PP
D 3
Out of band data is maintained by the protocol and usually not
stored in the socket's send queue.  The PRU_SENDOOB and PRU_RCVOOB
E 3
I 3
Out of band data is maintained by the protocol and is usually not
stored in the socket's receive queue.
A socket-level option, SO_OOBINLINE,
is provided to force out-of-band data to be placed in the normal
receive queue when urgent data is received;
this sometimes amelioriates problems due to loss of data
when multiple out-of-band
segments are received before the first has been passed to the user.
The PRU_SENDOOB and PRU_RCVOOB
E 3
requests to the \fIpr_usrreq\fP routine are used in sending and
receiving data.
D 3
.ds RH "Trailer protocols
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

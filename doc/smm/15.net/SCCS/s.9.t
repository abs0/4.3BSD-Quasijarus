h21015
s 00003/00002/00094
d D 6.3 86/06/05 09:52:50 karels 4 3
c formatting glitches
e
s 00025/00017/00071
d D 6.2 86/06/04 23:53:50 karels 3 2
c updates for 4.3
e
s 00000/00000/00088
d D 6.1 86/05/26 13:26:39 mckusick 2 1
c 4.3BSD beta release document
e
s 00088/00000/00000
d D 5.1 86/05/26 13:26:33 mckusick 1 0
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
D 4
.ds RH "Protocol/network-interface
E 4
I 4
.\".ds RH "Protocol/network-interface
.br
.ne 2i
E 4
.NH
\s+2Protocol/network-interface interface\s0
.PP
The lowest layer in the set of protocols which comprise a
protocol family must interface itself to one or more network
interfaces in order to transmit and receive
packets.  It is assumed that
any routing decisions have been made before handing a packet
to a network interface, in fact this is absolutely necessary
in order to locate any interface at all (unless, of course,
one uses a single ``hardwired'' interface).  There are two
D 3
cases to be concerned with, transmission of a packet,
E 3
I 3
cases with which to be concerned, transmission of a packet
E 3
and receipt of a packet; each will be considered separately.
.NH 2
Packet transmission
.PP
Assuming a protocol has a handle on an interface, \fIifp\fP,
D 3
a (struct ifnet *),
E 3
I 3
a (struct ifnet\ *),
E 3
it transmits a fully formatted packet with the following call,
.DS
error = (*ifp->if_output)(ifp, m, dst)
int error; struct ifnet *ifp; struct mbuf *m; struct sockaddr *dst;
.DE
The output routine for the network interface transmits the packet
\fIm\fP to the \fIdst\fP address, or returns an error indication
(a UNIX error number).  In reality transmission may
D 3
not be immediate, or successful; normally the output
E 3
I 3
not be immediate or successful; normally the output
E 3
routine simply queues the packet on its send queue and primes
an interrupt driven routine to actually transmit the packet.
D 3
For unreliable mediums, such as the Ethernet, ``successful''
transmission simply means the packet has been placed on the cable
E 3
I 3
For unreliable media, such as the Ethernet, ``successful''
transmission simply means that the packet has been placed on the cable
E 3
without a collision.  On the other hand, an 1822 interface guarantees
proper delivery or an error indication for each message transmitted.
The model employed in the networking system attaches no promises
of delivery to the packets handed to a network interface, and thus
corresponds more closely to the Ethernet.  Errors returned by the
D 3
output routine are normally trivial in nature (no buffer space, 
E 3
I 3
output routine are only those that can be detected immediately,
and are normally trivial in nature (no buffer space, 
E 3
address format not handled, etc.).
I 3
No indication is received if errors are detected after the call has returned.
E 3
.NH 2
Packet reception
.PP
Each protocol family must have one or more ``lowest level'' protocols.
These protocols deal with internetwork addressing and are responsible
for the delivery of incoming packets to the proper protocol processing
modules.  In the PUP model [Boggs78] these protocols are termed Level
1 protocols,
D 3
in the ISO model, network layer protocols.  In our system each such
E 3
I 3
in the ISO model, network layer protocols.  In this system each such
E 3
protocol module has an input packet queue assigned to it.  Incoming
D 3
packets received by a network interface are queued up for the protocol
module and a VAX software interrupt is posted to initiate processing.  
E 3
I 3
packets received by a network interface are queued for the protocol
module, and a VAX software interrupt is posted to initiate processing.  
E 3
.PP
D 3
Three macros are available for queueing and dequeueing packets,
E 3
I 3
Three macros are available for queuing and dequeuing packets:
E 3
.IP "IF_ENQUEUE(ifq, m)"
.br
This places the packet \fIm\fP at the tail of the queue \fIifq\fP.
.IP "IF_DEQUEUE(ifq, m)"
.br
This places a pointer to the packet at the head of queue \fIifq\fP 
D 3
in \fIm\fP.  A zero value will be returned in \fIm\fP if the queue
is empty.
E 3
I 3
in \fIm\fP
and removes the packet from the queue.
A zero value will be returned in \fIm\fP if the queue is empty.
.IP "IF_DEQUEUEIF(ifq, m, ifp)"
.br
Like IF_DEQUEUE, this removes the next packet from the head of a queue
and returns it in \fIm\fP.
A pointer to the interface on which the packet was received
is placed in \fIifp\fP, a (struct ifnet\ *).
E 3
.IP "IF_PREPEND(ifq, m)"
.br
This places the packet \fIm\fP at the head of the queue \fIifq\fP.
.PP
Each queue has a maximum length associated with it as a simple form
of congestion control.  The macro IF_QFULL(ifq) returns 1 if the queue
is filled, in which case the macro IF_DROP(ifq) should be used to
D 3
bump a count of the number of packets dropped and the offending
packet dropped.  For example, the following code fragment is commonly
E 3
I 3
increment the count of the number of packets dropped, and the offending
packet is dropped.  For example, the following code fragment is commonly
E 3
found in a network interface's input routine,
.DS 
._f
if (IF_QFULL(inq)) {
	IF_DROP(inq);
	m_freem(m);
} else
	IF_ENQUEUE(inq, m);
.DE
D 3
.ds RH "Gateways and routing
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

h31771
s 00002/00001/00116
d D 6.3 86/06/05 09:53:06 karels 4 3
c formatting glitches
e
s 00023/00023/00094
d D 6.2 86/06/04 23:54:22 karels 3 2
c updates for 4.3
e
s 00000/00000/00117
d D 6.1 86/05/26 13:27:03 mckusick 2 1
c 4.3BSD beta release document
e
s 00117/00000/00000
d D 5.1 86/05/26 13:26:58 mckusick 1 0
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
.ds RH "Raw sockets
E 3
I 3
.\".ds RH "Raw sockets
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Raw sockets\s0
.PP
D 3
A raw socket is a mechanism which allows users direct access
to a lower level protocol.  Raw sockets are intended for knowledgeable
E 3
I 3
A raw socket is an object which allows users direct access
to a lower-level protocol.  Raw sockets are intended for knowledgeable
E 3
processes which wish to take advantage of some protocol
feature not directly accessible through the normal interface, or 
for the development of new protocols built atop existing lower level
protocols.  For example, a new version of TCP might be developed at the
user level by utilizing a raw IP socket for delivery of packets.
The raw IP socket interface attempts to provide an identical interface
to the one a protocol would have if it were resident in the kernel.
.PP
The raw socket support is built around a generic raw socket interface,
D 3
and (possibly) augmented by protocol-specific processing routines.
E 3
I 3
(possibly) augmented by protocol-specific processing routines.
E 3
This section will describe the core of the raw socket interface.
.NH 2
Control blocks
.PP
D 3
Every raw socket has a protocol control block of the following form,
E 3
I 3
Every raw socket has a protocol control block of the following form:
E 3
.DS
D 3
.if t .ta .5i 1.25i 2.9i
.if n .ta .7i 1.75i 4.0i
E 3
I 3
.ta \w'struct  'u +\w'caddr_t  'u +\w'sockproto rcb_proto;    'u 
E 3
struct rawcb {
	struct	rawcb *rcb_next;	/* doubly linked list */
	struct	rawcb *rcb_prev;
	struct	socket *rcb_socket;	/* back pointer to socket */
	struct	sockaddr rcb_faddr;	/* destination address */
	struct	sockaddr rcb_laddr;	/* socket's address */
I 3
	struct	sockproto rcb_proto;	/* protocol family, protocol */
E 3
	caddr_t	rcb_pcb;		/* protocol specific stuff */
I 3
	struct	mbuf *rcb_options;	/* protocol specific options */
	struct	route rcb_route;	/* routing information */
E 3
	short	rcb_flags;
};
.DE
All the control blocks are kept on a doubly linked list for
performing lookups during packet dispatch.  Associations may
be recorded in the control block and used by the output routine
D 3
in preparing packets for transmission.  The addresses are also
E 3
I 3
in preparing packets for transmission.
The \fIrcb_proto\fP structure contains the protocol family and protocol
number with which the raw socket is associated.
The protocol, family and addresses are
E 3
used to filter packets on input; this will be described in more
D 3
detail shortly.  If any protocol specific information is required,
E 3
I 3
detail shortly.  If any protocol-specific information is required,
E 3
it may be attached to the control block using the \fIrcb_pcb\fP
D 3
field. 
E 3
I 3
field.
Protocol-specific options for transmission in outgoing packets
may be stored in \fIrcb_options\fP.
E 3
.PP
A raw socket interface is datagram oriented.  That is, each send
or receive on the socket requires a destination address.  This
address may be supplied by the user or stored in the control block
and automatically installed in the outgoing packet by the output
routine.  Since it is not possible to determine whether an address
is present or not in the control block, two flags, RAW_LADDR and
RAW_FADDR, indicate if a local and foreign address are present.
D 3
Another flag, RAW_DONTROUTE, indicates if routing should be performed
on outgoing packets.  If it is, a route is expected to be 
allocated for each
``new'' destination address.  That is, the first time a packet is
transmitted a route is determined, and thereafter each time the
destination address stored in \fIrcb_route\fP differs from
\fIrcb_faddr\fP, or \fIrcb_route.ro_rt\fP is zero, the old
route is discarded and a new one allocated. 
E 3
I 3
Routing is expected to be performed by the underlying protocol
if necessary.
E 3
.NH 2
Input processing
.PP
Input packets are ``assigned'' to raw sockets based on a simple
pattern matching scheme.  Each network interface or protocol
D 3
gives packets
E 3
I 3
gives unassigned packets
E 3
to the raw input routine with the call:
.DS
raw_input(m, proto, src, dst)
struct mbuf *m; struct sockproto *proto, struct sockaddr *src, *dst;
.DE
The data packet then has a generic header prepended to it of the
form
.DS
._f
struct raw_header {
	struct	sockproto raw_proto;
	struct	sockaddr raw_dst;
	struct	sockaddr raw_src;
};
.DE
and it is placed in a packet queue for the ``raw input protocol'' module.
Packets taken from this queue are copied into any raw sockets that
match the header according to the following rules,
.IP 1)
The protocol family of the socket and header agree.
.IP 2)
If the protocol number in the socket is non-zero, then it agrees
with that found in the packet header.
.IP 3)
If a local address is defined for the socket, the address format
of the local address is the same as the destination address's and
the two addresses agree bit for bit.
.IP 4)
The rules of 3) are applied to the socket's foreign address and the packet's
source address.
.LP
A basic assumption is that addresses present in the
control block and packet header (as constructed by the network
interface and any raw input protocol module) are in a canonical
form which may be ``block compared''.
.NH 2
Output processing
.PP
On output the raw \fIpr_usrreq\fP routine 
D 3
passes the packet and raw control block to the
E 3
I 3
passes the packet and a pointer to the raw control block to the
E 3
raw protocol output routine for any processing required before
it is delivered to the appropriate network interface.  The
output routine is normally the only code required to implement
a raw socket interface.
D 3
.ds RH "Buffering and congestion control
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

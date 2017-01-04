h60475
s 00007/00006/00630
d D 6.3 86/06/05 09:52:05 karels 4 3
c formatting glitches
e
s 00303/00156/00333
d D 6.2 86/06/04 23:53:14 karels 3 2
c updates for 4.3
e
s 00000/00000/00489
d D 6.1 86/05/26 13:25:44 mckusick 2 1
c 4.3BSD beta release document
e
s 00489/00000/00000
d D 5.1 86/05/26 13:25:32 mckusick 1 0
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
.ds RH "Internal layering
E 3
I 3
.\".ds RH "Internal layering
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Internal layering\s0
.PP
The internal structure of the network system is divided into
three layers.  These
layers correspond to the services provided by the socket
abstraction, those provided by the communication protocols,
and those provided by the hardware interfaces.  The communication
protocols are normally layered into two or more individual
cooperating layers, though they are collectively viewed
in the system as one layer providing services supportive
of the appropriate socket abstraction.
.PP
The following sections describe the properties of each layer
D 3
in the system and the interfaces each must conform to.
E 3
I 3
in the system and the interfaces to which each must conform.
E 3
.NH 2
Socket layer
.PP
D 3
The socket layer deals with the interprocess communications
E 3
I 3
The socket layer deals with the interprocess communication
E 3
facilities provided by the system.  A socket is a bidirectional
endpoint of communication which is ``typed'' by the semantics
of communication it supports.  The system calls described in
D 3
the \fI4.2BSD System Manual\fP are used to manipulate sockets.
E 3
I 3
the \fIBerkeley Software Architecture Manual\fP [Joy86]
are used to manipulate sockets.
E 3
.PP
A socket consists of the following data structure:
.DS
._f
struct socket {
	short	so_type;		/* generic type */
	short	so_options;		/* from socket call */
	short	so_linger;		/* time to linger while closing */
	short	so_state;		/* internal state flags */
	caddr_t	so_pcb;			/* protocol control block */
	struct	protosw *so_proto;	/* protocol handle */
	struct	socket *so_head;	/* back pointer to accept socket */
	struct	socket *so_q0;		/* queue of partial connections */
	short	so_q0len;		/* partials on so_q0 */
	struct	socket *so_q;		/* queue of incoming connections */
	short	so_qlen;		/* number of connections on so_q */
	short	so_qlimit;		/* max number queued connections */
D 3
	struct	sockbuf so_snd;		/* send queue */
E 3
	struct	sockbuf so_rcv;		/* receive queue */
I 3
	struct	sockbuf so_snd;		/* send queue */
E 3
	short	so_timeo;		/* connection timeout */
	u_short	so_error;		/* error affecting connection */
D 3
	short	so_oobmark;		/* chars to oob mark */
E 3
I 3
	u_short	so_oobmark;		/* chars to oob mark */
E 3
	short	so_pgrp;		/* pgrp for signals */
};
.DE
.PP
Each socket contains two data queues, \fIso_rcv\fP and \fIso_snd\fP,
and a pointer to routines which provide supporting services. 
The type of the socket,
\fIso_type\fP is defined at socket creation time and used in selecting
those services which are appropriate to support it.  The supporting
protocol is selected at socket creation time and recorded in
the socket data structure for later use.  Protocols are defined
by a table of procedures, the \fIprotosw\fP structure, which will
D 3
be described in detail later.  A pointer to a protocol specific
E 3
I 3
be described in detail later.  A pointer to a protocol-specific
E 3
data structure,
D 3
the ``protocol control block'' is also present in the socket structure.
Protocols control this data structure and it normally includes a
back pointer to the parent socket structure(s) to allow easy
E 3
I 3
the ``protocol control block,'' is also present in the socket structure.
Protocols control this data structure, which normally includes a
back pointer to the parent socket structure to allow easy
E 3
lookup when returning information to a user 
(for example, placing an error number in the \fIso_error\fP
field).  The other entries in the socket structure are used in
D 3
queueing connection requests, validating user requests, storing
E 3
I 3
queuing connection requests, validating user requests, storing
E 3
socket characteristics (e.g.
options supplied at the time a socket is created), and maintaining
a socket's state.
.PP
Processes ``rendezvous at a socket'' in many instances.  For instance,
when a process wishes to extract data from a socket's receive queue
and it is empty, or lacks sufficient data to satisfy the request,
the process blocks, supplying the address of the receive queue as
D 3
an ``wait channel' to be used in notification.  When data arrives
E 3
I 3
a ``wait channel' to be used in notification.  When data arrives
E 3
for the process and is placed in the socket's queue, the blocked
D 3
process is identified by the fact it is waiting ``on the queue''.
E 3
I 3
process is identified by the fact it is waiting ``on the queue.''
E 3
.NH 3
Socket state
.PP
A socket's state is defined from the following:
.DS
D 3
.if t .ta .6i 2.3i 3.0i
.if n .ta .84i 2.5i 3.20i
E 3
I 3
.ta \w'#define 'u +\w'SS_ISDISCONNECTING    'u +\w'0x000     'u
E 3
#define	SS_NOFDREF	0x001	/* no file table ref any more */
#define	SS_ISCONNECTED	0x002	/* socket connected to a peer */
#define	SS_ISCONNECTING	0x004	/* in process of connecting to peer */
#define	SS_ISDISCONNECTING	0x008	/* in process of disconnecting */
#define	SS_CANTSENDMORE	0x010	/* can't send more data to peer */
#define	SS_CANTRCVMORE	0x020	/* can't receive more data from peer */
D 3
#define	SS_CONNAWAITING	0x040	/* connections awaiting acceptance */
#define	SS_RCVATMARK	0x080	/* at mark on input */
E 3
I 3
#define	SS_RCVATMARK	0x040	/* at mark on input */
E 3

D 3
#define	SS_PRIV	0x100	/* privileged */
#define	SS_NBIO	0x200	/* non-blocking ops */
#define	SS_ASYNC	0x400	/* async i/o notify */
E 3
I 3
#define	SS_PRIV	0x080	/* privileged */
#define	SS_NBIO	0x100	/* non-blocking ops */
#define	SS_ASYNC	0x200	/* async i/o notify */
E 3
.DE
.PP
The state of a socket is manipulated both by the protocols
and the user (through system calls).
D 3
When a socket is created the state is defined based on the type of
input/output the user wishes to perform.  ``Non-blocking'' I/O  implies
E 3
I 3
When a socket is created, the state is defined based on the type of socket.
It may change as control actions are performed, for example connection
establishment.
It may also change according to the type of
input/output the user wishes to perform, as indicated by options
set with \fIfcntl\fP.  ``Non-blocking'' I/O  implies that
E 3
a process should never be blocked to await resources.  Instead, any
call which would block returns prematurely
D 3
with the error EWOULDBLOCK (the service request may be partially
fulfilled, e.g. a request for more data than is present).
E 3
I 3
with the error EWOULDBLOCK, or the service request may be partially
fulfilled, e.g. a request for more data than is present.
E 3
.PP
If a process requested ``asynchronous'' notification of events
D 3
related to the socket the SIGIO signal is posted to the process.
An event is a change in the socket's state,
examples of such occurances are: space
E 3
I 3
related to the socket, the SIGIO signal is posted to the process
when such events occur.
An event is a change in the socket's state;
examples of such occurrences are: space
E 3
becoming available in the send queue, new data available in the
receive queue, connection establishment or disestablishment, etc. 
.PP
D 3
A socket may be marked ``priviledged'' if it was created by the
super-user.  Only priviledged sockets may
send broadcast packets, or bind
addresses in priviledged portions of an address space.
E 3
I 3
A socket may be marked ``privileged'' if it was created by the
super-user.  Only privileged sockets may
bind addresses in privileged portions of an address space
or use ``raw'' sockets to access lower levels of the network.
E 3
.NH 3
Socket data queues
.PP
A socket's data queue contains a pointer to the data stored in
the queue and other entries related to the management of
the data.  The following structure defines a data queue:
.DS
._f
struct sockbuf {
D 3
	short	sb_cc;		/* actual chars in buffer */
	short	sb_hiwat;	/* max actual char count */
	short	sb_mbcnt;	/* chars of mbufs used */
	short	sb_mbmax;	/* max chars of mbufs to use */
	short	sb_lowat;	/* low water mark */
E 3
I 3
	u_short	sb_cc;		/* actual chars in buffer */
	u_short	sb_hiwat;	/* max actual char count */
	u_short	sb_mbcnt;	/* chars of mbufs used */
	u_short	sb_mbmax;	/* max chars of mbufs to use */
	u_short	sb_lowat;	/* low water mark */
E 3
	short	sb_timeo;	/* timeout */
	struct	mbuf *sb_mb;	/* the mbuf chain */
	struct	proc *sb_sel;	/* process selecting read/write */
	short	sb_flags;	/* flags, see below */
};
.DE
.PP
D 3
Data is stored in a queue as a chain of mbufs.  The actual
count of characters as well as high and low water marks are
E 3
I 3
Data is stored in a queue as a chain of mbufs.
The actual count of data characters as well as high and low water marks are
E 3
used by the protocols in controlling the flow of data.
I 3
The amount of buffer space (characters of mbufs and associated data pages)
is also recorded along with the limit on buffer allocation.
E 3
The socket routines cooperate in implementing the flow control
policy by blocking a process when it requests to send data and
the high water mark has been reached, or when it requests to
receive data and less than the low water mark is present
D 3
(assuming non-blocking I/O has not been specified).
E 3
I 3
(assuming non-blocking I/O has not been specified).*
.FS
* The low-water mark is always presumed to be 0
in the current implementation.
.FE
E 3
.PP
When a socket is created, the supporting protocol ``reserves'' space
for the send and receive queues of the socket.
I 3
The limit on buffer allocation is set somewhat higher than the limit
on data characters
to account for the granularity of buffer allocation.
E 3
The actual storage associated with a
D 3
socket queue may fluctuate during a socket's lifetime, but is assumed
this reservation will always allow a protocol to acquire enough memory
E 3
I 3
socket queue may fluctuate during a socket's lifetime, but it is assumed
that this reservation will always allow a protocol to acquire enough memory
E 3
to satisfy the high water marks.
.PP
The timeout and select values are manipulated by the socket routines
in implementing various portions of the interprocess communications
facilities and will not be described here.
.PP
I 3
Data queued at a socket is stored in one of two styles.
Stream-oriented sockets queue data with no addresses, headers
or record boundaries.
The data are in mbufs linked through the \fIm_next\fP field.
Buffers containing access rights may be present within the chain
if the underlying protocol supports passage of access rights.
Record-oriented sockets, including datagram sockets,
queue data as a list of packets; the sections of packets are distinguished
by the types of the mbufs containing them.
The mbufs which comprise a record are linked through the \fIm_next\fP field;
records are linked from the \fIm_act\fP field of the first mbuf
of one packet to the first mbuf of the next.
Each packet begins with an mbuf containing the ``from'' address
if the protocol provides it,
then any buffers containing access rights, and finally any buffers
containing data.
If a record contains no data,
no data buffers are required unless neither address nor access rights
are present.
.PP
E 3
A socket queue has a number of flags used in synchronizing access
D 3
to the data and in acquiring resources;
E 3
I 3
to the data and in acquiring resources:
E 3
.DS
._d
#define	SB_LOCK	0x01	/* lock on data queue (so_rcv only) */
#define	SB_WANT	0x02	/* someone is waiting to lock */
#define	SB_WAIT	0x04	/* someone is waiting for data/space */
#define	SB_SEL	0x08	/* buffer is selected */
#define	SB_COLL	0x10	/* collision selecting */
.DE
The last two flags are manipulated by the system in implementing
the select mechanism.
.NH 3
D 3
Socket connection queueing
E 3
I 3
Socket connection queuing
E 3
.PP
In dealing with connection oriented sockets (e.g. SOCK_STREAM)
D 3
the two sides are considered distinct.  One side is termed
E 3
I 3
the two ends are considered distinct.  One end is termed
E 3
\fIactive\fP, and generates connection requests.  The other
D 3
side is called \fIpassive\fP and accepts connection requests.
E 3
I 3
end is called \fIpassive\fP and accepts connection requests.
E 3
.PP
D 3
From the passive side, a socket is created with the option
SO_ACCEPTCONN specified, 
E 3
I 3
From the passive side, a socket is marked with
SO_ACCEPTCONN when a \fIlisten\fP call is made, 
E 3
creating two queues of sockets: \fIso_q0\fP for connections
in progress and \fIso_q\fP for connections already made and
awaiting user acceptance.
As a protocol is preparing incoming connections, it creates
a socket structure queued on \fIso_q0\fP by calling the routine
\fIsonewconn\fP().  When the connection
D 3
is established, the socket structure is then transfered
to \fIso_q\fP, making it available for an accept.
E 3
I 3
is established, the socket structure is then transferred
to \fIso_q\fP, making it available for an \fIaccept\fP.
E 3
.PP
If an SO_ACCEPTCONN socket is closed with sockets on either
D 3
\fIso_q0\fP or \fIso_q\fP, these sockets are dropped.
E 3
I 3
\fIso_q0\fP or \fIso_q\fP, these sockets are dropped,
with notification to the peers as appropriate.
E 3
.NH 2
Protocol layer(s)
.PP
I 3
Each socket is created in a communications domain,
which usually implies both an addressing structure (address family)
and a set of protocols which implement various socket types within the domain
(protocol family).
Each domain is defined by the following structure:
.DS
.ta .5i +\w'struct  'u +\w'(*dom_externalize)();   'u
struct	domain {
	int	dom_family;		/* PF_xxx */
	char	*dom_name;
	int	(*dom_init)();		/* initialize domain data structures */
	int	(*dom_externalize)();	/* externalize access rights */
	int	(*dom_dispose)();	/* dispose of internalized rights */
	struct	protosw *dom_protosw, *dom_protoswNPROTOSW;
	struct	domain *dom_next;
};
.DE
.PP
At boot time, each domain configured into the kernel
is added to a linked list of domain.
The initialization procedure of each domain is then called.
After that time, the domain structure is used to locate protocols
within the protocol family.
It may also contain procedure references
for externalization of access rights at the receiving socket
and the disposal of access rights that are not received.
.PP
E 3
Protocols are described by a set of entry points and certain
D 3
socket visible characteristics, some of which are used in
E 3
I 3
socket-visible characteristics, some of which are used in
E 3
deciding which socket type(s) they may support.  
.PP
An entry in the ``protocol switch'' table exists for each
protocol module configured into the system.  It has the following form:
.DS
D 3
._f
E 3
I 3
.ta .5i +\w'struct  'u +\w'domain *pr_domain;    'u
E 3
struct protosw {
	short	pr_type;		/* socket type used for */
D 3
	short	pr_family;		/* protocol family */
E 3
I 3
	struct	domain *pr_domain;	/* domain protocol a member of */
E 3
	short	pr_protocol;		/* protocol number */
	short	pr_flags;		/* socket visible attributes */
/* protocol-protocol hooks */
	int	(*pr_input)();		/* input to protocol (from below) */
	int	(*pr_output)();		/* output to protocol (from above) */
	int	(*pr_ctlinput)();	/* control input (from below) */
	int	(*pr_ctloutput)();	/* control output (from above) */
/* user-protocol hook */
	int	(*pr_usrreq)();		/* user request */
/* utility hooks */
	int	(*pr_init)();		/* initialization routine */
	int	(*pr_fasttimo)();	/* fast timeout (200ms) */
	int	(*pr_slowtimo)();	/* slow timeout (500ms) */
	int	(*pr_drain)();		/* flush any excess space possible */
};
.DE
.PP
A protocol is called through the \fIpr_init\fP entry before any other.
Thereafter it is called every 200 milliseconds through the
\fIpr_fasttimo\fP entry and
every 500 milliseconds through the \fIpr_slowtimo\fP for timer based actions.
The system will call the \fIpr_drain\fP entry if it is low on space and
this should throw away any non-critical data.
.PP
Protocols pass data between themselves as chains of mbufs using
the \fIpr_input\fP and \fIpr_output\fP routines.  \fIPr_input\fP
passes data up (towards
the user) and \fIpr_output\fP passes it down (towards the network); control
information passes up and down on \fIpr_ctlinput\fP and \fIpr_ctloutput\fP.
D 3
The protocol is responsible for the space occupied by any the
arguments to these entries and must dispose of it.
E 3
I 3
The protocol is responsible for the space occupied by any of the
arguments to these entries and must either pass it onward or dispose of it.
(On output, the lowest level reached must free buffers storing the arguments;
on input, the highest level is responsible for freeing buffers.)
E 3
.PP
D 3
The \fIpr_userreq\fP routine interfaces protocols to the socket
E 3
I 3
The \fIpr_usrreq\fP routine interfaces protocols to the socket
E 3
code and is described below.
.PP
The \fIpr_flags\fP field is constructed from the following values:
.DS
D 3
._d
E 3
I 3
.ta \w'#define 'u +\w'PR_CONNREQUIRED   'u +8n
E 3
#define	PR_ATOMIC	0x01		/* exchange atomic messages only */
#define	PR_ADDR	0x02		/* addresses given with messages */
#define	PR_CONNREQUIRED	0x04		/* connection required by protocol */
#define	PR_WANTRCVD	0x08		/* want PRU_RCVD calls */
#define	PR_RIGHTS	0x10		/* passes capabilities */
.DE
Protocols which are connection-based specify the PR_CONNREQUIRED
flag so that the socket routines will never attempt to send data
before a connection has been established.  If the PR_WANTRCVD flag
D 3
is set, the socket routines will notfiy the protocol when the user
E 3
I 3
is set, the socket routines will notify the protocol when the user
E 3
has removed data from the socket's receive queue.  This allows
the protocol to implement acknowledgement on user receipt, and
also update windowing information based on the amount of space
D 3
available in the receive queue.  The PR_ADDR field indicates any
E 3
I 3
available in the receive queue.  The PR_ADDR field indicates that any
E 3
data placed in the socket's receive queue will be preceded by the
D 3
address of the sender.  The PR_ATOMIC flag specifies each \fIuser\fP
E 3
I 3
address of the sender.  The PR_ATOMIC flag specifies that each \fIuser\fP
E 3
request to send data must be performed in a single \fIprotocol\fP send
request; it is the protocol's responsibility to maintain record
D 3
boundaries on data to be sent.  The PR_RIGHTS flag indicates the
E 3
I 3
boundaries on data to be sent.  The PR_RIGHTS flag indicates that the
E 3
protocol supports the passing of capabilities;  this is currently
D 3
used only the protocols in the UNIX protocol family.
E 3
I 3
used only by the protocols in the UNIX protocol family.
E 3
.PP
When a socket is created, the socket routines scan the protocol
D 3
table looking for an appropriate protocol to support the type of
E 3
I 3
table for the domain
looking for an appropriate protocol to support the type of
E 3
socket being created.  The \fIpr_type\fP field contains one of the
D 3
possible socket types (e.g. SOCK_STREAM), while the \fIpr_family\fP
field indicates which protocol family the protocol belongs to.
E 3
I 3
possible socket types (e.g. SOCK_STREAM), while the \fIpr_domain\fP
is a back pointer to the domain structure.
E 3
The \fIpr_protocol\fP field contains the protocol number of the
D 3
protocol, normally a well known value.
E 3
I 3
protocol, normally a well-known value.
E 3
.NH 2
Network-interface layer
.PP
Each network-interface configured into a system defines a
path through which packets may be sent and received.
Normally a hardware device is associated with this interface,
though there is no requirement for this (for example, all
systems have a software ``loopback'' interface used for 
debugging and performance analysis).
In addition to manipulating the hardware device, an interface
module is responsible
D 3
for encapsulation and deencapsulation of any low level header
information required to deliver a message to it's destination.
E 3
I 3
for encapsulation and decapsulation of any link-layer header
information required to deliver a message to its destination.
E 3
The selection of which interface to use in delivering packets
is a routing decision carried out at a
D 3
higher level than the network-interface layer.  Each interface
normally identifies itself at boot time to the routing module
so that it may be selected for packet delivery.
E 3
I 3
higher level than the network-interface layer.
An interface may have addresses in one or more address families.
The address is set at boot time using an \fIioctl\fP on a socket
in the appropriate domain; this operation is implemented by the protocol
family, after verifying the operation through the device \fIioctl\fP entry.
E 3
.PP
An interface is defined by the following structure,
.DS
D 3
._f
E 3
I 3
.ta .5i +\w'struct   'u +\w'ifaddr *if_addrlist;   'u
E 3
struct ifnet {
	char	*if_name;		/* name, e.g. ``en'' or ``lo'' */
	short	if_unit;		/* sub-unit for lower level driver */
	short	if_mtu;			/* maximum transmission unit */
D 3
	int	if_net;			/* network number of interface */
E 3
	short	if_flags;		/* up/down, broadcast, etc. */
	short	if_timer;		/* time 'til if_watchdog called */
D 3
	int	if_host[2];		/* local net host number */
	struct	sockaddr if_addr;	/* address of interface */
	union {
		struct	sockaddr ifu_broadaddr;
		struct	sockaddr ifu_dstaddr;
	} if_ifu;
E 3
I 3
	struct	ifaddr *if_addrlist;	/* list of addresses of interface */
E 3
	struct	ifqueue if_snd;		/* output queue */
	int	(*if_init)();		/* init routine */
	int	(*if_output)();		/* output routine */
	int	(*if_ioctl)();		/* ioctl routine */
	int	(*if_reset)();		/* bus reset routine */
	int	(*if_watchdog)();	/* timer routine */
	int	if_ipackets;		/* packets received on interface */
	int	if_ierrors;		/* input errors on interface */
	int	if_opackets;		/* packets sent on interface */
	int	if_oerrors;		/* output errors on interface */
	int	if_collisions;		/* collisions on csma interfaces */
	struct	ifnet *if_next;
};
.DE
I 3
Each interface address has the following form:
.DS
.ta \w'#define 'u +\w'struct   'u +\w'struct   'u +\w'sockaddr ifa_addr;   'u-\w'struct   'u
struct ifaddr {
	struct	sockaddr ifa_addr;	/* address of interface */
	union {
		struct	sockaddr ifu_broadaddr;
		struct	sockaddr ifu_dstaddr;
	} ifa_ifu;
	struct	ifnet *ifa_ifp;		/* back-pointer to interface */
	struct	ifaddr *ifa_next;	/* next address for interface */
};
.ta \w'#define 'u +\w'ifa_broadaddr   'u +\w'ifa_ifu.ifu_broadaddr	   'u
#define	ifa_broadaddr	ifa_ifu.ifu_broadaddr	/* broadcast address */
#define	ifa_dstaddr	ifa_ifu.ifu_dstaddr	/* other end of p-to-p link */
.DE
The protocol generally maintains this structure as part of a larger
structure containing additional information concerning the address.
E 3
.PP
Each interface has a send queue and routines used for 
initialization, \fIif_init\fP, and output, \fIif_output\fP.
If the interface resides on a system bus, the routine \fIif_reset\fP
will be called after a bus reset has been performed. 
An interface may also
D 3
specify a timer routine, \fIif_watchdog\fP, which should be called
every \fIif_timer\fP seconds (if non-zero).
E 3
I 3
specify a timer routine, \fIif_watchdog\fP;
if \fIif_timer\fP is non-zero, it is decremented once per second
until it reaches zero, at which time the watchdog routine is called.
E 3
.PP
The state of an interface and certain characteristics are stored in
the \fIif_flags\fP field.  The following values are possible:
.DS
._d
#define	IFF_UP	0x1	/* interface is up */
D 3
#define	IFF_BROADCAST	0x2	/* broadcast address valid */
E 3
I 3
#define	IFF_BROADCAST	0x2	/* broadcast is possible */
E 3
#define	IFF_DEBUG	0x4	/* turn on debugging */
D 3
#define	IFF_ROUTE	0x8	/* routing entry installed */
E 3
I 3
#define	IFF_LOOPBACK	0x8	/* is a loopback net */
E 3
#define	IFF_POINTOPOINT	0x10	/* interface is point-to-point link */
#define	IFF_NOTRAILERS	0x20	/* avoid use of trailers */
#define	IFF_RUNNING	0x40	/* resources allocated */
#define	IFF_NOARP	0x80	/* no address resolution protocol */
.DE
If the interface is connected to a network which supports transmission
of \fIbroadcast\fP packets, the IFF_BROADCAST flag will be set and
D 3
the \fIif_broadaddr\fP field will contain the address to be used in
E 3
I 3
the \fIifa_broadaddr\fP field will contain the address to be used in
E 3
sending or accepting a broadcast packet.  If the interface is associated
D 3
with a point to point hardware link (for example, a DEC DMR-11), the
IFF_POINTOPOINT flag will be set and \fIif_dstaddr\fP will contain the
E 3
I 3
with a point-to-point hardware link (for example, a DEC DMR-11), the
IFF_POINTOPOINT flag will be set and \fIifa_dstaddr\fP will contain the
E 3
address of the host on the other side of the connection.  These addresses
and the local address of the interface, \fIif_addr\fP, are used in
filtering incoming packets.  The interface sets IFF_RUNNING after
it has allocated system resources and posted an initial read on the
device it manages.  This state bit is used to avoid multiple allocation
requests when an interface's address is changed.  The IFF_NOTRAILERS
flag indicates the interface should refrain from using a \fItrailer\fP
D 3
encapsulation on outgoing packets; \fItrailer\fP protocols are described
E 3
I 3
encapsulation on outgoing packets, or (where per-host negotiation
of trailers is possible) that trailer encapsulations should not be requested;
\fItrailer\fP protocols are described
E 3
in section 14.  The IFF_NOARP flag indicates the interface should not
use an ``address resolution protocol'' in mapping internetwork addresses
to local network addresses.
.PP
D 3
The information stored in an \fIifnet\fP structure for point to point
communication devices is not currently used by the system internally.
Rather, it is used by the user level routing process in determining
host network connections and in initially devising routes (refer to
chapter 10 for more information).
.PP
E 3
Various statistics are also stored in the interface structure.  These
may be viewed by users using the \fInetstat\fP(1) program.
.PP
The interface address and flags may be set with the SIOCSIFADDR and
D 3
SIOCSIFFLAGS ioctls.  SIOCSIFADDR is used to initially define each
E 3
I 3
SIOCSIFFLAGS \fIioctl\fP\^s.  SIOCSIFADDR is used initially to define each
E 3
interface's address; SIOGSIFFLAGS can be used to mark
an interface down and perform site-specific configuration.
I 3
The destination address of a point-to-point link is set with SIOCSIFDSTADDR.
Corresponding operations exist to read each value.
Protocol families may also support operations to set and read the broadcast
address.
In addition, the SIOCGIFCONF \fIioctl\fP retrieves a list of interface
names and addresses for all interfaces and protocols on the host.
E 3
.NH 3
UNIBUS interfaces
.PP
All hardware related interfaces currently reside on the UNIBUS.
Consequently a common set of utility routines for dealing
with the UNIBUS has been developed.  Each UNIBUS interface
utilizes a structure of the following form:
.DS
D 3
.if t .ta .5i 1.25i 2.8i
.if n .ta .7i 1.75i 3.8i
E 3
I 3
D 4
.ta \w'#define 'u +\w'caddr_t    'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
I 4
.ta \w'#define 'u +\w'ifw_xtofree 'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
struct	ifubinfo {
	short	iff_uban;			/* uba number */
	short	iff_hlen;			/* local net header length */
	struct	uba_regs *iff_uba;		/* uba regs, in vm */
	short	iff_flags;			/* used during uballoc's */
};
.DE
Additional structures are associated with each receive and transmit buffer,
normally one each per interface; for read,
.DS
D 4
.ta \w'#define 'u +\w'caddr_t    'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
I 4
.ta \w'#define 'u +\w'ifw_xtofree 'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
struct	ifrw {
	caddr_t	ifrw_addr;			/* virt addr of header */
	short	ifrw_bdp;			/* unibus bdp */
	short	ifrw_flags;			/* type, etc. */
#define	IFRW_W	0x01				/* is a transmit buffer */
	int	ifrw_info;			/* value from ubaalloc */
	int	ifrw_proto;			/* map register prototype */
	struct	pte *ifrw_mr;			/* base of map registers */
};
.DE
and for write,
.DS
D 4
.ta \w'#define 'u +\w'caddr_t    'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
I 4
.ta \w'#define 'u +\w'ifw_xtofree 'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
struct	ifxmt {
	struct	ifrw ifrw;
	caddr_t	ifw_base;			/* virt addr of buffer */
	struct	pte ifw_wmap[IF_MAXNUBAMR];	/* base pages for output */
	struct	mbuf *ifw_xtofree;		/* pages being dma'd out */
	short	ifw_xswapd;			/* mask of clusters swapped */
	short	ifw_nmr;			/* number of entries in wmap */
};
D 4
.ta \w'#define 'u +\w'ifw_proto      'u
E 4
I 4
.ta \w'#define 'u +\w'ifw_xtofree 'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 4
#define	ifw_addr	ifrw.ifrw_addr
#define	ifw_bdp	ifrw.ifrw_bdp
#define	ifw_flags	ifrw.ifrw_flags
#define	ifw_info	ifrw.ifrw_info
D 4
#define	ifw_proto       ifrw.ifrw_proto
E 4
I 4
#define	ifw_proto	ifrw.ifrw_proto
E 4
#define	ifw_mr	ifrw.ifrw_mr
.DE
One of each of these structures is conveniently packaged for interfaces
with single buffers for each direction, as follows:
.DS
.ta \w'#define 'u +\w'ifw_xtofree 'u +\w'pte ifu_wmap[IF_MAXNUBAMR];    'u
E 3
struct	ifuba {
D 3
	short	ifu_uban;			/* uba number */
	short	ifu_hlen;			/* local net header length */
	struct	uba_regs *ifu_uba;		/* uba regs, in vm */
	struct ifrw {
.if t .ta .5i 1.25i 2.0i 2.8i
.if n .ta .7i 1.75i 2.75i 3.8i
		caddr_t	ifrw_addr;		/* virt addr of header */
		int	ifrw_bdp;		/* unibus bdp */
		int	ifrw_info;		/* value from ubaalloc */
		int	ifrw_proto;		/* map register prototype */
		struct	pte *ifrw_mr;		/* base of map registers */
	} ifu_r, ifu_w;
.if t .ta .5i 1.25i 2.8i
.if n .ta .7i 1.75i 3.8i
	struct	pte ifu_wmap[IF_MAXNUBAMR];	/* base pages for output */
	short	ifu_xswapd;			/* mask of clusters swapped */
	short	ifu_flags;			/* used during uballoc's */
	struct	mbuf *ifu_xtofree;		/* pages being dma'd out */
E 3
I 3
	struct	ifubinfo ifu_info;
	struct	ifrw ifu_r;
	struct	ifxmt ifu_xmt;
E 3
};
I 3
.ta \w'#define 'u +\w'ifw_xtofree 'u
#define	ifu_uban	ifu_info.iff_uban
#define	ifu_hlen	ifu_info.iff_hlen
#define	ifu_uba		ifu_info.iff_uba
#define	ifu_flags	ifu_info.iff_flags
#define	ifu_w		ifu_xmt.ifrw
#define	ifu_xtofree	ifu_xmt.ifw_xtofree
E 3
.DE
.PP
D 3
The \fIif_uba\fP structure describes UNIBUS resources held by
an interface.
IF_NUBAMR map registers are held for datagram data, starting
at \fIifr_mr\fP.  UNIBUS map register \fIifr_mr\fP[\-1]
E 3
I 3
The \fIif_ubinfo\fP structure contains the general information needed
to characterize the I/O-mapped buffers for the device.
In addition, there is a structure describing each buffer, including
UNIBUS resources held by the interface.
Sufficient memory pages and bus map registers are allocated to each buffer
upon initialization according to the maximum packet size and header length.
The kernel virtual address of the buffer is held in \fIifrw_addr\fP,
and the map registers begin
at \fIifrw_mr\fP.  UNIBUS map register \fIifrw_mr\fP\^[\-1]
E 3
maps the local network header
ending on a page boundary.  UNIBUS data paths are
reserved for read and for
D 3
write, given by \fIifr_bdp\fP.  The prototype of the map
registers for read and for write is saved in \fIifr_proto\fP.
E 3
I 3
write, given by \fIifrw_bdp\fP.  The prototype of the map
registers for read and for write is saved in \fIifrw_proto\fP.
E 3
.PP
D 3
When write transfers are not full pages on page boundaries
the data is just copied into the pages mapped on the UNIBUS
E 3
I 3
When write transfers are not at least half-full pages on page boundaries,
the data are just copied into the pages mapped on the UNIBUS
E 3
and the transfer is started.
D 3
If a write transfer is of a (1024 byte) page size and on a page
E 3
I 3
If a write transfer is at least half a page long and on a page
E 3
boundary, UNIBUS page table entries are swapped to reference
the pages, and then the initial pages are
D 3
remapped from \fIifu_wmap\fP when the transfer completes.
E 3
I 3
remapped from \fIifw_wmap\fP when the transfer completes.
The mbufs containing the mapped pages are placed on the \fIifw_xtofree\fP
queue to be freed after transmission.
E 3
.PP
D 3
When read transfers give whole pages of data to be input, page
E 3
I 3
When read transfers give at least half a page of data to be input, page
E 3
frames are allocated from a network page list and traded
with the pages already containing the data, mapping the allocated
pages to replace the input pages for the next UNIBUS data input.
.PP
The following utility routines are available for use in
D 3
writing network interface drivers, all use the \fIifuba\fP
structure described above.
.IP "if_ubainit(ifu, uban, hlen, nmr);"
E 3
I 3
writing network interface drivers; all use the
structures described above.
.LP
if_ubaminit(ifubinfo, uban, hlen, nmr, ifr, nr, ifx, nx);
E 3
.br
D 3
\fIif_ubainit\fP allocates resources on UNIBUS adaptor \fIuban\fP
and stores the resultant information
in the \fIifuba\fP structure pointed to by \fIifu\fP. 
It is called only at boot time or after a UNIBUS reset. 
Two data paths (buffered or unbuffered,
depending on the \fIifu_flags\fP field) are allocated, one for
reading and one for writing.  The \fInmr\fP parameter indicates
E 3
I 3
if_ubainit(ifuba, uban, hlen, nmr);
.IP
\fIif_ubaminit\fP allocates resources on UNIBUS adapter \fIuban\fP,
storing the information in the \fIifubinfo\fP, \fIifrw\fP and \fIifxmt\fP
structures referenced.
The \fIifr\fP and \fIifx\fP parameters are pointers to arrays
of \fIifrw\fP and \fIifxmt\fP structures whose dimensions
are \fInr\fP and \fInx\fP, respectively.
\fIif_ubainit\fP is a simpler, backwards-compatible interface used
for hardware with single buffers of each type.
They are called only at boot time or after a UNIBUS reset. 
One data path (buffered or unbuffered,
depending on the \fIifu_flags\fP field) is allocated for each buffer.
The \fInmr\fP parameter indicates
E 3
the number of UNIBUS mapping registers required to map a maximal
sized packet onto the UNIBUS, while \fIhlen\fP specifies the size
of a local network header, if any, which should be mapped separately
from the data (see the description of trailer protocols in chapter 14).
Sufficient UNIBUS mapping registers and pages of memory are allocated
to initialize the input data path for an initial read.  For the output
data path, mapping registers and pages of memory are also allocated
and mapped onto the UNIBUS.  The pages associated with the output
data path are held in reserve in the event a write requires copying
non-page-aligned data (see \fIif_wubaput\fP below).
D 3
If \fIif_ubainit\fP is called with resources already allocated,
E 3
I 3
If \fIif_ubainit\fP is called with memory pages already allocated,
E 3
they will be used instead of allocating new ones (this normally
occurs after a UNIBUS reset).
D 3
A 1 is returned when allocation and initialization is successful,
E 3
I 3
A 1 is returned when allocation and initialization are successful,
E 3
0 otherwise.
D 3
.IP "m = if_rubaget(ifu, totlen, off0);"
E 3
I 3
.LP
m = if_ubaget(ifubinfo, ifr, totlen, off0, ifp);
E 3
.br
D 3
\fIif_rubaget\fP pulls read data off an interface.  \fItotlen\fP
specifies the length of data to be obtained, not counting the
E 3
I 3
m = if_rubaget(ifuba, totlen, off0, ifp);
.IP
\fIif_ubaget\fP and \fIif_rubaget\fP pull input data
out of an interface receive buffer and into an mbuf chain.
The first interface passes pointers to the \fIifubinfo\fP structure
for the interface and the \fIifrw\fP structure for the receive buffer;
the second call may be used for single-buffered devices.
\fItotlen\fP specifies the length of data to be obtained, not counting the
E 3
local network header.  If \fIoff0\fP is non-zero, it indicates
a byte offset to a trailing local network header which should be
D 3
copied into a
separate mbuf and prepended to the front of the resultant mbuf
chain.  When page sized units of data are present and are
page-aligned, the previously mapped data pages are remapped
into the mbufs and swapped with fresh pages; thus avoiding
any copying.  A 0 return value indicates a failure to allocate
resources.
.IP "if_wubaput(ifu, m);"
E 3
I 3
copied into a separate mbuf and prepended to the front of the resultant mbuf
chain.  When the data amount to at least a half a page,
the previously mapped data pages are remapped
into the mbufs and swapped with fresh pages, thus avoiding
any copy.
The receiving interface is recorded as \fIifp\fP, a pointer to an \fIifnet\fP
structure, for the use of the receiving network protocol.
A 0 return value indicates a failure to allocate resources.
.LP
if_wubaput(ifubinfo, ifx, m);
E 3
.br
D 3
\fIif_wubaput\fP maps a chain of mbufs onto a network interface
in preparation for output.  The chain includes any local network
E 3
I 3
if_wubaput(ifuba, m);
.IP
\fIif_ubaput\fP and \fIif_wubaput\fP map a chain of mbufs
onto a network interface in preparation for output.
The first interface is used by devices with multiple transmit buffers.
The chain includes any local network
E 3
header, which is copied so that it resides in the mapped and
D 3
aligned I/O space.  Any other mbufs which contained non page
sized data portions are also copied to the I/O space.
E 3
I 3
aligned I/O space.
Page-aligned data that are page-aligned in the output buffer
are mapped to the UNIBUS in place of the normal buffer page,
and the corresponding mbuf is placed on a queue to be freed after transmission.
Any other mbufs which contained non-page-sized
data portions are copied to the I/O space and then freed.
E 3
Pages mapped from a previous output operation (no longer needed)
D 3
are unmapped and returned to the network page pool.
.ds RH "Socket/protocol interface
.bp
E 3
I 3
are unmapped.
D 4
'ne 2i
E 4
E 3
E 1

h54671
s 00002/00001/00122
d D 6.3 86/06/05 09:53:12 karels 4 3
c formatting glitches
e
s 00024/00019/00099
d D 6.2 86/06/04 23:54:28 karels 3 2
c updates for 4.3
e
s 00000/00000/00118
d D 6.1 86/05/26 13:27:15 mckusick 2 1
c 4.3BSD beta release document
e
s 00118/00000/00000
d D 5.1 86/05/26 13:27:09 mckusick 1 0
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
.ds RH "Buffering and congestion control
E 3
I 3
.\".ds RH "Buffering and congestion control
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Buffering and congestion control\s0
.PP
One of the major factors in the performance of a protocol is
the buffering policy used.  Lack of a proper buffering policy
can force packets to be dropped, cause falsified windowing
information to be emitted by protocols, fragment host memory,
degrade the overall host performance, etc.  Due to problems
such as these, most systems allocate a fixed pool of memory
to the networking system and impose
a policy optimized for ``normal'' network operation.  
.PP
The networking system developed for UNIX is little different in this
respect.  At boot time a fixed amount of memory is allocated by
the networking system.  At later times more system memory
may be requested as the need arises, but at no time is
memory ever returned to the system.  It is possible to
garbage collect memory from the network, but difficult.  In
order to perform this garbage collection properly, some
portion of the network will have to be ``turned off'' as
data structures are updated.  The interval over which this
occurs must kept small compared to the average inter-packet
arrival time, or too much traffic may
be lost, impacting other hosts on the network, as well as
increasing load on the interconnecting mediums.  In our
environment we have not experienced a need for such compaction,
and thus have left the problem unresolved.
.PP
The mbuf structure was introduced in chapter 5.  In this
section a brief description will be given of the allocation
mechanisms, and policies used by the protocols in performing
connection level buffering.
.NH 2
Memory management
.PP
D 3
The basic memory allocation routines place no restrictions on
the amount of space which may be allocated.  Any request made
is filled until the system memory allocator starts refusing
to allocate additional memory.  When the current quota of memory
is insufficient to satisfy an mbuf allocation request, the
allocator requests enough new pages from the system to satisfy
the current request only.  All memory owned by the network is
described by a private page table used in remapping pages to
E 3
I 3
The basic memory allocation routines manage a private page map,
the size of which determines the maximum amount of memory
that may be allocated by the network.
A small amount of memory is allocated at boot time
to initialize the mbuf and mbuf page cluster free lists.
When the free lists are exhausted, more memory is requested
from the system memory allocator if space remains in the map.
If memory cannot be allocated,
callers may block awaiting free memory,
or the failure may be reflected to the caller immediately.
The allocator will not block awaiting free map entries, however,
as exhaustion of the page map usually indicates that buffers have been lost
due to a ``leak.''
The private page table is used by the network buffer management
routines in remapping pages to
E 3
be logically contiguous as the need arises.  In addition, an
array of reference counts parallels the page table and is used
D 3
when multiple copies of a page are present.
E 3
I 3
when multiple references to a page are present.
E 3
.PP
Mbufs are 128 byte structures, 8 fitting in a 1Kbyte
D 3
page of memory.  When data is placed in mbufs, if possible,
E 3
I 3
page of memory.  When data is placed in mbufs,
E 3
it is copied or remapped into logically contiguous pages of
D 3
memory from the network page pool.  Data smaller than the size
E 3
I 3
memory from the network page pool if possible.
Data smaller than half of the size
E 3
of a page is copied into one or more 112 byte mbuf data areas. 
.NH 2
Protocol buffering policies
.PP
Protocols reserve fixed amounts of
buffering for send and receive queues at socket creation time.  These
amounts define the high and low water marks used by the socket routines
in deciding when to block and unblock a process.  The reservation
of space does not currently
result in any action by the memory management
D 3
routines, though it is clear if one imposed an upper
bound on the total amount of physical memory allocated to the network,
reserving memory would become important.
E 3
I 3
routines.
E 3
.PP
Protocols which provide connection level flow control do this
based on the amount of space in the associated socket queues.  That
is, send windows are calculated based on the amount of free space
in the socket's receive queue, while receive windows are adjusted
based on the amount of data awaiting transmission in the send queue.
Care has been taken to avoid the ``silly window syndrome'' described
in [Clark82] at both the sending and receiving ends.
.NH 2
Queue limiting
.PP
Incoming packets from the network are always received unless
memory allocation fails.  However, each Level 1 protocol
input queue
has an upper bound on the queue's length, and any packets
exceeding that bound are discarded.  It is possible for a host to be
overwhelmed by excessive network traffic (for instance a host
acting as a gateway from a high bandwidth network to a low bandwidth
network).  As a ``defensive'' mechanism the queue limits may be
adjusted to throttle network traffic load on a host.
Consider a host willing to devote some percentage of
its machine to handling network traffic. 
If the cost of handling an
incoming packet can be calculated so that an acceptable
``packet handling rate''
can be determined, then input queue lengths may be dynamically
adjusted based on a host's network load and the number of packets
awaiting processing.  Obviously, discarding packets is
not a satisfactory solution to a problem such as this
(simply dropping packets is likely to increase the load on a network);
the queue lengths were incorporated mainly as a safeguard mechanism.
.NH 2
Packet forwarding
.PP
When packets can not be forwarded because of memory limitations,
D 3
the system generates a ``source quench'' message.  In addition,
E 3
I 3
the system attempts to generate a ``source quench'' message.  In addition,
E 3
any other problems encountered during packet forwarding are also
reflected back to the sender in the form of ICMP packets.  This
helps hosts avoid unneeded retransmissions.
.PP
Broadcast packets are never forwarded due to possible dire
consequences.  In an early stage of network development, broadcast
packets were forwarded and a ``routing loop'' resulted in network
saturation and every host on the network crashing.
D 3
.ds RH "Out of band data
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

h12492
s 00002/00001/00100
d D 6.3 86/06/05 09:53:23 karels 4 3
c formatting glitches
e
s 00015/00016/00086
d D 6.2 86/06/04 23:54:46 karels 3 2
c updates for 4.3
e
s 00000/00000/00102
d D 6.1 86/05/26 13:27:37 mckusick 2 1
c 4.3BSD beta release document
e
s 00102/00000/00000
d D 5.1 86/05/26 13:27:31 mckusick 1 0
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
.ds RH "Trailer protocols
E 3
I 3
.\".ds RH "Trailer protocols
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Trailer protocols\s0
.PP
Core to core copies can be expensive.
Consequently, a great deal of effort was spent
in minimizing such operations.  The VAX architecture
provides virtual memory hardware organized in
page units.  To cut down on copy operations, data
D 3
is kept in page sized units on page-aligned
E 3
I 3
is kept in page-sized units on page-aligned
E 3
boundaries whenever possible.  This allows data
to be moved in memory simply by remapping the page
instead of copying.  The mbuf and network
interface routines perform page table manipulations
where needed, hiding the complexities of the VAX
virtual memory hardware from higher level code. 
.PP
Data enters the system in two ways: from the user,
or from the network (hardware interface).  When data
is copied from the user's address space
into the system it is deposited in pages (if sufficient
D 3
data is present to fill an entire page).
E 3
I 3
data is present).
E 3
This encourages the user to transmit information in
messages which are a multiple of the system page size.
.PP
Unfortunately, performing a similar operation when taking
data from the network is very difficult.
Consider the format of an incoming packet.  A packet
usually contains a local network header followed by
one or more headers used by the high level protocols. 
Finally, the data, if any, follows these headers.  Since
the header information may be variable length, DMA'ing the eventual
data for the user into a page aligned area of
memory is impossible without
D 3
a priori knowledge of the format (e.g. supporting
E 3
I 3
\fIa priori\fP knowledge of the format (e.g., by supporting
E 3
only a single protocol header format).
.PP
To allow variable length header information to
be present and still ensure page alignment of data,
a special local network encapsulation may be used.
D 3
This encapsulation, termed a \fItrailer protocol\fP,
E 3
I 3
This encapsulation, termed a \fItrailer protocol\fP [Leffler84],
E 3
places the variable length header information after
the data.  A fixed size local network
header is then prepended to the resultant packet. 
The local network header contains the size of the
D 3
data portion, and a new \fItrailer protocol
E 3
I 3
data portion (in units of 512 bytes), and a new \fItrailer protocol
E 3
header\fP, inserted before the variable length
information, contains the size of the variable length
header information.  The following trailer
protocol header is used to store information
regarding the variable length protocol header:
.DS
._f
struct {
	short	protocol;	/* original protocol no. */
	short	length;	/* length of trailer */
};
.DE
.PP
The processing of the trailer protocol is very
D 3
simple.  On output, the local network header indicates
E 3
I 3
simple.  On output, the local network header indicates that
E 3
a trailer encapsulation is being used.
D 3
The protocol identifier also includes an indication
of the number of data pages present (before the trailer
protocol header).  The trailer protocol header is
initialized to contain the actual protocol and
variable length header size, and appended to the data
E 3
I 3
The header also includes an indication
of the number of data pages present before the trailer
protocol header.  The trailer protocol header is
initialized to contain the actual protocol identifier and the
variable length header size, and is appended to the data
E 3
along with the variable length header information.
.PP
On input, the interface routines identify the
trailer encapsulation
by the protocol type stored in the local network header,
then calculate the number of
pages of data to find the beginning of the trailer. 
The trailing information is copied into a separate
mbuf and linked to the front of the resultant packet.
.PP
Clearly, trailer protocols require cooperation between
source and destination.  In addition, they are normally
cost effective only when sizable packets are used.  The
current scheme works because the local network encapsulation
header is a fixed size, allowing DMA operations
to be performed at a known offset from the first data page
being received.  Should the local network header be
variable length this scheme fails. 
.PP
D 3
Statistics collected indicate as much as 200Kb/s
E 3
I 3
Statistics collected indicate that as much as 200Kb/s
E 3
can be gained by using a trailer protocol with
1Kbyte packets.  The average size of the variable
length header was 40 bytes (the size of a
minimal TCP/IP packet header).  If hardware
supports larger sized packets, even greater gains
may be realized.
D 3
.ds RH Acknowledgements
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

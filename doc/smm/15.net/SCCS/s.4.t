h62646
s 00002/00001/00038
d D 6.3 86/06/05 09:51:52 karels 4 3
c formatting glitches
e
s 00014/00008/00025
d D 6.2 86/06/04 23:52:58 karels 3 2
c updates for 4.3
e
s 00000/00000/00033
d D 6.1 86/05/26 13:24:42 mckusick 2 1
c 4.3BSD beta release document
e
s 00033/00000/00000
d D 5.1 86/05/26 13:24:35 mckusick 1 0
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
.ds RH "Address representation
E 3
I 3
.\".ds RH "Address representation
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Internal address representation\s0
.PP
Common to all portions of the system are two data structures.
These structures are used to represent
addresses and various data objects.
Addresses, internally are described by the \fIsockaddr\fP structure,
.DS
._f
struct sockaddr {
	short	sa_family;	/* data format identifier */
	char	sa_data[14];	/* address */
};
.DE
All addresses belong to one or more \fIaddress families\fP
which define their format and interpretation.
D 3
The \fIsa_family\fP field indicates which address family the address
belongs to, the \fIsa_data\fP field contains the actual data value.
E 3
I 3
The \fIsa_family\fP field indicates the address family to which the address
belongs, and the \fIsa_data\fP field contains the actual data value.
E 3
The size of the data field, 14 bytes, was selected based on a study
D 3
of current address formats*.
E 3
I 3
of current address formats.*
Specific address formats use private structure definitions
that define the format of the data field.
The system interface supports larger address structures,
although address-family-independent support facilities, for example routing
and raw socket interfaces, provide only 14 bytes for address storage.
Protocols that do not use those facilities (e.g, the current Unix domain)
may use larger data areas.
E 3
.FS
D 3
* Later versions of the system support variable length addresses.
E 3
I 3
* Later versions of the system may support variable length addresses.
E 3
.FE
D 3
.ds RH "Memory management
.bp
E 3
I 3
D 4
'ne 2i
E 4
E 3
E 1

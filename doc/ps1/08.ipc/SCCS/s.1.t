h40886
s 00023/00015/00058
d D 1.3 86/05/02 17:39:59 karels 3 2
c corrections
e
s 00018/00012/00055
d D 1.2 86/04/30 11:21:19 karels 2 1
c updates for 4.3 from lapsley
e
s 00067/00000/00000
d D 1.1 86/04/30 11:18:56 karels 1 0
c 4.2BSD version
e
u
U
t
T
I 1
D 2
.ds LH "4.2BSD IPC Primer
E 2
I 2
.\" Copyright (c) 1986 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 3
.ds LH "4.3BSD IPC Primer
E 2
.ds RH Introduction
.LP
E 3
I 3
.\".ds LH "4.3BSD IPC Primer
.\".ds RH Introduction
.\".ds RF "Leffler/Fabry/Joy
.\".ds LF "\*(DY
.\".ds CF "
E 3
.nr H1 1
I 3
.LP
E 3
.bp
D 3
.ds RF "Leffler/Fabry/Joy
D 2
.ds LF "DRAFT of \*(DY
E 2
I 2
.ds LF "\*(DY
E 2
.ds CF "
E 3
.LG
.B
.ce
1. INTRODUCTION
.sp 2
.R
.NL
D 2
One of the most important parts of 4.2BSD is the interprocess
E 2
I 2
D 3
One of the most important parts of 4.3BSD is the interprocess
E 2
communication facilities.  These facilities are the result of
E 3
I 3
One of the most important additions to UNIX in 4.2BSD was interprocess
communication.
These facilities were the result of
E 3
more than two years of discussion and research.  The facilities
D 2
provided in 4.2BSD incorporate many of the ideas from current
E 2
I 2
D 3
provided in 4.3BSD incorporate many of the ideas from current
E 3
I 3
provided in 4.2BSD incorporated many of the ideas from current
E 3
E 2
research, while trying to maintain the UNIX philosophy of
D 3
simplicity and conciseness.  It is hoped that
the interprocess communication
E 3
I 3
simplicity and conciseness.
The current release of Berkeley UNIX, 4.3BSD,
completes some of the IPC facilities
and provides an upward-compatible interface.
It is hoped that the interprocess communication
E 3
D 2
facilities included in 4.2BSD will establish a
E 2
I 2
facilities included in 4.3BSD will establish a
E 2
standard for UNIX.  From the response to the design,
it appears many organizations carrying out
work with UNIX are adopting it.
.PP
UNIX has previously been very weak in the area of interprocess
D 2
communication.  Prior to the 4.2BSD facilities, the only
E 2
I 2
communication.  Prior to the 4BSD facilities, the only
E 2
standard mechanism which allowed two processes to communicate were
pipes (the mpx files which were part of Version 7 were
experimental).  Unfortunately, pipes are very restrictive
in that
the two communicating processes must be related through a
common ancestor.
Further, the semantics of pipes makes them almost impossible
to maintain in a distributed environment. 
.PP
D 2
Earlier attempts at extending the ipc facilities of UNIX have
E 2
I 2
Earlier attempts at extending the IPC facilities of UNIX have
E 2
met with mixed reaction.  The majority of the problems have
D 2
been related to the fact these facilities have been tied to
E 2
I 2
been related to the fact that these facilities have been tied to
E 2
D 3
the UNIX file system; either through naming, or implementation.
E 3
I 3
the UNIX file system, either through naming or implementation.
E 3
D 2
Consequently, the ipc facilities provided in 4.2BSD have been
designed as a totally independent subsystem.  The 4.2BSD ipc
E 2
I 2
Consequently, the IPC facilities provided in 4.3BSD have been
designed as a totally independent subsystem.  The 4.3BSD IPC
E 2
allows processes to rendezvous in many ways. 
Processes may rendezvous through a UNIX file system-like
name space (a space where all names are path names)
as well as through a
network name space.  In fact, new name spaces may
be added at a future time with only minor changes visible
to users.  Further, the communication facilities 
D 2
have been extended to included more than the simple byte stream
E 2
I 2
have been extended to include more than the simple byte stream
E 2
D 3
provided by a pipe-like entity.  These extensions have resulted
E 3
I 3
provided by a pipe.  These extensions have resulted
E 3
in a completely new part of the system which users will need
time to familiarize themselves with.  It is likely that as
more use is made of these facilities they will be refined;
only time will tell.
.PP
I 3
This document provides a high-level description
of the IPC facilities in 4.3BSD and their use.
It is designed to complement the manual pages for the IPC primitives
by examples of their use.
E 3
The remainder of this document is organized in four sections.  
D 3
Section 2 introduces the new system calls and the basic model
E 3
I 3
Section 2 introduces the IPC-related system calls and the basic model
E 3
of communication.  Section 3 describes some of the supporting
library routines users may find useful in constructing distributed
applications.  Section 4 is concerned with the client/server model
used in developing applications and includes examples of the
two major types of servers.  Section 5 delves into advanced topics
which sophisticated users are likely to encounter when using
D 2
the ipc facilities.  
E 2
I 2
D 3
the IPC facilities.  
E 3
I 3
the IPC facilities.
E 3
E 2
E 1

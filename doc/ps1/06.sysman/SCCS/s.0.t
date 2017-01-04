h18149
s 00017/00001/00264
d D 6.7 04/11/28 23:33:06 msokolov 8 7
c Quasijarus working draft
e
s 00001/00001/00264
d D 6.6 86/05/13 16:20:02 mckusick 7 6
c fix those macros
e
s 00075/00075/00190
d D 6.5 86/05/12 11:59:19 mckusick 6 5
c format
e
s 00001/00001/00264
d D 6.4 86/05/12 01:23:09 karels 5 4
c spelling
e
s 00005/00004/00260
d D 6.3 86/05/12 01:00:31 karels 4 3
c update, correct, rephrase and re-propose
e
s 00006/00001/00258
d D 6.2 86/05/08 17:50:48 mckusick 3 2
c typesetting glitches
e
s 00009/00026/00250
d D 6.1 86/05/08 12:24:39 mckusick 2 1
c update virtual memory design
e
s 00276/00000/00000
d D 5.1 86/05/08 00:02:03 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1983 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 2
.\" %M% %I% %E%
E 2
I 2
D 4
.EH 'PS1:6-%''4.3BSD Architecture Manual'
.OH '4.3BSD Architecture Manual''PS1:6-%'
E 4
E 2
.if n .ND
.TL
D 2
4.2BSD System Manual
.sp
Revised July, 1983
E 2
I 2
Berkeley Software Architecture Manual
I 3
.br
E 3
D 8
4.3BSD Edition
E 8
I 8
4.3BSD-Quasijarus Working Draft
E 8
E 2
.AU
D 2
William Joy, Eric Cooper, Robert Fabry,
.br
Samuel Leffler, Kirk McKusick and David Mosher
E 2
I 2
D 3
William Joy, Samuel Leffler, M. Kirk McKusick, Michael Karels
E 3
I 3
William Joy, Robert Fabry,
.AU
Samuel Leffler, M. Kirk McKusick,
.AU
Michael Karels
E 3
E 2
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA  94720
I 8
.AU
Michael Sokolov
.AI
Quasijarus Project
International Free Computing Task Force
http://ifctfvax.Harhan.ORG/Quasijarus/
E 8
I 4
.EH 'PS1:6-%''4.3BSD Architecture Manual'
.OH '4.3BSD Architecture Manual''PS1:6-%'
E 4
D 2

(415) 642-7780
E 2
.AB
.FS
* UNIX is a trademark of Bell Laboratories.
.FE
This document summarizes the facilities
D 2
provided by the 4.2BSD version of the UNIX operating system.
E 2
I 2
D 4
provided by the 4.3BSD version of the UNIX operating system.
E 4
I 4
provided by the 4.3BSD version of the UNIX\|* operating system.
E 4
E 2
It does not attempt to act as a tutorial for use of the system
nor does it attempt to explain or justify the design of the
system facilities.
It gives neither motivation nor implementation details,
in favor of brevity.
.PP
The first section describes the basic kernel functions
provided to a UNIX process: process naming and protection,
memory management, software interrupts,
object references (descriptors), time and statistics functions,
and resource controls.
These facilities, as well as facilities for
bootstrap, shutdown and process accounting,
are provided solely by the kernel.
.PP
The second section describes the standard system
abstractions for
files and file systems,
communication,
terminal handling,
and process control and debugging.
These facilities are implemented by the operating system or by
network server processes.
.AE
.LP
I 8
.LG
WARNING: This document is a working draft!
It will change several times as work on 4.3BSD-Quasijarus progresses
and will be finalized only when approved by Quasijarus Project
principal maintainer Michael Sokolov.
Working draft copies should not be distributed except to Quasijarus
developers.
.LN
.LP
Printed on \n(cn\n(yr-\n(mo-\n(dy
E 8
D 2
.de PT
.lt \\n(LLu
.pc %
.nr PN \\n%
.tl '\\*(LH'\\*(CH'\\*(RH'
.lt \\n(.lu
..
.af PN i
.ds LH 4.2BSD System Manual
.ds RH Contents
.bp 1
.if t .ds CF -- September 1, 1982 --
.if t .ds LF CSRG TR/5
.if t .ds RF "Joy, et. al.
E 2
I 2
.bp
E 2
.ft B
.br
.sv 2
.ce
TABLE OF CONTENTS
.ft R
.LP
.sp 1
.nf
.B "Introduction."
.LP
.if t .sp .5v
.nf
.B "0. Notation and types"
.LP
.if t .sp .5v
.nf
.B "1. Kernel primitives"
.LP
.if t .sp .5v
.nf
.nf
\fB1.1.  Processes and protection\fP
D 6
\0\0\0.1.  Host and process identifiers
\0\0\0.2.  Process creation and termination
\0\0\0.3.  User and group ids
\0\0\0.4.  Process groups
E 6
I 6
1.1.1.  Host and process identifiers
1.1.2.  Process creation and termination
1.1.3.  User and group ids
1.1.4.  Process groups
E 6
.LP
.nf
\fB1.2.  Memory management\fP
D 6
\0\0\0.1.  Text, data and stack
\0\0\0.2.  Mapping pages
\0\0\0.3.  Page protection control
\0\0\0.4.  Giving and getting advice
I 2
\0\0\0.5.  Protection primitives
E 6
I 6
1.2.1.  Text, data and stack
1.2.2.  Mapping pages
1.2.3.  Page protection control
1.2.4.  Giving and getting advice
1.2.5.  Protection primitives
E 6
E 2
.LP
.if t .sp .5v
.nf
\fB1.3.  Signals\fP
D 6
\0\0\0.1.  Overview
\0\0\0.2.  Signal types
\0\0\0.3.  Signal handlers
\0\0\0.4.  Sending signals
\0\0\0.5.  Protecting critical sections
\0\0\0.6.  Signal stacks
E 6
I 6
1.3.1.  Overview
1.3.2.  Signal types
1.3.3.  Signal handlers
1.3.4.  Sending signals
1.3.5.  Protecting critical sections
1.3.6.  Signal stacks
E 6
.LP
.if t .sp .5v
.nf
\fB1.4.  Timing and statistics\fP
D 6
\0\0\0.1.  Real time
\0\0\0.2.  Interval time
E 6
I 6
1.4.1.  Real time
1.4.2.  Interval time
E 6
.LP
.if t .sp .5v
.nf
\fB1.5.  Descriptors\fP
D 6
\0\0\0.1.  The reference table
\0\0\0.2.  Descriptor properties
\0\0\0.3.  Managing descriptor references
\0\0\0.4.  Multiplexing requests
\0\0\0.5.  Descriptor wrapping
E 6
I 6
1.5.1.  The reference table
1.5.2.  Descriptor properties
1.5.3.  Managing descriptor references
1.5.4.  Multiplexing requests
1.5.5.  Descriptor wrapping
E 6
.LP
.if t .sp .5v
.nf
\fB1.6.  Resource controls\fP
D 6
\0\0\0.1.  Process priorities
\0\0\0.2.  Resource utilization
\0\0\0.3.  Resource limits
E 6
I 6
1.6.1.  Process priorities
1.6.2.  Resource utilization
1.6.3.  Resource limits
E 6
.LP
.if t .sp .5v
.nf
\fB1.7.  System operation support\fP
D 6
\0\0\0.1.   Bootstrap operations
\0\0\0.2.   Shutdown operations
\0\0\0.3.   Accounting
E 6
I 6
1.7.1.   Bootstrap operations
1.7.2.   Shutdown operations
1.7.3.   Accounting
E 6
.bp
.LP
.if t .sp .5v
.sp 1
.nf
\fB2.  System facilities\fP
.LP
.if t .sp .5v
.nf
\fB2.1.   Generic operations\fP
D 6
\0\0\0.1.   Read and write
\0\0\0.2.   Input/output control
\0\0\0.3.   Non-blocking and asynchronous operations
E 6
I 6
2.1.1.   Read and write
2.1.2.   Input/output control
2.1.3.   Non-blocking and asynchronous operations
E 6
.LP
.if t .sp .5v
.nf
\fB2.2.  File system\fP
D 6
\0\0\0.1   Overview
\0\0\0.2.  Naming
\0\0\0.3.  Creation and removal
\0\0\0.3.1.  Directory creation and removal
\0\0\0.3.2.  File creation
\0\0\0.3.3.  Creating references to devices
\0\0\0.3.4.  Portal creation
\0\0\0.3.6.  File, device, and portal removal
\0\0\0.4.  Reading and modifying file attributes
\0\0\0.5.  Links and renaming
\0\0\0.6.  Extension and truncation
\0\0\0.7.  Checking accessibility
\0\0\0.8.  Locking
\0\0\0.9.  Disc quotas
E 6
I 6
2.2.1   Overview
2.2.2.  Naming
2.2.3.  Creation and removal
2.2.3.1.  Directory creation and removal
2.2.3.2.  File creation
2.2.3.3.  Creating references to devices
2.2.3.4.  Portal creation
2.2.3.6.  File, device, and portal removal
2.2.4.  Reading and modifying file attributes
2.2.5.  Links and renaming
2.2.6.  Extension and truncation
2.2.7.  Checking accessibility
2.2.8.  Locking
2.2.9.  Disc quotas
E 6
.LP
.if t .sp .5v
.nf
D 5
\fB2.3.  Inteprocess communication\fP
E 5
I 5
\fB2.3.  Interprocess communication\fP
E 5
D 6
\0\0\0.1.   Interprocess communication primitives
\0\0\0.1.1.\0   Communication domains
\0\0\0.1.2.\0   Socket types and protocols
\0\0\0.1.3.\0   Socket creation, naming and service establishment
\0\0\0.1.4.\0   Accepting connections
\0\0\0.1.5.\0   Making connections
\0\0\0.1.6.\0   Sending and receiving data
\0\0\0.1.7.\0   Scatter/gather and exchanging access rights
\0\0\0.1.8.\0   Using read and write with sockets
\0\0\0.1.9.\0   Shutting down halves of full-duplex connections
\0\0\0.1.10.\0  Socket and protocol options
\0\0\0.2.   UNIX domain
\0\0\0.2.1.    Types of sockets
\0\0\0.2.2.    Naming
\0\0\0.2.3.    Access rights transmission
\0\0\0.3.   INTERNET domain
\0\0\0.3.1.    Socket types and protocols
\0\0\0.3.2.    Socket naming
\0\0\0.3.3.    Access rights transmission
\0\0\0.3.4.    Raw access
E 6
I 6
2.3.1.   Interprocess communication primitives
2.3.1.1.\0   Communication domains
2.3.1.2.\0   Socket types and protocols
2.3.1.3.\0   Socket creation, naming and service establishment
2.3.1.4.\0   Accepting connections
2.3.1.5.\0   Making connections
2.3.1.6.\0   Sending and receiving data
2.3.1.7.\0   Scatter/gather and exchanging access rights
2.3.1.8.\0   Using read and write with sockets
2.3.1.9.\0   Shutting down halves of full-duplex connections
2.3.1.10.\0  Socket and protocol options
2.3.2.   UNIX domain
2.3.2.1.    Types of sockets
2.3.2.2.    Naming
2.3.2.3.    Access rights transmission
2.3.3.   INTERNET domain
2.3.3.1.    Socket types and protocols
2.3.3.2.    Socket naming
2.3.3.3.    Access rights transmission
2.3.3.4.    Raw access
E 6
.LP
.if t .sp .5v
.nf
\fB2.4.  Terminals and devices\fP
D 6
\0\0\0.1.   Terminals
\0\0\0.1.1.    Terminal input
\0\0\0.1.1.1     Input modes
\0\0\0.1.1.2     Interrupt characters
\0\0\0.1.1.3     Line editing
\0\0\0.1.2.    Terminal output
\0\0\0.1.3.    Terminal control operations
\0\0\0.1.4.    Terminal hardware support
\0\0\0.2.   Structured devices
\0\0\0.3.   Unstructured devices
E 6
I 6
2.4.1.   Terminals
2.4.1.1.    Terminal input
2.4.1.1.1     Input modes
2.4.1.1.2     Interrupt characters
2.4.1.1.3     Line editing
2.4.1.2.    Terminal output
2.4.1.3.    Terminal control operations
2.4.1.4.    Terminal hardware support
2.4.2.   Structured devices
2.4.3.   Unstructured devices
E 6
.LP
.if t .sp .5v
.nf
\fB2.5.  Process control and debugging\fP
.LP
.if t .sp .5v
.nf
\fBI.  Summary of facilities\fP
.LP
D 2
.af PN 1
E 2
.de sh
.ds RH \\$1
.bp
.NH \\*(ss
\s+2\\$1\s0
.PP
.PP
..
D 2
.bp 1
E 2
I 2
.bp
E 2
D 7
.nr ss 1
E 7
I 7
.ds ss 1
E 7
.de _d
.if t .ta .6i 2.1i 2.6i
.\" 2.94 went to 2.6, 3.64 to 3.30
.if n .ta .84i 2.6i 3.30i
..
.de _f
.if t .ta .5i 1.25i 2.5i 3.5i
.\" 3.5i went to 3.8i
.if n .ta .7i 1.75i 3.8i 4.8i
..
.nr H1 -1
.sh "Notation and types
.PP
The notation used to describe system calls is a variant of a
C language call, consisting of a prototype call followed by
declaration of parameters and results.
An additional keyword \fBresult\fP, not part of the normal C language,
is used to indicate which of the declared entities receive results.
As an example, consider the \fIread\fP call, as described in
section 2.1:
.DS
cc = read(fd, buf, nbytes);
result int cc; int fd; result char *buf; int nbytes;
.DE
The first line shows how the \fIread\fP routine is called, with
three parameters.
As shown on the second line \fIcc\fP is an integer and \fIread\fP also
returns information in the parameter \fIbuf\fP.
.PP
Description of all error conditions arising from each system call
is not provided here; they appear in the programmer's manual.
In particular, when accessed from the C language,
many calls return a characteristic \-1 value
when an error occurs, returning the error code in the global variable
\fIerrno\fP.
Other languages may present errors in different ways.
.PP
D 4
A number of system standard types are defined in the include file <sys/types.h>
E 4
I 4
A number of system standard types are defined in the include file
.I <sys/types.h>
E 4
and used in the specifications here and in many C programs.
These include \fBcaddr_t\fP giving a memory address (typically as
a character pointer), 
\fBoff_t\fP giving a file offset (typically as a long integer),
and a set of unsigned types \fBu_char\fP, \fBu_short\fP, \fBu_int\fP
and \fBu_long\fP, shorthand names for \fBunsigned char\fP, \fBunsigned
short\fP, etc.
E 1

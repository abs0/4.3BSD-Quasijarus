h21691
s 00001/00001/00028
d D 6.2 86/05/12 01:00:37 karels 3 2
c update, correct, rephrase and re-propose
e
s 00000/00001/00029
d D 6.1 86/05/08 12:26:21 mckusick 2 1
c format updates for 4.3BSD
e
s 00030/00000/00000
d D 5.1 86/05/08 00:02:15 mckusick 1 0
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
.ds ss 1
.sh "Kernel primitives
.PP
The facilities available to a UNIX user process are logically
divided into two parts: kernel facilities directly implemented by
UNIX code running in the operating system, and system facilities
implemented either by the system, or in cooperation with a
\fIserver process\fP.  These kernel facilities are described in
this section 1.
.PP
The facilities implemented in the kernel are those which define the
D 3
\fIUNIX virtual machine\fP which each process runs in.
E 3
I 3
\fIUNIX virtual machine\fP in which each process runs.
E 3
Like many real machines, this virtual machine has memory management hardware,
an interrupt facility, timers and counters.  The UNIX
virtual machine also allows access to files and other objects through a set of
\fIdescriptors\fP.  Each descriptor resembles a device controller,
and supports a set of operations.  Like devices on real machines, some
of which are internal to the machine and some of which are external,
parts of the descriptor machinery are built-in to the operating system, while
other parts are often implemented in server processes on other machines.
The facilities provided through the descriptor machinery are described in
section 2.
.ds ss 2
E 1

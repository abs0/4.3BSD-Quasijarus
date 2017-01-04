h35168
s 00002/00001/00058
d D 6.3 86/06/03 18:04:48 karels 4 3
c 4.3 version
e
s 00009/00007/00050
d D 6.2 86/05/25 17:48:14 mckusick 3 2
c format for 4.3 documentation
e
s 00000/00000/00057
d D 6.1 86/05/25 16:36:59 mckusick 2 1
c 4.3BSD beta release document
e
s 00057/00000/00000
d D 5.1 86/05/25 16:36:52 mckusick 1 0
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
.bd S B 3
.de UX
.ie \\n(GA>0 \\$2UNIX\\$1
.el \{\
.if n \\$2UNIX\\$1*
.if t \\$2UNIX\\$1\\f1\(dg\\fP
.FS
.if n *UNIX
.if t \(dgUNIX
.ie \\$3=1 is a Footnote of Bell Laboratories.
.el is a Trademark of Bell Laboratories.
.FE
.nr GA 1\}
..
.TL
D 3
Building 4.2BSD
E 3
I 3
Building Berkeley 
E 3
.UX
D 3
Systems with Config
.br
June, 1983
E 3
I 3
Kernels with Config
E 3
.AU
D 3
Samuel J. Leffler
E 3
I 3
Samuel J. Leffler and Michael J. Karels
E 3
.AI
Computer Systems Research Group
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, California  94720
D 3
(415) 642-7780
E 3
.de IR
\fI\\$1\fP\\$2
..
.de DT
.TA 8 16 24 32 40 48 56 64 72 80
..
.AB
.PP
This document describes the use of
\fIconfig\fP\|(8) to configure and create bootable
D 4
4.2BSD system images.
E 4
I 4
4.3BSD system images.
E 4
It discusses the structure of system
configuration files and how to configure
systems with non-standard hardware configurations.
Sections describing the preferred way to
add new code to the system and how the system's autoconfiguration
process operates are included.  An appendix
contains a summary of the rules used by the system
in calculating the size of system data structures,
and also indicates some of the standard system size
limitations (and how to change them).
I 4
Other configuration options are also listed.
E 4
I 3
.sp
.LP
Revised %Q%
E 3
.AE
D 3
.ND
E 3
I 3
.LP
.OH 'Building Kernels with Config''SMM:2-%'
.EH 'SMM:2-%''Building Kernels with Config'
E 3
E 1

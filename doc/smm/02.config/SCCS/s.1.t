h21529
s 00006/00015/00028
d D 6.3 86/06/03 18:04:51 karels 4 3
c 4.3 version
e
s 00000/00002/00043
d D 6.2 86/05/25 17:48:19 mckusick 3 2
c format for 4.3 documentation
e
s 00000/00000/00045
d D 6.1 86/05/25 16:37:45 mckusick 2 1
c 4.3BSD beta release document
e
s 00045/00000/00000
d D 5.1 86/05/25 16:37:39 mckusick 1 0
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
D 4
.ds LH "Building Systems With Config
.ds RH Introduction
.ds CF July 27, 1983
D 3
.LP
E 3
.nr H1 1
.ds CH "
.bp
D 3
.nr % 1
E 3
.ds CH "\(hy \\n(PN \(hy
.LG
.B
.ce
1. INTRODUCTION
.sp 2
.R
.NL
E 4
I 4
.\".ds RH Introduction
.ne 2i
.sp 3
.NH
INTRODUCTION
E 4
.PP
.I Config
D 4
is a tool used in building 4.2BSD system images.
E 4
I 4
is a tool used in building 4.3BSD system images (the UNIX kernel).
E 4
It takes a file describing a system's tunable parameters and
hardware support, and generates a collection
of files which are then used to build a copy of UNIX appropriate
to that configuration.
.I Config
simplifies system maintenance by isolating system dependencies
in a single, easy to understand, file.
.PP
This document describes the content and 
format of system configuration
files and the rules which must be followed when creating 
these files.  Example configuration files are constructed
and discussed.
.PP
Later sections suggest guidelines to be used in modifying
system source and explain some of the inner workings of the
autoconfiguration process.  Appendix D summarizes the rules
used in calculating the most important system data structures
and indicates some inherent system data structure size
limitations (and how to go about modifying them).
E 1

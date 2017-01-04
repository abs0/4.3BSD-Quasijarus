h36522
s 00029/00027/00056
d D 6.1 86/05/14 16:44:51 kjd 2 1
c 4.3BSD beta release document
e
s 00083/00000/00000
d D 5.1 86/05/14 16:44:28 kjd 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
D 2
.\" Copyright (c) 1980 Regents of the University of California.
E 2
I 2
.\" Copyright (c) 1986 Regents of the University of California.
E 2
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.ds RH Introduction
.NH
Introduction
.PP
This paper describes the changes from the original 512 byte UNIX file
system to the new one released with the 4.2 Berkeley Software Distribution.
It presents the motivations for the changes,
D 2
the methods used to affect these changes,
E 2
I 2
the methods used to effect these changes,
E 2
the rationale behind the design decisions,
and a description of the new implementation.
This discussion is followed by a summary of
the results that have been obtained,
directions for future work,
and the additions and changes
D 2
that have been made to the user visible facilities.
The paper concludes with a history of the software engineering
of the project.
E 2
I 2
that have been made to the facilities that are
available to programmers.
E 2
.PP
The original UNIX system that runs on the PDP-11\(dg
.FS
\(dg DEC, PDP, VAX, MASSBUS, and UNIBUS are
trademarks of Digital Equipment Corporation.
.FE
has simple and elegant file system facilities.  File system input/output
is buffered by the kernel;
there are no alignment constraints on
data transfers and all operations are made to appear synchronous.
All transfers to the disk are in 512 byte blocks, which can be placed
D 2
arbitrarily within the data area of the file system.  No constraints
other than available disk space are placed on file growth
[Ritchie74], [Thompson79].
E 2
I 2
arbitrarily within the data area of the file system.  Virtually
no constraints other than available disk space are placed on file growth
[Ritchie74], [Thompson78].*
.FS
* In practice, a file's size is constrained to be less than about
one gigabyte.
.FE
E 2
.PP
When used on the VAX-11 together with other UNIX enhancements,
the original 512 byte UNIX file
system is incapable of providing the data throughput rates
that many applications require.
For example, 
D 2
applications that need to do a small amount of processing
on a large quantities of data
such as VLSI design and image processing,
E 2
I 2
applications
such as VLSI design and image processing
do a small amount of processing
on a large quantities of data and
E 2
need to have a high throughput from the file system.
D 2
High throughput rates are also needed by programs with
large address spaces that are constructed by mapping
files from the file system into virtual memory.
E 2
I 2
High throughput rates are also needed by programs
that map files from the file system into large virtual
address spaces.
E 2
Paging data in and out of the file system is likely
D 2
to occur frequently.
E 2
I 2
to occur frequently [Ferrin82b].
E 2
This requires a file system providing
D 2
higher bandwidth than the original 512 byte UNIX one which provides only about
E 2
I 2
higher bandwidth than the original 512 byte UNIX
one that provides only about
E 2
two percent of the maximum disk bandwidth or about
20 kilobytes per second per arm [White80], [Smith81b].
.PP
Modifications have been made to the UNIX file system to improve
its performance.
Since the UNIX file system interface
is well understood and not inherently slow,
this development retained the abstraction and simply changed
the underlying implementation to increase its throughput.
D 2
Consequently users of the system have not been faced with
E 2
I 2
Consequently, users of the system have not been faced with
E 2
massive software conversion.
.PP
Problems with file system performance have been dealt with
extensively in the literature; see [Smith81a] for a survey.
I 2
Previous work to improve the UNIX file system performance has been
done by [Ferrin82a].
E 2
The UNIX operating system drew many of its ideas from Multics,
a large, high performance operating system [Feiertag71].
Other work includes Hydra [Almes78],
Spice [Thompson80],
D 2
and a file system for a lisp environment [Symbolics81a].
.PP
A major goal of this project has been to build a file system that is
extensible into a networked environment [Holler73].
Other work on network file systems describe
centralized file servers [Accetta80],
distributed file servers [Dion80], [Luniewski77], [Porcar82],
and protocols to reduce the amount of information that must be
transferred across a network [Symbolics81b], [Sturgis80].
E 2
I 2
and a file system for a LISP environment [Symbolics81].
A good introduction to the physical latencies of disks is
described in [Pechura83].
E 2
.ds RH Old file system
D 2
.bp
E 2
I 2
.sp 2
.ne 1i
E 2
E 1

h62225
s 00010/00010/00044
d D 1.2 85/08/11 10:42:41 cabrera 2 1
c my first pass
e
s 00054/00000/00000
d D 1.1 85/07/27 19:42:59 mckusick 1 0
c date and time created 85/07/27 19:42:59 by mckusick
e
u
U
t
T
I 1
.\" Copyright (c) 1985 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.ds RH Introduction
.af PN 1
.bp 1
.NH
Introduction
.PP
D 2
The 4.2 Berkeley Software Distribution of 
E 2
I 2
The Berkeley Software Distributions of
E 2
.UX
D 2
for the VAX has added many new capabilities that were
E 2
I 2
for the VAX have added many new capabilities that were
E 2
previously unavailable under
.UX .
The development effort for 4.2BSD concentrated on providing new
facilities, and in getting them to work correctly.
Many new data structures were added to the system to support
these new capabilities.
In addition,
many of the existing data structures and algorithms
were put to new uses or their old functions placed under increased demand.
D 2
The limited development period left little time for tuning the completed system.
E 2
The effect of these changes was that
mechanisms that were well tuned under 4.1BSD
no longer provided adequate performance for 4.2BSD.
The increased user feedback that came with the release of
4.2BSD and a growing body of experience with the system
highlighted the performance shortcomings of 4.2BSD.
.PP
This paper details the work that we have done since
the release of 4.2BSD to measure the performance of the system,
detect the bottlenecks,
and find solutions to remedy them.
Most of our tuning has been in the context of the real
timesharing systems in our environment.
Rather than using simulated workloads,
we have sought to analyze our tuning efforts under
realistic conditions.
Much of the work has been done in the machine independent parts
of the system, hence these improvements could be applied to
other variants of UNIX with equal success.
I 2
All of the changes made have been included in 4.3BSD.
E 2
.PP
D 2
The first part of this paper describes the tools and techniques
available for measuring system performance.
The second part describes the results of using these tools.
The third part of this paper describes the performance improvements
E 2
I 2
Section 2 of the paper describes the tools and techniques
available to us for measuring system performance.
In Section 3 we present the results of using these tools, while Section 4
has the performance improvements
E 2
that have been made to the system based on our measurements.
D 2
The fourth part describes functional enhancements that have
been made.
The final part discusses some of the security problems that
E 2
I 2
Section 5 highlights the functional enhancements that have
been made to Berkeley UNIX 4.2BSD.
Section 6 discusses some of the security problems that
E 2
have been addressed.
E 1

h01507
s 00015/00000/00000
d D 1.1 84/05/21 17:58:49 mckusick 1 0
c date and time created 84/05/21 17:58:49 by mckusick
e
u
U
t
T
I 1
.\"	%W%	(Copyright 1984 M. K. McKusick)	%E%
.ds RH Introduction
.NH 1
Introduction
.PP
The purpose of this paper is to describe the tools and techniques 
that are available for improving the performance of the the kernel.
The primary tool used to measure the kernel is the hierarchical
profiler \fIgprof\fP.
The profiler enables the user to measure the cost of
the abstractions that the kernel provides to the user.
Once the expensive abstractions are identified,
optimizations are postulated to help improve their performance.
These optimizations are each individually
verified to insure that they are producing a measurable improvement.
E 1

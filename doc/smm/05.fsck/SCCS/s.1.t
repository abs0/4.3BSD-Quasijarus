h38027
s 00001/00002/00055
d D 4.2 85/07/18 22:42:42 mckusick 2 1
c update to reflect 4.3BSD version of fsck
e
s 00057/00000/00000
d D 4.1 85/06/03 17:25:41 mckusick 1 0
c version distributed with 4.2BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1982 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.ds RH Introduction
.NH
Introduction
.PP
This document reflects the use of
.I fsck
D 2
with the 4.2BSD file system organization.  This
E 2
I 2
with the 4.2BSD and 4.3BSD file system organization.  This
E 2
is a revision of the
original paper written by
T. J. Kowalski.
.PP
When a UNIX
operating system is brought up, a consistency
check of the file systems should always be performed.
This precautionary measure helps to insure
a reliable environment for file storage on disk.
If an inconsistency is discovered,
corrective action must be taken.
.I Fsck
runs in two modes.
Normally it is run non-interactively by the system after 
a normal boot.
When running in this mode,
it will only make changes to the file system that are known
to always be correct.
If an unexpected inconsistency is found
.I fsck
will exit with a non-zero exit status, 
leaving the system running single-user.
Typically the operator then runs 
.I fsck
interactively.
When running in this mode,
each problem is listed followed by a suggested corrective action.
The operator must decide whether or not the suggested correction
should be made.
.PP
The purpose of this memo is to dispel the
mystique surrounding
file system inconsistencies.
It first describes the updating of the file system
(the calm before the storm) and
then describes file system corruption (the storm).
Finally,
the set of deterministic corrective actions
used by
.I fsck
(the Coast Guard
to the rescue) is presented.
.ds RH Overview of the File System
D 2
.bp
E 2
E 1

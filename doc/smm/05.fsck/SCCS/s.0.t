h65510
s 00030/00051/00093
d D 4.3 86/05/20 16:19:35 kjd 3 2
c Fixes for typesetting
e
s 00006/00007/00138
d D 4.2 85/07/18 22:42:35 mckusick 2 1
c update to reflect 4.3BSD version of fsck
e
s 00145/00000/00000
d D 4.1 85/06/03 17:23:47 mckusick 1 0
c version distributed with 4.2BSD
e
u
U
t
T
I 1
D 3
.\" Copyright (c) 1982 Regents of the University of California.
E 3
I 3
.\" Copyright (c) 1986 Regents of the University of California.
E 3
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.if n .ND
.TL
Fsck \- The UNIX\(dg File System Check Program
D 3
.sp
D 2
Revised July 28, 1983
E 2
I 2
Revised July 16, 1985
E 3
I 3
.EH 'SMM:5-%''The \s-2UNIX\s+2 File System Check Program'
.OH 'The \s-2UNIX\s+2 File System Check Program''SMM:5-%'
E 3
E 2
.AU
Marshall Kirk McKusick
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA  94720
.AU
T. J. Kowalski
.AI
Bell Laboratories
Murray Hill, New Jersey 07974
.AB
.FS
\(dgUNIX is a trademark of Bell Laboratories.
.FE
.FS
This work was done under grants from
the National Science Foundation under grant MCS80-05144,
and the Defense Advance Research Projects Agency (DoD) under
Arpa Order No. 4031 monitored by Naval Electronic System Command under
Contract No. N00039-82-C-0235.
.FE
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
File System Check Program (\fIfsck\fR)
is an interactive file system check and repair program.
.I Fsck
uses the redundant structural information in the
UNIX file system to perform several consistency checks.
If an inconsistency is detected, it is reported
to the operator, who may elect to fix or ignore
each inconsistency.
These inconsistencies result from the permanent interruption
of the file system updates, which are performed every
time a file is modified.
Unless there has been a hardware failure,
.I fsck
is able to repair corrupted file systems
using procedures based upon the order in which UNIX honors
these file system update requests.
.PP
The purpose of this document is to describe the normal updating
of the file system,
to discuss the possible causes of file system corruption,
and to present the corrective actions implemented
by
.I fsck.
Both the program and the interaction between the
program and the operator are described.
I 3
.sp 2
.LP
Revised July 16, 1985
E 3
.AE
.LP
D 3
.de PT
.lt \\n(LLu
.pc %
.nr PN \\n%
.tl '\\*(LH'\\*(CH'\\*(RH'
.lt \\n(.lu
..
.af PN i
.ds LH Fsck
.ds RH Contents
.bp 1
D 2
.if t .ds CF July 28, 1983
.if t .ds LF CSRG TR/9
.if t .ds RF McKusick, et. al.
E 2
I 2
..if t .ds CF July 16, 1985
..if t .ds LF CSRG TR/9
..if t .ds RF McKusick, et. al.
E 3
I 3
.bp
E 3
E 2
.ce
.B "TABLE OF CONTENTS"
.LP
.sp 1
.nf
.B "1.  Introduction"
.LP
.sp .5v
.nf
.B "2.  Overview of the file system
D 3
\0.1.    Superblock
\0.2.    Summary Information
\0.3.    Cylinder groups
\0.4.    Fragments
\0.5.    Updates to the file system
E 3
I 3
2.1.    Superblock
2.2.    Summary Information
2.3.    Cylinder groups
2.4.    Fragments
2.5.    Updates to the file system
E 3
.LP
.sp .5v
.nf
.B "3.  Fixing corrupted file systems
D 3
\0.1.    Detecting and correcting corruption
\0.2.    Super block checking
\0.3.    Free block checking
\0.4.    Checking the inode state
\0.5.    Inode links
\0.6.    Inode data size
\0.7.    Checking the data associated with an inode
\0.8.    File system connectivity
E 3
I 3
3.1.    Detecting and correcting corruption
3.2.    Super block checking
3.3.    Free block checking
3.4.    Checking the inode state
3.5.    Inode links
3.6.    Inode data size
3.7.    Checking the data associated with an inode
3.8.    File system connectivity
E 3
.LP
.sp .5v
.nf
.B Acknowledgements
.LP
.sp .5v
.nf
.B References
.LP
.sp .5v
.nf
.B "4.  Appendix A
D 3
\0.1.     Conventions
\0.2.     Initialization
\0.3.     Phase 1 - Check Blocks and Sizes
\0.4.     Phase 1b - Rescan for more Dups
\0.5.     Phase 2 - Check Pathnames
\0.6.     Phase 3 - Check Connectivity
\0.7.     Phase 4 - Check Reference Counts
\0.8.     Phase 5 - Check Cyl groups
D 2
\0.9.     Phase 6 - Salvage Cylinder Groups
\0.10.    Cleanup
E 2
I 2
\0.9.     Cleanup
E 3
I 3
4.1.     Conventions
4.2.     Initialization
4.3.     Phase 1 - Check Blocks and Sizes
4.4.     Phase 1b - Rescan for more Dups
4.5.     Phase 2 - Check Pathnames
4.6.     Phase 3 - Check Connectivity
4.7.     Phase 4 - Check Reference Counts
4.8.     Phase 5 - Check Cyl groups
4.9.     Cleanup
E 3
E 2
.ds RH Introduction
D 3
.af PN 1
.bp 1
.de _d
.if t .ta .6i 2.1i 2.6i
.\" 2.94 went to 2.6, 3.64 to 3.30
.if n .ta .84i 2.6i 3.30i
..
.de _f
.if t .ta .5i 1.25i 2.5i
.\" 3.5i went to 3.8i
.if n .ta .7i 1.75i 3.8i
..
E 3
I 3
.bp
E 3
E 1

h33079
s 00014/00039/00114
d D 6.2 86/05/20 16:36:35 kjd 3 2
c fixes for typesetting
e
s 00049/00017/00104
d D 6.1 86/05/14 16:44:01 kjd 2 1
c 4.3BSD beta release document
e
s 00121/00000/00000
d D 5.1 86/05/14 16:42:14 kjd 1 0
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
I 2
D 3
.EH 'SMM:14-%''A Fast File System for \s-2UNIX\s+2'
.OH 'A Fast File System for \s-2UNIX\s+2''SMM:14-%'
E 3
.EQ
delim $$
.EN
E 2
.if n .ND
.TL
A Fast File System for UNIX*
D 3
.sp
D 2
Revised July 27, 1983
E 2
I 2
Revised February 18, 1984
E 3
I 3
.EH 'SMM:14-%''A Fast File System for \s-2UNIX\s+2'
.OH 'A Fast File System for \s-2UNIX\s+2''SMM:14-%'
E 3
E 2
.AU
Marshall Kirk McKusick, William N. Joy\(dg,
Samuel J. Leffler\(dd, Robert S. Fabry
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA  94720
.AB
.FS
* UNIX is a trademark of Bell Laboratories.
.FE
.FS
D 2
\(dgWilliam N. Joy is currently employed by:
E 2
I 2
\(dg William N. Joy is currently employed by:
E 2
Sun Microsystems, Inc, 2550 Garcia Avenue, Mountain View, CA 94043
.FE
.FS
D 2
\(ddSamuel J. Leffler is currently employed by:
E 2
I 2
\(dd Samuel J. Leffler is currently employed by:
E 2
Lucasfilm Ltd., PO Box 2009, San Rafael, CA 94912
.FE
.FS
This work was done under grants from
the National Science Foundation under grant MCS80-05144,
and the Defense Advance Research Projects Agency (DoD) under
D 2
Arpa Order No. 4031 monitored by Naval Electronic System Command under
E 2
I 2
ARPA Order No. 4031 monitored by Naval Electronic System Command under
E 2
Contract No. N00039-82-C-0235.
.FE
A reimplementation of the UNIX file system is described.
The reimplementation provides substantially higher throughput
D 2
rates by using more flexible allocation policies,
that allow better locality of reference and that can
E 2
I 2
rates by using more flexible allocation policies
that allow better locality of reference and can
E 2
be adapted to a wide range of peripheral and processor characteristics.
The new file system clusters data that is sequentially accessed
D 2
and provides two block sizes to allow fast access for large files
E 2
I 2
and provides two block sizes to allow fast access to large files
E 2
while not wasting large amounts of space for small files.
File access rates of up to ten times faster than the traditional
UNIX file system are experienced.
D 2
Long needed enhancements to the user interface are discussed.
These include a mechanism to lock files, 
E 2
I 2
Long needed enhancements to the programmers'
interface are discussed.
These include a mechanism to place advisory locks on files, 
E 2
extensions of the name space across file systems,
D 2
the ability to use arbitrary length file names,
and provisions for efficient administrative control of resource usage.
E 2
I 2
the ability to use long file names,
and provisions for administrative control of resource usage.
I 3
.sp
.LP
Revised February 18, 1984
E 3
E 2
.AE
.LP
I 2
.sp 2
CR Categories and Subject Descriptors:
D.4.3
.B "[Operating Systems]":
File Systems Management \-
.I "file organization, directory structures, access methods";
D.4.2
.B "[Operating Systems]":
Storage Management \-
.I "allocation/deallocation strategies, secondary storage devices";
D.4.8
.B "[Operating Systems]":
Performance \-
.I "measurements, operational analysis";
H.3.2
.B "[Information Systems]":
Information Storage \-
.I "file organization"
.sp
Additional Keywords and Phrases:
UNIX,
file system organization,
file system performance,
file system design,
application program interface.
.sp
General Terms:
file system,
measurement,
performance.
E 2
D 3
.de PT
.lt \\n(LLu
.pc %
.nr PN \\n%
.tl '\\*(LH'\\*(CH'\\*(RH'
.lt \\n(.lu
..
.af PN i
.ds LH File System
.ds RH Contents
.bp 1
D 2
.if t .ds CF July 27, 1983
E 2
I 2
.if t .ds CF February 18, 1984
E 2
.if t .ds LF CSRG TR/7
.if t .ds RF McKusick, et. al.
E 3
I 3
.bp 
E 3
.ce
.B "TABLE OF CONTENTS"
.LP
.sp 1
.nf
.B "1.  Introduction"
.LP
.sp .5v
.nf
.B "2.  Old file system
.LP
.sp .5v
.nf
.B "3.  New file system organization
D 3
\0.1.    Optimizing storage utilization
\0.2.    File system parameterization
\0.3.    Layout policies
E 3
I 3
3.1.    Optimizing storage utilization
3.2.    File system parameterization
3.3.    Layout policies
E 3
.LP
.sp .5v
.nf
.B "4.  Performance
.LP
.sp .5v
.nf
.B "5.  File system functional enhancements
D 3
\0.1.     Long file names
\0.2.     File locking
\0.3.     Symbolic links
\0.4.     Rename
\0.5.     Quotas
E 3
I 3
5.1.     Long file names
5.2.     File locking
5.3.     Symbolic links
5.4.     Rename
5.5.     Quotas
E 3
D 2
.LP
.sp .5v
.nf
.B "6.  Software engineering
E 2
.LP
.sp .5v
.nf
.B Acknowledgements
.LP
.sp .5v
.nf
.B References
D 3
.ds RH Introduction
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
E 1

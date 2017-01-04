h30415
s 00001/00001/00065
d D 1.3 88/07/17 09:36:42 karels 3 2
c add keywords
e
s 00019/00013/00047
d D 1.2 88/07/17 09:31:47 karels 2 1
c karels, bostic editing
e
s 00060/00000/00000
d D 1.1 88/06/13 10:48:15 bostic 1 0
c date and time created 88/06/13 10:48:15 by bostic
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
.\" Copyright (c) 1988 Regents of the University of California.
E 2
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
D 3
.\"	@(#)0.t	6.1 (Berkeley) 5/13/86
E 3
I 3
.\"	%W% (Berkeley) %G%
E 3
.\"
D 2
.EH 'SMM:1-%''Installing and Operating 4.3BSD on the Tahoe'
.OH 'Installing and Operating 4.3BSD on the Tahoe''SMM:1-%'
.ds 4B 4.3BSD
E 2
I 2
.EH 'SMM:1-%''Installing and Operating 4.3BSD-tahoe UNIX on the Tahoe'
.OH 'Installing and Operating 4.3BSD-tahoe UNIX on the Tahoe''SMM:1-%'
.ds 4B 4.3BSD-tahoe
.nr Th 1		\" Tahoe version
.ds Mc Tahoe
.ds mC tahoe
.ds Dk dk
.ds Dn Eagle
.ds Pa c
.ds Ps 4.3BSD-beta
E 2
.bd S B 3
.TL
D 2
Installing and Operating \*(4B on the Tahoe
E 2
I 2
Installing and Operating \*(4B UNIX* on the Tahoe
E 2
.br
D 2
April 1, 1986
E 2
I 2
July 14, 1988
E 2
.AU
Samuel J. Leffler
.AU
I 2
Keith Bostic
.AU
E 2
Michael J. Karels
.AU
Marshall Kirk McKusick
.AI
Computer Systems Research Group
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, California  94720
(415) 642-7780
.de IR
\\fI\\$1\|\\fP\\$2
..
.de UX
UNIX\\$1
..
.AB
.PP
.FS
D 2
* Tahoe is a trademark of Computer Consoles Incorporated.
E 2
I 2
*\s-2UNIX\s0 is a register trademark of AT&T in the USA and other countries.
E 2
.FE
D 2
.FS
** \s-2UNIX\s0 is a Trademark of Bell Laboratories.
.FE
E 2
This document contains instructions for the
installation and operation of the
\*(4B release of
D 2
.UX **
E 2
I 2
.UX
E 2
as distributed by The University of California at Berkeley
D 2
for the Tahoe* (CCI Power 6/32 and similar machines).
E 2
I 2
for the Tahoe (CCI Power 6/32 and similar machines).
E 2
.PP
D 2
It discusses procedures for installing UNIX on a new Tahoe,
E 2
I 2
It discusses procedures for installing UNIX on a new machine,
E 2
and for upgrading an existing 4.2BSD Tahoe UNIX system to the new release.
An explanation of how to lay out file systems on available disks,
how to set up terminal lines and user accounts,
and how to do system-specific tailoring is provided.
A description of how to install and configure the networking
facilities included with \*(4B is included.
Finally, the document details system operation procedures:
shutdown and startup,
hardware error reporting and diagnosis, file system backup procedures,
resource control, performance monitoring, and procedures for recompiling
and reinstalling system software.
.AE
E 1

h28573
s 00011/00005/00069
d D 6.4 03/11/18 22:18:02 msokolov 4 3
c update for 4.3BSD-Quasijarus
e
s 00000/00000/00074
d D 6.3 03/11/16 16:24:17 msokolov 3 2
c bump it up to 6.3
e
s 00000/00000/00074
d D 6.2 03/11/16 16:23:49 msokolov 2 1
c bump it up to 6.3
e
s 00074/00000/00000
d D 6.1 03/11/16 16:22:17 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 6.3
e
u
U
t
T
I 1
.\" Copyright (c) 1980,1986,1988 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 4
.EH 'SMM:1-%''Installing and Operating 4.3BSD-tahoe UNIX on the VAX'
.OH 'Installing and Operating 4.3BSD-tahoe UNIX on the VAX''SMM:1-%'
.ds 4B 4.3BSD-tahoe
E 4
I 4
.EH 'SMM:1-%''Installing and Operating 4.3BSD-Quasijarus UNIX on the VAX'
.OH 'Installing and Operating 4.3BSD-Quasijarus UNIX on the VAX''SMM:1-%'
.ds 4B 4.3BSD-Quasijarus
E 4
.nr Vx 1		\" VAX version
.ds Mc VAX
.ds mC vax
.ds Dk hp
.ds Dn RM80
.ds Pa g
.ds Ps 4.3BSD
.bd S B 3
.TL
Installing and Operating \*(4B UNIX* on the VAX\(dg
.br
D 4
July 14, 1988
E 4
I 4
%Q%
E 4
.AU
Michael J. Karels
.AU
Chris Torek
.AU
James M. Bloom
.AU
Marshall Kirk McKusick
.AU
Samuel J. Leffler
.AU
William N. Joy
.AI
Computer Systems Research Group
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, California  94720
(415) 642-7780
I 4
.AU
Michael Sokolov
.AI
Quasijarus Project
International Free Computing Task Force
http://ifctfvax.Harhan.ORG/Quasijarus/
E 4
.de IR
\\fI\\$1\|\\fP\\$2
..
.de UX
UNIX\\$1
..
.AB
.PP
.FS
*\s-2UNIX\s0 is a register trademark of AT&T in the USA and other countries.
.FE
.FS
\(dgDEC, VAX, IDC, SBI, UNIBUS and MASSBUS are trademarks of
Digital Equipment Corporation.
.FE
This document contains instructions for the
installation and operation of the
\*(4B release of the VAX
.UX
D 4
system, as distributed by The University of California at Berkeley.
E 4
I 4
system, as distributed by Quasijarus Consortium.
E 4
.PP
It discusses procedures for installing UNIX on a new VAX,
and for upgrading an existing 4.2BSD or 4.3BSD
VAX UNIX system to the new release.
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

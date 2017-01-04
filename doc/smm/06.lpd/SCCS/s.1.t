h24015
s 00005/00004/00046
d D 6.4 04/08/24 20:23:23 msokolov 5 4
c document Quasijarus PostScript support
e
s 00001/00001/00049
d D 6.3 86/04/28 19:08:32 bloom 4 3
c more comments about syslog, phrasing cleanup
e
s 00004/00004/00046
d D 6.2 86/04/17 19:53:43 bloom 3 2
c clean up diction
e
s 00000/00000/00050
d D 6.1 86/04/17 16:43:52 mckusick 2 1
c 4.3BSD beta release document
e
s 00050/00000/00000
d D 5.1 86/04/17 16:43:41 mckusick 1 0
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
.NH 1
Overview
.PP
The line printer system supports:
.IP \(bu 3
multiple printers,
.IP \(bu 3
multiple spooling queues,
.IP \(bu 3
both local and remote
printers, and
.IP \(bu 3
D 3
printers attached via serial lines which require
E 3
I 3
printers attached via serial lines that require
E 3
line initialization such as the baud rate.
.LP
D 5
Raster output devices
such as a Varian or Versatec, and laser printers such as an Imagen,
are also supported by the line printer system.
E 5
I 5
The line printer system can also support, via converting filters,
printing devices that do not follow the line printer model.
Ready to use filters are provided for Varian/Versatec and for
PostScript printers.
E 5
.PP
The line printer system consists mainly of the
following files and commands:
.DS
.TS
l l.
/etc/printcap	printer configuration and capability data base
/usr/lib/lpd	line printer daemon, does all the real work
/usr/ucb/lpr	program to enter a job in a printer queue
/usr/ucb/lpq	spooling queue examination program
/usr/ucb/lprm	program to delete jobs from a queue
/etc/lpc	program to administer printers and spooling queues
/dev/printer	socket on which lpd listens
.TE
.DE
The file /etc/printcap is a master data base describing line
printers directly attached to a machine and, also, printers
accessible across a network. The manual page entry
.IR printcap (5)
D 3
provides the ultimate definition of
E 3
I 3
provides the authoritative definition of
E 3
the format of this data base, as well as
D 3
indicating default values for important items
E 3
I 3
specifying default values for important items
E 3
such as the directory in which spooling is performed.
D 4
This document highlights the important
E 4
I 4
This document introduces some of the
E 4
D 3
information which may be placed
E 3
I 3
D 5
information that may be placed
E 5
I 5
information that may be placed in
E 5
E 3
.IR printcap .
E 1

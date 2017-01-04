h41536
s 00002/00002/00054
d D 6.2 86/05/12 01:01:15 karels 3 2
c update, correct, rephrase and re-propose
e
s 00001/00002/00055
d D 6.1 86/05/08 12:26:48 mckusick 2 1
c format updates for 4.3BSD
e
s 00057/00000/00000
d D 5.1 86/05/08 00:03:17 mckusick 1 0
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
D 2
.\" %M% %I% %E%
E 2
.ds ss 1
.sh "System facilities
This section discusses the system facilities that
are not considered part of the kernel.
.PP
The system abstractions described are:
.IP "Directory contexts
.br
A directory context is a position in the UNIX file system name
space.  Operations on files and other named objects in a file system are
always specified relative to such a context.
.IP "Files
.br
Files are used to store uninterpreted sequence of bytes on which
random access \fIreads\fP and \fIwrites\fP may occur.
D 3
Pages from files may also be mapped into process address space.
A directory may be read as a file\(dg.
E 3
I 3
Pages from files may also be mapped into process address space.\(dg
A directory may be read as a file.
E 3
.FS
D 2
\(dg Support for mapping files is not included in the 4.2 release.
E 2
I 2
\(dg Support for mapping files is not included in the 4.3 release.
E 2
.FE
.IP "Communications domains
.br
A communications domain represents
an interprocess communications environment, such as the communications
facilities of the UNIX system,
communications in the INTERNET, or the resource sharing protocols
and access rights of a resource sharing system on a local network.
.IP "Sockets
.br
A socket is an endpoint of communication and the focal
point for IPC in a communications domain.  Sockets may be created in pairs,
or given names and used to rendezvous with other sockets
in a communications domain, accepting connections from these
sockets or exchanging messages with them.  These operations model
a labeled or unlabeled communications graph, and can be used in a
wide variety of communications domains.  Sockets can have different
\fItypes\fP\| to provide different semantics of communication,
increasing the flexibility of the model.
.IP "Terminals and other devices
.br
Devices include
terminals, providing input editing and interrupt generation
and output flow control and editing, magnetic tapes,
disks and other peripherals.  They often support the generic
\fIread\fP and \fIwrite\fP operations as well as a number of \fIioctl\fP\|s.
.IP "Processes
.br
Process descriptors provide facilities for control and debugging of
other processes.
.ds ss 2
E 1

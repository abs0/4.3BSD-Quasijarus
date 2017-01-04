h47838
s 00000/00000/00043
d D 1.2 85/08/11 16:04:25 cabrera 2 1
c my first pass
e
s 00043/00000/00000
d D 1.1 85/07/27 19:43:09 mckusick 1 0
c date and time created 85/07/27 19:43:09 by mckusick
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
.ds RH Security Tightening
.NH
Security Tightening
.PP
Since we do not wish to encourage rampant system cracking,
we describe only briefly the changes made to enhance security.
.NH 2
Generic Kernel
.PP
Several loopholes in the process tracing facility have been corrected.
Programs being traced may not be executed;
executing programs may not be traced.
Programs may not provide input to terminals to which they do not
have read permission.
The handling of process groups has been tightened to eliminate
some problems.
When a program attempts to change its process group,
the system checks to see if the process with the pid of the process 
group was started by the same user.
If it exists and was started by a different user the process group
number change is denied.
.NH 2
Security Problems in Utilities
.PP
Setuid utilities no longer use the \fIpopen\fP or \fIsystem\fP library routines.
Access to the kernel's data structures through the kmem device
is now restricted to programs that are set group id ``kmem''.
Thus many programs that used to run with root privileges
no longer need to do so.
Access to disk devices is now controlled by an ``operator'' group id;
this permission allows operators to function without being the super-user.
Only users in group wheel can do ``su root''; this restriction
allows administrators to define a super-user access list.
Numerous holes have been closed in the shell to prevent
users from gaining privileges from set user id shell scripts,
although use of such scripts is still highly discouraged on systems
that are concerned about security.
E 1

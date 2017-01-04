h10266
s 00001/00001/00072
d D 6.3 86/05/12 01:23:25 karels 4 3
c spelling
e
s 00001/00001/00072
d D 6.2 86/05/12 01:01:12 karels 3 2
c update, correct, rephrase and re-propose
e
s 00000/00001/00073
d D 6.1 86/05/08 12:26:45 mckusick 2 1
c format updates for 4.3BSD
e
s 00074/00000/00000
d D 5.1 86/05/08 00:03:11 mckusick 1 0
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
.sh "System operation support
.PP
Unless noted otherwise,
the calls in this section are permitted only to a privileged user.
.NH 3
Bootstrap operations
.PP
The call
.DS
mount(blkdev, dir, ronly);
char *blkdev, *dir; int ronly;
.DE
extends the UNIX name space.  The \fImount\fP call specifies
a block device \fIblkdev\fP containing a UNIX file system
to be made available starting at \fIdir\fP.  If \fIronly\fP is
set then the file system is read-only; writes to the file system
will not be permitted and access times will not be updated
when files are referenced.
\fIDir\fP is normally a name in the root directory.
.PP
The call
.DS
swapon(blkdev, size);
char *blkdev; int size;
.DE
specifies a device to be made available for paging and swapping.
.PP
.NH 3
Shutdown operations
.PP
The call
.DS
unmount(dir);
char *dir;
.DE
unmounts the file system mounted on \fIdir\fP.
This call will succeed only if the file system is
not currently being used.
.PP
The call
.DS
sync();
.DE
schedules input/output to clean all system buffer caches.
D 4
(This call does not require priveleged status.)
E 4
I 4
(This call does not require privileged status.)
E 4
.PP
The call
.DS
reboot(how)
int how;
.DE
causes a machine halt or reboot.  The call may request a reboot
by specifying \fIhow\fP as RB_AUTOBOOT, or that the machine be halted
D 3
with RB_HALT.  These constants are defined in <sys/reboot.h>.
E 3
I 3
with RB_HALT.  These constants are defined in \fI<sys/reboot.h>\fP.
E 3
.NH 3
Accounting
.PP
The system optionally keeps an accounting record in a file
for each process that exits on the system.
The format of this record is beyond the scope of this document.
The accounting may be enabled to a file \fIname\fP by doing
.DS
acct(path);
char *path;
.DE
If \fIpath\fP is null, then accounting is disabled.  Otherwise,
the named file becomes the accounting file.
E 1

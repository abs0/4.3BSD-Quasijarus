h33761
s 00004/00000/00632
d D 6.5 03/11/18 22:56:33 msokolov 6 5
c document default boot device setting on MicroVAXen
e
s 00020/00007/00612
d D 6.4 03/11/18 22:18:15 msokolov 5 4
c update for 4.3BSD-Quasijarus
e
s 00118/00084/00501
d D 6.3 88/07/17 09:34:12 karels 4 3
c merge vax and tahoe versions
e
s 00001/00002/00584
d D 6.2 86/05/14 09:42:37 mckusick 3 2
c /usr/adm/shutdownlog disappears into the past
e
s 00091/00071/00495
d D 6.1 86/05/14 09:37:45 mckusick 2 1
c 4.3BSD release document
e
s 00566/00000/00000
d D 5.1 86/05/14 09:37:36 mckusick 1 0
c broken out of 0.t for 4.2BSD document
e
u
U
t
T
I 1
D 4
.\" Copyright (c) 1980 Regents of the University of California.
E 4
I 4
.\" Copyright (c) 1980,1986,1988 Regents of the University of California.
E 4
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.de IR
\fI\\$1\fP\|\\$2
..
D 2
.ds LH "Installing/Operating 4.2BSD
E 2
I 2
.ds LH "Installing/Operating \*(4B
E 2
.nr H1 6
.nr H2 0
.ds RH "System Operation
.ds CF \*(DY
.bp
.LG
.B
.ce
6. SYSTEM OPERATION
.sp 2
.R
.NL
.PP
D 4
This section describes procedures used to operate a VAX UNIX system.
E 4
I 4
This section describes procedures used to operate a \*(4B UNIX system.
E 4
Procedures described here are used periodically, to reboot the system,
analyze error messages from devices, do disk backups, monitor
system performance, recompile system software and control local changes.
.NH 2
Bootstrap and shutdown procedures
.PP
In a normal reboot, the system checks the disks and comes up multi-user
without intervention at the console.
Such a reboot
can be stopped (after it prints the date) with a ^C (interrupt).
This will leave the system in single-user mode, with only the console
terminal active.
I 2
It is also possible to allow the filesystem checks to complete
D 4
and then to return to single-user mode by signaling \fIfsck\fP
with a QUIT signal (^\).
E 4
I 4
and then to return to single-user mode by signaling \fIfsck\fP(8)
with a QUIT signal (^\\).
.if \n(Th \{\
E 4
E 2
.PP
If booting from the console command level is needed, then the command
.DS
D 4
\fB>>>\fP B
E 4
I 4
\fB#>\fP\|fb
E 4
.DE
will boot from the default device.
D 2
On an 11/780 (11/730) the default device is determined by a ``DEPOSIT''
command stored on the floppy (cassette) in the file ``DEFBOO.CMD'';
E 2
I 2
D 4
On an 8650, 8600, 11/785, 11/780, or 11/730 the default device is
E 4
I 4
.PP
You can boot a system up single user by doing
.DS
\fB#>\fP\fI\|p23 2.\fP\fB#>\fP\fIy.\fP\fB#>\fP\fI\|fb\fP
.DE
.PP
Other possibilities are:
.DS
\fB#>\fP\fI\|p23 3.\fP\fB#>\fP\fIy.\fP\fB#>\fP\fI\|fb\fP
.DE
to do a full bootstrap, or
.DS
\fB#>\fP\fI\|p23 3.\fP\fB#>\fP\fIy.\fP\fB#>\fP\fI\|fr /boot\fP
.DE
to run the bootstrap without performing self-tests and
reloading microcode; it can be used after a full bootstrap has been done
once.
.\}
.if \n(Vx \{\
.PP
If booting from the console command level is needed, then the command
.DS
\fB>>>\fP\fIB\fP
.DE
will boot from the default device.
D 5
On an 8600, 8200, 11/780, or 11/730 the default device is
E 5
I 5
On an 8600, 11/780, or 11/730 the default device is
E 5
E 4
determined by a ``DEPOSIT''
command stored on the console boot device in the file ``DEFBOO.CMD''
D 4
(``DEFBOO.COM'' on an 8650 or 8600);
E 4
I 4
(``DEFBOO.COM'' on an 8600);
E 4
E 2
on an 11/750 the default device is determined by the setting of a switch
D 5
on the front panel.
E 5
I 5
on the front panel;
on an 8200 the default device is stored in EEPROM.
On 11/750 and 8200 the default boot device may be set to the console storage
device (TU58 on 750 and RX50 on 8200).  In this case there must be a console
medium with BOOT58 in the console storage device, and the boot procedure and
system disk are determined by the ``DEFBOO.CMD'' boot script stored on the
console medium.
I 6
On MicroVAX 3/3+ the default boot device is stored in NVRAM and set with
``SET BOOT'' console command.
MicroVAX II does not allow the boot device to be selected, it always boots from
the first bootable disk in the system.
E 6
E 5
.PP
D 2
You can boot a system up single user on a 780 or 730 by doing
E 2
I 2
You can boot a system up single user
D 4
on an 8650, 8600, 785, 780, or 730 by doing
E 4
I 4
on an 8600, 780, or 730 by doing
E 4
E 2
.DS
D 4
\fB>>>\fP B \fIXX\fP\|S
E 4
I 4
\fB>>>\fP\fIB xxS\fP
E 4
.DE
D 4
where \fIXX\fP is one of HP, HK, UP, RA, or RB for a 730.
E 4
I 4
where \fIxx\fP is one of HP, HK, UP, RA, or RB.
E 4
D 5
The corresponding command on an 11/750 is
E 5
I 5
The corresponding command on an 11/750 or 8200 booting
without a console medium, or for a MicroVAX is
E 5
.DS
D 2
\fB>>>\fP B/1
E 2
I 2
D 4
\fB>>>\fP B/2
E 4
I 4
\fB>>>\fP\fIB/2\fP
E 4
E 2
.DE
I 4
D 5
On an 8200, use
E 5
I 5
On an 8200 using the console floppy, use
E 5
.DS
\fB>>>\fP\fIB/R5:800\fP
(node and memory test values)
D 5
\fBBOOT58>\fP \fI@\fPXX\fISBOO.CMD\fP
E 5
I 5
\fBBOOT58>\fP \fI@SNGBOO.CMD\fP
E 5
.DE
E 4
.PP
For second vendor storage modules on the
UNIBUS or MASSBUS of an 11/750 you will need to
have a boot prom.  Most vendors will sell you
such proms for their controllers; contact your vendor
if you don't have one.
I 5
Alternatively, you could set up a BOOT58-based boot path.
Contact Quasijarus Consortium for assistance.
E 5
.PP
Other possibilities are:
.DS
D 4
\fB>>>\fP B ANY
E 4
I 4
\fB>>>\fP\fIB ANY\fP
E 4
.DE
D 4
or, on a 750
E 4
I 4
D 5
or, on an 8200,
E 5
I 5
or, on an 8200 using the console floppy,
E 5
E 4
.DS
D 4
\fB>>>\fP B/3
E 4
I 4
\fB>>>\fP\fIB/R5:800\fP
\fBBOOT58>\fP\fI@ANYBOO.CMD\fP
E 4
.DE
I 4
D 5
or, on an 11/750
E 5
I 5
or, on an 11/750 or a MicroVAX
E 5
.DS
\fB>>>\fP\fIB/3\fP
.DE
.\}
E 4
These commands boot and ask for the name of the system to be booted.
They can be used after building a new test system to give the
D 4
boot program the name of the test version of the system.
E 4
I 4
boot program the name of the test version of the system.*
.FS
* Additional bootflags are used when a system is configured with
the kernel debugger; consult \fIkdb\fP(4) for details.
.FE
E 4
.PP
To bring the system up to a multi-user configuration from the single-user
D 2
status after, e.g., a ``B HPS'' on an 11/780, ``B RBS'' on a 730,
or a ``B/1'' on an
E 2
I 2
D 4
status after, e.g., a ``B HPS'' on an 8650, 8600, 11/785 or 11/780, ``B RBS''
on a 11/730, or a ``B/2'' on an
E 2
11/750 all you have to do is hit ^D on the console.  The system
E 4
I 4
status,
all you have to do is hit ^D on the console.  The system
E 4
will then execute /etc/rc,
a multi-user restart script (and /etc/rc.local),
and come up on the terminals listed as
active in the file /etc/ttys.
See
\fIinit\fP\|(8)
and
D 4
\fIttys\fP\|(5).
E 4
I 4
\fIttys\fP\|(5) for more details.
E 4
Note, however, that this does not cause a file system check to be performed.
Unless the system was taken down cleanly, you should run
``fsck \-p'' or force a reboot with
\fIreboot\fP\|(8)
to have the disks checked.
.PP
To take the system down to a single user state you can use
.DS
D 4
\fB#\fP kill 1
E 4
I 4
\fB#\fP \fIkill 1\fP
E 4
.DE
or use the
\fIshutdown\fP\|(8)
D 4
command (which is much more polite, if there are other users logged in.)
when you are up multi-user.
E 4
I 4
command (which is much more polite, if there are other users logged in)
when you are running multi-user.
E 4
Either command will kill all processes and give you a shell on the console,
as if you had just booted.  File systems remain mounted after the
system is taken single-user.  If you wish to come up multi-user again, you
should do this by:
.DS
D 4
\fB#\fP cd /
\fB#\fP /etc/umount -a
\fB#\fP ^D
E 4
I 4
\fB#\fP \fIcd /\fP
\fB#\fP \fI/etc/umount -a\fP
\fB#\fP \fI^D\fP
E 4
.DE
.PP
Each system shutdown, crash, processor halt and reboot
D 3
is recorded in the file /usr/adm/shutdownlog
E 3
I 3
is recorded in the system log
E 3
D 4
with the cause.
E 4
I 4
with its cause.
E 4
.NH 2
Device errors and diagnostics
.PP
D 2
When errors occur on peripherals or in the system, the system
prints a warning diagnostic on the console.  These messages are collected
regularly and written into a system error log file
/usr/adm/messages.
E 2
I 2
When serious errors occur on peripherals or in the system, the system
prints a warning diagnostic on the console.
These messages are collected
by the system error logging process
.IR syslogd (8)
and written into a system error log file
\fI/usr/adm/messages\fP.
Less serious errors are sent directly to \fIsyslogd\fP,
which may log them on the console.
The error priorities that are logged and the locations to which they are logged
are controlled by \fI/etc/syslog.conf\fP.  See
.IR syslogd (8)
D 4
for details.
E 4
I 4
for further details.
E 4
E 2
.PP
Error messages printed by the devices in the system are described with the
drivers for the devices in section 4 of the programmer's manual.
D 2
If errors occur indicating hardware problems, you should contact
E 2
I 2
If errors occur suggesting hardware problems, you should contact
E 2
your hardware support group or field service.  It is a good idea to
examine the error log file regularly
D 2
(e.g. with ``tail \-r /usr/adm/messages'').
E 2
I 2
D 4
(e.g. with ``tail \-r \fI/usr/adm/messages\fP'').
E 4
I 4
(e.g. with the command \fItail \-r /usr/adm/messages\fP).
E 4
E 2
.NH 2
File system checks, backups and disaster recovery
.PP
Periodically (say every week or so in the absence of any problems)
and always (usually automatically) after a crash,
all the file systems should be checked for consistency
by
\fIfsck\fP\|(1).
The procedures of
\fIreboot\fP\|(8)
should be used to get the system to a state where a file system
check can be performed manually or automatically.
.PP
Dumping of the file systems should be done regularly,
since once the system is going it is easy to
become complacent.
Complete and incremental dumps are easily done with
\fIdump\fP\|(8).
You should arrange to do a towers-of-hanoi dump sequence; we tune
ours so that almost all files are dumped on two tapes and kept for at
least a week in most every case.  We take full dumps every month (and keep
these indefinitely).
Operators can execute ``dump w'' at login that will tell them what needs
to be dumped
(based on the /etc/fstab
information).
Be sure to create a group
.B operator
in the file /etc/group
so that dump can notify logged-in operators when it needs help.
.PP
More precisely, we have three sets of dump tapes: 10 daily tapes,
5 weekly sets of 2 tapes, and fresh sets of three tapes monthly.
We do daily dumps circularly on the daily tapes with sequence
`3 2 5 4 7 6 9 8 9 9 9 ...'.
Each weekly is a level 1 and the daily dump sequence level
restarts after each weekly dump.
Full dumps are level 0 and the daily sequence restarts after each full dump
also.
.PP
Thus a typical dump sequence would be:
.br
.ne 6
I 2
.KS
E 2
.TS
center;
c c c c c
n n n l l.
tape name	level number	date	opr	size
_
FULL	0	Nov 24, 1979	jkf	137K
D1	3	Nov 28, 1979	jkf	29K
D2	2	Nov 29, 1979	rrh	34K
D3	5	Nov 30, 1979	rrh	19K
D4	4	Dec 1, 1979	rrh	22K
W1	1	Dec 2, 1979	etc	40K
D5	3	Dec 4, 1979	rrh	15K
D6	2	Dec 5, 1979	jkf	25K
D7	5	Dec 6, 1979	jkf	15K
D8	4	Dec 7, 1979	rrh	19K
W2	1	Dec 9, 1979	etc	118K
D9	3	Dec 11, 1979	rrh	15K
D10	2	Dec 12, 1979	rrh	26K
D1	5	Dec 15, 1979	rrh	14K
W3	1	Dec 17, 1979	etc	71K
D2	3	Dec 18, 1979	etc	13K
FULL	0	Dec 22, 1979	etc	135K
.TE
D 2
We do weekly's often enough that daily's always fit on one tape and
never get to the sequence of 9's in the daily level numbers.
E 2
I 2
.KE
We do weekly dumps often enough that daily dumps always fit on one tape.
E 2
.PP
Dumping of files by name is best done by
\fItar\fP\|(1)
but the amount of data that can be moved in this way is limited
to a single tape.
Finally if there are enough drives entire
disks can be copied with
\fIdd\fP\|(1)
using the raw special files and an appropriate
blocking factor; the number of sectors per track is usually
D 2
a good value to use, consult /etc/disktab.
E 2
I 2
a good value to use, consult \fI/etc/disktab\fP.
E 2
.PP
It is desirable that full dumps of the root file system be
made regularly.
This is especially true when only one disk is available.
Then, if the
root file system is damaged by a hardware or software failure, you
can rebuild a workable disk doing a restore in the
same way that the initial root file system was created.
.PP
Exhaustion of user-file space is certain to occur
now and then; disk quotas may be imposed, or if you
D 4
prefer a less facist approach, try using the programs
E 4
I 4
prefer a less fascist approach, try using the programs
E 4
\fIdu\fP\|(1),
D 4
\fIdf\fP\|(1),
E 4
I 4
\fIdf\fP\|(1), and
E 4
\fIquot\fP\|(8),
combined with threatening
messages of the day, and personal letters.
.NH 2
D 2
Moving filesystem data
E 2
I 2
Moving file system data
E 2
.PP
D 4
If you have the equipment,
E 4
I 4
If you have the resources,
E 4
the best way to move a file system
D 4
is to dump it to magtape using
\fIdump\fP\|(8),
use
\fInewfs\fP\|(8)
to create the new file system,
and restore the tape, using \fIrestore\fP\|(8).
If for some reason you don't want to use magtape,
dump accepts an argument telling where to put the dump;
you might use another disk.
E 4
I 4
is to dump it to a spare disk partition, or magtape, using
\fIdump\fP\|(8), use \fInewfs\fP\|(8) to create the new file system,
and restore the file system using \fIrestore\fP\|(8).
E 4
D 2
The restore program uses an ``in-place'' algorithm which
E 2
I 2
Filesystems may also be moved by piping the output of \fIdump\fP
to \fIrestore\fP.
The \fIrestore\fP program uses an ``in-place'' algorithm that
E 2
allows file system dumps to be restored without concern for the
original size of the file system.  Further, portions of a
D 2
file system may be selectively restored in a manner similar
E 2
I 2
file system may be selectively restored using a method similar
E 2
to the tape archive program.
.PP
If you have to merge a file system into another, existing one,
the best bet is to
use \fItar\fP\|(1).
If you must shrink a file system, the best bet is to dump
the original and restore it onto the new file system.
If you
are playing with the root file system and only have one drive,
the procedure is more complicated.
I 2
If the only drive is a Winchester disk, this procedure may not be used
without overwriting the existing root or another partition.
E 2
What you do is the following:
.IP 1.
D 4
GET A SECOND PACK!!!!
E 4
I 4
GET A SECOND PACK, OR USE ANOTHER DISK DRIVE!!!!
E 4
.IP 2.
Dump the root file system to tape using
\fIdump\fP\|(8).
.IP 3.
D 4
Bring the system down and mount the new pack.
E 4
I 4
Bring the system down.
E 4
.IP 4.
I 4
Mount the new pack in the correct disk drive, if
using removable media.
.IP 5.
E 4
Load the distribution tape and install the new
root file system as you did when first installing the system.
D 4
.IP 5.
E 4
Boot normally
using the newly created disk file system.
.PP
Note that if you change the disk partition tables or add new disk
drivers they should also be added to the standalone system in
D 2
/sys/stand and the default disk partition tables in /etc/disktab
E 2
I 2
D 4
\fI/sys/stand\fP and the default disk partition tables in \fI/etc/disktab\fP
E 4
I 4
\fI/sys/\*(mCstand\fP,
and the default disk partition tables in \fI/etc/disktab\fP
E 4
E 2
should be modified.
.NH 2
Monitoring System Performance
.PP
The
D 2
.I vmstat
E 2
I 2
.I systat
E 2
program provided with the system is designed to be an aid to monitoring
D 2
systemwide activity.  Together with the
\fIps\fP\|(1)
command (as in ``ps av''), it can be used to investigate systemwide
virtual memory activity.
By running
.I vmstat
E 2
I 2
systemwide activity.  The default ``pigs'' mode shows a dynamic ``ps''.
By running in the ``vmstat'' mode
E 2
when the system is active you can judge the system activity in several
dimensions: job distribution, virtual memory load, paging and swapping
D 2
activity, disk and cpu utilization.
E 2
I 2
activity, device interrupts, and disk and cpu utilization.
E 2
Ideally, there should be few blocked (b) jobs,
there should be little paging or swapping activity, there should
be available bandwidth on the disk devices (most single arms peak
D 2
out at 30-35 tps in practice), and the user cpu utilization (us) should
be high (above 60%).
E 2
I 2
out at 20-30 tps in practice), and the user cpu utilization (us) should
be high (above 50%).
E 2
.PP
If the system is busy, then the count of active jobs may be large,
and several of these jobs may often be blocked (b).  If the virtual
memory is active, then the paging demon will be running (sr will
be non-zero).  It is healthy for the paging demon to free pages when
the virtual memory gets active; it is triggered by the amount of free
memory dropping below a threshold and increases its pace as free memory
goes to zero.
.PP
D 2
If you run
.I vmstat
when the system is busy (a ``vmstat 1'' gives all the
numbers computed by the system), you can find
E 2
I 2
If you run in the ``vmstat'' mode
when the system is busy, you can find
E 2
imbalances by noting abnormal job distributions.  If many
processes are blocked (b), then the disk subsystem
D 2
is overloaded or imbalanced.  If you have a several non-dma
E 2
I 2
is overloaded or imbalanced.  If you have several non-dma
E 2
devices or open teletype lines that are ``ringing'', or user programs
that are doing high-speed non-buffered input/output, then the system
time may go high (60-70% or higher).
It is often possible to pin down the cause of high system time by
looking to see if there is excessive context switching (cs), interrupt
D 2
activity (in) or system call activity (sy).  Cumulatively on one of
our large machines we average about 60 context switches and interrupts
per second and about 90 system calls per second.
E 2
I 2
activity (in) and per-device interrupt counts,
or system call activity (sy).  Cumulatively on one of
our large machines we average about 60-100 context switches and interrupts
per second and about 70-120 system calls per second.
E 2
.PP
If the system is heavily loaded, or if you have little memory
D 2
for your load (1M is little in most any case), then the system
E 2
I 2
for your load (2M is little in most any case), then the system
E 2
may be forced to swap.  This is likely to be accompanied by a noticeable
reduction in system performance and pregnant pauses when interactive
jobs such as editors swap out.
If you expect to be in a memory-poor environment
for an extended period you might consider administratively
limiting system load.
.NH 2
Recompiling and reinstalling system software
.PP
It is easy to regenerate the system, and it is a good
idea to try rebuilding pieces of the system to build confidence
in the procedures.
The system consists of two major parts:
the kernel itself (/sys) and the user programs
(/usr/src and subdirectories).
The major part of this is /usr/src.
.PP
The three major libraries are the C library in /usr/src/lib/libc
and the \s-2FORTRAN\s0 libraries /usr/src/usr.lib/libI77 and
/usr/src/usr.lib/libF77.  In each
case the library is remade by changing into the corresponding directory
and doing
.DS
D 4
\fB#\fP make
E 4
I 4
\fB#\fP \fImake\fP
E 4
.DE
and then installed by
.DS
D 4
\fB#\fP make install
E 4
I 4
\fB#\fP \fImake install\fP
E 4
.DE
Similar to the system,
.DS
D 4
\fB#\fP make clean
E 4
I 4
\fB#\fP \fImake clean\fP
E 4
.DE
cleans up.
.PP
The source for all other libraries is kept in subdirectories of
/usr/src/usr.lib; each has a makefile and can be recompiled by the above
recipe.
.PP
If you look at /usr/src/Makefile, you will see that
you can recompile the entire system source with one command.
To recompile a specific program, find
out where the source resides with the \fIwhereis\fP\|(1)
command, then change to that directory and remake it
D 4
with the makefile present in the directory.
E 4
I 4
with the Makefile present in the directory.
E 4
For instance, to recompile ``date'', 
all one has to do is
.DS
D 4
\fB#\fP whereis date
\fBdate: /usr/src/bin/date.c /bin/date /usr/man/man1/date.1\fP
\fB#\fP cd /usr/src/bin
\fB#\fP make date
E 4
I 4
\fB#\fP \fIwhereis date\fP
\fBdate: /usr/src/bin/date.c /bin/date\fP
\fB#\fP \fIcd /usr/src/bin\fP
\fB#\fP \fImake date\fP
E 4
.DE
this will create an unstripped version of the binary of ``date''
in the current directory.  To install the binary image, use the
install command as in
.DS
D 4
\fB#\fP install \-s date /bin/date
E 4
I 4
\fB#\fP \fIinstall \-s date -o bin -g bin -m 755 /bin/date\fP
E 4
.DE
The \-s option will insure the installed version of date has
its symbol table stripped.  The install command should be used
instead of mv or cp as it understands how to install programs
even when the program is currently in use.
.PP
If you wish to recompile and install all programs in a particular
target area you can override the default target by doing:
.DS
D 4
\fB#\fP make
\fB#\fP make DESTDIR=\fIpathname\fP install
E 4
I 4
\fB#\fP \fImake\fP
\fB#\fP \fImake DESTDIR=\fPpathname \fIinstall\fP
E 4
.DE
.PP
To regenerate all the system source you can do
.DS
D 4
\fB#\fP cd /usr/src
\fB#\fP make
E 4
I 4
\fB#\fP \fIcd /usr/src\fP
\fB#\fP \fImake clean; make depend; make\fP
E 4
.DE
.PP
If you modify the C library, say to change a system call,
and want to rebuild and install everything from scratch you
have to be a little careful.
D 2
You must insure the libraries are installed before the
E 2
I 2
You must insure that the libraries are installed before the
E 2
remainder of the source, otherwise the loaded images will not
contain the new routine from the library.  The following
D 2
steps are recommended.
E 2
I 2
sequence will accomplish this.
E 2
.DS
D 4
\fB#\fP cd /usr/src
D 2
\fB#\fP cd lib; make install
\fB#\fP cd ..
\fB#\fP make usr.lib
\fB#\fP cd usr.lib; make install
\fB#\fP cd ..
\fB#\fP make bin etc usr.bin ucb games local
\fB#\fP for i in bin etc usr.bin ucb games local; do (cd $i; make install); done
E 2
I 2
\fB#\fP make clean
\fB#\fP make build
\fB#\fP make installsrc
E 4
I 4
\fB#\fP \fIcd /usr/src\fP
\fB#\fP \fImake clean\fP
\fB#\fP \fImake depend\fP
\fB#\fP \fImake build\fP
\fB#\fP \fImake installsrc\fP
E 4
E 2
.DE
D 2
This will take about 12 hours on a reasonably configured 11/750.
E 2
I 2
D 4
The first \fImake\fP removes any existing binaries in the source trees
to insure that everything is reloaded.
The next \fImake\fP compiles and installs the libraries and compilers,
then compiles the remainder of the sources.
The final line installs all of the commands not installed in the first phase.
This will take about 18 hours on a reasonably configured 11/750.
E 4
I 4
The \fImake clean\fP removes any existing binary or object files in the source
trees to insure that everything will be recompiled and reloaded.  The \fImake
depend\fP recreates all of the dependencies.  See \fImkdep\fP(1) for
further details. The \fImake build\fP compiles and installs the libraries
and compilers, then recompiles the libraries and compilers and the remainder
of the sources.  The \fImake installsrc\fP installs all of the commands not
installed as part of the \fImake build\fP.
I 5
.if \n(Vx \{\
This will take approximately 4
hours on a KA655.
.\}
E 5
.if \n(Th \{\
This will take approximately 10
hours on a reasonably configured Tahoe.
.\}
E 4
E 2
.NH 2
Making local modifications
.PP
D 4
To keep track of changes to system source we migrate changed
versions of commands in /usr/src/bin, /usr/src/usr.bin, and /usr/src/ucb
in through the directory /usr/src/new
and out of the original directory into /usr/src/old for
a time before removing them.
I 2
(/usr/new is also used by default for the programs that constitute
the contributed software portion of the distribution.)
E 4
E 2
Locally written commands that aren't distributed are kept in /usr/src/local
and their binaries are kept in /usr/local.  This allows /usr/bin, /usr/ucb,
and /bin to correspond to the distribution tape (and to the manuals that
D 4
people can buy).  People wishing to use /usr/local commands are made
aware that they aren't in the base manual.  As manual updates incorporate
these commands they are moved to /usr/ucb.
.PP
D 2
A directory /usr/junk to throw garbage into, as well as binary directories
/usr/old and /usr/new are useful.  The man command supports manual
directories such as /usr/man/manj for junk and /usr/man/manl for local
E 2
I 2
A directory, /usr/junk, to throw garbage into, as well as binary directories,
/usr/old and /usr/new, are useful.  The man command supports manual
directories such as /usr/man/mano for old and /usr/man/manl for local
E 2
to make this or something similar practical.
E 4
I 4
people can buy).  People using local commands should be made aware that
they aren't in the base manual.  Manual pages for local commands should be
installed in /usr/src/local/man and installed in /usr/local/man/cat[1-8].
The \fIman\fP(1) command automatically finds manual pages placed in
/usr/local/man/cat[1-8] to facilitate this practice.
E 4
.NH 2
Accounting
.PP
UNIX optionally records two kinds of accounting information:
connect time accounting and process resource accounting.  The connect
D 2
time accounting information is stored in the file /usr/adm/wtmp, which
E 2
I 2
time accounting information is stored in the file \fI/usr/adm/wtmp\fP, which
E 2
is summarized by the program
.IR ac (8).
D 2
The process time accounting information is stored in the file /usr/adm/acct,
and analyzed and summarized by the program
E 2
I 2
The process time accounting information is stored in the file
\fI/usr/adm/acct\fP after it is enabled by
.IR accton (8),
and is analyzed and summarized by the program
E 2
.IR sa (8).
.PP
D 2
If you need to implement recharge for computing time, you can implement
E 2
I 2
If you need to recharge for computing time, you can develop
E 2
procedures based on the information provided by these commands.
A convenient way to do this is to give commands to the clock daemon
D 2
/etc/cron
E 2
I 2
.I /etc/cron
E 2
to be executed every day at a specified time.  This is done by adding
D 2
lines to /usr/adm/crontab; see
E 2
I 2
lines to \fI/usr/adm/crontab\fP; see
E 2
.IR cron (8)
for details.
.NH 2
Resource control
.PP
D 2
Resource control in the current version of UNIX is fairly
elaborate compared to most UNIX systems.  The disc quota
E 2
I 2
Resource control in the current version of UNIX is more
elaborate than in most UNIX systems.  The disk quota
E 2
facilities developed at the University of Melbourne have
been incorporated in the system and allow control over the
D 2
number of files and amount of disc space each user may use
E 2
I 2
number of files and amount of disk space each user may use
E 2
on each file system.  In addition, the resources consumed
by any single process can be limited by the mechanisms of
\fIsetrlimit\fP\|(2).  As distributed, the latter mechanism
is voluntary, though sites may choose to modify the login
D 2
mechanism to impose limits not covered with disc quotas.
E 2
I 2
mechanism to impose limits not covered with disk quotas.
E 2
.PP
D 2
To utilize the disc quota facilities, the system must be
E 2
I 2
To use the disk quota facilities, the system must be
E 2
configured with ``options QUOTA''.  File systems may then
be placed under the quota mechanism by creating a null file
.I quotas
at the root of the file system, running
.IR quotacheck (8),
D 2
and modifying /etc/fstab to indicate the file system is read-write
with disc quotas (a ``rq'' type field).  The
E 2
I 2
and modifying \fI/etc/fstab\fP to show that the file system is read-write
with disk quotas (an ``rq'' type field).  The
E 2
.IR quotaon (8)
program may then be run to enable quotas.
.PP
Individual quotas are applied by using the quota editor
.IR edquota (8).
Users may view their quotas (but not those of other users) with the
.IR quota (1)
program.  The 
.IR repquota (8)
program may be used to summarize the quotas and current
space usage on a particular file system or file systems.
.PP
Quotas are enforced with 
.I soft
and
.I hard
limits.  When a user first reaches a soft limit on a resource, a
message is generated on his/her terminal.  If the user fails to
lower the resource usage below the soft limit the next time
they log in to the system the
.I login
program will generate a warning about excessive usage.  Should
three login sessions go by with the soft limit breached the
system then treats the soft limit as a
.I hard
limit and disallows any allocations until enough space is
reclaimed to bring the user back below the soft limit.  Hard
limits are enforced strictly resulting in errors when a user
tries to create or write a file.  Each time a hard limit is
exceeded the system will generate a message on the user's 
terminal.
.PP
Consult the auxiliary document, ``Disc Quotas in a UNIX Environment''
and the appropriate manual entries for more information.
.NH 2
Network troubleshooting
.PP
If you have anything more than a trivial network configuration,
from time to time you are bound to run into problems.  Before
blaming the software, first check your network connections.  On
networks such as the Ethernet a
loose cable tap or misplaced power cable can result in severely
deteriorated service.  The \fInetstat\fP\|(1) program may be of
aid in tracking down hardware malfunctions.  In particular, look
D 2
at the \-i and \-s options in the manual page.
E 2
I 2
at the \fB\-i\fP and \fB\-s\fP options in the manual page.
E 2
.PP
Should you believe a communication protocol problem exists,
consult the protocol specifications and attempt to isolate the
problem in a packet trace.  The SO_DEBUG option may be supplied
before establishing a connection on a socket, in which case the
system will trace all traffic and internal actions (such as timers
expiring) in a circular trace buffer.  This buffer may then
D 2
be printed out with the \fItrpt\fP\|(8C) program.  Most all the
servers distributed with the system accept a \-d option forcing
E 2
I 2
be printed out with the \fItrpt\fP\|(8C) program.  Most of the
servers distributed with the system accept a \fB\-d\fP option forcing
E 2
all sockets to be created with debugging turned on.  Consult the
appropriate manual pages for more information.
.NH 2
D 2
Files which need periodic attention
E 2
I 2
Files that need periodic attention
E 2
.PP
We conclude the discussion of system operations by listing
D 4
the files that require periodic attention or are system specific
E 4
I 4
the files that require periodic attention or are system specific:
E 4
.de BP
.IP \fB\\$1\fP
.br
..
.TS
center;
lb a.
/etc/fstab	how disk partitions are used
D 4
/etc/disktab	disk partition sizes
E 4
I 4
/etc/disktab	default disk partition sizes/labels
E 4
/etc/printcap	printer data base
/etc/gettytab	terminal type definitions
/etc/remote	names and phone numbers of remote machines for \fItip\fP(1)
/etc/group	group memberships
/etc/motd	message of the day
/etc/passwd	password file; each account has a line
/etc/rc.local	local system restart script; runs reboot; starts daemons
I 2
/etc/inetd.conf	local internet servers
E 2
/etc/hosts	host name data base
/etc/networks	network name data base
/etc/services	network services data base
/etc/hosts.equiv	hosts under same administrative control
D 2
/etc/securetty	restricted list of ttys where root can log in
E 2
I 2
/etc/syslog.conf	error log configuration for \fIsyslogd\fP\|(8)
E 2
/etc/ttys	enables/disables ports
D 2
/etc/ttytype	terminal types connected to ports
E 2
/usr/lib/crontab	commands that are run periodically
/usr/lib/aliases	mail forwarding and distribution groups
/usr/adm/acct	raw process account data
/usr/adm/messages	system error log
D 3
/usr/adm/shutdownlog	log of system reboots
E 3
/usr/adm/wtmp	login session accounting
.TE
E 1

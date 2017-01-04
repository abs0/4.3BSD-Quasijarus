h24482
s 00001/00001/00568
d D 1.6 99/09/23 12:58:32 msokolov 6 5
c restore r, not restore x
e
s 00037/00043/00532
d D 1.5 88/07/29 14:49:18 bostic 5 4
c redo format of the tape so it will fit on 1600 bpi
e
s 00000/00002/00575
d D 1.4 88/07/19 16:15:25 bostic 4 3
c no need to set up /sys, it's on the distribution
e
s 00001/00001/00576
d D 1.3 88/07/17 09:36:46 karels 3 2
c add keywords
e
s 00236/00226/00341
d D 1.2 88/07/17 09:31:51 karels 2 1
c karels, bostic editing
e
s 00567/00000/00000
d D 1.1 88/06/13 14:20:00 bostic 1 0
c date and time created 88/06/13 14:20:00 by bostic
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
.\"	@(#)2.t	6.1 (Berkeley) 5/14/86
E 3
I 3
.\"	%W% (Berkeley) %G%
E 3
.\"
.ds lq ``
.ds rq ''
.ds LH "Installing/Operating \*(4B
.ds RH Bootstrapping
.ds CF \*(DY
.bp
.nr H1 2
.nr H2 0
.bp
.LG
.B
.ce
2. BOOTSTRAP PROCEDURE
.sp 2
.R
.NL
.PP
This section explains the bootstrap procedure that can be used
to get the kernel supplied with this distribution running on your machine.
If you are not currently running 4.2BSD you will
have to do a full bootstrap.
D 2
Chapter 3 describes how to upgrade an existing 4.2BSD system.
E 2
I 2
Chapter 3 describes how to upgrade a 4.2BSD system.
E 2
An understanding of the operations used in a full bootstrap
is very helpful in performing an upgrade as well.
In either case, it is highly desirable to read and understand
the remainder of this document before proceeding.
.NH 2
Booting from tape
.PP
The tape bootstrap procedure used to create a
working system involves the following major
steps:
.IP 1)
D 2
Format a disk pack with the \fIvdformat\fP program.
E 2
I 2
Format a disk pack with the \fIvdformat\fP program, if necessary.
E 2
.IP 2)
Copy a ``mini root'' file system from the
tape onto the swap area of the disk.
.IP 3)
D 2
Boot the UNIX system on the ``mini root''.
E 2
I 2
Boot the UNIX system on the ``mini root.''
E 2
.IP 4)
Restore the full root file system using \fIrestore\fP\|(8).
.IP 5)
Reboot the completed root file system.
.IP 6)
Label the disks with the \fIdisklabel\fP\|(8) program.
.IP 7)
Build and restore the /usr file system from tape
with \fItar\fP\|(1).
.IP 8)
Extract the system and utility files and contributed software
as desired.
.PP
D 2
The following sections describe the above steps in detail.
In these sections references to disk drives are of the
form \fIxx\fP\|(\fIn\fP,\fIm\fP)
and references to files on tape drives are of the form
\fIyy\fP\|(\fIn\fP,\fIm\fP) where \fIxx\fP and \fIyy\fP
are names described in section 1.4 and \fIn\fP
and \fIm\fP are the unit and offset numbers described in
section 1.4.  Commands
you are expected to type are shown in Roman, while that
information printed by the system is shown emboldened.
E 2
I 2
The following sections describe the above steps in detail.  In these
sections references to disk drives are of the form \fIxx\fP\|(\fId\fP,
\fIp\fP) and references to files on tape drives are of the form
\fIxx\fP\|(\fIc\fP,\fId\fP, \fIp\fP)
where \fIxx\fP are device types described in section 1.4,
\fIc\fP is the (optional) controller unit number,
\fId\fP is the drive unit number, and \fIp\fP is a disk partition
or tape file offset numbers as described in section 1.4.
For the sake of simplicity, all disk examples will use the disk type
``dk'' and all tape examples will similarly use ``cy'';
the examples assume drive 0, partition 0.
Commands you
are expected to type are shown in italics, while that information
printed by the system is shown emboldened.
E 2
.PP
If you encounter problems while following the instructions in
this part of the document, refer to Appendix B for help in
troubleshooting.
.NH 3
Step 1: formatting the disk
.PP
All disks used with \*(4B should be formatted to insure
the proper handling of physically corrupted disk sectors.
The
.I vdformat
program included in the distribution, or a vendor supplied
formatting program, may be used to format disks if this has not
D 2
already been done.
The
.I vdformat
program is capable of formatting
any of the disk drives listed in \(sc1.1.
E 2
I 2
already been done.  The \fIvdformat\fP program is capable of formatting
any of the disk drives listed in section 1.1, when booting from tape;
when booting from disk, it supports any drive listed in
\fI/etc/disktab\fP.
E 2
.PP
To load the \fIvdformat\fP program, perform the following steps.
.DS
.TS
lw(2i) l.
(machine powered up)
\fBMIB POC\fP
\fBType '#' to cancel boot\fP
D 2
#	(cancel automatic reboot)
\fBCP [a10.h0]#>\fP\|h	(halt the cpu)
\fB#>\|\fPy	(initialize the machine)
\fB#>\|\fPfd cyp(0,0)	(make cypher default device)
\fB#>\|\fPp23 3. \fB00000000\fP	(set boot flags)
\fB#>\|\fPfb	(boot machine)
E 2
I 2
\fI#\fP	(cancel automatic reboot)
\fBCP [a10.h0]#>\fP\fI\|h\fP	(halt the cpu)
\fB#>\|\fP\fIy.\fP	(initialize the machine)
\fB#>\|\fP\fIfd cyp(0,0)\fP	(make cypher default device)
\fB#>\|\fP\fIp23 3.\fP \fB00000000\fP	(set boot flags)
\fB#>\|\fP\fIfb\fP	(boot machine)
E 2
\fBcyp(0,0)/etc/fstab\fP
\fBCP cold boot\fP
\fB4 way interleave set\fP
\fBCPU memory test\fP
\fBECC CPU memory test\fP
\fBcyp(0,0)/.\fP
\fBCPU POC1\fP
\fBcyp(0,0)/poc1\fP
\fBCPU POC2\fP
\fBcyp(0,0)/poc2\fP
\fBFPP POC\fR	(only if floating point processor present)
\fBcyp(0,0)/fppoc\fP
\fBFPP WCS\fR	(only if floating point processor present)
\fBcyp(0,0)/fppwcs\fP
\fBBOOT SYSTEM cyp(0,0)/boot\fP

\fBBoot\fP
D 2
\fB:\fRcy(0,0)stand/vdformat	(load and run from first tape file)
E 2
I 2
\fB:\fIcy(0,0)stand/vdformat\fR	(load and run from first tape file)
\fB52224+17408+1177716 start 0x1000\fP
\fBVDFORMAT     Berkeley Version 1.6\fP
E 2
.TE
D 2
.DE
.PP
The \fIvdformat\fP program should now be running and awaiting your input:
.DS
\fB:\fPcy(0,0)stand/vdformat
\fB50176+14336+776780 start 0x1000\fP
\fBVDFORMAT	Version 3.0\fP
E 2

\fBcontroller 0: smd\fP
\fBcontroller 1: smd-e\fP

\fBType `Help' for help, `Start' to execute operations.\fP

\fBvdformat>\fP
.DE
I 2
.PP
The \fIvdformat\fP program should now be running and awaiting your input.
E 2
If you made a mistake loading the program off the tape
D 2
you should get either the ``:'' prompt again from the
boot program or the ``#>'' prompt from the console
E 2
I 2
you should get either the ``:'' prompt again (from the
boot program) or the ``#>'' prompt from the console
E 2
processor.  In either case you can retype the appropriate
command to try again.
If something else happened, you may have a bad distribution
tape, or your hardware may be broken; refer to
Appendix B for help in troubleshooting.
.PP
\fIVdformat\fP will create sector headers and verify
the integrity of each sector formatted.  
The program starts up by identifying the disk controllers
installed in the machine.  Old VDDC controllers which 
support only SMD drives are indicated
as ``smd'' while newer controllers capable of supporting both
SMD and extended-SMD drives are tagged as ``smd-e''. 
D 2
Remember \fIvdformat\fP works only with the drives listed above.
E 2
\fIVdformat\fP
will prompt for the information required as shown below.
If you err in answering questions,
D 2
``Delete'' erases the last character typed, and ``^U'' erases
E 2
I 2
``Delete'' or backspace erase the last character typed, and ``^U'' erases
E 2
the current input line.  At any point you can ask for
assistance by typing ``help''; \fIvdformat\fP will list
the possible answers to the current question.
.DS
D 2
\fBvdformat>\fP\|format
  \fBFormat on which controllers?\fP\|1
    \fBDrives on controller 1?\fP\|0
      \fBNumber of patterns to use while verifying?\fP\|1
      \fBDrive type for controller 1, drive 0?\fP\|egl
        \fBModule serial number for controller 1, drive 0?\fP\|1
\fBvdformat>\fP\|list
E 2
I 2
\fBvdformat>\fP\|\fIformat\fP
  \fBFormat on which controllers?\fP\|\fI1\fP
    \fBDrives on controller 1?\fP\|\fI0\fP
      \fBNumber of patterns to use while verifying?\fP\|\fI1\fP
      \fBDrive type for controller 1, drive 0?\fP\|\fIegl\fP
        \fBModule serial number for controller 1, drive 0?\fP\|\fI1\fP
\fBvdformat>\fP\|\fIlist\fP
E 2
  \fBThe following operations will occur when Start is issued:\fP
    \fBFormat: Controller 1, drive 0, type EGL.\fP
D 2
\fBvdformat>\fP\|start
E 2
I 2
\fBvdformat>\fP\|\fIstart\fP
E 2
\fBStarting format on controller 1, drive 0, type EGL.\fP
(\fIbad sectors will be indicated\fP)
\fBvdformat>\fP
.DE
Once the root device has been formatted, \fIvdformat\fP
will prompt for another command.
Return to the bootstrap by typing
.DS
D 2
\fBvdformat>\fP\|exit
E 2
I 2
\fBvdformat>\fP\|\fIexit\fP
E 2
.DE
or halt the machine by
typing ``~h''.
.DS
D 2
\fBvdformat>\fP ~h
E 2
I 2
\fBvdformat>\fP \fI~h\fP
E 2
\fB#>\|\fP
.DE
.PP
It may be necessary to format other drives before constructing
file systems on them; this can be done at a later time with the
steps just performed, or \fIvdformat\fP may be brought in
off a disk drive as described in \(sc6.1.
.NH 3
Step 2: copying the mini-root file system
.PP
D 2
The second step is to run a simple program,
\fIcopy\fP, which copies a small root
file system into the second partition of the disk.
This file system will serve as the base for creating the actual root
file system to be restored.  The version of the operating
system maintained on the ``mini-root'' file system understands
that it should not swap on top of itself, thereby allowing double use
of the disk partition.
Disk 0 is normally used for this operation when doing an initial
boot.
Another disk may be substituted if necessary,
although several modifications to the procedure may be needed
to create special files for the alternate disk.
The actual disk number should be substituted for the \fIx\fP below.
\fICopy\fP is loaded just as the
\fIvdformat\fP program was loaded;
if you don't have the bootstrap running,
repeat the above instructions until you see the
prompt from Boot (a colon), and then:
E 2
I 2
The second step is to run a simple program, \fIcopy\fP, to copy a
small root file system into the \fBsecond\fP partition of the disk.  (Note
that the disk partitions used by \*(4B may not correspond to those
used by vendor supplied software.)  This file system will serve as the
base for creating the actual root file system to be restored.  The
generic version of the operating system maintained on the ``mini-root''
file system understands that it should not swap on top of itself, thereby
allowing double use of the disk partition.  Disk 0 is normally used for
this operation; this is reflected in the example procedure.  Another disk
may be substituted if necessary, although several modifications will
be necessary to create special files for the alternate disk.  \fICopy\fP
is loaded just as the \fIvdformat\fP program was loaded; if you don't
have the bootstrap running, repeat the previous instructions until you
see the prompt from boot (a colon), and then:
E 2
.DS
.TS
lw(2i) l.
D 2
(copy mini root file system)
\fB:\|\fPcy(0,0)copy	(load and run copy program)
\fBFrom:\fP cy(0,1)	(unit 0, second tape file)
\fBTo:\fP dk(\fIx\fP,1)	(mini root is on drive \fIx\fP; second partition)
E 2
I 2
\fB:\|\fP\fIcy(0,0)copy\fP	(load and run copy program)
\fBFrom:\fP \fIcy(0,1)\fP	(tape drive unit 0, second tape file)
\fBTo:\fP \fIdk(0,1)\fP	(disk drive unit 0, second disk partition)
E 2
\fBCopy completed: 205 records copied\fP
\fBBoot\fP
\fB:\fP
.TE
D 2
(As above, `delete' erases characters and `^U' erases lines.)
E 2
.DE
I 2
As before, `delete' or backspace erase characters and `^U' erases lines.
E 2
.NH 3
Step 3: booting from the mini-root file system
.PP
You now have the minimal set of tools necessary to create a
root file system and restore the file system contents from tape.
To access this file system load the bootstrap program
and boot the version of unix that has been placed in the
``mini-root.''
As before, load the bootstrap if you do not already have
it running.  At the colon prompt:
.DS
.TS
lw(2i) l.
D 2
\fB: \fPdk(\fIx\fP,1)vmunix	(bring in \fIvmunix\fP off mini root)
E 2
I 2
\fB: \fP\fIdk(0,1)vmunix\fP	(get \fIvmunix\fP from disk drive 0, second partition)
E 2
.TE
.DE
The standalone boot program should then read the system from
the mini root file system you just created, and the system should boot:
.DS
.B
271944+78848+92812 start 0x12e8
D 2
4.3 BSD UNIX #1: Wed Apr  9 23:33:59 PST 1985
    sam@okeeffe.berkeley.edu:/usr/src/sys/GENERIC
real mem  = \fIxxx\fP
avail mem = \fIyyy\fP
\fI\&... information about available devices ...\fP
E 2
I 2
4.3 BSD #1: Sat Jun  4 17:11:42 PDT 1988
	(karels@okeeffe.Berkeley.EDU:/usr/src/sys/GENERIC)
real mem  = xxx
avail mem = ###
using ### buffers containing ### bytes of memory
(... information about available devices ...)
E 2
root device? 
.R
.DE
.PP
D 2
The first three numbers are printed out by the bootstrap
programs and are the sizes of different
parts of the system (text, initialized and uninitialized data).  The
system also allocates several system data structures after it starts
running.  The sizes of these structures are based on the amount of available
memory and the maximum count of active users expected, as declared in a system
configuration description.  This will be discussed later.
E 2
I 2
The first three numbers are printed out by the bootstrap programs and
are the sizes of different parts of the system (text, initialized and
uninitialized data).  The system also allocates several system data
structures after it starts running.  The sizes of these structures are
based on the amount of available memory and the maximum count of active
users expected, as declared in a system configuration description.  This
will be discussed later.
E 2
.PP
UNIX itself then runs for the first time and begins by printing out a banner
identifying the release and
version of the system that is in use and the date that it was compiled.  
.PP
Next the
.I mem
messages give the
amount of real (physical) memory and the
memory available to user programs
in bytes.
D 2
For example, if your machine has only 512K bytes of memory, then
\fIxxx\fP will be 520192, 4096 bytes less than 512K.
The system reserves the last 4096 bytes of memory for use in
error logging and doesn't count it as part of real memory.
E 2
I 2
For example, if your machine has 16Mb bytes of memory, then
\fBxxx\fP will be 16777216.
E 2
.PP
The messages that come out next show what devices were found on
the current processor.  These messages are described in
\fIautoconf\fP\|(4).
The distributed system may not have
D 2
found all the communications devices you have (vioc's),
E 2
I 2
found all the communications devices you have (VIOC's or MPCC's),
E 2
or all the mass storage peripherals you have, especially
if you have more than
D 2
two of anything.  You will correct this soon, when you create
a description of your machine from which to configure UNIX.
E 2
I 2
two of anything.  You will correct this when you create
a description of your machine from which to configure a site-dependent
version of UNIX.
E 2
The messages printed at boot here contain much of the information
that will be used in creating the configuration.
In a correctly configured system most of the information
present in the configuration description
is printed out at boot time as the system verifies that each device
is present.
.PP
The \*(lqroot device?\*(rq prompt was printed by the system 
D 2
and is now asking you for the name of the root file system to use.
E 2
I 2
to ask you for the name of the root file system to use.
E 2
This happens because the distribution system is a \fIgeneric\fP
system, i.e. it can be bootstrapped on a Tahoe cpu with its root device
D 2
and paging area on any available disk drive.  You should respond
to the root device question with \fIxx\fP0*.  This response
supplies two pieces of information:
first, \fIxx\fP0 shows that the disk it is running on is drive
0 of type \fIxx\fP, secondly the \*(lq*\*(rq shows that the system is
running \*(lqatop\*(rq the paging area.  The latter is most important,
otherwise the system will attempt to page on top of itself and
chaos will ensue.
You will later build a system tailored to your configuration that
will not ask this question when it is bootstrapped.
E 2
I 2
and paging area on any available disk drive.  You should respond to the
root device question with ``dk0*''.  This response supplies two pieces
of information: first, ``dk0'' shows that the disk it is running on is
drive 0 of type ``dk'', and, secondly, the \*(lq*\*(rq shows that the
system is running \*(lqatop\*(rq the paging area.  The latter is
extremely important, otherwise the system will attempt to page on top
of itself and chaos will ensue.  You will later build a system tailored
to your configuration that will not ask this question when it is
bootstrapped.
E 2
.DS
D 2
\fBroot device?\fP \fIxx\fP0*
E 2
I 2
\fBroot device?\fP \fIdk0*\fP
E 2
WARNING: preposterous time in file system \-\- CHECK AND RESET THE DATE!
\fBerase ^?, kill ^U, intr ^C\fP
\fB#\fP
.DE
.PP
The \*(lqerase ...\*(rq message is part of the /.profile
that was executed by the root shell when it started.  This message
is present to inform you as to what values the character erase,
line erase, and interrupt characters have been set.
.NH 3
Step 4: restoring the root file system
.PP
UNIX is now running,
D 2
and the `UNIX Programmer's manual' applies.
The `#' is the prompt from the shell,
and lets you know that you are the super-user,
whose login name is \*(lqroot\*(rq.  To complete installation
of the bootstrap system one step remains:  the root
file system must be created.
E 2
I 2
and the \fIUNIX Programmer's manual\fP applies.  The ``#'' is the prompt
from the Bourne shell, and lets you know that you are the super-user,
whose login name is \*(lqroot\*(rq.
E 2
.PP
D 2
If the root file system is to reside on a disk other than
unit 0 (as the information printed out
during autoconfiguration shows), you will
have to create the necessary special files in /dev and use
the appropriate value. For example, if the root should be
placed on dk1, you must create /dev/rdk1a and /dev/dk1a using 
\fImknod\fP(8) or the MAKEDEV script in /dev.
E 2
I 2
To complete installation of the bootstrap system one step remains: the
root file system must be created.  If the root file system is to reside
on a disk other than unit 0, you will have to create the necessary special
files in /dev and use the appropriate value in the following example
procedures.
E 2
.PP
D 2
To create the root file system the shell script \*(lqxtr\*(rq
E 2
I 2
For example, if the root must be placed on dk1, you should
create /dev/rdk1a and /dev/dk1a using the MAKEDEV script in /dev
as follows:
.DS
\fB#\fP\|\fIcd /dev; MAKEDEV dk1\fP
.DE
.PP
To actually create the root file system the shell script \*(lqxtr\*(rq
E 2
should be run:
.DS
D 2
\fB#\|\fPdisk=dk\fIx\fP tape=cy xtr
E 2
I 2
\fB#\fP\|\fIdisk=dk0 tape=cy xtr\fP
(Note, ``dk0'' specifies both the disk type and the unit number.  Modify
as necessary.)
E 2
.DE
I 2
.PP
E 2
This will generate many messages regarding the construction
of the file system and the restoration of the tape contents,
D 2
but should eventually stop with the messages:
E 2
I 2
but should eventually stop with the message:
E 2
.DS
 ...
\fBRoot filesystem extracted\fP
\fB#\fP
.DE
.NH 3
Step 5: rebooting the completed root file system
.PP
With the above work completed, all that is left is to reboot:
.DS
.ta 3.5i
D 2
\fB#\|\fPsync	(synchronize file system state)
\fB#\|\fP~h	(halt cpu)
\fB#>\|\fPy	(initialize machine)
\fB#>\|\fPp23 2	(set boot flags)
\fB#>\|\fPfr boot
\fI\&...(boot program is eventually loaded)...\fP
E 2
I 2
\fB#\|\fP\fIsync\fP	(synchronize file system state)
\fB#\|\fP\fI~h\fP	(halt cpu)
\fB#>\|\fP\fIy.\fP	(initialize machine)
\fB#>\|\fP\fIp23 2.\fP	(set boot flags)
\fB#>\|\fP\fIfr boot\fP
\fB\&...(boot program is eventually loaded)...\fP
E 2
\fBBoot\fP
D 2
\fB:\fP dk(\fIx\fP,0)vmunix	(\fIvmunix\fP brought in off root)
\fB271944+78848+92812 start 0x12e8
\fB4.3 BSD UNIX #1: Wed Apr  9 23:33:59 PST 1985
\fB    karels@okeeffe.berkeley.edu:/usr/src/sys/GENERIC
\fBreal mem  = \fIxxx\fR
\fBavail mem = \fIyyy\fR
\fI\&... information about available devices ...\fP
\fBroot on xx0\fP
WARNING: preposterous time in file system \-\- CHECK AND RESET THE DATE!
\fBerase ^?, kill ^U, intr ^C\fP
\fB#\fP
E 2
I 2
\fB:\fP \fIdk(0,0)vmunix\fP	(\fIvmunix\fP from disk drive 0, partition 0)
(Modify unit number as necessary.)
.B
.nf
271944+78848+92812 start 0x12e8
4.3 BSD #1: Sat Jun  4 17:11:42 PDT 1988
        (karels@okeeffe.Berkeley.EDU:/usr/src/sys/GENERIC)
real mem  = ###
avail mem = ###
using ### buffers containing ### bytes of memory
(... information about available devices ...)
root on dk0
WARNING: preposterous time in file system -- CHECK AND RESET THE DATE!
erase ^?, kill ^U, intr ^C
#
.fi
E 2
.DE
I 2
.R
E 2
.PP
D 2
If the root device selected by the kernel is not correct,
it is necessary to reboot again using the option to ask for the root
device.  On the Tahoe use ``p23 3''.
At the prompt from the bootstrap, use the same device specification
above: dk(\fIx\fP,0)vmunix.
Then, to the question ``root device?,''
respond with dk0.
E 2
I 2
If the root device selected by the kernel is not correct, it is necessary
to reboot again using the option to ask for the root device.  On the Tahoe
use ``\fIp23 3.\fP''.  At the prompt from the bootstrap, use the same
disk driver unit specification as used above: ``\fIdk(0,0)vmunix\fP''.
Then, to the question ``root device?,'' respond with ``\fIdk0\fP''.
E 2
See section 6.1 and appendix C if the system does not reboot properly.
.PP
D 2
The system is now running single user on the installed
root file system.  The next section tells how to complete
the installation of distributed software on the /usr file system.
E 2
I 2
The system is now running single user on the installed root file system.
The next section tells how to complete the installation of distributed
software on the /usr file system.
E 2
.NH 3
Step 6: placing labels on the disks
.PP
D 2
4.3BSD uses disk labels in the first sector of each disk to contain
E 2
I 2
\*(4B uses disk labels in the first sector of each disk to contain
E 2
information about the geometry of the drive and the partition layout.
This information is written with \fIdisklabel\fP\|(8).
Note that recent CCI releases, and apparently Harris releases,
may use a different form of disk label, also in the first sector.
As the formats of these labels are incompatible,
skip this step if your machine is using disk labels already.
Recent firmware for the console processor (CP) may use these labels,
and thus the labels must be retained.
Eventually, it will be possible to use both formats simultaneously.
I 2
You may wish to experiment on a spare disk once the system is running.
E 2
.PP
For each disk that you wish to label, run the following command:
.DS
D 2
\fB#\|\fPdisklabel -w dk\fIx\fP \fItype\fP "\fIoptional_pack_name\fP"
E 2
I 2
\fB#\|\fP\fIdisklabel  -rw  dk\fP\fB#\fP  \fBtype\fP  \fI"optional_pack_name"\fP
E 2
.DE
D 2
The \fItype\fP is the CCI disk device name as listed in section 1.3,
or any other name listed in /etc/disktab.
E 2
I 2
The \fB#\fP is the unit number; the \fBtype\fP is the CCI disk device
name as listed in section 1.4 or any other name listed in /etc/disktab.
E 2
The optional information may contain any descriptive name for the
D 2
contents of a disk, and may be up to 16 characters long.
This procedure will place the label on the disk using the information
found in /etc/disktab for the disk type named.
The default disk partitions in \*(4B are the mostly
the same as those in the CCI 1.21 release,
except for CDC 340Mb xfd drives;
see section 4.3.2 for details.
If you have changed the disk partition sizes,
you may add entries for the modified configuration in /etc/disktab
E 2
I 2
contents of a disk, and may be up to 16 characters long.  This procedure
will place the label on the disk using the information found in /etc/disktab
for the disk type named.  The default disk partitions in \*(4B are the mostly
the same as those in the CCI 1.21 release, except for CDC 340Mb xfd drives;
see section 4.2 for details.  If you have changed the disk partition sizes,
you may wish to add entries for the modified configuration in /etc/disktab
E 2
before labeling the affected disks.
I 2
.PP
Note that the partition sizes and sectors per track in /etc/disktab
are now specified in sectors, not units of kilobytes as in the vendors'
4.2BSD and System V systems.
For SMD disks, the sector size is 512 bytes, and is listed explicitly.
E 2
.NH 3
Step 7: setting up the /usr file system
.PP
The next thing to do is to extract the rest of the data from
the tape.
D 2
You might wish to review the disk configuration information in section 4.4
before continuing; the partitions used below are those most appropriate
E 2
I 2
You might wish to review the disk configuration information in section
4.2 before continuing; the partitions used below are those most appropriate
E 2
in size.
.PP
For the Cypher tape drive, execute the following commands:
.DS
D 2
\fB#\fP cd /dev; MAKEDEV cy0; sync
E 2
I 2
\fB#\fP \fIcd /dev; MAKEDEV cy0\fP
E 2
.DE
Then perform the following:
.br
.ne 5
.sp
.DS
.TS
lw(2i) l.
D 2
\fB#\fP date \fIyymmddhhmm\fP	(set date, see \fIdate\fP\|(1))
E 2
I 2
\fB#\fP \fIdate yymmddhhmm\fP	(set date, see \fIdate\fP\|(1))
E 2
\&....
D 2
\fB#\fP passwd root	(set password for super-user)
E 2
I 2
\fB#\fP \fIpasswd root\fP	(set password for super-user)
E 2
\fBNew password:\fP	(password will not echo)
\fBRetype new password:\fP
D 2
\fB#\fP hostname \fImysitename\fP	(set your hostname)
\fB#\fP newfs dk0c	(create empty user file system)
(this takes a few minutes)
\fB#\fP mount /dev/dk0c /usr	(mount the usr file system)
\fB#\fP cd /usr	(make /usr the current directory)
\fB#\fP mt fsf
\fB#\fP tar xpbf 20 /dev/rmt12 	(extract all of usr except usr/src)
E 2
I 2
\fB#\fP \fIhostname mysitename\fP	(set your hostname)
\fB#\fP \fInewfs dk#c\fP	(create empty user file system)
(\fIdk\fP is the disk type, \fI#\fP is the unit number, \fIc\fP
is the partition; this takes a few minutes)
\fB#\fP \fImount /dev/dk#c /usr\fP	(mount the usr file system)
\fB#\fP \fIcd /usr\fP	(make /usr the current directory)
D 5
\fB#\fP \fImt fsf\fP	(space to end of previous tape file)
\fB#\fP \fItar xpf /dev/rmt12\fP	(extract all of usr except usr/src)
E 5
I 5
\fB#\fP \fImt -t /dev/rmt12 fsf\fP	(space to end of previous tape file)
\fB#\fP \fItar xbpf 40 /dev/rmt12\fP	(extract all of usr except usr/src)
E 5
E 2
(this takes about 15-20 minutes)
.TE
.DE
I 2
If no disk label has been installed on the disk, the \fInewfs\fP
command will require a third argument to specify the disk type,
using one of the names in /etc/disktab.
E 2
If the tape had been rewound or positioned incorrectly before the \fItar\fP,
it may be repositioned by the following commands.
.DS
D 2
\fB#\fP mt rew
\fB#\fP mt fsf 3
E 2
I 2
D 5
\fB#\fP \fImt rew\fP
\fB#\fP \fImt fsf 3\fP
E 5
I 5
\fB#\fP \fImt -t /dev/rmt12 rew\fP
\fB#\fP \fImt -t /dev/rmt12 fsf 3\fP
E 5
E 2
.DE
The data on the fourth tape file has now been extracted.
D 5
If you are using 1600bpi tapes,
the first reel of the distribution is no longer needed;
the remainder of the installation procedure uses the second
D 2
reel of tape that should be mounted in place of the first.
E 2
I 2
reel of tape which should now be mounted in place of the first.
E 2
The first instruction below should be ignored if using 1600bpi tapes.
The installation procedure continues from this point on the 6250bpi tape.
E 5
I 5
If you are using 1600bpi tapes, the first reel of the
distribution is no longer needed; you should now mount the second
reel instead.  The installation procedure continues from this
point on the 6250bpi tape.
E 5
.DS
.TS
lw(2i) l.
D 2
\fB#\fP mt fsf		(do not do on 1600bpi tapes)
\fB#\fP mkdir src	(make directory for source)
\fB#\fP mkdir src/sys	(make directory for system source)
\fB#\fP cd src/sys	(make /usr/sys the current directory)
\fB#\fP tar xpbf 20 /dev/rmt12 	(extract the system source)
E 2
I 2
D 5
\fB#\fP \fImt fsf\fP		(6250bpi tapes only)
E 5
\fB#\fP \fImkdir src\fP	(make directory for source)
D 5
\fB#\fP \fImkdir src/sys\fP	(make directory for system source)
\fB#\fP \fIcd src/sys\fP	(make /usr/src/sys the current directory)
\fB#\fP \fItar xpbf 20 /dev/rmt12\fP 	(extract the system source)
E 5
I 5
\fB#\fP \fIcd src\fP	(make source directory the current directory)
\fB#\fP \fImt -t /dev/rmt12 fsf\fP	(space to end of previous tape file)
\fB#\fP \fItar xpbf 40 /dev/rmt12\fP 	(extract the system source)
E 5
E 2
(this takes about 5-10 minutes)
D 2
\fB#\fP cd /	(back to root)
\fB#\fP chmod 755  /  /usr  /usr/src /usr/src/sys
\fB#\fP rm \-f sys
\fB#\fP ln \-s usr/src/sys sys	(make a symbolic link to the system source)
\fB#\fP umount /dev/dk0c	(unmount /usr)
E 2
I 2
D 5
\fB#\fP \fIcd /\fP	(back to root)
\fB#\fP \fIchmod 755  /  /usr  /usr/src /usr/src/sys\fP
E 5
I 5
\fB#\fP \fIcd /\fP	(change directory, back to the root)
\fB#\fP \fIchmod 755  /usr/src\fP
E 5
D 4
\fB#\fP \fIrm \-f sys\fP
\fB#\fP \fIln \-s usr/src/sys sys\fP	(make a symbolic link to the system source)
E 4
\fB#\fP \fIumount /dev/dk#c\fP	(unmount /usr)
E 2
.TE
.DE
.PP
You can check the consistency of the /usr file system by doing
.DS
D 2
\fB#\fP fsck /dev/rdk0c
E 2
I 2
\fB#\fP \fIfsck /dev/rdk#c\fP
E 2
.DE
The output from
.I fsck
should look something like:
.DS
.B
D 2
** /dev/rdk0c
E 2
I 2
** /dev/rdk#c
E 2
** Last Mounted on /usr
** Phase 1 - Check Blocks and Sizes
** Phase 2 - Check Pathnames
** Phase 3 - Check Connectivity
** Phase 4 - Check Reference Counts
** Phase 5 - Check Cyl groups
671 files, 3497 used, 137067 free (75 frags, 34248 blocks)
.R
.DE
.PP
If there are inconsistencies in the file system, you may be prompted
D 2
to apply corrective action; see the document describing
.I fsck
for information.
E 2
I 2
to apply corrective action; see the \fIfsck\fP(8) or \fIFsck -- The UNIX
File System Check Program\fP for more details.
E 2
.PP
D 2
To use the /usr file system, you should now remount it by
saying
E 2
I 2
To use the /usr file system, you should now remount it with:
E 2
.DS
D 2
\fB#\fP /etc/mount /dev/dk0c /usr
E 2
I 2
\fB#\fP \fI/etc/mount /dev/dk#c /usr\fP
E 2
.DE
D 5
You can then extract the source code for the commands:
E 5
I 5
.PP
If you are using 1600bpi tapes, the second reel of the
distribution is no longer needed; you should now mount the third
reel instead.  The installation procedure continues from this
point on the 6250bpi tape.
E 5
.DS
D 2
\fB#\fP cd /usr/src
\fB#\fP mt fsf
\fB#\fP tar xpb 20
E 2
I 2
D 5
\fB#\fP \fIcd /usr/src\fP
\fB#\fP \fImt fsf\fP
\fB#\fP \fItar xpb 20\fP
E 5
I 5
\fB#\fP \fImkdir /usr/src/sys\fP
\fB#\fP \fIchmod 755 /usr/src/sys\fP
\fB#\fP \fIcd /usr/src/sys\fP
\fB#\fP \fImt -t /dev/rmt12 fsf\fP
\fB#\fP \fItar xpbf 40 /dev/rmt12\fP
E 5
E 2
.DE
D 5
If you get an error at this point, most likely it was
a problem with tape positioning.
You can reposition the tape by rewinding it and
then skipping over the files already read (see \fImt\fP\|(1)).
.NH 3
Additional software
E 5
.PP
D 2
There are three extra tape files on the distribution tape(s)
which have not been installed to this point.  They are
a font library for use with Varian and Versatec printers,
the Ingres database system, and user contributed software.
All three tape files are in \fItar\fP\|(1) format and
can be installed by positioning the tape 
E 2
I 2
There is one additional tape file on the distribution tape(s)
D 5
which has not been installed to this point;
it contains user contributed software in \fItar\fP\|(1) format.
On the 1600bpi tape set, this file is the sole file on the third tape.
It can be installed by positioning the tape 
E 2
using \fImt\fP\|(1) and reading
D 2
in the files as was done for /usr/src above.  As distributed,
the fonts should be placed in a directory /usr/lib/vfont, the
Ingres system should be placed in /usr/ingres, and the user
contributed software should be placed in /usr/src/new.  The
exact contents of the user contributed software is given in
a separate document.
E 2
I 2
in the files as was done for /usr/src above.
As distributed, the user contributed software should be placed in /usr/src/new.
It may be extracted by mounting the appropriate tape (if not already mounted),
positioning the tape at the beginning of this file (for 6250bpi),
and extracting with
.IR tar :
E 5
I 5
which has not been installed to this point; it contains user
contributed software in \fItar\fP\|(1) format.  As distributed,
the user contributed software should be placed in /usr/src/new.
E 5
.DS
D 5
\fB#\fP \fIcd /usr/src\fP
\fB#\fP \fImkdir new\fP
\fB#\fP \fIchmod 755 new\fP
\fB#\fP \fIcd new\fP
\fB#\fP \fItar xpb 20\fP
E 5
I 5
\fB#\fP \fImkdir /usr/src/new\fP
\fB#\fP \fIchmod 755 /usr/src/new\fP
\fB#\fP \fIcd /usr/src/new\fP
\fB#\fP \fImt -t /dev/rmt12 fsf\fP
\fB#\fP \fItar xpbf 40 /dev/rmt12\fP
E 5
.DE
Several of the directories for large contributed software subsystems
D 5
have been placed in a single archive file and compressed to allow
E 5
I 5
have been placed in a single archive file and compressed due to space
constraints within the distribution.
E 5
E 2
.NH 2
Additional conversion information
.PP
D 2
After setting up the new \*(4B filesystems,
you may restore the user files that were saved on tape before beginning
the conversion.
Note that the \*(4B \fIrestore\fP program does
its work on a mounted file system using normal system operations
(unlike the older \fIrestor\fP that accessed the raw file
system device and deposited inodes in the appropriate locations
on disk).  This means that file system dumps may be restored even
if the characteristics of the file system changed.  To restore
a dump tape for, say, the /a file system something like the following
would be used:
E 2
I 2
After setting up the new \*(4B filesystems, you may restore the user
files that were saved on tape before beginning the conversion.
Note that the \*(4B \fIrestore\fP program does its work on a mounted
file system using normal system operations.  This means that file
system dumps may be restored even if the characteristics of the file
system changed.  To restore a dump tape for, say, the /a file system
something like the following would be used:
E 2
.DS
D 2
\fB#\fP mkdir /a
\fB#\fP newfs dk1c eagle
\fB#\fP mount /dev/dk1c /a
\fB#\fP cd /a
\fB#\fP restore x
E 2
I 2
\fB#\fP \fImkdir /a\fP
\fB#\fP \fInewfs dk#c\fI
\fB#\fP \fImount /dev/dk#c /a\fP
\fB#\fP \fIcd /a\fP
D 6
\fB#\fP \fIrestore x\fP
E 6
I 6
\fB#\fP \fIrestore r\fP
E 6
E 2
.DE
.PP
If \fItar\fP images were written instead of doing a dump, you should
D 2
be sure to use the `p' option when reading the files back.
No matter how you restore a file system, be sure and check its
integrity with \fIfsck\fP when the job is complete.
E 2
I 2
be sure to use its `-p' option when reading the files back.  No matter
how you restore a file system, be sure to unmount it and and check its
integrity with \fIfsck\fP(8) when the job is complete.
I 5




E 5
E 2
E 1

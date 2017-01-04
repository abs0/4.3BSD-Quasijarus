h64669
s 00010/00002/01321
d D 6.6 03/11/18 22:32:25 msokolov 7 6
c VAX/Tahoe conditional logic was breaking tables
e
s 00030/00033/01293
d D 6.5 03/11/18 22:18:10 msokolov 6 5
c update for 4.3BSD-Quasijarus
e
s 00021/00010/01305
d D 6.4 88/07/21 18:06:48 bostic 5 4
c add info on mpcc; remove extraneous paragraph, minor cleanup
e
s 00008/00007/01307
d D 6.3 88/07/19 16:15:46 bostic 4 3
c Kirk's cleanup on block sizes
e
s 00325/00165/00989
d D 6.2 88/07/17 09:34:00 karels 3 2
c merge vax and tahoe versions
e
s 00328/00208/00826
d D 6.1 86/05/14 09:36:04 mckusick 2 1
c 4.3BSD release document
e
s 01034/00000/00000
d D 5.1 86/05/14 09:35:47 mckusick 1 0
c broken out of 0.t for 4.2BSD document
e
u
U
t
T
I 1
D 3
.\" Copyright (c) 1980 Regents of the University of California.
E 3
I 3
.\" Copyright (c) 1980,1986,1988 Regents of the University of California.
E 3
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
.nr H1 4
.nr H2 0
.ds CF \*(DY
.ds RH "System setup
.bp
.LG
.B
.ce
4. SYSTEM SETUP
.sp 2
.R
.NL
.PP
D 2
This section describes procedures used to setup a VAX UNIX system.
Procedures described here are used when a system is first installed
E 2
I 2
D 3
This section describes procedures used to set up a VAX UNIX system.
E 3
I 3
This section describes procedures used to set up a \*(Mc UNIX system.
E 3
These procedures are used when a system is first installed
E 2
or when the system configuration changes.  Procedures for normal
system operation are described in the next section.
I 3
.if \n(Vx \{\
E 3
.NH 2
I 2
Creating UNIX boot media
.PP
The procedures for making the various UNIX boot media are described in this
D 3
section.  If you have an 11/785 or 11/780, you will need to make a floppy.
For an 11/730, you will need to make a cassette.  While for an 8650
or 8600, you will need to make a console RL02 pack.
E 3
I 3
D 6
section.  If you have an 8200 or 11/780, you will need to make a floppy.
For an 11/730, you will need to make a cassette.  For an
8600, you will need to make a console RL02 pack.
E 6
I 6
section.  If you have an 11/780, you will need to make a floppy.
Making a console floppy is also recommended for 8200.
For an 11/730 (and rarely for an 11/750), you will need to make a cassette.
For an 8600, you will need to make a console RL02 pack.
E 6
E 3
.PP
The boot command files are all set up for booting off of the first
UNIBUS or MASSBUS.  If you are booting off of a different UNIBUS
or MASSBUS, you will need to modify the boot command files appropriately.
.NH 3
Making a UNIX boot console RL02 pack
.PP
D 3
If you have an 8650 or 8600 you will want to create a
E 3
I 3
If you have an 8600 you will want to create a
E 3
.UX
boot console RL02 pack by adding some files to your current DEC
console pack, using
\fIarff\fP\|(8).
If you do not want to modify your current DEC console pack, you may
make a copy of it first using
\fIdd\fP\|(1).
This pack will make standalone system operations such as
bootstrapping much easier.
.PP
First change into the directory where the console RL02
information is stored:
.DS
D 3
\fB#\fP cd /sys/consolerl
E 3
I 3
\fB#\fI cd /sys/consolerl\fR
E 3
.DE
then set up the default boot device.
If you have an RK07 as your primary root do:
.DS
D 3
\fB#\fP cp defboo.hk defboo.com
E 3
I 3
\fB#\fI cp defboo.hk defboo.com\fR
E 3
.DE
If you have a drive on a UDA50 (e.g. an RA81) as your
primary root do:
.DS
D 3
\fB#\fP cp defboo.ra defboo.com
E 3
I 3
\fB#\fI cp defboo.ra defboo.com\fR
E 3
.DE
If you have a second vendor
UNIBUS storage module as your primary root do:
.DS
D 3
\fB#\fP cp defboo.up defboo.com
E 3
I 3
\fB#\fI cp defboo.up defboo.com\fR
E 3
.DE
Otherwise:
.DS
D 3
\fB#\fP cp defboo.hp defboo.com
E 3
I 3
\fB#\fI cp defboo.hp defboo.com\fR
E 3
.DE
The final step in updating the console RL02 pack is:
.DS
D 3
\fB#\fP make update
E 3
I 3
\fB#\fI make update\fR
E 3
.DE
More copies of this console RL02 pack can be made using
.IR dd (1).
.NH 3
E 2
Making a UNIX boot floppy
.PP
D 2
If you have an 11/780 you will want to create a
E 2
I 2
D 3
If you have an 11/785 or 11/780 you will want to create a
E 3
I 3
D 6
If you have an 8200 or 11/780 you will want to create a
E 6
I 6
If you have an 11/780 you will want to create a
E 6
E 3
E 2
.UX
boot floppy by adding some files to a copy of your current DEC
D 3
console floppy, using
E 3
I 3
console floppy, using either
E 3
.IR flcopy (8)
D 3
and
\fIarff\fP\|(8).
E 3
I 3
or
.IR dd \|(1),
and using
.IR arff \|(8).
E 3
This floppy will make standalone system operations such as
bootstrapping much easier.
.PP
First change into the directory where the console floppy
information is stored:
.DS
D 3
\fB#\fP cd /sys/floppy
E 3
I 3
\fB#\fI cd /sys/floppy\fR
E 3
.DE
then set up the default boot device.
If you have an RK07 as your primary root do:
.DS
D 3
\fB#\fP cp defboo.hk defboo.cmd
E 3
I 3
\fB#\fI cp defboo.hk defboo.cmd\fR
E 3
.DE
If you have a drive on a UDA50 (e.g. an RA81) as your
primary root do:
.DS
D 3
\fB#\fP cp defboo.ra defboo.cmd
E 3
I 3
\fB#\fI cp defboo.ra defboo.cmd\fR
E 3
.DE
If you have a second vendor
UNIBUS storage module as your primary root do:
.DS
D 3
\fB#\fP cp defboo.up defboo.cmd
E 3
I 3
\fB#\fI cp defboo.up defboo.cmd\fR
E 3
.DE
I 3
D 6
If you have a drive on a KDB50 as your primary root do:
.DS
\fB#\fI cp defboo.kra defboo.cmd\fR
.DE
E 6
E 3
Otherwise:
.DS
D 3
\fB#\fP cp defboo.hp defboo.cmd
E 3
I 3
\fB#\fI cp defboo.hp defboo.cmd\fR
E 3
.DE
D 3
If the local configuration requires any changes in restar.cmd
D 2
or defboo.cmd (e.g., for interleaved memory controllers),
E 2
I 2
or defboo.cmd (e.g., for interleaved memory controllers see
E 3
I 3
On an 11/780,
if the local configuration requires any changes in restar.cmd
or defboo.cmd (e.g., for interleaved old-style memory controllers see
E 3
defboo.MS780C-interleaved),
E 2
these should be made now.
The following command will then copy your DEC local console floppy,
updating the copy appropriately.
.DS
D 3
\fB#\fP make update
E 3
I 3
\fB#\fI make update\fR
E 3
\fBChange Floppy, Hit return when done.\fP
(waits for you to put clean floppy in console)
D 3
\fBAre you sure you want to clobber the floppy?\fP yes
E 3
I 3
\fBAre you sure you want to clobber the floppy?\fI yes\fR
E 3
.DE
More copies of this floppy can be made using
.IR flcopy (8).
I 3
.PP
D 6
On an 8200, copy any of the DEC diagnostic floppies
by placing the source in console drive 1 and the destination
in console drive 2, then:
E 6
I 6
On an 8200 it is recommended to make a
.UX
console RX50 floppy, although it is not required if you use the ROM
to boot directly from a KDB50 or UDA50.
Since the 8200 does not need any CPU microcode or front end processor code
on the console floppy, the distribution console RX50 may be used for booting
and as a maintenance aid.  There is no need to make a different console floppy.
If you have not received a console RX50 with your \*(4B distribution, you can
make one with the following commands:
E 6
.DS
D 6
.\" XXX be sure to put /dev/csa? in root fs, or makedev first
\fB#\fI dd if=/dev/csa1 of=/dev/csa2 bs=400k\fR 
\fB1+0 records in\fP
\fB1+0 records out\fP
E 6
I 6
\fB#\fI cd /sys/rx50\fR
\fB#\fI make\fR
\fB#\fI make install\fR
E 6
.DE
D 6
Next remove all but the first few files, leaving only those
that lead up to ``boot58.exe'' (as well as boot58.exe itself).
It is a good idea to remove
the original floppy from drive 1 first.
.DS
\fB#\fI arff tmf /dev/csa2\fR
\&...(should list something like ``fg81.ve0'', followed by ``boot58.exe'';
then a series of files that may be deleted)...\fP
\fB#\fI arff dmf /dev/csa2\fR files to delete from previous list
.DE
Finally, add UNIX boot files:
.DS
\fB#\fI arff rmf /dev/csa2 boot format copy *boo.cmd\fR
.DE
Put the new boot floppy in drive 1.  To make copies of this floppy,
use the same
.I dd
command shown above.
E 6
I 6
The
.I defboo.cmd
and
.I sngboo.cmd
command scripts are set up for booting from the first KDB50.
If you need to boot from a KDB50 other than the first, or from an UDA50,
change the scripts accordingly prior to running
.IR make .
E 6
E 3
D 2
.NH 2
E 2
I 2
.NH 3
E 2
Making a UNIX boot cassette
.PP
If you have an 11/730 you will want to create a
.UX
boot cassette by adding some files to a copy of
your current DEC console cassette, using
D 2
.IR flcopy (8)
and
.IR arff (8).
E 2
I 2
\fIflcopy\fP\|(8) and \fIarff\fP\|(8).
E 2
This cassette will make standalone system operations such as
bootstrapping much easier.
.PP
First change into the directory where the console cassette
information is stored:
.DS
D 3
\fB#\fP cd /sys/cassette
E 3
I 3
\fB#\fI cd /sys/cassette\fR
E 3
.DE
then set up the default boot device.
If you have an IDC storage module as your primary root do:
.DS
D 3
\fB#\fP cp defboo.rb defboo.cmd
E 3
I 3
\fB#\fI cp defboo.rb defboo.cmd\fR
E 3
.DE
If you have an RK07 as your primary root do:
.DS
D 3
\fB#\fP cp defboo.hk defboo.cmd
E 3
I 3
\fB#\fI cp defboo.hk defboo.cmd\fR
E 3
.DE
If you have a drive on a UDA50 as your primary root do:
.DS
D 3
\fB#\fP cp defboo.ra defboo.cmd
E 3
I 3
\fB#\fI cp defboo.ra defboo.cmd\fR
E 3
.DE
Otherwise:
.DS
D 3
\fB#\fP cp defboo.up defboo.cmd
E 3
I 3
\fB#\fI cp defboo.up defboo.cmd\fR
E 3
.DE
To complete the procedure place your DEC local
console cassette in 
drive 0 (the drive at front of the CPU);
the following command will then copy it,
updating the copy appropriately.
.DS
D 3
\fB#\fP make update
E 3
I 3
\fB#\fI make update\fR
E 3
\fBChange Floppy, Hit return when done.\fP
(waits for you to put clean cassette in console drive 0)
D 3
\fBAre you sure you want to clobber the floppy?\fP yes
E 3
I 3
\fBAre you sure you want to clobber the floppy?\fI yes\fR
E 3
.DE
More copies of this cassette can best be made using
.IR dd (1).
I 6
.PP
Although it is rarely necessary, you can also create a console cassette for
a 750 with BOOT58.  You will need to do this if you cannot obtain a boot PROM
for your system disk.  Contact Quasijarus Consortium for assistance if you need
to do this.
E 6
I 3
.\}
E 3
.NH 2
Kernel configuration
.PP
This section briefly describes the layout of the kernel code and
how files for devices are made.
For a full discussion of configuring
and building system images, consult the document ``Building
D 2
4.2BSD UNIX Systems with Config''.
E 2
I 2
D 3
\*(4B UNIX Systems with Config''.
E 3
I 3
4.3BSD UNIX Systems with Config''.
E 3
E 2
.NH 3
Kernel organization
.PP
As distributed, the kernel source is in a 
separate tar image.  The source may be physically
located anywhere within any file system so long as
a symbolic link to the location is created for the
file /sys
(many files in /usr/include are normally symbolic links
relative to /sys).  In further discussions of the
system source all path names will be given relative to
/sys.
.PP
The directory /sys/sys
contains the mainline machine independent
operating system code.
Files within this directory are conventionally
D 2
named with the following prefixes.
E 2
I 2
named with the following prefixes:
E 2
.DS
.TS
lw(1.0i) l.
init_	system initialization
kern_	kernel (authentication, process management, etc.)
quota_	disk quotas
sys_	system calls and similar
tty_	terminal handling
ufs_	file system
uipc_	interprocess communication
vm_	virtual memory
.TE
.DE
.PP
D 2
The remaining directories are organized as follows.
E 2
I 2
The remaining directories are organized as follows:
E 2
.DS
.TS
lw(1.0i) l.
D 3
/sys/h	machine independent include files
E 3
I 3
/sys/h	machine-independent include files
E 3
/sys/conf	site configuration files and basic templates
D 3
/sys/net	network independent, but network related code
/sys/netinet	DARPA Internet code
E 3
I 3
/sys/kdb	machine-independent part of the kernel debugger
/sys/net	protocol-independent, but network-related code
E 3
/sys/netimp	IMP support code
D 2
/sys/netpup	PUP-1 support code
E 2
I 2
D 3
/sys/netns	Xerox NS support code
E 2
/sys/vax	VAX specific mainline code
E 3
I 3
/sys/netinet	DARPA Internet code
/sys/netns	Xerox NS code
/sys/stand	machine-independent standalone code
/sys/tahoe	Tahoe-specific mainline code
/sys/tahoealign	Tahoe unaligned-reference emulation code
/sys/tahoedist	Tahoe distribution files
/sys/tahoeif	Tahoe network interface code
/sys/tahoevba	Tahoe VERSAbus device drivers and related code
/sys/tahoemath	Tahoe floating point emulation code
/sys/tahoestand	Tahoe standalone device drivers and related code
/sys/vax	VAX-specific mainline code
/sys/vaxbi	VAX BI device drivers and related code
/sys/vaxdist	VAX distribution files
E 3
/sys/vaxif	VAX network interface code
/sys/vaxmba	VAX MASSBUS device drivers and related code
I 3
/sys/vaxstand	VAX standalone device drivers and boot code
E 3
/sys/vaxuba	VAX UNIBUS device drivers and related code
.TE
.DE
.PP
Many of these directories are referenced through /usr/include with
symbolic links.  For example, /usr/include/sys is a symbolic
link to /sys/h.  The system code, as distributed, is totally
independent of the include files in /usr/include.  This allows
the system to be recompiled from scratch without the /usr file
system mounted.
.NH 3
Devices and device drivers
.PP
Devices supported by UNIX are implemented in the kernel
D 3
by drivers whose source is kept in /sys/vax, /sys/vaxuba,
or /sys/vaxmba.  These drivers are loaded
E 3
I 3
by drivers whose source is kept in
.if \n(Vx \{\
/sys/vax, /sys/vaxbi, /sys/vaxuba, or /sys/vaxmba.
.\}
.if \n(Th \{\
/sys/tahoe or /sys/tahoevba.
.\}
These drivers are loaded
E 3
into the system when included in a cpu specific configuration file
kept in the conf directory.  Devices are accessed through special
files in the file system, made by the
.IR mknod (8)
program and normally kept in the /dev directory.
For all the devices supported by the distribution system, the
files in /dev are created by the /dev/MAKEDEV
shell script.
.PP
Determine the set of devices that you have and create a new /dev
directory by running the MAKEDEV script.
First create a new directory
/newdev, copy MAKEDEV into it, edit the file MAKEDEV.local
to provide an entry for local needs,
and run it to generate a /newdev directory.
I 3
.if \n(Vx \{\
E 3
D 2
For instance, if your machine has a single dz-11, a single
dh-11, a single dmf-32, an rm03 disk, an EMULEX controller, an
AMPEX-9300 disk, and a te16 tape drive you would do:
E 2
I 2
For instance, if your machine has a single DZ11, a single
DH11, a single DMF32, an RM03 disk, an EMULEX UNIBUS SMD disk controller, an
AMPEX 9300 disk, and a TE16 tape drive you would do:
I 3
.\}
.if \n(Th \{\
For instance, if your machine has a single VIOC terminal
multiplexor, two CDC 340 megabyte Winchester drives, and
a single Cipher tape drive you would do:
.\}
E 3
E 2
.DS
D 3
\fB#\fP cd /
\fB#\fP mkdir newdev
\fB#\fP cp dev/MAKEDEV newdev/MAKEDEV
\fB#\fP cd newdev
\fB#\fP MAKEDEV dz0 dh0 dmf0 hp0 up0 ht0 std LOCAL
E 3
I 3
\fB#\fP \fIcd /\fP
\fB#\fP \fImkdir newdev\fP
\fB#\fP \fIcp dev/MAKEDEV newdev/MAKEDEV\fP
\fB#\fP \fIcd newdev\fP
.if \n(Vx \{\
\fB#\fP \fIMAKEDEV dz0 dh0 dmf0 hp0 up0 ht0 std LOCAL\fP
.\}
.if \n(Th \{\
\fB#\fP \fIMAKEDEV vx0 dk0 dk1 cy0 std LOCAL\fP
.\}
E 3
.DE
Note the ``std'' argument causes standard devices
D 2
such as /dev/console, the machine console, /dev/floppy,
the console floppy disk interface for the 11/780, and
/dev/tu0 and /dev/tu1, the console cassette interfaces
E 2
I 2
D 3
such as \fI/dev/console\fP, the machine console, \fI/dev/floppy\fP,
E 3
I 3
such as \fI/dev/console\fP, the machine console,
.if \n(Vx \{\
\fI/dev/floppy\fP,
E 3
the console floppy disk interface for the 11/780 and 11/785, and
\fI/dev/tu0\fP and \fI/dev/tu1\fP, the console cassette interfaces
E 2
D 3
for the 11/750 and 11/730, to be created.
E 3
I 3
for the 11/750 and 11/730,
.\}
to be created.
E 3
.PP
You can then do
.DS
D 3
\fB#\fP cd /
\fB#\fP mv dev olddev ; mv newdev dev
\fB#\fP sync
E 3
I 3
\fB#\fP \fIcd /\fP
\fB#\fP \fImv dev olddev ; mv newdev dev\fP
\fB#\fP \fIsync\fP
E 3
.DE
to install the new device directory.
.NH 3
Building new system images
.PP
The kernel configuration of each UNIX system is described by
D 2
a single configuration file, stored in the /sys/conf directory.
E 2
I 2
a single configuration file, stored in the \fI/sys/conf\fP directory.
E 2
To learn about the format of this file and the procedure used
to build system images,
D 2
start by reading ``Building 4.2BSD UNIX Systems with Config'',
E 2
I 2
D 3
start by reading ``Building \*(4B UNIX Systems with Config'',
E 3
I 3
start by reading ``Building 4.3BSD UNIX Systems with Config'',
E 3
E 2
look at the manual pages in section 4
of the UNIX manual for the devices you have,
D 2
and look at the configuration files in the /sys/conf
E 2
I 2
and look at the sample configuration files in the /sys/conf
E 2
directory.
.PP
The configured system image ``vmunix'' should be
copied to the root, and then booted to try it out.
It is best to name it /newvmunix so as not to destroy
the working system until you're sure it does work:
.DS
D 3
\fB#\fP cp vmunix /newvmunix
\fB#\fP sync
E 3
I 3
\fB#\fP \fIcp vmunix /newvmunix\fP
\fB#\fP \fIsync\fP
E 3
.DE
D 2
It is also a good idea to keep the old system around under some other
E 2
I 2
It is also a good idea to keep the previous system around under some other
E 2
name.  In particular, we recommend that you save the generic distribution
D 2
version of the system permanently as /genvmunix for use in emergencies.
.PP
E 2
I 2
version of the system permanently as \fI/genvmunix\fP for use in emergencies.
E 2
To boot the new version of the system you should follow the
bootstrap procedures outlined in section 6.1.
I 2
After having booted and tested the new system, it should be installed
as \fI/vmunix\fP before going into multiuser operation.
E 2
A systematic scheme for numbering and saving old versions
D 2
of the system is best.
E 2
I 2
of the system may be useful.
E 2
.NH 2
Disk configuration
.PP
This section describes how to layout file systems to make use
of the available space and to balance disk load for better system
performance.
.NH 3
Initializing /etc/fstab
.PP
I 3
.if \n(Vx \{\
E 3
Change into the directory /etc and copy the appropriate file from:
.DS
fstab.rm03
fstab.rm05
fstab.rm80
fstab.ra60
fstab.ra80
fstab.ra81
fstab.rb80
fstab.rp06
fstab.rp07
fstab.rk07
D 3
fstab.up160m (160Mb up drives)
D 2
fstab.up300m (300Mb up drives)
E 2
fstab.hp400m (400Mb hp drives)
E 3
I 3
fstab.up160m (160MB up drives)
fstab.hp400m (400MB hp drives)
E 3
fstab.up (other up drives)
fstab.hp (other hp drives)
.DE
to the file /etc/fstab, i.e.:
.DS
D 3
\fB#\fP cd /etc
\fB#\fP cp \fIfstab.xxx\fP fstab
E 3
I 3
\fB#\fI cd /etc\fR
\fB#\fI cp \fIfstab.xxx\fP fstab\fR
E 3
.DE
.PP
D 2
This will set up the initial information about the usage of disk
E 2
I 2
This will set up the default information about the usage of disk
E 2
partitions, which we see how to update more below.
I 3
.\}
.if \n(Th \{\
The names of the disks on \*(4B all use the basename \fIdk\fP,
unlike other systems on the Tahoe.
Unfortunately, the console processor reads the file \fI/etc/fstab\fP
and expects disk names that indicate the type of disk drive.
Therefore, the first line in \fI/etc/fstab\fP is a dummy line
to satisfy the console processor:
.DS
/dev/fsd0a:/:xx:1:1
.DE
If your root disk is a type other than \fIfsd\fP,
edit \fI/etc/fstab\fP to change the first device
to the appropriate type.
.\}
E 3
.NH 3
Disk naming and divisions
.PP
Each physical disk drive can be divided into up to 8 partitions;
D 3
UNIX typically
uses only 3 or 4 partitions.
For instance, on an RM03
or RP06, the first partition, hp0a,
E 3
I 3
UNIX typically uses only 3 or 4 partitions.
For instance, on an \*(Dn,
the first partition, \*(Dk0a,
E 3
is used for a root file system, a backup thereof,
or a small file system like, /tmp;
D 3
the second partition, hp0b,
E 3
I 3
the second partition, \*(Dk0b,
E 3
is used for paging and swapping; and
D 3
the third partition hp0g
holds a user file system.  On an RM05, the first three partitions
are used as for the RM03, and the fourth partition, hp0h,
E 3
I 3
the third partition, \*(Dk0\*(Pa,
holds a user file system.
.if \n(Vx \{\
On an RM05, the first three partitions
are used as for the \*(Dn, and the fourth partition, \*(Dk0h,
E 3
D 2
is used to hold the /usr file system, including source code.
E 2
I 2
holds the /usr file system, including source code.
I 3
.\}
.if !\n(Th \{\
E 3
E 2
.PP
The disk partition sizes for a drive are based on a
D 2
set of four default partition tables; c.f. \fIdiskpart\fP\|(8). 
E 2
I 2
set of four prototype partition tables; c.f. \fIdiskpart\fP\|(8). 
E 2
The particular
table used is dependent on the size of the drive.
The ``a'' partition is the same size across all drives,
15884 sectors.  The ``b'' partition, used for paging and
swapping, is sized according to the total space on the disk.
For drives less than about 400 megabytes the partition
is 33440 sectors, while for larger drives the partition size
is doubled to 66880 sectors.  The ``c'' partition is always
used to access the entire physical disk, including the space
at the back of the disk reserved for the bad sector
forwarding table.  If the disk is larger than about 250 megabytes,
an ``h'' partition is created with size 291346 sectors, and
no matter whether the ``h'' partition is created or not, the
remainder of the drive is allocated to the ``g'' partition.
D 2
Sites which want to split up the ``g'' partition into a number
of smaller file systems may use the ``d'', ``e'', and ``f''
partitions which overlap the ``g'' partition.  The default
E 2
I 2
Sites that want to split up the ``g'' partition into several
smaller file systems may use the ``d'', ``e'', and ``f''
partitions that overlap the ``g'' partition.  The default
E 2
sizes for these partitions are 15884, 55936, and the remainder
of the disk, respectively*.
.FS
D 3
* These rules are, unfortunately not evenly applied to all
disks.  Drives on DEC UDA50 and IDC controllers do not
completely follow these rules;
D 2
in particular, the swap partition on an RA81 is only 33440 sectors,
and no ``d'', ``e'', or ``f'' partitions are available on an RA60
or RA80.  Consult \fIuda\fP\|(4) for more information.
E 2
I 2
in particular,
no ``d'', ``e'', or ``f'' partitions are available on an
RA60 and RA80.  Consult \fIuda\fP\|(4) for more information.
E 3
I 3
* These rules are, unfortunately, not evenly applied to all
disks.  \fI/etc/disktab\fP, and the pack label or driver tables,
give the final word; consult section 4 of the manual, and
read /etc/disktab, for more information.
E 3
E 2
.FE
D 2
.NH 3
Space available
E 2
.PP
I 2
The disk partition sizes for DEC RA60, RA80, and RA81 have
changed since 4.2BSD.  If upgrading from 4.2BSD,
you will need to decide if you want
to use the new partitions or the old partitions.  If you 
D 3
desire to use the old partitions, you will need to update
/etc/disktab and the device driver for the UDA50.  Any
other partition sizes that were modified at your site, will
require the same consideration.
E 3
I 3
desire to use the old partitions, you will need to label your packs
as `racompat', or create your own by updating
/etc/disktab.  Any
other partition sizes that were modified at your site will
require the same consideration;
if the device driver does not support pack labels, you will have to
update its compiled-in tables as well.
.\}
E 3
.PP
E 2
The space available on a disk varies per device.  The amount of space
available on the common disk partitions is listed in the following table.
Not shown in the table are the partitions of each drive devoted
to the root file system and the paging area.
I 3
Many other partitions are listed in the standard partitions,
but most of them are not useful.
Note that the standard partition tables usually list several alternative
ways to divide a disk, but that only nonoverlapping partitions may be used
on any one disk.
I 7
.if \n(Vx \{\
E 7
E 3
.DS
.TS
center;
l l n l n.
Type	Name	Size	Name	Size
_
I 3
D 7
.if \n(Vx \{\
E 7
E 3
rk07	hk?g	13 Mb
rm03	hp?g	41 Mb
rp06	hp?g	145 Mb
rm05	hp?g	80 Mb	hp?h	145 Mb
rm80	hp?g	96 Mb
D 2
ra60	ra?g	41 Mb	ra?h	139 Mb
ra80	ra?g	41 Mb	ra?h	56 Mb
ra81	ra?g	41 Mb	ra?h	380 Mb
E 2
I 2
ra60	ra?g	78 Mb	ra?h	96 Mb
ra80	ra?g	96 Mb
ra81	ra?g	257 Mb	ra?h	145 Mb
E 2
rb80	rb?g	41 Mb	rb?h	56 Mb
rp07	hp?g	315 Mb	hp?h	145 Mb
up300	up?g	80 Mb	up?h	145 Mb
D 2
hp400	hp?g	216 Mb	hp?h	145 Mb
E 2
I 2
up330	up?g	90 Mb	up?h	145 Mb
up400	hp?g	216 Mb	hp?h	145 Mb
E 2
up160	up?g	106 Mb
I 7
.TE
.DE
E 7
I 3
.\}
.if \n(Th \{\
I 7
.DS
.TS
center;
l l n l n.
Type	Name	Size	Name	Size
_
E 7
xfd	dk?c	225 Mb	dk?g,h	112 Mb
eagle	dk?c	301 Mb
fsd	dk?c	106 Mb
D 7
.\}
E 7
E 3
.TE
.DE
I 7
.\}
E 7
I 3
.if \n(Vx \{\
E 3
.LP
D 3
Here up300 refers to either an AMPEX or CDC 300 Megabyte disk on a
E 3
I 3
Here up300 refers to either an AMPEX or CDC 300 megabyte disk on a
E 3
D 2
UNIBUS disk controller, up160 refers to a FUJITSU 160 Megabyte disk
on the UNIBUS, and hp400 refers to a FUJITSU Eagle 400 Megabyte
disk on a MASBUS disk controller.
E 2
I 2
MASSBUS or UNIBUS disk controller, up330 refers to either an AMPEX
D 3
or FUJITSU 330 Megabyte disk on a MASSBUS or UNIBUS controller,
up160 refers to a FUJITSU 160 Megabyte disk
on the UNIBUS, and up400 refers to a FUJITSU Eagle 400 Megabyte
E 3
I 3
or FUJITSU 330 megabyte disk on a MASSBUS or UNIBUS controller,
up160 refers to a FUJITSU 160 megabyte disk
on the UNIBUS, and up400 refers to a FUJITSU Eagle 400 megabyte
E 3
disk on a MASBUS or UNIBUS disk controller.  ``hp'' should be
substituted for ``up'' above if the disk is on the MASSBUS.
E 2
Consult the manual pages for the specific controllers for other
supported disks or other partitions.
.PP
D 3
Each disk also has a paging area, typically of 16 Megabytes, and
D 2
a root file sytem of 8 Megabytes.
The distributed system binaries occupy about 22 Megabytes
while the major sources occupy another 25 Megabytes.
This overflows dual RK07 and dual RL02 systems,
E 2
I 2
a root file system of 8 Megabytes.
The distributed system binaries occupy about 34 Megabytes
while the major sources occupy another 32 Megabytes.
E 3
I 3
Each disk also has a paging area, typically 16 megabytes, and
a root file system of 7.5 megabytes.
.\}
.if \n(Th \{\
.PP
Each disk also has a paging area and a root file system of between 10 and 30
Megabytes apiece.
.\}
.\" XXX check
The distributed system binaries occupy about 34 megabytes
.\" XXX check
while the major sources occupy another 32 megabytes.
.if \n(Vx \{\
E 3
This overflows dual RK07, dual RL02 and single RM03 systems,
E 2
but fits easily on most other hardware configurations.
I 3
.\}
.if \n(Th \{\
This is unlikely to
overflow even the smallest Tahoe configurations.
.\}
E 3
.PP
Be aware that the disks have their sizes
D 3
measured in disk sectors (512 bytes), while the UNIX file
E 3
I 3
measured in disk sectors (usually 512 bytes), while the UNIX file
E 3
system blocks are variable sized.  All user programs report
disk space in kilobytes and, where needed, disk sizes are always
D 2
specified in terms of
E 2
I 2
specified in units of
E 2
D 3
sectors.  The /etc/disktab file used in making file systems
E 3
I 3
sectors.  The /etc/disktab file used in labelling disks and making file systems
E 3
specifies disk partition sizes in sectors; the default sector size
D 2
of 512 bytes may be overridden with the ``se'' attribute.
E 2
I 2
D 3
may be overridden with the ``se'' attribute.  Note that the only
sector size currently supported is DEV_BSIZE as defined in 
\fI/sys/h/param.h\fP.
E 3
I 3
(DEV_BSIZE as defined in /sys/h/param.h)
may be overridden with the ``se'' attribute.
.if \n(Th \{\
All SMD disks on Tahoe currently use a sector size of 512 bytes.
.\}
E 3
E 2
.NH 3
Layout considerations
.PP
There are several considerations in deciding how
D 2
to adjust the arrangement of things on your disks:
the most important is making sure there is adequate space
E 2
I 2
to adjust the arrangement of things on your disks.
The most important is making sure that there is adequate space
E 2
for what is required; secondarily, throughput should be maximized.
Paging space is an important parameter.
The system, as distributed, sizes the configured
paging areas each time the system is booted.  Further,
multiple paging areas of different size may be interleaved.
I 3
.if \n(Vx \{\
E 3
Drives smaller than 400 megabytes have swap partitions of 16 megabytes
while drives larger than 400 megabytes have 32 megabytes.  These
values may be changed to get more paging space by changing
D 3
the appropriate partition table in the disk driver.
E 3
I 3
the label (or, if labels are unsupported,
the appropriate partition table in the disk driver).
.\}
E 3
.PP
Many common system programs (C, the editor, the assembler etc.)
create intermediate files in the /tmp directory,
so the file system where this is stored also should be made
large enough to accommodate
most high-water marks; if you have several disks, it makes
sense to mount this in a ``root'' (i.e. first partition)
file system on another disk.
All the programs that create files in /tmp take
care to delete them, but are not immune to rare events
and can leave dregs.
The directory should be examined every so often and the old
files deleted.
.PP
The efficiency with which UNIX is able to use the CPU
is often strongly affected by the configuration of disk controllers.
For general time-sharing applications,
the best strategy is to try to split the root file system (/), system binaries
(/usr), the temporary files (/tmp),
and the user files among several disk arms, and to interleave
D 2
the paging activity among a several arms.
E 2
I 2
the paging activity among several arms.
E 2
.PP
It is critical for good performance to balance disk load.
There are at least five components of the disk load that you can
divide between the available disks:
.DS
1. The root file system.
2. The /tmp file system.
3. The /usr file system.
4. The user files.
5. The paging activity.
.DE
The following possibilities are ones we have used at times
when we had 2, 3 and 4 disks:
.TS
center doublebox;
l | c s s
l | lw(5) | lw(5) | lw(5).
	disks
what	2	3	4
_
D 2
/	1	2	2
tmp	1	3	4
E 2
I 2
/	0	0	0
tmp	1	2	3
E 2
usr	1	1	1
D 2
paging	1+2	1+3	1+3+4
users	2	2+3	2+3
archive	x	x	4
E 2
I 2
paging	0+1	0+2	0+2+3
users	0	0+2	0+2
archive	x	x	3
E 2
.TE
.PP
The most important things to consider are to
even out the disk load as much as possible, and to do this by
decoupling file systems (on separate arms) between which heavy copying occurs.
D 2
Note that a long term average balanced load is not important... it is
much more important to have instantaneously balanced
E 2
I 2
Note that a long term average balanced load is not important; it is
much more important to have an instantaneously balanced
E 2
load when the system is busy.
.PP
Intelligent experimentation with a few file system arrangements can
pay off in much improved performance.  It is particularly easy to
move the root, the
/tmp
file system and the paging areas.  Place the
user files and the
/usr
directory as space needs dictate and experiment
with the other, more easily moved file systems.
.NH 3
File system parameters
.PP
Each file system is parameterized according to its block size,
fragment size, and the disk geometry characteristics of the
medium on which it resides.  Inaccurate specification of the disk
characteristics or haphazard choice of the file system parameters
can result in substantial throughput degradation or significant
waste of disk space.  As distributed,
file systems are configured according to the following table.
.DS
.TS
center;
l l l.
File system	Block size	Fragment size
_
D 3
/	8 Kbytes	1 Kbytes
usr	4 Kbytes	512 bytes
users	4 Kbytes	1 Kbytes
E 3
I 3
/	8 kbytes	1 kbytes
D 4
usr	4 kbytes	512 bytes
E 4
I 4
usr	4 kbytes	1 kbytes
E 4
users	4 kbytes	1 kbytes
E 3
.TE
.DE
.PP
The root file system block size is
made large to optimize bandwidth to the associated
disk;  this is particularly important since the
D 2
/tmp directory is normally part of the root file.
E 2
I 2
/tmp directory is normally part of the root file or a similar filesystem.
E 2
The large block size is also
important as many of the most heavily used programs
are demand paged out of the /bin directory.  The
D 3
fragment size of 1 Kbytes is a ``nominal'' value to use
with a file system.  With a 1 Kbyte fragment size
E 3
I 3
fragment size of 1 kbyte is a ``nominal'' value to use
with a file system.  With a 1 kbyte fragment size
E 3
D 2
disk space utilization is approximately the same
E 2
I 2
disk space utilization is about the same
E 2
as with the earlier versions of the file system.
.PP
D 3
The usr file system uses a 4 Kbyte block size
E 3
I 3
D 4
The usr file system uses a 4 kbyte block size
E 3
with 512 byte fragment size in an effort to get
high performance while conserving the amount of
space wasted by a large fragment size.  Space compaction
E 4
I 4
The usr file system would like to use a 4 kbyte block size
with 512 byte fragment size in an effort to get high performance
while conserving the amount of space wasted by a large fragment
size.  However, the tahoe disk controllers require a minimum
block size of 1 Kbyte.  Space compaction
E 4
has been deemed important here because the source code
for the system is normally placed on this file system.
I 2
If the source code is placed on a separate filesystem,
D 3
use of an 8 Kbyte block size with 1 Kbyte fragments might
E 3
I 3
use of an 8 kbyte block size with 1 kbyte fragments might
E 3
be considered for improved performance when paging from \fI/usr\fP binaries.
E 2
.PP
D 3
The file systems for users have a 4 Kbyte block
size with 1 Kbyte fragment size.  These parameters
E 3
I 3
The file systems for users have a 4 kbyte block
size with 1 kbyte fragment size.  These parameters
E 3
have been selected based on observations of the
D 3
performance of our user file systems.  The 4 Kbyte
E 3
I 3
performance of our user file systems.  The 4 kbyte
E 3
block size provides adequate bandwidth while the
D 3
1 Kbyte fragment size provides acceptable space compaction
E 3
I 3
1 kbyte fragment size provides acceptable space compaction
E 3
and disk fragmentation.
.PP
Other parameters may be chosen in constructing file
systems, but the factors involved in choosing a block
size and fragment size are many and interact in complex
ways.  Larger block sizes result in better
throughput to large files in the file system as
D 2
larger i/o requests will then be performed by the
E 2
I 2
larger I/O requests will then be performed by the
E 2
system.  However,
consideration must be given to the average file sizes
found in the file system and the performance of the
internal system buffer cache.   The system
currently provides space in the inode for
12 direct block pointers, 1 single indirect block
pointer, and 1 double indirect block pointer.*
.FS
* A triple indirect block pointer is also reserved, but
not currently supported.
.FE
If a file uses only direct blocks, access time to
it will be optimized by maximizing the block size.
If a file spills over into an indirect block,
increasing the block size of the file system may
decrease the amount of space used
by eliminating the need to allocate an indirect block.
However, if the block size is increased and an indirect
block is still required, then more disk space will be
used by the file because indirect blocks are allocated
according to the block size of the file system. 
.PP
In selecting a fragment size for a file system, at least
two considerations should be given.  The major performance
D 3
tradeoffs observed are between an 8 Kbyte block file system
D 2
and a 4 Kbyte block file system.  Due to implementation
E 2
I 2
and a 4 Kbyte block file system.  Because of implementation
E 3
I 3
tradeoffs observed are between an 8 kbyte block file system
and a 4 kbyte block file system.  Because of implementation
E 3
E 2
constraints, the block size / fragment size ratio can not
D 3
be greater than 8.  This means that an 8 Kbyte file system
will always have a fragment size of at least 1 Kbytes.  If
a file system is created with a 4 Kbyte block size and a
1 Kbyte fragment size, then upgraded to an 8 Kbyte block size
and 1 Kbyte fragment size, identical space compaction will be
observed.  However, if a file system has a 4 Kbyte block size
E 3
I 3
be greater than 8.  This means that an 8 kbyte file system
will always have a fragment size of at least 1 kbytes.  If
a file system is created with a 4 kbyte block size and a
1 kbyte fragment size, then upgraded to an 8 kbyte block size
and 1 kbyte fragment size, identical space compaction will be
observed.  However, if a file system has a 4 kbyte block size
E 3
and 512 byte fragment size, converting it to an 8K/1K
file system will result in significantly more space being
D 2
used.  This implies that 4 Kbyte block file systems which
E 2
I 2
D 3
used.  This implies that 4 Kbyte block file systems that
E 2
might be upgraded to 8 Kbyte blocks for higher performance should
use fragment sizes of at least 1 Kbytes to minimize the amount
E 3
I 3
used.  This implies that 4 kbyte block file systems that
might be upgraded to 8 kbyte blocks for higher performance should
use fragment sizes of at least 1 kbytes to minimize the amount
E 3
of work required in conversion.
.PP
A second, more important, consideration when selecting the
fragment size for a file system is the level of fragmentation 
D 4
on the disk.  With a 512 byte fragment size, storage fragmentation
E 4
I 4
on the disk.  With an 8:1 fragment to block ratio, storage fragmentation
E 4
occurs much sooner, particularly with a busy file system running
near full capacity.  By comparison, the level of fragmentation in a 
D 2
1 Kbyte fragment file system is an order of magnitude less severe.  This
E 2
I 2
D 3
1 Kbyte fragment file system is one tenth as severe.  This
E 3
I 3
D 4
1 kbyte fragment file system is one tenth as severe.  This
E 4
I 4
4:1 fragment to block ratio file system is one tenth as severe.  This
E 4
E 3
E 2
means that on file systems where many files are created and
D 2
deleted the 512 byte fragment size is more likely to result in apparent
space exhaustion due to fragmentation.  That is, when the file 
system is nearly full, file expansion which requires locating a
E 2
I 2
deleted, the 512 byte fragment size is more likely to result in apparent
space exhaustion because of fragmentation.  That is, when the file 
system is nearly full, file expansion that requires locating a
E 2
contiguous area of disk space is more likely to fail on a 512
D 3
byte file system than on a 1 Kbyte file system.  To minimize
E 3
I 3
byte file system than on a 1 kbyte file system.  To minimize
E 3
fragmentation problems of this sort, a parameter in the super
D 2
block specifies a minimum acceptable free space threshhold.  When
E 2
I 2
block specifies a minimum acceptable free space threshold.  When
E 2
normal users (i.e. anyone but the super-user) attempt to allocate
disk space and the free space threshold is exceeded, the user is
D 2
returned an error as if the file system were actually full.  This
E 2
I 2
returned an error as if the file system were really full.  This
E 2
parameter is nominally set to 10%; it may be changed by supplying
D 2
a parameter to \fInewfs\fP, or by patching the super block of an
existing file system.
E 2
I 2
D 3
a parameter to \fInewfs\fP, or by updating the super block of an
E 3
I 3
a parameter to \fInewfs\fP(8), or by updating the super block of an
E 3
existing file system using \fItunefs\fP\|(8).
E 2
.PP
In general, unless a file system is to be used
for a special purpose application (for example, storing
D 2
image processing data), we recommend using the default
values supplied.  
E 2
I 2
image processing data), we recommend using the
values supplied above.
E 2
Remember that the current
D 3
implementation limits the block size to at most 8 Kbytes
E 3
I 3
implementation limits the block size to at most 8 kbytes
E 3
D 2
and the ratio of block size / fragment size must be in
the range 1-8.
E 2
I 2
and the ratio of block size / fragment size must be 1, 2, 4, or 8.
E 2
.PP
The disk geometry information used by the file system
affects the block layout policies employed.  The file
/etc/disktab, as supplied, contains the data for most
D 3
all drives supported by the system.  When constructing
a file system you should use the \fInewfs\fP\|(8) program
and specify the type of disk on which the file system
resides.  This file also contains the default
E 3
I 3
all drives supported by the system.  Before constructing
a file system with \fInewfs\fP\|(8)
you should label the disk (if it has not yet been labeled,
and the driver supports labels).
If labels cannot be used, you must instead
specify the type of disk on which the file system resides;
\fInewfs\fP then reads /etc/disktab instead of the pack label.
This file also contains the default
E 3
file system partition
sizes, and default block and fragment sizes.  To
D 3
override any of the default values you can modify the file
E 3
I 3
override any of the default values you can modify the file,
edit the disk label,
E 3
D 2
or use one of the options to \fInewfs\fP.
E 2
I 2
or use an option to \fInewfs\fP.
E 2
.NH 3
Implementing a layout
.PP
To put a chosen disk layout into effect, you should use the
.IR newfs (8)
command to create each new file system.
Each file system must also be added to the file
/etc/fstab
so that it will be checked and mounted when the system is bootstrapped.
.PP
D 2
As an example, consider a system with rm03's.  On the first rm03, hp0,
E 2
I 2
D 3
As an example, consider a system with RM80's.  On the first RM80, hp0,
E 2
we will put the root file system in hp0a, and the /usr
file system in hp0g, which has enough space to hold it and then some.
E 3
I 3
As an example, consider a system with \*(Dn's.  On the first \*(Dn, \*(Dk0,
we will put the root file system in \*(Dk0a, and the /usr
file system in \*(Dk0\*(pa, which has enough space to hold it and then some.
E 3
The /tmp directory will be part of the root file system,
as no file system will be mounted on /tmp.
D 2
If we had only one rm03, we would put user files
E 2
I 2
D 3
If we had only one RM80, we would put user files
E 2
in the hp0g partition with the system source and binaries.
E 3
I 3
If we had only one \*(Dn, we would put user files
in the \*(Dk0\*(pa partition with the system source and binaries.
E 3
.PP
D 2
If we had a second rm03, we would create a file system in hp1g
and put user files there, calling the file system /mnt.
E 2
I 2
D 3
If we had a second RM80, we would place \fI/usr\fP in hp1g.
We would put user files in hp0g, calling the file system /mnt.
E 3
I 3
If we had a second \*(Dn, we would place \fI/usr\fP in \*(Dk1\*(Pa.
We would put user files in \*(Dk0g, calling the file system /a.
E 3
E 2
We would also interleave the paging
D 2
between the 2 rm03's.  To do this we would build a system configuration
E 2
I 2
D 3
between the 2 RM80's.  To do this we would build a system configuration
E 3
I 3
between the 2 \*(Dn's.  To do this we would build a system configuration
E 3
E 2
that specified:
.DS
D 3
config	vmunix	root on hp0 swap on hp0 and hp1
E 3
I 3
config	vmunix	root on \*(Dk0 swap on \*(Dk0 and \*(Dk1
E 3
.DE
D 2
to get the swap interleaved, and add the lines
E 2
I 2
D 3
to get the swap interleaved, and \fI/etc/fstab would then contain
E 3
I 3
to get the swap interleaved, and \fI/etc/fstab\fP would then contain
E 3
E 2
.DS
I 2
D 3
/dev/hp0a:/:rw:1:1
/dev/hp0b::sw::
/dev/hp0g:/mnt:rw:1:2
E 2
/dev/hp1b::sw::
D 2
/dev/hp1g:/mnt:rw:1:2
E 2
I 2
/dev/hp1g:/usr:rw:1:2
E 3
I 3
/dev/\*(Dk0a:/:rw:1:1
/dev/\*(Dk0b::sw::
/dev/\*(Dk0g:/a:rw:1:2
/dev/\*(Dk1b::sw::
/dev/\*(Dk1g:/usr:rw:1:2
E 3
E 2
.DE
D 2
to the /etc/fstab file.  We would keep a backup copy of the root
E 2
I 2
We would keep a backup copy of the root
E 2
D 3
file system in the \fBhp1a\fP disk partition.
E 3
I 3
file system in the \fB\*(Dk1a\fP disk partition.
E 3
I 2
Alternatively, that partition could be used for \fI/tmp\fP.
E 2
.PP
D 3
To make the /mnt file system we would do:
E 3
I 3
To make the /a file system we would do:
.if \n(Th \{\
.ds Dn eagle
.\}
E 3
.DS
D 3
\fB#\fP cd /dev
\fB#\fP MAKEDEV hp1
D 2
\fB#\fP newfs hp1g rm03
E 2
I 2
\fB#\fP newfs hp1g rm80
E 3
I 3
\fB#\fP \fIcd /dev\fP
\fB#\fP \fIMAKEDEV \*(Dk1\fP
\fB#\fP \fIdisklabel -wr \*(Dk1 \*(Dn "disk name"\fP
\fB#\fP \fInewfs \*(Dk1\*(Pa\fP
E 3
E 2
(information about file system prints out)
D 3
\fB#\fP mkdir /mnt
\fB#\fP mount /dev/hp1g /mnt
E 3
I 3
\fB#\fP \fImkdir /a\fP
\fB#\fP \fImount /dev/\*(Dk1\*(Pa /a\fP
E 3
.DE
.NH 2
Configuring terminals
.PP
If UNIX is to support simultaneous
D 2
access from more than just the console terminal,
the file /etc/ttys (\fIttys\fP\|(5)) has to be edited.
E 2
I 2
access from directly-connected terminals other than the console,
the file \fI/etc/ttys\fP (\fIttys\fP\|(5)) must be edited.
I 3
.if \n(Vx \{\
E 3
E 2
.PP
D 2
Terminals connected via dz interfaces are conventionally named \fBttyDD\fP
E 2
I 2
Terminals connected via DZ11 interfaces are conventionally named \fBttyDD\fP
E 2
where DD is a decimal number, the ``minor device'' number.
The lines on dz0 are named /dev/tty00, /dev/tty01, ... /dev/tty07.
D 2
Lines on dh or dmf interfaces are conventionally named \fBttyh\fPX, where X
is a hexadecimal digit.  If more than one dh or dmf interface is present
in a configuration, successive terminals would be named
\fBttyi\fPX, \fBttyj\fPX, etc.
.PP
To add a new terminal, be sure the device is configured into the system
and that the special file for the device has been made by /dev/MAKEDEV.
Then, set the first character of the appropriate line of /etc/ttys to 1
(or add a new line).
.PP
The second character of each line in the /etc/ttys file lists
the speed and initial parameter settings for the terminal.
The commonly used choices are:
E 2
I 2
By convention, all other terminal names are of the form \fBtty\fPCX, where
C is an alphabetic character according to the type of terminal multiplexor
and its unit number,
and X is a digit for the first ten lines on the interface
and an increasing lower case letter for the rest of the lines.
C is defined for the number of interfaces of each type listed below.
E 2
.DS
D 2
0	300-1200-150-110
2	9600
3	1200-300
5	300-1200
E 2
I 2
.TS
center box;
c c c c
c c c c
l c n n.
Interface		Number of lines	Number of
Type	Characters	per board	Interfaces
_
DZ11	see above	8	10
DMF32	A-C,E-I	8	8
DMZ32	a-c,e-g	24	6
DH11	h-o	16	8
DHU11	S-Z	16	8
pty	p-u	16	6
.TE
E 2
.DE
I 3
.\}
.if \n(Th \{\
E 3
D 2
Here the first speed is the speed a terminal starts at, and
``break'' switches speeds.
E 2
I 2
.PP
I 3
Terminals connected via VIOC-X interfaces are conventionally named tty\fIDD\fP
where \fIDD\fP is a hexadecimal number, the ``minor device'' number.
The first digit is the multiplexor unit number, and the second digit
is the line number.
For VIOC's with fewer than 16 connectors, the missing unit numbers are unused.
I 5
.PP
Terminals connected using 16 port MPCC interfaces are conventionally named
tty\fICD\fP where \fIC\fP is a single upper-case letter and \fID\fP is a
single hexidecimal digit.  The upper-case letter is the multiplexor unit
number (with \fIA\fP being mpcc 0) and the hexidecimal digit is the port
number on that unit.
E 5
.\}
.PP
E 3
To add a new terminal device, be sure the device is configured into the system
and that the special files for the device have been made by /dev/MAKEDEV.
I 3
.if \n(Vx \{\
(For example, use ``cd /dev; MAKEDEV dz1'' to make the special files
for the second DZ11.)
.\}
.if \n(Th \{\
(For example, use ``cd /dev; MAKEDEV vx1'' to make the special files
for the second VIOC.)
.\}
E 3
Then, enable the appropriate lines of /etc/ttys by setting the ``status''
field to \fBon\fP (or add new lines).
Note that lines in \fI/etc/ttys\fP are one-for-one with entries
in the file of current users (\fI/etc/utmp\fP),
and therefore it is best to make changes
while running in single-user mode
and to add all of the entries for a new device at once.
I 5
.if \n(Th \{\
E 5
.PP
I 5
To add mpcc controllers, and additional step is required.  At boot time,
the firmware for each mpcc controller must be downloaded.  The program
\fI/etc/dlmpcc\fP must therefore be invoked from \fI/etc/rc.local\fP.
The file \fI/etc/mpcctab\fP describes each mpcc controller and is used
by \fI/etc/dlmpcc\fP to determine how many mpcc's are on the system.
See \fImpcc\fP(4) and \fIdlmpcc\fP(8) for more information.
.\}
.PP
E 5
D 3
The format of the /etc/ttys file is completely new in \*(4B.
E 3
I 3
The format of the /etc/ttys file is completely new in 4.3BSD.
E 3
Each line in the file is broken into four tab separated
fields (comments are shown by a `#' character and extend to
the end of the line).  For each terminal line the four fields
are:
the device (without a leading /dev),
the program /etc/init should startup to service the line
(or \fBnone\fP if the line is to be left alone),
the terminal type (found in /etc/termcap),
and optional status information describing if the terminal is
enabled or not and if it is ``secure'' (i.e. the super user should
be allowed to login on the line).  All fields are character strings
with entries requiring embedded white space enclosed in double
quotes.
E 2
Thus a newly added terminal /dev/tty00 could be added as
.DS
D 2
12tty00
E 2
I 2
tty00 	"/etc/getty std.9600"	vt100	on secure	# mike's office
E 2
.DE
D 2
if it was wired to run at 9600 baud.  The definition
of each ``terminal type'' is located in the file /etc/gettytab
and read by the 
.I getty
program.  To make custom terminal types, consult 
E 2
I 2
The std.9600 parameter provided
to /etc/getty is used in searching the file /etc/gettytab; it specifies
a terminal's characteristics (such as baud rate).
To make custom terminal types, consult 
E 2
.IR gettytab (5)
D 2
before modifying this file.
E 2
I 2
before modifying /etc/gettytab.
E 2
.PP
Dialup terminals should be wired so that carrier is asserted only when the
phone line is dialed up.
D 5
For non-dialup terminals from which modem control
is not available, you must either wire back the signals so that
E 5
I 5
For non-dialup terminals, from which modem control is not available,
E 5
I 3
.if \n(Vx \{\
I 5
you must either wire back the signals so that
E 5
E 3
the carrier appears to always be present, or show in the system
D 2
configuration that carrier is to be assumed to be present.  See
E 2
I 2
configuration that carrier is to be assumed to be present
with \fIflags\fP for each terminal device.  See
E 2
.IR dh (4),
I 2
.IR dhu (4),
E 2
.IR dz (4),
I 2
.IR dmz (4),
E 2
and
.IR dmf (4)
for details.
I 3
.\}
.if \n(Th \{\
I 5
you must wire back the signals so that
E 5
the carrier appears to always be present.  For further details, see
.IR vx (4),
.IR mpcc (4),
and
.IR dlmpcc (8).
.\}
E 3
.PP
D 2
You should also edit the file
/etc/ttytype
placing the type of each new terminal there (see \fIttytype\fP\|(5)).
E 2
I 2
For network terminals (i.e. pseudo terminals), no program should
be started up on the lines.  Thus, the normal entry in /etc/ttys
would look like
.DS
ttyp0 	none	network
.DE
D 3
(Note the fourth field is not needed when here.)
E 3
I 3
(Note, the fourth field is not needed here.)
E 3
E 2
.PP
When the system is running multi-user, all terminals that are listed
D 2
in /etc/ttys having a 1 as the first character of
their line are enabled.  If, during normal operations, it is desired
E 2
I 2
D 5
in /etc/ttys as \fBon\fP have their line are enabled.
If, during normal operations, it is desired
E 5
I 5
in /etc/ttys as \fBon\fP have their line enabled.
If, during normal operations, you wish
E 5
E 2
to disable a terminal line, you can edit the file
/etc/ttys
D 2
and change the first character of the corresponding line to be a 0 and
E 2
I 2
to change the terminal's status to \fBoff\fP and
E 2
then send a hangup signal to the \fIinit\fP process, by doing
.DS
D 3
\fB#\fP kill \-1 1
E 3
I 3
\fB#\fP \fIkill \-1 1\fP
E 3
.DE
D 2
Terminals can similarly be enabled by changing the first character of a line
from a 0 to a 1 and sending a hangup signal to \fIinit\fP.
E 2
I 2
Terminals can similarly be enabled by changing the status field
from \fBoff\fP to \fBon\fP and sending a hangup signal to \fIinit\fP.
E 2
.PP
D 2
Note that several programs, /usr/src/etc/init.c and
/usr/src/etc/comsat.c in particular, will have to be
recompiled if there are to be more than 100 terminals.
Also note that if a special file is inaccessible when \fIinit\fP tries
to create a process for it, init will print a message on the console
E 2
I 2
Note that if a special file is inaccessible when \fIinit\fP tries
to create a process for it, init will log a message to the
system error logging process (/etc/syslogd)
E 2
and try to reopen the terminal every minute, reprinting the warning
D 2
message every 10 minutes.
E 2
I 2
message every 10 minutes.  Messages of this sort are normally
printed on the console, though other actions may occur depending
on the configuration information found in /etc/syslog.conf.
E 2
.PP
Finally note that you should change the names of any dialup
terminals to ttyd?
D 2
where ? is in [0-9a-f], as some programs use this property of the
E 2
I 2
where ? is in [0-9a-zA-Z], as some programs use this property of the
E 2
names to determine if a terminal is a dialup.
Shell commands to do this should be put in the /dev/MAKEDEV.local
script.
.PP
I 3
D 5
Also, lines in /etc/ttys are in one-to-one correspondence with entries
in the file of current users (/etc/utmp), and therefore it is best to make
changes while running in single-user mode, and to add all of the entries
for a new device at once.
.PP
E 5
E 3
While it is possible to use truly arbitrary strings for terminal names,
the accounting and noticeably the
\fIps\fP\|(1)
command make good use of the convention that tty names
(by default, and also after dialups are named as suggested above)
are distinct in the last 2 characters. 
Change this and you may be sorry later, as the heuristic
\fIps\fP\|(1)
D 5
uses based on these conventions will then break down and ps will
E 5
I 5
uses based on these conventions will then break down and \fIps\fP will
E 5
run MUCH slower.
.NH 2
Adding users
.PP
D 3
New users can be added to the system by adding a line to the
password file
/etc/passwd.
The procedure for adding a new user is described in
.IR adduser (8).
.PP
E 3
I 3
The procedure for adding a new user is described in \fIadduser\fP(8).
E 3
You should add accounts for the initial user community, giving
each a directory and a password, and putting users who will wish
to share software in the same groups.
.PP
D 2
A number of guest accounts have been provided on the distribution
system; these accounts are for people at Berkeley, DEC and at Bell Laboratories
E 2
I 2
Several guest accounts have been provided on the distribution
system; these accounts are for people at Berkeley, 
Bell Laboratories, and others
E 2
who have done major work on UNIX in the past.  You can delete these accounts,
or leave them on the system if you expect that these people would have
occasion to login as guests on your system.
.NH 2
Site tailoring
.PP
D 2
All programs which require the site's name, or some similar
E 2
I 2
All programs that require the site's name, or some similar
E 2
characteristic, obtain the information through system calls
or from files located in /etc.  Aside from parts of the
system related to the network, to tailor the system to your
site you must simply select a site name, then edit the file
.DS
D 3
/etc/rc.local
E 3
I 3
/etc/netstart
E 3
.DE
D 3
The first line in /etc/rc.local,
E 3
I 3
The first lines in /etc/netstart use a variable to set the hostname,
E 3
.DS
D 3
/bin/hostname \fImysitename\fP
E 3
I 3
hostname=\fImysitename\fP
/bin/hostname $hostname
E 3
.DE
D 3
defines the value returned by the 
E 3
I 3
to define the value returned by the 
E 3
.IR gethostname (2)
D 2
system call.  Programs such as
E 2
I 2
system call.  If you are running the name server, your site
name should be your fully qualified domain name.  Programs such as
E 2
.IR getty (8),
.IR mail (1),
.IR wall (1),
D 3
.IR uucp (1),
E 3
and
D 3
.IR who (1)
E 3
I 3
.IR uucp (1)
E 3
use this system call so that the binary images are site
independent.
.NH 2
Setting up the line printer system
.PP
The line printer system consists of at least
the following files and commands:
.DS
.TS
l l.
/usr/ucb/lpq	spooling queue examination program
/usr/ucb/lprm	program to delete jobs from a queue
/usr/ucb/lpr	program to enter a job in a printer queue
/etc/printcap	printer configuration and capability data base
/usr/lib/lpd	line printer daemon, scans spooling queues
/etc/lpc	line printer control program
I 2
/etc/hosts.lpd	list of host allowed to use the printers
E 2
.TE
.DE
.PP
The file /etc/printcap is a master data base describing line
printers directly attached to a machine and, also, printers
accessible across a network.  The manual page
.IR printcap (5)
describes the format of this data base and also
D 2
indicates the default values for such things as the directory
E 2
I 2
shows the default values for such things as the directory
E 2
in which spooling is performed.  The line printer system handles
multiple printers, multiple spooling queues, local and remote
D 2
printers, and also printers attached via serial lines which require
E 2
I 2
printers, and also printers attached via serial lines that require
E 2
line initialization such as the baud rate.  Raster output devices
such as a Varian or Versatec, and laser printers such as an Imagen,
are also supported by the line printer system.
.PP
Remote spooling via the network is handled with two spooling
queues, one on the local machine and one on the remote machine.
D 2
When a remote printer job is initiated with
E 2
I 2
When a remote printer job is started with
E 2
.IR lpr ,
the job is
queued locally and a daemon process created to oversee the
transfer of the job to the remote machine.  If the destination
machine is unreachable, the job will remain queued until it is
possible to transfer the files to the spooling queue on the
remote machine.  The
.I lpq 
program shows the contents of spool
queues on both the local and remote machines.
.PP
To configure your line printers, consult the printcap manual page
D 2
and the accompanying document, ``4.2BSD Line Printer Spooler Manual''.
E 2
I 2
D 3
and the accompanying document, ``\*(4B Line Printer Spooler Manual''.
E 3
I 3
and the accompanying document, ``4.3BSD Line Printer Spooler Manual''.
E 3
E 2
A call to the
.I lpd
program should be present in /etc/rc.
.NH 2
Setting up the mail system
.PP
The mail system consists of the following commands:
.DS
.TS
l l.
D 2
/bin/mail	old standard mail program (from 32/V)
/usr/ucb/mail	UCB mail program, described in mail(1)
E 2
I 2
D 3
/bin/mail	old standard mail program, \fIbinmail\fP\|(1)
E 3
I 3
/bin/mail	old standard mail program, described in \fIbinmail\fP\|(1)
E 3
/usr/ucb/mail	UCB mail program, described in \fImail\fP\|(1)
E 2
/usr/lib/sendmail	mail routing program
/usr/spool/mail	mail spooling directory
/usr/spool/secretmail	secure mail directory
/usr/bin/xsend	secure mail sender
/usr/bin/xget	secure mail receiver
/usr/lib/aliases	mail forwarding information
/usr/ucb/newaliases	command to rebuild binary forwarding database
/usr/ucb/biff	mail notification enabler
/etc/comsat	mail notification daemon
D 2
/etc/syslog	error message logger, used by sendmail
E 2
.TE
.DE
Mail is normally sent and received using the
.IR mail (1)
D 3
command, which provides a front-end to edit the messages sent
E 3
I 3
command (found in /usr/ucb/mail),
which provides a front-end to edit the messages sent
E 3
and received, and passes the messages to
.IR sendmail (8)
for routing.
The routing algorithm uses knowledge of the network name syntax,
aliasing and forwarding information, and network topology, as
defined in the configuration file /usr/lib/sendmail.cf, to
process each piece of mail.
D 2
Local mail is delivered by giving it to the program /usr/bin/mail
which adds it to the mailboxes in the directory /usr/spool/mail/\fIusername\fP,
E 2
I 2
Local mail is delivered by giving it to the program /bin/mail
that adds it to the mailboxes in the directory /usr/spool/mail/\fIusername\fP,
E 2
using a locking protocol to avoid problems with simultaneous updates.
After the mail is delivered, the local mail delivery daemon /etc/comsat
is notified, which in turn notifies
D 2
users who have issued a ``biff y'' command that mail has arrived.
E 2
I 2
users who have issued a ``\fIbiff\fP y'' command that mail has arrived.
E 2
.PP
Mail queued in the directory /usr/spool/mail is normally readable
D 2
only by the recipient.  To send mail which is secure against any possible
E 2
I 2
D 3
only by the recipient.  To send mail that is secure against any possible
E 2
perusal (except by a code-breaker) you should
use the secret mail facility,
which encrypts the mail so that no one can read it.
E 3
I 3
only by the recipient.  To send mail that is secure against perusal
(except by a code-breaker) you should use the secret mail facility,
which encrypts the mail.
E 3
.PP
D 2
To setup the mail facility you should read the instructions in the
E 2
I 2
To set up the mail facility you should read the instructions in the
E 2
file READ_ME in the directory /usr/src/usr.lib/sendmail and then adjust
the necessary configuration files.
You should also set up the file /usr/lib/aliases for your installation,
creating mail groups as appropriate.  Documents describing 
.IR sendmail 's
operation and installation are also included in the distribution.
.NH 3
D 2
Setting up a uucp connection
E 2
I 2
Setting up a UUCP connection
E 2
.PP
D 2
The version of \fIuucp\fP included in 4.2BSD is an
enhanced version of that originally distributed with 32/V*.
E 2
I 2
D 3
The version of \fIuucp\fP included in \*(4B is an
E 3
I 3
The version of \fIuucp\fP included in \*(4B is a greatly
E 3
enhanced version of the one originally distributed with 32/V*.
E 2
.FS
* The \fIuucp\fP included in this distribution is the result
of work by many people; we gratefully acknowledge their
contributions, but refrain from mentioning names in the 
interest of keeping this document current.
.FE
The enhancements include:
.IP \(bu 3
D 2
support for many auto call units
other than the DEC DN11,
E 2
I 2
support for many auto call units and dialers
in addition to the DEC DN11,
E 2
.IP \(bu 3
D 2
breakup of the spooling area into
multiple subdirectories,
E 2
I 2
breakup of the spooling area into multiple subdirectories,
E 2
.IP \(bu 3
addition of an \fIL.cmds\fP file to control the set
D 2
of commands which may be executed by a remote site,
E 2
I 2
of commands that may be executed by a remote site,
E 2
.IP \(bu 3
enhanced ``expect-send'' sequence capabilities when
logging in to a remote site,
.IP \(bu 3
new commands to be used in polling sites and
D 2
obtaining snap shots of \fIuucp\fP activity.
E 2
I 2
obtaining snap shots of \fIuucp\fP activity,
.IP \(bu 3
additional protocols for different communication media.
E 2
.LP
D 2
This section gives a brief overview of \fIuucp\fP and points
out the most important steps in its installation.
E 2
I 2
This section gives a brief overview of \fIuucp\fP
and points out the most important steps in its installation.
E 2
.PP
To connect two UNIX machines with a \fIuucp\fP network link using modems,
D 2
one site must have an automatic call unit and the other must have a
dialup port.  It is better if both sites have both.
E 2
I 2
one site must have an automatic call unit
and the other must have a dialup port.
It is better if both sites have both.
E 2
.PP
D 2
You should first read the paper in volume 2B of the Unix Programmers Manual:
``Uucp Implementation Description''.  It describes in detail the file
formats and conventions, and will give you a little context.
In addition, the document setup.tblms, located in the directory
/usr/src/usr.bin/uucp/UUAIDS, may be of use in tailoring the
software to your needs.
E 2
I 2
You should first read the paper in the UNIX System Manager's Manual:
``Uucp Implementation Description''.
It describes in detail the file formats and conventions,
and will give you a little context.
In addition,
the document ``setup.tblms'',
located in the directory /usr/src/usr.bin/uucp/UUAIDS,
may be of use in tailoring the software to your needs.
E 2
.PP
D 2
The \fIuucp\fP support is located in three major directories: /usr/bin,
/usr/lib/uucp, and /usr/spool/uucp.  User commands are kept in /usr/bin,
operational commands in /usr/lib/uucp, and /usr/spool/uucp is used as
a spooling area.  The commands in /usr/bin are:
E 2
I 2
The \fIuucp\fP support is located in three major directories:
/usr/bin,
/usr/lib/uucp,
and /usr/spool/uucp.
User commands are kept in /usr/bin,
operational commands in /usr/lib/uucp,
and /usr/spool/uucp is used as a spooling area.
The commands in /usr/bin are:
E 2
.DS
.TS
l l.
/usr/bin/uucp	file-copy command
/usr/bin/uux	remote execution command
/usr/bin/uusend	binary file transfer using mail
/usr/bin/uuencode	binary file encoder (for \fIuusend\fP)
/usr/bin/uudecode	binary file decoder (for \fIuusend\fP)
/usr/bin/uulog	scans session log files
/usr/bin/uusnap	gives a snap-shot of \fIuucp\fP activity
/usr/bin/uupoll	polls remote system until an answer is received
I 2
/usr/bin/uuname	prints a list of known uucp hosts
/usr/bin/uuq	gives information about the queue
E 2
.TE
.DE
The important files and commands in /usr/lib/uucp are:
.DS
.TS
l l.
D 2
/usr/lib/uucp/L-devices	list of dialers and hardwired lines
E 2
I 2
/usr/lib/uucp/L-devices	list of dialers and hard-wired lines
E 2
/usr/lib/uucp/L-dialcodes	dialcode abbreviations
I 2
/usr/lib/uucp/L.aliases	hostname aliases
E 2
/usr/lib/uucp/L.cmds	commands remote sites may execute
/usr/lib/uucp/L.sys	systems to communicate with, how to connect, and when
/usr/lib/uucp/SEQF	sequence numbering control file
/usr/lib/uucp/USERFILE	remote site pathname access specifications
D 2
/usr/lib/uucp/uuclean	cleans up garbage files in spool area
E 2
/usr/lib/uucp/uucico	\fIuucp\fP protocol daemon
I 2
/usr/lib/uucp/uuclean	cleans up garbage files in spool area
E 2
/usr/lib/uucp/uuxqt	\fIuucp\fP remote execution server
.TE
.DE
D 2
while the spooling area contains the following important
files and directories:
E 2
I 2
while the spooling area contains the following important files and directories:
E 2
.DS
.TS
l l.
/usr/spool/uucp/C.	directory for command, ``C.'' files
/usr/spool/uucp/D.	directory for data, ``D.'', files
/usr/spool/uucp/X.	directory for command execution, ``X.'', files
/usr/spool/uucp/D.\fImachine\fP	directory for local ``D.'' files
/usr/spool/uucp/D.\fImachine\fPX	directory for local ``X.'' files
/usr/spool/uucp/TM.	directory for temporary, ``TM.'', files
/usr/spool/uucp/LOGFILE	log file of \fIuucp\fP activity
/usr/spool/uucp/SYSLOG	log file of \fIuucp\fP file transfers
.TE
.DE
.PP
D 2
To install \fIuucp\fP on your system, start by
selecting a site name (less than
8 characters).  
A \fIuucp\fP account must be created in
the password file and a password set up.
Then, create the appropriate
spooling directories with mode
755 and owned by user \fIuucp\fP, group \fIdaemon\fP.
E 2
I 2
To install \fIuucp\fP on your system,
start by selecting a site name
(shorter than 14 characters).  
A \fIuucp\fP account must be created in the password file and a password set up.
Then,
create the appropriate spooling directories with mode 755
and owned by user \fIuucp\fP, group \fIdaemon\fP.
E 2
.PP
D 2
If you have an auto-call unit, the L.sys, L-dialcodes, and
L-devices files should be created.  The L.sys file should
contain the phone numbers and login sequences required to
establish a connection with a \fIuucp\fP daemon on another
machine.  For example, our L.sys file looks something like:
E 2
I 2
If you have an auto-call unit,
the L.sys, L-dialcodes, and L-devices files should be created.
The L.sys file should contain
the phone numbers and login sequences
required to establish a connection with a \fIuucp\fP daemon on another machine.
For example, our L.sys file looks something like:
E 2
.DS
adiron Any ACU 1200 out0123456789- ogin-EOT-ogin uucp
cbosg Never Slave 300
cbosgd Never Slave 300
chico Never Slave 1200 out2010123456
.DE
D 2
The first field is the name of a site, the second indicates when
the machine may be called, the third field specifies how the
host is connected (through an ACU, a hardwired line, etc.),
then comes the phone number to use in connecting through an
auto-call unit, and finally a login sequence.  The phone number
may contain common abbreviations which are defined in
the L-dialcodes file.  The device specification should refer to
devices specified in the L-devices file.  Indicating only ACU
causes the \fIuucp\fP daemon, \fIuucico\fP, to search for any
available auto-call unit in L-devices.  Our L-dialcodes file
is of the form:
E 2
I 2
The first field is the name of a site,
the second shows when the machine may be called,
the third field specifies how the host is connected
(through an ACU, a hard-wired line, etc.),
then comes the phone number to use in connecting through an auto-call unit,
and finally a login sequence.
The phone number
may contain common abbreviations that are defined in the L-dialcodes file.
The device specification should refer to devices
specified in the L-devices file.
Listing only ACU causes the \fIuucp\fP daemon, \fIuucico\fP,
to search for any available auto-call unit in L-devices.
Our L-dialcodes file is of the form:
E 2
.DS
ucb 2
out 9%
.DE
while our L-devices file is:
.DS
ACU cul0 unused 1200 ventel
.DE
Refer to the README file in the \fIuucp\fP source directory
for more information about installation.
.PP
As \fIuucp\fP operates it creates (and removes) many small
D 2
files in the directories underneath /usr/spool/uucp.  Sometimes
files are left undeleted; these are most easily purged with
the \fIuuclean\fP program.  The log files can grow without 
bound unless trimmed back; \fIuulog\fP is used to maintain
these files.  Many useful aids in maintaining your \fIuucp\fP
installation are included in a subdirectory UUAIDS beneath
/usr/src/usr.bin/uucp.  Peruse this directory and read the
``setup'' instructions also located there.
E 2
I 2
files in the directories underneath /usr/spool/uucp.
Sometimes files are left undeleted;
these are most easily purged with the \fIuuclean\fP program.
The log files can grow without bound unless trimmed back;
\fIuulog\fP maintains these files.
Many useful aids in maintaining your \fIuucp\fP installation
are included in a subdirectory UUAIDS beneath /usr/src/usr.bin/uucp.
Peruse this directory and read the ``setup'' instructions also located there.
E 2
E 1

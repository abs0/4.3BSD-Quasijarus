h52479
s 00052/00040/00363
d D 6.2 86/06/03 18:05:07 karels 3 2
c 4.3 version
e
s 00000/00000/00403
d D 6.1 86/05/25 16:38:48 mckusick 2 1
c 4.3BSD beta release document
e
s 00403/00000/00000
d D 5.1 86/05/25 16:38:41 mckusick 1 0
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
D 3
.ds LH "Building Systems With Config
.ds RH "Configuration File Syntax
.ds CF July 27, 1983
.LP
.nr H1 4
.nr H2 0
.ds CH "
.bp
.ds CH "\(hy \\n(PN \(hy
.LG
.B
.ce
4. CONFIGURATION FILE SYNTAX
.sp 2
.R
.NL
E 3
I 3
.\".ds RH "Configuration File Syntax
.ne 2i
.NH
CONFIGURATION FILE SYNTAX
E 3
.PP
In this section we consider the specific rules used in writing
a configuration file.  A complete grammar for the input language
can be found in Appendix A and may be of use if you should have
problems with syntax errors.
.PP
A configuration file is broken up into three logical pieces:
.IP \(bu 3
configuration parameters global to all system images 
specified in the configuration file,
.IP \(bu 3
parameters specific to each
system image to be generated, and
.IP \(bu 3
device specifications.
.NH 2
Global configuration parameters
.PP
The global configuration parameters are the type of machine,
cpu types, options, timezone, system identifier, and maximum users.
Each is specified with a separate line in the configuration file.
.IP "\fBmachine\fP \fItype\fP"
.br
The system is to run on the machine type specified.  No more than
one machine type can appear in the configuration file.  Legal values
are
.B vax
and
\fBsun\fP.
.IP "\fBcpu\fP ``\fItype\fP''"
.br
This system is to run on the cpu type specified.
More than one cpu type specification
can appear in a configuration file.
Legal types for a
.B vax
machine are
D 3
\fBVAX780\fP,\fBVAX750\fP,
E 3
I 3
\fBVAX8600\fP, \fBVAX780\fP, \fBVAX750\fP,
\fBVAX730\fP
E 3
and
D 3
\fBVAX730\fP.
E 3
I 3
\fBVAX630\fP (MicroVAX II).
The 8650 is listed as an 8600, the 785 as a 780, and a 725 as a 730.
E 3
.IP "\fBoptions\fP \fIoptionlist\fP"
.br
Compile the listed optional code into the system. 
Options in this list are separated by commas.
Possible options are listed at the top of the generic makefile.
A line of the form ``options FUNNY,HAHA'' generates global ``#define''s
\-DFUNNY \-DHAHA in the resultant makefile.
An option may be given a value by following its name with ``\fB=\fP'',
D 3
then the value enclosed in (double) quotes.  None of the standard options
use such a value.  The following options are currently in use:
COMPAT (include code for compatiblity with 4.1BSD binaries),
E 3
I 3
then the value enclosed in (double) quotes.
The following are major options are currently in use:
COMPAT (include code for compatibility with 4.1BSD binaries),
E 3
INET (Internet communication protocols),
D 3
PUP (support for a PUP raw interface),
E 3
I 3
NS (Xerox NS communication protocols),
E 3
and
QUOTA (enable disk quotas).
I 3
Other kernel options controlling system sizes and limits
are listed in Appendix D;
options for the network are found in Appendix E.
E 3
There are additional options which are associated with certain
peripheral devices; those are listed in the Synopsis section
of the manual page for the device.
I 3
.IP "\fBmakeoptions\fP \fIoptionlist\fP"
.br
Options that are used within the system makefile
and evaluated by
.I make
are listed as
.IR makeoptions .
Options are listed with their values with the form
``makeoptions name=value,name2=value2.''
The values must be enclosed in double quotes if they include numerals
or begin with a dash.
E 3
.IP "\fBtimezone\fP \fInumber\fP [ \fBdst\fP [ \fInumber\fP ] ]"
.br
D 3
Specifies the timezone you are in.  This is measured in the
E 3
I 3
Specifies the timezone used by the system.  This is measured in the
E 3
number of hours your timezone is west of GMT.  
EST is 5 hours west of GMT, PST is 8.  Negative numbers
indicate hours east of GMT. If you specify
\fBdst\fP, the system will operate under daylight savings time.
An optional integer or floating point number may be included
to specify a particular daylight saving time correction algorithm;
the default value is 1, indicating the United States.
Other values are: 2 (Australian style), 3 (Western European),
4 (Middle European), and 5 (Eastern European).  See
\fIgettimeofday\fP\|(2) and \fIctime\fP\|(3) for more information.
.IP "\fBident\fP \fIname\fP"
.br
This system is to be known as
.IR name .
This is usually a cute name like ERNIE (short for Ernie Co-Vax) or
VAXWELL (for Vaxwell Smart).
I 3
This value is defined for use in conditional compilation,
and is also used to locate an optional list of source files specific
to this system.
E 3
.IP "\fBmaxusers\fP \fInumber\fP"
.br
The maximum expected number of simultaneously active user on this system is
.IR number .
This number is used to size several system data structures.
.NH 2
System image parameters
.PP
Multiple bootable images may be specified in a single configuration
file.  The systems will have the same global configuration parameters
and devices, but the location of the root file system and other
system specific devices may be different.  A system image is specified
with a ``config'' line:
.IP
\fBconfig\fP\ \fIsysname\fP\ \fIconfig-clauses\fP
.LP
The
.I sysname
field is the name given to the loaded system image; almost everyone
names their standard system image ``vmunix''.  The configuration clauses
are one or more specifications indicating where the root file system
D 3
is located, how many paging devices there are and where they go.
E 3
I 3
is located and the number and location of paging devices.
E 3
The device used by the system to process argument lists during
.IR execve (2)
calls may also be specified, though in practice this is almost
always selected by
.I config
using one of its rules for selecting default locations for
system devices.
.PP
A configuration clause is one of the following
.IP
.nf
\fBroot\fP [ \fBon\fP ] \fIroot-device\fP
D 3
\fBswap\fP [ \fBon\fP ] \fIswap-device\fP [ \fBand\fP \fIswap-device\fP ]
E 3
I 3
\fBswap\fP [ \fBon\fP ] \fIswap-device\fP [ \fBand\fP \fIswap-device\fP ] ...
E 3
\fBdumps\fP [ \fBon\fP ] \fIdump-device\fP
\fBargs\fP [ \fBon\fP ] \fIarg-device\fP
.LP
(the ``on'' is optional.)  Multiple configuration clauses
are separated by white space; 
.I config
allows specifications to be continued across multiple lines
by beginning the continuation line with a tab character.
The ``root'' clause specifies where the root file system
is located, the ``swap'' clause indicates swapping and paging
area(s), the ``dumps'' clause can be used to force system dumps
to be taken on a particular device, and the ``args'' clause
can be used to specify that argument list processing for
.I execve
D 3
should be done on a particular disk.
E 3
I 3
should be done on a particular device.
E 3
.PP
The device names supplied in the clauses may be fully specified
as a device, unit, and file system partition; or underspecified
in which case
.I config
will use builtin rules to select default unit numbers and file
system partitions.  The defaulting rules are a bit complicated
as they are dependent on the overall system configuration.
For example, the swap area need not be specified at all if 
the root device is specified; in this case the swap area is
placed in the ``b'' partition of the same disk where the root
file system is located.  Appendix B contains a complete list
of the defaulting rules used in selecting system configuration
devices.
.PP
The device names are translated to the
appropriate major and minor device
numbers on a per-machine basis.  A file,
``/sys/conf/devices.machine'' (where ``machine''
is the machine type specified in the configuration file),
is used to map a device name to its major block device number.
The minor device number is calculated using the standard 
disk partitioning rules: on unit 0, partition ``a'' is minor device
0, partition ``b'' is minor device 1, and so on; for units
other than 0, add 8 times the unit number to get the minor
device.
.PP
If the default mapping of device name to major/minor device
number is incorrect for your configuration, it can be replaced
by an explicit specification of the major/minor device.
This is done by substituting
.IP
\fBmajor\fP \fIx\fP \fBminor\fP \fIy\fP
.LP
where the device name would normally be found.  For example,
.IP
.nf
\fBconfig\fP vmunix \fBroot\fP \fBon\fP \fBmajor\fP 99 \fBminor\fP 1
.fi
.PP
Normally, the areas configured for swap space are sized by the system
D 3
at boot time.  If a non-standard partition size is to be used for one
or more swap areas, this can also be specified.  To do this, the
E 3
I 3
at boot time.  If a non-standard size is to be used for one
or more swap areas (less than the full partition),
this can also be specified.  To do this, the
E 3
device name specified for a swap area should have a ``size''
specification appended.  For example,
.IP
.nf
\fBconfig\fP vmunix \fBroot\fP \fBon\fP hp0 \fBswap\fP \fBon\fP hp0b \fBsize\fP 1200
.fi
.LP
would force swapping to be done in partition ``b'' of ``hp0'' and
the swap partition size would be set to 1200 sectors.  A swap area
sized larger than the associated disk partition is trimmed to the
partition size.
.PP
To create a generic configuration, only the clause ``swap generic''
should be specified; any extra clauses will cause an error.
.NH 2
Device specifications
.PP
Each device attached to a machine must be specified
to
.I config
so that the system generated will know to probe for it during
the autoconfiguration process carried out at boot time.  Hardware
specified in the configuration need not actually be present on
the machine where the generated system is to be run.  Only the
hardware actually found at boot time will be used by the system.
.PP
The specification of hardware devices in the configuration file
parallels the interconnection hierarchy of the machine to be
D 3
configured.  On the VAX, this means a configuration file must
E 3
I 3
configured.  On the VAX, this means that a configuration file must
E 3
indicate what MASSBUS and UNIBUS adapters are present, and to
D 3
which \fInexi\fP they might be connected*. 
E 3
I 3
which \fInexi\fP they might be connected.* 
E 3
.FS
* While VAX-11/750's and VAX-11/730 do not actually have 
nexi, the system treats them as having 
.I "simulated nexi"
to simplify device configuration.
.FE
Similarly, devices
and controllers must be indicated as possibly being connected
to one or more adapters.  A device description may provide a
complete definition of the possible configuration parameters
or it may leave certain parameters undefined and make the system
probe for all the possible values.  The latter allows a single
device configuration list to match many possible physical
configurations.  For example, a disk may be indicated as present
at UNIBUS adapter 0, or at any UNIBUS adapter which the system
locates at boot time.  The latter scheme, termed 
.IR wildcarding ,
allows more flexibility in the physical configuration of a system;
if a disk must be moved around for some reason, the system will
still locate it at the alternate location.
.PP
A device specification takes one of the following forms:
.IP
.nf
\fBmaster\fP \fIdevice-name\fP \fIdevice-info\fP
\fBcontroller\fP \fIdevice-name\fP \fIdevice-info\fP [ \fIinterrupt-spec\fP ]
\fBdevice\fP \fIdevice-name\fP \fIdevice-info\fP \fIinterrupt-spec\fP
\fBdisk\fP \fIdevice-name\fP \fIdevice-info\fP
\fBtape\fP \fIdevice-name\fP \fIdevice-info\fP
.fi
.LP
A ``master'' is a MASSBUS tape controller; a ``controller'' is a
disk controller, a UNIBUS tape controller, a MASSBUS adapter, or
a UNIBUS adapter.  A ``device'' is an autonomous device which
connects directly to a UNIBUS adapter (as opposed to something
like a disk which connects through a disk controller).  ``Disk''
and ``tape'' identify disk drives and tape drives connected to
D 3
a ``controller'' or ``master''.
E 3
I 3
a ``controller'' or ``master.''
E 3
.PP
The
.I device-name
is one of the standard device names, as
indicated in section 4 of the UNIX Programmers Manual,
concatenated with the
.I logical
unit number to be assigned the device (the 
.I logical
unit number may be different than the
.I physical
unit number indicated on the front of something
like a disk; the
.I logical
unit number is used to refer to the UNIX device, not
the physical unit number).  For example, ``hp0'' is logical
unit 0 of a MASSBUS storage device, even though it might
be physical unit 3 on MASSBUS adapter 1.
.PP
The
.I device-info
clause specifies how the hardware is
connected in the interconnection hierarchy.  On the VAX,
UNIBUS and MASSBUS adapters are connected to the internal
system bus through
a \fInexus\fP.
Thus, one of the following
specifications would be used:
.IP
.ta 1.5i 2.5i 4.0i
.nf
\fBcontroller\fP	mba0	\fBat\fP \fBnexus\fP \fIx\fP
\fBcontroller\fP	uba0	\fBat\fP \fBnexus\fP \fIx\fP
.fi
.LP
To tie a controller to a specific nexus, ``x'' would be supplied
as the number of that nexus; otherwise ``x'' may be specified as
``?'', in which
case the system will probe all nexi present looking
for the specified controller.
.PP
The remaining interconnections on the VAX are:
.IP \(bu 3
a controller
may be connected to another controller (e.g. a disk controller attached
to a UNIBUS adapter),
.IP \(bu 3
D 3
a master is always attached to a controller (a MASSBUS adaptor),
E 3
I 3
a master is always attached to a controller (a MASSBUS adapter),
E 3
.IP \(bu 3
a tape is always attached to a master (for MASSBUS
tape drives),
.IP \(bu 3
a disk is always attached to a controller, and
.IP \(bu 3
devices
are always attached to controllers (e.g. UNIBUS controllers attached
to UNIBUS adapters).
.LP
The following lines give an example of each of these interconnections:
.IP
.ta 1.5i 2.5i 4.0i
.nf
\fBcontroller\fP	hk0	\fBat\fP uba0 ...
\fBmaster\fP	ht0	\fBat\fP mba0 ...
I 3
\fBdisk\fP	hp0	\fBat\fP mba0 ...
E 3
\fBtape\fP	tu0	\fBat\fP ht0 ...
\fBdisk\fP	rk1	\fBat\fP hk0 ...
\fBdevice\fP	dz0	\fBat\fP uba0 ...
.fi
.LP
Any piece of hardware which may be connected to a specific
controller may also be wildcarded across multiple controllers.
.PP
The final piece of information needed by the system to configure
devices is some indication of where or how a device will interrupt.
For tapes and disks, simply specifying the \fIslave\fP or \fIdrive\fP
number is sufficient to locate the control status register for the
D 3
device.  For controllers, the control status register must be
given explicitly, as well how many interrupt vectors are used and
E 3
I 3
device.
\fIDrive\fP numbers may be wildcarded
on MASSBUS devices, but not on disks on a UNIBUS controller.
For controllers, the control status register must be
given explicitly, as well the number of interrupt vectors used and
E 3
the names of the routines to which they should be bound. 
Thus the example lines given above might be completed as:
.IP
.ta 1.5i 2.5i 4.0i
.nf
\fBcontroller\fP	hk0	\fBat\fP uba0 \fBcsr\fP 0177440	\fBvector\fP rkintr
\fBmaster\fP	ht0	\fBat\fP mba0 \fBdrive\fP 0
I 3
\fBdisk\fP	hp0	\fBat\fP mba0 \fBdrive\fP ?
E 3
\fBtape\fP	tu0	\fBat\fP ht0 \fBslave\fP 0
\fBdisk\fP	rk1	\fBat\fP hk0 \fBdrive\fP 1
\fBdevice\fP	dz0	\fBat\fP uba0 \fBcsr\fP 0160100	\fBvector\fP dzrint dzxint
.fi
.PP
Certain device drivers require extra information passed to them
at boot time to tailor their operation to the actual hardware present.
The line printer driver, for example, needs to know how many columns
are present on each non-standard line printer (i.e. a line printer
with other than 80 columns).  The drivers for the terminal multiplexors
need to know which lines are attached to modem lines so that no one will
be allowed to use them unless a connection is present.  For this reason,
one last parameter may be specified to a
.IR device ,
a 
.I flags
field.  It has the syntax
.IP
\fBflags\fP \fInumber\fP
.LP
and is usually placed after the
.I csr
specification.  The
.I number
is passed directly to the associated driver.  The manual pages
in section 4 should be consulted to determine how each driver
uses this value (if at all).
Communications interface drivers commonly use the flags
to indicate whether modem control signals are in use.
.PP
The exact syntax for each specific device is given in the Synopsis
section of its manual page in section 4 of the manual.
.NH 2
Pseudo-devices
.PP
A number of drivers and software subsystems
are treated like device drivers without any associated hardware.
To include any of these pieces, a ``pseudo-device'' specification
must be used.  A specification for a pseudo device takes the form
.IP
.DT
.nf
\fBpseudo-device\fP	\fIdevice-name\fP [ \fIhowmany\fP ]
.fi
.PP
D 3
Examples of pseudo devices are \fBbk\fP, the Berknet line discipline,
E 3
I 3
Examples of pseudo devices are
E 3
\fBpty\fP, the pseudo terminal driver (where the optional
.I howmany
value indicates the number of pseudo terminals to configure, 32 default),
D 3
and \fBinet\fP, the DARPA Internet protocols (one must also specify INET
in the ``options'').
Other pseudo devices for the network include \fBloop\fP, the software loopback
interface, \fBimp\fP (required when a CSS or ACC imp is configured),
E 3
I 3
and \fBloop\fP, the software loopback network pseudo-interface.
Other pseudo devices for the network include
\fBimp\fP (required when a CSS or ACC imp is configured)
E 3
and \fBether\fP (used by the Address Resolution Protocol
D 3
on 10 Mb/sec ethernets).
E 3
I 3
on 10 Mb/sec Ethernets).
E 3
More information on configuring each of these can also be found
in section 4 of the manual.
E 1

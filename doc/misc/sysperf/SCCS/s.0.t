h52686
s 00005/00005/00231
d D 1.3 85/11/30 13:12:05 mckusick 3 2
c editing glitches
e
s 00010/00008/00226
d D 1.2 85/08/11 10:24:58 cabrera 2 1
c my first pass
e
s 00234/00000/00000
d D 1.1 85/07/27 19:42:58 mckusick 1 0
c date and time created 85/07/27 19:42:58 by mckusick
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
.if n .ND
.TL
D 2
Measuring and Improving the Performance of UNIX*
E 2
I 2
Measuring and Improving the Performance of Berkeley UNIX*
E 2
.sp
D 2
Revised July 16, 1985
E 2
I 2
D 3
Revised July 16, August 11, 1985
E 3
I 3
%Q%
E 3
E 2
.AU
Marshall Kirk McKusick,
Samuel J. Leffler\(dg,
Michael J. Karels,
Luis Felipe Cabrera\(dd
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA  94720
.AB
.FS
D 2
* UNIX is a trademark of Bell Laboratories.
E 2
I 2
* UNIX is a trademark of AT&T Bell Laboratories.
E 2
.FE
.FS
\(dg Samuel J. Leffler is currently employed by:
Lucasfilm Ltd., PO Box 2009, San Rafael, CA 94912
.FE
.FS
\(dd Luis Felipe Cabrera is currently employed by:
D 2
???
E 2
I 2
Computer Science Department, IBM Research Laboratory, 5600 Cottle Road,
San Jose, California 95193.
E 2
.FE
.FS
This work was done under grants from
the National Science Foundation under grant MCS80-05144,
and the Defense Advance Research Projects Agency (DoD) under
ARPA Order No. 4031 monitored by Naval Electronic System Command under
Contract No. N00039-82-C-0235.
.FE
The 4.2 Berkeley Software Distribution of 
.UX
for the VAX\(dd
.FS
\(dd VAX, MASSBUS, UNIBUS, and DEC are trademarks of
Digital Equipment Corporation.
.FE
D 2
has several problems that can severely affect the overall
E 2
I 2
had several problems that could severely affect the overall
E 2
performance of the system.
These problems were identified with
kernel profiling and system tracing during day to day use.
Once potential problem areas had been identified
benchmark programs were devised to highlight the bottlenecks.
These benchmarks verified that the problems existed and provided
a metric against which to validate proposed solutions.
This paper examines 
the performance problems encountered and describes
modifications that have been made
to the system since the initial distribution.
D 2
.pp
E 2
I 2
.PP
E 2
The changes to the system have consisted of improvements to the
performance of the existing facilities,
as well as enhancements to the current facilities.
Performance improvements in the kernel include cacheing of path name
translations, reductions in clock handling and scheduling overhead,
D 2
and improved throughput of the network.
E 2
I 2
and improved throughput of the network subsystem.
E 2
Performance improvements in the libraries and utilities include replacement of
linear searches of system databases with indexed lookup,
merging of most network services into a single daemon,
and conversion of system utilities to use the more efficient
facilities available in 4.2BSD.
Enhancements in the kernel include the addition of subnets and gateways,
increases in many kernel limits,
cleanup of the signal and autoconfiguration implementations,
and support for windows and system logging.
Functional extensions in the libraries and utilities include
the addition of an Internet name server,
new system management tools,
and extensions to \fIdbx\fP to work with Pascal.
The paper concludes with a brief discussion of changes made to
the system to enhance security.
I 2
All of these enhancements are present in Berkeley UNIX 4.3BSD.
E 2
.AE
.LP
.sp 2
CR Categories and Subject Descriptors:
D.4.3
.B "[Operating Systems]":
File Systems Management \-
.I "file organization, directory structures, access methods";
D.4.2
.B "[Operating Systems]":
Storage Management \-
.I "allocation/deallocation strategies, secondary storage devices";
D.4.8
.B "[Operating Systems]":
Performance \-
.I "measurements, operational analysis";
H.3.2
.B "[Information Systems]":
Information Storage \-
.I "file organization"
.sp
Additional Keywords and Phrases:
D 2
UNIX,
E 2
I 2
Berkeley UNIX,
E 2
file system organization,
file system performance,
file system design,
application program interface.
.sp
General Terms:
file system,
measurement,
performance.
.de PT
.lt \\n(LLu
.pc %
.nr PN \\n%
.tl '\\*(LH'\\*(CH'\\*(RH'
.lt \\n(.lu
..
.af PN i
D 3
.ds LH File System
E 3
I 3
.ds LH Performance
E 3
.ds RH Contents
.bp 1
D 3
.if t .ds CF July 16, 1985
.if t .ds LF TOCS
E 3
I 3
.if t .ds CF %Q%
.if t .ds LF DRAFT
E 3
.if t .ds RF McKusick, et. al.
.ce
.B "TABLE OF CONTENTS"
.LP
.sp 1
.nf
.B "1.  Introduction"
.LP
.sp .5v
.nf
.B "2.  Observation techniques
\0.1.    System maintenance tools
\0.2.    Kernel profiling
\0.3.    Kernel tracing
\0.4.    Benchmark programs
.LP
.sp .5v
.nf
.B "3.  Results of our observations
\0.1.    User programs
\0.1.1.    Mail system
\0.1.2.    Network servers
\0.2.    System overhead
\0.2.1.    Micro-operation benchmarks
\0.2.2.    Path name translation
\0.2.3.    Clock processing
\0.2.4.    Terminal multiplexors
\0.2.5.    Process table management
\0.2.6.    File system buffer cache
\0.2.7.    Network subsystem
\0.2.8.    Virtual memory subsystem
.LP
.sp .5v
.nf
.B "4.  Performance Improvements
\0.1.    Performance Improvements in the Kernel
\0.1.1.    Name Cacheing
\0.1.2.    Intelligent Auto Siloing
\0.1.3.    Process Table Management
\0.1.4.    Scheduling
\0.1.5.    Clock Handling
\0.1.6.    File System
\0.1.7.    Network
\0.1.8.    Exec
\0.1.9.    Context Switching
\0.1.10.   Setjmp and Longjmp
\0.1.11.   Compensating for Lack of Compiler Technology
\0.2.    Improvements to Libraries and Utilities
\0.2.1.    Hashed Databases
\0.2.2.    Buffered I/O
\0.2.3.    Mail System
\0.2.4.    Network Servers
\0.2.5.    The C Run-time Library
\0.2.6.    Csh
.LP
.sp .5v
.nf
.B "5.  Functional Extensions
\0.1.    Kernel Extensions
\0.1.1.    Subnets, Broadcasts, and Gateways
\0.1.2.    Interface Addressing
\0.1.3.    User Control of Network Buffering
\0.1.4.    Number of File Descriptors
\0.1.5.    Kernel Limits
\0.1.6.    Memory Management
\0.1.7.    Signals
\0.1.8.    System Logging
\0.1.9.    Windows
\0.1.10.   Configuration of UNIBUS Devices
\0.1.11.   Disk Recovery from Errors
\0.2.    Functional Extensions to Libraries and Utilities
\0.2.1.    Name Server
\0.2.2.    System Management
\0.2.3.    Routing
\0.2.4.    Compilers
.LP
.sp .5v
.nf
.B "6.  Security Tightening
\0.1.    Generic Kernel
\0.2.    Security Problems in Utilities
.LP
.sp .5v
.nf
.B "7.  Conclusions
.LP
.sp .5v
.nf
.B Acknowledgements
.LP
.sp .5v
.nf
.B References
.LP
.sp .5v
.nf
D 3
.B Appendix - Benchmark Programs
E 3
I 3
.B "Appendix \- Benchmark Programs"
E 3
.de _d
.if t .ta .6i 2.1i 2.6i
.\" 2.94 went to 2.6, 3.64 to 3.30
.if n .ta .84i 2.6i 3.30i
..
.de _f
.if t .ta .5i 1.25i 2.5i
.\" 3.5i went to 3.8i
.if n .ta .7i 1.75i 3.8i
..
E 1

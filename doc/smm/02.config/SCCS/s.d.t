h06329
s 00120/00068/00125
d D 6.2 86/06/03 18:05:54 karels 3 2
c 4.3 version
e
s 00011/00004/00182
d D 6.1 86/05/25 16:40:30 mckusick 2 1
c 4.3BSD beta release document
e
s 00186/00000/00000
d D 5.1 86/05/25 16:40:23 mckusick 1 0
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
.ds RH "Data Structure Sizing Rules
.ds CF July 27, 1983
.LP
.nr H1 1
.ds CH "
E 3
I 3
.\".ds RH "Data Structure Sizing Rules
E 3
.bp
D 3
.ds CH "\(hy \\n(PN \(hy
E 3
.LG
.B
.ce
APPENDIX D. VAX KERNEL DATA STRUCTURE SIZING RULES
D 3
.sp 2
E 3
I 3
.sp
E 3
.R
.NL
.PP
Certain system data structures are sized at compile time
according to the maximum number of simultaneous users expected,
while others are calculated at boot time based on the
D 3
physical resources present; e.g. memory.  This appendix lists
E 3
I 3
physical resources present, e.g. memory.  This appendix lists
E 3
both sets of rules and also includes some hints on changing
built-in limitations on certain data structures.
.SH
Compile time rules
.PP
D 3
The file \fI/sys/conf/param.c\fP contains the definitions of
E 3
I 3
The file \fI/sys/conf\|/param.c\fP contains the definitions of
E 3
almost all data structures sized at compile time.  This file
is copied into the directory of each configured system to allow
configuration-dependent rules and values to be maintained.
I 3
(Each copy normally depends on the copy in /sys/conf,
and global modifications cause the file to be recopied unless
the makefile is modified.)
E 3
The rules implied by its contents are summarized below (here
MAXUSERS refers to the value defined in the configuration file
in the ``maxusers'' rule).
I 3
Most limits are computed at compile time and stored in global variables
for use by other modules; they may generally be patched in the system
binary image before rebooting to test new values.
E 3
.IP \fBnproc\fP
.br
D 3
The maximum number of processes which may be running at
any time.  It is defined to be 20 + 8 * MAXUSERS and referred
to in other calculations as NPROC.
E 3
I 3
The maximum number of processes which may be running at any time.
It is referred to in other calculations as NPROC and is defined to be
.DS
20 + 8 * MAXUSERS
.DE
E 3
.IP \fBntext\fP
.br
D 3
The maximum number of active shared text segments.  Defined as
24 + MAXUSERS + NETSLOP, where NETSLOP is 20 when the Internet
protocols are configured in the system and 0 otherwise.  The
added size for supporting the network is to take into account
the numerous server processes which are likely to exist.
E 3
I 3
The maximum number of active shared text segments.
The constant is intended to allow for network servers and common commands
that remain in the table.
It is defined as
.DS
36 + MAXUSERS.
.DE
E 3
.IP \fBninode\fP
.br
The maximum number of files in the file system which may be
active at any time.  This includes files in use by users, as 
well as directory files being read or written by the system
D 3
and files associated with bound sockets in the UNIX ipc domain.
This is defined as (NPROC + 16 + MAXUSERS) + 32.
E 3
I 3
and files associated with bound sockets in the UNIX IPC domain.
It is defined as
.DS
(NPROC + 16 + MAXUSERS) + 32
.DE
E 3
.IP \fBnfile\fP
.br
The number of ``file table'' structures.  One file
table structure is used for each open, unshared, file descriptor.
Multiple file descriptors may reference a single file table
entry when they are created through a \fIdup\fP call, or as the
result of a \fIfork\fP.  This is defined to be
.DS
D 3
16 * (NPROC + 16 + MAXUSERS) / 10 + 32 + 2 * NETSLOP
E 3
I 3
16 * (NPROC + 16 + MAXUSERS) / 10 + 32
E 3
.DE
D 3
where NETSLOP is defined as for \fBntext\fP.
E 3
.IP \fBncallout\fP
.br
The number of ``callout'' structures.  One callout
structure is used per internal system event handled with
a timeout.  Timeouts are used for terminal delays,
watchdog routines in device drivers, protocol timeout processing, etc.
D 3
This is defined as 16 + NPROC.
E 3
I 3
This is defined as
.DS
16 + NPROC
.DE
E 3
.IP \fBnclist\fP
.br
The number of ``c-list'' structures.  C-list structures are
D 3
used in terminal i/o.  This is defined as 100 + 16 * MAXUSERS.
E 3
I 3
used in terminal I/O, and currently each holds 60 characters.
Their number is defined as
.DS
60 + 12 * MAXUSERS
.DE
E 3
.IP \fBnmbclusters\fP
.br
The maximum number of pages which may be allocated by the network.  
This is defined as 256 (a quarter megabyte of memory) in /sys/h/mbuf.h.
In practice, the network rarely uses this much memory.  It starts off
D 3
by allocating 64 kilobytes of memory, then requesting more as 
E 3
I 3
by allocating 8 kilobytes of memory, then requesting more as 
E 3
required.  This value represents an upper bound.
.IP \fBnquota\fP
.br
The number of ``quota'' structures allocated.  Quota structures
are present only when disc quotas are configured in the system.  One
quota structure is kept per user.  This is defined to be
D 3
(MAXUSERS * 9) / 7 + 3.
E 3
I 3
.DS
(MAXUSERS * 9) / 7 + 3
.DE
E 3
.IP \fBndquot\fP
.br
The number of ``dquot'' structures allocated.  Dquot structures
are present only when disc quotas are configured in the system.
One dquot structure is required per user, per active file system quota.
That is, when a user manipulates a file on a file system on which
quotas are enabled, the information regarding the user's quotas on
that file system must be in-core.  This information is cached, so
that not all information must be present in-core all the time.
D 3
This is defined as (MAXUSERS * NMOUNT) / 4 + NPROC, where NMOUNT
is the maximum number of mountable file systems.
E 3
I 3
This is defined as
.DS
NINODE + (MAXUSERS * NMOUNT) / 4
.DE
where NMOUNT is the maximum number of mountable file systems.
E 3
.LP
In addition to the above values, the system page tables (used to
map virtual memory in the kernel's address space) are sized at
D 2
compile time by the SYSPTSIZE definition in the file /sys/vax/param.h.
E 2
I 2
compile time by the SYSPTSIZE definition in the file /sys/vax/vmparam.h.
E 2
D 3
This is defined to be 20 + MAXUSERS pages of page tables. 
E 3
I 3
This is defined to be
.DS
20 + MAXUSERS
.DE
pages of page tables. 
E 3
Its definition affects
the size of many data structures allocated at boot time because
it constrains the amount of virtual memory which may be addressed
by the running system.  This is often the limiting factor
D 3
in the size of the buffer cache.
E 3
I 3
in the size of the buffer cache, in which case a message is printed
when the system configures at boot time.
E 3
.SH
Run-time calculations
.PP
The most important data structures sized at run-time are those used in
D 3
the buffer cache.  Allocation is done by swiping physical memory
(and the associated virtual memory) immediately after the system
E 3
I 3
the buffer cache.  Allocation is done by allocating physical memory
(and system virtual memory) immediately after the system
E 3
has been started up; look in the file /sys/vax/machdep.c.
The amount of physical memory which may be allocated to the buffer
cache is constrained by the size of the system page tables, among
other things.  While the system may calculate
a large amount of memory to be allocated to the buffer cache,
if the system page
table is too small to map this physical
memory into the virtual address space
of the system, only as much as can be mapped will be used.
.PP
The buffer cache is comprised of a number of ``buffer headers''
and a pool of pages attached to these headers.  Buffer headers
are divided into two categories: those used for swapping and
D 3
paging, and those used for normal file i/o.  The system tries
to allocate 10% of available physical memory for the buffer
E 3
I 3
paging, and those used for normal file I/O.  The system tries
to allocate 10% of the first two megabytes and 5% of the remaining
available physical memory for the buffer
E 3
cache (where \fIavailable\fP does not count that space occupied by
the system's text and data segments).  If this results in fewer
than 16 pages of memory allocated, then 16 pages are allocated.
This value is kept in the initialized variable \fIbufpages\fP
so that it may be patched in the binary image (to allow tuning
D 3
without recompiling the system).  A sufficient number of
file i/o buffer headers are then allocated to allow each to hold
2 pages each, and half as many swap i/o buffer headers are then
allocated.  The number of swap i/o buffer headers is constrained
to be no more than 256.
E 3
I 3
without recompiling the system),
or the default may be overridden with a configuration-file option.
For example, the option \fBoptions BUFPAGES="3200"\fP
causes 3200 pages (3.2M bytes) to be used by the buffer cache.
A sufficient number of file I/O buffer headers are then allocated
to allow each to hold 2 pages each.
Each buffer maps 8K bytes.
If the number of buffer pages is larger than can be mapped
by the buffer headers, the number of pages is reduced.
The number of buffer headers allocated
is stored in the global variable \fInbuf\fP,
which may be patched before the system is booted.
The system option \fBoptions NBUF="1000"\fP forces the allocation
of 1000 buffer headers.
Half as many swap I/O buffer headers as file I/O buffers
are allocated,
but no more than 256.
E 3
.SH
System size limitations
.PP
As distributed, the sum of the virtual sizes of the core-resident
D 3
processes is limited to 64M bytes.  The size of the text, and data
segments of a single process are currently limited to 6M bytes each, and
the stack segment size is limited to 512K bytes as a soft, user-changeable
limit, and may be increased to 6M with the \fIsetrlimit\fP\|(2) system call.
If these are insufficient, they
can be increased by changing the constants MAXTSIZ, MAXDSIZ and MAXSSIZ
in the file
D 2
/sys/vax/vmparam.h, while
changing the definitions in
/sys/h/dmap.h and /sys/h/text.h.
E 2
I 2
/sys/vax/vmparam.h.
The size of the swap maps for these objects must also be increased;
for text, the parameters are NXDAD (/sys/h/text.h)
and DMTEXT (/sys/vax/autoconfig.c).
The maps for data and swap are limited by NDMAP (/sys/h/dmap.h)
and DMMAX (/sys/vax/autoconfig.c).
E 3
I 3
processes is limited to 256M bytes.  The size of the text
segment of a single process is currently limited to 6M bytes.
It may be increased to no greater than the data segment size limit
(see below) by redefining MAXTSIZ.
This may be done with a configuration file option,
e.g. \fBoptions MAXTSIZ="(10*1024*1024)"\fP
to set the limit to 10 million bytes.
Other per-process limits discussed here may be changed with similar options
with names given in parentheses.
Soft, user-changeable limits are set to 512K bytes for stack (DFLSSIZ)
and 6M bytes for the data segment (DFLDSIZ) by default;
these may be increased up to the hard limit
with the \fIsetrlimit\fP\|(2) system call.
The data and stack segment size hard limits are set by a system configuration
option to one of 17M, 33M or 64M bytes.
One of these sizes is chosen based on the definition of MAXDSIZ;
with no option, the limit is 17M bytes; with an option
\fBoptions MAXDSIZ="(32*1024*1024)"\fP (or any value between 17M and 33M),
the limit is increased to 33M bytes, and values larger than 33M
result in a limit of 64M bytes.
E 3
E 2
You must be careful in doing this that you have adequate paging space.
D 3
As normally configured , the system has only 16M bytes per paging area.
E 3
I 3
As normally configured , the system has 16M or 32M bytes per paging area,
depending on disk size.
E 3
The best way to get more space is to provide multiple, thereby
interleaved, paging areas.
I 3
Increasing the virtual memory limits results in interleaving of
swap space in larger sections (from 500K bytes to 1M or 2M bytes).
E 3
.PP
I 3
By default, the virtual memory system allocates enough memory
for system page tables mapping user page tables
to allow 256 megabytes of simultaneous active virtual memory.
That is, the sum of the virtual memory sizes of all (completely- or partially-)
resident processes can not exceed this limit.
If the limit is exceeded, some process(es) must be swapped out.
E 3
To increase the amount of resident virtual space possible,
you can alter the constant USRPTSIZE (in
/sys/vax/vmparam.h).
D 3
To allow 128 megabytes of resident virtual space one would
change the 8 to a 16.
E 3
I 3
Each page of system page tables allows 8 megabytes of user virtual memory.
E 3
.PP
Because the file system block numbers are stored in
page table \fIpg_blkno\fP
entries, the maximum size of a file system is limited to
D 3
2^19 1024 byte blocks.  Thus no file system can be larger than 512M bytes.
E 3
I 3
2^24 1024 byte blocks.  Thus no file system can be larger than 8 gigabytes.
E 3
.PP
D 3
The count of mountable file systems is limited to 15.  This should
be sufficient.  If you have many disks it makes sense to make some of
E 3
I 3
The number of mountable file systems is set at 20 by the definition
of NMOUNT in /sys/h/param.h.
This should be sufficient; if not, the value can be increased up to 255.
If you have many disks, it makes sense to make some of
E 3
them single file systems, and the paging areas don't count in this total.
D 3
To increase this it will be necessary to change the core-map
/sys/h/cmap.h since there is a 4 bit field used here.  The size
of the core-map will then expand to 16 bytes per 1024 byte page.
(Don't forget to change MSWAPX and NMOUNT in /sys/h/param.h also.)
E 3
.PP
D 3
The maximum value NOFILE (open files per process limit)
can be raised to
is 30 because of a bit field in the page table entry in
/sys/machine/pte.h.
E 3
I 3
The limit to the number of files that a process may have open simultaneously
is set to 64.
This limit is set by the NOFILE definition in /sys/h/param.h.
It may be increased arbitrarily, with the caveat that the user structure
expands by 5 bytes for each file, and thus UPAGES (/sys/vax/machparam.h)
must be increased accordingly.
E 3
I 2
.PP
D 3
The amount of physical memory is currently limited to 8 Mb
E 3
I 3
The amount of physical memory is currently limited to 64 Mb
E 3
by the size of the index fields in the core-map (/sys/h/cmap.h).
D 3
This limit is also found in /sys/vax/locore.s.
E 3
I 3
The limit may be increased by following instructions in that file
to enlarge those fields.
E 3
E 2
E 1

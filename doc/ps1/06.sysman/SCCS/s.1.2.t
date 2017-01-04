h19029
s 00010/00001/00235
d D 6.10 86/08/25 15:05:18 mckusick 12 11
c update from discussions with shannon
e
s 00032/00026/00204
d D 6.9 86/08/15 16:01:30 mckusick 11 9
c update VM spec from discussions with Sun
e
s 00022/00019/00211
d R 6.9 86/08/11 15:16:58 mckusick 10 9
c update interface per discussion with Sun
e
s 00002/00002/00228
d D 6.8 86/05/14 14:04:10 karels 9 8
c tabs
e
s 00013/00004/00217
d D 6.7 86/05/12 11:32:56 mckusick 8 7
c leave toe-hold for MAP_SWAP; add ADV_SPACEAVAIL to reserve space
e
s 00022/00028/00199
d D 6.6 86/05/12 10:51:17 karels 7 6
c msleep stays, but after mset; caveat about mixed use
e
s 00001/00000/00226
d D 6.5 86/05/12 09:08:08 karels 6 5
c missing .DE
e
s 00084/00049/00142
d D 6.4 86/05/12 01:00:45 karels 5 4
c update, correct, rephrase and re-propose
e
s 00008/00007/00183
d D 6.3 86/05/10 16:35:55 mckusick 4 3
c add MAP_HASSEMAPHORE option
e
s 00026/00027/00164
d D 6.2 86/05/08 17:50:29 mckusick 3 2
c comments from the readers
e
s 00072/00012/00119
d D 6.1 86/05/08 12:24:47 mckusick 2 1
c update virtual memory design
e
s 00131/00000/00000
d D 5.1 86/05/08 00:02:35 mckusick 1 0
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
.sh "Memory management\(dg
.NH 3
Text, data and stack
.PP
.FS
\(dg This section represents the interface planned for later
releases of the system.  Of the calls described in this section,
D 2
only \fIsbrk\fP and \fIgetpagesize\fP are included in 4.2BSD.
E 2
I 2
only \fIsbrk\fP and \fIgetpagesize\fP are included in 4.3BSD.
E 2
.FE
Each process begins execution with three logical areas of memory
called text, data and stack.  
The text area is read-only and shared, while the data and stack
areas are private to the process.  Both the data and stack areas may
be extended and contracted on program request.  The call
.DS
addr = sbrk(incr);
result caddr_t addr; int incr;
.DE
changes the size of the data area by \fIincr\fP bytes and
returns the new end of the data area, while
.DS
addr = sstk(incr);
result caddr_t addr; int incr;
.DE
changes the size of the stack area.
The stack area is also automatically extended as needed.
On the VAX the text and data areas are adjacent in the P0 region,
while the stack section is in the P1 region, and grows downward.
.NH 3
Mapping pages
.PP
The system supports sharing of data between processes
by allowing pages to be mapped into memory.  These mapped
pages may be \fIshared\fP with other processes or \fIprivate\fP
to the process.
D 5
Protection and sharing options are defined in <mman.h> as:
E 5
I 5
Protection and sharing options are defined in \fI<sys/mman.h>\fP as:
E 5
.DS
D 9
._d
E 9
I 9
D 11
.ta \w'#define\ \ 'u +\w'MAP_HASSEMPHORE\ \ 'u +\w'0x0080\ \ 'u
E 11
I 11
.ta \w'#define\ \ 'u +\w'MAP_HASSEMAPHORE\ \ 'u +\w'0x0080\ \ 'u
E 11
E 9
/* protections are chosen from these bits, or-ed together */
D 3
#define	PROT_READ	0x4	/* pages can be read */
#define	PROT_WRITE	0x2	/* pages can be written */
#define	PROT_EXEC	0x1	/* pages can be executed */
E 3
I 3
#define	PROT_READ	0x04	/* pages can be read */
#define	PROT_WRITE	0x02	/* pages can be written */
#define	PROT_EXEC	0x01	/* pages can be executed */
E 3
D 11

E 11
I 11
.DE
.DS
.ta \w'#define\ \ 'u +\w'MAP_HASSEMAPHORE\ \ 'u +\w'0x0080\ \ 'u
E 11
I 5
/* flags contain mapping type, sharing type and options */
E 5
I 2
/* mapping type; choose one */
D 3
#define MAP_FILE	0x0001	/* mapped from a file */
#define MAP_SWAP	0x0002	/* mapped to swap space */
#define MAP_MEMORY	0x0004	/* mapped to device memory */
E 3
I 3
D 5
#define MAP_FILE	0x01	/* mapped from a file */
#define MAP_SWAP	0x02	/* mapped from swap space */
D 4
#define MAP_MEMORY	0x04	/* mapped from device memory */
E 4
I 4
#define MAP_MEMORY	0x03	/* mapped from device memory */
E 5
I 5
#define MAP_FILE	0x0001	/* mapped from a file or device */
#define MAP_ANON	0x0002	/* allocated from memory, swap space */
#define MAP_TYPE	0x000f	/* mask for type field */
E 5
E 4
E 3
D 11

E 11
I 11
.DE
.DS
.ta \w'#define\ \ 'u +\w'MAP_HASSEMAPHORE\ \ 'u +\w'0x0080\ \ 'u
E 11
E 2
D 3
/* sharing types; choose either SHARED or PRIVATE */
D 2
#define	MAP_SHARED	1	/* share changes */
#define	MAP_PRIVATE	2	/* changes are private */
E 2
I 2
#define	MAP_SHARED	0x0010	/* share changes */
#define	MAP_PRIVATE	0x0020	/* changes are private */
E 3
I 3
/* sharing types; choose one */
D 4
#define	MAP_SHARED	0x10	/* share changes */
#define	MAP_PRIVATE	0x20	/* changes are private */
E 4
I 4
D 5
#define	MAP_SHARED	0x04	/* share changes */
#define	MAP_PRIVATE	0x00	/* changes are private */
E 5
I 5
#define	MAP_SHARED	0x0010	/* share changes */
#define	MAP_PRIVATE	0x0000	/* changes are private */
E 5
E 4
E 3
D 11

E 11
I 11
.DE
.DS
.ta \w'#define\ \ 'u +\w'MAP_HASSEMAPHORE\ \ 'u +\w'0x0080\ \ 'u
E 11
D 3
/* other options */
#define MAP_FIXED	0x0040	/* map segment must be allocated at addr */
#define MAP_EXTEND	0x0080	/* for MAP_FILE, the file may be extended */
E 3
I 3
/* other flags */
D 4
#define MAP_FIXED	0x40	/* map region must be allocated at addr */
#define MAP_EXTEND	0x80	/* for MAP_FILE, the file may be extended */
E 4
I 4
D 5
#define MAP_FIXED	0x10	/* map region must be allocated at addr */
#define MAP_EXTEND	0x20	/* for MAP_FILE, the file may be extended */
#define MAP_HASSEMPHORE	0x40	/* region may contain semaphores */
E 5
I 5
#define MAP_FIXED	0x0020	/* map addr must be exactly as requested */
D 11
#define MAP_NOEXTEND	0x0040	/* for MAP_FILE, don't change file size */
#define MAP_HASSEMPHORE	0x0080	/* region may contain semaphores */
#define MAP_INHERIT	0x0100	/* region is retained after exec */
E 11
I 11
#define MAP_INHERIT	0x0040	/* region is retained after exec */
#define MAP_HASSEMAPHORE	0x0080	/* region may contain semaphores */
I 12
#define MAP_NOPREALLOC	0x0100	/* do not preallocate space */
E 12
E 11
E 5
E 4
E 3
E 2
.DE
The cpu-dependent size of a page is returned by the
\fIgetpagesize\fP system call:
.DS
pagesize = getpagesize();
result int pagesize;
.DE
D 11
.PP
E 11
I 11
.LP
E 11
The call:
.DS
D 2
mmap(addr, len, prot, share, fd, pos);
caddr_t addr; int len, prot, share, fd; off_t pos;
E 2
I 2
D 3
caddr_t
maddr = mmap(addr, len, prot, share, fd, pos);
result caddr_t maddr; caddr_t addr; int *len, prot, share, fd; off_t pos;
E 3
I 3
maddr = mmap(addr, len, prot, flags, fd, pos);
result caddr_t maddr; caddr_t addr; int *len, prot, flags, fd; off_t pos;
E 3
E 2
.DE
causes the pages starting at \fIaddr\fP and continuing
D 2
for \fIlen\fP bytes to be mapped from the object represented by
descriptor \fIfd\fP, at absolute position \fIpos\fP.  The parameter
\fIshare\fP specifies whether modifications made to this mapped copy
of the page, are to be kept \fIprivate\fP, or are to be \fIshared\fP with
E 2
I 2
for at most \fIlen\fP bytes to be mapped from the object represented by
D 3
descriptor \fIfd\fP, at absolute position \fIpos\fP.
E 3
I 3
descriptor \fIfd\fP, starting at byte offset \fIpos\fP.
E 3
D 5
The starting address of the region is returned.
E 5
I 5
The starting address of the region is returned;
for the convenience of the system,
D 11
it may be different than that supplied
E 11
I 11
it may differ from that supplied
E 11
unless the MAP_FIXED flag is given,
in which case the exact address will be used or the call will fail.
E 5
D 3
The actual amount mapped is returned in len.
The parameter \fIshare\fP specifies whether modifications made to
E 3
I 3
The actual amount mapped is returned in \fIlen\fP.
D 5
The parameter \fIflags\fP specifies whether modifications made to
E 3
this mapped copy of the page,
are to be kept \fIprivate\fP, or are to be \fIshared\fP with
E 2
other references.
The parameter \fIprot\fP specifies the accessibility
of the mapped pages.
E 5
The \fIaddr\fP, \fIlen\fP, and \fIpos\fP parameters
must all be multiples of the pagesize.
I 11
D 12
A successful \fImmap\fP will \fImunmap\fP any previous mapping
E 12
I 12
A successful \fImmap\fP will delete any previous mapping
E 12
in the allocated address range.
E 11
I 5
The parameter \fIprot\fP specifies the accessibility
of the mapped pages.
The parameter \fIflags\fP specifies
the type of object to be mapped,
mapping options, and
whether modifications made to
this mapped copy of the page
are to be kept \fIprivate\fP, or are to be \fIshared\fP with
other references.
Possible types include MAP_FILE,
mapping a regular file or character-special device memory,
and MAP_ANON, which maps memory not associated with any specific file.
The file descriptor used for creating MAP_ANON regions is used only
D 8
for naming, and may be given as -1 if no name is associated with the region.
E 8
I 8
for naming, and may be given as \-1 if no name
D 11
is associated with the region\(dd.
E 11
I 11
is associated with the region.\(dd
E 11
.FS
\(dd The current design does not allow a process
to specify the location of swap space.
In the future we may define an additional mapping type, MAP_SWAP,
in which the file descriptor argument specifies a file
or device to which swapping should be done.
.FE
E 8
D 11
The MAP_NOEXTEND flag prevents the mapped file from being extended
despite rounding due to the granularity of mapping.
E 11
I 11
The MAP_INHERIT flag allows a region to be inherited after an \fIexec\fP.
E 11
D 8
Other flags allow special handling for regions that may contain semaphores
or that may be inherited after an \fIexec\fP.
E 8
I 8
The MAP_HASSEMAPHORE flag allows special handling for
regions that may contain semaphores.
I 12
The MAP_NOPREALLOC flag allows processes to allocate regions whose
virtual address space, if fully allocated,
would exceed the available memory plus swap resources.
Such regions may get a SIGSEGV signal if they page fault and resources
are not available to service their request;
typically they would free up some resources via \fIunmap\fP so that
when they return from the signal the page
fault could be successfully completed.
E 12
D 11
The MAP_INHERIT flag allows a region to be inherited after an \fIexec\fP.
E 11
E 8
E 5
.PP
D 5
A process can move pages within its own memory by using the
.I mremap
call:
E 5
I 5
A facility is provided to synchronize a mapped region with the file
it maps; the call
E 5
.DS
D 3
mremap(addr, len, prot, share, fromaddr);
caddr_t addr; int len, prot, share; caddr_t fromaddr;
E 3
I 3
D 5
mremap(addr, len, prot, flags, fromaddr);
caddr_t addr; int len, prot, flags; caddr_t fromaddr;
E 3
.DE
This call maps the pages starting at \fIfromaddr\fP to the address specified
by \fIaddr\fP.
E 5
I 5
msync(addr, len);
caddr_t addr; int len;
I 6
.DE
E 6
writes any modified pages back to the filesystem and updates
the file modification time.
If \fIlen\fP is 0, all modified pages within the region containing \fIaddr\fP
will be flushed;
if \fIlen\fP is non-zero, only the pages containing \fIaddr\fP and \fIlen\fP
succeeding locations will be examined.
D 11
Any required invalidation of memory caches will also take place at this time.
I 7
Filesystem operations on a file which is mapped for shared modifications
E 11
I 11
Any required synchronization of memory caches
will also take place at this time.
Filesystem operations on a file that is mapped for shared modifications
E 11
are unpredictable except after an \fImsync\fP.
E 7
E 5
.PP
A mapping can be removed by the call
.DS
D 5
munmap(addr, len);
caddr_t addr; int len;
E 5
I 5
D 11
munmap(addr);
caddr_t addr;
E 11
I 11
munmap(addr, len);
caddr_t addr; int len;
E 11
E 5
.DE
D 2
This causes further references to these pages to refer to private
pages initialized to zero.
E 2
I 2
D 5
This call causes further references to these pages
E 5
I 5
D 11
This call deletes the region containing the address given,
and causes further references to addresses within the region
E 11
I 11
This call deletes the mappings for the specified address range,
and causes further references to addresses within the range
E 11
E 5
to generate invalid memory references.
D 3
If the segment is mapped MAP_FILE with mode PROT_WRITE,
E 3
I 3
D 5
If the region is mapped MAP_FILE with mode PROT_WRITE,
E 3
the file is truncated to the length specified by \fIlen\fP.
E 5
E 2
.NH 3
Page protection control
.PP
A process can control the protection of pages using the call
.DS
mprotect(addr, len, prot);
caddr_t addr; int len, prot;
.DE
This call changes the specified pages to have protection \fIprot\fP\|.
I 5
Not all implementations will guarantee protection on a page basis;
the granularity of protection changes may be as large as an entire region.
E 5
.NH 3
Giving and getting advice
.PP
A process that has knowledge of its memory behavior may
use the \fImadvise\fP call:
.DS
madvise(addr, len, behav);
caddr_t addr; int len, behav;
.DE
\fIBehav\fP describes expected behavior, as given
D 7
in <mman.h>:
E 7
I 7
in \fI<sys/mman.h>\fP:
E 7
.DS
D 9
._d
E 9
I 9
.ta \w'#define\ \ 'u +\w'MADV_SEQUENTIAL\ \ 'u +\w'00\ \ \ \ 'u
E 9
#define	MADV_NORMAL	0	/* no further special treatment */
#define	MADV_RANDOM	1	/* expect random page references */
#define	MADV_SEQUENTIAL	2	/* expect sequential references */
#define	MADV_WILLNEED	3	/* will need these pages */
#define	MADV_DONTNEED	4	/* don't need these pages */
I 8
#define	MADV_SPACEAVAIL	5	/* insure that resources are reserved */
E 8
.DE
Finally, a process may obtain information about whether pages are
core resident by using the call
.DS
mincore(addr, len, vec)
caddr_t addr; int len; result char *vec;
.DE
Here the current core residency of the pages is returned
in the character array \fIvec\fP, with a value of 1 meaning
that the page is in-core.
I 2
.NH 3
Synchronization primitives
.PP
I 5
D 7
.if \n(sw=0 .ig sw
E 5
Two routines provide services analogous to the kernel
D 3
sleep and wakeup functions interpreted in the domain of
E 3
I 3
\fIsleep\fP and \fIwakeup\fP functions interpreted in the domain of
E 3
shared memory.
D 3
A process may relinquish the processor by calling msleep:
E 3
I 3
A process may relinquish the processor by calling \fImsleep\fP:
E 3
.DS
D 5
msleep(addr)
caddr_t addr;
E 5
I 5
msleep(sem)
semaphore *sem;
E 5
.DE
D 3
Addr must lie within a MAP_SHARED segment with at least modes
E 3
I 3
D 5
\fIAddr\fP must lie within a MAP_SHARED region with at least modes
E 5
I 5
\fISem\fP must lie within a MAP_SHARED region with at least modes
E 5
E 3
PROT_READ and PROT_WRITE.
I 4
The MAP_HASSEMAPHORE flag must have been specified when the region was created.
E 4
The process will remain in a sleeping state
D 5
until some other process issues an \fImwakeup\fP for the same byte
E 5
I 5
until some other process issues an \fImwakeup\fP for the same semaphore
E 5
D 4
within the region (possibly from a different virtual address)
using the call:
E 4
I 4
within the region using the call:
E 4
.DS
D 5
mwakeup(addr)
caddr_t addr;
E 5
I 5
mwakeup(sem)
semaphore *sem;
E 5
.DE
I 5
An \fImwakeup\fP may awaken all sleepers on the semaphore,
or may awaken only the next sleeper on a queue.
E 5
.PP
To avoid system calls for the usual case of an uncontested lock,
D 5
library routines are provided to acquire and release locks.
E 5
I 5
routines are provided to acquire and release locks.
.sw
.if \n(sw .ig sw
E 7
Primitives are provided for synchronization using semaphores in shared memory.
Semaphores must lie within a MAP_SHARED region with at least modes
PROT_READ and PROT_WRITE.
The MAP_HASSEMAPHORE flag must have been specified when the region was created.
D 7
.sw
E 7
E 5
To acquire a lock a process calls:
.DS
D 5
mset(addr)
caddr_t addr;
E 5
I 5
value = mset(sem, wait)
result int value; semaphore *sem; int wait;
E 5
.DE
D 3
\fIMset\fP indivisibly tests and sets the memory location addr.
E 3
I 3
D 5
\fIMset\fP indivisibly tests and sets the memory location \fIaddr\fP.
E 5
I 5
\fIMset\fP indivisibly tests and sets the semaphore \fIsem\fP.
E 5
E 3
If the the previous value is zero, the process has acquired the lock
D 5
and \fImset\fP returns immediately.
If the previous value is non-zero, the ``want'' bit is set and
the test-and-set is retried;
if the lock is still unavailable \fImset\fP calls \fImsleep\fP and tries again.
E 5
I 5
and \fImset\fP returns true immediately.
Otherwise, if the \fIwait\fP flag is zero,
failure is returned.
If \fIwait\fP is true and the previous value is non-zero,
D 11
the ``want'' flag is set and the test-and-set is retried;
if the lock is still unavailable \fImset\fP relinquishes the processor
until notified that it should retry.
E 11
I 11
\fImset\fP relinquishes the processor until notified that it should retry.
E 11
E 5
D 3
.PP
E 3
I 3
.LP
E 3
To release a lock a process calls:
.DS
D 5
mclear(addr)
caddr_t addr;
E 5
I 5
mclear(sem)
semaphore *sem;
E 5
.DE
D 3
\fIMclear\fP indivisibly tests and clears the memory location addr.
E 3
I 3
D 5
\fIMclear\fP indivisibly tests and clears the memory location \fIaddr\fP.
E 3
If the ``want'' bit is zero in the previous value,
E 5
I 5
\fIMclear\fP indivisibly tests and clears the semaphore \fIsem\fP.
D 11
If the ``want'' flag is zero in the previous value,
E 11
I 11
If the ``WANT'' flag is zero in the previous value,
E 11
E 5
\fImclear\fP returns immediately.
D 5
If the ``want'' bit is non-zero in the previous value,
\fImclear\fP calls \fImwakeup\fP before returning.
E 5
I 5
D 11
If the ``want'' flag is non-zero in the previous value,
E 11
I 11
If the ``WANT'' flag is non-zero in the previous value,
E 11
\fImclear\fP arranges for waiting processes to retry before returning.
I 7
.PP
Two routines provide services analogous to the kernel
\fIsleep\fP and \fIwakeup\fP functions interpreted in the domain of
shared memory.
D 11
A process may relinquish the processor by calling \fImsleep\fP:
E 11
I 11
A process may relinquish the processor by calling \fImsleep\fP
with a set semaphore:
E 11
.DS
msleep(sem)
semaphore *sem;
.DE
D 11
The process will remain in a sleeping state
E 11
I 11
If the semaphore is still set when it is checked by the kernel,
the process will be put in a sleeping state
E 11
until some other process issues an \fImwakeup\fP for the same semaphore
within the region using the call:
.DS
mwakeup(sem)
semaphore *sem;
.DE
An \fImwakeup\fP may awaken all sleepers on the semaphore,
or may awaken only the next sleeper on a queue.
D 8
.PP
E 8
E 7
E 5
E 2
E 1

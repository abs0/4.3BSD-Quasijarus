h03002
s 00084/00063/00518
d D 1.7 88/04/22 21:15:21 mckusick 7 6
c edits from Mike
e
s 00046/00027/00535
d D 1.6 88/04/22 17:39:09 mckusick 6 5
c minor edits and cleanups
e
s 00049/00007/00513
d D 1.5 88/04/21 23:18:44 mckusick 5 4
c comments from reviewer #201
e
s 00019/00005/00501
d D 1.4 88/04/21 19:32:43 mckusick 4 3
c comments from reviewer #200
e
s 00084/00047/00422
d D 1.3 88/04/21 18:03:30 mckusick 3 2
c feedback from reviewer #204
e
s 00092/00069/00377
d D 1.2 88/02/20 00:57:30 mckusick 2 1
c edits from Mike
e
s 00446/00000/00000
d D 1.1 88/02/19 17:22:22 mckusick 1 0
c first draft
e
u
U
t
T
I 1
.\"	%W%	(Copyright 1988 M. K. McKusick)	%E%
.\" reference a system routine name
.de RN
D 7
\fI\\$1\fP\^()\\$2
E 7
I 7
\fI\\$1\fP\^(\h'1m/24u')\\$2
E 7
..
.\" reference a header name
.de H
.NH \\$1
\\$2
..
I 6
.\" begin figure
.\" .FI "title"
.nr Fn 0 1
.de FI
.ds Lb Figure \\n+(Fn
.ds Lt \\$1
.KF
.DS B
.nf
..
.\"
.\" end figure
.de Fe
D 7
.sp
E 7
I 7
.sp .5
E 7
.\" cheat: original indent is stored in \n(OI by .DS B; restore it
.\" then center legend after .DE rereads and centers the block.
\\\\.in \\n(OI
\\\\.ce
\\\\*(Lb.  \\\\*(Lt
D 7
.sp
E 7
I 7
.sp .5
E 7
.DE
.KE
.if \nd 'ls 2
..
E 6
.EQ
delim $$
.EN
.rm CM
I 6
.ds CH "
.ds CF "- % -
.nr PO 1.25i
E 6
.TL
Design of a General Purpose Memory Allocator for the 4.3BSD UNIX\(dg Kernel
.FS
\(dgUNIX is a registered trademark of AT&T in the US and other countries.
.FE
.AU
Marshall Kirk McKusick
.AU
Michael J. Karels
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, California  94720
.AB
D 3
This paper describes the current haphazard methods for allocating memory in
the 4.3BSD UNIX kernel.
Next it describes the requirements for a general purpose memory
allocator suitable for use in the kernel.
After describing the currently available memory allocators,
the paper describes how a hybrid of them are used to
implement a memory allocator suitable for all dynamic memory allocation
in the kernel.
It concludes with a discussion of our experience in using
E 3
I 3
The 4.3BSD UNIX kernel uses many memory allocation mechanisms,
each designed for the particular needs of the utilizing subsystem.
This paper describes a general purpose dynamic memory allocator
D 7
that can be used by all the kernel subsystems.
E 7
I 7
that can be used by all of the kernel subsystems.
E 7
The design of this allocator takes advantage of known memory usage
patterns in the UNIX kernel and a hybrid strategy that is time-efficient
for small allocations and space-efficient for large allocations.
This allocator replaces the multiple memory allocation interfaces 
with a single easy-to-program interface,
results in more efficient use of global memory by eliminating
partitioned and specialized memory pools,
D 7
and is quick enough that no performance loss relative to the
current implementations is observed.
E 7
I 7
and is quick enough that no performance loss is observed
relative to the current implementations.
E 7
The paper concludes with a discussion of our experience in using
E 3
the new memory allocator,
D 6
and directions for future improvements.
E 6
I 6
and directions for future work.
E 6
.AE
.LP
.H 1 "Kernel Memory Allocation in 4.3BSD
.PP
The 4.3BSD kernel has at least ten different memory allocators.
I 2
Some of them handle large blocks,
some of them handle small chained data structures,
and others include information to describe I/O operations.
E 2
Often the allocations are for small pieces of memory that are only
needed for the duration of a single system call.
In a user process such short-term
D 3
memory would be allocated on the runtime stack.
Because the kernel has a limited runtime stack,
E 3
I 3
memory would be allocated on the run-time stack.
Because the kernel has a limited run-time stack,
E 3
D 2
it is not feasible to allocate even small blocks of memory on it.
E 2
I 2
it is not feasible to allocate even moderate blocks of memory on it.
E 2
Consequently, such memory must be allocated through a more dynamic mechanism.
For example,
when the system must translate a pathname,
it must allocate a one kilobye buffer to hold the name.
D 3
.PP
E 3
D 2
Other blocks of memory must be more persistent than a single system call,
so really have to be allocated from dynamic memory.
E 2
I 2
Other blocks of memory must be more persistent than a single system call
and really have to be allocated from dynamic memory.
E 2
Examples include protocol control blocks that remain throughout
the duration of the network connection.
.PP
Demands for dynamic memory allocation in the kernel have increased
as more services have been added.
Each time a new type of memory allocation has been required,
a specialized memory allocation scheme has been written to handle it.
Often the new memory allocation scheme has been built on top
of an older allocator.
For example, the block device subsystem provides a crude form of
D 7
memory allocation through the allocation of empty buffers.
E 7
I 7
memory allocation through the allocation of empty buffers [Thompson78].
E 7
The allocation is slow because of the implied semantics of
finding the oldest buffer, pushing its contents to disk if they are dirty,
and moving physical memory into or out of the buffer to create 
D 7
the requested size [Thompson78].
E 7
I 7
the requested size.
E 7
D 2
To reduce the overhead a ``new'' memory allocator is built that
allocates a pool of empty buffers.
E 2
I 2
D 3
To reduce the overhead a ``new'' memory allocator is built
E 3
I 3
D 6
To reduce the overhead a ``new'' memory allocator was built in 4.3BSD
E 6
I 6
To reduce the overhead, a ``new'' memory allocator was built in 4.3BSD
E 6
E 3
for name translation that allocates a pool of empty buffers.
E 2
It keeps them on a free list so they can
be quickly allocated and freed [McKusick85].
.PP
This memory allocation method has several drawbacks.
First, the new allocator can only handle a limited range of sizes.
D 7
Second, it depletes the buffer pool as it steals memory intended
E 7
I 7
Second, it depletes the buffer pool, as it steals memory intended
E 7
to buffer disk blocks to other purposes.
Finally, it creates yet another interface of
which the programmer must be aware.
.PP
A generalized memory allocator is needed to reduce the complexity
of writing code inside the kernel.
Rather than providing many semi-specialized ways of allocating memory,
the kernel should provide a single general purpose allocator.
With only a single interface, 
D 3
programmers need not concern themselves with trying to figure
E 3
I 3
programmers do not need to figure
E 3
out the most appropriate way to allocate memory.
If a good general purpose allocator is available,
it helps avoid the syndrome of creating yet another special
purpose allocator.
.PP
D 2
To ease the task of understanding how to use the memory allocator,
it should have an interface similar to the interface
E 2
I 2
To ease the task of understanding how to use it,
the memory allocator should have an interface similar to the interface
E 2
D 3
provided by the well known memory allocator provided for
E 3
I 3
D 7
of the well known memory allocator provided for
E 7
I 7
of the well-known memory allocator provided for
E 7
E 3
applications programmers through the C library routines
.RN malloc
and
.RN free .
Like the C library interface,
the allocation routine should take a parameter specifying the
D 2
size of memory needed whose range  should not be constrained.
E 2
I 2
size of memory that is needed.
The range of sizes for memory requests should not be constrained.
E 2
The free routine should take a pointer to the storage being freed,
and should not require additional information such as the size
of the piece of memory being freed.
D 3
.H 1 "Criterion for a Kernel Memory Allocator
E 3
I 3
.H 1 "Criteria for a Kernel Memory Allocator
E 3
.PP
The design specification for a kernel memory allocator is similar to,
D 3
but not identical with,
the design criterion for a user level memory allocator.
E 3
I 3
but not identical to,
the design criteria for a user level memory allocator.
E 3
The first criterion for a memory allocator is that it make good use
of the physical memory.
Good use of memory is measured by the amount of memory needed to hold
a set of allocations at any point in time.
Percentage utilization is expressed as:
.EQ
D 2
utilization = used over allocated
E 2
I 2
utilization~=~requested over required
E 2
.EN
D 2
Here, ``used'' is the sum of the memory that has been requested
and ``allocated'' is the amount of memory that has been
allocated to the pool from which the requests are filled.
E 2
I 2
Here, ``requested'' is the sum of the memory that has been requested
and not yet freed.
``Required'' is the amount of memory that has been
allocated for the pool from which the requests are filled.
An allocator requires more memory than requested because of fragmentation
D 7
and to have a ready supply of free memory for future requests.
E 7
I 7
and a need to have a ready supply of free memory for future requests.
E 7
E 2
A perfect memory allocator would have a utilization of 100%.
In practice,
having a 50% utilization is considered good [Korn85].
.PP
Good memory utilization in the kernel is more important than
in user processes.
Because user processes run in virtual memory,
unused parts of their address space can be paged out.
D 2
Thus pages that are part of the ``allocated'' pool that are not
being ``used'' need not tie up physical memory.
E 2
I 2
D 3
Thus pages that are part of the ``required'' pool that are not
E 3
I 3
Thus pages in the process address space
that are part of the ``required'' pool that are not
E 3
being ``requested'' need not tie up physical memory.
E 2
Because the kernel is not paged,
D 2
all pages in the ``allocated'' pool are held by the kernel and
E 2
I 2
all pages in the ``required'' pool are held by the kernel and
E 2
cannot be used for other purposes.
D 3
Consequently, it is desirable to keep the utilization percentage
as high as possible.
D 2
It is also desirable to release memory from the ``allocated'' pool
rather than to hold them as is typically done with user processes.
E 2
I 2
It is also desirable to release memory from the ``required'' pool
E 3
I 3
To keep the kernel utilization percentage as high as possible,
it is desirable to release unused memory in the ``required'' pool
E 3
rather than to hold it as is typically done with user processes.
I 3
Because the kernel can directly manipulate its own page maps,
releasing unused memory is fast;
a user process must do a system call to release memory.
E 3
E 2
.PP
The most important criterion for a memory allocator is that it be fast.
D 3
Memory allocation is done frequently,
D 2
so a slow memory allocator will degrade the system performance.
E 2
I 2
as a slow memory allocator will degrade the system performance.
E 2
The kernel is more critical than user processes in this respect
E 3
I 3
Because memory allocation is done frequently,
a slow memory allocator will degrade the system performance.
Speed of allocation is more critical when executing in the
kernel than in user code,
E 3
because the kernel must allocate many data structure that user
D 2
programs would be able to (cheaply) allocate on their runtime stack.
E 2
I 2
D 3
programs would be able to allocate cheaply on their runtime stack.
E 3
I 3
processes can allocate cheaply on their run-time stack.
E 3
E 2
In addition, the kernel represents the platform on which all user
processes run,
D 7
so if it is slow, it will degrade the performance of every process
E 7
I 7
and if it is slow, it will degrade the performance of every process
E 7
that is running.
.PP
Another problem with a slow memory allocator is that programmers
D 2
of frequently used kernel interfaces will feel that they
E 2
I 2
of frequently-used kernel interfaces will feel that they
E 2
cannot afford to use it as their primary memory allocator. 
Instead they will build their own memory allocator on top of the
original by maintaining their own pool of memory blocks.
D 7
Creating such a specialized memory allocator has the 
problem of creating multiple interfaces of which
the programmer must be aware.
.PP
D 2
Multiple allocators also reduces the efficiency with which memory is used.
E 2
I 2
Multiple allocators also reduce the efficiency with which memory is used.
E 7
I 7
Multiple allocators reduce the efficiency with which memory is used.
E 7
E 2
The kernel ends up with many different free lists of memory
instead of a single free list from which all allocation can be drawn.
For example,
D 2
consider the case of two subsystem that need memory.
E 2
I 2
consider the case of two subsystems that need memory.
E 2
If they have their own free lists,
the amount of memory tied up in the two lists will be the
sum of the greatest amount of memory that each of
D 2
the two subsystems ever used.
E 2
I 2
the two subsystems has ever used.
E 2
D 6
If they share a freelist,
E 6
I 6
If they share a free list,
E 6
the amount of memory tied up in the free list may be as low as the
greatest amount of memory that either subsystem used.
As the number of subsystems grows,
D 6
the savings from having a single freelist grows.
E 6
I 6
D 7
the savings from having a single free list grows.
E 7
I 7
the savings from having a single free list grow.
E 7
E 6
D 2
.H 1 "Existing Implementations
E 2
I 2
.H 1 "Existing User-level Implementations
E 2
.PP
There are many different algorithms and
D 2
implementations of memory allocators.
E 2
I 2
implementations of user-level memory allocators.
E 2
A survey of those available on UNIX systems appeared in [Korn85].
D 2
Nearly all the memory allocators tested made good used of memory, 
E 2
I 2
D 7
Nearly all the memory allocators tested made good use of memory, 
E 7
I 7
Nearly all of the memory allocators tested made good use of memory, 
E 7
E 2
though most of them were too slow for use in the kernel.
D 3
The fastest memory allocator by nearly a factor of two,
E 3
I 3
The fastest memory allocator in the survey by nearly a factor of two
E 3
D 2
was the memory allocator provided on 4.2BSD.
E 2
I 2
was the memory allocator provided on 4.2BSD originally
written by Chris Kingsley at California Institute of Technology.
E 2
Unfortunately,
the 4.2BSD memory allocator also wasted twice as much memory
D 6
as its nearest competitor.
E 6
I 6
as its nearest competitor in the survey.
E 6
.PP
D 2
The 4.2BSD memory allocator works by maintaining a set of lists
that are ordered by powers of two.
E 2
I 2
The 4.2BSD user-level memory allocator works by maintaining a set of lists
that are ordered by increasing powers of two.
E 2
Each list contains a set of memory blocks of its corresponding size.
To fulfill a memory request, 
D 2
the size of the request is rounded up to the next power of two.
E 2
I 2
D 7
the size of the request is rounded up to the next power-of-two.
E 7
I 7
the size of the request is rounded up to the next power of two.
E 7
E 2
A piece of memory is then removed from the list corresponding
D 2
to the specified power of two and returned to the requester.
E 2
I 2
D 7
to the specified power-of-two and returned to the requester.
E 7
I 7
to the specified power of two and returned to the requester.
E 7
E 2
Thus, a request for a block of memory of size 53 returns
a block from the 64-sized list.
A typical memory allocation requires a roundup calculation
followed by a linked list removal.
Only if the list is empty is a real memory allocation done.
The free operation is also fast;
the block of memory is put back onto the list from which it came.
D 2
.H 1 "Problems and Solutions Unique to a Kernel Allocator
E 2
I 2
The correct list is identified by a size indicator stored
immediately preceding the memory block.
.H 1 "Considerations Unique to a Kernel Allocator
E 2
.PP
There are several special conditions that arise when writing a
memory allocator for the kernel that do not apply to a user process
memory allocator.
First, the maximum memory allocation can be determined at 
the time that the machine is booted.
This number is never more than the amount of physical memory on the machine,
and is typically much less since a machine with all its
D 2
memory dedicated to the operating system is uninteresting to run on.
E 2
I 2
memory dedicated to the operating system is uninteresting to use.
E 2
D 7
Thus the kernel can statically allocate a set of data structures
E 7
I 7
Thus, the kernel can statically allocate a set of data structures
E 7
to manage its dynamically allocated memory.
D 2
These data structures never need to be grown to accommodate
E 2
I 2
D 3
These data structures never need to be expanded to accommodate
E 2
memory requests, yet if properly designed need not be large.
.PP
E 3
I 3
These data structures never need to be
expanded to accommodate memory requests;
D 7
yet if properly designed they need not be large.
E 7
I 7
yet, if properly designed, they need not be large.
E 7
E 3
For a user process, the maximum amount of memory that may be allocated
is a function of the maximum size of its virtual memory.
Although it could allocate static data structures to manage
its entire virtual memory,
D 2
even if they were efficiently encoded they would be potentially huge.
The other alternative is to allocate data structures as they are needed,
however that adds extra complications such as what to do if it cannot
E 2
I 2
even if they were efficiently encoded they would potentially be huge.
The other alternative is to allocate data structures as they are needed.
D 7
However, that adds extra complications such as what to do if it cannot
E 2
allocate space for additional structures and how to link them all together.
E 7
I 7
However, that adds extra complications such as new
failure modes if it cannot allocate space for additional
structures and additional mechanisms to link them all together.
E 7
.PP
Another special condition of the kernel memory allocator is that it
can control its own address space.
Unlike user processes that can only grow and shrink their heap at one end,
the kernel can keep an arena of kernel addresses and allocate
pieces from that arena which it then populates with physical memory.
The effect is much the same as a user process that has parts of
its address space paged out when they are not in use,
except that the kernel can explicitly control the set of pages
allocated to its address space.
The result is that the ``working set'' of pages in use by the
kernel exactly corresponds to the set of pages that it is really using.
I 7
.FI "One day memory usage on a Berkeley time-sharing machine"
.so usage.tbl
.Fe
E 7
.PP
A final special condition that applies to the kernel is that
D 7
all the different uses of dynamic memory are known in advance.
E 7
I 7
all of the different uses of dynamic memory are known in advance.
E 7
Each one of these uses of dynamic memory can be assigned a type.
For each type of dynamic memory that is allocated,
the kernel can provide allocation limits.
One reason given for having separate allocators is that
no single allocator could starve the rest of the kernel of all
D 7
its available memory.
E 7
I 7
its available memory and thus a single runaway
client could not paralyze the system.
E 7
By putting limits on each type of memory,
the single general purpose memory allocator can provide the same
D 2
protection against memory starvation\(dg.
E 2
I 2
protection against memory starvation.\(dg
E 2
.FS
\(dgOne might seriously ask the question what good it is if ``only''
one subsystem within the kernel hangs if it is something like the
network on a diskless workstation.
.FE
I 4
D 6
.KF
.DS B
E 6
I 6
D 7
.FI "One day memory usage on a Berkeley timesharing machine"
E 6
.so usage.tbl
D 6
.DE
.ce
Figure 1 \- One day memory usage on a Berkeley timesharing machine.
.KE
E 6
I 6
.Fe
E 7
E 6
E 4
.PP
D 4
In profiling studies of the kernel, we found that most of its
E 4
I 4
D 6
Figure 1 shows the memory usage of the kernel over a one day period
E 6
I 6
\*(Lb shows the memory usage of the kernel over a one day period
E 6
on a general timesharing machine at Berkeley.
I 7
The ``In Use'', ``Free'', and ``Mem Use'' fields are instantaneous values;
the ``Requests'' field is the number of allocations since system startup;
the ``High Use'' field is the maximum value of 
the ``Mem Use'' field since system startup.
E 7
The figure demonstrates that most
E 4
allocations are for small objects.
Large allocations occur infrequently, 
D 3
and are typically for long lived objects
E 3
I 3
and are typically for long-lived objects
E 3
such as buffers to hold the superblock for
D 3
a file system when it is mounted.
E 3
I 3
a mounted file system.
E 3
D 4
Thus a memory allocator only needs to be fast for small pieces of memory.
E 4
I 4
Thus, a memory allocator only needs to be
fast for small pieces of memory.
E 4
.H 1 "Implementation of the Kernel Memory Allocator
.PP
In reviewing the available memory allocators,
none of their strategies could be used without some modification.
The kernel memory allocator that we ended up with is a hybrid
of the fast memory allocator found in the 4.2BSD C library
D 7
and a slower but more memory efficient first-fit allocator.
E 7
I 7
and a slower but more-memory-efficient first-fit allocator.
E 7
.PP
D 5
For maximum speed,
D 2
small allocations are done using the 4.2BSD power of two list strategy.
E 2
I 2
small allocations are done using the 4.2BSD power-of-two list strategy.
E 2
To avoid the cost of a subroutine call,
macros are provided to compute the list to use and remove an
element if it is available.
E 5
I 5
Small allocations are done using the 4.2BSD power-of-two list strategy;
the typical allocation requires only a computation of
the list to use and the removal of an element if it is available,
so it is quite fast.
Macros are provided to avoid the cost of a subroutine call.
E 5
Only if the request cannot be fulfilled from a list is a call
D 3
made into the allocator itself.
To insure that the allocator is always called for large requests,
E 3
I 3
made to the allocator itself.
To ensure that the allocator is always called for large requests,
E 3
the lists corresponding to large allocations are always empty.
I 5
D 6
Appendix 1 shows the data structures and implementation of the macros.
E 6
I 6
Appendix A shows the data structures and implementation of the macros.
E 6
E 5
.PP
Similarly, freeing a block of memory can be done with a macro.
The macro computes the list on which to place the request
and puts it there.
The free routine is called only if the block of memory is
D 6
large enough to be a page-based allocation.
E 6
I 6
considered to be a large allocation.
E 6
Including the cost of blocking out interrupts,
the allocation and freeing macros generate respectively
only nine and sixteen (simple) VAX instructions.
.PP
D 2
Because of the inefficiency of power of two allocation strategies
E 2
I 2
Because of the inefficiency of power-of-two allocation strategies
E 2
for large allocations,
a different strategy is used for allocations larger than two kilobytes.
The selection of two kilobytes is derived from our statistics on
the utilization of memory within the kernel,
that showed that 95 to 98% of allocations are of size one kilobyte or less.
I 2
D 6
The most frequent caller of the memory allocator
E 6
I 6
A frequent caller of the memory allocator
E 6
(the name translation function)
always requests a one kilobyte block.
E 2
Additionally the allocation method for large blocks is based on allocating
pieces of memory in multiples of pages.
D 7
Consequently the density of allocation for requests of size
E 7
I 7
Consequently the actual allocation size for requests of size
E 7
D 3
$2~times~pagesize$ or less are identical.
E 3
I 3
D 6
$2~times~pagesize$ or less are identical.\*(dg
E 6
I 6
$2~times~pagesize$ or less are identical.\(dg
E 6
.FS
D 6
\*(dgTo understand why this number is $2~times~pagesize$ one observes
that the power-of-two algorithm yields sizes of 1, 2, 4, 8, ...
E 6
I 6
\(dgTo understand why this number is $size 8 {2~times~pagesize}$ one
D 7
observes that the power-of-two algorithm yields sizes of 1, 2, 4, 8, \fIetc.\fP
E 7
I 7
observes that the power-of-two algorithm yields sizes of 1, 2, 4, 8, \&...
E 7
E 6
pages while the large block algorithm that allocates in multiples
D 6
of pages yields sizes of 1, 2, 3, 4, ... pages.
E 6
I 6
D 7
of pages yields sizes of 1, 2, 3, 4, \fIetc.\fP pages.
E 7
I 7
of pages yields sizes of 1, 2, 3, 4, \&... pages.
E 7
E 6
Thus for allocations of sizes between one and two pages
both algorithms use two pages;
it is not until allocations of sizes between two and three pages
that a difference emerges where the power-of-two algorithm will use
four pages while the large block algorithm will use three pages.
.FE
E 3
D 2
On the VAX, the (software) page size is one kilobyte,
E 2
I 2
In 4.3BSD on the VAX, the (software) page size is one kilobyte,
E 2
so two kilobytes is the smallest logical cutoff.
.PP
Large allocations are first rounded up to be a multiple of the page size.
D 2
The allocator then does a first-fit for the allocation from the
E 2
I 2
The allocator then uses a first-fit algorithm to find space in the
E 2
kernel address arena set aside for dynamic allocations.
Thus a request for a five kilobyte piece of memory will use exactly
D 2
five pages of memory rather than eight kilobytes as the power of two
allocation strategy would use.
E 2
I 2
five pages of memory rather than eight kilobytes as with
the power-of-two allocation strategy.
I 4
When a large piece of memory is freed,
D 7
the memory pages are returned to the free memory pool
E 7
I 7
the memory pages are returned to the free memory pool,
E 7
and the address space is returned to the kernel address arena
where it is coalesced with adjacent free pieces.
E 4
E 2
.PP
D 2
Another technique to both improve the efficiency of memory utilization
and to speed allocation,
is to cluster same sized small allocations on a page.
When a list for a power of two allocation is empty,
a new page is allocated and entirely broken up into pieces of
the needed size.
This speeds future allocations since several pieces of memory
E 2
I 2
D 3
Another technique both to improve the efficiency of memory utilization
and to speed allocation
E 3
I 3
Another technique to improve both the efficiency of memory utilization
and the speed of allocation
E 3
is to cluster same-sized small allocations on a page.
When a list for a power-of-two allocation is empty,
a new page is allocated and divided into pieces of the needed size.
This strategy speeds future allocations as several pieces of memory
E 2
become available as a result of the call into the allocator.
.PP
I 6
.FI "Calculation of allocation size"
.so alloc.fig
.Fe
E 6
D 2
Same size allocation per page improves the memory efficiency.
Instead of storing the size of each piece of memory with the piece itself,
E 2
I 2
Because the size is not specified when a block of memory is freed,
the allocator must keep track of the sizes of the pieces it has handed out.
The 4.2BSD user-level allocator stores the size of each block
in a header just before the allocation.
D 5
However, this strategy degrades memory efficiency for allocations that
E 5
I 5
However, this strategy doubles the memory requirement for allocations that
E 5
require a power-of-two-sized block.
Therefore,
instead of storing the size of each piece of memory with the piece itself,
E 2
the size information is associated with the memory page.
D 3
To determine the size of a piece of memory that is being freed,
the kernel calculates the page in which it resides,
and looks up the size associated with that page.
E 3
I 3
D 4
Figure 1 shows how the kernel determines
E 4
I 4
D 6
Figure 2 shows how the kernel determines
E 6
I 6
\*(Lb shows how the kernel determines
E 6
E 4
the size of a piece of memory that is being freed,
by calculating the page in which it resides,
and looking up the size associated with that page.
D 6
.KF
.DS B
.so alloc.fig
.DE
.ce
D 4
Figure 1 \- Calculation of allocation size.
E 4
I 4
Figure 2 \- Calculation of allocation size.
E 4
.KE
E 6
E 3
Eliminating the cost of the overhead per piece improved utilization
far more than expected.
The reason is that many allocations in the kernel are for blocks of 
D 2
memory that are a power of two in size.
Previously these requests had been nearly doubled to make room for
the size information.
E 2
I 2
D 7
memory whose size is a power-of-two.
E 7
I 7
memory whose size is exactly a power of two.
E 7
These requests would be nearly doubled if the user-level strategy were used.
E 2
Now they can be accommodated with no wasted memory.
I 3
.PP
D 7
The allocator can be called both from the top half of the kernel
that is willing to wait for memory to become available,
E 7
I 7
The allocator can be called both from the top half of the kernel,
which is willing to wait for memory to become available,
E 7
and from the interrupt routines in the bottom half of the kernel
that cannot wait for memory to become available.
Clients indicate their willingness (and ability) to wait with a flag
to the allocation routine.
For clients that are willing to wait,
the allocator guarrentees that their request will succeed.
Thus, these clients can need not check the return value from the allocator.
If memory is unavailable and the client cannot wait,
the allocator returns a null pointer.
D 7
These clients must be prepared to cope with this (infrequent) condition
E 7
I 7
These clients must be prepared to cope with this
(hopefully infrequent) condition
E 7
(usually by giving up and hoping to do better later).
E 3
.H 1 "Results of the Implementation
.PP
The new memory allocator was written about a year ago.
Conversion from the old memory allocators to the new allocator
D 7
have been going on ever since.
E 7
I 7
has been going on ever since.
E 7
Many of the special purpose allocators have been eliminated.
This list includes
.RN calloc ,
.RN wmemall ,
and 
.RN zmemall .
I 2
D 3
Most of the uses of
.RN m_get
as a general purpose allocator have been
converted to use the new allocator.
E 3
E 2
Many of the special purpose memory allocators built on
top of other allocators have also been eliminated.
For example, the allocator that was built on top of the buffer pool allocator
.RN geteblk
to allocate pathname buffers in 
.RN namei
has been eliminated.
Because the typical allocation is so fast,
we have found that none of the special purpose pools are needed.
D 2
Indeed, the allocation is about the same as the cost of
E 2
I 2
Indeed, the allocation is about the same as the previous cost of
E 2
D 7
allocating buffers from the network pool (``mbufs'').
E 7
I 7
allocating buffers from the network pool (\fImbuf\fP\^s).
E 7
Consequently applications that used to allocate network
D 3
buffers for their own uses can be switched over to using
E 3
I 3
buffers for their own uses have been switched over to using
E 3
D 5
the general purpose allocator without loss in performance.
E 5
I 5
the general purpose allocator without increasing their running time.
E 5
.PP
I 5
Quantifying the performance of the allocator is difficult because
it is hard to measure the amount of time spent allocating
and freeing memory in the kernel.
The usual approach is to compile a kernel for profiling
and then compare the running time of the routines that
implemented the old abstraction versus those that implement the new one.
The old routines are difficult to quantify because
individual routines were used for more than one purpose.
For example, the
.RN geteblk
routine was used both to allocate one kilobyte memory blocks
and for its intended purpose of providing buffers to the filesystem.
Differentiating these uses is often difficult.
To get a measure of the cost of memory allocation before
putting in our new allocator,
we summed up the running time of all the routines whose
exclusive task was memory allocation.
To this total we added the fraction
of the running time of the multi-purpose routines that could
clearly be identified as memory allocation usage.
This number showed that approximately three percent of
the time spent in the kernel could be accounted to memory allocation.
.PP
The new allocator is difficult to measure
because the usual case of the memory allocator is implemented as a macro.
Thus, its running time is a small fraction of the running time of the
numerous routines in the kernel that use it.
To get a bound on the cost,
D 7
we changed the macro to always call the memory allocation routine.
E 7
I 7
we changed the macro always to call the memory allocation routine.
E 7
Running in this mode, the memory allocator accounted for six percent
of the time spent in the kernel.
Factoring out the cost of the statistics collection and the
subroutine call overhead for the cases that could
normally be handled by the macro,
we estimate that the allocator would account for
D 7
approximate four percent of time in the kernel.
E 7
I 7
at most four percent of time in the kernel.
E 7
These measurements show that the new allocator does not introduce
significant new run-time costs.
.PP
E 5
The other major success has been in keeping the size information
D 7
on a per page basis.
E 7
I 7
on a per-page basis.
E 7
D 2
This technique allowed the most frequently requested sizes to be
allocated without wastage.
E 2
I 2
D 3
This technique allowed the most-frequently-requested sizes to be
E 3
I 3
This technique allows the most frequently requested sizes to be
E 3
allocated without waste.
E 2
D 3
It also reduced the amount of bookkeeping information associated
E 3
I 3
It also reduces the amount of bookkeeping information associated
E 3
D 7
with the allocator to a compact four kilobytes of information
E 7
I 7
with the allocator to four kilobytes of information
E 7
per megabyte of memory under management (with a one kilobyte page size).
.H 1 "Future Work
.PP
D 7
Our next immediate project is to convert many of the static
E 7
I 7
Our next project is to convert many of the static
E 7
D 2
kernel tables to being dynamically allocated.
Static tables include the process table, the file table, the inodes table,
E 2
I 2
kernel tables to be dynamically allocated.
Static tables include the process table, the file table,
E 2
and the mount table.
Making these tables dynamic will have two benefits.
First, it will reduce the amount of memory
that must be statically allocated at boot time.
D 2
Second it will eliminate the arbitrary upper limit imposed
E 2
I 2
Second, it will eliminate the arbitrary upper limit imposed
E 2
D 7
by the current static sizing.
E 7
I 7
by the current static sizing
(although a limit will be retained to constrain runaway clients).
E 7
Other researchers have already shown the memory savings
achieved by this conversion [Rodriguez88].
.PP
Under the current implementation,
D 2
memory is never moved from one sized list to another.
E 2
I 2
memory is never moved from one size list to another.
E 2
D 7
With the 4.2BSD memory allocator this causes problems
E 7
I 7
With the 4.2BSD memory allocator this causes problems,
E 7
particularly for large allocations where a process may use
a quarter megabyte piece of memory once,
D 7
that is then never available for any other size request.
E 7
I 7
which is then never available for any other size request.
E 7
In our hybrid scheme,
D 7
memory can be shuffled between large requests so large blocks
E 7
I 7
memory can be shuffled between large requests so that large blocks
E 7
of memory are never stranded as they are with the 4.2BSD allocator.
D 7
However pages allocated to small requests are allocated once
E 7
I 7
However, pages allocated to small requests are allocated once
E 7
to a particular size and never changed thereafter.
If a burst of requests came in for a particular size,
D 7
that particular size would acquire a large amount of memory
E 7
I 7
that size would acquire a large amount of memory
E 7
that would then not be available for other future requests.
D 2
In practice, we do not find that such behavior occurs,
however we have been investigating ways to handles such problems
if they become problematical in the future.
E 2
.PP
D 2
Our current investigations have involved having a routine
E 2
I 2
In practice, we do not find that the free lists become too large.
D 4
However, we have been investigating ways to handles such problems
E 4
I 4
However, we have been investigating ways to handle such problems
E 4
if they occur in the future.
Our current investigations involve a routine
E 2
that can run as part of the idle loop that would sort the elements
on each of the free lists into order of increasing address.
Since any given page has only one size of elements allocated from it,
the effect of the sorting would be to sort the list into distinct pages.
When all the pieces of a page became free,
the page itself could be released back to the free pool so that 
it could be allocated to another purpose.
Although there is no guarantee that all the pieces of a page would ever
be freed,
D 2
most allocations are short-lived lasting only the duration of
E 2
I 2
D 7
most allocations are short-lived, lasting only the duration of
E 7
I 7
most allocations are short-lived, lasting only for the duration of
E 7
E 2
an open file descriptor, an open network connection, or a system call.
D 2
Since new allocations would be concentrated from the page sorted to
E 2
I 2
D 7
As new allocations would be concentrated from the page sorted to
E 7
I 7
As new allocations would be made from the page sorted to
E 7
E 2
the front of the list,
D 7
returns of elements from pages at the back would eventually
E 7
I 7
return of elements from pages at the back would eventually
E 7
allow pages later in the list to be freed.
I 2
D 7
.\" clists -> mbufs (streams)
.\" bufferpool -> VM physical page management
E 7
I 7
.PP
Two of the traditional UNIX
memory allocators remain in the current system.
The terminal subsystem uses \fIclist\fP\^s (character lists).
That part of the system is expected to undergo major revision within
the the next year or so, and it will probably be changed to use
\fImbuf\fP\^s as it is merged into the network system.
The other major allocator that remains is
.RN getblk ,
the routine that manages the filesystem buffer pool memory
and associated control information.
Only the filesystem uses
.RN getblk
in the current system;
it manages the constant-sized buffer pool.
We plan to merge the filesystem buffer cache into the virtual memory system's
page cache in the future.
This change will allow the size of the buffer pool to be changed
according to memory load,
but will require a policy for balancing memory needs
with filesystem cache performance.
E 7
E 2
.H 1 "Acknowledgments
.PP
In the spirit of community support,
we have made various versions of our allocator available to our test sites.
They have been busily burning it in and giving
us feedback on their experiences.
We acknowledge their invaluable input.
I 5
The feedback from the Usenix program committee on the initial draft of
our paper suggested numerous important improvements.
E 5
.H 1 "References
D 7
.sp
E 7
I 7
.LP
E 7
.IP Korn85 \w'Rodriguez88\0\0'u
David Korn, Kiem-Phong Vo,
``In Search of a Better Malloc''
\fIProceedings of the Portland Usenix Conference\fP,
pp 489-506, June 1985.
D 7
.sp
E 7
.IP McKusick85
D 7
M. McKusick, M. Karels, S.Leffler,
E 7
I 7
M. McKusick, M. Karels, S. Leffler,
E 7
``Performance Improvements and Functional Enhancements in 4.3BSD''
\fIProceedings of the Portland Usenix Conference\fP,
pp 519-531, June 1985.
D 7
.sp
E 7
.IP Rodriguez88
Robert Rodriguez, Matt Koehler, Larry Palmer, Ricky Palmer,
``A Dynamic UNIX Operating System''
D 7
Digital Equipment Corporation, ULTRIX Engineering, Nashua, NH 03062,
To appear.
E 7
I 7
\fIProceedings of the San Francisco Usenix Conference\fP,
June 1988.
E 7
.IP Thompson78
Ken Thompson,
``UNIX Implementation''
\fIBell System Technical Journal\fP, volume 57, number 6,
pp 1931-1946, 1978.
E 1

h03680
s 00004/00003/00153
d D 6.3 86/06/05 09:51:56 karels 4 3
c formatting glitches
e
s 00053/00021/00103
d D 6.2 86/06/04 23:53:02 karels 3 2
c updates for 4.3
e
s 00000/00000/00124
d D 6.1 86/05/26 13:25:25 mckusick 2 1
c 4.3BSD beta release document
e
s 00124/00000/00000
d D 5.1 86/05/26 13:25:16 mckusick 1 0
c document distributed with 4.2BSD
e
u
U
t
T
I 1
D 3
.\" Copyright (c) 1983 Regents of the University of California.
E 3
I 3
.\" Copyright (c) 1983,1986 Regents of the University of California.
E 3
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.nr H2 1
D 3
.ds RH "Memory management
E 3
I 3
.\".ds RH "Memory management
I 4
.br
.ne 2i
E 4
E 3
.NH
\s+2Memory management\s0
.PP
A single mechanism is used for data storage: memory buffers, or
\fImbuf\fP's.  An mbuf is a structure of the form:
.DS
._f
struct mbuf {
	struct	mbuf *m_next;		/* next buffer in chain */
	u_long	m_off;			/* offset of data */
	short	m_len;			/* amount of data in this mbuf */
	short	m_type;			/* mbuf type (accounting) */
	u_char	m_dat[MLEN];		/* data storage */
	struct	mbuf *m_act;		/* link in higher-level mbuf list */
};
.DE
The \fIm_next\fP field is used to chain mbufs together on linked
D 3
lists, while the \fIm_act\fP field allows lists of mbufs to be
E 3
I 3
lists, while the \fIm_act\fP field allows lists of mbuf chains to be
E 3
accumulated.  By convention, the mbufs common to a single object
(for example, a packet) are chained together with the \fIm_next\fP
field, while groups of objects are linked via the \fIm_act\fP
field (possibly when in a queue).
.PP
Each mbuf has a small data area for storing information, \fIm_dat\fP.
The \fIm_len\fP field indicates the amount of data, while the \fIm_off\fP
field is an offset to the beginning of the data from the base of the
mbuf.  Thus, for example, the macro \fImtod\fP, which converts a pointer
to an mbuf to a pointer to the data stored in the mbuf, has the form
.DS
._d
D 3
#define	mtod(x,t)	((t)((int)(x) + (x)->m_off))
E 3
I 3
#define	mtod(\fIx\fP,\fIt\fP)	((\fIt\fP)((int)(\fIx\fP) + (\fIx\fP)->m_off))
E 3
.DE
D 3
(note the \fIt\fP parameter, a C type cast, is used to cast
E 3
I 3
(note the \fIt\fP parameter, a C type cast, which is used to cast
E 3
the resultant pointer for proper assignment).
.PP
In addition to storing data directly in the mbuf's data area, data
of page size may be also be stored in a separate area of memory.
The mbuf utility routines maintain
a pool of pages for this purpose and manipulate a private page map
D 3
for such pages.  The virtual addresses of
these data pages precede those of mbufs, so when pages of data are
separated from an mbuf, the mbuf data offset is a negative value.
E 3
I 3
for such pages.
An mbuf with an external data area may be recognized by the larger
offset to the data area;
this is formalized by the macro M_HASCL(\fIm\fP), which is true
if the mbuf whose address is \fIm\fP has an external page cluster.
E 3
An array of reference counts on pages is also maintained
so that copies of pages may be made without core to core
D 3
copying  (copies are created simply by duplicating the relevant
page table entries in the data page map and incrementing the associated
reference counts for the pages).  Separate data pages are currently
used only
E 3
I 3
copying  (copies are created simply by duplicating the reference to the data
and incrementing the associated reference counts for the pages).
Separate data pages are currently used only
E 3
when copying data from a user process into the kernel,
and when bringing data in at the hardware level.  Routines which
D 3
manipulate mbufs are not normally aware if data is stored directly in 
E 3
I 3
manipulate mbufs are not normally aware whether data is stored directly in 
E 3
the mbuf data array, or if it is kept in separate pages.
.PP
I 3
The following may be used to allocate and free mbufs:
.LP
m = m_get(wait, type);
.br
MGET(m, wait, type);
.IP
The subroutine \fIm_get\fP and the macro \fIMGET\fP
each allocate an mbuf, placing its address in \fIm\fP.
The argument \fIwait\fP is either M_WAIT or M_DONTWAIT according
to whether allocation should block or fail if no mbuf is available.
The \fItype\fP is one of the predefined mbuf types for use in accounting
of mbuf allocation.
.IP "MCLGET(m);"
This macro attempts to allocate an mbuf page cluster
to associate with the mbuf \fIm\fP.
If successful, the length of the mbuf is set to CLSIZE,
the size of the page cluster.
.LP
n = m_free(m);
.br
MFREE(m,n);
.IP
D 4
The routine f\Im_free\fP and the macro \fIMFREE\fP
E 4
I 4
The routine \fIm_free\fP and the macro \fIMFREE\fP
E 4
each free a single mbuf, \fIm\fP, and any associated external storage area,
placing a pointer to its successor in the chain it heads, if any, in \fIn\fP.
.IP "m_freem(m);"
This routine frees an mbuf chain headed by \fIm\fP.
.PP
E 3
The following utility routines are available for manipulating mbuf
chains:
.IP "m = m_copy(m0, off, len);"
.br
The \fIm_copy\fP routine create a copy of all, or part, of a
list of the mbufs in \fIm0\fP.  \fILen\fP bytes of data, starting 
\fIoff\fP bytes from the front of the chain, are copied. 
Where possible, reference counts on pages are used instead
of core to core copies.  The original mbuf chain must have at
least \fIoff\fP + \fIlen\fP bytes of data.  If \fIlen\fP is
specified as M_COPYALL, all the data present, offset
as before, is copied.  
.IP "m_cat(m, n);"
.br
The mbuf chain, \fIn\fP, is appended to the end of \fIm\fP.
Where possible, compaction is performed.
.IP "m_adj(m, diff);"
.br
The mbuf chain, \fIm\fP is adjusted in size by \fIdiff\fP
bytes.  If \fIdiff\fP is non-negative, \fIdiff\fP bytes
are shaved off the front of the mbuf chain.  If \fIdiff\fP
is negative, the alteration is performed from back to front.
D 3
No space is reclaimed in this operation, alterations are
E 3
I 3
No space is reclaimed in this operation; alterations are
E 3
accomplished by changing the \fIm_len\fP and \fIm_off\fP
fields of mbufs.
.IP "m = m_pullup(m0, size);"
.br
After a successful call to \fIm_pullup\fP, the mbuf at
the head of the returned list, \fIm\fP, is guaranteed
to have at least \fIsize\fP
D 3
bytes of data in contiguous memory (allowing access via
a pointer, obtained using the \fImtod\fP macro).
E 3
I 3
bytes of data in contiguous memory within the data area of the mbuf
(allowing access via a pointer, obtained using the \fImtod\fP macro,
and allowing the mbuf to be located from a pointer to the data area
using \fIdtom\fP, defined below).
E 3
If the original data was less than \fIsize\fP bytes long,
\fIlen\fP was greater than the size of an mbuf data
area (112 bytes), or required resources were unavailable,
\fIm\fP is 0 and the original mbuf chain is deallocated.
.IP
This routine is particularly useful when verifying packet
header lengths on reception.  For example, if a packet is
received and only 8 of the necessary 16 bytes required
for a valid packet header are present at the head of the list
of mbufs representing the packet, the remaining 8 bytes
may be ``pulled up'' with a single \fIm_pullup\fP call.
If the call fails the invalid packet will have been discarded.
.PP
D 3
By insuring mbufs always reside on 128 byte boundaries
it is possible to always locate the mbuf associated with a data
E 3
I 3
By insuring that mbufs always reside on 128 byte boundaries,
it is always possible to locate the mbuf associated with a data
E 3
area by masking off the low bits of the virtual address.
This allows modules to store data structures in mbufs and
pass them around without concern for locating the original
mbuf when it comes time to free the structure.
I 3
Note that this works only with objects stored in the internal data
buffer of the mbuf.
E 3
The \fIdtom\fP macro is used to convert a pointer into an mbuf's
data area to a pointer to the mbuf,
.DS
#define	dtom(x)	((struct mbuf *)((int)x & ~(MSIZE-1)))
.DE
.PP
Mbufs are used for dynamically allocated data structures such as
D 3
sockets, as well as memory allocated for packets.  Statistics are
E 3
I 3
sockets as well as memory allocated for packets and headers.  Statistics are
E 3
maintained on mbuf usage and can be viewed by users using the
D 4
\fInetstat\fP(1) program.
D 3
.ds RH "Internal layering
.bp
E 3
I 3
'ne 2i
E 4
I 4
\fInetstat\fP\|(1) program.
E 4
E 3
E 1

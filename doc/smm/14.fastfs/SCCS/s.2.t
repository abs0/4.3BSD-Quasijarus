h46378
s 00045/00031/00071
d D 6.1 86/05/14 16:45:30 kjd 2 1
c 4.3BSD beta release document
e
s 00102/00000/00000
d D 5.1 86/05/14 16:45:09 kjd 1 0
c document distributed with 4.2BSD
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
.\" Copyright (c) 1986 Regents of the University of California.
E 2
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.ds RH Old file system
.NH
Old File System
.PP
D 2
In the old file system developed at Bell Laboratories
each disk drive contains one or more file systems.\(dg
E 2
I 2
In the file system developed at Bell Laboratories
(the ``traditional'' file system),
each disk drive is divided into one or more
partitions.  Each of these disk partitions may contain
one file system.  A file system never spans multiple
partitions.\(dg
E 2
.FS
D 2
\(dg A file system always resides on a single drive.
E 2
I 2
\(dg By ``partition'' here we refer to the subdivision of
physical space on a disk drive.  In the traditional file
system, as in the new file system, file systems are really
located in logical disk partitions that may overlap.  This
overlapping is made available, for example,
to allow programs to copy entire disk drives containing multiple
file systems.
E 2
.FE
A file system is described by its super-block,
which contains the basic parameters of the file system.
These include the number of data blocks in the file system,
a count of the maximum number of files,
D 2
and a pointer to a list of free blocks.
All the free blocks in the system are chained together in
a linked list.
E 2
I 2
and a pointer to the \fIfree list\fP, a linked
list of all the free blocks in the file system.
.PP
E 2
Within the file system are files.
Certain files are distinguished as directories and contain
pointers to files that may themselves be directories.
Every file has a descriptor associated with it called an
.I "inode".
D 2
The inode contains information describing ownership of the file,
E 2
I 2
An inode contains information describing ownership of the file,
E 2
time stamps marking last modification and access times for the file,
and an array of indices that point to the data blocks for the file.
For the purposes of this section, we assume that the first 8 blocks
of the file are directly referenced by values stored
D 2
in the inode structure itself*.
E 2
I 2
in an inode itself*.
E 2
.FS
* The actual number may vary from system to system, but is usually in
the range 5-13.
.FE
D 2
The inode structure may also contain references to indirect blocks
E 2
I 2
An inode may also contain references to indirect blocks
E 2
containing further data block indices.
In a file system with a 512 byte block size, a singly indirect
block contains 128 further block addresses,
D 2
a doubly indirect block contains 128 addresses of further single indirect
E 2
I 2
a doubly indirect block contains 128 addresses of further singly indirect
E 2
blocks,
and a triply indirect block contains 128 addresses of further doubly indirect
blocks.
.PP
D 2
A traditional 150 megabyte UNIX file system consists
E 2
I 2
A 150 megabyte traditional UNIX file system consists
E 2
of 4 megabytes of inodes followed by 146 megabytes of data.
This organization segregates the inode information from the data;
D 2
thus accessing a file normally incurs a long seek from its inode to its data.
E 2
I 2
thus accessing a file normally incurs a long seek from the
file's inode to its data.
E 2
Files in a single directory are not typically allocated
D 2
slots in consecutive locations in the 4 megabytes of inodes,
causing many non-consecutive blocks to be accessed when executing
operations on all the files in a directory.
E 2
I 2
consecutive slots in the 4 megabytes of inodes,
causing many non-consecutive blocks of inodes
to be accessed when executing
operations on the inodes of several files in a directory.
E 2
.PP
The allocation of data blocks to files is also suboptimum.
The traditional
file system never transfers more than 512 bytes per disk transaction
and often finds that the next sequential data block is not on the same
cylinder, forcing seeks between 512 byte transfers.
The combination of the small block size,
limited read-ahead in the system,
and many seeks severely limits file system throughput.
.PP
The first work at Berkeley on the UNIX file system attempted to improve both
reliability and throughput.
D 2
The reliability was improved by changing the file system so that
all modifications of critical information were staged so that they could
either be completed or repaired cleanly
by a program after a crash [Kowalski78].
E 2
I 2
The reliability was improved by staging modifications
to critical file system information so that they could
either be completed or repaired cleanly by a program
after a crash [Kowalski78].
E 2
The file system performance was improved by a factor of more than two by
changing the basic block size from 512 to 1024 bytes.
D 2
The increase was because of two factors;
E 2
I 2
The increase was because of two factors:
E 2
each disk transfer accessed twice as much data, 
D 2
and most files could be described without need to access through
any indirect blocks since the direct blocks contained twice as much data.
E 2
I 2
and most files could be described without need to access
indirect blocks since the direct blocks contained twice as much data.
E 2
The file system with these changes will henceforth be referred to as the
.I "old file system."
.PP
This performance improvement gave a strong indication that
increasing the block size was a good method for improving
throughput.
Although the throughput had doubled, 
the old file system was still using only about
four percent of the disk bandwidth.
The main problem was that although the free list was initially
ordered for optimal access,
it quickly became scrambled as files were created and removed.
D 2
Eventually the free list became entirely random
E 2
I 2
Eventually the free list became entirely random,
E 2
causing files to have their blocks allocated randomly over the disk.
D 2
This forced the disk to seek before every block access.
E 2
I 2
This forced a seek before every block access.
E 2
Although old file systems provided transfer rates of up
to 175 kilobytes per second when they were first created,
this rate deteriorated to 30 kilobytes per second after a
D 2
few weeks of moderate use because of randomization of their free block list.
There was no way of restoring the performance an old file system
E 2
I 2
few weeks of moderate use because of this
randomization of data block placement.
There was no way of restoring the performance of an old file system
E 2
except to dump, rebuild, and restore the file system.
D 2
Another possibility would be to have a process that periodically
reorganized the data on the disk to restore locality as
suggested by [Maruyama76].
E 2
I 2
Another possibility, as suggested by [Maruyama76],
would be to have a process that periodically
reorganized the data on the disk to restore locality.
E 2
.ds RH New file system
D 2
.bp
E 2
I 2
.sp 2
.ne 1i
E 2
E 1

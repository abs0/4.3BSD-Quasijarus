h15095
s 00122/00107/00144
d D 6.1 86/05/14 16:48:10 kjd 2 1
c 4.3BSD beta release document
e
s 00251/00000/00000
d D 5.1 86/05/14 16:47:45 kjd 1 0
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
.ds RH Functional enhancements
.NH 
File system functional enhancements
.PP
D 2
The speed enhancements to the UNIX file system did not require
any changes to the semantics or data structures viewed by the
users.
However several changes have been generally desired for some 
time but have not been introduced because they would require users to 
E 2
I 2
The performance enhancements to the
UNIX file system did not require
any changes to the semantics or
data structures visible to application programs.
However, several changes had been generally desired for some 
time but had not been introduced because they would require users to 
E 2
dump and restore all their file systems.
Since the new file system already
D 2
requires that all existing file systems
E 2
I 2
required all existing file systems to
E 2
be dumped and restored, 
D 2
these functional enhancements have been introduced at this time.
E 2
I 2
these functional enhancements were introduced at this time.
E 2
.NH 2
Long file names
.PP
File names can now be of nearly arbitrary length.
D 2
The only user programs affected by this change are
those that access directories.
To maintain portability among UNIX systems that
E 2
I 2
Only programs that read directories are affected by this change.
To promote portability to UNIX systems that
E 2
are not running the new file system, a set of directory
D 2
access routines have been introduced that provide a uniform
E 2
I 2
access routines have been introduced to provide a consistent
E 2
interface to directories on both old and new systems.
.PP
D 2
Directories are allocated in units of 512 bytes.
E 2
I 2
Directories are allocated in 512 byte units called chunks.
E 2
This size is chosen so that each allocation can be transferred
D 2
to disk in a single atomic operation.
Each allocation unit contains variable-length directory entries.
Each entry is wholly contained in a single allocation unit.
The first three fields of a directory entry are fixed and contain
an inode number, the length of the entry, and the length
of the name contained in the entry.
Following this fixed size information is the null terminated name,
padded to a 4 byte boundary.
The maximum length of a name in a directory is currently 255 characters.
E 2
I 2
to disk in a single operation.
Chunks are broken up into variable length records termed
directory entries.  A directory entry
contains the information necessary to map the name of a
file to its associated inode.
No directory entry is allowed to span multiple chunks.
The first three fields of a directory entry are fixed length
and contain: an inode number, the size of the entry, and the length
of the file name contained in the entry.
The remainder of an entry is variable length and contains
a null terminated file name, padded to a 4 byte boundary.
The maximum length of a file name in a directory is
currently 255 characters.
E 2
.PP
D 2
Free space in a directory is held by
entries that have a record length that exceeds the space
required by the directory entry itself.
All the bytes in a directory unit are claimed by the directory entries.
This normally results in the last entry in a directory being large.
When entries are deleted from a directory,
the space is returned to the previous entry in the same directory
unit by increasing its length.
If the first entry of a directory unit is free, then its 
inode number is set to zero to show that it is unallocated.
E 2
I 2
Available space in a directory is recorded by having
one or more entries accumulate the free space in their
entry size fields.  This results in directory entries
that are larger than required to hold the
entry name plus fixed length fields.  Space allocated
to a directory should always be completely accounted for
by totaling up the sizes of its entries.
When an entry is deleted from a directory,
its space is returned to a previous entry
in the same directory chunk by increasing the size of the
previous entry by the size of the deleted entry.
If the first entry of a directory chunk is free, then 
the entry's inode number is set to zero to indicate
that it is unallocated.
E 2
.NH 2
File locking
.PP
The old file system had no provision for locking files.
Processes that needed to synchronize the updates of a
D 2
file had to create a separate ``lock'' file to synchronize
their updates.
E 2
I 2
file had to use a separate ``lock'' file.
E 2
A process would try to create a ``lock'' file. 
D 2
If the creation succeeded, then it could proceed with its update;
if the creation failed, then it would wait, and try again.
E 2
I 2
If the creation succeeded, then the process
could proceed with its update;
if the creation failed, then the process would wait and try again.
E 2
This mechanism had three drawbacks.
D 2
Processes consumed CPU time, by looping over attempts to create locks.
Locks were left lying around following system crashes and had
to be cleaned up by hand.
E 2
I 2
Processes consumed CPU time by looping over attempts to create locks.
Locks left lying around because of system crashes had
to be manually removed (normally in a system startup command script).
E 2
Finally, processes running as system administrator
are always permitted to create files,
D 2
so they had to use a different mechanism.
E 2
I 2
so were forced to use a different mechanism.
E 2
While it is possible to get around all these problems,
D 2
the solutions are not straight-forward,
E 2
I 2
the solutions are not straight forward,
E 2
so a mechanism for locking files has been added.
.PP
D 2
The most general schemes allow processes to concurrently update a file.
E 2
I 2
The most general schemes allow multiple processes
to concurrently update a file.
E 2
Several of these techniques are discussed in [Peterson83].
D 2
A simpler technique is to simply serialize access with locks.
E 2
I 2
A simpler technique is to serialize access to a file with locks.
E 2
To attain reasonable efficiency,
certain applications require the ability to lock pieces of a file.
Locking down to the byte level has been implemented in the
Onyx file system by [Bass81].
D 2
However, for the applications that currently run on the system,
E 2
I 2
However, for the standard system applications,
E 2
a mechanism that locks at the granularity of a file is sufficient.
.PP
Locking schemes fall into two classes,
those using hard locks and those using advisory locks.
The primary difference between advisory locks and hard locks is the
D 2
decision of when to override them. 
A hard lock is always enforced whenever a program tries to
E 2
I 2
extent of enforcement.
A hard lock is always enforced when a program tries to
E 2
access a file;
an advisory lock is only applied when it is requested by a program.
Thus advisory locks are only effective when all programs accessing
a file use the locking scheme.
D 2
With hard locks there must be some override policy implemented in the kernel,
with advisory locks the policy is implemented by the user programs.
E 2
I 2
With hard locks there must be some override
policy implemented in the kernel.
With advisory locks the policy is left to the user programs.
E 2
In the UNIX system, programs with system administrator
D 2
privilege can override any protection scheme.
Because many of the programs that need to use locks run as
system administrators,
E 2
I 2
privilege are allowed override any protection scheme.
Because many of the programs that need to use locks must
also run as the system administrator,
E 2
we chose to implement advisory locks rather than 
D 2
create a protection scheme that was contrary to the UNIX 
philosophy or could not be used by system administration
programs.
E 2
I 2
create an additional protection scheme that was inconsistent
with the UNIX philosophy or could
not be used by system administration programs.
E 2
.PP
The file locking facilities allow cooperating programs to apply
advisory
.I shared
or
.I exclusive
locks on files.
D 2
Only one process has an exclusive
E 2
I 2
Only one process may have an exclusive
E 2
lock on a file while multiple shared locks may be present.
Both shared and exclusive locks cannot be present on
a file at the same time.
If any lock is requested when
another process holds an exclusive lock,
or an exclusive lock is requested when another process holds any lock,
D 2
the open will block until the lock can be gained.
E 2
I 2
the lock request will block until the lock can be obtained.
E 2
Because shared and exclusive locks are advisory only,
even if a process has obtained a lock on a file,
D 2
another process can override the lock by
opening the same file without a lock.
E 2
I 2
another process may access the file.
E 2
.PP
D 2
Locks can be applied or removed on open files,
so that locks can be manipulated without
needing to close and reopen the file.
E 2
I 2
Locks are applied or removed only on open files.
This means that locks can be manipulated without
needing to close and reopen a file.
E 2
This is useful, for example, when a process wishes
D 2
to open a file with a shared lock to read some information,
to determine whether an update is required.
It can then get an exclusive lock so that it can do a read,
modify, and write to update the file in a consistent manner.
E 2
I 2
to apply a shared lock, read some information
and determine whether an update is required, then
apply an exclusive lock and update the file.
E 2
.PP
D 2
A request for a lock will cause the process to block if the lock
E 2
I 2
A request for a lock will cause a process to block if the lock
E 2
can not be immediately obtained.
In certain instances this is unsatisfactory.
For example, a process that
wants only to check if a lock is present would require a separate
mechanism to find out this information.
Consequently, a process may specify that its locking
request should return with an error if a lock can not be immediately
obtained.
D 2
Being able to poll for a lock is useful to ``daemon'' processes
E 2
I 2
Being able to conditionally request a lock
is useful to ``daemon'' processes
E 2
that wish to service a spooling area.
If the first instance of the
daemon locks the directory where spooling takes place,
later daemon processes can
easily check to see if an active daemon exists.
D 2
Since the lock is removed when the process exits or the system crashes,
there is no problem with unintentional locks files
that must be cleared by hand.
E 2
I 2
Since locks exist only while the locking processes exist,
lock files can never be left active after
the processes exit or if the system crashes.
E 2
.PP
Almost no deadlock detection is attempted.
D 2
The only deadlock detection made by the system is that the file
descriptor to which a lock is applied does not currently have a
E 2
I 2
The only deadlock detection done by the system is that the file
to which a lock is applied must not already have a
E 2
lock of the same type (i.e. the second of two successive calls
to apply a lock of the same type will fail).
D 2
Thus a  process can deadlock itself by
requesting locks on two separate file descriptors for the same
object.
E 2
.NH 2
Symbolic links
.PP
D 2
The 512 byte UNIX file system allows multiple
E 2
I 2
The traditional UNIX file system allows multiple
E 2
directory entries in the same file system
D 2
to reference a single file.
E 2
I 2
to reference a single file.  Each directory entry
``links'' a file's name to an inode and its contents.
E 2
The link concept is fundamental;
D 2
files do not live in directories, but exist separately and
E 2
I 2
inodes do not reside in directories, but exist separately and
E 2
are referenced by links.
D 2
When all the links are removed,
the file is deallocated.
This style of links does not allow references across physical file
E 2
I 2
When all the links to an inode are removed,
the inode is deallocated.
This style of referencing an inode does
not allow references across physical file
E 2
systems, nor does it support inter-machine linkage. 
To avoid these limitations
.I "symbolic links"
D 2
have been added similar to the scheme used by Multics [Feiertag71].
E 2
I 2
similar to the scheme used by Multics [Feiertag71] have been added.
E 2
.PP
A symbolic link is implemented as a file that contains a pathname.
When the system encounters a symbolic link while
interpreting a component of a pathname,
the contents of the symbolic link is prepended to the rest
of the pathname, and this name is interpreted to yield the
resulting pathname.
D 2
If the symbolic link contains an absolute pathname,
E 2
I 2
In UNIX, pathnames are specified relative to the root
of the file system hierarchy, or relative to a process's
current working directory.  Pathnames specified relative
to the root are called absolute pathnames.  Pathnames
specified relative to the current working directory are
termed relative pathnames.
If a symbolic link contains an absolute pathname,
E 2
the absolute pathname is used,
otherwise the contents of the symbolic link is evaluated
relative to the location of the link in the file hierarchy.
.PP
Normally programs do not want to be aware that there is a
symbolic link in a pathname that they are using.
However certain system utilities
must be able to detect and manipulate symbolic links.
Three new system calls provide the ability to detect, read, and write
D 2
symbolic links, and seven system utilities were modified to use these calls.
E 2
I 2
symbolic links; seven system utilities required changes
to use these calls.
E 2
.PP
D 2
In future Berkeley software distributions 
it will be possible to mount file systems from other
machines within a local file system.
When this occurs,
E 2
I 2
In future Berkeley software distributions
it may be possible to reference file systems located on
remote machines using pathnames.  When this occurs,
E 2
it will be possible to create symbolic links that span machines.
.NH 2
Rename
.PP
D 2
Programs that create new versions of data files typically create the
E 2
I 2
Programs that create a new version of an existing
file typically create the
E 2
new version as a temporary file and then rename the temporary file
D 2
with the original name of the data file.
In the old UNIX file systems the renaming required three calls to the system.
If the program were interrupted or the system crashed between
these calls,
the data file could be left with only its temporary name.
To eliminate this possibility a single system call
has been added that performs the rename in an
atomic fashion to guarantee the existence of the original name.
E 2
I 2
with the name of the target file.
In the old UNIX file system renaming required three calls to the system.
If a program were interrupted or the system crashed between these calls,
the target file could be left with only its temporary name.
To eliminate this possibility the \fIrename\fP system call
has been added.  The rename call does the rename operation
in a fashion that guarantees the existence of the target name.
E 2
.PP
D 2
In addition, the rename facility allows directories to be moved around
in the directory tree hierarchy.
The rename system call performs special validation checks to insure
E 2
I 2
Rename works both on data files and directories.
When renaming directories,
the system must do special validation checks to insure
E 2
that the directory tree structure is not corrupted by the creation
of loops or inaccessible directories.
Such corruption would occur if a parent directory were moved
into one of its descendants.
D 2
The validation check requires tracing the ancestry of the target
E 2
I 2
The validation check requires tracing the descendents of the target
E 2
directory to insure that it does not include the directory being moved.
.NH 2
Quotas
.PP
The UNIX system has traditionally attempted to share all available
resources to the greatest extent possible.
Thus any single user can allocate all the available space
in the file system.
In certain environments this is unacceptable.
Consequently, a quota mechanism has been added for restricting the
amount of file system resources that a user can obtain.
D 2
The quota mechanism sets limits on both the number of files
E 2
I 2
The quota mechanism sets limits on both the number of inodes
E 2
and the number of disk blocks that a user may allocate.
A separate quota can be set for each user on each file system.
D 2
Each resource is given both a hard and a soft limit.
E 2
I 2
Resources are given both a hard and a soft limit.
E 2
When a program exceeds a soft limit,
a warning is printed on the users terminal;
the offending program is not terminated
unless it exceeds its hard limit.
The idea is that users should stay below their soft limit between
login sessions,
D 2
but they may use more space while they are actively working.
E 2
I 2
but they may use more resources while they are actively working.
E 2
To encourage this behavior,
users are warned when logging in if they are over
any of their soft limits.
D 2
If they fail to correct the problem for too many login sessions,
E 2
I 2
If users fails to correct the problem for too many login sessions,
E 2
they are eventually reprimanded by having their soft limit
enforced as their hard limit.
D 2
.ds RH Software engineering
.bp
E 2
I 2
.ds RH Acknowledgements
.sp 2
.ne 1i
E 2
E 1

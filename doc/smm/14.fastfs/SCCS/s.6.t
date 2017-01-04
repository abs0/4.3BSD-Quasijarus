h35376
s 00126/00100/00006
d D 6.1 86/05/14 16:49:09 kjd 2 1
c 4.3BSD beta release document
e
s 00106/00000/00000
d D 5.1 86/05/14 16:48:48 kjd 1 0
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
D 2
.ds RH Software engineering
.NH
Software engineering
E 2
I 2
.nr H2 1
.ds RH Acknowledgements
.SH
\s+2Acknowledgements\s0
E 2
.PP
D 2
The preliminary design was done by Bill Joy in late 1980;
he presented the design at The USENIX Conference
held in San Francisco in January 1981.
The implementation of his design was done by Kirk McKusick
in the summer of 1981.
Most of the new system calls were implemented by Sam Leffler.
The code for enforcing quotas was
implemented by Robert Elz at the University of Melbourne.
.PP
To understand how the project was done it is necessary
to understand the interfaces that the UNIX system provides to
the hardware mass storage systems.
At the lowest level is a
.I "raw disk."
This interface provides access to the disk as a linear
array of sectors.
Normally this interface is only used by programs that need to
do disk to disk copies or that wish to dump file systems.
However, user programs with proper access rights can also access
this interface.
A disk is usually formated with a file system that is
interpreted by the UNIX system to
provide a directory hierarchy and files.
The UNIX system interprets and multiplexes requests from user programs
to create, read, write, and delete files by allocating and freeing
inodes and data blocks.
The interpretation of the data on the disk could be done by the
user programs themselves.
The reason that it is done by the UNIX system is to synchronize the user
requests, so that two processes do not attempt
to allocate or modify the same resource simultaneously.
It also allows access to be restricted at the file level rather than 
at the disk level and allows the common file system
routines to be shared between processes.
.PP
The implementation of the new file system amounted to 
using a different scheme for formating and interpreting the disk.
Since the synchronization and disk access routines themselves
were not being changed,
the changes to the file system could be developed by moving the 
file system interpretation routines out of the kernel and into a
user program.
Thus, the first step was to extract the file system code for
the old file system from the UNIX kernel and
change its requests to the disk driver to accesses to a raw disk.
This produced a library of routines that
mapped what would normally be system calls
into read or write operations on the raw disk.
This library was then debugged by linking it into
the system utilities that copy, remove, archive, and restore files.
.PP
A new cross file system utility was written that copied files from
the simulated file system to the one implemented by the kernel.
This was accomplished by calling the simulation library to do a read,
and then writing the resultant data by using the conventional
write system call.
A similar utility copied data from the kernel to the simulated file
system by doing a conventional read system call and then writing
the resultant data using the simulated file system library.
.PP
The second step was to rewrite the file system simulation library to
interpret the new file system.
By linking the new simulation library into the cross file system
copying utility,
it was possible to easily copy files from the old file system
into the new one and from the new one to the old one.
Having the file system interpretation implemented
in user code had several major benefits.
These included being able to use the standard system tools
such as the debuggers to set breakpoints and single step through the code.
When bugs were discovered,
the offending problem could be fixed and
tested without the need to reboot the machine.
There was never a period where it was necessary to 
maintain two concurrent file systems in the kernel.
Finally it was not necessary to dedicate a machine
entirely to file system development,
except for a brief period while the new file system was boot strapped.
.PP
The final step was to merge the new file system back into the UNIX kernel.
This was done in less than two weeks, 
since the only bugs remaining were those that involved interfacing
to the synchronization routines
that could not be tested in the simulated system.
Again the simulation system proved useful since it enabled
files to be easily copied between old and new file systems
regardless of which file system was running in the kernel.
This greatly reduced the number of times that the system had
to be rebooted.
.PP
The total design and debug time took about one man year.
Most of the work was done on the file system utilities,
and changing all the user programs to use the new facilities.
The code changes in the kernel were minor, involving the
addition of only about 800 lines of code (including comments).
.bp
E 2
I 2
We thank Robert Elz for his ongoing interest in the new file system,
and for adding disk quotas in a rational and efficient manner.
We also acknowledge Dennis Ritchie for his suggestions
on the appropriate modifications to the user interface.
We appreciate Michael Powell's explanations on how
the DEMOS file system worked;
many of his ideas were used in this implementation.
Special commendation goes to Peter Kessler and Robert Henry for acting
like real users during the early debugging stage when file systems were
less stable than they should have been.
The criticisms and suggestions by the reviews contributed significantly
to the coherence of the paper.
Finally we thank our sponsors,
the National Science Foundation under grant MCS80-05144,
and the Defense Advance Research Projects Agency (DoD) under
ARPA Order No. 4031 monitored by Naval Electronic System Command under
Contract No. N00039-82-C-0235.
.ds RH References
.nr H2 1
.sp 2
.SH
\s+2References\s0
.LP
.IP [Almes78] 20
Almes, G., and Robertson, G.
"An Extensible File System for Hydra"
Proceedings of the Third International Conference on Software Engineering,
IEEE, May 1978.
.IP [Bass81] 20
Bass, J.
"Implementation Description for File Locking",
Onyx Systems Inc, 73 E. Trimble Rd, San Jose, CA 95131
Jan 1981.
.IP [Feiertag71] 20
Feiertag, R. J. and Organick, E. I., 
"The Multics Input-Output System",
Proceedings of the Third Symposium on Operating Systems Principles,
ACM, Oct 1971. pp 35-41
.IP [Ferrin82a] 20
Ferrin, T.E.,
"Performance and Robustness Improvements in Version 7 UNIX",
Computer Graphics Laboratory Technical Report 2,
School of Pharmacy, University of California,
San Francisco, January 1982.
Presented at the 1982 Winter Usenix Conference, Santa Monica, California.
.IP [Ferrin82b] 20
Ferrin, T.E.,
"Performance Issuses of VMUNIX Revisited",
;login: (The Usenix Association Newsletter), Vol 7, #5, November 1982. pp 3-6
.IP [Kridle83] 20
Kridle, R., and McKusick, M.,
"Performance Effects of Disk Subsystem Choices for
VAX Systems Running 4.2BSD UNIX",
Computer Systems Research Group, Dept of EECS, Berkeley, CA 94720,
Technical Report #8.
.IP [Kowalski78] 20
Kowalski, T.
"FSCK - The UNIX System Check Program",
Bell Laboratory, Murray Hill, NJ 07974. March 1978
.IP [Knuth75] 20
Kunth, D.
"The Art of Computer Programming",
Volume 3 - Sorting and Searching,
Addison-Wesley Publishing Company Inc, Reading, Mass, 1975. pp 506-549
.IP [Maruyama76]
Maruyama, K., and Smith, S.
"Optimal reorganization of Distributed Space Disk Files",
CACM, 19, 11. Nov 1976. pp 634-642
.IP [Nevalainen77] 20
Nevalainen, O., Vesterinen, M.
"Determining Blocking Factors for Sequential Files by Heuristic Methods",
The Computer Journal, 20, 3. Aug 1977. pp 245-247
.IP [Pechura83] 20
Pechura, M., and Schoeffler, J.
"Estimating File Access Time of Floppy Disks",
CACM, 26, 10. Oct 1983. pp 754-763
.IP [Peterson83] 20
Peterson, G.
"Concurrent Reading While Writing",
ACM Transactions on Programming Languages and Systems,
ACM, 5, 1. Jan 1983. pp 46-55
.IP [Powell79] 20
Powell, M.
"The DEMOS File System",
Proceedings of the Sixth Symposium on Operating Systems Principles,
ACM, Nov 1977. pp 33-42
.IP [Ritchie74] 20
Ritchie, D. M. and Thompson, K.,
"The UNIX Time-Sharing System",
CACM 17, 7. July 1974. pp 365-375
.IP [Smith81a] 20
Smith, A.
"Input/Output Optimization and Disk Architectures: A Survey",
Performance and Evaluation 1. Jan 1981. pp 104-117
.IP [Smith81b] 20
Smith, A.
"Bibliography on File and I/O System Optimization and Related Topics",
Operating Systems Review, 15, 4. Oct 1981. pp 39-54
.IP [Symbolics81] 20
"Symbolics File System",
Symbolics Inc, 9600 DeSoto Ave, Chatsworth, CA 91311
Aug 1981.
.IP [Thompson78] 20
Thompson, K.
"UNIX Implementation",
Bell System Technical Journal, 57, 6, part 2. pp 1931-1946
July-August 1978.
.IP [Thompson80] 20
Thompson, M.
"Spice File System",
Carnegie-Mellon University,
Department of Computer Science, Pittsburg, PA 15213
#CMU-CS-80, Sept 1980.
.IP [Trivedi80] 20
Trivedi, K.
"Optimal Selection of CPU Speed, Device Capabilities, and File Assignments",
Journal of the ACM, 27, 3. July 1980. pp 457-473
.IP [White80] 20
White, R. M.
"Disk Storage Technology",
Scientific American, 243(2), August 1980.
E 2
E 1

h10546
s 01224/01418/00873
d D 6.4 86/08/27 14:20:35 mckusick 6 5
c rewrite from Carl S. Gutekunst
e
s 00486/00597/01805
d D 6.3 86/06/05 09:52:48 bloom 5 4
c typeset copy
e
s 01199/00585/01203
d D 6.2 86/05/26 18:11:31 mckusick 4 3
c first cut at document merge
e
s 00000/00000/01788
d D 6.1 86/05/26 13:34:11 mckusick 3 2
c document for 4.3BSD release
e
s 00000/00000/01788
d D 5.1 86/05/26 13:33:24 mckusick 2 1
c document distributed with 4.2BSD
e
s 01788/00000/00000
d D 4.1 86/05/26 13:32:53 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 4
.\" Copyright (c) 1986 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
E 4
I 1
.\"	%W% (Berkeley) %G%
.\"
I 6
.ds UU UUCP
.ds Uu U\s-2UCP\s+2
.ds uu \s-2UUCP\s+2
E 6
D 4
.RP
.TM 78-1273-5 39199 39199-11
.ND October 31, 1978
.if \n(TN>0 .FS
.if \n(TN>0 * On internship from Department 9444.
.if \n(TN>0 .FE
E 4
.TL
D 4
Uucp Implementation Description
.AU "MH 2C-572" 3126
.ie \n(TN>0 D. A. Nowitz\s-2\u*\d\s+2
.el D. A. Nowitz
E 4
I 4
D 6
Installation and Operation of UUCP
E 6
I 6
Installation and Operation of \*(UU
E 6
.br
4.3BSD Edition
.AU
D. A. Nowitz
.AI
D 6
.MH
E 6
I 6
AT&T Bell Laboratories
Murray Hill, New Jersey 07974
E 6
.AU
D 6
Ross Green
E 6
I 6
Carl S. Gutekunst
E 6
.AI
D 6
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA  94720
E 6
I 6
Communications Software Research and Development
Pyramid Technology Corporation
Mountain View, California 94039
E 6
E 4
.AB
D 4
.PP
Uucp is a series of programs designed to permit communication
between
UNIX
systems using either dial-up or hardwired communication
lines.
This document gives a detailed implementation
description of the current (second)
implementation of uucp.
.PP
This document is
for use by an administrator/installer of the system.
It is not meant as a user's guide.
.AE
.CS 12 5 15
.SH
Introduction
.LP
E 4
D 5
Uucp is a series of programs designed to permit communication between
E 5
I 5
D 6
Uucp is a collection of programs designed to permit communication between
E 6
I 6
\*(Uu is a series of programs designed to permit communication
between
E 6
E 5
.UX
D 6
systems using either dial-up or
hardwired communication lines.
It is used for file transfers and remote command execution.
The first version of the system was designed and implemented
D 4
by M. E. Lesk.\s-2\u1\d\s+2
.FS
1 M. E. Lesk and A. S. Cohen,
.UX
Software Distribution by Communication Link,
.ie \n(TN>0 TM-77-1274-3, TM-77-8234-5.
.el private communication.
.FE
This paper describes the current (second) implementation
of the system.
E 4
I 4
by M. E. Lesk (SMM:21).
E 6
I 6
systems using a variety of communications links.
\*(Uu provides batched, error free file transfers and remote command
execution.
It is well suited for tasks such as electronic mail, public news networks,
and software distribution, particularly when only slow,
low-cost communication links are available (e.g., 1200 baud dial-up).
E 6
E 4
D 5
.LP
E 5
I 5
.PP
E 5
I 4
D 6
There have been many changes to the implementation of UUCP
since the release of 4.2BSD.
Many problems been fixed,
and several improvements to provide greater throughput have been incorporated.
D 5
A number of new features and facilites have been added,
these include:
E 5
I 5
A number of new features and facilities have been added.
These include:
E 5
.IP \(bu 3
Improved administration.
.IP \(bu 3
Extended modem support.
.IP \(bu 3
New transfer protocols
.IP \(bu 3
Security enhancements.
.PP
The first part of this document gives a detailed 
description of the use of UUCP.
I 5
The command descriptions do not describe all the options available;
see the manual pages for complete descriptions.
E 5
The rest of the document indicates the changes that have been made to UUCP,
and provides an update on the installation and implementation details.
D 5
It is for use by an administrator/installer of the system;
E 5
I 5
It is for use by an administrator or installer of the system;
E 5
it is not meant as a user's guide.
.sp
E 6
I 6
This document describes the 4.3BSD version of \*(Uu.
This is a distant but direct descendent of the ``second implementation''
of \*(Uu developed by D. A. Nowitz at AT&T Bell Laboratories.
A number of other \*(Uu versions are in common usage; these are discussed
only to the extent that they affect administration of 4.3BSD systems.
E 6
.LP
D 5
Revised %Q%
E 5
I 5
D 6
Revised May 1986
E 6
I 6
Revised August 24, 1986
E 6
E 5
.AE
.LP
.OH 'Installation and Operation of UUCP''SMM:9-%'
.EH 'SMM:9-%''Installation and Operation of UUCP'
I 6
.ne 5
E 6
.NH
D 6
Uucp Implementation Description
E 6
I 6
\*(UU OVERVIEW
E 6
.PP
E 4
D 6
Uucp is a batch type operation.
Files are created in a spool directory for processing
by the uucp demons.
I 5
For efficiency, the files are separated by type into subdirectories
of this directory.  The subdirectories will be described
in section 9.
E 5
There are three types of files used for the execution
of work.
.I Data\ files
contain data for transfer to remote systems.
.I Work\ files
D 5
contain directions for file transfers between systems.
E 5
I 5
contain instructions for file transfers between systems.
E 5
.I Execution\ files
D 5
are directions for
E 5
I 5
are instructions for
E 6
I 6
\*(Uu is a batch-type operation.
Users issue commands that are queued in a spool directory for processing
by background daemons.
.LP
\fIUucp\fP (UNIX-to-UNIX Copy) and \fIuux\fP (UNIX-to-UNIX Execution)
provide the user interface to \*(Uu.
.I Uucp
has syntax and semantics similar to the standard
E 6
E 5
.UX
I 6
utility \fIcp\fP(1), with the added ability to prefix filenames with
system names.
Similarly, \fIuux\fP mimics the conventions of \fIsh\fP(1), and allows
commands to be prefixed with system names.
.LP
\fIUucico\fP (Copy-In, Copy-Out) is the primary \*(Uu daemon.
It processes the requests queued by \fIuucp\fP and \fIuux\fP,
initiates calls to remote systems, transfers files, and forks other
daemons to execute \fIuux\fP-requested commands.
\fIUucico\fP also acts as the \*(Uu ``shell'' when remote systems call in
to requests transfers.
.LP
Three types of files are used in \*(Uu operation.
\fIControl files\fP describe the \*(Uu environment, including
known remote hosts, available devices, and remote file access permissions.
Control files are relatively static; they are generally changed only by the
system administrator.
\fISpool files\fP (also called \fIQueue files\fP) contain transfer requests
and data; they are created and deleted as necessary
by \fIuucp\fP, \fIuux\fP, and \fIuucico\fP.
\fILog files\fP accumulate a history of \*(Uu activity; these tend to
grow forever if not periodically cleaned up.
.LP
Spool files are further divided into three types:
\fIWork files\fP
contain directions for file transfers between systems.
Every invocation of \fIuucp\fP or \fIuux\fP creates one or more work files.
\fIData files\fP contain data for transfer to or from remote systems.
\fIExecution files\fP contain directions for
.UX
E 6
command executions which
involve the resources of one or more systems.
I 6
Execution files are created only by \fIuux\fP.
.\"===========================================================================
.\" SECTION 2: USER UTILITIES
.\"===========================================================================
.ne 5
.NH
USER UTILITIES
.PP
\*(Uu includes a total of ten ``primary'' utilities, that is, ten
utilities for general users.
All reside in the \fB/usr/bin\fP directory, where they are easily accessible.
This section provides detailed implementation descriptions for the more
important commands; see the corresponding \fIman\fP pages for additional
information.
E 6
.LP
D 4
The uucp system consists of four primary and two
E 4
I 4
D 5
The uucp system consists of ten primary and four
E 5
I 5
D 6
The uucp system consists of ten primary (i.e. invoked by users) and four
E 5
E 4
secondary programs.
D 4
The primary programs are:
E 4
I 4
D 5
These programs are summaried in section 9.
E 5
I 5
These programs are summarized in section 9.
E 5
The three most important primary programs are:
E 6
I 6
The following two commands queue transfer requests:
E 6
E 4
.RS
D 6
.IP uucp 10
D 5
This program creates work and gathers data files in the spool directory
E 5
I 5
This program creates work and gathers data files in the spool directories
E 5
for the transmission of files.
.IP uux
This program creates work files, execute files and gathers data files for the remote execution of
E 6
I 6
.IP uucp(1C) 15
UNIX-to-UNIX File Copy.
One of more \fIcontrol files\fP are created, containing names of files to be
transferred.
When necessary, local files are copied into \fIdata files\fP for
transmission.
.IP uux(1C)
Execute command.
An \fIexecute file\fP is created, containing a
E 6
.UX
D 6
commands.
D 4
.IP uucico
E 4
I 4
D 5
.IP uulog
This program updates the log file with new entries
and reports on the status of uucp requests.
E 5
I 5
.IP uusnap
This program provides a snapshot of the current queue including
transfers queued and commands to be executed locally.
E 6
I 6
command to be executed and its arguments.
A \fIcontrol file\fP is created that includes all files that must be
transferred to execute the command, including the \fIexecute file\fP itself.
When necessary, local files are copied into \fIdata files\fP for
transmission.
Any output from the command will also be written to \fIdata files\fP.
E 6
E 5
.RE
D 6
.ne 10
E 6
.LP
D 6
The three most important secondary programs are:
E 6
I 6
The following four commands provide \*(Uu status information:
E 6
.RS
D 6
.IP uucico 10
E 4
D 5
This program executes the work files for data transmission.
E 5
I 5
This program actually performs the data transmission.
E 5
.IP uuxqt
This program executes the execution files for
.UX
command execution.
D 4
.RE
.ne 10
.LP
The secondary programs are:
.RS
.IP uulog 10
This program updates the log file with new entries
and reports on the status of uucp requests.
E 4
.IP uuclean
D 5
This program removes old files from the spool directory.
E 5
I 5
This program removes old files from the spool directories.
E 6
I 6
.IP uulog(1C) 15
Display selected information from the \*(Uu log.
.IP uuname(1C)
Display the names of all remote hosts that are directly accessible via \*(Uu.
.IP uusnap(8C)
Provide a snapshot of the current queue, including
the number of work files, data files, and execute files for each site.
.IP uuq(1C)
A variant of \fIuusnap\fP, lists files and \fIuux\fP commands
queued for each site.
\fIUuq\fP also permits the \*(Uu administrator to delete jobs.
E 6
E 5
D 4
.LP
E 4
.RE
D 4
The remainder of this paper will describe the operation
of each program, the installation of the system,
E 4
I 4
.LP
D 6
The next six sections of this paper will describe the operation
of each program.
D 5
the installation of the system,
E 5
I 5
The remainder of this paper describes the installation of the system,
E 5
E 4
the security aspects of the system,
the files required for execution,
and the administration of the system.
.NH
E 6
I 6
The following four commands provide miscellaneous support services:
.RS
.IP uudecode(1C) 15
The decoder for files created by \fIuuencode\fP, below.
.IP uuencode(1C)
A filter to convert binary files into printable ASCII.
This is useful when transferring object files over communications links
that do not support 8-bit transfers.
.IP uupoll(8C)
A user utility to conveniently fork the \*(Uu daemon, \fIuucico\fP.
.IP uusend(1C)
A utility to send files to remote sites more than one ``hop'' distant.
.RE
.\"===========================================================================
.NH 2
E 6
Uucp - UNIX to UNIX File Copy
.LP
D 6
The
.I uucp
E 6
I 6
The \fIuucp\fP
E 6
command is the user's primary interface with the system.
The
.I uucp
command was designed to look like
.I cp
to the user.
The syntax is
.IP
.I uucp\ \ 
.B [
option
.B ]
\ ...\ \ source\ ...\ \ destination
.LP
where the source and destination
D 6
may contain the prefix
.I system-name!
E 6
I 6
may contain the prefix \fIsystem-name\fP\fB!\fP
E 6
which indicates the system on which the file
or files reside
or where they will be copied.
.LP
The options interpreted by
.I uucp
are:
.RS
D 5
.IP \-d 10
Make directories when necessary for copying the file.
.IP \-c
Don't copy source files to the spool directory,
but use the specified source when the actual
E 5
I 5
.IP \-f 10
Don't make directories when copying the file.
The default is to make the necessary directories.
.IP \-C
Copy source files to the spool directory.
The default is to use the specified source when the actual
E 5
transfer takes place.
D 6
.IP \-g\fIletter\fR
E 6
I 6
.IP \-g\fIgrade\fR
E 6
Put
D 6
.I letter
E 6
I 6
.I grade
E 6
in as the grade in the name of the work file.
D 6
(This can be used to change the order of work for a particular
machine.)
E 6
I 6
This is a single character in the range \fB[0-9][A-Z][a-z]\fP.
The \fIgrade\fP will be used by \fIuucico\fP to establish the
priority of requests.
\fB0\fP is the highest (best) grade; \fBz\fP is the lowest (worst).
The default
.I grade
for
.I uucp
is \fBn\fP.
E 6
.IP \-m
Send mail on completion of the work.
I 5
.IP \-n\fIuser\fR
Notify \fIuser\fR on the destination system that a file was sent.
E 5
.LP
D 6
The following options are used primarily for debugging:
E 6
I 6
The following options are used primarily for debugging, or when
.I uucp
is invoked from other programs:
E 6
.IP \-r 10
D 6
Queue the job but do not start
.I uucico
program.
E 6
I 6
Queue the job but do not start \fIuucico\fP.
The assumption is that \fIuucico\fP will be started at a later time, perhaps
by \fIcron\fP(8) or \fIuupoll\fP.
E 6
.IP \-s\fIdir\fR
Use directory
.I dir
D 5
for the spool directory.
E 5
I 5
for the top level spool directory.
E 5
.IP \-x\fInum\fR
.I Num
is the level of debugging output desired.
I 6
This option requires the user to have read permission to the \*(Uu
control file \fIL.sys\fP.
E 6
.RE
.LP
The destination may be a directory name,
in which case the file name is taken from the last part of the
source's name.
The source
name may contain special shell characters
D 6
such as ``\fI?*[]\fR''.
E 6
I 6
such as ``\fB?*[]\fR'';
these and other shell characters such as ``\fB!<>\fP'' will need to be quoted
or escaped.
E 6
If a source argument has a
D 6
.I system-name!
E 6
I 6
\fIsystem-name\fP\fB!\fP
E 6
prefix for a remote system,
the file name expansion will be done on the remote system.
I 5
D 6
Quote or escape characters that have special meaning to your shell,
for example, `!' in csh.
E 6
E 5
.LP
The command
.IP "" 12
uucp\ \ *.c\ \ usg!/usr/dan
.LP
will set up the transfer of all files whose names end with ``.c''
D 5
to the ``/usr/dan'' directory on the``usg'' machine.
E 5
I 5
to the ``/usr/dan'' directory on the ``usg'' machine.
E 5
.LP
D 6
The source and/or destination names may also contain a
.I ~user
E 6
I 6
The source and/or destination names may also contain a \fB~\fP\fIuser\fP
E 6
prefix.
This translates to the login directory on
the specified system.
I 6
A lone \fB~\fP prefix is expanded to the name of the specified system's
public access directory, usually 
\fB/usr/spool/uucppublic\fP.
E 6
For names with partial path-names,
the current directory is prepended to the file name.
File names with
.I ../
are not permitted.
.LP
The command
.IP "" 12
uucp\ \ usg!~dan/*.h\ \ ~dan
.LP
will set up the transfer of files whose names end with ``.h''
in dan's login
directory on system ``usg'' to dan's local
login directory.
.LP
For each source file,
the program will check the source and destination
file-names
and the system-part of each to
classify the work into one of five types:
.RS
.IP [1]
Copy source to destination on local system.
.IP [2]
D 5
Receive files from other systems.
E 5
I 5
Receive files from a remote system.
E 5
.IP [3]
D 5
Send files to a remote systems.
E 5
I 5
Send files to a remote system.
E 5
.IP [4]
D 5
Send files from remote systems
E 5
I 5
Send files from remote system
E 5
to another remote system.
.IP [5]
D 5
Receive files from remote systems when the source
E 5
I 5
Receive files from remote system when the source pathname
E 5
contains special shell characters as
mentioned above.
.RE
.LP
D 5
After the work has been set up in the spool directory,
E 5
I 5
After the work has been set up in the spool directories,
E 5
D 6
the
.I uucico
program is started to try to contact the other
E 6
I 6
the \*(Uu daemon \fIuucico\fP is started to try to contact the other
E 6
machine to execute the work (unless the \-r option
was specified).
.SH
Type 1
.LP
D 5
A
.I cp
command is used to do the work.
E 5
I 5
.I Uucp
makes a copy of the file.
E 5
The
D 5
.I \-d
and the
E 5
.I \-m
D 5
options are not honored in this case.
E 5
I 5
option is not honored in this case.
E 5
.SH
Type 2
.LP
A one line
.I "work file"
D 5
is created for each file requested and put in the spool directory
E 5
I 5
D 6
is created for each file requested and put in the appropriate spool directory
E 6
I 6
is created for each file requested and put in the \fBC.\fP spool directory
E 6
E 5
with the following fields, each separated by a blank.
(All
.I "work files"
and
.I "execute files"
use a blank as the field separator.)
.RS
.IP [1]
R
.IP [2]
The full path-name of the source or a ~user/path-name.
The
.I ~user
part will be expanded on the remote system.
.IP [3]
D 5
The full path-name of the destination file.
E 5
I 5
The full path-name of the local destination file.
E 5
If the
.I ~user
notation is used, it will be immediately
expanded to be the login directory for the user.
.IP [4]
The user's login name.
.IP [5]
D 6
A ``\-'' followed by an option list.
E 6
I 6
A `\-' followed by an option list.
E 6
D 5
(Only the \-m and \-d options will appear in this list.)
E 5
.RE
.KS
.SH
Type 3
.LP
For each source file, a
.I "work file"
D 5
is created and the source file is copied into a
.I "data file"
in the spool directory.
(A ``\-c'' option on the
E 5
I 5
is created.
D 6
A ``\-C'' option on the
E 6
I 6
A \fB\-C\fP option on the
E 6
E 5
.I uucp
D 5
command will prevent the
E 5
I 5
command will cause the
E 5
.I "data file"
D 5
from being made.)
In this case, the file will be transmitted from
the indicated source.)
E 5
I 5
to be copied into the spool directory
and the file to be transmitted from
D 6
the copy.
E 6
I 6
the copy; the copy is deleted when the transfer completes.
E 6
E 5
The fields of each entry are given below.
.RS
.IP [1]
S
.IP [2]
The full-path name of the source file.
.IP [3]
The full-path name of the destination or
~user/file-name.
.IP [4]
The user's login name.
.IP [5]
D 6
A ``\-'' followed by an option list.
E 6
I 6
A `\-' followed by an option list.
E 6
.IP [6]
D 6
The name of the
E 6
I 6
The full path-name of the local source file.
If the
.I ~user
notation is used, it will be immediately
expanded to be the login directory for the user.
If the \fB\-C\fP option was used, this will be the name of a
E 6
.I "data file"
in the spool directory.
.IP [7]
The file mode bits of the source file
in octal print format
(e.g. 0666).
I 5
.IP [8]
The user to notify on the remote system that the transfer has completed.
E 5
.RE
.KE
.SH
Type 4 and Type 5
.LP
.I Uucp
generates a
.I uucp
command and sends it to the remote machine;
the remote
.I uucico
executes the
.I uucp
command.
D 6
.NH
E 6
I 6
.\"===========================================================================
.NH 2
E 6
Uux - UNIX To UNIX Execution
.LP
D 6
The
.I uux
E 6
I 6
The \fIuux\fP
E 6
command is used to set up the execution of a
.UX
command
where the execution machine and/or some of the
files are remote.
The syntax of the uux command is
.IP
.I uux\ \ 
.B [
\-
.B "] ["
option
.B ]
\ ...\ \ command-string
.LP
where the command-string is made up of one or more arguments.
D 5
All special shell characters such as ``<>|^'' must be quoted
E 5
I 5
All special shell characters such as ``<>|*?!'' must be quoted
E 5
either by quoting the entire command-string
or quoting the character as a separate argument.
Within the command-string, the command and file names may
contain a
D 6
.I system-name!
E 6
I 6
\fIsystem-name\fP\fB!\fP
E 6
prefix.
All arguments which do not contain a ``!'' will not
be treated as files.
(They will not be copied to the execution machine.)
D 6
The ``\-'' is used to indicate that the standard input
E 6
I 6
The `\-' is used to indicate that the standard input
E 6
for
.I command-string
should be inherited from the standard input
of the
.I uux
command.
D 6
The options, essentially for debugging, are:
E 6
I 6
.LP
The options, used mostly for debugging and by other programs, are:
E 6
.RS
D 6
.IP \-r 10
Don't start
.I uucico
or
.I uuxqt
after queuing the job;
E 6
I 6
.IP \-a\fIname\fP 10
Use \fIname\fP as the requestor of the \fIuux\fP command, instead of the
real system and login names.
Unlike most other \*(Uu arguments, \fIname\fP may consist of a chain of
system names separated by `!' characters, as in:
.IP \  15
uux\ \ \-\ \ \-r\ \ \-aihnp4!decwrl!pyramid!csg\ \ seismo!rmail\ \ rick
.IP \-C 10
Copy source files to the spool directory.
Same as for \fIuucp\fP.
.IP \-g\fIgrade\fR
Put
.I grade
in as the grade in the name of the work file.
Same as for \fIuucp\fP.
The default
.I grade
for
.I uux
is \fBA\fP.
.IP \-n
Do not mail an acknowledgement to the requestor of the command.
Normally the execution daemon, \fIuuxqt\fP, will mail a message
to the user who entered the \fIuux\fP command.
This message includes the status return value that the program exited with.
The \fB\-n\fP option requests that this message not be sent.
.IP \-r
Do not start the \*(Uucp daemons \fIuucico\fP(8C) or \fIuuxqt\fP(8C)
after queuing the job.
E 6
.IP \-x\fInum\fR
Num is the level of debugging output desired.
I 6
.IP \-z
Mail an acknowledgement to the requestor only if the command fails, that
is, the command exits with a non-zero status.
E 6
.RE
.LP
The command
.IP "" 12
pr\ \ abc\ \ |\ \ uux\ \ \-\ \ usg!lpr
.LP
will set up the output of ``pr abc''
as standard input to an lpr command
to be executed on system ``usg''.
.LP
.I Uux
generates an
.I "execute file"
which contains the
names of the files required
for execution (including standard input),
the user's login name, the destination
of the standard output, and the command to be executed.
D 5
This file is either put in the spool directory
E 5
I 5
D 6
This file is either put in the appropriate spool directory
E 5
for local execution or sent to the remote system using
a generated send command (type 3 above).
E 6
I 6
This file is either put in the \fBX.\fP spool directory
for local execution,
or in the \fBD.\fP\fIhostname\fP\fBX\fP directory
for transfer to the remote system.
E 6
.LP
For required files which are not on the execution machine,
.I uux
will generate receive command files (type 2 above).
These command-files will be put on the execution machine and
D 6
executed by the
.I uucico
program.
E 6
I 6
executed by 
\fIuucico\fP.
E 6
(This will work only if the local system has permission
to put files in the remote spool directory as controlled
by the remote
D 5
.I USERFILE .
)
E 5
I 5
D 6
``USERFILE''.)
E 6
I 6
\fIUSERFILE\fP.)
E 6
E 5
.LP
The
.I "execute file"
will be processed
by the
D 6
.I uuxqt
E 6
I 6
\fIuuxqt\fP(8C)
E 6
program on the execution machine.
It is made up of several lines,
each of which contains an identification character
and one or more arguments.
The order of the lines in the file is not relevant
and some of the lines may not be present.
Each line is described below.
.RS
.SH
User Line
.IP
U\ \ user\ \ system
.LP
where the
.I user
and
.I system
D 6
are the requester's login name and system.
E 6
I 6
are the requestor's login name and system.
E 6
.SH
Required File Line
.IP
F file-name real-name
.LP
where the
.I file-name
is the generated name of a file for the execute machine
and
.I real-name
is the last part of the actual file name (contains no
path information).
Zero or more of these lines may be present in the
.I "execute file" .
The
.I uuxqt
program will check for the existence of all required
files before the command is executed.
.SH
Standard Input Line
.IP
I\ \ file-name
.LP
D 6
The standard input is either specified by a ``<'' in the
E 6
I 6
The standard input is either specified by a `<' in the
E 6
command-string or inherited from the standard input of the
.I uux
D 6
command if the ``\-'' option is used.
E 6
I 6
command if the `\-' option is used.
E 6
If a standard input is not specified,
D 6
``/dev/null'' is used.
E 6
I 6
.B /dev/null
is used.
E 6
.SH
Standard Output Line
.IP
O\ \ file-name\ \ system-name
.LP
D 6
The standard output is specified by a ``>'' within the
E 6
I 6
The standard output is specified by a `>' within the
E 6
command-string.
If a standard output is not specified,
D 6
``/dev/null'' is used.
E 6
I 6
.B /dev/null
is used.
E 6
(Note \- the use of ``>>'' is not implemented.)
.SH
I 6
Status Return Line
.IP
N
.LP
Normally \fIuuxqt\fP mails an acknowledgement message to the
requestor after the command completes.
The message includes the status return value that the program exited with.
This line inhibits mailing of the acknowledgement message.
It is generated by the \fB-n\fP option of \fIuux\fP;
it is also quietly assumed by \fIuuxqt\fP on the command \fBrmail\fP.
.SH
Error Status Return Line
.IP
Z
.LP
A variant of the \fIStatus Return\fP line, this line indicates that
an acknowledgement should be mailed only if the command's status
return is non-zero, i.e., the program exited with an error.
This line is generated by the \fB-z\fP option of \fIuux\fP.
It is also quietly assumed by \fIuuxqt\fP on the command \fBrnews\fP.
If both the \fBZ\fP and \fBN\fP lines appear, the \fBZ\fP line has
precedence.
.SH
Requestor Line
.IP
R\ \ requestor
.LP
where
.I requestor
is a complete return mailing address to the original requestor.
This line is generated by the \fB-a\fP option of \fIuux\fP, and is used
to override the mail return address implied by the \fIUser\fP line.
This is commonly used by mailers and programs like \fIuusend\fP that
know how to ``hop'' a file from system to system.
.SH
E 6
Command Line
.IP
C\ \ command\ \ 
.B [
arguments
.B ]
\ ...
.LP
The arguments are those specified in the command-string.
The standard input and standard output will not appear on this
line.
All
.I "required files"
will be moved to the execution directory (a subdirectory
of the spool directory)
and the
.UX
command is executed using the Shell specified in the
.I uucp.h
D 6
header file.
E 6
I 6
header file (usually \fI/bin/sh\fP).
E 6
In addition, a shell ``PATH'' statement is prepended
D 5
to the command line as specified in the
.I uuxqt
program.
E 5
I 5
to the command line.
E 5
.LP
D 5
After execution, the standard output is copied or set up to be
E 5
I 5
After execution, the temporary standard output file is copied to
or set up to be
E 5
sent to the proper place.
.RE
I 6
.\"===========================================================================
.\" SECTION 3: SYSTEM UTILITIES
.\"===========================================================================
.ne 5
E 6
.NH
I 4
D 5
Uulog - Uucp Log Inquiry
E 5
I 5
D 6
Uusnap - Uucp Queue Snapshot
E 6
I 6
SYSTEM AND ADMINISTRATIVE UTILITIES
E 6
E 5
.LP
D 5
The
E 5
I 5
D 6
This program displays a synopsis of the current
E 5
.I uucp
D 5
programs create individual
log files for each program invocation.
Periodically,
.I uulog
may be executed to prepend these files to the
system logfile.
This method of logging was chosen to minimize file
locking of the logfile during program execution.
.LP
The
.I uulog
program merges the individual
log files and outputs specified log entries.
The output request is specified by the use of the
following options:
.RS
.IP \-s\fIsys\fR 9
Print entries where
.I sys
is the remote system name;
.IP \-u\fIuser\fR
Print entries for user
.I user.
.RE
.LP
The intersection of lines satisfying the two options is output.
A null
.I sys
or
.I user
means all system names or users respectively.
E 5
I 5
situation.  For each site that has work queued or that had an abnormal
termination on the last connection, a line summarizing the work to be done
is output.  The line will indicate how many commands there are to be sent,
how many data files have been received and not processed, and how many
jobs received from the site there are to be executed.  A status message
describing the last connection will be included if the connection
terminated abnormally.
E 5
.NH
E 4
Uucico - Copy In, Copy Out
E 6
I 6
\*(Uu includes four system utilities;
these are not normally referenced by users.
All except \fIuucpd\fP reside in the \*(Uu administrative directory,
\fB/usr/lib/uucp\fP.
These include:
.RS
.IP uucico(8C) 15
Copy In, Copy Out. This is the primary \*(Uu daemon.
.IP uuclean(8C)
A handy utility to clean up the \*(Uu spool directories.
.IP uucpd
The \*(Uu TCP/IP daemon.
This daemon ``answers'' the connection request from a remote \fIuucico\fP
to a TCP/IP socket.
It is functionally a stripped-down version of \fIrlogind\fP(8) that provides
full 8-bit communication.
(Note: this utility does not have a \fIman\fP page.)
.IP uuxqt(8C)
Execution Daemon.
This is forked by \fIuucico\fP to interpret execution files
transferred from a remote system.
.RE
.\"===========================================================================
.NH 2
Uucico - Copy In, Copy Out (\*(Uu Daemon)
E 6
.LP
D 6
The
.I uucico
program will perform the following major functions:
E 6
I 6
.I Uucico
is the ``heart'' of the \*(Uu system.
The program performs the following major functions:
E 6
.RS
.IP -\ \  3
Scan the spool directory for work.
.IP -\ \  
Place a call to a remote system.
.IP -\ \ 
Negotiate a line protocol to be used.
.IP -\ \ 
Execute all requests from both systems.
.IP -\ \ 
Log work requests and work completions.
.RE
.LP
.I Uucico
may be started in several ways;
.RS
.IP a) 5
D 6
by a system daemon,
E 6
I 6
by a system daemon (such as \fIcron\fP(8)),
E 6
.IP b)
by one of the
.I
uucp, uux, uuxqt
.R
or
D 5
.I uucico
E 5
I 5
.I uupoll
E 5
programs,
.IP c)
directly by the user (this is usually for testing),
.IP d)
by a remote system.
D 5
(The uucico program should be specified as the ``shell''
E 5
I 5
(The \fIuucico\fP program should be specified as the ``shell''
E 5
D 6
field in the ``/etc/passwd'' file for the ``uucp'' logins.)
E 6
I 6
field in the \fB/etc/passwd\fP file for the \*(Uu logins.)
E 6
.RE
.LP
When started by method a, b or c, the program is considered to
be in
.I MASTER
mode.
In this mode, a connection will be made to a remote system.
If started by a remote system (method d),
the program is considered to be in
.I SLAVE
mode.
.LP
The
.I MASTER
mode will operate in one of two ways.
If no system name is specified
(\-s option not specified)
the program will scan the spool directory for
systems to call.
If a system name is specified, that system will be called,
and work will only be done for that system.
.LP
The
.I uucico
program is generally started by another program.
There are several options used for execution:
.RS
D 6
.IP \-r1 10
E 6
I 6
.IP \-g\fIgrade\fP 10
Set the minimum grade of this \fIuucico\fP run to \fIgrade\fP.
Only files of this grade or better will be transferred.
.IP \-r1
E 6
Start the program in
.I MASTER
mode.
This is used when
.I uucico
D 6
is started by a program or ``cron'' shell.
E 6
I 6
is started by a program or \fIcron\fP shell.
E 6
.IP \-s\fIsys\fR
Do work only for system
.I sys.
If
D 5
.I \-s
E 5
I 5
.B \-s
E 5
is specified,
a call to the specified system
will be made even if there is no work for system
.I sys
in the spool directory.
This is useful for polling systems which do not have
the hardware to initiate a connection.
.LP
The following options are used primarily for debugging:
.IP \-d\fIdir\fR
Use directory
.I dir
D 5
for the spool directory.
E 5
I 5
for the top level spool directory.
E 5
.IP \-x\fInum\fR
.I Num
is the level of debugging output desired.
.RE
.LP
The next part of this section will describe the major steps within
the
.I uucico
program.
.SH
Scan For Work
.LP
D 5
The names of the work related files in the spool directory have format
E 5
I 5
The names of the work related files in a spool subdirectory have format
E 5
.IP
D 6
type . system-name grade number
E 6
I 6
type \fB.\fP system-name grade number
E 6
.LP
where:
.IP
.I Type
is an upper case letter,
(
D 6
.I C
-\ copy command file,
.I D
E 6
I 6
.B C
-\ work (copy command) file,
.B D
E 6
-\ data file,
D 6
.I X
E 6
I 6
.B X
E 6
-\ execute file);
.IP
.I System-name
is the remote system;
.IP
.I Grade
D 6
is a character;
E 6
I 6
is a character in the range \fB[0-9][A-Z][a-z]\fP;
E 6
.IP
.I Number
is a four digit, padded sequence number.
.LP
The file
.IP "" 12
C.res45n0031
.LP
would be a
.I "work file"
for a file transfer between the local
machine and the ``res45'' machine.
.LP
The scan for work is done by looking through the
D 5
spool directory for
E 5
I 5
appropriate spool directory for
E 5
D 6
.I "work files"
(files with prefix ``C.'').
E 6
I 6
\fIwork files\fP
(files with prefix \fBC.\fP).
E 6
A list is made of all systems to be called.
.I Uucico
will then call each system and process all
.I "work files" .
.SH
Call Remote System
.LP
D 6
The call is made using information from several
D 5
files which reside in the uucp program directory.
E 5
I 5
files which reside in the uucp system directory (usually /usr/lib/uucp).
E 6
I 6
The call is made using information from the \fIcontrol\fP files
that reside in the \fB/usr/lib/uucp\fP directory.
E 6
E 5
At the start of the call process, a lock is
set to forbid multiple conversations 
between the same two systems.
.LP
The system name is found in the
D 5
.I L.sys
E 5
I 5
D 6
``L.sys''
E 5
file.
I 4
The precise format of the
D 5
.I L.sys
E 5
I 5
``L.sys''
E 5
file is described in section 10, ``System File Details''.
E 6
I 6
.I L.sys
control file.
E 6
E 4
The information contained for each system is;
.RS
.IP [1]
system name,
.IP [2]
times to call the system
(days-of-week and times-of-day),
.IP [3]
D 6
device or device type to be used for call,
E 6
I 6
the \fIcaller\fP, that is, the type of device to be used for the call,
E 6
.IP [4]
D 6
line speed,
E 6
I 6
the line speed or network number (as appropriate),
E 6
.IP [5]
D 6
phone number if field [3] is
.I ACU
or the device name (same as field [3])
if not
.I ACU,
E 6
I 6
telephone number or device name (as appropriate),
E 6
.IP [6]
D 6
login information (multiple fields),
E 6
I 6
login information (multiple fields).
E 6
.RE
.LP
The time field is checked against the present time to see
if the call should be made.
.LP
The
.I
phone number
.R
may contain abbreviations (e.g. mh, py, boston) which get translated into dial
sequences using the
.I L-dialcodes
file.
.LP
The
.I L-devices
file is scanned using fields [3] and [4] from the
D 5
.I L.sys
E 5
I 5
D 6
``L.sys''
E 6
I 6
.I L.sys
E 6
E 5
file to find an available device for the call.
The program will try all devices which satisfy
D 5
[3] and [4] until the call is made, or no more
E 5
I 5
[3] and [4] until the call is made or no more
E 5
devices can be tried.
If a device is successfully opened, a lock file
is created so that another copy of
.I uucico
will not try to use it.
If the call is complete, the
.I
login information
.R
(field [6] of
D 5
.I L.sys )
E 5
I 5
D 6
``L.sys'')
E 6
I 6
\fIL.sys\fP)
E 6
E 5
is used to login.
.LP
The conversation between the two
.I uucico
programs begins with a handshake started by the called,
.I SLAVE ,
system.
The
.I SLAVE
sends a message to let the
.I MASTER
know it is ready to receive the system
identification and conversation sequence number.
The response from the
.I MASTER
is
verified by the
.I SLAVE
and if acceptable, protocol selection begins.
The
.I SLAVE
can also reply with a ``call-back required''
message in which case, the current conversation
is terminated.
.SH
Line Protocol Selection
.LP
The remote system sends a message
.IP "" 12
P\fIproto-list\fR
.LP
where proto-list is a string of characters, each
representing a line protocol.
.LP
The calling program checks the proto-list
for a letter corresponding to an available line
protocol and returns a
.I use-protocol
message.
The
.I use-protocol
message is
.IP "" 12
U\fIcode\fR
.LP
D 6
where code is either a one character
E 6
I 6
where 
.I code
is either a one character
E 6
protocol letter or
D 6
.I N
E 6
I 6
.B N
E 6
which means there is no common protocol.
I 6
.LP
The following protocols are implemented in 4.3BSD \*(Uu:
.RS
.IP \fBg\fP
General.
Default for dialup or hardwired lines, supported by all versions of \*(Uu.
This protocol employs small (64 byte) data packets with
checksums and packet-by-packet retransmission.
This ensures reliable and efficient transfers over slow and noisy links
like 1200-baud dial-up lines.
These same characteristics make the \fBg\fP protocol bulky and slow over
error free links, and very expensive on public data-switched networks.
.IP \fBf\fP
Optimized for use on X.25 PAD public data-switched networks.
The protocol employs larger (256 byte) data packets,
passes no control characters except CR,
and uses only a 7-bit data path.
(Note that the files transferred may still contain full 8-bit data.)
It assumes that the link is ``mostly'' error-free, calculating a checksum
for the entire file only. 
When an error is detected, the entire file is retransmitted.
.IP \fBt\fP
Optimized for use on TCP/IP networks and other completely error free links.
It employs large (1024 byte) packets, and uses the full 8-bit data path.
.RE
.LP
Note: AT&T System VR2 \*(UU supports the \fBx\fP (\fIX.25\fP) and \fBe\fP
(\fIError Free\fP) protocols, which provide functionality similar to the
4.3BSD \fBf\fP and \fBt\fP protocols, respectively. 
They are incompatible, however.
Thus when attempting to connect two systems via X.25 or an local area network,
it is not adequate for both systems to simply ``support X.25'' or ``support
error free transfers.''
Both must support the same \*(Uu protocols.
E 6
.SH
Work Processing
.LP
The initial roles (
.I MASTER
or
.I SLAVE
) for the work processing are
the mode in which each program starts.
(The 
.I MASTER
D 5
has been specified by the ``\-r1'' uucico option.)
E 5
I 5
D 6
has been specified by the ``\-r1'' \fIuucico\fP option.)
E 6
I 6
has been specified by the \fB\-r1\fP \fIuucico\fP option.)
E 6
E 5
The
.I MASTER
program does a work search similar to the
one used in the ``Scan For Work'' section.
.LP
There are five messages used during the
work processing, each specified by the first
character of the message.
They are;
.IP "" 12
.RS
.IP S 3
send a file,
.IP R
receive a file,
.IP C
copy complete,
.IP X
execute a
.I uucp
D 5
command,
E 5
I 5
command, and
E 5
.IP H
hangup.
.RE
.LP
The
.I MASTER
will send
.I R ,
.I S
or
.I X
messages until all work from the spool directory is
complete, at which point an
.I H
message will be sent.
The
.I SLAVE
will reply with
\fISY\fR, \fISN\fR, \fIRY\fR, \fIRN\fR, \fIHY\fR, \fIHN\fR,
D 4
\fIXY\fR, \fIXN\fr,
E 4
I 4
\fIXY\fR, \fIXN\fR,
E 4
corresponding to
.I yes
or
.I no
for each request.
.LP
The send and receive replies are
based on permission to access the
D 6
requested file/directory using the
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 6
I 6
requested file/directory using
.I USERFILE
E 6
E 5
and read/write permissions of the file/directory.
After each file is copied into the spool directory
of the receiving system,
a copy-complete message is sent by the receiver of the file.
The message
.I CY
will be sent if the
file has successfully been moved from the
temporary spool file to the actual destination.
Otherwise, a
.I CN
message is sent.
(In the case of
.I CN ,
D 5
the transferred file will be in the spool
directory with a name beginning with ``TM'.)
E 5
I 5
D 6
the transferred file will be in a spool
subdirectory with a name beginning with ``TM'.)
E 6
I 6
the transferred file will be in the \fBTM.\fP spool subdirectory.)
E 6
E 5
The requests and results are logged on both systems.
.LP
The hangup response is determined by the
.I SLAVE
D 5
program by a work scan of the spool directory.
If work for the remote system exists in the
.I SLAVE's
E 5
I 5
program by a work scan of its spool directory.
If work for the \fIMASTER\fP\|'s system exists in the
\fISLAVE\fP\|'s
E 5
spool directory, an
.I HN
message is sent and the programs switch roles.
If no work exists, an
.I HY
response is sent.
.SH
Conversation Termination
.LP
When a
.I HY
message is received by the
.I MASTER
it is echoed back to the
.I SLAVE
and the protocols are turned off.
Each program sends a final ``OO'' message to the
other.
The original
.I SLAVE
program will clean up and terminate.
The
.I MASTER
will proceed to call other systems
and process work as long as possible
or terminate if a
D 6
.I \-s
E 6
I 6
.B \-s
E 6
option was specified.
.LP
D 6
.NH
E 6
I 6
.\"===========================================================================
.NH 2
E 6
Uuxqt - Uucp Command Execution
.LP
The
.I uuxqt
program is used to execute
.I
execute files
.R
generated by
.I uux.
The
.I uuxqt
program may be started by either the
.I uucico
or
.I uux
programs.
D 5
The program scans the spool directory for
E 5
I 5
D 6
The program scans the appropriate spool directory for
E 5
.I
execute files
.R
(prefix ``X.'').
E 6
I 6
The program scans the \fBX.\fP spool directory for
\fIexecute files\fP.
E 6
Each one is checked to see if all the required files are available and
if so, the command line or send line is executed.
.LP
The
.I
execute file
.R
D 6
is described in the ``Uux''
E 6
I 6
is described in the
.I uux
E 6
section above.
.SH
Command Execution
.LP
The execution is accomplished by executing a
.I
sh \-c
.R
of the command line after appropriate
standard input and standard output have been opened.
If a standard output is specified, the program
will create a send command or copy the output
file as appropriate.
D 6
.NH
E 6
I 6
.\"===========================================================================
.NH 2
E 6
D 4
Uulog - Uucp Log Inquiry
.LP
The
.I uucp
programs create individual
log files for each program invocation.
Periodically,
.I uulog
may be executed to prepend these files to the
system logfile.
This method of logging was chosen to minimize file
locking of the logfile during program execution.
.LP
The
.I uulog
program merges the individual
log files and outputs specified log entries.
The output request is specified by the use of the
following options:
.RS
.IP \-s\fIsys\fR 9
Print entries where
.I sys
is the remote system name;
.IP \-u\fIuser\fR
Print entries for user
.I user.
.RE
.LP
The intersection of lines satisfying the two options is output.
A null
.I sys
or
.I user
means all system names or users respectively.
.NH
E 4
Uuclean - Uucp Spool Directory Cleanup
.LP
D 6
This program is typically started by the daemon, once a day.
E 6
I 6
This program is typically started by the
\fIcron\fP(8)
daemon, once a day.
E 6
D 5
Its function is to remove files from the spool directory which
E 5
I 5
Its function is to remove files from the spool directories which
E 5
are more than 3 days old.
These are usually files for work which can not be completed.
.LP
.LP
The options available are:
.RS
.IP \-d\fIdir\fR 10
The directory to be scanned is
.I dir .
.IP \-m
Send mail to the owner of each file being removed.
(Note that most files put into the spool directory
will be owned by the owner of the
uucp programs since the setuid bit will be set on these
programs.
The mail will therefore most often go to the owner
of the uucp programs.)
.IP \-n\fIhours\fR
Change the aging time from 72 hours to
.I hours
hours.
.IP \-p\fIpre\fR
Examine files with prefix
.I pre
for deletion.
(Up to 10 file prefixes may be specified.)
.IP \-x\fInum\fR
This is the level of debugging output desired.
.RE
I 6
.\"===========================================================================
.\" SECTION 4: CONTROL FILES
.\"===========================================================================
.ne 5
E 6
.NH
D 4
Security
E 4
I 4
D 6
Changes to the UUCP Implementation
E 6
I 6
SYSTEM CONTROL FILES
E 6
.PP
D 5
The demands placed on UUCP networking,
and new technology,
E 5
I 5
D 6
The demands placed on UUCP networking
and new technology
E 5
have prompted several changes and improvements to the UUCP software.
Such things as low cost, autodial, autoanswer, high speed modems,
and the availability of X.25 and TCP/IP as carriers,
D 5
have encouraged new facilities in UUCP to be developed.
E 5
I 5
have encouraged new facilities to be developed for UUCP.
E 5
.PP
D 5
The following areas have been changed between the 4.2 and 4.3 BSD releases.
E 5
I 5
The following areas have been changed between the 4.2 and 4.3 BSD releases:
E 5
.IP \(bu 3
General fixes and performance improvements.
.IP \(bu 3
D 5
Administration control facilites.
E 5
I 5
Administration control facilities.
E 5
.IP \(bu 3
Modem and autodialer support has been extended.
.IP \(bu 3
New protocols for different transport media.
.IP \(bu 3
Security enhancements.
.SH
Fixes and performance improvements.
.PP
D 5
Many of the fixes related to portability considerations,
and improvements as provided by the USENET community.
E 5
I 5
These include many fixes related to portability
and general improvements as provided by the USENET community.
In particular, the \fIsitename\fR truncation length
has been extended to 14 characters from the original 7.
This makes it compatible with the current System V version of UUCP.
E 5
.PP
D 5
The \fIsitename\fR truncation length as been extended to 14 characters from
the original 7 characters.
This maintains compatibility with the current System V version of UUCP.
.PP
An effort as been made to improve the overall performance of the UUCP system
E 5
I 5
An effort has been made to improve the overall performance of the UUCP system
E 5
by organizing its workload in a more sensible way.
D 5
For example the program \fIuucico\fR will not resend files it has already sent,
E 5
I 5
For example the program \fIuucico\fR will not resend files it has already sent
E 5
when the files are specified in one ``C.'' file.
.SH
Administration and control facilities.
.PP
There is a new program, \fIuuq\fR,
to give more descriptive information on status of jobs in the UUCP spool queue.
D 5
It also allows the user to delete spooled requests,
still in the queue.
E 5
I 5
It also allows users to delete requests that are still in the queue.
E 5
.PP
In the past, on large UUCP sites,
the spool directory could grow large with many files
within the ``/usr/spool/uucp'' directory.
To help the UUCP administrator control the system,
D 5
a number of subdirectories have been created to easy this congestion.
E 5
I 5
a number of subdirectories have been created to ease this congestion.
E 5
.PP
The system status ``STST'' files are kept in a subdirectory.
.PP
D 5
Corrupted ``C.'' and ``X.'' files,
that could not be processed,
E 5
I 5
Corrupted ``C.'' and ``X.'' files
that could not be processed
E 5
are placed in the ``CORRUPT'' subdirectory,
D 5
instead of just exiting.
E 5
I 5
instead of terminating the connection.
E 5
.PP
Lock files may be kept in a subdirectory,
``LCK'',
if desired.
.PP
If an ``X.'' request fails,
the notification is returned to the originator of the request,
D 5
instead of ``uucp'' on the previous system. 
E 5
I 5
not to ``uucp'' on the previous system. 
E 5
.PP
There is a new \fIsystem\fR file, ``L.aliases'',
D 5
that may be used when a site changes it's name.
All the utilities,
\fIuucp\fR, \fIuux\fR, \fIuucico\fR, etc.,
all check ``L.aliases''.
E 5
I 5
that may be used when a site changes its name.
Most of the utilities
check ``L.aliases'' for correct mapping.
E 5
.SH
D 5
Modem and autodialer support:
E 5
I 5
Modem and autodialer support
E 5
.PP
In a short period of time,
D 5
there has been a big increase in the transfer rates and capabilites
E 5
I 5
there has been an increase in the transfer rates and capabilities
E 5
that are being provided with modern modems.
D 5
Most modems will allow several combinations of baud rate,
and provide autodial and autoanswer facilites as well.
E 5
I 5
Most modems allow several combinations of baud rate,
and provide autodial and autoanswer facilities as well.
E 5
.PP
D 5
Most sites will have but a few modems,
they are therefore a precious resource an effort has been made to use them
to maximum potential.
The \fIuucico\fR program now has code to dial in and out on the same device,
if that modem as both autodial and autoanswer provision.
.PP
There is a new dialing facility \fIacucntrl\fR that has been built to handle
E 5
I 5
Most sites will have but a few modems;
they are therefore a precious resource,
and an effort has been made to use them to maximum potential.
The \fIuucico\fR program now has code to place and receive calls on the same
device, if that modem has both autodial and autoanswer support.
There is a new dialing facility \fIacucntrl\fR that has been designed to handle
E 5
some of the changes in modem technology.
D 5
There are a number of new modems and autodialers that can now be handled.
E 5
I 5
There are a number of new modems and autodialers that are now supported.
E 5
Here is a list of some of the new devices:
D 5
Racal Vadic 212,
Racal Vadic 811 dialer with 831 adaptor,
Racal Vadic 820 dialer with 831 adaptor,
Racal Vadic MACS 811 dialer with 831 adaptor,
Racal Vadic MACS 820 dialer with 831 adaptor,
Dec DF112,
Novation,
Penril,
Hayes 2400 Smartmodem,
Concord Data Systems CDS 224,
ATT 2224 2400 baud modem.
.PP
It now correctly does the closing hangup sequence.
.PP
It will try up to TRYCALLS to dial a site
instead of one try for each dialer.
E 5
I 5
.sp
E 6
I 6
Seven \fIControl Files\fP are referenced by the \*(Uu utilities.
All live in the \*(Uu administrative directory, \fB/usr/lib/uucp\fP.
These are ASCII files, and can be modified using standard text editors such
as \fIvi\fP and \fIex\fP.
Lines beginning with a `#' character are comments;
lines ending with a `\e' are continued on the next input line.
E 6
.RS
D 6
.nf
Racal-Vadic 212
Racal-Vadic 811 dialer with 831 adapter
Racal-Vadic 820 dialer with 831 adapter
Racal-Vadic MACS 811 dialer with 831 adapter
Racal-Vadic MACS 820 dialer with 831 adapter
DEC DF112
Novation
Penril
Hayes 2400 Smartmodem
Concord Data Systems CDS 224
AT&T 2224 2400 baud modem
.fi
E 6
I 6
.IP L-devices(5) 15
Declares all devices that are available to \fIuucico\fP for calling out.
.IP L-dialcodes(5)
Phone number prefixes.
Used to map alphabetic prefixes on phone numbers from \fIL.sys\fP to
real phone numbers.
Also useful to keep a phone number database outside of \fIL.sys\fP.
.IP L.sys(5)
Systems.
Declares all ``adjacent'' \*(Uu hosts, with directions on how to reach them.
.IP L.aliases(5)
Contains aliases used to map obsolete or truncated host names to the
correct names.
.IP L.cmds(5)
Commands Permissions.
Declares those commands for which remote \fIuux\fP execution is permitted.
.IP SQFILE
Sequence-number check file. (Optional)
.IP USERFILE(5)
Directory Tree Permissions.
Specifies the set of directory trees that a particular user or host may
reference.
E 6
.RE
E 5
D 6
.SH
New protocols for different transportation mediums
.PP
The UUCP software has had provision for different protocols
D 5
to be used in the sending and receiving of data,
but originaly only one was implemented
E 5
I 5
to be used for sending and receiving data,
but originally only one was implemented
E 5
and this is the one that is largely used throughout the UUCP community.
D 5
The standard `g' protocol,
has a maxium throughput around 9000 baud,
E 5
I 5
It has a maximum throughput of around 9000 baud,
E 5
regardless of the physical medium.
D 5
The use of checksums and the like are of little use when the protocol
is bounded within another protocol such as TCP or X.25.
It is a waste of time and cpu resources to calculate CRC's
when the carrier already provides error free transmissions.
E 5
I 5
The use of checksums and short data packets are of little use when the protocol
is layered above another reliable protocol such as TCP or X.25.
E 5
The UUCP system did not utilize LAN's and high speed carriers well.
Two new protocols have been added
D 5
to provide for efficient use of new carrier facilities.
E 5
I 5
to provide for this.
E 5
The protocols now available to UUCP are:
.DS
D 5
`t' protocol, optimised for use on TCP/IP carriers.
`f' protocol, optimised for use on X.25 PAD carriers.
E 5
I 5
`t' protocol, optimized for use on TCP/IP carriers.
`f' protocol, optimized for use on X.25 PAD carriers.
E 5
`g' protocol, standard UUCP protocol used for dialup or hardwired lines.
.DE
.PP
D 5
The `t' protocol presumes an error free channel,
and is essentially the `g' protocol without the checksumming and packetizing.
Other changes where necessary to run UUCP on top of a TCP carrier,
the code could not do ioctl's on sockets that are connections to remote hosts.
.PP
The `f' protocol relies on flow control of the data stream.
It is meant for working over links that can be guaranteed to be errorfree,
E 5
I 5
The existing `g' protocol code has been cleaned up in this version.
The `t' protocol is essentially the `g' protocol except that the channel
is assumed to be free from errors.  As such, no checksums are used and
files are transferred without packetizing.
The `f' protocol relies on the flow control of the data stream.
It is meant for use over links that can be guaranteed
to be free from errors,
E 5
specifically X.25/PAD links.
D 5
A checksum is calculated over a whole file only.
E 5
I 5
The checksum is calculated over whole files only.
E 5
If a transport fails the receiver can request retransmissions.
D 5
This protocol uses a 7-bit datapath only,
so it may be used on carriers that are not 8-bit transparent.
.PP
As well as adding new protocols,
the existing `g' protocol code has been cleaned up.
E 5
I 5
This protocol uses a 7-bit data path only,
so it may be used on carriers that do not handle 8-bit data paths transparently.
E 5
.SH
Changes to \fIuucico\fR
.PP
I 5
\fIUucico\fP used to attempt to place a call using every dialer on the system.
Since this could take a long time at large sites, the defined constant TRYCALLS
now limits the number of attempts.
.PP
E 5
You can specify a maximum grade to send either
D 5
on the command line using (-gX)
or in the ``L.sys'' file
E 5
I 5
on the command line using -gX option
or by specifying the time to call in the ``L.sys'' file as follows:
E 5
.DS
D 5
Any/C|Evening will only send grade C,
E 5
I 5
Any/C,Evening 
E 5
.DE
I 5
This will only send grade C or higher transfers,
E 5
usually mail,
D 5
or higher during the day and will send everything in the evening
See Figure 5.
.SH
UUCP System files.
E 5
I 5
during the day and will send any grades in the evening.
E 5
.PP
D 5
The \fIsystem\fR files in the ``/usr/lib/uucp'' directory can contain comments,
by putting a `#' as the first character on a line.
Lines may be continued by placing a `\\' as the last character of a line.
This is helpful in making an understandable \fIL.sys\fR file.
E 5
I 5
The code for the closing hangup sequence has been fixed.
E 5
.PP
D 5
Some new options are available to \fIuucico\fR, these include:
E 5
I 5
Some new options were added to \fIuucico\fR.  These include:
E 5
.RS
.IP -R
D 5
This flag reverses \fIuucico\fR role.
Let the remote system be master first instead of being the slave.
E 5
I 5
This flag reverses \fIuucico\fR\|'s initial role
(lets the remote system be master first rather than slave).
E 5
.IP -L
\fIuucico\fR will only call ``local'' sites.
Local sites are those sites having one of
D 5
\fBLOCAL\fR, \fBTCP\fR or \fBDIRECT\fR in the CALLER field of ``L.sys''.
E 5
I 5
\fBLOCAL\fR, \fBTCP\fR or \fBDIR\fR in the CALLER field of ``L.sys''.
E 5
.RE
.PP
If ``/etc/nologin'' is present,
D 5
usually created by \fIshutdown\fR,
\fIuucico\fR and \fIuuxqt\fR will gracefully exit,
E 5
I 5
usually created by \fIshutdown\fR\|(8),
\fIuucico\fR and \fIuuxqt\fR will exit gracefully,
E 5
instead of getting killed off when the system goes down.
.PP
D 5
Does an exponential backoff on retry time if call fails
instead of always waiting the default 5 minutes.
The default may be overridden by adding ",TIME" to the time field in ``L.sys''.
E 5
I 5
\fIUucico\fP now uses an exponential back off on the retry time if
consecutive calls fail instead of always waiting 5 minutes.
The default may be overridden by adding ";\fItime\fP"
to the time field in ``L.sys''.
E 5
.DS
D 5
ucbvax Any,2
E 5
I 5
ucbvax Any;2
E 5
.DE
D 5
will use a default retry time of 2 minutes.
E 5
I 5
The preceding fragment indicates that a default retry time of 2 minutes will
be used.
E 5
.PP
If \fIuucico\fR receives a SIGFPE while running,
D 5
it will toggle debugging on and off.
E 5
I 5
it will toggle debugging.
E 5
.PP
D 5
It will not send files to remote system if the remote system
is returning an out of temp space error.
E 5
I 5
It will not send files to a remote system
returning an out of temporary file space error.
E 5
.PP
D 5
Add ABORT sequence to the expect/send sequence so it does not have
to wait for timeout if cannot get through a dataswitch.
See figure X.
This example will only call noao in the evening.
It will expect nothing,
then wait 1 second (\ed),
and then send a carriage return.
Look for CLASS, then send NOAOUUCP.
From then on,
if it sees the word Down before finishing logging in,
it will hang up immediately.
In the mean time,
it looks for GO,
when received,
delay 1 second and then send a CR.
Look for ``ogin:'', etc.
This abort sequence is useful
if you must go through a dataswitch to get to the computer.
E 5
I 5
More functionality has been added to the expect/send sequences.
The ABORT command was added to the expect/send sequence so it does not have
to wait for timeout if cannot get through a port selector.
You can specify a time for the expect/send sequences with ~
to override the default timeout.
The expect/send sequences now allow escape sequences to specify characters
that could not be specified before.
E 5
.PP
The time field in the ``L.sys'' file now handles
D 5
"Evening" and "Night" in addition to:
.DS
Any, Mo, Tu, We, Th, Fr, Sa, Su.
E 5
I 5
``Evening'', ``Night'', and ``NonPeak'' in addition to
Any, Mo, Tu, We, Th, Fr, Sa, Su, and Wk.
E 5
.DE
D 5
Evening and Night are defined to be:
.DS
Evening = Wk1700-0800|Sa|Su
Night = Any2300-0800|Sa|Su0800-1700
.DE
E 5
.PP
D 5
The expect/send code now handles '\e' sequences:
.RS
.IP "s"
indicates a space
.IP "d"
indicates a delay 1 second
.IP "r"
indicates a carriage return with no linefeed
.IP "b"
indicates a break
.IP "c"
indicates do not send a CR after these characters
.IP "xxx"
the octal character xxx (e.g. \es == \e040
.RE
.PP
The file \fIL-devices\fR now handles "chat" scripts,
E 5
I 5
The file \fIL-devices\fR now handles ``chat'' scripts,
E 5
to help get through local port selectors and smart modems.
D 5
This helps keep \fIL.sys\fR readable but increases functionality.
See figure 4.
E 5
I 5
This helps keep ``L.sys'' readable while using the increased functionality.
E 5
.PP
D 5
For compatibility with System V UUCP system,
in the Date fields of ``L.sys'':
E 5
I 5
For compatibility with the System V UUCP,
the following changes were made
in the date fields of ``L.sys'':
E 5
.DS
D 5
`|' was changed to `,' (| is supported, but not encouraged)
`,' was changed to `;' (to allow , to be the date seperator)
E 5
I 5
`|' changed to `,' (`|' is supported, but not encouraged)
`,' changed to `;' (to allow `,' to be the date separator)
E 5
.DE
.PP
For Honey DanBer compatibility,
D 5
the Grade flag is now passed as:
.DS
-vgrade=X
.DE
E 5
I 5
\fIuucico\fP now passes the maximum grade to the remote system as
``-vgrade=X''
E 5
instead of the old -pX
.PP
D 5
You can specify a time for the expect send sequences with ~ instead
of getting the default MAXMSGTIME.
For example:
.DS
system Any ACU 1200 1234567 ogin~20--ogin~10--ogin user password pw
.DE
will look for ``ogin'' for 20 seconds,
then send CR,
look for ``ogin'' for 10 seconds,
send a CR and look for ``ogin'' for MAXMSGTIME seconds
E 5
I 5
Support has been added for GTE's PC Pursuit service.
It is mainly the handling of the call back method they use.
E 5
.PP
D 5
Added code to support GTEs PC Pursuit service.
It's mainly the handling of the dialback they use.
.PP
Added time "NonPeak" for Tymnet/Telenet services that charge lower rates
from 6pm-7am M-F and Sat & Sun.
.SH
Security enhancements.
.PP
Running \fIuucico\fR with debugging turned on,
requires ``L.sys'' to have read access.
E 5
I 5
Users must now have read access to ``L.sys'' in order to run
\fIuucico\fP with debugging turned on.
E 5
.NH
The UUCP system.
.SH
Names
.PP
D 5
The naming of a site is important since it provides a means of
E 5
I 5
The name of a site is important since it provides a means of
E 5
identifying a machine,
and consequently,
that machine's users.
D 5
There are two names used within the UUCP system,
these are the \fIloginname\fR and the \fIsitename\fR.
E 5
I 5
There are two kinds of names used within the UUCP system;
\fIloginname\fRs and \fIsitename\fRs.
E 5
.PP
D 5
It is important that the \fIloginname\fR used by a remote machine
E 5
I 5
It is important that the \fIloginname\fRs used by a remote machine
E 5
to call into a local machine
is not the same as that of a normal user of the local machine.
D 5
It is common for many remote machines to have the same \fIloginname\fR,
such as uucp or nuucp.
E 5
I 5
Each \fIloginname\fP corresponds with a line in ``/etc/passwd''.
It is the administrator's decision whether each remote site should use
the same login name or different ones.
E 5
.PP
Each machine in a UUCP network is given a unique \fIsitename\fR.
The \fIsitename\fR identifies the calling machine to the called machine.
A \fIsitename\fR can be up to 14 characters in length.
It is useful to have a \fIsitename\fR that is unique in the first 7 characters,
D 5
to be compatible with earlier implementaions of UUCP.
E 5
I 5
to be compatible with earlier implementations of UUCP.
E 5
It is desirable that the \fIsitename\fR will convey this uniqueness
and perhaps a real world identity to the rest of the network.
D 5
.PP
The \fIsitename\fR and the \fIloginname\fR are not the same thing!
They may have the same values,
but this is purely a decision of the UUCP administrators
when the network connections are set up.
E 5
.SH
The UUCP system organization.
.PP
There are several directories that are used by the UUCP system as distributed.
These are:
.RS
D 5
.IP src 12
E 5
I 5
.IP src 10
E 5
(/usr/src/usr.bin/uucp)
D 5
This directory contains the source files for generating the UUCP system.
.IP system 12
E 5
I 5
This directory contains the source files for the UUCP system.
.IP system
E 5
(/usr/lib/uucp)
D 5
This is the directory where system binaries,
and system control files reside.
.IP spool 12
E 5
I 5
This directory contains the system binaries and system control files.
.IP spool
E 5
(/usr/spool/uucp)
D 5
This is the spool directory used to store transfer requests and data.
.IP commands 12
E 5
I 5
This spool directory is used to store transfer requests and data.
.IP command
E 5
(/usr/bin)
D 5
This is the directory where the programs used by users will be kept.
E 5
I 5
This directory contains the user-level programs.
E 5
.RE
.SH
The system directory
.PP
The following files are required for execution,
and should reside in the \fIsystem\fR directory,
/usr/lib/uucp.
.RS
.IP L-devices 15
D 5
This file contains entries for all devices that are to be used by UUCP.
E 5
I 5
Contains entries for all devices that are to be used by UUCP.
E 5
.IP L-dialcodes 15
D 5
This file contains dialing abbreviations.
E 5
I 5
Contains dialing abbreviations.
E 5
.IP L.aliases 15
D 5
Used to provide sitename aliases.
E 5
I 5
Contains site name aliases.
E 5
.IP L.cmds 15
D 5
This file contains commands that can be used by a remote site.
E 5
I 5
Contains the list of commands that can be used by a remote site.
E 5
.IP L.sys 15
Contains site connection information for each system that can be called.
.IP SEQF 15
The sequence numbering and check file.
.IP USERFILE 15
Remote system access rights.
.IP acucntrl 15
The program used to control calling remote systems.
.IP uucico 15
The actual transfer program.
.IP uuclean 15
D 5
A utility to cleanup after UUCP.
E 5
I 5
A utility to clean up after UUCP.
E 5
.IP uuxqt 15
D 5
Allows UUCP to execute commands.
E 5
I 5
Executes commands received from remote systems.
E 5
.RE
.SH
The command directory
.PP
The \fIcommand\fR directory, /usr/bin,
contains the following user available commands:
.RS
.IP uucp 15
D 5
spools a UNIX to UNIX file-copy request.
E 5
I 5
Spools a UNIX to UNIX file-copy request.
E 5
.IP uux 15
D 5
spools a request for remote execution.
E 5
I 5
Spools a request for remote execution.
E 5
.IP uusend 15
D 5
provides a facility to transfer binary files using mail.
E 5
I 5
Provides a facility to transfer binary files using mail.
E 5
.IP uuencode 15
D 5
binary file encoder (for \fIuusend\fR)
E 5
I 5
Binary file encoder (for \fIuusend\fR)
E 5
.IP uudecode 15
D 5
binary file decoder (for \fIuusend\fR)
E 5
I 5
Binary file decoder (for \fIuusend\fR)
E 5
.IP uulog 15
D 5
reports from log files.
E 5
I 5
Reports from log files.
E 5
.IP uusnap 15
D 5
provides a snap-shot of \fIuucp\fP activity.
E 5
I 5
Provides a snapshot of \fIuucp\fP activity.
E 5
.IP uupoll 15
D 5
polls remote system until an answer is received.
E 5
I 5
Polls a remote system.
E 5
.IP uuname 15
D 5
prints a list of known remote UUCP hosts.
E 5
I 5
Prints a list of known remote UUCP hosts.
E 5
.IP uuq 15
D 5
reports information from the UUCP spool queue.
E 5
I 5
Reports information from the UUCP spool queue.
E 5
.RE
.SH
The spool directory
.PP
The \fIspool\fR directory,
/usr/spool/uucp,
contains the following files and directories:
.RS
.IP C. 15
D 5
A directory for command, ``C.'' files.
E 5
I 5
A directory for command (``C.'') files.
E 5
.IP D. 15
D 5
A directory for data, ``D.'', files.
E 5
I 5
A directory for data (``D.'') files.
E 5
.IP X. 15
D 5
A directory for command execution, ``X.'', files.
E 5
I 5
A directory for command execution (``X.'') files.
E 5
.IP D.\fImachine\fP 15
A directory for local ``D.'' files.
.IP D.\fImachine\fPX 15
A directory for local ``X.'' files.
.IP CORRUPT 15
A directory for corrupted ``C.'' and ``X.'' files.
.IP ERRLOG 15
A file where internal error messages are collected.
.IP LCK 15
D 5
A directory for device and site lock files.
E 5
I 5
A directory for device and site lock files (optional).
E 5
.IP LOG 15
D 5
A directory for individual site LOGFILE's.
E 5
I 5
A directory for individual site LOGFILE's (optional).
E 5
.IP LOGFILE 15
D 5
the log file of UUCP activity.
E 5
I 5
The log file of UUCP activity (optional).
E 5
.IP STST 15
D 5
A directory for site STST files.
E 5
I 5
A directory for per site system status files (``STST'').
E 5
.IP SYSLOG 15
D 5
the log file of UUCP file transfers.
E 5
I 5
The log file of UUCP file transfers.
E 5
.IP TM. 15
D 5
A directory for temporary, ``TM.'', files.
E 5
I 5
A directory for temporary (``TM.'') files.
E 5
.RE
.PP
I 5
This version has broken the spool directory into the above list
of directories leaving only a few system files in the top level
directory.  The logs from each system may be kept together or
in separate files in a subdirectory (LOG).  This decision is
made when the system is compiled.
.PP
E 5
There is an additional directory,
/usr/spool/uucppublic,
D 5
that is used as a general Public accecs directory for UUCP.
E 5
I 5
that is used as a general public access directory for UUCP.
E 5
It is not used by UUCP directly
but it is normally the home directory for the UUCP system owner.
Most importantly this directory is owned by uucp,
D 5
and the access permissions are 0777,
this usually garrantees a place that files can be sent to,
E 5
I 5
and the access permissions are 0777.
This usually guarantees a place that files can be copied to,
E 5
and retrieved from,
on any site.
.NH
System file details.
I 5
.PP
The \fIsystem\fR files in the ``/usr/lib/uucp'' directory can contain comments,
by putting a `#' as the first character on a line.
Lines may be continued by placing a `\e' as the last character of a line.
This is helpful in making the files more readable.
E 5
.SH
L-devices
.PP
This file contains entries for the call-unit devices and
hardwired connections which are to be used by UUCP.
The special device files are assumed to be in the /dev directory.
.PP
The format for each entry is:
.DS
\fIType Device Useful Class Dialer\fR [\fIChat\fR ...]
.DE
E 6
E 4
.LP
I 6
A general description of each file follows; see the \fIman\fP pages for
complete information.
Examples of the six standard files are included in the distribution in the
\fB/usr/lib/uucp/UUAIDS\fP directory.
.NH 2
L-devices \- \*(UU Devices File
.LP
This file declares all devices that are available to
\fIuucico\fP
for calling out.
The special device files are assumed to be in the
.I /dev
directory.
The format for each entry is
.IP "" 12
caller  line  call-unit  class  dialer  [chat....]
.LP
E 6
D 4
.LG
\fB
E 4
I 4
where;
D 6
.IP \fIType\fR 10
D 5
is the type of calling to use.
There are several different calling types.
E 5
I 5
Is the type of connection to use.
.sp
E 6
E 5
.RS
D 5
.br
\fBACU\fR indicates a dialing devices.
.br
\fBDIR\fR is used when a direct connection is used.
.br
\fBDK\fR an AT&T Datakit.
.br
\fBMICOM\fR Micom terminal switch.
.br
\fBPAD\fR X.25 PAD connection.
.br
\fBPCP\fR GTE Telenet PC Pursuit.
.br
\fBSYTEK\fR Sytek high-speed dedicated modem port.
.br
\fBTCP\fR TCP/IP connection.
E 5
I 5
D 6
.IP \fBACU\fR 12
Indicates that a dialing device is used.
.IP \fBLOCAL\fR
Indicates an \fBACU\fP with a ``preferred'' connection.
.IP \fBDIR\fR
Indicates that a direct connection is used.
.IP \fBDK\fR
Indicates that an AT&T Datakit is used.
.IP \fBMICOM\fR
Indicates that a Micom terminal switch is used.
.IP \fBPAD\fR
Indicates that a X.25 PAD connection is used.
.IP \fBPCP\fR
Indicates that GTE Telenet PC Pursuit is used.
.IP \fBSYTEK\fR
Indicates that a Sytek high-speed dedicated modem port is used.
.IP \fBTCP\fR
Indicates that a TCP/IP connection is used.
E 6
I 6
.IP caller 12
is the caller mechanism, that is, the type of device to be used.
This can be one of  \fBACU\fP (for Automatic
Call Units (modem)), \fBDIR\fP (direct hardwired), \fBPAD\fP
(X.25/PAD), and others.
.IP line
is the device for the link.
For example, \fBcul0\fP for a modem, \fBtty10\fP for a hardwired line.
.IP call-unit
is the automatic call unit associated with
\fIdevice\fP.
This is used on autodialers such as the Racal-Vadic MACS and the
DEC DN-11 that use one device for data, and a second device for dialing.
If unused, this field must contain a placeholder such as ``unused'' or ``0''.
Some modems use this field to specify tone or pulse dialing.
.IP class
is the line speed, plus an optional alphabetic prefix.
The prefix can be used to distinguish among different devices that
have identical \fIcaller\fP and line speed.
.IP dialer
applies to \fBACU\fP devices only;
this is the type or brand name of the modem.
Supported modems include \fBDN11\fP (DEC DN-11),
\fBhayes\fP (Hayes Smartmodem),
\fBvadic\fP (Racal-Vadic 3451),
\fBventel\fP (VenTel 212A), and others.
.IP chat
refers to an \fIexpect/send\fP script, similar to that provided in
\fIL.sys\fP.
The difference is that the script in
.I L-devices
is executed before the connection is established, while the script in
.I L.sys
is executed afterwards.
E 6
E 5
.RE
D 6
.IP \fIDevice\fR 10
D 5
is the entry in ``/dev'' corresponding to a real device,
the owner should be uucp.
.IP \fIUseful\fR 10
information to be used by the device,
such as the name of the callunit to be used,
or maybe ``unused''.
E 5
I 5
Is the entry in ``/dev'' corresponding to a real device.
UUCP should be able to access this device.
.IP \fICall_Unit\fR 10
Is the device for dialing if different from the device used for the data
transfer.
This field must contain a place holder if unused (such as ``unused'').
E 5
.IP \fIClass\fR 10
D 5
is the line speed.
E 5
I 5
is the line baud rate for dialers and direct lines or the port number
for network connections.
E 5
.IP \fIDialer\fR 10
is either \fBdirect\fR,
or from the list of available dialers.
The list of available dialers includes:
.RS
D 5
.IP \fBDF02\fR 10
E 5
I 5
.IP \fBDF02\fR 12
E 5
DEC DF02 or DF03 modems.
D 5
.IP \fBDF112\fR 10
Dec DF112 modems.
E 5
I 5
.IP \fBDF112\fR 12
DEC DF112 modems.
E 5
Use a \fIDialer\fR field of \fBDF112T\fR to use tone dialing,
or \fBDF112P\fR for pulse dialing.
D 5
.IP \fBatt\fR 10
E 5
I 5
.IP \fBatt\fR 12
E 5
AT&T 2224 2400 baud modem.
D 5
.IP \fBcds224\fR 10
E 5
I 5
.IP \fBcds224\fR 12
E 5
Concord Data Systems 224 2400 baud modem.
D 5
.IP \fBdn11\fR 10
DEC DN11 Unibus dialer.
.IP \fBhayes\fR 10
E 5
I 5
.IP \fBdn11\fR 12
DEC DN11 \s-2UNIBUS\s+2 dialer.
.IP \fBhayes\fR 12
E 5
Hayes Smartmodem 1200 and compatible autodialing modems.
Use a \fIDialer\fR field of \fBhayestone\fR to use tone dialing,
or \fBhayespulse\fR for pulse dialing.
It is also permissible to include the letters `T' and `P' in the phone number
D 5
(in \fIL.sys\fR)
E 5
I 5
(in ``L.sys'')
E 5
to change to tone or pulse midway through dialing.
(Note that a leading `T' or `P' will be interpreted as a dialcode!)
D 5
.IP \fBhayes2400\fR 10
E 5
I 5
.IP \fBhayes2400\fR 12
E 5
Hayes Smartmodem 2400 and compatible modems.
Use a \fIDialer\fR field of \fBhayes2400tone\fR to use tone dialing,
or \fBhayes2400pulse\fR for pulse dialing.
D 5
.IP \fBnovation\fR 10
E 5
I 5
.IP \fBnovation\fR 12
E 5
Novation ``Smart Cat'' autodialing modem.
D 5
.IP \fBpenril\fR 10
E 5
I 5
.IP \fBpenril\fR 12
E 5
Penril Corp ``Hayes compatible'' modems.
D 5
.IP \fBrvmacs\fR 10
E 5
I 5
.IP \fBrvmacs\fR 12
E 5
Racal-Vadic 820 dialer with 831 adapter in a MACS configuration.
D 5
.IP \fBva212\fR 10
E 5
I 5
.IP \fBva212\fR 12
E 5
Racal-Vadic 212 autodialing modem.
D 5
.IP \fBva811s\fR 10
E 5
I 5
.IP \fBva811s\fR 12
E 5
Racal-Vadic 811s dialer with 831 adapter.
D 5
.IP \fBva820\fR 10
E 5
I 5
.IP \fBva820\fR 12
E 5
Racal-Vadic 820 dialer with 831 adapter.
D 5
.IP \fBvadic\fR 10
E 5
I 5
.IP \fBvadic\fR 12
E 5
Racal-Vadic 3450 and 3451 series autodialing modems.
D 5
.IP \fBventel\fR 10
E 5
I 5
.IP \fBventel\fR 12
E 5
Ventel 212+ autodialing modem.
D 5
.IP \fBvmacs\fR 10
E 5
I 5
.IP \fBvmacs\fR 12
E 5
Racal-Vadic 811 dialer with 831 adapter in a MACS configuration.
.RE
.IP \fIChat\fR
is a send/expect sequence that can be used to talk through dataswitches,
D 5
or issue special comands to a device such as a modem.
The syntax is identical to that of the Expect/Send script of \fIL.sys\fR.
E 5
I 5
or issue special commands to a device such as a modem.
The syntax is identical to that of the Expect/Send script of ``L.sys''
and will be described later.
E 5
The difference is that,
the \fIL-devices\fR script is used before the connection is made,
D 5
while the \fIL.sys\fR script is used after.
E 5
I 5
while the ``L.sys'' script is used after.
E 5
.SH
L-dialcodes
.PP
E 6
I 6
.LP
The line
.IP "" 12
ACU\ \ tty47\ \ unused\ \ 1200\ \ hayes
.LP
would be set up for a system which
had device tty47 wired to a 
Hayes ``Smartmodem 1200''
for use at 1200 baud.
.NH 2
L-dialcodes \- Phone Number Prefix File
.LP
E 6
This file contains entries with location abbreviations used
D 6
in the ``L.sys'' file (e.g. py, mh, boston).
The entry format is:
.DS
E 6
I 6
in the
.I L.sys
file (e.g. py, mh, boston).
The entry format is
.IP "" 12
E 6
abb\ \ dial-seq
D 6
.DE
E 6
.LP
where;
.RS
.IP abb 12
is the abbreviation,
.IP dial-seq
is the dial sequence to call that location.
.RE
D 5
.PP
E 5
I 5
.LP
E 5
The line
.IP "" 12
py\ \ 165\-
.LP
D 5
would be set up so that entry py7777 would
E 5
I 5
D 6
would be set up so that entry py7777 in ``L.sys'' would
E 6
I 6
would be set up so that entry py7777 would
E 6
E 5
send 165\-7777 to the dial-unit.
D 6
.SH
L.aliases.
.PP
D 5
The \fIL.aliases\fR file provides a mapping facility of \fIsitenames\fR.
This facility is useful when \fIsitenames\fR are changed,
and the change is only temporary,
or the change is permanent but it is not widely known by the users of the net.
E 5
I 5
The \fIL.aliases\fR file provides a mapping facility for \fIsitename\fRs.
This facility is useful when a \fIsitename\fR is changed temporarily,
or until a permanent change becomes widely known by the users of the net.
E 5
The format of the file is:
.DS
real_name alias_name
.DE
The ``L.aliases'' file may be used to map hosts with longer names in ``L.sys''
to 7 character names that some hosts send.
This provides a mechanism to handle those sites,
entries should be:
.DS
	fullname 7-char-name
.DE
.SH
L.cmds
.PP
The L.cmds file contains a list of commands that are permitted
for remote execution with \fIuux\fR.
The commands are listed one per line.
Most sites L.cmds will be something like:
.DS
rmail
I 5
rnews
E 5
ruusend
.DE
A line of the form:
.DS
PATH=/bin:/usr/bin:/usr/ucb:/usr/local/bin
.DE
can be used to set a search path.
.SH
L.sys
.PP
E 6
I 6
.NH 2
L.aliases \- Hostname Aliases File
.LP
This file defines mapping (aliasing) of remote host names.
This is intended for compensating for systems that have
changed names, or do not provide their entire machine name
(like most USG systems).
It is also useful when a machine's name is not obvious or commonly misspelled.
.LP
Each line is of the form
.IP
real-name\ \ alias-name
.LP
where
.I real-name
is the full, correct name for the host, and
.I alias-name
is the old or truncated name.
.NH 2
L.sys \- \*(Uu Systems File
.LP
E 6
Each entry in this file represents one system
D 5
which can be called by the local UUCP programs.
The fields are described below.
E 5
I 5
D 6
that communicates with the local system and has the form:
E 5
.DS
\fISitename  Times  Caller  Class  Device\fR  [\fIExpect  Send\fR]....
.DE
.IP \fISitename\fR 10
is the name of the remote system.
Every machine with which this system communicates via UUCP should be listed,
regardless of who calls whom.
Systems not listed in ``L.sys'' will not be permitted a connection.
.PP
.IP \fITimes\fR 10
is a comma-separated list of the times of the day and week that 
calls are permitted to this site.
This can be used to restrict long distance telephone calls
to those times when rates are lower.
List items are constructed as:
.DS
\fIkeyword\fPhhmm\fB-\fPhhmm\fB/\fP\fIgrade\fP\fB;\fP\fIretry_time\fP
.DE
\fIKeyword\fR is required, and must be one of:
E 6
I 6
which can be called by the local uucp programs.
The format for each entry is
.IP
system  times  caller  class  device/phone-number  [login]
.LP
where;
E 6
.RS
D 5
.IP \fBAny\fR 8
E 5
I 5
D 6
.IP \fBAny\fR 10
E 5
Any time, any day of the week.
D 5
.IP \fBWk\fR 8
E 5
I 5
.IP \fBWk\fR
E 5
Any weekday. In addition,
\fBMo, Tu, We, Th, Fr, Sa,\fR and \fBSu\fR
D 5
can be used for Monday through Sunday, respectively.
.IP \fBEvening\fR 8
E 5
I 5
can be used.
.IP \fBEvening\fR
E 5
When evening telephone rates are in effect,
from 1700 to 0800 Monday through Friday,
and all day Saturday and Sunday.
.B Evening
is the same as
.B Wk1700-0800,Sa,Su .
D 5
.IP \fBNight\fR 8
E 5
I 5
.IP \fBNight\fR
E 5
When nighttime telephone rates are in effect,
from 2300 to 0800 Monday through Friday,
all day Saturday, and from 2300 to 1700 Sunday.
.B Night
is the same as
.B Any2300-0800,Sa,Su0800-1700 .
D 5
.IP \fBNonPeak\fR 8
E 5
I 5
.IP \fBNonPeak\fR
E 5
This is a slight modification of 
.B Evening .
It matches when the USA X.25 carriers have their lower rate period. This
is 1800 to 0700 Monday through Friday, and all day Saturday and Sunday.
.B NonPeak
is the same as
.B Any1800-0700,Sa,Su .
D 5
.IP \fBNever\fR 8
Never call;
calling into this site is forbidden or impossible.
E 5
I 5
.IP \fBNever\fR
Calling this site is forbidden or impossible.
E 5
This is intended for polled connections,
where the remote system calls into the local machine periodically.
D 5
This is necessary when one of the machines is lacking
either dial-in or dial-out modems.
E 5
.PP
The optional \fIhhmm-hhmm\fR
subfield provides a time range that modifies the keyword.
.I hhmm
refers to
.I hours
and
.I minutes
in 24-hour time (from 0000 to 2359).
The time range is permitted to "wrap" around midnight,
and will behave in the obvious way.
It is invalid to follow the \fBEvening\fR, \fBNonPeak\fR,
and \fBNight\fR keywords with a time range.
.PP
The \fIgrade\fR subfield is optional; if present,
it is composed of a `/' (slash) and single character denoting the \fIgrade\fR
of the connection.
Grades are in the range [\fB0-9A-Za-z\fR].
This specifies that only requests of grade \fIgrade\fR
or better will be transferred during this time.
(The grade of a request or job is specified
when it is queued by \fIuucp\fR or \fIuux\fR).
By convention, mail is sent at grade \fBC\fR,
news is sent at grade \fBd\fR,
and uucp copies are sent at grade \fBn\fR.
D 5
Unfortunately, some sites do not follow these conventions,
so it is not 100% reliable.
E 5
I 5
Unfortunately, some sites do not follow these conventions consistently.
E 5
.PP
The \fIretry_time\fR subfield is optional;
it must be preceded by a `;' (semicolon) and
D 5
specifies the time, in minutes,
before a failed connection may be tried again.
E 5
I 5
specifies the minimum time, in minutes,
before a failed connection will be tried again.
E 5
By default,
the retry time starts at 10 minutes and gradually increases at each failure,
until after 26 tries \fIuucico\fR gives up completely (MAX RETRIES).
If the retry time is too small,
\fIuucico\fR may run into MAX RETRIES too soon.
.RE
.IP \fICaller\fR 10
is the type of device used.
It may be one of the following:
.DS
D 5
\fBACU DIR MICOM PAD PCP SYTEK TCP\fR
E 5
I 5
\fBACU DIR LOCAL MICOM PAD PCP SYTEK TCP\fR
E 5
.DE
D 5
the derscriptions in L-devices apply here.
E 5
I 5
The descriptions are the same as listed in ``L-devices'' above.
E 5
If several alternate ports or network connections should be tried,
use multiple
D 5
.I L.sys
E 5
I 5
``L.sys''
E 5
entries.
.IP \fIClass\fR 10
is usually the speed (baud) of the device,
typically 300, 1200, or 2400 for \fRACU\fR devices and 9600 for direct lines.
Valid values are device dependent,
and are specified in the ``L-devices'' file.
.PP
On some devices,
the speed may be preceded by a non-numeric prefix.
This is used in ``L-devices''
to distinguish among devices that have identical \fICaller\fR and baud,
but yet are distinctly different.
For example,
1200 could refer to all Bell 212-compatible modems,
V1200 to Racal-Vadic modems,
and C1200 to CCITT modems,
all at 1200 baud.
.PP
On TCP connections,
.I Class
D 5
is the port number (an integer number) or a port name from ``/etc/services''
E 5
I 5
is the port number (an integer) or a port name from ``/etc/services''
E 5
that is used to make the connection.
For standard Berkeley TCP/IP,
UUCP normally uses port number 540.
.IP \fIDevice\fR 10
varies based on the \fICaller\fR field.
For \fBACU\fR devices,
this is the phone number to dial.
The number may include: digits \fB0\fR through \fB9\fR;
.B #
and
.B *
for dialing those symbols on tone telephone lines;
.B -
(hyphen) to pause for a moment, typically two to four seconds;
.B =
(equal sign) to wait for a second dial tone
(implemented as a pause on many modems).
Other characters are modem dependent;
generally standard telephone punctuation characters
(such as the slash and parentheses) are ignored, although
.I uucico
does not guarantee this.
.PP
The phone number can be preceded by an alphabetic
string; the string is indexed and converted through the ``L-dialcodes'' file.
.PP
For \fBDIR\fR devices, the
.I Device
field contains the name of the device in /dev
that is used to make the connection.
There must be a corresponding line in ``L-devices'' with identical
\fICaller, Class\fR, and \fIDevice\fR fields.
.PP
For \fBTCP\fR and other network devices,
.I Device
D 5
holds the true network name of the remote system,
which may be different from its UUCP name
(although one would hope not).
E 5
I 5
holds the network name for establishing a connection to the remote system,
which may be different from its UUCP name.
E 5
.PP
The
.I Expect
and
.I Send
refer to an arbitrarily long set of strings that
alternately specify what to
E 6
I 6
.IP "system" 12
is the hostname of the remote system.
.IP times
is a keyword-encoded string that indicates the days-of-the-week
and times-of-day when the system may
be called.
For example \fBMoTuTh0800\-1730\fP would denote Monday, Tuesday,
and Thursday, between 8 a.m. and 5:30p.m.
.IP
The day portion may be a list containing
any of
\fBSu\fP, \fBMo\fP, \fBTu\fP, \fBWe\fP, \fBTh\fP, \fBFr\fP, \fBSa\fP,
or 
.B Wk
for any week-day or
.B Any
for any day.
.IP
The time should be a range of times (as in \fB0800\-1230\fP).
If no time portion is specified, any time
of day is assumed to be acceptable for the call.
.IP caller
is one of the caller device-types listed in \fIL-devices\fP.
.IP class
is the line speed for the call (e.g., 300, 1200, 9600),
plus an optional alphabetic prefix.
Network devices use this field for the network port number.
.IP phone
is the the phone number to call (for \fBACU\fP devices) or the
device filename. 
A phone number is made up of an optional
alphabetic abbreviation and a numeric part.
The abbreviation is one which appears in the
.I L-dialcodes
file (e.g. mh5900, boston995\-9980).
.IP login
is a script describing how to log in to the remote host.
It is expressed as a series of
fields and subfields in the format
.IP "" 17
expect\ \ send\ 
[
expect\ \ send
]
\ ...
.IP "" 12
where;
E 6
.I expect
D 6
and what to
E 6
I 6
is the string expected to be read and
E 6
.I send
D 6
to login to the remote system once a physical connection has
been established.  A complete set of expect/send strings is referred
D 5
to as an
.IR "expect/send script" .
E 5
I 5
to as an ``\fIexpect\fP/\fIsend script\fP''.
E 5
The same syntax is used in the
.I L\-devices
file to interact with the dialer prior to making a connection;
there it is referred to as a \fIchat script\fR.
The complete format for one
.I expect/send
pair is:
.PP
.DS
D 5
\fIexpect\fP\fB~\fP\fItimeout\fP\fB-\fP\fIsend\fP\fB-\fP\fI\
E 5
I 5
\fIexpect\fP\fB~\fP\fItimeout\fP\fB\-\fP\fIfailsend\fP\fB\-\fP\fI\
E 5
expect\fP\fB~\fP\fItimeout   send\fP
.DE
.PP
D 5
.I Expect
E 5
I 5
.I Expect,
.I failsend,
E 5
and
E 6
I 6
is the string to be sent when the
.I expect
string is received.
The
E 6
D 5
.I Send
E 5
I 5
.I send
E 5
D 6
are character strings.
.I Expect
D 5
is compared against in coming text from the remote host;
E 5
I 5
is compared against incoming text from the remote host;
E 6
I 6
string is normally terminated with carriage-return;
an empty
E 6
E 5
.I send
D 6
is sent back when
.I expect
is matched.  By default, the
E 6
I 6
string will send only a carriage-return.
.IP
The expect field may be made up of subfields
of the form
.IP "" 17
expect\fB[\fR\-send\-expect\fB]\fR...
.IP "" 12
where the
E 6
.I send
D 6
is followed by a `\er' (carriage return). If the
E 6
I 6
is sent if the prior
E 6
.I expect
D 6
string is not matched within
.I timeout
seconds (default 45), then it is assumed that the match failed.
D 5
The `\fIexpect\fP\fB-\fP\fIsend\fP\fB-\fP\fIexpect\fP' notation 
E 5
I 5
The `\fIexpect\fP\fB-\fP\fIfailsend\fP\fB-\fP\fIexpect\fP' notation 
E 5
provides a limited loop mechanism; if the first
E 6
I 6
is not successfully read
and the
E 6
.I expect
D 6
string fails to match, then the
D 5
.I send
E 5
I 5
.I failsend
E 5
string between the hyphens is transmitted, and
.I uucico
waits for the second
.I expect
string. This can be repeated indefinitely. When the last
.I expect
string fails,
.I uucico
hangs up and logs that the connection failed. 
.PP
The timeout can (optionally) be specified by appending the parameter
`\fB~\fP\fInn\fP' to the expect string, when \fInn\fR is the timeout
time in seconds.
.PP
D 5
Backslash escapes that may be imbedded in the
E 5
I 5
Backslash escapes that may be embedded in the
E 5
.I expect
or
E 6
I 6
following the
E 6
.I send
D 6
strings include:
.PP
E 6
I 6
is the next expected string.
.RE
.LP
A typical entry in the L.sys file would be
.IP "" 6
sys\ Any\ ACU\ 1200\ \ mh7654\ login:--login:\ uucp\ ssword:\ word
.LP
The expect algorithm looks at the last part of the
string as illustrated in the password field.
.NH 2
L.cmds \- Commands Permissions File
.LP
This file contains a list of commands, one per line, that are permitted
for remote execution via \fIuux\fP.
This list should be chosen with great care, since commands that take filenames
as arguments will allow users to easily circumvent \*(Uu's security.
For most sites,
.I L.cmds
should only include the lines:
E 6
.DS
D 6
\eb	Generate a 3/10 second BREAK.
\eb\fIn\fP	Where \fIn\fP is a single-digit number;
	generate an \fIn\fP/10 second BREAK.
\ec	Suppress the \er at the end of a \fIsend\fP string.
\ed	Delay; pause for 1 second. (\fISend\fR only.)
\er	Carriage Return.
\es	Space.
\en	Newline.
\exxx	Where \fIxxx\fP is an octal constant;
	denotes the corresponding ASCII character.
E 6
I 6
rmail
ruusend
E 6
.DE
D 6
.PP
D 5
As a special case, an empty pair of double-quotes \fB""\fP in the
E 5
I 5
As a special case, an empty pair of double-quotes \fB"\|"\fP in the
E 5
.I expect
string is interpreted as ``expect nothing'';
that is, transmit the \fIsend\fR string regardless of what is received.
Empty double-quotes in the \fIsend\fR string
cause a lone `\er' (carriage return) to be sent.
.PP
One of the following keywords may be substituted for the
.I send
string:
D 5
.DS
E 5
I 5
.sp
.TS
l l.
E 5
BREAK	Generate a 3/10 second BREAK
BREAK\fIn\fP	Generate an \fIn\fP/10 second BREAK
D 5
CR	Send a Carriage Return (same as "").
E 5
I 5
CR	Send a Carriage Return (same as "\|").
E 5
EOT	Send an End-Of-Transmission character, ASCII \e004.
	Note that this will cause most hosts to hang up.
NL	Send a Newline.
PAUSE	Pause for 3 seconds.
PAUSE\fIn\fP	Pause for \fIn\fR seconds.
P_ODD	Use odd parity on future send strings.
P_ONE	Use parity one on future send strings.
P_EVEN	Use even parity on future send strings. (Default)
P_ZERO	Use parity zero on future send strings.
D 5
.DE
E 5
I 5
.TE
E 5
.PP
Finally, if the
.I expect
D 5
string consists of the keyword
.BR ABORT ,
then the string following is used to arm an abort trap. If that string
E 5
I 5
string consists of the keyword \fBABORT\fP,
the following string is used to arm an abort trap. If that string
E 5
is subsequently received any time prior to the completion of the entire
.I expect/send
script, then
.I uucico
will abort, just as if the
script had timed out. This is useful for trapping error messages from
port selectors or front-end processors such as ``Host Unavailable'' or
``System is Down.''
.PP
D 5
For example:
.PP
E 5
I 5
An example expect/send sequence might look something like this:
E 5
.DS
D 5
""  ""  ogin:--ogin:  nuucp  ssword:  ufeedme
E 5
I 5
"\|" \ed\er CLASS HOST ABORT Down GO \ed\er ogin:~30-\eb-ogin: uucp word: password
E 5
.DE
D 5
.PP
This is executed as, ``When the remote system answers,
.I expect
nothing.
.I Send
a carriage return.
.I Expect
the remote to transmit the string `ogin:'. If it doesn't
within 45 seconds, send another carriage return.  When it finally does,
.I send
it the string `nuucp'.  Then
.I expect
the string `ssword:'; when that is received,
.I send
`ufeedme'.''
E 5
I 5
First, \fIuucico\fP will expect nothing,
wait 1 second (\ed),
and then send a carriage return.
The next expected message is ``CLASS'', in response to which \fIuucico\fP
sends ``HOST''.
From then on,
if it sees the word ``Down'' before finishing logging in,
it will hang up immediately.
In the mean time,
it looks for ``GO''.
After this is received,
it delays 1 second and then sends a CR.
\fIUucico\fP resets the timeout to 30 seconds while whating to
receive ``ogin:''.  If there is no response, a break will be sent
and the program will wait for 45 seconds for ``ogin:'' again.
When this is received, ``uucp'' will be sent.  The sequence ends by waiting
for ``word:'' and responding with ``password''.
At this point, UUCP has completed the login and continues with the protocol
for establishing the connection..
E 5
.SH
USERFILE
.PP
E 6
I 6
.NH 2
SQFILE \- Sequence Check File (Optional)
.LP
This file contains an entry for each remote
system with which this site agrees to perform conversation
sequence checks.
The initial entry is just the system name of
the remote system.
The first conversation will add two items to the line,
the conversation count, and the date/time of the most
resent conversation.
These items will be updated with each conversation.
If a sequence check fails, which could indicate that an unauthorized
connection has been attempted, the entry will have to
be adjusted.
.LP
This facility is technically no longer supported in 4.3BSD \*(Uu,
since it was hardly ever used and consumed precious memory space on PDP-11
systems.
The compile-time #define GNXSEQ can be set to enable sequence checking
should it be needed.
.NH 2
USERFILE \- Pathnames Permissions File
.LP
E 6
This file contains user accessibility information.
D 6
It specifies the file system directory trees that are accessible to
local users and to remote systems via UUCP
E 6
I 6
It specifies four types of constraint;
.RS
.IP [1]
which files can be accessed by a normal user of the local machine,
.IP [2]
which files can be accessed from a remote computer,
.IP [3]
which login name is used by a particular remote computer,
.IP [4]
whether a remote computer should be called back in order to confirm
its identity.
.RE
.LP
Each line in the file has the following format
.IP "" 6
login,sys\ \ 
.B [
c
.B ]
\ \ path-name\ \ 
.B [
path-name
.B ]
\ ...
.LP
where;
.RS
.IP login 12
is the login name for a user or the remote computer,
.IP  sys
is the system name for a remote computer,
.IP c
is the optional
.I
call-back required
.R
flag,
.IP path-name
is a path-name prefix that is acceptable for
.I user.
.LP
.RE
.LP
The constraints are implemented as follows.
.RS
.IP [1]
When the program is obeying a command stored on the local machine,
.I MASTER
mode,
the path-names allowed are those given for the first line in the
.I USERFILE
that has a login name that matches the login name of the user
who entered the command.
If no such line is found, the first line with a
.I null
login name is used.
.IP [2]
When the program is responding to a command from a remote machine,
.I SLAVE
mode, the path-names allowed are those given for the first line
in the file that has the system name that matches the system name
of the remote machine.
If no such line is found, the first one with a
.I null
system name is used.
.IP [3]
When a remote computer logs in, the login name that
it uses must appear in the
.I USERFILE .
There may be several lines with the same login name but one of them must
either have the name of the remote system or must contain a
.I null
system name.
.B Note:
This constraint, although stated in the original Nowitz \*(Uu document,
was not implemented in Version 7 \*(Uu.
For all practical purposes,
a remote computer's login was not validated by \*(Uu.
This is still the case in 4.3BSD.
Remote login checking \fIis\fP implemented in AT&T's System VR2.2 release,
and in the \*(Uu provided with Digital Equipment Corporation's ULTRIX.
HoneyDanBer analogously requires all remote logins to be listed in
its \fIPermissions\fP file.
.IP [4]
If the line matched in ([3]) contains a ``c'',
the remote machine is called back before any transactions take place.
.RE
.LP
The line
.IP "" 12
u,m  /usr/xyz
.LP
allows machine
.I m
to login with name
.I u
and request the transfer of files whose names start with
``/usr/xyz''.
.LP
The line
.IP "" 12
dan,  /usr/dan
.LP
allows the ordinary user
.I dan
to issue commands for files whose name starts with
``/usr/dan''.
.LP
The lines
.IP "" 12
u,m /usr/xyz  /usr/spool
.br
u,  /usr/spool
.LP
allows any remote machine to login with name
.I u ,
but if its system name is not
.I m ,
it can only ask to transfer files whose names start with
``/usr/spool''.
.LP
The lines
.IP "" 12
root,  /
.br
,   /usr
.LP
allows any user to transfer files beginning with ``/usr''
but the user with login
.I root
can transfer any file.
E 6
.PP
D 6
Each line in
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 5
is of the form:
.DS
[\fIloginname\fP]\fB,\fP[\fIsitename\fP] [ \fBc\fP ] \fIpathname\fP \c
[\fIpathname\fP] [\fIpathname\fP]
.DE
.PP
The first two items are separated by a comma;
any number of spaces or tabs may separate the remaining items.
.PP
The \fIloginname\fR
D 5
is a login name (from ``/etc/passwd'')
E 5
I 5
is a user name (from ``/etc/passwd'')
E 5
on the local machine.
.PP
The \fIsitename\fR
D 5
is the name of a remote machine,
this is the same name used in ``L.sys''.
E 5
I 5
is the name of a remote machine.
This is the same name used in ``L.sys''.
E 5
.PP
The \fIc\fR denotes the optional \fIcallback\fR field.
If a \fBc\fP appears here,
a remote machine that calls in will be told that callback is requested,
and the conversation will be terminated.
The local system will then immediately call the remote host back.
.PP
The \fIpathname\fR
is a pathname prefix that is permissible for this \fIloginname\fR
and/or \fIsitename\fR.
.PP
I 5
When \fIuucico\fP
runs in master role or \fIuucp\fP or \fIuux\fP
are run by local users, the permitted pathnames are those on the
first line with a
.I loginname
that matches the name of the user who executed the command.
If no such line exists, then the first line with a null (missing)
.I loginname
field is used.
(Beware:
.I uucico
is often run by the superuser or the UUCP administrator through \fIcron\fP.
.PP
When
.I uucico
runs in slave role, the permitted pathnames are those on the
first line with a
.I sitename
field that matches the hostname of the remote machine.
If no such line exists, then the first line with a null (missing)
.I sitename
field is used.
.PP
.I Uuxqt
works differently; it knows neither a login name nor a hostname.
E 5
It accepts the pathnames on the first line that has a null
D 5
.I system 
E 5
I 5
.I sitename 
E 5
field.
I 5
(This is the same line that is used by
.I uucico
when it cannot match the remote machine's hostname.)
E 5
.PP
D 5
A line with both \fIloginname\fR and \fIsitename\fR are null,
for example
E 5
I 5
A line with both
.I loginname
and
.I sitename
null, for example
E 5
.DS
,  /usr/spool/uucppublic
D 5
.DE
can be used to conveniently specify the paths for both "no match" cases
E 5
I 5
.DE	
can be used to conveniently specify the paths for both ``no match'' cases
E 5
if lines earlier in ``USERFILE'' did not define them.
E 6
I 6
.\"===========================================================================
.\" SECTION 5: SPOOL FILES
.\"===========================================================================
.ne 5
E 6
.NH
D 6
Installing the UUCP system.
E 6
I 6
SPOOL FILES
E 6
.PP
D 6
There are several source modifications that may be required
before the system programs are compiled.
.PP
Two files which may require modification,
the ``Makefile'' file and the ``uucp.h'' file.
The following paragraphs describe some of the options
available at build time.
.SH
Uucp.h modifications
.PP
D 5
The installer of UUCP may wish to change some of the defines in ``uucp.h'',
some of the interesting defines are mentioned below.
E 5
I 5
The installer of UUCP may wish to change some of the defines in ``uucp.h''.
Some of the interesting defines are mentioned below.
E 5
.PP
if \fBDIALINOUT\fR is defined then \fIacucntrl\fR will allow modems to be
used in both directions.
.PP
If \fBDONTCOPY\fR is defined in ``uucp.h'',
\fIuucp\fR will not make a copy of the source file by default.
.PP
if \fBLOCKDIR\fR is defined then lock files
will be stored in the ``/usr/spool/uucp/LCK'' directory.
.PP
If \fBLOGBYSITE\fR is defined,
\fIuucp\fR logging is done with a log file per site,
instead of one LOGFILE.
.PP
If \fBNOSTRANGERS\fR is defined in ``uucp.h'',
the remote site must be in your ``L.sys'' or the call will be rejected.
.SH
Makefile modification
.PP
There are several
.I make
variable definitions which may need modification.
E 6
I 6
Spool Files contain \*(Uu transfer requests and data.
Most have been described in detail earlier in this document.
.LP
All spool files live in the
.B /usr/spool/uucp
directory tree.
To keep the spool directory from becoming hopelessly cluttered,
each type of spool file is kept in its own subdirectory.
The name of the directory is the same as the common prefix of the
filename.
For example, \fIwork files\fP (files beginning with \fBC.\fP) are kept
in the \fBC.\fP directory; \fIexecute files\fP (which begin with \fBX.\fP)
are kept in the \fBX.\fP directory, and so on.
.LP
A total of ten spool subdirectories are used, one of which is optional:
E 6
.RS
D 5
.IP DESTDIR 12
where all the system will end up,
normal from the root.
.IP LIBDIR 12
${DESTDIR}/usr/lib/uucp, low level binaries, site information, and dialing
information resides here.
.IP BIN 12
${DESTDIR}/usr/bin, the user utilities reside here.
.IP ETC 12
${DESTDIR}/etc
.IP PUBDIR 12
${DESTDIR}/usr/spool/uucppublic, uucp owns this directory.
A place where files can almost always be sent.
.IP SPOOL 12
${DESTDIR}/usr/spool/uucp,
where all commands and data is held until transfers can take place.
.IP XQTDIR 12
${SPOOL}/XTMP, a place where UUCP executeable commands will be kept.
.IP CORRUPT 12
${SPOOL}/CORRUPT, where corrupted ``C.'' and ``D.'' files end up.
E 5
I 5
D 6
.IP LIBDIR 15
the directory where
low level binaries, site information, and dialing
information are stored
.IP BIN
The directory in which the user utilities reside.
.IP PUBDIR
A directory where files can almost always be sent.
This should be UUCP's home directory and writable by everyone.
.IP SPOOL
The top level spool directory.
.IP XQTDIR
The directory where temporary files will be stored by \fIuuxqt\fP.
E 6
I 6
.IP C. 15
\fIWork\fP files.
E 6
.IP CORRUPT
D 6
The directory where corrupted ``C.'' and ``D.'' files end up.
E 5
.IP AUDIT
D 5
${SPOOL}/AUDIT, an audit trail.
.IP LCK 12
${SPOOL}/LCK, a place to keep lock files.
LOG= ${SPOOL}/LOG
.IP STST 12
${SPOOL}/STST, a place to keep ``STST'' files for different systems.
.IP HOSTNAME 12
the machines name.
.IP SUBDIRS 12
There are six subdirs,
not counting XTMP, that may be built under SPOOL,
these are,
``C.'', ``D.\fIHOSTNAME\fRX'', ``D.\fIHOSTNAME\fR'', ``D.'', ``X.'', and ``TM.''.
E 5
I 5
The directory where debugging traces are stored by \fIuucico\fP when
debugging is remotely enabled or enabled by a signal.
E 6
I 6
Corrupted \fIwork\fP and \fIexecute\fP files.
\fIUucico\fP and \fIuuxqt\fP will deposit \fBC.\fP and \fBX.\fP files here
when they are unable to parse them.
A notice will also be placed in the \*(Uu log.
.IP D.
\fIData files\fP received from remote hosts.
.IP D.\fIhostname\fP
\fIData files\fP to be sent to remote hosts.
.IP D.\fIhostname\fPX
\fIExecution files\fP to be sent to remote hosts.
E 6
.IP LCK
D 6
The directory where lock files are kept.
\fITip\fP\|(1) and other programs may need to be
modified if this is changed as the lock files are shared.
.IP LOG
The directory where the log files are placed if ``LOGBYSITE'' is defined
in ``uucp.h''.
E 6
I 6
Per-device and per-site lock (\fBLCK.\fP) files. (Optional)
E 6
.IP STST
D 6
The directory where the remote system status files (``STST'') are stored.
.IP HOSTNAME
The machine's name.
E 6
I 6
Per-site system status files.
.IP TM.
Temporary files used in data transfer.
When the transfer is complete, the file is typically
\fImv\fP'ed to the \fBD.\fP or \fBX.\fP directory.
.IP X.
\fIExecution files\fP received from remote sites. 
.IP XTMP
Temporary files and home directory for \fIuuxqt\fP.
E 6
E 5
.RE
D 6
.SH
Building the system
.PP
E 6
I 6
.LP
The following sections describe only those spool files that were not
discussed earlier.
.NH 2
LCK \- lock files
.LP
Lock files are created for each device in use (except for TCP/IP sockets)
and each system conversing.
This prevents duplicate conversations and multiple attempts to use the
same devices.
The form of the lock file name is
.IP "" 12
\fBLCK..\fRstr
.LP
where
.I str
is either a device or system name.
The files may be left in the spool directory if
.I uucico
aborts.
They will be ignored (reused) after 90 minutes.
When runs abort and calls are desired before the time limit expires,
the lock files should be removed.
If the \fBLCK.\fP subdirectory is used, it's access mode can be set to 777,
thus allowing normal users to remove dead lock files when necessary.
.NH 2
STST \- system status files
.LP
These files are created in the \fBSTST\fP subdirectory by
\fIuucico\fP.
They contain information of failures such as login, dialup, or
sequence check, and will contain a
\fITALKING\fP, \fIRECEIVING\fP, or \fPSENDING\fP
status when two machines are conversing.
The file name is
\fBSTST/\fP\fIsystem\fP,
where \fIsystem\fP is the host name of the remote machine.
.LP
For ordinary failures (dialup, login), the file indicates the time
of the last failure;
this allows \fIuucico\fP to avoid retrying the failed call too soon.
For sequence check failures, the file must be removed before
any future attempts to converse with that remote system.
.LP
If the file is left due to an aborted run, it may contain a
.I TALKING
status.
In this case, the file must be removed before a conversation
is attempted.
The easiest way to do this is to use the \fIuupoll\fP command to
force \fIuucico\fP to start up.
.NH 2
TM \- temporary data files
.LP
These files are created in the
.B /usr/spool/uucp/TM.
directory while files are being copied
from a remote machine.
Their names have the form
.IP "" 12
\fBTM\fR.pid.ddd
.LP
where
.I pid
is a process-id and
.I ddd
is a sequential three digit number starting at zero
for each invocation of
.I uucico
and incremented for each file received.
After the entire remote file is received, the
.B TM
file is moved to the requested destination,
often the \fBX.\fP or \fBD.\fP directory.
If processing is abnormally terminated or the
move fails, the file will remain in the
\fBTM.\fP directory.
.LP
The stranded files should be periodically removed;
the
.I uuclean
program is useful in this regard.
E 6
The command
I 6
.IP "" 12
uuclean\ \ -d/usr/spool/uucp/TM.\ \ \-pTM.
.LP
will remove all
.B TM
files older than three days.
.\"===========================================================================
.\" SECTION 6: LOG FILES
.\"===========================================================================
.ne 5
.NH
LOG FILES
.LP
The following files provide a history of \*(Uu activities.
All live in the spool directory, \fB/usr/spool/uucp\fP.
They grow forever, and must be periodically trimmed or deleted;
this is usually done weekly (or daily) via \fIcron\fP.
.RS
.IP AUDIT 12
This is a directory of audit trail files, one file per site.
.I Uucico
uses an audit file for debugging output
whenever it is run with debug enabled (via the \fB-x\fP option or a
\fBSIGFPE\fP signal), but the standard message output file \fBstderr\fP is
not available.
.IP ERRLOG
This is an oft-forgotten log of \*(Uu ``Assert'' errors.
An Assert error is a catastrophic and unrecoverable failure of the \*(Uu
system.
These include spool directories or control files that cannot be opened, 
an unexpected error return from a system call, or an ``impossible case''
in a utility's control flow.
.IP
Utilities that abort with an Assert error return a status code of -1.
If a user reports \fIuucp\fP or \fIuux\fP dying with a message like
``uux failed, status -1,'' then the ERRLOG file should be checked.
.IP LOGFILE
This is the primary \*(Uu log. All \*(Uu activity is recorded here,
including queue requests from \fIuucp\fP and \fIuux\fP, attempted
connections, file transfers, and communications failures.
.IP SYSLOG
This is a log of file transfer statistics: number of bytes, time required,
and number of packet retries.
The effective data rate can be calculated simply by dividing the number of
bytes by the time;
low data rates or a large number of retries implies that the communication
link may marginal.
.RE
.LP
Optionally, one \fILOGFILE\fP per site may be maintained in the \fBLOG\fP
subdirectory.
This option can be selected at \*(Uu compile time via the LOGBYSITE #define
in \fBuucp.h\fP.
.\"===========================================================================
.\" SECTION 7: ADMINSTRATION AND SYSTEM SECURITY
.\"===========================================================================
.ne 5
.NH
ADMINISTRATION AND SYSTEM SECURITY
.NH 2
.UX 
System Files
.SH
/etc/passwd
.LP
\*(Uu requires a login in \fB/etc/passwd\fP;
at its simplest the entry would be
E 6
.DS
D 6
make
E 6
I 6
uucp::66:1:UNIX-to-UNIX Copy:/usr/spool/uucppublic:/usr/lib/uucp/uucico
E 6
.DE
D 6
will compile the entire system.
.PP
The command
E 6
I 6
.LP
This user should own all the \*(Uu files and utilities.
Remote sites wishing to call in for \*(Uu transfers would login to
\fBuucp\fP (with the correct password, if any), and get
.I uucico
as their ``shell.''
Since \fIuucico\fP would be called without any options, it would run in
.I SLAVE
mode, thus responding correctly to the remote system, which
would be in
.I MASTER
mode.
.LP
The directory
.B /usr/spool/uucppublic
should be created with 777 access modes, owned by \fBuucp\fP.
In addition to serving as the home directory for \*(Uu remote logins,
.B uucppublic
provides a ``public-access'' directory where any user can read, write,
or transfer files.
.LP
There are a number of security problems with using a single login, not
the least of which is that superuser permission would be necessary to
edit the \fIcontrol\fP files.
A better arrangement would be:
E 6
.DS
D 5
make makedirs
E 5
I 5
D 6
make mkdirs
E 6
I 6
uucp::66:1:UUCP Administrator:/usr/lib/uucp:
nuucp::67:1:UNIX-to-UNIX Copy:/usr/spool/uucppublic:/usr/lib/uucp/uucico
E 6
E 5
.DE
D 6
will build all the directories needed for the system,
giving them appropriate owners and permissions.
.PP
The command
E 6
I 6
This provides one login for the \*(Uu administrator (which must be kept
secure!) and a second for remote machines to use for login.
A still more elaborate setup would use a separate login for each remote
site, and possibly provide the administrator with a choice of shells:
E 6
.DS
D 6
make install
E 6
I 6
uucp::66:1:UUCP Administrator:/usr/lib/uucp:
UUCP::66:1:UUCP Administrator:/usr/lib/uucp:/bin/csh
Uhosta::6001:1:UNIX-to-UNIX Copy:/usr/spool/uucppublic:/usr/lib/uucp/uucico
Uhostb::6002:1:UNIX-to-UNIX Copy:/usr/spool/uucppublic:/usr/lib/uucp/uucico
Uhostc::6003:1:UNIX-to-UNIX Copy:/usr/spool/uucppublic:/usr/lib/uucp/uucico
E 6
.DE
D 6
.PP
will install the commands in the correct directories,
setting ownership and permissions.
.NH
Connecting new systems to the network.
.PP
When first connecting a new machine to a UUCP network,
it is advisable to try and establish a connection with
E 6
I 6
.LP
It is assumed that the login name
used by a remote computer to dial in
is not the same as the login name of a normal user
of the machine.
However, several remote computers may employ the same
login name.
.LP
Note that
.B uucppublic
is
.I not
used as the home directory for
.B uucp
when it logs into a regular shell.
This would be an extreme security hazard, since anyone could slip a
``Trojan horse'' into a
.B .profile
or
.B .cshrc
file, which would be automatically executed when the \*(Uu administrator
logged in.
.SH
/etc/rc
.LP
The system startup file, \fB/etc/rc\fP, should clean up any stray lock
files with the line
.IP
rm -f /usr/spool/uucp/LCK.*
.LP
or, if the LCK subdirectory is being used,
.IP
rm -f /usr/spool/uucp/LCK/LCK.*
.SH
/etc/services
.LP
If \*(Uu is to be used over TCP/IP links, then an entry for \*(Uu's port
number should be added to \fB/etc/services\fP:
.IP
uucp\ \ 540/tcp\ \ uucpd\ \ # UUCP TCP/IP
.\"===========================================================================
.NH 2
Shell Scripts For Periodic Cleanup
.LP
The \*(Uu system has a fairly large number of activities that must
occur periodically.
These include starting \fIuucico\fP to process queued requests,
running \fIuuclean\fP to remove old spool files, and
shuffling the boundlessly-growing log files.
Some sites will also want to poll other sites periodically.
.LP
While it's possible to put all the necessary commands into \fIcron\fP's
control file \fB/usr/lib/crontab\fP, this would be extremely awkward.
The usual technique is to use three separate shells scripts, one each
for hourly, daily, and weekly operations.
Examples are provided in the
.B UUAIDS
directory; the following sections provide some specific recommendations.
.SH
Hourly
.LP
Activities that should occur hourly include:
.RS
.IP - 2
Polling of selected sites.
Sites that have no dial-out capability will need to be periodically polled.
The \fIuupoll\fP command works well for this.
.IP -
Start \fIuucico\fP to complete all unfinished work.
This can be as simple as:
.IP "" 7
uucico -r1 &
.RE
.SH
Daily
.LP
The daily script should be started by \fIcron\fP in the wee hours, around
4 a.m.
Activities that should occur daily include:
.RS
.IP - 2
Call
.I uuclean
to remove old spool files.
The preferred technique is something like the following:
.DS
cd /usr/lib/uucp
deadtime=`expr 24 * 7`
uuclean -d/usr/spool/uucp/AUDIT -n72
uuclean -d/usr/spool/uucp/LCK -pLCK. -pLTMP. -n24
uuclean -d/usr/spool/uucp/STST -n72
uuclean -d/usr/spool/uucp/TM. -pTM. -n72
uuclean -d/usr/spool/uucp/XTMP -n72
uuclean -d/usr/spool/uucp/X. -pX. -n$deadtime
uuclean -d/usr/spool/uucp/C. -pC. -n$deadtime
uuclean -d/usr/spool/uucp/D. -pD. -n$deadtime
uuclean -d/usr/spool/uucp/D.`uuname -l` -pD. -n$deadtime
uuclean -d/usr/spool/uucp/D.`uuname -l`X -pD. -n$deadtime
.DE
.IP
In this example,
Audit files, Lock files, System Status files, temp files, and \fIuuxqt\fP
output files are cleaned up every 72 hours (3 days).
(\fBLTMP.\fP files are temporary files created by the lock mechanism;
they are rarely around for more than a few seconds.
Note, the above assumes that the
.B LCK
subdirectory is being used.)
All normal data files are cleaned up every 24 * 7 hours, or every 7 days.
.IP -
Shuffle the log files.
At the very least, LOGFILE should be moved to LOGFILE.old, and SYSLOG moved
to SYSLOG.old.
Busy sites may want to use \fIcompress\fP(1) to squeeze down the old files.
.IP -
Use \fIfind\fP(1) to clean up the
.B /usr/spool/uucppublic
directory.
If left unattended, garbage will gradually accumulate there until it fills
the file system.
.RE
.SH
Weekly
.LP
Small sites with very little traffic may chose to shuffle the log files once
per week, instead of once per day.
The weekly script should, like the daily script, be run early in the morning.
.\"===========================================================================
.NH 2
Connecting new systems
.LP
When first connecting a new machine to a \*(Uu network,
it is useful to try and establish a connection with
E 6
\fItip\fR or \fIcu\fR first.
D 6
The administrator should then be aware of any special facilities
E 6
I 6
The \*(Uu administrator will quickly become aware of any special facilities
E 6
that are going to be required,
D 6
things like;
E 6
I 6
for example:
E 6
What lines and modems are to be used?
D 5
or
is the connection through different hardware and carriers?
E 5
I 5
Is the connection through different hardware and carriers?
E 5
Does the remote system care about parity?
What speed lines are being used and do they cycle through several speeds?
D 6
Is there a line switch front end that will require special Chat dialogue in
D 5
``L.sys''?
E 5
I 5
``L.sys''\|?
E 5
.PP
D 5
Once a \fIlogin\fR connection can be completed the Admisitrator should
E 5
I 5
Once a \fIlogin\fR connection can be completed the administrator should
E 5
have enough information to allow the correct setup of the \fIsystem\fR files
in /usr/lib/uucp.
.PP
The UUCP administrator should then
D 5
negociate with the remote site UUCP administrator
as to when and who will do polling.
The relevant accounts and passwords must be set up.
Decide on what permissions and security precausions are to be observed.
Arrange testing time and facilites to complete initial connection to the system.
E 5
I 5
negotiate with the remote site's UUCP administrator
as to who will do polling and when.
E 6
I 6
Is there a line switch front end that will require special login dialogue in
\fBL.sys\fP?
.LP
Once a successful login is achieved ``by hand,'' the administrator should
have enough information to allow the correct setup of the \fIcontrol\fR files
in
.B /usr/lib/uucp.
.LP
The \*(Uu administrator should then
negotiate with the remote site's \*(Uu administrator
as to who (if anyone) will do polling and when.
E 6
Both administrators must set up the relevant accounts and passwords.
D 6
The UUCP administrator should
E 6
I 6
The local administrator should
E 6
decide on what permissions and security precautions are to be observed.
Testing time and facilities will need to be arranged
to complete initial connection testing between the systems.
E 5
D 6
.NH
Security
.PP
E 4
The uucp system, left unrestricted,
E 6
I 6
.\"============================================================================
.NH 2
Miscellaneous Security Issues
.LP
The \*(Uu system, left unrestricted,
E 6
will let any outside user execute any commands
D 5
and copy in/out any file which is readable/writable
by the uucp login user.
E 5
I 5
and copy any files that are accessible
D 6
to the uucp login user.
E 6
I 6
to the
.B uucp
login user.
E 6
E 5
It is up to the individual sites to be aware of this and
apply the protections that they feel are necessary.
D 4
\fR
.NL
.LP
E 4
I 4
.PP
E 4
There are several security features available aside from the
normal file mode protections.
These must be set up by the installer of the
D 6
.I uucp
E 6
I 6
\*(Uu
E 6
system.
.IP - 3
The login for uucp does not get a standard shell.
D 6
Instead, the
E 6
I 6
Instead, 
E 6
.I uucico
D 6
program is started.
E 6
I 6
is started.
E 6
Therefore, the only work that can be done is through
.I uucico .
.IP -
A path check is done on file names that are to be sent
or received.
D 6
The
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 6
I 6
.I USERFILE
E 6
E 5
supplies the information for these checks.
D 6
The
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 6
I 6
.I USERFILE
E 6
E 5
can also be set up to require call-back
for certain login-ids.
D 5
(See the ``Files required for execution'' section
for the file description.)
E 5
I 5
D 6
(See the description of ``USERFILE'' above.)
E 6
I 6
(See the description of 
.I USERFILE
above.)
E 6
E 5
.IP -
A conversation sequence count can be set up so
that the called system
can be more confident that the caller
is who he says he is.
.IP -
D 6
The
.I uuxqt
program comes with a list of commands that it
E 6
I 6
.I Uuxqt
is restricted via the
.I L.cmds
file to a small list of commands that it
E 6
will execute.
A ``PATH'' shell statement is prepended to the command
D 5
line as specifed in the
E 5
I 5
line as specified in the
E 5
D 6
.I uuxqt
program.
The installer may modify the list or remove the
E 6
I 6
.I L.cmds
file.
The administrator may modify the list or remove the
E 6
restrictions as desired.
.IP -
D 6
The
D 5
.I L.sys
file should be owned by uucp and have mode 0400
E 5
I 5
``L.sys''
file should be owned by uucp and only readable by uucp
E 5
to protect the phone numbers and login information
for remote sites.
(Programs uucp, uucico, uux, uuxqt should be also
D 5
owned by uucp and have the setuid bit set.)
E 5
I 5
owned by uucp and have the set user id bit set.)
E 6
I 6
All the \*(Uu utilities except \fIuudecode\fP, \fIuuencode\fP,
and \fIuusend\fP should be owned by the
.B uucp
login with the ``setuid'' bit set and only execute
permissions (e.g. mode 04111).
This will prevent outsiders from modifying the programs
to get at a standard shell with a
.B uucp
login.
Optionally, the utilities may belong to group \fBdaemon\fP and be given
``setgid'' permissions (mode 06111).
\fIUuxqt\fP should only permit other \*(Uu programs to execute it;
its mode should be 04100 or 06110.
.IP -
The \fIcontrol\fP files \fIL.sys\fP, \fIUSERFILE\fP, and \fISQFILE\fP
contain highly sensitive information.
They should be owned by the
.B uucp
login, with read and write permission granted only to the owner (mode 0600).
.\"===========================================================================
.\" SECTION 7: UUCP SOURCE INSTALLATION
.\"===========================================================================
.ne 5
E 6
E 5
.NH
D 4
Uucp Installation
.LP
There are several source modifications that may be required
before the system programs are compiled.
These relate to the directories used during compilation,
the directories used during execution,
and the local
.I
uucp system-name.
.R
.LP
The four directories are:
.RS
.IP lib 12
(/usr/src/cmd/uucp)
This directory contains the source files for generating the
.I uucp
system.
.IP program
(/usr/lib/uucp)
This is the directory used for the executable system programs and
the system files.
.IP spool
(/usr/spool/uucp)
This is the spool directory used during
.I uucp
execution.
.IP xqtdir
(/usr/spool/uucp/.XQTDIR)
This directory is used during execution of
.I "execute files" .
.RE
.LP
The names given in parentheses above are the default values
for the directories.
The italicized named
.I
lib, program, xqtdir,
.R
and
.I spool
will be used in the following text to represent the
appropriate directory names.
.LP
There are two files which may require modification,
the
.I makefile
file and the
.I uucp.h
file.
The following paragraphs describe the modifications.
The modes of
.I spool
and
.I xqtdir
should be made ``0777''.
.SH
Uucp.h modification
.LP
Change the
.I program
and the
.I spool
names from the default values to the directory
names to be used on the local system using
global edit commands.
.LP
Change the
.I define
value for
.I MYNAME
to be the local
.I uucp
system-name.
.SH
makefile modification
.LP
There are several
.I make
variable definitions which may need modification.
.RS
.IP INSDIR 10
This is the
.I program
directory
(e.g. INSDIR=/usr/lib/uucp).
This parameter is used if ``make cp'' is
used after the programs are compiled.
.IP IOCTL
This is required to be set if an appropriate
.I ioctl
interface subroutine does not exist in the standard
``C'' library;
the statement
``IOCTL=ioctl.o'' is required in this case.
.IP PKON
The statement ``PKON=pkon.o'' is required if the
packet driver is not in the kernel.
.RE
.SH
Compile the system
The command
.IP "" 12
make
.LP
will compile the entire system.
The command
.IP "" 12
make cp
.LP
will copy the commands to the
to the appropriate directories.
.LP
The programs
.I uucp ,
.I uux ,
and
.I uulog
should be put in ``/usr/bin''.
The programs
.I uuxqt ,
.I uucico ,
and
.I uuclean
should be put in the
.I program
directory.
.SH
Files required for execution
.LP
There are four files which are required for execution,
all of which should reside in the
.I program
directory.
The field separator for all files is a space unless otherwise
specified.
.SH
L-devices
.LP
This file contains entries for the call-unit devices and
hardwired connections which are to be used by
.I uucp.
The special device files are assumed to be in the
.I /dev
directory.
The format for each entry is
.IP "" 12
line\ \ call-unit\ \ speed
.LP
where;
.RS
.IP line 12
is the device for the line (e.g. cul0),
.IP call-unit
is the automatic call unit associated with
.I line
(e.g. cua0),
(Hardwired lines have a number ``0'' in this field.),
.IP speed
is the line speed.
.RE
.LP
The line
.IP "" 12
cul0\ \ cua0\ \ 300
.LP
would be set up for a system which
had device cul0 wired to a call-unit
cua0 for use at 300 baud.
.SH
L-dialcodes
.LP
This file contains entries with location abbreviations used
in the
.I L.sys
file (e.g. py, mh, boston).
The entry format is
.IP "" 12
abb\ \ dial-seq
.LP
where;
.RS
.IP abb 12
is the abbreviation,
.IP dial-seq
is the dial sequence to call that location.
.RE
.LP
The line
.IP "" 12
py\ \ 165\-
.LP
would be set up so that entry py7777 would
send 165\-7777 to the dial-unit.
.SH
LOGIN/SYSTEM NAMES
.LP
It is assumed that the
.I "login name"
used by a remote computer to call into a local computer
is not the same as the login name of a normal user
of that local machine.
However, several remote computers may employ the same
login name.
.LP
Each computer is given a unique
.I "system name"
which is transmitted at the start of each call.
This name identifies the calling machine to the called machine.
.SH
USERFILE
.LP
This file contains user accessibility information.
It specifies four types of constraint;
.RS
.IP [1]
which files can be accessed by a normal user of the local machine,
.IP [2]
which files can be accessed from a remote computer,
.IP [3]
which login name is used by a particular remote computer,
.IP [4]
whether a remote computer should be called back in order to confirm
its identity.
.RE
.LP
Each line in the file has the following format
.IP "" 6
login,sys\ \ 
.B [
c
.B ]
\ \ path-name\ \ 
.B [
path-name
.B ]
\ ...
.LP
where;
.RS
.IP login 12
is the login name for a user or the remote computer,
.IP  sys
is the system name for a remote computer,
.IP c
is the optional
.I
call-back required
.R
flag,
.IP path-name
is a path-name prefix that is acceptable for
.I user.
.LP
.RE
.LP
The constraints are implemented as follows.
.RS
.IP [1]
When the program is obeying a command stored on the local machine,
.I MASTER
mode,
the path-names allowed are those given for the first line in the
.I USERFILE
that has a login name that matches the login name of the user
who entered the command.
If no such line is found, the first line with a
.I null
login name is used.
.IP [2]
When the program is responding to a command from a remote machine,
.I SLAVE
mode, the path-names allowed are those given for the first line
in the file that has the system name that matches the system name
of the remote machine.
If no such line is found, the first one with a
.I null
system name is used.
.IP [3]
When a remote computer logs in, the login name that
it uses must appear in the
.I USERFILE .
There may be several lines with the same login name but one of them must
either have the name of the remote system or must contain a
.I null
system name.
.IP [4]
If the line matched in ([3]) contains a ``c'',
the remote machine is called back before any transactions take place.
.RE
.LP
The line
.IP "" 12
u,m  /usr/xyz
.LP
allows machine
.I m
to login with name
.I u
and request the transfer of files whose names start with
``/usr/xyz''.
.LP
The line
.IP "" 12
dan,  /usr/dan
.LP
allows the ordinary user
.I dan
to issue commands for files whose name starts with
``/usr/dan''.
.LP
The lines
.IP "" 12
u,m /usr/xyz  /usr/spool
.br
u,  /usr/spool
.LP
allows any remote machine to login with name
.I u ,
but if its system name is not
.I m ,
it can only ask to transfer files whose names start with
``/usr/spool''.
.LP
The lines
.IP "" 12
root,  /
.br
,   /usr
.LP
allows any user to transfer files beginning with ``/usr''
but the user with login
.I root
can transfer any file.
.SH
L.sys
.LP
Each entry in this file represents one system
which can be called by the local uucp programs.
The fields are described below.
.RS
.SH
system name
.LP
The name of the remote system.
.SH
time
.LP
This is a string which indicates the days-of-week
and times-of-day when the system should
be called
(e.g. MoTuTh0800\-1730).
.LP
The day portion may be a list containing
some of
.IP
.I
Su Mo Tu We Th Fr Sa
.R
.LP
or it may be
.I Wk
for any week-day or
.I Any
for any day.
.LP
The time should be a range of times (e.g. 0800\-1230).
If no time portion is specified, any time
of day is assumed to be ok for the call.
.SH
device
.LP
This is either
.I ACU
or the hardwired device to be used for the call.
For the hardwired case, the last part of the
special file name is used (e.g. tty0).
.SH
speed
.LP
This is the line speed for the call (e.g. 300).
.SH
phone
.LP
The phone number is made up of an optional
alphabetic abbreviation and a numeric part.
The abbreviation is one which appears in the
.I L-dialcodes
file (e.g. mh5900, boston995\-9980).
.LP
For the hardwired devices, this field contains
the same string as used for the
.I device
field.
.SH
login
.LP
The login information is given as a series of
fields and subfields in the format
.IP
expect\ \ send\ 
.B [
expect\ \ send
.B ]
\ ...
.LP
where;
.I expect
is the string expected to be read and
.I send
is the string to be sent when the
.I expect
string is received.
.LP
The expect field may be made up of subfields
of the form
.IP
expect\fB[\fR\-send\-expect\fB]\fR...
.LP
where the
.I send
is sent if the prior
.I expect
is not successfully read
and the
.I expect
following the
.I send
is the next expected string.
.LP
There are two special names available to be sent
during the login sequence.
The string
.I EOT
will send an EOT character and the string
.I BREAK
will try to send a BREAK character.
(The
.I BREAK
character is simulated using line speed changes
and null characters and may not work on all
devices and/or systems.)
.RE
.LP
A typical entry in the L.sys file would be
.IP "" 6
sys Any ACU 300  mh7654 login uucp ssword: word
.LP
The expect algorithm looks at the last part of the
string as illustrated in the password field.
.RE
.NH
E 4
D 6
Administration
E 6
I 6
INSTALLING THE \*(UU SYSTEM
E 6
D 4
.LP
E 4
I 4
.PP
E 4
D 6
This section indicates some events and files which must be
administered for the
.I uucp
system.
Some administration can be accomplished by 
.I "shell files"
D 5
which can be initiated by
.I crontab
entries.
E 5
I 5
which can be initiated by \fIcron\fP\|(8).
E 5
Others will require manual intervention.
D 5
Some sample 
.I "shell files"
are given toward the end of this section.
E 5
.SH
SQFILE \- sequence check file
D 4
.LP
E 4
I 4
.PP
E 4
This file is set up in the
D 5
.I program
E 5
I 5
.I library
E 5
directory and contains an entry for each remote
system with which you agree to perform conversation
sequence checks.
The initial entry is just the system name of
the remote system.
The first conversation will add two items to the line,
the conversation count, and the date/time of the most
resent conversation.
These items will be updated with each conversation.
D 5
If a sequence check fails, the entry will have to
E 5
I 5
If a sequence check fails, which could indicate that an unauthorized
connection has been attempted, the entry will have to
E 5
be adjusted.
.SH
TM \- temporary data files
D 4
.LP
E 4
I 4
.PP
E 4
These files are created in the
.I spool
directory while files are being copied
from a remote machine.
Their names have the form
.IP "" 12
\fBTM\fR.pid.ddd
D 4
.LP
E 4
I 4
.PP
E 4
where
.I pid
is a process-id and
.I ddd
is a sequential three digit number starting at zero
for each invocation of
.I uucico
and incremented for each file received.
D 5

E 5
After the entire remote file is received, the
.I TM
D 5
file is moved/copied to the requested destination.
E 5
I 5
file is moved to the requested destination.
E 5
If processing is abnormally terminated or the
D 5
move/copy fails, the file will remain in the
E 5
I 5
move fails, the file will remain in the
E 5
spool directory.
D 4
.LP
E 4
I 4
.PP
E 4
The leftover files should be periodically removed;
the
.I uuclean
program is useful in this regard.
The command
.IP "" 12
uuclean\ \ \-pTM
E 6
I 6
The source for the \*(UU system resides in the
.B /usr/src/usr.bin/uucp
directory.
The README file includes complete instructions on how to rebuild the
\*(Uu system from source.
E 6
.LP
D 6
will remove all
.I TM
files older than three days.
.SH
D 5
LOG \- log entry files
D 4
.LP
E 4
I 4
.PP
E 4
During execution of programs, individual
.I LOG
files are created in the
.I spool
directory with information about
queued requests, calls to remote systems,
execution of
.I uux
commands and file copy results.
These files should be combined into the
.I LOGFILE
by using the
.I uulog
program.
This program will put the new
.I LOG
files at the beginning of the existing
.I LOGFILE.
The command
.IP "" 12
uulog
.LP
will accomplish the merge.
Options are available to print some or all the
log entries after the files are merged.
The
.I LOGFILE
should be removed periodically
since it is copied each time new LOG
entries are put into the file.
D 4
.LP
E 4
I 4
.PP
E 4
The
.I LOG
files are created initially with mode 0222.
If the program which creates the file terminates normally,
it changes the
mode to 0666.
Aborted runs may leave the files with mode
0222 and the
.I uulog
program will not read or remove them.
To remove them, either use
.I rm ,
.I uuclean ,
or change the mode to 0666 and let
.I uulog
merge them with the
.I LOGFILE .
.SH
E 5
STST \- system status files
D 4
.LP
E 4
I 4
.PP
E 4
These files are created in the spool directory by the
.I uucico
program.
They contain information of failures such as login, dialup or
sequence check and will contain a
.I TALKING
D 5
status when to machines are conversing.
The form of the file name is
.IP
\fBSTST\fR.sys
E 5
I 5
status when two machines are conversing.
The file name is
the remote system name in the ``STST'' directory.
E 5
D 4
.LP
E 4
I 4
.PP
E 4
D 5
where
.I sys
is the remote system name.
D 4
.LP
E 4
I 4
.PP
E 5
E 4
For ordinary failures (dialup, login), the file will prevent
D 5
repeated tries for about one hour.
E 5
I 5
repeated tries too frequently.
E 5
For sequence check failures, the file must be removed before
any future attempts to converse with that remote system.
D 4
.LP
E 4
I 4
.PP
E 4
If the file is left due to an aborted run, it may contain a
.I TALKING
status.
In this case, the file must be removed before a conversation
is attempted.
.SH
LCK \- lock files
.LP
Lock files are created for each device in use (e.g. automatic calling
unit) and each system conversing.
This prevents duplicate conversations and multiple attempts to use the
same devices.
The form of the lock file name is
.IP "" 12
\fBLCK..\fRstr
.LP
where
.I str
is either a device or system name.
The files may be left in the spool directory if runs abort.
They will be ignored (reused) after a time of about 24 hours.
D 5
When runs abort and calls are desired before the time limit,
E 5
I 5
When runs abort and calls are desired before the time limit expires,
E 5
the lock files should be removed.
.SH
Shell Files
D 4
.LP
E 4
I 4
.PP
E 6
I 6
For most environments, only two files will need to be modified:
.B uucp.h
includes a large number of tunable system-dependent parameters,
including operating system type, devices to be supported,
and a variety of optional features.
E 6
E 4
The
D 6
.I uucp
program will spool work and attempt to start the
.I uucico
program, but the starting of
.I uucico
will sometimes fail.
(No devices available, login failures etc.).
Therefore, the
.I uucico
program should be periodically started.
The command to start
.I uucico
D 5
can be put in a ``shell'' file with a command to merge
.I LOG
files and started by a crontab entry on an hourly basis.
The file could contain the commands
E 5
I 5
can be put in a ``shell'' file
and started by \fIcron\fP on an hourly basis.
The file could contain the command:
E 5
.IP
D 5
.I program /uulog
.br
.I program /uucico
\ \ \-r1
E 5
I 5
uucico\ \ \-r1
E 6
I 6
.B Makefile
may also have to be modified,
particularly if you chose to keep certain files in different
directories from usual.
.\"===========================================================================
.\" SECTION 8: ACKNOWLEDGMENTS
.\"===========================================================================
.ne 5
.NH
ACKNOWLEDGEMENTS
E 6
E 5
D 4
.LP
E 4
I 4
.PP
E 4
D 6
Note that the ``\-r1'' option is required to start the
.I uucico
program in
D 5
.I MASTER
E 5
I 5
MASTER
E 5
mode.
D 4
.LP
E 4
I 4
.PP
E 4
Another shell file may be set up on a daily basis to remove
.I TM ,
.I ST
and
.I LCK
files
and
.I C.
or
.I D.
files for work which can not be accomplished for
reasons like bad phone number, login changes etc.
A shell file containing commands like
.IP
D 5
.I program /uuclean
E 5
I 5
uuclean
E 5
\ \ \-pTM \-pC. \-pD.
.br
D 5
.I program /uuclean
E 5
I 5
uuclean
E 5
\ \ \-pST \-pLCK \-n12
E 6
I 6
4.3BSD UUCP was a group development effort, involving the contributed work
of over one hundred members of the USENET community.
We're extremely grateful to them all.
E 6
.LP
D 6
can be used.
Note the ``\-n12'' option causes the
.I ST
and
.I LCK
files older than 12 hours to be deleted.
The absence of the ``\-n'' option will use a three day time
limit.
D 4
.LP
E 4
I 4
.PP
E 4
A daily or weekly shell should also be created
to remove or save old
.I LOGFILE s.
D 4
A shell like
E 4
I 4
One can use a command like
E 4
.IP
D 4
cp
.I spool /LOGFILE
\ \ 
.I spool /o.LOGFILE
.br
rm
.I spool /LOGFILE
.LP
can be used.
E 4
I 4
mv spool/LOGFILE spool/o.LOGFILE
E 4
.SH
Login Entry
D 4
.LP
E 4
I 4
.PP
E 4
One or more logins should be set up for
.I uucp .
Each of the ``/etc/passwd'' entries should
have the
D 5
``\fIprogram\fR/uucico''
E 5
I 5
.I uucico
E 5
as the shell to be executed.
D 4
The login directory is not used, but if the system
has a special directory for use by the users for
sending or receiving file, it should as the
login entry.
E 4
I 4
The login directory is normally ``/usr/spool/uucppublic''.
E 4
The various logins are used in conjunction with the
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 5
to restrict file access.
Specifying the
.I shell
D 4
argument limits the login to the use of uucp
(
.I uucico )
only.
E 4
I 4
argument limits the login to the use of UUCP (\fIuucico\fP) only.
E 4
.SH
File Modes
D 4
.LP
E 4
I 4
.PP
E 4
It is suggested that the owner and file modes of various
programs and files be set as follows.
D 4
.LP
E 4
I 4
.PP
E 4
The programs
.I uucp ,
.I uux ,
.I uucico
and
.I uuxqt
should be owned by the
.I uucp
login with the ``setuid'' bit set and only execute
permissions (e.g. mode 04111).
This will prevent outsiders from modifying the programs
to get at a standard
.I shell
for the
.I uucp
logins.
D 4
.LP
E 4
I 4
.PP
E 4
D 5
The
.I L.sys ,
.I SQFILE
E 5
I 5
``L.sys'',
``SQFILE'',
E 5
and the
D 5
.I USERFILE
E 5
I 5
``USERFILE''
E 5
which are put in the
.I program
directory should be owned by
the
.I uucp
D 5
login and set with mode 0400.
E 5
I 5
login and set so that they can only be read by the \fIuucp\fP login
and are writable by no one.
E 6
I 6
Special thanks go to the following individuals, whose contributions were
especially valuable:
.RS
.IP - 2
Rick Adams (Center for Seismic Studies) coordinated the 4.3BSD UUCP release,
incorporating (and often correcting) hundreds of bug fixes that
were posted on the USENET and mailed to him directly.
Rick also managed to find time to add many enhancements
and corrections of his own.
.IP -
Tom Truscott (Research Triangle Institute) and Bob Gray (then with
PAR Tech Corp, now at Univ of Colorado)
coordinated the 4.2BSD UUCP release, which was also a group effort.
Tom has continued to provide enhancements and fixes in 4.3BSD.
.IP -
Guy Harris (then with Computer Consoles, Inc., now with Sun Microsystems)
contributed many general bug fixes;
in particular, he was the first to isolate the infamous 4.2BSD ``TIMEOUT'' bug.
.IP -
Lou Salkind (New York University) wrote the \fIuuq\fP utility.
.IP -
James Bloom (U.C. Berkeley) isolated a major
day-one bug in the \fBg\fP-protocol driver
that had eluded many people's attempts to squash it.
.IP -
Piet Beertema (Centrum voor Wiskunde en Informatica, Amsterdam) wrote the
\fBf\fP-protocol to support ``mostly error-free links'';
Robert Elz (University of Melbourne) modified the protocol
specifically for X.25/PAD.
.IP -
Peter Honeyman (Princeton) assisted Rick by providing information on the
facilities provided in HoneyDanBer UUCP;
Rick then added many HDB-compatibility features and HDB-like
extensions to 4.3BSD UUCP.
.IP -
Ross Green (U.C. Berkeley) produced the first revision of this chapter,
updating the aging Nowitz document to more closely reflect reality.
.RE
.LP
Thanks again to everyone who contributed.
Berkeley UUCP continues to be a product of its own users,
and would not exist as it does today without them.
E 6
E 5
D 4
.SG MH-1273-DAN-unix
E 4
E 1

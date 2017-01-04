h21483
s 00011/00011/00677
d D 6.3 86/05/14 17:52:48 mckusick 5 4
c edits from Anne
e
s 00014/00013/00674
d D 6.2 86/05/12 15:12:00 mckusick 4 3
c changes from Mike
e
s 00236/00598/00451
d D 6.1 86/05/12 12:19:25 mckusick 3 2
c first draft for 4.3BSD
e
s 00296/00307/00753
d D 5.1 86/05/11 00:09:13 mckusick 2 1
c document distributed with 4.2BSD
e
s 01060/00000/00000
d D 4.1 86/05/11 00:08:50 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1980 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 3
.af PN i
D 2
.pn 5
E 2
I 2
.pn 7
E 3
E 2
.de IR
\fI\\$1\^\fR\\$2
..
.de RI
\fR\\$1\fI\\$2\^\fR\\$3
..
.TL
D 3
INTRODUCTION TO VOLUME 1
E 3
I 3
INTRODUCTION TO USER'S REFERENCE MANUAL
.OH 'Introduction''- % -'
.EH '- % -''Introduction'
.af % i
.pn 6
E 3
.LP
D 2
This volume gives descriptions of the publicly available
features of the
E 2
I 2
D 3
This volume gives descriptions of the publicly available features of the
E 3
I 3
The documentation has been reorganized for 4.3BSD in a format similar
to the one used for the Usenix 4.2BSD manuals.
It is divided into three sets; each set consists of one or more volumes.
The abbreviations for the volume names are listed in square brackets;
the abbreviations for the manual sections are listed in parenthesis.
.DS
I. User's Documents
	User's Reference Manual [URM]
		Commands (1)
		Games (6)
		Macro packages and language conventions (7)
	User's Supplementary Documents [USD]
		Getting Started
		Basic Utilities
		Communicating with the World
		Text Editing
		Document Preparation
		Amusements

II. Programmer's Documents
	Programmer's Reference Manual [PRM]
		System calls (2)
		Subroutines (3)
		Special files (4)
		File formats and conventions (5)
	Programmer's Supplementary Documents, Volume 1 [PS1]
		Languages in common use
		General Reference
		Programming Tools
		Programming Libraries
	Programmer's Supplementary Documents, Volume 2 [PS2]
		Documents of Historic Interest
		Other Languages
		Database Management

III. System Manager's Manual [SMM]
	Maintenance commands (8)
	System Installation and Administration
	Supporting Documentation
.DE
.LP
References to individual documents are given as ``volume:document'',
thus USD:1 refers to the first document in the ``User's Supplementary
Documents''.
D 4
References to manual pages are given as ``volume:name(section)'', 
thus URM:sh(1) refers to the shell manual entry in section 1.
E 4
I 4
References to manual pages are given as ``\fIname\fP(section)'' thus
.IR sh (1)
refers to the shell manual entry in section 1.
E 4
.LP
The manual pages give descriptions of the publicly available features of the
E 3
E 2
.UX \s-2/32V\s0
D 2
system,
as extended to provide a virtual memory environment
and other enhancements
at U. C. Berkeley.
It does not attempt to provide perspective or tutorial
information upon the
E 2
I 2
system, as extended to provide a virtual memory environment
D 3
and other enhancements at U. C. Berkeley.
It does not attempt to provide perspective or tutorial information upon the
E 3
I 3
and other enhancements at the University of California.
They do not attempt to provide perspective or tutorial information about the
E 3
E 2
.UX
D 2
operating system,
its facilities, or its implementation.
Various documents on those topics are contained in
Volume 2.
In particular,
for an overview see `The
E 2
I 2
operating system, its facilities, or its implementation.
D 3
Various documents on those topics are contained in Volume 2.
In particular, for an overview see `The
E 2
.UX
D 2
Time-Sharing System'
by Ritchie and Thompson; for a tutorial see
E 2
I 2
Time-Sharing System' by Ritchie and Thompson; for a tutorial see
E 2
`\s8UNIX\s10 for Beginners' by Kernighan,
E 3
I 3
Various documents on those topics are contained in the
``UNIX User's Supplementary Documents'' (USD), the
``UNIX Programmer's Supplementary Documents'' (PS1 and PS2),
and ``UNIX System Manager's Manual'' (SMM).
In particular, for an overview see ``The UNIX Time-Sharing System'' (PS2:1)
by Ritchie and Thompson; for a tutorial see
``\s8UNIX\s10 for Beginners'' (USD:1) by Kernighan,
E 3
and for an guide to the new features of this virtual version, see
D 3
`Getting started with Berkeley Software for \s8UNIX\s10 on the \s8VAX\s10'
D 2
in volume 2c.
E 2
I 2
in volume 2C.
E 3
I 3
``Berkeley Software Architecture Manual (4.3 Edition)'' (PS1:6).
E 3
E 2
.LP
D 2
Within the area it surveys, this volume attempts
to be timely, complete and concise.
Where the latter two objectives conflict,
E 2
I 2
Within the area it surveys, this volume attempts to be timely, complete
and concise.  Where the latter two objectives conflict,
E 2
the obvious is often left unsaid in favor of brevity.
D 2
It is intended that each program be described
as it is, not as it should be.
Inevitably, this means that
various sections will soon be out of date.
E 2
I 2
It is intended that each program be described as it is, not as it should be.
Inevitably, this means that various sections will soon be out of date.
E 2
.LP
D 2
The volume is divided into
eight sections:
E 2
I 2
D 3
The volume is divided into eight sections:
E 2
.DS
D 2
1.	Commands
2.	System calls
3.	Subroutines
4.	Special files
5.	File formats and conventions
6.	Games
7.	Macro packages and language conventions
8.	Maintenance commands and procedures
E 2
I 2
1.      Commands
2.      System calls
3.      Subroutines
4.      Special files
5.      File formats and conventions
6.      Games
7.      Macro packages and language conventions
8.      Maintenance commands and procedures
E 2
.DE
E 3
Commands are programs intended to be invoked directly by
D 3
the user, in contradistinction to subroutines, which are
E 3
I 3
D 5
the user, in contradistinction to subroutines, that are
E 5
I 5
the user, in contrast to subroutines, that are
E 5
E 3
intended to be called by the user's programs.
I 3
D 4
User commands are described in URM:section(1).
E 4
I 4
User commands are described in URM section 1.
E 4
E 3
Commands generally reside in directory
.I /bin
(for
.IR bin \|ary
programs).
Some programs also reside in
.I
/\|usr/\|bin,
.R
D 3
or in
E 3
.I
/\|usr/\|ucb,
.R
I 3
or
.I
/\|usr/\|new,
.R
E 3
to save space in
D 3
.I  /bin.
E 3
I 3
.I  /\|bin.
E 3
These directories are searched automatically by the command interpreters.
.LP
I 3
D 4
Games have been relegated to URM:section(6) and
E 4
I 4
Games have been relegated to URM section 6 and
E 4
.I
/\|usr/\|games,
.R
to keep them from contaminating
D 4
the more staid information of URM:section(1).
E 4
I 4
the more staid information of URM section 1.
E 4
.LP
Miscellaneous collection of information necessary for
writing in various specialized languages such as character codes, 
D 4
macro packages for typesetting, etc is contained in URM:section(7).
E 4
I 4
macro packages for typesetting, etc is contained in URM section 7.
E 4
.LP
E 3
System calls are entries into the
.UX
D 2
supervisor.
The system call interface is identical to a C language
E 2
I 2
supervisor.  The system call interface is identical to a C language
E 2
D 3
procedure call; the equivalent C procedures are described in Section 2.
E 3
I 3
D 4
procedure call; the equivalent C procedures are described in PRM:section(2).
E 4
I 4
procedure call; the equivalent C procedures are described in PRM section 2.
E 4
E 3
.LP
D 2
An assortment
of subroutines is available;
they are described in section 3.
E 2
I 2
D 3
An assortment of subroutines is available; they are described in section 3.
E 3
I 3
An assortment of subroutines is available;
D 4
they are described in PRM:section(3).
E 4
I 4
they are described in PRM section 3.
E 4
E 3
E 2
The primary libraries in which they are kept are described in
.IR intro (3).
D 3
The functions are described in terms of C, but most will
work with Fortran as well.
E 3
I 3
The functions are described in terms of C;
those that will work with Fortran are described in
.IR intro (3f).
E 3
.LP
D 3
The special files section 4 discusses the characteristics of
each system `file' that actually refers to an I/O device.
E 3
I 3
D 4
PRM:section(4) discusses the characteristics of
E 4
I 4
PRM section 4 discusses the characteristics of
E 4
each system ``file'' that refers to an I/O device.
E 3
D 2
The names in this
section refer to the DEC device names for the
hardware,
instead of the names of
the special files themselves.
E 2
I 2
The names in this section refer to the DEC device names for the hardware,
instead of the names of the special files themselves.
E 2
.LP
D 3
The file formats and conventions section 5 documents the structure of particular
kinds of files; for example, the form of the output of the loader and
E 3
I 3
D 4
The file formats and conventions (PRM:section(5))
E 4
I 4
The file formats and conventions (PRM section 5)
E 4
documents the structure of particular kinds of files;
for example, the form of the output of the loader and
E 3
assembler is given.  Excluded are files used by only one command,
for example the assembler's intermediate files.
.LP
D 3
Games have been relegated to section 6 to keep them from contaminating
the more staid information of section 1.
.LP
Section 7 is a miscellaneous collection of information necessary to
D 2
writing in various specialized languages:
character codes, 
macro packages for typesetting,
etc.
E 2
I 2
writing in various specialized languages: character codes, 
macro packages for typesetting, etc.
E 2
.LP
D 2
The maintenance 
section 8 discusses commands and procedures not intended
E 2
I 2
The maintenance section 8 discusses commands and procedures not intended
E 2
for use by the ordinary user.
E 3
I 3
Commands and procedures intended for use primarily by the
D 4
system administrator are described in SMM:section(8).
E 4
I 4
system administrator are described in SMM section 8.
E 4
E 3
The commands and files described here are almost all kept in the directory
D 3
.I /etc.
E 3
I 3
.I /\|etc.
E 3
.LP
D 3
Each section consists of a number of independent
entries of a page or so each.
E 3
I 3
Each section consists of independent entries of a page or so each.
E 3
The name of the entry is in the upper corners of its pages,
together with the section number, and sometimes a
letter characteristic of a subcategory, e.g. graphics is 1G,
and the math library is 3M.
D 2
Entries within each section are
alphabetized.
E 2
I 2
Entries within each section are alphabetized.
I 3
D 4
except for PRM:section(3f) which appears after the rest of PRM:section(3).
E 4
I 4
except for PRM section 3f which appears after the rest of PRM section 3.
E 4
E 3
E 2
The page numbers of each entry start at 1;
it is infeasible to number consecutively the pages of 
a document like this that is republished in many variant forms.
.LP
D 3
All entries are based on a common format,
not all of whose subsections will always appear.
E 3
I 3
All entries are based on a common format;
not all subsections always appear.
E 3
.RS
.LP
The
.I name
subsection lists the exact names of the commands and subroutines
D 2
covered under the entry and gives
a very short description of their purpose.
E 2
I 2
D 3
covered under the entry and gives a very short description of their purpose.
E 3
I 3
covered under the entry and gives a short description of their purpose.
E 3
E 2
.LP
The
.IR synopsis ""
D 2
summarizes the use of the
program being described.
A few conventions are used, particularly in the
Commands subsection:
E 2
I 2
summarizes the use of the program being described.
A few conventions are used, particularly in the Commands subsection:
E 2
.LP
.RS
.B Boldface
D 2
words are considered literals, and
are typed just as they appear.
E 2
I 2
words are considered literals, and are typed just as they appear.
E 2
.LP
D 2
Square brackets [ ] around an argument
indicate that the argument is optional.
When an argument is given as `name', it always
refers to a file name.
E 2
I 2
D 3
Square brackets [ ] around an argument indicate that the argument is optional.
When an argument is given as `name', it always refers to a file name.
E 3
I 3
Square brackets [ ] around an argument show that the argument is optional.
When an argument is given as ``name'', it always refers to a file name.
E 3
E 2
.LP
D 3
Ellipses `.\|.\|.' are used to show that the previous argument-prototype
E 3
I 3
Ellipses ``.\|.\|.'' are used to show that the previous argument-prototype
E 3
may be repeated.
.LP
A final convention is used by the commands themselves.
D 2
An argument beginning with a minus sign `\-'
is often taken to mean some sort of option-specifying argument
even if it appears in a position where a file name
could appear.  Therefore, it is unwise to have files
whose names begin with `\-'.
E 2
I 2
D 3
An argument beginning with a minus sign `\-' is often taken to mean some
sort of option-specifying argument even if it appears in a position where
E 3
I 3
An argument beginning with a minus sign ``\-'' usually means that it is an
option-specifying argument, even if it appears in a position where
E 3
a file name could appear.  Therefore, it is unwise to have files whose
D 3
names begin with `\-'.
E 3
I 3
names begin with ``\-''.
E 3
E 2
.LP
.RE
The
.IR description ""
subsection discusses in detail the subject at hand.
.LP
The
.IR files ""
D 2
subsection gives the names of files which are
built into the program.
E 2
I 2
D 3
subsection gives the names of files which are built into the program.
E 3
I 3
subsection gives the names of files that are built into the program.
E 3
E 2
.LP
A
.I
see also
.R
subsection gives pointers to related information.
.LP
A
.I  diagnostics
D 2
subsection discusses
the diagnostic indications which may be produced.
Messages which are intended to be self-explanatory
are not listed.
E 2
I 2
D 3
subsection discusses the diagnostic indications which may be produced.
Messages which are intended to be self-explanatory are not listed.
E 3
I 3
subsection discusses the diagnostic indications that may be produced.
Messages that are intended to be self-explanatory are not listed.
E 3
E 2
.LP
The
.IR bugs ""
D 2
subsection gives
known bugs and sometimes deficiencies.
Occasionally also the suggested fix is
described.
E 2
I 2
subsection gives known bugs and sometimes deficiencies.
D 5
Occasionally also the suggested fix is described.
E 5
I 5
Occasionally the suggested fix is also described.
E 5
E 2
.LP
D 2
In section 2 an
.I assembler
subsection carries the PDP-11 assembly-language system interface.
.LP
E 2
.RE
D 3
At the beginning of the volume is a table of contents,
E 3
I 3
At the beginning of URM is a table of contents,
E 3
organized by section and alphabetically within each section.
There is also a permuted index derived from the table of contents.
D 2
Within each index entry, the title
of the writeup to which
E 2
I 2
Within each index entry, the title of the writeup to which
E 2
it refers is followed by the appropriate section number in parentheses.
This fact is important because there is considerable
D 2
name duplication among the sections,
arising principally from commands which
E 2
I 2
D 3
name duplication among the sections, arising principally from commands which
E 3
I 3
name duplication among the sections, arising principally from commands that
E 3
E 2
exist only to exercise a particular system call.
.SH
HOW TO GET STARTED
.LP
D 2
This section sketches the basic information
you need to get started on
E 2
I 2
D 3
This section sketches the basic information you need to get started on
E 2
.UX
E 3
I 3
This section sketches the basic information you need to get started on UNIX;
E 3
D 2
how to log in and log out,
how to communicate through your terminal,
E 2
I 2
how to log in and log out, how to communicate through your terminal,
E 2
and how to run a program.
D 3
See `\c
E 3
I 3
See ``\c
E 3
.UX
D 2
for Beginners'
in Volume 2 for a more complete introduction
to the system.
E 2
I 2
D 3
for Beginners' in Volume 2 for a more complete introduction to the system.
E 3
I 3
for Beginners'' in (USD:1) for a more complete introduction to the system.
E 3
E 2
.LP
.I
Logging in.\ \ 
.R
D 3
You must call
.UX
from an appropriate terminal.
E 3
D 2
Most any ASCII terminal capable of full duplex operation and generating
E 2
I 2
Almost any ASCII terminal capable of
full duplex operation and generating
E 2
the entire character set can be used.
D 3
You must also have a valid user name,
which may be obtained, together with necessary telephone numbers,
from the system administration.
After a data connection is established,
D 2
the login procedure depends on what kind of terminal
you are using.
.I
.I
.R
.R
E 2
I 2
the login procedure depends on what kind of terminal you are using
and local system conventions.  The following examples are typical.
E 3
I 3
You must have a valid user name,
which may be obtained from the system administration.
If you will be accessing UNIX remotely, you will also
need to obtain the telephone number for the system that you will be using.
E 3
E 2
.LP
D 3
.I
300-baud terminals:\ \ 
.R
D 2
Such terminals include the GE Terminet 300, and
most display terminals
run with popular modems.
These terminals generally have a speed
switch which should be set at `300' (or `30' for
30 characters per second)
and a half/full duplex switch which should be set at
full-duplex.
E 2
I 2
Such terminals include the GE Terminet 300, and most display terminals
run with popular modems.  These terminals generally have a speed
switch which should be set at `300' (or `30' for 30 characters per second)
and a half/full duplex switch which should be set at full-duplex.
E 3
I 3
After a data connection is established,
the login procedure depends on what type of terminal you are using
and local system conventions.
If your terminal is directly connected to the computer,
it generally runs at 9600 or 19200 baud.
If you are using a modem running over a phone line,
the terminal must be set at the speed appropriate for the modem you are using,
typically 300, 1200, or 2400 baud.
The half/full duplex switch should always be set at full-duplex.
E 3
E 2
(This switch will often have to be changed
since many other systems require half-duplex).
D 2
When a connection is established, the system
types `login:'; you type your
E 2
I 2
D 3
When a connection is established, the system types `login:'; you type your
E 2
user name, followed by the `return' key.
E 3
I 3
.LP
When a connection is established, the system types ``login:'';
you type your user name, followed by the ``return'' key.
E 3
If you have a password, the system asks for it
D 2
and turns off the printer on the terminal
so the password will not appear.
After you have logged in,
the `return', `new line', or `linefeed' keys
E 2
I 2
D 3
and turns off the printer on the terminal so the password will not appear.
After you have logged in, the `return', `new line', or `linefeed' keys
E 3
I 3
and suppresses echo to the terminal so the password will not appear.
After you have logged in, the ``return'', ``new line'', or ``linefeed'' keys
E 3
E 2
will give exactly the same results.
I 3
A message-of-the-day usually greets you before your first prompt.
E 3
.LP
D 3
.I
1200- and 150-baud terminals:\ \ 
.R
If there is a half/full duplex switch, set it at full-duplex.
When you have established a data connection,
the system types out a few garbage characters
(the `login:' message at the wrong speed).
D 2
Depress the `break' (or `interrupt')
key; this is a speed-independent signal
E 2
I 2
Depress the `break' (or `interrupt') key; this is a speed-independent signal
E 2
to
E 3
I 3
If the system types out a few garbage characters
after you have established a data connection
(the ``login:'' message at the wrong speed),
depress the ``break'' (or ``interrupt'') key.
This is a speed-independent signal to
E 3
.UX
D 2
that a different speed terminal
is in use.
The system then will type `login:,' this time at another
speed.
Continue depressing the break key
until `login:' appears in clear, then
E 2
I 2
that a different speed terminal is in use.
D 3
The system then will type `login:,' this time at another speed.
Continue depressing the break key until `login:' appears in clear, then
E 2
respond with your user name.
From the TTY 37 terminal, and any other which has the `newline'
D 2
function (combined carriage return and linefeed), terminate each line you type with the
`new line' key,
otherwise use the `return' key.
E 2
I 2
function (combined carriage return and linefeed), terminate each line you
type with the `new line' key, otherwise use the `return' key.
E 3
I 3
The system then will type ``login:,'' this time at another speed.
Continue depressing the break key until ``login:'' appears clearly,
then respond with your user name.
E 3
E 2
.LP
D 3
.I
Hard-wired terminals.\ \ 
.R
Hard-wired terminals usually begin at the right
D 2
speed, up to 9600 baud; otherwise the preceding instructions
apply.
E 2
I 2
speed, up to 9600 baud; otherwise the preceding instructions apply.
E 2
.LP
E 3
For all these terminals, it is important
that you type your name in lower-case if possible; if you type
upper-case letters,
.UX
will assume that your terminal cannot generate lower-case
D 2
letters and will translate all subsequent upper-case
letters to lower case.
E 2
I 2
D 3
letters and will translate all subsequent upper-case letters to lower case.
E 3
I 3
letters and will translate all subsequent lower-case letters to upper case.
E 3
E 2
.LP
D 2
The evidence that you have successfully
logged in is that a shell program
E 2
I 2
The evidence that you have successfully logged in is that a shell program
E 2
D 3
will type a prompt (`$' or `%') to you.
D 2
(The shells are described below under
`How to run a program.')
E 2
I 2
(The shells are described below under `How to run a program.')
E 3
I 3
will type a prompt (``$'' or ``%'') to you.
(The shells are described below under ``How to run a program.'')
E 3
E 2
.LP
For more information, consult
.IR tset (1),
and
.IR stty (1),
D 3
which tell how to adjust terminal behavior,
E 3
I 3
D 5
that tell how to adjust terminal behavior,
E 3
.IR getty (8),
D 2
which discusses the login sequence in more
detail, and
E 2
I 2
D 3
which discusses the login sequence in more detail, and
E 3
I 3
that discusses the login sequence in more detail, and
E 3
E 2
.IR tty (4),
D 3
which discusses terminal I/O.
E 3
I 3
that discusses terminal I/O.
E 5
I 5
which tell how to adjust terminal behavior;
.IR getty (8)
discusses the login sequence in more detail, and
.IR tty (4)
discusses terminal I/O.
E 5
E 3
.LP
.I
Logging out.\ \ 
.R
There are three ways to log out:
.IP
D 2
By typing an end-of-file indication
(EOT character, control-d) to the Shell.
The Shell will terminate and the `login: ' message
will appear again.
E 2
I 2
D 3
By typing an end-of-file indication (EOT character, control-d) to the Shell.
The Shell will terminate and the `login: ' message will appear again.
E 3
I 3
By typing ``logout'' or an end-of-file
D 5
indication (EOT character, control-D) to the Shell.
The Shell will terminate and the ``login:'' message will appear again.
E 5
I 5
indication (EOT character, control-D) to the shell.
The shell will terminate and the ``login:'' message will appear again.
E 5
E 3
E 2
.IP
D 2
You can log in directly as another user
by giving a
E 2
I 2
You can log in directly as another user by giving a
E 2
.IR login (1)
command.
.IP
If worse comes to worse,
you can simply hang up the phone; but beware \- some machines may
lack the necessary hardware to detect that the phone has been hung up.
Ask your system administrator if this is a problem on your machine.
.LP
.I
How to communicate through your terminal.\ \ 
.R
When you type characters, a gnome deep in the system
D 2
gathers your characters and saves them in a secret
place.
The
characters will not be given to a program
until you type a return (or newline), as described above
in
E 2
I 2
gathers your characters and saves them in a secret place.
The characters will not be given to a program
until you type a return (or newline), as described above in
E 2
.I
Logging in.
.R
.LP
.UX
terminal I/O is full-duplex.
D 2
It has full read-ahead, which means that you can
type at any time,
even while a program is
typing at you.
E 2
I 2
It has full read-ahead, which means that you can type at any time,
even while a program is typing at you.
E 2
Of course, if you type during output, the printed output will
have the input characters interspersed.
D 2
However, whatever you type will be saved
up and interpreted in correct sequence.
E 2
I 2
However, whatever you type will be saved up and interpreted in correct sequence.
E 2
There is a limit to the amount of read-ahead,
but it is generous and not likely to be exceeded unless
the system is in trouble.
When the read-ahead limit is exceeded, the system
D 2
throws away all the saved characters (or beeps, if your prompt
was a %).
E 2
I 2
D 3
throws away all the saved characters (or beeps, if your prompt was a %).
E 3
I 3
throws away all the saved characters (or beeps, if your prompt was a ``%'').
E 3
E 2
.LP
D 2
The character `@' in typed input
kills all the preceding characters in the line, so
typing mistakes
can be repaired on a single line.
E 2
I 2
D 3
The character `@' in typed input kills all the preceding characters in the
line, so typing mistakes can be repaired on a single line.
E 2
Also, the character `#' erases the last character typed.
(Most users prefer to use a backspace rather than `#',
and many prefer control-U instead of `@';
.IR tset (1)
E 3
I 3
The delete (DEL) character in typed input kills all the
preceding characters in the line,
so typing mistakes can be repaired on a single line.
Also, the backspace character (control-H) erases the last character typed.
.IR Tset (1)
E 3
or
.IR stty (1)
D 3
can be used to arrange this.)
Successive uses of `#' erase characters back to, but
E 3
I 3
can be used to change these defaults.
Successive uses of backspace erases characters back to, but
E 3
not beyond, the beginning of the line.
D 2
`@' and `#' can be transmitted to a program
by preceding them with `\\'.
E 2
I 2
D 3
`@' and `#' can be transmitted to a program by preceding them with `\\'.
E 2
(So, to erase `\\', you need two `#'s).
E 3
I 3
DEL and backspace can be transmitted to a program by preceding them with ``\e''.
(So, to erase ``\e'', you need two backspaces).
E 3
.LP
D 3
The `break' or `interrupt' key causes an
E 3
I 3
An
E 3
.I
D 3
interrupt signal,
E 3
I 3
interrupt signal
E 3
.R
D 2
as does the
\s8ASCII\s10 `delete' (or `rubout') character,
E 2
I 2
D 3
as does the \s8ASCII\s10 `delete' (or `rubout') character,
E 3
I 3
is sent to a program by typing control-C or the ``break'' key
E 3
E 2
which is not passed to programs.
D 2
This signal
generally causes whatever program
you are running to terminate.
It is typically used to stop a long printout that
you don't want.
However, programs can arrange either to ignore
this signal altogether,
or to be notified when it happens (instead
of being terminated).
The editor, for example, catches interrupts and
stops what it is doing,
E 2
I 2
This signal generally causes whatever program you are running to terminate.
D 3
It is typically used to stop a long printout that you don't want.
E 3
I 3
It is typically used to stop a long printout that you do not want.
E 3
However, programs can arrange either to ignore this signal altogether,
or to be notified when it happens (instead of being terminated).
The editor, for example, catches interrupts and stops what it is doing,
E 2
instead of terminating, so that an interrupt can
D 2
be used to halt an editor printout without
losing the file being edited.
Many users change this interrupt character to be ^C (control-C)
using
E 2
I 2
be used to halt an editor printout without losing the file being edited.
D 3
Many users change this interrupt character to be ^C (control-C) using
E 2
\fIstty\fR(1).
E 3
I 3
The interrupt character can also be changed with
.IR tset (1)
or
.IR stty (1).
E 3
.LP
D 3
It is also possible to suspend output temporarily using ^S (control-s)
and later resume output with ^Q.
In a newer terminal driver, it is possible to cause output to be thrown
away without interrupting the program by typing ^O; see
E 3
I 3
It is also possible to suspend output temporarily using ^S (control-S)
and later resume output with ^Q (control-Q).
Output can be thrown away without interrupting
the program by typing ^O (control-O); see
E 3
D 2
.IR newtty (4).
E 2
I 2
.IR tty (4).
E 2
.LP
The
.IR quit ""
D 2
signal is generated
by typing the \s8ASCII\s10 FS character.
E 2
I 2
signal is generated by typing the \s8ASCII\s10 FS character.
E 2
(FS appears many places on different terminals, most commonly
as control-\e or control-\^|\^.)
It not only causes a running program to terminate
D 2
but also generates a file with the core image
of the terminated process.
Quit is useful
for debugging.
E 2
I 2
but also generates a file with the core image of the terminated process.
Quit is useful for debugging.
E 2
.LP
Besides adapting to the speed of the terminal,
.UX
tries to be intelligent about whether
you have a terminal with the newline function
D 2
or whether it must be simulated with carriage-return
and line-feed.
E 2
I 2
or whether it must be simulated with carriage-return and line-feed.
E 2
In the latter case, all input carriage returns
D 2
are turned to newline characters (the standard
line delimiter)
and both a carriage return and a line feed
are echoed to the terminal.
E 2
I 2
are turned to newline characters (the standard line delimiter)
and both a carriage return and a line feed are echoed to the terminal.
E 2
If you get into the wrong mode, the
.IR reset (1)
command will rescue you.
I 3
If the terminal does not appear to be echoing anything that you type,
it may be stuck in ``no-echo'' or ``raw'' mode.
Try typing ``(control-J)reset(control-J)'' to recover.
E 3
.LP
Tab characters are used freely in
.UX
source programs.
If your terminal does not have the tab function,
you can arrange to have them turned into spaces
D 2
during output, and echoed as spaces
during input.
The system assumes
that tabs are set every eight columns.
E 2
I 2
during output, and echoed as spaces during input.
The system assumes that tabs are set every eight columns.
E 2
Again, the
.IR tset (1)
or
.IR stty (1)
D 3
command will set or reset this mode.
E 3
I 3
command can be used to change these defaults.
E 3
.IR Tset (1)
can be used to set the tab stops automatically when necessary.
.LP
.I
How to run a program; the shells.\ \ 
.R
When you have successfully logged in, a program
called a shell is listening to your terminal.
The shell reads typed-in lines, splits them up
into a command name and arguments, and executes the command.
A command is simply an executable program.
D 5
The Shell looks in several system directories to find the command.  You can also
E 5
I 5
The shell looks in several system directories to find the command.  You can also
E 5
place commands in your own directory and have the shell find them there.
There is nothing special about system-provided
D 2
commands except that they are kept in a directory
where the shell can find them.
E 2
I 2
commands except that they are kept in a directory where the shell can find them.
E 2
.LP
The command name is always the first word on an input line;
D 2
it and its arguments are separated from one another by
spaces.
E 2
I 2
it and its arguments are separated from one another by spaces.
E 2
.LP
When a program terminates, the shell will ordinarily regain control and type 
D 3
a prompt at you to indicate that it is ready for another command.
E 3
I 3
a prompt at you to show that it is ready for another command.
E 3
.LP
D 3
The shells have many other capabilities, which are described in detail in
E 3
I 3
The shells have many other capabilities, that are described in detail in
E 3
sections
.IR sh (1)
and
.IR csh (1).
D 3
If the shell prompts you with `$', then it is an instance of
E 3
I 3
If the shell prompts you with ``$'', then it is an instance of
E 3
.IR sh (1)
D 5
the standard Bell-labs provided shell.
E 5
I 5
the standard shell provided by Bell Labs.
E 5
D 3
If it prompts with `%' then it is an instance of
E 3
I 3
If it prompts with ``%'' then it is an instance of
E 3
D 2
.IR csh (1)
E 2
I 2
.IR csh (1),
E 2
a shell written at Berkeley.
The shells are different for all but the most simple terminal usage.
Most users at Berkeley choose
.IR csh (1)
because of the
.I history
mechanism and the
.I alias
D 3
feature, which greatly enhance its power when used interactively.
E 3
I 3
feature, that greatly enhance its power when used interactively.
E 3
.I Csh
D 2
also supports the job-control facilities new to this release of the system.
See
.IR newcsh (1)
E 2
I 2
also supports the job-control facilities;
see
.IR csh (1)
E 2
D 3
or the Csh introduction in volume 2C for details.
E 3
I 3
or the Csh introduction in USD:4 for details.
E 3
.LP
You can change from one shell to the other by using the
.I chsh (1)
command, which takes effect at your next login.
.LP
.I
The current directory.\ \ 
.R
.UX
D 3
has a file system arranged in a hierarchy of directories.
E 3
I 3
has a file system arranged as a hierarchy of directories.
E 3
When the system administrator gave you a user name,
D 3
he also created a directory for you (ordinarily
E 3
I 3
they also created a directory for you (ordinarily
E 3
with the same name as your user name).
D 2
When you log in, any file
name you type is by default
in this directory.
E 2
I 2
When you log in, any file name you type is by default in this directory.
E 2
Since you are the owner of this directory, you have
D 2
full permission to read, write, alter, or destroy
its contents.
E 2
I 2
full permission to read, write, alter, or destroy its contents.
E 2
Permissions to have your will with other directories
D 2
and files will have been granted or denied to you
by their owners.
E 2
I 2
and files will have been granted or denied to you by their owners.
E 2
As a matter of observed fact, few
.UX
D 2
users
protect their files from perusal by other users.
E 2
I 2
users protect their files from perusal by other users.
E 2
.LP
D 2
To change the
current directory (but not the set of permissions you
E 2
I 2
To change the current directory (but not the set of permissions you
E 2
were endowed with at login) use
.IR cd (1).
.LP
.I
Path names.\ \ 
.R
D 2
To refer to files not in the current directory, you must
use a path name.
E 2
I 2
To refer to files not in the current directory, you must use a path name.
E 2
D 3
Full path names begin with `/', the name of the root directory of the
E 3
I 3
Full path names begin with ``/\|'', the name of the root directory of the
E 3
whole file system.
After the slash comes the name of each directory containing the next
D 2
sub-directory (followed by a `/') until finally the
file name is reached.
E 2
I 2
D 3
sub-directory (followed by a `/') until finally the file name is reached.
E 3
I 3
sub-directory (followed by a ``/\|'') until finally the file name is reached.
E 3
E 2
For example,
.I
D 3
/\^usr/\^lem/\^filex
E 3
I 3
/\^usr/\^tmp/\^filex
E 3
.R
refers to the file
.I
filex
.R
in the directory
.I
D 3
lem; lem
E 3
I 3
tmp; tmp
E 3
.R
is itself a subdirectory of
.I
usr; usr
.R
springs directly from the root directory.
.LP
If your current directory has subdirectories,
the path names of files therein begin with
D 3
the name of the subdirectory with no prefixed `/'.
E 3
I 3
the name of the subdirectory with no prefixed ``/\|''.
E 3
.LP
D 2
A path name may be used anywhere a file name is
required.
E 2
I 2
A path name may be used anywhere a file name is required.
E 2
.LP
D 2
Important commands which modify the contents of files
are
E 2
I 2
D 3
Important commands which modify the contents of files are
E 3
I 3
Important commands that modify the contents of files are
E 3
E 2
.IR cp (1),
.IR mv (1),
and
.IR rm (1),
which respectively copy, move (i.e. rename) and remove files.
To find out the status of files or directories, use 
.IR ls (1).
See
.IR mkdir (1)
for making directories and
D 3
.I
rmdir
.R
(in
.IR rm (1))
E 3
I 3
.IR rmdir (1)
E 3
for destroying them.
.LP
For a fuller discussion of the file system, see
D 3
`The
.UX
Time-Sharing System,'
by Ken Thompson and Dennis Ritchie.
D 2
It may also be useful to glance through
section 2 of this manual, which discusses
system calls, even if you don't intend
E 2
I 2
It may also be useful to glance through section 2 of this manual, which
discusses system calls, even if you don't intend
E 3
I 3
``A Fast File System for UNIX'' (SMM:14)
by McKusick, Joy, Leffler, and Fabry.
D 4
It may also be useful to glance through PRM:section(2),
E 4
I 4
It may also be useful to glance through PRM section 2,
E 4
that discusses system calls, even if you do not intend
E 3
E 2
to deal with the system at that level.
.LP
.I
Writing a program.\ \ 
.R
To enter the text of a source program into a
.UX
D 2
file, use
the editor
E 2
I 2
file, use the editor
E 2
.IR ex (1)
or its display editing alias
.IR vi (1).
(The old standard editor
.IR ed (1)
is also available.)
The principal languages in
.UX
D 2
are
provided by the C compiler
E 2
I 2
are provided by the C compiler
E 2
.IR cc (1),
the Fortran compiler
.IR f77 (1),
I 3
and its derivatives 
.IR efl (1)
and
.IR ratfor (1),
E 3
the Pascal compiler
.IR pc (1),
and interpreter
D 3
.IR pi (1)
and
.IR px (1),
E 3
I 3
.IR pi (1),
E 3
D 2
the Lisp system
.IR lisp (1),
and the APL system
.IR apl (1).
After the program text has been entered through 
the editor
E 2
I 2
and the Lisp system
.IR lisp (1).
User contributed software in the latest
release of the system supports
D 3
APL, the Functional Programming language, and Icon.
E 3
I 3
APL, B, the Functional Programming language, and Icon.
E 3
Refer to
.IR apl (1),
I 3
.IR b (1),
E 3
.IR fp (1),
and
.IR icon (1),
respectively for more information about each.
After the program text has been entered through the editor
E 2
D 3
and written on a file, you can give the file
E 3
I 3
and written to a file, you can give the file
E 3
to the appropriate language processor as an argument.
The output of the language processor
D 3
will be left on a file in the current directory named `a.out'.
(If the output is precious, use
.I mv
D 2
to move it to a less
exposed name soon.)\ 
E 2
I 2
to move it to a less exposed name soon.)\ 
E 3
I 3
will be left on a file in the current directory named ``a.out''.
If the output is precious, use
.IR mv (1)
to move it to a less exposed name after successful compilation.
E 3
E 2
.LP
When you have finally gone through this entire process
without provoking any diagnostics, the resulting program
can be run by giving its name to the shell
D 3
in response to the shell (`$' or `%') prompt.
E 3
I 3
in response to the shell (``$'' or ``%'') prompt.
E 3
.LP
Your programs can receive arguments from the command line
just as system programs do,
D 3
see
E 3
I 3
see ``UNIX Programming - Second Edition'' (PS2:3),
or for a more terse description
E 3
D 2
.IR exec (2).
E 2
I 2
.IR execve (2).
E 2
.LP
.I
Text processing.\ \ 
.R
Almost all text is entered through the editor
.IR ex (1)
(often entered via
.IR vi (1)).
The commands most often used to write text on a terminal are:
D 3
.I
cat, pr, more
.R
E 3
I 3
.IR cat (1),
.IR more (1),
E 3
and
D 3
.I nroff,
all in section 1.
E 3
I 3
.IR nroff (1).
E 3
.LP
The
D 3
.I cat
E 3
I 3
.IR cat (1)
E 3
command simply dumps \s8ASCII\s10 text
on the terminal, with no processing at all.
D 3
The
.IR pr ""
command paginates the text, supplies headings,
and has a facility for multi-column output.
.I
Nroff
.R
E 3
I 3
.IR More (1)
is useful for preventing the output of a command from
scrolling off the top of your screen.
It is also well suited to perusing files.
.IR Nroff (1)
E 3
is an elaborate text formatting program.
Used naked, it requires careful forethought, but for
D 2
ordinary documents it has been tamed;
see
E 2
I 2
ordinary documents it has been tamed; see
E 2
.IR me (7)
and
.IR ms (7).
D 3
.I
E 3
.LP
D 3
.I Troff
D 2
prepares documents for a
Graphics Systems phototypesetter or a Versatec Plotter;
E 2
I 2
prepares documents for a Graphics Systems phototypesetter or a Versatec Plotter;
E 2
it is very similar to 
.I nroff,
E 3
I 3
.IR Troff (1)
prepares documents for a Graphics Systems phototypesetter
or a Versatec Plotter;
it is similar to 
.IR nroff (1),
E 3
D 2
and often works from exactly the same
source text.
E 2
I 2
and often works from exactly the same source text.
E 2
It was used to produce this manual.
.LP
.IR Script (1)
lets you keep a record of your session in a file,
which can then be printed, mailed, etc.
It provides the advantages of a hard-copy terminal
even when using a display terminal.
.LP
D 3
.IR More (1)
is useful for preventing the output of a command from
zipping off the top of your screen.
It is also well suited to perusing files.
.LP
E 3
.I
Status inquiries.\ \ 
.R
D 2
Various commands exist to provide you with useful
information.
E 2
I 2
Various commands exist to provide you with useful information.
E 2
.IR w (1)
D 2
prints a list of users presently logged in,
and what they are doing.
E 2
I 2
D 3
prints a list of users presently logged in, and what they are doing.
E 3
I 3
prints a list of users currently logged in, and what they are doing.
E 3
E 2
.IR date (1)
prints the current time and date.
.IR ls (1)
will list the files in your directory or give
summary information about particular files.
.LP
.I
Surprises.\ \ 
.R
Certain commands provide inter-user communication.
Even if you do not plan to use them, it would be
D 2
well to learn something about them, because someone else may
aim them at you.
E 2
I 2
well to learn something about them, because someone else may aim them at you.
E 2
.LP
To communicate with another user currently logged in,
.IR write (1)
I 3
or
.IR talk (1)
E 3
is used;
.IR mail (1)
will leave a message whose presence will be announced
D 3
to another user when he next logs in.
E 3
I 3
to another user when they next log in.
E 3
The write-ups in the manual also suggest how to respond to
D 3
the two commands if you are a target.
E 3
I 3
the these commands if you are a target.
E 3
.LP
If you use
.IR csh (1)
D 2
the key ^Z (control-Z)
will cause jobs to ``stop''.
E 2
I 2
the key ^Z (control-Z) will cause jobs to ``stop''.
E 2
If this happens before you learn about it,
you can simply continue by saying ``fg'' (for foreground) to bring
the job back.
D 3
.PP
D 2
When you log in, a message-of-the-day may greet you
before the first prompt.
E 2
I 2
When you log in, a message-of-the-day may greet you before the first prompt.
E 3
E 2
.SH
D 3
CONVERTING FROM THE 6TH EDITION
E 3
I 3
CONVERTING FROM 4.2BSD SYSTEMS
E 3
.LP
D 3
There follows a catalogue of significant, mostly incompatible,
changes that will affect old users converting from the sixth edition
on a PDP-11.
No attempt is made to list all new facilities, or even all
D 2
minor, but easily spotted changes,
just the bare essentials without which it will be
almost impossible to do anything.
E 2
I 2
minor, but easily spotted changes, just the bare essentials without which
it will be almost impossible to do anything.
E 2
.LP
.I
Addressing files.\ \ 
.R
Byte addresses in files are now long (32-bit) integers.
Accordingly
.I seek
has been replaced by
.IR lseek (2).
Every program that contains a 
.I seek
must be modified.
.I Stat
and
.IR fstat (2)
have been affected similarly, since file lengths are now
32- rather than 24-bit quantities.
.LP
.I
Assembly language.\ \ 
.R
This language is dead.  Necromancy will be severely punnished.
.LP
.I Stty
and
.I gtty.\ \ 
.R
D 2
These system calls have been extensively altered,
see
E 2
I 2
These system calls have been extensively altered, see
E 2
.IR ioctl (2)
and
.IR tty (4).
.LP
.I 
C language, lint.\ \ 
.R
D 2
The syntax for initialization
requires an equal sign = before an initializer,
E 2
I 2
The syntax for initialization requires an equal sign = before an initializer,
E 2
and brackets { } around compound initial values;
arrays and structures are now initialized honestly.
Assignment operators such as =+ and =\-
are now written in the reverse order: +=, \-=.  This removes the possibility
of ambiguity in constructs such as x=\-2, y=*p, and a=/*b.
You will also certainly want to learn about
.DS
long integers
type definitions
casts (for type conversion)
unions (for more honest storage sharing)
#include <filename> (which searches in standard places)
.DE
.LP
The program
.IR lint (1)
D 2
checks for obsolete syntax and
does strong type checking of C programs, singly
E 2
I 2
checks for obsolete syntax and does strong type checking of C programs, singly
E 2
or in groups that are expected to be loaded together.
It is indispensable for conversion work.
.LP
.I Fortran.\ \ 
The old 
.I fc
is replaced by
.I f77,
D 2
a true compiler for Fortran 77,
compatible with C.
E 2
I 2
a true compiler for Fortran 77, compatible with C.
E 2
There are substantial changes in the language;
see `A Portable Fortran 77 Compiler' in Volume 2.
.LP
.I
Stream editor.\ \ 
.R
The program
.IR sed (1)
is adapted to massive, repetitive
D 2
editing jobs of the sort encountered in converting to
the new system.
E 2
I 2
editing jobs of the sort encountered in converting to the new system.
E 2
It is well worth learning.
.LP
.I
Standard I/O.\ \ 
.R
The old 
.I
fopen, getc, putc
.R
complex and the old
.I \-lp
D 2
package are both dead,
and even
E 2
I 2
package are both dead, and even
E 2
.I getchar
has changed.
All have been replaced by the clean, highly efficient,
D 2
.IR stdio (3)
package.
E 2
I 2
.I stdio
package,
.IR intro (3S).
E 2
The first things to know are that
.IR getchar (3)
returns the integer EOF (\-1) (which is not a possible byte value)
on end of file, that 518-byte buffers are out, and that there
is a defined FILE data type.
.LP
.I Make.\ \ 
The program
.IR make (1)
D 2
handles the recompilation and loading of
software in an orderly way from
E 2
I 2
handles the recompilation and loading of software in an orderly way from
E 2
a `makefile' recipe given for each piece of software.
It remakes only as much as the modification dates of the input files
show is necessary.
The makefiles will guide you in building your new system.
.LP
.I
Shell, chdir.\ \ 
.R
F. L. Bauer once said Algol 68 is the Everest that
D 2
must be climbed by every computer scientist because
it is there.
E 2
I 2
must be climbed by every computer scientist because it is there.
E 2
So it is with the shell for
.UX
users.
D 2
Everything beyond simple command invocation from a terminal is
different.
E 2
I 2
Everything beyond simple command invocation from a terminal is different.
E 2
Even
.I chdir
is now spelled
D 2
.I cd.
E 2
I 2
.IR cd .
E 2
If you wish to use
.I sh
(as opposed to
.IR csh )
then you will want to study
.IR sh (1)
long and hard.
.LP
D 2
.I "C shell" .\ \ 
E 2
I 2
.I
C shell.\ \ 
.R
E 2
.IR Csh (1),
D 2
developed at Berkeley,
has features comparible to
E 2
I 2
developed at Berkeley, has features comparible to
E 2
.IR sh .
It includes a history mechanism that saves you from retyping all or part
of previous commands, as well as an efficient aliasing (macro) mechanism.
The job control facilities of the system, which make the system much
more pleasant to use, are currently available only with
D 2
.I csh.
E 2
I 2
.IR csh .
E 2
See
D 2
.IR newcsh (1)
E 2
I 2
.IR csh (1)
E 2
for a description.
These features make
.I csh
pleasant to use interactively.
.I Csh
programs have a syntax reminiscent of
D 2
.I C,
E 2
I 2
.IR C ,
E 2
while
.I sh
command programs have a syntax reminiscent of \s-2ALGOL\s0-68.
.LP
D 2
.I Debugging.\ \ 
.IR Sdb (1)
E 2
I 2
.I
Debugging.\ \ 
.R
.I Sdb
E 2
is a far more capable replacement for the debugger
D 2
.I cdb,
E 2
I 2
.IR cdb ,
E 2
and debugs C and Fortran at the source level.
For machine language debugging,
.I adb
replaces
D 2
.I db.
E 2
I 2
.IR db .
E 2
The first-time user should be especially careful about
distinguishing / and ? in
.I adb
commands, and watching to make sure that the
.I x
whose value he asked for is the real
D 2
.I x,
and not just some absolute location equal to the stack offset
of some automatic
.I x.
E 2
I 2
.IR x ,
and not just some absolute location equal to the stack offset of some automatic
.IR x .
E 2
You can always use the `true' name,
D 2
.I _x,
E 2
I 2
.IR _x ,
E 2
to pin down a C external variable.
.LP
D 2
.I Dsw.
This little-known, but indispensable facility has been
taken over by
E 2
I 2
.IR Dsw .
This little-known, but indispensable facility has been taken over by
E 2
.I
rm \-ri.
I 2
.R
E 2
.LP
.I
Boot procedures.\ \ 
.R
Needless to say, these are all different.
See section 8 of this volume, and the other documentation
you should have received with your tape.
.SH
CONVERTING FROM THE DECEMBER, 1979 BERKELEY DISTRIBUTION
.PP
There have been a number of significant changes and improvements
in the system.  This list just gives the bare essentials:
.LP
.I
C language changes.\ \ 
.R
The C compiler now accepts and checks essentially arbitrary length
identifiers and preprocessor names.  There is a new type available
in type casts: \fBvoid\fR which signifies that a value is to be ignored.
It is useful in keeping lint happy about values which are not used
(especially values returned from procedures).  Finally, the language
has been changed so that field names need not be unique to structures;
on the other hand, the compiler insists that you be more honest
about types involved in pointer constructs or it will warn you.
.LP
.I
Object file format.\ \ 
.R
The object file format has been changed to include a string table,
so that language compilers may have names longer than 8 characters
in their resulting \fIa.out\fR files.  Old \fI.o\fR files must be
recreated.  \fIA.out\fR files will still run on both this and the
D 2
December 1979 version of the system;
only the symbol tables are incompatible.
E 2
I 2
December 1979 version of the system; only the symbol tables are incompatible.
E 2
.LP
.I
Archive format and table of contents.\ \ 
.R
The archive format has been changed to one which is portable between
the VAX and other machines (e.g. the PDP-11).  Old \s-2VAX\s0
archives should be converted with
.IR arcv (8);
loader archives should just be recreated since the object files
are also obsolete.
Loader archives should have table-of-contents added by
.IR ranlib (1);
if they dont the loader will gripe when they are used.
D 2
See also
.IR old (8).
E 2
.LP
.I
New tty driver, job control facilities and csh.\ \ 
.R
Hand in hand are new job control facilities, a new tty driver and a new
version of the C shell which supports and uses all of this.
See
D 2
.IR newtty (4)
E 2
I 2
.IR tty (4)
E 2
and
D 2
.IR newcsh (1)
E 2
I 2
.IR csh (1)
E 2
for a quick introduction.
D 2
You should use
.I oldcsh
until you learn about the new facilities.
E 2
.LP
.I
Pascal compiler.\ \ 
.R
There is a true Pascal compiler,
.IR pc (1)
which allows separate compilation as well as mixing in of FORTRAN and
C code.
.LP
.I
Error analyzer.\ \ 
.R
There is an error analyzer program
.IR error (1),
which takes a set of error message
and merges them back into the source files at the point of error.
It can be used interactively to avoid inserting errors which are uninteresting.
This program eliminates once and for all making lists of errors on small
scraps of paper.
.LP
.I
Mail forwarding.\ \ 
.R
The system now provides mail forwarding and distribution facilities.
Group and aliases are defined in the file
.I /usr/lib/aliases
see
.IR aliases (5).
If you change this file you will have to rerun
.IR newaliases (1).
For any particular system a table in the source of the
.I delivermail
postman program may have to be changed so that it knows about
the gateways on the local machine.
.LP
.I
System bootstrap procedures.\ \ 
.R
These are totally changed; the system performs automatic reboots and
preens the disks automatically at reboot.  You should reread the appropriate
pages in section 8 if you deal with system reboots.
I 2
.SH
CONVERTING FROM THE JUNE, 1981 BERKELEY DISTRIBUTION
.PP
Many many changes have been made.  This list indicates those
which are most visible to users.
.LP
.I
Directory format.\ \ 
.R
Directory entries are no longer fixed length.  This forces
user programs which read directories to be modified to use
the 
.IR directory (3)
package.
.LP
.I
Signals.\ \ 
.R
A new signal package has replaced the previous signal mechanism
as well as the ``jobs library''.  When using the compatible 
\fIsignal\fP\|(3C) interface routine, the two most important
changes are: signal handlers are not reset to SIG_DFL when a
process receives a signal, and while a signal handler is processing
a signal, that signal is blocked until the handler returns.
This has implications, in particular, for programs which process
the suspend character typed at the terminal.  Refer to 
\fIsigvec\fP, \fIsigblock\fP, \fIsigpause\fP, \fIsigstack\fP,
and \fIsigsetmask\fP\|(2) for
information about the new signal facilities.
.LP
.I
File and path names.\ \ 
.R
File names may now be up to 255 characters in length.  Path
names are restricted to be at most 1024 characters.  These two
constants are provides as MAXNAMLEN and MAXPATHLEN in
.RI < sys/dir.h >
and
.RI < sys/param.h >,
respectively.
.LP
.I
System time.\ \ 
.R
System time is provided in microsecond precision with
10 millisecond accuracy.  The new system call
.IR gettimeofday (2)
supplants the old
.IR time (3)
call which is now a library routine.  The major impact of this
change is that programs are now written in a fashion which
is independent of the line clock frequency.
.LP
.I
Groups.\ \ 
.R
A user may now be in many groups simultaneously.  This has
obviated the need for the
.I newgrp
command.  See
.IR getgroups (2)
for more information.
.LP
.I
Stat and fstat return value.\ \ 
.R
The structure returned by the
.I stat
and
.I fstat
system calls is now larger.  This is due to inode numbers
growing to 32-bits, time stamps expanding to 64-bits and
other information being included in the return value.  Consult
.IR stat (2)
for more information.
.LP
.I
Mail forwarding.\ \ 
.R
The system now provides general internetwork mail forwarding
and distribution facilities.  The
.IR sendmail (8)
program replaces the old
.I delivermail
facility.
.LP
.I 
Debuggers.\ \ 
.R
The previous C source language debugger,
.IR sdb ,
has been replaced by a new one,
.IR dbx (1).
.IR Adb (1)
has been extended to simplify
debugging of the operating system.
.LP
.I
Networking support.\ \ 
.R
Many new user programs provide access to the networking
facilities.  The
.IR rlogin (1C)
and
.IR rsh (1C)
programs are intended for communicating between UNIX
systems.  The 
.IR telnet (1C)	
and
.IR ftp (1C)
programs support the DARPA Internet standard protocols.
The
.IR netstat (1)
program is useful in watching network activity.
E 3
I 3
A detailed list of changes from the 4.2BSD to the 4.3BSD distributions
is contained in ``Bug Fixes and Changes in 4.3BSD'' (SMM:12),
and ``Changes to the Kernel in 4.3BSD'' (SMM:13).
Detailed conversion procedures are described in
``Installing and Operating 4.3BSD on the VAX'' (SMM:1);
it also discusses changes from pre-4.2BSD systems.
E 3
E 2
E 1

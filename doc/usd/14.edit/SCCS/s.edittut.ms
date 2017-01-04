h20282
s 00005/00005/02290
d D 6.2 04/10/23 08:46:52 msokolov 4 3
c don't mess with the line length, keep the -ms default
e
s 00061/00061/02234
d D 6.1 86/05/27 19:11:46 mckusick 3 2
c document distributed with 4.3BSD
e
s 00820/00482/01475
d D 5.1 86/05/27 19:10:40 mckusick 2 1
c document distributed with 4.2BSD
e
s 01957/00000/00000
d D 4.1 86/05/27 19:10:21 mckusick 1 0
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
I 3
.EH 'USD:14-%''Edit:  A Tutorial'
.OH 'Edit:  A Tutorial''USD:14-%'
E 3
D 2
.ND Draft:\ \ \ April 5, 1979
.RP
.TL
Edit:  A Tutorial
.AU
E 2
I 2
.LP
.ds u \s-2UNIX\s0
D 4
.ll 5i
.nr LL 5i
E 4
I 4
.\".ll 5i
.\".nr LL 5i
E 4
.ND
.sp 4
.ce
\f3\s+2Edit:  A Tutorial\s0\f1
.sp
.ce 3
.I
E 2
Ricki Blau
D 2
.AU
E 2
I 2
.sp
E 2
James Joyce
D 2
.AI
E 2
I 2
.R
.sp
.ce 3
E 2
Computing Services
University of California
Berkeley, California 94720
D 2
.AB
.PP
E 2
I 2
.sp 3
.ce
.I
ABSTRACT
.R
.sp
.LP
E 2
This narrative introduction to the use of the text editor
.I edit
assumes no prior familiarity with computers or with text editing.
Its aim is to lead the beginning \s-2UNIX\(dg\s+2 user through the
.FS
\(dgUNIX is a trademark of Bell Laboratories.
.FE
fundamental steps of writing and revising a file of text.
Edit,
a version of the text editor
.I ex,
was designed to provide an informative environment
for new and casual users.
.PP
D 2
This edition documents Versions 2.0 thru 3.1 of
.I edit
and
.I ex .
.PP
E 2
We welcome comments and suggestions about this tutorial
and the \s-2UNIX\s+2 documentation in general.
D 2
Contact the \s-2UNIX\s+2 consultant in 217 Evans, 642-4072.
.AE
E 2
I 2
.sp .5v
September 1981
.bp
D 3
.ll 6i
.nr LL 6i
E 3
I 3
D 4
.ll 6.5i
.nr LL 6.5i
.nr LT 6.5i
E 4
I 4
.\".ll 6.5i
.\".nr LL 6.5i
.\".nr LT 6.5i
E 4
E 3
.ds u \s-2UNIX\s0
.ce
\s+2\f3Contents\f1\s0
.LP
.nf
Introduction\ \ \ 3
.sp
Session 1\ \ \4
.in +.5i
Making contact with \s-2UNIX\s+2\ \ \ 4
Logging in\ \ \4
Asking for \fIedit\fR\ \ \ 4
The ``Command not found'' message\ \ \ 5
A summary\ \ \5
Entering text\ \ \ 5
Messages from \fIedit\fR\ \ \ 5
Text input mode\ \ \ 6
Making corrections\ \ \ 6
Writing text to disk\ \ \ 7
Signing off\ \ \7
.in -.5i
.sp
Session 2\ \ \ 8
.in +.5i
Adding more text to the file\ \ \ 8
Interrupt\ \ \ 8
Making corrections\ \ \ 8
Listing what's in the buffer (p)\ \ \ 9
Finding things in the buffer\ \ \ 9
The current line\ \ \ 10
Numbering lines (nu)\ \ \ 10
Substitute command (s)\ \ \ 10
Another way to list what's in the buffer (z)\ \ \ 11
Saving the modified text\ \ \ 12
.in -.5i
.sp
Session 3\ \ \ 13
.in +.5i
Bringing text into the buffer (e)\ \ \ 13
Moving text in the buffer (m)\ \ \ 13
Copying lines (copy)\ \ \ 14
Deleting lines (d)\ \ \ 14
A word or two of caution\ \ \ 15
Undo (u) to the rescue\ \ \ 15
More about the dot (.) and buffer end ($)\ \ \ 16
Moving around in the buffer (+ and \-)\ \ \ 16
Changing lines (c)\ \ \ 17
.in -.5i
.sp
Session 4\ \ \ 18
.in +.5i
Making commands global (g)\ \ \ 18
More about searching and substituting\ \ \ 19
Special characters\ \ \ 19
Issuing \s-2UNIX\s+2 commands from the editor\ \ \ 20
Filenames and file manipulation\ \ \ 20
The file (f) command\ \ \ 20
Reading additional files (r)\ \ \ 21
Writing parts of the buffer\ \ \ 21
Recovering files\ \ \ 21
Other recovery techniques\ \ \ 21
Further reading and other information\ \ \ 22
Using \fIex\fR\ \ \ 22
.in -.5i
.sp
Index\ \ \ 23
.bp
E 2
.SH
I 2
.ce
\s+2Introduction\s0
E 2
.PP
Text editing using a terminal connected to a computer
D 2
allows a user to create, modify, and print text
easily.  Creating text is as easy as typing it much
as one would on an electric typewriter.
E 2
I 2
allows you to create, modify, and print text
easily.
A
.I
text editor
.R
is a program
that assists you
as you create and modify text.
The text editor you will learn here is named
.I edit.
Creating text using edit is as easy as typing it
on an electric typewriter.
E 2
Modifying text involves telling the text editor 
D 2
what to add, change, or delete.
Text is printed by giving the proper
command to print the file contents, with or
without special instructions as to the format
of the desired output.
E 2
I 2
what you want to add, change, or delete.
You can review your text
by typing a command
to print the file contents
D 3
as they were entered by you.
Another program,
a text formatter,
E 3
I 3
as they are currently.
Another program (which we do not discuss in this
document), a text formatter,
E 3
rearranges your text
for you into ``finished form.''
D 3
This document does not
discuss the use of a text formatter.
E 3
E 2
.PP
These lessons assume no prior familiarity with computers
or with text editing.
They consist of a series of text editing sessions
D 2
which will lead you through the fundamental steps
of creating and revising a file of text.
E 2
I 2
which lead you through the fundamental steps
of creating and revising text.
E 2
After scanning each lesson and before beginning the next,
D 2
you should follow the examples at a terminal to get a feeling
E 2
I 2
D 3
you should practice the examples at a terminal to get a feeling
E 3
I 3
you should try the examples at a terminal to get a feeling
E 3
E 2
for the actual process of text editing.
D 2
Set aside some time for experimentation,
and you will soon become familiar with using the
E 2
I 2
If you set aside some time for experimentation,
you will soon become familiar with using the
E 2
computer to write and modify text.
In addition to the actual use of the text editor,
other features of \s-2UNIX\s0 will be very important to your work.
You can begin to
learn about these other features by
D 3
reading ``Communicating with \s-2UNIX\s0''
or one of the other tutorials
E 3
I 3
reading one of the other tutorials
E 3
D 2
which provide a general introduction to the system.
E 2
I 2
that provide a general introduction to the system.
E 2
You will be ready to proceed with this lesson as soon as
D 2
you are familiar with your terminal and its special keys,
the login procedure, and the ways of correcting typing errors.
E 2
I 2
you are familiar with (1) your terminal and its special keys,
D 3
(2) the login procedure,
E 3
I 3
(2) how to login,
E 3
(3) and the ways of correcting typing errors.
E 2
Let's first define some terms:
.sp .5
.IP program 12
D 2
A set of instructions given to the computer,
describing the sequence of steps which the computer performs
E 2
I 2
A set of instructions, given to the computer,
describing the sequence of steps the computer performs
E 2
in order to accomplish a specific task.
D 2
As an example, a series of steps to balance your
checkbook is a program.
E 2
I 2
D 3
The tasks must be specific,
E 3
I 3
The task must be specific,
E 3
such as balancing your checkbook
or editing your text.
A general task,
such as working for world peace,
D 3
is something we can do,
but not something we can write programs to do.
E 3
I 3
is something we can all do,
but not something we can currently write programs to do.
E 3
E 2
.IP UNIX
\s-2UNIX\s0 is a special type of program,
called an operating system, that supervises the machinery
and all other programs comprising the total
computer system.
.IP edit
.I edit
D 2
is the name of the \s-2UNIX\s0 text editor which you will be learning to use,
a program that aids you in writing or revising text.
E 2
I 2
is the name of the \s-2UNIX\s0 text editor you will be learning to use,
and is a program that aids you in writing or revising text.
E 2
Edit was designed for beginning users,
D 2
and is a simplified version of an editor called
E 2
I 2
and is a simplified version of an editor named
E 2
.I ex.
.IP file
Each \s-2UNIX\s0 account is allotted
D 2
space for the permanent storage of information, such as programs, data or text.
E 2
I 2
space for the permanent storage of information,
such as programs, data or text.
E 2
A file is a logical unit of data,
D 2
for example, an essay, a program, or a chapter from a book,
E 2
I 2
for example, an essay, a program,
or a chapter from a book,
E 2
which is stored on a computer system.
Once you create a file,
it is kept until you instruct the system to remove it.
D 2
You may create a file during one \s-2UNIX\s0 session, log out,
E 2
I 2
You may create a file during one \s-2UNIX\s0 session,
end the session,
E 2
and return to use it at a later time.
Files contain anything you choose to write and store in them.
The sizes of files vary to suit your needs;
D 2
one file might hold only a single number while another might contain
E 2
I 2
one file might hold only a single number,
yet another might contain
E 2
a very long document or program.
The only way to save
D 2
information from one session to the next is to store it in a file.
E 2
I 2
information from one session to the next is to store it in a file,
which you will learn in Session 1.
E 2
.IP filename
Filenames are used to distinguish one file from another,
serving the same purpose as the labels of manila
folders in a file cabinet.
In order to write or access information in a file,
you use the name of that file in a \s-2UNIX\s0 command,
and the system will automatically locate the file.
.IP disk
Files are stored on an input/output device called a disk,
which looks something like a stack of phonograph records.
D 3
Each surface is coated with a material similar to the
D 2
coating on magnetic recording tape, on which information is recorded.
E 2
I 2
coating on magnetic recording tape,
E 3
I 3
Each surface is coated with a material similar to that
on magnetic recording tape,
E 3
and information is recorded on it.
E 2
.IP buffer
A temporary work space, made available to the user
for the duration of a session of text editing
D 2
and used for building and modifying
E 2
I 2
and used for creating and modifying
E 2
the text file.
D 2
We can imagine the buffer as a blackboard that is
E 2
I 2
We can think of the buffer as a blackboard that is
E 2
erased after each class, where each session with the editor
is a class.
D 2
.sp 2
E 2
I 2
.bp
E 2
.SH
.ce 1
D 2
Session 1:  Creating a File of Text
E 2
I 2
\s+2Session 1\s0
E 2
.sp 1
I 2
.SH
Making contact with \s-1UNIX\s0
E 2
.PP
To use the editor you must first make contact with the computer
by logging in to \s-2UNIX\s0.
D 2
We'll quickly review the standard \s-2UNIX\s0 login procedure.
E 2
I 2
We'll quickly review the standard \s-2UNIX\s0 login procedure
for the two ways you can make contact:
on a terminal that is directly linked to the computer,
or over a telephone line where the computer answers your call.
.SH
Directly-linked terminals
E 2
.PP
D 2
If the terminal you are using is directly linked to the computer,
turn it on and press carriage return,
usually
labelled ``\s-1RETURN\s+1''.
E 2
I 2
Turn on your terminal and press the \s-1RETURN\s0 key.
You are now ready to login.
.SH
Dial-up terminals
.PP
E 2
If your terminal connects with the computer over a telephone line,
turn on the terminal, dial the system access number,
D 3
and, when you hear a high-pitched tone, place the receiver of
the telephone in the acoustic coupler.
E 3
I 3
and, when you hear a high-pitched tone, place the 
telephone handset in the acoustic coupler, if you are using one.
E 3
D 2
Press carriage return once and await the login message:
E 2
I 2
You are now ready to login.
.SH
Logging in
.PP
The message inviting you to login is:
E 2
.DS I 1i
D 3
:login:
E 3
I 3
login:
E 3
.DE
D 2
.PP
E 2
I 2
.LP
E 2
Type your login name, which identifies you to \s-2UNIX\s0,
D 2
on the same line as the login
message, and press carriage return.
If the terminal you are using has both upper
and lower case, be sure you enter your login name
in lower case; otherwise \s-2UNIX\s0 assumes your terminal
E 2
I 2
on the same line as the login message,
and press \s-2RETURN\s+2.
If the terminal you are using
has both upper and lower case,
.B
be sure you enter your login name in lower case;
.R
otherwise \s-2UNIX\s0 assumes your terminal
E 2
has only upper case and will not recognize lower case
letters you may type.
D 3
\s-2UNIX\s0 types ``:login:'' and you reply
E 3
I 3
\s-2UNIX\s0 types ``login:'' and you reply
E 3
with your login name, for example ``susan'':
.DS I 1i
D 2
:login: \fBsusan\fR \fI(and press carriage return)\fR
E 2
I 2
D 3
:login: \fBsusan\fR \fI(and press the \s-2RETURN\s0 key)\fR
E 3
I 3
login: \fBsusan\fR \fI(and press the \s-2RETURN\s0 key)\fR
E 3
E 2
.DE
D 2
(In the examples, input typed by the user appears in
E 2
I 2
(In the examples, input you would type appears in
E 2
.B "bold face"
to distinguish it from the responses from \s-2UNIX\s0.)
.PP
\s-2UNIX\s0 will next respond with a request for a password
as an additional precaution to prevent
unauthorized people from using your account.
The password will not appear when you type it,
to prevent others from seeing it.
The message is:
.DS I 1i
D 2
Password:    \fI(type your password and press carriage return)\fR
E 2
I 2
Password:    \fI(type your password and press \s-2RETURN\s+2)\fR
E 2
.DE
If any of the information you gave during the login
sequence was mistyped or incorrect,
\s-2UNIX\s0 will respond with
.DS I 1i
Login incorrect.
.if t .sp .2v
.if n .sp 1
D 3
:login:
E 3
I 3
login:
E 3
.DE
in which case you should start the login process anew.
Assuming that you have successfully
logged in, \s-2UNIX\s0
will print the message of the day and eventually will present
you with a % at the beginning of a fresh line.
The % is the \s-2UNIX\s0 prompt symbol
which tells you that \s-2UNIX\s0 is ready to accept a command.
.bd I 3
.SH
Asking for \fIedit\fP
.fl
.bd I
.PP
You are ready to tell \s-2UNIX\s0 that you
want to work with edit, the text editor.
Now is a convenient time to choose
D 2
a name for the file of text which you are about to create.
To begin your editing session type
E 2
I 2
a name for the file of text you are about to create.
To begin your editing session,
type
E 2
.B edit
followed by a space and then the filename
D 2
which you have selected, for example ``text''.
E 2
I 2
you have selected; for example, ``text''.
E 2
D 3
When you have completed the command,
E 3
I 3
After that,
E 3
D 2
press carriage return and wait for edit's response:
E 2
I 2
press the \s-2RETURN\s0 key and wait for edit's response:
E 2
.DS I 1i
D 2
% \fBedit text\fP    \fI(followed by a carriage return)\fR
E 2
I 2
% \fBedit text\fP    \fI(followed by a \s-2RETURN\s+2)\fR
E 2
"text" No such file or directory
:
.DE
If you typed the command correctly,
you will now be in communication with edit.
Edit has set aside a buffer for use as
a temporary working space during your current editing session.
D 3
It also checked to see if the file you named, ``text'',
already existed.
D 2
As we expected, it was unable to find such a file
since ``text'' is the name of the new file that we will create.
E 2
I 2
It was unable to find such a file,
since ``text'' is a new file we are about to create.
E 2
Edit confirms this with the line:
E 3
I 3
Since ``text'' is a new file we are about to create
the editor was unable to find that file, which it
confirms by saying:
E 3
.DS I 1i
"text" No such file or directory
.DE
On the next line appears edit's prompt ``:'',
D 2
announcing that edit expects a command from you.
E 2
I 2
announcing that you are in \f2command mode\f1 and
edit expects a command from you.
E 2
You may now begin to create the new file.
.SH
D 2
The ``not found'' message
E 2
I 2
The ``Command not found'' message
E 2
.PP
If you misspelled edit by typing, say, ``editor'',
D 3
your request would be handled as follows:
E 3
I 3
this might appear:
E 3
.DS I 1i
% \fBeditor\fP
D 2
editor:  not found
E 2
I 2
editor: Command not found
E 2
%
.DE
Your mistake in calling edit ``editor'' was
treated by \s-2UNIX\s0 as a request
for a program named ``editor''.
Since there is no program
named ``editor'',
\s-2UNIX\s0 reported that the program was ``not found''.
A new % indicates that \s-2UNIX\s0 is ready for another command,
D 2
so you may enter the correct command.
E 2
I 2
and you may then enter the correct command.
E 2
.SH
A summary
.PP
Your exchange with \s-2UNIX\s0 as you logged in and made contact with edit
should look something like this:
.DS I 1i
D 3
:login: \fBsusan\fP
E 3
I 3
login: \fBsusan\fP
E 3
Password:
D 2
Computer Center \s-2UNIX\s0 System
E 2
\&... A Message of General Interest ...
% \fBedit text\fP
"text" No such file or directory
:
.DE
.SH
Entering text
.PP
D 2
You may now begin to enter text into the buffer.
This is done by \fIappending\fP text to whatever
E 2
I 2
You may now begin entering text into the buffer.
This is done by \fIappending\fP (or adding) text to whatever
E 2
is currently in the buffer.
Since there is nothing in the buffer at the moment,
D 2
you are appending text to nothing; in effect, you 
are creating text.
E 2
I 2
you are appending text to nothing;
in effect, 
since you are adding text to nothing
you are creating text.
E 2
D 3
Most edit commands have two forms:
E 3
I 3
Most edit commands have two equivalent forms:
E 3
D 2
a word which describes what the command does
E 2
I 2
a word that suggests what the command does,
E 2
and a shorter abbreviation of that word.
D 3
Either form may be used.
E 3
Many beginners find the full command names
D 2
easier to remember,
E 2
I 2
easier to remember at first,
E 2
but once you are familiar with editing you may
prefer to type the shorter abbreviations.
D 2
The command to input text is ``append''
which may be abbreviated ``a''.
E 2
I 2
D 3
The command to input text is ``append'',
and it may be abbreviated ``a''.
E 3
I 3
The command to input text is ``append''.
(It may be abbreviated ``a''.)
E 3
E 2
Type
.B append
D 2
and press carriage return.
E 2
I 2
and press the \s-2RETURN\s0 key.
E 2
.DS I 1i
% \fBedit text
\fR:\|\fBappend
.R
.DE
.SH
.bd I 3
Messages from
.I edit
.fl
.bd I
.PP
If you make a mistake in entering a command and
type something that edit does not recognize,
edit will respond with a message
intended to help you diagnose your error.
For example, if you misspell the command to input text by typing,
perhaps, ``add'' instead of ``append'' or ``a'',
you will receive this message:
.DS I 1i
:\|\fBadd\fR
add: Not an editor command
:
.DE
When you receive a diagnostic message,
check what you typed in order to determine what
part of your command confused edit.
The message above means that edit
was unable to recognize your mistyped command
and, therefore, did not execute it.
Instead, a new ``:''
appeared to let you know that
edit is again ready to execute a command.
.SH
Text input mode
.PP
By giving the command ``append'' (or using the abbreviation ``a''),
you entered
.I
text input mode,
.R
also known as
.I
append mode.
.R
When you enter text input mode,
D 2
edit responds by doing nothing.
E 2
I 2
edit stops sending you a prompt.
E 2
You will not receive any prompts
I 2
or error messages
E 2
while in text input mode.
D 2
This is your signal
that you are to begin entering lines of text.  You can enter
pretty much anything you want on the lines.  The
lines are transmitted one by one to the buffer
E 2
I 2
You can enter
pretty much anything you want on the lines.
The lines are transmitted one by one to the buffer
E 2
and held there during the editing session.
You may append as much text as you want, and
.I
when you wish to stop entering text lines you should
type a period as the only character on the line
D 2
and press carriage return.
E 2
I 2
and press the \s-2RETURN\s0 key.
E 2
.R
D 2
When you give this signal that you want to stop appending text,
you will exit from text input mode and reenter command mode.
E 2
I 2
When you type the period and press \s-2RETURN\s0,
you signal that you want to stop appending text,
and edit responds by allowing
you to exit text input mode and reenter command mode.
E 2
Edit will again
prompt you for a command by printing ``:''.
.PP
Leaving append mode does not destroy the text in
D 2
the buffer.  You have to leave append
E 2
I 2
the buffer.
You have to leave append
E 2
mode to do any of the other kinds of editing,
such as changing, adding, or printing text.
If you type a period as the first character and
type any other character on the same line,
edit will believe you want to remain in append mode
and will not let you out.
As this can be very frustrating, 
be sure to type
.B only
D 2
the period and carriage return.
E 2
I 2
the period and the \s-2RETURN\s0 key.
E 2
.PP
D 2
This is as good a place as any to learn an important
E 2
I 2
This is a good place to learn an important
E 2
lesson about computers and text:  a blank space is
a character as far as a computer is concerned.  
If you so much as type a period followed by a blank
(that is, type a period and then the space bar on the keyboard),
you will remain in append mode with the last line of text
being:
.DS I 1i
.B
.ps +2
\&.
.ps -2
.R
.DE
D 3
Let's say that the lines of text you enter are
E 3
I 3
Let's say that you enter the lines 
E 3
(try to type
.B exactly
what you see, including ``thiss''):
.DS I 1i
.B
This is some sample text.
And thiss is some more text.
Text editing is strange, but nice.
\&.
.R
.DE
D 2
The last line is the period followed by a carriage return
E 2
I 2
The last line is the period followed by a \s-2RETURN\s0
E 2
that gets you out of append mode.  
D 2
If while typing the line you hit an incorrect key,
recall that
you may delete the incorrect character
or cancel the entire line of input by erasing in the usual way.
Refer to ``Communicating with \s-2UNIX\s0'' if you need to review
the procedures for making a correction.
Erasing a character or cancelling a line must be done
before the line has been completed by a carriage return.
We will discuss changes in lines already typed in session 2.
E 2
.SH
I 2
Making corrections
.PP
If you have read a general introduction to \s-2UNIX\s0,
D 3
such as ``Communicating with \s-2UNIX\s0'',
E 3
you will recall that it is possible to erase individual
letters that you have typed.
This is done by typing the designated erase character
as many times as there are characters
you want to erase.
.PP
D 3
The usual erase character is the backspace (control-H),
and you can correct typing errors
E 3
I 3
The usual erase character varies from place to place and 
user to user.  Often it
is the backspace (control-H),
so you can correct typing errors
E 3
in the line you are typing
by holding down the \s-1CTRL\s+1 key
D 3
and typing the ``H'' key.
If you try typing control-H
E 3
I 3
and typing the ``H'' key.  (Sometimes it is the DEL key.)
If you type the erase character
E 3
you will notice
that the terminal backspaces in the line you are on.
You can backspace over your error,
and then type what you want to be the rest of the line.
.PP
If you make a bad start
in a line
and would like to begin again,
you can either backspace to the beginning of the line
or you can use the at-sign ``@'' to erase everything on the line:
.DS I 1i
.B
Text edtiing is strange, but@
Text editing is strange, but nice.
.R
.fl
.bd S
.DE
When you type the at-sign (@), you erase
the entire line typed so far
and are given a fresh line to type on.
You may immediately begin to retype the line.
D 3
This, unfortunately, does not help after you type the
E 3
I 3
This, unfortunately, does not work after you type the
E 3
line and press \s-2RETURN\s+2.  
To make corrections in lines that have been completed,
it is necessary to use the editing commands
D 3
covered in the next session and those that follow.
E 3
I 3
covered in the next sessions.
E 3
.SH
E 2
Writing text to disk
.PP
D 3
You are now ready to edit the text.  The simplest kind of editing
is to write it to disk as a file for safekeeping
E 3
I 3
You are now ready to edit the text.  One common operation
is to write the text to disk as a file for safekeeping
E 3
after the session is over.
This is the only way to save information from one session to the next,
since the editor's buffer is temporary and will last only until the
end of the editing session.
D 2
Thus, learning how to write a file to disk is second in
E 2
I 2
Learning how to write a file to disk is second in
E 2
importance only to entering the text.
To write the contents of the buffer to a disk
file, use the command ``write''
(or its abbreviation ``w''):
.DS I 1i
:\|\fBwrite
.R
.DE
D 2
Edit will copy the buffer to a disk file.
E 2
I 2
Edit will copy the contents of the buffer to a disk file.
E 2
If the file does not yet exist,
a new file will be created automatically
and the presence of a ``[New file]'' will be noted.
The newly-created file will be given the name specified when
you entered the editor, in this case ``text''.
To confirm that the disk file has been successfully written,
edit will repeat the filename and give
the number of lines and the total
number of characters in the file.
The buffer remains unchanged by the ``write'' command.
D 2
All of the lines which were written to disk will still be
E 2
I 2
All of the lines that were written to disk will still be
E 2
in the buffer,
should you want to modify or add to them.
.PP
D 3
Edit must have a filename to use before it can write a file.
E 3
I 3
Edit must have a name for the file to be written.
E 3
If you forgot to indicate the name of the file
D 3
when you began the editing session,
edit will print
E 3
I 3
when you began to edit,
edit will print in response to your write command:
E 3
.DS I 1i
No current filename
.DE
D 3
in response to your write command.
E 3
If this happens, you can specify the filename in a new write command:
.DS I 1i
:\|\fBwrite text
.R
.DE
D 2
After the ``write'' (or ``w'') type a space and then the name of the file.
E 2
I 2
After the ``write'' (or ``w''), type a space and then the name of the file.
E 2
.SH
Signing off
.PP
We have done enough for this first lesson on using the
\s-2UNIX\s0 text editor, and are ready to quit the session with edit.
D 2
To do this we type ``quit'' (or ``q'') and press carriage return:
E 2
I 2
To do this we type ``quit'' (or ``q'') and press \s-2RETURN\s+2:
E 2
.DS I 1i
:\|\fBwrite
.R
"text" [New file]  3 lines, 90 characters
:\|\fBquit\fR
%
.DE
The % is from \s-2UNIX\s0 to tell you that your session with edit is
D 2
over and you may command \s-2UNIX\s0 further.  Since we want
to end the entire session at the terminal we also need to
E 2
I 2
over and you may command \s-2UNIX\s0 further.
Since we want
to end the entire session at the terminal, we also need to
E 2
exit from \s-2UNIX\s0.
In response to the \s-2UNIX\s0 prompt of ``\|%\|''
D 2
type a ``control d''.  This is done by holding down the control
key (usually labelled ``CTRL'') and simultaneously
pressing the d key.  This
will end your session with \s-2UNIX\s0 and will ready the
E 2
I 2
type the command
.DS I 1i
%\|\fBlogout\fR
.DE
This will end your session with \s-2UNIX\s0, and will ready the
E 2
terminal for the next user.
D 2
It is always important to type a ``control-d'' at the end of a session
E 2
I 2
It is always important to type \fBlogout\fR at the end of a session
E 2
to make absolutely sure no one
could accidentally stumble into your abandoned 
session and thus gain access to your files,
tempting even the most honest of souls.
I 2
.sp 1
E 2
.PP
This is the end of the first session on \s-2UNIX\s0 text editing.
.bp
D 2
.ND
E 2
.TL
Session 2
I 2
.sp
E 2
.PP
Login with \s-2UNIX\s0 as in the first session:
.DS I 1i
D 3
:login: \fBsusan\fP  \fI(carriage return)\fR
E 3
I 3
login: \fBsusan\fP  \fI(carriage return)\fR
E 3
Password:       \fI(give password and carriage return)\fR
.if t .sp .2v
.if n .sp 1
D 2
Computer Center \s-2UNIX\s0 System
E 2
I 2
\&... A Message of General Interest ...
E 2
% 
.DE
D 2
This time when you say that you want to edit,
E 2
I 2
When you indicate you want to edit,
E 2
you can specify the name of the file you worked on last time.
This will
D 2
start edit working and it will fetch the contents of the
E 2
I 2
start edit working, and it will fetch the contents of the
E 2
file into the buffer, so that you can resume editing the same file.
When edit has copied the file into the buffer, it
will repeat its name and tell
you the number of lines and characters it contains.
Thus,
.DS I 1i
.B
% edit text
.R
"text" 3 lines, 90 characters
:
.DE
means you asked edit to fetch
the file named ``text'' for editing,
causing it to copy the
90 characters of text into the buffer.
Edit awaits
D 2
your further instructions.
E 2
I 2
your further instructions,
and indicates this by its prompt character, the colon (:).
E 2
In this session, we will append more text to our file,
print the contents of the buffer, and learn to change the text of a line.
.SH
Adding more text to the file
.PP
If you want to add more to the end of your
text you may do so by using the append command to enter text input mode.
I 2
When ``append'' is the first command
of your editing session,
the lines you enter
are placed at the end of the buffer.
E 2
Here we'll use the abbreviation for the append command, ``a'':
.DS I 1i
:\|\fBa
This is text added in Session 2.
It doesn't mean much here, but
it does illustrate the editor.
D 2
\&.
E 2
I 2
\|\fB\s+2\&.\s-2
E 2
.R
.DE
I 2
You may recall that once you enter append mode
using the ``a'' (or ``append'') command,
you need to type a line containing only a period (.)
to exit append mode.
E 2
.SH
D 2
\ \ Interrupt
E 2
I 2
Interrupt
E 2
.PP
D 2
Should you press the \s-2RUBOUT\s+2 key (sometimes labelled \s-2DELETE\s+2)
E 2
I 2
Should you press the \s-2RUB\s+2 key (sometimes labelled \s-2DELETE\s+2)
E 2
while working with edit,
it will send this message to you:
.DS I 1i
Interrupt
:
.DE
Any command that edit might be executing
D 2
is terminated by rubout or delete,
E 2
I 2
is terminated by rub or delete,
E 2
causing edit to prompt you for a new command.
If you are appending text at the time,
D 2
you will exit from append mode and be expected to give another command.
The line of text that you were typing when the append command was interrupted
E 2
I 2
you will exit from append mode
and be expected to give another command.
The line of text you were typing
when the append command was interrupted
E 2
will not be entered into the buffer.
.SH
Making corrections
.PP
D 2
If you have read a general introduction to \s-2UNIX\s0,
such as ``Communicating with \s-2UNIX\s0'',
you will recall that it is possible to erase individual
letters that you have typed.
This is done by typing the designated erase character,
usually the number sign (#),
as many times as there are characters you want to erase.
If you make a bad start
in a line
and would like to begin again, this technique
is cumbersome \- what if you had 15
characters in your line and wanted to get rid of them?
To do so either requires:
.bd S 3
.DS I 1i
.B
This is yukky tex###############
.R
.DE
with no room for the great text you'd like to type, or,
.DS I 1i
.B
This is yukky tex@This is great text.
.R
.fl
.bd S
.DE
When you type the at-sign (@), you erase
the entire line typed so far.
You may immediately begin to retype the line.
This, unfortunately, does not help after you type the
line and press carriage return.  
To make corrections in lines which have been completed,
it is necessary to use the editing commands
covered in this session and those that follow.
E 2
I 2
If while typing the line you hit an incorrect key,
recall that
you may delete the incorrect character
or cancel the entire line of input by erasing in the usual way.
Refer either
to the last few pages of Session 1
D 3
or to ``Communicating with \s-2UNIX\s0'' if you need to review
E 3
I 3
if you need to review
E 3
the procedures for making a correction.
The most important idea to remember is that
erasing a character or cancelling a line must be done
before you press the \s-2RETURN\s+2 key.
E 2
.SH
D 2
Listing what's in the buffer
E 2
I 2
Listing what's in the buffer (p)
E 2
.PP
D 2
Having appended text to what you wrote in Lesson 1,
you might be curious to see what is in the buffer.
E 2
I 2
Having appended text to what you wrote in Session 1,
you might want to see all the lines in the buffer.
E 2
To print the contents of the buffer, type the command:
.DS I 1i
:\|\fB1,$p
.R
.DE
D 2
The ``1'' stands for line 1 of the buffer,
E 2
I 2
The ``1''\(dg
.FS
\(dgThe numeral ``one'' is the top left-most key,
and should not be confused with the letter ``el''.
.FE
stands for line 1 of the buffer,
E 2
the ``$'' is a special symbol designating the last line
of the buffer,
and ``p'' (or \fBprint\fR) is the command to print from line 1
D 2
to the end of the buffer.  Thus,
``1,$p''
gives you:
E 2
I 2
to the end of the buffer.
The command ``1,$p'' gives you:
E 2
.DS I 1i
This is some sample text.
And thiss is some more text.
Text editing is strange, but nice.
This is text added in Session 2.
It doesn't mean much here, but
it does illustrate the editor.
.DE
D 2
Occasionally, you may
enter into the buffer a character which can't be printed,
which is done by striking a key while the \s-2CTRL\s0 key is depressed.
E 2
I 2
Occasionally, you may accidentally
type a character that can't be printed,
which can be done by striking a key
while the \s-2CTRL\s0 key is pressed.
E 2
In printing lines, edit uses a special notation to
show the existence of non-printing characters.
D 2
Suppose you had introduced the non-printing character ``control-a''
E 2
I 2
Suppose you had introduced the non-printing character ``control-A''
E 2
into the word ``illustrate''
D 2
by accidently holding down the \s-2CTRL\s0 key while
E 2
I 2
by accidently pressing the \s-2CTRL\s0 key while
E 2
typing ``a''.
D 2
Edit would display
E 2
I 2
This can happen on many terminals
because the \s-2CTRL\s+2 key and the ``A'' key
are beside each other.
If your finger presses between the two keys,
control-A results.
When asked to print the contents of the buffer,
edit would display
E 2
.DS I 1i
it does illustr^Ate the editor.
.DE
D 2
if you asked to have the line printed.
To represent the control-a, edit shows ``^A''.
The sequence ``^'' followed by a capital letter stands for the one character
E 2
I 2
To represent the control-A, edit shows ``^A''.
The sequence ``^'' followed by a capital
letter stands for the one character
E 2
entered by holding down the \s-2CTRL\s0 key and typing the letter
which appears after the ``^''.
D 2
We'll soon discuss the commands which can be used
E 2
I 2
We'll soon discuss the commands that can be used
E 2
to correct this typing error.
.PP
In looking over the text we see that
D 2
``this'' is typed as ``thiss'' in the second line, as suggested.
E 2
I 2
``this'' is typed as ``thiss'' in the second line,
a deliberate error so we can learn to make corrections.
E 2
Let's correct the spelling.
.SH
Finding things in the buffer
.PP
In order to change something in the buffer we first need to
D 2
find it.  We can find ``thiss'' in the text we have
E 2
I 2
find it.
We can find ``thiss'' in the text we have
E 2
entered by looking at a listing
D 2
of the lines.  Physically speaking, we search the lines
E 2
I 2
of the lines.
Physically speaking, we search the lines
E 2
of text looking for ``thiss'' and stop searching when
we have found it.
The way to tell edit to search for something
is to type it inside slash marks:
.DS I 1i
:\|\fB/thiss/
.R
.DE
By typing
.B /thiss/
D 2
and pressing carriage return edit is
instructed to search for ``thiss''.
If we asked edit to look for a pattern of characters
which it could not find in the buffer,
it would respond ``Pattern not found''.
E 2
I 2
and pressing \s-1RETURN\s0,
you instruct edit to search for ``thiss''.
If you ask edit to look for a pattern of characters
which it cannot find in the buffer,
it will respond ``Pattern not found''.
E 2
When edit finds
the characters ``thiss'', it will print the line of text
for your inspection:
.DS I 1i
And thiss is some more text.
.DE
Edit is now positioned in the buffer at the
D 2
line which it just printed,
E 2
I 2
line it just printed,
E 2
ready to make a change in the line.
I 2
.bp
E 2
.SH
The current line
.PP
D 2
At all times during an editing session,
edit keeps track of the line in the buffer where it is positioned.
In general, the line which has been most recently
E 2
I 2
Edit keeps track of the line in the buffer where it is located
at all times during an editing session.
In general, the line that has been most recently
E 2
printed, entered, or changed
D 2
is considered to be the current position in the buffer.
You can refer to your current position in the buffer by the
E 2
I 2
is the current location in the buffer.
The editor is prepared to make changes
at the current location in the buffer,
unless you direct it to another location.
.PP
In particular,
when you bring a file into the buffer,
you will be located at the last line in the file,
where the editor left off copying the lines
from the file to the buffer.
If your first editing command is ``append'',
the lines you enter are added
to the end of the file,
after the current line \(em
the last line in the file.
.PP
You can refer to your current location in the buffer by the
E 2
symbol
period (.) usually known by the name ``dot''.
If you type ``.'' and carriage
return you will be instructing edit to print the current line:
.DS I 1i
:\|\fB\s+2\&.\s-2
.R
And thiss is some more text.
.DE
.PP
If you want to know the number of the current line,
you can type
.B \&.=
D 2
and carriage return, 
E 2
I 2
and press \s-2RETURN\s+2,
E 2
and edit will respond with the line number:
.DS I 1i
:\|\fB\s+2.\s-2=
.R
2
.DE
D 2
If you type the number of any line and a carriage return,
edit will
position you at that line and
E 2
I 2
If you type the number of any line and press \s-2RETURN\s+2,
edit will position you at that line and
E 2
print its contents:
.DS I 1i
:\|\fB2
.R
And thiss is some more text.
.DE
D 2
You should experiment with these commands to assure
yourself that you understand what they do.
E 2
I 2
You should experiment with these commands
to gain experience in using them to make changes.
E 2
.SH
Numbering lines (nu)
.PP
The
.B
number (nu)
.R
command is similar to print,
giving both the number and the text of each printed line.
To see the number and the text of the current line type
.DS I 1i
:\|\fBnu
.R
\0\0\0\0\02\0\0And thiss is some more text.
.DE
D 2
Notice that the shortest abbreviation for the number command is
``nu'' (and not ``n'' which is used for a different command).
E 2
I 2
Note that the shortest abbreviation for the number command is
``nu'' (and not ``n'', which is used for a different command).
E 2
You may specify a range of lines
to be listed by the number command in the same way that lines
are specified for print.
D 2
For example, ``1,$nu'' lists all lines in the buffer with the
E 2
I 2
For example, \f31,$nu\f1 lists all lines in the buffer with their
E 2
corresponding line numbers.
.SH
Substitute command (s)
.PP
D 2
Now that we have found our misspelled word it is 
time to change it from ``thiss'' to ``this''.
E 2
I 2
Now that you have found the misspelled word, 
you can change it from ``thiss'' to ``this''.
E 2
As far as edit is concerned,
changing things is a matter of
substituting one thing for another.
As
.I a
stood for
.I append,
so
.I s
stands for
.I substitute.
We will use the abbreviation ``s'' to reduce the chance
of mistyping the substitute command.
This command will instruct edit to make the change:
.DS I 1i
D 2
2s/thiss/this/
E 2
I 2
\f32s/thiss/this/\f1
E 2
.DE
We first indicate the line to be changed, line 2,
and then
type an ``s'' to indicate we want
D 2
substitution.
E 2
I 2
edit to make a substitution.
E 2
Inside the first set of slashes
are the characters that we want to change,
D 2
followed by the characters to replace them
E 2
I 2
followed by the characters to replace them,
E 2
and then a closing slash mark.
To summarize:
.DS I 1i
D 2
2s/ \fIwhat is to be changed\fR / \fIwhat to change to \fR/
E 2
I 2
2s/ \fIwhat is to be changed\fR / \fIwhat to change it to \fR/
E 2
.DE
If edit finds an exact match of the characters to be
changed it will make the change
.B only
D 2
in the first occurrence of 
the characters.
E 2
I 2
in the first occurrence of the characters.
E 2
If it does not find the characters
D 2
to be changed it will respond:
E 2
I 2
to be changed, it will respond:
E 2
.DS I 1i
Substitute pattern match failed
.DE
D 2
indicating your instructions could not be carried out.
When edit does find the characters which you want to change,
E 2
I 2
indicating that your instructions could not be carried out.
When edit does find the characters that you want to change,
E 2
it will make the substitution and automatically print
the changed line, so that you can check that the correct substitution
was made.
In the example,
.DS I 1i
:\|\fB2s/thiss/this/
.R
And this is some more text.
D 2
:
E 2
.DE
line 2 (and line 2 only) will be searched for the characters
``thiss'', and when the first exact match is found, ``thiss''
will be changed to ``this''.
Strictly speaking, it was not necessary above to
specify  the number of the line to be changed.
In
.DS I 1i
:\|\fBs/thiss/this/
.R
.DE
edit will assume that we mean to change
D 2
the line where we are currently positioned
(``.'').
E 2
I 2
the line where we are currently located (``.'').
E 2
In this case,
the command without a line number would have produced the same result
D 2
because we were already positioned
E 2
I 2
because we were already located
E 2
at the line we wished to change.
.PP
D 2
For another illustration of substitution
we may choose the line:
E 2
I 2
For another illustration of the substitute command,
let us choose the line:
E 2
.DS I 1i
Text editing is strange, but nice.
.DE
D 2
We might like to be a bit more positive.  Thus, we could
take out the characters ``strange, but\ '' so the line 
would read:
E 2
I 2
You can make this line a bit more positive
by taking out the characters ``strange, but\ '' so the line 
reads:
E 2
.DS I 1i
Text editing is nice.
.DE
D 2
A command which will first position edit at that line
E 2
I 2
A command that will first position edit at the desired line
E 2
and then make the substitution is:
.DS I 1i
:\|\fB/strange/s/strange, but //
.R
.DE
D 2
.PP
E 2
I 2
.LP
E 2
What we have done here is combine our search with
our substitution.
D 2
Such combinations are perfectly legal.
This illustrates that we do not necessarily have to use
E 2
I 2
Such combinations are perfectly legal,
and speed up editing quite a bit
once you get used to them.
That is, you do not necessarily have to use
E 2
line numbers to identify a line to edit.
D 2
Instead, we may identify the line we want to change
E 2
I 2
Instead, you may identify the line you want to change
E 2
by asking edit to search for a specified pattern of letters
D 2
which occurs in that line.
E 2
I 2
that occurs in that line.
E 2
The parts of the above command are:
D 2
.in +1i
E 2
.TS
I 2
.in +1i
E 2
.nr 35 \n(.u
.nf
.ds #d .d
.if \(ts\n(.z\(ts\(ts .ds #d nl
.nr 80 0
.nr 38 \w\f3/strange/\fP
.if \n(80<\n(38 .nr 80 \n(38
.nr 38 \w\f3s\fP
.if \n(80<\n(38 .nr 80 \n(38
.nr 38 \w\f3/strange, but //\fP
.if \n(80<\n(38 .nr 80 \n(38
.nr 81 0
.nr 38 \wtells edit to find the characters ``strange'' in the text
.if \n(81<\n(38 .nr 81 \n(38
D 2
.nr 38 \wtells edit we want to make a substitution
E 2
I 2
.nr 38 \wtells edit to make a substitution
E 2
.if \n(81<\n(38 .nr 81 \n(38
.nr 38 \wsubstitutes nothing at all for the characters ``strange, but ''
.if \n(81<\n(38 .nr 81 \n(38
.nr 38 1n
.nr 79 0
.nr 40 \n(79+(0*\n(38)
.nr 80 +\n(40
.nr 41 \n(80+(3*\n(38)
.nr 81 +\n(41
.nr TW \n(81
.if t .if (\n(TW+\n(.o)>7.75i .tm Table at line 307 file ed2.tbl is too wide - \n(TW units
.fc  
.nr #T 0
.eo
.de T#
.ds #d .d
.if \(ts\n(.z\(ts\(ts .ds #d nl
.mk ##
.nr ## -1v
..
.ec
.ta \n(80u \n(81u 
\&\h'|\n(40u'\f3/strange/\fP\h'|\n(41u'tells edit to find the characters ``strange'' in the text
.ta \n(80u \n(81u 
D 2
\&\h'|\n(40u'\f3s\fP\h'|\n(41u'tells edit we want to make a substitution
E 2
I 2
\&\h'|\n(40u'\f3s\fP\h'|\n(41u'tells edit to make a substitution
E 2
.ta \n(80u \n(81u 
\&\h'|\n(40u'\f3/strange, but //\fP\h'|\n(41u'substitutes nothing at all for the characters ``strange, but ''
.fc
.nr T. 1
.T# 1
.if \n(35>0 .fi
D 2
.TE
E 2
.in -1i
I 2
.TE
E 2
.PP
You should note the space after ``but'' in ``/strange, but /''. 
D 2
If you do not indicate the space is to be taken out,
your line will be:
E 2
I 2
If you do not indicate that the space is to be taken out,
your line will read:
E 2
.DS I 1i
.if t Text editing is   nice.
.if n Text editing is  nice.
.DE
which looks a little funny   
because of the extra space between ``is'' and ``nice''.
Again, we realize from this that a blank space
is a real character to a computer, and in editing text
we need to be aware of spaces
within a line just as we would be aware of an ``a'' or 
a ``4''.
.SH
Another way to list what's in the buffer (z)
.PP
Although the print command is useful for looking at specific lines
in the buffer,
D 2
other commands can be more convenient for
E 2
I 2
other commands may be more convenient for
E 2
viewing large sections of text.
You can ask to see a screen full of text at a time
by using the command
.B z.
If you type
.DS I 1i
:\|\fB1z
.R
.DE
edit will start with line 1 and continue printing lines,
stopping either when the screen of
your terminal is full
or when the last line in the buffer has been printed.
D 2
If you want to read the next segment of text, give the command
E 2
I 2
If you want to read the next segment of text, type the command
E 2
.DS I 1i
:\|\fBz
.DE
If no starting line number is given for the z command,
printing will start at the ``current'' line, in this case the
last line printed.
Viewing lines in the buffer one screen full at a time
D 2
is known as paging.
Paging can also be used to print a section of text on a hard-copy terminal.
E 2
I 2
is known as \fIpaging\fR.
Paging can also be used to print
a section of text on a hard-copy terminal.
E 2
.SH
Saving the modified text
.PP
This seems to be a good place to pause in our work,
and so we should end the second session.
If you (in haste) type ``q'' to quit the session
your dialogue with edit will be:
.DS I 1i
:\|\fBq
.R
D 2
No write since last change (q! quits)
E 2
I 2
No write since last change (:quit! overrides)
E 2
:
.DE
This is edit's warning that you have not written
the modified contents of the buffer to disk.
D 2
You run the risk of losing the work you have done
during the editing session since the latest write
command.  Since in this lesson we have not written
E 2
I 2
You run the risk of losing the work you did
during the editing session since you typed the latest write
command.
Because in this lesson we have not written
E 2
to disk at all, everything we have done
D 2
would be lost.
If we did not want to save the work done during
this editing session, we would have to type ``q!''
to confirm that we indeed wanted to end the session
immediately, losing the contents of the buffer.
E 2
I 2
would have been lost
if edit had obeyed the \fBq\fR command.
If you did not want to save the work done during
this editing session, you would have to type ``q!''
or (``quit!'')
to confirm that you indeed wanted to end the session
immediately,
leaving the file as it was
after the most recent ``write'' command.
E 2
However,
D 2
since we want to preserve what
we have edited, we need to say:
E 2
I 2
since you want to save what
you have edited, you need to type:
E 2
.DS I 1i
:\|\fBw
.R
"text" 6 lines, 171 characters
.DE
D 2
and then,
E 2
I 2
and then follow with the commands to quit and logout:
E 2
.DS I 1i
:\|\fBq
D 2
% \fI{control d}\fR
E 2
I 2
% \fBlogout\fR
E 2
.DE
and hang up the phone or turn off the terminal when
\s-2UNIX\s0 asks for a name.
I 2
Terminals connected to the port selector
will stop after the logout command,
and pressing keys on the keyboard will do nothing.
.sp 1
.PP
E 2
This is the end of the second session on \s-2UNIX\s0 text editing.
.bp
D 2
.ND
E 2
.TL
Session 3
.SH
Bringing text into the buffer (e)
.PP
Login to \s-2UNIX\s0 and make contact with edit.  
You should try to login without
looking at the notes, but if you must
then by all means do.
.PP
Did you remember to give the name of the file
D 2
you wanted to edit?  That is, did you say
E 2
I 2
you wanted to edit?
That is, did you type
E 2
.DS I 1i
% \fBedit text\fR
.DE
or simply
.DS I 1i
% \fBedit\fR
.DE
Both ways get you in contact with edit, but the first way
will bring a copy of the file named ``text'' into
the buffer.  
If you did forget to tell edit the name of your file,
you can get it into the buffer by
D 2
saying:
E 2
I 2
typing:
E 2
.DS I 1i
:\|\fBe text
.R
"text" 6 lines, 171 characters
.DE
The command
.B edit,
D 2
which may be abbreviated ``\fBe\fR'',
E 2
I 2
which may be abbreviated \fBe\fR,
E 2
tells edit that you want
to erase anything that might already be in 
the buffer and bring a copy of the file ``text'' into the buffer
for editing.
You may also use the edit (e) command to change files in
D 2
the middle of an editing session 
E 2
I 2
the middle of an editing session,
E 2
or to give edit the name of a new file that you want to create.
Because the edit command clears the buffer,
you will receive a warning if you try to edit a new file without
having saved a copy of the old file.
This gives you a chance to write the contents of the buffer to disk
before editing the next file.
.SH
Moving text in the buffer (m)
.PP
Edit allows you to move lines of text
from one location in the buffer to another
by means of the
.B move
D 2
(\fBm\fR) command:
E 2
I 2
(\fBm\fR) command.
The first two examples are for illustration only,
though after you have read this Session
you are welcome to return to them for practice.
The command
E 2
.DS I 1i
:\|\fB2,4m$
.R
.DE
D 2
This command directs edit to move lines 2, 3, and 4
E 2
I 2
directs edit to move lines 2, 3, and 4
E 2
to the end of the buffer ($).  
The format for the move command is that you specify
the first line to be moved, the last line to be moved,
the move command ``m'', and the line after which
the moved text is to be placed.
D 2
Thus,
E 2
I 2
So,
E 2
.DS I 1i
D 2
:\|\fB1,6m20
E 2
I 2
:\|\fB1,3m6
E 2
.R
.DE
D 2
would instruct edit to move lines 1 through 6 (inclusive) 
to a position after line 20 in the buffer.
E 2
I 2
would instruct edit to move lines 1 through 3 (inclusive) 
to a location after line 6 in the buffer.
E 2
To move only one line, say, line 4,
D 2
to a position in the buffer after line 6, 
the command would be ``4m6''.
E 2
I 2
to a location in the buffer after line 5, 
the command would be ``4m5''.
E 2
.PP
Let's move some text using the command:
.DS I 1i
:\|\fB5,$m1
.R
2 lines moved
it does illustrate the editor.
.DE
D 2
After executing a command which changes more than one line of the buffer,
edit tells how many lines were affected by the change.
The last moved line is printed for your inspection.
E 2
I 2
After executing a command that moves more than one line of the buffer,
edit tells how many lines were affected by the move
and prints the last moved line for your inspection.
E 2
If you want to see more than just the last line,
I 2
you can then
E 2
use the print (p), z, or number (nu) command to view more text.
The buffer should now contain:
.DS I 1i
This is some sample text.
It doesn't mean much here, but
it does illustrate the editor.
And this is some more text.
Text editing is nice.
This is text added in Session 2.
.DE
D 2
We can restore the original order by typing:
E 2
I 2
You can restore the original order by typing:
E 2
.DS I 1i
:\|\fB4,$m1
.R
.DE
or, combining context searching and the move command:
.DS I 1i
:\|\fB/And this is some/,/This is text/m/This is some sample/
.R
.DE
I 2
(Do not type both examples here!)
E 2
The problem with combining context searching
with the move command 
D 2
is that the chance of making a typing error
E 2
I 2
is that your chance of making a typing error
E 2
in such a long command is greater than
D 2
if one types line numbers.
E 2
I 2
if you type line numbers.
E 2
.SH
Copying lines (copy)
.PP
The
.B copy
command
is used to make a second copy of specified lines,
leaving the original lines where they were.
Copy
has the same format as the move command, for example:
.DS I 1i
D 2
:\|\fB12,15copy $
E 2
I 2
:\|\fB2,5copy $
E 2
.R
.DE
D 2
makes a copy of lines 12 through 15,
E 2
I 2
makes a copy of lines 2 through 5,
E 2
placing the added lines after the buffer's end ($).
Experiment with the copy command
so that you can become familiar with how it works.
Note that the shortest abbreviation for copy is
D 2
``co'' (and
.B not
the letter ``c'' which has another meaning).
E 2
I 2
\f3co\f1 (and
not the letter ``c'', which has another meaning).
E 2
.SH
Deleting lines (d)
.PP
Suppose you want to delete 
the line
.DS I 1i
This is text added in Session 2.
.DE
from the buffer.
If you know the number of the line to be deleted,
you can type
that number followed by
D 2
``\fBdelete\fR'' or ``\fBd\fR''.
This example deletes line 4:
E 2
I 2
\fBdelete\fR or \fBd\fR.
This example deletes line 4,
which is ``This is text added in Session 2.''
if you typed the commands
suggested so far.
E 2
.DS I 1i
:\|\fB4d
.R
It doesn't mean much here, but
.DE
D 2
Here ``4'' is the number of the line to be deleted and
``delete'' or ``d'' is the command to delete the line.
E 2
I 2
Here ``4'' is the number of the line to be deleted,
and ``delete'' or ``d'' is the command to delete the line.
E 2
After executing the delete command,
D 2
edit prints the line which has become the current line (``.'').
E 2
I 2
edit prints the line that has become the current line (``.'').
E 2
.PP
If you do not happen to know the line number
you can search for the line and then delete it using this
sequence of commands:
.DS I 1i
:\|\fB/added in Session 2./
.R
This is text added in Session 2.
:\|\fBd
.R
It doesn't mean much here, but
.DE
The ``/added in Session 2./''
asks edit to locate and print
D 2
the next line which contains the indicated text.
Once you are sure that you have correctly specified the line that
E 2
I 2
the line containing the indicated text,
starting its search at the current line
and moving line by line
until it finds the text.
Once you are sure that you have correctly specified the line
E 2
you want to delete,
you can enter the delete (d) command.
In this case it is not necessary to
specify a line number before the ``d''.
If no line number is given,
edit deletes the current line (``.''),
that is, the line found by our search.
After the deletion, your buffer should contain:
.DS I 1i
This is some sample text.
And this is some more text.
Text editing is nice.
It doesn't mean much here, but
it does illustrate the editor.
I 2
And this is some more text.
Text editing is nice.
This is text added in Session 2.
It doesn't mean much here, but
E 2
.DE
To delete both lines 2 and 3:
.DS I 1i
And this is some more text.
Text editing is nice.
.DE
you type
.DS I 1i
D 2
:\|\fB2,3d
.R
E 2
I 2
:\|\f32,3d\f1
2 lines deleted
E 2
.DE
which specifies the range of lines from 2 to 3,
D 2
and the operation on those lines \- ``d'' for delete.
E 2
I 2
and the operation on those lines \(em ``d'' for delete.
If you delete more than one line
you will receive a message
telling you the number of lines deleted,
as indicated in the example above.
E 2
.PP
D 2
Again, this presumes that you know the line numbers for
E 2
I 2
The previous example assumes that you know the line numbers for
E 2
the lines to be deleted.
If you do not you might combine the search command
D 2
with the delete command as so:
E 2
I 2
with the delete command:
E 2
.DS I 1i
:\|\fB/And this is some/,/Text editing is nice./d
.R
.DE
.SH
D 2
A word or two of caution:
E 2
I 2
A word or two of caution
E 2
.PP
In using the search function to locate lines to
be deleted you should be
.B
absolutely sure
.R
the characters you give as the basis for the search
will take edit to the line you want deleted.
Edit will search for the first
occurrence of the characters starting from where
you last edited \-
that is, from the line you see printed if you type dot (.).
.PP
A search based on too few
characters may result in the wrong lines being deleted,
which edit will do as easily as if you had meant it.
For this reason, it is usually safer
to specify the search and then delete in two separate steps,
at least until you become familiar enough with using the editor
that you understand how best to specify searches.
For a beginner it is not a bad idea to double-check
D 2
each command before pressing carriage return to send the command on its way.
E 2
I 2
each command before pressing \s-2RETURN\s+2 to send the command on its way.
E 2
.SH
Undo (u) to the rescue
.PP
The
.B
undo (u)
.R
command has the ability to
D 2
reverse the effects of the last command.
E 2
I 2
reverse the effects of the last command that changed the buffer.
E 2
To undo the previous command, type
``u'' or ``undo''.
Undo can rescue
the contents of the buffer from many an unfortunate mistake.
However, its powers are not unlimited,
D 2
so it is still wise to be reasonably careful about the commands you give.
E 2
I 2
so it is still wise to be reasonably
careful about the commands you give.
.PP
E 2
It is possible to undo only commands which
D 2
have the power to change the buffer, for example
E 2
I 2
have the power to change the buffer \(em for example,
E 2
delete, append, move, copy, substitute, and even undo itself.
D 2
The commands write (w) and edit (e) which interact with disk files
cannot be undone, nor can commands such as print which do not change
the buffer.
E 2
I 2
The commands write (w) and edit (e), which interact with disk files,
cannot be undone, nor can commands that do not change
the buffer, such as print.
E 2
Most importantly,
the
.B only
D 2
command which can be reversed by undo
E 2
I 2
command that can be reversed by undo
E 2
is the
D 2
last ``undo-able'' command which you gave.
E 2
I 2
last ``undo-able'' command you typed.
You can use control-H and @ to change
commands while you are typing them,
and undo to reverse the effect of the commands
after you have typed them and pressed \s-2RETURN\s+2.
E 2
.PP
To illustrate,
let's issue an undo command.
Recall that the last buffer-changing command we gave deleted
D 2
the lines which were formerly numbered 2 and 3.
Executing undo at this moment will reverse the effects
E 2
I 2
the lines formerly numbered 2 and 3.
Typing undo at this moment will reverse the effects
E 2
of the deletion, causing those two lines to be
replaced in the buffer.
.DS I 1i
:\|\fBu
.R
2 more lines in file after undo
And this is some more text.
.DE
Here again, edit informs you if the command affects more
than one line,
and prints
the text of the line which is now ``dot'' (the current line).
.SH
More about the dot (.) and buffer end ($)
.PP
The function assumed by the symbol dot depends on its context.
It can be used:
.IP
D 2
1.  to exit from append mode we type dot (and only a dot) on
a line and press carriage return;
E 2
I 2
1.  to exit from append mode; we type dot (and only a dot) on
a line and press \s-2RETURN\s+2;
E 2
.IP
2.  to refer to the line we are at in the buffer.
.LP
Dot can also be combined with the equal sign to get
the number of the line currently being edited:
.DS I 1i
:\|\fB\&.=
.R
.DE
D 2
Thus if we type ``\fB.\fR='' we are asking for the number of the line
E 2
I 2
If we type ``\fB.\fR='' we are asking for the number of the line,
E 2
and if we type ``\fB.\fR'' we are asking for the text of the line.
.PP
In this editing session and the last, we used the dollar
sign to indicate the end of the buffer
in commands such as print, copy, and move.
The dollar sign as a command asks edit to print the last
line in the buffer.
D 2
If the dollar sign is combined with the equal sign ($=)
E 2
I 2
If the dollar sign is combined with the equal sign (\f3$=\f1)
E 2
edit will print the line number corresponding to the
last line in the buffer.
.PP
D 2
``\fB.\fR'' and ``$'' therefore represent line numbers.
E 2
I 2
``\fB.\fR'' and ``$'', then, represent line numbers.
E 2
Whenever appropriate, these symbols can be used in
place of line numbers in commands.
For example
.DS I 1i
:\|\fB\s+2.\s-2,$d
.R
.DE
instructs edit to delete all lines from the current line (\fB.\fR)
to the end of the buffer.
.SH
Moving around in the buffer  (+ and \-)
.PP
D 2
It is frequently convenient during an editing session
E 2
I 2
When you are editing
you often want
E 2
to go back and re-read a previous line.
D 2
We could specify a context search for a line we want to
read if we remember some of its text,
but if we simply want to see what was written a few, say 3, lines
ago, we can type
E 2
I 2
You could specify a context search for a line you want to
read if you remember some of its text,
but if you simply want to see what was written a few, say 3, lines
ago, you can type
E 2
.DS I 1i
\-3p
.DE
This tells edit to move back to a position 3 lines
before the current line (.)
and print that line.
D 2
We can move forward in the buffer similarly:
E 2
I 2
You can move forward in the buffer similarly:
E 2
.DS I 1i
+2p
.DE
D 2
instructs edit to print the line which is 2
ahead of our current position.
E 2
I 2
instructs edit to print the line that is 2
ahead of your current position.
E 2
.PP
You may use ``+'' and ``\-'' in any command where edit
accepts line numbers.
Line numbers specified with ``+'' or ``\-''
can be combined to print a range of lines.
The command
.DS I 1i
:\|\fB\-1,+2copy$
.R
.DE
makes a copy of 4 lines:  the current line, the line before it,
and the two after it.
The copied lines will be placed after the last line
D 2
in the buffer ($).
E 2
I 2
in the buffer ($),
and the original lines referred to by ``\-1'' and ``+2''
remain where they are.
E 2
.PP
Try typing only ``\-''; you will move back one line just as
if you had typed ``\-1p''.
Typing the command ``+'' works similarly.
You might also try typing a few plus or minus signs in a row
(such as ``+++'') to see edit's response.
D 2
Typing a carriage return alone on a line is the equivalent
E 2
I 2
Typing \s-2RETURN\s+2 alone on a line is the equivalent
E 2
of typing ``+1p''; it will move you one line ahead in the buffer
and print that line.
.PP
If you are at the last line of the buffer and try
to move further ahead, perhaps by typing a ``+'' or
a carriage return alone on the line,
edit will remind you that you are at the end of the buffer:
D 2
.DS I 1i
E 2
I 2
.sp
.nf
.ti 1i
E 2
At end-of-file
D 2
.DE
E 2
I 2
.br
or
.ti 1i
Not that many lines in buffer
.fi
.LP
E 2
Similarly, if you try to move to a position before the first line,
edit will print one of these messages:
D 2
.DS I 1i
E 2
I 2
.sp
.nf
.ti 1i
E 2
Nonzero address required on this command
I 2
.br
or
.ti 1i
E 2
Negative address \- first buffer line is 1
D 2
.DE
E 2
I 2
.fi
.LP
E 2
The number associated with a buffer line is the line's ``address'',
in that it can be used to locate the line.
.SH
Changing lines (c)
.PP
D 2
There may be occasions when you want to delete certain lines and
E 2
I 2
You can also delete certain lines and
E 2
insert new text in their place.
This can be accomplished easily with the
.B "change (c)"
command.
The change command instructs edit to delete specified lines
D 2
and then switch to text input mode in order to
accept the text which will replace them.
Let's say we want to change the first two lines in the buffer:
E 2
I 2
and then switch to text input mode to
accept the text that will replace them.
Let's say you want to change the first two lines in the buffer:
E 2
.DS I 1i
This is some sample text.
And this is some more text.
.DE
to read
.DS I 1i
This text was created with the \s-2UNIX\s0 text editor.
.DE
D 2
To do so, you can type:
E 2
I 2
To do so, you type:
E 2
.DS I 1i
:\|\fB1,2c
.R
2 lines changed
.B
This text was created with the \s-2UNIX\s0 text editor.
\s+2\&.\s-2
.R
:
.DE
In the command
.B 1,2c
we specify that we want to change
the range of lines beginning with 1 and ending with 2
by giving line numbers as with the print command.
These lines will be deleted.
D 2
After a carriage return enters the change command,
E 2
I 2
After you type \s-2RETURN\s+2 to end the change command,
E 2
edit notifies you if more than one line will be changed
and places you in text input mode.
Any text typed on the following lines will be inserted into
the position where lines were deleted by the change command.
I 2
.B
E 2
You will remain in text input mode until you exit in the usual way,
by typing a period alone on a line.
I 2
.R
E 2
Note that the number of lines added to the buffer need not be
the same as the number of lines deleted.
.sp 1
.PP
This is the end of the third session on text editing with \s-2UNIX\s0.
.bp
D 2
.ND
.TL
Session 4
E 2
I 2
.SH
.ce 1
\s+2Session 4\s0
.sp
E 2
.PP
This lesson covers several topics, starting with
D 2
commands which apply throughout the buffer,
E 2
I 2
commands that apply throughout the buffer,
E 2
characters with special meanings,
and how to issue \s-2UNIX\s0 commands while in the editor.
The next topics deal with files:
more on reading and writing,
and methods of recovering files lost in a crash.
The final section suggests sources of further information.
.SH
Making commands global (g)
.PP
One disadvantage to the commands we have used for
searching or substituting is that if you
have a number of instances of a word to change 
it appears that you have to type the command 
repeatedly, once for
each time the change needs to be made.
Edit, however, provides a way to make commands
apply to the entire contents of the buffer \-
the
.B
global (g)
.R
command.
.PP
To print all lines
containing a certain sequence of characters
(say, ``text'')
the command is:
.DS I 1i
:\|\fBg/text/p
.R
.DE
The ``g'' instructs edit to
make a global search for all lines
in the buffer containing the characters  ``text''.
The ``p'' prints the lines found.
.PP
To issue a global command, start by typing a ``g'' and then a search
pattern identifying
the lines to be affected.
Then, on the same line, type the command to be
D 2
executed on the identified lines.
E 2
I 2
executed for the identified lines.
E 2
Global substitutions are frequently useful.
For example,
to change all instances of the word ``text'' to the word ``material''
the command would be a combination of the global search and the
substitute command:
.DS I 1i
:\|\fBg/text/s/text/material/g
.R
.DE
D 2
Note the ``g'' at the end of the global command
E 2
I 2
Note the ``g'' at the end of the global command,
E 2
which instructs edit to change
each and every instance of ``text'' to ``material''.
If you do not type the ``g'' at the end of the command
only the
.I first
D 2
instance of ``text'' in each line will be changed
E 2
I 2
instance of ``text'' \fIin each line\fR will be changed
E 2
(the normal result of the substitute command).
The ``g'' at the end of the command is independent of the ``g''
at the beginning.
You may give a command such as:
.DS I 1i
D 2
:\|\fB14s/text/material/g
E 2
I 2
:\|\fB5s/text/material/g
E 2
.R
.DE
D 2
to change every instance of ``text'' in line 14 alone.
Further, neither command will change ``Text'' to ``material''
because ``Text'' begins with a capital rather than a lower-case
E 2
I 2
to change every instance of ``text'' in line 5 alone.
Further, neither command will change ``text'' to ``material''
if ``Text'' begins with a capital rather than a lower-case
E 2
.I t.
.PP
Edit does not automatically print the lines modified by a
global command.
If you want the lines to be printed, type a ``p''
at the end of the global command:
.DS I 1i
:\|\fBg/text/s/text/material/gp
.R
.DE
D 2
The usual qualification should be made
E 2
I 2
You should be careful
E 2
about using the global command in combination with any other \-
in essence, be sure of what you are telling edit to do
D 2
to the entire buffer.  For example,
E 2
I 2
to the entire buffer.
For example,
E 2
.DS I 1i
:\|\fBg/ /d
.R
72 less lines in file after global
.DE
will delete every line containing a blank anywhere in it.
This could adversely affect
your document, since most lines have spaces between words
and thus would be deleted.
After executing the global command,
edit will print a warning if the command added or deleted more than one line.
Fortunately, the undo command can reverse
the effects of a global command.
You should experiment with the global command
D 2
on a small buffer of text to see what it can do for you.
E 2
I 2
on a small file of text to see what it can do for you.
E 2
.SH
More about searching and substituting
.PP
In using slashes to identify a character string
that we want to search for or change,
we have always specified the exact characters.
There is a less tedious way to
repeat the same string of characters.
D 2
To change ``noun'' to ``nouns'' we may type either
E 2
I 2
To change ``text'' to ``texts'' we may type either
E 2
.DS I 1i
D 2
:\|\fB/noun/s/noun/nouns/
E 2
I 2
:\|\fB/text/s/text/texts/
E 2
.R
.DE
as we have done in the past,
or a somewhat abbreviated command:
.DS I 1i
D 2
:\|\fB/noun/s//nouns/
E 2
I 2
:\|\fB/text/s//texts/
E 2
.R
.DE
In this example, the characters to be changed
are not specified \-
there are no characters, not even a space,
D 2
between the two slash marks which indicate what is to be changed.
This lack of characters between the slashes is taken by the editor to mean
E 2
I 2
between the two slash marks
that indicate what is to be changed.
This lack of characters between the slashes
is taken by the editor to mean
E 2
``use the characters we last searched for as the characters to be changed.''
.PP
Similarly, the last context search may be repeated
by typing a pair of slashes with nothing between them:
.DS I 1i
:\|\fB/does/
.R
It doesn't mean much here, but
:\|\fB//
.R
it does illustrate the editor.
.DE
I 2
(You should note that the search command found the characters ``does''
in the word ``doesn't'' in the first search request.)
E 2
Because no characters are specified for the second search,
the editor scans the buffer for the next occurrence of the
characters ``does''.
.PP
Edit normally searches forward through the buffer,
wrapping around from the end of the buffer to the beginning,
until the specified character string is found.
If you want to search in the reverse direction,
use question marks (?) instead of slashes
D 2
to surround the character string.
.SH
E 2
I 2
to surround the characters you are searching for.
.PP
It is also possible
to repeat the last substitution
without having to retype the entire command.
An ampersand (&) used as a command
repeats the most recent substitute command,
using the same search and replacement patterns.
After altering the current line by typing
.DS I 1i
:\|\fBs/text/texts/
.R
.DE
you type
.DS I 1i
:\|\fB/text/&
.R
.DE
or simply
.DS I 1i
:\|\fB//&
.R
.DE
to make the same change on the next line in the buffer
containing the characters ``text''.
.SH
E 2
Special characters
.PP
Two characters have special meanings when
used in specifying searches:  ``$'' and ``^''.
``$'' is taken by the editor to mean ``end of the line''
and is used to identify strings
D 2
which occur at the end of a line.
E 2
I 2
that occur at the end of a line.
E 2
.DS I 1i
D 2
:\|\fBg/ing$/s//ed/p
E 2
I 2
:\|\fBg/text.$/s//material./p
E 2
.R
.DE
D 2
tells the editor to search for all lines ending in ``ing''
E 2
I 2
tells the editor to search for all lines ending in ``text.''
E 2
(and nothing else, not even a blank space),
D 2
to change each final ``ing'' to ``ed''
E 2
I 2
to change each final ``text.'' to ``material.'',
E 2
and print the changed lines.
.PP
The symbol ``^'' indicates the beginning of a line.
Thus,
.DS I 1i
:\|\fBs/^/1. /
.R
.DE
instructs the editor to insert ``1.'' and a space at the beginning
of the current line.
.PP
The characters ``$'' and ``^'' have special meanings only in the context
of searching.
At other times, they are ordinary characters.
If you ever need to search for a character that has a special meaning,
you must indicate that the
D 2
character is to temporarily lose
E 2
I 2
character is to lose temporarily
E 2
its special significance by typing another special character,
the backslash (\\), before it.
.DS I 1i
:\|\fBs/\\\\\&$/dollar/
.R
.DE
looks for the character ``$'' in the current
line and replaces it by the word ``dollar''.
Were it not for the backslash, the ``$'' would have represented
D 2
``the end of the line'' in your search,
not necessarily the character ``$''.
The backslash retains its special significance at all times.
E 2
I 2
``the end of the line'' in your search
rather than the character ``$''.
The backslash retains its special significance
unless it is preceded by another backslash.
E 2
.SH
Issuing \s-2UNIX\s0 commands from the editor
.PP
After creating several files with the editor,
you may want to delete files
no longer useful to you or ask for a list of your files.
Removing and listing files are not functions of the editor,
and so they require the use of \s-2UNIX\s0 system commands
(also referred to as ``shell'' commands, as
``shell'' is the name of the program that processes \s-2UNIX\s0 commands).
You do not need to quit the editor to execute a \s-2UNIX\s0 command
as long as you indicate that it
is to be sent to the shell for execution.
To use the \s-2UNIX\s0 command
D 2
.I rm
E 2
I 2
.B rm
E 2
to remove the file named ``junk'' type:
.DS I 1i
:\|\fB!rm junk
.R
!
:
.DE
The exclamation mark (!)
D 2
indicates that the rest of the line is to be processed as a \s-2UNIX\s0 command.
E 2
I 2
indicates that the rest of the line is to be processed as a shell command.
E 2
If the buffer contents have not been written since the last change,
D 2
a warning will be printed before the command is executed.
E 2
I 2
a warning will be printed before the command is executed:
.DS I 1i
[No write since last change]
.DE
E 2
The editor prints a ``!'' when the command is completed.
D 3
The tutorial ``Communicating with \s-2UNIX\s0''
describes useful features of the system,
of which the editor is only one part.
E 3
I 3
Other tutorials describe useful features of the system,
of which an editor is only one part.
E 3
.SH
Filenames and file manipulation
.PP
Throughout each editing session,
edit keeps track of the name of the file being edited as the
.I "current filename."
Edit remembers as the current filename the name given
when you entered the editor.
The current filename changes whenever the edit (e) command
is used to specify a new file.
Once edit has recorded a current filename,
it inserts that name into any command where a filename has been omitted.
If a write command does not specify a file,
edit, as we have seen, supplies the current filename.
D 2
You can have the editor write onto a different file
E 2
I 2
If you are editing a file named ``draft3'' having 283 lines in it,
you can have the editor write onto a different file
E 2
by including its name in the write command:
.DS I 1i
:\fB\|w chapter3
.R
D 2
"chapter3" 283 lines, 8698 characters
E 2
I 2
"chapter3" [new file] 283 lines, 8698 characters
E 2
.DE
The current filename remembered by the editor
.I
D 2
will not be changed as a result of the write command
unless it is the first filename given in the editing session.
E 2
I 2
will not be changed as a result of the write command.
E 2
.R
D 2
Thus, in the next write command
which does not specify a name,
edit will write onto the current file and not onto the file ``chapter3''.
E 2
I 2
Thus, if the next write command
does not specify a name,
edit will write onto the current file (``draft3'')
and not onto the file ``chapter3''.
E 2
.SH
The file (f) command
.PP
To ask for the current filename, type
.B file
(or
.B f ).
In response, the editor provides current information about the buffer,
D 2
including the filename, your current position, and the number of
lines in the buffer:
E 2
I 2
including the filename, your current position, the number of
lines in the buffer,
and the percent of the distance through the file
your current location is.
E 2
.DS I 1i
:\|\fBf
.R
"text" [Modified] line 3 of 4 --75%--
.DE
.\"The expression ``[Edited]'' indicates that the buffer contains
.\"either the editor's copy of the existing file ``text''
.\"or a file which you are just now creating.
If the contents of the buffer have changed
since the last time the file was written,
the editor will tell you that the file has been ``[Modified]''.
After you save the changes by writing onto a disk file,
the buffer will no longer be considered modified:
.DS I 1i
:\|\fBw
.R
"text" 4 lines, 88 characters
:\|\fBf
.R
"text" line 3 of 4 --75%--
.DE
.SH
Reading additional files (r)
D 2

E 2
.PP
The
D 2
.B
read (r)
.R
command allows you to add the contents of a file
E 2
I 2
\f3read (r)\f1 command allows you to add the contents of a file
E 2
to the buffer
D 2
without destroying the text already there.
E 2
I 2
at a specified location,
essentially copying new lines
between two existing lines.
E 2
To use it, specify the line after which the new text will be placed,
D 2
the command
.I r,
E 2
I 2
the \f3read (r)\f1 command,
E 2
and then the name of the file.
I 2
If you have a file named ``example'', the command
E 2
.DS I 1i
D 2
:\|\fB$r bibliography
E 2
I 2
:\|\fB$r example
E 2
.R
D 2
"bibliography" 18 lines, 473 characters
E 2
I 2
"example" 18 lines, 473 characters
E 2
.DE
D 2
This command reads in the file
.I bibliography
E 2
I 2
reads the file ``example''
E 2
and adds it to the buffer after the last line.
D 2
The current filename is not changed by the read command unless
it is the first filename given in the editing session.
E 2
I 2
The current filename is not changed by the read command.
E 2
.SH
Writing parts of the buffer
.PP
The
.B
write (w)
.R
command can write all or part of the buffer
to a file you specify.
We are already familiar with
writing the entire contents of the
buffer to a disk file.
To write only part of the buffer onto a file,
indicate the beginning and ending lines before the write command,
for example
.DS I 1i
:\|\fB45,$w ending
.R
.DE
Here all lines from 45 through the end of the buffer
are written onto the file named
.I ending.
The lines remain in the buffer
as part of the document you are editing,
and you may continue to edit the entire buffer.
I 2
Your original file is unaffected
by your command to write part of the buffer
to another file.
Edit still remembers whether you have saved changes to the buffer
in your original file or not.
E 2
.SH
Recovering files
.PP
I 2
Although it does not happen very often,
there are times \s-2UNIX\s+2 stops working
because of some malfunction.
This situation is known as a \fIcrash\fR.
E 2
Under most circumstances,
D 2
edit's crash recovery mechanism
E 2
I 2
edit's crash recovery feature
E 2
is able to save work to within a few lines of changes
D 2
after a crash or if the phone is hung up accidently.
E 2
I 2
before a crash (or an accidental phone hang up).
E 2
If you lose the contents of an editing buffer in a system crash,
D 2
you will normally receive mail when you login which gives
E 2
I 2
you will normally receive mail when you login that gives
E 2
the name of the recovered file.
To recover the file,
enter the editor and type the command
.B recover
(\fBrec\fR),
followed by the name of the lost file.
I 2
For example,
to recover the buffer for an edit session
involving the file ``chap6'', the command is:
E 2
.DS I 1i
.R
:\|\fBrecover chap6
.R
.DE
Recover is sometimes unable to save the entire buffer successfully,
so always check the contents of the saved buffer carefully
before writing it back onto the original file.
I 2
For best results,
write the buffer to a new file temporarily
so you can examine it without risk to the original file.
Unfortunately,
you cannot use the recover command
to retrieve a file you removed
using the shell command \f3rm\f1.
E 2
.SH
Other recovery techniques
.PP
If something goes wrong when you are using the editor,
it may be possible to save your work by using the command
.B preserve
(\fBpre\fR),
which saves the buffer as if the system had crashed.
If you are writing a file and you get the message
``Quota exceeded'', you have tried to use more disk storage
than is allotted to your account.
.I
Proceed with caution
.R
because it is likely that only a part
of the editor's buffer is now present in the file you tried to write.
In this case you should use the shell escape from the editor (!)
to remove some files you don't need and try to write
the file again.
If this is not possible and you cannot find someone to help you,
enter the command
.DS I 1i
:\|\fBpreserve
.R
.DE
D 2
and then seek help.
E 2
I 2
and wait for the reply,
.DS I 1i
File preserved.
.DE
If you do not receive this reply,
seek help immediately.
E 2
Do not simply leave the editor.
If you do, the buffer will be lost, 
and you may not be able to save your file.
I 2
If the reply is ``File preserved.''
you can leave the editor
(or logout)
to remedy the situation.
E 2
After a preserve, you can use the recover command
D 2
once the problem has been corrected.
E 2
I 2
once the problem has been corrected,
or the \fB\-r\fR option of the edit command
if you leave the editor and want to return.
E 2
.PP
If you make an undesirable change to the buffer
D 2
and issue a write command before discovering your mistake,
E 2
I 2
and type a write command before discovering your mistake,
E 2
the modified version will replace any previous version of the file.
Should you ever lose a good version of a document in this way,
do not panic and leave the editor.
As long as you stay in the editor,
the contents of the buffer remain accessible.
Depending on the nature of the problem,
it may be possible
to restore the buffer to a more complete
state with the undo command.
After fixing the damaged buffer, you can again write the file
to disk.
.SH
Further reading and other information
.PP
Edit is an editor designed for beginning and casual users.
It is actually a version of a more powerful editor called
.I ex.
These lessons are intended to introduce you to the editor
and its more commonly-used commands.
We have not covered all of the editor's commands,
D 2
just a selection of commands
which should be sufficient to accomplish most of your editing tasks.
E 2
I 2
but a selection of commands
that should be sufficient to accomplish most of your editing tasks.
E 2
You can find out more about the editor in the
.I
Ex Reference Manual,
.R
which is applicable to both
.I ex
and
.I edit.
D 2
The manual is available from the Computer Center Library,
E 2
I 2
D 3
The manual is available from the Computing Services Library,
E 2
218 Evans Hall.
E 3
One way to become familiar with the manual is to begin by reading
the description of commands that you already know.
.bd I 3
.SH
Using
.I ex
.fl
.bd I
.PP
As you become more experienced with using the editor,
you may still find that edit continues to meet your needs.
D 3
However, should you become interested in using ex,
E 3
I 3
However, should you become interested in using 
.I ex,
E 3
it is easy to switch.
D 3
To begin an editing session with ex,
E 3
I 3
To begin an editing session with 
.I ex,
E 3
use the name
.B ex
in your command instead of
.B edit.
.PP
D 3
Edit commands work the same way in ex,
E 3
I 3
Edit commands also work in 
.I ex,
E 3
but the editing environment is somewhat different.
You should be aware of a few differences
D 3
that exist between the two versions of the editor.
E 3
I 3
between 
.I ex
and 
.I edit.
E 3
In edit, only the characters ``^'', ``$'', and ``\\'' have
special meanings in searching the buffer
or indicating characters to be changed by a substitute command.
D 2
Several additional characters have ``magic''
E 2
I 2
Several additional characters have special
E 2
meanings in ex, as described in the
.I
Ex Reference Manual.
.R
Another feature of the edit environment prevents users from
accidently entering two alternative modes of editing,
.I open
and
.I visual,
in which
D 2
the editor behaves quite differently than in normal command mode.
E 2
I 2
the editor behaves quite differently from normal command mode.
E 2
D 3
If you are using ex and the editor behaves strangely,
E 3
I 3
If you are using ex and you encounter strange behavior,
E 3
you may have accidently entered open mode by typing ``o''.
D 2
Type the \s-2ESC\s0 key and then a ``q''
E 2
I 2
Type the \s-2ESC\s0 key and then a ``Q''
E 2
to get out of open or visual mode and back into
the regular editor command mode.
The document
.I
D 2
An Introduction to Display Editing with Vi
E 2
I 2
An Introduction to Display Editing with Vi\|\|
E 2
.R
D 3
provides a full discussion of visual mode.
E 3
I 3
provide full details of visual mode.
E 3
D 2
.sp 5
.bd I 3
.in +.7i
.ll -.7i
.nr LL -.7i
.LP
.I
This tutorial was produced at the Computer Center of the
University of California, Berkeley.
We welcome comments and suggestions concerning this item
and the \s-2UNIX\s0 documentation in general.
Contact the \s-2UNIX\s0 consultant in 217 Evans, 642-4072.
.fl
E 2
.bp
D 2
.bd I
.ND
.TL
Index
.sp 3
E 2
I 2
.SH
.ce 1
\s+2Index\s0
.LP
.sp 2
E 2
.2C
.nf
addressing, \fIsee\fR line numbers
D 2
append mode, 4
backslash (\\), 17
buffer, 1
command mode, 4
context search, 7, 9, 13, 17
control characters (``^'' notation), 7
control-d, 5
current filename, 18, 19
current line (.), 8, 14
diagnostic messages, 3
disk, 1
documentation, 20
edit (to begin editing session), 2, 6
E 2
I 2
ampersand, 20
append mode, 6-7
append (a) command, 6, 7, 9
``At end of file'' (message), 18
backslash (\\), 21
buffer, 3
caret (^), 10, 20
change (c) command, 18
command mode, 5-6
``Command not found'' (message), 6
context search, 10-12, 19-21
control characters (``^'' notation), 10
control-H, 7
copy (co) command, 15
corrections, 7, 16
current filename, 21
current line (\|.\|), 11, 17
delete (d) command, 15-16
dial-up, 5
disk, 3
documentation, 3, 23
dollar ($), 10, 11, 17, 20-21
dot (\f3\|.\|\f1) 11, 17
edit (text editor), 3, 5, 23
edit (e) command, 5, 9, 14
E 2
editing commands:
D 2
.in +2
append (a), 3, 4, 6
change (c), 15
copy (co), 12
delete (d), 12-13
edit (e), 11
file (f), 18
global (g), 16-17
move (m), 11-12
number (nu), 8
preserve (pre), 19
print (p), 7
quit (q), 5, 10
quit! (q!), 10
read (r), 18-19
recover (rec), 19
substitute (s), 8-9, 16, 17
undo (u), 13, 17
write (w), 4-5, 10, 19
z, 9
.sp 10i
! (shell escape), 18
$= , 14
+, 14
\-, 14
//, 7, 17
??, 17
\&\fB.\fR, 8, 14
\&\fB.\fR=, 8, 14
.in -2
E 2
I 2
.in +.25i
append (a), 6, 7, 9
change (c), 18
copy (co), 15
delete (d), 15-16
edit (text editor), 3, 5, 23
edit (e), 5, 9, 14
file (f), 21-22
global (g), 19
move (m), 14-15
number (nu), 11
preserve (pre), 22-23
print (p), 10
quit (q), 8, 13
read (r), 22
recover (rec), 22, 23
substitute (s), 11-12, 19, 20
undo (u), 16-17, 23
write (w), 8, 13, 21, 22
z, 12-13
! (shell escape), 21
$=, 17
+, 17
\-, 17
//, 12, 20
??, 20
\&., 11, 17
\&.=, 11, 17
.in -.25i
entering text, 3, 6-7
E 2
erasing
D 2
.ti +2
characters (#), 6
.ti +2
E 2
I 2
.in +.25i
characters (^H), 7
E 2
lines (@), 7
D 2
ex (text editor), 20
\fIEx Reference Manual\fR, 20
file, 1
file recovery, 19
filename, 1
Interrupt (message), 6
E 2
I 2
.in -.25i
error corrections, 7, 16
ex (text editor), 23
\fIEx Reference Manual\fR, 23
exclamation (!), 21
file, 3
file (f) command, 21-22
file recovery, 22-23
filename, 3, 21
global (g) command, 19
input mode, 6-7
Interrupt (message), 9
E 2
line numbers, \fIsee also\fR current line
D 2
.ti +2
dollar sign ($), 7, 14
.ti +2
dot (.), 8, 14
.ti +2
relative (+ and \-), 14
logging out, 5
login procedure, 2
``magic'' characters, 20
non-printing characters, 7
``not found'' (message), 3
program, 1
recovery \fIsee\fR file recovery
shell, 18
shell escape (!), 18
special characters (^, $, \e), 17
text input mode, 4
UNIX, 1
E 2
I 2
.in +.25i
dollar sign ($), 10, 11, 17
dot (\|.\|), 11, 17
relative (+ and \-), 17
.in -.25i
list, 10
logging in, 4-6
logging out, 8
``Login incorrect'' (message), 5
minus (\-), 17
move (m) command, 14-15
``Negative address\(emfirst buffer line is 1'' (message), 18
``No current filename'' (message), 8
``No such file or directory'' (message), 5, 6
``No write since last change'' (message), 21
non-printing characters, 10
``Nonzero address required'' (message), 18
``Not an editor command'' (message), 6
``Not that many lines in buffer'' (message), 18
number (nu) command, 11
password, 5
period (\|.\|), 11, 17
plus (+), 17
preserve (pre) command, 22-23
print (p) command, 10
program, 3
prompts
.in .25i
% (\s-2UNIX\s0), 5
: (edit), 5, 6, 7
\0 (append), 7
.in -.25i
question (?), 20
quit (q) command, 8, 13
read (r) command, 22
recover (rec) command, 22, 23
recovery, \fIsee\fR\| file recovery
references, 3, 23
remove (rm) command, 21, 22
reverse command effects (undo), 16-17, 23
searching, 10-12, 19-21
shell, 21
shell escape (!), 21
slash (/), 11-12, 20
special characters (^, $, \\), 10, 11, 17, 20-21
substitute (s) command, 11-12, 19, 20
terminals, 4-5
text input mode, 7
undo (u) command, 16-17, 23
\s-1UNIX\s0, 3
write (w) command, 8, 13, 21, 22
z command, 12-13

E 2
E 1

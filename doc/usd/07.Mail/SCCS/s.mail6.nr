h62343
s 00092/00000/00006
d D 6.1 86/05/23 12:00:57 kjd 3 2
c document distributed with 4.3BSD
e
s 00000/00163/00006
d D 5.1 86/05/23 12:00:51 kjd 2 1
c document distributed with 4.2BSD
e
s 00169/00000/00000
d D 4.1 86/05/23 12:00:45 kjd 1 0
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
.bp
.sh 1 "Command line options"
.pp
This section describes command line options for
.i Mail
and what they are used for.
.ip \-N
Suppress the initial printing of headers.
.ip \-d
Turn on debugging information.  Not of general interest.
.ip "\-f file"
Show the messages in
.i file
instead of your system mailbox.  If
.i file
is omitted,
.i Mail
reads
.i mbox
in your home directory.
.ip \-i
Ignore tty interrupt signals.  Useful on noisy phone lines, which
generate spurious RUBOUT or DELETE characters.  It's usually
more effective to change your interrupt character to control\-c,
for which see the
.i stty
shell command.
.ip \-n
Inhibit reading of /usr/lib/Mail.rc.  Not generally useful, since
/usr/lib/Mail.rc is usually empty.
.ip "\-s string"
Used for sending mail.
.i String
is used as the subject of the message being composed.  If
.i string
contains blanks, you must surround it with quote marks.
.ip "\-u name"
Read
.i names's
mail instead of your own.  Unwitting others often neglect to protect
their mailboxes, but discretion is advised. Essentially,
.b "\-u user"
is a shorthand way of doing
.b "\-f /usr/spool/user".
.ip "\-v"
Use the
.b \-v
flag when invoking sendmail. This feature may also be enabled
by setting the the option "verbose".
.pp
The following command line flags are also recognized, but are
intended for use by programs invoking
.i Mail
and not for people.
.ip "\-T file"
Arrange to print on
.i file
the contents of the
.i article-id
fields of all messages that were either read or deleted.
.b \-T
is for the
.i readnews
program and should NOT be used for reading your mail.
.ip "\-h number"
Pass on hop count information.
.i Mail
will take the number, increment it, and pass it with
.b \-h
to the mail delivery system.
.b \-h
only has effect when sending mail and is used for network mail
forwarding.
.ip "\-r name"
Used for network mail forwarding:  interpret
.i name
as the sender of the message.  The
.i name
and
.b \-r
are simply sent along to the mail delivery system.  Also,
.i Mail
will wait for the message to be sent and return the exit status.
Also restricts formatting of message.
.pp
Note that
.b \-h
and
.b \-r ,
which are for network mail forwarding, are not used in practice
since mail forwarding is now handled separately.  They may
disappear soon.
E 3
D 2
.sh 1 "Additional commands"
.pp
This section describes additional Mail commands available when
receiving mail.
.pp
The
.b next
command goes to the next message and types it.  If given a message list,
.b next
goes to the first such message and types it.  Thus,
.(l
type root
.)l
goes to the next message sent by \*(lqroot\*(rq and types it.
The
.b next
command can be abbreviated to simply a newline, which means that one
can go to and type a message by simply giving its message number or
one of the magic characters
.q "\(ua"
.q "."
or
.q "$".
Thus,
.(l
\&.
.)l
prints the current message and
.(l
4
.)l
prints message 4.
.pp
The
.rb \-
command goes to the previous message and prints it.  The
.rb \-
command may be given a decimal number
.i n
as an argument, in which case the
.i n th
previous message is gone to and printed.
.pp
The
.b save
command allows you to save messages received from others on a file
other than
.i mbox.
Its syntax varies somewhat from the other commands which accept
a message list in that the final word on the command line is taken to be
the file on which to save the messages.  The named messages are
appended to the file (which is created if it did not already exist)
and are marked as saved.  Saved messages are not automatically saved in
.i mbox
at quit time, nor are they selected by the
.b next
command described above, unless explicitly specified.  The
.b save
command provides a facility for saving messages pertaining to a particular
subject or from a particular person in a special place.
.pp
The
.b undelete
command causes a message which had been deleted previously to regain
its initial status.  Only messages which are already deleted may be
undeleted.  This command may be abbreviated to
.b u .
.pp
The
.b preserve
command takes a message list and marks each message therein so that it
will be saved in your system mailbox instead of being deleted or
saved in
.i mbox
when you quit.  This is useful for saving messages of importance that
you want to see again, or messages not intended for you if you are sharing
a login name.
.pp
Often, one wants to deal with a message by responding to its author right
then and there.  The
.b reply
command is useful for this purpose:  it takes a message list and sends mail
to the authors of those messages.  The message is collected in the usual
fashion by reading up to an EOT.  All of the tilde escapes described in section
three will work in
.b reply .
Additionally, if there are header fields
in the message being replied to, this information is copied into the
new message.  The
.b reply
command can be abbreviated to
.b r .
.pp
In order to simply mail to a user inside of Mail, the
.b mail
command is provided.  This sends mail in the manner described for the
.b reply
command above, except that the user supplies a list of recipient login
names and distribution groups.  All of the tilde escapes described in
section three will work in
.b mail .
The
.b mail
command may be abbreviated to
.b m .
.pp
In order to edit individual messages using the text editor, the
.b edit
command is provided.  The
.b edit
command takes a list of message as described under the
.b type
command and processes each by writing it into the file
Message\c
.i x
where
.i x
is the message number being edited and executing the text editor on it.
When you have edited the message to your satisfaction, write the message
out and quit, upon which Mail will read the message back and remove the file.
.b Edit
may be abbreviated to
.b e .
.pp
It is often useful to be able to invoke one of two editors,
based on the type of terminal one is using.  To invoke
a display oriented editor, you can use the
.b visual
command.  The operation of the
.b visual
command is otherwise identical to that of the
.b edit
command.
.pp
When Mail is invoked to receive mail, it prints out the message header
for each message.  In order to reprint the headers for remaining messages
(those which haven't been deleted), you may type the
.b headers
command.  Deleted messages do not appear in the listing, saved messages are
flagged with a
.q "*"
and preserved messages are flagged with a
\*(lqP.\*(rq
.pp
The
.b from
command takes a list of messages and prints out the header lines for each one;
hence
.(l
from joe
.)l
is the easy way to display all the message headers from \*(lqjoe.\*(rq
.pp
The
.b top
command takes a message list and prints the first five lines
of each addressed message.  It may be abbreviated to
.b to .
.pp
The
.b dt
command deletes the current message and prints the next message.
It is useful for quickly reading and disposing of mail.
E 2
E 1

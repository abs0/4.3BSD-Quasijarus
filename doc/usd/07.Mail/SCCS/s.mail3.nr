h18701
s 00100/00000/00006
d D 6.1 86/05/23 11:59:46 kjd 3 2
c document distributed with 4.3BSD
e
s 00000/00174/00006
d D 5.1 86/05/23 11:59:39 kjd 2 1
c document distributed with 4.2BSD
e
s 00180/00000/00000
d D 4.1 86/05/23 11:59:34 kjd 1 0
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
.sh 1 "Maintaining folders"
.pp
.i Mail
includes a simple facility for maintaining groups of messages together
in folders.  This section describes this facility.
.pp
To use the folder facility, you must tell
.i Mail
where you wish to keep your folders.  Each folder of messages will
be a single file.  For convenience, all of your folders are kept in
a single directory of your choosing.  To tell
.i Mail
where your folder directory is, put a line of the form
.(l
set folder=letters
.)l
in your
.i .mailrc
file.  If, as in the example above, your folder directory does not
begin with a `/,'
.i Mail
will assume that your folder directory is to be found starting from
your home directory.  Thus, if your home directory is
.b /usr/person
the above example told
.i Mail
to find your folder directory in
.b /usr/person/letters .
.pp
Anywhere a file name is expected, you can use a folder name, preceded
with `+.'  For example, to put a message into a folder with the
.b save
command, you can use:
.(l
save +classwork
.)l
to save the current message in the
.i classwork
folder.  If the
.i classwork
folder does not yet exist, it will be created.  Note that messages
which are saved with the
.b save
command are automatically removed from your system mailbox.
.pp
In order to make a copy of a message in a folder without causing
that message to be removed from your system mailbox, use the
.b copy
command, which is identical in all other respects to the
.b save
command.  For example,
.(l
copy +classwork
.)l
copies the current message into the
.i classwork
folder and leaves a copy in your system mailbox.
.pp
The
.b folder
command
can be used to direct
.i Mail
to the contents of a different folder.
For example,
.(l
folder +classwork
.)l
directs
.i Mail
to read the contents of the
.i classwork
folder.  All of the commands that you can use on your system
mailbox are also applicable to folders, including
.b type ,
.b delete ,
and
.b reply .
To inquire which folder you are currently editing, use simply:
.(l
folder
.)l
.pp
To list your current set of folders, use the
.b folders
command.
.pp
To start
.i Mail
reading one of your folders, you can use the
.b \-f
option described in section 2.  For example:
.(l
% Mail \-f +classwork
.)l
will cause
.i Mail
to read your
.i classwork
folder without looking at your system mailbox.
E 3
D 2
.sh 1 "Tilde escapes"
.pp
While typing in a message to be sent to others, it is often
useful to be able to invoke the text editor on the partial message,
print the message, execute a shell command, or perform some other
auxiliary function.  Mail provides these capabilities through
.i "tilde escapes" ,
which consist of a tilde (~) at the beginning of a line, followed by
a single character which indicates the function to be performed.  For
example, to print the text of the message so far, use:
.(l
~p
.)l
which will print a line of dashes, the recipients of your message, and
the text of the message so far.  If you are dissatisfied with the message as
it stands, you can invoke the text editor on it using the escape
.(l
~e
.)l
which causes the message to be copied into a temporary file and an
instance of the editor to be spawned.  After modifying the message to
your satisfaction, write it out and quit the editor.  Mail will respond
by typing
.(l
(continue)
.)l
after which you may continue typing text which will be appended to your
message, or type <control-d> to end the message.
.pp
It is often useful to be able to include the contents of some
file in your message; the escape
.(l
~r filename
.)l
is provided for this purpose, and causes the named file to be appended
to your current message.  Mail complains if the file doesn't exist
or can't be read.  If the read is successful, the number of lines and
characters appended to your message is printed, after which you may continue
appending text.
.pp
As a special case of ~r, the escape
.(l
~d
.)l
reads in the file
.q dead.letter
in your home directory.  This is often useful since Mail copies the text
of your message there when you abort a message with \s-2RUBOUT\s0.
.pp
In order to save the current text of your message on a file you may use the
.(l
~w filename
.)l
escape.  Mail will print out the number of lines and characters written
to the file, after which you may continue appending text to your message.
.pp
If you are sending mail from within Mail's command mode (read about the
.b reply
and
.b mail
commands, section six), you can read a message sent to you into the message
you are constructing with the escape:
.(l
~m 4
.)l
which will read message 4 into the current message, shifted right by
one tab stop.  You can name any non-deleted message, or list of messages.
This is the usual way to forward a message.
.pp
If, in the process of composing a message, you decide to add additional
people to the list of message recipients, you can do so with the escape
.(l
~t name1 name2 ...
.)l
You may name as few or many additional recipients as you wish.  Note
that the users originally on the recipient list will still receive
the message; in fact, you cannot remove someone from the recipient
list with ~t.
.pp
If you wish, you can associate a subject with your message by using the
escape
.(l
~s Arbitrary string of text
.)l
which replaces any previous subject with
.q "Arbitrary string of text."
The subject, if given, is sent near the
top of the message prefixed with
.q "Subj:"
You can see what the message will look like by using ~p.
.pp
For political reasons, one occasionally prefers to list certain
people as recipients of carbon copies of a message rather than
direct recipients.  The escape
.(l
~c name1 name2 ...
.)l
adds the named people to the
.q "Cc:"
list, similar to ~t.
Again, you can execute ~p to see what the message will look like.
.pp
The recipients of the message together constitute the
.q "To:"
field, the subject the
.q "Subj:"
field, and the carbon copies the
.q "Cc:"
field.  If you wish to edit these in ways impossible with the ~t, ~s,
and ~c escapes, you can use the escape
.(l
~h
.)l
which prints
.q "To:"
followed by the current list of recipients and leaves the cursor
(or printhead) at the end of the line.  If you type in ordinary
characters, they are appended to the end of the current list of
recipients.  You can also use your erase character to erase back into
the list of recipients, or your kill character to erase them altogether.
Thus, for example, if your erase and kill characters are the standard
# and @ symbols,
.(l
~h
To: root kurt####bill
.)l
would change the initial recipients
.q "root kurt"
to
.q "root bill."
When you type a newline, Mail advances to the
.q "Subj:"
field, where the same rules apply.  Another newline brings you to
the
.q "Cc:"
field, which may be edited in the same fashion.  Another newline
leaves you appending text to the end of your message.  You can use
~p to print the current text of the header fields and the body
of the message.
.pp
To effect a temporary escape to the shell, the escape
.(l
~!command
.)l
is used, which executes
.i command
and returns you to mailing mode without altering the text of
your message.  If you wish, instead, to filter the body of your
message through a shell command, then you can use
.(l
~|command
.)l
which pipes your message through the command and uses the output
as the new text of your message.  If the command produces no output,
Mail assumes that something is amiss and retains the old version
of your message.  A frequently-used filter is the command
.i fmt
which is designed to format outgoing mail.
.pp
If you wish (for some reason) to send a message which contains
a line beginning with a tilde, you must double it.  Thus, for example,
.(l
~~This line begins with a tilde.
.)l
sends the line
.(l
~This line begins with a tilde.
.)l
.pp
Finally, the escape
.(l
~?
.)l
prints out a brief summary of the available tilde escapes.
E 2
E 1

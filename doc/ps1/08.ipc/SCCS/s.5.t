h11950
s 00002/00002/01185
d D 1.5 88/01/06 10:29:13 karels 5 4
c SIOCATMARK returns int
e
s 00205/00146/00982
d D 1.4 86/05/02 17:40:39 karels 4 3
c corrections
e
s 00062/00041/01066
d D 1.3 86/04/30 12:28:40 karels 3 2
c newer stuff from phil
e
s 00906/00147/00201
d D 1.2 86/04/30 11:22:21 karels 2 1
c updates for 4.3 from lapsley
e
s 00348/00000/00000
d D 1.1 86/04/30 11:19:04 karels 1 0
c 4.2BSD version
e
u
U
t
T
I 2
.\" Copyright (c) 1986 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
E 2
I 1
D 4
.ds RH "Advanced Topics
E 4
I 4
.\".ds RH "Advanced Topics
E 4
.bp
.nr H1 5
.nr H2 0
D 4
.bp
E 4
.LG
.B
.ce
5. ADVANCED TOPICS
.sp 2
.R
.NL
.PP
A number of facilities have yet to be discussed.  For most users
D 2
of the ipc the mechanisms already
E 2
I 2
of the IPC the mechanisms already
E 2
described will suffice in constructing distributed
D 2
applications.  However, others will find need to utilize some
E 2
I 2
applications.  However, others will find the need to utilize some
E 2
of the features which we consider in this section.
.NH 2
Out of band data
.PP
The stream socket abstraction includes the notion of \*(lqout
of band\*(rq data.  Out of band data is a logically independent 
transmission channel associated with each pair of connected
stream sockets.  Out of band data is delivered to the user
D 2
independently of normal data along with the SIGURG signal.
E 2
I 2
D 4
independently of normal data along with the SIGURG signal
(if multiple sockets may have out of band data awaiting
delivery, a \fIselect\fP call may be used to determine those
sockets with such data).  A process can set the process group
or process id to be informed by the SIGURG signal via the
appropriate \fIfcntl\fP call, as described below for
SIGIO.
.PP
E 2
In addition to the information passed, a logical mark is placed in
the data stream to indicate the point at which the out
of band data was sent.  The remote login and remote shell
D 2
applications use this facility to propagate signals from between
E 2
I 2
applications use this facility to propagate signals between
E 2
client and server processes.  When a signal is expected to
flush any pending output from the remote process(es), all
data up to the mark in the data stream is discarded.
.PP
The
stream abstraction defines that the out of band data facilities
E 4
I 4
independently of normal data.
The abstraction defines that the out of band data facilities
E 4
must support the reliable delivery of at least one
out of band message at a time.  This message may contain at least one
byte of data, and at least one message may be pending delivery
to the user at any one time.  For communications protocols which
support only in-band signaling (i.e. the urgent data is
D 2
delivered in sequence with the normal data) the system extracts
E 2
I 2
D 4
delivered in sequence with the normal data), the system extracts
E 4
I 4
delivered in sequence with the normal data), the system normally extracts
E 4
E 2
the data from the normal data stream and stores it separately.
This allows users to choose between receiving the urgent data
in order and receiving it out of sequence without having to
D 2
buffer all the intervening data.
E 2
I 2
D 4
buffer all the intervening data.  It is not possible
E 4
I 4
buffer all the intervening data.  It is possible
E 4
to ``peek'' (via MSG_PEEK) at out of band data.
I 4
If the socket has a process group, a SIGURG signal is generated
when the protocol is notified of its existence.
A process can set the process group
or process id to be informed by the SIGURG signal via the
appropriate \fIfcntl\fP call, as described below for
SIGIO.
If multiple sockets may have out of band data awaiting
delivery, a \fIselect\fP call for exceptional conditions
may be used to determine those sockets with such data pending.
Neither the signal nor the select indicate the actual arrival
of the out-of-band data, but only notification that it is pending.
E 4
E 2
.PP
I 4
In addition to the information passed, a logical mark is placed in
the data stream to indicate the point at which the out
of band data was sent.  The remote login and remote shell
applications use this facility to propagate signals between
client and server processes.  When a signal
flushs any pending output from the remote process(es), all
data up to the mark in the data stream is discarded.
.PP
E 4
D 2
To send an out of band message the SOF_OOB flag is supplied to
E 2
I 2
To send an out of band message the MSG_OOB flag is supplied to
E 2
a \fIsend\fP or \fIsendto\fP calls,
D 2
while to receive out of band data SOF_OOB should be indicated
E 2
I 2
while to receive out of band data MSG_OOB should be indicated
E 2
when performing a \fIrecvfrom\fP or \fIrecv\fP call.
To find out if the read pointer is currently pointing at
the mark in the data stream, the SIOCATMARK ioctl is provided:
.DS
ioctl(s, SIOCATMARK, &yes);
.DE
If \fIyes\fP is a 1 on return, the next read will return data
after the mark.  Otherwise (assuming out of band data has arrived), 
the next read will provide data sent by the client prior
to transmission of the out of band signal.  The routine used
in the remote login process to flush output on receipt of an
interrupt or quit signal is shown in Figure 5.
I 4
It reads the normal data up to the mark (to discard it),
then reads the out-of-band byte.
E 4
.KF
.DS
I 2
#include <sys/ioctl.h>
#include <sys/file.h>
 ...
E 2
oob()
{
D 2
	int out = 1+1;
E 2
I 2
D 5
	int out = FWRITE;
E 2
	char waste[BUFSIZ], mark;
E 5
I 5
	int out = FWRITE, mark;
	char waste[BUFSIZ];
E 5

D 2
	signal(SIGURG, oob);
	/* flush local terminal input and output */
E 2
I 2
	/* flush local terminal output */
E 2
	ioctl(1, TIOCFLUSH, (char *)&out);
	for (;;) {
		if (ioctl(rem, SIOCATMARK, &mark) < 0) {
			perror("ioctl");
			break;
		}
		if (mark)
			break;
		(void) read(rem, waste, sizeof (waste));
	}
D 2
	recv(rem, &mark, 1, SOF_OOB);
E 2
I 2
	if (recv(rem, &mark, 1, MSG_OOB) < 0) {
		perror("recv");
		...
	}
E 2
	...
}
.DE
.ce
D 4
Figure 5.  Flushing terminal i/o on receipt of out of band data.
E 4
I 4
Figure 5.  Flushing terminal I/O on receipt of out of band data.
E 4
.sp
.KE
I 4
.PP
A process may also read or peek at the out-of-band data
without first reading up to the mark.
This is more difficult when the underlying protocol delivers
the urgent data in-band with the normal data, and only sends
notification of its presence ahead of time (e.g., the TCP protocol
used to implement streams in the Internet domain).
With such protocols, the out-of-band byte may not yet have arrived
when a \fIrecv\fP is done with the MSG_OOB flag.
In that case, the call will return an error of EWOULDBLOCK.
Worse, there may be enough in-band data in the input buffer
that normal flow control prevents the peer from sending the urgent data
until the buffer is cleared.
The process must then read enough of the queued data
that the urgent data may be delivered.
.PP
Certain programs that use multiple bytes of urgent data and must
handle multiple urgent signals (e.g., \fItelnet\fP\|(1C))
need to retain the position of urgent data within the stream.
This treatment is available as a socket-level option, SO_OOBINLINE;
see \fIsetsockopt\fP\|(2) for usage.
With this option, the position of urgent data (the \*(lqmark\*(rq)
is retained, but the urgent data immediately follows the mark
within the normal data stream returned without the MSG_OOB flag.
Reception of multiple urgent indications causes the mark to move,
but no out-of-band data are lost.
E 4
.NH 2
I 2
D 4
Interrupt driven socket i/o
E 4
I 4
Non-Blocking Sockets
E 4
.PP
I 4
It is occasionally convenient to make use of sockets
which do not block; that is, I/O requests which
cannot complete immediately and
would therefore cause the process to be suspended awaiting completion are
not executed, and an error code is returned.
Once a socket has been created via
the \fIsocket\fP call, it may be marked as non-blocking
by \fIfcntl\fP as follows:
.DS
#include <fcntl.h>
 ...
int	s;
 ...
s = socket(AF_INET, SOCK_STREAM, 0);
 ...
if (fcntl(s, F_SETFL, FNDELAY) < 0)
	perror("fcntl F_SETFL, FNDELAY");
	exit(1);
}
 ...
.DE
.PP
When performing non-blocking I/O on sockets, one must be
careful to check for the error EWOULDBLOCK (stored in the
global variable \fIerrno\fP), which occurs when
an operation would normally block, but the socket it
was performed on is marked as non-blocking.
In particular, \fIaccept\fP, \fIconnect\fP, \fIsend\fP, \fIrecv\fP,
\fIread\fP, and \fIwrite\fP can
all return EWOULDBLOCK, and processes should be prepared
to deal with such return codes.
If an operation such as a \fIsend\fP cannot be done in its entirety,
but partial writes are sensible (for example, when using a stream socket),
the data that can be sent immediately will be processed,
and the return value will indicate the amount actually sent.
.NH 2
Interrupt driven socket I/O
.PP
E 4
The SIGIO signal allows a process to be notified
via a signal when a socket (or more generally, a file
descriptor) has data waiting to be read.  Use of
the SIGIO facility requires three steps:  First,
the process must set up a SIGIO signal handler
D 4
by use of the \fIsignal\fP call.  Second,
E 4
I 4
by use of the \fIsignal\fP or \fIsigvec\fP calls.  Second,
E 4
it must set the process id or process group id which is to receive
notification of pending input to its own process id,
or the process group id of its process group (note that
the default process group of a socket is group zero).
D 4
This is accomplished by use of a \fIfcntl\fP call.
Third, it must turn on notification of pending i/o requests
E 4
I 4
This is accomplished by use of an \fIfcntl\fP call.
Third, it must enable asynchronous notification of pending I/O requests
E 4
with another \fIfcntl\fP call.  Sample code to
allow a given process to receive information on
D 4
pending i/o requests as they occur for a socket \fIs\fP
is given in Figure 6.  With slight change, this code can also
be used to prepare for receipt of SIGURG signals.
E 4
I 4
pending I/O requests as they occur for a socket \fIs\fP
is given in Figure 6.  With the addition of a handler for SIGURG,
this code can also be used to prepare for receipt of SIGURG signals.
E 4
.KF
.DS
#include <fcntl.h>
 ...
int	io_handler();
 ...
signal(SIGIO, io_handler);

/* Set the process receiving SIGIO/SIGURG signals to us */

if (fcntl(s, F_SETOWN, getpid()) < 0) {
	perror("fcntl F_SETOWN");
	exit(1);
}

D 4
/* Allow receipt of asynchronous i/o signals */
E 4
I 4
/* Allow receipt of asynchronous I/O signals */
E 4

if (fcntl(s, F_SETFL, FASYNC) < 0) {
	perror("fcntl F_SETFL, FASYNC");
	exit(1);
}
.DE
.ce
D 4
Figure 6.  Use of asynchronous notification of i/o requests.
E 4
I 4
Figure 6.  Use of asynchronous notification of I/O requests.
E 4
.sp
.KE
.NH 2
E 2
Signals and process groups
.PP
Due to the existence of the SIGURG and SIGIO signals each socket has an
D 2
associated process group (just as is done for terminals).
This process group is initialized to the process group of its
creator, but may be redefined at a later time with the SIOCSPGRP
ioctl:
E 2
I 2
associated process number, just as is done for terminals.
This value is initialized to zero,
but may be redefined at a later time with the F_SETOWN
\fIfcntl\fP, such as was done in the code above for SIGIO.
To set the socket's process id for signals, positive arguments
should be given to the \fIfcntl\fP call.  To set the socket's
process group for signals, negative arguments should be 
passed to \fIfcntl\fP.  Note that the process number indicates
either the associated process id or the associated process
group; it is impossible to specify both at the same time.
A similar \fIfcntl\fP, F_GETOWN, is available for determining the
current process number of a socket.
.PP
D 4
An old signal which is useful when constructing server processes
E 4
I 4
Another signal which is useful when constructing server processes
E 4
is SIGCHLD.  This signal is delivered to a process when any
D 4
children processes have changed state.  Normally servers use
the signal to \*(lqreap\*(rq child processes after exiting.
E 4
I 4
child processes have changed state.  Normally servers use
the signal to \*(lqreap\*(rq child processes that have exited
without explicitly awaiting their termination
or periodic polling for exit status.
E 4
For example, the remote login server loop shown in Figure 2
may be augmented as shown in Figure 7.
.KF
E 2
.DS
D 2
ioctl(s, SIOCSPGRP, &pgrp);
E 2
I 2
int reaper();
 ...
signal(SIGCHLD, reaper);
listen(f, 5);
for (;;) {
	int g, len = sizeof (from);

	g = accept(f, (struct sockaddr *)&from, &len,);
	if (g < 0) {
		if (errno != EINTR)
			syslog(LOG_ERR, "rlogind: accept: %m");
		continue;
	}
	...
}
 ...
#include <wait.h>
reaper()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
}
E 2
.DE
D 2
A similar ioctl, SIOCGPGRP, is available for determining the
current process group of a socket.
E 2
I 2
.sp
.ce
Figure 7.  Use of the SIGCHLD signal.
.sp
.KE
.PP
If the parent server process fails to reap its children,
a large number of \*(lqzombie\*(rq processes may be created.
E 2
.NH 2
Pseudo terminals
.PP
Many programs will not function properly without a terminal
D 4
for standard input and output.  Since a socket is not a terminal,
E 4
I 4
for standard input and output.  Since sockets do not provide
the semantics of terminals,
E 4
it is often necessary to have a process communicating over
D 4
the network do so through a \fIpseudo terminal\fP.  A pseudo
E 4
I 4
the network do so through a \fIpseudo-terminal\fP.  A pseudo-
E 4
terminal is actually a pair of devices, master and slave,
which allow a process to serve as an active agent in communication
between processes and users.  Data written on the slave side
D 4
of a pseudo terminal is supplied as input to a process reading
D 2
from the master side.  Data written on the master side is
given the slave as input.  In this way, the process manipulating
E 2
I 2
from the master side, while data written on the master side is
given to the slave as input.  In this way, the process manipulating
E 2
the master side of the pseudo terminal has control over the
D 2
information read and written on the slave side.  The remote
E 2
I 2
information read and written on the slave side.
E 4
I 4
of a pseudo-terminal is supplied as input to a process reading
from the master side, while data written on the master side are
processed as terminal input for the slave.
In this way, the process manipulating
the master side of the pseudo-terminal has control over the
information read and written on the slave side
as if it were manipulating the keyboard and reading the screen
on a real terminal.
E 4
The purpose of this abstraction is to
D 4
preserve terminal semantics over a network connection \(em
that is, the slave side looks like a normal terminal to
E 4
I 4
preserve terminal semantics over a network connection\(em
that is, the slave side appears as a normal terminal to
E 4
any process reading from or writing to it.
.PP
For example, the remote
E 2
D 4
login server uses pseudo terminals for remote login sessions.
E 4
I 4
login server uses pseudo-terminals for remote login sessions.
E 4
A user logging in to a machine across the network is provided
D 4
a shell with a slave pseudo terminal as standard input, output,
E 4
I 4
a shell with a slave pseudo-terminal as standard input, output,
E 4
and error.  The server process then handles the communication
between the programs invoked by the remote shell and the user's
D 4
local client process.  When a user sends an interrupt or quit
signal to a process executing on a remote machine, the client
login program traps the signal, sends an out of band message
to the server process who then uses the signal number, sent
as the data value in the out of band message, to perform a
\fIkillpg\fP(2) on the appropriate process group.  
E 4
I 4
local client process.
When a user sends a character that generates an interrupt
on the remote machine that flushes terminal output,
the pseudo-terminal generates a control message for the server process.
The server then sends an out of band message
to the client process to signal a flush of data at the real terminal
and on the intervening data buffered in the network.
E 4
I 2
.PP
D 4
Under 4.3BSD, the slave side of a pseudo terminal is
E 4
I 4
Under 4.3BSD, the name of the slave side of a pseudo-terminal is of the form
E 4
\fI/dev/ttyxy\fP, where \fIx\fP is a single letter
D 4
starting at `p' and perhaps continuing as far down
as `t'.  \fIy\fP is a hexidecimal ``digit'' (i.e., a single
E 4
I 4
starting at `p' and continuing to `t'.
\fIy\fP is a hexadecimal digit (i.e., a single
E 4
character in the range 0 through 9 or `a' through `f').
D 4
The master side of a pseudo terminal is \fI/dev/ptyxy\fP,
where \fIx\fP and \fIy\fP correspond to the same letters
in the slave side of the pseudo terminal.
E 4
I 4
The master side of a pseudo-terminal is \fI/dev/ptyxy\fP,
where \fIx\fP and \fIy\fP correspond to the
slave side of the pseudo-terminal.
E 4
.PP
In general, the method of obtaining a pair of master and
D 4
slave pseudo terminals is made up of three components.
First, the process must find a pseudo terminal which
is not currently in use.  Having done so,
it then opens both the master and the slave side of
the device, taking care to open the master side of the device first.
E 4
I 4
slave pseudo-terminals is to
find a pseudo-terminal which
is not currently in use.
The master half of a pseudo-terminal is a single-open device;
thus, each master may be opened in turn until an open succeeds.
The slave side of the pseudo-terminal is then opened,
and is set to the proper terminal modes if necessary.
E 4
The process then \fIfork\fPs; the child closes
D 4
the master side of the pseudo terminal, and \fIexec\fPs the
E 4
I 4
the master side of the pseudo-terminal, and \fIexec\fPs the
E 4
appropriate program.  Meanwhile, the parent closes the
D 4
slave side of the pseudo terminal and begins reading and
E 4
I 4
slave side of the pseudo-terminal and begins reading and
E 4
writing from the master side.  Sample code making use of
D 4
pseudo terminals is given in Figure 8; this code assumes
E 4
I 4
pseudo-terminals is given in Figure 8; this code assumes
E 4
that a connection on a socket \fIs\fP exists, connected
to a peer who wants a service of some kind, and that the
D 4
process has disassociated itself from a controlling terminal.
E 4
I 4
process has disassociated itself from any previous controlling terminal.
E 4
.KF
.DS
gotpty = 0;
for (c = 'p'; !gotpty && c <= 's'; c++) {
	line = "/dev/ptyXX";
	line[sizeof("/dev/pty")-1] = c;
	line[sizeof("/dev/ptyp")-1] = '0';
	if (stat(line, &statbuf) < 0)
		break;
	for (i = 0; i < 16; i++) {
		line[sizeof("/dev/ptyp")-1] = "0123456789abcdef"[i];
		master = open(line, O_RDWR);
		if (master > 0) {
			gotpty = 1;
			break;
		}
	}
}
if (!gotpty) {
	syslog(LOG_ERR, "All network ports in use");
	exit(1);
}

line[sizeof("/dev/")-1] = 't';
slave = open(line, O_RDWR);	/* \fIslave\fP is now slave side */
if (slave < 0) {
	syslog(LOG_ERR, "Cannot open slave pty %s", line);
	exit(1);
}

ioctl(slave, TIOCGETP, &b);	/* Set slave tty modes */
b.sg_flags = CRMOD|XTABS|ANYP;
ioctl(slave, TIOCSETP, &b);

i = fork();
if (i < 0) {
	syslog(LOG_ERR, "fork: %m");
	exit(1);
} else if (i) {		/* Parent */
	close(slave);
	...
} else {		 /* Child */
	(void) close(s);
	(void) close(master);
	dup2(slave, 0);
	dup2(slave, 1);
	dup2(slave, 2);
	if (slave > 2)
		(void) close(slave);
	...
}
.DE
.ce
Figure 8.  Creation and use of a pseudo terminal
.sp
.KE
E 2
.NH 2
D 2
Internet address binding
E 2
I 2
Selecting specific protocols
E 2
.PP
D 2
Binding addresses to sockets in the Internet domain can be
fairly complex.  Communicating processes are bound
by an \fIassociation\fP.  An association 
is composed of local and foreign
addresses, and local and foreign ports.  Port numbers are
allocated out of separate spaces, one for each Internet
protocol.  Associations are always unique.  That is, there
may never be duplicate <protocol, local address, local port, foreign
address, foreign port> tuples. 
E 2
I 2
If the third argument to the \fIsocket\fP call is 0,
\fIsocket\fP will select a default protocol to use with
D 4
the returned socket of the type requested.  This
protocol should be correct for almost every situation.
Still, it is conceivable that the user may wish to specify
a particular protocol for use with a given socket.
E 2
.PP
D 2
The bind system call allows a process to specify half of
an association, <local address, local port>, while the connect
and accept primitives are used to complete a socket's association.
E 2
I 2
To obtain a particular protocol one selects the protocol number,
E 4
I 4
the returned socket of the type requested.
The default protocol is usually correct, and alternate choices are not
usually available.
However, when using ``raw'' sockets to communicate directly with
lower-level protocols or hardware interfaces,
the protocol argument may be important for setting up demultiplexing.
For example, raw sockets in the Internet family may be used to implement
a new protocol above IP, and the socket will receive packets
only for the protocol specified.
To obtain a particular protocol one determines the protocol number
E 4
as defined within the communication domain.  For the Internet
D 4
domain the available protocols are defined in <\fInetinet/in.h\fP>
or, better yet, one may use one of the library routines
E 4
I 4
domain one may use one of the library routines
E 4
discussed in section 3, such as \fIgetprotobyname\fP:
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
 ...
pp = getprotobyname("newtcp");
s = socket(AF_INET, SOCK_STREAM, pp->p_proto);
.DE
This would result in a socket \fIs\fP using a stream
based connection, but with protocol type of ``newtcp''
instead of the default ``tcp.''
.PP
In the NS domain, the available socket protocols are defined in
<\fInetns/ns.h\fP>.  To create a raw socket for Xerox Error Protocol
messages, one might use:
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
 ...
s = socket(AF_NS, SOCK_RAW, NSPROTO_ERROR);
.DE
.NH 2
Address binding
.PP
As was mentioned in section 2, 
binding addresses to sockets in the Internet and NS domains can be
fairly complex.  As a brief reminder, these associations
are composed of local and foreign
addresses, and local and foreign ports.  Port numbers are
allocated out of separate spaces, one for each system and one
for each domain on that system.
Through the \fIbind\fP system call, a
process may specify half of an association, the
<local address, local port> part, while the
\fIconnect\fP
and \fIaccept\fP
primitives are used to complete a socket's association by
specifying the <foreign address, foreign port> part.
E 2
Since the association is created in two steps the association
D 2
uniqueness requirement indicated above could be violated unless
E 2
I 2
uniqueness requirement indicated previously could be violated unless
E 2
care is taken.  Further, it is unrealistic to expect user
programs to always know proper values to use for the local address
and local port since a host may reside on multiple networks and
the set of allocated port numbers is not directly accessible
to a user.
.PP
D 2
To simplify local address binding the notion of a
E 2
I 2
To simplify local address binding in the Internet domain the notion of a
E 2
\*(lqwildcard\*(rq address has been provided.  When an address
is specified as INADDR_ANY (a manifest constant defined in
<netinet/in.h>), the system interprets the address as 
\*(lqany valid address\*(rq.  For example, to bind a specific
port number to a socket, but leave the local address unspecified,
the following code might be used:
.DS
#include <sys/types.h>
#include <netinet/in.h>
 ...
struct sockaddr_in sin;
 ...
s = socket(AF_INET, SOCK_STREAM, 0);
sin.sin_family = AF_INET;
D 2
sin.sin_addr.s_addr = INADDR_ANY;
sin.sin_port = MYPORT;
bind(s, (char *)&sin, sizeof (sin));
E 2
I 2
sin.sin_addr.s_addr = htonl(INADDR_ANY);
sin.sin_port = htons(MYPORT);
bind(s, (struct sockaddr *) &sin, sizeof (sin));
E 2
.DE
Sockets with wildcarded local addresses may receive messages
D 4
directed to the specified port number, and addressed to any
E 4
I 4
directed to the specified port number, and sent to any
E 4
D 2
of the possible addresses assigned a host.  For example,
if a host is on a networks 46 and 10 and a socket is bound as
E 2
I 2
of the possible addresses assigned to a host.  For example,
D 4
if a host is on a networks 128.32 and 10 and a socket is bound as
E 2
above, then an accept call is performed, the process will be
able to accept connection requests which arrive either from
D 2
network 46 or network 10.
E 2
I 2
network 128.32 or network 10.
E 4
I 4
if a host has addresses 128.32.0.4 and 10.0.0.78, and a socket is bound as
above, the process will be
able to accept connection requests which are addressed to
128.32.0.4 or 10.0.0.78.
E 4
If a server process wished to only allow hosts on a
given network connect to it, it would bind
D 4
the address of the host on the appropriate network.  Such
an address could perhaps be determined by a routine
such as \fIgethostbynameandnet\fP, as mentioned in section 3.
E 4
I 4
the address of the host on the appropriate network.
E 4
E 2
.PP
In a similar fashion, a local port may be left unspecified
(specified as zero), in which case the system will select an
D 2
appropriate port number for it.  For example:
E 2
I 2
appropriate port number for it.  This shortcut will work
both in the Internet and NS domains.  For example, to
bind a specific local address to a socket, but to leave the
local port number unspecified:
E 2
.DS
D 2
sin.sin_addr.s_addr = MYADDRESS;
sin.sin_port = 0;
bind(s, (char *)&sin, sizeof (sin));
E 2
I 2
hp = gethostbyname(hostname);
if (hp == NULL) {
	...
}
bcopy(hp->h_addr, (char *) sin.sin_addr, hp->h_length);
sin.sin_port = htons(0);
bind(s, (struct sockaddr *) &sin, sizeof (sin));
E 2
.DE
D 2
The system selects the port number based on two criteria.
The first is that ports numbered 0 through 1023 are reserved
for privileged users (i.e. the super user).  The second is
E 2
I 2
The system selects the local port number based on two criteria.
The first is that on 4BSD systems,
D 4
local ports numbered 0 through 1023 (for the Xerox domain,
E 4
I 4
Internet ports below IPPORT_RESERVED (1024) (for the Xerox domain,
E 4
0 through 3000) are reserved
D 4
for privileged users (i.e., the super user).  The second is
E 4
I 4
for privileged users (i.e., the super user);
Internet ports above IPPORT_USERRESERVED (50000) are reserved
for non-privileged servers.  The second is
E 4
E 2
that the port number is not currently bound to some other
D 2
socket.  In order to find a free port number in the privileged
range the following code is used by the remote shell server:
E 2
I 2
socket.  In order to find a free Internet port number in the privileged
range the \fIrresvport\fP library routine may be used as follows
to return a stream socket in with a privileged port number:
E 2
.DS
D 2
struct sockaddr_in sin;
 ...
lport = IPPORT_RESERVED \- 1;
sin.sin_addr.s_addr = INADDR_ANY;
 ...
for (;;) {
	sin.sin_port = htons((u_short)lport);
	if (bind(s, (caddr_t)&sin, sizeof (sin)) >= 0)
		break;
	if (errno != EADDRINUSE && errno != EADDRNOTAVAIL) {
		perror("socket");
		break;
	}
	lport--;
	if (lport == IPPORT_RESERVED/2) {
		fprintf(stderr, "socket: All ports in use\en");
		break;
	}
E 2
I 2
int lport = IPPORT_RESERVED \- 1;
int s;
...
s = rresvport(&lport);
if (s < 0) {
	if (errno == EAGAIN)
		fprintf(stderr, "socket: all ports in use\en");
	else
		perror("rresvport: socket");
	...
E 2
}
.DE
The restriction on allocating ports was done to allow processes
executing in a \*(lqsecure\*(rq environment to perform authentication
D 2
based on the originating address and port number.
E 2
I 2
based on the originating address and port number.  For example,
the \fIrlogin\fP(1) command allows users to log in across a network
without being asked for a password, if two conditions hold:
First, the name of the system the user
is logging in from is in the file
\fI/etc/hosts.equiv\fP on the system he is logging
in to (or the system name and the user name are in
the user's \fI.rhosts\fP file in the user's home
directory), and second, that the user's rlogin
D 4
process is coming from a privileged port on the machine he is
logging in from.  The port number and network address of the
machine the user is logging in from can be determined either
by the \fIfrom\fP value-result parameter to the \fIaccept\fP call, or
E 4
I 4
process is coming from a privileged port on the machine from which he is
logging.  The port number and network address of the
machine from which the user is logging in can be determined either
by the \fIfrom\fP result of the \fIaccept\fP call, or
E 4
from the \fIgetpeername\fP call.
E 2
.PP
In certain cases the algorithm used by the system in selecting
D 4
port numbers is unsuitable for an application.  This is due to
associations being created in a two step process.  For example,
E 4
I 4
port numbers is unsuitable for an application.  This is because
associations are created in a two step process.  For example,
E 4
the Internet file transfer protocol, FTP, specifies that data
connections must always originate from the same local port.  However,
duplicate associations are avoided by connecting to different foreign
ports.  In this situation the system would disallow binding the
same local address and port number to a socket if a previous data
D 4
connection's socket were around.  To override the default port
selection algorithm then an option call must be performed prior
E 4
I 4
connection's socket still existed.  To override the default port
selection algorithm, an option call must be performed prior
E 4
to address binding:
.DS
D 2
setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *)0, 0);
bind(s, (char *)&sin, sizeof (sin));
E 2
I 2
 ...
int	on = 1;
 ...
setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
bind(s, (struct sockaddr *) &sin, sizeof (sin));
E 2
.DE
With the above call, local addresses may be bound which
are already in use.  This does not violate the uniqueness
requirement as the system still checks at connect time to
be sure any other sockets with the same local address and
D 4
port do not have the same foreign address and port (if an
association already exists, the error EADDRINUSE is returned).
E 4
I 4
port do not have the same foreign address and port.
If the association already exists, the error EADDRINUSE is returned.
E 4
D 2
.PP
Local address binding by the system is currently
done somewhat haphazardly when a host is on multiple
networks.  Logically, one would expect
the system to bind the local address associated with
the network through which a peer was communicating.
For instance, if the local host is connected to networks
46 and 10 and the foreign host is on network 32, and
traffic from network 32 were arriving via network
10, the local address to be bound would be the host's address
on network 10, not network 46.  This unfortunately, is
not always the case.  For reasons too complicated to discuss
here, the local address bound may be appear to be chosen
at random.  This property of local address binding
will normally be invisible to users unless the foreign
host does not understand how to reach the address
selected*.
.FS
* For example, if network 46 were unknown to the host on
network 32, and the local address were bound to that located
on network 46, then even though a route between the two hosts
existed through network 10, a connection would fail.
.FE
E 2
.NH 2
D 4
Broadcasting and datagram sockets
E 4
I 4
Broadcasting and determining network configuration
E 4
.PP
D 4
By using a datagram socket it is possible to send broadcast
packets on many networks supported by the system (the network
itself must support the notion of broadcasting; the system
provides no broadcast simulation in software).  Broadcast
messages can place a high load on a network since they force
E 4
I 4
By using a datagram socket, it is possible to send broadcast
packets on many networks supported by the system.
The network itself must support broadcast; the system
provides no simulation of broadcast in software.
Broadcast messages can place a high load on a network since they force
E 4
every host on the network to service them.  Consequently,
D 2
the ability to send broadcast packets has been limited to
the super user.
E 2
I 2
the ability to send broadcast packets has been limited
to sockets which are explicitly marked as allowing broadcasting.
I 4
Broadcast is typically used for one of two reasons:
it is desired to find a resource on a local network without prior
knowledge of its address,
or important functions such as routing require that information
be sent to all accessible neighbors.
E 4
E 2
.PP
D 2
To send a broadcast message, an Internet datagram socket 
E 2
I 2
To send a broadcast message, a datagram socket 
E 2
should be created:
.DS
s = socket(AF_INET, SOCK_DGRAM, 0);
.DE
I 2
or
.DS
s = socket(AF_NS, SOCK_DGRAM, 0);
.DE
The socket is marked as allowing broadcasting,
.DS
int	on = 1;

setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof (on));
.DE
E 2
and at least a port number should be bound to the socket:
.DS
sin.sin_family = AF_INET;
D 2
sin.sin_addr.s_addr = INADDR_ANY;
sin.sin_port = MYPORT;
bind(s, (char *)&sin, sizeof (sin));
E 2
I 2
sin.sin_addr.s_addr = htonl(INADDR_ANY);
sin.sin_port = htons(MYPORT);
bind(s, (struct sockaddr *) &sin, sizeof (sin));
E 2
.DE
D 2
Then the message should be addressed as:
E 2
I 2
or, for the NS domain,
E 2
.DS
D 2
dst.sin_family = AF_INET;
dst.sin_addr.s_addr = INADDR_ANY;
dst.sin_port = DESTPORT;
E 2
I 2
sns.sns_family = AF_NS;
netnum = htonl(net);
sns.sns_addr.x_net = *(union ns_net *) &netnum; /* insert net number */
sns.sns_addr.x_port = htons(MYPORT);
bind(s, (struct sockaddr *) &sns, sizeof (sns));
E 2
.DE
D 2
and, finally, a sendto call may be used:
E 2
I 2
The destination address of the message to be broadcast
D 4
depends on the network the message is to be broadcast
on, and therefore requires some knowledge of the networks
to which the host is connected.  Since this information should
be obtained in a host-independent fashion, 4.3BSD provides a method of
E 4
I 4
depends on the network(s) on which the message is to be broadcast.
The Internet domain supports a shorthand notation for broadcast
on the local network, the address INADDR_BROADCAST (defined in
<\fInetinet/in.h\fP>.
To determine the list of addresses for all reachable neighbors
requires knowledge of the networks to which the host is connected.
Since this information should
be obtained in a host-independent fashion and may be impossible
to derive, 4.3BSD provides a method of
E 4
retrieving this information from the system data structures.
The SIOCGIFCONF \fIioctl\fP call returns the interface
configuration of a host in the form of a
single \fIifconf\fP structure; this structure contains
a ``data area'' which is made up of an array of
of \fIifreq\fP structures, one for each network interface
to which the host is connected.
These structures are defined in
\fI<net/if.h>\fP as follows:
E 2
.DS
D 2
sendto(s, buf, buflen, 0, &dst, sizeof (dst));
E 2
I 2
.if t .ta .5i 1.0i 1.5i 3.5i
.if n .ta .7i 1.4i 2.1i 3.4i
struct ifconf {
	int	ifc_len;		/* size of associated buffer */
	union {
		caddr_t	ifcu_buf;
		struct	ifreq *ifcu_req;
	} ifc_ifcu;
};

#define	ifc_buf	ifc_ifcu.ifcu_buf		/* buffer address */
#define	ifc_req	ifc_ifcu.ifcu_req		/* array of structures returned */

#define	IFNAMSIZ	16

struct ifreq {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
		struct	sockaddr ifru_broadaddr;
		short	ifru_flags;
		caddr_t	ifru_data;
	} ifr_ifru;
};

.if t .ta \w'  #define'u +\w'  ifr_broadaddr'u +\w'  ifr_ifru.ifru_broadaddr'u
#define	ifr_addr	ifr_ifru.ifru_addr	/* address */
#define	ifr_dstaddr	ifr_ifru.ifru_dstaddr	/* other end of p-to-p link */
#define	ifr_broadaddr	ifr_ifru.ifru_broadaddr	/* broadcast address */
#define	ifr_flags	ifr_ifru.ifru_flags	/* flags */
#define	ifr_data	ifr_ifru.ifru_data	/* for use by interface */
E 2
.DE
I 2
The actual call which obtains the
interface configuration is
.DS
struct ifconf ifc;
char buf[BUFSIZ];

ifc.ifc_len = sizeof (buf);
ifc.ifc_buf = buf;
if (ioctl(s, SIOCGIFCONF, (char *) &ifc) < 0) {
	...
}
.DE
After this call \fIbuf\fP will contain one \fIifreq\fP structure for
each network to which the host is connected, and
\fIifc.ifc_len\fP will have been modified to reflect the number
of bytes used by the \fIifreq\fP structures.
E 2
.PP
I 2
For each structure
there exists a set of ``interface flags'' which tell
whether the network corresponding to that interface is
up or down, point to point or broadcast, etc.  The
SIOCGIFFLAGS \fIioctl\fP retrieves these
flags for an interface specified by an \fIifreq\fP
structure as follows:
.DS
struct ifreq *ifr;

ifr = ifc.ifc_req;

for (n = ifc.ifc_len / sizeof (struct ifreq); --n >= 0; ifr++) {
	/*
	 * We must be careful that we don't use an interface
D 4
	 * devoted to an address family other than our own;
E 4
I 4
	 * devoted to an address family other than those intended;
E 4
	 * if we were interested in NS interfaces, the
	 * AF_INET would be AF_NS.
	 */
	if (ifr->ifr_addr.sa_family != AF_INET)
		continue;
	if (ioctl(s, SIOCGIFFLAGS, (char *) ifr) < 0) {
		...
	}
D 4
	if ((ifr->ifr_flags & IFF_UP) == 0 ||	/* Skip boring cases */
E 4
I 4
	/*
	 * Skip boring cases.
	 */
	if ((ifr->ifr_flags & IFF_UP) == 0 ||
	    (ifr->ifr_flags & IFF_LOOPBACK) ||
E 4
	    (ifr->ifr_flags & (IFF_BROADCAST | IFF_POINTTOPOINT)) == 0)
		continue;
.DE
.PP
Once the flags have been obtained, the broadcast address 
must be obtained.  In the case of broadcast networks this is
done via the SIOCGIFBRDADDR \fIioctl\fP, while for point-to-point networks
the address of the destination host is obtained with SIOCGIFDSTADDR.
.DS
struct sockaddr dst;

if (ifr->ifr_flags & IFF_POINTTOPOINT) {
	if (ioctl(s, SIOCGIFDSTADDR, (char *) ifr) < 0) {
		...
	}
	bcopy((char *) ifr->ifr_dstaddr, (char *) &dst, sizeof (ifr->ifr_dstaddr));
} else if (ifr->ifr_flags & IFF_BROADCAST) {
	if (ioctl(s, SIOCGIFBRDADDR, (char *) ifr) < 0) {
		...
	}
	bcopy((char *) ifr->ifr_broadaddr, (char *) &dst, sizeof (ifr->ifr_broadaddr));
}
.DE
.PP
After the appropriate \fIioctl\fP's have obtained the broadcast
or destination address (now in \fIdst\fP), the \fIsendto\fP call may be
used:
.DS
	sendto(s, buf, buflen, 0, (struct sockaddr *)&dst, sizeof (dst));
}
.DE
In the above loop one \fIsendto\fP occurs for every
D 4
interface the host is connected to which supports the notion of
E 4
I 4
interface to which the host is connected that supports the notion of
E 4
broadcast or point-to-point addressing.
If a process only wished to send broadcast
messages on a given network, code similar to that outlined above
would be used, but the loop would need to find the
correct destination address.
.PP
E 2
Received broadcast messages contain the senders address
D 2
and port (datagram sockets are anchored before
a message is allowed to go out).  
E 2
I 2
and port, as datagram sockets are bound before
a message is allowed to go out.
E 2
.NH 2
D 2
Signals
E 2
I 2
Socket Options
E 2
.PP
D 2
Two new signals have been added to the system which may
be used in conjunction with the interprocess communication
facilities.  The SIGURG signal is associated with the existence
of an \*(lqurgent condition\*(rq.  The SIGIO signal is used
with \*(lqinterrupt driven i/o\*(rq (not presently implemented).
SIGURG is currently supplied a process when out of band data
is present at a socket.  If multiple sockets have out of band
data awaiting delivery, a select call may be used to determine
those sockets with such data.
E 2
I 2
It is possible to set and get a number of options on sockets
via the \fIsetsockopt\fP and \fIgetsockopt\fP system calls.
These options include such things as marking a socket for
broadcasting, not to route, to linger on close, etc.
The general forms of the calls are:
.DS
setsockopt(s, level, optname, optval, optlen);
.DE
and
.DS
getsockopt(s, level, optname, optval, optlen);
.DE
E 2
.PP
D 2
An old signal which is useful when constructing server processes
is SIGCHLD.  This signal is delivered to a process when any
children processes have changed state.  Normally servers use
the signal to \*(lqreap\*(rq child processes after exiting.
For example, the remote login server loop shown in Figure 2
may be augmented as follows:
E 2
I 2
The parameters to the calls are as follows: \fIs\fP
is the socket on which the option is to be applied.
\fILevel\fP specifies the protocol layer on which the
option is to be applied; in most cases this is
the ``socket level'', indicated by the symbolic constant
SOL_SOCKET, defined in \fI<sys/socket.h>.\fP
The actual option is specified in \fIoptname\fP, and is
a symbolic constant also defined in \fI<sys/socket.h>\fP.
\fIOptval\fP and \fIOptlen\fP point to the value of the
option (in most cases, whether the option is to be turned
on or off), and the length of the value of the option,
respectively.
For \fIgetsockopt\fP, \fIoptlen\fP is
a value-result parameter, initially set to the size of
the storage area pointed to by \fIoptval\fP, and modified
upon return to indicate the actual amount of storage used.
.PP
An example should help clarify things.  It is sometimes
useful to determine the type (e.g., stream, datagram, etc.)
of an existing socket; programs
under \fIinetd\fP (described below) may need to perform this
task.  This can be accomplished as follows via the
SO_TYPE socket option and the \fIgetsockopt\fP call:
E 2
.DS
D 2
int reaper();
 ...
sigset(SIGCHLD, reaper);
listen(f, 10);
for (;;) {
	int g, len = sizeof (from);
E 2
I 2
#include <sys/types.h>
#include <sys/socket.h>
E 2

D 2
	g = accept(f, &from, &len, 0);
	if (g < 0) {
		if (errno != EINTR)
			perror("rlogind: accept");
		continue;
	}
E 2
I 2
int type, size;

size = sizeof (int);

if (getsockopt(s, SOL_SOCKET, SO_TYPE, (char *) &type, &size) < 0) {
E 2
	...
}
I 2
.DE
After the \fIgetsockopt\fP call, \fItype\fP will be set
to the value of the socket type, as defined in
\fI<sys/socket.h>\fP.  If, for example, the socket were
a datagram socket, \fItype\fP would have the value
corresponding to SOCK_DGRAM.
.NH 2
NS Packet Sequences
.PP
The semantics of NS connections demand that
the user both be able to look inside the network header associated
with any incoming packet and be able to specify what should go
D 3
in certain fields of an outgoing packet.  The header of an
IDP-level packet looks like:
.DS
.if t .ta \w'struct  'u +\w"  struct ns_addr"u +2.0i
struct idp {
	u_short	idp_sum;	/* Checksum */
	u_short	idp_len;	/* Length, in bytes, including header */
	u_char	idp_tc;		/* Transport Control (i.e., hop count) */
	u_char	idp_pt;		/* Packet Type (i.e., level 2 protocol) */
	struct ns_addr	idp_dna;	/* Destination Network Address */
	struct ns_addr	idp_sna;	/* Source Network Address */
};
.DE
Most of the fields are filled in automatically; the only
field that the user should be concerned with is the 
\fIpacket type\fP field.  The standard values for this
field are (as defined in <\fInetns/ns.h\fP>):
.DS
.if t .ta \w"  #define"u +\w"  NSPROTO_ERROR"u +1.0i
#define NSPROTO_RI	1		/* Routing Information */
#define NSPROTO_ECHO	2		/* Echo Protocol */
#define NSPROTO_ERROR	3		/* Error Protocol */
#define NSPROTO_PE	4		/* Packet Exchange */
#define NSPROTO_SPP	5		/* Sequenced Packet */
.DE
For SPP connections, the contents of this field are
automatically set to NSPROTO_SPP; for IDP packets,
this value defaults to zero, which means ``unknown''.
E 3
I 3
in certain fields of an outgoing packet.
Using different calls to \fIsetsockopt\fP, it is possible
to indicate whether prototype headers will be associated by
the user with each outgoing packet (SO_HEADERS_ON_OUTPUT),
to indicate whether the headers received by the system should be
delivered to the user (SO_HEADERS_ON_INPUT), or to indicate
default information that should be associated with all
outgoing packets on a given socket (SO_DEFAULT_HEADERS).
E 3
.PP
The contents of a SPP header (minus the IDP header) are:
.DS
.if t .ta \w"  #define"u +\w"  u_short"u +2.0i
struct sphdr {
	u_char	sp_cc;		/* connection control */
#define	SP_SP	0x80		/* system packet */
#define	SP_SA	0x40		/* send acknowledgement */
#define	SP_OB	0x20		/* attention (out of band data) */
#define	SP_EM	0x10		/* end of message */
	u_char	sp_dt;		/* datastream type */
	u_short	sp_sid;		/* source connection identifier */
	u_short	sp_did;		/* destination connection identifier */
	u_short	sp_seq;		/* sequence number */
	u_short	sp_ack;		/* acknowledge number */
	u_short	sp_alo;		/* allocation number */
};
.DE
Here, the items of interest are the \fIdatastream type\fP and
the \fIconnection control\fP fields.  The semantics of the
datastream type are defined by the application(s) in question;
the value of this field is, by default, zero, but it can be
used to indicate things such as Xerox's Bulk Data Transfer
Protocol (in which case it is set to one).  The connection control
D 3
field is a mask of the flags defined above.  The user may
E 3
I 3
field is a mask of the flags defined just below it.  The user may
E 3
set or clear the end-of-message bit to indicate
that a given message is the last of a given substream type,
or may set/clear the attention bit as an alternate way to
indicate that a packet should be sent out-of-band.
D 3
.PP
Using different calls to \fIsetsockopt\fP, is it possible
to indicate whether prototype headers will be associated by
the user with each outgoing packet (SO_HEADERS_ON_OUTPUT),
to indicate whether the headers received by the system should be
delivered to the user (SO_HEADERS_ON_INPUT), or to indicate
default information that should be associated with all
outgoing packets on a given socket (SO_DEFAULT_HEADERS).
For example, to associate prototype headers with outgoing
SPP packets, one might use:
E 3
I 3
As an example, to associate prototype headers with outgoing
SPP packets, consider:
E 3
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
#include <netns/sp.h>
E 2
 ...
D 2
#include <wait.h>
reaper()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
E 2
I 2
struct sockaddr_ns sns, to;
int s, on = 1;
struct databuf {
	struct sphdr proto_spp;	/* prototype header */
	char buf[534];		/* max. possible data by Xerox std. */
} buf;
 ...
s = socket(AF_NS, SOCK_SEQPACKET, 0);
 ...
bind(s, (struct sockaddr *) &sns, sizeof (sns));
setsockopt(s, NSPROTO_SPP, SO_HEADERS_ON_OUTPUT, &on, sizeof(on));
 ...
buf.proto_spp.sp_dt = 1;	/* bulk data */
buf.proto_spp.sp_cc = SP_EM;	/* end-of-message */
strcpy(buf.buf, "hello world\en");
sendto(s, (char *) &buf, sizeof(struct sphdr) + strlen("hello world\en"),
    (struct sockaddr *) &to, sizeof(to));
 ...
.DE
Note that one must be careful when writing headers; if the prototype
header is not written with the data with which it is to be associated,
the kernel will treat the first few bytes of the data as the
header, with unpredictable results.
To turn off the above association, and to indicate that packet
headers received by the system should be passed up to the user,
one might use:
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
#include <netns/sp.h>
 ...
struct sockaddr sns;
int s, on = 1, off = 0;
 ...
s = socket(AF_NS, SOCK_SEQPACKET, 0);
 ...
bind(s, (struct sockaddr *) &sns, sizeof (sns));
setsockopt(s, NSPROTO_SPP, SO_HEADERS_ON_OUTPUT, &off, sizeof(off));
setsockopt(s, NSPROTO_SPP, SO_HEADERS_ON_INPUT, &on, sizeof(on));
 ...
.DE
D 3
To indicate a default prototype header to be associated with
the outgoing packets on an IDP datagram socket, one would use:
E 3
I 3
.PP
Output is handled somewhat differently in the IDP world.
The header of an IDP-level packet looks like:
E 3
.DS
I 3
.if t .ta \w'struct  'u +\w"  struct ns_addr"u +2.0i
struct idp {
	u_short	idp_sum;	/* Checksum */
	u_short	idp_len;	/* Length, in bytes, including header */
	u_char	idp_tc;		/* Transport Control (i.e., hop count) */
	u_char	idp_pt;		/* Packet Type (i.e., level 2 protocol) */
	struct ns_addr	idp_dna;	/* Destination Network Address */
	struct ns_addr	idp_sna;	/* Source Network Address */
};
.DE
The primary field of interest in an IDP header is the \fIpacket type\fP
field.  The standard values for this field are (as defined
in <\fInetns/ns.h\fP>):
.DS
.if t .ta \w"  #define"u +\w"  NSPROTO_ERROR"u +1.0i
#define NSPROTO_RI	1		/* Routing Information */
#define NSPROTO_ECHO	2		/* Echo Protocol */
#define NSPROTO_ERROR	3		/* Error Protocol */
#define NSPROTO_PE	4		/* Packet Exchange */
#define NSPROTO_SPP	5		/* Sequenced Packet */
.DE
For SPP connections, the contents of this field are
automatically set to NSPROTO_SPP; for IDP packets,
this value defaults to zero, which means ``unknown''.
.PP
Setting the value of that field with SO_DEFAULT_HEADERS is
easy:
.DS
E 3
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
#include <netns/idp.h>
 ...
struct sockaddr sns;
struct idp proto_idp;		/* prototype header */
int s, on = 1;
 ...
s = socket(AF_NS, SOCK_DGRAM, 0);
 ...
bind(s, (struct sockaddr *) &sns, sizeof (sns));
proto_idp.idp_pt = NSPROTO_PE;	/* packet exchange */
setsockopt(s, NSPROTO_IDP, SO_DEFAULT_HEADERS, (char *) &proto_idp,
    sizeof(proto_idp));
 ...
.DE
I 3
.PP
Using SO_HEADERS_ON_OUTPUT is somewhat more difficult.  When
SO_HEADERS_ON_OUTPUT is turned on for an IDP socket, the socket
becomes (for all intents and purposes) a raw socket.  In this
case, all the fields of the prototype header (except the 
length and checksum fields, which are computed by the kernel)
must be filled in correctly in order for the socket to send and
receive data in a sensible manner.  To be more specific, the
source address must be set to that of the host sending the
data; the destination address must be set to that of the
host for whom the data is intended; the packet type must be
set to whatever value is desired; and the hopcount must be
set to some reasonable value (almost always zero).  It should
also be noted that simply sending data using \fIwrite\fP
will not work unless a \fIconnect\fP or \fIsendto\fP call
is used, in spite of the fact that it is the destination
address in the prototype header that is used, not the one
given in either of those calls.  For almost
all IDP applications , using SO_DEFAULT_HEADERS is easier and
more desirable than writing headers.
E 3
.NH 2
Three-way Handshake
.PP
The semantics of SPP connections indicates that a three-way
handshake, involving changes in the datastream type, should \(em
but is not absolutely required to \(em take place before a SPP
connection is closed.  Almost all SPP connections are
``well-behaved'' in this manner; when communicating with
any process, it is best to assume that the three-way handshake
is required unless it is known for certain that it is not
required.  In a three-way close, the closing process
indicates that it wishes to close the connection by sending
a zero-length packet with end-of-message set and with
datastream type 254.  The other side of the connection
indicates that it is OK to close by sending a zero-length
packet with end-of-message set and datastream type 255.  Finally,
the closing process replies with a zero-length packet with 
substream type 255; at this point, the connection is considered
closed.  The following code fragments are simplified examples
of how one might handle this three-way handshake at the user
level; in the future, support for this type of close will
probably be provided as part of the C library or as part of
the kernel.  The first code fragment below illustrates how a process
might handle three-way handshake if it sees that the process it
is communicating with wants to close the connection:
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
#include <netns/sp.h>
 ...
#ifndef SPPSST_END
#define SPPSST_END 254
#define SPPSST_ENDREPLY 255
#endif
struct sphdr proto_sp;
int s;
 ...
read(s, buf, BUFSIZE);
if (((struct sphdr *)buf)->sp_dt == SPPSST_END) {
	/*
	 * SPPSST_END indicates that the other side wants to
	 * close.
	 */
	proto_sp.sp_dt = SPPSST_ENDREPLY;
	proto_sp.sp_cc = SP_EM;
	setsockopt(s, NSPROTO_SPP, SO_DEFAULT_HEADERS, (char *)&proto_sp,
	    sizeof(proto_sp));
	write(s, buf, 0);
	/*
	 * Write a zero-length packet with datastream type = SPPSST_ENDREPLY
	 * to indicate that the close is OK with us.  The packet that we
	 * don't see (because we don't look for it) is another packet
	 * from the other side of the connection, with SPPSST_ENDREPLY
	 * on it it, too.  Once that packet is sent, the connection is
	 * considered closed; note that we really ought to retransmit
	 * the close for some time if we do not get a reply.
	 */
	close(s);
E 2
}
I 2
 ...
E 2
.DE
I 2
To indicate to another process that we would like to close the
connection, the following code would suffice:
.DS
#include <sys/types.h>
#include <sys/socket.h>
#include <netns/ns.h>
#include <netns/sp.h>
 ...
#ifndef SPPSST_END
#define SPPSST_END 254
#define SPPSST_ENDREPLY 255
#endif
struct sphdr proto_sp;
int s;
 ...
proto_sp.sp_dt = SPPSST_END;
proto_sp.sp_cc = SP_EM;
setsockopt(s, NSPROTO_SPP, SO_DEFAULT_HEADERS, (char *)&proto_sp,
    sizeof(proto_sp));
write(s, buf, 0);	/* send the end request */
proto_sp.sp_dt = SPPSST_ENDREPLY;
setsockopt(s, NSPROTO_SPP, SO_DEFAULT_HEADERS, (char *)&proto_sp,
    sizeof(proto_sp));
/*
 * We assume (perhaps unwisely)
 * that the other side will send the
 * ENDREPLY, so we'll just send our final ENDREPLY
 * as if we'd seen theirs already.
 */
write(s, buf, 0);
close(s);
 ...
.DE
.NH 2
Packet Exchange
E 2
.PP
D 2
If the parent server process fails to reap its children,
a large number of \*(lqzombie\*(rq processes may be created.
E 2
I 2
The Xerox standard protocols include a protocol that is both
reliable and datagram-oriented.  This protocol is known as
Packet Exchange (PEX or PE) and, like SPP, is layered on top
of IDP.  PEX is important for a number of things: Courier
remote procedure calls may be expedited through the use
of PEX, and many Xerox servers are located by doing a PEX
``BroadcastForServers'' operation.  Although there is no
implementation of PEX in the kernel,
it may be simulated at the user level with some clever coding
and the use of one peculiar \fIgetsockopt\fP.  A PEX packet
looks like:
.DS
.if t .ta \w'struct  'u +\w"  struct idp"u +2.0i
/*
 * The packet-exchange header shown here is not defined
 * as part of any of the system include files.
 */
struct pex {
	struct idp	p_idp;	/* idp header */
	u_short	ph_id[2];	/* unique transaction ID for pex */
	u_short	ph_client;	/* client type field for pex */
};
.DE
The \fIph_id\fP field is used to hold a ``unique id'' that
is used in duplicate suppression; the \fIph_client\fP
field indicates the PEX client type (similar to the packet
type field in the IDP header).  PEX reliability stems from the
fact that it is an idempotent (``I send a packet to you, you
send a packet to me'') protocol.  Processes on each side of
the connection may use the unique id to determine if they have
seen a given packet before (the unique id field differs on each
packet sent) so that duplicates may be detected, and to indicate
which message a given packet is in response to.  If a packet with
a given unique id is sent and no response is received in a given
amount of time, the packet is retransmitted until it is decided
that no response will ever be received.  To simulate PEX, one
must be able to generate unique ids -- something that is hard to
do at the user level with any real guarantee that the id is really
unique.  Therefore, a means (via \fIgetsockopt\fP) has been provided
for getting unique ids from the kernel.  The following code fragment
indicates how to get a unique id:
.DS
long uniqueid;
int s, idsize = sizeof(uniqueid);
 ...
s = socket(AF_NS, SOCK_DGRAM, 0);
 ...
/* get id from the kernel -- only on IDP sockets */
getsockopt(s, NSPROTO_PE, SO_SEQNO, (char *)&uniqueid, &idsize);
 ...
.DE
The retransmission and duplicate suppression code required to
simulate PEX fully is left as an exercise for the reader.
.NH 2
D 4
Non-Blocking Sockets
.PP
It is occasionally convenient to make use of sockets
which do not block; that is, i/o requests which
would take time and
would cause the process to wait for their completion are
not executed, and an error code is returned.
Once a socket has been created via
the \fIsocket\fP call, it may be marked as non-blocking
by \fIfcntl\fP as follows:
.DS
#include <fcntl.h>
 ...
int	s;
 ...
s = socket(AF_INET, SOCK_STREAM, 0);
 ...
if (fcntl(s, F_SETFL, FNDELAY) < 0)
	perror("fcntl F_SETFL, FNDELAY");
	exit(1);
}
 ...
.DE
.PP
When performing non-blocking i/o on sockets, one must be
careful to check for the error EWOULDBLOCK (stored in the
global variable \fIerrno\fP), which occurs when
an operation would normally block, but the socket it
was performed on is marked as non-blocking.
In particular, \fIaccept\fP, \fIconnect\fP, \fIsend\fP, \fIrecv\fP,
\fIread\fP, and \fIwrite\fP can
all return EWOULDBLOCK, and processes should be prepared
to deal with such return codes.
.NH 2
E 4
Inetd
.PP
One of the daemons provided with 4.3BSD is \fIinetd\fP, the
so called ``internet super-server.''  \fIInetd\fP is invoked at boot
time, and determines from the file \fI/etc/inetd.conf\fP the
servers for which it is to listen.  Once this information has been
read and a pristine environment created, \fIinetd\fP proceeds
to create one socket for each service it is to listen for,
binding the appropriate port number to each socket.
.PP
\fIInetd\fP then performs a \fIselect\fP on all these
sockets for read availability, waiting for somebody wishing
a connection to the service corresponding to
that socket.  \fIInetd\fP then performs an \fIaccept\fP on
the socket in question, \fIfork\fPs, \fIdup\fPs the new
socket to file descriptors 0 and 1 (stdin and
stdout), closes other open file
descriptors, and \fIexec\fPs the appropriate server.
.PP
Servers making use of \fIinetd\fP are considerably simplified,
as \fIinetd\fP takes care of the majority of the IPC work
required in establishing a connection.  The server invoked
by \fIinetd\fP expects the socket connected to its client
on file descriptors 0 and 1, and may immediately perform
any operations such as \fIread\fP, \fIwrite\fP, \fIsend\fP,
or \fIrecv\fP.  Indeed, servers may use
D 4
buffered i/o as provided by the ``stdio'' conventions, as
E 4
I 4
buffered I/O as provided by the ``stdio'' conventions, as
E 4
long as as they remember to use \fIfflush\fP when appropriate.
.PP
One call which may be of interest to individuals writing
servers under \fIinetd\fP is the \fIgetpeername\fP call,
which returns the address of the peer (process) connected
on the other end of the socket.  For example, to log the
Internet address in ``dot notation'' (e.g., ``128.32.0.4'')
of a client connected to a server under
\fIinetd\fP, the following code might be used:
.DS
struct sockaddr_in name;
int namelen = sizeof (name);
 ...
if (getpeername(0, (struct sockaddr *)&name, &namelen) < 0) {
	syslog(LOG_ERR, "getpeername: %m");
	exit(1);
} else
	syslog(LOG_INFO, "Connection from %s", inet_ntoa(name.sin_addr));
 ...
.DE
While the \fIgetpeername\fP call is especially useful when
writing programs to run with \fIinetd\fP, it can be used
D 4
at any time.  Be warned, however, that \fIgetpeername\fP will
fail on UNIX domain sockets, as their addresses (i.e., pathnames)
are inaccessible.
E 4
I 4
under other circumstances.  Be warned, however, that \fIgetpeername\fP will
fail on UNIX domain sockets.
E 4
E 2
E 1

h37957
s 00008/00003/00476
d D 1.3 86/05/02 17:40:28 karels 3 2
c corrections
e
s 00154/00083/00325
d D 1.2 86/04/30 11:22:05 karels 2 1
c updates for 4.3 from lapsley
e
s 00408/00000/00000
d D 1.1 86/04/30 11:19:01 karels 1 0
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
D 3
.ds RH "Client/Server Model
E 3
I 3
.\".ds RH "Client/Server Model
E 3
.bp
.nr H1 4
.nr H2 0
I 2
.sp 8i
E 2
.bp
.LG
.B
.ce
4. CLIENT/SERVER MODEL
.sp 2
.R
.NL
.PP
The most commonly used paradigm in constructing distributed applications
is the client/server model.  In this scheme client applications request
services from a server process.  This implies an asymmetry in establishing
communication between the client and server which has been examined
in section 2.  In this section we will look more closely at the interactions
between client and server, and consider some of the problems in developing
client and server applications.
.PP
D 2
Client and server require a well known set of conventions before
E 2
I 2
The client and server require a well known set of conventions before
E 2
service may be rendered (and accepted).  This set of conventions
comprises a protocol which must be implemented at both ends of a
connection.  Depending on the situation, the protocol may be symmetric
or asymmetric.  In a symmetric protocol, either side may play the 
master or slave roles.  In an asymmetric protocol, one side is
D 2
immutably recognized as the master, with the other the slave.  
E 2
I 2
immutably recognized as the master, with the other as the slave.  
E 2
An example of a symmetric protocol is the TELNET protocol used in
the Internet for remote terminal emulation.  An example
of an asymmetric protocol is the Internet file transfer protocol,
FTP.  No matter whether the specific protocol used in obtaining
a service is symmetric or asymmetric, when accessing a service there
is a \*(lqclient process\*(rq and a \*(lqserver process\*(rq.  We
will first consider the properties of server processes, then
client processes.
.PP
D 2
A server process normally listens at a well know address for
service requests.  Alternative schemes which use a service server
E 2
I 2
A server process normally listens at a well known address for
service requests.  That is, the server process remains dormant
until a connection is requested by a client's connection
to the server's address.  At such a time
the server process ``wakes up'' and services the client,
performing whatever appropriate actions the client requests of it.
.PP
Alternative schemes which use a service server
E 2
may be used to eliminate a flock of server processes clogging the
D 2
system while remaining dormant most of the time.  The Xerox
Courier protocol uses the latter scheme.  When using Courier, a
Courier client process contacts a Courier server at the remote
host and identifies the service it requires.  The Courier server
process then creates the appropriate server process based on a
data base and \*(lqsplices\*(rq the client and server together,
voiding its part in the transaction.  This scheme is attractive
in that the Courier server process may provide a single contact
point for all services, as well as carrying out the initial steps
in authentication.  However, while this is an attractive possibility
for standardizing access to services, it does introduce a certain
amount of overhead due to the intermediate process involved.
Implementations which provide this type of service within the
system can minimize the cost of client server
rendezvous.  The \fIportal\fP notion described
in the \*(lq4.2BSD System Manual\*(rq embodies many of the ideas
found in Courier, with the rendezvous mechanism implemented internal
to the system.
E 2
I 2
system while remaining dormant most of the time.  For Internet
servers in 4.3BSD,
this scheme has been implemented via \fIinetd\fP, the so called
``internet super-server.''  \fIInetd\fP listens at a variety
of ports, determined at start-up by reading a configuration file.
When a connection is requested to a port on which \fIinetd\fP is
listening, \fIinetd\fP executes the appropriate server program to handle the
client.  With this method, clients are unaware that an
intermediary such as \fIinetd\fP has played any part in the
connection.  \fIInetd\fP will be described in more detail in
section 5.
.PP
A similar alternative scheme is used by most Xerox services.  In general,
the Courier dispatch process (if used) accepts connections from
processes requesting services of some sort or another.  The client
processes request a particular <program number, version number, procedure
number> triple.  If the dispatcher knows of such a program, it is
started to handle the request; if not, an error is reported to the
client.  In this way, only one port is required to service a large
variety of different requests.  Again, the Courier facilities are
not available without the use and installation of the Courier
compiler.  The information presented in this section applies only
to NS clients and services that do not use Courier.
E 2
.NH 2
Servers
.PP
D 2
In 4.2BSD most servers are accessed at well known Internet addresses
or UNIX domain names.  When a server is started at boot time it
advertises it services by listening at a well know location.  For
E 2
I 2
In 4.3BSD most servers are accessed at well known Internet addresses
or UNIX domain names.  For
E 2
example, the remote login server's main loop is of the form shown
in Figure 2.
.KF
D 2
.if t .ta .5i 1.0i 1.5i 2.0i
.if n .ta .7i 1.4i 2.1i 2.8i
E 2
I 2
.if t .ta .5i 1.0i 1.5i 2.0i 2.5i 3.0i 3.5i
.if n .ta .7i 1.4i 2.1i 2.8i 3.5i 4.2i 4.9i
.sp 0.5i
E 2
.DS
main(argc, argv)
	int argc;
D 2
	char **argv;
E 2
I 2
	char *argv[];
E 2
{
	int f;
	struct sockaddr_in from;
	struct servent *sp;

	sp = getservbyname("login", "tcp");
	if (sp == NULL) {
		fprintf(stderr, "rlogind: tcp/login: unknown service\en");
		exit(1);
	}
	...
#ifndef DEBUG
D 2
	<<disassociate server from controlling terminal>>
E 2
I 2
	/* Disassociate server from controlling terminal */
	...
E 2
#endif
I 2

	sin.sin_port = sp->s_port;	/* Restricted port -- see section 5 */
E 2
	...
D 2
	sin.sin_port = sp->s_port;
	...
E 2
	f = socket(AF_INET, SOCK_STREAM, 0);
	...
D 2
	if (bind(f, (caddr_t)&sin, sizeof (sin)) < 0) {
E 2
I 2
	if (bind(f, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
E 2
		...
	}
	...
	listen(f, 5);
	for (;;) {
		int g, len = sizeof (from);

D 2
		g = accept(f, &from, &len);
E 2
I 2
		g = accept(f, (struct sockaddr *) &from, &len);
E 2
		if (g < 0) {
			if (errno != EINTR)
D 2
				perror("rlogind: accept");
E 2
I 2
				syslog(LOG_ERR, "rlogind: accept: %m");
E 2
			continue;
		}
		if (fork() == 0) {
			close(f);
			doit(g, &from);
		}
		close(g);
	}
}
.DE
.ce
Figure 2.  Remote login server.
D 2
.sp
E 2
I 2
.sp 0.5i
E 2
.KE
.PP
The first step taken by the server is look up its service
definition:
.sp 1
.nf
.in +5
.if t .ta .5i 1.0i 1.5i 2.0i
.if n .ta .7i 1.4i 2.1i 2.8i
sp = getservbyname("login", "tcp");
if (sp == NULL) {
	fprintf(stderr, "rlogind: tcp/login: unknown service\en");
	exit(1);
}
.sp 1
.in -5
.fi
D 2
This definition is used in later portions of the code to
E 2
I 2
The result of the \fIgetservbyname\fP call
is used in later portions of the code to
E 2
define the Internet port at which it listens for service
requests (indicated by a connection).
I 2
.KS
E 2
.PP
Step two is to disassociate the server from the controlling
D 2
terminal of its invoker.  This is important as the server will
E 2
I 2
terminal of its invoker:
.DS
	for (i = 0; i < 3; ++i)
		close(i);

	open("/", O_RDONLY);
	dup2(0, 1);
	dup2(0, 2);

	i = open("/dev/tty", O_RDWR);
	if (i >= 0) {
		ioctl(i, TIOCNOTTY, 0);
		close(i);
	}
.DE
.KE
This step is important as the server will
E 2
likely not want to receive signals delivered to the process
D 2
group of the controlling terminal. 
E 2
I 2
group of the controlling terminal.  Note, however, that
once a server has disassociated itself it can no longer
send reports of errors to a terminal, and must log errors
via \fIsyslog\fP.
E 2
.PP
Once a server has established a pristine environment, it
creates a socket and begins accepting service requests.
The \fIbind\fP call is required to insure the server listens
D 2
at its expected location.  The main body of the loop is
fairly simple:
E 2
I 2
at its expected location.  It should be noted that the
remote login server listens at a restricted port number, and must
therefore be run
with a user-id of root.
This concept of a ``restricted port number'' is 4BSD
specific, and is covered in section 5.
.PP
The main body of the loop is fairly simple:
E 2
.DS
.if t .ta .5i 1.0i 1.5i 2.0i
.if n .ta .7i 1.4i 2.1i 2.8i
for (;;) {
	int g, len = sizeof (from);

D 2
	g = accept(f, &from, &len);
E 2
I 2
	g = accept(f, (struct sockaddr *)&from, &len);
E 2
	if (g < 0) {
		if (errno != EINTR)
D 2
			perror("rlogind: accept");
E 2
I 2
			syslog(LOG_ERR, "rlogind: accept: %m");
E 2
		continue;
	}
D 2
	if (fork() == 0) {
E 2
I 2
	if (fork() == 0) {	/* Child */
E 2
		close(f);
		doit(g, &from);
	}
D 2
	close(g);
E 2
I 2
	close(g);		/* Parent */
E 2
}
.DE
An \fIaccept\fP call blocks the server until
a client requests service.  This call could return a
failure status if the call is interrupted by a signal
such as SIGCHLD (to be discussed in section 5).  Therefore,
the return value from \fIaccept\fP is checked to insure
D 2
a connection has actually been established.  With a connection
E 2
I 2
a connection has actually been established, and
an error report is logged via \fIsyslog\fP if an error
has occurred.
.PP
With a connection
E 2
in hand, the server then forks a child process and invokes
the main body of the remote login protocol processing.  Note
D 3
how the socket used by the parent for queueing connection
E 3
I 3
how the socket used by the parent for queuing connection
E 3
requests is closed in the child, while the socket created as
D 2
a result of the accept is closed in the parent.  The
E 2
I 2
a result of the \fIaccept\fP is closed in the parent.  The
E 2
address of the client is also handed the \fIdoit\fP routine
because it requires it in authenticating clients.
.NH 2
Clients
.PP
The client side of the remote login service was shown
earlier in Figure 1.
One can see the separate, asymmetric roles of the client
and server clearly in the code.  The server is a passive entity,
listening for client connections, while the client process is
an active entity, initiating a connection when invoked.  
.PP
Let us consider more closely the steps taken
D 2
by the client remote login process.  As in the server process
E 2
I 2
by the client remote login process.  As in the server process,
E 2
the first step is to locate the service definition for a remote
login:
.DS
sp = getservbyname("login", "tcp");
if (sp == NULL) {
	fprintf(stderr, "rlogin: tcp/login: unknown service\en");
	exit(1);
}
.DE
Next the destination host is looked up with a
\fIgethostbyname\fP call:
.DS
hp = gethostbyname(argv[1]);
if (hp == NULL) {
	fprintf(stderr, "rlogin: %s: unknown host\en", argv[1]);
	exit(2);
}
.DE
With this accomplished, all that is required is to establish a
connection to the server at the requested host and start up the
remote login protocol.  The address buffer is cleared, then filled
in with the Internet address of the foreign host and the port
D 2
number at which the login process resides:
E 2
I 2
number at which the login process resides on the foreign host:
E 2
.DS
D 2
bzero((char *)&sin, sizeof (sin));
bcopy(hp->h_addr, (char *)sin.sin_addr, hp->h_length);
sin.sin_family = hp->h_addrtype;
sin.sin_port = sp->s_port;
E 2
I 2
bzero((char *)&server, sizeof (server));
bcopy(hp->h_addr, (char *) &server.sin_addr, hp->h_length);
server.sin_family = hp->h_addrtype;
server.sin_port = sp->s_port;
E 2
.DE
D 2
A socket is created, and a connection initiated.
E 2
I 2
A socket is created, and a connection initiated.  Note
that \fIconnect\fP implicitly performs a \fIbind\fP
call, since \fIs\fP is unbound.
E 2
.DS
s = socket(hp->h_addrtype, SOCK_STREAM, 0);
if (s < 0) {
	perror("rlogin: socket");
	exit(3);
}
 ...
D 2
if (connect(s, (char *)&sin, sizeof (sin)) < 0) {
E 2
I 2
if (connect(s, (struct sockaddr *) &server, sizeof (server)) < 0) {
E 2
	perror("rlogin: connect");
	exit(4);
}
.DE
The details of the remote login protocol will not be considered here.
.NH 2
Connectionless servers
.PP
While connection-based services are the norm, some services
are based on the use of datagram sockets.  One, in particular,
is the \*(lqrwho\*(rq service which provides users with status
information for hosts connected to a local area
network.  This service, while predicated on the ability to
\fIbroadcast\fP information to all hosts connected to a particular
network, is of interest as an example usage of datagram sockets.
.PP
A user on any machine running the rwho server may find out
the current status of a machine with the \fIruptime\fP(1) program.
The output generated is illustrated in Figure 3.
.KF
.DS B
.TS
l r l l l l l.
arpa	up	9:45,	5 users, load	1.15,	1.39,	1.31
cad	up	2+12:04,	8 users, load	4.67,	5.13,	4.59
calder	up	10:10,	0 users, load	0.27,	0.15,	0.14
dali	up	2+06:28,	9 users, load	1.04,	1.20,	1.65
degas	up	25+09:48,	0 users, load	1.49,	1.43,	1.41
ear	up	5+00:05,	0 users, load	1.51,	1.54,	1.56
ernie	down	0:24
esvax	down	17:04
ingres	down	0:26
kim	up	3+09:16,	8 users, load	2.03,	2.46,	3.11
matisse	up	3+06:18,	0 users, load	0.03,	0.03,	0.05
medea	up	3+09:39,	2 users, load	0.35,	0.37,	0.50
merlin	down	19+15:37
miro	up	1+07:20,	7 users, load	4.59,	3.28,	2.12
monet	up	1+00:43,	2 users, load	0.22,	0.09,	0.07
oz	down	16:09
statvax	up	2+15:57,	3 users, load	1.52,	1.81,	1.86
ucbvax	up	9:34,	2 users, load	6.08,	5.16,	3.28
.TE
.DE
.ce
Figure 3. ruptime output.
.sp
.KE
.PP
Status information for each host is periodically broadcast
by rwho server processes on each machine.  The same server
process also receives the status information and uses it
to update a database.  This database is then interpreted
to generate the status information for each host.  Servers
operate autonomously, coupled only by the local network and
its broadcast capabilities.
.PP
I 3
Note that the use of broadcast for such a task is fairly inefficient,
as all hosts must process each message, whether or not using an rwho server.
Unless such a service is sufficiently universal and is frequently used,
the expense of periodic broadcasts outweighs the simplicity.
.PP
E 3
The rwho server, in a simplified form, is pictured in Figure
4.  There are two separate tasks performed by the server.  The
first task is to act as a receiver of status information broadcast
by other hosts on the network.  This job is carried out in the
main loop of the program.  Packets received at the rwho port
are interrogated to insure they've been sent by another rwho
server process, then are time stamped with their arrival time
and used to update a file indicating the status of the host.
When a host has not been heard from for an extended period of
time, the database interpretation routines assume the host is
down and indicate such on the status reports.  This algorithm
is prone to error as a server may be down while a host is actually
up, but serves our current needs.
.KF
.DS
.if t .ta .5i 1.0i 1.5i 2.0i
.if n .ta .7i 1.4i 2.1i 2.8i
main()
{
	...
	sp = getservbyname("who", "udp");
	net = getnetbyname("localnet");
	sin.sin_addr = inet_makeaddr(INADDR_ANY, net);
	sin.sin_port = sp->s_port;
	...
	s = socket(AF_INET, SOCK_DGRAM, 0);
	...
D 2
	bind(s, &sin, sizeof (sin));
E 2
I 2
	on = 1;
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0) {
		syslog(LOG_ERR, "setsockopt SO_BROADCAST: %m");
		exit(1);
	}
	bind(s, (struct sockaddr *) &sin, sizeof (sin));
E 2
	...
D 2
	sigset(SIGALRM, onalrm);
E 2
I 2
	signal(SIGALRM, onalrm);
E 2
	onalrm();
	for (;;) {
		struct whod wd;
		int cc, whod, len = sizeof (from);

D 2
		cc = recvfrom(s, (char *)&wd, sizeof (struct whod), 0, &from, &len);
E 2
I 2
		cc = recvfrom(s, (char *)&wd, sizeof (struct whod), 0,
		    (struct sockaddr *)&from, &len);
E 2
		if (cc <= 0) {
			if (cc < 0 && errno != EINTR)
D 2
				perror("rwhod: recv");
E 2
I 2
				syslog(LOG_ERR, "rwhod: recv: %m");
E 2
			continue;
		}
		if (from.sin_port != sp->s_port) {
D 2
			fprintf(stderr, "rwhod: %d: bad from port\en",
E 2
I 2
			syslog(LOG_ERR, "rwhod: %d: bad from port",
E 2
				ntohs(from.sin_port));
			continue;
		}
		...
		if (!verify(wd.wd_hostname)) {
D 2
			fprintf(stderr, "rwhod: malformed host name from %x\en",
E 2
I 2
			syslog(LOG_ERR, "rwhod: malformed host name from %x",
E 2
				ntohl(from.sin_addr.s_addr));
			continue;
		}
		(void) sprintf(path, "%s/whod.%s", RWHODIR, wd.wd_hostname);
D 2
		whod = open(path, FWRONLY|FCREATE|FTRUNCATE, 0666);
E 2
I 2
D 3
		whod = open(path, O_RDONLY | O_CREAT | O_TRUNC, 0666);
E 3
I 3
		whod = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
E 3
E 2
		...
		(void) time(&wd.wd_recvtime);
		(void) write(whod, (char *)&wd, cc);
		(void) close(whod);
	}
}
.DE
.ce
Figure 4.  rwho server.
I 2
.sp
E 2
.KE
.PP
The second task performed by the server is to supply information
regarding the status of its host.  This involves periodically
acquiring system status information, packaging it up in a message
and broadcasting it on the local network for other rwho servers
to hear.  The supply function is triggered by a timer and 
runs off a signal.  Locating the system status
information is somewhat involved, but uninteresting.  Deciding
D 2
where to transmit the resultant packet does, however, indicates
some problems with the current protocol.
E 2
I 2
where to transmit the resultant packet
is somewhat problematical, however.
E 2
.PP
D 2
Status information is broadcast on the local network.
E 2
I 2
Status information must be broadcast on the local network.
E 2
For networks which do not support the notion of broadcast another
scheme must be used to simulate or
replace broadcasting.  One possibility is to enumerate the
D 2
known neighbors (based on the status received).  This, unfortunately,
requires some bootstrapping information, as a
server started up on a quiet network will have no
E 2
I 2
known neighbors (based on the status messages received
from other rwho servers).  This, unfortunately,
requires some bootstrapping information,
for a server will have no idea what machines are its
neighbors until it receives status messages from them.
Therefore, if all machines on a net are freshly booted,
no machine will have any
E 2
known neighbors and thus never receive, or send, any status information.
This is the identical problem faced by the routing table management
process in propagating routing status information.  The standard
solution, unsatisfactory as it may be, is to inform one or more servers
of known neighbors and request that they always communicate with
these neighbors.  If each server has at least one neighbor supplied
D 2
it, status information may then propagate through
E 2
I 2
to it, status information may then propagate through
E 2
a neighbor to hosts which
are not (possibly) directly neighbors.  If the server is able to
support networks which provide a broadcast capability, as well as
those which do not, then networks with an
arbitrary topology may share status information*.
.FS
* One must, however, be concerned about \*(lqloops\*(rq.
That is, if a host is connected to multiple networks, it
will receive status information from itself.  This can lead
to an endless, wasteful, exchange of information.
.FE
.PP
D 2
The second problem with the current scheme is that the rwho process
services only a single local network, and this network is found by
reading a file.  It is important that software operating in a distributed
E 2
I 2
It is important that software operating in a distributed
E 2
environment not have any site-dependent information compiled into it.
This would require a separate copy of the server at each host and
D 2
make maintenance a severe headache.  4.2BSD attempts to isolate
E 2
I 2
make maintenance a severe headache.  4.3BSD attempts to isolate
E 2
host-specific information from applications by providing system
D 2
calls which return the necessary information\(dg.
E 2
I 2
calls which return the necessary information*.
E 2
.FS
D 2
\(dg An example of such a system call is the \fIgethostname\fP(2)
E 2
I 2
* An example of such a system call is the \fIgethostname\fP(2)
E 2
call which returns the host's \*(lqofficial\*(rq name.
.FE
D 2
Unfortunately, no straightforward mechanism currently
exists for finding the collection
of networks to which a host is directly connected.  Thus the
rwho server performs a lookup in a file
to find its local network.  A better, though still
unsatisfactory, scheme used by the routing process is to interrogate
the system data structures to locate those directly connected
networks.  A mechanism to acquire this information from the system
would be a useful addition.
E 2
I 2
A mechanism exists, in the form of an \fIioctl\fP call,
for finding the collection
of networks to which a host is directly connected.
Further, a local network broadcasting mechanism
has been implemented at the socket level.
Combining these two features allows a process
to broadcast on any directly connected local
network which supports the notion of broadcasting
in a site independent manner.  This allows 4.3BSD
to solve the problem of deciding how to propagate
status information in the case of \fIrwho\fP, or
more generally in broadcasting:
Such status information is broadcast to connected
networks at the socket level, where the connected networks
have been obtained via the appropriate \fIioctl\fP
calls.
The specifics of
such broadcastings are complex, however, and will
be covered in section 5.
E 2
E 1

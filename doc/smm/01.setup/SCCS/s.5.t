h65311
s 00009/00002/00585
d D 6.3 03/11/18 22:32:28 msokolov 4 3
c VAX/Tahoe conditional logic was breaking tables
e
s 00161/00151/00424
d D 6.2 88/07/17 09:34:08 karels 3 2
c merge vax and tahoe versions
e
s 00388/00196/00187
d D 6.1 86/05/14 09:37:16 mckusick 2 1
c 4.3BSD release document
e
s 00383/00000/00000
d D 5.1 86/05/14 09:37:05 mckusick 1 0
c broken out of 0.t for 4.2BSD document
e
u
U
t
T
I 1
D 3
.\" Copyright (c) 1980 Regents of the University of California.
E 3
I 3
.\" Copyright (c) 1980,1986,1988 Regents of the University of California.
E 3
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.ds lq ``
.ds rq ''
D 2
.ds LH "Installing/Operating 4.2BSD
E 2
I 2
.ds LH "Installing/Operating \*(4B
E 2
.ds RH Network setup
.ds CF \*(DY
.LP
.nr H1 5
.nr H2 0
.bp
.LG
.B
.ce
5. NETWORK SETUP
.sp 2
.R
.NL
I 3
.ds B3 4.3BSD
E 3
.PP
D 2
4.2BSD provides support for the DARPA standard Internet
E 2
I 2
D 3
\*(4B provides support for the DARPA standard Internet
E 3
I 3
\*(B3 provides support for the DARPA standard Internet
E 3
E 2
protocols IP, ICMP, TCP, and UDP.  These protocols may be used
on top of a variety of hardware devices ranging from the
D 2
IMP's used in the ARPANET to local area network controllers
E 2
I 2
IMP's (PSN's) used in the ARPANET to local area network controllers
E 2
for the Ethernet.  Network services are split between the
kernel (communication protocols) and user programs (user
services such as TELNET and FTP).  This section describes
D 2
how to configure your system to use the networking support.
E 2
I 2
how to configure your system to use the Internet networking support.
D 3
\*(4B also supports the Xerox Network Systems (NS) protocols.
E 3
I 3
\*(B3 also supports the Xerox Network Systems (NS) protocols.
E 3
IDP and SPP are implemented in the kernel,
and other protocols such as Courier run at the user level.
E 2
.NH 2
System configuration
.PP
To configure the kernel to include the Internet communication
D 2
protocols, define the INET option and include the pseudo-devices
``inet'', ``pty'', and ``loop'' in your machine's configuration
E 2
I 2
protocols, define the INET option.
Xerox NS support is enabled with the NS option.
In either case, include the pseudo-devices
``pty'', and ``loop'' in your machine's configuration
E 2
file.  
The ``pty'' pseudo-device forces the pseudo terminal device driver
to be configured into the system, see \fIpty\fP\|(4), while
the ``loop'' pseudo-device forces inclusion of the software loopback
D 2
interface driver.  The loop driver
is used in network testing and also by the mail system.
E 2
I 2
interface driver.
The loop driver is used in network testing
and also by the error logging system.
E 2
.PP
D 2
If you are planning to use the network facilities on a 10Mb/s
E 2
I 2
If you are planning to use the Internet network facilities on a 10Mb/s
E 2
Ethernet, the pseudo-device ``ether'' should also be included
in the configuration; this forces inclusion of the Address Resolution
Protocol module used in mapping between 48-bit Ethernet
and 32-bit Internet addresses.
D 2
Also, if you have an imp,
E 2
I 2
Also, if you have an IMP connection,
E 2
you will need to include the pseudo-device ``imp.''
.PP
Before configuring the appropriate networking hardware, you should
D 2
consult the manual pages in section 4 of the programmer's manual.
E 2
I 2
consult the manual pages in section 4 of the Programmer's Manual.
E 2
The following table lists the devices for which software support
exists.
I 4
.if \n(Vx \{\
E 4
.DS
.TS
l l.
Device name	Manufacturer and product
_
I 3
D 4
.if \n(Vx \{\
E 4
E 3
acc	ACC LH/DH interface to IMP
css	DEC IMP-11A interface to IMP
I 2
ddn	ACC ACP625 DDN Standard mode X.25 interface to IMP
E 2
dmc	DEC DMC-11 (also works with DMR-11)
I 2
de	DEC DEUNA 10Mb/s Ethernet
E 2
ec	3Com 10Mb/s Ethernet
en	Xerox 3Mb/s prototype Ethernet (not a product)
I 2
ex	Excelan 204 10Mb/s Ethernet
hdh	ACC IF-11/HDH IMP interface
E 2
hy	NSC Hyperchannel, w/ DR-11B and PI-13 interfaces
D 2
il	Interlan 10Mb/s Ethernet
E 2
I 2
il	Interlan 1010 and 10101A 10Mb/s Ethernet interfaces
ix	Interlan NP100 10Mb/s Ethernet interface
E 2
pcl	DEC PCL-11
D 2
un	Ungermann-Bass network w/ DR-11W interface
vv	Proteon ring network (V2LNI)
E 2
I 2
vv	Proteon 10Mb/s and 80Mb/s proNET ring network (V2LNI)
I 4
.TE
.DE
E 4
I 3
.\}
.if \n(Th \{\
I 4
.DS
.TS
l l.
Device name	Manufacturer and product
_
E 4
ace	ACC 10Mb/s Ethernet
enp	CMC 10Mb/s Ethernet
D 4
.\}
E 4
E 3
E 2
.TE
.DE
I 4
.\}
E 4
.PP
D 2
All network interface drivers require some or all of their
host address be defined at boot time.  This is accomplished
with
E 2
I 2
All network interface drivers including the loopback interface,
require that their host address(es) be defined at boot time.
This is done with
E 2
.IR ifconfig (8C)
D 2
commands included in the /etc/rc.local file.
Interfaces which are able to dynamically deduce the host
part of an address, but not the network number, take the
network number from the address specified with
.IR ifconfig .
Hosts which use a more complex address mapping scheme, such
as the Address Resolution Protocol,
.IR arp (4),
require the full address.
E 2
I 2
D 3
commands included in the \fI/etc/rc.local\fP file.
E 3
I 3
commands included in the \fI/etc/netstart\fP file.
E 3
Interfaces that are able to dynamically deduce the host
part of an address may check that the host part of the address is correct.
E 2
The manual page for each network interface
describes the method used to establish a host's address.
D 3
.IR Ifconfig (8)
E 3
I 3
.IR Ifconfig (8C)
E 3
can also be used to set options for the interface at boot time.
D 2
These options include disabling the use of the Address Resolution Protocol
and/or the use of trailer encapsulation; this is useful if a network
is shared with hosts running software which is unable to perform these
functions.
E 2
Options are set independently for each interface, and
apply to all packets sent using that interface.
D 2
An alternative approach to ARP is to divide the address range,
using ARP only for those addresses below the cutoff and using
another mapping above this constant address; see the source
(/sys/netinet/if_ether.c) for more information.
E 2
I 2
These options include disabling the use of the Address Resolution Protocol;
this may be useful if a network is shared with hosts running software
that does not yet provide this function.
Alternatively, translations for such hosts may be set in advance
D 3
or ``published'' by a \*(4B host by use of the
.IR arp (8c)
E 3
I 3
or ``published'' by a \*(B3 host by use of the
.IR arp (8C)
E 3
command.
D 3
Note that the use of trailer link-level is now negotiated between \*(4B hosts
E 3
I 3
Note that the use of trailer link-level is now negotiated between \*(B3 hosts
E 3
using ARP,
and it is thus no longer necessary to disable the use of trailers
with \fIifconfig\fP.
E 2
.PP
D 2
In order to use the pseudo terminals just configured, device
entries must be created in the /dev directory.  To create 16
E 2
I 2
To use the pseudo terminals just configured, device
entries must be created in the /dev directory.  To create 32
E 2
pseudo terminals (plenty, unless you have a heavy network load)
D 2
perform the following commands.
E 2
I 2
execute the following commands.
E 2
.DS
D 3
\fB#\fP cd /dev
D 2
\fB#\fP MAKEDEV pty0
E 2
I 2
\fB#\fP MAKEDEV pty0 pty1
E 3
I 3
\fB#\fP \fIcd /dev\fP
\fB#\fP \fIMAKEDEV pty0 pty1\fP
E 3
E 2
.DE
D 2
More pseudo terminals may be made by specifying \fIpty1\fP, \fIpty2\fP,
E 2
I 2
More pseudo terminals may be made by specifying \fIpty2\fP, \fIpty3\fP,
E 2
etc.  The kernel normally includes support for 32 pseudo terminals
unless the configuration file specifies a different number.
D 2
Each pseudo terminal actually consists of two files in /dev:
E 2
I 2
Each pseudo terminal really consists of two files in /dev:
E 2
a master and a slave.  The master pseudo terminal file is named
D 2
/dev/pty?, while the slave side is /dev/ttyp?.  Pseudo terminals
are also used by the \fIscript\fP\|(1) program.  In addition to
creating the pseudo terminals, be sure to install them in the
E 2
I 2
/dev/ptyp?, while the slave side is /dev/ttyp?.  Pseudo terminals
are also used by several programs not related to the network.
In addition to creating the pseudo terminals,
be sure to install them in the
E 2
.I /etc/ttys
D 2
file (with a `0' in the first column so no
E 2
I 2
file (with a `none' in the second column so no
E 2
.I getty
D 2
is started), and in the 
.I /etc/ttytype
file (with type ``network'').
E 2
I 2
is started).
.NH 2
D 3
Local subnetworks
E 3
I 3
Local subnets
E 3
E 2
.PP
D 2
When configuring multiple networks some thought must be given
to the ordering of the devices in the configuration file.  The first
network interface configured in the system is used as the default
network when the system is forced to assign a local address to
a socket.  This means that your most widely known network should
always be placed first in the configuration file.  For example,
hosts attached to both the ARPANET and our local area
network have devices configured in the order show below.
E 2
I 2
D 3
In \*(4B the DARPA Internet support
includes the notion of ``subnetworks''.  This is a mechanism
E 3
I 3
In \*(B3 the DARPA Internet support
includes the notion of ``subnets''.  This is a mechanism
E 3
by which multiple local networks may appears as a single Internet
network to off-site hosts.  Subnetworks are useful because
they allow a site to hide their local topology, requiring only a single
route in external gateways;
it also means that local network numbers may be locally administered.
The standard describing this change in Internet addressing is RFC-950.
.PP
D 3
To set up local subnetworks one must first decide how the available
E 3
I 3
To set up local subnets one must first decide how the available
E 3
address space (the Internet ``host part'' of the 32-bit address)
is to be partitioned.
Sites with a class A network
D 3
number have a 24-bit address space with which to work,
sites with a class B network number have a 16-bit address space,
while sites with a class C network number have an 8-bit address space*.
E 3
I 3
number have a 24-bit host address space with which to work, sites with a
class B network number have a 16-bit host address space, while sites with
a class C network number have an 8-bit host address space.*
E 3
.FS
* If you are unfamiliar with the Internet addressing structure, consult
``Address Mappings'', Internet RFC-796, J. Postel; available from
the Internet Network Information Center at SRI.
.FE
To define local subnets you must steal some bits
from the local host address space for use in extending the network
portion of the Internet address.  This reinterpretation of Internet
addresses is done only for local networks; i.e. it is not visible
to hosts off-site.  For example, if your site has a class B network
number, hosts on this network have an Internet address that contains
the network number, 16 bits, and the host number, another
16 bits.  To define 254 local subnets, each
possessing at most 255 hosts, 8 bits may be taken from the local part.
(The use of subnets 0 and all-1's, 255 in this example, is discouraged
to avoid confusion about broadcast addresses.)
These new network
numbers are then constructed by concatenating the original 16-bit network
D 3
number with the extra 8 bits containing the local subnetwork number.
E 3
I 3
number with the extra 8 bits containing the local subnet number.
E 3
.PP
D 3
The existence of local subnetworks is communicated to the system at the time a
E 3
I 3
The existence of local subnets is communicated to the system at the time a
E 3
network interface is configured with the
.I netmask
option to the
.I ifconfig
program.  A ``network mask'' is specified to define the
portion of the Internet address that is to be considered the network part
for that network.
This mask normally contains the bits corresponding to the standard
network part as well as the portion of the local part
that has been assigned to subnets.
If no mask is specified when the address is set,
it will be set according to the class of the network.
For example, at Berkeley (class B network 128.32) 8 bits
D 3
of the local part have been reserved for defining subnetworks;
consequently the /etc/rc.local file contains lines of the form
E 3
I 3
of the local part have been reserved for defining subnets;
consequently the /etc/netstart file contains lines of the form
E 3
E 2
.DS
D 2
.ta 1.0i 1.5i 2.0i 2.5i 3.0i 3.5i
device	acc0	at uba? csr 0167600 vector accrint accxint
device	en0	at uba? csr 0161000 vector enxint enrint encollide
E 2
I 2
/etc/ifconfig en0 netmask 0xffffff00 128.32.1.7
E 2
.DE
I 2
This specifies that for interface ``le0'', the upper 24 bits of
the Internet address should be used in calculating network numbers
(netmask 0xffffff00), and the interface's Internet address is
``128.32.1.7'' (host 7 on network 128.32.1).  Hosts \fIm\fP on
sub-network \fIn\fP of this network would then have addresses of
the form ``128.32.\fIn\fP.\fIm\fP'';  for example, host
99 on network 129 would have an address ``128.32.129.99''.
For hosts with multiple interfaces, the network mask should
be set for each interface,
although in practice only the mask of the first interface on each network
is actually used.
E 2
.NH 2
I 2
Internet broadcast addresses
.PP
The address defined as the broadcast address for Internet networks
according to RFC-919 is the address with a host part of all 1's.
The address used by 4.2BSD was the address with a host part of 0.
D 3
\*(4B uses the standard broadcast address (all 1's) by default,
E 3
I 3
\*(B3 uses the standard broadcast address (all 1's) by default,
E 3
but allows the broadcast address to be set (with \fIifconfig\fP)
for each interface.
D 3
This allows networks consisting of both 4.2BSD and \*(4B hosts
E 3
I 3
This allows networks consisting of both 4.2BSD and \*(B3 hosts
E 3
to coexist while the upgrade process proceeds.
In the presence of subnets, the broadcast address uses the subnet field
as for normal host addresses, with the remaining host part set to 1's
(or 0's, on a network that has not yet been converted).
D 3
\*(4B hosts recognize and accept packets
E 3
I 3
\*(B3 hosts recognize and accept packets
E 3
sent to the logical-network broadcast address as well as those sent
to the subnet broadcast address, and when using an all-1's broadcast,
also recognize and receive packets sent to host 0 as a broadcast.
.NH 2
Routing
.PP
If your environment allows access to networks not directly
attached to your host you will need to set up routing information
to allow packets to be properly routed.  Two schemes are
supported by the system.  The first scheme
employs the routing table management daemon \fI/etc/routed\fP
to maintain the system routing tables.  The routing daemon
uses a variant of the Xerox Routing Information Protocol
to maintain up to date routing tables in a cluster of local
area networks.  By using the \fI/etc/gateways\fP
file created by
.IR htable (8),
the routing daemon can also be used to initialize static routes
to distant networks (see the next section for further discussion).
When the routing daemon is started up
D 3
(usually from \fI/etc/rc.local\fP) it reads \fI/etc/gateways\fP if it exists
E 3
I 3
(usually from \fI/etc/rc\fP) it reads \fI/etc/gateways\fP if it exists
E 3
and installs those routes defined there, then broadcasts on each local network
to which the host is attached to find other instances of the routing
daemon.  If any responses are received, the routing daemons
cooperate in maintaining a globally consistent view of routing
in the local environment.  This view can be extended to include
remote sites also running the routing daemon by setting up suitable
entries in \fI/etc/gateways\fP; consult
.IR routed (8C)
for a more thorough discussion.
.PP
The second approach is to define a default or wildcard
route to a smart
gateway and depend on the gateway to provide ICMP routing
redirect information to dynamically create a routing data
base.  This is done by adding an entry of the form
.DS
/etc/route add default \fIsmart-gateway\fP 1
.DE
D 3
to \fI/etc/rc.local\fP; see
E 3
I 3
to \fI/etc/netstart\fP; see
E 3
.IR route (8C)
for more information.  The default route
will be used by the system as a ``last resort''
in routing packets to their destination.  Assuming the gateway
to which packets are directed is able to generate the proper
routing redirect messages, the system will then add routing
table entries based on the information supplied.  This approach
has certain advantages over the routing daemon, but is
unsuitable in an environment where there are only bridges (i.e.
pseudo gateways that, for instance, do not generate routing
redirect messages).  Further, if the
smart gateway goes down there is no alternative, save manual
alteration of the routing table entry, to maintaining service.
.PP
The system always listens, and processes, routing redirect
information, so it is possible to combine both of the above
facilities.  For example, the routing table management process
might be used to maintain up to date information about routes
to geographically local networks, while employing the wildcard
routing techniques for ``distant'' networks.  The
.IR netstat (1)
program may be used to display routing table contents as well
as various routing oriented statistics.  For example,
.DS
D 3
\fB#\fP\|netstat \-r
E 3
I 3
\fB#\fP \fInetstat \-r\fP
E 3
.DE
will display the contents of the routing tables, while
.DS
D 3
\fB#\fP\|netstat \-r \-s
E 3
I 3
\fB#\fP \fInetstat \-r \-s\fP
E 3
.DE
will show the number of routing table entries dynamically
created as a result of routing redirect messages, etc.
.NH 2
D 3
Use of \*(4B machines as gateways
E 3
I 3
Use of \*(B3 machines as gateways
E 3
.PP
D 3
Several changes have been made in \*(4B in the area of gateway support
E 3
I 3
Several changes have been made in \*(B3 in the area of gateway support
E 3
(or packet forwarding, if one prefers).
A new configuration option, GATEWAY, is used when configuring
a machine to be used as a gateway.
This option increases the size of the routing hash tables in the kernel.
Unless configured with that option,
hosts with only a single non-loopback interface never attempt
to forward packets or to respond with ICMP error messages to misdirected
packets.
This change reduces the problems that may occur when different hosts
on a network disagree as to the network number or broadcast address.
D 3
Another change is that \*(4B machines that forward packets back through
E 3
I 3
Another change is that \*(B3 machines that forward packets back through
E 3
the same interface on which they arrived
will send ICMP redirects to the source host if it is on the same network.
D 3
This improves the interaction of \*(4B gateways with hosts that configure
E 3
I 3
This improves the interaction of \*(B3 gateways with hosts that configure
E 3
their routes via default gateways and redirects.
The generation of redirects may be disabled with the configuration option
IPSENDREDIRECTS=0 in environments where it may cause difficulties.
.PP
Local area routing within a group of interconnected Ethernets
and other such networks may be handled by
D 3
.IR routed (8c).
E 3
I 3
.IR routed (8C).
E 3
Gateways between the Arpanet or Milnet and one or more local networks
require an additional routing protocol, the Exterior Gateway Protocol (EGP),
to inform the core gateways of their presence
and to acquire routing information from the core.
D 3
An EGP implementation for 4.2BSD was done by Paul Kirton
while visiting ISI, and any sites requiring such support that have not
already obtained a copy should contact Joyce Reynolds (JKReynolds@usc-isif.arpa)
for information.
That implementation works with \*(4B without kernel modifications.
It must be modified, as packets from the ICMP raw socket include
the IP header like other raw sockets in \*(4B.
If necessary, contact the Berkeley Computer Systems Research Group
for assistance.
E 3
I 3
An EGP implementation for \*(B3 is available
by anonymous ftp from ucbarpa.berkeley.edu.  If necessary, contact the
Berkeley Computer Systems Research Group for assistance.
E 3
.NH 2
I 3
Network data bases
.PP
Several data files are used by the network library routines
and server programs.  Most of these files are host independent
and updated only rarely.
.br
.ne 1i
.DS
.TS
l l l.
File	Manual reference	Use
_
/etc/hosts	\fIhosts\fP\|(5)	host names
/etc/networks	\fInetworks\fP\|(5)	network names
/etc/services	\fIservices\fP\|(5)	list of known services
/etc/protocols	\fIprotocols\fP\|(5)	protocol names
/etc/hosts.equiv	\fIrshd\fP\|(8C)	list of ``trusted'' hosts
/etc/netstart	\fIrc\fP\|(8)	command script for initializing network
/etc/rc	\fIrc\fP\|(8)	command script for starting standard servers
/etc/rc.local	\fIrc\fP\|(8)	command script for starting local servers
/etc/ftpusers	\fIftpd\fP\|(8C)	list of ``unwelcome'' ftp users
/etc/hosts.lpd	\fIlpd\fP\|(8C)	list of hosts allowed to access printers
/etc/inetd.conf	\fIinetd\fP\|(8)	list of servers started by \fIinetd\fP
.TE
.DE
The files distributed are set up for ARPANET or other Internet hosts.
Local networks and hosts should be added to describe the local
configuration; the Berkeley entries may serve as examples
(see also the section on on /etc/hosts).
Network numbers will have to be chosen for each Ethernet.
For sites connected to the Internet,
the normal channels should be used for allocation of network
numbers (contact hostmaster@SRI-NIC.ARPA).
For other sites,
these could be chosen more or less arbitrarily,
but it is generally better to request official numbers
to avoid conversion if a connection to the Internet (or others on the Internet)
is ever established.
.NH 3
E 3
Network servers
.PP
D 3
In \*(4B most of the server programs are started up by a
E 3
I 3
Most network servers are automatically started up at boot time
by the command file /etc/rc
or by the Internet daemon (see below).
These include the following:
.DS
.TS
l l l.
Program	Server	Started by
_
/etc/syslogd	error logging server	/etc/rc
/etc/named	Internet name server	/etc/rc
/etc/routed	routing table management daemon	/etc/rc
/etc/rwhod	system status daemon	/etc/rc
/etc/timed	time synchronization daemon	/etc/rc.local
/usr/lib/sendmail	SMTP server	/etc/rc.local
/etc/rshd	shell server	inetd
/etc/rexecd	exec server	inetd
/etc/rlogind	login server	inetd
/etc/telnetd	TELNET server	inetd
/etc/ftpd	FTP server	inetd
/etc/fingerd	Finger server	inetd
/etc/tftpd	TFTP server	inetd
.TE
.DE
Consult the manual pages and accompanying documentation (particularly
for named and sendmail) for details about their operation.
.PP
The use of \fIrouted\fP and \fIrwhod\fP is controlled by shell
variables set in /etc/netstart.
By default, \fIrouted\fP is used, but \fIrwhod\fP is not;
they are enabled by setting the variables \fIroutedflags\fP
and \fIrwhod\fP to strings other than ``NO.''
The value of \fIroutedflags\fP is used to provide host-specific options
to \fIrouted\fP.
For example,
.DS
routedflags=-q
rwhod=NO
.DE
would run \fIrouted -q\fP and would not run \fIrwhod\fP.
.PP
To have other network servers started as well,
commands of the following sort should be placed in the site-dependent
file \fI/etc/rc.local\fP.
.DS
if [ -f /etc/timed ]; then
	/etc/timed & echo -n ' timed'			>/dev/console
f\&i
.DE
.NH 3
Internet daemon
.PP
In \*(B3 most of the servers for user-visible services are started up by a
E 3
``super server'', the Internet daemon.  The Internet
daemon, \fI/etc/inetd\fP, acts as a master server for
programs specified in its configuration file, \fI/etc/inetd.conf\fP,
listening for service requests for these servers, and starting
up the appropriate program whenever a request is received.
The configuration file contains lines containing a service
name (as found in \fI/etc/services\fP), the type of socket the
server expects (e.g. stream or dgram), the protocol to be
used with the socket (as found in \fI/etc/protocols\fP), whether
to wait for each server to complete before starting up another,
the user name as which the server should run, the server
program's name, and at most five arguments to pass to the
server program.
Some trivial services are implemented internally in \fIinetd\fP,
and their servers are listed as ``internal.''
For example, an entry for the file
transfer protocol server would appear as
.DS
ftp	stream	tcp	nowait	root	/etc/ftpd	ftpd
.DE
Consult
D 3
.IR inetd (8c)
E 3
I 3
.IR inetd (8C)
E 3
for more detail on the format of the configuration file
and the operation of the Internet daemon.
D 3
.NH 2
E 2
Network data bases
.PP
D 2
A number of data files are used by the network library routines
E 2
I 2
Several data files are used by the network library routines
E 2
and server programs.  Most of these files are host independent
and updated only rarely.
.DS
.TS
l l l.
File	Manual reference	Use
_
/etc/hosts	\fIhosts\fP\|(5)	host names
/etc/networks	\fInetworks\fP\|(5)	network names
/etc/services	\fIservices\fP\|(5)	list of known services
/etc/protocols	\fIprotocols\fP\|(5)	protocol names
/etc/hosts.equiv	\fIrshd\fP\|(8C)	list of ``trusted'' hosts
/etc/rc.local	\fIrc\fP\|(8)	command script for starting servers
/etc/ftpusers	\fIftpd\fP\|(8C)	list of ``unwelcome'' ftp users
I 2
/etc/hosts.lpd	\fIlpd\fP\|(8C)	list of hosts allowed to access printers
/etc/inetd.conf	\fIinetd\fP\|(8)	list of servers started by \fIinetd\fP
E 2
.TE
.DE
The files distributed are set up for ARPANET or other Internet hosts.
Local networks and hosts should be added to describe the local
configuration; the Berkeley entries may serve as examples
(see also the next section).
D 2
Network numbers will have to be chosen for each ethernet.
E 2
I 2
Network numbers will have to be chosen for each Ethernet.
E 2
For sites not connected to the Internet,
these can be chosen more or less arbitrarily,
otherwise the normal channels should be used for allocation of network
numbers.
E 3
.NH 3
Regenerating /etc/hosts and /etc/networks
.PP
D 2
The host and network name data bases are normally derived from
E 2
I 2
When using the host address routines that use the Internet name server,
the file \fI/etc/hosts\fP is only used for setting interface addresses
and at other times that the server is not running,
and therefore it need only contain addresses for local hosts.
There is no equivalent service for network names yet.
The full host and network name data bases are normally derived from
E 2
a file retrieved from the Internet Network Information Center at
D 2
SRI.  To do this you should use the program /etc/gettable
to retrieve the NIC host data base, and the program /etc/htable
E 2
I 2
SRI.
To do this you should use the program /etc/gettable
to retrieve the NIC host data base, and the program
.IR htable (8)
E 2
to convert it to the format used by the libraries.
I 2
You should change to the directory where you maintain your local
additions to the host table and execute the following commands.
E 2
.DS
D 2
\fB#\fP cd /usr/src/ucb/netser/htable
\fB#\fP /etc/gettable sri-nic
\fBConnection to sri-nic opened.\fP
E 2
I 2
D 3
\fB#\fP /etc/gettable sri-nic.arpa
E 3
I 3
\fB#\fP \fI/etc/gettable sri-nic.arpa\fP
E 3
\fBConnection to sri-nic.arpa opened.\fP
E 2
\fBHost table received.\fP
D 2
\fBConnection to sri-nic closed.\fP
E 2
I 2
\fBConnection to sri-nic.arpa closed.\fP
E 2
D 3
\fB#\fP /etc/htable hosts.txt
E 3
I 3
\fB#\fP \fI/etc/htable hosts.txt\fP
E 3
\fBWarning, no localgateways file.\fP
\fB#\fP
.DE
D 2
The \fIhtable\fP program generates two files of interest
in the local directory: \fIhosts\fP and \fInetworks\fP.  If
a file ``localhosts'' is present in the working directory its
E 2
I 2
The \fIhtable\fP program generates three files
in the local directory: \fIhosts\fP, \fInetworks\fP and \fIgateways\fP.
If a file ``localhosts'' is present in the working directory its
E 2
contents are first copied to the output file.  Similarly, a
``localnetworks'' file may be prepended to the output created
D 2
by \fIhtable\fP.  It is usually wise to run \fIdiff\fP\|(1) on
the new host and network data bases before installing them in
/etc.
E 2
I 2
by \fIhtable\fP,
and `localgateways'' will be prepended to \fIgateways\fP.
It is usually wise to run \fIdiff\fP\|(1) on
the new host and network data bases before installing them in /etc.
If you are using the host table for host name and address
mapping, you should run \fImkhosts\fP\|(8) after installing
\fI/etc/hosts\fP.
If you are using the name server for the host name and address mapping,
you only need to install \fInetworks\fP and a small copy of \fIhosts\fP
describing your local machines.  The full host table in this case might
be placed somewhere else for reference by users.
The gateways file may be installed in \fI/etc/gateways\fP if you use
D 3
.IR routed (8c)
E 3
I 3
.IR routed (8C)
E 3
for local routing and wish to have static external routes installed
when \fIrouted\fP is started.
This procedure is essentially obsolete, however, except for individual hosts
that are on the Arpanet or Milnet and do not forward packets from a local
network.
Other situations require the use of an EGP server.
.PP
If you are connected to the DARPA Internet, it is highly recommended that
you use the name server for your host name and address mapping, as this
provides access to a much larger set of hosts than are provided in the
D 3
host table.  Many large organization on the network, currently have
E 3
I 3
host table.  Many large organizations on the network currently have
E 3
only a small percentage of their hosts listed in the host table retrieved
from NIC.
E 2
.NH 3
/etc/hosts.equiv
.PP
The remote login and shell servers use an
D 2
authentication scheme based on trusted hosts.  The hosts.equiv
file contains a list of hosts which are considered trusted
and/or, under a single administrative control.  When a user
E 2
I 2
authentication scheme based on trusted hosts.  The \fIhosts.equiv\fP
file contains a list of hosts that are considered trusted
and, under a single administrative control.  When a user
E 2
contacts a remote login or shell server requesting service,
the client process passes the user's name and the official
name of the host on which the client is located.  In the simple
D 2
case, if the hosts's name is located in hosts.equiv and
E 2
I 2
case, if the host's name is located in \fIhosts.equiv\fP and
E 2
the user has an account on the server's machine, then service
is rendered (i.e. the user is allowed to log in, or the command
D 2
is executed).  Users may constrain this ``equivalence'' of
machines by installing a .rhosts file in their login directory.
The root login is handled specially, bypassing the hosts.equiv
file, and using only the /.rhosts file.
E 2
I 2
is executed).  Users may expand this ``equivalence'' of
machines by installing a \fI.rhosts\fP file in their login directory.
The root login is handled specially, bypassing the \fIhosts.equiv\fP
file, and using only the \fI/.rhosts\fP file.
E 2
.PP
D 2
Thus, to create a class of equivalent machines, the hosts.equiv
E 2
I 2
Thus, to create a class of equivalent machines, the \fIhosts.equiv\fP
E 2
file should contain the \fIofficial\fP names for those machines.
D 2
For example, most machines on our major local
network are considered trusted, so the hosts.equiv file is
E 2
I 2
If you are running the name server, you may omit the domain part
of the host name for machines in your local domain.
D 3
For example, several machines on our local
E 3
I 3
For example, four machines on our local
E 3
network are considered trusted, so the \fIhosts.equiv\fP file is
E 2
of the form:
.DS
ucbarpa
D 2
ucbcalder
ucbdali
ucbernie
ucbkim
ucbmatisse
ucbmonet
E 2
I 2
D 3
calder
dali
ernie
kim
matisse
E 3
I 3
okeeffe
E 3
monet
E 2
ucbvax
D 2
ucbmiro
ucbdegas
E 2
I 2
D 3
miro
degas
E 3
E 2
.DE
.NH 3
D 3
/etc/rc.local
.PP
Most network servers are automatically started up at boot time
by the command file /etc/rc (if they are installed in their
D 2
presumed locations).  These include the following:
E 2
I 2
presumed locations) or by the Internet daemon (see above).
These include the following:
E 2
.DS
.TS
D 2
l l.
/etc/rshd	shell server
/etc/rexecd	exec server
/etc/rlogind	login server
/etc/rwhod	system status daemon
E 2
I 2
l l l.
Program	Server	Started by
_
/etc/rshd	shell server	inetd
/etc/rexecd	exec server	inetd
/etc/rlogind	login server	inetd
/etc/telnetd	TELNET server	inetd
/etc/ftpd	FTP server	inetd
/etc/fingerd	Finger server	inetd
/etc/tftpd	TFTP server	inetd
/etc/rwhod	system status daemon	/etc/rc
/etc/syslogd	error logging server	/etc/rc
/usr/lib/sendmail	SMTP server	/etc/rc
/etc/routed	routing table management daemon	/etc/rc
E 2
.TE
.DE
D 2
To have other network servers started up as well, commands
of the following sort should be placed in the site dependent
file /etc/rc.local.
E 2
I 2
Consult the manual pages and accompanying documentation (particularly
for sendmail) for details about their operation.
.PP
To have other network servers started up as well,
the appropriate line should be added
to the Internet daemon's configuration file \fI/etc/inetd.conf\fP, or
commands of the following sort should be placed in the site dependent
file \fI/etc/rc.local\fP.
E 2
.DS
D 2
if [ -f /etc/telnetd ]; then
	/etc/telnetd & echo -n ' telnetd'			>/dev/console
E 2
I 2
if [ -f /etc/routed ]; then
	/etc/routed & echo -n ' routed'			>/dev/console
E 2
f\&i
.DE
D 2
The following servers are included with the system and should
be installed in /etc/rc.local as the need arises.
.DS
.TS
l l.
/etc/telnetd	TELNET server
/etc/ftpd	FTP server
/etc/tftpd	TFTP server
/etc/syslog	error logging server
/etc/sendmail	SMTP server
/etc/courierd	Courier remote procedure call server
/etc/routed	routing table management daemon
.TE
.DE
Consult the manual pages and accompanying documentation (particularly
for sendmail) for details about their operation.
E 2
.NH 3
E 3
/etc/ftpusers
.PP
The FTP server included in the system provides support for an
D 2
anonymous FTP account.  Due to the inherent security problems
E 2
I 2
anonymous FTP account.  Because of the inherent security problems
E 2
with such a facility you should read this section carefully if
you consider providing such a service.
.PP
An anonymous account is enabled by creating a user \fIftp\fP.
When a client uses the anonymous account a \fIchroot\fP\|(2)
system call is performed by the server to restrict the client
from moving outside that part of the file system where the
D 2
user ftp home directory is located.  Because a chroot call
is used, certain programs and files must be supplied the server
process for it to execute properly.  Further, one must be
E 2
I 2
user ftp home directory is located.  Because a \fIchroot\fP call
is used, certain programs and files used by the server 
process must be placed in the ftp home directory. 
Further, one must be
E 2
sure that all directories and executable images are unwritable.
D 3
The following directory setup is recommended.
E 3
I 3
The following directory setup is recommended.  The
use of the \fIawk\fP commands to copy the /etc/passwd and /etc/group
files are \fBSTRONGLY\fP recommended.
E 3
.DS
D 3
\fB#\fP cd ~ftp
\fB#\fP chmod 555 .; chown ftp .; chgrp ftp .
\fB#\fP mkdir bin etc pub
\fB#\fP chown root bin etc
\fB#\fP chmod 555 bin etc
\fB#\fP chown ftp pub
\fB#\fP chmod 777 pub
\fB#\fP cd bin
\fB#\fP cp /bin/sh /bin/ls .
\fB#\fP chmod 111 sh ls
\fB#\fP cd ../etc
\fB#\fP cp /etc/passwd /etc/group .
\fB#\fP chmod 444 passwd group
E 3
I 3
\fB#\fP \fIcd ~ftp\fP
\fB#\fP \fIchmod 555 .; chown ftp .; chgrp ftp .\fP
\fB#\fP \fImkdir bin etc pub\fP
\fB#\fP \fIchown root bin etc\fP
\fB#\fP \fIchmod 555 bin etc\fP
\fB#\fP \fIchown ftp pub\fP
\fB#\fP \fIchmod 777 pub\fP
\fB#\fP \fIcd bin\fP
\fB#\fP \fIcp /bin/sh /bin/ls .\fP
\fB#\fP \fIchmod 111 sh ls\fP
\fB#\fP \fIcd ../etc\fP
\fB#\fP \fIawk -F: '{$2="*";print$1":"$2":"$3":"$4":"$5":"$6":"}' < /etc/passwd > passwd\fP
\fB#\fP \fIawk -F: '{$2="*";print$1":"$2":"}' < /etc/group > group\fP
\fB#\fP \fIchmod 444 passwd group\fP
E 3
.DE
When local users wish to place files in the anonymous
area, they must be placed in a subdirectory.  In the
D 2
setup here, the directory ~ftp/pub is used.
E 2
I 2
setup here, the directory \fI~ftp/pub\fP is used.
E 2
.PP
I 2
D 3
Another issue to consider is the copy of \fI/etc/passwd\fP
placed here.  It may be copied by users who use the
anonymous account.  They may then try to break the 
passwords of users on your machine for further access.
A good choice of users to include in this copy might
be root, daemon, uucp, and the ftp user.  All passwords
here should probably be ``*''.
.PP
E 3
E 2
Aside from the problems of directory modes and such,
the ftp server may provide a loophole for interlopers
D 2
if certain user accounts are allowed.  The
file /etc/ftpusers is checked on each connection.  If
the requested user name is located in the file, the
E 2
I 2
if certain user accounts are allowed.
The file \fI/etc/ftpusers\fP is checked on each connection.
If the requested user name is located in the file, the
E 2
request for service is denied.  This file normally has
the following names on our systems.
.DS
uucp
root
.DE
D 2
Accounts with nonstandard shells and no passwords (e.g., who or finger)
should also be listed in this file to prevent their use as anonymous
accounts with ftp.
.NH 2
Routing and gateways/bridges
.PP
If your environment allows access to networks not directly
attached to your host you will need to set up routing information
to allow packets to be properly routed.  Two schemes are
supported by the system.  The first scheme
employs the routing table management daemon /etc/routed
to maintain the system routing tables.  The routing daemon
uses a variant of the Xerox Routing Information Protocol
to maintain up to date routing tables in a cluster of local
area networks.  By using the /etc/gateways
file created by /etc/htable,
the routing daemon can also be used to initialize static routes
to distant networks.  When the routing daemon is started up
(usually from /etc/rc.local) it reads /etc/gateways and installs
those routes defined there, then broadcasts on each local network
to which the host is attached to find other instances of the routing
daemon.  If any responses are received, the routing daemons
cooperate in maintaining a globally consistent view of routing
in the local environment.  This view can be extended to include
remote sites also running the routing daemon by setting up suitable
entries in /etc/gateways; consult
.IR routed (8C)
for a more thorough discussion.
.PP
The second approach is to define a wildcard route to a smart
gateway and depend on the gateway to provide ICMP routing
redirect information to dynamically create a routing data
base.  This is done by adding an entry of the form
.DS
/etc/route add 0 \fIsmart-gateway\fP 1
.DE
to /etc/rc.local; see
.IR route (8C)
for more information.  The wildcard route, indicated by a 0 valued
destination, will be used by the system as a ``last resort''
in routing packets to their destination.  Assuming the gateway
to which packets are directed is able to generate the proper
routing redirect messages, the system will then add routing
table entries based on the information supplied.  This approach
has certain advantages over the routing daemon, but is
unsuitable in an environment where their are only bridges (i.e.
pseudo gateways which, for instance, do not generate routing
redirect messages).  Further, if the
smart gateway goes down there is no alternative, save manual
alteration of the routing table entry, to maintaining service.
.PP
The system always listens, and processes, routing table redirect
information, so it is possible to combine both the above
facilities.  For example, the routing table management process
might be used to maintain up to date information about routes
to geographically local networks, while employing the wildcard
routing techniques for ``distant'' networks.  The
.IR netstat (1)
program may be used to display routing table contents as well
as various routing oriented statistics.  For example,
.DS
\fB#\fP\|netstat \-r
.DE
will display the contents of the routing tables, while
.DS
\fB#\fP\|netstat \-r \-s
.DE
will show the number of routing table entries dynamically
created as a result of routing redirect messages, etc.
E 2
I 2
D 3
Accounts with nonstandard shells should be listed in
this file.  Accounts without passwords
need not be listed in this file, the ftp server will
not service these users.
E 3
I 3
Accounts without passwords need not be listed in this file as the ftp
server will refuse service to these users.
Accounts with nonstandard shells (any not listed in /etc/shells)
will also be denied access via ftp.
E 3
E 2
E 1

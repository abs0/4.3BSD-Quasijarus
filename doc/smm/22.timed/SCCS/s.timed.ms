h43687
s 00050/00081/00427
d D 6.2 86/06/04 14:23:19 bloom 2 1
c final copy
e
s 00508/00000/00000
d D 6.1 86/05/23 18:30:07 mckusick 1 0
c first draft for distribution in 4.3BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1986 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
.TL
D 2
The Berkeley UNIX
E 2
I 2
The Berkeley
.UX
E 2
.br
Time Synchronization Protocol
.AU
Riccardo Gusella, Stefano Zatti, and James M. Bloom
.AI
Computer Systems Research Group
Computer Science Division
Department of Electrical Engineering and Computer Science
University of California, Berkeley
Berkeley, CA 94720
.FS
This work was sponsored by the Defense Advanced Research Projects Agency
(DoD), monitored by the Naval Electronics Systems
Command under contract No. N00039-84-C-0089, and by the Italian CSELT 
Corporation.
The views and conclusions contained in this document are those of the
authors and should not be interpreted as representing official policies,
either expressed or implied, of the Defense Research Projects Agency,
of the US Government, or of CSELT.
.FE
.LP
.OH 'The Berkeley UNIX Time Synchronization Protocol''SMM:22-%'
.EH 'SMM:22-%''The Berkeley UNIX Time Synchronization Protocol'
.SH 
Introduction
.PP
The Time Synchronization Protocol (TSP) 
has been designed for specific use by the program \fItimed\fP,
a local area network clock synchronizer for 
the UNIX 4.3BSD operating
system.
D 2
\fITimed\fP is built on the DARPA UDP protocol and 
E 2
I 2
Timed is built on the DARPA UDP protocol [4] and
E 2
is based on a master slave scheme.
.PP
TSP serves a dual purpose.
First, it supports messages for the synchronization of the clocks 
of the various hosts in a local area network.
Second, it supports messages for the election that occurs
among slave time daemons when, for any reason, the master disappears.
The synchronization mechanism and the election procedure 
D 2
employed by the program \fItimed\fP are described 
E 2
I 2
employed by the program timed are described 
E 2
in other documents [1,2,3].
.PP
Briefly, the synchronization software, which works in a 
local area network, consists of a collection of \fItime daemons\fP
(one per machine) and is based on a master-slave
structure.
The present implementation keeps processor clocks synchronized 
within 20 milliseconds.
A \fImaster time daemon\fP measures the time
difference between the clock of the machine on which it 
D 2
is running and those of all other machines.
E 2
I 2
is running and those of all other machines.  The current implementation
uses ICMP \fITime Stamp Requests\fP [5] to measure the clock difference
between machines.
E 2
The master computes the \fInetwork time\fP as the average of the 
times provided by nonfaulty clocks.\**
.FS
A clock is considered to be faulty when its value 
is more than a small specified
interval apart from the majority of the clocks 
of the machines on the same network.
See [1,2] for more details.
.FE
It then sends to each \fIslave time daemon\fP the
correction that should be performed on the clock of its machine.
This process is repeated periodically.
Since the correction is expressed as a time difference rather than an 
absolute time, transmission delays do not interfere with synchronization.
When a machine comes up and joins the network,
it starts a slave time daemon, which
will ask the master for the correct time and will reset the machine's clock
before any user activity can begin.
The time daemons therefore maintain a single network time in spite of 
the drift of clocks away from each other. 
.PP
D 2
There is one other mode in which a time daemon may run, \fIsubmaster\fP.
A \fIsubmaster timed daemon\fP is located only on gateways between networks.
It functions as if it were a slave on one network, and a master on other
networks.  This time daemon is indistinguishable from any other time daemon
in the same state except for adjusting time.  In this case, the
\fIsubmaster time daemon\fP receives an adjustment from the master on the
network on which is a slave, measures the difference between its time and
its slaves, and sends out adjustments based upon the sum of these two
corrections.
E 2
I 2
Additionally, a time daemon on gateway machines may run as 
a \fIsubmaster\fP.
A submaster time daemon functions as a slave on one network that
already has a master and as master on other networks.
In addition, a submaster is responsible for propagating broadcast
packets from one network to the other.
E 2
.PP
To ensure that service provided is continuous and reliable,
it is necessary to implement an election algorithm that will elect a
new master should the machine running the current master crash, the master
terminate (for example, because of a run-time error), or the network be
partitioned.
Under our algorithm, slaves are able to realize when the master has
stopped functioning and to elect a new master from among themselves.
D 2
It is important to note that, since the failure of the master results
E 2
I 2
It is important to note that since the failure of the master results
E 2
only in a gradual divergence of clock values, the election
need not occur immediately.
I 2
.PP
E 2
All the communication occurring among time daemons uses the TSP
protocol.
D 2
.PP
E 2
While some messages need not be sent in a reliable way,
D 2
most communication in TSP does require reliability.
E 2
I 2
most communication in TSP requires reliability not provided by the underlying
protocol.
E 2
Reliability is achieved by the use of acknowledgements, sequence numbers, and
retransmission when message losses occur.
D 2
When a message that requires acknowledgment is not acknowledged,
the time daemon which has sent the message will assume that the
E 2
I 2
When a message that requires acknowledgment is not acknowledged after
multiple attempts,
the time daemon that has sent the message will assume that the
E 2
addressee is down.
This document will not describe the details of how reliability is
implemented, but will only point out when
a message type requires a reliable transport mechanism.
.PP
The message format in TSP is the same for all message types;
however, in some instances, one or more fields are not used. 
The next section describes the message format.
The following sections describe
in detail the different message types, their use and the contents
D 2
of each field.
E 2
I 2
of each field.  NOTE:  The message format is likely to change in
future versions of timed.
E 2
.sp 2
.SH
Message Format
.PP
All fields are based upon 8-bit bytes.  Fields should be sent in
D 2
internet byte order if they are more than one byte long.
E 2
I 2
network byte order if they are more than one byte long.
E 2
The structure of a TSP message is the following:
.IP 1)
A one byte message type.
.IP 2)
D 2
A one byte version number, specifying the protocol version to which a
message refers.
E 2
I 2
A one byte version number, specifying the protocol version which the
message uses.
E 2
.IP 3)
A two byte sequence number to be used for recognizing duplicate messages
D 2
that occur when acknowledgments are lost.
E 2
I 2
that occur when messages are retransmitted.
E 2
.IP 4)
Eight bytes of packet specific data.  This field contains two 4 byte time
values, a one byte hop count, or may be unused depending on the type
of the packet.
.IP 5)
D 2
A null-terminated string of up to 256 characters with the name of 
E 2
I 2
A zero-terminated string of up to 256 \s-2ASCII\s+2 characters with the name of 
E 2
the machine sending the message.
.PP
The following charts describe the message types,
show their fields, and explain their usages.
For the purpose of the following discussion, a time daemon can 
be considered to be in
D 2
one of three states: slave, master, or candidate.
Also, the word \fIbroadcast\fP refers to
E 2
I 2
one of three states: slave, master, or candidate for election to master.
Also, the term \fIbroadcast\fP refers to
E 2
the sending of a message to all active time daemons.
.sp 1
.DS L
.SH
Adjtime Message
.so time
.LP
Type: TSP_ADJTIME (1)
.sp 1
D 2
.LP
Description:
E 2
.PP
The master sends this message to a slave to communicate 
the difference between 
the clock of the slave and
the network time the master has just computed. 
The slave will accordingly
adjust the time of its machine.
This message requires an acknowledgment.
.sp 1
.DE
.DS L
.SH
Acknowledgment Message
.so unused
.LP
Type: TSP_ACK (2)
.sp 1
D 2
.LP
Description:
E 2
.PP
Both the master and the slaves use this message for
acknowledgment only.
It is used in several different contexts, for example
in reply to an Adjtime message.
.sp 1
.DE
.DS L
.SH
Master Request Message
.so unused
.LP
Type: TSP_MASTERREQ (3)
.sp 1
D 2
.LP
Description:
E 2
.PP
A newly-started time daemon broadcasts this message to
locate a master.  No other action is implied by this packet.
It requires a Master Acknowledgment.
.sp 1
.DE
.DS L
.SH
Master Acknowledgement
.so unused
.LP
Type: TSP_MASTERACK (4)
.sp 1
D 2
.LP
Description:
E 2
.PP
The master sends this message to acknowledge the Master Request message
and the Conflict Resolution Message.
.sp 1
.DE
.DS L
.SH
Set Network Time Message
D 2
.so time
E 2
I 2
.so date
E 2
.LP
Type: TSP_SETTIME (5)
.sp 1
D 2
.LP
Description:
E 2
.PP
D 2
The master sends this message to a newly-started time slave to set its time.
E 2
I 2
The master sends this message to slave time daemons to set their time.
This packet is sent to newly started time daemons and when the network
date is changed.
E 2
It contains the master's time as an approximation of the network time.
It requires an acknowledgment.
The next
synchronization round will eliminate the small time difference
caused by the random delay in the communication channel.
.sp 1
.DE
.DS L
.SH
Master Active Message
.so unused
.LP
Type: TSP_MASTERUP (6)
.sp 1
D 2
.LP
Description:
E 2
.PP
The master broadcasts this message to 
solicit the names of the active slaves.
Slaves will reply with a Slave Active message.
.sp 1
.DE
.DS L
.SH
Slave Active Message
.so unused
.LP
Type: TSP_SLAVEUP (7)
.sp 1
D 2
.LP
Description:
E 2
.PP
A slave sends this message to the master in answer to a Master Active message.
D 2
This message is also send when a new slave starts up to inform the master that
E 2
I 2
This message is also sent when a new slave starts up to inform the master that
E 2
it wants to be synchronized.
.sp 1
.DE
.DS L
.SH
Master Candidature Message
.so unused
.LP
Type: TSP_ELECTION (8)
.sp 1
D 2
.LP
Description:
E 2
.PP
A slave eligible to become a master broadcasts this message when its election
timer expires.
The message declares that the slave wishes to become the new master.
.sp 1
.DE
.DS L
.SH
Candidature Acceptance Message
.so unused
.LP
Type: TSP_ACCEPT (9)
.sp 1
D 2
.LP
Description:
E 2
.PP
A slave sends this message to accept the candidature of the time daemon
that has broadcast an Election message.
The candidate will add the slave's name to the list of machines that it
will control should it become the master.
.sp 1
.DE
.DS L
.SH
Candidature Rejection Message
.so unused
.LP
Type: TSP_REFUSE (10)
.sp 1
D 2
.LP
Description:
E 2
.PP
After a slave accepts the candidature of a time daemon, it will reply
to any election messages from other slaves
with this message.
This rejects any candidature other than the first received.
.sp 1
.DE
.DS L
.SH
Multiple Master Notification Message
.so unused
.LP
Type: TSP_CONFLICT (11)
.sp 1
D 2
.LP
Description:
E 2
.PP
When two or more masters reply to a Master Request message, the slave
uses this message to inform one of them that more than one master exists.
.sp 1
.DE
.DS L
.SH
Conflict Resolution Message 
.so unused
.LP
Type: TSP_RESOLVE (12)
.sp 1
D 2
.LP
Description:
E 2
.PP
A master which has been informed of the existence of other masters
D 2
sends this message to determine who the other masters are.
E 2
I 2
broadcasts this message to determine who the other masters are.
E 2
.sp 1
.DE
.DS L
.SH
Quit Message
.so unused
.LP
Type: TSP_QUIT (13)
.sp 1
D 2
.LP
Description:
E 2
.PP
This message is sent by the master in three different contexts:
D 2
1) to a candidate that broadcasts an Election message,
E 2
I 2
1) to a candidate that broadcasts an Master Candidature message,
E 2
2) to another master when notified of its existence,
3) to another master if a loop is detected.
D 2
In both cases, the two time daemons will become slaves.
E 2
I 2
In all cases, the recipient time daemon will become a slave.
E 2
This message requires an acknowledgement.
.sp 1
.DE
.DS L
.SH
Set Date Message
.so date
.LP
Type: TSP_SETDATE (22)
.sp 1
D 2
.LP
Description:
E 2
.PP
D 2
The program \fIdate(1)\fP sends this message to the local time daemon
E 2
I 2
The program \fIdate\fP\|(1) sends this message to the local time daemon
E 2
when a super-user wants to set the network date.
D 2
If the local time daemon is the master, it will set the time;
E 2
I 2
If the local time daemon is the master, it will set the date;
E 2
if it is a slave, it will communicate the desired date to the master.
.sp 1
.DE
.DS L
.SH
Set Date Request Message
.so date
.LP
Type: TSP_SETDATEREQ (23)
.sp 1
D 2
.LP
Description:
E 2
.PP
A slave that has received a Set Date message will communicate the
desired date to the master using this message.
.sp 1
.DE
.DS L
.SH
Set Date Acknowledgment Message
.so unused
.LP
Type: TSP_DATEACK (16)
.sp 1
D 2
.LP
Description:
E 2
.PP
The master sends this message to a slave in acknowledgment of a
Set Date Request Message.
The same message is sent by the local time daemon to the program
\fIdate(1)\fP to confirm that the network date has been set by the
master.
.sp 1
.DE
.DS L
.SH
Start Tracing Message
.so unused
.LP
Type: TSP_TRACEON (17)
.sp 1
D 2
.LP
Description:
E 2
.PP
The controlling program \fItimedc\fP sends this message to the local
time daemon to start the recording in a system file of
all messages received.
.sp 1
.DE
.DS L
.SH
Stop Tracing Message
.so unused
.LP
Type: TSP_TRACEOFF (18)
.sp 1
D 2
.LP
Description:
E 2
.PP
\fITimedc\fP sends this message to the local
time daemon to stop the recording of
messages received.
.sp 1
.DE
.DS L
.SH
Master Site Message
.so unused
.LP
Type: TSP_MSITE (19)
.sp 1
D 2
.LP
Description:
E 2
.PP
\fITimedc\fP sends this message to the local time daemon to find out
where the master is running.
.sp 1
.DE
.DS L
.SH
Remote Master Site Message
.so unused
.LP
Type: TSP_MSITEREQ (20)
.sp 1
D 2
.LP
Description:
E 2
.PP
A local time daemon broadcasts this message to find the location
of the master.
It then uses the Acknowledgement message to 
communicate this location to \fItimedc\fP.
.sp 1
.DE
.DS L
.SH
Test Message
.so unused
.LP
Type: TSP_TEST (21)
.sp 1
D 2
.LP
Description:
E 2
.PP
D 2
For testing purposes, \fItimedc\fP sends this message to a set of slaves
to cause their election timers expire simultaneously.  NOTE: \fItimed\fP
E 2
I 2
For testing purposes, \fItimedc\fP sends this message to a slave
to cause its election timer to expire.  NOTE: \fItimed\fP
E 2
is not normally compiled to support this.
.sp 1
.DE
.SH
.DS L
.SH
Loop Detection Message
.so loop
.LP
Type: TSP_LOOP (24)
.sp 1
D 2
.LP
Description
E 2
.PP
This packet is initiated by all masters occasionally to attempt to detect loops.
D 2
All submasters forward this packet onto the networks they are master over.
E 2
I 2
All submasters forward this packet onto the networks over which they are master.
E 2
If a master receives a packet it sent out initially,
it knows that a loop exists and tries to correct the problem.
.DE
.SH
References
.IP 1.
R. Gusella and S. Zatti, 
\fITEMPO: A Network Time Controller for Distributed Berkeley UNIX System\fP,
USENIX Summer Conference Proceedings, Salt Lake City, June 1984.
.IP 2.
R. Gusella and S. Zatti, \fIClock Synchronization in a Local Area Network\fP,
University of California, Berkeley, Technical Report, \fIto appear\fP.
.IP 3.
R. Gusella and S. Zatti, 
\fIAn Election Algorithm for a Distributed Clock Synchronization Program\fP,
University of California, Berkeley, CS Technical Report #275, Dec. 1985.
I 2
.IP 4.
Postel, J., \fIUser Datagram Protocol\fP, RFC 768.
Network Information Center, SRI International, Menlo Park, California,
August 1980.
.IP 5.
Postel, J., \fIInternet Control Message Protocol\fP, RFC 792.
Network Information Center, SRI International, Menlo Park, California,
September 1981.
E 2
E 1

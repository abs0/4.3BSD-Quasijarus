h25279
s 00005/00005/00183
d D 4.4 82/10/18 23:54:43 mckusick 4 3
c update to properly use DESTDIR
e
s 00010/00011/00178
d D 4.3 82/10/02 20:19:34 comay 3 2
c archives are put in right place and send? directory is protected
e
s 00002/00002/00187
d D 4.2 82/09/20 23:58:58 mckusick 2 1
c set up installed net programs to be owned by daemon
e
s 00189/00000/00000
d D 4.1 82/09/12 17:46:08 mckusick 1 0
c date and time created 82/09/12 17:46:08 by mckusick
e
u
U
t
T
I 1
#	%W%	(Berkeley)	%G%
#
DESTDIR = /
OBJS =
D 3
ARCH = /usr/src/cmd/berknet/
E 3
I 3
ARCH = /usr/src/ucb/berknet/
E 3
RDIR = $(DESTDIR)/usr/ucb/
CRYPT =
D 2
OTHER = schmidt
E 2
I 2
D 3
OTHER = daemon
E 3
I 3
D 4
OTHER = schmidt
E 4
I 4
OTHER = daemon
E 4
E 3
E 2
MWRITEMODE = 711
NETLPRMODE = 711
D 2
NETLPROWN = schmidt
E 2
I 2
D 3
NETLPROWN = daemon
E 3
I 3
D 4
NETLPROWN = schmidt
E 4
I 4
NETLPROWN = daemon
E 4
E 3
E 2
V6MAILMODE = 4711
CC = cc
CFLAGS = -O
D 3
LDFLAGS =  -n  -z
E 3
I 3
LDFLAGS =  -n -s -z
E 3
CPALL = cp
TOM = y
PR = /usr/ucb/vprint
# the constants above are machine dependent.
#
D 3
# CSVAX version
E 3
I 3
# ucbvax version
E 3
# makefile for Berkeley Unix network
D 3
# Eric Schmidt -- January 19, 1980
E 3
#
# to make net source:
#
#	make
#
# to install in right places:
#
#	make install DESTDIR=
#
# to remove all `.o' and executable files:
#
#	make clean
#
# To install the first time also do this:
#
#	make firstinstall
#
# The files can be grouped in these ways:
#	Commands that can be put in "new" directories for users to try:
#		netq, netlpr, netrm, netmail, netcp, netlogin
#	Commands that are internal and must work on incoming/outgoing requests:
#		prmail, sendberkmail, mmail, mwrite, v6mail
# 	Commands that must be dumped in and tried, ready or not:
#		netdaemon, net, netstart, nsh, chktroff
NDIR = $(DESTDIR)/usr/net/bin/
SPOOL = /usr/spool/berknet
all: netdaemon net netq netrm netcp netlpr netmail sendberkmail mmail mwrite \
	netstart nsh prmail chktroff netlogin v6mail done
install:
	-$(CPALL) net netcp netdaemon netstart mmail mwrite \
		sendberkmail prmail chktroff v6mail $(NDIR)
	-$(CPALL) netrm netq netlpr netmail netlogin $(RDIR)
D 4
	-cp nsh /usr/net/network/nsh
E 4
I 4
	-cp nsh $(DESTDIR)/usr/net/network/nsh
E 4
	-cp netlog.sh $(RDIR)/netlog
	-cp nettroff.sh $(RDIR)/nettroff
I 3
	-rm -f netcp netmail sendberkmail netdaemon netstart mmail mwrite \
		netlpr net netq netrm nsh prmail chktroff netlogin v6mail
E 3
	-chown $(OTHER) $(NDIR)netdaemon $(NDIR)netstart $(NDIR)mmail \
		$(NDIR)mwrite $(NDIR)sendberkmail $(RDIR)netmail \
		$(NDIR)netcp $(NDIR)prmail $(NDIR)chktroff $(RDIR)netlogin
	-chown root $(NDIR)net $(RDIR)netq $(RDIR)netrm $(NDIR)v6mail
	-chown $(NETLPROWN) $(RDIR)netlpr
D 4
	-chown network /usr/net/network/nsh
E 4
I 4
	-chown network $(DESTDIR)/usr/net/network/nsh
E 4
	-chmod 711 $(NDIR)netcp $(RDIR)netmail $(NDIR)sendberkmail \
		$(NDIR)mmail $(NDIR)prmail $(RDIR)netlogin
D 4
	-chmod 555 /usr/net/network/nsh $(RDIR)/nettroff $(RDIR)/netlog
E 4
I 4
	-chmod 555 $(DESTDIR)/usr/net/network/nsh $(RDIR)/nettroff $(RDIR)/netlog
E 4
	-chmod $(MWRITEMODE) $(NDIR)mwrite
	-chmod $(NETLPRMODE) $(RDIR)netlpr
	-chmod $(V6MAILMODE) $(NDIR)v6mail
	-chmod 700 $(NDIR)netdaemon $(NDIR)netstart
	-chmod 4711 $(NDIR)net $(RDIR)netq $(RDIR)netrm
	-rm -f $(RDIR)netcp $(RDIR)net
	-ln $(NDIR)net		$(RDIR)net
	-ln $(NDIR)netcp	$(RDIR)netcp
D 3
clean:	ridX
E 3
I 3
clean:
E 3
	@-rm -f netdaemon net mwrite netq netcp netlpr sendberkmail \
	mmail netmail netrm netstart nsh interact \
	listen receive speedr speeds store nettest prmail \
	netdaemon.o net.o mwrite.o netq.o netcp.o netlpr.o sendberkmail.o \
	mmail.o netmail.o netrm.o netstart.o nsh.o prmail.o interact.o \
	listen.o receive.o speedr.o speeds.o store.o nettest.o \
	nbs.o prot.o sub.o mach.o netrc.o setup.o header.o \
	chktroff.o chktroff errs netlogin netlogin.o environ.o v6mail v6mail.o
D 3
ridX:
	-rm -f netcp netmail sendberkmail netdaemon netstart mmail mwrite \
		netlpr net netq netrm nsh prmail chktroff netlogin v6mail
E 3
othernet: interact listen speedr speeds store receive nettest setmode
othernetclean:
	-rm -f interact interact.o listen listen.o speedr speedr.o \
	speeds speeds.o store store.o receive receive.o nettest nettest.o \
	setmode setmode.o
netdaemon: netdaemon.o sub.o prot.o mach.o netrc.o nbs.o setup.o header.o \
		$(CRYPT)
	$(CC) $(LDFLAGS) -o netdaemon netdaemon.o sub.o prot.o mach.o setup.o\
		netrc.o nbs.o header.o $(CRYPT) $(OBJS)
net:	net.o sub.o mach.o netrc.o nbs.o header.o environ.o $(CRYPT)
	$(CC) $(LDFLAGS) -o net net.o sub.o mach.o netrc.o nbs.o header.o\
		environ.o $(CRYPT) $(OBJS)
netq: 	netq.o sub.o mach.o header.o
	$(CC) $(LDFLAGS) -o netq netq.o sub.o mach.o header.o $(OBJS)
netrm:	netrm.o sub.o mach.o
	$(CC) $(LDFLAGS) -o netrm netrm.o sub.o mach.o $(OBJS)
netcp:	netcp.o sub.o mach.o netrc.o nbs.o environ.o
	$(CC) $(LDFLAGS) -o netcp netcp.o sub.o netrc.o mach.o nbs.o environ.o\
		$(OBJS)
netlpr:	netlpr.o sub.o mach.o netrc.o environ.o nbs.o
	$(CC) $(LDFLAGS) -o netlpr netlpr.o sub.o netrc.o mach.o environ.o\
		nbs.o $(OBJS)
netmail: netmail.o sub.o mach.o netrc.o environ.o nbs.o
	$(CC) $(LDFLAGS) -o netmail netmail.o netrc.o sub.o mach.o environ.o\
		nbs.o $(OBJS)
sendberkmail: sendberkmail.o sub.o mach.o
	$(CC) $(LDFLAGS) -o sendberkmail sendberkmail.o sub.o mach.o $(OBJS)
mwrite:	mwrite.o sub.o mach.o
	$(CC) $(LDFLAGS) -o mwrite mwrite.o sub.o mach.o $(OBJS)
mmail:	mmail.o sub.o mach.o
	$(CC) $(LDFLAGS) -o mmail mmail.o sub.o mach.o $(OBJS)
netstart: netstart.o mach.o setup.o sub.o netrc.o
	$(CC) $(LDFLAGS) -o netstart netstart.o mach.o setup.o sub.o netrc.o \
		$(OBJS)
nsh:	nsh.o sub.o mach.o
	$(CC) $(LDFLAGS) -o nsh nsh.o sub.o mach.o $(OBJS)
prmail:	prmail.o mach.o sub.o
	$(CC) $(LDFLAGS) -o prmail prmail.o sub.o mach.o $(OBJS)
chktroff: chktroff.o
	$(CC) $(LDFLAGS) -o chktroff chktroff.o
netlogin:	netlogin.o sub.o mach.o nbs.o environ.o
	$(CC) $(LDFLAGS) -o netlogin netlogin.o sub.o mach.o nbs.o environ.o\
		$(OBJS)
interact: interact.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o interact interact.o sub.o prot.o mach.o setup.o\
		netrc.o $(OBJS)
listen:	listen.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o listen listen.o sub.o prot.o mach.o setup.o \
		netrc.o $(OBJS)
speeds:	speeds.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o speeds speeds.o sub.o prot.o mach.o setup.o \
		netrc.o $(OBJS)
speedr:	speedr.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o speedr speedr.o sub.o prot.o mach.o setup.o \
		netrc.o $(OBJS)
store:	store.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o store store.o sub.o prot.o mach.o  setup.o \
		netrc.o $(OBJS)
receive: receive.o sub.o prot.o mach.o setup.o netrc.o
	$(CC) $(LDFLAGS) -o receive receive.o sub.o prot.o mach.o setup.o\
		netrc.o $(OBJS)
nettest: nettest.o sub.o mach.o
	$(CC) $(LDFLAGS) -o nettest nettest.o sub.o mach.o $(OBJS)
setmode:	setmode.o
	$(CC) -s -o setmode setmode.o $(OBJS)
v6mail:	v6mail.o mach.o
	$(CC) $(LDFLAGS) -o v6mail v6mail.o mach.o $(OBJS)
done:
	@-echo DONE!
print:
	$(PR) TODO BUGLIST READ_ME makefile *.h *.c
lintit:
	lint *.c
lint1:
	echo netdaemon.c sub.c prot.c mach.c nbs.c setup.c netrc.c
	lint netdaemon.c sub.c prot.c mach.c nbs.c setup.c netrc.c
	echo net.c sub.c mach.c nbs.c netrc.c
	lint net.c sub.c mach.c nbs.c netrc.c
	echo netcp.c sub.c mach.c
	lint netcp.c sub.c mach.c
firstinstall:
	mkdir /usr/spool/berknet /usr/net /usr/net/bin /usr/net/network \
		/usr/spool/berknet/rcv /usr/spool/berknet/send$(TOM)
	cat /dev/null >/usr/spool/berknet/logfile
	cat /dev/null >/usr/spool/berknet/plogfile$(TOM)
	cat /dev/null >/usr/spool/berknet/netstat$(TOM)
	cat /dev/null >/usr/spool/berknet/usernames
	chown $(OTHER) $(SPOOL) /usr/net $(NDIR) \
		$(SPOOL)/rcv $(SPOOL)/send$(TOM) \
		$(SPOOL)/logfile $(SPOOL)/plogfile$(TOM) \
		$(SPOOL)/usernames $(SPOOL)/netstat$(TOM)
	chown network /usr/net/network
	chmod 666 $(SPOOL)/logfile $(SPOOL)/plogfile$(TOM)
	chmod 644 $(SPOOL)/usernames $(SPOOL)/netstat$(TOM) 
D 3
	chmod 755 /usr/net $(SPOOL) $(NDIR) $(SPOOL)/rcv $(SPOOL)/send$(TOM)
E 3
I 3
	chmod 755 /usr/net $(SPOOL) $(NDIR) $(SPOOL)/rcv
	chmod 700 $(SPOOL)/send$(TOM)
E 3
archive:
	-ar rn berknet.a makefile TODO BUGLIST READ_ME *.h *.c *.sh $(CRYPT) 
	-ar r  berknet.a update /usr/news/net ../othernet/*.c \
		/usr/net/initfile /usr/net/network.map /usr/net/bin/setlength\
		/usr/net/bin/start /usr/include/sysexits.h
	mv berknet.a $(DESTDIR)$(ARCH)
	chmod 644 $(DESTDIR)$(ARCH)/berknet.a
E 1

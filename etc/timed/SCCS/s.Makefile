h04479
s 00010/00005/00154
d D 5.5 88/06/18 14:07:58 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00150
d D 5.4 87/12/23 14:29:54 bostic 10 9
c append Berkeley header; NASA wants a copy
e
s 00067/00085/00086
d D 5.3 87/06/02 21:56:21 bostic 9 7
c new template
e
s 00066/00084/00087
d R 5.2 87/06/02 21:43:32 bostic 8 7
c new template
e
s 00050/00051/00121
d D 5.1 87/05/31 20:53:50 bostic 7 6
c added depend label, got rid of "makefile", MACHINE in make(1), now
e
s 00001/00001/00171
d D 2.3 86/11/17 09:06:20 sam 6 5
c use kirk trick to avoid recompiles
e
s 00011/00010/00161
d D 2.2 86/10/13 15:52:16 sam 5 4
c eliminate machine subdirs to ease machine-independence mods to Makefile
e
s 00004/00011/00167
d D 2.1 85/12/10 13:06:09 bloom 4 3
c Multi network support
e
s 00133/00016/00045
d D 1.3 85/09/18 20:12:32 bloom 3 2
c add make depend, cleanup
e
s 00003/00003/00058
d D 1.2 85/09/07 14:10:56 mckusick 2 1
c fix DESTDIR
e
s 00061/00000/00000
d D 1.1 85/06/27 12:48:06 gusella 1 0
c date and time created 85/06/27 12:48:06 by gusella
e
u
U
t
T
I 1
#
D 9
# Copyright (c) 1983 Regents of the University of California.
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
E 9
D 10
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 10
I 10
# All rights reserved.
E 10
#
D 10
#	%W%	(Berkeley)	%G%
E 10
I 10
# Redistribution and use in source and binary forms are permitted
D 11
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 11
I 11
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 11
#
#	%W% (Berkeley) %G%
E 10
#
D 3
# optional flags are: MEASURE TESTING
E 3
I 3
# optional flags are: MEASURE TESTING DEBUG
E 3
D 9

D 4
CFLAGS= -O -DMEASURE -DTESTING
E 4
I 4
CFLAGS= -O
E 4
D 2
DESTDIR= /etc
E 2
I 2
DESTDIR=
E 2
D 5
MACHINE= vax
E 5
I 5
D 6
MACHINE= `machine`
E 6
I 6
D 7
MACHINE=unknown
E 7
E 6
E 5
LIBS=
PROGRS=	timed timedc

D 3
HDRDS= 	/usr/include/protocols/timed.h globals.h

E 3
D 4
SRCDS=	acksend.c broadcast.c candidate.c correct.c \
E 4
I 4
SRCDS=	acksend.c candidate.c correct.c \
E 4
	master.c networkdelta.c readmsg.c slave.c timed.c

D 4
OBJDS=	acksend.o broadcast.o candidate.o correct.o \
E 4
I 4
OBJDS=	acksend.o candidate.o correct.o \
E 4
	master.o networkdelta.o readmsg.o slave.o timed.o

E 9
I 9
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCDS=	acksend.c candidate.c correct.c master.c networkdelta.c readmsg.c \
	slave.c timed.c
OBJDS=	acksend.o candidate.o correct.o master.o networkdelta.o readmsg.o \
	slave.o timed.o
E 9
D 3
HDRCS=	/usr/include/protocols/timed.h timedc.h

E 3
SRCCS=	cmds.c cmdtab.c timedc.c
D 9

E 9
OBJCS=	cmds.o cmdtab.o timedc.o
D 9

E 9
D 5
COMMS=	byteorder.c measure.c ${MACHINE}/cksum.c
E 5
I 5
COMMS=	byteorder.c measure.c cksum.${MACHINE}.c
E 5
D 9

E 9
D 3
COMMO=	byteorder.o measure.o ${MACHINE}/cksum.o
E 3
I 3
D 5
COMMO=	byteorder.o measure.o cksum.o
E 5
I 5
COMMO=	byteorder.o measure.o cksum.${MACHINE}.o
E 5
E 3

D 9
all:	${PROGRS}
E 9
I 9
all: timed timedc
E 9

I 9
timed: 	${OBJDS} ${COMMO} ${LIBC}
	${CC} ${CFLAGS} ${OBJDS} ${COMMO} ${LIBS} -o $@

timedc: ${OBJCS} ${COMMO} ${LIBC}
	${CC} ${CFLAGS} ${OBJCS} ${COMMO} ${LIBS} -o $@

E 9
D 3
${SRCDS}: ${HDRDS}
E 3
I 3
D 5
cksum.o:
	cc ${CFLAGS} -c ${MACHINE}/$*.c
E 5
I 5
cksum.${MACHINE}.o:
D 9
	cc ${CFLAGS} -c $*.c
E 9
I 9
	${CC} ${CFLAGS} -c $*.c
E 9
E 5
E 3

D 3
${SRCCS}: ${HDRCS}

${COMMS}: ${HDRDS}

${MACHINE}/cksum.o:
	cc ${CFLAGS} ${LIBS} -c $<
	mv cksum.o ${MACHINE}

E 3
D 9
timed: 	${OBJDS} ${COMMO}
	cc ${CFLAGS} ${OBJDS} ${COMMO} ${LIBS} -o timed 
E 9
I 9
clean: FRC
	rm -f ${OBJDS} ${OBJCS} ${COMMO} core timed timedc
E 9

D 9
timedc: ${OBJCS} ${COMMO}
	cc ${CFLAGS} ${OBJCS} ${COMMO} ${LIBS} -o timedc
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCDS} ${SRCCS} ${COMMS}
E 9

D 9
install: ${PROGRS}
D 2
	install -s timed ${DESTDIR}
	install -s -m 4511 timedc ${DESTDIR}
E 2
I 2
	install -s timed ${DESTDIR}/etc
D 4
	install -s -m 4511 timedc ${DESTDIR}/etc
E 4
I 4
	install -s -o root -m 4511 timedc ${DESTDIR}/etc
E 9
I 9
install: FRC
	install -s -o bin -g bin -m 755 timed ${DESTDIR}/etc/timed
	install -s -o root -g bin -m 4511 timedc ${DESTDIR}/etc/timedc
E 9
E 4
E 2

D 9
clean:
D 3
	rm -f a.out core ${OBJDS} ${OBJCS} ${COMMO} ${PROGRS}
E 3
I 3
	rm -f a.out core *.o Makefile.bak errs ${PROGRS}
E 9
I 9
lint: FRC
	lint ${CFLAGS} ${SRCDS} ${COMMS}
	lint ${CFLAGS} ${SRCCS} ${COMMS}
E 9
E 3

D 9
lint:
	lint ${SRCDS} ${COMMS}
	lint ${SRCCS} ${COMMS}
E 9
I 9
tags: FRC
	ctags ${SRCDS} ${SRCCS} ${COMMS}
E 9
I 3

D 9
depend:
	for i in ${SRCCS} ${SRCDS} ${COMMS}; do \
	    cc -M ${CFLAGS} $$i | awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 9
I 9
FRC:
E 9

D 9
# DO NOT DELETE THIS LINE -- make depend uses it
E 9
I 9
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 9

D 7
cmds.o: cmds.c ./timedc.h /usr/include/sys/param.h
cmds.o: /usr/include/machine/machparam.h /usr/include/signal.h
cmds.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
cmds.o: /usr/include/time.h /usr/include/errno.h /usr/include/sys/socket.h
E 7
I 7
D 9
cmds.o: cmds.c ./timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
cmds.o: /usr/include/signal.h /usr/include/machine/machparam.h
cmds.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
cmds.o: /usr/include/errno.h /usr/include/sys/socket.h
E 7
cmds.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/arpa/inet.h
cmds.o: /usr/include/netinet/in_systm.h /usr/include/netinet/ip.h
cmds.o: /usr/include/netinet/ip_icmp.h /usr/include/protocols/timed.h
cmds.o: /usr/include/sys/file.h
D 7
cmdtab.o: cmdtab.c ./timedc.h /usr/include/sys/param.h
cmdtab.o: /usr/include/machine/machparam.h /usr/include/signal.h
cmdtab.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
cmdtab.o: /usr/include/time.h /usr/include/errno.h /usr/include/sys/socket.h
E 7
I 7
cmdtab.o: cmdtab.c ./timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
cmdtab.o: /usr/include/signal.h /usr/include/machine/machparam.h
cmdtab.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
cmdtab.o: /usr/include/errno.h /usr/include/sys/socket.h
E 7
cmdtab.o: /usr/include/netinet/in.h /usr/include/netdb.h
cmdtab.o: /usr/include/arpa/inet.h
D 7
timedc.o: timedc.c ./timedc.h /usr/include/sys/param.h
timedc.o: /usr/include/machine/machparam.h /usr/include/signal.h
timedc.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
timedc.o: /usr/include/time.h /usr/include/errno.h /usr/include/sys/socket.h
E 7
I 7
timedc.o: timedc.c ./timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
timedc.o: /usr/include/signal.h /usr/include/machine/machparam.h
timedc.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
timedc.o: /usr/include/errno.h /usr/include/sys/socket.h
E 7
timedc.o: /usr/include/netinet/in.h /usr/include/netdb.h
timedc.o: /usr/include/arpa/inet.h /usr/include/signal.h /usr/include/ctype.h
timedc.o: /usr/include/setjmp.h /usr/include/syslog.h
acksend.o: acksend.c ./globals.h /usr/include/sys/param.h
E 9
I 9
acksend.o: acksend.c globals.h /usr/include/sys/param.h
E 9
D 7
acksend.o: /usr/include/machine/machparam.h /usr/include/signal.h
acksend.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
acksend.o: /usr/include/sys/types.h /usr/include/signal.h
acksend.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
acksend.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
acksend.o: /usr/include/syslog.h /usr/include/sys/socket.h
acksend.o: /usr/include/netinet/in.h /usr/include/netdb.h
acksend.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
D 4
broadcast.o: broadcast.c ./globals.h /usr/include/sys/param.h
broadcast.o: /usr/include/machine/machparam.h /usr/include/signal.h
broadcast.o: /usr/include/sys/types.h /usr/include/stdio.h
broadcast.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
broadcast.o: /usr/include/syslog.h /usr/include/sys/socket.h
broadcast.o: /usr/include/netinet/in.h /usr/include/netdb.h
broadcast.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
E 4
D 9
candidate.o: candidate.c ./globals.h /usr/include/sys/param.h
E 9
I 9
candidate.o: candidate.c globals.h /usr/include/sys/param.h
E 9
D 7
candidate.o: /usr/include/machine/machparam.h /usr/include/signal.h
candidate.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
candidate.o: /usr/include/sys/types.h /usr/include/signal.h
candidate.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
candidate.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
candidate.o: /usr/include/syslog.h /usr/include/sys/socket.h
candidate.o: /usr/include/netinet/in.h /usr/include/netdb.h
candidate.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
D 9
correct.o: correct.c ./globals.h /usr/include/sys/param.h
E 9
I 9
correct.o: correct.c globals.h /usr/include/sys/param.h
E 9
D 7
correct.o: /usr/include/machine/machparam.h /usr/include/signal.h
correct.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
correct.o: /usr/include/sys/types.h /usr/include/signal.h
correct.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
correct.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
correct.o: /usr/include/syslog.h /usr/include/sys/socket.h
correct.o: /usr/include/netinet/in.h /usr/include/netdb.h
correct.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
D 9
master.o: master.c ./globals.h /usr/include/sys/param.h
D 7
master.o: /usr/include/machine/machparam.h /usr/include/signal.h
master.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
master.o: /usr/include/time.h /usr/include/errno.h /usr/include/syslog.h
master.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
master.o: /usr/include/netdb.h /usr/include/arpa/inet.h
D 5
master.o: /usr/include/protocols/timed.h /usr/include/setjmp.h
E 5
I 5
master.o: /usr/include/protocols/timed.h /usr/include/sys/file.h
master.o: /usr/include/setjmp.h /usr/include/utmp.h
E 7
I 7
master.o: /usr/include/sys/types.h /usr/include/signal.h
master.o: /usr/include/machine/machparam.h /usr/include/stdio.h
master.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
master.o: /usr/include/syslog.h /usr/include/sys/socket.h
E 9
I 9
master.o: master.c globals.h /usr/include/sys/param.h /usr/include/sys/types.h
master.o: /usr/include/signal.h /usr/include/machine/machparam.h
master.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
master.o: /usr/include/errno.h /usr/include/syslog.h /usr/include/sys/socket.h
E 9
master.o: /usr/include/netinet/in.h /usr/include/netdb.h
master.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
master.o: /usr/include/sys/file.h /usr/include/setjmp.h /usr/include/utmp.h
E 7
E 5
D 9
networkdelta.o: networkdelta.c ./globals.h /usr/include/sys/param.h
E 9
I 9
networkdelta.o: networkdelta.c globals.h /usr/include/sys/param.h
E 9
D 7
networkdelta.o: /usr/include/machine/machparam.h /usr/include/signal.h
networkdelta.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
networkdelta.o: /usr/include/sys/types.h /usr/include/signal.h
networkdelta.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
networkdelta.o: /usr/include/sys/time.h /usr/include/time.h
networkdelta.o: /usr/include/errno.h /usr/include/syslog.h
networkdelta.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
networkdelta.o: /usr/include/netdb.h /usr/include/arpa/inet.h
networkdelta.o: /usr/include/protocols/timed.h
D 9
readmsg.o: readmsg.c ./globals.h /usr/include/sys/param.h
E 9
I 9
readmsg.o: readmsg.c globals.h /usr/include/sys/param.h
E 9
D 7
readmsg.o: /usr/include/machine/machparam.h /usr/include/signal.h
readmsg.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
readmsg.o: /usr/include/sys/types.h /usr/include/signal.h
readmsg.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
readmsg.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
readmsg.o: /usr/include/syslog.h /usr/include/sys/socket.h
readmsg.o: /usr/include/netinet/in.h /usr/include/netdb.h
readmsg.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
D 7
slave.o: slave.c ./globals.h /usr/include/sys/param.h
slave.o: /usr/include/machine/machparam.h /usr/include/signal.h
slave.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
slave.o: /usr/include/time.h /usr/include/errno.h /usr/include/syslog.h
slave.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
slave.o: /usr/include/netdb.h /usr/include/arpa/inet.h
slave.o: /usr/include/protocols/timed.h /usr/include/setjmp.h
timed.o: timed.c ./globals.h /usr/include/sys/param.h
timed.o: /usr/include/machine/machparam.h /usr/include/signal.h
timed.o: /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sys/time.h
timed.o: /usr/include/time.h /usr/include/errno.h /usr/include/syslog.h
timed.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
timed.o: /usr/include/netdb.h /usr/include/arpa/inet.h
timed.o: /usr/include/protocols/timed.h /usr/include/net/if.h
D 5
timed.o: /usr/include/sys/file.h /usr/include/sys/ioctl.h
timed.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
timed.o: /usr/include/setjmp.h
E 5
I 5
timed.o: /usr/include/net/if_arp.h /usr/include/sys/file.h
timed.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
timed.o: /usr/include/sys/ttydev.h /usr/include/setjmp.h
E 7
I 7
D 9
slave.o: slave.c ./globals.h /usr/include/sys/param.h /usr/include/sys/types.h
E 9
I 9
slave.o: slave.c globals.h /usr/include/sys/param.h /usr/include/sys/types.h
E 9
slave.o: /usr/include/signal.h /usr/include/machine/machparam.h
slave.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
slave.o: /usr/include/errno.h /usr/include/syslog.h /usr/include/sys/socket.h
slave.o: /usr/include/netinet/in.h /usr/include/netdb.h
slave.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
slave.o: /usr/include/setjmp.h
D 9
timed.o: timed.c ./globals.h /usr/include/sys/param.h /usr/include/sys/types.h
E 9
I 9
timed.o: timed.c globals.h /usr/include/sys/param.h /usr/include/sys/types.h
E 9
timed.o: /usr/include/signal.h /usr/include/machine/machparam.h
timed.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
timed.o: /usr/include/errno.h /usr/include/syslog.h /usr/include/sys/socket.h
timed.o: /usr/include/netinet/in.h /usr/include/netdb.h
timed.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
timed.o: /usr/include/net/if.h /usr/include/net/if_arp.h
timed.o: /usr/include/sys/file.h /usr/include/sys/ioctl.h
timed.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
timed.o: /usr/include/setjmp.h
E 7
E 5
D 9
byteorder.o: byteorder.c ./globals.h /usr/include/sys/param.h
E 9
I 9
cmds.o: cmds.c timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
cmds.o: /usr/include/signal.h /usr/include/machine/machparam.h
cmds.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
cmds.o: /usr/include/errno.h /usr/include/sys/socket.h
cmds.o: /usr/include/netinet/in.h /usr/include/netdb.h /usr/include/arpa/inet.h
cmds.o: /usr/include/netinet/in_systm.h /usr/include/netinet/ip.h
cmds.o: /usr/include/netinet/ip_icmp.h /usr/include/protocols/timed.h
cmds.o: /usr/include/sys/file.h
cmdtab.o: cmdtab.c timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
cmdtab.o: /usr/include/signal.h /usr/include/machine/machparam.h
cmdtab.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
cmdtab.o: /usr/include/errno.h /usr/include/sys/socket.h
cmdtab.o: /usr/include/netinet/in.h /usr/include/netdb.h
cmdtab.o: /usr/include/arpa/inet.h
timedc.o: timedc.c timedc.h /usr/include/sys/param.h /usr/include/sys/types.h
timedc.o: /usr/include/signal.h /usr/include/machine/machparam.h
timedc.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
timedc.o: /usr/include/errno.h /usr/include/sys/socket.h
timedc.o: /usr/include/netinet/in.h /usr/include/netdb.h
timedc.o: /usr/include/arpa/inet.h /usr/include/signal.h /usr/include/ctype.h
timedc.o: /usr/include/setjmp.h /usr/include/syslog.h
byteorder.o: byteorder.c globals.h /usr/include/sys/param.h
E 9
D 7
byteorder.o: /usr/include/machine/machparam.h /usr/include/signal.h
byteorder.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
byteorder.o: /usr/include/sys/types.h /usr/include/signal.h
byteorder.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
byteorder.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
byteorder.o: /usr/include/syslog.h /usr/include/sys/socket.h
byteorder.o: /usr/include/netinet/in.h /usr/include/netdb.h
byteorder.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
D 9
measure.o: measure.c ./globals.h /usr/include/sys/param.h
E 9
I 9
measure.o: measure.c globals.h /usr/include/sys/param.h
E 9
D 7
measure.o: /usr/include/machine/machparam.h /usr/include/signal.h
measure.o: /usr/include/sys/types.h /usr/include/stdio.h
E 7
I 7
measure.o: /usr/include/sys/types.h /usr/include/signal.h
measure.o: /usr/include/machine/machparam.h /usr/include/stdio.h
E 7
measure.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
measure.o: /usr/include/syslog.h /usr/include/sys/socket.h
measure.o: /usr/include/netinet/in.h /usr/include/netdb.h
measure.o: /usr/include/arpa/inet.h /usr/include/protocols/timed.h
measure.o: /usr/include/netinet/in_systm.h /usr/include/netinet/ip.h
measure.o: /usr/include/netinet/ip_icmp.h
D 5
cksum.o: vax/cksum.c /usr/include/sys/types.h
E 5
I 5
cksum.tahoe.o: cksum.tahoe.c /usr/include/sys/types.h
E 5
D 9
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 9
I 9

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 3
E 1

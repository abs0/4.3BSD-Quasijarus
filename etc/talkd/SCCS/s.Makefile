h64028
s 00011/00006/00069
d D 5.7 88/06/18 14:10:37 bostic 15 14
c install approved copyright notice
e
s 00028/00016/00047
d D 5.6 88/05/20 11:53:26 bostic 14 13
c add Berkeley specific header
e
s 00049/00055/00014
d D 5.5 87/06/02 21:54:47 bostic 13 10
c new template
e
s 00049/00055/00014
d R 5.5 87/06/02 21:21:35 bostic 12 10
c new template
e
s 00002/00002/00067
d R 5.5 86/10/13 15:37:53 sam 11 10
c talkd is no longer installed as ntalkd
e
s 00001/00001/00068
d D 5.4 86/03/13 19:32:53 mckusick 10 7
c install as /etc/ntalkd since it listens on a new port number
e
s 00001/00001/00068
d R 5.5 86/03/13 19:24:45 mckusick 9 8
c installs as /etc/ntalkd so as not to overrun the old version
e
s 00001/00001/00068
d R 5.4 86/03/13 18:04:57 mckusick 8 7
c setgid to group "write" so that terminals need not be world writable
e
s 00044/00000/00025
d D 5.3 86/03/13 17:31:54 mckusick 7 6
c add make depend
e
s 00009/00025/00016
d D 5.2 86/03/13 17:17:10 mckusick 6 5
c new version from sam@monet.berkeley.edu
e
s 00006/00001/00035
d D 5.1 85/06/06 09:14:27 dist 5 4
c Add copyright
e
s 00013/00013/00023
d D 1.2 84/12/20 17:34:49 karels 4 1
c reformatting
e
s 00014/00014/00022
d R 1.2 84/04/11 16:03:25 karels 3 1
c add keywords
e
s 00016/00016/00020
d R 1.2 84/04/11 15:15:23 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00036/00000/00000
d D 1.1 84/04/11 15:04:09 karels 1 0
c date and time created 84/04/11 15:04:09 by karels
e
u
U
t
T
I 1
D 4
# $Header: /a/guest/moore/talk/RCS/Makefile.dist,v 1.3 83/06/23 02:20:37 moore Exp $

E 4
I 4
D 5
#	%M%	%I%	%G%
E 5
I 5
#
D 13
# Copyright (c) 1983 Regents of the University of California.
E 13
I 13
D 14
# Copyright (c) 1987 Regents of the University of California.
E 13
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 14
I 14
D 15
# Copyright (c) 1988 Regents of the University of California.
E 15
I 15
# Copyright (c) 1987 Regents of the University of California.
E 15
# All rights reserved.
E 14
#
D 13
#	%W% (Berkeley) %G%
E 13
I 13
D 14
#	%W%	(Berkeley)	%G%
E 14
I 14
# Redistribution and use in source and binary forms are permitted
D 15
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 15
I 15
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
E 15
E 14
E 13
E 5
#
I 14
#	%W% (Berkeley) %G%
#
E 14
E 4
D 13
DESTDIR=
D 4
DOBJECT = talkd.o announce.o process.o table.o print.o
TOBJECT = talk.o get_names.o display.o io.o ctl.o init_disp.o\
	  msgs.o get_addrs.o ctl_transact.o invite.o look_up.o
DSOURCE = talkd.c announce.c process.c table.c print.c
TSOURCE = talk.c get_names.c display.c io.c ctl.c init_disp.c\
	  msgs.c get_addrs.c ctl_transact.c invite.c look_up.c
INCLUDE = talk.h ctl.h talk_ctl.h
SOURCE = ${DSOURCE} ${TSOURCE}
E 4
I 4
D 6
DOBJECT=talkd.o announce.o process.o table.o print.o
TOBJECT=talk.o get_names.o display.o io.o ctl.o init_disp.o \
	msgs.o get_addrs.o ctl_transact.o invite.o look_up.o
DSOURCE=talkd.c announce.c process.c table.c print.c
TSOURCE=talk.c get_names.c display.c io.c ctl.c init_disp.c \
	msgs.c get_addrs.c ctl_transact.c invite.c look_up.c
INCLUDE=talk.h ctl.h talk_ctl.h
SOURCE= ${DSOURCE} ${TSOURCE}
E 6
I 6
OBJS=	talkd.o announce.o process.o table.o print.o
E 13
I 13
CFLAGS=	-O
LIBC=	/lib/libc.a
E 13
SRCS=	talkd.c announce.c process.c table.c print.c
E 6
E 4
D 13
CFLAGS= -O
E 13
I 13
OBJS=	talkd.o announce.o process.o table.o print.o
E 13

D 6
all:	talk talkd
E 6
I 6
D 13
all:	talkd
E 13
I 13
all: talkd
E 13
E 6

D 4
talkd:	${DOBJECT}
E 4
I 4
D 6
talkd: ${DOBJECT}
E 4
	cc ${CFLAGS} -o talkd ${DOBJECT}
E 6
I 6
D 13
talkd: ${OBJS}
	cc ${CFLAGS} -o talkd ${OBJS}
E 13
I 13
talkd:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 13
E 6

D 6
talk:	${TOBJECT}
	cc -o talk ${TOBJECT} -lcurses -ltermlib

D 4
${DOBJECT} : ctl.h
${TOBJECT} : talk.h ctl.h talk_ctl.h
E 4
I 4
${DOBJECT}: ctl.h
${TOBJECT}: talk.h ctl.h talk_ctl.h
E 4

install: talk talkd
	install -s talk ${DESTDIR}/usr/ucb/talk
E 6
I 6
D 13
install: talkd
E 6
D 10
	install -s talkd ${DESTDIR}/etc/talkd
E 10
I 10
	install -s talkd ${DESTDIR}/etc/ntalkd
E 13
I 13
clean: FRC
	rm -f ${OBJS} core talkd
E 13
E 10

D 6
lint:
	lint ${DSOURCE}

E 6
D 13
clean:
D 6
	rm -f *.o talk talkd
E 6
I 6
	rm -f ${OBJS} errs core a.out talkd
E 13
I 13
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 13
E 6

D 6
tags:	${SOURCE} ${INCLUDE}
	ctags ${SOURCE} ${INCLUDE}
E 6
I 6
D 13
tags:	${SRCS}
	ctags ${SOURCE}
E 13
I 13
install: FRC
	install -s -o bin -g bin -m 755 talkd ${DESTDIR}/etc/ntalkd
E 13
I 7

D 13
depend: ${SRCS}
	for i in ${SRCS}; do \
	    cc -M $$i | sed 's/\.o//' | \
	    awk ' { if ($$1 != prev) \
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
E 13
I 13
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 13

D 13
# DO NOT DELETE THIS LINE -- make depend uses it
E 13
I 13
tags: FRC
	ctags ${SRCS}
E 13

D 13
talkd: talkd.c /usr/include/stdio.h /usr/include/errno.h /usr/include/signal.h
talkd: /usr/include/syslog.h /usr/include/protocols/talkd.h
talkd: /usr/include/sys/types.h /usr/include/sys/socket.h
announce: announce.c /usr/include/sys/types.h /usr/include/sys/stat.h
announce: /usr/include/sgtty.h /usr/include/sys/ioctl.h
announce: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
announce: /usr/include/sys/ioctl.h /usr/include/sys/time.h /usr/include/time.h
announce: /usr/include/stdio.h /usr/include/sys/wait.h /usr/include/errno.h
announce: /usr/include/syslog.h /usr/include/protocols/talkd.h
announce: /usr/include/sys/types.h /usr/include/sys/socket.h
process: process.c /usr/include/sys/types.h /usr/include/sys/stat.h
process: /usr/include/stdio.h /usr/include/syslog.h /usr/include/netdb.h
process: /usr/include/netinet/in.h /usr/include/protocols/talkd.h
process: /usr/include/sys/types.h /usr/include/sys/socket.h /usr/include/utmp.h
table: table.c /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h
table: /usr/include/syslog.h /usr/include/protocols/talkd.h
table: /usr/include/sys/types.h /usr/include/sys/socket.h
print: print.c /usr/include/stdio.h /usr/include/syslog.h
print: /usr/include/protocols/talkd.h /usr/include/sys/types.h
print: /usr/include/sys/socket.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 13
I 13
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

talkd.o: talkd.c /usr/include/stdio.h /usr/include/errno.h
D 14
talkd.o: /usr/include/signal.h /usr/include/syslog.h
talkd.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
talkd.o: /usr/include/sys/socket.h
E 14
I 14
talkd.o: /usr/include/signal.h /usr/include/machine/trap.h
talkd.o: /usr/include/syslog.h /usr/include/protocols/talkd.h
talkd.o: /usr/include/sys/types.h /usr/include/sys/socket.h
E 14
announce.o: announce.c /usr/include/sys/types.h /usr/include/sys/stat.h
announce.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 14
announce.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
announce.o: /usr/include/sys/ioctl.h /usr/include/sys/time.h
announce.o: /usr/include/time.h /usr/include/stdio.h /usr/include/sys/wait.h
announce.o: /usr/include/machine/machparam.h /usr/include/errno.h
announce.o: /usr/include/syslog.h /usr/include/protocols/talkd.h
announce.o: /usr/include/sys/types.h /usr/include/sys/socket.h
E 14
I 14
announce.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
announce.o: /usr/include/sys/ttydev.h /usr/include/sys/ioctl.h
announce.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/stdio.h
announce.o: /usr/include/sys/wait.h /usr/include/machine/endian.h
announce.o: /usr/include/errno.h /usr/include/syslog.h
announce.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
announce.o: /usr/include/sys/socket.h
E 14
process.o: process.c /usr/include/sys/types.h /usr/include/sys/stat.h
process.o: /usr/include/stdio.h /usr/include/syslog.h /usr/include/netdb.h
process.o: /usr/include/netinet/in.h /usr/include/protocols/talkd.h
process.o: /usr/include/sys/types.h /usr/include/sys/socket.h
process.o: /usr/include/utmp.h
table.o: table.c /usr/include/stdio.h /usr/include/sys/time.h
D 14
table.o: /usr/include/time.h /usr/include/syslog.h
table.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
table.o: /usr/include/sys/socket.h
E 14
I 14
table.o: /usr/include/time.h /usr/include/syslog.h /usr/include/sys/param.h
table.o: /usr/include/sys/types.h /usr/include/signal.h
table.o: /usr/include/machine/trap.h /usr/include/machine/machparam.h
table.o: /usr/include/machine/endian.h /usr/include/protocols/talkd.h
table.o: /usr/include/sys/types.h /usr/include/sys/socket.h
E 14
print.o: print.c /usr/include/stdio.h /usr/include/syslog.h
I 14
print.o: /usr/include/sys/param.h /usr/include/sys/types.h
print.o: /usr/include/signal.h /usr/include/machine/trap.h
print.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
E 14
print.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
print.o: /usr/include/sys/socket.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 13
E 7
E 6
E 1

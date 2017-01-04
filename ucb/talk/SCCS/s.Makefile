h59665
s 00001/00001/00121
d D 5.8 88/07/06 18:52:06 edward 12 11
c talk doesn't have to be setgid tty
e
s 00010/00005/00112
d D 5.7 88/06/29 20:22:11 bostic 11 10
c install approved copyright notice
e
s 00060/00071/00057
d D 5.6 88/05/20 12:36:55 bostic 10 9
c add Berkeley specific header
e
s 00112/00098/00016
d D 5.5 87/06/16 18:55:21 bostic 9 8
c new template
e
s 00001/00001/00113
d D 5.4 86/04/12 15:43:16 karels 8 7
c write => tty
e
s 00001/00001/00113
d D 5.3 86/03/13 18:02:27 mckusick 7 6
c setgid to group "write" so that terminals need not be world writable
e
s 00095/00022/00019
d D 5.2 86/03/13 17:39:56 mckusick 6 5
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
D 9
#	%W% (Berkeley) %G%
E 9
I 9
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
E 10
E 9
E 5
#
I 10
#	%W% (Berkeley) %G%
#
E 10
E 4
D 9
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
E 6
I 6
OBJS=	talk.o get_names.o display.o io.o ctl.o init_disp.o \
E 6
	msgs.o get_addrs.o ctl_transact.o invite.o look_up.o
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
E 9
D 6
DSOURCE=talkd.c announce.c process.c table.c print.c
TSOURCE=talk.c get_names.c display.c io.c ctl.c init_disp.c \
E 6
I 6
SRCS=	talk.c get_names.c display.c io.c ctl.c init_disp.c \
E 6
	msgs.c get_addrs.c ctl_transact.c invite.c look_up.c
D 6
INCLUDE=talk.h ctl.h talk_ctl.h
SOURCE= ${DSOURCE} ${TSOURCE}
E 6
I 6
D 9
INCLUDE=talk.h talk_ctl.h
E 6
E 4
CFLAGS= -O
E 9
I 9
OBJS=	talk.o get_names.o display.o io.o ctl.o init_disp.o \
	msgs.o get_addrs.o ctl_transact.o invite.o look_up.o
E 9

D 6
all:	talk talkd
E 6
I 6
D 9
all:	talk
E 9
I 9
all: talk
E 9
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
D 9
talk:	${OBJS}
	cc -o talk ${OBJS} -lcurses -ltermlib
E 9
I 9
talk:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -lcurses -ltermlib
E 9
E 6

D 6
talk:	${TOBJECT}
	cc -o talk ${TOBJECT} -lcurses -ltermlib
E 6
I 6
D 9
${OBJS}: talk.h talk_ctl.h
E 9
I 9
clean: FRC
	rm -f ${OBJS} core talk
E 9
E 6

D 4
${DOBJECT} : ctl.h
${TOBJECT} : talk.h ctl.h talk_ctl.h
E 4
I 4
D 6
${DOBJECT}: ctl.h
${TOBJECT}: talk.h ctl.h talk_ctl.h
E 4

install: talk talkd
E 6
I 6
D 9
install: talk
E 6
D 7
	install -s talk ${DESTDIR}/usr/ucb/talk
E 7
I 7
D 8
	install -g write -m 2755 -s talk ${DESTDIR}/usr/ucb/talk
E 8
I 8
	install -g tty -m 2755 -s talk ${DESTDIR}/usr/ucb/talk
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 9
E 8
E 7
D 6
	install -s talkd ${DESTDIR}/etc/talkd
E 6

D 6
lint:
	lint ${DSOURCE}

E 6
D 9
clean:
D 6
	rm -f *.o talk talkd
E 6
I 6
	rm -f ${OBJS} a.out errs core talk
E 9
I 9
install: FRC
D 12
	install -s -o bin -g tty -m 2755 talk ${DESTDIR}/usr/ucb/talk
E 12
I 12
	install -s -o bin -g bin -m 755 talk ${DESTDIR}/usr/ucb/talk
E 12
E 9
E 6

D 6
tags:	${SOURCE} ${INCLUDE}
	ctags ${SOURCE} ${INCLUDE}
E 6
I 6
D 9
tags:	${SRCS} ${INCLUDE}
	ctags ${SRCS} ${INCLUDE}
E 9
I 9
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 9

D 9
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
E 9
I 9
tags: FRC
	ctags ${SRCS}
E 9

D 9
# DO NOT DELETE THIS LINE -- make depend uses it
E 9
I 9
FRC:
E 9

D 9
talk: talk.c ./talk.h /usr/include/curses.h /usr/include/stdio.h
talk: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
talk: /usr/include/sys/ttydev.h /usr/include/utmp.h
get_names: get_names.c ./talk.h /usr/include/curses.h /usr/include/stdio.h
get_names: /usr/include/sgtty.h /usr/include/sys/ioctl.h
get_names: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
get_names: /usr/include/utmp.h /usr/include/sys/param.h
get_names: /usr/include/machine/machparam.h /usr/include/signal.h
get_names: /usr/include/sys/types.h /usr/include/protocols/talkd.h
get_names: /usr/include/sys/types.h /usr/include/sys/socket.h
display: display.c ./talk.h /usr/include/curses.h /usr/include/stdio.h
display: /usr/include/sgtty.h /usr/include/sys/ioctl.h
display: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
display: /usr/include/utmp.h
io: io.c ./talk.h /usr/include/curses.h /usr/include/stdio.h
io: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
io: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/stdio.h
io: /usr/include/errno.h /usr/include/sys/time.h /usr/include/time.h
ctl: ctl.c ./talk_ctl.h /usr/include/sys/types.h /usr/include/protocols/talkd.h
ctl: /usr/include/sys/types.h /usr/include/sys/socket.h
ctl: /usr/include/netinet/in.h ./talk.h /usr/include/curses.h
ctl: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ctl: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h /usr/include/utmp.h
ctl: /usr/include/errno.h
init_disp: init_disp.c ./talk.h /usr/include/curses.h /usr/include/stdio.h
init_disp: /usr/include/sgtty.h /usr/include/sys/ioctl.h
init_disp: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
init_disp: /usr/include/utmp.h /usr/include/signal.h
msgs: msgs.c /usr/include/signal.h /usr/include/stdio.h /usr/include/sys/time.h
msgs: /usr/include/time.h ./talk.h /usr/include/curses.h /usr/include/stdio.h
msgs: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
msgs: /usr/include/sys/ttydev.h /usr/include/utmp.h
get_addrs: get_addrs.c ./talk_ctl.h /usr/include/sys/types.h
get_addrs: /usr/include/protocols/talkd.h /usr/include/sys/types.h
get_addrs: /usr/include/sys/socket.h /usr/include/netinet/in.h ./talk.h
get_addrs: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
get_addrs: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
get_addrs: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
get_addrs: /usr/include/netdb.h
ctl_transact: ctl_transact.c ./talk_ctl.h /usr/include/sys/types.h
ctl_transact: /usr/include/protocols/talkd.h /usr/include/sys/types.h
ctl_transact: /usr/include/sys/socket.h /usr/include/netinet/in.h ./talk.h
ctl_transact: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
ctl_transact: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
ctl_transact: /usr/include/sys/ttydev.h /usr/include/utmp.h
ctl_transact: /usr/include/errno.h /usr/include/sys/time.h /usr/include/time.h
invite: invite.c ./talk_ctl.h /usr/include/sys/types.h
invite: /usr/include/protocols/talkd.h /usr/include/sys/types.h
invite: /usr/include/sys/socket.h /usr/include/netinet/in.h ./talk.h
invite: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
invite: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
invite: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
invite: /usr/include/sys/time.h /usr/include/time.h /usr/include/signal.h
invite: /usr/include/setjmp.h
look_up: look_up.c ./talk_ctl.h /usr/include/sys/types.h
look_up: /usr/include/protocols/talkd.h /usr/include/sys/types.h
look_up: /usr/include/sys/socket.h /usr/include/netinet/in.h ./talk.h
look_up: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
look_up: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
look_up: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 9
I 9
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 10
talk.o: talk.c
talk.o:talk.h
talk.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
talk.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 10
I 10
talk.o: talk.c talk.h /usr/include/curses.h /usr/include/stdio.h
talk.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
talk.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 10
talk.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
D 10
get_names.o: get_names.c
get_names.o:talk.h
get_names.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
get_names.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 10
I 10
get_names.o: get_names.c talk.h /usr/include/curses.h /usr/include/stdio.h
get_names.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
get_names.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 10
get_names.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
get_names.o: /usr/include/sys/param.h /usr/include/sys/types.h
D 10
get_names.o: /usr/include/signal.h /usr/include/machine/machparam.h
E 10
I 10
get_names.o: /usr/include/signal.h /usr/include/machine/trap.h
get_names.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
E 10
get_names.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
D 10
get_names.o: /usr/include/sys/socket.h
display.o: display.c
display.o:talk.h
display.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
display.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 10
I 10
get_names.o: /usr/include/sys/socket.h /usr/include/pwd.h
display.o: display.c talk.h /usr/include/curses.h /usr/include/stdio.h
display.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
display.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 10
display.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
D 10
io.o: io.c
io.o:talk.h
io.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
io.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
io.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/stdio.h
io.o: /usr/include/errno.h /usr/include/sys/time.h /usr/include/time.h
ctl.o: ctl.c
ctl.o:talk_ctl.h
ctl.o: /usr/include/sys/types.h /usr/include/protocols/talkd.h
E 10
I 10
io.o: io.c talk.h /usr/include/curses.h /usr/include/stdio.h
io.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
io.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
io.o: /usr/include/utmp.h /usr/include/stdio.h /usr/include/errno.h
io.o: /usr/include/sys/time.h /usr/include/time.h
ctl.o: ctl.c talk_ctl.h /usr/include/sys/types.h /usr/include/protocols/talkd.h
E 10
ctl.o: /usr/include/sys/types.h /usr/include/sys/socket.h
D 10
ctl.o: /usr/include/netinet/in.h
ctl.o:talk.h
ctl.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
ctl.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 10
I 10
ctl.o: /usr/include/netinet/in.h talk.h /usr/include/curses.h
ctl.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
ctl.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 10
ctl.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
D 10
init_disp.o: init_disp.c
init_disp.o:talk.h
init_disp.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
init_disp.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 10
I 10
init_disp.o: init_disp.c talk.h /usr/include/curses.h /usr/include/stdio.h
init_disp.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
init_disp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
E 10
init_disp.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
D 10
init_disp.o: /usr/include/signal.h
msgs.o: msgs.c /usr/include/signal.h /usr/include/stdio.h
msgs.o: /usr/include/sys/time.h /usr/include/time.h
msgs.o:talk.h
E 10
I 10
init_disp.o: /usr/include/signal.h /usr/include/machine/trap.h
msgs.o: msgs.c /usr/include/signal.h /usr/include/machine/trap.h
msgs.o: /usr/include/stdio.h /usr/include/sys/time.h /usr/include/time.h talk.h
E 10
msgs.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
msgs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 10
msgs.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
get_addrs.o: get_addrs.c
get_addrs.o:talk_ctl.h
get_addrs.o: /usr/include/sys/types.h /usr/include/protocols/talkd.h
get_addrs.o: /usr/include/sys/types.h /usr/include/sys/socket.h
get_addrs.o: /usr/include/netinet/in.h
get_addrs.o:talk.h
E 10
I 10
msgs.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
msgs.o: /usr/include/utmp.h
get_addrs.o: get_addrs.c talk_ctl.h /usr/include/sys/types.h
get_addrs.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
get_addrs.o: /usr/include/sys/socket.h /usr/include/netinet/in.h talk.h
E 10
get_addrs.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
get_addrs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 10
get_addrs.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
get_addrs.o: /usr/include/netdb.h
ctl_transact.o: ctl_transact.c
ctl_transact.o:talk_ctl.h
ctl_transact.o: /usr/include/sys/types.h /usr/include/protocols/talkd.h
ctl_transact.o: /usr/include/sys/types.h /usr/include/sys/socket.h
ctl_transact.o: /usr/include/netinet/in.h
ctl_transact.o:talk.h
E 10
I 10
get_addrs.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
get_addrs.o: /usr/include/utmp.h /usr/include/errno.h /usr/include/netdb.h
ctl_transact.o: ctl_transact.c talk_ctl.h /usr/include/sys/types.h
ctl_transact.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
ctl_transact.o: /usr/include/sys/socket.h /usr/include/netinet/in.h talk.h
E 10
ctl_transact.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
ctl_transact.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 10
ctl_transact.o: /usr/include/sys/ttydev.h /usr/include/utmp.h
ctl_transact.o: /usr/include/errno.h /usr/include/sys/time.h
ctl_transact.o: /usr/include/time.h
invite.o: invite.c
invite.o:talk_ctl.h
invite.o: /usr/include/sys/types.h /usr/include/protocols/talkd.h
invite.o: /usr/include/sys/types.h /usr/include/sys/socket.h
invite.o: /usr/include/netinet/in.h
invite.o:talk.h
E 10
I 10
ctl_transact.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
ctl_transact.o: /usr/include/utmp.h /usr/include/errno.h
ctl_transact.o: /usr/include/sys/time.h /usr/include/time.h
invite.o: invite.c talk_ctl.h /usr/include/sys/types.h
invite.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
invite.o: /usr/include/sys/socket.h /usr/include/netinet/in.h talk.h
E 10
invite.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
invite.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 10
invite.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
invite.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/signal.h
E 10
I 10
invite.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
invite.o: /usr/include/utmp.h /usr/include/errno.h /usr/include/sys/time.h
invite.o: /usr/include/time.h /usr/include/signal.h /usr/include/machine/trap.h
E 10
invite.o: /usr/include/setjmp.h
D 10
look_up.o: look_up.c
look_up.o:talk_ctl.h
look_up.o: /usr/include/sys/types.h /usr/include/protocols/talkd.h
look_up.o: /usr/include/sys/types.h /usr/include/sys/socket.h
look_up.o: /usr/include/netinet/in.h
look_up.o:talk.h
E 10
I 10
look_up.o: look_up.c talk_ctl.h /usr/include/sys/types.h
look_up.o: /usr/include/protocols/talkd.h /usr/include/sys/types.h
look_up.o: /usr/include/sys/socket.h /usr/include/netinet/in.h talk.h
E 10
look_up.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
look_up.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 10
look_up.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/errno.h
E 10
I 10
look_up.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
look_up.o: /usr/include/utmp.h /usr/include/errno.h
E 10

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 6
E 1

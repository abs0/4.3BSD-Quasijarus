h20442
s 00074/00016/00015
d D 5.7 87/06/02 21:57:44 bostic 8 7
c new template
e
s 00002/00000/00029
d D 5.6 87/05/31 20:43:56 bostic 7 6
c added depend label
e
s 00003/00003/00026
d D 5.5 85/09/17 21:42:44 sklower 6 5
c -O as standard instead of -g
e
s 00007/00007/00022
d D 5.4 85/08/16 22:12:49 sklower 5 3
c forgot to actually add sccs keyword lines.
e
s 00007/00007/00022
d R 5.4 85/08/16 22:11:50 sklower 4 3
c fprg
e
s 00000/00000/00029
d D 5.3 85/08/16 21:48:41 sklower 3 2
c This version Aug 16th -- source directory moved to /usr/src/etc/XNSrouted;
c includes fix to response to request for specific net, and adds copyright notices
e
s 00006/00006/00023
d D 5.2 85/08/16 20:43:28 sklower 2 1
c status as of 4.3 alpha tape
e
s 00029/00000/00000
d D 5.1 85/08/16 20:22:29 sklower 1 0
c date and time created 85/08/16 20:22:29 by sklower
e
u
U
t
T
I 5
#
D 8
# Copyright (c) 1983 Regents of the University of California.
E 8
I 8
# Copyright (c) 1987 Regents of the University of California.
E 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 8
#	%W% (Berkeley) %G%";
E 8
I 8
#	%W%	(Berkeley)	%G%
E 8
#
E 5
I 1
#	Makefile for Xerox Routing Information Protocol
#	Daemon
#
D 2
ALL=	xnsrouted
E 2
I 2
D 8
ALL=	XNSrouted
E 8
I 8
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	af.c if.c input.c main.c output.c startup.c tables.c timer.c \
	trace.c
E 8
E 2
OBJS=	af.o if.o input.o main.o output.o startup.o tables.o timer.o \
	trace.o
D 6
CFLAGS= -g
E 6
I 6
D 8
CFLAGS=  -O
E 6
C2=	/lib/c2
ASMSCRIPT= /sys/machine/asm.sed
DESTDIR=
D 6
LDFLAGS= -g
E 6
I 6
LDFLAGS=
E 8
E 6

D 8
all:	${ALL}
E 8
I 8
all: XNSrouted
E 8

D 2
xnsrouted: ${OBJS}
	${CC} -o xnsrouted ${LDFLAGS} ${OBJS}
E 2
I 2
D 8
XNSrouted: ${OBJS}
D 6
	${CC} -o XNSrouted ${LDFLAGS} ${OBJS}
E 6
I 6
	${CC} -g -o XNSrouted ${LDFLAGS} ${OBJS}
E 8
I 8
XNSrouted: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 8
E 6
E 2

D 2
install: xnsrouted
	install -s xnsrouted ${DESTDIR}/etc
E 2
I 2
D 8
install: XNSrouted
	install -s XNSrouted ${DESTDIR}/etc
E 8
I 8
clean: FRC
	rm -f ${OBJS} core XNSrouted
E 8
E 2
D 5

# The following can be deleted where not appropriate to use the kernel's
# inline code expansions.
#.c.o:
#	${CC} -S ${CFLAGS} $*.c
#	${C2} $*.s | sed -f ${ASMSCRIPT} | ${AS} -o $*.o
#	rm -f $*.s
E 5

D 8
clean:
D 2
	rm -f xnsrouted *.o core a.out t.c linterrs typescript errs
E 2
I 2
	rm -f XNSrouted *.o core a.out t.c linterrs typescript errs
E 8
I 8
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 8
I 7

D 8
depend:
E 8
I 8
install: FRC
	install -s -o bin -g bin -m 755 XNSrouted ${DESTDIR}/etc/XNSrouted

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

af.o: af.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
af.o: /usr/include/net/route.h /usr/include/netns/ns.h /usr/include/netns/idp.h
af.o: /usr/include/stdio.h /usr/include/syslog.h protocol.h trace.h interface.h
af.o: table.h af.h
if.o: if.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
if.o: /usr/include/net/route.h /usr/include/netns/ns.h /usr/include/netns/idp.h
if.o: /usr/include/stdio.h /usr/include/syslog.h protocol.h trace.h interface.h
if.o: table.h af.h
input.o: input.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
input.o: /usr/include/net/route.h /usr/include/netns/ns.h
input.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
input.o: protocol.h trace.h interface.h table.h af.h
main.o: main.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
main.o: /usr/include/net/route.h /usr/include/netns/ns.h
main.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
main.o: protocol.h trace.h interface.h table.h af.h /usr/include/sys/ioctl.h
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/net/if.h
main.o: /usr/include/net/if_arp.h /usr/include/errno.h /usr/include/nlist.h
main.o: /usr/include/signal.h
output.o: output.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
output.o: /usr/include/net/route.h /usr/include/netns/ns.h
output.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
output.o: protocol.h trace.h interface.h table.h af.h
startup.o: startup.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
startup.o: /usr/include/net/route.h /usr/include/netns/ns.h
startup.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
startup.o: protocol.h trace.h interface.h table.h af.h /usr/include/sys/ioctl.h
startup.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
startup.o: /usr/include/net/if.h /usr/include/net/if_arp.h /usr/include/nlist.h
startup.o: /usr/include/syslog.h
tables.o: tables.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
tables.o: /usr/include/net/route.h /usr/include/netns/ns.h
tables.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
tables.o: protocol.h trace.h interface.h table.h af.h /usr/include/sys/ioctl.h
tables.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tables.o: /usr/include/errno.h
timer.o: timer.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
timer.o: /usr/include/net/route.h /usr/include/netns/ns.h
timer.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
timer.o: protocol.h trace.h interface.h table.h af.h
trace.o: trace.c defs.h /usr/include/sys/types.h /usr/include/sys/socket.h
trace.o: /usr/include/net/route.h /usr/include/netns/ns.h
trace.o: /usr/include/netns/idp.h /usr/include/stdio.h /usr/include/syslog.h
trace.o: protocol.h trace.h interface.h table.h af.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 7
E 2
E 1

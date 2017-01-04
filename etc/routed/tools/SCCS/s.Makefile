h44885
s 00011/00010/00045
d D 5.3 88/06/11 18:25:39 karels 8 7
c use CFLAGS
e
s 00044/00015/00011
d D 5.2 87/12/01 17:32:21 bostic 7 6
c new template
e
s 00007/00001/00019
d D 5.1 85/06/04 16:41:03 dist 6 5
c Add copyright
e
s 00005/00019/00015
d D 4.5 83/12/21 14:23:46 karels 5 4
c upgrade to 4.2; headers in ..; query looks for multiple responses
c from a host.
e
s 00005/00003/00029
d D 4.4 82/10/21 14:40:58 sam 4 3
c DESTDIR and less work by default
e
s 00005/00011/00027
d D 4.3 82/10/06 14:33:50 sam 3 2
c make install and clean, etc
e
s 00000/00001/00038
d D 4.2 82/10/06 10:34:34 sam 2 1
c no route here, up one level
e
s 00039/00000/00000
d D 4.1 82/10/06 10:28:44 sam 1 0
c date and time created 82/10/06 10:28:44 by sam
e
u
U
t
T
I 1
D 6
# %M% %G%
E 6
I 6
#
D 7
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
E 7
#
I 7
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
#
E 7
#	%W% (Berkeley) %G%
#
E 6
D 5
ALL=	rip.h routed.c query.c trace.c
E 5
I 5
D 7
ALL=	../protocol.h query.c trace.c
E 7
E 5
CFLAGS=	-O
I 4
D 7
DESTDIR=
E 4
LDFLAGS=
E 7
I 7
SRCS=	query.c trace.c
E 7

D 5
.c.o:
	${CC} -S ${CFLAGS} $*.c
	sed -f ../asm.sed $*.s | ${AS} -o $*.o
	rm -f $*.s
E 5
I 5
D 7
all:	query trace
E 7
I 7
all: query trace
E 7
E 5

D 4
all:	routed query trace
E 4
I 4
D 5
all:	routed
E 4

routed: routed.o af.o
	${CC} -o routed ${LDFLAGS} routed.o af.o -ljobs

D 3
routed.o: rip.h router.h
af.o: router.h
E 3
I 3
routed.o query.o: rip.h
routed.o af.o: router.h
E 3

E 5
I 4
# test programs and utilities
E 4
D 3
query:	query.o raddr.o
	${CC} -o query ${LDFLAGS} query.o raddr.o
E 3
I 3
D 7
query:	query.o
	${CC} -o query ${LDFLAGS} query.o
E 7
I 7
query:
D 8
	${CC} -o $@ query.c
E 8
I 8
	${CC} ${CFLAGS} -o $@ query.c
E 8
E 7
E 3

D 3
query.o: rip.h
raddr.o: ../raddr.c
	${CC} -S ${CFLAGS} ../raddr.c
	sed -f ../asm.sed raddr.s | ${AS} -o raddr.o
	rm -f raddr.s

E 3
D 7
trace:	trace.o
	${CC} -o trace ${LDFLAGS} trace.o
E 7
I 7
trace:
D 8
	${CC} -o $@ trace.c
E 8
I 8
	${CC} ${CFLAGS} -o $@ trace.c
E 8
E 7

D 3
install: ${ALL}
E 3
I 3
D 4
install: routed trace query
E 3
	install -s routed /etc
E 4
I 4
D 5
install: routed
	install -s routed ${DESTDIR}/etc
E 5
I 5
D 7
install:
	@echo Nothing to install
E 7
I 7
install: FRC
E 7
E 5
E 4
D 2
	install -s route /etc
E 2

D 5
lint:
	lint -hbxn routed.c af.c

E 5
D 7
clean:
D 5
	rm -f routed *.o core a.out t.c query linterrs trace typescript errs
E 5
I 5
	rm -f *.o core a.out t.c query linterrs trace typescript errs
E 7
I 7
clean: FRC
	rm -f core query trace tags

depend: FRC
	mkdep -p ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

query: query.c /usr/include/sys/param.h /usr/include/sys/types.h
query: /usr/include/signal.h /usr/include/machine/trap.h
D 8
query: /usr/include/machine/machparam.h /usr/include/sys/protosw.h
query: /usr/include/sys/socket.h /usr/include/sys/time.h /usr/include/time.h
query: /usr/include/netinet/in.h /usr/include/errno.h /usr/include/stdio.h
query: /usr/include/netdb.h /usr/include/protocols/routed.h
E 8
I 8
query: /usr/include/machine/machparam.h /usr/include/machine/endian.h
query: /usr/include/sys/protosw.h /usr/include/sys/socket.h
query: /usr/include/sys/time.h /usr/include/time.h /usr/include/netinet/in.h
query: /usr/include/errno.h /usr/include/stdio.h /usr/include/netdb.h
query: /usr/include/protocols/routed.h
E 8
trace: trace.c /usr/include/sys/param.h /usr/include/sys/types.h
trace: /usr/include/signal.h /usr/include/machine/trap.h
D 8
trace: /usr/include/machine/machparam.h /usr/include/sys/protosw.h
trace: /usr/include/sys/socket.h /usr/include/netinet/in.h /usr/include/errno.h
trace: /usr/include/stdio.h /usr/include/netdb.h
trace: /usr/include/protocols/routed.h
E 8
I 8
trace: /usr/include/machine/machparam.h /usr/include/machine/endian.h
trace: /usr/include/sys/protosw.h /usr/include/sys/socket.h
trace: /usr/include/netinet/in.h /usr/include/errno.h /usr/include/stdio.h
trace: /usr/include/netdb.h /usr/include/protocols/routed.h
E 8

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 7
E 5
E 1

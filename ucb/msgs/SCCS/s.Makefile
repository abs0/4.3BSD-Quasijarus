h12035
s 00040/00015/00007
d D 5.3 87/06/16 18:35:23 bostic 4 3
c new template
e
s 00003/00000/00019
d D 5.2 87/05/31 21:12:12 bostic 3 2
c added depend label
e
s 00006/00001/00013
d D 5.1 85/06/04 15:28:16 dist 2 1
c Add copyright
e
s 00014/00000/00000
d D 4.1 82/05/19 10:14:28 rrh 1 0
c date and time created 82/05/19 10:14:28 by rrh
e
u
U
t
T
I 1
#
D 2
#	%W% %G%
E 2
I 2
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
#
E 2
D 4
#
CFLAGS=-O
SRCS = msgs.c msgs.h Makefile
msgs: msgs.c msgs.h
	cc $(CFLAGS) -o msgs msgs.c -ltermlib
install:
	install -s msgs ${DESTDIR}/usr/ucb
clean:
	-rm -f msgs
E 4
I 4
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	msgs.c
OBJS=	msgs.o
E 4
I 3

D 4
depend:
E 4
I 4
all: msgs
E 4

E 3
D 4
sources: $(SRCS)
$(SRCS):
	sccs get $@
E 4
I 4
msgs:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -ltermlib

clean: FRC
	rm -f ${OBJS} core msgs

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 msgs ${DESTDIR}/usr/ucb/msgs

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

msgs.o: msgs.c /usr/include/stdio.h /usr/include/sys/param.h
msgs.o: /usr/include/sys/types.h /usr/include/signal.h
msgs.o: /usr/include/machine/machparam.h /usr/include/signal.h
msgs.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/ctype.h
msgs.o: /usr/include/pwd.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
msgs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
msgs.o: /usr/include/setjmp.h
msgs.o:msgs.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1

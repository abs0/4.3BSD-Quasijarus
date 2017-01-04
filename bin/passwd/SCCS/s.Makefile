h29281
s 00009/00011/00036
d D 5.2 88/01/21 10:27:34 bostic 2 1
c only compile the one file
e
s 00047/00000/00000
d D 5.1 87/12/12 17:14:19 bostic 1 0
c date and time created 87/12/12 17:14:19 by bostic
e
u
U
f b 
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	passwd.c
D 2
OBJS=	passwd.o
E 2

all: passwd

D 2
passwd:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 2
I 2
passwd: ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS}
E 2

clean: FRC
D 2
	rm -f ${OBJS} core passwd
E 2
I 2
	rm -f core passwd
E 2

depend: FRC
D 2
	mkdep ${CFLAGS} ${SRCS}
E 2
I 2
	mkdep -p ${CFLAGS} ${SRCS}
E 2

install: FRC
	install -s -o root -g bin -m 4755 passwd ${DESTDIR}/bin/passwd
	rm -f ${DESTDIR}/bin/chfn; ln ${DESTDIR}/bin/passwd ${DESTDIR}/bin/chfn
	rm -f ${DESTDIR}/bin/chsh; ln ${DESTDIR}/bin/passwd ${DESTDIR}/bin/chsh

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 2
passwd.o: passwd.c /usr/include/sys/types.h /usr/include/sys/file.h
passwd.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
passwd.o: /usr/include/sys/resource.h /usr/include/stdio.h
passwd.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/pwd.h
passwd.o: /usr/include/ndbm.h /usr/include/errno.h /usr/include/strings.h
passwd.o: /usr/include/ctype.h
E 2
I 2
passwd: passwd.c /usr/include/sys/types.h /usr/include/sys/file.h
passwd: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
passwd: /usr/include/sys/resource.h /usr/include/stdio.h /usr/include/signal.h
passwd: /usr/include/machine/trap.h /usr/include/pwd.h /usr/include/ndbm.h
passwd: /usr/include/errno.h /usr/include/strings.h /usr/include/ctype.h
E 2

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1

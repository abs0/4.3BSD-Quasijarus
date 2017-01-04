h43802
s 00010/00005/00048
d D 5.3 88/06/18 14:47:02 bostic 3 2
c install approved copyright notice
e
s 00011/00011/00042
d D 5.2 87/12/29 17:29:47 bostic 2 1
c don't use intermediate .o
e
s 00053/00000/00000
d D 5.1 87/11/30 16:17:23 bostic 1 0
c date and time created 87/11/30 16:17:23 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
#
#	%W% (Berkeley) %G%
#
# -DLOG		log games in /usr/adm
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	dm.c
D 2
OBJS=	dm.o
E 2
I 2
OBJS=
E 2

all: dm

D 2
dm: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 2
I 2
dm: ${LIBC}
	${CC} -o $@ ${CFLAGS} dm.c
E 2

clean: FRC
D 2
	rm -f ${OBJS} core dm
E 2
I 2
	rm -f core dm
E 2

depend: FRC
D 2
	mkdep ${CFLAGS} ${SRCS}
E 2
I 2
	mkdep -p ${CFLAGS} ${SRCS}
E 2

install: FRC
	install -s -o games -g kmem -m 6755 dm ${DESTDIR}/usr/games
#	install -c -o games -g bin -m 444 dm.config ${DESTDIR}/usr/games

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 2
dm.o: dm.c /usr/include/sys/param.h /usr/include/sys/types.h
dm.o: /usr/include/signal.h /usr/include/machine/trap.h
dm.o: /usr/include/machine/machparam.h /usr/include/sys/file.h
dm.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
dm.o: /usr/include/pwd.h /usr/include/utmp.h /usr/include/nlist.h
dm.o: /usr/include/stdio.h /usr/include/ctype.h
E 2
I 2
dm: dm.c /usr/include/sys/param.h /usr/include/sys/types.h
dm: /usr/include/signal.h /usr/include/machine/trap.h
dm: /usr/include/machine/machparam.h /usr/include/sys/file.h
dm: /usr/include/sys/time.h /usr/include/time.h /usr/include/sys/resource.h
dm: /usr/include/pwd.h /usr/include/utmp.h /usr/include/nlist.h
dm: /usr/include/stdio.h /usr/include/ctype.h
E 2

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1

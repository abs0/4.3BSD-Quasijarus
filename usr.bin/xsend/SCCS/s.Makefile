h33781
s 00050/00018/00011
d D 4.4 87/06/19 00:00:43 bostic 4 3
c new template
e
s 00002/00000/00027
d D 4.3 87/05/31 21:34:06 bostic 3 2
c added depend label
e
s 00006/00007/00021
d D 4.2 83/06/30 14:26:47 sam 2 1
c from sun
e
s 00028/00000/00000
d D 4.1 83/03/30 12:08:40 sam 1 0
c date and time created 83/03/30 12:08:40 by sam
e
u
U
t
T
I 1
D 4
#	%M%	%I%	%E%
E 4
#
I 4
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 4
D 2
CFLAGS=	-O -d2
E 2
I 2
CFLAGS=	-O
E 2
D 4
DESTDIR=
I 2
ALL=	enroll xsend xget
E 4
I 4
LIBC=	/lib/libc.a
SRCS=	enroll.c lib.c xget.c xsend.c
OBJS=	enroll.o lib.o xget.o xsend.o
E 4
E 2

D 2
all:	enroll xsend xget
E 2
I 2
D 4
all:	${ALL}
E 4
I 4
all: enroll xsend xget
E 4
E 2

D 4
enroll:	enroll.o lib.o
	${CC} enroll.o lib.o -lmp -o enroll
E 4
I 4
enroll: enroll.o lib.o ${LIBC}
	${CC} enroll.o lib.o -lmp -o $@
E 4

D 4
xget:	xget.o lib.o
	${CC} xget.o lib.o -lmp -o xget
E 4
I 4
xget: xget.o lib.o ${LIBC}
	${CC} xget.o lib.o -lmp -o $@
E 4

D 4
xsend:	xsend.o lib.o
	${CC} xsend.o lib.o -lmp -o xsend
E 4
I 4
xsend: xsend.o lib.o ${LIBC}
	${CC} xsend.o lib.o -lmp -o $@
E 4

D 4
enroll.o xget.o xsend.o lib.o:	xmail.h
E 4
I 4
clean: FRC
	rm -f ${OBJS} core enroll xsend xget
E 4

D 4
list:
D 2
	@pr -2 -w124 m.h xmail.h enroll.c xsend.c xget.c lib.c makefile
E 2
I 2
	@pr -2 -w124 m.h xmail.h enroll.c xsend.c xget.c lib.c Makefile
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 4
E 2

D 4
install: enroll xsend xget
D 2
	install -s enroll ${DESTDIR}/usr/bin
	install -s xsend ${DESTDIR}/usr/bin
	install -s xget ${DESTDIR}/usr/bin
E 2
I 2
	for i in ${ALL}; do install -s $$i ${DESTDIR}/usr/bin; done
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 enroll ${DESTDIR}/usr/bin/enroll
	install -s -o bin -g bin -m 755 xget ${DESTDIR}/usr/bin/xget
	install -s -o bin -g bin -m 755 xsend ${DESTDIR}/usr/bin/xsend
E 4
E 2

D 4
clean:
D 2
	rm -f *.o yacc.* y.tab.c
E 2
I 2
	rm -f *.o yacc.* y.tab.c ${ALL}
E 4
I 4
lint: FRC
	lint ${CFLAGS} enroll.c lib.c
	lint ${CFLAGS} xget.c lib.c
	lint ${CFLAGS} xsend.c lib.c
E 4
I 3

D 4
depend:
E 4
I 4
tags: FRC
	ctags enroll.c lib.c
	ctags -a xget.c
	ctags -a xsend.c
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

enroll.o: enroll.c xmail.h /usr/include/stdio.h /usr/include/mp.h
enroll.o: /usr/include/pwd.h /usr/include/sys/types.h
lib.o: lib.c xmail.h /usr/include/stdio.h /usr/include/mp.h
xget.o: xget.c xmail.h /usr/include/stdio.h /usr/include/mp.h
xget.o: /usr/include/sys/types.h /usr/include/sys/dir.h /usr/include/ctype.h
xget.o: /usr/include/pwd.h /usr/include/sys/stat.h
xsend.o: xsend.c xmail.h /usr/include/stdio.h /usr/include/mp.h
xsend.o: /usr/include/sys/types.h /usr/include/pwd.h /usr/include/sys/stat.h
xsend.o: /usr/include/sys/dir.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 3
E 2
E 1

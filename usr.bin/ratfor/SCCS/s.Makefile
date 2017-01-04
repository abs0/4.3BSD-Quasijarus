h05521
s 00042/00019/00005
d D 5.3 87/06/18 22:46:05 bostic 3 2
c new template
e
s 00001/00000/00023
d D 5.2 87/05/31 21:32:14 bostic 2 1
c added depend label
e
s 00023/00000/00000
d D 5.1 82/12/15 21:49:57 clemc 1 0
c date and time created 82/12/15 21:49:57 by clemc
e
u
U
t
T
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
YFLAGS=	-d
LIBC=	/lib/libc.a
SRCS=	r.c r0.c r1.c r2.c rio.c rlook.c rlex.c
OBJS=	r.o r0.o r1.o r2.o rio.o rlook.o rlex.o
E 3
I 1

D 3
#	%W% (Berkeley) %G%
E 3
I 3
all: ratfor
E 3

D 3
CFLAGS = -O
E 3
I 3
ratfor:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 3

D 3
ratfor:	r0.o r1.o r2.o rio.o rlook.o rlex.o y.tab.o
	cc r*.o y.tab.o -o ratfor
E 3
I 3
clean: FRC
	rm -f ${OBJS} core ratfor r.c
E 3

D 3
r0.o:	r.h y.tab.h r0.c
r1.o:	r.h y.tab.h r1.c
r2.o:	r.h y.tab.h r2.c
rio.o:	r.h y.tab.h rio.c
rlook.o:	r.h y.tab.h rlook.c
rlex.o:	r.h y.tab.h rlex.c
y.tab.c:	r.g
	yacc -d r.g
y.tab.h:	r.g
	yacc -d r.g
install: ratfor
	install -s ratfor $(DESTDIR)/usr/bin
clean:
	rm -f y.tab.c *.o ratfor y.tab.h
E 3
I 3
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

I 2
D 3
depend:
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 ratfor ${DESTDIR}/usr/bin/ratfor

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

r.o: r.c
r0.o: r0.c r.h /usr/include/stdio.h y.tab.h
r1.o: r1.c r.h /usr/include/stdio.h y.tab.h
r2.o: r2.c r.h /usr/include/stdio.h y.tab.h
rio.o: rio.c r.h /usr/include/stdio.h y.tab.h
rlook.o: rlook.c
rlex.o: rlex.c r.h /usr/include/stdio.h y.tab.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1

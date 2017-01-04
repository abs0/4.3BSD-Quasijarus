h32571
s 00001/00001/00047
d D 4.3 04/10/26 17:33:46 msokolov 3 2
c revive from the ashes
e
s 00036/00021/00012
d D 4.2 87/11/04 20:30:24 bostic 2 1
c new template
e
s 00033/00000/00000
d D 4.1 83/03/09 16:57:10 ralph 1 0
c date and time created 83/03/09 16:57:10 by ralph
e
u
U
t
T
I 1
#
D 2
#	%M%	%I%	%E%
E 2
I 2
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 2
#
I 2
#	%W%	(Berkeley)	%G%
#
E 2
CFLAGS=	-O
D 2
SRCS=	fed.h \
	fed.c subr.c io.c
E 2
I 2
LIBC=	/lib/libc.a
SRCS=	fed.c subr.c io.c
E 2
OBJS=	fed.o subr.o io.o
LIBS=	-lm -l2648
D 2
VGRIND=	csh /usr/ucb/vgrind
DESTDIR=
E 2

D 2
fed:	${OBJS} /usr/lib/lib2648.a
	${CC} -o fed ${CFLAGS} ${OBJS} ${LIBS}
E 2
I 2
all: fed
E 2

D 2
tags:	/tmp
	ctags ${SRCS}
E 2
I 2
fed: ${OBJS} ${LIBC} /usr/lib/lib2648.a
	${CC} -o $@ ${CFLAGS} ${OBJS} ${LIBS}
E 2

D 2
print:
	print ${SRCS}
E 2
I 2
clean: FRC
	rm -f ${OBJS} core fed
E 2

D 2
vgrind:
	tee index < /dev/null
	${VGRIND} -h fed ${SRCS}
	${VGRIND} -x index
E 2
I 2
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 2

D 2
lint:
	lint ${SRCS} > lint.out
E 2
I 2
install: FRC
D 3
	install -s -o bin -g bin -m 755 fed ${DESTDIR}/usr/old/fed
E 3
I 3
	install -s -o bin -g bin -m 755 fed ${DESTDIR}/usr/ucb/fed
E 3
E 2

D 2
clean:
	rm -f fed ${OBJS} errs core trace
E 2
I 2
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 2

D 2
install: fed
	install -s fed ${DESTDIR}/usr/ucb/fed
E 2
I 2
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

fed.o: fed.c fed.h /usr/include/stdio.h /usr/include/ctype.h
fed.o: /usr/include/vfont.h /usr/include/signal.h /usr/include/machine/trap.h
fed.o: /usr/include/setjmp.h
subr.o: subr.c fed.h /usr/include/stdio.h /usr/include/ctype.h
subr.o: /usr/include/vfont.h /usr/include/signal.h /usr/include/machine/trap.h
subr.o: /usr/include/setjmp.h
io.o: io.c fed.h /usr/include/stdio.h /usr/include/ctype.h /usr/include/vfont.h
io.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/setjmp.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 2
E 1

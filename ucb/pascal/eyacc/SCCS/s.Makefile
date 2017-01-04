h59946
s 00032/00017/00013
d D 5.2 87/10/26 09:03:07 bostic 3 1
c new template
e
s 00032/00017/00013
d R 5.2 87/10/16 16:05:15 bostic 2 1
c new template
e
s 00030/00000/00000
d D 5.1 86/06/05 14:09:35 mckusick 1 0
c date and time created 86/06/05 14:09:35 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 3
INSTALLDIR = ${DESTDIR}/usr/ucb
E 3
I 3
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	ey0.c ey1.c ey2.c ey3.c ey4.c ey5.c
OBJS=	ey0.o ey1.o ey2.o ey3.o ey4.o ey5.o
E 3

D 3
eyacc: ey0.o ey1.o ey2.o ey3.o ey4.o ey5.o
	cc -o eyacc -z ey0.o ey1.o ey2.o ey3.o ey4.o ey5.o
E 3
I 3
all: eyacc
E 3

D 3
.c.o:
	cc -O -c $*.c
E 3
I 3
eyacc: ${LIBC} ${OBJS}
	${CC} ${CFLAGS} -o $@ -z ${OBJS}
E 3

D 3
clean:
	-rm -f *.o eyacc
E 3
I 3
clean: FRC
	rm -f ${OBJS} core eyacc
E 3

D 3
install: eyacc
#	cp eyacc ${INSTALLDIR}/eyacc
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

D 3
print:
	@ls -l | pr
	@pr READ_ME makefile
	@pr ey.h ey0.c ey1.c ey2.c ey3.c ey4.c ey5.c
E 3
I 3
install: FRC
#	install -s -o bin -g bin -m 755 eyacc ${DESTDIR}/usr/ucb/eyacc
E 3

D 3
ey1.o:	ey.h
ey2.o:	ey.h
ey3.o:	ey.h
ey4.o:	ey.h
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

ey0.o: ey0.c /usr/include/stdio.h
ey1.o: ey1.c ey.h /usr/include/stdio.h
ey2.o: ey2.c ey.h /usr/include/stdio.h
ey3.o: ey3.c ey.h /usr/include/stdio.h
ey4.o: ey4.c ey.h /usr/include/stdio.h
ey5.o: ey5.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1

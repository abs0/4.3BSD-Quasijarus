h48841
s 00044/00008/00011
d D 5.2 87/06/19 16:38:53 bostic 3 2
c new template
e
s 00007/00001/00012
d D 5.1 85/05/07 11:44:01 dist 2 1
c Add copyright notice
e
s 00013/00000/00000
d D 4.1 83/11/10 16:03:26 ralph 1 0
c date and time created 83/11/10 16:03:26 by ralph
e
u
U
t
T
I 1
D 2
#	%M%	%I%	%E%
E 2
I 2
#
D 3
# Copyright (c) 1980 Regents of the University of California.
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
E 3
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 3
#	%W% (Berkeley) %G%
E 3
I 3
#	%W%	(Berkeley)	%G%
E 3
#
E 2
D 3
#
E 3
CFLAGS=	-O
I 3
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c
E 3
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o

D 3
../libplotgigi:	${OBJS}
	ar cu ../libplotgigi ${OBJS}
E 3
I 3
all: ../libplotgigi
E 3

D 3
${OBJS}:	gigi.h
E 3
I 3
../libplotgigi: ${OBJS}
	ar cu $@ ${OBJS}
E 3

D 3
clean:
	rm -f ${OBJS} errs a.out core
E 3
I 3
clean: FRC
	rm -f ${OBJS} core

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

install:
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

arc.o: arc.c gigi.h /usr/include/stdio.h /usr/include/math.h
box.o: box.c
circle.o: circle.c gigi.h /usr/include/stdio.h /usr/include/math.h
close.o: close.c /usr/include/signal.h gigi.h /usr/include/stdio.h
close.o: /usr/include/math.h
cont.o: cont.c gigi.h /usr/include/stdio.h /usr/include/math.h
dot.o: dot.c
erase.o: erase.c gigi.h /usr/include/stdio.h /usr/include/math.h
label.o: label.c gigi.h /usr/include/stdio.h /usr/include/math.h
line.o: line.c gigi.h /usr/include/stdio.h /usr/include/math.h
linemod.o: linemod.c gigi.h /usr/include/stdio.h /usr/include/math.h
move.o: move.c gigi.h /usr/include/stdio.h /usr/include/math.h
open.o: open.c /usr/include/signal.h gigi.h /usr/include/stdio.h
open.o: /usr/include/math.h
point.o: point.c gigi.h /usr/include/stdio.h /usr/include/math.h
space.o: space.c gigi.h /usr/include/stdio.h /usr/include/math.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1

h08367
s 00045/00008/00010
d D 5.2 87/06/19 16:38:07 bostic 8 6
c new template
e
s 00081/00010/00008
d R 5.2 87/06/19 16:32:00 bostic 7 6
c new template
e
s 00006/00001/00012
d D 5.1 85/04/30 16:18:03 dist 6 5
c add copyright
e
s 00001/00001/00012
d D 4.4 83/11/11 11:45:43 ralph 5 4
c forgot cont.o in lib.
e
s 00002/00002/00011
d D 4.3 83/11/10 16:09:11 ralph 4 2
c changed the library name
e
s 00002/00002/00011
d R 4.3 83/11/10 14:40:26 ralph 3 2
c changed library name
e
s 00002/00002/00011
d D 4.2 83/11/10 11:22:12 ralph 2 1
c fixing library order.
e
s 00013/00000/00000
d D 4.1 83/11/10 10:59:50 ralph 1 0
c date and time created 83/11/10 10:59:50 by ralph
e
u
U
t
T
I 1
D 6
#	%M%	%I%	%E%
E 6
I 6
D 8
# Copyright (c) 1980 Regents of the University of California.
E 8
I 8
#
# Copyright (c) 1987 Regents of the University of California.
E 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 8
#	%W% (Berkeley) %G%
E 8
I 8
#	%W%	(Berkeley)	%G%
E 8
#
E 6
D 8
#
E 8
CFLAGS=	-O
I 8
LIBC=	/lib/libc.a
SRCS=	box.c circle.c arc.c cont.c dot.c erase.c line.c linemod.c point.c \
	label.c move.c open.c close.c space.c
E 8
D 2
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o
E 2
I 2
D 5
OBJS=	box.o circle.o arc.o dot.o erase.o line.o linemod.o point.o \
E 5
I 5
OBJS=	box.o circle.o arc.o cont.o dot.o erase.o line.o linemod.o point.o \
E 5
	label.o move.o open.o close.o space.o
E 2

D 4
../libbg:	${OBJS}
	ar cu ../libbg ${OBJS}
E 4
I 4
D 8
../libplotbg:	${OBJS}
	ar cu ../libplotbg ${OBJS}
E 8
I 8
all: ../libplotbg
E 8
E 4

D 8
${OBJS}:	bg.h
E 8
I 8
../libplotbg: ${OBJS}
	ar cu $@ ${OBJS}
E 8

D 8
clean:
	rm -f ${OBJS} errs a.out core
E 8
I 8
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

box.o: box.c
circle.o: circle.c
arc.o: arc.c bg.h /usr/include/stdio.h /usr/include/math.h
cont.o: cont.c bg.h /usr/include/stdio.h /usr/include/math.h
dot.o: dot.c
erase.o: erase.c bg.h /usr/include/stdio.h /usr/include/math.h
line.o: line.c bg.h /usr/include/stdio.h /usr/include/math.h
linemod.o: linemod.c
point.o: point.c
label.o: label.c
move.o: move.c bg.h /usr/include/stdio.h /usr/include/math.h
open.o: open.c /usr/include/signal.h bg.h /usr/include/stdio.h
open.o: /usr/include/math.h
close.o: close.c /usr/include/signal.h bg.h /usr/include/stdio.h
close.o: /usr/include/math.h
space.o: space.c bg.h /usr/include/stdio.h /usr/include/math.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 1

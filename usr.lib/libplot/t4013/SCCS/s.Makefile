h57353
s 00043/00006/00010
d D 5.2 87/06/19 16:40:56 bostic 3 2
c new template
e
s 00006/00001/00010
d D 5.1 85/06/07 08:29:01 dist 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 85/01/02 20:10:32 jak 1 0
c date and time created 85/01/02 20:10:32 by jak
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
E 2
#
CFLAGS=	-O
I 3
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
E 3
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o subr.o

D 3
../lib4013:	${OBJS}
	ar cu ../lib4013 `lorder ${OBJS} | tsort`
E 3
I 3
all: ../lib4013
E 3

D 3
clean:
	rm -f ${OBJS} errs a.out core
E 3
I 3
../lib4013: ${OBJS}
	ar cu $@ `lorder ${OBJS} | tsort`

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

arc.o: arc.c
box.o: box.c
circle.o: circle.c
close.o: close.c /usr/include/stdio.h
dot.o: dot.c
erase.o: erase.c
label.o: label.c
line.o: line.c
linemod.o: linemod.c
move.o: move.c
open.o: open.c
point.o: point.c
space.o: space.c
subr.o: subr.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1

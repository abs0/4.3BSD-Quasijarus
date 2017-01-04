h61405
s 00044/00008/00009
d D 5.2 87/06/19 16:41:17 bostic 3 2
c new template
e
s 00006/00001/00011
d D 5.1 85/06/07 09:31:10 dist 2 1
c Add copyright
e
s 00012/00000/00000
d D 1.1 85/01/02 20:29:35 jak 1 0
c date and time created 85/01/02 20:29:35 by jak
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
D 3

OBJS = arc.o box.o circle.o clospl.o cont.o dot.o erase.o label.o \
E 3
I 3
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c clospl.c cont.c dot.c erase.c label.c \
	line.c linemd.c move.c open.c point.c space.c
OBJS=	arc.o box.o circle.o clospl.o cont.o dot.o erase.o label.o \
E 3
	line.o linemd.o move.o open.o point.o space.o

D 3
../libf77plot:	${OBJS}
	ar cu ../libf77plot `lorder ${OBJS} | tsort`
E 3
I 3
all: ../libf77plot
E 3

D 3
clean:
	rm -f ${OBJS} errs a.out core
E 3
I 3
../libf77plot: ${OBJS}
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
clospl.o: clospl.c
cont.o: cont.c
dot.o: dot.c
erase.o: erase.c
label.o: label.c
line.o: line.c
linemd.o: linemd.c
move.o: move.c
open.o: open.c
point.o: point.c
space.o: space.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1

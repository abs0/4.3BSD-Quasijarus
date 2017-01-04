h55448
s 00047/00005/00006
d D 4.4 87/06/19 16:41:25 bostic 4 3
c new template
e
s 00002/00002/00009
d D 4.3 83/07/09 23:45:21 sam 3 2
c name change
e
s 00002/00002/00009
d D 4.2 83/06/27 14:53:16 sam 2 1
c not a tektronix box
e
s 00011/00000/00000
d D 4.1 83/06/27 14:26:23 sam 1 0
c date and time created 83/06/27 14:26:23 by sam
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
CFLAGS=	-O
I 4
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c dot.c erase.c label.c \
	line.c linmod.c move.c open.c point.c space.c subr.c
E 4
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
	line.o linmod.o move.o open.o point.o space.o subr.o

D 2
../libtvt0.a:	${OBJS}
	ar cu ../libtvt0.a ${OBJS}
E 2
I 2
D 3
../libvt0.a:	${OBJS}
	ar cu ../libvt0.a ${OBJS}
E 3
I 3
D 4
../libvt0:	${OBJS}
	ar cu ../libvt0 ${OBJS}
E 4
I 4
all: ../libvt0
E 4
E 3
E 2

D 4
clean:
	rm -f ${OBJS} errs a.out core
E 4
I 4
../libvt0: ${OBJS}
	ar cu $@ ${OBJS}

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
close.o: close.c
dot.o: dot.c
erase.o: erase.c
label.o: label.c
line.o: line.c
linmod.o: linmod.c
move.o: move.c
open.o: open.c
point.o: point.c
space.o: space.c
subr.o: subr.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1

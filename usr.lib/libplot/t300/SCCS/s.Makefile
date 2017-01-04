h61838
s 00054/00005/00006
d D 4.4 87/06/19 16:40:35 bostic 5 4
c new template
e
s 00002/00002/00009
d D 4.3 83/09/21 18:54:51 sam 4 2
c wrong library name
e
s 00001/00001/00010
d R 4.3 83/09/21 18:51:50 sam 3 2
c wrong library name
e
s 00002/00002/00009
d D 4.2 83/07/09 23:44:04 sam 2 1
c name change
e
s 00011/00000/00000
d D 4.1 83/06/27 14:13:32 sam 1 0
c date and time created 83/06/27 14:13:32 by sam
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 5
CFLAGS=	-O
I 5
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c dot.c erase.c label.c \
	line.c linmod.c move.c open.c point.c space.c subr.c
E 5
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
	line.o linmod.o move.o open.o point.o space.o subr.o

D 2
../libt300.a:	${OBJS}
	ar cu ../libt300.a ${OBJS}
E 2
I 2
D 4
../libt300:	${OBJS}
	ar cu ../libt300 ${OBJS}
E 4
I 4
D 5
../lib300:	${OBJS}
	ar cu ../lib300 ${OBJS}
E 5
I 5
all: ../lib300
E 5
E 4
E 2

D 5
clean:
	rm -f ${OBJS} errs a.out core
E 5
I 5
../lib300: ${OBJS}
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
close.o: close.c /usr/include/stdio.h
dot.o: dot.c
erase.o: erase.c con.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
erase.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
label.o: label.c con.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
label.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
line.o: line.c con.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
line.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
linmod.o: linmod.c
move.o: move.c
open.o: open.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
open.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
point.o: point.c
space.o: space.c con.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
space.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
subr.o: subr.c /usr/include/stdio.h con.h /usr/include/sgtty.h
subr.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
subr.o: /usr/include/sys/ttydev.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1

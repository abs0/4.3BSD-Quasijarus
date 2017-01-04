h26100
s 00067/00007/00011
d D 5.2 87/06/19 16:36:18 bostic 4 2
c new template
e
s 00080/00009/00009
d R 5.2 87/06/19 16:31:30 bostic 3 2
c new template
e
s 00006/00001/00012
d D 5.1 85/06/05 10:06:09 dist 2 1
c Add copyright
e
s 00013/00000/00000
d D 4.1 83/11/11 15:13:06 ralph 1 0
c date and time created 83/11/11 15:13:06 by ralph
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
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
E 2
#
CFLAGS=	-O
I 4
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
E 4
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o subr.o

D 4
../libplotaed:	${OBJS}
	ar cu ../libplotaed ${OBJS}
E 4
I 4
all: ../libplotaed
E 4

D 4
${OBJS}:	aed.h
E 4
I 4
../libplotaed: ${OBJS}
	ar cu $@ ${OBJS}
E 4

D 4
clean:
	rm -f ${OBJS} errs a.out core
E 4
I 4
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
circle.o: circle.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
circle.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
circle.o: /usr/include/sys/ttydev.h
close.o: close.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
close.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
close.o: /usr/include/sys/ttydev.h
cont.o: cont.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
cont.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
cont.o: /usr/include/sys/ttydev.h
dot.o: dot.c
erase.o: erase.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
erase.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
erase.o: /usr/include/sys/ttydev.h
label.o: label.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
label.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
label.o: /usr/include/sys/ttydev.h
line.o: line.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
line.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
line.o: /usr/include/sys/ttydev.h
linemod.o: linemod.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
linemod.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
linemod.o: /usr/include/sys/ttydev.h
move.o: move.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
move.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
move.o: /usr/include/sys/ttydev.h
open.o: open.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
open.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
open.o: /usr/include/sys/ttydev.h
point.o: point.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
point.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
point.o: /usr/include/sys/ttydev.h
space.o: space.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
space.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
space.o: /usr/include/sys/ttydev.h
subr.o: subr.c aed.h /usr/include/stdio.h /usr/include/sgtty.h
subr.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
subr.o: /usr/include/sys/ttydev.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1

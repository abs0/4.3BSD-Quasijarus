h56395
s 00047/00008/00011
d D 5.2 87/06/19 16:39:06 bostic 4 3
c new template
e
s 00007/00001/00012
d D 5.1 85/05/07 12:08:40 dist 3 2
c Add copyright notice
e
s 00002/00002/00011
d D 4.2 83/11/10 16:14:25 ralph 2 1
c changed library name
e
s 00013/00000/00000
d D 4.1 83/11/10 14:11:56 ralph 1 0
c date and time created 83/11/10 14:11:56 by ralph
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
I 3
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
#
E 3
D 4
#
E 4
CFLAGS=	-O
I 4
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
E 4
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o subr.o

D 2
../lib2648:	${OBJS}
	ar cu ../lib2648 ${OBJS}
E 2
I 2
D 4
../libplot2648:	${OBJS}
	ar cu ../libplot2648 ${OBJS}
E 4
I 4
all: ../libplot2648
E 4
E 2

D 4
${OBJS}:	hp2648.h
E 4
I 4
../libplot2648: ${OBJS}
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

arc.o: arc.c hp2648.h /usr/include/stdio.h
box.o: box.c
circle.o: circle.c hp2648.h /usr/include/stdio.h
close.o: close.c hp2648.h /usr/include/stdio.h
cont.o: cont.c hp2648.h /usr/include/stdio.h
dot.o: dot.c
erase.o: erase.c hp2648.h /usr/include/stdio.h
label.o: label.c hp2648.h /usr/include/stdio.h
line.o: line.c hp2648.h /usr/include/stdio.h
linemod.o: linemod.c hp2648.h /usr/include/stdio.h
move.o: move.c hp2648.h /usr/include/stdio.h
open.o: open.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
open.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h hp2648.h
open.o: /usr/include/stdio.h
point.o: point.c hp2648.h /usr/include/stdio.h
space.o: space.c hp2648.h /usr/include/stdio.h
subr.o: subr.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
subr.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h hp2648.h
subr.o: /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1

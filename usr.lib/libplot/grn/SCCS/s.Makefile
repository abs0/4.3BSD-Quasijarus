h25226
s 00043/00007/00011
d D 6.2 87/06/19 16:38:59 bostic 2 1
c new template
e
s 00018/00000/00000
d D 6.1 86/08/29 15:06:15 sklower 1 0
c date and time created 86/08/29 15:06:15 by sklower
e
u
U
t
T
I 1
#
D 2
# Copyright (c) 1980, 1986 Regents of the University of California.
E 2
I 2
# Copyright (c) 1987 Regents of the University of California.
E 2
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 2
#	%W% (Berkeley) %G%
E 2
I 2
#	%W%	(Berkeley)	%G%
E 2
#
CFLAGS=	-O
I 2
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
E 2
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o \
	line.o linemod.o move.o open.o point.o space.o subr.o

D 2
../libplotgrn:	${OBJS}
	ar cu ../libplotgrn ${OBJS}
E 2
I 2
all: ../libplotgrn
E 2

D 2
${OBJS}:	grnplot.h
E 2
I 2
../libplotgrn: ${OBJS}
	ar cu $@ ${OBJS}
E 2

D 2
clean:
	rm -f ${OBJS} errs a.out core
E 2
I 2
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

arc.o: arc.c grnplot.h /usr/include/stdio.h
box.o: box.c
circle.o: circle.c grnplot.h /usr/include/stdio.h
close.o: close.c grnplot.h /usr/include/stdio.h
cont.o: cont.c grnplot.h /usr/include/stdio.h
dot.o: dot.c
erase.o: erase.c grnplot.h /usr/include/stdio.h
label.o: label.c grnplot.h /usr/include/stdio.h
line.o: line.c grnplot.h /usr/include/stdio.h
linemod.o: linemod.c grnplot.h /usr/include/stdio.h
move.o: move.c grnplot.h /usr/include/stdio.h
open.o: open.c grnplot.h /usr/include/stdio.h
point.o: point.c grnplot.h /usr/include/stdio.h
space.o: space.c grnplot.h /usr/include/stdio.h
subr.o: subr.c grnplot.h /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 2
E 1

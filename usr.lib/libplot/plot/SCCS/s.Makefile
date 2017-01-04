h09969
s 00048/00005/00006
d D 4.3 87/06/19 16:40:21 bostic 3 2
c new template
e
s 00002/00002/00009
d D 4.2 83/07/09 23:43:41 sam 2 1
c name change
e
s 00011/00000/00000
d D 4.1 83/06/27 14:30:53 sam 1 0
c date and time created 83/06/27 14:30:53 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
#
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 3
CFLAGS=	-O
I 3
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linmod.c move.c open.c point.c putsi.c space.c
E 3
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o \
	line.o linmod.o move.o open.o point.o putsi.o space.o

D 2
../libplot.a:	${OBJS}
	ar cu ../libplot.a ${OBJS}
E 2
I 2
D 3
../libplot:	${OBJS}
	ar cu ../libplot ${OBJS}
E 3
I 3
all: ../libplot
E 3
E 2

D 3
clean:
	rm -f ${OBJS} errs a.out core
E 3
I 3
../libplot: ${OBJS}
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

arc.o: arc.c /usr/include/stdio.h
box.o: box.c
circle.o: circle.c /usr/include/stdio.h
close.o: close.c /usr/include/stdio.h
cont.o: cont.c /usr/include/stdio.h
dot.o: dot.c /usr/include/stdio.h
erase.o: erase.c /usr/include/stdio.h
label.o: label.c /usr/include/stdio.h
line.o: line.c /usr/include/stdio.h
linmod.o: linmod.c /usr/include/stdio.h
move.o: move.c /usr/include/stdio.h
open.o: open.c
point.o: point.c /usr/include/stdio.h
putsi.o: putsi.c /usr/include/stdio.h
space.o: space.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 1

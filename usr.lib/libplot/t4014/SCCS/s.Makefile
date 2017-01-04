h16891
s 00047/00005/00006
d D 4.6 87/06/19 16:41:05 bostic 6 5
c new template
e
s 00001/00001/00010
d D 4.5 85/01/02 20:01:47 jak 5 4
c use lorder so ld needs only single scan of library.
e
s 00002/00002/00009
d D 4.4 83/09/21 18:53:52 sam 4 3
c wrong library name
e
s 00002/00002/00009
d D 4.3 83/07/09 23:44:45 sam 3 2
c name change
e
s 00001/00001/00010
d D 4.2 83/06/27 14:20:26 sam 2 1
c different name 
e
s 00011/00000/00000
d D 4.1 83/06/27 14:19:29 sam 1 0
c date and time created 83/06/27 14:19:29 by sam
e
u
U
t
T
I 1
D 6
#	%M%	%I%	%E%
E 6
#
I 6
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 6
CFLAGS=	-O
I 6
LIBC=	/lib/libc.a
SRCS=	arc.c box.c circle.c close.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c subr.c
E 6
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
D 2
	line.o linmod.o move.o open.o point.o space.o subr.o
E 2
I 2
	line.o linemod.o move.o open.o point.o space.o subr.o
E 2

D 3
../libt4014.a:	${OBJS}
	ar cu ../libt4014.a ${OBJS}
E 3
I 3
D 4
../libt4014:	${OBJS}
	ar cu ../libt4014 ${OBJS}
E 4
I 4
D 6
../lib4014:	${OBJS}
D 5
	ar cu ../lib4014 ${OBJS}
E 5
I 5
	ar cu ../lib4014 `lorder ${OBJS} | tsort`
E 6
I 6
all: ../lib4014
E 6
E 5
E 4
E 3

D 6
clean:
	rm -f ${OBJS} errs a.out core
E 6
I 6
../lib4014: ${OBJS}
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
E 6
E 1

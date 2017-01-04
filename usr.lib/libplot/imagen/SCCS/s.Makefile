h34067
s 00044/00013/00014
d D 5.5 87/06/19 16:39:52 bostic 5 4
c new template
e
s 00008/00002/00019
d D 5.4 85/09/21 16:21:34 sam 4 3
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00003/00003/00018
d D 5.3 85/09/21 15:18:06 sam 3 2
c move archive name
e
s 00002/00002/00019
d D 5.2 85/09/21 15:14:20 sam 2 1
c nothing interesting
e
s 00021/00000/00000
d D 5.1 85/09/21 15:05:43 sam 1 0
c date and time created 85/09/21 15:05:43 by sam
e
u
U
t
T
I 1
#
D 2
# Copyright (c) 1980 Regents of the University of California.
E 2
I 2
D 5
# Copyright (c) 1985 Regents of the University of California.
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
E 5
E 2
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 5
#	%W% (Berkeley) %G%
E 5
I 5
#	%W%	(Berkeley)	%G%
E 5
#
D 5
CFLAGS=	-O
E 5
I 5
# DEFRES == default printer resolution dpi
CFLAGS=	-O -DDEFRES=240
LIBC=	/lib/libc.a
SRCS=	arc.c box.c charset.c circle.c close.c cont.c dot.c \
	erase.c label.c line.c linemod.c move.c open.c point.c \
	scale.c space.c
E 5
D 4
OBJS=	arc.o box.o circle.o close.o cont.o dot.o erase.o label.o line.o \
	linemod.o move.o open.o point.o scale.o space.o
E 4
I 4
OBJS=	arc.o box.o charset.o circle.o close.o cont.o dot.o \
	erase.o label.o line.o linemod.o move.o open.o point.o \
	scale.o space.o
D 5
# default printer resolution dpi
DEFRES=	240
E 5
E 4

D 3
all:	../libimagen
E 3
I 3
D 5
all:	../libplotimagen
E 5
I 5
all: ../libplotimagen
E 5
E 3

D 3
../libimagen: ${OBJS}
	ar cr ../libimagen ${OBJS}
E 3
I 3
../libplotimagen: ${OBJS}
D 5
	ar cr ../libplotimagen ${OBJS}
E 5
I 5
	ar cr $@ ${OBJS}
E 5
E 3

D 5
close.o erase.o label.o line.o open.o: imp.h imPcodes.h
cont.o move.o:	imp.h
E 5
I 5
clean: FRC
	rm -f ${OBJS} core
E 5
I 4

D 5
space.o: space.c Makefile
	${CC} -c ${CFLAGS} -DDEFRES=${DEFRES} space.c
E 5
I 5
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 5
E 4

D 5
clean:
D 2
	rm -f *.o
E 2
I 2
	rm -f ${OBJS} a.out core errs
E 5
I 5
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
charset.o: charset.c imp.h /usr/include/stdio.h
circle.o: circle.c
close.o: close.c imp.h /usr/include/stdio.h imPcodes.h
cont.o: cont.c /usr/include/stdio.h imp.h /usr/include/stdio.h
dot.o: dot.c
erase.o: erase.c imPcodes.h imp.h /usr/include/stdio.h
label.o: label.c imPcodes.h imp.h /usr/include/stdio.h
line.o: line.c imp.h /usr/include/stdio.h imPcodes.h
linemod.o: linemod.c imp.h /usr/include/stdio.h
move.o: move.c imp.h /usr/include/stdio.h
open.o: open.c imPcodes.h imp.h /usr/include/stdio.h
point.o: point.c
scale.o: scale.c
space.o: space.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 2
E 1

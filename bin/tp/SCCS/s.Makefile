h45994
s 00040/00012/00006
d D 4.3 87/06/02 23:41:34 bostic 3 2
c new template
e
s 00002/00000/00016
d D 4.2 87/05/31 20:34:10 bostic 2 1
c added depend label
e
s 00016/00000/00000
d D 4.1 82/12/18 15:14:10 sam 1 0
c date and time created 82/12/18 15:14:10 by sam
e
u
U
t
T
I 1
D 3
#	%W%	%G%
E 3
I 3
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	tp0.c tp1.c tp2.c tp3.c
OBJS=	tp0.o tp1.o tp2.o tp3.o
E 3

D 3
CFLAGS=-O
h = tp.h tp_defs.h
o  = tp0.o tp1.o tp2.o tp3.o
E 3
I 3
all: tp
E 3

D 3
tp :	$o
	$(CC) -o tp $o
E 3
I 3
tp:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 3

D 3
$o :	$h
E 3
I 3
clean: FRC
	rm -f ${OBJS} core tp
E 3

D 3
install : tp
	install -s tp ${DESTDIR}/bin
E 3
I 3
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

D 3
clean : 
	rm -f *.o
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 tp ${DESTDIR}/bin/tp
E 3
I 2

D 3
depend:
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

tp0.o: tp0.c tp.h tp_defs.h
tp1.o: tp1.c tp.h
tp2.o: tp2.c tp.h /usr/include/stdio.h /usr/include/sys/param.h
tp2.o: /usr/include/sys/types.h /usr/include/signal.h
tp2.o: /usr/include/machine/machparam.h /usr/include/sys/stat.h
tp2.o: /usr/include/sys/dir.h
tp3.o: tp3.c tp.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1

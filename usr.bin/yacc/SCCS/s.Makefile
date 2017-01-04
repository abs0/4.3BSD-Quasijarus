h06022
s 00037/00018/00007
d D 4.4 87/06/19 00:03:20 bostic 4 3
c new template
e
s 00002/00000/00023
d D 4.3 87/05/31 21:34:21 bostic 3 2
c added depend label
e
s 00001/00000/00022
d D 4.2 83/02/11 16:09:42 rrh 2 1
c define DESTDIR
e
s 00022/00000/00000
d D 4.1 83/02/11 15:24:51 rrh 1 0
c date and time created 83/02/11 15:24:51 by rrh
e
u
U
t
T
I 1
#
D 4
#	%W%	(Berkeley)	%E%
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 4
#
I 2
D 4
DESTDIR=
E 2
CFLAGS=-O -DWORD32
SRCS = Makefile dextern files yaccpar \
	y1.c y2.c y3.c y4.c \
	yaccdiffs yaccnews
E 4
I 4
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O -DWORD32
LIBC=	/lib/libc.a
SRCS=	y1.c y2.c y3.c y4.c
OBJS=	y1.o y2.o y3.o y4.o
E 4

all: yacc

D 4
yacc: y1.o y2.o y3.o y4.o
	$(CC) -o yacc y?.o 
y1.o y2.o y3.o y4.o: dextern files
install:
	install -s yacc $(DESTDIR)/usr/bin
	install -c yaccpar $(DESTDIR)/usr/lib
clean :
	-rm -f *.o yacc
E 4
I 4
yacc: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 4

D 4
srcs: $(SRCS)
$(SRCS):
	sccs get $@
E 4
I 4
clean: FRC
	rm -f ${OBJS} core yacc
E 4
I 3

D 4
depend:
E 4
I 4
depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 yacc ${DESTDIR}/usr/bin/yacc
	install -c -o bin -g bin -m 755 yaccpar ${DESTDIR}/usr/lib/yaccpar

lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

y1.o: y1.c dextern /usr/include/stdio.h /usr/include/ctype.h files
y2.o: y2.c dextern /usr/include/stdio.h /usr/include/ctype.h files
y3.o: y3.c dextern /usr/include/stdio.h /usr/include/ctype.h files
y4.o: y4.c dextern /usr/include/stdio.h /usr/include/ctype.h files

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 3
E 1

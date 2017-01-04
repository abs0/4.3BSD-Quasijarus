h35086
s 00040/00023/00009
d D 4.3 87/06/18 18:06:36 bostic 3 2
c new template
e
s 00002/00000/00030
d D 4.2 87/05/31 21:30:10 bostic 2 1
c added depend label
e
s 00030/00000/00000
d D 4.1 83/08/11 20:50:28 sam 1 0
c date and time created 83/08/11 20:50:28 by sam
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
D 3
CFLAGS = -O
E 3
I 3
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	lmain.c parser.c sub1.c sub2.c header.c
OBJS=	lmain.o parser.o sub1.o sub2.o header.o
E 3

all: lex

D 3
lex: lmain.o y.tab.o sub1.o sub2.o header.o
	cc lmain.o y.tab.o sub1.o sub2.o header.o -o lex
E 3
I 3
lex: ${OBJS} ${LIBC}
	${CC} ${CFLAGS} ${OBJS} -o $@
E 3

D 3
smallex:
	cc -DSMALL -O lmain.c y.tab.c sub1.c sub2.c header.c -o smallex
E 3
I 3
smallex: ${SRCS} ${LIBC} FRC
	${CC} -DSMALL ${CFLAGS} ${SRCS} -o $@
E 3

D 3
y.tab.c: parser.y
	yacc parser.y
lmain.o:lmain.c ldefs.c once.c
	cc -c -O lmain.c
sub1.o: sub1.c ldefs.c
	cc -c -O sub1.c
sub2.o: sub2.c ldefs.c
	cc -c -O sub2.c
header.o: header.c ldefs.c
	cc -c -O header.c
E 3
I 3
clean: FRC
	rm -f ${OBJS} core lex smallex parser.c
E 3

D 3
install: all
	install -s lex $(DESTDIR)/usr/bin
	install -c ncform $(DESTDIR)/usr/lib/lex
	install -c nrform $(DESTDIR)/usr/lib/lex
E 3
I 3
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}
E 3

D 3
clean:
	rm -f *.o lex y.tab.c
E 3
I 3
install: FRC
	install -s -o bin -g bin -m 755 lex ${DESTDIR}/usr/bin/lex
	install -c -o bin -g bin -m 755 ncform ${DESTDIR}/usr/lib/lex/ncform
	install -c -o bin -g bin -m 755 nrform ${DESTDIR}/usr/lib/lex/nrform
E 3
I 2

D 3
depend:
E 3
I 3
lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

lmain.o: lmain.c ldefs.c /usr/include/stdio.h once.c
parser.o: parser.c ldefs.c /usr/include/stdio.h
sub1.o: sub1.c ldefs.c /usr/include/stdio.h
sub2.o: sub2.c ldefs.c /usr/include/stdio.h
header.o: header.c ldefs.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1

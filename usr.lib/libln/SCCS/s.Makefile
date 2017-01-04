h12123
s 00034/00013/00013
d D 4.3 87/06/19 11:22:22 bostic 3 2
c new template
e
s 00012/00007/00014
d D 4.2 85/05/30 22:53:28 sam 2 1
c add tags; a bit of cleanup
e
s 00021/00000/00000
d D 4.1 82/12/25 10:41:44 sam 1 0
c date and time created 82/12/25 10:41:44 by sam
e
u
U
t
T
I 1
D 3
#	%W%	%G%
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
E 3
I 2
SRCS=	allprint.c main.c reject.c yyless.c yywrap.c
OBJS=	allprint.o main.o reject.o yyless.o yywrap.o
D 3
TAGSFILE=tags
E 3
E 2

all: libln.a

D 2
libln.a:
	cc -c -O allprint.c main.c reject.c yyless.c
	cc -c -O yywrap.c
	rm -f libln.a
	ar rvc libln.a allprint.o main.o reject.o yyless.o yywrap.o
	rm allprint.o main.o reject.o yyless.o yywrap.o
E 2
I 2
libln.a: ${OBJS}
D 3
	ar rc libln.a ${OBJS}
E 3
I 3
	ar rc $@ ${OBJS}
E 3
E 2

D 3
install: all
	install libln.a ${DESTDIR}/usr/lib
E 3
I 3
clean: FRC
	rm -f ${OBJS} core libln.a

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 libln.a ${DESTDIR}/usr/lib/libln.a
E 3
	rm -f ${DESTDIR}/usr/lib/libl.a
	ln ${DESTDIR}/usr/lib/libln.a ${DESTDIR}/usr/lib/libl.a
	ranlib ${DESTDIR}/usr/lib/libln.a

I 2
D 3
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 3
I 3
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 3

E 2
D 3
clean:
D 2
	rm -f *.o libln.a
E 2
I 2
	rm -f ${OBJS} libln.a tags
E 3
I 3
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

allprint.o: allprint.c /usr/include/stdio.h
main.o: main.c /usr/include/stdio.h
reject.o: reject.c /usr/include/stdio.h
yyless.o: yyless.c
yywrap.o: yywrap.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 3
E 2
E 1

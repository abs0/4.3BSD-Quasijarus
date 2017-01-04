h33172
s 00001/00001/00077
d D 5.3 2012/02/16 05:13:10 msokolov 3 2
c need to save the binary on install, needed in ../eqnchar/Makefile
e
s 00006/00005/00072
d D 5.2 2012/02/16 04:03:20 msokolov 2 1
c it's about time for pseqn to become /usr/ucb/eqn
e
s 00077/00000/00000
d D 5.1 04/09/15 04:23:32 msokolov 1 0
c date and time created 04/09/15 04:23:32 by msokolov
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 2
#	%W%	(Berkeley)	%G%
E 2
I 2
#	%W%	(Berkeley)	%E%
E 2
#
COMMON=	../common_source
CFLAGS=	-O -DPS -I. -I${COMMON}
YFLAGS=	-d
VPATH=	${COMMON}
LIBC=	/lib/libc.a
SRCS=	e.c diacrit.c eqnbox.c font.c fromto.c funny.c glob.c integral.c \
	io.c lex.c lookup.c mark.c matrix.c move.c over.c paren.c pile.c \
	shift.c size.c sqrt.c text.c
OBJS=	e.o diacrit.o eqnbox.o font.o fromto.o funny.o glob.o integral.o \
	io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o \
	shift.o size.o sqrt.o text.o

D 2
all: pseqn
E 2
I 2
all: eqn
E 2

D 2
pseqn: ${OBJS} ${LIBC}
E 2
I 2
eqn: ${OBJS} ${LIBC}
E 2
	${CC} -o $@ ${CFLAGS} ${OBJS}

e.c: ${COMMON}/e.y
	${YACC} ${YFLAGS} ${COMMON}/e.y
	mv y.tab.h e.def
	mv y.tab.c e.c

clean: FRC
D 2
	rm -f ${OBJS} core e.def e.c pseqn
E 2
I 2
	rm -f ${OBJS} core e.def e.c eqn
E 2

depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
D 2
	install -s -o bin -g bin -m 755 pseqn ${DESTDIR}/usr/ucb/pseqn
E 2
I 2
D 3
	install -s -o bin -g bin -m 755 eqn ${DESTDIR}/usr/ucb/eqn
E 3
I 3
	install -c -s -o bin -g bin -m 755 eqn ${DESTDIR}/usr/ucb/eqn
E 3
	cd ${DESTDIR}/usr/ucb; rm -f pseqn; ln eqn pseqn
E 2

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

e.o: e.c ../common_source/e.h /usr/include/stdio.h
diacrit.o: ../common_source/diacrit.c ../common_source/e.h /usr/include/stdio.h
diacrit.o: e.def
eqnbox.o: ../common_source/eqnbox.c ../common_source/e.h /usr/include/stdio.h
font.o: ../common_source/font.c ../common_source/e.h /usr/include/stdio.h
fromto.o: ../common_source/fromto.c ../common_source/e.h /usr/include/stdio.h
funny.o: ../common_source/funny.c ../common_source/e.h /usr/include/stdio.h
funny.o: e.def
glob.o: ../common_source/glob.c ../common_source/e.h /usr/include/stdio.h
integral.o: ../common_source/integral.c ../common_source/e.h
integral.o: /usr/include/stdio.h e.def
io.o: ../common_source/io.c ../common_source/e.h /usr/include/stdio.h
lex.o: ../common_source/lex.c ../common_source/e.h /usr/include/stdio.h e.def
lookup.o: ../common_source/lookup.c ../common_source/e.h /usr/include/stdio.h
lookup.o: e.def
mark.o: ../common_source/mark.c ../common_source/e.h /usr/include/stdio.h
matrix.o: ../common_source/matrix.c ../common_source/e.h /usr/include/stdio.h
move.o: ../common_source/move.c ../common_source/e.h /usr/include/stdio.h e.def
over.o: ../common_source/over.c ../common_source/e.h /usr/include/stdio.h
paren.o: ../common_source/paren.c ../common_source/e.h /usr/include/stdio.h
pile.o: ../common_source/pile.c ../common_source/e.h /usr/include/stdio.h
shift.o: ../common_source/shift.c ../common_source/e.h /usr/include/stdio.h
shift.o: e.def
size.o: ../common_source/size.c ../common_source/e.h /usr/include/stdio.h
sqrt.o: ../common_source/sqrt.c ../common_source/e.h /usr/include/stdio.h
text.o: ../common_source/text.c ../common_source/e.h /usr/include/stdio.h e.def

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 1

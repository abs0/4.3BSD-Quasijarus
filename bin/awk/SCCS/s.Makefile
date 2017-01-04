h58897
s 00001/00001/00070
d D 4.8 88/06/09 18:54:34 bostic 9 8
c tokenscript has this file called temp
e
s 00003/00002/00068
d D 4.7 87/11/30 21:18:20 bostic 8 6
c fix clean: label
e
s 00001/00001/00069
d R 4.7 87/11/30 21:10:13 bostic 7 6
c remove awk.g.o, too
e
s 00002/00001/00068
d D 4.6 87/06/22 10:13:43 bostic 6 5
c make proc ./proc so path doesn't require .
e
s 00051/00038/00018
d D 4.5 87/06/02 23:46:41 bostic 5 4
c new template
e
s 00002/00000/00054
d D 4.4 87/05/31 20:32:03 bostic 4 3
c added depend label
e
s 00001/00001/00053
d D 4.3 86/05/15 07:17:55 lepreau 3 2
c make sure get ex; temp may not be writable wither
e
s 00004/00002/00050
d D 4.2 83/07/08 23:13:00 sam 2 1
c wrong path name
e
s 00052/00000/00000
d D 4.1 82/05/07 19:24:31 mckusick 1 0
c date and time created 82/05/07 19:24:31 by mckusick
e
u
U
t
T
I 1
D 5
#	%M%	%I%	%E%
E 5
#
D 5
CFLAGS=-O
YFLAGS=-d
FILES=awk.lx.o b.o main.o token.o tran.o lib.o run.o parse.o proctab.o freeze.o
SOURCE=awk.def awk.g.y awk.lx.l b.c lib.c main.c parse.c \
	proc.c freeze.c\
	run.c token.c tran.c
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
YFLAGS=	-d
OBJS=	awk.lx.o b.o main.o token.o tran.o lib.o run.o parse.o proctab.o \
	freeze.o
SRCS=	awk.lx.c b.c lib.c main.c parse.c proctab.c freeze.c run.c \
	token.c tran.c
E 5

D 5
awk:	$(FILES) awk.g.o
	cc $(CFLAGS) awk.g.o  $(FILES)  -lm -o awk
E 5
I 5
all: awk
E 5

D 5
y.tab.h:	awk.g.o
E 5
I 5
awk: ${OBJS} awk.g.o ${LIBC}
	${CC} ${CFLAGS} awk.g.o  ${OBJS} -lm -o $@
E 5

D 5
awk.h:	y.tab.h
E 5
I 5
y.tab.h: awk.g.o

awk.h: y.tab.h
E 5
	-cmp -s y.tab.h awk.h || cp y.tab.h awk.h

D 5
$(FILES):	awk.h awk.def
E 5
I 5
token.c: awk.h
	ex - < tokenscript
E 5

D 5
token.c:	awk.h
D 3
	e - <tokenscript
E 3
I 3
	ex - <tokenscript
E 5
I 5
profile: awk.g.o ${OBJS} mon.o
	${CC} -p -i awk.g.o ${OBJS} mon.o -lm
E 5
E 3

D 5
get:
D 2
	for i in $(SOURCE) makefile tokenscript README; do cp /usr/src/cmd/awk/$$i .; done
E 2
I 2
	for i in $(SOURCE) Makefile tokenscript README; do \
		cp /usr/src/bin/awk/$$i .;
	done
E 5
I 5
proctab.c: proc
D 6
	proc > proctab.c
E 6
I 6
	./proc > proctab.c
E 6
E 5
E 2

D 5
install:
	install -s awk ${DESTDIR}/bin
E 5
I 5
D 8
proc:	awk.h proc.o token.o
E 8
I 8
proc: awk.h proc.o token.o
E 8
	${CC} -o $@ proc.o token.o
E 5

D 5
profile:	awk.g.o $(FILES) mon.o
	cc -p -i awk.g.o $(FILES) mon.o -lm
E 5
I 5
clean: FRC
D 8
	rm -f ${OBJS} core awk awk.h proc proctab.c yacc*
E 8
I 8
#	use *.o, not ${OBJS}
D 9
	rm -f *.o core awk awk.h awk.lx.c y.tab.h proc proctab.c yacc*
E 9
I 9
	rm -f *.o core awk awk.h awk.lx.c y.tab.h proc proctab.c yacc* temp
E 9
E 8
E 5

D 5
find:
	egrep -n "$(PAT)" *.[ylhc] awk.def
E 5
I 5
depend: y.tab.h ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}
E 5

I 4
D 5
depend:
E 5
I 5
install:
	install -s -o bin -g bin -m 755 awk ${DESTDIR}/bin/awk
E 5

E 4
D 5
list:
D 2
	-pr $(SOURCE) makefile tokenscript README EXPLAIN
E 2
I 2
	-pr $(SOURCE) Makefile tokenscript README EXPLAIN
E 5
I 5
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 5
E 2

D 5
lint:
	lint -spu b.c main.c token.c tran.c run.c lib.c parse.c -lm |\
		egrep -v '^(error|free|malloc)'
E 5
I 5
tags: proctab.c FRC
	ctags ${SRCS}
E 5

D 5
proctab.c:	proc
	proc >proctab.c
E 5
I 5
FRC:
E 5

D 5
proc:	awk.h proc.o token.o
	cc -o proc proc.o token.o
E 5
I 5
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 5

I 6
awk.lx.o: awk.lx.c /usr/include/stdio.h awk.h awk.def
E 6
D 5
clean:
	-rm -f *.o t.* *temp* *.out *junk* y.tab.* awk.h proc proctab.c awk yacc*
E 5
I 5
b.o: b.c awk.def /usr/include/stdio.h awk.h
lib.o: lib.c /usr/include/stdio.h awk.def awk.h /usr/include/ctype.h
main.o: main.c /usr/include/stdio.h /usr/include/ctype.h awk.def awk.h
parse.o: parse.c awk.def awk.h /usr/include/stdio.h
proctab.o: proctab.c awk.def
freeze.o: freeze.c /usr/include/stdio.h
run.o: run.c awk.def /usr/include/math.h awk.h /usr/include/stdio.h
run.o: /usr/include/fcntl.h
token.o: token.c awk.h
tran.o: tran.c /usr/include/stdio.h awk.def awk.h
E 5

D 5
diffs:
	-for i in $(SOURCE); do echo $$i:; diff $$i /usr/src/cmd/awk | ind; done
E 5
I 5
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1

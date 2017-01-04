h45657
s 00024/00000/00000
d D 5.1 04/09/10 23:19:11 msokolov 1 0
c date and time created 04/09/10 23:19:11 by msokolov
e
u
U
t
T
I 1
# Makefile for catemu
#
#	%W%	(Berkeley)	%G%

CFLAGS=	-O
SRCS=	catemu.c
PROGS=	catemu
PSFILES=CatemuEncoding.ps CatemuProcset.ps SpecialFont.ps

all:	${PROGS}

catemu:	catemu.c
	${CC} ${CFLAGS} -o $@ $@.c

install:
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb
	-mkdir ${DESTDIR}/usr/lib/catemu
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/usr/lib/catemu

depend:
# no includes, hence no dependencies

clean:
	rm -f *.o ${PROGS} a.out core errs
E 1

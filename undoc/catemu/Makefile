# Makefile for catemu
#
#	@(#)Makefile	5.1	(Berkeley)	9/10/04

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

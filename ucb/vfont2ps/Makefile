# Makefile for vfont2ps
#
#	@(#)Makefile	5.1	(Berkeley)	9/14/04

CFLAGS=	-O
SRCS=	vfont2ps.c
PROGS=	vfont2ps

all:	${PROGS}

vfont2ps:	vfont2ps.c
	${CC} ${CFLAGS} -o $@ $@.c

install:
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb
	install -c -o bin -g bin -m 444 buildchar.ps \
		${DESTDIR}/usr/lib/vfont2ps.buildchar

depend:
# no includes, hence no dependencies

clean:
	rm -f *.o ${PROGS} a.out core errs

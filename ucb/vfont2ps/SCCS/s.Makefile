h40125
s 00023/00000/00000
d D 5.1 04/09/14 09:44:38 msokolov 1 0
c date and time created 04/09/14 09:44:38 by msokolov
e
u
U
t
T
I 1
# Makefile for vfont2ps
#
#	%W%	(Berkeley)	%G%

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
E 1

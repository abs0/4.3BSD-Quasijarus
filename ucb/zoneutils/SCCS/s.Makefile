h49548
s 00002/00000/00021
d D 1.3 2011/12/24 05:44:48 msokolov 3 2
c do-nothing depend: target added
e
s 00006/00001/00015
d D 1.2 11/07/12 19:12:33 msokolov 2 1
c this Makefile looks production-ready
e
s 00016/00000/00000
d D 1.1 11/07/12 00:46:37 msokolov 1 0
c zonecomp written
e
u
U
t
T
I 1
# Makefile for MSDNS zone utilities
#
#	%W% (IFCTF) %E%

CFLAGS=	-O
D 2
PROGS=	zonecomp
E 2
I 2
PROGS=	zonecomp zonedump zonexfer
E 2

all:	${PROGS}

${PROGS}:
	${CC} ${CFLAGS} -o $@ $@.c

zonecomp:	zonecomp.c
I 2
zonedump:	zonedump.c
zonexfer:	zonexfer.c

install:
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb
E 2

I 3
depend:

E 3
clean:
	rm -f *.o ${PROGS} *.out core errs
E 1

# Makefile for MSDNS zone utilities
#
#	@(#)Makefile	1.3 (IFCTF) 2011/12/24

CFLAGS=	-O
PROGS=	zonecomp zonedump zonexfer

all:	${PROGS}

${PROGS}:
	${CC} ${CFLAGS} -o $@ $@.c

zonecomp:	zonecomp.c
zonedump:	zonedump.c
zonexfer:	zonexfer.c

install:
	install -s -o bin -g bin -m 755 ${PROGS} ${DESTDIR}/usr/ucb

depend:

clean:
	rm -f *.o ${PROGS} *.out core errs

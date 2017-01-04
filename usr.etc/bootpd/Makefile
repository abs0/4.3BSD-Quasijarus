#
# bootpd   - BOOTP server daemon
#
# @(#)Makefile	5.2	(Berkeley)	05/04/17

CFLAGS=	-O -DVEND_CMU -DPRIVATE=static
OBJS=	bootpd.o readfile.o hash.o version.o

all: bootpd

bootpd:	${OBJS}
	${CC} ${CFLAGS} -o bootpd ${OBJS}

bootpd.o: bootpd.c bootpd.h bootp.h
readfile.o: readfile.c bootpd.h bootp.h
hash.o: hash.c hash.h

install:
	${INSTALL} -s -o bin -g bin -m 755 bootpd ${DESTDIR}/usr/etc

clean:
	rm -f core bootpd *.BAK *.CKP *~ .emacs* *.o a.out errs

depend:

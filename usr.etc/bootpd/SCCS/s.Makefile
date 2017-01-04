h55584
s 00001/00001/00023
d D 5.2 05/04/17 04:53:54 msokolov 2 1
c don't need -DSYSLOG any more, drop -DDEBUG too
e
s 00024/00000/00000
d D 5.1 05/04/17 04:17:05 msokolov 1 0
c bootpd 2.0 imported into 4.3BSD-Quasijarus
e
u
U
t
T
I 1
#
# bootpd   - BOOTP server daemon
#
# %W%	(Berkeley)	%E%

D 2
CFLAGS=	-O -DSYSLOG -DDEBUG -DVEND_CMU -DPRIVATE=static
E 2
I 2
CFLAGS=	-O -DVEND_CMU -DPRIVATE=static
E 2
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
E 1

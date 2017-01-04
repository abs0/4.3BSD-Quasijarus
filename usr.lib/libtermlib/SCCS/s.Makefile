h58144
s 00006/00000/00059
d D 5.3 87/09/11 16:13:18 jak 5 4
c added test target to compile test programs
e
s 00036/00026/00023
d D 5.2 87/06/19 16:28:10 bostic 4 3
c new template
e
s 00006/00001/00043
d D 5.1 85/06/05 11:32:41 dist 3 2
c Add copyright
e
s 00016/00007/00028
d D 4.2 85/05/30 23:05:42 sam 2 1
c add tags
e
s 00035/00000/00000
d D 4.1 83/06/27 13:57:07 sam 1 0
c date and time created 83/06/27 13:57:07 by sam
e
u
U
t
T
I 1
D 3
#	%M%	%I%	%E%
E 3
I 3
#
D 4
# Copyright (c) 1980 Regents of the University of California.
E 4
I 4
# Copyright (c) 1987 Regents of the University of California.
E 4
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 4
#	%W% (Berkeley) %G%
E 4
I 4
#	%W%	(Berkeley)	%G%
E 4
E 3
#
CFLAGS=	-O -DCM_N -DCM_GT -DCM_B -DCM_D
D 4
LD = ld
E 4
I 4
LIBC=	/lib/libc.a
E 4
I 2
SRCS=	termcap.c tgoto.c tputs.c
OBJS=	termcap.o tgoto.o tputs.o
D 4
TAGSFILE=tags
E 4
E 2

.c.o:
D 4
	$(CC) $(CFLAGS) -c -p $*.c
	$(LD) $(LDFLAGS) -x -r -o profiled/$*.o $*.o
	$(CC) $(CFLAGS) -c $*.c
	$(LD) $(LDFLAGS) -X -r $*.o
E 4
I 4
	${CC} ${CFLAGS} -c -p $*.c
	ld -x -r -o profiled/$*.o $*.o
	${CC} ${CFLAGS} -c $*.c
	ld -X -r $*.o
E 4
	mv a.out $*.o

I 4
all: termcap.a termcap_p.a

E 4
D 2
termcap.a termcap_p.a: termcap.o tgoto.o tputs.o
	ar cr termcap.a termcap.o tgoto.o tputs.o
	cd profiled; ar cr ../termcap_p.a termcap.o tgoto.o tputs.o
E 2
I 2
termcap.a termcap_p.a: ${OBJS}
	ar cr termcap.a ${OBJS}
	cd profiled; ar cr ../termcap_p.a ${OBJS}
E 2

I 5
test:
	ranlib termcap.a
	${CC} ${CFLAGS} -o tc1 tc1.c termcap.a
	${CC} ${CFLAGS} -o tc2 tc2.c termcap.a
	${CC} ${CFLAGS} -o tc3 tc3.c termcap.a

E 5
D 2
clean:
	-rm -f *.o profiled/*.o
	-rm -f termcap.a termcap_p.a

E 2
D 4
install: termcap.a termcap_p.a
	install -c termcap.a ${DESTDIR}/usr/lib/libtermcap.a
	-rm -f ${DESTDIR}/usr/lib/libtermlib.a
E 4
I 4
clean: FRC
	rm -f ${OBJS} core profiled/*.o termcap.a termcap_p.a

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -o bin -g bin -m 644 termcap.a ${DESTDIR}/usr/lib/libtermcap.a
	rm -f ${DESTDIR}/usr/lib/libtermlib.a
E 4
	ln ${DESTDIR}/usr/lib/libtermcap.a ${DESTDIR}/usr/lib/libtermlib.a
	ranlib ${DESTDIR}/usr/lib/libtermcap.a
D 4
	install -c termcap_p.a ${DESTDIR}/usr/lib/libtermcap_p.a
	-rm -f ${DESTDIR}/usr/lib/libtermlib_p.a
E 4
I 4
	install -o bin -g bin -m 644 termcap_p.a ${DESTDIR}/usr/lib/libtermcap_p.a
	rm -f ${DESTDIR}/usr/lib/libtermlib_p.a
E 4
	ln ${DESTDIR}/usr/lib/libtermcap_p.a ${DESTDIR}/usr/lib/libtermlib_p.a
	ranlib ${DESTDIR}/usr/lib/libtermcap_p.a
I 2

D 4
tags:
	cwd=`pwd`; \
	for i in ${SRCS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done
E 4
I 4
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 4

D 4
clean:
	-rm -f *.o profiled/*.o
	-rm -f termcap.a termcap_p.a
E 4
I 4
tags: FRC
	ctags ${SRCS}
E 4
E 2

D 4
VGRIND=	csh /usr/ucb/vgrind
vgrind:
	cp /dev/null index
	${VGRIND} -h "Termcap library" termcap.c tputs.c tgoto.c
	${VGRIND} -h "Termcap library" -x index
E 4
I 4
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

termcap.o: termcap.c /usr/include/ctype.h
tgoto.o: tgoto.c
tputs.o: tputs.c /usr/include/sgtty.h /usr/include/sys/ioctl.h
tputs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tputs.o: /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 1

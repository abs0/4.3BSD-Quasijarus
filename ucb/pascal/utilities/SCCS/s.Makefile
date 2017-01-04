h29307
s 00003/00001/00099
d D 5.6 87/10/26 08:59:38 bostic 26 24
c fix depend label
e
s 00002/00000/00100
d R 5.6 87/10/26 07:48:02 bostic 25 24
c add depend label
e
s 00001/00001/00099
d D 5.5 85/12/12 22:08:58 donn 24 23
c pass DESTDIR to pc2 make
e
s 00003/00003/00097
d D 5.4 85/09/07 15:51:06 mckusick 23 22
c strip on install
e
s 00001/00000/00099
d D 5.3 85/06/26 14:31:19 bloom 22 21
c clean pc2 as well
e
s 00002/00001/00097
d D 5.2 85/06/25 18:45:21 bloom 21 20
c pc3 should be in /usr/lib
e
s 00007/00000/00091
d D 5.1 85/06/05 16:32:31 dist 20 19
c Add copyright
e
s 00004/00008/00087
d D 1.19 85/03/26 16:53:13 mckusick 19 18
c cleanups
e
s 00007/00012/00088
d D 1.18 84/08/18 18:19:29 mckusick 18 17
c pc2 now lives in a subdirectory
e
s 00001/00001/00099
d D 1.17 84/01/10 20:15:33 aoki 17 16
c use mode 644 instead of 744 on shared files
e
s 00034/00013/00066
d D 1.16 84/01/09 17:31:12 aoki 16 15
c install: use the 'install' program instead of 'cp', which halts
c if the destination is a symbolic link.
e
s 00005/00014/00074
d D 1.15 83/05/18 14:16:11 evan 15 14
c Removes entries related to the interperter.
e
s 00001/00001/00087
d D 1.14 83/04/18 14:15:20 rt 14 13
c more permission fix-ups
e
s 00003/00000/00085
d D 1.13 83/04/18 13:05:30 rt 13 12
c force things to be installed with useful file-protections.
e
s 00003/00002/00082
d D 1.12 83/04/08 14:53:26 mckusick 12 11
c do not "pipe" to the assembler, as some assemblers cannot handle pipe input
e
s 00029/00015/00055
d D 1.11 83/03/03 14:58:31 sam 11 10
c changes to reflect new source layout
e
s 00004/00004/00066
d D 1.10 83/01/22 00:54:44 mckusick 10 9
c new names, new header files, new .o files
e
s 00012/00004/00058
d D 1.9 83/01/07 13:21:26 mckusick 9 8
c delete duplicate entries in pcexterns.o
e
s 00003/00003/00059
d D 1.8 82/12/06 18:24:17 peter 8 7
c why were these things compiled with -d2?
e
s 00001/00001/00061
d D 1.7 82/10/18 23:35:09 mckusick 7 6
c do not worry about the return code from ``pc''
e
s 00003/00001/00059
d D 1.6 82/07/29 19:34:48 peter 6 5
c make pcexterns.o depend on changes to its awk script.
e
s 00002/00002/00058
d D 1.5 82/07/29 17:02:32 peter 5 4
c fix typo in path name
e
s 00013/00003/00047
d D 1.4 82/07/19 15:16:10 mckusick 4 3
c add pcexterns to resolve outside references in pc3
e
s 00004/00002/00046
d D 1.3 82/07/19 14:43:27 peter 3 2
c let's not strip the un-installed versions.
e
s 00001/00001/00047
d D 1.2 81/04/21 00:28:28 mckusic 2 1
c add pmerge
e
s 00048/00000/00000
d D 1.1 81/04/21 00:26:05 mckusick 1 0
c date and time created 81/04/21 00:26:05 by mckusick
e
u
U
t
T
I 20
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 20
I 1
SCCSID = %Z%%M% %I% %G%
INSTALL = ${DESTDIR}/usr/ucb
INSTALLIB = ${DESTDIR}/usr/lib
I 11
SRCDIR=	../src
I 16
PX_HEADER = px_header
E 16
E 11
D 15
PX_HEADER = px_header
E 15
I 4
NM = nm -go
RM = rm -f
E 4
D 11
CFLAGS = -O
E 11
I 11
CFLAGS = -O -I${SRCDIR}
E 11

D 4
all: pix px_header pc pc2 pc3 pmerge
E 4
I 4
D 15
all: pix px_header pc pc2 pc3 pmerge pcexterns.o
E 15
I 15
D 16
all: pc pc2 pc3 pmerge pcexterns.o
E 16
I 16
D 19
PROGS =	pc pix pmerge
D 18
FILES =	pc2 pc3 pcexterns.o how_pc how_pi how_pix how_pxp
E 18
I 18
FILES =	pc3 pcexterns.o how_pc how_pi how_pix how_pxp
E 19
I 19
D 21
PROGS =	pc pix pmerge pc3
E 21
I 21
PROGS =	pc pix pmerge
E 21
FILES =	pcexterns.o how_pc how_pi how_pix how_pxp
E 19
E 18
E 16
E 15
E 4

I 16
all: pix px_header pc pc2 pc3 pmerge pcexterns.o

E 16
install: all pxref.p
D 15
	dd if=px_header of=${INSTALLIB}/${PX_HEADER} conv=sync
	cp pc pix ${INSTALL}
E 15
I 15
D 16
	cp pc ${INSTALL}
E 15
D 4
	cp how* pc2 pc3 ${INSTALLIB}
E 4
I 4
	cp how* pc2 pc3 pcexterns.o ${INSTALLIB}
E 16
I 16
	dd if=px_header of=temp conv=sync
D 19
	install temp ${INSTALLIB}/${PX_HEADER}
E 19
I 19
	install -m 644 temp ${INSTALLIB}/${PX_HEADER}
E 19
D 23
	for i in ${PROGS}; do (install $$i ${INSTALL}/$$i ); done
E 23
I 23
	for i in ${PROGS}; do (install -s $$i ${INSTALL}/$$i ); done
E 23
D 19
	for i in ${FILES}; do (install $$i ${INSTALLIB}/$$i ); done
E 16
I 13
D 17
	cd ${INSTALLIB}; chmod 744 how* pcexterns.o ${PX_HEADER}
E 17
I 17
	cd ${INSTALLIB}; chmod 644 how* pcexterns.o ${PX_HEADER}
E 17
E 13
E 4
I 3
D 5
	strip ${INSTALLLIB}/pc2
	strip ${INSTALLLIB}/pc3
E 5
I 5
D 18
	strip ${INSTALLIB}/pc2
E 18
	strip ${INSTALLIB}/pc3
I 13
D 18
	cd ${INSTALLIB}; chmod 555 pc2 pc3
E 18
I 18
	cd ${INSTALLIB}; chmod 555 pc3
E 19
I 19
	for i in ${FILES}; do (install -m 644 -c $$i ${INSTALLIB}/$$i ); done
I 21
D 23
	install pc3 ${INSTALLIB}/pc3
E 23
I 23
	install -s pc3 ${INSTALLIB}/pc3
E 23
E 21
E 19
D 24
	cd pc2; make install
E 24
I 24
	cd pc2; make DESTDIR=${DESTDIR} install
E 24
E 18
E 13
E 5
E 3
D 2
	cp pmerge ${INSTALLIB}
E 2
I 2
D 16
	cp pmerge ${INSTALL}/pmerge
E 2
D 7
	pc -w pxref.p -o ${INSTALL}/pxref
E 7
I 7
	-pc -w pxref.p -o ${INSTALL}/pxref
I 13
D 14
	cd ${INSTALL} ; chmod 555 pmerge pxref
E 14
I 14
D 15
	cd ${INSTALL} ; chmod 555 pmerge pxref pc pix
E 15
I 15
	cd ${INSTALL} ; chmod 555 pmerge pxref pc 
E 16
I 16
	-pc -w pxref.p
D 23
	install a.out ${INSTALL}/pxref
E 23
I 23
	install -s a.out ${INSTALL}/pxref
E 23
D 19
	cd ${INSTALL} ; chmod 555 pmerge pxref pc pix
E 19
E 16
E 15
E 14
E 13
E 7

I 16
pix: pix.c config.o
	${CC} ${CFLAGS} -o pix pix.c config.o

E 16
D 10
pix: pix.c
	${CC} -O -o pix pix.c
E 10
I 10
D 15
pix: pix.c config.o
D 11
	${CC} -O -o pix pix.c config.o
E 11
I 11
	${CC} ${CFLAGS} -o pix pix.c config.o
E 11
E 10

E 15
pmerge: pmerge.c
D 11
	${CC} -O -o pmerge pmerge.c
E 11
I 11
	${CC} ${CFLAGS} -o pmerge pmerge.c
E 11

I 16
px_header: px_header.c ${SRCDIR}/objfmt.h config.o
	${CC} ${CFLAGS} -o px_header px_header.c config.o -N
	strip px_header

E 16
D 10
px_header: px_header.c objfmt.h
	${CC} -O -d2 -o px_header px_header.c -N
E 10
I 10
D 11
px_header: px_header.c objfmt.h config.o
	${CC} -O -o px_header px_header.c config.o -N
E 11
I 11
D 15
px_header: px_header.c ${SRCDIR}/objfmt.h config.o
	${CC} ${CFLAGS} -o px_header px_header.c config.o -N
E 11
E 10
	strip px_header

E 15
D 18
pc2: pc2.c
D 11
	${CC} pc2.c -lpc -o tmp
	${CC} -S pc2.c
E 11
I 11
	${CC} ${CFLAGS} pc2.c -lpc -o tmp
	${CC} ${CFLAGS} -S pc2.c
E 11
D 8
	./tmp pc2.s | as -d2 -o pc2.o
E 8
I 8
D 12
	./tmp pc2.s | as -o pc2.o
E 12
I 12
	./tmp pc2.s npc2.s
	as -o pc2.o npc2.s
E 12
E 8
D 3
	${CC} pc2.o -o pc2 -s
E 3
I 3
D 11
	${CC} pc2.o -o pc2
E 11
I 11
	${CC} ${CFLAGS} pc2.o -o pc2
E 11
E 3
D 12
	rm -f pc2.o pc2.s tmp
E 12
I 12
	rm -f pc2.o npc2.s pc2.s tmp
E 18
I 18
pc2: /tmp
	cd pc2; make
E 18
E 12

D 11
pc3: pc3.c pc3.h pstab.h
D 3
	${CC} -O -d2 pc3.c -o pc3 -s
E 3
I 3
D 8
	${CC} -O -d2 pc3.c -o pc3
E 8
I 8
	${CC} -O pc3.c -o pc3
E 11
I 11
pc3: pc3.c pc3.h ${SRCDIR}/pstab.h
	${CC} ${CFLAGS} pc3.c -o pc3
E 11
E 8
E 3

pxref: pxref.p
	pc -w pxref.p -o pxref

pc: pc.c
D 8
	${CC} -O -d2 -o pc pc.c
E 8
I 8
D 11
	${CC} -O -o pc pc.c
E 11
I 11
	${CC} ${CFLAGS} -o pc pc.c
E 11
E 8

I 4
D 6
pcexterns.o: /usr/lib/libpc.a /lib/libc.a /usr/lib/libm.a /usr/lib/libg.a
E 6
I 6
D 16
LIBRARIES = /usr/lib/libpc.a /lib/libc.a /usr/lib/libm.a /usr/lib/libg.a
E 16
I 16
LIBPC 	= /usr/lib/libpc.a
LIBC	= /lib/libc.a
LIBM	= /usr/lib/libm.a
LIBG	= /usr/lib/libg.a
D_LIBPC	= $(DESTDIR)$(LIBPC)
D_LIBC	= $(DESTDIR)$(LIBC)
D_LIBM	= $(DESTDIR)$(LIBM)
D_LIBG	= $(DESTDIR)$(LIBG)
LIBRARIES = $(D_LIBPC) $(D_LIBC) $(D_LIBM) $(D_LIBG)
E 16

pcexterns.o: pcexterns.awk ${LIBRARIES}
E 6
D 9
	${NM} /usr/lib/libpc.a | awk -f pcexterns.awk >pcexterns.s
	${NM} /lib/libc.a | awk -f pcexterns.awk >>pcexterns.s
	${NM} /usr/lib/libm.a | awk -f pcexterns.awk >>pcexterns.s
	${NM} /usr/lib/libg.a | awk -f pcexterns.awk >>pcexterns.s
E 9
I 9
D 16
	${NM} /usr/lib/libpc.a \
E 16
I 16
	( echo -n $(LIBPC):; ${NM} $(D_LIBPC) ) \
E 16
		| awk -f pcexterns.awk \
		| sort -t\" +1 -2 -u >pcexterns.s
D 16
	${NM} /lib/libc.a \
E 16
I 16
	( echo -n $(LIBC):; ${NM} $(D_LIBC) ) \
E 16
		| awk -f pcexterns.awk \
		| sort -t\" +1 -2 -u >>pcexterns.s
D 16
	${NM} /usr/lib/libm.a \
E 16
I 16
	( echo -n $(LIBM):; ${NM} $(D_LIBM) ) \
E 16
		| awk -f pcexterns.awk \
		| sort -t\" +1 -2 -u >>pcexterns.s
D 16
	${NM} /usr/lib/libg.a \
E 16
I 16
	( echo -n $(LIBG):; ${NM} $(D_LIBG) ) \
E 16
		| awk -f pcexterns.awk \
		| sort -t\" +1 -2 -u >>pcexterns.s
E 9
	as pcexterns.s -o pcexterns.o
	${RM} pcexterns.s

I 11
opcode.h: ${SRCDIR}/OPnames.h ${SRCDIR}/opc.c
	${RM} opcode.h
	cc ${SRCDIR}/opc.c -o opc
	opc >opcode.h
	${RM} opc

picture: ${SRCDIR}/OPnames.h ${SRCDIR}/pic.c
	${RM} picture
	cc ${SRCDIR}/pic.c -o pic
	pic >picture
	${RM} pic

E 11
E 4
clean:
D 4
	rm -f pix px_header pxref pmerge pc pc2 pc3
E 4
I 4
D 11
	${RM} pix px_header pxref pmerge pc pc2 pc3 pcexterns.s pcexterns.o
E 11
I 11
D 15
	${RM} pix px_header pxref pmerge pc pc2 pc3 \
E 15
I 15
D 16
	${RM} pxref pmerge pc pc2 pc3 \
E 16
I 16
D 18
	${RM} pix px_header pxref pmerge pc pc2 pc3 \
E 18
I 18
	${RM} pix px_header pxref pmerge pc pc3 \
E 18
E 16
E 15
	pcexterns.s *.o errs opc opc.c pic pic.c picture
I 22
	cd pc2; make clean
E 22
E 11
E 4

D 11
print:
	@pr READ_ME makefile
E 11
I 11
print: picture
D 26
	@pr READ_ME makefile picture
E 26
I 26
	@pr READ_ME Makefile picture
E 26
E 11
	@ls -l | pr
D 11
	@pr pix.c pmerge.c pxref.p pc.c pc2.c
E 11
I 11
D 15
	@pr pix.c pmerge.c pxref.p pc.c pc2.c pc3.h pc3.c
E 15
I 15
D 16
	@pr pmerge.c pxref.p pc.c pc2.c pc3.h pc3.c
E 16
I 16
D 18
	@pr pix.c pmerge.c pxref.p pc.c pc2.c pc3.h pc3.c
E 18
I 18
	@pr pix.c pmerge.c pxref.p pc.c pc3.h pc3.c
I 26

depend:
E 26
E 18
E 16
E 15
E 11
E 1

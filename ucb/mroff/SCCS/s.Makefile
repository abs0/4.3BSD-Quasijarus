h09527
s 00001/00001/00171
d D 5.20 2012/07/21 08:00:55 msokolov 20 19
c bdprocset.ps added
e
s 00013/00003/00159
d D 5.19 2012/07/15 03:18:27 msokolov 19 18
c troff: named char handling converted to LUT, Cyrillic support added
e
s 00001/00001/00161
d D 5.18 2012/03/06 04:19:57 msokolov 18 17
c clean chtabs.c and sortchtab
e
s 00011/00009/00151
d D 5.17 2012/03/06 04:14:05 msokolov 17 16
c new font model
e
s 00002/00002/00158
d D 5.16 2012/03/05 00:22:33 msokolov 16 15
c dependency on chardef.h
e
s 00007/00003/00153
d D 5.15 2012/03/04 05:38:30 msokolov 15 14
c troffchar utility added
e
s 00001/00001/00155
d D 5.14 2012/03/04 00:53:36 msokolov 14 13
c bad use of fgrep
e
s 00001/00000/00155
d D 5.13 2012/02/19 05:18:22 msokolov 13 12
c we are now officially troff!
e
s 00015/00005/00140
d D 5.12 2012/02/16 00:53:22 msokolov 12 11
c chtab sorting implemented
e
s 00003/00009/00142
d D 5.11 10/10/08 07:04:11 msokolov 11 10
c pstmerge and pstfinish have moved into finish+merge subdir
e
s 00007/00003/00144
d D 5.10 10/08/29 03:35:16 msokolov 10 9
c drawing operations added to pstroff
e
s 00013/00007/00134
d D 5.9 10/08/23 18:50:47 msokolov 9 8
c 5lig and pstfinish added
e
s 00006/00001/00135
d D 5.8 04/10/31 05:47:12 msokolov 8 7
c add troffemu subdirectory
e
s 00002/00007/00134
d D 5.7 04/10/30 03:45:09 msokolov 7 6
c Symbolextend.ps is gone, TroffProcset.ps is here
e
s 00005/00001/00136
d D 5.6 04/10/20 00:18:33 msokolov 6 5
c add pstmerge
e
s 00007/00001/00130
d D 5.5 04/09/16 08:32:18 msokolov 5 4
c create /usr/lib/pstroff if it doesn't already exist
c strip comments when installing Symbolextend.ps
e
s 00004/00001/00127
d D 5.4 04/09/14 23:04:03 msokolov 4 3
c cttab.c
e
s 00002/00002/00126
d D 5.3 04/09/09 18:49:04 msokolov 3 2
c install Symbolextend.ps
e
s 00006/00002/00122
d D 5.2 04/09/08 16:59:23 msokolov 2 1
c add preppsfont
e
s 00124/00000/00000
d D 5.1 04/09/08 16:41:52 msokolov 1 0
c first working version
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 12
#	%W%	(Berkeley)	%G%
E 12
I 12
#	%W%	(Berkeley)	%E%
E 12
#
CFLAGS=	-O -DVMUNIX
LIBC=	/lib/libc.a
I 10
LIBM=	/usr/lib/libm.a
E 10
SRCS=	ni.c nii.c n1.c n2.c n3.c n4.c n5.c n6.c t6.c n7.c n8.c n9.c n10.c \
D 2
	t10.c chtab.c hytab.c suftab.c
E 2
I 2
D 12
	t10.c chtab.c hytab.c suftab.c preppsfont.c
E 12
I 12
D 15
	t10.c chtab.c hytab.c suftab.c preppsfont.c sortchtab.c
E 15
I 15
	t10.c chtab.c hytab.c suftab.c preppsfont.c sortchtab.c troffchar.c
E 15
E 12
E 2
NOBJS=	ni.o nii.o n1.o n2.o n3.o n4.o n5.o n6.o n7.o n8.o n9.o n10.o \
D 12
	chtab.o hytab.o suftab.o
E 12
I 12
	chtabs.o hytab.o suftab.o
E 12
D 10
TOBJS=	ni_t.o nii_t.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o t10.o \
E 10
I 10
TOBJS=	ni_t.o nii_t.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o t10.o td.o \
E 10
D 4
	chtab.o hytab.o suftab.o
E 4
I 4
D 12
	chtab.o hytab.o suftab.o cttab.o
E 12
I 12
D 19
	chtabs.o hytab.o suftab.o cttab.o
E 19
I 19
	chlut.o hytab.o suftab.o cttab.o
E 19
E 12
E 4
D 2
PROGS=	nroff troff
E 2
I 2
D 6
PROGS=	nroff troff preppsfont
E 6
I 6
D 9
PROGS=	nroff troff preppsfont pstmerge
E 9
I 9
D 11
PROGS=	nroff troff preppsfont pstmerge pstfinish
E 11
I 11
D 15
PROGS=	nroff troff preppsfont
E 15
I 15
D 17
PROGS=	nroff troff preppsfont troffchar
E 17
I 17
PROGS=	nroff troff grokafm mkfont
E 17
E 15
E 11
E 9
E 6
I 3
D 7
PSFILES=TroffEncoding.ps Symbolextend.ps
E 7
I 7
D 19
PSFILES=TroffEncoding.ps TroffProcset.ps
E 19
I 19
D 20
PSFILES=CyrTroffEncoding.ps TroffEncoding.ps TroffProcset.ps
E 20
I 20
PSFILES=CyrTroffEncoding.ps TroffEncoding.ps TroffProcset.ps bdprocset.ps
E 20
E 19
I 9
D 11
SUBDIR=	5lig troffemu
E 11
I 11
D 17
SUBDIR=	5lig finish+merge troffemu
E 17
I 17
SUBDIR=	5lig finish+merge stdfonts troffemu
E 17
E 11
E 9
E 7
E 3
E 2

D 8
all: ${PROGS}
E 8
I 8
D 9
all: ${PROGS} troffemu
E 9
I 9
all: ${PROGS} ${SUBDIR}
E 9
E 8

nroff: ${NOBJS} ${LIBC}
	${CC} -o $@ ${NOBJS}

D 10
troff: ${TOBJS} ${LIBC}
	${CC} -o $@ ${TOBJS}
E 10
I 10
troff: ${TOBJS} ${LIBC} ${LIBM}
	${CC} -o $@ ${TOBJS} -lm
E 10

ni.o: ni.c tdef.h
	${CC} -c ${CFLAGS} -DNROFF ni.c

ni_t.o: ni.c tdef.h
	${CC} -c -o $@ ${CFLAGS} ni.c

nii.o: nii.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF nii.c

nii_t.o: nii.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} nii.c

n1.o: n1.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n1.c

t1.o: n1.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n1.c

n2.o: n2.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n2.c

t2.o: n2.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n2.c

n3.o: n3.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n3.c

t3.o: n3.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n3.c

n4.o: n4.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n4.c

t4.o: n4.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n4.c

n5.o: n5.c tdef.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n5.c

t5.o: n5.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n5.c

n6.o: n6.c tdef.h tw.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n6.c

D 16
t6.o: t6.c tdef.h d.h v.h
E 16
I 16
D 17
t6.o: t6.c tdef.h d.h v.h chardef.h
E 17
I 17
t6.o: t6.c tdef.h d.h v.h fontinfo.h
E 17
E 16
	${CC} -c -o $@ ${CFLAGS} t6.c

n7.o: n7.c tdef.h tw.h sdef.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n7.c

t7.o: n7.c tdef.h sdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n7.c

n8.o: n8.c tdef.h
	${CC} -c ${CFLAGS} -DNROFF n8.c

t8.o: n8.c tdef.h
	${CC} -c -o $@ ${CFLAGS} n8.c

n9.o: n9.c tdef.h tw.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n9.c

t9.o: n9.c tdef.h d.h v.h
	${CC} -c -o $@ ${CFLAGS} n9.c

n10.o: n10.c tdef.h tw.h d.h v.h
	${CC} -c ${CFLAGS} -DNROFF n10.c

D 17
t10.o: t10.c tdef.h d.h v.h
E 17
I 17
t10.o: t10.c tdef.h d.h v.h fontinfo.h
E 17
	${CC} -c -o $@ ${CFLAGS} t10.c
I 10

td.o: td.c tdef.h
	${CC} -c -o $@ ${CFLAGS} td.c
E 10

chtab.o: chtab.c
D 12
	${CC} -R -c chtab.c
E 12
I 12
	${CC} -c chtab.c

sortchtab:	chtab.o sortchtab.o
	${CC} -o $@ $@.o chtab.o

chtabs.c:	chtab.c sortchtab
	./sortchtab > $@
D 14
	fgrep sccsid chtab.c >> $@
E 14
I 14
	grep sccsid chtab.c >> $@
E 14

chtabs.o: chtabs.c
	${CC} -R -c chtabs.c
E 12
I 4

I 19
mkchlut:	chtab.o mkchlut.o
	${CC} -o $@ $@.o chtab.o

chlut.c:	chtab.c mkchlut
	./mkchlut > $@
	grep sccsid chtab.c >> $@

chlut.o: chlut.c
	${CC} -c chlut.c

E 19
cttab.o: cttab.c
	${CC} -R -c cttab.c
E 4

hytab.o: hytab.c
	${CC} -R -c hytab.c

suftab.o: suftab.c
	${CC} -R -c suftab.c

I 2
D 17
preppsfont: preppsfont.c
E 17
I 17
grokafm: grokafm.c
E 17
D 15
	${CC} -o $@ ${CFLAGS} preppsfont.c
E 15
I 15
	${CC} -o $@ ${CFLAGS} $@.c
E 15

I 15
D 16
troffchar: troffchar.c
E 16
I 16
D 17
troffchar: troffchar.c chardef.h
E 17
I 17
mkfont: mkfont.c fontinfo.h
E 17
E 16
	${CC} -o $@ ${CFLAGS} $@.c

E 15
I 6
D 11
pstmerge: pstmerge.c
	${CC} -o $@ ${CFLAGS} pstmerge.c
E 11
I 11
D 17
5lig:	preppsfont
E 17
I 17
5lig:	mkfont grokafm
stdfonts:	mkfont
troffemu:	mkfont
E 17
E 11

I 8
D 9
troffemu: FRC
	cd troffemu; make ${MFLAGS}
E 9
I 9
D 11
pstfinish: pstfinish.c
	${CC} -o $@ ${CFLAGS} pstfinish.c
E 9

E 11
I 9
${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

E 9
E 8
E 6
E 2
clean: FRC
D 18
	rm -f *.o a.out errs core ${PROGS}
E 18
I 18
D 19
	rm -f *.o a.out errs core ${PROGS} chtabs.c sortchtab
E 19
I 19
	rm -f *.o a.out errs core ${PROGS} chtabs.c sortchtab chlut.c mkchlut
E 19
E 18
I 8
D 9
	cd troffemu; make ${MFLAGS} clean
E 9
I 9
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 9
E 8

depend:

install: FRC
	install -s -o bin -g bin -m 755 nroff ${DESTDIR}/usr/ucb/nroff8
	install -s -o bin -g bin -m 755 troff ${DESTDIR}/usr/ucb/pstroff
I 13
	cd ${DESTDIR}/usr/ucb; rm -f troff; ln pstroff troff
E 13
I 2
D 9
	install -s -o bin -g bin -m 755 preppsfont ${DESTDIR}/usr/ucb
E 9
I 9
D 17
	install -c -s -o bin -g bin -m 755 preppsfont ${DESTDIR}/usr/ucb
I 15
	install -c -s -o bin -g bin -m 755 troffchar ${DESTDIR}/usr/ucb
E 17
I 17
	install -c -s -o bin -g bin -m 755 grokafm ${DESTDIR}/usr/ucb
	install -c -s -o bin -g bin -m 755 mkfont ${DESTDIR}/usr/ucb
E 17
E 15
E 9
I 6
D 11
	install -s -o bin -g bin -m 755 pstmerge ${DESTDIR}/usr/ucb
I 9
	install -s -o bin -g bin -m 755 pstfinish ${DESTDIR}/usr/ucb
E 11
E 9
E 6
E 2
D 3
	install -c -o bin -g bin -m 444 TroffEncoding.ps \
		${DESTDIR}/usr/lib/pstroff
E 3
I 3
D 5
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/usr/lib/pstroff
E 5
I 5
	if [ ! -d /usr/lib/pstroff ]; then mkdir /usr/lib/pstroff; else true; fi
D 7
	install -c -o bin -g bin -m 444 TroffEncoding.ps \
		${DESTDIR}/usr/lib/pstroff
	sed -e 's/%.*$$//' -e '/^$$/d' Symbolextend.ps > \
		${DESTDIR}/usr/lib/pstroff/Symbolextend.ps
	chown bin.bin ${DESTDIR}/usr/lib/pstroff/Symbolextend.ps
	chmod 444 ${DESTDIR}/usr/lib/pstroff/Symbolextend.ps
E 7
I 7
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/usr/lib/pstroff
I 8
D 9
	cd troffemu; make ${MFLAGS} install
E 9
I 9
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
E 9
E 8
E 7
E 5
E 3

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:
E 1

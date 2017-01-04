#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.20	(Berkeley)	2012/07/21
#
CFLAGS=	-O -DVMUNIX
LIBC=	/lib/libc.a
LIBM=	/usr/lib/libm.a
SRCS=	ni.c nii.c n1.c n2.c n3.c n4.c n5.c n6.c t6.c n7.c n8.c n9.c n10.c \
	t10.c chtab.c hytab.c suftab.c preppsfont.c sortchtab.c troffchar.c
NOBJS=	ni.o nii.o n1.o n2.o n3.o n4.o n5.o n6.o n7.o n8.o n9.o n10.o \
	chtabs.o hytab.o suftab.o
TOBJS=	ni_t.o nii_t.o t1.o t2.o t3.o t4.o t5.o t6.o t7.o t8.o t9.o t10.o td.o \
	chlut.o hytab.o suftab.o cttab.o
PROGS=	nroff troff grokafm mkfont
PSFILES=CyrTroffEncoding.ps TroffEncoding.ps TroffProcset.ps bdprocset.ps
SUBDIR=	5lig finish+merge stdfonts troffemu

all: ${PROGS} ${SUBDIR}

nroff: ${NOBJS} ${LIBC}
	${CC} -o $@ ${NOBJS}

troff: ${TOBJS} ${LIBC} ${LIBM}
	${CC} -o $@ ${TOBJS} -lm

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

t6.o: t6.c tdef.h d.h v.h fontinfo.h
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

t10.o: t10.c tdef.h d.h v.h fontinfo.h
	${CC} -c -o $@ ${CFLAGS} t10.c

td.o: td.c tdef.h
	${CC} -c -o $@ ${CFLAGS} td.c

chtab.o: chtab.c
	${CC} -c chtab.c

sortchtab:	chtab.o sortchtab.o
	${CC} -o $@ $@.o chtab.o

chtabs.c:	chtab.c sortchtab
	./sortchtab > $@
	grep sccsid chtab.c >> $@

chtabs.o: chtabs.c
	${CC} -R -c chtabs.c

mkchlut:	chtab.o mkchlut.o
	${CC} -o $@ $@.o chtab.o

chlut.c:	chtab.c mkchlut
	./mkchlut > $@
	grep sccsid chtab.c >> $@

chlut.o: chlut.c
	${CC} -c chlut.c

cttab.o: cttab.c
	${CC} -R -c cttab.c

hytab.o: hytab.c
	${CC} -R -c hytab.c

suftab.o: suftab.c
	${CC} -R -c suftab.c

grokafm: grokafm.c
	${CC} -o $@ ${CFLAGS} $@.c

mkfont: mkfont.c fontinfo.h
	${CC} -o $@ ${CFLAGS} $@.c

5lig:	mkfont grokafm
stdfonts:	mkfont
troffemu:	mkfont

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

clean: FRC
	rm -f *.o a.out errs core ${PROGS} chtabs.c sortchtab chlut.c mkchlut
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend:

install: FRC
	install -s -o bin -g bin -m 755 nroff ${DESTDIR}/usr/ucb/nroff8
	install -s -o bin -g bin -m 755 troff ${DESTDIR}/usr/ucb/pstroff
	cd ${DESTDIR}/usr/ucb; rm -f troff; ln pstroff troff
	install -c -s -o bin -g bin -m 755 grokafm ${DESTDIR}/usr/ucb
	install -c -s -o bin -g bin -m 755 mkfont ${DESTDIR}/usr/ucb
	if [ ! -d /usr/lib/pstroff ]; then mkdir /usr/lib/pstroff; else true; fi
	install -c -o bin -g bin -m 444 ${PSFILES} ${DESTDIR}/usr/lib/pstroff
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done

lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}

tags: ${SRCS} FRC
	ctags ${SRCS}

FRC:

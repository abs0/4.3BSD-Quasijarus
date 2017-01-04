h05825
s 00001/00001/00046
d D 1.4 88/03/23 19:18:35 jaap 4 3
c Oops, little bug
e
s 00000/00002/00047
d D 1.3 85/10/24 23:37:56 jaap 3 2
c We don't install vpic or pltroff anymore
e
s 00006/00004/00043
d D 1.2 85/07/23 11:19:20 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00047/00000/00000
d D 1.1 85/07/19 13:58:27 jaap 1 0
c date and time created 85/07/19 13:58:27 by jaap
e
u
U
t
T
I 1
#
#	%M%	(CWI)	%I%	%E%
#
D 2
CFLAGS= -O
E 2
I 2
CFLAGS= -g
E 2
YFLAGS= -d
DESTDIR=
BINDIR=/usr/local
OFILES = main.o print.o misc.o symtab.o blockgen.o boxgen.o circgen.o \
D 2
	arcgen.o linegen.o movegen.o troffgen.o textgen.o \
	pic2.o pltroff.o
E 2
I 2
D 4
	picy.o arcgen.o linegen.o movegen.o textgen.o \
E 4
I 4
	arcgen.o linegen.o movegen.o textgen.o \
E 4
	input.o for.o pltroff.o
E 2
OLDOFILES = OLDmain.o print.o misc.o symtab.o blockgen.o boxgen.o circgen.o \
	arcgen.o linegen.o movegen.o troffgen.o textgen.o \
	pic2.o OLDpltroff.o
D 2
OBJECTS= pic pltroff vpic
E 2
I 2
OBJECTS= pic
E 2

all: ${OBJECTS}

pic:	picy.o picl.o ${OFILES}
	cc -o pic picy.o picl.o ${OFILES} -lm

pltroff:	driver.o pltroff.o
I 2
	@echo "not supported"
E 2
	cc -o pltroff pltroff.o driver.o -lm

vpic:	picy.o picl.o ${OLDOFILES}
I 2
	@echo "not supported"
E 2
	cc -o vpic picy.o picl.o ${OLDOFILES} -lm

OLDpltroff.o:	pltroff.c
	cc ${CFLAGS} -c -DOLDTROFF pltroff.c
	mv pltroff.o OLDpltroff.o

OLDmain.o:	main.c
	cc -O -c -DOLDTROFF main.c
	mv main.o OLDmain.o

y.tab.h:	picy.o

pic.ydef:	ytab.h
	-cmp -s y.tab.h pic.ydef || cp y.tab.h pic.ydef

install: all
	install -s pic ${DESTDIR}${BINDIR}/pic
D 3
	install -s vpic ${DESTDIR}${BINDIR}/vpic
	install -s pltroff ${DESTDIR}${BINDIR}/pltroff
E 3
	install -c -m 644 pic.1 ${DESTDIR}/usr/man/manl/pic.1

clean:
	rm -f ${OBJECTS} *.o y.tab.h make.out
E 1

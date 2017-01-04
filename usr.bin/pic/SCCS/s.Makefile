h38321
s 00017/00013/00014
d D 1.2 2013/08/05 06:08:13 msokolov 2 1
c Makefile for bringing this pic version into the 4.3BSD-Quasijarus env
e
s 00027/00000/00000
d D 1.1 2013/08/05 05:43:16 msokolov 1 0
c pic version from Final-CSRG /usr/src/local/ditroff/pic; 1988-04-13 file dates
e
u
U
t
T
I 1
D 2
BINDIR  = /usr/local
DESTFILE= npic
YFLAGS = -d
CFLAGS =
E 2
I 2
# Makefile for the version of pic adopted into 4.3BSD-Quasijarus
#
#	%W% (Quasijarus) %E%
E 2

I 2
BINDIR=	/usr/bin
PROG=	pic
YFLAGS=	-d
CFLAGS=	-O

E 2
OFILES = picy.o picl.o main.o print.o misc.o symtab.o blockgen.o boxgen.o \
	 circgen.o arcgen.o linegen.o movegen.o textgen.o \
	 input.o for.o pltroff.o 
CFILES = main.c print.c misc.c symtab.c blockgen.c boxgen.c circgen.c \
	 arcgen.c linegen.c movegen.c textgen.c \
	 input.c for.c pltroff.c
D 2
SRCFILES = picy.y picl.l pic.h $(CFILES)
E 2
I 2
SRCFILES = picy.y picl.l pic.h ${CFILES}
E 2

D 2
pic:	picy.o picl.o $(OFILES) pic.h
	cc -o pic picy.o picl.o $(OFILES) -lm
E 2
I 2
all:	${PROG}
E 2

D 2
$(OFILES):	pic.h
E 2
I 2
pic:	${OFILES} pic.h
	cc -o $@ ${OFILES} -lm
E 2

I 2
${OFILES}:	pic.h

E 2
y.tab.h:	picy.o

D 2
install:	$(BINDIR)/$(DESTFILE)
E 2
I 2
install:
	install -o bin -g bin -m 755 -s ${PROG} ${BINDIR}
E 2

D 2
$(BINDIR)/$(DESTFILE):	pic
	install -c -s pic $(BINDIR)/$(DESTFILE)

E 2
clean:
D 2
	/bin/rm -f *.o y.tab.h make.out pic
E 2
I 2
	rm -f *.o y.tab.h make.out pic errs
E 2
E 1

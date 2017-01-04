# Makefile for the version of pic adopted into 4.3BSD-Quasijarus
#
#	@(#)Makefile	1.2 (Quasijarus) 2013/08/05

BINDIR=	/usr/bin
PROG=	pic
YFLAGS=	-d
CFLAGS=	-O

OFILES = picy.o picl.o main.o print.o misc.o symtab.o blockgen.o boxgen.o \
	 circgen.o arcgen.o linegen.o movegen.o textgen.o \
	 input.o for.o pltroff.o 
CFILES = main.c print.c misc.c symtab.c blockgen.c boxgen.c circgen.c \
	 arcgen.c linegen.c movegen.c textgen.c \
	 input.c for.c pltroff.c
SRCFILES = picy.y picl.l pic.h ${CFILES}

all:	${PROG}

pic:	${OFILES} pic.h
	cc -o $@ ${OFILES} -lm

${OFILES}:	pic.h

y.tab.h:	picy.o

install:
	install -o bin -g bin -m 755 -s ${PROG} ${BINDIR}

clean:
	rm -f *.o y.tab.h make.out pic errs

BINDIR  = /usr/local
DESTFILE= npic
YFLAGS = -d
CFLAGS =

OFILES = picy.o picl.o main.o print.o misc.o symtab.o blockgen.o boxgen.o \
	 circgen.o arcgen.o linegen.o movegen.o textgen.o \
	 input.o for.o pltroff.o 
CFILES = main.c print.c misc.c symtab.c blockgen.c boxgen.c circgen.c \
	 arcgen.c linegen.c movegen.c textgen.c \
	 input.c for.c pltroff.c
SRCFILES = picy.y picl.l pic.h $(CFILES)

pic:	picy.o picl.o $(OFILES) pic.h
	cc -o pic picy.o picl.o $(OFILES) -lm

$(OFILES):	pic.h

y.tab.h:	picy.o

install:	$(BINDIR)/$(DESTFILE)

$(BINDIR)/$(DESTFILE):	pic
	install -c -s pic $(BINDIR)/$(DESTFILE)

clean:
	/bin/rm -f *.o y.tab.h make.out pic

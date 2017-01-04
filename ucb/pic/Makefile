BINDIR	= /usr/local
DESTFILE= pic
DEVDIR	= "/usr/local/lib/font"
YFLAGS	= -d
CFLAGS	= '-DDEVDIR=$(DEVDIR)'

OFILES = main.o print.o misc.o symtab.o blockgen.o boxgen.o circgen.o \
	arcgen.o linegen.o movegen.o troffgen.o textgen.o \
	pic2.o pltroff.o

CFILES = main.c print.c misc.c symtab.c blockgen.c boxgen.c circgen.c \
	arcgen.c linegen.c movegen.c troffgen.c textgen.c \
	pic2.c pltroff.c

SRCFILES = picy.y picl.l pic.h $(CFILES)


pic:	picy.o picl.o $(OFILES) pic.h 
	cc -o pic picy.o picl.o $(OFILES)  -lm

pltroff:	driver.o pltroff.o
	cc -o pltroff pltroff.o driver.o -lm

npltroff:	driver.o npltroff.o
	cc -o npltroff npltroff.o driver.o -lm

$(OFILES):	pic.h

install:	$(BINDIR)/$(DESTFILE)

$(BINDIR)/$(DESTFILE):	pic
	install -c -s pic $(BINDIR)/$(DESTFILE)

lineseg:	lineseg.o picy.o picl.o $(OFILES)
	cc -o lineseg picy.o picl.o lineseg.o $(OFILES)  -lm

y.tab.h:	picy.o

pic.ydef:	y.tab.h
	-cmp -s y.tab.h pic.ydef || cp y.tab.h pic.ydef

list:
	@pr WISH UNDOC picy.y picl.l pic.h  $(CFILES)

gout:	gout.c
	cc -o gout gout.c

gin:	gin.c
	cc -o gin gin.c

memo:
	refer -e picmemo | pic | eqn | troff -ms $(TFLAGS) >pic.out 2>pic.mess

spline:	spline.c
	cc spline.c -lm -o spline

grapic: grapic.c
	cc -DPIC -O grapic.c -lplot -lm -o grapic

clean:
	/bin/rm -f *.o y.tab.h make.out pic

#
#	%W%	(Berkeley)	%E%
#
CFLAGS=	-O
YFLAGS=	-d
DESTDIR=
BINDIR=	/usr/ucb
OFILES=	main.o print.o misc.o symtab.o blockgen.o boxgen.o circgen.o \
	arcgen.o linegen.o movegen.o textgen.o \
	input.o for.o pltroff.o
PROG=	pic

all:	${PROG}

pic:	picy.o picl.o ${OFILES}
	cc -o pic picy.o picl.o ${OFILES} -lm

install: all
	install -s pic ${DESTDIR}${BINDIR}/pic
	install -c -m 644 pic.1 ${DESTDIR}/usr/man/manl/pic.1

clean:
	rm -f ${PROG} *.o y.tab.h make.out

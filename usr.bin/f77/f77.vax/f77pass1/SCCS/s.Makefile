h53215
s 00095/00157/00019
d D 5.4 87/06/18 17:33:27 bostic 4 3
c new template
e
s 00031/00031/00145
d D 5.3 86/11/05 15:18:15 mckusick 3 2
c delete extraneous levels of directories
e
s 00002/00003/00174
d D 5.2 85/08/29 00:23:50 donn 2 1
c Add definition for NAMELIST (from Jerry Berkman).
e
s 00177/00000/00000
d D 5.1 85/06/07 21:23:18 mckusick 1 0
c 4.3BSD beta release version
e
u
U
t
T
I 1
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
#
D 2
CFLAGS	      = -O -DHERE=VAX -DTARGET=VAX -DFAMILY=PCC -DUCBVAXASM -DUCBPASS2 \

		-I../../include
E 2
I 2
D 4
CFLAGS	      = -O -DHERE=VAX -DTARGET=VAX -DFAMILY=PCC -DUCBVAXASM \
D 3
		-DUCBPASS2 -DNAMELIST -I../../include
E 3
I 3
		-DUCBPASS2 -DNAMELIST -I../include
E 4
I 4
CFLAGS=	-O -DHERE=VAX -DTARGET=VAX -DFAMILY=PCC -DUCBVAXASM \
	-DUCBPASS2 -DNAMELIST -I../include
LIBC=	/lib/libc.a
SRCS=	bb.c conv.c data.c equiv.c error.c exec.c expr.c fmt.c gram.c init.c \
	intr.c io.c lex.c main.c misc.c optcse.c optim.c optloop.c paramset.c \
	proc.c put.c putpcc.c regalloc.c setfmt.c stab.c vax.c vaxx.c
OBJS=	bb.o conv.o data.o equiv.o error.o exec.o expr.o fmt.o gram.o init.o \
	intr.o io.o lex.o main.o misc.o optcse.o optim.o optloop.o paramset.o \
	proc.o put.o putpcc.o regalloc.o setfmt.o stab.o vax.o vaxx.o
E 4
E 3
E 2

D 4
DEST	      = $(DESTDIR)/usr/lib
E 4
I 4
all: f77pass1
E 4

D 3
EXTHDRS	      = ../../include/defines.h \
		../../include/machdefs.h \
E 3
I 3
D 4
EXTHDRS	      = ../include/defines.h \
		../include/machdefs.h \
E 3
		/usr/include/a.out.h \
		/usr/include/ctype.h \
		/usr/include/signal.h \
		/usr/include/stab.h \
		/usr/include/stdio.h \
		/usr/include/sys/file.h \
		/usr/include/sys/types.h
E 4
I 4
f77pass1: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 4

D 4
HDRS	      = conv.h \
		data.h \
		defs.h \
		fio.h \
		ftypes.h \
		io.h \
		optim.h \
		tokdefs.h
E 4
I 4
gram.c:	gram.head gram.dcl gram.expr gram.exec gram.io tokdefs.h
	( sed <tokdefs.h "s/#define/%token/"; \
		cat gram.head gram.dcl gram.expr gram.exec gram.io ) >gram.in
	${YACC} gram.in
	mv y.tab.c gram.c
E 4

D 4
LDFLAGS	      =
E 4
I 4
gram.head: defs.h data.h
E 4

D 4
LIBS	      =
E 4
I 4
tokdefs.h: tokens
	grep -n . <tokens | sed "s/\([^:]*\):\(.*\)/#define \2 \1/" >tokdefs.h
E 4

D 4
LINKER	      = cc
E 4
I 4
clean: FRC
	rm -f ${OBJS} core f77pass1 gram.c gram.in
E 4

D 4
MAKEFILE      = Makefile
E 4
I 4
depend: ${SRCS} FRC
	mkdep ${CFLAGS} ${SRCS}
E 4

D 4
OBJS	      = bb.o \
		conv.o \
		data.o \
		equiv.o \
		error.o \
		exec.o \
		expr.o \
		fmt.o \
		gram.o \
		init.o \
		intr.o \
		io.o \
		lex.o \
		main.o \
		misc.o \
		optcse.o \
		optim.o \
		optloop.o \
		paramset.o \
		proc.o \
		put.o \
		putpcc.o \
		regalloc.o \
		setfmt.o \
		stab.o \
		vax.o \
		vaxx.o
E 4
I 4
install: FRC
	install -s -o bin -g bin -m 755 f77pass1 ${DESTDIR}/usr/lib/f77pass1
E 4

D 4
PRINT	      = pr
E 4
I 4
lint: ${SRCS} FRC
	lint ${CFLAGS} ${SRCS}
E 4

D 4
PROGRAM	      = f77pass1
E 4
I 4
tags: ${SRCS} FRC
	ctags ${SRCS}
E 4

D 4
SRCS	      = bb.c \
		conv.c \
		data.c \
		equiv.c \
		error.c \
		exec.c \
		expr.c \
		fmt.c \
		gram.c \
		init.c \
		intr.c \
		io.c \
		lex.c \
		main.c \
		misc.c \
		optcse.c \
		optim.c \
		optloop.c \
		paramset.c \
		proc.c \
		put.c \
		putpcc.c \
		regalloc.c \
		setfmt.c \
		stab.c \
		vax.c \
		vaxx.c
E 4
I 4
FRC:
E 4

D 4
all:		$(PROGRAM)
E 4
I 4
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 4

D 4
$(PROGRAM):     $(OBJS) $(LIBS)
		@echo -n "Loading $(PROGRAM) ... "
		@$(LINKER) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
		@echo "done"
E 4
I 4
bb.o: bb.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
bb.o: ../include/defines.h ../include/machdefs.h optim.h
conv.o: conv.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
conv.o: ../include/defines.h ../include/machdefs.h conv.h
data.o: data.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
data.o: ../include/defines.h ../include/machdefs.h data.h
equiv.o: equiv.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
equiv.o: ../include/defines.h ../include/machdefs.h /usr/include/a.out.h
equiv.o: /usr/include/sys/exec.h /usr/include/stab.h
error.o: error.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
error.o: ../include/defines.h ../include/machdefs.h
exec.o: exec.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
exec.o: ../include/defines.h ../include/machdefs.h optim.h
expr.o: expr.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
expr.o: ../include/defines.h ../include/machdefs.h /usr/include/signal.h
expr.o: /usr/include/setjmp.h
fmt.o: fmt.c format.h
gram.o: gram.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
gram.o: ../include/defines.h ../include/machdefs.h data.h /usr/include/a.out.h
gram.o: /usr/include/sys/exec.h /usr/include/stab.h
init.o: init.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
init.o: ../include/defines.h ../include/machdefs.h io.h /usr/include/sys/file.h
intr.o: intr.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
intr.o: ../include/defines.h ../include/machdefs.h
io.o: io.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
io.o: ../include/defines.h ../include/machdefs.h io.h
lex.o: lex.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
lex.o: ../include/defines.h ../include/machdefs.h tokdefs.h
main.o: main.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
main.o: ../include/defines.h ../include/machdefs.h /usr/include/signal.h
main.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
misc.o: misc.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
misc.o: ../include/defines.h ../include/machdefs.h
optcse.o: optcse.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
optcse.o: ../include/defines.h ../include/machdefs.h optim.h
optim.o: optim.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
optim.o: ../include/defines.h ../include/machdefs.h optim.h
optloop.o: optloop.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
optloop.o: ../include/defines.h ../include/machdefs.h optim.h
paramset.o: paramset.c defs.h /usr/include/stdio.h /usr/include/ctype.h
paramset.o: ftypes.h ../include/defines.h ../include/machdefs.h data.h
proc.o: proc.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
proc.o: ../include/defines.h ../include/machdefs.h /usr/include/a.out.h
proc.o: /usr/include/sys/exec.h /usr/include/stab.h
put.o: put.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
put.o: ../include/defines.h ../include/machdefs.h /usr/include/pcc.h
putpcc.o: putpcc.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
putpcc.o: ../include/defines.h ../include/machdefs.h /usr/include/pcc.h
regalloc.o: regalloc.c defs.h /usr/include/stdio.h /usr/include/ctype.h
regalloc.o: ftypes.h ../include/defines.h ../include/machdefs.h optim.h
setfmt.o: setfmt.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
setfmt.o: ../include/defines.h ../include/machdefs.h format.h
stab.o: stab.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
stab.o: ../include/defines.h ../include/machdefs.h /usr/include/sys/types.h
stab.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
vax.o: vax.c defs.h /usr/include/stdio.h /usr/include/ctype.h ftypes.h
vax.o: ../include/defines.h ../include/machdefs.h /usr/include/a.out.h
vax.o: /usr/include/sys/exec.h /usr/include/stab.h /usr/include/pcc.h
vaxx.o: vaxx.c /usr/include/stdio.h ../include/defines.h ../include/machdefs.h
E 4

D 4
clean:;		@rm -f $(OBJS) gram.c gram.in

depend:;	@mkmf -f $(MAKEFILE) PROGRAM=$(PROGRAM) DEST=$(DEST)

index:;		@ctags -wx $(HDRS) $(SRCS)

install:	$(PROGRAM)
		@echo Installing $(PROGRAM) in $(DEST)
		@install -s $(PROGRAM) $(DEST)

lint:;		lint -h $(CFLAGS) $(SRCS)

print:;		@$(PRINT) $(HDRS) $(SRCS)

program:        $(PROGRAM)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)

update:		$(DEST)/$(PROGRAM)

$(DEST)/$(PROGRAM): $(SRCS) $(LIBS) $(HDRS) $(EXTHDRS)
		@make -f $(MAKEFILE) DEST=$(DEST) install

gram.c:	gram.head gram.dcl gram.expr gram.exec gram.io tokdefs.h
	( sed <tokdefs.h "s/#define/%token/" ;\
		cat gram.head gram.dcl gram.expr gram.exec gram.io ) >gram.in
	$(YACC) $(YFLAGS) gram.in
	@echo "(expect 4 shift/reduce)"
	mv y.tab.c gram.c

gram.head: defs.h data.h

tokdefs.h: tokens
	grep -n . <tokens | sed "s/\([^:]*\):\(.*\)/#define \2 \1/" >tokdefs.h
###
bb.o: /usr/include/stdio.h /usr/include/ctype.h ftypes.h \
D 3
	../../include/defines.h ../../include/machdefs.h defs.h optim.h
conv.o: defs.h ../../include/machdefs.h conv.h
data.o: defs.h ../../include/machdefs.h data.h
equiv.o: defs.h ../../include/machdefs.h /usr/include/a.out.h \
E 3
I 3
	../include/defines.h ../include/machdefs.h defs.h optim.h
conv.o: defs.h ../include/machdefs.h conv.h
data.o: defs.h ../include/machdefs.h data.h
equiv.o: defs.h ../include/machdefs.h /usr/include/a.out.h \
E 3
	/usr/include/stab.h
D 3
error.o: defs.h ../../include/machdefs.h
exec.o: defs.h ../../include/machdefs.h optim.h
expr.o: defs.h ../../include/machdefs.h
fmt.o: defs.h format.h ../../include/machdefs.h
gram.o: defs.h ../../include/machdefs.h data.h /usr/include/a.out.h \
E 3
I 3
error.o: defs.h ../include/machdefs.h
exec.o: defs.h ../include/machdefs.h optim.h
expr.o: defs.h ../include/machdefs.h
fmt.o: defs.h format.h ../include/machdefs.h
gram.o: defs.h ../include/machdefs.h data.h /usr/include/a.out.h \
E 3
	/usr/include/stab.h
D 3
init.o: defs.h ../../include/machdefs.h io.h /usr/include/sys/file.h
intr.o: defs.h ../../include/machdefs.h
io.o: defs.h ../../include/machdefs.h io.h
lex.o: defs.h ../../include/machdefs.h tokdefs.h
main.o: defs.h ../../include/machdefs.h /usr/include/signal.h \
E 3
I 3
init.o: defs.h ../include/machdefs.h io.h /usr/include/sys/file.h
intr.o: defs.h ../include/machdefs.h
io.o: defs.h ../include/machdefs.h io.h
lex.o: defs.h ../include/machdefs.h tokdefs.h
main.o: defs.h ../include/machdefs.h /usr/include/signal.h \
E 3
	/usr/include/a.out.h /usr/include/stab.h
D 3
misc.o: defs.h ../../include/machdefs.h
optcse.o: defs.h ../../include/machdefs.h optim.h
optim.o: defs.h ../../include/machdefs.h optim.h
optloop.o: defs.h ../../include/machdefs.h optim.h
paramset.o: defs.h ../../include/machdefs.h data.h
proc.o: defs.h ../../include/machdefs.h /usr/include/a.out.h \
E 3
I 3
misc.o: defs.h ../include/machdefs.h
optcse.o: defs.h ../include/machdefs.h optim.h
optim.o: defs.h ../include/machdefs.h optim.h
optloop.o: defs.h ../include/machdefs.h optim.h
paramset.o: defs.h ../include/machdefs.h data.h
proc.o: defs.h ../include/machdefs.h /usr/include/a.out.h \
E 3
	/usr/include/stab.h
D 3
put.o: defs.h ../../include/machdefs.h /usr/include/pcc.h
putpcc.o: defs.h ../../include/machdefs.h /usr/include/pcc.h
regalloc.o: defs.h ../../include/machdefs.h optim.h
setfmt.o: defs.h format.h ../../include/machdefs.h
stab.o: defs.h ../../include/machdefs.h /usr/include/sys/types.h \
E 3
I 3
put.o: defs.h ../include/machdefs.h /usr/include/pcc.h
putpcc.o: defs.h ../include/machdefs.h /usr/include/pcc.h
regalloc.o: defs.h ../include/machdefs.h optim.h
setfmt.o: defs.h format.h ../include/machdefs.h
stab.o: defs.h ../include/machdefs.h /usr/include/sys/types.h \
E 3
	/usr/include/a.out.h /usr/include/stab.h
D 3
vax.o: defs.h ../../include/machdefs.h /usr/include/a.out.h \
E 3
I 3
vax.o: defs.h ../include/machdefs.h /usr/include/a.out.h \
E 3
	/usr/include/stab.h /usr/include/pcc.h
D 3
vaxx.o: /usr/include/stdio.h ../../include/defines.h \
	../../include/machdefs.h
E 3
I 3
vaxx.o: /usr/include/stdio.h ../include/defines.h \
	../include/machdefs.h
E 4
I 4
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 4
E 3
E 1

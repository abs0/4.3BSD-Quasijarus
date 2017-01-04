h38222
s 00005/00003/00270
d D 1.21 83/05/11 21:15:17 dlw 21 20
c old lib goes to /usr/old/lib. DWL
e
s 00001/00001/00272
d D 1.20 83/05/11 15:24:05 claudio 20 19
c added ioinit.f to archive. DLW
e
s 00033/00013/00240
d D 1.19 83/05/06 11:17:27 dlw 19 18
c added profiled library. DLW
e
s 00004/00012/00249
d D 1.18 83/04/15 22:57:46 dlw 18 17
c removed yes_66, no_66; redefined libI66. DLW
e
s 00010/00002/00251
d D 1.17 83/04/14 23:28:31 dlw 17 16
c added ioinit.f . DLW
e
s 00103/00073/00148
d D 1.16 83/01/03 22:54:15 dlw 16 15
c cleaned up & adapted to SCCS subdir. DLW
e
s 00003/00003/00218
d D 1.15 82/06/03 20:39:53 dlw 15 14
c minor syntax fixes. DLW
e
s 00001/00005/00219
d D 1.14 82/02/09 09:31:42 root 14 13
c removed all reference to dballoc. DLW
e
s 00107/00004/00117
d D 1.13 82/01/08 00:11:00 dlw 13 12
c added Makefile target; added SCCS invocation. DLW
e
s 00002/00001/00119
d D 1.12 81/08/14 14:26:37 dlw 12 11
c added global for 'lpr'. DLW
e
s 00001/00001/00119
d D 1.11 81/08/11 16:44:43 dlw 11 10
c removed dballoc - will use the libc version. DLW
e
s 00007/00001/00113
d D 1.10 81/04/29 13:31:34 dlw 10 9
c added libI66 to init the fortran-66 i/o features. DLW
e
s 00003/00002/00111
d D 1.9 81/04/28 19:30:47 dlw 9 8
c added {yes,no}_66 for f66 initialization. DLW
e
s 00008/00002/00105
d D 1.8 81/04/19 22:31:27 dlw 8 7
c added Vax & PDP11 specific defs. DLW
e
s 00006/00002/00101
d D 1.7 81/02/27 16:13:06 dlw 7 6
c made f_errlist a separate module. DLW
e
s 00001/00001/00102
d D 1.6 81/02/26 23:02:41 dlw 6 5
c enabled saving old lib on install. DLW
e
s 00002/00001/00101
d D 1.5 81/02/26 17:41:25 dlw 5 4
c made LIBDIR /usr/ucb/lib. DLW
e
s 00009/00003/00093
d D 1.4 81/02/25 16:21:12 dlw 4 3
c added targets for mkindx & mkvers. DLW
e
s 00001/00001/00095
d D 1.3 81/02/25 14:48:22 dlw 3 2
c replaced sccs keywords. DLW
e
s 00013/00012/00083
d D 1.2 81/02/25 14:45:08 dlw 2 1
c added $(LIB) and mk????* to 'make tape'. DLW
e
s 00095/00000/00000
d D 1.1 81/02/18 18:26:30 dlw 1 0
c date and time created 81/02/18 18:26:30 by dlw
e
u
U
t
T
I 1
# Makefile for the f77 I/O library
D 2
#	%W%
E 2
I 2
D 3
#	@(#)Makefile	1.1
E 3
I 3
#	%W%	%G%
E 3
E 2
# Originally written by P. Weinberger, Bell Labs, Murray Hill, N.J.
# Modified by D. Wasley, Univ of California, Berkeley, Calif.

I 16
DESTDIR =
E 16
D 2
DESTDIR = cc
E 2
I 2
D 5
LIBDIR = /usr/cc/lib
E 5
I 5
D 8
LIBDIR = /usr/ucb/lib
E 8
E 5
LIB = libI77.a
I 19
LIB_P = libI77_p.a
E 19
E 2
CFLAGS = -O
I 12
LPR = lpr
E 12
D 8
TAPE = /dev/nrmt1
E 8
I 8

# for CFO 11's
#ENV = ucb
D 16
#LIBDIR = /usr/$(ENV)/lib
E 16
I 16
#LIBDIR = ${DESTDIR}/usr/$(ENV)/lib
I 21
#OLDDIR = ${DESTDIR}/usr/old/lib
E 21
E 16
#TAPE = /dev/nrmt1

# for Vax
D 16
LIBDIR = /usr/lib
E 16
I 16
LIBDIR = ${DESTDIR}/usr/lib
E 16
D 21
TAPE = /dev/rnmt0.1600
E 21
I 21
OLDDIR = ${DESTDIR}/usr/old/lib
TAPE = /dev/rnmt1
E 21
E 8

D 14
SOURCES = backspace.c close.c dballoc.c dfe.c due.c endfile.c err.c fmt.c \
E 14
I 14
SOURCES = backspace.c close.c dfe.c due.c endfile.c err.c fmt.c \
E 14
	fmtlib.c iio.c inquire.c lwrite.c lread.c dolio.c open.c \
	rdfmt.c rewind.c sfe.c sue.c douio.c util.c wrtfmt.c \
D 7
	dofio.c fiodefs.h fio.h format.h lio.h f_errno.h f_errlist.h
E 7
I 7
D 9
	dofio.c f_errlist.c f_errno.h fiodefs.h fio.h format.h lio.h
E 9
I 9
D 18
	dofio.c f_errlist.c yes_66.c no_66.c \
E 18
I 18
	dofio.c f_errlist.c \
E 18
D 17
	f_errno.h fiodefs.h fio.h format.h lio.h
E 17
I 17
	f_errno.h fiodefs.h fio.h format.h lio.h ioinit.f
E 17
E 9
E 7

OBJECTS = dfe.o due.o iio.o sue.o sfe.o lread.o lwrite.o \
	dofio.o douio.o dolio.o \
	rdfmt.o wrtfmt.o fmt.o fmtlib.o \
	backspace.o rewind.o open.o close.o endfile.o inquire.o \
D 7
	dballoc.o err.o util.o
E 7
I 7
D 9
	dballoc.o err.o util.o f_errlist.o
E 9
I 9
D 11
	dballoc.o yes_66.o err.o no_66.o util.o f_errlist.o
E 11
I 11
D 17
	yes_66.o err.o no_66.o util.o f_errlist.o
E 17
I 17
D 18
	yes_66.o err.o no_66.o util.o f_errlist.o ioinit.o
E 18
I 18
	ioinit.o err.o util.o f_errlist.o
E 18
E 17
E 11
E 9
E 7

D 2
libI77.a:	$(OBJECTS) Version
E 2
I 2
D 19
all:	$(LIB)
E 19
I 19
all:	$(LIB) $(LIB_P)
E 19

D 20
$(LIB):	$(OBJECTS) Version
E 20
I 20
$(LIB):	$(OBJECTS) Version ioinit.f
E 20
E 2
D 16
	@echo Loading
E 16
D 2
	@rm -f libI77.a
	@ar rc libI77.a $(OBJECTS) Version
	@chmod 664 libI77.a
	@echo "Done"
E 2
I 2
D 19
	@rm -f $(LIB)
D 16
	@ar rc $(LIB) $(OBJECTS) Version
E 16
I 16
	ar rc $(LIB) $(OBJECTS) Version
E 16
	@chmod 664 $(LIB)
E 19
I 19
	ar ru $(LIB) $?
	ranlib $(LIB)
	@chmod 644 $(LIB)
E 19
D 16
	@echo "" > /dev/tty
E 16
E 2

D 10
install:
E 10
I 10
D 16
install:	$(LIB) libI66.a
E 16
I 16
D 19
install:	$(LIBDIR)/$(LIB) $(LIBDIR)/libI66.a
E 19
I 19
$(LIB_P):	$(OBJECTS) Version
	cd profiled; ar ru ../$(LIB_P) $?
	ranlib $(LIB_P)
	@chmod 644 $(LIB_P)
E 19

I 19
install:	$(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB_P) $(LIBDIR)/libI66.a

E 19
$(LIBDIR)/$(LIB):	$(LIB)
E 16
E 10
D 2
#	@mv /usr/$(DESTDIR)/lib/libI77.a /usr/$(DESTDIR)/lib/libI77.a.old
	cp libI77.a /usr/$(DESTDIR)/lib/libI77.a
E 2
I 2
D 6
#	@mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 6
I 6
D 15
	@mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 15
I 15
D 21
	@-mv $(LIBDIR)/$(LIB) $(LIBDIR)/$(LIB).old
E 21
I 21
	@-mv $(LIBDIR)/$(LIB) $(OLDDIR)/$(LIB)
E 21
E 15
E 6
D 19
	cp $(LIB) $(LIBDIR)/$(LIB)
I 5
	ranlib $(LIBDIR)/$(LIB)
I 10
D 16
	chmod 644 $(LIBDIR)/$(LIB)
	@mv libI66.a $(LIBDIR)
E 16
I 16
	@chmod 644 $(LIBDIR)/$(LIB)
E 19
I 19
	tar cf - $(LIB) | (cd $(LIBDIR); tar xvf - )
E 19

I 19
$(LIBDIR)/$(LIB_P):	$(LIB_P)
D 21
	@-mv $(LIBDIR)/$(LIB_P) $(LIBDIR)/$(LIB_P).old
E 21
I 21
	@-mv $(LIBDIR)/$(LIB_P) $(OLDDIR)/$(LIB_P)
E 21
	tar cf - $(LIB_P) | (cd $(LIBDIR); tar xvf - )

E 19
D 18
$(LIBDIR)/libI66.a:	yes_66.o
	cp yes_66.o $(LIBDIR)/libI66.a
E 18
I 18
$(LIBDIR)/libI66.a:	libI66.o
	cp libI66.o $(LIBDIR)/libI66.a
E 18
E 16
	@chmod 644 $(LIBDIR)/libI66.a
E 10
E 5
E 2

backspace.o:	fio.h backspace.c
dfe.o:		fio.h dfe.c
due.o:		fio.h due.c
iio.o:		fio.h lio.h iio.c
inquire.o:	fio.h inquire.c
rewind.o:	fio.h rewind.c
rdfmt.o:	fio.h format.h rdfmt.c
sue.o:		fio.h sue.c
douio.o:	fio.h douio.c
sfe.o:		fio.h sfe.c
fmt.o:		fio.h format.h fmt.c
dofio.o:	fio.h format.h dofio.c
lwrite.o:	fio.h lio.h lwrite.c
lread.o:	fio.h lio.h lread.c
dolio.o:	fio.h lio.h dolio.c
open.o:		fio.h open.c
close.o:	fio.h close.c
util.o:		fio.h util.c
endfile.o:	fio.h endfile.c
wrtfmt.o:	fio.h format.h wrtfmt.c
err.o:		fiodefs.h err.c
fmtlib.o:	fio.h fmtlib.c
D 14
dballoc.o:	dballoc.c
E 14
#fio.h:		fiodefs.h
I 7
#fiodefs.h:	f_errno.h
E 7

# compile, then strip unnecessary symbols
.c.o:
I 19
	-cd profiled; \
		cc $(CFLAGS) -p -c ../$*.c; \
		ld -r -x $*.o; \
		mv a.out $*.o
E 19
	cc $(CFLAGS) -c $*.c
	-ld -r -x $*.o
	mv a.out $*.o
I 7

I 17
ioinit.o:	ioinit.f
I 19
	-cd profiled; \
		f77 -O -p -c ../ioinit.f; \
		ld -r -x ioinit.o; \
		mv a.out ioinit.o
E 19
	f77 -O -c ioinit.f
	-ld -r -x ioinit.o
	mv a.out ioinit.o

E 17
f_errlist.o:	f_errlist.c
	cc $(CFLAGS) -c f_errlist.c
I 19
	@rm -f profiled/f_errlist.o
	ln f_errlist.o profiled/f_errlist.o
E 19
E 7

D 4
Version:	$(SOURCES)
E 4
I 4
Version:	$(SOURCES) mkvers
E 4
	@rm -f Version.c
D 2
	mkvers libI77.a $(SOURCES)
E 2
I 2
D 15
	mkvers $(LIB) $(SOURCES) > Version.c
E 15
I 15
	./mkvers $(LIB) $(SOURCES) > Version.c
E 15
E 2
	cc -c Version.c
	mv Version.o Version
I 19
	@rm -f profiled/Version
	ln Version profiled/Version
E 19

I 4
mkvers:	mkvers.c
	@cc mkvers.c -o mkvers

E 4
clean:
D 2
	rm -f *.o libI77.a tags
E 2
I 2
D 16
	rm -f *.o $(LIB) libI66.a tags
E 16
I 16
D 19
	rm -f $(OBJECTS) $(LIB) libI66.o
E 19
I 19
	rm -f $(OBJECTS) Version $(LIB) $(LIB_P) libI66.o profiled/*
E 19
E 16
E 2

D 4
index:	$(SOURCES)
E 4
I 4
index:	$(SOURCES) mkindx
E 4
D 15
	@mkindx "f77 libI77.a Source Listing " Makefile $(SOURCES)
E 15
I 15
	@./mkindx "f77 libI77.a Source Listing " Makefile $(SOURCES)
E 15

print:	index
D 12
	@pr index Makefile `ls $(SOURCES)` | lpr
E 12
I 12
	@pr index Makefile `ls $(SOURCES)` | $(LPR)
E 12

I 4
mkindx:	mkindx.c
	@cc mkindx.c -o mkindx

E 4
Intro:	Intro.tx
	@-rm Intro
D 19
	@nroff -ms Intro.tx > Intro
E 19
I 19
	nroff -ms Intro.tx > Intro
E 19

wup:	Intro.tx
D 19
	@nroff -ms Intro.tx | ul | more
E 19
I 19
	nroff -ms Intro.tx | ul | more
E 19

D 13
tape:	
D 2
	@tar cbf 20 $(TAPE) \
E 2
I 2
D 4
	@tar cbf 20 $(TAPE) mkvers.c mkvers mkindx.c mkindx \
E 4
I 4
	@tar cbf 20 $(TAPE) mkvers.c mkindx.c \
E 4
E 2
	Makefile READ_ME NEWS Intro.tx Intro $(SOURCES)

E 13
order:
	@rm -f order
D 19
	@lorder $(OBJECTS) | tsort >order
E 19
I 19
	lorder $(OBJECTS) | tsort > order
E 19

tags:	$(SOURCES)
D 19
	@ctags $(SOURCES)
E 19
I 19
	ctags $(SOURCES)
E 19

I 10
D 16
libI66.a:	yes_66.o
	@rm -f libI66.a
	@cp yes_66.o libI66.a
E 16
I 13

# End of Makefile
D 16
# Below this line is nor normally distributed ...
E 16
I 16
# Below this line normally is not distributed ...
E 16

Makefile:	makefile
	@sed -n -e "1,/End of Makefile/p" makefile > Makefile

tape:	Makefile
	@tar cbf 20 $(TAPE) mkvers.c mkindx.c \
	Makefile READ_ME NEWS Intro.tx Intro $(SOURCES)


# below here is SCCS stuff ...

D 16
backspace.c:	s.backspace.c
E 16
I 16
backspace.c:	SCCS/s.backspace.c
E 16
	@rm -f backspace.c
D 16
	get s.backspace.c
close.c:	s.close.c
E 16
I 16
	get SCCS/s.backspace.c

close.c:	SCCS/s.close.c
E 16
	@rm -f close.c
D 16
	get s.close.c
D 14
dballoc.c:	s.dballoc.c
	@rm -f dballoc.c
	get s.dballoc.c
E 14
dfe.c:	s.dfe.c
E 16
I 16
	get SCCS/s.close.c

dfe.c:	SCCS/s.dfe.c
E 16
	@rm -f dfe.c
D 16
	get s.dfe.c
due.c:	s.due.c
E 16
I 16
	get SCCS/s.dfe.c

due.c:	SCCS/s.due.c
E 16
	@rm -f due.c
D 16
	get s.due.c
endfile.c:	s.endfile.c
E 16
I 16
	get SCCS/s.due.c

endfile.c:	SCCS/s.endfile.c
E 16
	@rm -f endfile.c
D 16
	get s.endfile.c
err.c:	s.err.c
E 16
I 16
	get SCCS/s.endfile.c

err.c:	SCCS/s.err.c
E 16
	@rm -f err.c
D 16
	get s.err.c
fmt.c:	s.fmt.c
E 16
I 16
	get SCCS/s.err.c

fmt.c:	SCCS/s.fmt.c
E 16
	@rm -f fmt.c
D 16
	get s.fmt.c
fmtlib.c:	s.fmtlib.c
E 16
I 16
	get SCCS/s.fmt.c

fmtlib.c:	SCCS/s.fmtlib.c
E 16
	@rm -f fmtlib.c
D 16
	get s.fmtlib.c
iio.c:	s.iio.c
E 16
I 16
	get SCCS/s.fmtlib.c

iio.c:	SCCS/s.iio.c
E 16
	@rm -f iio.c
D 16
	get s.iio.c
inquire.c:	s.inquire.c
E 16
I 16
	get SCCS/s.iio.c

inquire.c:	SCCS/s.inquire.c
E 16
	@rm -f inquire.c
D 16
	get s.inquire.c
lwrite.c:	s.lwrite.c
E 16
I 16
	get SCCS/s.inquire.c

lwrite.c:	SCCS/s.lwrite.c
E 16
	@rm -f lwrite.c
D 16
	get s.lwrite.c
lread.c:	s.lread.c
E 16
I 16
	get SCCS/s.lwrite.c

lread.c:	SCCS/s.lread.c
E 16
	@rm -f lread.c
D 16
	get s.lread.c
dolio.c:	s.dolio.c
E 16
I 16
	get SCCS/s.lread.c

dolio.c:	SCCS/s.dolio.c
E 16
	@rm -f dolio.c
D 16
	get s.dolio.c
open.c:	s.open.c
E 16
I 16
	get SCCS/s.dolio.c

open.c:	SCCS/s.open.c
E 16
	@rm -f open.c
D 16
	get s.open.c
rdfmt.c:	s.rdfmt.c
E 16
I 16
	get SCCS/s.open.c

rdfmt.c:	SCCS/s.rdfmt.c
E 16
	@rm -f rdfmt.c
D 16
	get s.rdfmt.c
rewind.c:	s.rewind.c
E 16
I 16
	get SCCS/s.rdfmt.c

rewind.c:	SCCS/s.rewind.c
E 16
	@rm -f rewind.c
D 16
	get s.rewind.c
sfe.c:	s.sfe.c
E 16
I 16
	get SCCS/s.rewind.c

sfe.c:	SCCS/s.sfe.c
E 16
	@rm -f sfe.c
D 16
	get s.sfe.c
sue.c:	s.sue.c
E 16
I 16
	get SCCS/s.sfe.c

sue.c:	SCCS/s.sue.c
E 16
	@rm -f sue.c
D 16
	get s.sue.c
douio.c:	s.douio.c
E 16
I 16
	get SCCS/s.sue.c

douio.c:	SCCS/s.douio.c
E 16
	@rm -f douio.c
D 16
	get s.douio.c
util.c:	s.util.c
E 16
I 16
	get SCCS/s.douio.c

util.c:	SCCS/s.util.c
E 16
	@rm -f util.c
D 16
	get s.util.c
wrtfmt.c:	s.wrtfmt.c
E 16
I 16
	get SCCS/s.util.c

wrtfmt.c:	SCCS/s.wrtfmt.c
E 16
	@rm -f wrtfmt.c
D 16
	get s.wrtfmt.c
dofio.c:	s.dofio.c
E 16
I 16
	get SCCS/s.wrtfmt.c

dofio.c:	SCCS/s.dofio.c
E 16
	@rm -f dofio.c
D 16
	get s.dofio.c
f_errlist.c:	s.f_errlist.c
E 16
I 16
	get SCCS/s.dofio.c

f_errlist.c:	SCCS/s.f_errlist.c
E 16
	@rm -f f_errlist.c
D 16
	get s.f_errlist.c
yes_66.c:	s.yes_66.c
E 16
I 16
	get SCCS/s.f_errlist.c
D 18

yes_66.c:	SCCS/s.yes_66.c
E 16
	@rm -f yes_66.c
D 16
	get s.yes_66.c
no_66.c:	s.no_66.c
E 16
I 16
	get SCCS/s.yes_66.c

no_66.c:	SCCS/s.no_66.c
E 16
	@rm -f no_66.c
D 16
	get s.no_66.c
f_errno.h:	s.f_errno.h
E 16
I 16
	get SCCS/s.no_66.c
E 18

f_errno.h:	SCCS/s.f_errno.h
E 16
	@rm -f f_errno.h
D 16
	get s.f_errno.h
fiodefs.h:	s.fiodefs.h
E 16
I 16
	get SCCS/s.f_errno.h

fiodefs.h:	SCCS/s.fiodefs.h
E 16
	@rm -f fiodefs.h
D 16
	get s.fiodefs.h
fio.h:	s.fio.h
E 16
I 16
	get SCCS/s.fiodefs.h

fio.h:	SCCS/s.fio.h
E 16
	@rm -f fio.h
D 16
	get s.fio.h
format.h:	s.format.h
E 16
I 16
	get SCCS/s.fio.h

format.h:	SCCS/s.format.h
E 16
	@rm -f format.h
D 16
	get s.format.h
lio.h:	s.lio.h
E 16
I 16
	get SCCS/s.format.h

lio.h:	SCCS/s.lio.h
E 16
	@rm -f lio.h
D 16
	get s.lio.h
E 16
I 16
	get SCCS/s.lio.h

I 17
ioinit.f:	SCCS/s.ioinit.f
	@rm -f ioinit.f
	get SCCS/s.ioinit.f
E 17
E 16
E 13
E 10
E 1

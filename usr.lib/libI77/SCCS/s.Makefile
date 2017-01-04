h56526
s 00139/00183/00023
d D 5.7 87/06/19 10:54:41 bostic 11 9
c new template
e
s 00139/00183/00023
d R 5.7 87/06/19 10:27:12 bostic 10 9
c new template
e
s 00002/00002/00204
d D 5.6 86/10/30 21:49:23 sam 9 8
c remove mkvers on clean; use -f on mv for Version
e
s 00001/00001/00205
d D 5.5 86/04/25 20:10:11 mckusick 8 7
c cleanup clean
e
s 00010/00003/00196
d D 5.4 85/07/30 16:39:58 jerry 7 6
c implement namelist
e
s 00000/00003/00199
d D 5.3 85/07/12 17:52:57 jerry 6 5
c patch f77_abort(), delete no_lg.c for better way to detect -lg.
e
s 00006/00000/00196
d D 5.2 85/06/26 18:19:45 jerry 5 4
c Moved f77_abort() and no_lg.c here from libF77.
e
s 00008/00002/00188
d D 5.1 85/06/07 23:39:29 kre 4 3
c Add copyright
e
s 00036/00012/00154
d D 1.3 85/05/21 20:16:26 libs 3 2
c Split up dfe.c, sfe.c, iio.c so only what is needed is loaded.
e
s 00022/00022/00144
d D 1.2 85/02/19 23:38:14 libs 2 1
c add dependencies for header files.
e
s 00166/00000/00000
d D 1.1 84/06/07 13:53:31 ralph 1 0
c date and time created 84/06/07 13:53:31 by ralph
e
u
U
t
T
I 1
D 4
# Makefile for f77 I/O lib, libI77.a
E 4
#
D 4
# %W% (Berkeley) %G%
E 4
I 4
D 11
# Copyright (c) 1980 Regents of the University of California.
E 11
I 11
# Copyright (c) 1987 Regents of the University of California.
E 11
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 11
#	%W% (Berkeley) %G%
E 11
I 11
#	%W%	(Berkeley)	%G%
E 11
#
I 11
CFLAGS=	-O
FFLAGS=	-O
LIBC=	/lib/libc.a
DEST=	$(DESTDIR)/usr/lib
LIBRARY=	libI77.a
LIBRARY_P=	libI77_p.a
SRCS=	backspace.c c_dfe.c c_iio.c c_sfe.c close.c dofio.c dolio.c douio.c \
	due.c endfile.c err.c f77_abort.c f_errlist.c fmt.c fmtlib.c \
	inquire.c lread.c lwrite.c open.c rdfe.c rdfmt.c rewind.c rfi.c \
	rsfe.c rsli.c rsnmle.c sue.c util.c wdfe.c wfi.c wrtfmt.c wsfe.c \
	wsli.c wsnmle.c
OBJS=	backspace.o c_dfe.o c_iio.o c_sfe.o close.o dofio.o dolio.o douio.o \
	due.o endfile.o err.o f77_abort.o f_errlist.o fmt.o fmtlib.o \
	inquire.o lread.o lwrite.o open.o rdfe.o rdfmt.o rewind.o rfi.o \
	rsfe.o rsli.o rsnmle.o sue.o util.o wdfe.o wfi.o wrtfmt.o wsfe.o \
	wsli.o wsnmle.o
E 11

D 11
# Makefile for f77 I/O lib, libI77.a
E 11
I 11
.c.o:
	${CC} -p ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out profiled/$*.o
	${CC} ${CFLAGS} -c $*.c
	-ld -x -r $*.o
	mv a.out $*.o
E 11
E 4

D 11
CFLAGS	      = -O
E 11
I 11
all: ${LIBRARY} ${LIBRARY_P} libI66.o
E 11

D 11
DEST	      = $(DESTDIR)/usr/lib
E 11
I 11
${LIBRARY}: ${OBJS} Version
	@echo "Loading ${LIBRARY} ... "
	@ar cru ${LIBRARY} ${OBJS} Version
	@ranlib ${LIBRARY}
E 11

D 11
DESTDIR	      =
E 11
I 11
${LIBRARY_P}: ${OBJS} Version
	@echo "Loading ${LIBRARY_P} ... "
	@cd profiled; ar cru ../${LIBRARY_P} ${OBJS} Version
	@ranlib ${LIBRARY_P}
E 11

D 11
EXTHDRS	      =
E 11
I 11
Version: ${SRCS} mkvers
	./mkvers ${LIBRARY} ${SRCS} > Version.c
	$(CC) -c Version.c -o Version
	@rm -f profiled/Version
	ln Version profiled/Version
E 11

D 11
FFLAGS	      = -O
E 11
I 11
mkvers: mkvers.c
	${CC} mkvers.c -o $@
E 11

D 11
HDRS	      = f_errno.h \
		fio.h \
		fiodefs.h \
		format.h \
D 7
		lio.h
E 7
I 7
		lio.h \
		nmlio.h
E 11
I 11
f_errlist.o: f_errlist.c
	${CC} ${CFLAGS} -c f_errlist.c
	@rm -f profiled/f_errlist.o
	ln f_errlist.o profiled/f_errlist.o
E 11
E 7

D 11
LIBRARY	      = libI77.a
E 11
I 11
clean: FRC
	rm -f ${OBJS} profiled/*.o core ${LIBRARY} ${LIBRARY_P} libI66.o mkvers
E 11

D 11
LIBRARY_P     = libI77_p.a
E 11
I 11
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 11

D 11
MAKEFILE      = Makefile
E 11
I 11
install: FRC
	install -o bin -g bin -m 644 ${LIBRARY} ${DEST}/${LIBRARY}
	ranlib ${DEST}/${LIBRARY}
	install -o bin -g bin -m 644 ${LIBRARY_P} ${DEST}/${LIBRARY_P}
	ranlib ${DEST}/${LIBRARY_P}
	install -c -o bin -g bin -m 644 libI66.o ${DEST}/libI66.a
E 11

D 11
OBJS	      = backspace.o \
I 3
		c_dfe.o \
		c_iio.o \
		c_sfe.o \
E 3
		close.o \
D 3
		dfe.o \
E 3
		dofio.o \
		dolio.o \
		douio.o \
		due.o \
		endfile.o \
		err.o \
I 5
		f77_abort.o \
E 5
		f_errlist.o \
		fmt.o \
		fmtlib.o \
D 3
		iio.o \
E 3
		inquire.o \
		lread.o \
		lwrite.o \
I 5
D 6
		no_lg.o \
E 6
E 5
		open.o \
I 3
		rdfe.o \
E 3
		rdfmt.o \
		rewind.o \
D 3
		sfe.o \
E 3
I 3
		rfi.o \
		rsfe.o \
		rsli.o \
I 7
		rsnmle.o \
E 7
E 3
		sue.o \
		util.o \
D 3
		wrtfmt.o
E 3
I 3
		wdfe.o \
		wfi.o \
		wrtfmt.o \
		wsfe.o \
D 7
		wsli.o
E 7
I 7
		wsli.o \
		wsnmle.o
E 11
I 11
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 11
E 7
E 3

D 11
OLDDIR	      = $(DESTDIR)/usr/old/lib

PRINT	      = pr

SRCS	      = backspace.c \
I 3
		c_dfe.c \
		c_iio.c \
		c_sfe.c \
E 3
		close.c \
D 3
		dfe.c \
E 3
		dofio.c \
		dolio.c \
		douio.c \
		due.c \
		endfile.c \
		err.c \
I 5
		f77_abort.c \
E 5
		f_errlist.c \
		fmt.c \
		fmtlib.c \
D 3
		iio.c \
E 3
		inquire.c \
		lread.c \
		lwrite.c \
I 5
D 6
		no_lg.c \
E 6
E 5
		open.c \
I 3
		rdfe.c \
E 3
		rdfmt.c \
		rewind.c \
D 3
		sfe.c \
E 3
I 3
		rfi.c \
		rsfe.c \
		rsli.c \
I 7
		rsnmle.c \
E 7
E 3
		sue.c \
		util.c \
D 3
		wrtfmt.c
E 3
I 3
		wdfe.c \
		wfi.c \
		wrtfmt.c \
		wsfe.c \
D 7
		wsli.c
E 7
I 7
		wsli.c \
		wsnmle.c
E 11
I 11
tags: FRC
	ctags ${SRCS}
E 11
E 7
E 3

D 11
all:		$(LIBRARY) $(LIBRARY_P) libI66.o
E 11
I 11
extract: FRC
	@ar xo ${DEST}/${LIBRARY}; rm -f __.SYMDEF
	@cd profiled; -ar xo ${DEST}/${LIBRARY_P}; rm -f __.SYMDEF
E 11

D 11
$(LIBRARY):	$(OBJS) Version
		@echo -n "Loading $(LIBRARY) ... "
		@ar cru $(LIBRARY) $(OBJS) Version
		@ranlib $(LIBRARY)
		@echo "done"
E 11
I 11
update ${DEST}/${LIBRARY}: FRC
	@-ar xo ${DEST}/${LIBRARY}
	@cd profiled; -ar xo ${DEST}/${LIBRARY_P}
	@make DEST=${DEST} all install clean
E 11

D 11
$(LIBRARY_P):	$(OBJS) Version
		@echo -n "Loading $(LIBRARY_P) ... "
		@cd profiled; ar cru ../$(LIBRARY_P) $(OBJS) Version
		@ranlib $(LIBRARY_P)
		@echo "done"
E 11
I 11
FRC:
E 11

D 11
Version:	$(SRCS) mkvers
		@rm -f Version.c
		./mkvers $(LIBRARY) $(SRCS) > Version.c
		$(CC) -c Version.c
D 9
		mv Version.o Version
E 9
I 9
		mv -f Version.o Version
E 9
		@rm -f profiled/Version
		ln Version profiled/Version
E 11
I 11
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 11

D 11
mkvers:		mkvers.c
		@$(CC) mkvers.c -o mkvers
E 11
I 11
backspace.o: backspace.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
backspace.o: /usr/include/errno.h
c_dfe.o: c_dfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
c_dfe.o: /usr/include/errno.h
c_iio.o: c_iio.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
c_iio.o: /usr/include/errno.h lio.h
c_sfe.o: c_sfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
c_sfe.o: /usr/include/errno.h
close.o: close.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
close.o: /usr/include/errno.h
dofio.o: dofio.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
dofio.o: /usr/include/errno.h format.h
dolio.o: dolio.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
dolio.o: /usr/include/errno.h lio.h
douio.o: douio.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
douio.o: /usr/include/errno.h
due.o: due.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
due.o: /usr/include/errno.h
endfile.o: endfile.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
endfile.o: /usr/include/errno.h
err.o: err.c /usr/include/sys/types.h /usr/include/sys/stat.h
err.o: /usr/include/signal.h fio.h fiodefs.h /usr/include/stdio.h f_errno.h
err.o: /usr/include/errno.h
f77_abort.o: f77_abort.c /usr/include/signal.h fio.h fiodefs.h
f77_abort.o: /usr/include/stdio.h f_errno.h /usr/include/errno.h
f_errlist.o: f_errlist.c
fmt.o: fmt.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
fmt.o: /usr/include/errno.h format.h
fmtlib.o: fmtlib.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
fmtlib.o: /usr/include/errno.h
inquire.o: inquire.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
inquire.o: /usr/include/errno.h
lread.o: lread.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
lread.o: /usr/include/errno.h lio.h
lwrite.o: lwrite.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
lwrite.o: /usr/include/errno.h lio.h
open.o: open.c /usr/include/sys/types.h /usr/include/sys/stat.h
open.o: /usr/include/errno.h fio.h fiodefs.h /usr/include/stdio.h f_errno.h
open.o: /usr/include/errno.h
rdfe.o: rdfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rdfe.o: /usr/include/errno.h
rdfmt.o: rdfmt.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rdfmt.o: /usr/include/errno.h format.h
rewind.o: rewind.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rewind.o: /usr/include/errno.h
rfi.o: rfi.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rfi.o: /usr/include/errno.h
rsfe.o: rsfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rsfe.o: /usr/include/errno.h
rsli.o: rsli.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rsli.o: /usr/include/errno.h lio.h
rsnmle.o: rsnmle.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
rsnmle.o: /usr/include/errno.h lio.h nmlio.h /usr/include/ctype.h
sue.o: sue.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
sue.o: /usr/include/errno.h
util.o: util.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
util.o: /usr/include/errno.h
wdfe.o: wdfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wdfe.o: /usr/include/errno.h
wfi.o: wfi.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wfi.o: /usr/include/errno.h
wrtfmt.o: wrtfmt.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wrtfmt.o: /usr/include/errno.h format.h
wsfe.o: wsfe.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wsfe.o: /usr/include/errno.h
wsli.o: wsli.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wsli.o: /usr/include/errno.h lio.h
wsnmle.o: wsnmle.c fio.h fiodefs.h /usr/include/stdio.h f_errno.h
wsnmle.o: /usr/include/errno.h lio.h nmlio.h /usr/include/strings.h
E 11

D 8
clean:;		@rm -f $(OBJS) profiled/*.o $(LIBRARY) $(LIBRARY_P)
E 8
I 8
D 9
clean:;		@rm -f $(OBJS) profiled/*.o $(LIBRARY) $(LIBRARY_P) libI66.o
E 9
I 9
D 11
clean:;		@rm -f $(OBJS) profiled/*.o $(LIBRARY) $(LIBRARY_P) libI66.o mkvers
E 9
E 8

depend:;	@echo Construct dependencies manually

extract:;	@ar xo $(DEST)/$(LIBRARY); rm -f __.SYMDEF
		@cd profiled; -ar xo $(DEST)/$(LIBRARY_P); rm -f __.SYMDEF

index:;		@ctags -wx $(HDRS) $(SRCS)

install:	$(LIBRARY) $(LIBRARY_P) libI66.o
		install -m 644 $(LIBRARY) $(DEST)/$(LIBRARY)
		ranlib $(DEST)/$(LIBRARY)
		install -m 644 $(LIBRARY_P) $(DEST)/$(LIBRARY_P)
		ranlib $(DEST)/$(LIBRARY_P)
		install -m 644 -c libI66.o $(DEST)/libI66.a

library:        $(LIBRARY) $(LIBRARY_P)

print:;		@$(PRINT) $(HDRS) $(SRCS)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)

update:         $(DEST)/$(LIBRARY)

$(DEST)/$(LIBRARY): $(SRCS) $(HDRS) $(EXTHDRS)
		@-ar xo $(DEST)/$(LIBRARY)
		@cd profiled; -ar xo $(DEST)/$(LIBRARY_P)
		@make -f $(MAKEFILE) DEST=$(DEST) install clean

f_errlist.o:	f_errlist.c
		$(CC) $(CFLAGS) -c f_errlist.c
		@rm -f profiled/f_errlist.o
		ln f_errlist.o profiled/f_errlist.o
.c.o:
		$(CC) -p $(CFLAGS) -c $*.c
		-ld -x -r $*.o
		mv a.out profiled/$*.o
		$(CC) $(CFLAGS) -c $*.c
		-ld -x -r $*.o
		mv a.out $*.o

D 2
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
E 2
I 2
backspace.o:	fio.h f_errno.h fiodefs.h backspace.c
D 3
dfe.o:		fio.h f_errno.h fiodefs.h dfe.c
E 3
I 3
c_dfe.o:	fio.h f_errno.h fiodefs.h c_dfe.c
rdfe.o:		fio.h f_errno.h fiodefs.h rdfe.c
wdfe.o:		fio.h f_errno.h fiodefs.h wdfe.c
E 3
due.o:		fio.h f_errno.h fiodefs.h due.c
D 3
iio.o:		fio.h f_errno.h fiodefs.h lio.h iio.c
E 3
I 3
rfi.o:		fio.h f_errno.h fiodefs.h rfi.c
wfi.o:		fio.h f_errno.h fiodefs.h wfi.c
rsli.o:		fio.h f_errno.h fiodefs.h lio.h rsli.c
wsli.o:		fio.h f_errno.h fiodefs.h lio.h wsli.c
c_iio.o:	fio.h f_errno.h fiodefs.h lio.h c_iio.c
E 3
inquire.o:	fio.h f_errno.h fiodefs.h inquire.c
rewind.o:	fio.h f_errno.h fiodefs.h rewind.c
rdfmt.o:	fio.h f_errno.h fiodefs.h format.h rdfmt.c
sue.o:		fio.h f_errno.h fiodefs.h sue.c
douio.o:	fio.h f_errno.h fiodefs.h douio.c
D 3
sfe.o:		fio.h f_errno.h fiodefs.h sfe.c
E 3
I 3
rsfe.o:		fio.h f_errno.h fiodefs.h rsfe.c
wsfe.o:		fio.h f_errno.h fiodefs.h wsfe.c
c_sfe.o:	fio.h f_errno.h fiodefs.h c_sfe.c
E 3
fmt.o:		fio.h f_errno.h fiodefs.h format.h fmt.c
dofio.o:	fio.h f_errno.h fiodefs.h format.h dofio.c
lwrite.o:	fio.h f_errno.h fiodefs.h lio.h lwrite.c
lread.o:	fio.h f_errno.h fiodefs.h lio.h lread.c
dolio.o:	fio.h f_errno.h fiodefs.h lio.h dolio.c
open.o:		fio.h f_errno.h fiodefs.h open.c
close.o:	fio.h f_errno.h fiodefs.h close.c
util.o:		fio.h f_errno.h fiodefs.h util.c
endfile.o:	fio.h f_errno.h fiodefs.h endfile.c
wrtfmt.o:	fio.h f_errno.h fiodefs.h format.h wrtfmt.c
D 3
err.o:		fiodefs.h f_errno.h err.c
E 3
I 3
err.o:		fio.h f_errno.h fiodefs.h err.c
E 3
fmtlib.o:	fio.h f_errno.h fiodefs.h fmtlib.c
I 5
f77_abort.o:	fio.h f_errno.h fiodefs.h f77_abort.c
I 7
rsnmle.o:	fio.h f_errno.h fiodefs.h lio.h nmlio.h rsnmle.c
wsnmle.o:	fio.h f_errno.h fiodefs.h lio.h nmlio.h wsnmle.c
E 11
I 11
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 11
E 7
D 6
no_lg.o:	no_lg.c
E 6
E 5
E 2
E 1

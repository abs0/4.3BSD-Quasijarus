h48480
s 00163/00310/00021
d D 4.10 88/05/05 11:07:31 rick 10 9
c check in the correct version
e
s 00310/00159/00021
d D 4.9 88/04/05 12:30:56 rick 9 8
c 
e
s 00001/00001/00179
d D 4.8 88/02/24 21:37:40 rick 8 7
c another typo
e
s 00001/00001/00179
d D 4.7 88/02/24 20:58:40 rick 7 6
c typo
e
s 00064/00043/00116
d D 4.6 88/02/24 20:44:25 rick 6 5
c add p+& for parallel makes
e
s 00151/00009/00008
d D 4.5 87/06/18 23:56:32 bostic 5 4
c new template
e
s 00001/00001/00016
d D 4.4 86/02/12 17:33:52 bloom 4 3
c add new dialer
e
s 00004/00002/00013
d D 4.3 86/01/13 14:07:14 bloom 3 2
c add new dialers
e
s 00002/00002/00013
d D 4.2 85/04/03 11:07:20 ralph 2 1
c added DEC DF112 and PENRIL dialers
e
s 00015/00000/00000
d D 4.1 85/01/22 13:04:13 ralph 1 0
c date and time created 85/01/22 13:04:13 by ralph
e
u
U
t
T
I 9
D 10
#	@(#)Makefile	5.16	4/5/88
E 10
E 9
I 1
D 5
#	%M%	%I%	%E%

D 3
CFLAGS= -O
E 3
I 3
DEBUG=
CFLAGS= -O  ${DEBUG}
E 3

D 2
OBJS= bsdtcp.o df2.o dk.o dn.o hys.o hysq.o mic.o nov.o pnet.o rvmacs.o \
	sy.o unet.o va212.o va811.o va820.o vad.o vent.o vmacs.o
E 2
I 2
OBJS= bsdtcp.o df2.o df12.o dk.o dn.o hys.o hysq.o mic.o nov.o pen.o pnet.o \
E 5
I 5
#
D 9
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 9
I 9
D 10
# This version expects the 4.2BSD directory reading routines to
# located in libc.a.  If they aren't, augment LIBS.  Also, LIBS
# can be set to reference other object modules and libraries needed
# by uucico, such as -lunet (needed when UNET is defined).
E 10
I 10
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 10
E 9
#
D 9
#	%W%	(Berkeley)	%G%
E 9
I 9
D 10
# Common object files are assembled into a library {uulib.a}
E 10
I 10
#	%W%	(Berkeley)	%G%
E 10
E 9
#
D 9
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	bsdtcp.c df2.c df12.c dk.c dn.c hys.c hysq.c mic.c nov.c pen.c pnet.c \
	rvmacs.c sy.c unet.c va212.c va811.c va820.c vad.c vent.c vmacs.c \
	hys24.c cds224.c att2224.c
OBJS=	bsdtcp.o df2.o df12.o dk.o dn.o hys.o hysq.o mic.o nov.o pen.o pnet.o \
E 5
D 3
	rvmacs.o sy.o unet.o va212.o va811.o va820.o vad.o vent.o vmacs.o
E 3
I 3
	rvmacs.o sy.o unet.o va212.o va811.o va820.o vad.o vent.o vmacs.o \
D 4
	hys24.o cds224.o
E 4
I 4
	hys24.o cds224.o att2224.o
E 9
I 9
D 10
ALL=	uucico uucp uux uuxqt uulog uuclean uuname uupoll uusnap \
	uuencode uudecode uusend uucpd uuq acucntrl
# Common object files placed in uulib.a
COMMON=	anlwrk.o anyread.o cfgets.o chkpth.o \
	cpmv.o expfile.o gename.o getargs.o getprm.o \
	getpwinfo.o gnxseq.o lastpart.o logent.o mailst.o \
	prefix.o setline.o subdir.o sysacct.o systat.o \
	ulockf.o uucpname.o versys.o xqt.o uucpdefs.o
SRCS=	${USRCS} ${OSRCS} ${LSRCS}
USRCS=	cico.c cntrl.c conn.c condevs.c gnsys.c pk0.c chksum.c pk1.c tio.c \
	fio.c gio.c imsg.c 
OSRCS=	uuclean.c uucp.c uulog.c uuname.c uupoll.c \
	uusend.c uusnap.c uux.c uuxqt.c uuq.c acucntrl.c
LSRCS=	anlwrk.c anyread.c cfgets.c chkpth.c \
	cpmv.c expfile.c gename.c getargs.c getprm.c getpwinfo.c \
	gnxseq.c lastpart.c logent.c mailst.c prefix.c \
	setline.c subdir.c sysacct.c systat.c ulockf.c \
	uucpdefs.c uucpname.c versys.c xqt.c

#These might be useful on non 4.3bsd systems.
MISC= htonl.c ioctl.c index.c mkdir.c strpbrk.c 

DESTDIR=

# Define P=& if your make supports parallelism (e.g. Sequent)
E 10
I 10
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	bsdtcp.c df2.c df12.c dk.c dn.c hys.c hysq.c mic.c nov.c pen.c pnet.c \
	rvmacs.c sy.c unet.c va212.c va811.c va820.c vad.c vent.c vmacs.c \
	hys24.c cds224.c att2224.c
OBJS=	bsdtcp.o df2.o df12.o dk.o dn.o hys.o hysq.o mic.o nov.o pen.o pnet.o \
	rvmacs.o sy.o unet.o va212.o va811.o va820.o vad.o vent.o vmacs.o \
	hys24.o cds224.o att2224.o
E 10
E 9
I 6
D 7
p+
E 7
I 7
D 8
P=+
E 8
I 8
P=
E 8
E 7
E 6
E 4
E 3
E 2

I 5
D 9
all: aculib.a
E 9
I 9
D 10
OWNER=	uucp
GROUP=	daemon
CFLAGS=	-O
LDFLAGS=
LINTFLAGS= -chbap
LIBS= 
LIBDIR=	${DESTDIR}/usr/lib/uucp
BIN=	${DESTDIR}/usr/bin
ETC=	${DESTDIR}/etc
PUBDIR=	${DESTDIR}/usr/spool/uucppublic
SPOOL=	${DESTDIR}/usr/spool/uucp
XQTDIR=	${SPOOL}/XTMP
CORRUPT= ${SPOOL}/CORRUPT
AUDIT=	${SPOOL}/AUDIT
LCK= ${SPOOL}/LCK
LOG= ${SPOOL}/LOG
STST=	${SPOOL}/STST
# The six subdirs {not counting XTMP}.
HOSTNAME=`uuname -l | sed 's/\(.......\).*/\1/'`
SUBDIRS=C. D.${HOSTNAME}X D.${HOSTNAME} D. X. TM.
E 10
I 10
all: aculib.a
E 10
E 9

E 5
D 6
aculib.a: ${OBJS}
E 6
I 6
D 9
aculib.a: $(P) ${OBJS}
E 6
	ar cr aculib.a ${OBJS}
	-ranlib aculib.a 2>&1 | sed '/no symbol table/d'
E 9
I 9
D 10
all:	$(P) ${ALL} 
E 10
I 10
aculib.a: $(P) ${OBJS}
	ar cr aculib.a ${OBJS}
	-ranlib aculib.a 2>&1 | sed '/no symbol table/d'
E 10
E 9

D 5
${OBJS}: ../uucp.h ../condevs.h
E 5
I 5
D 9
clean: FRC
	rm -f ${OBJS} core aculib.a
E 9
I 9
D 10
lint: ${SRCS}
	lint ${LINTFLAGS} ${USRCS} ${LSRCS}
	-for i in ${OSRCS} ; do \
		lint ${LINTFLAGS} $$i ${LSRCS} ;\
	done
print:	$(SRCS)
	vgrind $?
	vgrind -x index
	touch print
E 10
I 10
clean: FRC
	rm -f ${OBJS} core aculib.a
E 10
E 9
E 5

I 9
D 10
uucp:	$(P) uucp.o uulib.a
	${CC} -o uucp ${LDFLAGS} uucp.o uulib.a ${LIBS}

uux:	$(P) uux.o uulib.a
	${CC} -o uux ${LDFLAGS} uux.o uulib.a ${LIBS}

uuxqt:	$(P) uuxqt.o uulib.a
	${CC} -o uuxqt ${LDFLAGS} uuxqt.o uulib.a ${LIBS}

uucico:	$(P) cico.o cntrl.o conn.o condevs.o gnsys.o pk0.o chksum.o pk1.o \
	tio.o fio.o gio.o imsg.o uulib.a $(P) aculib/aculib.a
	${CC} -o uucico ${LDFLAGS} cico.o cntrl.o conn.o condevs.o gnsys.o \
	pk0.o chksum.o pk1.o tio.o fio.o gio.o imsg.o \
	uulib.a aculib/aculib.a ${LIBS}

uulog:	$(P) uulog.o uulib.a
	${CC} -o uulog ${LDFLAGS} uulog.o uulib.a ${LIBS}

uuclean: $(P) uuclean.o uulib.a
	${CC} -o uuclean ${LDFLAGS} uuclean.o uulib.a ${LIBS}

uuname:	$(P) uuname.o uulib.a
	${CC} -o uuname ${LDFLAGS} uuname.o uulib.a ${LIBS}

uupoll:	$(P) uupoll.o uulib.a
	${CC} -o uupoll ${LDFLAGS} uupoll.o uulib.a ${LIBS}

uusnap:	uusnap.o
	${CC} -o uusnap ${LDFLAGS} uusnap.o ${LIBS}

uuencode: uuencode.o
	${CC} -o uuencode ${LDFLAGS} uuencode.o ${LIBS}

uudecode: uudecode.o
	${CC} -o uudecode ${LDFLAGS} uudecode.o ${LIBS}

uusend: uusend.o
	${CC} -o uusend ${LDFLAGS} uusend.o uulib.a ${LIBS}

uucpd: uucpd.o uucp.h
	${CC} -o uucpd ${LDFLAGS} uucpd.o ${LIBS}

uuq: $(P) uuq.o uulib.a
	${CC} -o uuq ${LDFLAGS} uuq.o uulib.a ${LIBS}

acucntrl: acucntrl.o
	${CC} -o acucntrl ${LDFLAGS} acucntrl.o ${LIBS}

# Note: mode 700 on ${LIBDIR} would be safer.
# Also,  L.sys etc should be 600.

mkdirs:
	-for i in ${LIBDIR} ${SPOOL} ${PUBDIR} ${XQTDIR} ${CORRUPT} \
		${AUDIT} ${LCK} ${LOG} ${STST} ; do \
		rm -f $$i ; mkdir $$i ; \
		chmod 755 $$i; /etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
	done
	chmod 777 ${PUBDIR} ${LCK}
	-cd ${LOG}; for i in uucico uux uuxqt uucp xferstats; do\
		rm -f $$i ; mkdir $$i ; \
		chmod 755 $$i; /etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
	done
	-cd ${SPOOL}; for i in ${SUBDIRS} ; do \
		mkdir $$i; \
		/etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i; chmod 755 $$i; \
	done

# The lorder...tsort below is for systems w/o ranlib
# But it doesnt hurt to use it. Ignore the spurious "cycle" messages
uulib.a: $(P) ${COMMON}
	rm -f $@
	ar cr $@ `lorder ${COMMON} | tsort`
	ranlib $@

aculib/aculib.a:
	cd aculib; make ${MFLAGS} "CFLAGS=${CFLAGS}" "P=${P}"

install: ${ALL}
	/etc/chown ${OWNER} ${LIBDIR}
	chgrp ${GROUP} ${LIBDIR}
	chmod 755 ${LIBDIR}
	for i in uucico uuclean; do \
		install -s -m 6111 -o ${OWNER} -g ${GROUP} $$i ${LIBDIR} ;\
	done
	for i in uucp uux uulog uuname uusnap uupoll uuq; do \
		install -s -m 6111 -o ${OWNER} -g ${GROUP} $$i ${BIN} ;\
	done
	install -s -m 6110 -o ${OWNER} -g ${GROUP} uuxqt ${LIBDIR}
	install -s -m 6110 -o root -g ${GROUP} acucntrl ${LIBDIR}
	install -s -m 500 -o uucp uucpd ${ETC}
	@echo Dont forget to fork off /etc/uucpd in /etc/rc.local
	@echo if you are not running /etc/inetd
	install -s -m 755 -o bin -g bin uusend ${BIN}
	install -s -m 755 -o bin -g bin uuencode ${BIN}
	install -s -m 755 -o bin -g bin uudecode ${BIN}
	rm -f ${BIN}/ruusend
	ln ${BIN}/uusend ${BIN}/ruusend

clean:
	rm -f *.o ${ALL} uulib.a
	cd aculib; make ${MFLAGS} clean

E 10
E 9
D 5
clean:
	rm -f *.o core errs  aculib.a
E 5
I 5
depend: FRC
I 9
D 10
	cd aculib; make ${MFLAGS} depend
E 10
E 9
	mkdep ${CFLAGS} ${SRCS}

I 10
lint: FRC
	lint ${CFLAGS} ${SRCS}

E 10
D 9
lint: FRC
	lint ${CFLAGS} ${SRCS}

E 9
tags: FRC
	ctags ${SRCS}

I 10
install:
E 10
D 9
install:
E 9
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 9
bsdtcp.o: bsdtcp.c ../condevs.h ../uucp.h /usr/include/stdio.h
bsdtcp.o: /usr/include/sysexits.h /usr/include/sys/types.h
bsdtcp.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
bsdtcp.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
I 6
bsdtcp.o: /usr/include/signal.h /usr/include/machine/trap.h
bsdtcp.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
bsdtcp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
bsdtcp.o: /usr/include/netdb.h /usr/include/sys/socket.h
bsdtcp.o: /usr/include/netinet/in.h
df2.o: df2.c ../condevs.h ../uucp.h /usr/include/stdio.h
df2.o: /usr/include/sysexits.h /usr/include/sys/types.h
df2.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
df2.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
df2.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
df2.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
df2.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
df2.o: /usr/include/sys/ttydev.h
E 6
df12.o: df12.c ../condevs.h ../uucp.h /usr/include/stdio.h
df12.o: /usr/include/sysexits.h /usr/include/sys/types.h
df12.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
df12.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
df12.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
df12.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
df12.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
df12.o: /usr/include/sys/ttydev.h
E 6
dk.o: dk.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sysexits.h
dk.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/errno.h
D 6
dk.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/sgtty.h
dk.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
I 6
dk.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
dk.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
dk.o: /usr/include/sys/ttydev.h
dn.o: dn.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sysexits.h
dn.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/errno.h
D 6
dn.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/sgtty.h
dn.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
I 6
dn.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
dn.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
dn.o: /usr/include/sys/ttydev.h
hys.o: hys.c ../condevs.h ../uucp.h /usr/include/stdio.h
hys.o: /usr/include/sysexits.h /usr/include/sys/types.h
hys.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
hys.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
hys.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
hys.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
hys.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hys.o: /usr/include/sys/ttydev.h
E 6
hysq.o: hysq.c ../condevs.h ../uucp.h /usr/include/stdio.h
hysq.o: /usr/include/sysexits.h /usr/include/sys/types.h
hysq.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
hysq.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
hysq.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
hysq.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
hysq.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hysq.o: /usr/include/sys/ttydev.h
E 6
mic.o: mic.c ../condevs.h ../uucp.h /usr/include/stdio.h
mic.o: /usr/include/sysexits.h /usr/include/sys/types.h
mic.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
mic.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
mic.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
mic.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
mic.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
mic.o: /usr/include/sys/ttydev.h
E 6
nov.o: nov.c ../condevs.h ../uucp.h /usr/include/stdio.h
nov.o: /usr/include/sysexits.h /usr/include/sys/types.h
nov.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
nov.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
nov.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
nov.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
nov.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
nov.o: /usr/include/sys/ttydev.h
E 6
pen.o: pen.c ../condevs.h ../uucp.h /usr/include/stdio.h
pen.o: /usr/include/sysexits.h /usr/include/sys/types.h
pen.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
pen.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
pen.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
pen.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
pen.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
pen.o: /usr/include/sys/ttydev.h
E 6
pnet.o: pnet.c ../condevs.h ../uucp.h /usr/include/stdio.h
pnet.o: /usr/include/sysexits.h /usr/include/sys/types.h
pnet.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
pnet.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
pnet.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
pnet.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
pnet.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
pnet.o: /usr/include/sys/ttydev.h
E 6
rvmacs.o: rvmacs.c ../condevs.h ../uucp.h /usr/include/stdio.h
rvmacs.o: /usr/include/sysexits.h /usr/include/sys/types.h
rvmacs.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
rvmacs.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
I 6
rvmacs.o: /usr/include/signal.h /usr/include/machine/trap.h
rvmacs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
rvmacs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
sy.o: sy.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sysexits.h
sy.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/errno.h
D 6
sy.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/sgtty.h
sy.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
I 6
sy.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
sy.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
E 6
sy.o: /usr/include/sys/ttydev.h
unet.o: unet.c ../condevs.h ../uucp.h /usr/include/stdio.h
unet.o: /usr/include/sysexits.h /usr/include/sys/types.h
unet.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
unet.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
unet.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
unet.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
unet.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
unet.o: /usr/include/sys/ttydev.h
E 6
va212.o: va212.c ../condevs.h ../uucp.h /usr/include/stdio.h
va212.o: /usr/include/sysexits.h /usr/include/sys/types.h
va212.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
va212.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
va212.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
va212.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va212.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va212.o: /usr/include/sys/ttydev.h
E 6
va811.o: va811.c ../condevs.h ../uucp.h /usr/include/stdio.h
va811.o: /usr/include/sysexits.h /usr/include/sys/types.h
va811.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
va811.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
va811.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
va811.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va811.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va811.o: /usr/include/sys/ttydev.h
E 6
va820.o: va820.c ../condevs.h ../uucp.h /usr/include/stdio.h
va820.o: /usr/include/sysexits.h /usr/include/sys/types.h
va820.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
va820.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
va820.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
va820.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va820.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va820.o: /usr/include/sys/ttydev.h
E 6
vad.o: vad.c ../condevs.h ../uucp.h /usr/include/stdio.h
vad.o: /usr/include/sysexits.h /usr/include/sys/types.h
vad.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
vad.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
vad.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
vad.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
vad.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vad.o: /usr/include/sys/ttydev.h
E 6
vent.o: vent.c ../condevs.h ../uucp.h /usr/include/stdio.h
vent.o: /usr/include/sysexits.h /usr/include/sys/types.h
vent.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
vent.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
vent.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
vent.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
vent.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vent.o: /usr/include/sys/ttydev.h
E 6
vmacs.o: vmacs.c ../condevs.h ../uucp.h /usr/include/stdio.h
vmacs.o: /usr/include/sysexits.h /usr/include/sys/types.h
vmacs.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
vmacs.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
vmacs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
vmacs.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
vmacs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vmacs.o: /usr/include/sys/ttydev.h
E 6
hys24.o: hys24.c ../condevs.h ../uucp.h /usr/include/stdio.h
hys24.o: /usr/include/sysexits.h /usr/include/sys/types.h
hys24.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
hys24.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
hys24.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 6
I 6
hys24.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
hys24.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hys24.o: /usr/include/sys/ttydev.h
E 6
cds224.o: cds224.c ../condevs.h ../uucp.h /usr/include/stdio.h
cds224.o: /usr/include/sysexits.h /usr/include/sys/types.h
cds224.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
cds224.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
I 6
cds224.o: /usr/include/signal.h /usr/include/machine/trap.h
cds224.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
cds224.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
att2224.o: att2224.c ../condevs.h ../uucp.h /usr/include/stdio.h
att2224.o: /usr/include/sysexits.h /usr/include/sys/types.h
att2224.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
D 6
att2224.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
I 6
att2224.o: /usr/include/signal.h /usr/include/machine/trap.h
att2224.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 6
att2224.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 9
I 9
D 10
cico.o: cico.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
cico.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
cico.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/sgtty.h
cico.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
cico.o: /usr/include/sys/ttydev.h /usr/include/netdb.h
cico.o: /usr/include/netinet/in.h /usr/include/sys/socket.h
cico.o: /usr/include/sys/stat.h uust.h uusub.h
cntrl.o: cntrl.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
cntrl.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
cntrl.o: /usr/include/sys/stat.h uust.h
conn.o: conn.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
conn.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
conn.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/ctype.h
conn.o: /usr/include/errno.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
conn.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
conn.o: /usr/include/sys/time.h /usr/include/time.h
condevs.o: condevs.c condevs.h uucp.h /usr/include/stdio.h
condevs.o: /usr/include/sysexits.h /usr/include/sys/types.h
condevs.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
condevs.o: /usr/include/signal.h /usr/include/machine/trap.h
condevs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
condevs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
condevs.o: /usr/include/sys/time.h /usr/include/time.h
gnsys.o: gnsys.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gnsys.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
gnsys.o: /usr/include/sys/dir.h
pk0.o: pk0.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
pk0.o: /usr/include/sys/types.h /usr/include/sys/timeb.h pk.h
chksum.o: chksum.c
pk1.o: pk1.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
pk1.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
pk1.o: /usr/include/sys/timeb.h pk.h /usr/include/setjmp.h
pk1.o: /usr/include/sys/time.h /usr/include/time.h
tio.o: tio.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
tio.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
tio.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/sys/stat.h
fio.o: fio.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
fio.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/signal.h
fio.o: /usr/include/machine/trap.h /usr/include/sgtty.h
fio.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
fio.o: /usr/include/sys/ttydev.h /usr/include/setjmp.h
gio.o: gio.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gio.o: /usr/include/sys/types.h /usr/include/sys/timeb.h pk.h
gio.o: /usr/include/setjmp.h
imsg.o: imsg.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
imsg.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/ctype.h
uuclean.o: uuclean.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
uuclean.o: /usr/include/stdio.h /usr/include/sysexits.h
uuclean.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/pwd.h
uuclean.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
uucp.o: uucp.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucp.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uucp.o: /usr/include/sys/stat.h uust.h
uulog.o: uulog.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uulog.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuname.o: uuname.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuname.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuname.o: /usr/include/signal.h /usr/include/machine/trap.h
uupoll.o: uupoll.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uupoll.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uusend.o: uusend.c /usr/include/stdio.h /usr/include/pwd.h
uusend.o: /usr/include/sys/types.h /usr/include/sys/stat.h
uusnap.o: uusnap.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uusnap.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uusnap.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/ctype.h
uux.o: uux.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uux.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuxqt.o: uuxqt.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuxqt.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuxqt.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/signal.h
uuxqt.o: /usr/include/machine/trap.h
uuq.o: uuq.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuq.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/stdio.h
uuq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
acucntrl.o: acucntrl.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
acucntrl.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
acucntrl.o: /usr/include/sys/buf.h /usr/include/signal.h
acucntrl.o: /usr/include/machine/trap.h /usr/include/sys/conf.h
acucntrl.o: /sys/vaxuba/ubavar.h /usr/include/sys/stat.h /usr/include/nlist.h
acucntrl.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
acucntrl.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
acucntrl.o: /usr/include/utmp.h /usr/include/pwd.h /usr/include/stdio.h
acucntrl.o: /usr/include/sys/file.h
anlwrk.o: anlwrk.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
anlwrk.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
anlwrk.o: /usr/include/sys/stat.h uust.h /usr/include/sys/dir.h
anlwrk.o: /usr/include/ctype.h
anyread.o: anyread.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
anyread.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
anyread.o: /usr/include/sys/stat.h
cfgets.o: cfgets.c /usr/include/stdio.h
chkpth.o: chkpth.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
chkpth.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
chkpth.o: /usr/include/sys/stat.h
cpmv.o: cpmv.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
cpmv.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
cpmv.o: /usr/include/sys/stat.h
expfile.o: expfile.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
expfile.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
expfile.o: /usr/include/sys/stat.h
gename.o: gename.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gename.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
gename.o: /usr/include/sys/file.h
getargs.o: getargs.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getargs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
getprm.o: getprm.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getprm.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
getpwinfo.o: getpwinfo.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getpwinfo.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
getpwinfo.o: /usr/include/pwd.h
gnxseq.o: gnxseq.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gnxseq.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
gnxseq.o: /usr/include/sys/time.h /usr/include/time.h
lastpart.o: lastpart.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
lastpart.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
logent.o: logent.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
logent.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
logent.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/fcntl.h
logent.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
logent.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
mailst.o: mailst.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
mailst.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
mailst.o: /usr/include/sys/timeb.h
prefix.o: prefix.c
setline.o: setline.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
setline.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
strpbrk.o: strpbrk.c
subdir.o: subdir.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
subdir.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
sysacct.o: sysacct.c /usr/include/sys/types.h
systat.o: systat.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
systat.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
ulockf.o: ulockf.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
ulockf.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
ulockf.o: /usr/include/sys/stat.h /usr/include/errno.h
uucpdefs.o: uucpdefs.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucpdefs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uucpname.o: uucpname.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucpname.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uucpname.o: /usr/include/sys/stat.h
versys.o: versys.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
versys.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
versys.o: /usr/include/stdio.h /usr/include/ctype.h
xqt.o: xqt.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
xqt.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
xqt.o: /usr/include/sys/timeb.h
E 10
I 10
bsdtcp.o: bsdtcp.c ../condevs.h ../uucp.h /usr/include/stdio.h
bsdtcp.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
bsdtcp.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
bsdtcp.o: /usr/include/signal.h /usr/include/machine/trap.h
bsdtcp.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
bsdtcp.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
bsdtcp.o: /usr/include/sys/ttydev.h /usr/include/netdb.h
bsdtcp.o: /usr/include/sys/socket.h /usr/include/netinet/in.h
df2.o: df2.c ../condevs.h ../uucp.h /usr/include/stdio.h
df2.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
df2.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
df2.o: /usr/include/machine/trap.h /usr/include/sgtty.h
df2.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
df2.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
df12.o: df12.c ../condevs.h ../uucp.h /usr/include/stdio.h
df12.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
df12.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
df12.o: /usr/include/machine/trap.h /usr/include/sgtty.h
df12.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
df12.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
dk.o: dk.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sys/types.h
dk.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/errno.h
dk.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
dk.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
dk.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
dn.o: dn.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sys/types.h
dn.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/errno.h
dn.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
dn.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
dn.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
hys.o: hys.c ../condevs.h ../uucp.h /usr/include/stdio.h
hys.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
hys.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
hys.o: /usr/include/machine/trap.h /usr/include/sgtty.h
hys.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hys.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
hysq.o: hysq.c ../condevs.h ../uucp.h /usr/include/stdio.h
hysq.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
hysq.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
hysq.o: /usr/include/machine/trap.h /usr/include/sgtty.h
hysq.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hysq.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
mic.o: mic.c ../condevs.h ../uucp.h /usr/include/stdio.h
mic.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
mic.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
mic.o: /usr/include/machine/trap.h /usr/include/sgtty.h
mic.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
mic.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
nov.o: nov.c ../condevs.h ../uucp.h /usr/include/stdio.h
nov.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
nov.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
nov.o: /usr/include/machine/trap.h /usr/include/sgtty.h
nov.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
nov.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
pen.o: pen.c ../condevs.h ../uucp.h /usr/include/stdio.h
pen.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
pen.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
pen.o: /usr/include/machine/trap.h /usr/include/sgtty.h
pen.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
pen.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
pnet.o: pnet.c ../condevs.h ../uucp.h /usr/include/stdio.h
pnet.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
pnet.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
pnet.o: /usr/include/machine/trap.h /usr/include/sgtty.h
pnet.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
pnet.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
rvmacs.o: rvmacs.c ../condevs.h ../uucp.h /usr/include/stdio.h
rvmacs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
rvmacs.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
rvmacs.o: /usr/include/signal.h /usr/include/machine/trap.h
rvmacs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
rvmacs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
rvmacs.o: /usr/include/sys/ttydev.h
sy.o: sy.c ../condevs.h ../uucp.h /usr/include/stdio.h /usr/include/sys/types.h
sy.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/errno.h
sy.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
sy.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
sy.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
unet.o: unet.c ../condevs.h ../uucp.h /usr/include/stdio.h
unet.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
unet.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
unet.o: /usr/include/machine/trap.h /usr/include/sgtty.h
unet.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
unet.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
va212.o: va212.c ../condevs.h ../uucp.h /usr/include/stdio.h
va212.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
va212.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
va212.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va212.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va212.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
va811.o: va811.c ../condevs.h ../uucp.h /usr/include/stdio.h
va811.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
va811.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
va811.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va811.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va811.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
va820.o: va820.c ../condevs.h ../uucp.h /usr/include/stdio.h
va820.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
va820.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
va820.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
va820.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
va820.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
vad.o: vad.c ../condevs.h ../uucp.h /usr/include/stdio.h
vad.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
vad.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
vad.o: /usr/include/machine/trap.h /usr/include/sgtty.h
vad.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vad.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
vent.o: vent.c ../condevs.h ../uucp.h /usr/include/stdio.h
vent.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/syslog.h
vent.o: /usr/include/errno.h /usr/include/setjmp.h /usr/include/signal.h
vent.o: /usr/include/machine/trap.h /usr/include/sgtty.h
vent.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vent.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
vmacs.o: vmacs.c ../condevs.h ../uucp.h /usr/include/stdio.h
vmacs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
vmacs.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
vmacs.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
vmacs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
vmacs.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
hys24.o: hys24.c ../condevs.h ../uucp.h /usr/include/stdio.h
hys24.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
hys24.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
hys24.o: /usr/include/signal.h /usr/include/machine/trap.h /usr/include/sgtty.h
hys24.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hys24.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
hys24.o: /usr/include/sys/file.h /usr/include/sys/ioctl.h
cds224.o: cds224.c ../condevs.h ../uucp.h /usr/include/stdio.h
cds224.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
cds224.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
cds224.o: /usr/include/signal.h /usr/include/machine/trap.h
cds224.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
cds224.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
cds224.o: /usr/include/sys/ttydev.h
att2224.o: att2224.c ../condevs.h ../uucp.h /usr/include/stdio.h
att2224.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
att2224.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
att2224.o: /usr/include/signal.h /usr/include/machine/trap.h
att2224.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
att2224.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
att2224.o: /usr/include/sys/ttydev.h
E 10
E 9

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1

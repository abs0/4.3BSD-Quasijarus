h57173
s 00107/00112/00219
d D 5.18 88/05/05 11:01:07 rick 19 18
c make depend
e
s 00001/00001/00330
d D 5.17 88/04/05 13:56:42 rick 18 17
c get defines right for generic version
e
s 00013/00010/00318
d D 5.16 88/04/05 12:01:08 rick 17 16
c remove assert
e
s 00006/00012/00322
d D 5.15 88/03/23 09:26:47 bostic 16 15
c mv strpbrk.c to MISC
e
s 00054/00053/00280
d D 5.14 88/02/24 19:44:54 rick 15 14
c add $P for parallel makes
e
s 00002/00001/00331
d D 5.13 87/08/23 16:23:50 mckusick 14 13
c uusend should NOT be setuid
e
s 00154/00228/00178
d D 5.12 87/06/18 23:54:06 bostic 13 12
c fix make depend, add tags
e
s 00002/00001/00404
d D 5.11 85/12/12 21:52:48 donn 12 11
c Put uucpd in ${DESTDIR}/etc.
e
s 00005/00005/00400
d D 5.10 85/09/18 02:44:39 lepreau 11 10
c inetd couldn't exec uucpd; chown -> /etc/chown
e
s 00149/00038/00256
d D 5.9 85/06/24 13:55:28 bloom 10 8
c fixes fom rick adams and new make depend
e
s 00146/00034/00260
d R 5.9 85/06/19 17:03:17 bloom 9 8
c changes from rick adams
e
s 00031/00020/00263
d D 5.8 85/04/10 15:17:02 ralph 8 7
c more changes from rick adams.
e
s 00101/00183/00182
d D 5.7 85/01/22 12:28:12 ralph 7 6
c bug fixes & changes from Rick Adams
e
s 00010/00002/00355
d D 5.6 84/08/30 16:13:21 ralph 6 5
c added network device NET
e
s 00002/00004/00355
d D 5.5 83/07/18 21:19:20 sam 5 4
c uuencode/uudecode are just normal executables
e
s 00001/00001/00358
d D 5.4 83/07/05 08:44:25 sam 4 3
c finally fixed unifdef
e
s 00001/00001/00358
d D 5.3 83/07/04 11:02:36 sam 3 2
c missing arg
e
s 00016/00025/00343
d D 5.2 83/07/02 18:24:06 sam 2 1
c finally done, sigh
e
s 00368/00000/00000
d D 5.1 83/07/02 17:56:10 sam 1 0
c date and time created 83/07/02 17:56:10 by sam
e
u
U
t
T
I 1
D 15
#	%M%	%I%	%E%
E 15
I 15
D 18
#	%W%	%G%
E 18
I 18
D 19
#	@(#)Makefile	5.16	4/5/88
E 19
I 19
#	%W%	%G%
E 19
E 18
E 15
#
# This version expects the 4.2BSD directory reading routines to
# located in libc.a.  If they aren't, augment LIBS.  Also, LIBS
# can be set to reference other object modules and libraries needed
# by uucico, such as -lunet (needed when UNET is defined).
#
# Common object files are assembled into a library {uulib.a}
#
D 8
ALL=	uucp uux uuxqt uucico uulog uuclean uuname uupoll uusnap \
D 6
	uuencode uudecode uusend
E 6
I 6
D 7
	uuencode uudecode uusend uucpd
E 7
I 7
	uuencode uudecode uusend uucpd uuq
E 8
I 8
ALL=	uucico uucp uux uuxqt uulog uuclean uuname uupoll uusnap \
	uuencode uudecode uusend uucpd uuq acucntrl
E 8
E 7
E 6
# Common object files placed in uulib.a
D 17
COMMON=	anlwrk.o anyread.o assert.o cfgets.o chkpth.o \
E 17
I 17
COMMON=	anlwrk.o anyread.o cfgets.o chkpth.o \
E 17
D 7
	cpmv.o expfile.o gename.o getargs.o getopt.o getprm.o \
	getpw.o getpwinfo.o gio.o gnamef.o gnxseq.o gwd.o imsg.o \
D 6
	index.o lastpart.o logent.o mailst.o pk0.o pk1.o prefix.o \
E 6
I 6
	index.o lastpart.o logent.o mailst.o nio.o pk0.o pk1.o prefix.o \
E 6
	sdmail.o setline.o shio.o subdir.o sysacct.o systat.o ulockf.o \
	uucpname.o versys.o xqt.o uucpdefs.o
E 7
I 7
	cpmv.o expfile.o gename.o getargs.o getprm.o \
D 10
	getpwinfo.o gio.o gnamef.o gnxseq.o gwd.o imsg.o \
	lastpart.o logent.o mailst.o pk0.o chksum.o pk1.o prefix.o \
D 8
	setline.o shio.o subdir.o sysacct.o systat.o \
E 8
I 8
	setline.o subdir.o sysacct.o systat.o \
E 8
	ulockf.o \
	uucpname.o versys.o xqt.o uucpdefs.o tio.o fio.o

SRCS=	anlwrk.c anyread.c assert.c cfgets.c chkpth.c chksum.c \
	cico.c cntrl.c condevs.c conn.c cpmv.c expfile.c \
E 10
I 10
D 15
	getpwinfo.o gnamef.o gnxseq.o lastpart.o logent.o mailst.o \
E 15
I 15
	getpwinfo.o gnxseq.o lastpart.o logent.o mailst.o \
E 15
D 16
	prefix.o setline.o strpbrk.o subdir.o sysacct.o systat.o \
E 16
I 16
	prefix.o setline.o subdir.o sysacct.o systat.o \
E 16
	ulockf.o uucpname.o versys.o xqt.o uucpdefs.o
SRCS=	${USRCS} ${OSRCS} ${LSRCS}
USRCS=	cico.c cntrl.c conn.c condevs.c gnsys.c pk0.c chksum.c pk1.c tio.c \
	fio.c gio.c imsg.c 
OSRCS=	uuclean.c uucp.c uulog.c uuname.c uupoll.c \
	uusend.c uusnap.c uux.c uuxqt.c uuq.c acucntrl.c
D 17
LSRCS=	anlwrk.c anyread.c assert.c cfgets.c chkpth.c \
E 17
I 17
LSRCS=	anlwrk.c anyread.c cfgets.c chkpth.c \
E 17
D 15
	cpmv.c expfile.c \
E 10
	gename.c getargs.c getprm.c getpwinfo.c \
D 10
	gio.c gnamef.c gnsys.c gnxseq.c gwd.c imsg.c \
	ioctl.c lastpart.c logent.c mailst.c ndir.h \
	pk.h pk0.c pk1.c pkon.c prefix.c \
D 8
	setline.c shio.c subdir.c sysacct.c systat.c tio.c fio.c\
E 8
I 8
	setline.c subdir.c sysacct.c systat.c tio.c fio.c\
E 8
	ulockf.c \
	uuclean.c uucp.c uucp.h uucpdefs.c uucpname.c uudecode.c \
	uuencode.c uulog.c uuname.c uupoll.c uusend.c uusnap.c \
	uux.c uuxqt.c \
D 8
	versys.c xqt.c uuq.c
E 8
I 8
	versys.c xqt.c uuq.c acucntrl.c
E 10
I 10
	gnamef.c gnxseq.c \
	lastpart.c logent.c mailst.c prefix.c \
E 15
I 15
	cpmv.c expfile.c gename.c getargs.c getprm.c getpwinfo.c \
	gnxseq.c lastpart.c logent.c mailst.c prefix.c \
E 15
D 16
	setline.c strpbrk.c subdir.c sysacct.c systat.c ulockf.c \
E 16
I 16
	setline.c subdir.c sysacct.c systat.c ulockf.c \
E 16
	uucpdefs.c uucpname.c versys.c xqt.c

E 10
E 8
D 17
#These might be useful on non 4.2bsd systems.
D 8
MISC= htonl.c ioctl.c index.c
E 8
I 8
D 10
MISC= htonl.c ioctl.c index.c mkdir.c
E 10
I 10
D 16
MISC= htonl.c ioctl.c index.c mkdir.c getwd.c
E 16
I 16
MISC= htonl.c ioctl.c index.c mkdir.c getwd.c strpbrk.c
E 17
I 17
#These might be useful on non 4.3bsd systems.
MISC= htonl.c ioctl.c index.c mkdir.c strpbrk.c 
E 17
E 16
E 10
E 8

E 7
DESTDIR=
I 10

I 15
# Define P=& if your make supports parallelism (e.g. Sequent)
P=

E 15
E 10
OWNER=	uucp
GROUP=	daemon
CFLAGS=	-O
LDFLAGS=
I 10
LINTFLAGS= -chbap
E 10
D 7
LIBS=
LIBDIR=	/usr/lib/uucp
BIN=	/usr/bin
PUBDIR=	/usr/spool/uucppublic
SPOOL=	/usr/spool/uucp
XQTDIR=	/usr/spool/uucp/XTMP
E 7
I 7
LIBS= 
LIBDIR=	${DESTDIR}/usr/lib/uucp
BIN=	${DESTDIR}/usr/bin
I 12
ETC=	${DESTDIR}/etc
E 12
PUBDIR=	${DESTDIR}/usr/spool/uucppublic
SPOOL=	${DESTDIR}/usr/spool/uucp
XQTDIR=	${SPOOL}/XTMP
CORRUPT= ${SPOOL}/CORRUPT
AUDIT=	${SPOOL}/AUDIT
D 8
LCK=	#${SPOOL}/LCK.
E 8
I 8
D 10
LCK=	${SPOOL}/LCK
LOG=	${SPOOL}/LOG
E 10
I 10
LCK= ${SPOOL}/LCK
LOG= ${SPOOL}/LOG
E 10
E 8
STST=	${SPOOL}/STST
E 7
D 8
# The six subdirs {not counting XTMP}.  The order of the D. files is crucial!
E 8
I 8
# The six subdirs {not counting XTMP}.
E 8
D 10
SUBDIRS=C. D.`uuname -l`X D.`uuname -l` D. X. TM.
E 10
I 10
HOSTNAME=`uuname -l | sed 's/\(.......\).*/\1/'`
SUBDIRS=C. D.${HOSTNAME}X D.${HOSTNAME} D. X. TM.
E 10
D 7
PKON=	pkon.o
IOCTL=
E 7
I 2
D 13
# for make depend
D 4
UNDEF=	-uNDIR -uUNET -uSYSIII -uUNAME -uCCWHOAMI -uGETMYHNAME -uDATAKIT
E 4
I 4
D 7
UNDEF=	-UNDIR -UUNET -USYSIII -UUNAME -UCCWHOAMI -UGETMYHNAME -UDATAKIT
E 7
I 7
UNDEF=	-UNDIR -UUNET -USYSIII -UUNAME -UCCWHOAMI -UGETMYHNAME -UDATAKIT \
D 8
	-UBSD4_2
E 8
I 8
D 10
	-UBSD4_2 -UUSG -UVMS
E 10
I 10
	-DBSD4_2 -UUSG -UVMS -UBSD2_9
E 13
E 10
E 8
E 7
E 4
E 2

D 15
all:	${ALL} 
E 15
I 15
all:	$(P) ${ALL} 
E 15

I 10
lint: ${SRCS}
	lint ${LINTFLAGS} ${USRCS} ${LSRCS}
	-for i in ${OSRCS} ; do \
		lint ${LINTFLAGS} $$i ${LSRCS} ;\
	done
E 10
I 7
print:	$(SRCS)
	vgrind $?
	vgrind -x index
	touch print

E 7
D 15
uucp:	uucp.o uulib.a
E 15
I 15
uucp:	$(P) uucp.o uulib.a
E 15
D 10
	${CC} -o uucp ${LDFLAGS} uucp.o uulib.a
E 10
I 10
	${CC} -o uucp ${LDFLAGS} uucp.o uulib.a ${LIBS}
E 10

D 15
uux:	uux.o uulib.a
E 15
I 15
uux:	$(P) uux.o uulib.a
E 15
D 10
	${CC} -o uux ${LDFLAGS} uux.o uulib.a
E 10
I 10
	${CC} -o uux ${LDFLAGS} uux.o uulib.a ${LIBS}
E 10

D 15
uuxqt:	uuxqt.o uulib.a
E 15
I 15
uuxqt:	$(P) uuxqt.o uulib.a
E 15
	${CC} -o uuxqt ${LDFLAGS} uuxqt.o uulib.a ${LIBS}

D 7
uucico:	cico.o cntrl.o conn.o condevs.o gnsys.o ${IOCTL} ${PKON} uulib.a
E 7
I 7
D 10
uucico:	cico.o cntrl.o conn.o condevs.o gnsys.o uulib.a aculib/aculib.a
E 7
	${CC} -o uucico ${LDFLAGS} cico.o cntrl.o conn.o condevs.o \
D 3
		gnsys.o ${IOCTL} ${PKON} ${LIBS}
E 3
I 3
D 7
		gnsys.o ${IOCTL} ${PKON} uulib.a ${LIBS}
E 7
I 7
		gnsys.o uulib.a aculib/aculib.a ${LIBS}
E 10
I 10
D 15
uucico:	cico.o cntrl.o conn.o condevs.o gnsys.o pk0.o chksum.o pk1.o tio.o \
	fio.o gio.o imsg.o uulib.a aculib/aculib.a
E 15
I 15
uucico:	$(P) cico.o cntrl.o conn.o condevs.o gnsys.o pk0.o chksum.o pk1.o \
	tio.o fio.o gio.o imsg.o uulib.a $(P) aculib/aculib.a
E 15
	${CC} -o uucico ${LDFLAGS} cico.o cntrl.o conn.o condevs.o gnsys.o \
	pk0.o chksum.o pk1.o tio.o fio.o gio.o imsg.o \
	uulib.a aculib/aculib.a ${LIBS}
E 10
E 7
E 3

D 15
uulog:	uulog.o uulib.a
E 15
I 15
uulog:	$(P) uulog.o uulib.a
E 15
D 10
	${CC} -o uulog ${LDFLAGS} uulog.o uulib.a
E 10
I 10
	${CC} -o uulog ${LDFLAGS} uulog.o uulib.a ${LIBS}
E 10

D 15
uuclean: uuclean.o uulib.a
E 15
I 15
uuclean: $(P) uuclean.o uulib.a
E 15
D 7
	${CC} -o uuclean ${LDFLAGS} uuclean.o uulib.a
E 7
I 7
	${CC} -o uuclean ${LDFLAGS} uuclean.o uulib.a ${LIBS}
E 7

D 15
uuname:	uuname.o uulib.a
E 15
I 15
uuname:	$(P) uuname.o uulib.a
E 15
D 10
	${CC} -o uuname ${LDFLAGS} uuname.o uulib.a
E 10
I 10
	${CC} -o uuname ${LDFLAGS} uuname.o uulib.a ${LIBS}
E 10
D 7
 
E 7
I 7

E 7
D 15
uupoll:	uupoll.o uulib.a
E 15
I 15
uupoll:	$(P) uupoll.o uulib.a
E 15
D 10
	${CC} -o uupoll ${LDFLAGS} uupoll.o uulib.a
E 10
I 10
	${CC} -o uupoll ${LDFLAGS} uupoll.o uulib.a ${LIBS}
E 10

D 7
uusnap:	uusnap.o uulib.a
	${CC} -o uusnap ${LDFLAGS} uusnap.o uulib.a ${LIBS}
E 7
I 7
uusnap:	uusnap.o
	${CC} -o uusnap ${LDFLAGS} uusnap.o ${LIBS}
E 7

D 7
uuencode: uuencode.o uulib.a
	${CC} -o uuencode ${LDFLAGS} uuencode.o uulib.a
E 7
I 7
uuencode: uuencode.o
D 10
	${CC} -o uuencode ${LDFLAGS} uuencode.o
E 10
I 10
	${CC} -o uuencode ${LDFLAGS} uuencode.o ${LIBS}
E 10
E 7

D 7
uudecode: uudecode.o uulib.a
	${CC} -o uudecode ${LDFLAGS} uudecode.o uulib.a
E 7
I 7
uudecode: uudecode.o
D 10
	${CC} -o uudecode ${LDFLAGS} uudecode.o
E 10
I 10
	${CC} -o uudecode ${LDFLAGS} uudecode.o ${LIBS}
E 10
E 7

D 7
uusend: uusend.o uulib.a
	${CC} -o uusend ${LDFLAGS} uusend.o uulib.a
E 7
I 7
uusend: uusend.o
D 10
	${CC} -o uusend ${LDFLAGS} uusend.o
E 10
I 10
	${CC} -o uusend ${LDFLAGS} uusend.o uulib.a ${LIBS}
E 10
E 7

I 6
D 7
uucpd:	uucpd.o
E 7
I 7
uucpd: uucpd.o uucp.h
E 7
D 10
	${CC} -o uucpd ${LDFLAGS} uucpd.o
E 10
I 10
	${CC} -o uucpd ${LDFLAGS} uucpd.o ${LIBS}
E 10

I 7
D 15
uuq: uuq.o uulib.a
E 15
I 15
uuq: $(P) uuq.o uulib.a
E 15
D 10
	${CC} -o uuq ${LDFLAGS} uuq.o uulib.a
E 10
I 10
	${CC} -o uuq ${LDFLAGS} uuq.o uulib.a ${LIBS}
E 10

I 8
acucntrl: acucntrl.o
D 10
	${CC} -o acucntrl ${LDFLAGS} acucntrl.o
E 10
I 10
	${CC} -o acucntrl ${LDFLAGS} acucntrl.o ${LIBS}
E 10

E 8
E 7
E 6
# Note: mode 700 on ${LIBDIR} would be safer.
# Also,  L.sys etc should be 600.
I 7

E 7
mkdirs:
D 7
	-mkdir ${DESTDIR}/${LIBDIR}
	chmod 755 ${DESTDIR}/${LIBDIR}
	chown ${OWNER} ${DESTDIR}/${LIBDIR}
	chgrp ${GROUP} ${DESTDIR}/${LIBDIR}
	-mkdir ${DESTDIR}/${SPOOL}
	chmod 755 ${DESTDIR}/${SPOOL}
	chown ${OWNER} ${DESTDIR}/${SPOOL}
	chgrp ${GROUP} ${DESTDIR}/${SPOOL}
	-mkdir ${DESTDIR}/${PUBDIR}
	chmod 777 ${DESTDIR}/${PUBDIR}
	chown ${OWNER} ${DESTDIR}/${PUBDIR}
	chgrp ${GROUP} ${DESTDIR}/${PUBDIR}
	-mkdir ${DESTDIR}/${XQTDIR}
	chmod 755 ${DESTDIR}/${XQTDIR}
	chown ${OWNER} ${DESTDIR}/${XQTDIR}
	chgrp ${GROUP} ${DESTDIR}/${XQTDIR}
	cd ${DESTDIR}/${SPOOL}; for i in ${SUBDIRS}; do \
E 7
I 7
	-for i in ${LIBDIR} ${SPOOL} ${PUBDIR} ${XQTDIR} ${CORRUPT} \
D 8
		${AUDIT} ${LCK} ${STST} ; do \
E 8
I 8
		${AUDIT} ${LCK} ${LOG} ${STST} ; do \
E 8
		rm -f $$i ; mkdir $$i ; \
D 11
		chmod 755 $$i; chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
E 11
I 11
		chmod 755 $$i; /etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
E 11
	done
	chmod 777 ${PUBDIR} ${LCK}
I 8
	-cd ${LOG}; for i in uucico uux uuxqt uucp xferstats; do\
		rm -f $$i ; mkdir $$i ; \
D 11
		chmod 755 $$i; chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
E 11
I 11
		chmod 755 $$i; /etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i ; \
E 11
	done
E 8
	-cd ${SPOOL}; for i in ${SUBDIRS} ; do \
E 7
		mkdir $$i; \
D 2
		chown ${UUCP} $$i; chgrp ${GROUP} $$i; chmod 755 $$i; \
E 2
I 2
D 11
		chown ${OWNER} $$i; chgrp ${GROUP} $$i; chmod 755 $$i; \
E 11
I 11
		/etc/chown ${OWNER} $$i; chgrp ${GROUP} $$i; chmod 755 $$i; \
E 11
E 2
	done

# The lorder...tsort below is for systems w/o ranlib
# But it doesnt hurt to use it. Ignore the spurious "cycle" messages
D 15
uulib.a: ${COMMON}
E 15
I 15
uulib.a: $(P) ${COMMON}
E 15
	rm -f $@
	ar cr $@ `lorder ${COMMON} | tsort`
	ranlib $@

D 7
install: all
	chown ${OWNER} ${DESTDIR}/${LIBDIR}
	chgrp ${GROUP} ${DESTDIR}/${LIBDIR}
	chmod 755 ${DESTDIR}/${LIBDIR}
	install -s -m 6111 -o ${OWNER} -g ${GROUP} uucp ${DESTDIR}/${BIN}/uucp
	install -s -m 6111 -o ${OWNER} -g ${GROUP} uux ${DESTDIR}/${BIN}/uux
	: chmod u+t ${BIN}/uux; : this helps PDPs
	install -s -m 6110 -o ${OWNER} -g ${GROUP} \
		uuxqt ${DESTDIR}/${LIBDIR}/uuxqt
	: chmod u+t ${LIBDIR}/uuxqt; : this helps PDPs
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uucico ${DESTDIR}/${LIBDIR}/uucico
	: chmod u+t ${LIBDIR}/uucico; : this helps PDPs if uucico is pure
	install -s -m 6111 -o ${OWNER} -g ${GROUP} uulog ${DESTDIR}/${BIN}/uulog
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uuclean ${DESTDIR}/${LIBDIR}/uuclean
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uuname ${DESTDIR}/${BIN}/uuname
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uupoll ${DESTDIR}/${BIN}/uupoll
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uusnap ${DESTDIR}/${BIN}/uusnap
D 5
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uuencode ${DESTDIR}/${BIN}/uuencode
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uudecode ${DESTDIR}/${BIN}/uudecode
E 5
I 5
	install -s uuencode ${DESTDIR}/${BIN}/uuencode
	install -s uudecode ${DESTDIR}/${BIN}/uudecode
E 5
	install -s -m 6111 -o ${OWNER} -g ${GROUP} \
		uusend ${DESTDIR}/${BIN}/uusend
I 6
	install -s -m 100 -o ${OWNER} -g ${GROUP} \
		uucpd ${DESTDIR}/${LIBDIR}/uucpd
E 6
	rm -f ${DESTDIR}/${BIN}/ruusend
	ln ${DESTDIR}/${BIN}/uusend ${DESTDIR}/${BIN}/ruusend
E 7
I 7
aculib/aculib.a:
D 8
	cd aculib; make
E 8
I 8
D 15
	cd aculib; make ${MFLAGS} "CFLAGS=${CFLAGS}"
E 15
I 15
	cd aculib; make ${MFLAGS} "CFLAGS=${CFLAGS}" "P=${P}"
E 15
E 8
E 7

I 7
D 8
install:
E 8
I 8
install: ${ALL}
E 8
D 11
	chown ${OWNER} ${LIBDIR}
E 11
I 11
	/etc/chown ${OWNER} ${LIBDIR}
E 11
	chgrp ${GROUP} ${LIBDIR}
	chmod 755 ${LIBDIR}
	for i in uucico uuclean; do \
		install -s -m 6111 -o ${OWNER} -g ${GROUP} $$i ${LIBDIR} ;\
	done
D 14
	for i in uucp uux uulog uuname uusnap uupoll uuq uusend; do \
E 14
I 14
	for i in uucp uux uulog uuname uusnap uupoll uuq; do \
E 14
		install -s -m 6111 -o ${OWNER} -g ${GROUP} $$i ${BIN} ;\
	done
D 15
	rm -f ${BIN}/ruusend
	ln ${BIN}/uusend ${BIN}/ruusend
E 15
	install -s -m 6110 -o ${OWNER} -g ${GROUP} uuxqt ${LIBDIR}
I 8
	install -s -m 6110 -o root -g ${GROUP} acucntrl ${LIBDIR}
E 8
D 11
	install -s -m 700 -o root uucpd /etc/uucpd
E 11
I 11
D 12
	install -s -m 500 -o uucp uucpd /etc/uucpd
E 12
I 12
	install -s -m 500 -o uucp uucpd ${ETC}
E 12
E 11
I 10
	@echo Dont forget to fork off /etc/uucpd in /etc/rc.local
	@echo if you are not running /etc/inetd
I 14
D 15
	install -s -o bin -g bin -m 755 uusend ${BIN}
E 14
E 10
D 8
	@echo Dont forget to fork off /etc/uucpd in /etc/rc.local
E 8
D 13
	install -s uuencode ${BIN}
	install -s uudecode ${BIN}
E 13
I 13
	install -s -o bin -g bin -m 755 uuencode ${BIN}
	install -s -o bin -g bin -m 755 uudecode ${BIN}
E 15
I 15
	install -s -m 755 -o bin -g bin uusend ${BIN}
	install -s -m 755 -o bin -g bin uuencode ${BIN}
	install -s -m 755 -o bin -g bin uudecode ${BIN}
	rm -f ${BIN}/ruusend
	ln ${BIN}/uusend ${BIN}/ruusend
E 15
E 13

E 7
clean:
	rm -f *.o ${ALL} uulib.a
I 7
D 8
	cd aculib; make clean
E 8
I 8
	cd aculib; make ${MFLAGS} clean
E 8
E 7

D 13
depend:
	for i in *.c; do \
		(echo `basename $$i .c`.o: $$i >>makedep; \
D 2
			unifdef -uUNET -uNDIR $$i | \
E 2
I 2
			unifdef ${UNDEF} $$i | \
E 2
			/bin/grep '^#[ 	]*include' | sed \
			-e '/\.\.\/h/d' \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/^[^"]*"\([^"]*\)".*/'"$$i"': \1/' \
			-e 's/\.c/.o/' >>makedep); done
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 13
I 13
depend: FRC
	cd aculib; make ${MFLAGS} depend
	mkdep ${CFLAGS} ${SRCS}
E 13

D 13
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
I 8
acucntrl.o: acucntrl.c
acucntrl.o: uucp.h
I 10
acucntrl.o: /usr/include/sys/buf.h
acucntrl.o: /usr/include/signal.h
acucntrl.o: /usr/include/sys/conf.h
acucntrl.o: /usr/include/vaxuba/ubavar.h
acucntrl.o: /usr/include/sys/stat.h
acucntrl.o: /usr/include/nlist.h
acucntrl.o: /usr/include/sgtty.h
acucntrl.o: /usr/include/utmp.h
acucntrl.o: /usr/include/pwd.h
acucntrl.o: /usr/include/stdio.h
E 10
E 8
anlwrk.o: anlwrk.c
anlwrk.o: uucp.h
I 10
anlwrk.o: /usr/include/sys/stat.h
E 10
D 7
anlwrk.o: /usr/include/sys/types.h
anlwrk.o: /usr/include/sys/stat.h
D 2
anlwrk.o: /usr/include/dir.h
E 2
I 2
anlwrk.o: /usr/include/sys/dir.h
E 7
I 7
anlwrk.o: uust.h
I 10
anlwrk.o: /usr/include/sys/dir.h
E 13
I 13
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 15
cico.o: cico.c /usr/include/signal.h uucp.h /usr/include/stdio.h
cico.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
cico.o: cico.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
cico.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
cico.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/sgtty.h
E 19
I 19
cico.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/sys/timeb.h
cico.o: /usr/include/syslog.h /usr/include/setjmp.h /usr/include/sgtty.h
E 19
cico.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 19
cico.o: /usr/include/sys/ttydev.h /usr/include/netdb.h
cico.o: /usr/include/netinet/in.h /usr/include/sys/socket.h
D 16
cico.o: /usr/include/sys/stat.h uust.h uusub.h
E 16
I 16
D 17
cico.o: /usr/include/sys/stat.h /usr/include/sys/time.h /usr/include/time.h
cico.o: /usr/include/fcntl.h uust.h uusub.h
E 17
I 17
cico.o: /usr/include/sys/stat.h uust.h uusub.h
E 17
E 16
cntrl.o: cntrl.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
cntrl.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
cntrl.o: /usr/include/sys/stat.h uust.h
E 19
I 19
cico.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
cico.o: /usr/include/netdb.h /usr/include/netinet/in.h
cico.o: /usr/include/sys/socket.h /usr/include/sys/stat.h
cico.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/fcntl.h uust.h
cico.o: uusub.h
cntrl.o: cntrl.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
cntrl.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/stat.h
cntrl.o: uust.h
E 19
D 15
conn.o: conn.c /usr/include/signal.h uucp.h /usr/include/stdio.h
conn.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
conn.o: conn.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
conn.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
conn.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/ctype.h
E 19
I 19
conn.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/sys/timeb.h
conn.o: /usr/include/syslog.h /usr/include/setjmp.h /usr/include/ctype.h
E 19
conn.o: /usr/include/errno.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 19
conn.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
conn.o: /usr/include/sys/time.h /usr/include/time.h
E 19
I 19
conn.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
conn.o: /usr/include/sys/ttydev.h /usr/include/sys/time.h /usr/include/time.h
E 19
condevs.o: condevs.c condevs.h uucp.h /usr/include/stdio.h
D 19
condevs.o: /usr/include/sysexits.h /usr/include/sys/types.h
condevs.o: /usr/include/sys/timeb.h /usr/include/errno.h /usr/include/setjmp.h
E 19
I 19
condevs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
condevs.o: /usr/include/syslog.h /usr/include/errno.h /usr/include/setjmp.h
E 19
D 15
condevs.o: /usr/include/signal.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 15
I 15
condevs.o: /usr/include/signal.h /usr/include/machine/trap.h
condevs.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
E 15
D 19
condevs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
condevs.o: /usr/include/sys/time.h /usr/include/time.h
gnsys.o: gnsys.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gnsys.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
gnsys.o: /usr/include/sys/dir.h
pk0.o: pk0.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
pk0.o: /usr/include/sys/types.h /usr/include/sys/timeb.h pk.h
E 19
I 19
condevs.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
condevs.o: /usr/include/sys/ttydev.h /usr/include/sys/time.h
condevs.o: /usr/include/time.h
gnsys.o: gnsys.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
gnsys.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/dir.h
pk0.o: pk0.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
pk0.o: /usr/include/sys/timeb.h /usr/include/syslog.h pk.h
E 19
chksum.o: chksum.c
D 15
pk1.o: pk1.c /usr/include/signal.h uucp.h /usr/include/stdio.h
pk1.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
pk1.o: pk1.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
pk1.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
pk1.o: /usr/include/sys/timeb.h pk.h /usr/include/setjmp.h
pk1.o: /usr/include/sys/time.h /usr/include/time.h
E 19
I 19
pk1.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/sys/timeb.h
pk1.o: /usr/include/syslog.h pk.h /usr/include/setjmp.h /usr/include/sys/time.h
pk1.o: /usr/include/time.h /usr/include/sys/uio.h
E 19
D 15
tio.o: tio.c /usr/include/signal.h uucp.h /usr/include/stdio.h
tio.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
tio.o: tio.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
tio.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
tio.o: /usr/include/sys/timeb.h /usr/include/setjmp.h /usr/include/sys/stat.h
fio.o: fio.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
fio.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/signal.h
E 19
I 19
tio.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/sys/timeb.h
tio.o: /usr/include/syslog.h /usr/include/setjmp.h /usr/include/sys/stat.h
tio.o: /usr/include/machine/machparam.h /usr/include/machine/endian.h
fio.o: fio.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
fio.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/signal.h
E 19
D 15
fio.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
fio.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
fio.o: /usr/include/setjmp.h
E 15
I 15
fio.o: /usr/include/machine/trap.h /usr/include/sgtty.h
fio.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 19
fio.o: /usr/include/sys/ttydev.h /usr/include/setjmp.h
E 15
gio.o: gio.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gio.o: /usr/include/sys/types.h /usr/include/sys/timeb.h pk.h
E 19
I 19
fio.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
fio.o: /usr/include/setjmp.h
gio.o: gio.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
gio.o: /usr/include/sys/timeb.h /usr/include/syslog.h pk.h
E 19
gio.o: /usr/include/setjmp.h
D 19
imsg.o: imsg.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
imsg.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/ctype.h
E 19
I 19
imsg.o: imsg.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
imsg.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/ctype.h
E 19
D 15
uuclean.o: uuclean.c /usr/include/signal.h uucp.h /usr/include/stdio.h
uuclean.o: /usr/include/sysexits.h /usr/include/sys/types.h
uuclean.o: /usr/include/sys/timeb.h /usr/include/pwd.h /usr/include/sys/stat.h
uuclean.o: /usr/include/sys/dir.h
E 15
I 15
uuclean.o: uuclean.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
uuclean.o: /usr/include/stdio.h /usr/include/sysexits.h
uuclean.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/pwd.h
E 19
I 19
uuclean.o: /usr/include/stdio.h /usr/include/sys/types.h
uuclean.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/pwd.h
E 19
uuclean.o: /usr/include/sys/stat.h /usr/include/sys/dir.h
E 15
D 19
uucp.o: uucp.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucp.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uucp.o: /usr/include/sys/stat.h uust.h
uulog.o: uulog.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uulog.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuname.o: uuname.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuname.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
D 15
uuname.o: /usr/include/signal.h
E 15
I 15
uuname.o: /usr/include/signal.h /usr/include/machine/trap.h
E 15
uupoll.o: uupoll.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uupoll.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
uucp.o: uucp.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uucp.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/stat.h
uucp.o: uust.h
uulog.o: uulog.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uulog.o: /usr/include/sys/timeb.h /usr/include/syslog.h
uuname.o: uuname.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uuname.o: /usr/include/sys/timeb.h /usr/include/syslog.h
uupoll.o: uupoll.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uupoll.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
uusend.o: uusend.c /usr/include/stdio.h /usr/include/pwd.h
uusend.o: /usr/include/sys/types.h /usr/include/sys/stat.h
D 19
uusnap.o: uusnap.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uusnap.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
uusnap.o: uusnap.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uusnap.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
uusnap.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/ctype.h
D 19
uux.o: uux.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uux.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
I 16
D 17
uux.o: /usr/include/sys/stat.h
E 17
E 16
uuxqt.o: uuxqt.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuxqt.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uuxqt.o: /usr/include/sys/stat.h /usr/include/sys/dir.h /usr/include/signal.h
E 19
I 19
uux.o: uux.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uux.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/stat.h
uux.o: /usr/include/sys/errno.h
uuxqt.o: uuxqt.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uuxqt.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/stat.h
uuxqt.o: /usr/include/sys/dir.h /usr/include/signal.h
E 19
I 15
uuxqt.o: /usr/include/machine/trap.h
E 15
D 19
uuq.o: uuq.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uuq.o: /usr/include/sys/types.h /usr/include/sys/timeb.h /usr/include/stdio.h
uuq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h
acucntrl.o: acucntrl.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
acucntrl.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
I 17
acucntrl.o: /usr/include/sys/buf.h /usr/include/signal.h
acucntrl.o: /usr/include/machine/trap.h /usr/include/sys/conf.h
acucntrl.o: /sys/vaxuba/ubavar.h /usr/include/sys/stat.h /usr/include/nlist.h
acucntrl.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
acucntrl.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
acucntrl.o: /usr/include/utmp.h /usr/include/pwd.h /usr/include/stdio.h
acucntrl.o: /usr/include/sys/file.h
E 17
D 16
acucntrl.o: /usr/include/sys/buf.h /usr/include/signal.h
D 15
acucntrl.o: /usr/include/sys/conf.h /sys/vaxuba/ubavar.h
acucntrl.o: /usr/include/sys/stat.h /usr/include/nlist.h /usr/include/sgtty.h
acucntrl.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
acucntrl.o: /usr/include/sys/ttydev.h /usr/include/utmp.h /usr/include/pwd.h
acucntrl.o: /usr/include/stdio.h /usr/include/sys/file.h
E 15
I 15
acucntrl.o: /usr/include/machine/trap.h /usr/include/sys/conf.h
acucntrl.o: /sys/vaxuba/ubavar.h /usr/include/sys/stat.h /usr/include/nlist.h
acucntrl.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
acucntrl.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
acucntrl.o: /usr/include/utmp.h /usr/include/pwd.h /usr/include/stdio.h
acucntrl.o: /usr/include/sys/file.h
E 16
E 15
anlwrk.o: anlwrk.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
anlwrk.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
uuq.o: uuq.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uuq.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/stdio.h
uuq.o: /usr/include/sys/dir.h /usr/include/sys/stat.h /usr/include/pwd.h
acucntrl.o: acucntrl.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
acucntrl.o: /usr/include/sys/timeb.h /usr/include/syslog.h
anlwrk.o: anlwrk.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
anlwrk.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
anlwrk.o: /usr/include/sys/stat.h uust.h /usr/include/sys/dir.h
E 13
anlwrk.o: /usr/include/ctype.h
E 10
E 7
E 2
D 13
anyread.o: anyread.c
anyread.o: uucp.h
E 13
I 13
D 19
anyread.o: anyread.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
anyread.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
anyread.o: anyread.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
anyread.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
E 13
I 10
anyread.o: /usr/include/sys/stat.h
E 10
D 7
anyread.o: /usr/include/sys/types.h
anyread.o: /usr/include/sys/stat.h
E 7
D 13
assert.o: assert.c
assert.o: uucp.h
I 10
assert.o: /usr/include/sys/time.h
assert.o: /usr/include/errno.h
E 10
D 2
assert.o: /usr/include/time.h
E 2
I 2
D 7
assert.o: /usr/include/sys/time.h
E 2
assert.o: /usr/include/sys/types.h
assert.o: /usr/include/errno.h
E 7
cfgets.o: cfgets.c
I 10
cfgets.o: /usr/include/stdio.h
E 10
D 7
cfgets.o: /usr/include/stdio.h
E 7
chkpth.o: chkpth.c
chkpth.o: uucp.h
E 13
I 13
D 17
assert.o: assert.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
assert.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
assert.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/errno.h
E 17
cfgets.o: cfgets.c /usr/include/stdio.h
D 19
chkpth.o: chkpth.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
chkpth.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
chkpth.o: chkpth.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
chkpth.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
E 13
I 10
chkpth.o: /usr/include/sys/stat.h
E 10
D 7
chkpth.o: /usr/include/sys/types.h
chkpth.o: /usr/include/sys/stat.h
E 7
I 7
D 13
chksum.o: chksum.c
E 7
cico.o: cico.c
I 10
cico.o: /usr/include/signal.h
E 10
cico.o: uucp.h
I 10
cico.o: /usr/include/setjmp.h
cico.o: /usr/include/sgtty.h
cico.o: /usr/include/netdb.h
cico.o: /usr/include/netinet/in.h
cico.o: /usr/include/sys/socket.h
cico.o: /usr/include/sys/stat.h
E 10
D 7
cico.o: /usr/include/signal.h
cico.o: /usr/include/setjmp.h
cico.o: /usr/include/sys/types.h
D 2
cico.o: /usr/include/termio.h
E 2
cico.o: /usr/include/sgtty.h
E 7
I 7
cico.o: uust.h
cico.o: uusub.h
E 7
cntrl.o: cntrl.c
cntrl.o: uucp.h
I 10
cntrl.o: /usr/include/sys/stat.h
E 10
D 7
cntrl.o: /usr/include/sys/types.h
cntrl.o: /usr/include/sys/stat.h
E 7
I 7
cntrl.o: uust.h
E 7
condevs.o: condevs.c
D 7
condevs.o: /usr/include/sys/types.h
condevs.o: /usr/include/errno.h
condevs.o: /usr/include/setjmp.h
condevs.o: /usr/include/signal.h
condevs.o: /usr/include/sgtty.h
E 7
D 8
condevs.o: uucp.h
E 8
I 8
condevs.o: condevs.h
I 10
condevs.o: /usr/include/sys/time.h
E 10
E 8
D 2
condevs.o: /usr/include/dk.h
condevs.o: /usr/include/time.h
E 2
I 2
D 7
condevs.o: /usr/include/sys/time.h
E 2
condevs.o: /usr/include/sys/timeb.h
E 7
conn.o: conn.c
I 10
conn.o: /usr/include/signal.h
E 10
conn.o: uucp.h
I 10
conn.o: /usr/include/setjmp.h
conn.o: /usr/include/ctype.h
conn.o: /usr/include/errno.h
conn.o: /usr/include/sgtty.h
conn.o: /usr/include/sys/time.h
E 10
D 7
conn.o: /usr/include/signal.h
conn.o: /usr/include/setjmp.h
conn.o: /usr/include/ctype.h
conn.o: /usr/include/sys/types.h
D 2
conn.o: /usr/include/time.h
E 2
I 2
conn.o: /usr/include/sys/time.h
E 2
conn.o: /usr/include/errno.h
D 2
conn.o: /usr/include/termio.h
conn.o: /usr/include/fcntl.h
E 2
conn.o: /usr/include/sgtty.h
E 7
cpmv.o: cpmv.c
cpmv.o: uucp.h
E 13
I 13
D 19
cpmv.o: cpmv.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
cpmv.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 13
I 10
cpmv.o: /usr/include/sys/stat.h
E 10
D 7
cpmv.o: /usr/include/sys/types.h
cpmv.o: /usr/include/sys/stat.h
E 7
D 13
expfile.o: expfile.c
expfile.o: uucp.h
E 13
I 13
expfile.o: expfile.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
expfile.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
cpmv.o: cpmv.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
cpmv.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/sys/stat.h
expfile.o: expfile.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
expfile.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
E 13
I 10
expfile.o: /usr/include/sys/stat.h
E 10
D 7
expfile.o: /usr/include/sys/types.h
expfile.o: /usr/include/sys/stat.h
E 7
I 7
D 13
fio.o: fio.c
I 10
fio.o: /usr/include/signal.h
E 10
fio.o: uucp.h
I 10
fio.o: /usr/include/sgtty.h
fio.o: /usr/include/setjmp.h
E 10
E 7
gename.o: gename.c
gename.o: uucp.h
getargs.o: getargs.c
D 7
getargs.o: /usr/include/stdio.h
E 7
D 8
getopt.o: getopt.c
E 8
I 8
getargs.o: uucp.h
E 8
D 7
getopt.o: /usr/include/stdio.h
E 7
getprm.o: getprm.c
I 10
getprm.o: uucp.h
E 10
D 7
getprm.o: /usr/include/stdio.h
getpw.o: getpw.c
D 2
getpw.o: stdio.h
E 2
I 2
getpw.o: /usr/include/stdio.h
E 7
E 2
getpwinfo.o: getpwinfo.c
getpwinfo.o: uucp.h
E 13
I 13
D 19
gename.o: gename.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gename.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
gename.o: gename.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
gename.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
gename.o: /usr/include/sys/file.h
D 19
getargs.o: getargs.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getargs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
getprm.o: getprm.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getprm.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
getpwinfo.o: getpwinfo.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
getpwinfo.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 13
I 10
getpwinfo.o: /usr/include/pwd.h
D 13
getwd.o: getwd.c
getwd.o: uucp.h
E 10
D 7
getpwinfo.o: /usr/include/pwd.h
E 7
gio.o: gio.c
D 7
gio.o: pk.p
gio.o: /usr/include/sys/types.h
E 7
D 8
gio.o: pk.h
E 8
D 7
gio.o: /usr/include/setjmp.h
E 7
gio.o: uucp.h
I 8
gio.o: pk.h
I 10
gio.o: /usr/include/setjmp.h
E 10
E 8
gnamef.o: gnamef.c
gnamef.o: uucp.h
E 13
I 13
D 15
gnamef.o: gnamef.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gnamef.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 13
I 10
gnamef.o: /usr/include/sys/dir.h
E 15
E 10
D 7
gnamef.o: /usr/include/sys/types.h
D 2
gnamef.o: /usr/include/dir.h
E 2
I 2
gnamef.o: /usr/include/sys/dir.h
E 7
E 2
D 13
gnsys.o: gnsys.c
gnsys.o: uucp.h
I 10
gnsys.o: /usr/include/sys/dir.h
E 10
D 7
gnsys.o: /usr/include/sys/types.h
D 2
gnsys.o: /usr/include/dir.h
E 2
I 2
gnsys.o: /usr/include/sys/dir.h
E 7
E 2
gnxseq.o: gnxseq.c
gnxseq.o: uucp.h
D 7
gnxseq.o: /usr/include/sys/types.h
D 2
gnxseq.o: /usr/include/time.h
E 2
I 2
gnxseq.o: /usr/include/sys/time.h
E 7
E 2
D 10
gwd.o: gwd.c
gwd.o: uucp.h
E 10
I 10
gnxseq.o: /usr/include/sys/time.h
E 10
D 7
gwd.o: /usr/include/signal.h
E 7
imsg.o: imsg.c
imsg.o: uucp.h
I 8
index.o: index.c
I 10
index.o: /usr/include/stdio.h
E 10
E 8
D 7
index.o: index.c
index.o: /usr/include/stdio.h
E 7
ioctl.o: ioctl.c
ioctl.o: uucp.h
I 10
ioctl.o: /usr/include/sgtty.h
E 10
D 7
ioctl.o: /usr/include/sgtty.h
E 7
lastpart.o: lastpart.c
I 10
lastpart.o: uucp.h
E 10
logent.o: logent.c
logent.o: uucp.h
I 10
logent.o: /usr/include/sys/time.h
logent.o: /usr/include/fcntl.h
logent.o: /usr/include/sgtty.h
E 10
D 7
logent.o: /usr/include/sys/types.h
D 2
logent.o: /usr/include/time.h
logent.o: /usr/include/fcntl.h
E 2
I 2
logent.o: /usr/include/sys/time.h
E 2
logent.o: /usr/include/sgtty.h
E 7
mailst.o: mailst.c
I 10
mailst.o: /usr/include/signal.h
E 10
mailst.o: uucp.h
I 8
mkdir.o: mkdir.c
E 8
I 6
D 7
nio.o: nio.c
nio.o: /usr/include/sys/param.h
nio.o: uucp.h
E 7
E 6
pk0.o: pk0.c
I 8
pk0.o: uucp.h
E 8
D 7
pk0.o: /usr/include/stdio.h
D 2
pk0.o: /usr/include/sys/types.h
E 2
pk0.o: pk.p
pk0.o: /usr/include/sys/param.h
E 7
pk0.o: pk.h
D 7
pk0.o: /usr/include/sys/buf.h
E 7
pk1.o: pk1.c
I 10
pk1.o: /usr/include/signal.h
E 10
D 7
pk1.o: /usr/include/stdio.h
D 2
pk1.o: /usr/include/sys/types.h
E 2
pk1.o: pk.p
pk1.o: /usr/include/sys/param.h
E 7
D 8
pk1.o: pk.h
E 8
D 7
pk1.o: /usr/include/sys/buf.h
pk1.o: /usr/include/setjmp.h
pk1.o: /usr/include/signal.h
pkon.o: pkon.c
E 7
I 7
pk1.o: uucp.h
I 8
pk1.o: pk.h
I 10
pk1.o: /usr/include/setjmp.h
pk1.o: /usr/include/sys/time.h
E 13
I 13
gnxseq.o: gnxseq.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
gnxseq.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
getargs.o: getargs.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
getargs.o: /usr/include/sys/timeb.h /usr/include/syslog.h
getprm.o: getprm.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
getprm.o: /usr/include/sys/timeb.h /usr/include/syslog.h
getpwinfo.o: getpwinfo.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
getpwinfo.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/pwd.h
gnxseq.o: gnxseq.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
gnxseq.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
gnxseq.o: /usr/include/sys/time.h /usr/include/time.h
D 19
lastpart.o: lastpart.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
lastpart.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
logent.o: logent.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
logent.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
lastpart.o: lastpart.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
lastpart.o: /usr/include/sys/timeb.h /usr/include/syslog.h
logent.o: logent.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
logent.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
logent.o: /usr/include/sys/time.h /usr/include/time.h /usr/include/fcntl.h
logent.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 19
logent.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 19
I 19
logent.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
logent.o: /usr/include/sys/ttydev.h
E 19
D 15
mailst.o: mailst.c /usr/include/signal.h uucp.h /usr/include/stdio.h
mailst.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
mailst.o: mailst.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
mailst.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
mailst.o: /usr/include/sys/timeb.h
E 19
I 19
mailst.o: /usr/include/stdio.h /usr/include/sys/types.h
mailst.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
E 13
E 10
E 8
E 7
prefix.o: prefix.c
D 7
sdmail.o: sdmail.c
sdmail.o: uucp.h
sdmail.o: /usr/include/pwd.h
E 7
D 13
setline.o: setline.c
setline.o: uucp.h
E 13
I 13
D 19
setline.o: setline.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
setline.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
I 17
strpbrk.o: strpbrk.c
E 17
E 13
I 10
D 16
strpbrk.o: strpbrk.c
E 16
E 10
D 2
setline.o: /usr/include/termio.h
E 2
D 8
shio.o: shio.c
shio.o: uucp.h
E 8
D 7
shio.o: /usr/include/signal.h
E 7
D 13
subdir.o: subdir.c
subdir.o: uucp.h
sysacct.o: sysacct.c
I 10
sysacct.o: /usr/include/sys/types.h
E 10
D 7
sysacct.o: /usr/include/sys/types.h
E 7
systat.o: systat.c
systat.o: uucp.h
D 7
systat.o: /usr/include/sys/types.h
E 7
I 7
tio.o: tio.c
I 10
tio.o: /usr/include/signal.h
E 10
tio.o: uucp.h
I 10
tio.o: /usr/include/setjmp.h
tio.o: /usr/include/sys/stat.h
E 10
E 7
ulockf.o: ulockf.c
ulockf.o: uucp.h
I 10
ulockf.o: /usr/include/sys/stat.h
E 10
D 7
ulockf.o: /usr/include/sys/types.h
ulockf.o: /usr/include/sys/stat.h
E 7
uuclean.o: uuclean.c
I 10
uuclean.o: /usr/include/signal.h
E 10
uuclean.o: uucp.h
I 10
uuclean.o: /usr/include/pwd.h
uuclean.o: /usr/include/sys/stat.h
uuclean.o: /usr/include/sys/dir.h
E 10
D 7
uuclean.o: /usr/include/signal.h
uuclean.o: /usr/include/pwd.h
uuclean.o: /usr/include/sys/types.h
uuclean.o: /usr/include/sys/stat.h
D 2
uuclean.o: /usr/include/dir.h
E 2
I 2
uuclean.o: /usr/include/sys/dir.h
E 7
E 2
uucp.o: uucp.c
uucp.o: uucp.h
I 10
uucp.o: /usr/include/sys/stat.h
E 10
D 7
uucp.o: /usr/include/sys/types.h
uucp.o: /usr/include/sys/stat.h
E 7
I 7
uucp.o: uust.h
uucpd.o: uucpd.c
uucpd.o: uucp.h
I 10
uucpd.o: /usr/include/netdb.h
uucpd.o: /usr/include/signal.h
uucpd.o: /usr/include/errno.h
uucpd.o: /usr/include/sys/socket.h
uucpd.o: /usr/include/netinet/in.h
uucpd.o: /usr/include/sys/wait.h
uucpd.o: /usr/include/sys/ioctl.h
uucpd.o: /usr/include/pwd.h
uucpd.o: /usr/include/lastlog.h
uucpd.o: /usr/include/utmp.h
uucpd.o: /usr/include/fcntl.h
E 10
E 7
uucpdefs.o: uucpdefs.c
uucpdefs.o: uucp.h
uucpname.o: uucpname.c
uucpname.o: uucp.h
E 13
I 13
subdir.o: subdir.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
subdir.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
setline.o: setline.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
setline.o: /usr/include/sys/timeb.h /usr/include/syslog.h
subdir.o: subdir.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
subdir.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
sysacct.o: sysacct.c /usr/include/sys/types.h
D 19
systat.o: systat.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
systat.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
ulockf.o: ulockf.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
ulockf.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
systat.o: systat.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
systat.o: /usr/include/sys/timeb.h /usr/include/syslog.h
ulockf.o: ulockf.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
ulockf.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
ulockf.o: /usr/include/sys/stat.h /usr/include/errno.h
D 19
uucpdefs.o: uucpdefs.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucpdefs.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
uucpname.o: uucpname.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
uucpname.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
E 19
I 19
uucpdefs.o: uucpdefs.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uucpdefs.o: /usr/include/sys/timeb.h /usr/include/syslog.h
uucpname.o: uucpname.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
uucpname.o: /usr/include/sys/timeb.h /usr/include/syslog.h
E 19
E 13
I 10
uucpname.o: /usr/include/sys/stat.h
E 10
D 7
uucpname.o: /usr/include/sys/types.h
uucpname.o: /usr/include/sys/stat.h
E 7
D 2
uucpname.o: /usr/include/UNET/unetio.h
uucpname.o: /usr/include/sys/utsname.h
uucpname.o: /usr/include/whoami.h
E 2
D 13
uudecode.o: uudecode.c
I 10
uudecode.o: /usr/include/stdio.h
uudecode.o: /usr/include/pwd.h
uudecode.o: /usr/include/sys/types.h
uudecode.o: /usr/include/sys/stat.h
E 10
D 7
uudecode.o: /usr/include/stdio.h
uudecode.o: /usr/include/pwd.h
uudecode.o: /usr/include/sys/types.h
uudecode.o: /usr/include/sys/stat.h
E 7
uuencode.o: uuencode.c
I 10
uuencode.o: /usr/include/stdio.h
uuencode.o: /usr/include/sys/types.h
uuencode.o: /usr/include/sys/stat.h
E 10
D 7
uuencode.o: /usr/include/stdio.h
uuencode.o: /usr/include/sys/types.h
uuencode.o: /usr/include/sys/stat.h
E 7
uulog.o: uulog.c
uulog.o: uucp.h
uuname.o: uuname.c
uuname.o: uucp.h
I 10
uuname.o: /usr/include/signal.h
E 10
D 7
uuname.o: /usr/include/signal.h
E 7
uupoll.o: uupoll.c
uupoll.o: uucp.h
I 7
uuq.o: uuq.c
uuq.o: uucp.h
I 10
uuq.o: /usr/include/stdio.h
uuq.o: /usr/include/sys/dir.h
uuq.o: /usr/include/sys/stat.h
E 10
E 7
uusend.o: uusend.c
I 10
uusend.o: /usr/include/stdio.h
uusend.o: /usr/include/pwd.h
uusend.o: /usr/include/sys/types.h
uusend.o: /usr/include/sys/stat.h
E 10
D 7
uusend.o: /usr/include/stdio.h
uusend.o: /usr/include/pwd.h
uusend.o: /usr/include/sys/types.h
uusend.o: /usr/include/sys/stat.h
E 7
uusnap.o: uusnap.c
uusnap.o: uucp.h
I 10
uusnap.o: /usr/include/sys/stat.h
uusnap.o: /usr/include/sys/dir.h
uusnap.o: /usr/include/ctype.h
E 10
D 7
uusnap.o: /usr/include/sys/types.h
uusnap.o: /usr/include/sys/stat.h
D 2
uusnap.o: /usr/include/dir.h
E 2
I 2
uusnap.o: /usr/include/sys/dir.h
E 7
E 2
uux.o: uux.c
uux.o: uucp.h
uuxqt.o: uuxqt.c
uuxqt.o: uucp.h
I 10
uuxqt.o: /usr/include/sys/stat.h
uuxqt.o: /usr/include/sys/dir.h
uuxqt.o: /usr/include/signal.h
E 10
D 7
uuxqt.o: /usr/include/sys/types.h
uuxqt.o: /usr/include/sys/stat.h
D 2
uuxqt.o: /usr/include/dir.h
E 2
I 2
uuxqt.o: /usr/include/sys/dir.h
E 7
E 2
versys.o: versys.c
versys.o: uucp.h
I 10
versys.o: /usr/include/stdio.h
versys.o: /usr/include/ctype.h
E 10
xqt.o: xqt.c
I 10
xqt.o: /usr/include/signal.h
E 10
xqt.o: uucp.h
D 7
xqt.o: /usr/include/signal.h
E 7
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 13
I 13
D 19
versys.o: versys.c uucp.h /usr/include/stdio.h /usr/include/sysexits.h
versys.o: /usr/include/sys/types.h /usr/include/sys/timeb.h
versys.o: /usr/include/stdio.h /usr/include/ctype.h
E 19
I 19
versys.o: versys.c uucp.h /usr/include/stdio.h /usr/include/sys/types.h
versys.o: /usr/include/sys/timeb.h /usr/include/syslog.h /usr/include/stdio.h
versys.o: /usr/include/ctype.h
E 19
D 15
xqt.o: xqt.c /usr/include/signal.h uucp.h /usr/include/stdio.h
xqt.o: /usr/include/sysexits.h /usr/include/sys/types.h
E 15
I 15
xqt.o: xqt.c /usr/include/signal.h /usr/include/machine/trap.h uucp.h
D 19
xqt.o: /usr/include/stdio.h /usr/include/sysexits.h /usr/include/sys/types.h
E 15
xqt.o: /usr/include/sys/timeb.h
E 19
I 19
xqt.o: /usr/include/stdio.h /usr/include/sys/types.h /usr/include/sys/timeb.h
xqt.o: /usr/include/syslog.h
E 19

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 13
E 1

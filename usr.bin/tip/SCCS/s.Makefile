h39650
s 00097/00039/00064
d D 5.4 87/06/18 23:47:22 bostic 20 19
c new template
e
s 00002/00000/00101
d D 5.3 87/05/31 21:33:23 bostic 19 18
c added depend label
e
s 00005/00003/00096
d D 5.2 86/04/03 17:09:44 donn 18 17
c Add define for Kirk Smith's USR Courier driver.  Change default baud
c rate from 300 to 1200.
e
s 00006/00001/00093
d D 5.1 85/06/06 09:47:26 dist 17 16
c Add copyright
e
s 00001/00001/00093
d D 4.14 85/06/01 14:08:29 edward 16 15
c install with -s
e
s 00001/00001/00093
d D 4.13 85/04/11 16:39:35 miriam 15 14
c Include hayes driver.
e
s 00001/00001/00093
d D 4.12 83/10/30 21:35:39 sam 14 13
c 
e
s 00002/00001/00092
d D 4.11 83/06/25 02:23:05 sam 13 12
c must rm before ln
e
s 00001/00000/00092
d D 4.10 83/06/25 02:12:59 sam 12 11
c include aculib in cleanup
e
s 00041/00034/00051
d D 4.9 83/06/25 02:09:08 sam 11 10
c new file organization
e
s 00010/00007/00075
d D 4.8 83/06/15 13:54:01 ralph 10 9
c changes for local info, parity, vadic auto dialers
e
s 00013/00014/00069
d D 4.7 82/11/07 02:25:36 sam 9 6
c cleanup install
e
s 00000/00000/00083
d R 4.7 82/11/07 02:22:26 sam 8 6
c put it in usr/bin since it replaces cu
e
s 00000/00000/00083
d R 4.7 82/11/07 02:21:03 sam 7 6
c since it replaces cu, put it in usr/bin
e
s 00002/00013/00081
d D 4.6 82/11/07 02:16:22 sam 6 5
c update for inclusion in 4.2
e
s 00017/00013/00077
d D 4.5 82/07/29 14:36:40 shannon 5 4
c Sun version and make install fixes
e
s 00002/00002/00088
d D 4.4 82/01/06 13:44:39 root 4 3
c do chmod last in install
e
s 00004/00004/00086
d D 4.3 82/01/06 11:07:52 root 3 2
c local version
e
s 00002/00001/00088
d D 4.2 81/11/29 22:58:57 sam 2 1
c fix comments
e
s 00089/00000/00000
d D 4.1 81/11/29 22:57:48 sam 1 0
c date and time created 81/11/29 22:57:48 by sam
e
u
U
t
T
I 1
D 17
#	%M%	%I%	%E%
E 17
I 17
#
D 20
# Copyright (c) 1983 Regents of the University of California.
E 20
I 20
# Copyright (c) 1987 Regents of the University of California.
E 20
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 20
#	%W% (Berkeley) %G%
E 20
I 20
#	%W%	(Berkeley)	%G%
E 20
E 17
#
D 11
# makefile for intermachine communications package
E 11
I 11
# make file for intermachine communications package
E 11
#
# Files are:
#	/etc/remote		remote host description file
#	/etc/phones		phone number file, owned by ${OWNER} and
D 11
#				  mode 644
E 11
I 11
#				  mode 6??
E 11
#	${ADM}/aculog		ACU accounting file, owned by ${OWNER} and
D 11
#				  mode 644 {if ACULOG defined}
E 11
I 11
#				  mode 6?? {if ACULOG defined}
E 11
# Presently supports:
#	BIZCOMP
#	DEC DF02-AC, DF03-AC
D 2
#	DEC DN-11/Able Quadracall {untested}
E 2
I 2
#	DEC DN-11/Able Quadracall
I 18
#	HAYES and Hayes emulators
#	USR COURIER (2400 baud)
E 18
D 11
#	VENTEL intelligent modem
I 10
#	VADIC 831 semi-smart modem
E 11
I 11
#	VENTEL 212+
#	VADIC 831 RS232 adaptor
E 11
#	VADIC 3451
I 11
# (drivers are located in aculib.a)
E 11
E 10
E 2
#
# Configuration defines:
#	DF02, DF03, DN11	ACU's supported
D 10
#	  BIZ1031, BIZ1022, VENTEL
E 10
I 10
D 11
#	  BIZ1031, BIZ1022, VENTEL, V831, VADIC
E 11
I 11
D 18
#	  BIZ1031, BIZ1022, VENTEL, V831, V3451
E 18
I 18
#	  BIZ1031, BIZ1022, VENTEL, V831, V3451, HAYES, COURIER
E 18
E 11
E 10
#	ACULOG			turn on tip logging of ACU use
#	PRISTINE		no phone #'s put in ACU log file
#	CONNECT			worthless command
#	DEFBR			default baud rate to make connection at
#	DEFFS			default frame size for FTP buffering of
#				writes on local side
#	BUFSIZ			buffer sizing from stdio, must be fed
#				explicitly to remcap.c if not 1024
I 5
D 11
#	VMUNIX			allow VMUNIX tty stuff and job control
E 11
E 5
D 20

E 20
D 5
ADM=/usr/adm
BIN=/usr/bin
E 5
I 5
D 9
ADM=${DESTDIR}/usr/adm
D 6
BIN=${DESTDIR}/usr/bin
E 6
I 6
BIN=${DESTDIR}/usr/ucb
E 6
E 5
OWNER=uucp
D 3
CFLAGS=-O -DVMUNIX -DDEFBR=300 -DDEFFS=BUFSIZ -DDF02 -DVENTEL
E 3
I 3
D 5
CFLAGS=-O -DVMUNIX -DDEFBR=300 -DDEFFS=BUFSIZ -DDF02 -DDF03 -DACULOG
E 3
LDFLAGS=-z
E 5
I 5
CFLAGS=-O -DDEFBR=300 -DDEFFS=BUFSIZ -DVENTEL -DACULOG
E 9
I 9
ADM=	usr/adm
D 20
OWNER=	uucp
D 10
CFLAGS=	-O -DDEFBR=300 -DDEFFS=BUFSIZ -DVENTEL -DACULOG
E 10
I 10
GROUP=	daemon
E 20
D 11
CFLAGS=	-O -DDEFBR=300 -DDEFFS=BUFSIZ -DVMUNIX -DACULOG -DV831
E 11
I 11
D 15
CONFIG=	-DV831 -DVENTEL
E 15
I 15
D 18
CONFIG=	-DV831 -DVENTEL -DHAYES
E 15
D 14
CFLAGS=	-O -DDEFBR=300 -DDEFFS=BUFSIZ -DACULOG
E 14
I 14
CFLAGS=	-O -DDEFBR=300 -DDEFFS=BUFSIZ -DACULOG -DPRISTINE
E 18
I 18
CONFIG=	-DV831 -DVENTEL -DHAYES -DCOURIER
CFLAGS=	-O -DDEFBR=1200 -DDEFFS=BUFSIZ -DACULOG -DPRISTINE
E 18
E 14
E 11
E 10
E 9
D 20
LDFLAGS=
E 5
D 11
OBJECTS=acu.o acutab.o biz22.o biz31.o cmds.o cmdtab.o cu.o df.o dn11.o hunt.o \
D 10
	lock.o log.o remote.o tip.o tipout.o value.o vars.o ventel.o
E 10
I 10
	lock.o log.o remote.o tip.o tipout.o value.o vars.o ventel.o v831.o \
	chartab.o
E 10
SOURCES=acu.c acutab.c biz22.c biz31.c cmds.c cmdtab.c cu.c df.c dn11.c hunt.c \
	lock.c log.c remcap.c remote.c tip.c tipout.c uucplock.c value.c  \
D 10
	vars.c ventel.c
E 10
I 10
	vars.c ventel.c v831.c chartab.c
E 11
I 11
OBJS=	acu.o cmds.o cmdtab.o cu.o hunt.o \
	log.o partab.o remote.o tip.o tipout.o value.o vars.o
SPECIAL=acutab.c remcap.c uucplock.c
DRIVERS=aculib/*.c
SOURCES=acu.c acutab.c cmds.c cmdtab.c cu.c hunt.c \
	log.c partab.c remote.c tip.c tipout.c value.c vars.c \
	${SPECIAL} ${DRIVERS}
E 11
E 10
I 5
D 6
MANS=tip.1 remote.5 phones.5
E 6
E 5
D 9
CXREF=/usr/ucb/ctags -xw
E 9
I 9
CXREF=	/usr/ucb/ctags -xw
E 20
I 20
LIBC=	/lib/libc.a
SRCS=	acu.c acutab.c cmds.c cmdtab.c cu.c hunt.c log.c partab.c remcap.c \
	remote.c tip.c tipout.c uucplock.c value.c vars.c
OBJS=	acu.o acutab.o cmds.o cmdtab.o cu.o hunt.o log.o partab.o remcap.o \
	remote.o tip.o tipout.o uucplock.o value.o vars.o
E 20
E 9
D 6
DIST=./dist
E 6

D 11
tip:	${OBJECTS} remcap.o uucplock.o
	${CC} -o tip ${LDFLAGS} ${OBJECTS} remcap.o uucplock.o
	rm -f cu
	ln tip cu
E 11
I 11
D 20
tip:	${OBJS} acutab.o remcap.o uucplock.o aculib/aculib.a
	${CC} -o tip ${LDFLAGS} ${OBJS} acutab.o remcap.o uucplock.o \
		aculib/aculib.a
E 20
I 20
all: aculib/aculib.a tip
E 20
E 11

D 11
all:	tip aculog
E 11
I 11
D 20
${OBJS}: tip.h
E 20
I 20
tip: ${OBJS} ${LIBC}
	${CC} -o $@ ${OBJS} aculib/aculib.a
E 20
E 11

D 11
install: all
E 11
I 11
remcap.o: remcap.c
	${CC} -c -DBUFSIZ=1024 ${CFLAGS} remcap.c

I 19
D 20
depend:

E 20
E 19
# acutab is configuration dependent, and so depends on the makefile
acutab.o: Makefile
acutab.o: acutab.c
	${CC} -c ${CFLAGS} ${CONFIG} acutab.c

# remote.o depends on the makefile because of DEFBR and DEFFS
D 20
remote.o: Makefile

E 20
# log.o depends on the makefile because of ACULOG
D 20
log.o:	Makefile
E 20
I 20
log.o remote.o: Makefile
E 20

D 20
aculib/aculib.a: ${DRIVERS}
E 20
I 20
aculib/aculib.a: FRC
E 20
	cd aculib; make ${MFLAGS}

D 20
install: tip
E 11
D 9
	cp tip ${BIN}/tip
D 4
	chmod 4711 ${BIN}/tip
E 4
	chown ${OWNER} ${BIN}/tip
I 4
	chmod 4711 ${BIN}/tip
E 4
D 5
	cp aculog /etc/aculog
D 3
	cp /dev/null ${ADM}/aculog
E 3
I 3
D 4
	chmod 4711 /etc/aculog
E 4
	chown ${OWNER} /etc/aculog
I 4
	chmod 4711 /etc/aculog
E 5
I 5
#	cp aculog /etc/aculog
#	chown ${OWNER} /etc/aculog
#	chmod 4711 /etc/aculog
E 5
E 4
#	cp /dev/null ${ADM}/aculog
E 3
D 5
	chown ${OWNER} ${ADM}/aculog
	chmod 600 ${ADM}/aculog
	@echo "create /etc/remote and /etc/phones"
E 5
I 5
#	chown ${OWNER} ${ADM}/aculog
#	chmod 600 ${ADM}/aculog
E 9
I 9
D 10
	install tip ${DESTDIR}/usr/bin/tip
	chown ${OWNER} ${DESTDIR}/usr/bin/tip
	chmod 4711 ${DESTDIR}/usr/bin/tip
E 10
I 10
D 16
	install -m 4711 -o ${OWNER} -g ${GROUP} tip ${DESTDIR}/usr/bin/tip
E 16
I 16
	install -s -m 4711 -o ${OWNER} -g ${GROUP} tip ${DESTDIR}/usr/bin/tip
E 20
I 20
clean: FRC
	rm -f ${OBJS} core tip
	cd aculib; make ${MFLAGS} clean

depend: FRC
	mkdep ${CFLAGS} ${SRCS}
	cd aculib; make ${MFLAGS} depend

install: FRC
	cd aculib; make ${MFLAGS} install
	install -s -o uucp -g daemon -m 4711 tip ${DESTDIR}/usr/bin/tip
E 20
E 16
D 13
	ln /usr/bin/tip /usr/bin/cu
E 13
I 13
	rm -f ${DESTDIR}/usr/bin/cu
	ln ${DESTDIR}/usr/bin/tip ${DESTDIR}/usr/bin/cu
E 13
E 10
D 11
#	install aculog ${DESTDIR}/etc/aculog
#	chown ${OWNER} ${DESTDIR}/etc/aculog
#	chmod 4711 ${DESTDIR}/etc/aculog
E 11
#	cp /dev/null ${DESTDIR}/${ADM}/aculog
#	chown ${OWNER} ${DESTDIR}/${ADM}/aculog
#	chmod 600 ${DESTDIR}/${ADM}/aculog
E 9
D 6
#	@echo "create /etc/remote and /etc/phones"
E 6
I 6
D 11
	@echo "create /etc/remote and /etc/phones"
E 11
I 11
#	@echo "create /etc/remote and /etc/phones"
E 11
E 6
E 5

D 11
aculog:	aculog.c
	${CC} -o aculog ${LDFLAGS} aculog.c
D 3
	chmod 4711 aculog
	chown ${OWNER} aculog
E 3

${OBJECTS}: tip.h

remcap.o: remcap.c
	${CC} -c -DBUFSIZ=1024 ${CFLAGS} remcap.c

E 11
D 20
tags:	${SOURCES} tip.h
	ctags -w ${SOURCES} tip.h
E 20
I 20
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 20

D 20
clean:
I 12
	cd aculib; make ${MFLAGS} clean
E 12
D 11
	rm -f aculog tip cu *.o
E 11
I 11
	rm -f tip cu *.o
E 20
I 20
tags: FRC
	ctags ${SRCS}
E 20
E 11

D 20
print:
	@pr README TODO makefile
	@size *.o | pr -h SIZES
D 11
	@${CXREF} ${SOURCES} tip.h | pr -h XREF
E 11
I 11
	@${CXREF} tip.h ${SOURCES} | pr -h XREF
E 11
	@ls -l | pr 
	@pr tip.h ${SOURCES}
E 20
I 20
FRC:
E 20

D 20
lint:
	-lint -hbacvx ${CFLAGS} ${SOURCES}
E 20
I 20
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

acu.o: acu.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
acu.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
acu.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
acu.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
acu.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
acutab.o: acutab.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
acutab.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
acutab.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
acutab.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
acutab.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
cmds.o: cmds.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
cmds.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
cmds.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmds.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
cmds.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
cmdtab.o: cmdtab.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
cmdtab.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
cmdtab.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
cmdtab.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
cmdtab.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
cu.o: cu.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
cu.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
cu.o: /usr/include/sys/ttydev.h /usr/include/signal.h /usr/include/stdio.h
cu.o: /usr/include/pwd.h /usr/include/ctype.h /usr/include/setjmp.h
cu.o: /usr/include/errno.h
hunt.o: hunt.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
hunt.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
hunt.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
hunt.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
hunt.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
log.o: log.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
log.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
log.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
log.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
log.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
partab.o: partab.c
remcap.o: remcap.c /usr/include/sys/file.h /usr/include/ctype.h
remote.o: remote.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
remote.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
remote.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
remote.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
remote.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
tip.o: tip.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
tip.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
tip.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tip.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
tip.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
tipout.o: tipout.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
tipout.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
tipout.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
tipout.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
tipout.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
uucplock.o: uucplock.c /usr/include/sys/types.h /usr/include/sys/stat.h
uucplock.o: /usr/include/stdio.h
value.o: value.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
value.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
value.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
value.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
value.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h
vars.o: vars.c tip.h /usr/include/sys/types.h /usr/include/sys/file.h
vars.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
vars.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
vars.o: /usr/include/signal.h /usr/include/stdio.h /usr/include/pwd.h
vars.o: /usr/include/ctype.h /usr/include/setjmp.h /usr/include/errno.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 20
D 6

distribution:
	-if test ! -d ${DIST} ; then mkdir ${DIST} ; else rm -f ${DIST}/* ; fi
	cp ${SOURCES} tip.h makefile README TODO ${DIST}
D 5
	cp remote-file phones-file tip.1 ${DIST}
	cd ${DIST}; tar cf dist.tar README TODO tip.h ${SOURCES} makefile \
		remote-file phones-file tip.1
E 5
I 5
	cp remote-file phones-file ${MANS} ${DIST}

tape:
	cd ${DIST}; tar c README TODO tip.h ${SOURCES} makefile \
		remote-file phones-file ${MANS}
E 6
E 5
E 1

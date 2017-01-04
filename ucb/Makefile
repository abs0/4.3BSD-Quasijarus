#
# Copyright (c) 1980, 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	@(#)Makefile	5.36 (Berkeley) 10/10/10
#
DESTDIR=
CFLAGS=	-O
LIBC=	/lib/libc.a

# Programs that live in subdirectories, and have makefiles of their own.
#
# fp removed; it doesn't work
SUBDIR=	Mail compress ctags dbx error ex ftp gprof grep indent man \
	more mroff msgs netstat pascal pstpipe psutils rdist sendbug systat \
	talk telnet tftp tn3270 tset vfont2ps vgrind vtools sysline window

# Shell scripts that need only be installed and are never removed.
#
SCRIPT= vtroff which

# C source that lives in the current directory
#
SRCS=	20b.c apply.c biff.c checknr.c clear.c colcrt.c colrm.c eps.c expand.c \
	finger.c fold.c from.c gcore.c groups.c head.c iso2koi8e.c koi8e2iso.c \
	last.c lastcomm.c leave.c lock.c logger.c mkstr.c printenv.c \
	quota.c rlogin.c rsh.c rt2unix.c ruptime.c rusdos2unix.c rusunix2dos.c \
	rwho.c sccs.c script.c soelim.c strings.c symorder.c tail.c tcopy.c \
	ul.c unexpand.c unifdef.c unix2rt.c users.c vacation.c \
	vmstat.c w.c wc.c whereis.c whoami.c whois.c xstr.c yes.c

# C programs that live in the current directory and do not need
# explicit make lines.
#
STD=	20b apply biff checknr colcrt colrm expand finger fold from \
	groups head iso2koi8e koi8e2iso last lastcomm leave lock logger mkstr \
	printenv rt2unix ruptime rusdos2unix rusunix2dos rwho sccs \
	script soelim strings symorder tail tcopy unexpand unifdef \
	unix2rt users whereis whoami whois wc xstr yes

# C programs that live in the current directory and need explicit make lines.
#
NSTD=	clear ul vacation

# Programs that get installed with special permissions
#
PERM=	eps gcore quota rlogin rsh vmstat w

all:	${SUBDIR} ${STD} ${NSTD} ${PERM}

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

${STD} ${PERM}: ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c

install:
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
	-for i in ${SCRIPT}; do \
		(install -c -o bin -g bin -m 755 $$i.csh ${DESTDIR}/usr/ucb/$$i); done
	install -s -o bin -g bin -m 755 ${STD} ${NSTD} ${DESTDIR}/usr/ucb
	install -s -o root -g bin -m 4755 quota ${DESTDIR}/usr/ucb/quota
	install -s -o root -g bin -m 4755 rlogin ${DESTDIR}/usr/ucb/rlogin
	install -s -o root -g bin -m 4755 rsh ${DESTDIR}/usr/ucb/rsh
	install -s -o root -g bin -m 4755 eps ${DESTDIR}/usr/ucb/eps
	install -s -o bin -g kmem -m 2755 gcore ${DESTDIR}/usr/ucb/gcore
	install -s -o bin -g kmem -m 2755 vmstat ${DESTDIR}/usr/ucb/vmstat
	install -s -o bin -g kmem -m 2755 w ${DESTDIR}/usr/ucb/w
	rm -f ${DESTDIR}/usr/ucb/uptime ${DESTDIR}/usr/ucb/f
	ln ${DESTDIR}/usr/ucb/w ${DESTDIR}/usr/ucb/uptime
	ln ${DESTDIR}/usr/ucb/finger ${DESTDIR}/usr/ucb/f
	rm -f ${DESTDIR}/usr/ucb/u
	ln ${DESTDIR}/usr/ucb/users ${DESTDIR}/usr/ucb/u

clean: FRC
	rm -f a.out core *.s *.o
	rm -f ${STD} ${NSTD} ${PERM}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend: ldepend
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

ldepend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

FRC:

# Files listed in ${NSTD} have explicit make lines given below.

clear:
	${CC} -o $@ ${CFLAGS} clear.c -ltermlib

ul:
	${CC} -o $@ ${CFLAGS} ul.c -ltermlib

vacation:
	${CC} -o $@ ${CFLAGS} vacation.c -ldbm

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

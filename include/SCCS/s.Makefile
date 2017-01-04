h61928
s 00002/00002/00122
d D 5.25 2012/06/23 08:23:36 msokolov 40 39
c timeparse.h added
e
s 00004/00004/00120
d D 5.24 2012/06/22 04:34:03 msokolov 39 38
c new additions: caldate.h and mjdtime.h
e
s 00003/00002/00121
d D 5.23 11/07/13 03:31:48 msokolov 38 37
c calendardefs.h and ctslcal.h added
e
s 00003/00003/00120
d D 5.22 99/10/09 21:43:08 msokolov 37 36
c By default copy /sys and others instead of symlinking so that the system as
c distributed is usable without the sources.
c Also remove the unnecessary "./" in front of the machine symlink and make
c /usr/include/sys mode 755.
e
s 00002/00001/00121
d D 5.21 99/01/18 00:23:14 msokolov 36 35
c add zconf.h and zlib.h
e
s 00001/00001/00121
d D 5.20 88/05/21 18:17:31 bostic 35 33
c remove syscall.h
e
s 00001/00001/00121
d R 5.20 88/03/24 14:44:46 bostic 34 33
c remove sysexits.h
e
s 00001/00001/00121
d D 5.19 87/09/29 13:31:48 bostic 33 32
c add regexp.h
e
s 00041/00021/00081
d D 5.18 87/06/03 01:59:15 bostic 32 29
c tahoe/vax fixes
e
s 00002/00002/00118
d R 5.19 87/05/30 15:43:38 bostic 31 30
c fixed symlinks
e
s 00039/00021/00081
d R 5.18 87/05/28 17:59:55 bostic 30 29
c machine independent symlink install
e
s 00001/00001/00101
d D 5.17 87/05/12 22:13:13 karels 29 28
c rm stand
e
s 00001/00001/00101
d D 5.16 87/03/04 17:04:37 bostic 28 27
c added tzfile.h
e
s 00006/00002/00096
d D 5.15 86/10/13 17:03:47 sam 27 26
c add tahoe
e
s 00001/00001/00097
d D 5.14 86/05/28 19:26:55 bloom 26 25
c fix to handle sh conditionals correctly
e
s 00015/00003/00083
d D 5.13 86/05/11 15:52:47 karels 25 24
c don't be so messy if non-root runs this
e
s 00001/00001/00085
d D 5.12 86/04/26 00:10:43 mckusick 24 23
c add resolv.h
e
s 00001/00001/00085
d D 5.11 86/03/26 16:26:13 mckusick 23 22
c ptrace.h moves to /sys/h
e
s 00002/00002/00084
d D 5.10 86/01/10 18:39:28 lepreau 22 21
c ignore piped tar's bitching
e
s 00002/00002/00084
d D 5.9 85/08/08 18:53:04 mckusick 21 20
c must use -B option to tar
e
s 00002/00002/00084
d D 5.8 85/08/08 14:22:37 kre 20 19
c deleted nameser.h and resolv.h (now in arpa/...)
e
s 00004/00004/00082
d D 5.7 85/08/08 14:17:41 kre 19 18
c added string.h & memory.h (sys5 compat stuff)
e
s 00001/00001/00085
d D 5.6 85/06/25 19:05:35 kre 18 17
c ditched dbm.h, that's maintained in usr.lib/libdbm now.
e
s 00005/00005/00081
d D 5.5 85/06/18 22:21:33 mckusick 17 16
c dumprestor.h moves to /usr/include/protocols/dumprestore.h
e
s 00003/00003/00083
d D 5.4 85/06/18 22:00:12 mckusick 16 15
c add protocols and netns subdirs; add time.h
e
s 00005/00003/00081
d D 5.3 85/06/06 17:46:54 kre 15 14
c don't copy files unless they've changed; expunge netpup
e
s 00008/00000/00076
d D 5.2 85/05/30 23:08:28 sam 14 13
c add tags
e
s 00006/00001/00070
d D 5.1 85/05/30 09:45:11 dist 13 12
c Add copyright
e
s 00002/00002/00069
d D 4.12 85/03/19 14:50:25 ralph 12 11
c added pcc.h for /lib/f1 opcode definitions
e
s 00002/00002/00069
d D 4.11 85/03/12 12:30:19 ralph 11 10
c syslog.h moved to sys/syslog.h
e
s 00002/00002/00069
d D 4.10 85/03/01 10:22:17 ralph 10 9
c added nameser.h and resolv.h for the domain name server
e
s 00001/00001/00070
d D 4.9 84/04/27 10:36:34 ralph 9 8
c added ttyent.h for getttyent(3).
e
s 00001/00001/00070
d D 4.8 84/04/11 09:17:32 ralph 8 7
c added ptrace.h for command defines.
e
s 00001/00001/00070
d D 4.7 83/12/02 15:37:32 ralph 7 6
c added ndbm.h
e
s 00003/00003/00068
d D 4.6 83/08/13 23:46:42 sam 6 5
c fix modes, should never make changes to files in /usr/include, 
c only in /usr/src/include...
e
s 00001/00001/00070
d D 4.5 83/08/11 23:12:27 sam 5 4
c getty.h should have been purged long ago
e
s 00002/00002/00069
d D 4.4 83/07/30 14:05:58 sam 4 3
c almost missed pascal stuff
e
s 00001/00001/00070
d D 4.3 83/07/10 00:01:19 sam 3 2
c string -> strings
e
s 00001/00001/00070
d D 4.2 83/07/03 00:37:22 sam 2 1
c add fcntl.h
e
s 00071/00000/00000
d D 4.1 83/07/01 16:14:31 root 1 0
c date and time created 83/07/01 16:14:31 by root
e
u
U
f b 
t
T
I 1
D 13
#	%M%	%I%	%E%
E 13
I 13
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 19
#	%W% (Berkeley) %G%
E 19
I 19
#	%W% (Berkeley) %E%
E 19
E 13
#
# Doing a make install builds /usr/include
#
# Define SHARED to indicate whether you want
# symbolic links to the system source (``symlinks''),
# or a separate copy (``copies'').
# (latter useful in environments where it's
# not possible to keep /sys publicly readable)
#
# The ``rm -rf''s used below are safe because rm doesn't
# follow symbolic links.
#
DESTDIR=
D 4
SUBDIRS=arpa
E 4
I 4
D 16
SUBDIRS=arpa pascal
E 16
I 16
SUBDIRS=arpa pascal protocols
E 16
E 4
D 7
STD=	a.out.h ar.h assert.h ctype.h curses.h dbm.h \
E 7
I 7
D 17
STD=	a.out.h ar.h assert.h ctype.h curses.h dbm.h ndbm.h \
E 7
D 2
	disktab.h dumprestor.h fstab.h getty.h grp.h \
E 2
I 2
D 5
	disktab.h dumprestor.h fcntl.h fstab.h getty.h grp.h \
E 5
I 5
D 12
	disktab.h dumprestor.h fcntl.h fstab.h grp.h \
E 5
E 2
D 8
	lastlog.h math.h mp.h mtab.h netdb.h nlist.h pwd.h ranlib.h \
E 8
I 8
D 10
	lastlog.h math.h mp.h mtab.h netdb.h nlist.h ptrace.h pwd.h ranlib.h \
E 8
D 3
	setjmp.h sgtty.h stab.h stdio.h string.h \
E 3
I 3
	setjmp.h sgtty.h stab.h stdio.h strings.h \
E 10
I 10
	lastlog.h math.h mp.h mtab.h nameser.h netdb.h nlist.h ptrace.h pwd.h \
E 12
I 12
	disktab.h dumprestor.h fcntl.h fstab.h grp.h lastlog.h \
	math.h mp.h mtab.h nameser.h netdb.h nlist.h pcc.h ptrace.h pwd.h \
E 12
	ranlib.h resolv.h setjmp.h sgtty.h stab.h stdio.h strings.h \
E 10
E 3
D 9
	struct.h syscall.h sysexits.h syslog.h utmp.h varargs.h vfont.h
E 9
I 9
D 11
	struct.h syscall.h sysexits.h syslog.h ttyent.h utmp.h varargs.h vfont.h
E 9
LINKS=	errno.h signal.h
E 11
I 11
D 16
	struct.h syscall.h sysexits.h ttyent.h utmp.h varargs.h vfont.h
E 16
I 16
	struct.h syscall.h sysexits.h time.h ttyent.h utmp.h varargs.h vfont.h
E 17
I 17
D 18
STD=	a.out.h ar.h assert.h ctype.h curses.h dbm.h ndbm.h disktab.h \
E 18
I 18
D 38
STD=	a.out.h ar.h assert.h ctype.h curses.h ndbm.h disktab.h \
E 18
D 19
	fcntl.h fstab.h grp.h lastlog.h math.h mp.h mtab.h nameser.h \
E 19
I 19
D 20
	fcntl.h fstab.h grp.h lastlog.h math.h memory.h mp.h mtab.h nameser.h \
E 19
	netdb.h nlist.h pcc.h ptrace.h pwd.h ranlib.h resolv.h setjmp.h \
E 20
I 20
	fcntl.h fstab.h grp.h lastlog.h math.h memory.h mp.h mtab.h \
E 38
I 38
D 39
STD=	a.out.h ar.h assert.h calendardefs.h ctslcal.h ctype.h curses.h \
	disktab.h \
	fcntl.h fstab.h grp.h lastlog.h math.h memory.h mp.h mtab.h ndbm.h \
E 38
D 23
	netdb.h nlist.h pcc.h ptrace.h pwd.h ranlib.h setjmp.h \
E 23
I 23
D 24
	netdb.h nlist.h pcc.h pwd.h ranlib.h setjmp.h \
E 24
I 24
D 33
	netdb.h nlist.h pcc.h pwd.h ranlib.h resolv.h setjmp.h \
E 33
I 33
	netdb.h nlist.h pcc.h pwd.h ranlib.h regexp.h resolv.h setjmp.h \
E 39
I 39
STD=	a.out.h ar.h assert.h caldate.h calendardefs.h ctslcal.h ctype.h \
	curses.h disktab.h \
	fcntl.h fstab.h grp.h lastlog.h math.h memory.h mjdtime.h mp.h mtab.h \
	ndbm.h netdb.h nlist.h pcc.h pwd.h ranlib.h regexp.h resolv.h setjmp.h \
E 39
E 33
E 24
E 23
E 20
D 19
	sgtty.h stab.h stdio.h strings.h struct.h syscall.h sysexits.h \
	time.h ttyent.h utmp.h varargs.h vfont.h
E 19
I 19
D 35
	sgtty.h stab.h stdio.h string.h strings.h struct.h syscall.h \
E 35
I 35
	sgtty.h stab.h stdio.h string.h strings.h struct.h \
E 35
D 28
	sysexits.h time.h ttyent.h utmp.h varargs.h vfont.h
E 28
I 28
D 36
	sysexits.h time.h ttyent.h tzfile.h utmp.h varargs.h vfont.h
E 36
I 36
D 40
	sysexits.h time.h ttyent.h tzfile.h utmp.h varargs.h vfont.h \
	zconf.h zlib.h
E 40
I 40
	sysexits.h time.h timeparse.h ttyent.h tzfile.h utmp.h varargs.h \
	vfont.h zconf.h zlib.h
E 40
E 36
E 28
E 19
E 17
E 16
LINKS=	errno.h signal.h syslog.h
E 11
D 27
MACHINE=vax
MACHDEP=${MACHINE} vaxif vaxmba vaxuba
E 27
I 27
D 32
#ifdef vax
#MACHINE=vax
#MACHDEP=${MACHINE} vaxif vaxmba vaxuba
#endif
MACHINE=tahoe
MACHDEP=${MACHINE} tahoeif tahoevba tahoemath
E 27
D 15
NETDIRS=net netimp netinet netpup
E 15
I 15
D 16
NETDIRS=net netimp netinet
E 16
I 16
NETDIRS=net netimp netinet netns
E 16
E 15
D 29
SYSDIRS=${NETDIRS} stand ${MACHDEP}
E 29
I 29
SYSDIRS=${NETDIRS} ${MACHDEP}
E 32
I 32

NETDIRS=	net netimp netinet netns
TAHOEDIRS=	tahoe tahoemath tahoevba tahoeif
VAXDIRS=	vax vaxmba vaxuba vaxif
E 32
E 29
D 37
SHARED=	symlinks
E 37
I 37
SHARED=	copies
E 37
I 14
TAGSFILE=tags
E 14

all:

install: ${SHARED}
	-for i in ${STD}; do \
D 6
		install -c -m 644 $$i ${DESTDIR}/usr/include/$$i; \
E 6
I 6
D 15
		install -c -m 444 $$i ${DESTDIR}/usr/include/$$i; \
E 15
I 15
		cmp -s $$i ${DESTDIR}/usr/include/$$i || \
		    install -c -m 444 $$i ${DESTDIR}/usr/include/$$i; \
E 15
E 6
	done
	-for i in ${SUBDIRS}; do \
		if [ ! -d ${DESTDIR}/usr/include/$$i ]; \
		then \
			mkdir ${DESTDIR}/usr/include/$$i; \
		fi; \
D 4
		(cd $$i; for j in *.h; do \
E 4
I 4
		(cd $$i; for j in *.[ih]; do \
I 15
			cmp -s $$j ${DESTDIR}/usr/include/$$i/$$j || \
E 15
E 4
D 6
			install -c -m 644 $$j ${DESTDIR}/usr/include/$$i/$$j; \
E 6
I 6
			install -c -m 444 $$j ${DESTDIR}/usr/include/$$i/$$j; \
E 6
		done); \
	done
I 25
D 26
	cmp -s Makefile.install ${DESTDIR}/usr/include/Makefile || \
E 26
I 26
	-cmp -s Makefile.install ${DESTDIR}/usr/include/Makefile || \
E 26
	    install -c -m 444 Makefile.install ${DESTDIR}/usr/include/Makefile
E 25
	-for i in ${LINKS}; do \
		rm -f ${DESTDIR}/usr/include/$$i; \
		ln -s sys/$$i ${DESTDIR}/usr/include/$$i; \
	done
	rm -f ${DESTDIR}/usr/include/machine
D 37
	ln -s ./${MACHINE} ${DESTDIR}/usr/include/machine
E 37
I 37
	ln -s ${MACHINE} ${DESTDIR}/usr/include/machine
E 37
	rm -f ${DESTDIR}/usr/include/frame.h
	ln -s machine/frame.h ${DESTDIR}/usr/include/frame.h

D 32
symlinks:
D 25
	for i in ${SYSDIRS}; do \
E 25
I 25
	-for i in ${SYSDIRS}; do \
E 32
I 32
symlinks: ${MACHINE}.symlinks
	rm -rf ${DESTDIR}/usr/include/sys
	-if [ ! -s ${DESTDIR}/usr/include/sys ]; \
	then \
		ln -s /sys/h ${DESTDIR}/usr/include/sys; \
	else \
		echo ${DESTDIR}/usr/include/sys not removed; \
	fi

tahoe.symlinks:
	-for i in ${NETDIRS} ${TAHOEDIRS}; do \
E 32
E 25
		rm -rf ${DESTDIR}/usr/include/$$i; \
D 25
		ln -s /sys/$$i ${DESTDIR}/usr/include/$$i; \
E 25
I 25
		if [ ! -s ${DESTDIR}/usr/include/$$i ]; \
		then \
			ln -s /sys/$$i ${DESTDIR}/usr/include/$$i; \
		else \
			echo ${DESTDIR}/usr/include/$$i not removed; \
		fi; \
E 25
	done
D 32
	rm -rf ${DESTDIR}/usr/include/sys
D 25
	ln -s /sys/h ${DESTDIR}/usr/include/sys
E 25
I 25
	-if [ ! -s ${DESTDIR}/usr/include/sys ]; \
	then \
		ln -s /sys/h ${DESTDIR}/usr/include/sys; \
	else \
		echo ${DESTDIR}/usr/include/sys not removed; \
	fi
E 32
E 25

D 32
copies:
D 22
	for i in ${SYSDIRS}; do \
E 22
I 22
	-for i in ${SYSDIRS}; do \
E 32
I 32
vax.symlinks:
	-for i in ${NETDIRS} ${VAXDIRS}; do \
E 32
E 22
		rm -rf ${DESTDIR}/usr/include/$$i; \
D 32
		cd /sys; \
D 15
		tar cf - $$i/*.h | (cd /usr/include; tar xpf -); \
E 15
I 15
D 21
		tar cf - $$i/*.h | (cd ${DESTDIR}/usr/include; tar xpf -); \
E 21
I 21
		tar cf - $$i/*.h | (cd ${DESTDIR}/usr/include; tar xpfB -); \
E 32
I 32
		if [ ! -s ${DESTDIR}/usr/include/$$i ]; \
		then \
			ln -s /sys/$$i ${DESTDIR}/usr/include/$$i; \
		else \
			echo ${DESTDIR}/usr/include/$$i not removed; \
		fi; \
E 32
E 21
E 15
	done
I 32

copies: ${MACHINE}.copies
E 32
	rm -rf ${DESTDIR}/usr/include/sys;
	mkdir ${DESTDIR}/usr/include/sys; 
D 6
	chmod 755 ${DESTDIR}/usr/include/sys;
E 6
I 6
D 37
	chmod 775 ${DESTDIR}/usr/include/sys;
E 37
I 37
	chmod 755 ${DESTDIR}/usr/include/sys;
E 37
E 6
D 21
	(cd /sys/h; tar cf - *.h | (cd ${DESTDIR}/usr/include/sys; tar xpf -))
E 21
I 21
D 22
	(cd /sys/h; tar cf - *.h | (cd ${DESTDIR}/usr/include/sys; tar xpfB -))
E 22
I 22
	-(cd /sys/h; tar cf - *.h | (cd ${DESTDIR}/usr/include/sys; tar xpfB -))
E 22
E 21

I 32
tahoe.copies:
	-for i in ${NETDIRS} ${TAHOEDIRS}; do \
		rm -rf ${DESTDIR}/usr/include/$$i; \
		cd /sys; \
		tar cf - $$i/*.h | (cd ${DESTDIR}/usr/include; tar xpfB -); \
	done

vax.copies:
	-for i in ${NETDIRS} ${VAXDIRS}; do \
		rm -rf ${DESTDIR}/usr/include/$$i; \
		cd /sys; \
		tar cf - $$i/*.h | (cd ${DESTDIR}/usr/include; tar xpfB -); \
	done

E 32
I 14
tags:
	cwd=/usr/include; \
	for i in ${STD} ${LINKS}; do \
		ctags -a -f ${TAGSFILE} $$cwd/$$i; \
	done

E 14
clean:
I 14
	rm -f tags
I 32

depend:
E 32
E 14
E 1

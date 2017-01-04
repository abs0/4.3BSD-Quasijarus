h33241
s 00001/00001/00085
d D 5.18 11/07/13 03:45:45 msokolov 31 30
c libctsl added to SUBDIR
e
s 00007/00000/00079
d D 5.17 04/10/21 01:03:58 msokolov 30 29
c add makewhatis
e
s 00001/00001/00078
d D 5.16 02/05/24 22:29:32 msokolov 29 28
c add ms
e
s 00001/00001/00078
d D 5.15 02/05/24 12:20:53 msokolov 28 27
c man was mysteriously missing from SUBDIRS
e
s 00001/00006/00078
d D 5.14 99/01/18 01:20:14 msokolov 27 26
c add libz
e
s 00009/00004/00075
d D 5.13 88/06/13 10:41:05 bostic 26 25
c add Berkeley copyright notice; libom has been moved to ../old
e
s 00013/00017/00066
d D 5.12 87/07/27 17:10:05 bostic 25 24
c new template
e
s 00023/00029/00060
d D 5.11 87/06/21 16:39:46 bostic 24 23
c new template
e
s 00001/00001/00088
d D 5.10 86/06/07 10:18:07 mckusick 23 22
c add learn
e
s 00003/00001/00086
d D 5.9 85/10/11 17:52:29 mckusick 22 21
c depend on FRC not /tmp
e
s 00001/00001/00086
d D 5.8 85/09/07 16:07:27 mckusick 21 20
c strip on install
e
s 00009/00011/00078
d D 5.7 85/08/26 11:09:05 mckusick 20 19
c new `make depend'; rebuild dependencies
e
s 00001/00001/00088
d D 5.6 85/08/09 21:47:19 mckusick 19 18
c add liby
e
s 00001/00001/00088
d D 5.5 85/06/07 16:40:12 miriam 18 17
c Include libom in the subdirectory list.
e
s 00001/00001/00088
d D 5.4 85/06/06 09:55:40 dist 17 16
c Add copyright
e
s 00007/00007/00082
d D 5.3 85/06/05 20:04:58 mckusick 16 15
c cleanups; -for
e
s 00013/00001/00076
d D 5.2 85/05/30 23:20:20 sam 15 14
c add tags
e
s 00006/00001/00071
d D 5.1 85/04/30 12:27:41 dist 14 13
c Add copyright
e
s 00001/00001/00071
d D 4.12 85/04/29 18:59:58 eric 13 12
c add -me source directory
e
s 00001/00007/00071
d D 4.11 84/08/02 10:26:04 mckusick 12 10
c atrun moves to usr.bin/at subdirectory
e
s 00001/00001/00077
d R 4.11 83/11/10 14:57:06 ralph 11 10
c lib2648 moved to /usr/src/ucb/fed
e
s 00003/00003/00075
d D 4.10 83/07/09 23:37:07 sam 10 9
c let's get it right folks
e
s 00001/00001/00077
d D 4.9 83/07/09 23:34:01 sam 9 8
c someone forgot curses
e
s 00001/00001/00077
d D 4.8 83/07/02 18:36:31 sam 8 7
c include fix
e
s 00001/00001/00077
d D 4.7 83/06/10 23:08:21 sam 7 6
c no more libjobs
e
s 00003/00002/00075
d D 4.6 83/04/02 13:56:03 sam 6 5
c patch destination directory; add bc library
e
s 00002/00002/00075
d D 4.5 83/03/09 15:22:28 ralph 5 4
c removed vpr and added lib2648 subdirectories.
e
s 00007/00001/00070
d D 4.4 83/02/26 13:21:35 sam 4 3
c atrun moved from etc
e
s 00001/00001/00070
d D 4.3 82/12/03 19:54:42 mckusick 3 2
c add lpr
e
s 00002/00002/00069
d D 4.2 82/11/22 18:18:08 mckusick 2 1
c add libU77; libmp moves from lib to usr.lib
e
s 00071/00000/00000
d D 4.1 82/10/21 00:59:12 mckusick 1 0
c date and time created 82/10/21 00:59:12 by mckusick
e
u
U
f b 
t
T
I 1
D 10
#	%W%	(Berkeley)	%G%
E 10
I 10
D 14
#	%M%	%I%	%E%
E 14
I 14
#
D 17
# Copyright (c) 1980 Regents of the University of California.
E 17
I 17
D 24
# Copyright (c) 1983 Regents of the University of California.
E 24
I 24
# Copyright (c) 1987 Regents of the University of California.
E 24
E 17
D 26
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 26
I 26
# All rights reserved.
E 26
#
I 26
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
E 26
#	%W% (Berkeley) %G%
E 14
E 10
#
D 26
DESTDIR=
E 26
CFLAGS=	-O
I 25
LIBC=	/lib/libc.a
E 25
I 15
TAGSFILE=tags
E 15

I 15
# Subdirectories whose routines are included in the making of the
# master tags file (/usr/lib/tags); the Fortran libraries should
# be on this list, but we don't control them....
#
TAGSDIR=libcurses libdbm libln libm libmp libpc libtermlib

E 15
# Programs that live in subdirectories, and have makefiles of their own.
#
D 2
SUBDIR=	libF77 libI77 libdbm libg libjobs libln libm libnm libplot \
	libtermlib sendmail vpr
E 2
I 2
D 5
SUBDIR=	libF77 libI77 libU77 libdbm libg libjobs libln libm libmp \
D 3
	libnm libplot libtermlib sendmail vpr
E 3
I 3
	libnm libplot libtermlib lpr sendmail vpr
E 5
I 5
D 7
SUBDIR=	lib2648 libF77 libI77 libU77 libdbm libg libjobs libln libm libmp \
E 7
I 7
D 10
SUBDIR=	lib2648 libF77 libI77 libU77 libdbm libg libln libm libmp \
E 7
D 9
	libnm libplot libtermlib lpr sendmail
E 9
I 9
	libnm libplot libcurses libtermlib lpr sendmail
E 10
I 10
D 23
SUBDIR=	lib2648 libF77 libI77 libU77 libcurses libdbm libg libln \
E 23
I 23
D 31
SUBDIR=	learn lib2648 libF77 libI77 libU77 libcurses libdbm libg libln \
E 31
I 31
SUBDIR=	learn lib2648 libF77 libI77 libU77 libctsl libcurses libdbm libg libln \
E 31
E 23
D 13
	libm libmp libnm libpc libplot libtermlib lpr sendmail
E 13
I 13
D 16
	libm libmp libnm libpc libplot libtermlib lpr me sendmail
E 16
I 16
D 18
	libm libmp libpc libplot libtermlib lpr me sendmail
E 18
I 18
D 19
	libom libm libmp libpc libplot libtermlib lpr me sendmail
E 19
I 19
D 26
	libom libm libmp libpc libplot libtermlib liby lpr me sendmail
E 26
I 26
D 27
	libm libmp libpc libplot libtermlib liby lpr me sendmail
E 27
I 27
D 28
	libm libmp libpc libplot libtermlib liby libz lpr me sendmail
E 28
I 28
D 29
	libm libmp libpc libplot libtermlib liby libz lpr man me sendmail
E 29
I 29
	libm libmp libpc libplot libtermlib liby libz lpr man me ms sendmail
E 29
E 28
E 27
E 26
E 19
E 18
E 16
E 13
E 10
E 9
E 5
E 3
E 2

D 25
# Shell scripts that need only be installed and are never removed.
#
SCRIPT=	makewhatis

E 25
I 24
# C source that lives in the current directory
#
SRCS=	getNAME.c makekey.c

E 24
# C programs that live in the current directory and do not need
# explicit make lines.
#
D 4
STD=	getNAME makekey
E 4
I 4
D 12
STD=	atrun getNAME makekey
E 12
I 12
STD=	getNAME makekey
E 12
E 4

# C programs that live in the current directory and need explicit make lines.
#
D 24
NSTD=	
E 24
I 24
NSTD=
E 24

D 25
all:	${SUBDIR} ${STD} ${NSTD}
E 25
I 25
all: ${SUBDIR} ${STD} ${NSTD}
E 25

D 22
${SUBDIR}: /tmp
E 22
I 22
${SUBDIR}: FRC
E 22
	cd $@; make ${MFLAGS}
I 22

D 25
FRC:
E 22

${STD}:
E 25
I 25
${STD}: ${LIBC}
E 25
D 24
	cc ${CFLAGS} -o $@ $@.c
E 24
I 24
	${CC} ${CFLAGS} -o $@ $@.c
E 24

D 25
install:
E 25
I 25
install: FRC
E 25
D 16
	for i in ${SUBDIR}; do \
E 16
I 16
	-for i in ${SUBDIR}; do \
E 16
D 24
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
D 6
	for i in ${SCRIPT}; do (install -c $$i.sh ${DESTDIR}/etc/$$i); done
	for i in ${STD} ${NSTD}; do (install $$i ${DESTDIR}/etc/$$i); done
E 6
I 6
D 16
	for i in ${SCRIPT}; do (install -c $$i.sh ${DESTDIR}/usr/lib/$$i); done
	for i in ${STD} ${NSTD}; do (install $$i ${DESTDIR}/usr/lib/$$i); done
E 16
I 16
	-for i in ${SCRIPT}; do (install -c $$i.sh ${DESTDIR}/usr/lib/$$i); done
D 21
	-for i in ${STD} ${NSTD}; do (install $$i ${DESTDIR}/usr/lib/$$i); done
E 21
I 21
	-for i in ${STD} ${NSTD}; do (install -s $$i ${DESTDIR}/usr/lib/$$i); done
E 21
E 16
	install -c lib.b ${DESTDIR}/usr/lib/lib.b
E 24
I 24
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); \
	done
D 25
	-for i in ${SCRIPT}; do \
		(install -c -o bin -g bin -m 755 $$i.sh ${DESTDIR}/usr/lib/$$i); \
	done
E 25
	-for i in ${STD} ${NSTD}; do \
		(install -s -o bin -g bin -m 755 $$i ${DESTDIR}/usr/lib/$$i); \
	done
	install -c -o bin -g bin -m 755 lib.b ${DESTDIR}/usr/lib/lib.b
I 30
	install -c -o bin -g bin -m 755 makewhatis.sh \
		${DESTDIR}/usr/lib/makewhatis
E 30
E 24
E 6

I 15
D 25
tags:
E 25
I 25
tags: FRC
E 25
D 16
	for i in ${TAGSDIR}; do \
E 16
I 16
	-for i in ${TAGSDIR}; do \
E 16
		(cd $$i; make ${MFLAGS} TAGSFILE=../${TAGSFILE} tags); \
	done

E 15
D 25
clean:
E 25
I 25
clean: FRC
E 25
D 15
	rm -f a.out core *.s *.o
E 15
I 15
D 24
	rm -f a.out core *.s *.o tags
E 24
I 24
	rm -f a.out core *.s *.o tags ${STD} ${NSTD}
E 24
E 15
D 16
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 16
I 16
D 25
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 25
I 25
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 25
E 16
D 24
	rm -f ${STD} ${NSTD}
E 24

D 25
depend:
E 25
I 25
depend: ldepend
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done

ldepend: FRC
E 25
D 20
	cat </dev/null >x.c
D 16
	for i in ${STD} ${NSTD}; do \
E 16
I 16
	-for i in ${STD} ${NSTD}; do \
E 16
		(echo $$i: $$i.c >>makedep; \
		/bin/grep '^#[ 	]*include' x.c $$i.c | sed \
			-e '/\.\.\/h/d' \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
			-e 's/\.c//' >>makedep); done
E 20
I 20
D 24
	for i in ${STD} ${NSTD}; do \
	    cc -M ${INCPATH} $$i.c | sed 's/\.o//' | \
	    awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
E 20
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
D 20
	rm eddep makedep x.c
E 20
I 20
	rm eddep makedep
E 20
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 24
I 24
	mkdep -p ${CFLAGS} ${SRCS}
D 25
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 25
I 25

FRC:
E 25
E 24

# Files listed in ${NSTD} have explicit make lines given below.

D 24
# DO NOT DELETE THIS LINE -- make depend uses it
E 24
I 24
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
I 30

getNAME: getNAME.c /usr/include/strings.h /usr/include/stdio.h
makekey: makekey.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 30
E 24
D 27

I 4
D 12
atrun: atrun.c
atrun: /usr/include/stdio.h
atrun: /usr/include/sys/param.h
atrun: /usr/include/sys/dir.h
D 8
atrun: /usr/include/time.h
E 8
I 8
atrun: /usr/include/sys/time.h
E 8
atrun: /usr/include/sys/stat.h
E 12
E 4
D 20
getNAME: getNAME.c
getNAME: /usr/include/stdio.h
E 20
I 20
getNAME: getNAME.c /usr/include/strings.h /usr/include/stdio.h
E 20
makekey: makekey.c
D 24
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 24
I 24

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 27
E 24
E 1

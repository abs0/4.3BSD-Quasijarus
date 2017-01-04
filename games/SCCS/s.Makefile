h61649
s 00001/00027/00105
d D 5.12 99/01/14 21:29:09 msokolov 33 31
c Axe gnuchess and larn. Hell knows how they ended up here.
c Also having dependencies in the SCCS file is sick.
e
s 00010/00005/00124
d D 5.10.1.2 88/07/09 14:15:27 bostic 32 30
c install approved copyright notice
e
s 00010/00005/00122
d D 5.11 88/07/09 11:16:09 bostic 31 29
c install approved copyright notice
e
s 00010/00008/00119
d D 5.10.1.1 88/06/06 20:18:17 bostic 30 29
c get a branch for the tahoe release
e
s 00012/00010/00115
d D 5.10 88/02/08 14:16:25 bostic 29 28
c add ppt
e
s 00064/00064/00061
d D 5.9 87/12/10 21:21:05 bostic 28 25
c tahoe release
e
s 00054/00060/00065
d R 5.9 87/12/10 21:20:08 bostic 27 25
c tahoe beta release
e
s 00043/00051/00074
d R 5.9 87/07/27 16:14:25 bostic 26 25
c new template
e
s 00001/00000/00124
d D 5.8 87/05/31 21:04:45 bostic 25 24
c do "make depend" in sub-directories
e
s 00004/00004/00120
d D 5.7 87/05/24 14:39:13 bostic 24 23
c MACHINE defined by make, now
e
s 00001/00000/00123
d D 5.6 86/11/17 18:47:24 mckusick 23 22
c do not forget to clean up!
e
s 00011/00009/00112
d D 5.5 86/11/17 18:45:48 mckusick 22 21
c update for VAX and CCI split
e
s 00003/00006/00118
d D 5.4 86/02/01 16:25:03 mckusick 21 20
c update for ddl and aard (from trwrb!trwspp!spp2!urban (Mike Urban))
e
s 00003/00001/00121
d D 5.3 85/10/11 17:53:09 mckusick 20 19
c depend on FRC not /tmp
e
s 00029/00038/00093
d D 5.2 85/08/26 19:36:32 mckusick 19 18
c new `make depend'; update dependencies
e
s 00000/00002/00131
d D 5.1 85/06/23 15:44:33 mckusick 18 17
c bring up to proper rev level
e
s 00005/00004/00128
d D 4.17 85/06/23 15:43:19 mckusick 17 16
c added wargames and ching
e
s 00014/00008/00118
d D 4.16 85/06/06 16:11:38 kre 16 15
c add copyright, and robots (apparently by "dist" w/o checkout)
c add '-' to for's in install & clean to protect from dum-dum errors.
e
s 00001/00001/00125
d D 4.15 84/12/03 17:26:18 edward 15 14
c battlestar added
e
s 00001/00001/00125
d D 4.14 84/09/07 18:46:17 mckusick 14 13
c add hunt
e
s 00001/00001/00125
d D 4.13 83/08/02 16:44:47 mckusick 13 12
c rogue becomes a subdirectory
e
s 00003/00001/00123
d D 4.12 83/07/03 22:57:29 sam 12 11
c strip on install
e
s 00001/00001/00123
d D 4.11 83/07/03 00:12:52 root 11 10
c trek added
e
s 00002/00002/00122
d D 4.10 83/07/02 23:56:25 root 10 9
c add sail, why I don't know
e
s 00009/00006/00115
d D 4.9 83/06/13 00:57:26 sam 9 8
c new games, oh boy
e
s 00002/00000/00119
d D 4.8 83/05/12 21:53:11 mckusick 8 7
c be sure to set up canfield database
e
s 00004/00012/00115
d D 4.7 83/05/12 21:19:12 mckusick 7 6
c add cfscores
e
s 00014/00006/00113
d D 4.6 83/02/08 23:43:44 sam 6 5
c random cleanups
e
s 00002/00005/00117
d D 4.5 83/01/07 01:37:22 sklower 5 4
c change to reflect hangman (screen) in subdirectory and ohangman (still good for printing terminals).
e
s 00002/00007/00120
d D 4.4 82/11/28 18:47:51 mckusick 4 3
c zork and quiz move to their own subdirectories
e
s 00003/00002/00124
d D 4.3 82/10/29 17:49:05 mckusick 3 2
c ching moves to its own subdirectory
e
s 00005/00000/00121
d D 4.2 82/10/27 17:54:15 mckusick 2 1
c add ching
e
s 00121/00000/00000
d D 4.1 82/10/25 01:16:02 mckusick 1 0
c date and time created 82/10/25 01:16:02 by mckusick
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
D 16
#	%M%	%I%	%E%
E 16
E 10
#
I 16
D 28
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 28
I 28
# Copyright (c) 1980, 1987 Regents of the University of California.
# All rights reserved.
E 28
#
D 24
#	%W% (Berkeley) %G%
E 24
I 24
D 28
#	@(#)Makefile	5.6 (Berkeley) 11/17/86
E 28
I 28
# Redistribution and use in source and binary forms are permitted
D 31
D 32
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 32
I 32
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
E 32
E 31
I 31
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
E 31
E 28
E 24
#
I 28
#	%W% (Berkeley) %G%
#
E 28
D 18
#	Makefile	4.15	84/12/03
#
E 18
E 16
DESTDIR=
CFLAGS=	-O
I 28
LIBC=	/lib/libc.a
E 28

D 21
# The following sources are incomplete and cannot be compiled without
# some work
WORK=	aard ddl mpu

E 21
# Programs that live in subdirectories, and have makefiles of their own.
#
D 15
SUBDIR=	adventure backgammon boggle compat cribbage doctor fortune \
E 15
I 15
D 17
SUBDIR=	adventure backgammon battlestar boggle compat cribbage doctor fortune \
E 15
D 4
	mille monop snake
E 4
I 4
D 5
	mille monop quiz snake zork
E 5
I 5
D 10
	mille monop quiz snake zork hangman
E 10
I 10
D 11
	mille monop quiz sail snake zork hangman
E 11
I 11
D 13
	hangman mille monop quiz sail snake trek zork
E 13
I 13
D 14
	hangman mille monop quiz rogue sail snake trek zork
E 14
I 14
D 16
	hangman hunt mille monop quiz rogue sail snake trek zork
E 16
I 16
	hangman hunt mille monop quiz robots rogue sail snake trek zork
E 17
I 17
D 21
SUBDIR=	adventure backgammon battlestar boggle ching compat cribbage doctor \
	fortune hangman hunt mille monop quiz robots rogue sail snake trek zork
E 21
I 21
D 22
SUBDIR=	aard adventure backgammon battlestar boggle ching compat \
	cribbage ddl doctor fortune hangman hunt mille monop quiz \
	robots rogue sail snake trek zork
E 22
I 22
D 28
SUBDIR=	adventure backgammon battlestar boggle cribbage fortune \
	hangman hunt mille monop quiz robots sail snake trek
E 28
I 28
# doctor removed until lisp works
SUBDIR=	adventure atc backgammon battlestar boggle btlgammon canfield \
D 30
D 33
	cribbage dm fortune gnuchess hack hangman hunt larn mille monop \
E 33
I 33
	cribbage dm fortune hack hangman hunt mille monop \
E 33
E 30
I 30
	cribbage dm fortune hack hangman hunt mille monop \
E 30
	phantasia quiz robots rogue sail snake trek \
	games.${MACHINE}
E 28
E 22
E 21
E 17
E 16
E 14
E 13
E 11
E 10
E 5
E 4

I 2
# Shell scripts that need only be installed and are never removed.
#
D 3
SCRIPT=	ching
E 3
I 3
D 17
#SCRIPT=	
E 17
I 17
SCRIPT=	wargames
E 17
E 3

I 28
# C sources that live in the current directory
#
D 29
SRCS=	arithmetic.c banner.c bcd.c factor.c fish.c number.c primes.c \
E 29
I 29
SRCS=	arithmetic.c banner.c bcd.c factor.c fish.c number.c ppt.c primes.c \
E 29
	rain.c worm.c worms.c wump.c

E 28
E 2
# C programs that live in the current directory and do not need
# explicit make lines.
#
D 4
STD=	arithmetic btlgammon banner bcd chess fish number quiz wump zork
E 4
I 4
D 5
STD=	arithmetic btlgammon banner bcd chess fish number wump
E 5
I 5
D 6
STD=	arithmetic btlgammon banner bcd chess fish number ohangman wump
E 6
I 6
D 7
STD=	arithmetic btlgammon banner bcd chess fish number wump
E 7
I 7
D 9
STD=	arithmetic btlgammon banner bcd cfscores chess fish number wump
E 9
I 9
D 22
STD=	arithmetic btlgammon banner bcd cfscores chess factor \
	fish number wump
E 22
I 22
D 28
STD=	arithmetic btlgammon banner bcd cfscores factor fish number wump
E 28
I 28
D 29
STD=	arithmetic banner bcd factor fish number wump
E 29
I 29
STD=	arithmetic banner bcd factor fish number ppt wump
E 29
E 28
E 22
E 9
E 7
E 6
E 5
E 4

# C programs that live in the current directory and need explicit make lines.
#
D 6
NSTD=	canfield hangman rain worm worms
E 6
I 6
D 9
NSTD=	canfield rain worm worms
E 9
I 9
D 28
NSTD=	canfield primes rain worm worms
E 28
I 28
NSTD=	primes rain worm worms
E 28
E 9
E 6

I 28
# programs that get hidden
HIDE=	fish wump worm

# programs that don't
D 29
NOHIDE=	arithmetic banner bcd factor number primes rain worms
E 29
I 29
NOHIDE=	arithmetic banner bcd factor number ppt primes rain worms
E 29

E 28
I 22
# Programs that require a lisp interpreter or compiler
LISP=	doctor

E 22
all:	${SUBDIR} ${STD} ${NSTD}
I 22
D 24
	cd games.`machine`; make ${MFLAGS}
E 24
I 24
D 28
	cd games.${MACHINE}; make ${MFLAGS}
E 28
E 24
E 22

D 20
${SUBDIR}: /tmp
E 20
I 20
${SUBDIR}: FRC
E 20
	cd $@; make ${MFLAGS}
I 20

D 28
FRC:
E 28
I 28
${STD}: ${LIBC}
	${CC} ${CFLAGS} -o $@ $@.c
E 28
E 20

D 28
${STD}:
	cc ${CFLAGS} -o $@ $@.c

install:
E 28
I 28
install: FRC
E 28
D 16
	for i in ${SUBDIR}; do \
E 16
I 16
	-for i in ${SUBDIR}; do \
E 16
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
I 2
D 3
	for i in ${SCRIPT}; do (install -c $$i ${DESTDIR}/usr/games/$$i); done
E 3
I 3
D 16
#	for i in ${SCRIPT}; do (install -c $$i ${DESTDIR}/usr/games/$$i); done
E 3
E 2
D 12
	for i in ${STD} ${NSTD}; do (install $$i ${DESTDIR}/usr/games/$$i); done
E 12
I 12
	for i in ${STD} ${NSTD}; do \
		(install -s $$i ${DESTDIR}/usr/games/$$i); \
	done
E 16
I 16
D 17
#	-for i in ${SCRIPT}; do (install -c $$i ${DESTDIR}/usr/games/$$i); done
E 17
I 17
	-for i in ${SCRIPT}; do \
D 28
		(install -c $$i.sh ${DESTDIR}/usr/games/$$i); done
E 17
	-for i in ${STD} ${NSTD}; do \
		(install -s $$i ${DESTDIR}/usr/games/$$i); done
E 16
E 12
I 3
D 22
	install -c chess.bin ${DESTDIR}/usr/games/lib/chess
I 8
	cat >${DESTDIR}/usr/games/lib/cfscores </dev/null
	chmod 777 ${DESTDIR}/usr/games/lib/cfscores
E 22
I 22
	-if [ ! -f ${DESTDIR}/usr/games/lib/cfscores ]; then \
		cat >${DESTDIR}/usr/games/lib/cfscores </dev/null; \
		chmod 777 ${DESTDIR}/usr/games/lib/cfscores; fi
D 24
	cd games.`machine`; make ${MFLAGS} DESTDIR=${DESTDIR} install
E 24
I 24
	cd games.${MACHINE}; make ${MFLAGS} DESTDIR=${DESTDIR} install
E 28
I 28
		(install -c -o games -g bin -m 755 $$i.sh ${DESTDIR}/usr/games/$$i); done
	install -s -o games -g bin -m 700 ${HIDE} ${DESTDIR}/usr/games/hide
	install -s -o games -g bin -m 755 ${NOHIDE} ${DESTDIR}/usr/games
	-for i in ${HIDE}; do \
		(cd ${DESTDIR}/usr/games; rm -f $$i; ln -s dm $$i; chown games.bin $$i) \
	done
E 28
E 24
E 22
E 8
E 3

D 28
clean:
	rm -f a.out core *.s *.o
D 16
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 16
I 16
	-for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done
E 16
	rm -f ${STD} ${NSTD}
I 23
D 24
	cd games.`machine`; make ${MFLAGS} DESTDIR=${DESTDIR} clean
E 24
I 24
	cd games.${MACHINE}; make ${MFLAGS} DESTDIR=${DESTDIR} clean
E 28
I 28
clean: FRC
	-for i in ${SUBDIR} games.vax games.tahoe; do \
		(cd $$i; make ${MFLAGS} clean); \
	done
	rm -f ${STD} ${NSTD} a.out core *.s *.o
E 28
E 24
E 23

D 28
depend:
E 28
I 28
depend: ldepend
E 28
I 25
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} depend); done
E 25
D 19
	cat </dev/null >x.c
E 19
D 28
	for i in ${STD} ${NSTD}; do \
D 19
		(echo $$i: $$i.c >>makedep; \
		/bin/grep '^#[ 	]*include' x.c $$i.c | sed \
			-e 's,<\(.*\)>,"/usr/include/\1",' \
			-e 's/:[^"]*"\([^"]*\)".*/: \1/' \
			-e 's/\.c//' >>makedep); done
E 19
I 19
	    cc -M ${INCPATH} $$i.c | sed 's/\.o//' | \
	    awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >> makedep; done
E 19
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	cp Makefile Makefile.bak
	ed - Makefile < eddep
D 19
	rm eddep makedep x.c
E 19
I 19
	rm eddep makedep
E 19
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 28

D 28
# Files listed in ${NSTD} have explicit make lines given below.
E 28
I 28
ldepend: FRC
	mkdep -p ${CFLAGS} ${SRCS}
E 28

D 28
canfield:
D 9
	cc -o canfield canfield.c -lcurses -ltermcap
E 9
I 9
	cc -o canfield ${CFLAGS} canfield.c -lcurses -ltermcap
E 28
I 28
FRC:
E 28
E 9
D 5

hangman:
	cc -o hangman hangman.c -lcurses -ltermcap -lm
E 5

I 28
# Files listed in ${NSTD} have explicit make lines given below.

E 28
I 9
primes:
D 28
	cc -o primes ${CFLAGS} primes.c -lm
E 28
I 28
	${CC} -o $@ ${CFLAGS} primes.c -lm
E 28
E 9
I 6

E 6
rain:
D 9
	cc -o rain rain.c -lcurses -ltermcap
E 9
I 9
D 28
	cc -o rain ${CFLAGS} rain.c -lcurses -ltermcap
E 28
I 28
	${CC} -o $@ ${CFLAGS} rain.c -lcurses -ltermcap
E 28
E 9

worm:
D 9
	cc -o worm worm.c -lcurses -ltermcap
E 9
I 9
D 28
	cc -o worm ${CFLAGS} worm.c -lcurses -ltermcap
E 28
I 28
	${CC} -o $@ ${CFLAGS} worm.c -lcurses -ltermcap
E 28
E 9

worms:
D 9
	cc -o worms worms.c -lcurses -ltermcap
E 9
I 9
D 28
	cc -o worms ${CFLAGS} worms.c -lcurses -ltermcap
E 28
I 28
	${CC} -o $@ ${CFLAGS} worms.c -lcurses -ltermcap
E 28
E 9

D 28
# DO NOT DELETE THIS LINE -- make depend uses it
E 28
I 28
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 28
D 33

D 19
arithmetic: arithmetic.c
arithmetic: /usr/include/stdio.h
arithmetic: /usr/include/signal.h
btlgammon: btlgammon.c
btlgammon: /usr/include/stdio.h
banner: banner.c
banner: /usr/include/stdio.h
E 19
I 19
arithmetic: arithmetic.c /usr/include/stdio.h /usr/include/signal.h
D 28
btlgammon: btlgammon.c /usr/include/stdio.h
E 28
I 28
arithmetic: /usr/include/machine/trap.h
E 28
banner: banner.c /usr/include/stdio.h
E 19
bcd: bcd.c
I 7
D 19
cfscores: cfscores.c
cfscores: /usr/include/pwd.h
E 7
chess: chess.c
chess: /usr/include/stdio.h
fish: fish.c
I 6
D 7
arithmetic: arithmetic.c
arithmetic: /usr/include/stdio.h
arithmetic: /usr/include/signal.h
btlgammon: btlgammon.c
btlgammon: /usr/include/stdio.h
banner: banner.c
banner: /usr/include/stdio.h
bcd: bcd.c
chess: chess.c
chess: /usr/include/stdio.h
fish: fish.c
E 7
E 6
fish: /usr/include/stdio.h
E 19
I 19
D 28
cfscores: cfscores.c /usr/include/pwd.h
E 28
D 22
chess: chess.c /usr/include/stdio.h
E 22
factor: factor.c
fish: fish.c /usr/include/stdio.h
E 19
D 28
number: number.c
D 4
quiz: quiz.c
quiz: /usr/include/stdio.h
quiz: /usr/include/signal.h
E 4
D 19
wump: wump.c
wump: /usr/include/stdio.h
wump: /usr/include/sgtty.h
D 4
zork: zork.c
zork: /usr/include/stdio.h
E 4
canfield: canfield.c
canfield: /usr/include/curses.h
canfield: /usr/include/ctype.h
canfield: /usr/include/signal.h
I 7
canfield: /usr/include/sys/types.h
E 7
D 6
hangman: hangman.c
hangman: /usr/include/stdio.h
hangman: /usr/include/sys/types.h
hangman: /usr/include/sys/stat.h
E 6
rain: rain.c
rain: /usr/include/stdio.h
rain: /usr/include/sgtty.h
E 19
I 19
wump: wump.c /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
wump: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
canfield: canfield.c /usr/include/curses.h /usr/include/stdio.h
canfield: /usr/include/sgtty.h /usr/include/sys/ioctl.h
canfield: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
canfield: /usr/include/ctype.h /usr/include/signal.h /usr/include/sys/types.h
E 28
I 28
number: number.c /usr/include/stdio.h /usr/include/ctype.h
I 29
ppt: ppt.c /usr/include/stdio.h
E 29
E 28
primes: primes.c /usr/include/stdio.h /usr/include/math.h
D 29
rain: rain.c /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
rain: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 19
D 28
rain: /usr/include/signal.h
E 28
I 28
rain: /usr/include/signal.h /usr/include/machine/trap.h
E 29
I 29
rain: rain.c /usr/include/sys/types.h /usr/include/stdio.h /usr/include/sgtty.h
rain: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 30
rain: /usr/include/sys/ttydev.h /usr/include/signal.h
rain: /usr/include/machine/trap.h
E 30
I 30
rain: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
rain: /usr/include/signal.h /usr/include/machine/trap.h
E 30
E 29
E 28
D 19
worm: worm.c
worm: /usr/include/ctype.h
worm: /usr/include/curses.h
worm: /usr/include/signal.h
worms: worms.c
worms: /usr/include/stdio.h
worms: /usr/include/sgtty.h
E 19
I 19
worm: worm.c /usr/include/ctype.h /usr/include/curses.h /usr/include/stdio.h
worm: /usr/include/sgtty.h /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 30
worm: /usr/include/sys/ttydev.h /usr/include/signal.h
I 28
worm: /usr/include/machine/trap.h
E 30
I 30
worm: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
worm: /usr/include/signal.h /usr/include/machine/trap.h
E 30
E 28
D 29
worms: worms.c /usr/include/stdio.h /usr/include/sgtty.h
worms: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
worms: /usr/include/sys/ttydev.h /usr/include/signal.h
E 19
D 28
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 28
I 28
worms: /usr/include/machine/trap.h
E 29
I 29
worms: worms.c /usr/include/sys/types.h /usr/include/stdio.h
worms: /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 30
worms: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
worms: /usr/include/signal.h /usr/include/machine/trap.h
E 30
I 30
worms: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
worms: /usr/include/sys/ttydev.h /usr/include/signal.h
worms: /usr/include/machine/trap.h
E 30
E 29
wump: wump.c /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 30
wump: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
E 30
I 30
wump: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
wump: /usr/include/sys/ttydev.h
E 30

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 33
E 28
E 1

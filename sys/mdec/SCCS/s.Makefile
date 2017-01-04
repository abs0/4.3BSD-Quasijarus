h52531
s 00002/00002/00065
d D 7.11 04/03/01 15:09:10 msokolov 18 17
c add tpdecboot
e
s 00001/00000/00066
d D 7.10 04/02/28 23:48:43 msokolov 17 16
c vmb.exe now needs to live in /, so install it
e
s 00002/00002/00064
d D 7.9 04/02/07 06:55:45 msokolov 16 15
c decboot replaces rdboot
e
s 00005/00005/00061
d D 7.8 99/09/05 15:48:20 msokolov 15 14
c add kraboot
e
s 00002/00021/00064
d D 7.7 99/01/08 17:10:28 msokolov 14 13
c tmscpboot.c wasn't listed among SRCS
c add -c to the install command (maketape and cassette Makefile depend on this)
e
s 00011/00005/00074
d D 7.6 88/07/09 11:03:30 bostic 13 12
c add appropriate copyright notice
e
s 00002/00002/00077
d D 7.5 88/07/01 09:07:24 bostic 12 11
c add rdboot to SRCS list
e
s 00002/00002/00077
d D 7.4 88/03/13 12:42:12 bostic 11 10
c add tmscpboot
e
s 00050/00117/00029
d D 7.3 88/01/03 13:16:43 bostic 10 9
c new template, cleanup; mostly from Chris Torek
e
s 00036/00022/00110
d D 7.2 86/08/28 20:59:01 karels 9 8
c changes for pack labels; use cpp, now are *.c
e
s 00001/00001/00131
d D 7.1 86/06/05 01:54:44 mckusick 8 7
c 4.3BSD release version
e
s 00006/00001/00126
d D 6.3 85/06/08 12:16:30 mckusick 7 6
c Add copyright
e
s 00005/00005/00122
d D 6.2 83/09/28 10:59:49 karels 6 5
c install in DESTDIR
e
s 00000/00000/00127
d D 6.1 83/07/29 07:43:01 sam 5 4
c 4.2 distribution
e
s 00008/00001/00119
d D 4.4 83/07/06 18:11:51 sam 4 3
c add tuboot
e
s 00044/00029/00076
d D 4.3 83/02/20 22:15:22 sam 3 2
c update
e
s 00015/00002/00090
d D 4.2 83/02/16 23:19:11 sam 2 1
c put back ut
e
s 00092/00000/00000
d D 4.1 83/02/16 22:06:48 sam 1 0
c date and time created 83/02/16 22:06:48 by sam
e
u
U
t
T
I 1
D 7
#	%W%	%G%
E 7
I 7
#
D 8
# Copyright (c) 1980 Regents of the University of California.
E 8
I 8
D 10
# Copyright (c) 1980, 1986 Regents of the University of California.
E 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 10
I 10
# Copyright (c) 1980, 1986, 1987 Regents of the University of California.
# All rights reserved.
E 10
#
I 10
# Redistribution and use in source and binary forms are permitted
D 13
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
#
E 10
#	%W% (Berkeley) %G%
E 7
#
I 13

E 13
D 2
ALL=	htboot tmboot tsboot hpboot hkboot upboot mtboot noboot \
	httoggle tmtoggle tstoggle mttoggle
E 2
I 2
D 3
ALL=	htboot tmboot tsboot hpboot hkboot upboot mtboot utboot noboot \
	httoggle tmtoggle tstoggle mttoggle uttoggle
E 3
I 3
D 10
ALL=	hkboot hpboot htboot mtboot noboot raboot rlboot \
D 4
	upboot utboot tmboot tsboot \
E 4
I 4
	upboot utboot tmboot tsboot tuboot \
E 4
	httoggle mttoggle tmtoggle tstoggle uttoggle
E 10
I 10
CFLAGS=	-DLOCORE
E 10
E 3
E 2

I 9
D 10
CFLAGS= -DLOCORE
INCLUDE= /usr/include
E 10
I 10
# source files that live in the current directory
D 12
SRCS=	hkboot.c hpboot.c htboot.c mtboot.c raboot.c rlboot.c upboot.c \
	utboot.c tmboot.c tsboot.c tuboot.c httoggle.s mttoggle.s \
E 12
I 12
D 15
SRCS=	hkboot.c hpboot.c htboot.c mtboot.c raboot.c rdboot.c rlboot.c \
	upboot.c utboot.c tmboot.c tsboot.c tuboot.c httoggle.s mttoggle.s \
E 12
D 14
	tmtoggle.s tstoggle.s uttoggle.s
E 14
I 14
	tmtoggle.s tstoggle.s uttoggle.s tmscpboot.c
E 15
I 15
D 16
SRCS=	hkboot.c hpboot.c htboot.c kraboot.c mtboot.c raboot.c rdboot.c \
E 16
I 16
SRCS=	decboot.c hkboot.c hpboot.c htboot.c kraboot.c mtboot.c raboot.c \
E 16
	rlboot.c upboot.c utboot.c tmboot.c tsboot.c tuboot.c httoggle.s \
D 18
	mttoggle.s tmtoggle.s tstoggle.s uttoggle.s tmscpboot.c
E 18
I 18
	mttoggle.s tmtoggle.s tstoggle.s uttoggle.s tmscpboot.c tpdecboot.c
E 18
E 15
E 14
E 10

E 9
D 10
all: ${ALL}
E 10
I 10
# boot blocks that are preprocessed, then assembled
D 11
BOOTS=	hkboot hpboot htboot mtboot raboot rlboot upboot utboot tmboot \
	tsboot tuboot
E 11
I 11
D 15
BOOTS=	hkboot hpboot htboot mtboot raboot rdboot rlboot upboot utboot \
	tmboot tmscpboot tsboot tuboot
E 15
I 15
D 16
BOOTS=	hkboot hpboot htboot kraboot mtboot raboot rdboot rlboot upboot \
E 16
I 16
BOOTS=	decboot hkboot hpboot htboot kraboot mtboot raboot rlboot upboot \
E 16
D 18
	utboot tmboot tmscpboot tsboot tuboot
E 18
I 18
	utboot tmboot tmscpboot tpdecboot tsboot tuboot
E 18
E 15
E 11
E 10

I 3
D 9
hkboot: hkboot.s
	as hkboot.s
E 9
I 9
D 10
hkboot: hkboot.c ${INCLUDE}/sys/disklabel.h
	cc -E ${CFLAGS} hkboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=hkboot conv=sync
I 9
	rm b.out
E 10
I 10
# toggle files that are assembled, but not installed
TOGGLES=httoggle mttoggle tmtoggle tstoggle uttoggle
E 10
E 9

D 9
hpboot: hpboot.s
	as hpboot.s
E 9
I 9
D 10
hpboot: hpboot.c ${INCLUDE}/sys/disklabel.h
	cc -E ${CFLAGS} hpboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=hpboot conv=sync
I 9
	rm b.out
E 10
I 10
all: ${BOOTS} ${TOGGLES} noboot
E 10
E 9

E 3
D 9
htboot: htboot.s
	as htboot.s
E 9
I 9
D 10
htboot: htboot.c
	cc -E ${CFLAGS} htboot.c | as
E 10
I 10
${BOOTS}:
	${CC} -E ${CFLAGS} $@.c | as
E 10
E 9
	nm -u a.out
	strip a.out
D 10
	dd if=a.out of=b.out bs=32 skip=1
	dd if=b.out of=htboot conv=sync
I 9
	rm b.out
E 9

I 3
D 9
mtboot: mtboot.s
	as mtboot.s
E 9
I 9
mtboot: mtboot.c
	cc -E ${CFLAGS} mtboot.c | as
E 9
	nm -u a.out
	strip a.out
E 10
	dd if=a.out bs=32 skip=1 of=b.out
D 10
	dd if=b.out of=mtboot conv=sync
E 10
I 10
	dd if=b.out of=$@ conv=sync
E 10
I 9
	rm b.out
E 9

D 9
raboot: raboot.s
	as raboot.s
E 9
I 9
D 10
raboot: raboot.c ${INCLUDE}/sys/disklabel.h
	cc -E ${CFLAGS} raboot.c | as
E 10
I 10
${TOGGLES}:
	as $@.s
E 10
E 9
	nm -u a.out
	strip a.out
D 10
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=raboot conv=sync
I 9
	rm b.out
E 10
I 10
	dd if=a.out bs=32 skip=1 of=$@
E 10
E 9

D 9
rlboot: rlboot.s
	as rlboot.s
E 9
I 9
D 10
rlboot: rlboot.c ${INCLUDE}/sys/disklabel.h
	cc -E ${CFLAGS} rlboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=rlboot conv=sync
I 9
	rm b.out
E 10
I 10
noboot:
	echo | dd of=noboot conv=sync
E 10
E 9

E 3
D 9
tmboot: tmboot.s
	as tmboot.s
E 9
I 9
D 10
tmboot: tmboot.c
	cc -E ${CFLAGS} tmboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out of=b.out bs=32 skip=1
	dd if=b.out of=tmboot conv=sync
I 9
	rm b.out
E 10
I 10
clean:
	rm -f a.out b.out ${BOOTS} ${TOGGLES} noboot
E 10
E 9

D 9
tsboot: tsboot.s
	as tsboot.s
E 9
I 9
D 10
tsboot: tsboot.c
	cc -E ${CFLAGS} tsboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out of=b.out bs=32 skip=1
	dd if=b.out of=tsboot conv=sync
I 9
	rm b.out
E 10
I 10
install:
D 14
	install -o bin -g bin -m 444 ${BOOTS} ${DESTDIR}/usr/mdec
E 14
I 14
	install -c -o bin -g bin -m 444 ${BOOTS} ${DESTDIR}/usr/mdec
E 14
	rm -f ${DESTDIR}/usr/mdec/mboot ${DESTDIR}/usr/mdec/uboot
	ln ${DESTDIR}/usr/mdec/htboot ${DESTDIR}/usr/mdec/mboot
	ln ${DESTDIR}/usr/mdec/hpboot ${DESTDIR}/usr/mdec/uboot
I 17
	install -c -o bin -g bin -m 444 vmb.exe ${DESTDIR}/
E 17
E 10
E 9

D 3
hpboot: hpboot.s
	as hpboot.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=hpboot conv=sync

hkboot: hkboot.s
	as hkboot.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=hkboot conv=sync

E 3
D 9
upboot: upboot.s
	as upboot.s
E 9
I 9
D 10
upboot: upboot.c ${INCLUDE}/sys/disklabel.h
	cc -E ${CFLAGS} upboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=upboot conv=sync
I 9
	rm b.out
E 10
I 10
depend:
	mkdep -p ${CFLAGS} ${SRCS}
E 10
E 9
I 4

D 9
tuboot: tuboot.s
	as tuboot.s
E 9
I 9
D 10
tuboot: tuboot.c
	cc -E ${CFLAGS} tuboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out of=b.out bs=32 skip=1
	dd if=b.out of=tuboot conv=sync
I 9
	rm b.out
E 10
I 10
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 10
E 9
E 4
D 14

I 10
hkboot: hkboot.c /usr/include/sys/disklabel.h
hpboot: hpboot.c /usr/include/sys/disklabel.h
htboot: htboot.c
mtboot: mtboot.c
raboot: raboot.c /usr/include/sys/disklabel.h
rlboot: rlboot.c /usr/include/sys/disklabel.h
upboot: upboot.c /usr/include/sys/disklabel.h
E 10
D 3
mtboot: mtboot.s
	as mtboot.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=mtboot conv=sync

E 3
I 2
D 9
utboot: utboot.s
	as utboot.s
E 9
I 9
utboot: utboot.c
D 10
	cc -E ${CFLAGS} utboot.c | as
E 9
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=b.out
	dd if=b.out of=utboot conv=sync
I 9
	rm b.out
E 9

E 10
I 10
tmboot: tmboot.c
tsboot: tsboot.c
tuboot: tuboot.c
E 10
E 2
httoggle: httoggle.s
D 10
	as httoggle.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=httoggle

E 10
D 3
tstoggle: tstoggle.s
	as tstoggle.s
E 3
I 3
mttoggle: mttoggle.s
D 10
	as mttoggle.s
E 3
	nm -u a.out
	strip a.out
D 3
	dd if=a.out bs=32 skip=1 of=tstoggle
E 3
I 3
	dd if=a.out bs=32 skip=1 of=mttoggle
E 3

E 10
tmtoggle: tmtoggle.s
D 10
	as tmtoggle.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=tmtoggle

E 10
D 3
mttoggle: mttoggle.s
	as mttoggle.s
E 3
I 3
tstoggle: tstoggle.s
D 10
	as tstoggle.s
E 3
	nm -u a.out
	strip a.out
D 3
	dd if=a.out bs=32 skip=1 of=mttoggle
E 3
I 3
	dd if=a.out bs=32 skip=1 of=tstoggle
E 3
I 2

E 10
uttoggle: uttoggle.s
D 10
	as uttoggle.s
	nm -u a.out
	strip a.out
	dd if=a.out bs=32 skip=1 of=uttoggle
E 10
E 2

D 10
noboot:
	echo | dd of=noboot conv=sync

clean:
	rm -f a.out b.out ${ALL}

install:
D 6
	cp *boot /usr/mdec
	rm -f /usr/mdec/mboot
	ln /usr/mdec/htboot /usr/mdec/mboot
	rm -f /usr/mdec/uboot
	ln /usr/mdec/hpboot /usr/mdec/uboot
E 6
I 6
	cp *boot ${DESTDIR}/usr/mdec
	rm -f ${DESTDIR}/usr/mdec/mboot
	ln ${DESTDIR}/usr/mdec/htboot ${DESTDIR}/usr/mdec/mboot
	rm -f ${DESTDIR}/usr/mdec/uboot
	ln ${DESTDIR}/usr/mdec/hpboot ${DESTDIR}/usr/mdec/uboot
E 10
I 10
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 14
E 10
E 6
E 1

h64616
s 00009/00000/00029
d D 7.2 99/09/07 09:15:48 msokolov 6 5
c we are now shipping these packs too!
e
s 00001/00001/00028
d D 7.1 86/06/05 01:57:00 mckusick 5 4
c 4.3BSD release version
e
s 00000/00000/00029
d D 5.1 86/03/13 17:48:27 karels 4 3
c rev 5
e
s 00001/00000/00028
d D 1.2 86/03/13 17:48:04 karels 3 1
c delete defboo.com after using to force checking each time
e
s 00001/00000/00028
d R 1.2 86/03/12 11:48:23 karels 2 1
c delete defboo.cmd after using to force checking each time
e
s 00028/00000/00000
d D 1.1 85/08/12 11:19:54 bloom 1 0
c date and time created 85/08/12 11:19:54 by bloom
e
u
U
t
T
I 1
#
D 5
# Copyright (c) 1985 Regents of the University of California.
E 5
I 5
# Copyright (c) 1985, 1986 Regents of the University of California.
E 5
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
# 
BOOTS=	boot
STDBOOS= defboo.com anyboo.com
DEFBOOS= defboo.hk defboo.hp defboo.ra defboo.up
DEVBOOS= hkmboo.com hksboo.com hpmboo.com hpsboo.com \
	ramboo.com rasboo.com upmboo.com upsboo.com
UTILS=	format copy drtest
# order is NOT random...
OBJS=	${BOOTS} ${STDBOOS} ${DEVBOOS} ${UTILS}
DRIVE=	/dev/crl

I 6
all:	consolerl

consolerl: ${OBJS}
	cp /dev/null consolerl
	arff mcrf consolerl ${OBJS}

install: consolerl
	dd if=consolerl of=${DRIVE}

E 6
# build a boot console rl02 from a DEC console rl02 pack
update:	${OBJS}
	arff rmf ${DRIVE} ${OBJS}
I 3
	-rm -f defboo.com
E 3

defboo.com:
	@echo You must copy one of ${DEFBOOS} to defboo.com.
	@echo See installing and operating guide for details.
	@/bin/false	#force exits

clean:
	rm -f ${BOOTS} ${UTILS} defboo.com
E 1

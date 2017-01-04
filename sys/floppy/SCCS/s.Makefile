h35353
s 00005/00000/00044
d D 7.1 86/06/05 02:00:26 mckusick 11 9
c 4.3BSD release version
e
s 00000/00000/00044
d R 7.1 86/06/05 01:57:11 mckusick 10 9
c 4.3BSD release version
e
s 00001/00000/00043
d D 6.5 86/03/12 11:48:44 karels 9 8
c delete defboo.cmd after using to force checking each time
e
s 00008/00001/00035
d D 6.4 85/09/19 08:45:04 karels 8 7
c warn about defboo.cmd
e
s 00004/00004/00032
d D 6.3 85/04/12 17:34:20 karels 7 6
c cleanup
e
s 00002/00002/00034
d D 6.2 83/09/25 13:15:21 karels 6 5
c rm OBJS from old floppy; more FROMDEC trash
e
s 00000/00000/00036
d D 6.1 83/07/29 07:50:27 sam 5 4
c 4.2 distribution
e
s 00002/00002/00034
d D 4.4 83/07/22 22:10:59 sam 4 3
c remove flcopy turd
e
s 00001/00003/00035
d D 4.3 83/07/10 00:18:13 sam 3 2
c fix up
e
s 00019/00005/00019
d D 4.2 83/07/09 01:33:40 sam 2 1
c add update and must supply first 3 tracks on distribution floppy
e
s 00024/00000/00000
d D 4.1 83/07/07 00:12:40 sam 1 0
c date and time created 83/07/07 00:12:40 by sam
e
u
U
t
T
I 11
#
# Copyright (c) 1980, 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
E 11
I 1
#	%M%	%I%	%E%
#
# Make a 780 rx01 floppy
# 
BOOTS=	boot
STDBOO=	defboo.cmd anyboo.cmd restar.cmd
DEFBOO=	defboo.hk defboo.hp defboo.ra defboo.up
DEVBOO=	hkmboo.cmd hksboo.cmd hpmboo.cmd hpsboo.cmd \
	ramboo.cmd rasboo.cmd upmboo.cmd upsboo.cmd
UTILS=	format copy drtest
I 8

E 8
D 2
FLOPPY=	rrx0c
E 2
I 2
# order is NOT random...
D 7
OBJS=	${BOOTS} ${STDBOO} ${DEFBOO} ${DEVBOO} ${UTILS}
E 7
I 7
OBJS=	${BOOTS} ${STDBOO} ${DEVBOO} ${UTILS}
E 7
D 4
FROMDEC=dm* db* s[mbr]* *boo.* vmb.exe
E 4
I 4
D 6
FROMDEC=du* dm* db* s[mbr]* *boo.* vmb.exe
E 6
I 6
FROMDEC=du* dm* db* s[mbr]* *boo.* vmb.exe *.hlp cs* ci*
I 8

E 8
E 6
E 4
D 7
#FLOPPY=	/dev/floppy
FLOPPY=	/dev/rrx0b
E 7
I 7
FLOPPY=	/dev/floppy
#FLOPPY= /dev/rrx0b		# for using RX device
E 7
E 2

all:	floppy

D 2
# order is NOT random...
floppy:	${BOOTS} ${STDBOO} ${DEFBOO} ${DEVBOO} ${UTILS}
E 2
I 2
floppy:	3tracks ${OBJS}
E 2
D 3
	cp /dev/null floppy
E 3
I 3
	cp 3tracks floppy
E 3
D 2
	arff crf floppy ${BOOTS} ${STDBOO} ${DEFBOO} ${DEVBOO} ${UTILS}
E 2
I 2
	arff crf floppy ${OBJS}
D 3
	dd if=floppy of=x skip=6
	cat 3tracks x > floppy
E 3
E 2

install: floppy
D 2
	dd if=floppy of=/dev/${FLOPPY}
E 2
I 2
	dd if=floppy of=${FLOPPY}
E 2

I 2
# build a boot floppy from a DEC console floppy
update:	${OBJS}
	-mkdir fromdec
D 6
	cd fromdec; arff xf ${FLOPPY}; rm -f ${FROMDEC}; \
E 6
I 6
D 7
	cd fromdec; arff xf ${FLOPPY}; rm -f ${FROMDEC} ${OBJS}; \
E 7
I 7
	cd fromdec; arff xf ${FLOPPY}; rm -f ${FROMDEC} ${OBJS} ${DEFBOO}; \
E 7
E 6
D 4
		flcopy -t3 -f ${FLOPPY}; arff crf ${FLOPPY} *
E 4
I 4
		flcopy -t3 -f ${FLOPPY}; rm -f floppy; arff crf ${FLOPPY} *
E 4
	rm -rf fromdec
	arff rf ${FLOPPY} ${OBJS}
I 9
	-rm -f defboo.cmd
E 9

I 8
defboo.cmd:
	@echo You must copy one of \{${DEFBOO}\} to defboo.cmd.
	@echo See installing and operating guide for details.
	@/bin/false	#force exits

E 8
E 2
clean:
D 8
	rm -f ${BOOTS} ${UTILS} floppy
E 8
I 8
	rm -f ${BOOTS} ${UTILS} floppy defboo.cmd
E 8
I 2
	rm -rf fromdec
E 2
E 1

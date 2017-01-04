h60669
s 00003/00006/00074
d D 6.9 04/10/27 19:56:48 msokolov 9 8
c use pipes instead of intermediate files
e
s 00040/00014/00040
d D 6.8 04/10/26 21:51:45 msokolov 8 7
c build Appendix D and the full manual
e
s 00022/00016/00032
d D 6.7 04/10/26 16:53:34 msokolov 7 6
c new appendix structure
e
s 00005/00001/00043
d D 6.6 04/10/25 00:48:33 msokolov 6 5
c have to cut tutor.ps with psrange (see explanation inside)
e
s 00001/00001/00043
d D 6.5 04/09/19 03:50:09 msokolov 5 4
c we are now using the BoldItalic font for headers
e
s 00016/00027/00028
d D 6.4 04/09/09 18:54:36 msokolov 4 3
c ditroff => pstroff
e
s 00037/00014/00018
d D 6.3 86/04/21 14:32:30 mckusick 3 2
c aps-5 typesetting fixes
e
s 00010/00006/00022
d D 6.2 86/04/17 14:21:18 mckusick 2 1
c cannot do whole paper at once, it makes troff loop?!?
e
s 00028/00000/00000
d D 6.1 86/04/17 12:56:49 mckusick 1 0
c date and time created 86/04/17 12:56:49 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
#SRCS=	m.mac m0 m0a m1 m2 m3 m4 m5 table1 table2 add obsolete
SRCS=	m.mac m0 m0a m1 m2 m3 m4 m5 table1 table2
E 2
I 2
D 3
SRCS=	m.mac m0 m0a m1 m2 m3 m4 m5
APNDX=	table1 table2
E 2
MARCOS=	-msU
E 3
I 3
INTRO=	m0
TUTOR=	m0a
PAPER=	m1 m2 m3 m4
D 7
APNDX1=	m5
APNDX2=	table1
APNDX3=	table2
E 7
I 7
D 8
APNDXA=	apndxa
APNDXB=	apndxb
APNDXC=	apndxc
E 8
I 8
APNDX=	apndxa apndxb apndxc apndxd
E 8
APNDXT=	m5
E 7
MACROS=	m.mac
I 8
PARTS=	intro.ps tutor.ps paper.ps apndxa.ps apndxb.ps apndxc.ps apndxd.ps \
	apndxt.ps
E 8
E 3
D 4
PRINTER=Pdp
D 3
EQN=	deqn -${PRINTER}
E 3
TBL=	dtbl -${PRINTER}
TROFF=	ditroff -${PRINTER}
I 3
LPR=	lpr -n -${PRINTER}
E 4
I 4
TBL=	tbl
D 5
TROFF=	pstroff
E 5
I 5
D 7
TROFF=	pstroff -fR,I,B,BI,S
E 7
I 7
TROFF=	pstroff
TROPTS=	-fR,I,B,BI,S
E 7
E 5
E 4
E 3

D 2
paper:	paper.${PRINTER}
E 2
I 2
D 3
paper:	paper.${PRINTER} apndx.${PRINTER}
E 2
	lpr -${PRINTER} -n paper.${PRINTER}
I 2
	lpr -${PRINTER} -n apndx.${PRINTER}
E 3
I 3
D 4
paper:	intro.${PRINTER} tutor.${PRINTER} paper.${PRINTER}
paper:	apndx1.${PRINTER} apndx2.${PRINTER} apndx3.${PRINTER} 
	${LPR} intro.${PRINTER}
	${LPR} tutor.${PRINTER}
	${LPR} paper.${PRINTER}
	${LPR} apndx1.${PRINTER}
	${LPR} apndx2.${PRINTER}
	${LPR} apndx3.${PRINTER}
E 4
I 4
D 7
all:	intro.ps tutor.ps paper.ps apndx1.ps apndx2.ps apndx3.ps
E 7
I 7
D 8
all:	intro.ps tutor.ps paper.ps apndxa.ps apndxb.ps apndxc.ps apndxt.ps
E 8
I 8
all:	manual.ps
E 8
E 7
E 4
E 3
E 2

I 8
manual.ps:	${PARTS}
	pstmerge ${PARTS} > $@

E 8
D 3
paper.${PRINTER}: ${SRCS}
	${EQN} ${SRCS} | ${TBL} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 3
I 3
D 4
intro.${PRINTER}: ${INTRO}
	${TROFF} -t ${MACROS} ${INTRO} > intro.${PRINTER}
E 4
I 4
intro.ps: ${INTRO}
D 7
	${TROFF} ${MACROS} ${INTRO} > intro.ps
E 7
I 7
	${TROFF} ${TROPTS} ${MACROS} ${INTRO} > $@
E 7
E 4
E 3

I 6
# We have to cut off an extra page with psrange because the last page is
# full, ends with a table, and .TE's .sp causes a spill :-(
E 6
I 2
D 3
apndx.${PRINTER}: ${APNDX}
	${EQN} ${APNDX} | ${TBL} | ${TROFF} ${MACROS} -t > apndx.${PRINTER}
E 3
I 3
D 4
tutor.${PRINTER}: ${TUTOR}
	${TBL} ${TUTOR} | ${TROFF} -t ${MACROS} - > tutor.${PRINTER}
E 4
I 4
tutor.ps: ${TUTOR}
D 6
	${TBL} ${TUTOR} | ${TROFF} ${MACROS} - > tutor.ps
E 6
I 6
D 7
	${TBL} ${TUTOR} | ${TROFF} ${MACROS} - > tutor1.ps
E 7
I 7
D 9
	${TBL} ${TUTOR} | ${TROFF} ${TROPTS} ${MACROS} - > tutor1.ps
E 7
	psrange tutor1.ps 1-5 > tutor.ps
	rm -f tutor1.ps
E 9
I 9
	${TBL} ${TUTOR} | ${TROFF} ${TROPTS} ${MACROS} - | psrange 1-5 > $@
E 9
E 6
E 4
E 3

I 3
D 4
paper.${PRINTER}: ${PAPER}
	${TBL} ${PAPER} | ${TROFF} -t ${MACROS} - > paper.${PRINTER}
E 4
I 4
paper.ps: ${PAPER}
D 7
	${TBL} ${PAPER} | ${TROFF} ${MACROS} - > paper.ps
E 7
I 7
	${TBL} ${PAPER} | ${TROFF} ${TROPTS} ${MACROS} - > $@
E 7
E 4

D 4
apndx1.${PRINTER}: ${APNDX1}
	${TROFF} -t ${MACROS} ${APNDX1} > apndx1.${PRINTER}
E 4
I 4
D 7
apndx1.ps: ${APNDX1}
	${TROFF} ${MACROS} ${APNDX1} > apndx1.ps
E 7
I 7
D 8
apndxa.ps: ${APNDXA}
	${TBL} ${APNDXA} | ${TROFF} ${TROPTS} ${MACROS} - > $@
E 8
I 8
apndxa.ps: apndxa
	${TBL} apndxa | ${TROFF} ${TROPTS} ${MACROS} - > $@
E 8
E 7
E 4

D 4
apndx2.${PRINTER}: ${APNDX2}
	${TROFF} -t ${MACROS} ${APNDX2} > apndx2.${PRINTER}
E 4
I 4
D 7
apndx2.ps: ${APNDX2}
	${TROFF} ${MACROS} ${APNDX2} > apndx2.ps
E 7
I 7
D 8
apndxb.ps: ${APNDXB}
	${TROFF} -fR,I,B,BI,H,HO,HB,HQ,C,CO,CB,CQ ${MACROS} ${APNDXB} > $@
E 8
I 8
apndxb.ps: apndxb
	${TROFF} -fR,I,B,BI,H,HO,HB,HQ,C,CO,CB,CQ ${MACROS} apndxb > $@
E 8
E 7
E 4

D 4
apndx3.${PRINTER}: ${APNDX3}
	${TROFF} -t ${MACROS} ${APNDX3} > apndx3.${PRINTER}
E 4
I 4
D 7
apndx3.ps: ${APNDX3}
	${TROFF} ${MACROS} ${APNDX3} > apndx3.ps
E 7
I 7
D 8
apndxc.ps: ${APNDXC}
	${TROFF} -fR,I,B,BI,CB ${MACROS} ${APNDXC} > $@
E 8
I 8
apndxc.ps: apndxc
	${TROFF} -fR,I,B,BI,CB ${MACROS} apndxc > $@
E 8
E 7
E 4

I 8
apndxd.ps: apndxd VarianSpecial.ps apndxd.fonts
D 9
	${TROFF} -Fapndxd.fonts -fR,I,B,BI,CB,VS ${MACROS} apndxd > apndxd1.ps
	sed -e 's/^5 9 SF$$/VSF setfont/' -e '/^%DELETEME%$$/d' apndxd1.ps > $@
	rm -f apndxd1.ps
E 9
I 9
	${TROFF} -Fapndxd.fonts -fR,I,B,BI,CB,VS ${MACROS} apndxd | \
		sed -e 's/^5 9 SF$$/VSF setfont/' -e '/^%DELETEME%$$/d' > $@
E 9

VarianSpecial.ps:	/usr/lib/vfont/S.18 VSfix.ex
	vfont2ps /usr/lib/vfont/S.18 18 VarianSpecial > $@
	ex - $@ < VSfix.ex

apndxd.fonts: fwVS.o
	rm -rf apndxd.fonts
	mkdir apndxd.fonts
	cp /usr/lib/pstroff/f[sw]R apndxd.fonts
	cp /usr/lib/pstroff/f[sw]I apndxd.fonts
	cp /usr/lib/pstroff/f[sw]B apndxd.fonts
	cp /usr/lib/pstroff/f[sw]BI apndxd.fonts
	cp /usr/lib/pstroff/f[sw]CB apndxd.fonts
	cp fwVS.o a.out
	strip a.out
	dd if=a.out of=apndxd.fonts/fwVS bs=32 skip=1
	rm -f a.out
	echo "%DELETEME%" > apndxd.fonts/fsVS

E 8
I 7
apndxt.ps: ${APNDXT}
	${TROFF} ${TROPTS} ${MACROS} ${APNDXT} > apndxt.ps

E 7
E 3
E 2
clean:
D 2
	rm -f paper.${PRINTER} *.spell errs Errs make.out
E 2
I 2
D 3
	rm -f paper.${PRINTER} apndx.${PRINTER} *.spell errs Errs make.out
E 3
I 3
D 4
	rm -f intro.${PRINTER} tutor.${PRINTER} paper.${PRINTER} \
		apndx1.${PRINTER} apndx2.${PRINTER} apndx3.${PRINTER} \
		*.spell errs Errs make.out
E 4
I 4
D 8
	rm -f *.ps *.spell errs Errs make.out
E 8
I 8
	rm -f *.o *.ps *.spell errs Errs make.out a.out core
	rm -rf apndxd.fonts
E 8
E 4
E 3
E 2

D 2
spell:	${SRCS}
	@for i in ${SRCS}; do \
E 2
I 2
D 3
spell:	${SRCS} ${APNDX}
	@for i in ${SRCS} ${APNDX}; do \
E 3
I 3
D 7
spell:	${INTRO} ${TUTOR} ${PAPER} ${APNDX1} ${APNDX2} ${APNDX3}
	@for i in ${INTRO} ${TUTOR} ${PAPER} ${APNDX1} ${APNDX2} ${APNDX3}; do \
E 7
I 7
D 8
spell:	${INTRO} ${TUTOR} ${PAPER} ${APNDXA} ${APNDXB} ${APNDXC} ${APNDXT}
	@for i in ${INTRO} ${TUTOR} ${PAPER} ${APNDXA} ${APNDXB} ${APNDXC} \
	${APNDXT}; do \
E 8
I 8
spell:	${INTRO} ${TUTOR} ${PAPER} ${APNDX} ${APNDXT}
	@for i in ${INTRO} ${TUTOR} ${PAPER} ${APNDX} ${APNDXT}; do \
E 8
E 7
E 3
E 2
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1

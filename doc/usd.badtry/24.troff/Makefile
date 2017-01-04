#
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.9 (Berkeley) 10/27/04
#
INTRO=	m0
TUTOR=	m0a
PAPER=	m1 m2 m3 m4
APNDX=	apndxa apndxb apndxc apndxd
APNDXT=	m5
MACROS=	m.mac
PARTS=	intro.ps tutor.ps paper.ps apndxa.ps apndxb.ps apndxc.ps apndxd.ps \
	apndxt.ps
TBL=	tbl
TROFF=	pstroff
TROPTS=	-fR,I,B,BI,S

all:	manual.ps

manual.ps:	${PARTS}
	pstmerge ${PARTS} > $@

intro.ps: ${INTRO}
	${TROFF} ${TROPTS} ${MACROS} ${INTRO} > $@

# We have to cut off an extra page with psrange because the last page is
# full, ends with a table, and .TE's .sp causes a spill :-(
tutor.ps: ${TUTOR}
	${TBL} ${TUTOR} | ${TROFF} ${TROPTS} ${MACROS} - | psrange 1-5 > $@

paper.ps: ${PAPER}
	${TBL} ${PAPER} | ${TROFF} ${TROPTS} ${MACROS} - > $@

apndxa.ps: apndxa
	${TBL} apndxa | ${TROFF} ${TROPTS} ${MACROS} - > $@

apndxb.ps: apndxb
	${TROFF} -fR,I,B,BI,H,HO,HB,HQ,C,CO,CB,CQ ${MACROS} apndxb > $@

apndxc.ps: apndxc
	${TROFF} -fR,I,B,BI,CB ${MACROS} apndxc > $@

apndxd.ps: apndxd VarianSpecial.ps apndxd.fonts
	${TROFF} -Fapndxd.fonts -fR,I,B,BI,CB,VS ${MACROS} apndxd | \
		sed -e 's/^5 9 SF$$/VSF setfont/' -e '/^%DELETEME%$$/d' > $@

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

apndxt.ps: ${APNDXT}
	${TROFF} ${TROPTS} ${MACROS} ${APNDXT} > apndxt.ps

clean:
	rm -f *.o *.ps *.spell errs Errs make.out a.out core
	rm -rf apndxd.fonts

spell:	${INTRO} ${TUTOR} ${PAPER} ${APNDX} ${APNDXT}
	@for i in ${INTRO} ${TUTOR} ${PAPER} ${APNDX} ${APNDXT}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done

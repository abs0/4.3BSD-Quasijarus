# Top level Makefile for the USD book
# Harhan preliminary edition
#
#	@(#)Makefile	6.4 (Berkeley) 10/08/23

SUBDIR=	01.begin 02.learn 03.shell 04.csh 05.dc 06.bc \
	07.Mail 09.newsread 10.etiq 11.notes \
	12.edtut 13.edadv 14.edit 15.vi 16.ex 17.jove 18.sed 19.awk \
	20.msmacros 21.msdiffs 22.memacros 23.meref 24.troff 25.trofftut \
	26.eqn 27.eqnguide 28.tbl 29.refer 30.invert 31.bib 32.diction \
	33.rogue 34.trek
DOCS=	01.begin/begin.ps 02.learn/learn.ps 03.shell/shell.ps 04.csh/csh.ps \
	05.dc/dc.ps 06.bc/bc.ps 07.Mail/paper.ps \
	12.edtut/edtut.ps 13.edadv/edadv.ps 14.edit/paper.ps 15.vi/paper.ps \
	16.ex/paper.ps 17.jove/paper.ps 18.sed/sed.ps 19.awk/awk.ps \
	20.msmacros/ms.ps 21.msdiffs/paper.ps 22.memacros/intro.ps \
	23.meref/ref.ps 24.troff/manual.ps 25.trofftut/trofftut.ps \
	26.eqn/eqn.ps 27.eqnguide/eqnguide.ps 28.tbl/tbl.ps 29.refer/paper.ps \
	30.invert/refer.ps 31.bib/paper.ps 32.diction/diction.ps \
	33.rogue/paper.ps 34.trek/paper.ps

all:	usd.ps usdcover.ps

${SUBDIR}: FRC
	cd $@; make ${MFLAGS}

Title.ps: Title
	pstroff Title > $@

00.contents.ps: 00.contents
	pstroff -ms 00.contents > $@

usd.ps:	${SUBDIR} Title.ps 00.contents.ps
	pstmerge -STs Title.ps 00.contents.ps ${DOCS} > $@

usdcover.ps:	Title.ps
	psrange Title.ps 1 > usdcover.ps
	ex - usdcover.ps < ../../man/psman/fixcover.ex

clean: FRC
	rm -f *.ps core errs
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

FRC:

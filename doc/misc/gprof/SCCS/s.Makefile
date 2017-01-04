h42614
s 00007/00003/00025
d D 5.2 86/06/17 19:53:11 mckusick 3 2
c add pic
e
s 00022/00036/00006
d D 5.1 86/06/17 14:51:55 mckusick 2 1
c update for reprinting
e
s 00042/00000/00000
d D 1.1 83/03/18 15:30:05 peter 1 0
c date and time created 83/03/18 15:30:05 by peter
e
u
U
t
T
I 1
#
D 2
#	since vtroff is a cshell script, the semi-colon is needed
#	to get a cshell to execute the vtroff commands.
E 2
I 2
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 2
#
D 2
#	%M% %I% %G% %U%
E 2
I 2
#	%W% (Berkeley) %G%
#
SRCS=	header.me abstract.me intro.me profiling.me gathering.me \
	postp.me present.me refs.me
I 3
PICSRC= postp1.pic postp2.pic postp3.pic pres1.pic pres2.pic
E 3
MACROS=	-me
PRINTER=Pdp
I 3
SOELIM=	soelim
E 3
EQN=	deqn -${PRINTER}
TBL=	dtbl -${PRINTER}
I 3
PIC= 	pic -${PRINTER}
E 3
TROFF=	ditroff -${PRINTER}
E 2

D 2
HEADER = header.me
FILES = abstract.me intro.me profiling.me gathering.me \
      postp.tbl.eqn present.tbl refs.me
MES = abstract.me intro.me profiling.me gathering.me \
      postp.me present.me refs.me
E 2
I 2
paper:	paper.${PRINTER}
	lpr -${PRINTER} -n paper.${PRINTER}
E 2

D 2
all: $(FILES)
	vtroff -t -me $(HEADER) $(FILES) >/tmp/peter.vpr-t;
	vpr -t /tmp/peter.vpr-t
E 2
I 2
D 3
paper.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${EQN} | ${TROFF} ${MACROS} -t > paper.${PRINTER}
E 3
I 3
paper.${PRINTER}: ${SRCS} ${PICSRC}
	${SOELIM} ${SRCS} | ${PIC} | ${TBL} | ${EQN} | \
	${TROFF} ${MACROS} -t > paper.${PRINTER}
E 3
E 2

D 2
Wall: $(FILES)
	vtroff -W -l14 -t -me Wheader.me $(FILES) > ccc.vpr-t-W;

vpr-t: $(FILES)
	vtroff -t -me $(HEADER) $(FILES) >/tmp/peter.vpr-t;

equations.eqn: equations.me
	eqn < equations.me > equations.eqn

postp.tbl.eqn: postp.me
	tbl postp.me | eqn > postp.tbl.eqn

present.tbl: present.me
	tbl < present.me > present.tbl

sources: $(HEADER) $(MES)

$(HEADER) $(MES):
	sccs get $@

echo:
	@echo ${HEADER} ${MES}

E 2
clean:
D 2
	rm *.vpr-t
	touch $(MES)
E 2
I 2
D 3
	rm -f paper.[PT]* *.spell errs Errs make.out
E 3
I 3
	rm -f paper.[PTp]* *.spell errs Errs make.out
E 3

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 2
E 1

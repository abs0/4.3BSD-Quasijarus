h17161
s 00007/00007/00017
d D 6.3 04/10/24 01:43:04 msokolov 3 2
c ditroff => pstroff
e
s 00002/00002/00022
d D 6.2 86/04/16 16:46:50 eric 2 1
c oops....
e
s 00024/00000/00000
d D 6.1 86/04/16 16:29:13 eric 1 0
c date and time created 86/04/16 16:29:13 by eric
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
SRCS=	intro.me
D 3
DEVICE=	dp
TROFF=	ditroff -P${DEVICE}
E 3
I 3
TROFF=	pstroff
E 3

D 2
paper:	intro.me
E 2
I 2
D 3
paper:	intro.${DEVICE}
E 2
	lpr -P${DEVICE} -n intro.${DEVICE}
E 3
I 3
all:	intro.ps
E 3

D 2
uchanges: ${SRCS}
E 2
I 2
D 3
intro.${DEVICE}: ${SRCS}
E 2
	${TROFF} -me -t ${SRCS} > intro.${DEVICE}
E 3
I 3
intro.ps: ${SRCS}
	${TROFF} -me -t ${SRCS} > intro1.ps
	psrange intro1.ps 2- > intro.ps
	rm -f intro1.ps
E 3

clean:
D 3
	rm -f intro.${DEVICE} *.spell errs Errs make.out
E 3
I 3
	rm -f *.ps *.spell errs Errs make.out
E 3

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1

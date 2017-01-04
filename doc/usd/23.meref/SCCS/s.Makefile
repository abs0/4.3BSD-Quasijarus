h14073
s 00007/00007/00017
d D 6.3 04/10/24 01:59:41 msokolov 3 2
c ditroff => pstroff
e
s 00002/00002/00022
d D 6.2 86/04/16 16:46:06 eric 2 1
c oops....
e
s 00024/00000/00000
d D 6.1 86/04/16 16:29:09 eric 1 0
c date and time created 86/04/16 16:29:09 by eric
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
SRCS=	ref.me
D 3
DEVICE=	dp
TROFF=	ditroff -P${DEVICE}
E 3
I 3
TROFF=	pstroff
E 3

D 2
paper:	ref.me
E 2
I 2
D 3
paper:	ref.${DEVICE}
E 2
	lpr -P${DEVICE} -n ref.${DEVICE}
E 3
I 3
all:	ref.ps
E 3

D 2
uchanges: ${SRCS}
E 2
I 2
D 3
ref.${DEVICE}: ${SRCS}
E 2
	${TROFF} -me -t ${SRCS} > ref.${DEVICE}
E 3
I 3
ref.ps: ${SRCS}
	${TROFF} -me -t ${SRCS} > ref1.ps
	psrange ref1.ps 2- > ref.ps
	rm -f ref1.ps
E 3

clean:
D 3
	rm -f ref.${DEVICE} *.spell errs Errs make.out
E 3
I 3
	rm -f *.ps *.spell errs Errs make.out
E 3

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 1

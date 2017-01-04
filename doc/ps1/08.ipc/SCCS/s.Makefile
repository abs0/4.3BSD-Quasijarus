h14215
s 00016/00010/00011
d D 1.2 86/05/02 17:41:06 karels 2 1
c corrections
e
s 00021/00000/00000
d D 1.1 86/04/30 12:29:50 karels 1 0
c date and time created 86/04/30 12:29:50 by karels
e
u
U
t
T
I 2
#
E 2
I 1
# Copyright (c) 1986 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
D 2
# Makefile to run off revised 4.3 ipc primer
#
E 2
I 2
SRCS=	0.t 1.t 2.t 3.t 4.t 5.t
MACROS=	-ms
PRINTER=-Pdp
EQN=	deqn ${PRINTER}
TBL=	dtbl ${PRINTER}
TROFF=	ditroff ${PRINTER}
E 2

D 2
TROFF= ditroff
PKG= -ms
TBL= dtbl
TBLARGS =
PRINTER = -Pdp
E 2
I 2
ipc:	ipc.${PRINTER}
	lpr ${PRINTER} -n ipc.${PRINTER}
E 2

D 2
ipc: 0.t 1.t 2.t 3.t 4.t 5.t
	$(TBL) $(TBLARGS) *.t | $(TROFF) $(PKG) $(PRINTER)
E 2
I 2
ipc.${PRINTER}: ${SRCS}
	${TBL} ${SRCS} | ${TROFF} ${MACROS} -t > ipc.${PRINTER}
E 2

clean:
D 2
	rm *.imP *.bak *.CKP
E 2
I 2
	rm -f ipc.-* *.spell errs Errs make.out
E 2

I 2
spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done
E 2
E 1

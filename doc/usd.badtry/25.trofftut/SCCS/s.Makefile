h64109
s 00001/00001/00016
d D 6.3 10/10/10 00:50:26 msokolov 3 2
c use the new pstroff -T option
e
s 00002/00006/00015
d D 6.2 10/08/23 21:19:00 msokolov 2 1
c new pstmerge/pstfinish
e
s 00021/00000/00000
d D 6.1 04/10/31 16:25:05 msokolov 1 0
c date and time created 04/10/31 16:25:05 by msokolov
e
u
U
t
T
I 1
# Makefile for B. W. Kernighan's TROFF Tutorial
# requires troffemu fonts
#
#	%W%	(Berkeley)	%E%

SRCS=	tt.mac tt00 tt01 tt02 tt03 tt04 tt05 tt06 tt07 tt08 tt09 tt10 tt11 \
	tt12 tt13 tt14 ttack ttcharset ttindex
TROFF=	pstroff
D 3
TROPTS=	-F/usr/lib/pstroff/troffemu
E 3
I 3
TROPTS=	-T
E 3
D 2
MERGE=	pstmerge
E 2

all:	trofftut.ps

D 2
trofftut1.ps:	${SRCS}
	${TROFF} ${TROPTS} -ms ${SRCS} > $@

trofftut.ps:	trofftut1.ps
	${MERGE} -T trofftut1.ps > $@
E 2
I 2
trofftut.ps:	${SRCS}
	${TROFF} ${TROPTS} -ms ${SRCS} | pstfinish > $@
E 2

clean:
	rm -f core errs *.ps
E 1

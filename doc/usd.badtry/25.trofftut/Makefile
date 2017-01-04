# Makefile for B. W. Kernighan's TROFF Tutorial
# requires troffemu fonts
#
#	@(#)Makefile	6.3	(Berkeley)	10/10/10

SRCS=	tt.mac tt00 tt01 tt02 tt03 tt04 tt05 tt06 tt07 tt08 tt09 tt10 tt11 \
	tt12 tt13 tt14 ttack ttcharset ttindex
TROFF=	pstroff
TROPTS=	-T

all:	trofftut.ps

trofftut.ps:	${SRCS}
	${TROFF} ${TROPTS} -ms ${SRCS} | pstfinish > $@

clean:
	rm -f core errs *.ps

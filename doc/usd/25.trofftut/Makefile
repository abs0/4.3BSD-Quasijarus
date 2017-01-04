# Makefile for the PostScript reprint of 4.3BSD document USD:25

SRCS=	tt.mac tt00 tt01 tt02 tt03 tt04 tt05 tt06 tt07 tt08 tt09 tt10 tt11 \
	tt12 tt13 tt14 ttack ttcharset #ttindex
# ttindex wasn't included in the original Usenix print,
# so let's not bother with it either - it seems to be broken anyway.
TROFF=	pstroff
TROPTS=	-T

all:	trofftut.ps

trofftut.ps:	${SRCS}
	${TROFF} ${TROPTS} -ms ${SRCS} | pstfinish -l USD:25-%l > $@

clean:
	rm -f core errs *.ps

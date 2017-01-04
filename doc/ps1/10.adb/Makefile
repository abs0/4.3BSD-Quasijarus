#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	6.2 (Berkeley) 9/13/04
#
TROFF=	pstroff

SRCS=	adb.ms

all:	adb.ps

adb.ps:	${SRCS}
	${TROFF} -ms ${SRCS} > adb.ps

clean:
	rm -f adb.ps

spell:	${SRCS}
	@for i in ${SRCS}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done

#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
#	@(#)Makefile	6.1 (Berkeley) 12/4/03
#
NROFF=	nroff

SRC=	title.t 0a.t 0b.t

qjchanges.txt: ${SRC}
	${NROFF} -ms ${SRC} | colcrt - > qjchanges.txt

clean:
	rm -f qjchanges.txt ?.t.spell errs Errs

spell:	${SRC}
	@for i in ${SRC}; do \
		echo $$i; spell $$i | sort | comm -23 - spell.ok > $$i.spell; \
	done

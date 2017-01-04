h30803
s 00011/00002/00033
d D 5.1 85/06/07 16:27:15 dist 4 3
c Add copyright
e
s 00000/00000/00035
d D 4.1 83/07/25 20:15:30 eric 3 2
c 4.2 release version
e
s 00007/00002/00028
d D 3.2 83/03/12 22:28:10 eric 2 1
c add usenix.me; be usable in /usr/doc/sendmail
e
s 00030/00000/00000
d D 3.1 83/03/12 22:22:54 eric 1 0
c date and time created 83/03/12 22:22:54 by eric
e
u
U
f b 
f i 
t
T
I 1
#
D 4
#	Makefile for sendmail documentation
E 4
I 4
#  Sendmail
#  Copyright (c) 1983  Eric P. Allman
#  Berkeley, California
E 4
#
D 4
#	%W%	%Y%	%G%
E 4
I 4
#  Copyright (c) 1983 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
#
#	Makefile for sendmail documentation
E 4
#

D 2
OBJS=	intro.lpr op.lpr
SRCS=	intro.me  op.me  sendmail.8 syslog.3 syslog.8
E 2
I 2
OBJS=	intro.lpr op.lpr usenix.lpr
DOCS=	intro.me  op.me  usenix.me
SRCS=	$(DOCS) sendmail.8 syslog.3 syslog.8
E 2
ALL=	$(OBJS) rfc819.lpr rfc821.lpr rfc822.lpr

LPR=	lpr
I 2
TROFF=	vtroff
E 2
GET=	sccs get

.SUFFIXES: .me .lpr

.me.lpr:
	nroff -me -Tlp $< > $@
I 2

troff: $(DOCS)
	for i in $(DOCS); do $(TROFF) -me $$i; done
E 2

all: $(ALL)

print: $(ALL)
	$(LPR) $(ALL)

sources: $(SRCS)

$(SRCS):
	$(GET) $(REL) SCCS/s.$@

clean:
	rm -f $(OBJS) a.out core
E 1

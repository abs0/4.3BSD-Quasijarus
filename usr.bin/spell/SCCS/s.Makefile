h48625
s 00001/00001/00089
d D 4.9 87/10/07 09:34:29 bostic 10 9
c fix mkdir line
e
s 00077/00042/00013
d D 4.8 87/06/18 23:33:31 bostic 9 7
c new template
e
s 00002/00000/00053
d D 4.7 87/05/31 21:32:31 bostic 7 6
c added depend label
e
s 00016/00011/00037
d D 4.6 87/03/16 14:21:37 mckusick 6 5
c Add second set of local files for George Bergman
e
s 00010/00010/00038
d D 4.5 87/03/12 12:22:22 mckusick 5 4
c set modes correctly!
e
s 00021/00006/00027
d D 4.4 87/03/12 12:08:05 mckusick 4 3
c update for new file names and installation
e
s 00001/00001/00032
d D 4.3 83/05/25 14:12:46 ralph 3 2
c fixed clean entry
e
s 00008/00006/00025
d D 4.2 83/02/14 13:53:40 shannon 2 1
c don't strip programs until installed
e
s 00031/00000/00000
d D 4.1 82/12/18 15:10:36 sam 1 0
c date and time created 82/12/18 15:10:36 by sam
e
u
U
t
T
I 1
D 9
#	%W%	%G%

E 9
I 9
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 9
I 4
D 6
# The word lists may be extended by adding local words.
E 6
I 6
# The word lists may be extended by adding special words.
E 6
# The set of files containing words to be added are defined
D 6
# by LOCAL below. By default we add commands and library
# function names defined in /usr/man/man[1238n].
E 6
I 6
D 9
# by SPECIAL below. By default we add commands and library
# function names defined in /usr/man/man[1238n]. The word
# lists also may be extended by adding local words. The set
E 9
I 9
# by SPECIAL below.  By default we add commands and library
# function names defined in /usr/man/man[1238n].  The word
# lists also may be extended by adding local words.  The set
E 9
# of files containing words to be added are defined by LOCAL
D 9
# below. Typically these lists reside in /usr/local/dict.
E 9
I 9
# below.  Typically these lists reside in /usr/local/dict.
E 9
E 6

D 6
LOCAL=special.4bsd
E 6
I 6
D 9
SPECIAL=special.4bsd
LOCAL=
E 9
I 9
SPECIAL=	special.4bsd
E 9
E 6

E 4
I 2
D 9
CFLAGS= -O
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	spell.c spellin.c spellout.c
OBJS=	spell.o spellin.o spellout.o
E 9

E 2
D 9
all:	spell hlist hlista hlistb hstop spellin spellout
E 9
I 9
all: spell hlist hlista hlistb hstop spellin spellout
E 9

D 9
install:	all
	install -s spell $(DESTDIR)/usr/lib
	install -s spellin ${DESTDIR}/usr/bin
	install -s spellout ${DESTDIR}/usr/bin
I 4
	install -c spell.sh $(DESTDIR)/usr/bin/spell
E 4
D 5
	install -c hlista $(DESTDIR)/usr/dict
	install -c hlistb $(DESTDIR)/usr/dict
	install -c hstop $(DESTDIR)/usr/dict
D 4
	install -c spell.sh $(DESTDIR)/usr/bin/spell
E 4
I 4
	install -c words $(DESTDIR)/usr/dict
	install -c american $(DESTDIR)/usr/dict
	install -c british $(DESTDIR)/usr/dict
	install -c stop $(DESTDIR)/usr/dict
	install -c README $(DESTDIR)/usr/dict
E 5
I 5
D 6
	install -m 444 -c hlista $(DESTDIR)/usr/dict
	install -m 444 -c hlistb $(DESTDIR)/usr/dict
	install -m 444 -c hstop $(DESTDIR)/usr/dict
E 6
I 6
	install -m 444 hlista $(DESTDIR)/usr/dict
	install -m 444 hlistb $(DESTDIR)/usr/dict
	install -m 444 hstop $(DESTDIR)/usr/dict
	install -m 444 hlist $(DESTDIR)/usr/dict
E 6
	install -m 444 -c words $(DESTDIR)/usr/dict
	install -m 444 -c american $(DESTDIR)/usr/dict
	install -m 444 -c british $(DESTDIR)/usr/dict
	install -m 444 -c stop $(DESTDIR)/usr/dict
	install -m 444 -c README $(DESTDIR)/usr/dict
E 5
	-mkdir $(DESTDIR)/usr/dict/special
D 5
	install -c special.4bsd $(DESTDIR)/usr/dict/special/4bsd
	install -c special.math $(DESTDIR)/usr/dict/special/math
E 5
I 5
	install -m 444 -c special.4bsd $(DESTDIR)/usr/dict/special/4bsd
	install -m 444 -c special.math $(DESTDIR)/usr/dict/special/math
E 9
I 9
spell: spell.c
	${CC} ${CFLAGS} spell.c -o $@
E 9
E 5
E 4

D 9
clean:	
D 3
	rm -f spell spellin hlista hlistb hlist hstop spellout
E 3
I 3
	rm -f *.o spell spellin hlista hlistb hlist hstop spellout
E 9
I 9
spellin: spellin.c
	${CC} ${CFLAGS} spellin.c -o $@
E 9
E 3

D 2
spell: spell.c
	cc -s -O spell.c -o spell
spellin: spellin.c
	cc -O -s spellin.c -o spellin
spellout: spellout.c
	cc -O -s spellout.c -o spellout
E 2
I 2
D 9
spell: spell.o
	cc spell.o -o spell
spellin: spellin.o
	cc spellin.o -o spellin
spellout: spellout.o
	cc spellout.o -o spellout
E 9
I 9
spellout: spellout.c
	${CC} ${CFLAGS} spellout.c -o $@
E 9
E 2

hlist: /usr/dict/words spellin
D 4
	spellin </usr/dict/words >hlist
hlista: american local hlist spellin
	(cat american local)|spellin hlist >hlista
hlistb: british local hlist spellin
	(cat british local)|spellin hlist >hlistb
E 4
I 4
D 9
	spellin <words >hlist
D 6
hlista: american $(LOCAL) hlist spellin
	(cat american $(LOCAL))|spellin hlist >hlista
hlistb: british $(LOCAL) hlist spellin
	(cat british $(LOCAL))|spellin hlist >hlistb
E 6
I 6
hlista: american $(SPECIAL) $(LOCAL) hlist spellin
	(cat american $(SPECIAL) $(LOCAL))|spellin hlist >hlista
hlistb: british $(SPECIAL) $(LOCAL) hlist spellin
	(cat british $(SPECIAL) $(LOCAL))|spellin hlist >hlistb
E 9
I 9
	spellin < words >hlist

hlista: american ${SPECIAL} ${LOCAL} hlist spellin
	(cat american ${SPECIAL} ${LOCAL}) | spellin hlist > hlista

hlistb: british ${SPECIAL} ${LOCAL} hlist spellin
	(cat british ${SPECIAL} ${LOCAL}) | spellin hlist > hlistb

E 9
E 6
E 4
hstop: stop spellin
D 9
	spellin <stop >hstop
E 9
I 9
	spellin < stop >hstop
E 9
I 7

D 9
depend:
E 9
I 9
clean: FRC
	rm -f ${OBJS} core spell spellin hlista hlistb hlist hstop spellout

depend: FRC
	mkdep -p ${CFLAGS} ${SRCS}

install: FRC
D 10
	-mkdir ${DESTDIR}/usr/dict/special > /dev/null 2>&1
E 10
I 10
	-[ -d ${DESTDIR}/usr/dict/special ] || mkdir ${DESTDIR}/usr/dict/special
E 10
	install -s -o bin -g bin -m 755 spell ${DESTDIR}/usr/lib/spell
	install -s -o bin -g bin -m 755 spellin ${DESTDIR}/usr/bin/spellin
	install -s -o bin -g bin -m 755 spellout ${DESTDIR}/usr/bin/spellout
	install -c -o bin -g bin -m 755 spell.sh ${DESTDIR}/usr/bin/spell
	install -o bin -g bin -m 444 hlista ${DESTDIR}/usr/dict/hlista
	install -o bin -g bin -m 444 hlistb ${DESTDIR}/usr/dict/hlistb
	install -o bin -g bin -m 444 hstop ${DESTDIR}/usr/dict/hstop
	install -o bin -g bin -m 444 hlist ${DESTDIR}/usr/dict/hlist
	install -c -o bin -g bin -m 444 words ${DESTDIR}/usr/dict/words
	install -c -o bin -g bin -m 444 american ${DESTDIR}/usr/dict/american
	install -c -o bin -g bin -m 444 british ${DESTDIR}/usr/dict/british
	install -c -o bin -g bin -m 444 stop ${DESTDIR}/usr/dict/stop
	install -c -o bin -g bin -m 444 README ${DESTDIR}/usr/dict/README
	install -c -o bin -g bin -m 444 special.4bsd ${DESTDIR}/usr/dict/special/4bsd
	install -c -o bin -g bin -m 444 special.math ${DESTDIR}/usr/dict/special/math

lint: FRC
	lint ${CFLAGS} spell.c
	lint ${CFLAGS} spellin.c
	lint ${CFLAGS} spellout.c

tags: FRC
	ctags spell.c
	ctags -a spellin.c
	ctags -a spellout.c
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

spell: spell.c spell.h /usr/include/stdio.h /usr/include/ctype.h
spellin: spellin.c spell.h /usr/include/stdio.h /usr/include/ctype.h
spellout: spellout.c spell.h /usr/include/stdio.h /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 7
E 1

h23672
s 00005/00005/00188
d D 4.10 87/12/12 19:52:08 bostic 11 10
c remove sortbib.o on clean
e
s 00001/00001/00192
d D 4.9 87/10/07 09:32:17 bostic 10 9
c fix mkdir line
e
s 00125/00080/00068
d D 4.8 87/06/23 11:46:13 bostic 9 7
c new template
e
s 00126/00081/00067
d R 4.8 87/06/18 23:11:10 bostic 8 7
c new template
e
s 00091/00012/00057
d D 4.7 87/05/06 09:13:09 bostic 7 6
c added depend
e
s 00043/00032/00026
d D 4.6 87/05/01 17:21:19 bostic 6 5
c reworked to install correctly
e
s 00001/00001/00057
d D 4.5 84/06/05 16:47:41 ralph 5 4
c no -i option to ld.
e
s 00002/00002/00056
d D 4.4 83/06/22 13:02:54 garrison 4 3
c added tick.o to hunt
e
s 00002/00002/00056
d D 4.3 83/05/08 16:11:39 mckusick 3 2
c don't forget to strip the .sh from the shell scripts!
e
s 00011/00011/00047
d D 4.2 83/05/08 15:35:31 mckusick 2 1
c cleanups and standardizations
e
s 00058/00000/00000
d D 4.1 83/05/08 14:44:17 mckusick 1 0
c date and time created 83/05/08 14:44:17 by mckusick
e
u
U
t
T
I 1
D 9
#	%W%	(Berkeley)	%E%
E 9
#
D 2
DESTDIR=/usr/new
E 2
I 2
D 9
DESTDIR=
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W%	(Berkeley)	%G%
#
E 9
E 2
D 7
CFLAGS = -O
E 7
I 7
CFLAGS=	-O
I 9
LIBC=	/lib/libc.a
DLSRCS=	deliv1.c deliv2.c
DLOBJS=	deliv1.o deliv2.o
HTSRCS=	deliv2.c glue4.c glue5.c hunt1.c hunt2.c hunt3.c hunt5.c hunt6.c \
	hunt7.c hunt8.c hunt9.c refer3.c shell.c tick.c
HTOBJS=	deliv2.o glue4.o glue5.o hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o \
	hunt7.o hunt8.o hunt9.o refer3.o shell.o tick.o
INSRCS=	inv1.c inv2.c inv3.c inv5.c inv6.c deliv2.c
INOBJS=	inv1.o inv2.o inv3.o inv5.o inv6.o deliv2.o
MKSRCS=	mkey1.c mkey2.c mkey3.c deliv2.c
MKOBJS=	mkey1.o mkey2.o mkey3.o deliv2.o
RFSRCS=	deliv2.c glue1.c glue2.c glue3.c glue4.c glue5.c hunt2.c hunt3.c \
	hunt5.c hunt6.c hunt7.c hunt8.c hunt9.c mkey3.c refer0.c refer1.c \
	refer2.c refer4.c refer5.c refer6.c refer7.c refer8.c shell.c
RFOBJS=	deliv2.o glue1.o glue2.o glue3.o glue4.o glue5.o hunt2.o hunt3.o \
	hunt5.o hunt6.o hunt7.o hunt8.o hunt9.o mkey3.o refer0.o refer1.o \
	refer2.o refer4.o refer5.o refer6.o refer7.o refer8.o shell.o
WHSRCS=	what1.c what2.c what3.c what4.c shell.c mkey3.c
WHOBJS=	what1.o what2.o what3.o what4.o shell.o mkey3.o
SRCS=	addbib.c lookbib.c ${DLSRCS} ${HTSRCS} ${INSRCS} ${MKSRCS} ${RFSRCS} \
	${WHSRCS}
D 11
OBJS=	addbib.o lookbib.o ${DLOBJS} ${HTOBJS} ${INOBJS} ${MKOBJS} ${RFOBJS} \
	${WHOBJS}
E 11
I 11
OBJS=	addbib.o lookbib.o sortbib.o ${DLOBJS} ${HTOBJS} ${INOBJS} ${MKOBJS} \
	${RFOBJS} ${WHOBJS}
E 11
E 9
E 7

D 9
all:	mkey inv hunt refer addbib lookbib sortbib
E 9
I 9
all:	addbib deliv hunt inv lookbib mkey refer sortbib whatabout
E 9

D 9
mkey: mkey1.o mkey2.o mkey3.o deliv2.o
D 6
	cc mkey?.o deliv2.o -o mkey
E 6
I 6
	${CC} mkey?.o deliv2.o -o $@
E 9
I 9
addbib: addbib.o
	${CC} ${CFLAGS} addbib.o -o $@
E 9

E 6
D 9
inv: inv1.o inv2.o inv3.o inv5.o inv6.o deliv2.o
D 6
	cc inv?.o deliv2.o -o inv
E 6
I 6
	${CC} inv?.o deliv2.o -o $@
E 9
I 9
deliv: ${DLOBJS} ${LIBC}
	${CC} ${CFLAGS} ${DLOBJS} -o $@
E 9

E 6
D 9
hunt: hunt1.o hunt2.o hunt3.o hunt5.o hunt6.o hunt7.o glue5.o
D 4
hunt: refer3.o hunt9.o shell.o deliv2.o hunt8.o glue4.o
	cc hunt?.o refer3.o glue5.o glue4.o shell.o deliv2.o -o hunt
E 4
I 4
hunt: refer3.o hunt9.o shell.o deliv2.o hunt8.o glue4.o tick.o
D 6
	cc hunt?.o refer3.o glue5.o glue4.o shell.o deliv2.o tick.o -o hunt
E 6
I 6
	${CC} hunt?.o refer3.o glue5.o glue4.o shell.o deliv2.o tick.o -o $@
E 9
I 9
hunt: ${HTOBJS} ${LIBC}
	${CC} ${CFLAGS} ${HTOBJS} -o $@
E 9
E 6
E 4

D 6
glue3.o: refer..c
hunt2.o: refer..c
hunt3.o: refer..c
refer0.o: refer..c
refer1.o: refer..c
refer2.o: refer..c
refer3.o: refer..c
refer4.o: refer..c
refer6.o: refer..c
refer5.o: refer..c
E 6
D 9
refer: glue1.o refer1.o refer2.o refer4.o refer5.o refer6.o mkey3.o
refer: refer7.o refer8.o hunt2.o hunt3.o deliv2.o hunt5.o hunt6.o hunt8.o
refer: glue3.o hunt7.o hunt9.o glue2.o glue4.o glue5.o refer0.o shell.o
D 5
	cc -i glue?.o refer[01245678].o hunt[2356789].o mkey3.o shell.o deliv2.o -o refer
E 5
I 5
D 6
	cc glue?.o refer[01245678].o hunt[2356789].o mkey3.o shell.o deliv2.o -o refer
E 6
I 6
	${CC} glue?.o refer[01245678].o hunt[2356789].o mkey3.o shell.o \
		deliv2.o -o $@
E 9
I 9
inv: ${INOBJS} ${LIBC}
	${CC} ${CFLAGS} ${INOBJS} -o $@
E 9
E 6
E 5

D 9
addbib: addbib.o
D 6
	cc addbib.o -o addbib
E 6
I 6
	${CC} addbib.o -o $@

E 9
E 6
lookbib: lookbib.o
D 6
	cc lookbib.o -o lookbib
E 6
I 6
D 9
	${CC} lookbib.o -o $@
E 9
I 9
	${CC} ${CFLAGS} lookbib.o -o $@
E 9

I 9
mkey: ${MKOBJS} ${LIBC}
	${CC} ${CFLAGS} ${MKOBJS} -o $@

refer: ${RFOBJS} ${LIBC}
	${CC} ${CFLAGS} ${RFOBJS} -o $@

# refpart doesn't compile
#
#RPSRCS=	deliv2.c glue4.c glue5.c mkey3.c refer0.c refer1.c refer2.c \
#	refer3.c refer4.c refer5.c refer6.c refer7.c refer8.c
#RPOBJS=	deliv2.o glue4.o glue5.o mkey3.o refer0.o refer1.o refer2.o \
#	refer3.o refer4.o refer5.o refer6.o refer7.o refer8.o
#refpart: ${RPOBJS} ${LIBC}
#	${CC} ${CFLAGS} ${RPOBJS} -o $@

E 9
E 6
sortbib: sortbib.o
D 6
	cc sortbib.o -o sortbib
E 6
I 6
D 9
	${CC} sortbib.o -o $@
E 9
I 9
	${CC} ${CFLAGS} sortbib.o -o $@
E 9
E 6

I 6
D 9
whatabout: what1.o what2.o what3.o what4.o shell.o mkey3.o
	${CC} what?.o shell.o mkey3.o -o $@
E 9
I 9
whatabout: ${WHOBJS} ${LIBC}
	${CC} ${CFLAGS} ${WHOBJS} -o $@
E 9

D 9
deliv: deliv1.o deliv2.o
	${CC} deliv?.o -o $@
E 9
I 9
clean: FRC
	rm -f ${OBJS} core addbib deliv hunt inv lookbib mkey refer \
		refpart sortbib whatabout
E 9

D 9
refpart: refer0.o refer1.o refer2.o refer3.o refer4.o refer5.o
refpart: refer6.o refer7.o refer8.o deliv2.o glue4.o
	${CC} refer?.o deliv2.o glue4.o -o $@
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 9

E 6
D 9
install: all
D 2
	install -s mkey /usr/lib/refer
	install -s inv  /usr/lib/refer
	install -s hunt /usr/lib/refer
	install -s refer $(DESTDIR)
	install -s addbib $(DESTDIR)
	install -s sortbib $(DESTDIR)
	install roffbib $(DESTDIR)
	install indxbib $(DESTDIR)
	install -s lookbib $(DESTDIR)
	install tmac.bib /usr/lib/tmac
E 2
I 2
D 6
	install -s mkey $(DESTDIR)/usr/lib/refer
	install -s inv  $(DESTDIR)/usr/lib/refer
	install -s hunt $(DESTDIR)/usr/lib/refer
	install -s refer $(DESTDIR)/usr/bin
	install -s addbib $(DESTDIR)/usr/bin
	install -s sortbib $(DESTDIR)/usr/bin
E 6
I 6
	-mkdir /usr/lib/refer
	install mkey $(DESTDIR)/usr/lib/refer/mkey
	install inv  $(DESTDIR)/usr/lib/refer/inv
	install hunt $(DESTDIR)/usr/lib/refer/hunt
	install refer $(DESTDIR)/usr/bin/refer
	install addbib $(DESTDIR)/usr/bin/addbib
	install sortbib $(DESTDIR)/usr/bin/sortbib
E 6
D 3
	install -c roffbib.sh $(DESTDIR)/usr/bin
	install -c indxbib.sh $(DESTDIR)/usr/bin
E 3
I 3
	install -c roffbib.sh $(DESTDIR)/usr/bin/roffbib
	install -c indxbib.sh $(DESTDIR)/usr/bin/indxbib
E 3
D 6
	install -s lookbib $(DESTDIR)/usr/bin
E 6
I 6
	install lookbib $(DESTDIR)/usr/bin/lookbib
E 6
	install -c tmac.bib $(DESTDIR)/usr/lib/tmac
E 9
I 9
install: FRC
D 10
	-mkdir /usr/lib/refer > /dev/null 2>&1
E 10
I 10
	-[ -d ${DESTDIR}/usr/lib/refer ] || mkdir ${DESTDIR}/usr/lib/refer
E 10
	install -s -o bin -g bin -m 755 mkey ${DESTDIR}/usr/lib/refer/mkey
	install -s -o bin -g bin -m 755 inv ${DESTDIR}/usr/lib/refer/inv
	install -s -o bin -g bin -m 755 hunt ${DESTDIR}/usr/lib/refer/hunt
	install -s -o bin -g bin -m 755 refer ${DESTDIR}/usr/bin/refer
	install -s -o bin -g bin -m 755 addbib ${DESTDIR}/usr/bin/addbib
	install -s -o bin -g bin -m 755 sortbib ${DESTDIR}/usr/bin/sortbib
	install -s -o bin -g bin -m 755 lookbib ${DESTDIR}/usr/bin/lookbib
	install -c -o bin -g bin -m 755 roffbib.sh ${DESTDIR}/usr/bin/roffbib
	install -c -o bin -g bin -m 755 indxbib.sh ${DESTDIR}/usr/bin/indxbib
	install -c -o bin -g bin -m 755 tmac.bib ${DESTDIR}/usr/lib/tmac
E 9
I 6
D 7
	(cd /usr/dict/papers; sh runinv)
E 7
I 7
	(cd /usr/dict/papers; /bin/sh runinv)
E 7

E 6
E 2
D 9
clean:
D 6
	rm -f refer inv hunt mkey addbib lookbib sortbib *.o
E 6
I 6
	rm -f ${all} *.o errs core
E 9
I 9
lint: FRC
	lint ${CFLAGS} ${DLSRCS}
	lint ${CFLAGS} ${HTSRCS}
	lint ${CFLAGS} ${INSRCS}
	lint ${CFLAGS} ${MKSRCS}
	lint ${CFLAGS} ${RFSRCS}
#	lint ${CFLAGS} ${RPSRCS}
	lint ${CFLAGS} ${WHSRCS}
E 9
E 6

D 6
whatabout: what1.o what2.o what3.o what4.o shell.o mkey3.o
	cc what?.o shell.o mkey3.o  -o whatabout
deliv: deliv1.o deliv2.o
	cc deliv?.o  -o deliv
refpart: refer0.o refer1.o refer2.o refer3.o refer4.o refer5.o
refpart: refer6.o refer7.o refer8.o deliv2.o glue4.o
	cc refer?.o deliv2.o glue4.o  -o refpart
E 6
I 6
D 7
glue3.o: refer..c
hunt2.o: refer..c
hunt3.o: refer..c
refer0.o: refer..c
refer1.o: refer..c
refer2.o: refer..c
refer3.o: refer..c
refer4.o: refer..c
refer6.o: refer..c
refer5.o: refer..c
E 7
I 7
D 9
depend: ${SOURCES}
	cc -M ${CFLAGS} *.c | sed -e 's, ./, ,g' | \
	    awk ' { if ($$1 != prev) \
		{ if (rec != "") print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		else rec = rec " " $$2 } } \
		END { print rec } ' >makedep
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
	ed - Makefile < eddep
	rm eddep makedep
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 9
I 9
tags: FRC
	ctags ${DLSRCS}
	ctags -a ${HTSRCS}
	ctags -a ${INSRCS}
	ctags -a ${MKSRCS}
	ctags -a ${RFSRCS}
#	ctags -a ${RPSRCS}
	ctags -a ${WHSRCS}
	sort -o tags tags
E 9

D 9
# DO NOT DELETE THIS LINE -- make depend uses it
E 9
I 9
FRC:
E 9

I 9
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

E 9
addbib.o: addbib.c /usr/include/stdio.h /usr/include/ctype.h
D 11
addbib.o: /usr/include/signal.h
E 11
I 11
addbib.o: /usr/include/signal.h /usr/include/machine/trap.h
E 11
D 9
annobib.o: annobib.c /usr/include/stdio.h
E 9
I 9
lookbib.o: lookbib.c /usr/include/stdio.h /usr/include/ctype.h
E 9
deliv1.o: deliv1.c /usr/include/stdio.h
D 9
deliv2.o: deliv2.c /usr/include/stdio.h
flagger.o: flagger.c /usr/include/stdio.h
glue1.o: glue1.c /usr/include/stdio.h
glue2.o: glue2.c
glue3.o: glue3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
glue3.o: /usr/include/assert.h
E 9
I 9
deliv2.o: deliv2.c /usr/include/stdio.h deliv2.c /usr/include/stdio.h
E 9
glue4.o: glue4.c /usr/include/stdio.h /usr/include/ctype.h
glue5.o: glue5.c /usr/include/stdio.h /usr/include/ctype.h
hunt1.o: hunt1.c /usr/include/stdio.h /usr/include/assert.h
hunt2.o: hunt2.c refer..c /usr/include/stdio.h /usr/include/ctype.h
hunt2.o: /usr/include/assert.h
hunt3.o: hunt3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
hunt3.o: /usr/include/assert.h
hunt5.o: hunt5.c /usr/include/stdio.h /usr/include/sys/types.h
hunt5.o: /usr/include/sys/stat.h
hunt6.o: hunt6.c /usr/include/stdio.h /usr/include/assert.h
hunt7.o: hunt7.c /usr/include/stdio.h /usr/include/assert.h
hunt8.o: hunt8.c /usr/include/stdio.h /usr/include/assert.h
hunt9.o: hunt9.c
I 9
refer3.o: refer3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer3.o: /usr/include/assert.h
shell.o: shell.c
tick.o: tick.c /usr/include/stdio.h /usr/include/sys/types.h
tick.o: /usr/include/sys/timeb.h
E 9
inv1.o: inv1.c /usr/include/stdio.h /usr/include/assert.h
inv2.o: inv2.c /usr/include/stdio.h /usr/include/assert.h
inv3.o: inv3.c
inv5.o: inv5.c /usr/include/stdio.h
inv6.o: inv6.c /usr/include/stdio.h /usr/include/assert.h
D 9
kaiser.o: kaiser.c /usr/include/stdio.h /usr/include/ctype.h
lookbib.o: lookbib.c /usr/include/stdio.h /usr/include/ctype.h
E 9
I 9
deliv2.o: deliv2.c /usr/include/stdio.h
E 9
mkey1.o: mkey1.c /usr/include/stdio.h
mkey2.o: mkey2.c /usr/include/stdio.h /usr/include/ctype.h
mkey3.o: mkey3.c /usr/include/stdio.h
D 9
refer..o: refer..c /usr/include/stdio.h /usr/include/ctype.h
refer..o: /usr/include/assert.h
E 9
I 9
deliv2.o: deliv2.c /usr/include/stdio.h deliv2.c /usr/include/stdio.h
glue1.o: glue1.c /usr/include/stdio.h
glue2.o: glue2.c
glue3.o: glue3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
glue3.o: /usr/include/assert.h
glue4.o: glue4.c /usr/include/stdio.h /usr/include/ctype.h
glue5.o: glue5.c /usr/include/stdio.h /usr/include/ctype.h
hunt2.o: hunt2.c refer..c /usr/include/stdio.h /usr/include/ctype.h
hunt2.o: /usr/include/assert.h
hunt3.o: hunt3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
hunt3.o: /usr/include/assert.h
hunt5.o: hunt5.c /usr/include/stdio.h /usr/include/sys/types.h
hunt5.o: /usr/include/sys/stat.h
hunt6.o: hunt6.c /usr/include/stdio.h /usr/include/assert.h
hunt7.o: hunt7.c /usr/include/stdio.h /usr/include/assert.h
hunt8.o: hunt8.c /usr/include/stdio.h /usr/include/assert.h
hunt9.o: hunt9.c
mkey3.o: mkey3.c /usr/include/stdio.h
E 9
refer0.o: refer0.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer0.o: /usr/include/assert.h
D 11
refer1.o: refer1.c /usr/include/signal.h refer..c /usr/include/stdio.h
refer1.o: /usr/include/ctype.h /usr/include/assert.h
E 11
I 11
refer1.o: refer1.c /usr/include/signal.h /usr/include/machine/trap.h refer..c
refer1.o: /usr/include/stdio.h /usr/include/ctype.h /usr/include/assert.h
E 11
refer2.o: refer2.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer2.o: /usr/include/assert.h
D 9
refer3.o: refer3.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer3.o: /usr/include/assert.h
E 9
refer4.o: refer4.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer4.o: /usr/include/assert.h
refer5.o: refer5.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer5.o: /usr/include/assert.h
refer6.o: refer6.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer6.o: /usr/include/assert.h
refer7.o: refer7.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer7.o: /usr/include/assert.h
refer8.o: refer8.c refer..c /usr/include/stdio.h /usr/include/ctype.h
refer8.o: /usr/include/assert.h
shell.o: shell.c
D 9
sortbib.o: sortbib.c /usr/include/stdio.h /usr/include/signal.h
thash.o: thash.c /usr/include/stdio.h
tick.o: tick.c /usr/include/stdio.h /usr/include/sys/types.h
tick.o: /usr/include/sys/timeb.h
types.o: types.c
what..o: what..c /usr/include/stdio.h /usr/include/ctype.h
what..o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/assert.h
E 9
what1.o: what1.c what..c /usr/include/stdio.h /usr/include/ctype.h
what1.o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/assert.h
what2.o: what2.c /usr/include/stdio.h /usr/include/ctype.h
what3.o: what3.c what..c /usr/include/stdio.h /usr/include/ctype.h
what3.o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/assert.h
what4.o: what4.c what..c /usr/include/stdio.h /usr/include/ctype.h
what4.o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/assert.h
D 9
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 9
I 9
shell.o: shell.c
mkey3.o: mkey3.c /usr/include/stdio.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 7
E 6
E 1

h53528
s 00005/00005/00102
d D 4.4 99/09/14 20:10:10 msokolov 5 4
c please don't litter in /usr/local!
e
s 00001/00001/00106
d D 4.3 87/06/03 17:36:03 bostic 4 3
c added depend label
e
s 00005/00005/00102
d D 4.2 82/10/24 19:35:52 mckusick 3 2
c add DESTDIR
e
s 00000/00000/00107
d D 4.1 82/05/12 11:13:31 rrh 2 1
c sync to release 4.1
e
s 00107/00000/00000
d D 1.1 82/05/12 11:03:06 rrh 1 0
c date and time created 82/05/12 11:03:06 by rrh
e
u
U
t
T
I 1
#
# 	%M%	%I%	%E%
#
MISCSRCS = Readme v6run.1
SSRCS = compat.s memsiz.s
HSRCS = defs.h rt11.h unix6sys.h unix6sysn.h unix7sys.h unix7sysn.h unixhdr.h
CSRCS = bcopy.c dofloat.c dosig.c runcompat.c unixemts.c unixstart.c unixtraps.c

SRCS = $(MISCSRCS) $(SSRCS) $(HSRCS) $(CSRCS)

v7run:	compat.o v7run.o v7start.o v7traps.o unixemts.o rdosig.o\
	dofloat.o bcopy.o
	ld -e start -N -o v7run compat.o v7run.o v7start.o v7traps.o bcopy.o \
	unixemts.o rdosig.o dofloat.o /lib/crt0.o -lc -s

v6run:	compat.o v6run.o v6start.o v6traps.o unixemts.o rdosig.o \
	bcopy.o dofloat.o
	ld -e start -N -o v6run compat.o v6run.o v6start.o v6traps.o\
	unixemts.o rdosig.o dofloat.o bcopy.o /lib/crt0.o -lc -s

v7trc:	compat.o v7run.o v7start.o v7ttraps.o unixemts.o tdosig.o dofloat.o
	ld -e start -N -o v7trc compat.o v7run.o v7start.o v7ttraps.o\
	unixemts.o tdosig.o dofloat.o /lib/crt0.o -lc

v6trc:	compat.o v6run.o v6start.o v6ttraps.o unixemts.o tdosig.o dofloat.o
	ld -e start -N -o v6trc compat.o v6run.o v6start.o v6ttraps.o\
	unixemts.o tdosig.o dofloat.o /lib/crt0.o -lc

rtrun:	compat.o rtrun.o rtstart.o rttraps.o rtemts.o rdosig.o dofloat.o
	ld -e start -N -o rtrun compat.o rtrun.o rtstart.o rttraps.o\
	rtemts.o rdosig.o dofloat.o /lib/crt0.o -lc

rttrc:	compat.o rtrun.o rtstart.o rtttraps.o rtemts.o rdosig.o dofloat.o
	ld -e start -N -o rttrc compat.o rtrun.o rtstart.o rttraps.o\
	rtemts.o rdosig.o dofloat.o /lib/crt0.o -lc

all:	v7run v6run # v7trc v6trc

compat.o: memsiz.s compat.s
	cat memsiz.s compat.s | as -o compat.o

v7run.o: defs.h unixhdr.h runcompat.c
	cc -c -O -DV7UNIX -DUNIX runcompat.c
	mv runcompat.o v7run.o

v6run.o: defs.h unixhdr.h runcompat.c
	cc -c -O -DV6UNIX -DUNIX runcompat.c
	mv runcompat.o v6run.o

rtrun.o: defs.h rt11.h runcompat.c
	cc -c -O -DRT11 runcompat.c
	mv runcompat.o rtrun.o

v7start.o: defs.h unixstart.c
	cc -c -O -DV7UNIX unixstart.c
	mv unixstart.o v7start.o

v6start.o: defs.h unixstart.c
	cc -c -O -DV6UNIX unixstart.c
	mv unixstart.o v6start.o

v7traps.o: defs.h unix7sys.h unixtraps.c
	cc -c -O -DV7UNIX unixtraps.c
	mv unixtraps.o v7traps.o

v6traps.o: defs.h unix6sys.h unixtraps.c
	cc -c -O -DV6UNIX unixtraps.c
	mv unixtraps.o v6traps.o

v7ttraps.o: defs.h unix7sys.h unixtraps.c
	cc -c -O -DV7UNIX -DTRACE unixtraps.c
	mv unixtraps.o v7ttraps.o

v6ttraps.o: defs.h unix6sys.h unixtraps.c
	cc -c -O -DV6UNIX -DTRACE unixtraps.c
	mv unixtraps.o v6ttraps.o

unixemts.o: unixemts.c
	cc -c -O unixemts.c

rdosig.o: dosig.c
	cc -c -O dosig.c
	mv dosig.o rdosig.o

tdosig.o: dosig.c
	cc -c -O -DTRACE dosig.c
	mv dosig.o tdosig.o

dofloat.o: defs.h dofloat.c
	cc -c -O dofloat.c

install: v7run # v6run v6trc v7trc
D 3
	cp v7run $(DESTDIR)/usr/games/lib/compat
	: cp v6run /usr/local
	: cp v6trc /usr/local
	: cp v7trc /usr/local
	: chmod 4755 /usr/local/v?run /usr/local/v?trc
E 3
I 3
D 5
	install v7run $(DESTDIR)/usr/games/lib/compat
	: install v6run $(DESTDIR)/usr/local
	: install v6trc $(DESTDIR)/usr/local
	: install v7trc $(DESTDIR)/usr/local
	: chmod 4755 $(DESTDIR)/usr/local/v?run $(DESTDIR)/usr/local/v?trc
E 5
I 5
	install -o bin -g bin -m 755 v7run $(DESTDIR)/usr/games/lib/compat
#	: install v6run $(DESTDIR)/usr/local
#	: install v6trc $(DESTDIR)/usr/local
#	: install v7trc $(DESTDIR)/usr/local
#	: chmod 4755 $(DESTDIR)/usr/local/v?run $(DESTDIR)/usr/local/v?trc
E 5
E 3

clean:
	rm -f *.o v6run v7run v7trc v6trc

D 4

E 4
sources: $(SRCS)

$(SRCS):
	sccs get $@

I 4
depend:
E 4
E 1

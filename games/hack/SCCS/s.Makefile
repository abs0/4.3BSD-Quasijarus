h29409
s 00001/00181/00108
d D 5.7 99/09/27 19:18:16 msokolov 11 10
c man pages move to /usr/src/man
e
s 00001/00001/00288
d D 5.6 87/12/26 13:31:06 bostic 10 9
c use cc; fix for ANSI C 
e
s 00001/00001/00288
d D 5.5 87/12/17 20:49:41 bostic 9 7
c add makedefs and hack to clean label
e
s 00001/00001/00288
d R 5.5 87/12/17 20:46:25 bostic 8 7
c remove hack on clean
e
s 00001/00001/00288
d D 5.4 87/09/22 10:45:38 bostic 7 6
c fix mkdir
e
s 00007/00007/00282
d D 5.3 87/09/21 11:46:55 bostic 6 3
c integrate with dm
e
s 00009/00007/00282
d R 5.3 87/09/20 10:22:15 bostic 5 3
c integrate with dm
e
s 00009/00007/00282
d R 5.3 87/09/19 17:09:11 bostic 4 3
c integrate with dm
e
s 00199/00106/00090
d D 5.2 87/06/03 19:28:28 bostic 3 1
c BSD template
e
s 00199/00106/00090
d R 5.2 87/06/03 19:19:07 bostic 2 1
c new template
e
s 00196/00000/00000
d D 5.1 87/06/03 18:50:18 bostic 1 0
c date and time created 87/06/03 18:50:18 by bostic
e
u
U
t
T
I 1
# Hack or Quest Makefile.

# on some systems the termcap library is in -ltermcap
TERMLIB = -ltermlib


# make hack
GAME = hack
GAMEDIR = /usr/games/lib/hackdir
D 3
CFLAGS = -g
E 3
I 3
CFLAGS = -O
E 3
HACKCSRC = hack.Decl.c\
	hack.apply.c hack.bones.c hack.c hack.cmd.c hack.do.c\
	hack.do_name.c hack.do_wear.c hack.dog.c hack.eat.c hack.end.c\
	hack.engrave.c hack.fight.c hack.invent.c hack.ioctl.c\
	hack.lev.c hack.main.c hack.makemon.c hack.mhitu.c\
	hack.mklev.c hack.mkmaze.c hack.mkobj.c hack.mkshop.c\
	hack.mon.c hack.monst.c hack.o_init.c hack.objnam.c\
	hack.options.c hack.pager.c hack.potion.c hack.pri.c\
	hack.read.c hack.rip.c hack.rumors.c hack.save.c\
	hack.search.c hack.shk.c hack.shknam.c hack.steal.c\
	hack.termcap.c hack.timeout.c hack.topl.c\
	hack.track.c hack.trap.c hack.tty.c hack.unix.c\
	hack.u_init.c hack.vault.c\
	hack.wield.c hack.wizard.c hack.worm.c hack.worn.c hack.zap.c\
	hack.version.c rnd.c alloc.c

CSOURCES = $(HACKCSRC) makedefs.c

HSOURCES = hack.h hack.mfndpos.h config.h\
	def.edog.h def.eshk.h def.flag.h def.func_tab.h def.gold.h\
	def.mkroom.h\
	def.monst.h def.obj.h def.objclass.h def.objects.h\
	def.permonst.h def.rm.h def.trap.h def.wseg.h

SOURCES = $(CSOURCES) $(HSOURCES)

D 11
AUX = data help hh rumors hack.6 hack.sh
E 11
I 11
AUX = data help hh rumors hack.sh
E 11

DISTR = $(SOURCES) $(AUX) READ_ME Makefile date.h hack.onames.h

HOBJ = hack.Decl.o hack.apply.o hack.bones.o hack.o hack.cmd.o hack.do.o\
	hack.do_name.o hack.do_wear.o hack.dog.o hack.eat.o hack.end.o\
	hack.engrave.o hack.fight.o hack.invent.o hack.ioctl.o\
	hack.lev.o hack.main.o hack.makemon.o hack.mhitu.o hack.mklev.o\
	hack.mkmaze.o hack.mkobj.o hack.mkshop.o hack.mon.o\
	hack.monst.o hack.o_init.o hack.objnam.o hack.options.o\
	hack.pager.o hack.potion.o hack.pri.o\
	hack.read.o hack.rip.o hack.rumors.o hack.save.o\
	hack.search.o hack.shk.o hack.shknam.o hack.steal.o\
	hack.termcap.o hack.timeout.o hack.topl.o\
	hack.track.o hack.trap.o\
	hack.tty.o hack.unix.o hack.u_init.o hack.vault.o hack.wield.o\
	hack.wizard.o hack.worm.o hack.worn.o hack.zap.o\
	hack.version.o rnd.o alloc.o

D 3
$(GAME):	$(HOBJ) Makefile
E 3
I 3
all: hack
hack: ${HOBJ} ${LIBC}
E 3
	@echo "Loading ..."
D 3
	@ld -X -o $(GAME) /lib/crt0.o $(HOBJ) $(TERMLIB) -lc
E 3
I 3
D 10
	@ld -X -o $@ /lib/crt0.o $(HOBJ) $(TERMLIB) -lc
E 10
I 10
	@cc -X -o $@ $(HOBJ) $(TERMLIB)
E 10
E 3

D 3
all:	$(GAME) lint
	@echo "Done."

E 3
makedefs:	makedefs.c
D 3
	cc -o makedefs makedefs.c
E 3
I 3
	${CC} ${CFLAGS} -o $@ makedefs.c
E 3

D 3

E 3
hack.onames.h:	makedefs def.objects.h
	makedefs > hack.onames.h

lint:
# lint cannot have -p here because (i) capitals are meaningful:
# [Ww]izard, (ii) identifiers may coincide in the first six places:
# doweararm() versus dowearring().
# _flsbuf comes from <stdio.h>, a bug in the system libraries.
	@echo lint -axbh -DLINT ...
	@lint -axbh -DLINT $(HACKCSRC) | sed '/_flsbuf/d'


diff:
	@- for i in $(SOURCES) $(AUX) ; do \
		cmp -s $$i $D/$$i || \
		( echo diff $D/$$i $$i ; diff $D/$$i $$i ; echo ) ; done

distribution: Makefile
	@- for i in READ_ME $(SOURCES) $(AUX) Makefile date.h hack.onames.h\
		; do \
		cmp -s $$i $D/$$i || \
		( echo cp $$i $D ; cp $$i $D ) ; done
# the distribution directory also contains the empty files perm and record.

D 3

E 3
install:
D 3
	rm -f $(GAMEDIR)/$(GAME)
	cp $(GAME) $(GAMEDIR)/$(GAME)
	chmod 04511 $(GAMEDIR)/$(GAME)
	rm -f $(GAMEDIR)/bones*
#	cp hack.6 /usr/man/man6
E 3
I 3
D 6
	install -s -o bin -g bin -m 4511 hack ${DESTDIR}/usr/games/hack
	-mkdir ${DESTDIR}/usr/games/lib/hackdir
E 6
I 6
	install -s -o games -g bin -m 4700 hack ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f hack; ln -s dm hack; chown games.bin hack)
D 7
	-mkdir ${DESTDIR}/usr/games/lib/hackdir > /dev/null 2>&1
E 7
I 7
	-[ -d ${DESTDIR}/usr/games/lib/hackdir ] || mkdir ${DESTDIR}/usr/games/lib/hackdir
E 7
E 6
	chmod 700 ${DESTDIR}/usr/games/lib/hackdir
D 6
	chown bin ${DESTDIR}/usr/games/lib/hackdir
	chgrp bin ${DESTDIR}/usr/games/lib/hackdir
	install -c -o bin -g bin -m 666 /dev/null ${DESTDIR}/usr/games/lib/hackdir/perm
	install -c -o bin -g bin -m 666 /dev/null ${DESTDIR}/usr/games/lib/hackdir/record
	install -c -o bin -g bin -m 666 hh ${DESTDIR}/usr/games/lib/hackdir/hh
E 6
I 6
	chown games.bin ${DESTDIR}/usr/games/lib/hackdir
	install -c -o games -g bin -m 666 /dev/null ${DESTDIR}/usr/games/lib/hackdir/perm
	install -c -o games -g bin -m 666 /dev/null ${DESTDIR}/usr/games/lib/hackdir/record
	install -c -o games -g bin -m 666 hh ${DESTDIR}/usr/games/lib/hackdir/hh
E 6
	rm -f ${DESTDIR}/usr/games/lib/hackdir/bones*
E 3

clean:
D 9
	rm -f *.o
E 9
I 9
	rm -f *.o hack makedefs
E 9

D 3

E 3
depend:
D 3
# For the moment we are lazy and disregard /usr/include files because
# the sources contain them conditionally. Perhaps we should use cpp.
#		( /bin/grep '^#[ 	]*include' $$i | sed -n \
#			-e 's,<\(.*\)>,"/usr/include/\1",' \
#
	for i in ${CSOURCES}; do \
		( /bin/grep '^#[ 	]*include[ 	]*"' $$i | sed -n \
			-e 's/[^"]*"\([^"]*\)".*/\1/' \
			-e H -e '$$g' -e '$$s/\n/ /g' \
			-e '$$s/.*/'$$i': &/' -e '$$s/\.c:/.o:/p' \
			>> makedep); done
	for i in ${HSOURCES}; do \
		( /bin/grep '^#[ 	]*include[ 	]*"' $$i | sed -n \
			-e 's/[^"]*"\([^"]*\)".*/\1/' \
			-e H -e '$$g' -e '$$s/\n/ /g' \
			-e '$$s/.*/'$$i': &\
				touch '$$i/p \
			>> makedep); done
	@echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	@echo '$$r makedep' >>eddep
	@echo 'w' >>eddep
	@cp Makefile Makefile.bak
	ed - Makefile < eddep
	@rm -f eddep makedep
	@echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	@echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	@echo '# see make depend above' >> Makefile
	- diff Makefile Makefile.bak
	@rm -f Makefile.bak
E 3
I 3
	mkdep ${CFLAGS} ${CSOURCES}
E 3

D 3
# DO NOT DELETE THIS LINE
E 3
I 3
tags:
	ctags ${CSOURCES}
E 3

D 3
hack.Decl.o:  hack.h def.mkroom.h
hack.apply.o:  hack.h def.edog.h def.mkroom.h
hack.bones.o:  hack.h
hack.o:  hack.h
hack.cmd.o:  hack.h def.func_tab.h
hack.do.o:  hack.h
hack.do_name.o:  hack.h
hack.do_wear.o:  hack.h
hack.dog.o:  hack.h hack.mfndpos.h def.edog.h def.mkroom.h
hack.eat.o:  hack.h
hack.end.o:  hack.h
hack.engrave.o:  hack.h
hack.fight.o:  hack.h
hack.invent.o:  hack.h def.wseg.h
hack.ioctl.o:  config.h
hack.lev.o:  hack.h def.mkroom.h def.wseg.h
hack.main.o:  hack.h
hack.makemon.o:  hack.h
hack.mhitu.o:  hack.h
hack.mklev.o:  hack.h def.mkroom.h
hack.mkmaze.o:  hack.h def.mkroom.h
hack.mkobj.o:  hack.h
hack.mkshop.o:  hack.h def.mkroom.h def.eshk.h
hack.mon.o:  hack.h hack.mfndpos.h
hack.monst.o:  hack.h def.eshk.h
hack.o_init.o:  config.h def.objects.h hack.onames.h
hack.objnam.o:  hack.h
hack.options.o:  config.h hack.h
hack.pager.o:  hack.h
hack.potion.o:  hack.h
hack.pri.o:  hack.h def.wseg.h
hack.read.o:  hack.h
hack.rip.o:  hack.h
hack.rumors.o:  hack.h
hack.save.o:  hack.h
hack.search.o:  hack.h
hack.shk.o:  hack.h hack.mfndpos.h def.mkroom.h def.eshk.h
hack.shknam.o:  hack.h
hack.steal.o:  hack.h
hack.termcap.o:  config.h def.flag.h
hack.timeout.o:  hack.h
hack.topl.o:  hack.h
hack.track.o:  hack.h
hack.trap.o:  hack.h def.mkroom.h
hack.tty.o:  hack.h
hack.unix.o:  hack.h def.mkroom.h
hack.u_init.o:  hack.h
hack.vault.o:  hack.h def.mkroom.h
hack.wield.o:  hack.h
hack.wizard.o:  hack.h
hack.worm.o:  hack.h def.wseg.h
hack.worn.o:  hack.h
hack.zap.o:  hack.h
hack.version.o:  date.h
hack.h:  config.h def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h def.permonst.h hack.onames.h
			touch hack.h
def.objects.h:  config.h def.objclass.h
			touch def.objects.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 3
I 3
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 11

hack.Decl.o: hack.Decl.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.Decl.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.Decl.o: def.permonst.h hack.onames.h def.mkroom.h
hack.apply.o: hack.apply.c hack.h config.h /usr/include/strings.h
hack.apply.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.apply.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.edog.h
hack.apply.o: def.mkroom.h
hack.bones.o: hack.bones.c hack.h config.h /usr/include/strings.h
hack.bones.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.bones.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.o: hack.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.o: def.permonst.h hack.onames.h /usr/include/stdio.h
hack.cmd.o: hack.cmd.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.cmd.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.cmd.o: def.permonst.h hack.onames.h def.func_tab.h
hack.do.o: hack.do.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.do.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.do.o: def.permonst.h hack.onames.h
hack.do_name.o: hack.do_name.c hack.h config.h /usr/include/strings.h
hack.do_name.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.do_name.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.do_name.o: /usr/include/stdio.h
hack.do_wear.o: hack.do_wear.c hack.h config.h /usr/include/strings.h
hack.do_wear.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.do_wear.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.do_wear.o: /usr/include/stdio.h
hack.dog.o: hack.dog.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.dog.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.dog.o: def.permonst.h hack.onames.h hack.mfndpos.h def.edog.h def.mkroom.h
hack.eat.o: hack.eat.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.eat.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.eat.o: def.permonst.h hack.onames.h
hack.end.o: hack.end.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.end.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.end.o: def.permonst.h hack.onames.h /usr/include/stdio.h
hack.end.o: /usr/include/signal.h
hack.engrave.o: hack.engrave.c hack.h config.h /usr/include/strings.h
hack.engrave.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.engrave.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.fight.o: hack.fight.c hack.h config.h /usr/include/strings.h
hack.fight.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.fight.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.invent.o: hack.invent.c hack.h config.h /usr/include/strings.h
hack.invent.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.invent.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.invent.o: /usr/include/stdio.h def.wseg.h
hack.ioctl.o: hack.ioctl.c /usr/include/stdio.h config.h /usr/include/sgtty.h
hack.ioctl.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
hack.ioctl.o: /usr/include/sys/ttydev.h /usr/include/signal.h
hack.lev.o: hack.lev.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.lev.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.lev.o: def.permonst.h hack.onames.h def.mkroom.h /usr/include/stdio.h
hack.lev.o: def.wseg.h
hack.main.o: hack.main.c /usr/include/stdio.h /usr/include/signal.h hack.h
hack.main.o: config.h /usr/include/strings.h def.objclass.h def.monst.h
hack.main.o: def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h def.permonst.h
hack.main.o: hack.onames.h
hack.makemon.o: hack.makemon.c hack.h config.h /usr/include/strings.h
hack.makemon.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.makemon.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.mhitu.o: hack.mhitu.c hack.h config.h /usr/include/strings.h
hack.mhitu.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.mhitu.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.mklev.o: hack.mklev.c hack.h config.h /usr/include/strings.h
hack.mklev.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.mklev.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.mkroom.h
hack.mkmaze.o: hack.mkmaze.c hack.h config.h /usr/include/strings.h
hack.mkmaze.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.mkmaze.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.mkroom.h
hack.mkobj.o: hack.mkobj.c hack.h config.h /usr/include/strings.h
hack.mkobj.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.mkobj.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.mkshop.o: hack.mkshop.c hack.h config.h /usr/include/strings.h
hack.mkshop.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.mkshop.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.mkroom.h
hack.mkshop.o: def.eshk.h
hack.mon.o: hack.mon.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.mon.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.mon.o: def.permonst.h hack.onames.h hack.mfndpos.h
hack.monst.o: hack.monst.c hack.h config.h /usr/include/strings.h
hack.monst.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.monst.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.eshk.h
hack.o_init.o: hack.o_init.c config.h def.objects.h config.h def.objclass.h
hack.o_init.o: hack.onames.h
hack.objnam.o: hack.objnam.c hack.h config.h /usr/include/strings.h
hack.objnam.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.objnam.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.options.o: hack.options.c config.h hack.h config.h /usr/include/strings.h
hack.options.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.options.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.pager.o: hack.pager.c /usr/include/stdio.h /usr/include/signal.h hack.h
hack.pager.o: config.h /usr/include/strings.h def.objclass.h def.monst.h
hack.pager.o: def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.pager.o: def.permonst.h hack.onames.h /usr/include/sys/wait.h
hack.pager.o: /usr/include/machine/machparam.h
hack.potion.o: hack.potion.c hack.h config.h /usr/include/strings.h
hack.potion.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.potion.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.pri.o: hack.pri.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.pri.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.pri.o: def.permonst.h hack.onames.h /usr/include/stdio.h def.wseg.h
hack.read.o: hack.read.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.read.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.read.o: def.permonst.h hack.onames.h
hack.rip.o: hack.rip.c /usr/include/stdio.h hack.h config.h
hack.rip.o: /usr/include/strings.h def.objclass.h def.monst.h def.gold.h
hack.rip.o: def.trap.h def.obj.h def.flag.h def.rm.h def.permonst.h
hack.rip.o: hack.onames.h
hack.rumors.o: hack.rumors.c /usr/include/stdio.h hack.h config.h
hack.rumors.o: /usr/include/strings.h def.objclass.h def.monst.h def.gold.h
hack.rumors.o: def.trap.h def.obj.h def.flag.h def.rm.h def.permonst.h
hack.rumors.o: hack.onames.h
hack.save.o: hack.save.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.save.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.save.o: def.permonst.h hack.onames.h /usr/include/signal.h
hack.search.o: hack.search.c hack.h config.h /usr/include/strings.h
hack.search.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.search.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.shk.o: hack.shk.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.shk.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.shk.o: def.permonst.h hack.onames.h hack.mfndpos.h def.mkroom.h def.eshk.h
hack.shknam.o: hack.shknam.c hack.h config.h /usr/include/strings.h
hack.shknam.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.shknam.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.steal.o: hack.steal.c hack.h config.h /usr/include/strings.h
hack.steal.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.steal.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.termcap.o: hack.termcap.c /usr/include/stdio.h config.h def.flag.h
hack.timeout.o: hack.timeout.c hack.h config.h /usr/include/strings.h
hack.timeout.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.timeout.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.topl.o: hack.topl.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.topl.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.topl.o: def.permonst.h hack.onames.h /usr/include/stdio.h
hack.track.o: hack.track.c hack.h config.h /usr/include/strings.h
hack.track.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.track.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.trap.o: hack.trap.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.trap.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.trap.o: def.permonst.h hack.onames.h def.mkroom.h
hack.tty.o: hack.tty.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.tty.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.tty.o: def.permonst.h hack.onames.h /usr/include/stdio.h
hack.tty.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
hack.tty.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
hack.unix.o: hack.unix.c /usr/include/stdio.h /usr/include/errno.h hack.h
hack.unix.o: config.h /usr/include/strings.h def.objclass.h def.monst.h
hack.unix.o: def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h def.permonst.h
hack.unix.o: hack.onames.h /usr/include/sys/types.h /usr/include/sys/stat.h
hack.unix.o: /usr/include/sys/time.h /usr/include/time.h
hack.u_init.o: hack.u_init.c hack.h config.h /usr/include/strings.h
hack.u_init.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.u_init.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.u_init.o: /usr/include/stdio.h /usr/include/signal.h
hack.vault.o: hack.vault.c hack.h config.h /usr/include/strings.h
hack.vault.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.vault.o: def.flag.h def.rm.h def.permonst.h hack.onames.h def.mkroom.h
hack.wield.o: hack.wield.c hack.h config.h /usr/include/strings.h
hack.wield.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.wield.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.wizard.o: hack.wizard.c hack.h config.h /usr/include/strings.h
hack.wizard.o: def.objclass.h def.monst.h def.gold.h def.trap.h def.obj.h
hack.wizard.o: def.flag.h def.rm.h def.permonst.h hack.onames.h
hack.worm.o: hack.worm.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.worm.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.worm.o: def.permonst.h hack.onames.h def.wseg.h
hack.worn.o: hack.worn.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.worn.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.worn.o: def.permonst.h hack.onames.h
hack.zap.o: hack.zap.c hack.h config.h /usr/include/strings.h def.objclass.h
hack.zap.o: def.monst.h def.gold.h def.trap.h def.obj.h def.flag.h def.rm.h
hack.zap.o: def.permonst.h hack.onames.h
hack.version.o: hack.version.c date.h
rnd.o: rnd.c
alloc.o: alloc.c
makedefs.o: makedefs.c

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 11
E 3
E 1

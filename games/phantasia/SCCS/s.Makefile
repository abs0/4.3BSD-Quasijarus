h59192
s 00001/00000/00131
d D 5.7 99/10/02 21:49:22 msokolov 9 8
c oops, need rm -f before ln
e
s 00004/00067/00127
d D 5.6 99/09/28 14:53:10 msokolov 8 7
c man pages move to /usr/src/man
e
s 00043/00030/00151
d D 5.5 88/06/01 19:22:34 bostic 7 6
c remove setup on clean; make manual page here; remove certain options
e
s 00001/00001/00180
d D 5.4 87/09/22 10:46:12 bostic 6 5
c fix mkdir
e
s 00005/00005/00176
d D 5.3 87/09/21 12:09:35 bostic 5 2
c integrate with dm
e
s 00005/00005/00176
d R 5.3 87/09/21 11:54:11 bostic 4 2
c integrate with dm
e
s 00007/00005/00176
d R 5.3 87/09/20 10:30:50 bostic 3 2
c integrate with dm
e
s 00076/00028/00105
d D 5.2 87/06/04 14:47:34 bostic 2 1
c new template
e
s 00133/00000/00000
d D 5.1 87/06/03 19:37:39 bostic 1 0
c date and time created 87/06/03 19:37:39 by bostic
e
u
U
t
T
I 1
# Makefile for Phantasia 3.3.2
#
# To create game:
#
# 1)  Set up a directory where the game and its support files will live.
#        (It is suggested that the source be kept somewhere else.)
#
# 2)  Set up the variables in Makefile CAREFULLY to reflect your
#        particular situation.
#
# 3)  Check out ok_to_play() at the end of main.c if you want to include
#        code to restrict access at certain times.
#
# 4)  'make install' and sit back and watch.
#
# NOTE:  'setup' MUST be executed before trying to run 'phantasia'.
#	 The install procedure does this for you.
#
#
# To convert from 3.3.1 or 3.3.1+ to 3.3.2:
#
# 1)	'make convert'  (3.3.1+: 'make PLUS=-DPHANTPLUS convert')
#
# 2)	Move 'newcharacs' to 'characs'.
#

RM =		-rm
SHAR =		/d2/estes/bin/shar
# Tell 'make' to use /bin/sh for all commands.
SHELL =		/bin/sh

# PLOTDEVICE is used for plotting the map.
# Change as appropriate.
PLOTDEVICE =	> /dev/tty

# Add '-ljobs' to LDFLAGS if 4.1bsd; add -ltermlib if not SVR2.
# Need separate i/d space on small machines.
# May need '-f' on machines without floating point hardware.
D 2
LDFLAGS =	-lm -lcurses -ltermlib
E 2
I 2
LIBS= -lm -lcurses -ltermlib
E 2

# DEST is where the program and its support files reside
DEST =		/usr/games/lib/phantasia
DESTR =		/usr/games

I 7
D 8
MDIR=	/usr/man/cat6

.SUFFIXES: .6 .0


E 8
E 7
# The following are program constants which are implementation dependent.
#
# DEST is passed on.  Note that there is no closing quote here.
# WIZARD is the login of the one who will clean up things.
# UID is the uid of game wizard.
# define OK_TO_PLAY to restrict playing access at certain times.
#	Also see function ok_to_play() in main.c, and tailor to your own needs.
# define ENEMY to include code for checking of a 'hit list' of resricted 
#	accounts.  The list of logins goes in the file 'enemy'.
# SHELL is the default shell for shell escapes.  If SHELL is not defined,
#	shell escapes are not enabled.
# define BSD41 for 4.1bsd
# define BSD42 for 4.2bsd
# define SYS3 for System III, or similar (like Version 7)
# define SYS5 for System V
# If you don't have 'strchr()', put '-Dstrchr=index' below.
# May need '-I/usr/include/sys' for 4.2bsd.
CFLAGS = 	-O \
		-DDEST=\"${DEST} \
		-DDESTR=\"${DESTR} \
D 7
		-DWIZARD=\"games\" \
		-DUID=57 \
E 7
I 7
		-DWIZARD=\"root\" \
		-DUID=0 \
E 7
		-DENEMY \
D 7
		-DSHELL=\"/bin/csh\" \
E 7
		-DBSD42

D 2
CFILES =	main.c fight.c io.c interplayer.c gamesupport.c misc.c phantglobs.c
OFILES =	main.o fight.o io.o interplayer.o gamesupport.o misc.o phantglobs.o
E 2
I 2
SRCS=	main.c fight.c io.c interplayer.c gamesupport.c misc.c phantglobs.c
OBJS=	main.o fight.o io.o interplayer.o gamesupport.o misc.o phantglobs.o
E 2
HFILES =	phantdefs.h phantstruct.h macros.h include.h
I 2
LIBC=	/lib/libc.a
E 2

D 7
all:		phantasia setup phant.help
E 7
I 7
D 8
all:		phantasia setup phantasia.0
E 8
I 8
all:		phantasia setup
E 8
E 7

# Make the game.
D 2
phantasia:	${OFILES}
		${CC} ${OFILES} ${LDFLAGS} -o phantasia
E 2
I 2
phantasia:	${OBJS} ${LIBC}
		${CC} ${OBJS} -o $@ ${LIBS}
E 2

D 2
${OFILES}:	${HFILES}
E 2
I 2
${OBJS}:	${HFILES}
E 2

# Make the initialization program.
D 2
setup:		phantglobs.o setup.o monsters.asc
		${CC} phantglobs.o setup.o ${LDFLAGS} -o setup
E 2
I 2
setup:		phantglobs.o setup.o monsters.asc ${LIBC}
		${CC} phantglobs.o setup.o -o $@ ${LIBS}
E 2

D 2
setup.o:	${HFILES}
E 2
I 2
setup.o: ${HFILES}
E 2

D 8
# Make documentation.
# The flags below on tbl and nroff are to make a line printable version.
D 7
phant.help:	phant.nr
		tbl -TX phant.nr | nroff -Ttn300 -man > phant.help
E 7
I 7
.6.0:
	tbl -TX phantasia.6 | /usr/man/manroff > phantasia.0
E 7

# Install game and documentation.  Initialize.
E 8
I 8
# Install game.  Initialize.
E 8
D 2
install:	all
		cp phantasia phant.help ${DEST}
		chmod 755 ${DEST}
		chmod 4711 ${DEST}/phantasia
		chmod 644 ${DEST}/phant.help
		setup
E 2
I 2
install: FRC
D 6
	-mkdir /usr/games/lib/phantasia
E 6
I 6
	-[ -d ${DESTDIR}/usr/games/lib/phantasia ] || mkdir ${DESTDIR}/usr/games/lib/phantasia
E 6
	chmod 700 /usr/games/lib/phantasia
D 5
	chown bin /usr/games/lib/phantasia
	install -s -o bin -g bin -m 4711 phantasia ${DESTDIR}/usr/games/phantasia
	install -c -o bin -g bin -m 444 phant.help ${DESTDIR}/usr/games/lib/phantasia/phant.help
E 5
I 5
	chown games.bin /usr/games/lib/phantasia
	install -s -o games -g bin -m 4700 phantasia ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f phantasia; ln -s dm phantasia; chown games.bin phantasia)
I 9
	rm -f ${DESTDIR}/usr/games/lib/phantasia/phant.help
E 9
D 7
	install -c -o games -g bin -m 400 phant.help ${DESTDIR}/usr/games/lib/phantasia/phant.help
E 7
I 7
D 8
	install -c -o games -g bin -m 400 phantasia.0 ${DESTDIR}/usr/games/lib/phantasia/phant.help
	install -c -o bin -g bin -m 444 phantasia.0 ${DESTDIR}${MDIR}
E 8
I 8
	ln -s /usr/man/cat6/phantasia.0 ${DESTDIR}/usr/games/lib/phantasia/phant.help
E 8
E 7
E 5
	./setup
D 5
	chgrp bin /usr/games/lib/phantasia/*
	chown bin /usr/games/lib/phantasia/*
E 5
I 5
	chown games.bin /usr/games/lib/phantasia/*
E 5
E 2

# Make Phantasia map.
# Change the map commands reflect your installation.
# Pre-System III installations may use 'plot' instead of 'tplot'.
map:		map.c
		cc -O map.c -lplot -o map
		map | tplot -t4014 ${PLOTDEVICE}

# Convert old character file to new format.
# 'convert' is meant to be run only once.
# PLUS = PHANTPLUS for conversion from 3.3.1+.
convert:	convert.c oldplayer.h phantstruct.h
		${CC} ${CFLAGS} ${PLUS} convert.c ${LDFLAGS} -o convert
		convert
		@echo "New data is in newcharacs."

# Clean up directory after installation.
clean:
D 2
		${RM} -f *.o phantasia phant.help phant.pt?
E 2
I 2
D 7
		${RM} -f *.o core phantasia phant.help phant.pt?
E 7
I 7
D 8
		${RM} -f *.o core phantasia phant.help phantasia.0 setup
E 8
I 8
		${RM} -f *.o core phantasia phant.help setup
E 8
E 7
E 2

D 2
# Make 'shell archives'.
# All source files barely fit into 5 archives, and must be
# carefully grouped to do so.
shar:		${CFILES} ${HFILES} phant.nr Makefile map.c convert.c oldplayer.h
		${SHAR} README Makefile main.c include.h phantstruct.h \
		    map.c monsters.asc > phant.pt1
		${SHAR} phantglobs.h phantglobs.c fight.c \
		    convert.c > phant.pt2
		${SHAR} interplayer.c gamesupport.c io.c > phant.pt3
		${SHAR} macros.h phantdefs.h setup.c misc.c \
		    oldplayer.h > phant.pt4
		${SHAR} phant.nr interplayer.c > phant.pt5
E 2
I 2
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 2

I 2
lint: FRC
	lint ${CFLAGS} ${SRCS}

tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 8

main.o: main.c include.h /usr/include/ctype.h /usr/include/curses.h
main.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 7
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
main.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
main.o: /usr/include/signal.h /usr/include/time.h macros.h phantdefs.h
main.o: phantstruct.h phantglobs.h
E 7
I 7
main.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
main.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
main.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
main.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h phantglobs.h
E 7
fight.o: fight.c include.h /usr/include/ctype.h /usr/include/curses.h
fight.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 7
fight.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
fight.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
fight.o: /usr/include/signal.h /usr/include/time.h macros.h phantdefs.h
E 7
I 7
fight.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
fight.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
fight.o: /usr/include/setjmp.h /usr/include/signal.h
fight.o: /usr/include/machine/trap.h /usr/include/time.h macros.h phantdefs.h
E 7
fight.o: phantstruct.h phantglobs.h
io.o: io.c include.h /usr/include/ctype.h /usr/include/curses.h
io.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 7
io.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h /usr/include/math.h
io.o: /usr/include/pwd.h /usr/include/setjmp.h /usr/include/signal.h
E 7
I 7
io.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
io.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
io.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
E 7
io.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h phantglobs.h
interplayer.o: interplayer.c include.h /usr/include/ctype.h
interplayer.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
interplayer.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 7
interplayer.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
interplayer.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/time.h
interplayer.o: macros.h phantdefs.h phantstruct.h phantglobs.h
E 7
I 7
interplayer.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
interplayer.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
interplayer.o: /usr/include/signal.h /usr/include/machine/trap.h
interplayer.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h
interplayer.o: phantglobs.h
E 7
gamesupport.o: gamesupport.c include.h /usr/include/ctype.h
gamesupport.o: /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
gamesupport.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 7
gamesupport.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
gamesupport.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/time.h
gamesupport.o: macros.h phantdefs.h phantstruct.h phantglobs.h
E 7
I 7
gamesupport.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
gamesupport.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
gamesupport.o: /usr/include/signal.h /usr/include/machine/trap.h
gamesupport.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h
gamesupport.o: phantglobs.h
E 7
misc.o: misc.c include.h /usr/include/ctype.h /usr/include/curses.h
misc.o: /usr/include/stdio.h /usr/include/sgtty.h /usr/include/sys/ioctl.h
D 7
misc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
misc.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
misc.o: /usr/include/signal.h /usr/include/time.h macros.h phantdefs.h
misc.o: phantstruct.h phantglobs.h
E 7
I 7
misc.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydefaults.h
misc.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
misc.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/machine/trap.h
misc.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h phantglobs.h
E 7
phantglobs.o: phantglobs.c include.h /usr/include/ctype.h /usr/include/curses.h
phantglobs.o: /usr/include/stdio.h /usr/include/sgtty.h
phantglobs.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
D 7
phantglobs.o: /usr/include/sys/ttydev.h /usr/include/math.h /usr/include/pwd.h
phantglobs.o: /usr/include/setjmp.h /usr/include/signal.h /usr/include/time.h
phantglobs.o: macros.h phantdefs.h phantstruct.h phantglobs.h
E 7
I 7
phantglobs.o: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
phantglobs.o: /usr/include/math.h /usr/include/pwd.h /usr/include/setjmp.h
phantglobs.o: /usr/include/signal.h /usr/include/machine/trap.h
phantglobs.o: /usr/include/time.h macros.h phantdefs.h phantstruct.h
phantglobs.o: phantglobs.h
E 7

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 2
E 1

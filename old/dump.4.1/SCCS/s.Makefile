h05597
s 00006/00001/00041
d D 5.1 85/06/05 08:44:29 dist 5 4
c Add copyright
e
s 00002/00001/00040
d D 1.4 83/04/28 15:11:17 mckusick 4 3
c install as dump.4.1
e
s 00003/00003/00038
d D 1.3 83/04/28 15:04:52 mckusick 3 2
c convert to work on 4.1c
e
s 00001/00003/00040
d D 1.2 80/10/18 17:56:02 bill 2 1
c install in /etc
e
s 00043/00000/00000
d D 1.1 80/10/13 17:30:22 root 1 0
c date and time created 80/10/13 17:30:22 by root
e
u
U
t
T
I 1
D 5
# sccsid = "%W% (Berkeley) %G%"
E 5
I 5
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 5
#
#	dump.h			header file
#	dumpitime.c		reads /etc/ddate
#	dumpmain.c		driver
#	dumpoptr.c		operator interface
#	dumptape.c		handles the mag tape and opening/closing
#	dumptraverse.c		traverses the file system
#	unctime.c		undo ctime
I 4
#	l3tol.c			3-byte to 4-byte unpacking
E 4
#
#	DEBUG			use local directory to find ddate and dumpdates
#	TDEBUG			trace out the process forking
#
PSRCS = \
	dump.h dumpmain.c dumptraverse.c dumptape.c dumpoptr.c dumpitime.c

SRCS =  \
	dump.h dumpitime.c \
	dumpmain.c dumpoptr.c dumptape.c \
D 3
	dumptraverse.c unctime.c
E 3
I 3
	dumptraverse.c unctime.c l3tol.c
E 3

OBJS = \
	dumpitime.o \
	dumpmain.o dumpoptr.o \
D 3
	dumptape.o dumptraverse.o unctime.o
E 3
I 3
	dumptape.o dumptraverse.o unctime.o l3tol.o
E 3

D 3
DFLAGS = -DERNIE
E 3
I 3
DFLAGS =
E 3
CFLAGS = -O $(DFLAGS)

dump:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o dump
install:
D 2
	install -s dump $(DESTDIR)/bin
/etc/dump:
	cp dump.csh $(DESTDIR)/etc/dump
E 2
I 2
D 4
	install -s dump $(DESTDIR)/etc
E 4
I 4
	install -s dump $(DESTDIR)/etc/dump.4.1
E 4
E 2
clean:
	rm -f *.o dump

lint:
	lint $(DFLAGS) $(SRCS)

psrcs:
	echo $(PSRCS)
E 1

h28128
s 00010/00005/00025
d D 5.3 88/07/09 11:23:59 bostic 3 2
c install approved copyright notice
e
s 00003/00002/00027
d D 5.2 88/05/09 14:43:33 bostic 2 1
c add dirblk 
e
s 00029/00000/00000
d D 5.1 88/03/30 16:01:18 bostic 1 0
c date and time created 88/03/30 16:01:18 by bostic
e
u
U
t
T
I 1
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 3
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
#
#	%W% (Berkeley) %G%
#
D 2
LIST=	dmcstats findproc.nxt frame ifuba ifubinfo ifxmt mba_device mba_hd \
	pcb proc setproc.nxt stacktrace trapframe tty ubahd
E 2
I 2
LIST=	dirblk dmcstats findproc.nxt frame ifuba ifubinfo ifxmt \
	mba_device mba_hd pcb proc setproc.nxt stacktrace trapframe \
	tty ubahd
E 2

all:

install: FRC
	install -c -o bin -g bin -m 444 ${LIST} ${DESTDIR}/usr/lib/adb

clean:
depend:
lint:
tags:
FRC:

# DO NOT DELETE THIS LINE -- make depend uses it

E 1

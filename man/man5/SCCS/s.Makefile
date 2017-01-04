h33455
s 00008/00029/00026
d D 5.5 04/10/20 17:39:09 msokolov 5 4
c back to 4.3BSD /usr/man format
e
s 00002/00002/00053
d D 5.4 99/09/27 18:55:04 msokolov 4 3
c add cpio(5)
e
s 00006/00004/00049
d D 5.3 99/06/01 16:57:22 msokolov 3 2
c add sccsfile(5)
e
s 00010/00005/00043
d D 5.2 88/07/09 11:37:51 bostic 2 1
c install approved copyright notice
e
s 00048/00000/00000
d D 5.1 87/12/12 18:21:42 bostic 1 0
c date and time created 87/12/12 18:21:42 by bostic
e
u
U
f b 
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 2
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 2
I 2
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
E 2
#
#	%W% (Berkeley) %G%
#
D 5
MDIR=	/usr/man/cat5
SRCS=	L-devices.5 L-dialcodes.5 L.aliases.5 L.cmds.5 L.sys.5 USERFILE.5 \
D 4
	a.out.5 acct.5 aliases.5 ar.5 core.5 dbx.5 dir.5 disklabel.5 \
E 4
I 4
	a.out.5 acct.5 aliases.5 ar.5 core.5 cpio.5 dbx.5 dir.5 disklabel.5 \
E 4
	disktab.5 dm.config.5 dump.5 fs.5 fstab.5 gettytab.5 group.5 hosts.5 \
	map3270.5 \
	mtab.5 networks.5 passwd.5 phones.5 plot.5 printcap.5 protocols.5 \
D 3
	remote.5 resolver.5 services.5 shells.5 stab.5 tar.5 termcap.5 \
	tp.5 ttys.5 types.5 tzfile.5 utmp.5 uuencode.5 vfont.5 vgrindefs.5
E 3
I 3
	remote.5 resolver.5 sccsfile.5 services.5 shells.5 stab.5 tar.5 \
	termcap.5 tp.5 ttys.5 types.5 tzfile.5 utmp.5 uuencode.5 vfont.5 \
	vgrindefs.5
E 3
OBJS=	L-devices.0 L-dialcodes.0 L.aliases.0 L.cmds.0 L.sys.0 USERFILE.0 \
D 4
	a.out.0 acct.0 aliases.0 ar.0 core.0 dbx.0 dir.0 disklabel.0 \
E 4
I 4
	a.out.0 acct.0 aliases.0 ar.0 core.0 cpio.0 dbx.0 dir.0 disklabel.0 \
E 4
	disktab.0 dm.config.0 dump.0 fs.0 fstab.0 gettytab.0 group.0 hosts.0 \
	map3270.0 \
	mtab.0 networks.0 passwd.0 phones.0 plot.0 printcap.0 protocols.0 \
D 3
	remote.0 resolver.0 services.0 shells.0 stab.0 tar.0 termcap.0 \
	tp.0 ttys.0 types.0 tzfile.0 utmp.0 uuencode.0 vfont.0 vgrindefs.0
E 3
I 3
	remote.0 resolver.0 sccsfile.0 services.0 shells.0 stab.0 tar.0 \
	termcap.0 tp.0 ttys.0 types.0 tzfile.0 utmp.0 uuencode.0 vfont.0 \
	vgrindefs.0
E 3
LINKS=	inode.0 dumpdates.0 wtmp.0
E 5
I 5
MDIR=	/usr/man/man5
E 5

D 5
.SUFFIXES: .5 .0
E 5
I 5
all:
E 5

D 5
.5.0:
	${DESTDIR}/usr/man/manroff $*.5 > $*.0
E 5
I 5
psman: FRC
	for i in *.5; do echo $$i; pstroff -man $$i > $$i.ps; done
E 5

D 5
all: ${OBJS}

E 5
clean: FRC
D 5
	rm -f ${OBJS}
E 5
I 5
	rm -f *.ps
E 5

install: FRC
D 5
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/fs.0 ${DESTDIR}${MDIR}/inode.0
	ln ${DESTDIR}${MDIR}/dump.0 ${DESTDIR}${MDIR}/dumpdates.0
	ln ${DESTDIR}${MDIR}/utmp.0 ${DESTDIR}${MDIR}/wtmp.0
E 5
I 5
	cd ${DESTDIR}${MDIR}; rm -f *
	install -c -o bin -g bin -m 444 *.5 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.5 ${DESTDIR}${MDIR}
E 5

FRC:
E 1

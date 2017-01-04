h27458
s 00007/00021/00026
d D 5.4 04/10/20 17:28:23 msokolov 4 3
c back to 4.3BSD /usr/man format
e
s 00002/00002/00045
d D 5.3 99/05/31 23:31:54 msokolov 3 2
c add dmv(4)
e
s 00010/00005/00037
d D 5.2 88/07/09 11:38:54 bostic 2 1
c install approved copyright notice
e
s 00042/00000/00000
d D 5.1 87/12/12 18:18:52 bostic 1 0
c date and time created 87/12/12 18:18:52 by bostic
e
u
U
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
D 4
MDIR=	/usr/man/cat4/vax
SRCS=	acc.4 ad.4 autoconf.4 cons.4 crl.4 css.4 ct.4 ddn.4 de.4 dh.4 dhu.4 \
D 3
	dmc.4 dmf.4 dmz.4 dn.4 dz.4 ec.4 en.4 ex.4 fl.4 hdh.4 hk.4 hp.4 \
E 3
I 3
	dmc.4 dmf.4 dmv.4 dmz.4 dn.4 dz.4 ec.4 en.4 ex.4 fl.4 hdh.4 hk.4 hp.4 \
E 3
	ht.4 hy.4 ik.4 il.4 intro.4 ix.4 kg.4 lp.4 mem.4 mt.4 mtio.4 np.4 \
	pcl.4 ps.4 qe.4 rx.4 tb.4 tm.4 tmscp.4 ts.4 tu.4 uda.4 up.4 ut.4 \
	uu.4 va.4 vp.4 vv.4
OBJS=	acc.0 ad.0 autoconf.0 cons.0 crl.0 css.0 ct.0 ddn.0 de.0 dh.0 dhu.0 \
D 3
	dmc.0 dmf.0 dmz.0 dn.0 dz.0 ec.0 en.0 ex.0 fl.0 hdh.0 hk.0 hp.0 \
E 3
I 3
	dmc.0 dmf.0 dmv.0 dmz.0 dn.0 dz.0 ec.0 en.0 ex.0 fl.0 hdh.0 hk.0 hp.0 \
E 3
	ht.0 hy.0 ik.0 il.0 intro.0 ix.0 kg.0 lp.0 mem.0 mt.0 mtio.0 np.0 \
	pcl.0 ps.0 qe.0 rx.0 tb.0 tm.0 tmscp.0 ts.0 tu.0 uda.0 up.0 ut.0 \
	uu.0 va.0 vp.0 vv.0
LINKS=	kmem.0
E 4
I 4
MDIR=	/usr/man/man4
E 4

D 4
.SUFFIXES: .4 .0
E 4
I 4
all:
E 4

D 4
.4.0:
	${DESTDIR}/usr/man/manroff $*.4 > $*.0
E 4
I 4
psman: FRC
	for i in *.4; do echo $$i; pstroff -man $$i > $$i.ps; done
E 4

D 4
all: ${OBJS}

E 4
clean: FRC
D 4
	rm -f ${OBJS}
E 4
I 4
	rm -f *.ps
E 4

install: FRC
D 4
	cd ${DESTDIR}${MDIR}; rm -f *.0
	install -c -o bin -g bin -m 444 ${OBJS} ${DESTDIR}${MDIR}
	ln ${DESTDIR}${MDIR}/mem.0 ${DESTDIR}${MDIR}/kmem.0
E 4
I 4
	install -c -o bin -g bin -m 444 *.4 ${DESTDIR}${MDIR}
	install -c -o bin -g bin -m 444 links/*.4 ${DESTDIR}${MDIR}
E 4

FRC:
E 1

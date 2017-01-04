h09862
s 00002/00008/00021
d D 4.6 99/09/29 17:31:33 msokolov 6 5
c don't count builds
e
s 00000/00000/00029
d D 4.5 99/09/29 17:28:44 msokolov 5 4
c bump it up to 4.5
e
s 00000/00000/00029
d D 4.4 99/09/29 17:28:43 msokolov 4 3
c bump it up to 4.5
e
s 00000/00000/00029
d D 4.3 99/09/29 17:28:42 msokolov 3 2
c bump it up to 4.5
e
s 00000/00000/00029
d D 4.2 99/09/29 17:28:41 msokolov 2 1
c bump it up to 4.5
e
s 00029/00000/00000
d D 4.1 99/09/29 17:28:00 msokolov 1 0
c This SCCS file has apparently been lost, reconstructing from version 4.5
e
u
U
t
T
I 1
#!/bin/sh -
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
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
#
#	%W% (Berkeley) %G%
#
D 6
if [ ! -r version ]
then
	echo 0 > version
fi
touch version
E 6
rm -f version.[oc]
D 6
v=`cat version` u=${USER-root} d=`pwd` h=`hostname` t=`date`
sed -e "s|%VERSION%|#${v}: ${t}|" -e "s|%WHOANDWHERE%|${u}@${h}:${d}|" \
E 6
I 6
u=${USER-root} d=`pwd` h=`hostname` t=`date`
sed -e "s|%VERSION%|${t}|" -e "s|%WHOANDWHERE%|${u}@${h}:${d}|" \
E 6
	< Version.c >version.c
D 6
/bin/echo `expr ${v} + 1` > version
E 6
E 1

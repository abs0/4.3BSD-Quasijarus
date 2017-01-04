h34210
s 00008/00000/00002
d D 5.2 85/06/06 11:07:13 dist 2 1
c Add copyright
e
s 00002/00000/00000
d D 5.1 85/06/06 11:06:25 dist 1 0
c date and time created 85/06/06 11:06:25 by dist
e
u
U
t
T
I 2
#!/bin/sh -
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 2
I 1
cp /dev/null /fastboot
/etc/reboot $*
E 1

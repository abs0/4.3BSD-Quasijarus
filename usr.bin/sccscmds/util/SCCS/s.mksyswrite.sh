h52542
s 00002/00002/00003
d D 1.3 88/05/21 16:33:35 bostic 3 2
c handle restructure of C library, get machine type cleanly
e
s 00002/00002/00003
d D 1.2 87/02/15 23:11:06 lepreau 2 1
c make it more robust
e
s 00005/00000/00000
d D 1.1 87/02/15 22:32:26 lepreau 1 0
c date and time created 87/02/15 22:32:26 by lepreau
e
u
U
t
T
I 1
#! /bin/sh
D 2
# %W%	%E%
E 2
I 2
# %M%	%I%	%E%
E 2

D 2
mach=`ls -l /usr/include/machine | sed 's/.*-> \.\///'`
E 2
I 2
D 3
mach=`ls -l /usr/include/machine | sed -e 's/.*-> \.\///' -e 's/.*-> //'`
E 2
/lib/cpp /usr/src/lib/libc/$mach/sys/write.c |sed 's/_write/_syswrite/g' >syswrite.s
E 3
I 3
mach=`machine`
/lib/cpp /usr/src/lib/libc/$mach/sys/write.s |sed 's/_write/_syswrite/g' >syswrite.s
E 3
E 1

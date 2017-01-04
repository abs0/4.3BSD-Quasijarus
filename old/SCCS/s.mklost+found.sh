h38422
s 00006/00002/00017
d D 5.1 85/05/28 15:03:55 dist 3 2
c Add copyright
e
s 00002/00004/00017
d D 1.2 85/01/10 19:58:24 mckusick 2 1
c use big file names to do things efficiently!
e
s 00021/00000/00000
d D 1.1 85/01/10 19:47:58 mckusick 1 0
c date and time created 85/01/10 19:47:58 by mckusick
e
u
U
t
T
I 1
D 3
#! /bin/sh
E 3
I 3
#!/bin/sh -
E 3
#
D 3
#	%W%	(Berkeley)	%E%
E 3
I 3
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 3
#
mkdir lost+found
cd lost+found
echo creating slots...
for i in 1 2 3 4 5 6 7 8 9 0 a b c d e f
do
D 2
	tee ${i}1 ${i}2 ${i}3 ${i}4 ${i}5 ${i}6 ${i}7 ${i}8 < /dev/null
	tee ${i}9 ${i}a ${i}b ${i}c ${i}d ${i}e ${i}f ${i}0 < /dev/null
E 2
I 2
	cat </dev/null >${i}XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
E 2
done
echo removing dummy files...
for i in 1 2 3 4 5 6 7 8 9 0 a b c d e f
do
D 2
	rm ${i}1 ${i}2 ${i}3 ${i}4 ${i}5 ${i}6 ${i}7 ${i}8
	rm ${i}9 ${i}a ${i}b ${i}c ${i}d ${i}e ${i}f ${i}0
E 2
I 2
	rm ${i}X*
E 2
done
cd ..
echo done
ls -ld `pwd`/lost+found
E 1

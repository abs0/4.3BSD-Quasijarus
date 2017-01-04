h13612
s 00008/00000/00000
d D 4.1 83/02/11 14:56:46 shannon 1 0
c date and time created 83/02/11 14:56:46 by shannon
e
u
U
t
T
I 1
#!/bin/sh
#
#	%M%	%I%	%E%
#
for file in $*
do
	/usr/ucb/uncompact < $file
done
E 1

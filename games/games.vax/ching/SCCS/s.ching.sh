h49715
s 00005/00002/00011
d D 4.2 83/05/19 12:03:39 peter 2 1
c pipe reading through more.
c confusion since cno and more can't both be reading from stdin
c in the same pipeline.
c thus the hacker placates the seekers.
e
s 00013/00000/00000
d D 4.1 82/10/27 17:43:20 peter 1 0
c date and time created 82/10/27 17:43:20 by peter
e
u
U
t
T
I 1
#! /bin/sh
#
#	%W%	(Berkeley)	%E%
#
cd /usr/games/lib/ching.d
PATH=:$PATH
case $1 in
	[6-9]*)	H=$1;shift;;
esac
if	test $H
D 2
then	phx $H | nroff $* macros -
else	cno | phx | nroff $* macros -
E 2
I 2
then	phx $H | nroff $* macros - | more -s
else	cno > "/tmp/#$$" 
	echo "  "
	phx < "/tmp/#$$" | nroff $* macros - | more -s
	rm "/tmp/#$$"
E 2
fi
E 1

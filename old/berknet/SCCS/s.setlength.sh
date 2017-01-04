h24282
s 00015/00000/00000
d D 4.1 82/09/12 17:45:35 mckusick 1 0
c date and time created 82/09/12 17:45:35 by mckusick
e
u
U
t
T
I 1
#! /bin/sh
#
#	%W%	(Berkeley)	%G%
#
# set the length of the logfiles
set a=$1
set tmp=setl$$
shift
unset noclobber
foreach i ($argv)
	tail -$a $i >/tmp/$tmp
	cp /tmp/$tmp $i
	chmod 666 $i
end
rm -f /tmp/$tmp
E 1

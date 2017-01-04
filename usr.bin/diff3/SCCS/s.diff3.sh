h27580
s 00021/00000/00000
d D 4.1 83/02/10 21:00:50 shannon 1 0
c date and time created 83/02/10 21:00:50 by shannon
e
u
U
t
T
I 1
#! /bin/sh
#
#	%M%	%I%	%E%
#
e=
case $1 in
-*)
	e=$1
	shift;;
esac
if test $# = 3 -a -f $1 -a -f $2 -a -f $3
then
	:
else
	echo usage: diff3 file1 file2 file3 1>&2
	exit
fi
trap "rm -f /tmp/d3[ab]$$" 0 1 2 13 15
diff $1 $3 >/tmp/d3a$$
diff $2 $3 >/tmp/d3b$$
/usr/lib/diff3 $e /tmp/d3[ab]$$ $1 $2 $3
E 1

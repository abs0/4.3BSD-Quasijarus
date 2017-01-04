h22144
s 00005/00010/00007
d D 4.5 83/05/27 17:05:29 ralph 5 4
c simpified version which doesn't use temporary files.
e
s 00000/00000/00017
d D 4.4 82/11/06 17:13:35 rrh 4 3
c Change so default macro package is -me; added -me, -ma and -k flags
c for deroff
e
s 00000/00000/00017
d D 4.3 82/11/06 17:08:12 rrh 3 2
c Change path to deroff so deroff is taken from /usr/bin
e
s 00000/00000/00017
d D 4.2 82/11/06 14:35:13 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00017/00000/00000
d D 4.1 82/11/06 13:48:41 rrh 1 0
c Oldest available version at Berkeley
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
D 5
trap 'rm $$; exit' 1 2 3 15
E 5
D=/usr/lib/explain.d
D 5
while echo "phrase?";read x
E 5
I 5
while	echo 'phrase?'
	read x
E 5
do
D 5
cat >$$ <<dn
/$x.*	/s/\(.*\)	\(.*\)/use "\2" for "\1"/p
dn
case $x in
[a-z]*)
sed -n -f $$ $D; rm $$;;
*) rm $$;;
esac
E 5
I 5
	case $x in
	[a-z]*)	sed -n /"$x"'.*	/s/\(.*\)	\(.*\)/use "\2" for "\1"/p' $D
	esac
E 5
done
E 1

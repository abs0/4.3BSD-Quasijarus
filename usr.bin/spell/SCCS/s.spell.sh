h00927
s 00004/00003/00037
d D 1.3 83/09/10 14:35:24 jak 3 2
c fixed -v and -x options
e
s 00026/00018/00014
d D 1.2 83/04/20 21:52:04 mckusick 2 1
c auxilliary files now as options, usage message added, et al --jak
e
s 00032/00000/00000
d D 1.1 83/04/20 15:52:19 mckusick 1 0
c date and time created 83/04/20 15:52:19 by mckusick
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
D 2
: B flags, D dictionary, F files, H history, S stop, V data for -v
H=${H-/usr/dict/spellhist}
T=/tmp/spell.$$
V=/dev/null
F= B=
trap "rm -f $T*; exit" 0 1 2 13 15
E 2
I 2
: V data for -v, B flags, D dictionary, S stop, H history, F files, T temp
V=/dev/null		B=			F= 
S=/usr/dict/hstop	H=/dev/null		T=/tmp/spell.$$
next="F=$F@"
trap "rm -f $T ${T}a ; exit" 0
E 2
for A in $*
do
	case $A in
D 3
	-v)	B="$B -v"
E 3
I 3
	-v)	B="$B@-v"
E 3
		V=${T}a ;;
I 3
	-x)	B="$B@-x" ;;
E 3
D 2
	-a)	;;
E 2
	-b) 	D=${D-/usr/dict/hlistb}
D 3
		B="$B -b" ;;
E 3
I 3
		B="$B@-b" ;;
E 3
D 2
	*)	F="$F $A"
E 2
I 2
	-d)	next="D=" ;;
	-s)	next="S=" ;;
	-h)	next="H=" ;;
	-*)	echo "Bad flag for spell: $A"
		echo "Usage:  spell [ -v ] [ -b ] [ -d hlist ] [ -s hstop ] [ -h spellhist ]"
		exit ;;
	*)	eval $next"$A"
		next="F=$F@" ;;
E 2
	esac
D 2
	done
deroff -w $F |\
  sort -u |\
  /usr/lib/spell ${S-/usr/dict/hstop} $T |\
  /usr/lib/spell ${D-/usr/dict/hlista} $V $B |\
  sort -u +0f +0 - $T |\
  tee -a $H
who am i >>$H 2>/dev/null
E 2
I 2
done
IFS=@
case $H in
/dev/null)	deroff -w $F | sort -u | /usr/lib/spell $S $T |
		/usr/lib/spell ${D-/usr/dict/hlista} $V $B |
		sort -u +0f +0 - $T ;;
*)		deroff -w $F | sort -u | /usr/lib/spell $S $T |
		/usr/lib/spell ${D-/usr/dict/hlista} $V $B |
		sort -u +0f +0 - $T | tee -a $H
		who am i >> $H 2> /dev/null ;;
esac
E 2
case $V in
D 2
/dev/null)	exit
E 2
I 2
/dev/null)	exit ;;
E 2
esac
D 2
sed '/^\./d' $V | sort -u +1f +0
E 2
I 2
D 3
sed '/^\./d' $V | sort -u +1f +0 ;;
E 3
I 3
sed '/^\./d' $V | sort -u +1f +0
E 3
E 2
E 1

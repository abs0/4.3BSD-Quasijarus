h27453
s 00001/00000/00028
d D 4.5 86/08/29 15:29:47 sklower 5 4
c add entry for grn output "driver"
e
s 00001/00000/00027
d D 4.4 85/09/21 15:19:20 sam 4 3
c add imagen
e
s 00001/00000/00026
d D 4.3 85/01/04 14:03:06 jak 3 2
c add 4013 option
e
s 00016/00007/00010
d D 4.2 83/11/11 15:02:39 ralph 2 1
c added new devices.
e
s 00017/00000/00000
d D 4.1 83/07/04 11:08:41 sam 1 0
c date and time created 83/07/04 11:08:41 by sam
e
u
U
t
T
I 1
D 2
#! /bin/sh
E 2
I 2
#!/bin/sh
E 2
#	%W%	(Berkeley)	%G%
#
D 2
PATH=/bin:/usr/bin
E 2
I 2
PATH=/bin:/usr/bin:/usr/ucb
E 2
case $1 in
-T*)	t=$1
	shift ;;
*)	t=-T$TERM
esac
case $t in
D 2
-T450)	exec t450 $*;;
-T300)	exec t300 $*;;
-T300S|-T300s)	exec t300s $*;;
-Tver)	exec vplot $*;;
E 2
I 2
-T450)			exec t450 $*;;
-T300)			exec t300 $*;;
-T300S|-T300s)		exec t300s $*;;
-Tver)			exec lpr -Pversatec -g $*;;
-Tvar)			exec lpr -Pvarian -g $*;;
E 2
-Ttek|-T4014|-T)	exec tek $* ;;
I 3
-T4013)			exec t4013 $* ;;
E 3
D 2
*)  echo plot: terminal type $t not known 1>&2; exit 1
E 2
I 2
-Tbitgraph|-Tbg)	exec bgplot $*;;
-Tgigi|-Tvt125)		exec gigiplot $*;;
-Taed)			exec aedplot $*;;
-Thp7221|-Thp7|-Th7)	exec hp7221plot $*;;
-Thp|-T2648|-T2648a|-Thp2648|-Thp2648a|h8)
			exec hpplot $*;;
I 4
-Tip|-Timagen)		exec implot $*;;
I 5
-Tgrn)			exec grnplot $*;;
E 5
E 4
-Tcrt)			exec crtplot $*;;
-Tdumb|un|unknown)	exec dumbplot $*;;
*)  			exec crtplot $*;;
E 2
esac
E 1

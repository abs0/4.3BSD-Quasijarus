h54927
s 00006/00009/00107
d R 4.5 85/10/28 15:24:27 mckusick 11 10
c rvsort and vsort are now handled by lpr
e
s 00030/00004/00086
d D 4.4 84/05/04 10:23:43 ralph 10 9
c added -h flag
e
s 00002/00000/00088
d D 4.3 83/10/12 10:00:35 ralph 9 8
c "vtroff -man -" now works like "vtroff -man"
e
s 00007/00005/00081
d D 4.2 83/05/26 15:13:26 ralph 8 7
c adds file name to banner and removes soelim to speed it up.
e
s 00005/00016/00081
d D 4.1 83/03/08 09:46:18 ralph 7 6
c new remote lpr replaces vpr, etc. This is for backwards compatibility.
e
s 00000/00001/00097
d D 1.6 82/11/23 16:55:15 peter 6 5
c took out debugging `set echo'.
e
s 00024/00031/00074
d D 1.5 82/11/23 16:52:53 peter 5 4
c do remote troffing over on dali.  maybe this should use dsh?
e
s 00012/00004/00093
d D 1.4 82/08/09 00:37:45 mckusick 4 3
c update to optimize for local host
e
s 00001/00000/00096
d D 1.3 81/07/12 00:49:18 sklower 3 2
c make this file directly executable (#!) and make it immune to funny
c aliases in user's .cshrc (-f option to csh)
e
s 00005/00005/00091
d D 1.2 81/01/08 20:30:15 root 2 1
c pass -rv1 for -me (this used to exist! what happened?)
e
s 00096/00000/00000
d D 1.1 80/11/30 15:56:49 root 1 0
c date and time created 80/11/30 15:56:49 by root
e
u
U
t
T
I 3
#! /bin/csh -f
I 5
D 6
set echo
E 6
E 5
E 3
I 1
D 2
#
E 2
I 2
D 4
#	%W%	%G%
E 4
I 4
#
#	%W%	(Berkeley)	%G%
#
D 5
set remote = ucbernie
set execdir = /usr/ucb
if ($remote != `hostname`) then
	set cmd = "/usr/ucb/rsh $remote"
E 5
I 5
D 7
#	$troffmachine is where the troffing will be done.
set troffmachine = ucbdali
#
#	if the troff machine is not the local machine and it is up,
#	use it otherwise troff (and sort) locally.
if ($troffmachine != `hostname` && \
    `ruptime | grep -c "$troffmachine.*up"` == 1) then
	set troffsh = ( /usr/ucb/rsh $troffmachine )
E 5
else
D 5
	set cmd = ""
E 5
I 5
	set troffsh = ( /bin/sh -c )
E 5
endif
E 7
E 4
E 2
umask 0
D 5
set flags=() noglob length=() fonts=() fontf=() macp=(/usr/lib/tmac/tmac.vcat)
E 5
I 5
set flags=() noglob length=() fonts=() fontf=()
E 5
unset t
I 5
set macp = (/usr/lib/tmac/tmac.vcat)
set sort = (/usr/lib/rvsort)
D 7
set vpr = (/usr/ucb/vpr)
E 7
I 7
set lpr = (/usr/ucb/lpr -Pvarian)
I 10
set troff = (/usr/bin/troff)
E 10
E 7
E 5
top:
	if ($#argv > 0) then
		switch ($argv[1])
D 5

E 5
		case -t:
			set t
			shift argv
			goto top
D 5

E 5
		case -l*:
			set length = $argv[1]
			shift argv
			goto top
D 5

E 5
		case -V:
D 5
			unset wide
E 5
I 5
			set sort = (/usr/lib/rvsort)
D 7
			set vpr = (/usr/ucb/vpr)
E 7
I 7
			set lpr = (/usr/ucb/lpr -Pvarian)
E 7
E 5
			shift argv
			goto top
D 5

E 5
		case -W:
D 5
			set wide
E 5
I 5
			set sort = (/usr/lib/vsort -W)
D 7
			set vpr = (/usr/ucb/vpr -W)
E 7
I 7
			set lpr = (/usr/ucb/lpr -Pversatec)
E 7
E 5
			shift argv
			goto top
I 10
		case -h:
			if ($#argv < 2) then
				echo -h takes following host name.
				exit(1)
			endif
			set host = $argv[2]
			shift argv
			shift argv
			goto top
E 10
D 5

E 5
		case -F:
			if ($#argv < 2) then
				echo -F takes following font name.
				exit(1)
			endif
			set argv=(-1 $2.r -2 $2.i -3 $2.b $argv[3-])
			goto top
D 5

E 5
		case -1:
		case -2:
		case -3:
			if ($#argv < 2) then
				echo $1 takes following font name.
				exit(1)
			endif
			if (! -r /usr/lib/fontinfo/$2) then
				if (! -r /usr/lib/fontinfo/$2.r) then
					echo ${2}: font not found.
					exit(1)
				endif
				set argv[2] = $2.r
			endif
			if ($#fonts == 0) then
				set fontf=/usr/tmp/fnt$$
				cp /dev/null $fontf
			endif
			@ fnum = 0 - $1
			echo .nr p $fnum >> $fontf
			cat /usr/lib/fontinfo/$2 >> $fontf
			set fonts=($fonts $1 $2)
			shift argv
			shift argv
			goto top
D 5

E 5
		case -x:
			set macp=()
			shift argv
			goto top
D 5

E 5
		case -*:
			set flags = ($flags $argv[1])
			shift argv
			goto top
I 9
		case -:
			breaksw
E 9
D 5

E 5
		endsw
	endif
I 10

E 10
if ($#argv == 0) then
	set argv=(-)
I 8
	set banner=vtroff
else
	set banner=$argv[1]
E 8
endif
D 5
if ($?wide) then
    if ($?t) then
D 2
	/usr/bin/troff -t $flags $macp $fontf $* | /usr/lib/vsort -W $length
E 2
I 2
	/usr/bin/troff -t -rv1 $flags $macp $fontf $* | /usr/lib/vsort -W $length
E 2
    else
D 2
	/usr/bin/troff -t $flags $macp $fontf $* | \
E 2
I 2
	/usr/bin/troff -t -rv1 $flags $macp $fontf $* | \
E 2
D 4
	    /usr/lib/vsort -W $length | /usr/ucb/vpr -W -t $fonts
E 4
I 4
	    /usr/lib/vsort -W $length | $cmd $execdir/vpr -W -t $fonts
E 4
    endif
E 5
I 5
D 10
if ($?t) then
D 8
    /usr/ucb/soelim $macp $fontf $argv[*] \
D 7
    | $troffsh "/usr/bin/troff -t -rv1 $flags | $sort $length"
E 7
I 7
    | /usr/bin/troff -t -rv1 $flags | $sort $length
E 8
I 8
    /usr/bin/troff -t -rv1 $flags $macp $fontf $* | $sort $length
E 10
I 10

set tflags=(-t -rv1 $flags $macp $fontf)

if ($?host) then
    if ($#fontf) then
	echo vtroff -h does not support changing fonts -- run vtroff locally
	exit(1)
    endif
    if ($?t) then
	soelim $* | rsh $host \"$troff $tflags - | $sort $length\"
    else
	soelim $* | rsh $host \"$troff $tflags - | $sort $length | $lpr -J$banner -t $fonts\"
    endif
E 10
E 8
E 7
E 5
else
D 5
    if ($?t) then
D 2
	/usr/bin/troff -t $flags $macp $fontf $* | /usr/lib/rvsort $length
E 2
I 2
	/usr/bin/troff -t -rv1 $flags $macp $fontf $* | /usr/lib/rvsort $length
E 2
    else
D 2
	/usr/bin/troff -t $flags $macp $fontf $* | \
E 2
I 2
	/usr/bin/troff -t -rv1 $flags $macp $fontf $* | \
E 2
D 4
	    /usr/lib/rvsort $length | /usr/ucb/vpr -t $fonts
#	    /usr/lib/vsort -c $length | /usr/ucb/vpr -t $fonts
E 4
I 4
	    /usr/lib/rvsort $length | $cmd $execdir/vpr -t $fonts
E 4
    endif
E 5
I 5
D 8
    /usr/ucb/soelim $macp $fontf $argv[*] \
D 7
    | $troffsh "/usr/bin/troff -t -rv1 $flags | $sort $length | $vpr -t $fonts"
E 7
I 7
    | /usr/bin/troff -t -rv1 $flags | $sort $length | $lpr -Jvtroff -t $fonts
E 8
I 8
D 10
    /usr/bin/troff -t -rv1 $flags $macp $fontf $* | $sort $length |\
	$lpr -J$banner -t $fonts
E 10
I 10
    if ($?t) then
	$troff $tflags $* | $sort $length
    else
	$troff $tflags $* | $sort $length | $lpr -J$banner -t $fonts
    endif
E 10
E 8
E 7
E 5
endif
I 10

E 10
if ($#fontf) then
D 5
	rm $fontf
E 5
I 5
D 8
	/bin/rm $fontf
E 8
I 8
    /bin/rm $fontf
E 8
E 5
endif
E 1

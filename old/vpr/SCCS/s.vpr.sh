h21509
s 00009/00042/00015
d D 4.1 83/03/08 09:46:08 ralph 6 5
c new remote lpr replaces vpr, etc. This is for backwards compatibility.
e
s 00001/00000/00056
d D 1.5 82/11/29 14:30:19 aigrain 5 4
c add missing #!/bin/csh
e
s 00001/00001/00055
d D 1.4 82/11/23 16:49:05 peter 4 3
c the varian and versatec moved from ucbvax to ucbernie.
e
s 00001/00001/00055
d D 1.3 82/10/19 15:04:24 sam 3 2
c varian moved to ucbvax from ernie
e
s 00018/00004/00038
d D 1.2 82/09/29 17:04:42 rrh 2 1
c vpr.sh now knows about setting the fonts. the mechanism for
c calling the "real" driver on the (possibly) remote machine also changed
e
s 00042/00000/00000
d D 1.1 82/08/09 00:38:15 mckusick 1 0
c date and time created 82/08/09 00:38:15 by mckusick
e
u
U
t
T
I 5
#! /bin/csh -f
E 5
I 1
#
#	%W%	(Berkeley)	%G%
#
D 6
# vpr.sh - Use on machines without raster plotters
#
D 3
set remote = ucbernie
E 3
I 3
D 4
set remote = ucbvax
E 4
I 4
set remote = ucbernie
E 4
E 3
set execdir = /usr/ucb
if ($remote != `hostname`) then
D 2
	set cmd = "/usr/ucb/rsh $remote"
E 2
I 2
	set cmd = "/usr/ucb/rsh $remote $execdir"
E 2
else
D 2
	set cmd = ""
E 2
I 2
	set cmd = "/usr/lib"
E 2
endif
set flags=() files=()
E 6
I 6
set flags = ()
set printer = -Pvarian
E 6
top:
	if ($#argv > 0) then
		switch ($argv[1])
D 6

		case -m:
			echo "Sorry, the '$argv[1]' flag is not supported."
E 6
I 6
		case -V:
			set printer = -Pvarian
E 6
			shift argv
			goto top
D 6

I 2
		case -1:
		case -2:
		case -3:
		case -4:
			if ($#argv > 1) then
				set flags = ($flags $argv[1] $argv[2])
				shift argv
				shift argv
				goto top
			else
				echo $argv[1] takes following font name.
				exit(1)
			endif

E 6
I 6
		case -W:
			set printer = -Pversatec
			shift argv
			goto top
E 6
E 2
		case -*:
			set flags = ($flags $argv[1])
			shift argv
			goto top
D 6
		
		default:
			set files = ($files $argv[1])
			shift argv
			goto top

E 6
		endsw
	endif
D 6

if ($#files) then
	foreach i ($files)
D 2
		$cmd $execdir/vpr $flags < $i
E 2
I 2
		$cmd/vpr $flags < $i
E 2
	end
else
D 2
	$cmd $execdir/vpr $flags
E 2
I 2
	$cmd/vpr $flags
E 2
endif
E 6
I 6
/usr/ucb/lpr $printer $flags $*
E 6
E 1

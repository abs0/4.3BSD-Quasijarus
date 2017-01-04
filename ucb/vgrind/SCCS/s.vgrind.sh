h30596
s 00001/00001/00117
d D 5.3 85/11/13 03:56:17 lepreau 11 10
c csh gets -f flag
e
s 00001/00001/00117
d D 5.2 85/07/22 18:50:33 bloom 10 9
c why was the shell changed?
e
s 00006/00002/00112
d D 5.1 85/06/06 09:28:10 dist 9 8
c Add copyright
e
s 00006/00001/00108
d D 1.8 82/10/21 22:31:39 mckusick 8 7
c allow slashes in file names
e
s 00091/00036/00018
d D 1.7 81/03/29 01:23:18 presott 7 6
c The macro dfinition names have been changed to not interfere
c with other macro packages for troff.
e
s 00001/00001/00053
d D 1.6 81/03/15 17:09:33 presott 6 5
c Because I fucked the last one up
e
s 00014/00007/00040
d D 1.5 81/03/15 17:06:21 presott 5 4
c fixed the -f stuff
e
s 00004/00002/00043
d D 1.4 81/03/15 16:24:13 presott 4 3
c do the -f stuff correctly
e
s 00009/00003/00036
d D 1.3 81/03/15 16:08:43 presott 3 2
c know about the -f stuff
e
s 00000/00000/00039
d D 1.2 81/01/20 00:54:27 root 2 1
c a new table driven vgrind -- presotto
e
s 00039/00000/00000
d D 1.1 80/11/30 15:56:46 root 1 0
c date and time created 80/11/30 15:56:46 by root
e
u
U
t
T
I 8
D 9
#! /bin/csh
E 9
I 9
D 10
#!/bin/sh -
E 10
I 10
D 11
#! /bin/csh
E 11
I 11
#! /bin/csh -f
E 11
E 10
E 9
E 8
I 1
#
I 8
D 9
#	%W%	(Berkeley)	%G%
E 9
I 9
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 9
#
E 8
# vgrind
#
D 5
set b=/usr/lib
E 5
I 5
D 6
set b=.
E 6
I 6
set b=/usr/lib
E 6
E 5
D 7
set o=
set t=
E 7
I 7
set voptions=
set options=
set files=
E 7
I 5
set f=''
E 5
D 7
set wide = ""
E 7
I 7
set head=""
E 7
top:
D 7
if ($#argv > 1) then
	switch ($1:q)
E 7
I 7
if ($#argv > 0) then
    switch ($1:q)
E 7

I 5
D 7
	case -f:
		set f='filter'
		shift
		goto top
E 7
I 7
    case -f:
	set f='filter'
	set options = "$options $1:q"
	shift
	goto top
E 7

E 5
D 7
	case -t:
		set t=-t
		shift
		goto top
E 7
I 7
    case -t:
	set voptions = "$voptions -t"
	shift
	goto top
E 7

D 7
	case -o*:
		set o=$1:q
		shift
		goto top
E 7
I 7
    case -o*:
	set voptions="$voptions $1:q"
	shift
	goto top
E 7
I 5

E 5
D 7
	case -W:
		set wide = "-W"
		shift
		goto top
	endsw
E 7
I 7
    case -W:
	set voptions = "$voptions -W"
	shift
	goto top

    case -d:
	if ($#argv < 2) then
	    echo "vgrind: $1:q option must have argument"
	    goto done
	else
	    set options = ($options $1:q $2)
	    shift
	    shift
	    goto top
	endif
			
    case -h:
	if ($#argv < 2) then
	    echo "vgrind: $1:q option must have argument"
	    goto done
	else
	    set head="$2"
	    shift
	    shift
	    goto top
	endif
			
    case -*:
	set options = "$options $1:q"
	shift
	goto top

    default:
	set files = "$files $1:q"
	shift
	goto top
    endsw
E 7
endif
if (-r index) then
D 7
	echo > nindex
	foreach i ($*:q)
		echo "/ $i /d" >> nindex
	end
	sed -f nindex index >xindex
D 3
	$b/vfontedpr $*:q | \
		/bin/sh -c "vtroff $t $wide -rx1 $o -i -mvgrind 2>> xindex"
E 3
I 3
D 5
	if (f == "-f") then
E 5
I 5
	if ($f == 'filter') then
	    $b/vfontedpr -f $*:q | cat /usr/lib/tmac/tmac.vgrind -
E 7
I 7
    echo > nindex
    foreach i ($files)
D 8
	echo "/ $i /d" >> nindex
E 8
I 8
	#	make up a sed delete command for filenames
	#	being careful about slashes.
	echo "? $i ?d" | sed -e "s:/:\\/:g" -e "s:?:/:g" >> nindex
E 8
    end
    sed -f nindex index >xindex
    if ($f == 'filter') then
	if ("$head" != "") then
	    $b/vfontedpr $options -h "$head" $files | cat $b/tmac/tmac.vgrind -
E 7
	else
E 5
D 7
	    $b/vfontedpr $*:q | \
		    /bin/sh -c "vtroff $t $wide -rx1 $o -i -mvgrind 2>> xindex"
E 7
I 7
	    $b/vfontedpr $options $files | cat $b/tmac/tmac.vgrind -
E 7
D 5
	else
D 4
	    $b/vfontedpr $*:q
E 4
I 4
	    $b/vfontedpr $*:q | cat /usr/lib/tmac/tmac.vgrind -
E 5
	endif
E 4
E 3
D 7
	sort -df +0 -2 xindex >index
	rm nindex xindex
E 7
I 7
    else
	if ("$head" != "") then
	    $b/vfontedpr $options -h "$head" $files | \
		/bin/sh -c "vtroff -rx1 $voptions -i -mvgrind 2>> xindex"
	else
	    $b/vfontedpr $options $files | \
		/bin/sh -c "vtroff -rx1 $voptions -i -mvgrind 2>> xindex"
	endif
    endif
    sort -df +0 -2 xindex >index
    rm nindex xindex
E 7
else
D 3
	$b/vfontedpr $*:q | vtroff $t $wide -i $o -mvgrind
E 3
I 3
D 5
	if (f == "-f") then
	    $b/vfontedpr $*:q | vtroff $t $wide -i $o -mvgrind
E 5
I 5
D 7
	if ($f == 'filter') then
	    $b/vfontedpr -f $*:q | cat /usr/lib/tmac/tmac.vgrind -
E 7
I 7
    if ($f == 'filter') then
	if ("$head" != "") then
	    $b/vfontedpr $options -h "$head" $files | cat $b/tmac/tmac.vgrind -
E 7
E 5
	else
D 4
	    $b/vfontedpr $*:q
E 4
I 4
D 5
	    $b/vfontedpr $*:q | cat /usr/lib/tmac/tmac.vgrind -
E 5
I 5
D 7
	    $b/vfontedpr $*:q | vtroff $t $wide -i $o -mvgrind
E 7
I 7
	    $b/vfontedpr $options $files | cat $b/tmac/tmac.vgrind -
E 7
E 5
	endif
I 7
    else
	if ("$head" != "") then
	    $b/vfontedpr $options -h "$head" $files \
		| vtroff -i $voptions -mvgrind
	else
	    $b/vfontedpr $options $files \
		| vtroff -i $voptions -mvgrind
	endif
    endif
E 7
E 4
E 3
endif
I 7

done:
E 7
E 1

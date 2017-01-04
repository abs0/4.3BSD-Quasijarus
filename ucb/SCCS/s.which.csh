h57480
s 00008/00002/00045
d D 5.4 88/04/19 20:12:40 bostic 8 7
c add Berkeley specific header, written by Peter Kessler
e
s 00003/00004/00044
d D 5.3 88/04/19 09:26:04 bostic 7 6
c this got fixed twice; either source .cshrc or don't use -f; latter seems
c simpler
e
s 00003/00001/00045
d D 5.2 85/07/29 09:49:11 bloom 6 5
c see if .cshrc exists before trying to source it
e
s 00006/00002/00040
d D 5.1 85/06/06 09:29:27 dist 5 4
c Add copyright
e
s 00003/00001/00039
d D 4.4 85/03/11 12:38:59 mckusick 4 3
c which should see aliases (from peter)
e
s 00001/00001/00039
d D 4.3 84/01/23 16:43:38 ralph 3 2
c don't use -f so it will find aliases
e
s 00002/00002/00038
d D 4.2 83/02/14 18:04:08 mckusick 2 1
c Changed to use environment path, not .cshrc path
e
s 00040/00000/00000
d D 4.1 83/02/14 18:02:59 mckusick 1 0
c date and time created 83/02/14 18:02:59 by mckusick
e
u
U
t
T
I 1
D 2
#! /bin/csh
E 2
I 2
D 3
#! /bin/csh -f
E 3
I 3
D 4
#! /bin/csh
E 4
I 4
D 5
#! /bin/csh -f
E 5
I 5
D 7
#!/bin/csh -f
E 7
I 7
#!/bin/csh
E 7
E 5
E 4
E 3
E 2
#
I 7
# DO NOT USE "csh -f"
#
E 7
D 5
#	%W%	(Berkeley)	%E%
E 5
I 5
# Copyright (c) 1980 Regents of the University of California.
D 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 8
I 8
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 8
#
#	%W% (Berkeley) %G%
E 5
#
#	which : tells you which program you get
D 2
#	hacked to do aliases (from .cshrc file only!)
E 2
I 2
#
I 4
set prompt = "% "
D 6
source ~/.cshrc
E 6
I 6
D 7
if ( -f ~/.cshrc) then
	source ~/.cshrc
endif
E 7
E 6
E 4
E 2
set noglob
foreach arg ( $argv )
    set alius = `alias $arg`
    switch ( $#alius )
	case 0 :
	    breaksw
	case 1 :
	    set arg = $alius[1]
	    breaksw
        default :
	    echo ${arg}: "	" aliased to $alius
	    continue
    endsw
    unset found
    if ( $arg:h != $arg:t ) then
	if ( -e $arg ) then
	    echo $arg
	else
	    echo $arg not found
	endif
	continue
    else
	foreach i ( $path )
	    if ( -x $i/$arg && ! -d $i/$arg ) then
		echo $i/$arg
		set found
		break
	    endif
	end
    endif
    if ( ! $?found ) then
	echo no $arg in $path
    endif
end
E 1

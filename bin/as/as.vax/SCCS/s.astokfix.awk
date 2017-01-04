h39092
s 00005/00002/00007
d D 5.1 85/04/30 14:35:41 dist 5 4
c Add copyright
e
s 00003/00005/00006
d D 4.4 83/06/30 09:31:41 rrh 4 3
c fix bug previnting proper generation of numbes
e
s 00000/00000/00011
d D 4.3 82/02/14 16:37:40 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00011
d D 4.2 82/02/14 16:24:13 rrh 2 1
c Synchronizing this new file to release 4.2
e
s 00011/00000/00000
d D 4.1 82/02/14 16:22:35 rrh 1 0
c date and time created 82/02/14 16:22:35 by rrh
e
u
U
t
T
I 1
#
D 5
#	Copyright (c) 1982 Regents of the University of California */
#	%Z%%M% %I% %G%
E 5
I 5
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 5
#
/AWKFIXESME/{
D 4
	if ($4 == "AWKFIXESME")
		$4 = count++;
}
{
	print $0;
E 4
I 4
	if ($4 == "AWKFIXESME"){
		print $1 " " $2 " " $3 " " count++;
	}
E 4
}
E 1

h26178
s 00010/00005/00019
d D 5.3 88/06/18 19:47:34 bostic 5 4
c install approved copyright notice
e
s 00008/00002/00016
d D 5.2 88/02/16 11:16:55 bostic 4 3
c authored by Alan Char; add Berkeley specific header
e
s 00005/00001/00013
d D 5.1 85/05/29 11:43:20 dist 3 2
c Add copyright
e
s 00000/00000/00014
d D 4.1 82/05/11 15:03:02 rrh 2 1
c bringing to release 4.1
e
s 00014/00000/00000
d D 1.1 82/05/11 14:54:56 rrh 1 0
c date and time created 82/05/11 14:54:56 by rrh
e
u
U
t
T
I 1
/*
D 3
 *	%M%	%I%	%E%
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 *
 *	%W% (Berkeley) %G%
E 3
 */

struct situatn  {
	int	brd[26];
	int	roll1;
	int	roll2;
	int	mp[4];
	int	mg[4];
	int	new1;
	int	new2;
	char	*(*com[8]);
};
E 1

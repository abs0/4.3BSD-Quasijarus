h10114
s 00010/00005/00016
d D 5.3 88/06/18 19:38:37 bostic 3 2
c install approved copyright notice
e
s 00010/00002/00011
d D 5.2 87/12/29 17:17:24 bostic 2 1
c Berkeley header
e
s 00013/00000/00000
d D 5.1 86/11/26 13:37:16 bostic 1 0
c date and time created 86/11/26 13:37:16 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
 *
 *	%W% (Berkeley) %G%
E 2
 */

/*
 * unctrl.h
 */

extern char	*_unctrl[];

# define	unctrl(ch)	(_unctrl[ch & 0177])
E 1

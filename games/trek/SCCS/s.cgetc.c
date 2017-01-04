h26931
s 00010/00005/00018
d D 5.3 88/06/18 15:07:10 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00014
d D 5.2 88/05/05 18:33:16 bostic 3 2
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00010
d D 5.1 85/05/30 08:48:59 dist 2 1
c Add copyright
e
s 00011/00000/00000
d D 1.1 83/05/27 14:57:15 layer 1 0
c date and time created 83/05/27 14:57:15 by layer
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W%	(Berkeley) %G%";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

# include	<stdio.h>

char	cgetc(i)
int	i;
{
	return ( getchar() );
}
E 1

h62832
s 00013/00002/00014
d D 5.2 88/06/27 16:37:42 bostic 4 3
c install approved copyright notice
e
s 00007/00001/00009
d D 5.1 85/05/30 09:46:57 dist 3 2
c Add copyright
e
s 00001/00001/00009
d D 4.2 85/01/10 12:49:08 serge 2 1
c changed declaration of inet_addr() to unsigned long
e
s 00010/00000/00000
d D 4.1 83/05/28 15:18:25 sam 1 0
c date and time created 83/05/28 15:18:25 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * External definitions for
 * functions in inet(3N)
 */
D 2
struct	in_addr inet_addr();
E 2
I 2
unsigned long inet_addr();
E 2
char	*inet_ntoa();
struct	in_addr inet_makeaddr();
unsigned long inet_network();
E 1

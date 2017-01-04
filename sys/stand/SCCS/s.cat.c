h07550
s 00002/00002/00026
d D 7.4 89/03/21 10:02:06 karels 9 8
c one colon will do; null is a character
e
s 00010/00005/00018
d D 7.3 88/06/29 18:19:09 bostic 8 7
c install approved copyright notice
e
s 00012/00012/00011
d D 7.2 88/02/21 11:00:54 bostic 7 6
c this is machine independent; redo for simplification
e
s 00001/00001/00022
d D 7.1 86/06/05 01:40:38 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00016
d D 6.2 85/06/08 13:07:01 mckusick 5 4
c Add copyright
e
s 00000/00000/00017
d D 6.1 83/07/29 07:46:37 sam 4 3
c 4.2 distribution
e
s 00001/00001/00016
d D 4.2 81/03/15 20:45:52 wnj 3 2
c 
e
s 00000/00000/00017
d D 4.1 80/11/09 16:29:08 bill 2 1
c stamp for 4bsd
e
s 00017/00000/00000
d D 1.1 80/06/28 10:42:46 bill 1 0
c date and time created 80/06/28 10:42:46 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%G%	*/
E 3
I 3
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
I 7
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
 *
E 7
 *	%W% (Berkeley) %G%
 */
E 5
E 3

main()
{
D 7
	int c, i;
	char buf[50];
E 7
I 7
	register int c, fd;
E 7

D 7
	do {
		printf("File: ");
		gets(buf);
		i = open(buf, 0);
	} while (i <= 0);

	while ((c = getc(i)) > 0)
E 7
I 7
D 9
	fd = getfile("File: ", 0);
	while ((c = getc(fd)) > 0)
E 9
I 9
	fd = getfile("File", 0);
	while ((c = getc(fd)) >= 0)
E 9
E 7
		putchar(c);
	exit(0);
}
E 1

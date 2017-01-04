h28973
s 00010/00005/00012
d D 5.3 88/06/18 19:56:07 bostic 12 11
c install approved copyright notice
e
s 00009/00003/00008
d D 5.2 88/03/09 12:30:45 bostic 11 10
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00007/00003/00004
d D 5.1 85/05/29 16:12:01 dist 10 9
c Add copyright
e
s 00006/00000/00001
d D 2.7 85/04/23 21:51:52 edward 9 8
c copyright message
e
s 00000/00000/00001
d D 2.6 85/04/22 02:03:14 edward 8 7
c 4.3 distribution
e
s 00000/00000/00001
d D 2.5 85/03/02 13:44:14 edward 7 6
c new version: player, driver, log now a single program
e
s 00000/00000/00001
d D 2.4 84/02/23 16:45:53 edward 6 5
c 
e
s 00000/00000/00001
d D 2.3 84/01/19 16:04:48 edward 5 4
c fixed driver death, and setuid(getuid()) after sync_open().
e
s 00000/00000/00001
d D 2.2 83/12/09 16:30:26 root 4 3
c 
e
s 00000/00000/00001
d D 2.1 83/10/31 13:45:43 edward 3 2
c new version
e
s 00001/00008/00000
d D 1.2 83/07/20 17:28:08 edward 2 1
c 
e
s 00008/00000/00000
d D 1.1 83/03/19 14:11:15 leres 1 0
c date and time created 83/03/19 14:11:15 by leres
e
u
U
t
T
I 9
/*
D 10
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
I 10
 * Copyright (c) 1983 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 12
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
I 12
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
E 12
E 11
E 10
 */
I 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11
E 10

E 9
I 1
D 2
version()
{
    static char *cp =
	"Wooden Ships and Iron Men, Version %R%.%L% (%E%)";

    Signal(cp, 0, 0);
    return;
}
E 2
I 2
char version[] = "Wooden Ships and Iron Men, Version %R%.%L% (%E%)";
E 2
E 1

h56088
s 00012/00007/00020
d D 5.3 88/06/18 13:18:34 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00016
d D 5.2 87/12/02 15:46:02 bostic 4 3
c bug report 4.3BSD/bin/105; exit 0 on success
e
s 00013/00001/00008
d D 5.1 85/04/30 15:05:07 dist 3 2
c Add copyright
e
s 00003/00001/00006
d D 4.2 83/08/11 19:53:05 sam 2 1
c sccs keyword fixes
e
s 00007/00000/00000
d D 4.1 82/11/07 20:02:33 sam 1 0
c date and time created 82/11/07 20:02:33 by sam
e
u
U
t
T
I 3
/*
D 5
 * Copyright (c) 1983 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
E 5
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
 * software without specific written prior permission. This software
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
 */

E 3
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
I 3
char copyright[] =
D 5
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 5
I 5
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 5
 All rights reserved.\n";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

#ifndef lint
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4
E 3
E 2

main()
{
D 4

E 4
	printf("%d\n", getpagesize());
I 4
	exit(0);
E 4
}
E 1

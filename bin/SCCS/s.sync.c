h29790
s 00012/00007/00020
d D 4.3 88/06/18 13:18:59 bostic 3 2
c install approved copyright notice
e
s 00023/00002/00004
d D 4.2 87/12/02 16:02:01 bostic 2 1
c bug report 4.3BSD/bin/107; exit 0 on success
e
s 00006/00000/00000
d D 4.1 80/10/01 17:28:46 bill 1 0
c date and time created 80/10/01 17:28:46 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
/*
D 3
 * Copyright (c) 1987 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1987 Regents of the University of California.
E 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
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
 */

#ifndef lint
char copyright[] =
D 3
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 3
I 3
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 3
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 2
main()
{
D 2

E 2
	sync();
I 2
	exit(0);
E 2
}
E 1

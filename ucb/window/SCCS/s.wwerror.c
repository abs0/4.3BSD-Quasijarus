h12818
s 00010/00005/00040
d D 3.5 88/06/29 21:38:03 bostic 5 4
c install approved copyright notice
e
s 00013/00007/00032
d D 3.4 88/02/21 13:38:20 bostic 4 3
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00033
d D 3.3 85/04/24 16:18:34 edward 3 2
c copyright messages
e
s 00001/00001/00032
d D 3.2 84/05/23 01:59:36 edward 2 1
c new sccs id
e
s 00033/00000/00000
d D 3.1 83/09/13 15:00:22 edward 1 0
c date and time created 83/09/13 15:00:22 by edward
e
u
U
t
T
I 1
D 4
#ifndef lint
D 2
static	char *sccsid = "%W% %E%";
E 2
I 2
static char sccsid[] = "%W% %G%";
E 2
#endif

E 4
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
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
 */
I 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

E 3
#include "ww.h"

char *
wwerror()
{
	extern errno;
	extern char *sys_errlist[];

	switch (wwerrno) {
	case WWE_NOERR:
		return "No error";
	case WWE_SYS:
		return sys_errlist[errno];
	case WWE_NOMEM:
		return "Out of memory";
	case WWE_TOOMANY:
		return "Too many windows";
	case WWE_NOPTY:
		return "Out of pseudo-terminals";
	case WWE_SIZE:
		return "Bad window size";
	case WWE_BADTERM:
		return "Unknown terminal type";
	case WWE_CANTDO:
		return "Can't run window on this terminal";
	default:
		return "Unknown error";
	}
}
E 1

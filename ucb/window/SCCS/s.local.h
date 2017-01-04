h56638
s 00010/00005/00017
d D 3.7 88/06/29 21:36:09 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00011
d D 3.6 88/02/21 13:37:06 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00001/00001/00017
d D 3.5 88/01/03 00:56:09 bostic 5 4
c fix ctrl macro for ANSI C
e
s 00006/00000/00012
d D 3.4 85/04/24 16:23:36 edward 4 3
c copyright messages
e
s 00002/00002/00010
d D 3.3 85/03/11 13:14:50 edward 3 2
c back to ~/.windowrc
e
s 00001/00001/00011
d D 3.2 84/05/23 02:01:03 edward 2 1
c new sccs id
e
s 00012/00000/00000
d D 3.1 84/04/16 20:29:43 edward 1 0
c date and time created 84/04/16 20:29:43 by edward
e
u
U
t
T
I 1
/*
D 2
 *	%W% %E%
E 2
I 2
D 6
 * %W% %G%
E 2
 */

/*
I 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 6
I 6
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
 *	%W% (Berkeley) %G%
E 6
 */

/*
E 4
 * Things of local interest.
 */

D 3
#define RUNCOM		".windrc"
E 3
I 3
#define RUNCOM		".windowrc"
E 3
D 5
#define ESCAPEC		ctrl(p)
E 5
I 5
#define ESCAPEC		ctrl('p')
E 5
D 3
#define NLINE		48
E 3
I 3
#define NLINE		48			/* default text buffer size */
E 3
#define SHELL		"/bin/csh"		/* if no environment SHELL */
E 1

h27394
s 00010/00005/00032
d D 3.7 88/06/29 21:36:02 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00026
d D 3.6 88/02/21 13:36:58 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00027
d D 3.5 85/04/24 16:21:38 edward 5 4
c copyright messages
e
s 00007/00004/00020
d D 3.4 84/07/12 13:38:57 edward 4 3
c new ARG_LIST flag for commands
e
s 00001/00001/00023
d D 3.3 84/05/23 02:00:29 edward 3 2
c new sccs id
e
s 00002/00004/00022
d D 3.2 84/03/23 18:17:33 edward 2 1
c compile with -R
e
s 00026/00000/00000
d D 3.1 83/11/22 12:48:07 edward 1 0
c date and time created 83/11/22 12:48:07 by edward
e
u
U
t
T
I 1
/*
D 3
 *	%W% %E%
E 3
I 3
D 6
 * %W% %G%
E 3
 */

I 5
/*
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

E 5
I 2
#define LCMD_NARG 20			/* maximum number of arguments */

E 2
struct lcmd_tab {
	char *lc_name;
	int lc_minlen;
	int (*lc_func)();
	struct lcmd_arg *lc_arg;
};

struct lcmd_arg {
	char *arg_name;
	int arg_minlen;
D 4
	char arg_type;
E 4
I 4
	int arg_flags;
E 4
D 2
	struct value arg_val;
E 2
};
D 2
#define arg_num arg_val.v_num
#define arg_str arg_val.v_str
#define arg_vtype arg_val.v_type
E 2

D 4
#define ARG_ANY 0
#define ARG_NUM 1
#define ARG_STR 2
E 4
I 4
	/* arg_flags bits */
#define ARG_TYPE	0x0f		/* type of arg */
#define ARG_ANY		0x00		/* any type */
#define ARG_NUM		0x01		/* must be a number */
#define ARG_STR		0x02		/* must be a string */
#define ARG_LIST	0x10		/* this arg can be a list */
E 4

struct lcmd_tab *lcmd_lookup();
E 1

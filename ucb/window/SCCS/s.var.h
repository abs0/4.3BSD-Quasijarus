h59321
s 00010/00005/00029
d D 3.9 88/06/29 21:37:06 bostic 9 8
c install approved copyright notice
e
s 00011/00007/00023
d D 3.8 88/02/21 13:37:51 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00024
d D 3.7 85/04/24 16:22:10 edward 7 6
c copyright messages
e
s 00001/00001/00023
d D 3.6 84/05/23 02:00:37 edward 6 5
c new sccs id
e
s 00009/00005/00015
d D 3.5 84/05/06 17:55:52 edward 5 4
c alias macros
e
s 00001/00001/00019
d D 3.4 84/01/13 11:53:16 edward 4 3
c var_walk() reworked
e
s 00003/00002/00017
d D 3.3 84/01/12 11:45:16 edward 3 2
c var_unset() added, plus cleanup and bug fixes
e
s 00004/00000/00015
d D 3.2 83/12/06 12:48:43 edward 2 1
c var_walk() macro, and var_setstr(), var_setnum() added
e
s 00015/00000/00000
d D 3.1 83/11/22 12:48:13 edward 1 0
c date and time created 83/11/22 12:48:13 by edward
e
u
U
t
T
I 1
/*
D 6
 *	%W% %E%
E 6
I 6
D 8
 * %W% %G%
E 6
 */

I 7
/*
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
 *
 *	%W% (Berkeley) %G%
E 8
 */

E 7
struct var {
	struct var *r_left;
	struct var *r_right;
	char *r_name;
	struct value r_val;
};

D 5
struct var *var_set();
I 2
struct var *var_setstr();
struct var *var_setnum();
E 5
I 5
struct var *var_set1();
struct var *var_setstr1();
struct var *var_setnum1();
E 5
E 2
D 3
struct var *var_lookup();
E 3
I 3
struct var **var_lookup1();
E 3
I 2

D 3
#define var_walk(f) var_walk1(var_head, (f))
E 3
I 3
D 4
#define var_walk(f)	var_walk1(var_head, (f))
E 4
I 4
D 5
#define var_walk(f, a)	var_walk1(var_head, (f), (a))
E 4
#define var_lookup(n)	(*var_lookup1(n))
E 5
I 5
#define var_set(n, v)		var_set1(&var_head, n, v)
#define var_setstr(n, s)	var_setstr1(&var_head, n, s)
#define var_setnum(n, i)	var_setnum1(&var_head, n, i)
#define var_unset(n)		var_unset1(&var_head, n)
#define var_lookup(n)		(*var_lookup1(&var_head, n))
#define var_walk(f, a)		var_walk1(var_head, f, a)
E 5
E 3
E 2

struct var *var_head;		/* secret, shhh */
E 1

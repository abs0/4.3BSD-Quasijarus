h05489
s 00010/00005/00023
d D 3.6 88/06/29 21:35:22 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00017
d D 3.5 88/02/21 13:36:31 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00018
d D 3.4 85/04/24 16:23:45 edward 5 4
c copyright messages
e
s 00004/00000/00014
d D 3.3 84/06/02 18:04:40 edward 4 3
c catch recursive aliases
e
s 00001/00001/00013
d D 3.2 84/05/23 02:01:06 edward 3 1
c new sccs id
e
s 00001/00001/00013
d R 3.2 84/05/23 01:54:52 edward 2 1
c 
e
s 00014/00000/00000
d D 3.1 84/05/06 18:00:10 edward 1 0
c date and time created 84/05/06 18:00:10 by edward
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
#define alias var
#define a_name r_name
#define a_buf r_val.v_str
I 4
#define a_flags r_val.v_type

	/* a_flags bits, must not interfere with v_type values */
#define A_INUSE		0x010	/* already inuse */
E 4

#define alias_set(n, s)		var_setstr1(&alias_head, n, s)
#define alias_walk(f, a)	var_walk1(alias_head, f, a)
#define alias_unset(n)		var_unset1(&alias_head, n)
#define alias_lookup(n)		(*var_lookup1(&alias_head, n))

struct var *alias_head;
E 1

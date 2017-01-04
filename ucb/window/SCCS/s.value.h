h64461
s 00010/00005/00024
d D 3.7 88/06/29 21:36:59 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00018
d D 3.6 88/02/21 13:37:47 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00019
d D 3.5 85/04/24 16:22:05 edward 5 4
c copyright messages
e
s 00001/00001/00018
d D 3.4 84/05/23 02:00:35 edward 4 3
c new sccs id
e
s 00002/00000/00017
d D 3.3 84/01/12 11:45:34 edward 3 2
c val_free() added
e
s 00001/00005/00016
d D 3.2 83/12/06 12:47:48 edward 2 1
c got rid of v_token, and v_link
e
s 00021/00000/00000
d D 3.1 83/11/22 12:48:11 edward 1 0
c date and time created 83/11/22 12:48:11 by edward
e
u
U
t
T
I 1
/*
D 4
 *	%W% %E%
E 4
I 4
D 6
 * %W% %G%
E 4
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
struct value {
	char v_type;
D 2
	struct value *v_link;
E 2
	union {
		int V_num;
		char *V_str;
D 2
		int V_tok;
E 2
	} v_un;
};
#define v_num	v_un.V_num
#define v_str	v_un.V_str
D 2
#define v_tok   v_un.V_tok
E 2

#define V_NUM	1
#define V_STR	2
D 2
#define V_TOK	3
#define V_ERR	4
E 2
I 2
#define V_ERR	3
I 3

#define val_free(v)	((v).v_type == V_STR ? str_free((v).v_str) : 0)
E 3
E 2
E 1

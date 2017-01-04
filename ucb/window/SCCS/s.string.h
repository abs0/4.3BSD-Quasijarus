h12919
s 00010/00005/00036
d D 3.7 88/06/29 21:36:33 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00030
d D 3.6 88/02/21 13:37:28 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00007/00000/00030
d D 3.5 85/04/24 16:21:48 edward 5 4
c copyright messages
e
s 00001/00001/00029
d D 3.4 84/05/23 02:00:31 edward 4 3
c new sccs id
e
s 00001/00000/00029
d D 3.3 84/04/05 16:52:15 edward 3 2
c string operators, +, <<, >>
e
s 00020/00000/00009
d D 3.2 84/01/05 15:47:30 edward 2 1
c consistency checking
e
s 00009/00000/00000
d D 3.1 83/11/22 12:48:09 edward 1 0
c date and time created 83/11/22 12:48:09 by edward
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
I 2
#define STR_DEBUG
E 2

char *str_cpy();
I 3
char *str_ncpy();
E 3
char *str_cat();
char *str_itoa();

#define str_cmp(a, b)	strcmp(a, b)
I 2

#ifdef STR_DEBUG
struct string {
	struct string *s_forw;
	struct string *s_back;
	char s_data[1];
};

struct string str_head;

#define str_offset ((unsigned)str_head.s_data - (unsigned)&str_head)
#define str_stos(s) ((struct string *)((unsigned)(s) - str_offset))

char *str_alloc();
int str_free();
#else
#define str_free(s)	free(s)
#define str_alloc(s)	malloc(s)
#endif
E 2
E 1

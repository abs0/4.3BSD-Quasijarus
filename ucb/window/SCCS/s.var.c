h60339
s 00010/00005/00128
d D 3.10 88/06/29 21:37:02 bostic 10 9
c install approved copyright notice
e
s 00013/00007/00120
d D 3.9 88/02/21 13:37:49 bostic 9 8
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00121
d D 3.8 85/04/24 16:16:54 edward 8 7
c copyright messages
e
s 00002/00001/00119
d D 3.7 84/07/12 13:38:49 edward 7 6
c new ARG_LIST flag for commands
e
s 00001/00001/00119
d D 3.6 84/05/23 02:00:21 edward 6 5
c new sccs id
e
s 00015/00011/00105
d D 3.5 84/05/06 17:55:27 edward 5 4
c alias macros
e
s 00006/00005/00110
d D 3.4 84/01/13 11:53:11 edward 4 3
c var_walk() reworked
e
s 00043/00034/00072
d D 3.3 84/01/12 11:45:12 edward 3 2
c var_unset() added, plus cleanup and bug fixes
e
s 00026/00007/00080
d D 3.2 83/12/06 12:49:14 edward 2 1
c var_walk() now a macro, var_setstr(), var_setnum() added.
c bug in var_add() fixed
e
s 00087/00000/00000
d D 3.1 83/11/22 12:48:04 edward 1 0
c date and time created 83/11/22 12:48:04 by edward
e
u
U
t
T
I 1
D 9
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 9
I 8
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */
I 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 9

E 8
#include "value.h"
#include "var.h"
#include "string.h"

char *malloc();

struct var *
D 5
var_set(name, v)
E 5
I 5
var_set1(head, name, v)
struct var **head;
E 5
char *name;
struct value *v;
{
I 3
	register struct var **p;
E 3
	register struct var *r;
I 3
	struct value val;
E 3

D 3
	if ((r = var_lookup(name)) == 0) {
E 3
I 3
	/* do this first, easier to recover */
	val = *v;
D 7
	if (val.v_type == V_STR && (val.v_str = str_cpy(val.v_str)) == 0)
E 7
I 7
	if (val.v_type == V_STR && val.v_str != 0 &&
	    (val.v_str = str_cpy(val.v_str)) == 0)
E 7
		return 0;
D 5
	if (*(p = var_lookup1(name)) == 0) {
E 5
I 5
	if (*(p = var_lookup1(head, name)) == 0) {
E 5
E 3
		r = (struct var *) malloc(sizeof (struct var));
D 3
		if (r == 0)
E 3
I 3
		if (r == 0) {
			val_free(val);
E 3
			return 0;
I 3
		}
E 3
		if ((r->r_name = str_cpy(name)) == 0) {
I 3
			val_free(val);
E 3
			free((char *) r);
			return 0;
		}
D 3
		var_add(r);
E 3
I 3
		r->r_left = r->r_right = 0;
		*p = r;
	} else {
		r = *p;
		val_free(r->r_val);
E 3
	}
D 3
	r->r_val = *v;
	if (v->v_type == V_STR) {
		if ((r->r_val.v_str = str_cpy(v->v_str)) == 0) {
			free((char *) r);
			str_free(r->r_name);
			return 0;
		}
	}
E 3
I 3
	r->r_val = val;
E 3
	return r;
}

struct var *
I 2
D 5
var_setstr(name, str)
E 5
I 5
var_setstr1(head, name, str)
struct var **head;
E 5
char *name;
char *str;
{
	struct value v;

	v.v_type = V_STR;
	v.v_str = str;
D 5
	return var_set(name, &v);
E 5
I 5
	return var_set1(head, name, &v);
E 5
}

struct var *
D 5
var_setnum(name, num)
E 5
I 5
var_setnum1(head, name, num)
struct var **head;
E 5
char *name;
int num;
{
	struct value v;

	v.v_type = V_NUM;
	v.v_num = num;
D 5
	return var_set(name, &v);
E 5
I 5
	return var_set1(head, name, &v);
E 5
}

D 3
struct var *
E 2
var_lookup(name)
E 3
I 3
D 5
var_unset(name)
E 5
I 5
var_unset1(head, name)
struct var **head;
E 5
E 3
char *name;
{
I 3
	register struct var **p;
E 3
	register struct var *r;
I 3

D 5
	if (*(p = var_lookup1(name)) == 0)
E 5
I 5
	if (*(p = var_lookup1(head, name)) == 0)
E 5
		return -1;
	r = *p;
	*p = r->r_left;
	while (*p != 0)
		p = &(*p)->r_right;
	*p = r->r_right;
	val_free(r->r_val);
	str_free(r->r_name);
	free((char *) r);
	return 0;
}

struct var **
D 5
var_lookup1(name)
E 5
I 5
var_lookup1(p, name)
register struct var **p;
E 5
register char *name;
{
D 5
	register struct var **p;
E 5
E 3
	register cmp;

D 3
	for (r = var_head; r != 0;) {
		if ((cmp = strcmp(name, r->r_name)) < 0)
			r = r->r_left;
E 3
I 3
D 5
	for (p = &var_head; *p != 0;) {
E 5
I 5
	while (*p != 0) {
E 5
		if ((cmp = strcmp(name, (*p)->r_name)) < 0)
			p = &(*p)->r_left;
E 3
		else if (cmp > 0)
D 3
			r = r->r_right;
E 3
I 3
			p = &(*p)->r_right;
E 3
		else
			break;
	}
D 3
	return r;
E 3
I 3
	return p;
E 3
}

D 2
var_walk(func)
int (*func)();
{
	var_walk1(var_head, func);
}

E 2
D 4
var_walk1(r, func)
E 4
I 4
var_walk1(r, func, a)
E 4
register struct var *r;
int (*func)();
{
	if (r == 0)
D 4
		return;
	var_walk1(r->r_left, func);
D 2
	(*func)();
E 2
I 2
	(*func)(r);
E 2
	var_walk1(r->r_right, func);
E 4
I 4
		return 0;
	if (var_walk1(r->r_left, func, a) < 0 || (*func)(a, r) < 0
	    || var_walk1(r->r_right, func, a) < 0)
		return -1;
	return 0;
E 4
D 3
}

var_add(r)
register struct var *r;
{
	register struct var **p;

	for (p = &var_head; *p != 0;) {
		/* don't care about duplicate entries */
		if (strcmp(r->r_name, (*p)->r_name) < 0)
			p = &(*p)->r_left;
		else
			p = &(*p)->r_right;
	}
	*p = r;
I 2
	r->r_left = r->r_right = 0;
E 3
E 2
}
E 1

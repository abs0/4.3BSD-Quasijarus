h32092
s 00010/00005/00162
d D 3.7 88/06/29 21:36:21 bostic 7 6
c install approved copyright notice
e
s 00013/00007/00154
d D 3.6 88/02/21 13:37:18 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00155
d D 3.5 85/04/24 16:22:16 edward 5 4
c copyright messages
e
s 00003/00003/00152
d D 3.4 84/07/13 23:36:52 edward 4 3
c fixed error messages
e
s 00001/00001/00154
d D 3.3 84/05/23 02:00:40 edward 3 2
c new sccs id
e
s 00002/00008/00153
d D 3.2 84/05/06 17:55:57 edward 2 1
c alias macros
e
s 00161/00000/00000
d D 3.1 84/01/12 12:43:00 edward 1 0
c date and time created 84/01/12 12:43:00 by edward
e
u
U
t
T
I 1
D 6
#ifndef lint
D 3
static	char *sccsid = "%W% %E%";
E 3
I 3
static char sccsid[] = "%W% %G%";
E 3
#endif

E 6
I 5
/*
D 6
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
E 6
 */
I 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 6

E 5
#include "parser.h"

/*
 * =
 * ? :
 * ||
 * &&
 * |
 * ^
 * &
 * == !=
 * <= >=
 * << >>
 * + -
 * * / %
 * unary - + ~ !
 */
p_expr(v, flag)
register struct value *v;
char flag;
{
	struct value t;
	int ret;

D 2
#ifdef DEBUG
	error("expr: %d.", flag);
#endif
E 2
	if (p_expr0(&t, flag) < 0)
		return -1;

	if (token != T_ASSIGN) {
		*v = t;
		return 0;
	}
	switch (t.v_type) {
I 2
	case V_NUM:
		p_error("%d: Not a variable.", t.v_num);
E 2
	case V_ERR:
		t.v_str = 0;
		break;
D 2
	case V_NUM:
		if ((t.v_str = str_itoa(t.v_num)) == 0) {
			p_memerror();
			return -1;
		}
E 2
	}
	ret = p_assign(t.v_str, v, flag);
	if (t.v_str != 0)
		str_free(t.v_str);
	return ret;
}

/*
 * ? :
 */
p_expr0(v, flag)
register struct value *v;
char flag;
{
	struct value t;
	char true;

	if (p_expr1(v, flag) < 0)
		return -1;
	if (token != T_QUEST)
		return 0;
	switch (v->v_type) {
	case V_NUM:
		true = v->v_num != 0;
		break;
	case V_STR:
D 4
		p_error("Numeric value required for ?.");
E 4
I 4
		p_error("?: Numeric left operand required.");
E 4
		str_free(v->v_str);
		v->v_type = V_ERR;
	case V_ERR:
		flag = 0;
		break;
	}
	(void) s_gettok();
	v->v_type = V_ERR;
	if ((flag && true ? p_expr1(v, 1) : p_expr1(&t, 0)) < 0)
		return -1;
	if (token != T_COLON) {
		val_free(*v);
		p_synerror();
		return -1;
	}
	(void) s_gettok();
	return flag && !true ? p_expr1(v, 1) : p_expr1(&t, 0);
}

/*
 * ||
 */
p_expr1(v, flag)
register struct value *v;
char flag;
{
	char true = 0;

	if (p_expr2(v, flag) < 0)
		return -1;
	if (token != T_OROR)
		return 0;
	for (;;) {
		switch (v->v_type) {
		case V_NUM:
			v->v_num = true = true || v->v_num != 0;
			break;
		case V_STR:
D 4
			p_error("Numeric value required for ||.");
E 4
I 4
			p_error("||: Numeric operands required.");
E 4
			str_free(v->v_str);
			v->v_type = V_ERR;
		case V_ERR:
			flag = 0;
			break;
		}
		if (token != T_OROR)
			return 0;
		(void) s_gettok();
		if (p_expr2(v, flag && !true) < 0)
			return -1;
	}
}

/*
 * &&
 */
p_expr2(v, flag)
register struct value *v;
char flag;
{
	char true = 1;

	if (p_expr3_10(3, v, flag) < 0)
		return -1;
	if (token != T_ANDAND)
		return 0;
	for (;;) {
		switch (v->v_type) {
		case V_NUM:
			v->v_num = true = true && v->v_num != 0;
			break;
		case V_STR:
D 4
			p_error("Numeric value required for &&.");
E 4
I 4
			p_error("&&: Numeric operands required.");
E 4
			str_free(v->v_str);
			v->v_type = V_ERR;
		case V_ERR:
			flag = 0;
			break;
		}
		if (token != T_ANDAND)
			return 0;
		(void) s_gettok();
		if (p_expr3_10(3, v, flag && true) < 0)
			return -1;
	}
	/*NOTREACHED*/
}
E 1

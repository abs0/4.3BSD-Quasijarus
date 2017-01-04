h13012
s 00010/00005/00172
d D 3.11 88/06/29 21:36:25 bostic 11 10
c install approved copyright notice
e
s 00013/00007/00164
d D 3.10 88/02/21 13:37:21 bostic 10 9
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00165
d D 3.9 85/04/24 16:22:36 edward 9 8
c copyright messages
e
s 00000/00015/00165
d D 3.8 85/04/03 20:39:28 edward 8 7
c removed some compatibility with old window, and some clean up
e
s 00025/00020/00155
d D 3.7 84/07/13 23:57:11 edward 7 6
c $? added
e
s 00001/00001/00174
d D 3.6 84/05/23 02:00:48 edward 6 5
c new sccs id
e
s 00001/00001/00174
d D 3.5 84/05/08 21:24:41 edward 5 4
c bug from last time
e
s 00026/00049/00149
d D 3.4 84/05/06 17:56:05 edward 4 3
c alias macros
e
s 00004/00002/00194
d D 3.3 84/04/06 21:48:06 edward 3 2
c fixed freeing of null string pointers
e
s 00001/00000/00195
d D 3.2 84/01/13 12:08:04 edward 2 1
c include var.h and lcmd.c only in some of the parser?.c
e
s 00195/00000/00000
d D 3.1 84/01/12 12:43:03 edward 1 0
c date and time created 84/01/12 12:43:03 by edward
e
u
U
t
T
I 1
D 10
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 10
I 9
/*
D 10
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
I 10
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */
I 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

E 9
#include "parser.h"
I 2
#include "var.h"
E 2

/*
D 7
 * unary $ + - ! ~
E 7
I 7
 * unary $ $? + - ! ~
E 7
 */
p_expr11(v, flag)
register struct value *v;
char flag;
{
	int op;
	char *opname;

	switch (token) {
	case T_DOLLAR:
		opname = "$";
		break;
I 7
	case T_DQ:
		opname = "$?";
		break;
E 7
	case T_PLUS:
		opname = "unary +";
		break;
	case T_MINUS:
		opname = "unary -";
		break;
	case T_NOT:
		opname = "!";
		break;
	case T_COMP:
		opname = "~";
		break;
	default:
		return p_expr12(v, flag);
	}
	op = token;
	(void) s_gettok();
	if (p_expr11(v, flag) < 0)
		return -1;
	switch (v->v_type) {
	case V_NUM:
D 4
		if (op == T_DOLLAR && (v->v_str = str_itoa(v->v_num)) == 0) {
			p_memerror();
			return -1;
		}
E 4
		break;
	case V_STR:
		switch (op) {
		case T_MINUS:
		case T_NOT:
		case T_COMP:
D 7
			p_error("Numeric value required for %s.", opname);
E 7
I 7
			p_error("%s: Numeric operand required.", opname);
E 7
			str_free(v->v_str);
			v->v_type = V_ERR;
			return 0;
		}
		break;
	case V_ERR:
		return 0;
	}
	switch (op) {
D 7
	case T_DOLLAR: {
		struct var *r;
E 7
I 7
	case T_DOLLAR:
	case T_DQ:
E 7
D 4
		if ((r = var_lookup(v->v_str)) == 0) {
			p_error("%s: Undefined variable.", v->v_str);
E 4
I 4
		if (v->v_type == V_NUM) {
D 7
			v->v_num--;
D 5
			if (cx.x_type != X_BUF || cx.x_arg == 0
E 5
I 5
			if (cx.x_type != X_BUF || cx.x_arg == 0 ||
E 5
			    v->v_num < 0 || v->v_num >= cx.x_narg) {
E 7
I 7
			int tmp = cx.x_type == X_BUF && cx.x_arg != 0 &&
				v->v_num > 0 && v->v_num <= cx.x_narg;
			if (op == T_DQ)
				v->v_num = tmp;
			else if (tmp)
				*v = cx.x_arg[v->v_num - 1];
			else {
E 7
				p_error("%d: No such argument.", v->v_num);
				v->v_type = V_ERR;
D 7
				return 0;
E 7
			}
D 7
			if (flag)
				*v = cx.x_arg[v->v_num];
E 7
		} else {
D 7
			if ((r = var_lookup(v->v_str)) == 0) {
				p_error("%s: Undefined variable.", v->v_str);
				str_free(v->v_str);
E 7
I 7
			char *name = v->v_str;
			struct var *r = var_lookup(name);
			if (op == T_DQ) {
				v->v_type = V_NUM;
				v->v_num = r != 0;
			} else if (r != 0)
				*v = r->r_val;
			else {
				p_error("%s: Undefined variable.", name);
E 7
				v->v_type = V_ERR;
D 7
				return 0;
E 7
			}
E 4
D 7
			str_free(v->v_str);
D 4
			v->v_type = V_ERR;
			return 0;
E 4
I 4
			if (flag)
				*v = r->r_val;
E 7
I 7
			str_free(name);
E 7
E 4
		}
D 4
		str_free(v->v_str);
		if (flag) {
			*v = r->r_val;
			if (v->v_type == V_STR
			    && (v->v_str = str_cpy(v->v_str)) == 0) {
				p_memerror();
				return -1;
			}
E 4
I 4
D 7
		if (v->v_type == V_STR
		    && (v->v_str = str_cpy(v->v_str)) == 0) {
E 7
I 7
		if (v->v_type == V_STR && (v->v_str = str_cpy(v->v_str)) == 0) {
E 7
			p_memerror();
			return -1;
E 4
		}
		break;
D 7
		}
E 7
	case T_MINUS:
		v->v_num = - v->v_num;
		break;
	case T_NOT:
		v->v_num = ! v->v_num;
		break;
	case T_COMP:
		v->v_num = ~ v->v_num;
		break;
	}
	return 0;
}

/*
 * string, number, ( expr )
 * Plus function calls.
D 8
 * Also we map % into string.
E 8
 *
 * Always return v_type == V_ERR when flag == 0.
 */
p_expr12(v, flag)
register struct value *v;
char flag;
{
	v->v_type = V_ERR;
D 4
#ifdef DEBUG
	error("expr12: %d.", flag);
#endif
E 4
	switch (token) {
D 8
	case T_MOD:
D 4
#ifdef DEBUG
		error("expr12: %.");
#endif
E 4
		if (flag) {
			v->v_type = V_STR;
			v->v_str = str_cpy("%");
		}
		(void) s_gettok();
		break;
E 8
	case T_NUM:
D 4
#ifdef DEBUG
		error("expr12: NUM %d.", token_num);
#endif
E 4
		if (flag) {
			v->v_type = V_NUM;
			v->v_num = token_num;
		}
		(void) s_gettok();
		break;
	case T_STR:
D 4
#ifdef DEBUG
		error("expr12: STR %s.", token_str);
#endif
E 4
		if (flag) {
			v->v_type = V_STR;
			v->v_str = token_str;
		} else
			str_free(token_str);
		(void) s_gettok();
		break;
	case T_LP:
		(void) s_gettok();
		if (p_expr(v, flag) < 0) {
			p_synerror();
			return -1;
		}
		if (token != T_RP) {
			p_synerror();
			val_free(*v);
			return -1;
		}
		(void) s_gettok();
		break;
	default:
D 4
#ifdef DEBUG
		error("expr12: token %d.", token);
#endif
E 4
		return -1;
	}
	while (token == T_LP) {
		char *cmd;

D 8
		(void) s_gettok();
E 8
D 4
		switch (v->v_type) {
		case V_STR:
			cmd = v->v_str;
			break;
		case V_ERR:
			flag = 0;
			cmd = 0;
			break;
		case V_NUM:
			if ((cmd = str_itoa(v->v_num)) == 0) {
				p_memerror();
				return -1;
			}
			break;
		}
#ifdef DEBUG
		error("expr12: function %s.", cmd);
#endif
E 4
I 4
		if (p_convstr(v) < 0)
			return -1;
		cmd = v->v_type == V_STR ? v->v_str : 0;
E 4
		if (p_function(cmd, v, flag) < 0) {
D 3
			str_free(cmd);
E 3
I 3
			if (cmd)
				str_free(cmd);
E 3
			return -1;
		}
D 3
		str_free(cmd);
E 3
I 3
		if (cmd)
			str_free(cmd);
E 3
D 8
		if (token != T_RP) {
			p_synerror();
			val_free(*v);
			return -1;
		}
		(void) s_gettok();
E 8
	}
	return 0;
}
E 1

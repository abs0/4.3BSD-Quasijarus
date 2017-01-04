h15499
s 00010/00005/00193
d D 3.20 88/06/29 21:36:17 bostic 21 20
c install approved copyright notice
e
s 00013/00007/00185
d D 3.19 88/02/21 13:37:15 bostic 20 19
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00186
d D 3.18 85/04/24 16:19:34 edward 19 18
c copyright messages
e
s 00002/00007/00184
d D 3.17 85/04/03 20:39:11 edward 18 17
c removed some compatibility with old window, and some clean up
e
s 00001/00001/00190
d D 3.16 84/07/13 23:36:47 edward 17 16
c fixed error messages
e
s 00001/00001/00190
d D 3.15 84/05/23 01:59:57 edward 16 15
c new sccs id
e
s 00008/00049/00183
d D 3.14 84/05/06 17:54:33 edward 15 14
c alias macros
e
s 00006/00003/00226
d D 3.13 84/04/06 21:48:00 edward 14 13
c fixed freeing of null string pointers
e
s 00014/00000/00215
d D 3.12 84/04/05 16:52:02 edward 13 12
c string operators, +, <<, >>
e
s 00001/00726/00214
d D 3.11 84/01/12 12:44:00 edward 12 11
c broken up into pieces
e
s 00006/00005/00934
d D 3.10 84/01/12 12:39:23 edward 11 10
c bug with c == 0 and argument is *
e
s 00016/00017/00923
d D 3.9 84/01/12 11:44:38 edward 10 9
c p_valfree() changed to val_free() in value.h
e
s 00002/00001/00938
d D 3.8 84/01/11 17:41:07 edward 9 7
c should free token_str if not used
e
s 00002/00001/00938
d R 3.8 84/01/11 17:26:35 edward 8 7
c must free token_str if not used.
e
s 00001/00000/00938
d D 3.7 84/01/05 17:39:20 edward 7 6
c set V_ERR before calling functions, in p_function
e
s 00036/00028/00902
d D 3.6 83/12/12 14:46:56 edward 6 5
c make p_function() accept * as default argument
e
s 00067/00007/00863
d D 3.5 83/12/09 12:23:31 edward 5 4
c print operator name for binary expression errors.
c map * into "*".
e
s 00017/00018/00853
d D 3.4 83/12/06 12:57:45 edward 4 3
c binary op bug
e
s 00016/00006/00855
d D 3.3 83/11/23 11:16:24 edward 3 2
c some more p_function bugs
e
s 00010/00007/00851
d D 3.2 83/11/22 19:56:25 edward 2 1
c misc bugs
e
s 00858/00000/00000
d D 3.1 83/11/22 12:47:58 edward 1 0
c date and time created 83/11/22 12:47:58 by edward
e
u
U
t
T
I 1
D 20
#ifndef lint
D 16
static	char *sccsid = "%W% %E%";
E 16
I 16
static char sccsid[] = "%W% %G%";
E 16
#endif

E 20
I 19
/*
D 20
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 20
I 20
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
 */
I 20

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 20

E 19
D 12
#include <stdio.h>
#include "value.h"
#include "context.h"
#include "token.h"
#include "string.h"
#include "lcmd.h"
#include "var.h"
E 12
I 12
#include "parser.h"
E 12

D 12
#define p_erred()	(cx.x_erred)
I 6
#define p_synerred()	(cx.x_synerred)
E 6
#define p_clearerr()	(cx.x_erred = cx.x_synerred = 0)
#define p_abort()	(cx.x_abort)
D 6
#define p_varfree(v)	if ((v).v_type == V_STR) str_free((v).v_str)
E 6
I 6
D 10
#define p_valfree(v)	if ((v).v_type == V_STR) str_free((v).v_str)
E 10
E 6

E 12
p_start()
{
	char flag = 1;

	(void) s_gettok();
	for (;;) {
		p_statementlist(flag);
		if (token == T_EOF || p_abort())
			break;
		flag = 0;
		p_synerror();
		while (token != T_EOL && token != T_EOF) {
			if (token == T_STR)
				str_free(token_str);
			(void) s_gettok();
		}
		if (token == T_EOL)
			(void) s_gettok();
		p_clearerr();
	}
}

p_statementlist(flag)
char flag;
{
D 2
	for (;;) {
		if (p_statement(flag) < 0)
			return -1;
		p_clearerr();
	}
E 2
I 2
	for (; p_statement(flag) >= 0; p_clearerr())
		;
E 2
}

p_statement(flag)
char flag;
{
D 15
#ifdef DEBUG
	error("statement: %d.", flag);
#endif
E 15
	switch (token) {
	case T_EOL:
D 15
#ifdef DEBUG
		error("statement: EOL.", flag);
#endif
E 15
		(void) s_gettok();
		return 0;
	case T_IF:
D 15
#ifdef DEBUG
		error("statement: IF.", flag);
#endif
E 15
		return p_if(flag);
	default:
D 15
#ifdef DEBUG
		error("statement: command.", flag);
#endif
E 15
D 18
		return p_command(flag);
E 18
I 18
		return p_expression(flag);
E 18
	}
}

p_if(flag)
char flag;
{
	struct value t;
	char true = 0;

top:
	(void) s_gettok();

	if (p_expr(&t, flag) < 0) {
		p_synerror();
		return -1;
	}
	switch (t.v_type) {
	case V_NUM:
		true = !true && t.v_num != 0;
		break;
	case V_STR:
D 17
		p_error("Numeric value required for if.");
E 17
I 17
		p_error("if: Numeric value required.");
E 17
		str_free(t.v_str);
	case V_ERR:
		flag = 0;
		break;
	}

	if (token != T_THEN) {
		p_synerror();
		return -1;
	}

	(void) s_gettok();
	p_statementlist(flag && true);
	if (p_erred())
		return -1;

	if (token == T_ELSIF)
		goto top;

	if (token == T_ELSE) {
		(void) s_gettok();
		p_statementlist(flag && !true);
		if (p_erred())
			return -1;
	}

	if (token == T_ENDIF) {
		(void) s_gettok();
		return 0;
	}

	p_synerror();
	return -1;
}

D 18
p_command(flag)
E 18
I 18
p_expression(flag)
E 18
char flag;
{
	struct value t;
	char *cmd;
I 15
	int p_function(), p_assign();
E 15

D 15
#ifdef DEBUG
	error("command: %d.", flag);
#endif
E 15
	switch (token) {
D 18
	case T_MOD:
		t.v_type = V_STR;
D 5
		t.v_str = "%";
E 5
I 5
		t.v_str = str_cpy("%");
E 5
		(void) s_gettok();
		break;
E 18
	case T_NUM:
		t.v_type = V_NUM;
		t.v_num = token_num;
		(void) s_gettok();
		break;
	case T_STR:
		t.v_type = V_STR;
		t.v_str = token_str;
		(void) s_gettok();
		break;
	default:
		if (p_expr(&t, flag) < 0)
			return -1;
		if (token == T_EOF) {
D 15
#ifdef DEBUG
			error("command: expression.");
#endif
E 15
D 6
			p_varfree(t);
E 6
I 6
D 10
			p_valfree(t);
E 10
I 10
			val_free(t);
E 10
E 6
			return 0;
		}
	}
D 15
	switch (t.v_type) {
	case V_ERR:
		cmd = 0;
		break;
	case V_STR:
		cmd = t.v_str;
		break;
	case V_NUM:
		if ((cmd = str_itoa(t.v_num)) == 0) {
			p_memerror();
			return -1;
		}
	}
	if (token == T_ASSIGN) {
#ifdef DEBUG
		error("command: assignment %s.", cmd == 0 ? "ERR" : cmd);
#endif
		if (p_assign(cmd, &t, flag) < 0) {
D 14
			str_free(cmd);
E 14
I 14
			if (cmd)
				str_free(cmd);
E 14
			return -1;
		}
	} else {
#ifdef DEBUG
		error("command: function %s.", cmd == 0 ? "ERR" : cmd);
#endif
		if (p_function(cmd, &t, flag) < 0) {
D 14
			str_free(cmd);
E 14
I 14
			if (cmd)
				str_free(cmd);
E 14
			return -1;
		}
E 15
I 15
	if (token != T_ASSIGN && p_convstr(&t) < 0)
		return -1;
	cmd = t.v_type == V_STR ? t.v_str : 0;
	if ((*(token == T_ASSIGN ? p_assign : p_function))(cmd, &t, flag) < 0) {
		if (cmd)
			str_free(cmd);
		return -1;
E 15
	}
D 14
	str_free(cmd);
E 14
I 14
	if (cmd)
		str_free(cmd);
E 14
D 6
	p_varfree(t);
E 6
I 6
D 10
	p_valfree(t);
E 10
I 10
	val_free(t);
E 10
E 6
	if (token == T_EOL)
		(void) s_gettok();
	else if (token != T_EOF) {
		p_synerror();
		return -1;
D 12
	}
	return 0;
}

/*
 * name == 0 means we don't have a function name but
 * want to parse the arguments anyway.  flag == 0 in this case.
 */
p_function(name, v, flag)
char *name;
register struct value *v;
{
	struct value t;
	register struct lcmd_tab *c;
	register struct lcmd_arg *ap;
	register i;

	if (name != 0) {
		if ((c = lcmd_lookup(name)) == 0) {
			p_error("%s: No such command.", name);
			flag = 0;
		}
	} else
		c = 0;

	if (c != 0)
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
			ap->arg_val.v_type = V_ERR;

	for (i = 0;;) {
		ap = 0;
		if (p_expr0(&t, flag) < 0)
D 6
			break;
E 6
I 6
			if (!p_synerred() && token == T_MUL) {
D 11
				if (c->lc_arg[i].arg_name == 0)
					p_error("%s: Too many arguments.",
						c->lc_name);
				else
					i++;
E 11
I 11
				if (c != 0)
					if (c->lc_arg[i].arg_name == 0)
						p_error("%s: Too many arguments.", c->lc_name);
					else
						i++;
E 11
				(void) s_gettok();
				continue;
			} else
				break;
E 6
		if (t.v_type == V_ERR)
			flag = 0;
		if (token != T_ASSIGN) {
			if (c != 0) {
				ap = &c->lc_arg[i];
				if (ap->arg_name == 0) {
D 3
					p_error("Too many arguments.");
E 3
I 3
					p_error("%s: Too many arguments.",
						c->lc_name);
E 3
D 6
					p_varfree(t);
E 6
I 6
D 10
					p_valfree(t);
E 10
I 10
					val_free(t);
E 10
E 6
					ap = 0;
					flag = 0;
				} else
					i++;
			}
		} else {
			char *tmp;
			switch (t.v_type) {
			case V_ERR:
				tmp = 0;
				break;
			case V_NUM:
				if ((tmp = str_itoa(t.v_num)) == 0) {
					p_memerror();
					goto abort;
				}
				break;
			case V_STR:
				tmp = t.v_str;
				break;
			}
			(void) s_gettok();
			if (p_expr(&t, flag) < 0) {
				if (tmp)
					str_free(tmp);
				p_synerror();
				goto abort;
			}
			if (t.v_type == V_ERR)
				flag = 0;
			if (tmp) {
I 11
				/* we know c != 0 */
E 11
				for (ap = c->lc_arg; ap->arg_name != 0; ap++)
					if (str_match(tmp, ap->arg_name,
							ap->arg_minlen))
						break;
				if (ap->arg_name == 0) {
D 3
					p_error("%s: Unknown argument.", tmp);
E 3
I 3
					p_error("%s: Unknown argument \"%s\".",
						c->lc_name, tmp);
E 3
D 6
					p_varfree(t);
E 6
I 6
D 10
					p_valfree(t);
E 10
I 10
					val_free(t);
E 10
E 6
					flag = 0;
					ap = 0;
				}
				str_free(tmp);
			}
		}
		if (ap != 0) {
D 2
			if (ap->arg_type == ARG_NUM && t.v_type != V_NUM
E 2
I 2
			if (ap->arg_val.v_type != V_ERR) {
D 3
				p_error("Argument %d (%s) multiply specified.",
					ap - c->lc_arg + 1, ap->arg_name);
E 3
I 3
				p_error("%s: Argument %d (%s) duplicated.",
					c->lc_name, ap - c->lc_arg + 1,
					ap->arg_name);
E 3
D 6
				p_varfree(t);
E 6
I 6
D 10
				p_valfree(t);
E 10
I 10
				val_free(t);
E 10
E 6
				flag = 0;
I 3
			} else if (t.v_type == V_ERR) {
				/* do nothing */
E 3
			} else if (ap->arg_type == ARG_NUM && t.v_type != V_NUM
E 2
			    || ap->arg_type == ARG_STR && t.v_type != V_STR) {
D 2
				p_error("%s: Argument type mismatch.", t.v_str);
E 2
I 2
D 3
				p_error("Argument %d (%s) type mismatch.",
					ap - c->lc_arg + 1, ap->arg_name);
E 3
I 3
				p_error("%s: Argument %d (%s) type mismatch.",
					c->lc_name, ap - c->lc_arg + 1,
					ap->arg_name);
E 3
E 2
D 6
				p_varfree(t);
E 6
I 6
D 10
				p_valfree(t);
E 10
I 10
				val_free(t);
E 10
E 6
				flag = 0;
			} else
				ap->arg_val = t;
		}
		if (token == T_COMMA)
			(void) s_gettok();
	}

I 3
	if (p_erred())
		flag = 0;
	if (token != T_RP && token != T_EOL && token != T_EOF)
		flag = 0;		/* look ahead a bit */
I 7
	v->v_type = V_ERR;
E 7
E 3
	if (flag)
		(*c->lc_func)(v);
	if (c != 0)
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
D 6
			p_varfree(ap->arg_val);
E 6
I 6
D 10
			p_valfree(ap->arg_val);
E 10
I 10
			val_free(ap->arg_val);
E 10
E 6
	return 0;
abort:
	if (c != 0)
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
D 6
			p_varfree(ap->arg_val);
E 6
I 6
D 10
			p_valfree(ap->arg_val);
E 10
I 10
			val_free(ap->arg_val);
E 10
E 6
	return -1;
}

p_assign(name, v, flag)
char *name;
struct value *v;
char flag;
{
	(void) s_gettok();

	if (p_expr(v, flag) < 0) {
		p_synerror();
		return -1;
	}
	switch (v->v_type) {
	case V_STR:
	case V_NUM:
		if (flag && var_set(name, v) == 0) {
			p_memerror();
D 6
			p_varfree(*v);
E 6
I 6
D 10
			p_valfree(*v);
E 10
I 10
			val_free(*v);
E 10
E 6
			return -1;
		}
		break;
	}
	return 0;
}

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

#ifdef DEBUG
	error("expr: %d.", flag);
#endif
	if (p_expr0(&t, flag) < 0)
		return -1;

	if (token != T_ASSIGN) {
		*v = t;
		return 0;
	}
	switch (t.v_type) {
	case V_ERR:
		t.v_str = 0;
		break;
	case V_NUM:
		if ((t.v_str = str_itoa(t.v_num)) == 0) {
			p_memerror();
			return -1;
		}
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
I 4
	struct value t;
E 4
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
		p_error("Numeric value required for ?.");
		str_free(v->v_str);
		v->v_type = V_ERR;
	case V_ERR:
		flag = 0;
		break;
	}
	(void) s_gettok();
I 6
	v->v_type = V_ERR;
E 6
D 4
	if (p_expr1(v, flag && true) < 0)
E 4
I 4
	if ((flag && true ? p_expr1(v, 1) : p_expr1(&t, 0)) < 0)
E 4
		return -1;
	if (token != T_COLON) {
I 6
D 10
		p_valfree(*v);
E 10
I 10
		val_free(*v);
E 10
E 6
		p_synerror();
		return -1;
	}
	(void) s_gettok();
D 4
	return p_expr1(v, flag && !true);
E 4
I 4
	return flag && !true ? p_expr1(v, 1) : p_expr1(&t, 0);
E 4
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
			p_error("Numeric value required for ||.");
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
			p_error("Numeric value required for &&.");
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

/*
 * |		3
 * ^		4
 * &		5
 * == !=	6
 * < <= > >=	7
 * << >>	8
 * + -		9
 * * / %	10
 */
p_expr3_10(level, v, flag)
register struct value *v;
char flag;
{
	struct value t;
	int op;
I 5
	char *opname;
E 5

	if (level == 10) {
		if (p_expr11(v, flag) < 0)
			return -1;
	} else {
		if (p_expr3_10(level + 1, v, flag) < 0)
			return -1;
	}
	for (;;) {
		switch (level) {
		case 3:
			if (token != T_OR)
				return 0;
I 5
			opname = "|";
E 5
			break;
		case 4:
			if (token != T_XOR)
				return 0;
I 5
			opname = "^";
E 5
			break;
		case 5:
			if (token != T_AND)
				return 0;
I 5
			opname = "&";
E 5
			break;
		case 6:
D 5
			if (token != T_EQ && token != T_NE)
E 5
I 5
			if (token == T_EQ)
				opname = "==";
			else if (token == T_NE)
				opname = "!=";
			else
E 5
				return 0;
			break;
		case 7:
			switch (token) {
			case T_LT:
I 5
				opname = "<";
				break;
E 5
			case T_LE:
I 5
				opname = "<=";
				break;
E 5
			case T_GT:
I 5
				opname = ">";
				break;
E 5
			case T_GE:
I 5
				opname = ">=";
E 5
				break;
			default:
				return 0;
			}
			break;
		case 8:
D 5
			if (token != T_LS && token != T_RS)
E 5
I 5
			if (token == T_LS)
				opname = "<<";
			else if (token == T_RS)
				opname = ">>";
			else
E 5
				return 0;
			break;
		case 9:
D 5
			if (token != T_PLUS && token != T_MINUS)
E 5
I 5
			if (token == T_PLUS)
				opname = "+";
			else if (token == T_MINUS)
				opname = "-";
			else
E 5
				return 0;
			break;
		case 10:
			switch (token) {
			case T_MUL:
I 5
				opname = "*";
				break;
E 5
			case T_DIV:
I 5
				opname = "/";
				break;
E 5
			case T_MOD:
I 5
				opname = "%";
E 5
				break;
			default:
				return 0;
			}
			break;
		}
		if (v->v_type == V_ERR)
			flag = 0;

		op = token;
		(void) s_gettok();
		if (level == 10) {
D 6
			if (p_expr11(&t, flag) < 0)
E 6
I 6
			if (p_expr11(&t, flag) < 0) {
				p_synerror();
D 10
				p_valfree(*v);
E 10
I 10
				val_free(*v);
E 10
E 6
				return -1;
I 6
			}
E 6
		} else {
D 6
			if (p_expr3_10(level + 1, &t, flag) < 0)
E 6
I 6
			if (p_expr3_10(level + 1, &t, flag) < 0) {
				p_synerror();
D 10
				p_valfree(*v);
E 10
I 10
				val_free(*v);
E 10
E 6
				return -1;
I 6
			}
E 6
		}
D 4
		if (t.v_type == V_ERR) {
			flag = 0;
			v->v_type = V_ERR;
		}
E 4

D 4
		if (!flag)
			return 0;

		if (t.v_type != v->v_type) {
E 4
I 4
		if (t.v_type == V_ERR)
			flag = 0;
		else if (t.v_type != v->v_type) {
E 4
			p_error("Type mismatch.");
D 4
			v->v_type = V_ERR;
			return 0;
		}
		switch (op) {
E 4
I 4
			flag = 0;
		} else switch (op) {
E 4
		case T_EQ:
		case T_NE:
		case T_LT:
		case T_LE:
		case T_GT:
		case T_GE:
			if (v->v_type == V_STR) {
				int tmp;
				tmp = strcmp(v->v_str, t.v_str);
				str_free(v->v_str);
				str_free(t.v_str);
				v->v_type = V_NUM;
				v->v_num = tmp;
				t.v_num = 0;
			}
			break;
		default:
			if (v->v_type == V_STR) {
D 5
				p_error("Numeric value required.");
E 5
I 5
				p_error("Numeric value required for %s.",
					opname);
E 5
D 4
				str_free(v->v_str);
				str_free(t.v_str);
				v->v_type = V_ERR;
				return 0;
E 4
I 4
				flag = 0;
E 4
			}
		}
I 4

		if (!flag) {
D 6
			p_varfree(*v);
			p_varfree(t);
E 6
I 6
D 10
			p_valfree(*v);
			p_valfree(t);
E 10
I 10
			val_free(*v);
			val_free(t);
E 10
E 6
			v->v_type = V_ERR;
			continue;
		}

E 4
		switch (op) {
		case T_OR:
			v->v_num |= t.v_num;
			break;
		case T_XOR:
			v->v_num ^= t.v_num;
			break;
		case T_AND:
			v->v_num &= t.v_num;
			break;
		case T_EQ:
			v->v_num = v->v_num == t.v_num;
			break;
		case T_NE:
			v->v_num = v->v_num != t.v_num;
			break;
		case T_LT:
			v->v_num = v->v_num < t.v_num;
			break;
		case T_LE:
			v->v_num = v->v_num <= t.v_num;
			break;
		case T_GT:
			v->v_num = v->v_num > t.v_num;
			break;
		case T_GE:
			v->v_num = v->v_num >= t.v_num;
			break;
		case T_LS:
			v->v_num <<= t.v_num;
			break;
		case T_RS:
			v->v_num >>= t.v_num;
			break;
		case T_PLUS:
			v->v_num += t.v_num;
			break;
		case T_MINUS:
			v->v_num -= t.v_num;
			break;
		case T_MUL:
			v->v_num *= t.v_num;
			break;
		case T_DIV:
			v->v_num /= t.v_num;
			break;
		case T_MOD:
			v->v_num %= t.v_num;
			break;
		}
	}
	/*NOTREACHED*/
}

/*
 * unary $ + - ! ~
 */
p_expr11(v, flag)
register struct value *v;
char flag;
{
	int op;
I 5
	char *opname;
E 5

	switch (token) {
	case T_DOLLAR:
I 5
		opname = "$";
		break;
E 5
	case T_PLUS:
I 5
		opname = "unary +";
		break;
E 5
	case T_MINUS:
I 5
		opname = "unary -";
		break;
E 5
	case T_NOT:
I 5
		opname = "!";
		break;
E 5
	case T_COMP:
I 5
		opname = "~";
E 5
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
		if (op == T_DOLLAR && (v->v_str = str_itoa(v->v_num)) == 0) {
			p_memerror();
			return -1;
		}
		break;
	case V_STR:
		switch (op) {
		case T_MINUS:
		case T_NOT:
		case T_COMP:
D 5
			p_error("Numeric value required.");
E 5
I 5
			p_error("Numeric value required for %s.", opname);
E 5
			str_free(v->v_str);
			v->v_type = V_ERR;
			return 0;
		}
		break;
	case V_ERR:
		return 0;
	}
	switch (op) {
	case T_DOLLAR: {
		struct var *r;
		if ((r = var_lookup(v->v_str)) == 0) {
			p_error("%s: Undefined variable.", v->v_str);
			str_free(v->v_str);
			v->v_type = V_ERR;
			return 0;
		}
		str_free(v->v_str);
		if (flag) {
			*v = r->r_val;
			if (v->v_type == V_STR
			    && (v->v_str = str_cpy(v->v_str)) == 0) {
				p_memerror();
				return -1;
			}
		}
		break;
		}
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
D 5
 * plus function calls.
E 5
I 5
 * Plus function calls.
D 6
 * Also we map * and % into strings.
E 6
I 6
 * Also we map % into string.
E 6
E 5
 *
 * Always return v_type == V_ERR when flag == 0.
 */
p_expr12(v, flag)
register struct value *v;
char flag;
{
	v->v_type = V_ERR;
#ifdef DEBUG
	error("expr12: %d.", flag);
#endif
	switch (token) {
I 5
D 6
	case T_MUL:
#ifdef DEBUG
		error("expr12: *.");
#endif
		if (flag) {
			v->v_type = V_STR;
			v->v_str = str_cpy("*");
		}
		(void) s_gettok();
		break;
E 6
	case T_MOD:
#ifdef DEBUG
		error("expr12: %.");
#endif
		if (flag) {
			v->v_type = V_STR;
			v->v_str = str_cpy("%");
		}
		(void) s_gettok();
		break;
E 5
	case T_NUM:
#ifdef DEBUG
		error("expr12: NUM %d.", token_num);
#endif
		if (flag) {
			v->v_type = V_NUM;
			v->v_num = token_num;
		}
		(void) s_gettok();
		break;
	case T_STR:
#ifdef DEBUG
		error("expr12: STR %s.", token_str);
#endif
		if (flag) {
			v->v_type = V_STR;
			v->v_str = token_str;
D 9
		}
E 9
I 9
		} else
			str_free(token_str);
E 9
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
D 6
			p_varfree(*v);
E 6
I 6
D 10
			p_valfree(*v);
E 10
I 10
			val_free(*v);
E 10
E 6
			return -1;
		}
		(void) s_gettok();
		break;
	default:
#ifdef DEBUG
		error("expr12: token %d.", token);
#endif
		return -1;
	}
	while (token == T_LP) {
		char *cmd;

		(void) s_gettok();
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
		if (p_function(cmd, v, flag) < 0) {
			str_free(cmd);
			return -1;
		}
		str_free(cmd);
		if (token != T_RP) {
			p_synerror();
D 6
			p_varfree(*v);
E 6
I 6
D 10
			p_valfree(*v);
E 10
I 10
			val_free(*v);
E 10
E 6
			return -1;
		}
		(void) s_gettok();
E 12
	}
	return 0;
}

I 13
p_convstr(v)
register struct value *v;
{
	if (v->v_type != V_NUM)
		return 0;
	if ((v->v_str = str_itoa(v->v_num)) == 0) {
		p_memerror();
		v->v_type = V_ERR;
		return -1;
	}
	v->v_type = V_STR;
	return 0;
}

E 13
p_synerror()
{
	if (!cx.x_synerred) {
		cx.x_synerred = cx.x_erred = 1;
		error("Syntax error.");
	}
}

/*VARARGS1*/
p_error(msg, a, b, c)
char *msg;
{
	if (!cx.x_erred) {
		cx.x_erred = 1;
		error(msg, a, b, c);
	}
}

p_memerror()
{
	cx.x_erred = cx.x_abort = 1;
	error("Out of memory.");
}
E 1

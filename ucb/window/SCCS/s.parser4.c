h40063
s 00010/00005/00267
d D 3.6 88/06/29 21:36:23 bostic 6 5
c install approved copyright notice
e
s 00013/00007/00259
d D 3.5 88/02/21 13:37:20 bostic 5 4
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00260
d D 3.4 85/04/24 16:22:25 edward 4 3
c copyright messages
e
s 00001/00001/00259
d D 3.3 84/05/23 02:00:43 edward 3 2
c new sccs id
e
s 00100/00055/00160
d D 3.2 84/04/05 16:52:19 edward 2 1
c string operators, +, <<, >>
e
s 00215/00000/00000
d D 3.1 84/01/12 12:43:02 edward 1 0
c date and time created 84/01/12 12:43:02 by edward
e
u
U
t
T
I 1
D 5
#ifndef lint
D 3
static	char *sccsid = "%W% %E%";
E 3
I 3
static char sccsid[] = "%W% %G%";
E 3
#endif

E 5
I 4
/*
D 5
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */
I 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

E 4
#include "parser.h"

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
D 2
	struct value t;
E 2
I 2
	struct value l, r;
E 2
	int op;
	char *opname;

D 2
	if (level == 10) {
		if (p_expr11(v, flag) < 0)
			return -1;
	} else {
		if (p_expr3_10(level + 1, v, flag) < 0)
			return -1;
	}
E 2
I 2
	if ((level == 10 ? p_expr11(v, flag)
	     : p_expr3_10(level + 1, v, flag)) < 0)
		return -1;
E 2
	for (;;) {
		switch (level) {
		case 3:
			if (token != T_OR)
				return 0;
			opname = "|";
			break;
		case 4:
			if (token != T_XOR)
				return 0;
			opname = "^";
			break;
		case 5:
			if (token != T_AND)
				return 0;
			opname = "&";
			break;
		case 6:
			if (token == T_EQ)
				opname = "==";
			else if (token == T_NE)
				opname = "!=";
			else
				return 0;
			break;
		case 7:
			switch (token) {
			case T_LT:
				opname = "<";
				break;
			case T_LE:
				opname = "<=";
				break;
			case T_GT:
				opname = ">";
				break;
			case T_GE:
				opname = ">=";
				break;
			default:
				return 0;
			}
			break;
		case 8:
			if (token == T_LS)
				opname = "<<";
			else if (token == T_RS)
				opname = ">>";
			else
				return 0;
			break;
		case 9:
			if (token == T_PLUS)
				opname = "+";
			else if (token == T_MINUS)
				opname = "-";
			else
				return 0;
			break;
		case 10:
			switch (token) {
			case T_MUL:
				opname = "*";
				break;
			case T_DIV:
				opname = "/";
				break;
			case T_MOD:
				opname = "%";
				break;
			default:
				return 0;
			}
			break;
		}
D 2
		if (v->v_type == V_ERR)
E 2
I 2
		l = *v;
		if (l.v_type == V_ERR)
E 2
			flag = 0;

		op = token;
		(void) s_gettok();
D 2
		if (level == 10) {
			if (p_expr11(&t, flag) < 0) {
				p_synerror();
				val_free(*v);
				return -1;
			}
		} else {
			if (p_expr3_10(level + 1, &t, flag) < 0) {
				p_synerror();
				val_free(*v);
				return -1;
			}
E 2
I 2
		if ((level == 10 ? p_expr11(&r, flag)
		     : p_expr3_10(level + 1, &r, flag)) < 0) {
			p_synerror();
			val_free(l);
			return -1;
E 2
		}

D 2
		if (t.v_type == V_ERR)
E 2
I 2
		if (r.v_type == V_ERR)
E 2
			flag = 0;
D 2
		else if (t.v_type != v->v_type) {
			p_error("Type mismatch.");
			flag = 0;
		} else switch (op) {
E 2
I 2
		else switch (op) {
E 2
		case T_EQ:
		case T_NE:
		case T_LT:
		case T_LE:
		case T_GT:
		case T_GE:
D 2
			if (v->v_type == V_STR) {
				int tmp;
				tmp = strcmp(v->v_str, t.v_str);
				str_free(v->v_str);
				str_free(t.v_str);
				v->v_type = V_NUM;
				v->v_num = tmp;
				t.v_num = 0;
E 2
I 2
		case T_PLUS:
			if (l.v_type == V_STR) {
				if (r.v_type == V_NUM)
					if (p_convstr(&r) < 0)
						flag = 0;
			} else
				if (r.v_type == V_STR)
					if (p_convstr(&l) < 0)
						flag = 0;
			break;
		case T_LS:
		case T_RS:
			if (r.v_type == V_STR) {
				char *p = r.v_str;
				r.v_type = V_NUM;
				r.v_num = strlen(p);
				str_free(p);
E 2
			}
			break;
I 2
		case T_OR:
		case T_XOR:
		case T_AND:
		case T_MINUS:
		case T_MUL:
		case T_DIV:
		case T_MOD:
E 2
		default:
D 2
			if (v->v_type == V_STR) {
				p_error("Numeric value required for %s.",
E 2
I 2
			if (l.v_type == V_STR || r.v_type == V_STR) {
				p_error("%s: Numeric operands required.",
E 2
					opname);
				flag = 0;
			}
		}
D 2

E 2
		if (!flag) {
D 2
			val_free(*v);
			val_free(t);
E 2
I 2
			val_free(l);
			val_free(r);
E 2
			v->v_type = V_ERR;
I 2
			if (p_abort())
				return -1;
E 2
			continue;
		}

I 2
		v->v_type = V_NUM;
E 2
		switch (op) {
I 2
		case T_EQ:
		case T_NE:
		case T_LT:
		case T_LE:
		case T_GT:
		case T_GE:
			if (l.v_type == V_STR) {
				int tmp = strcmp(l.v_str, r.v_str);
				str_free(l.v_str);
				str_free(r.v_str);
				l.v_type = V_NUM;
				l.v_num = tmp;
				r.v_type = V_NUM;
				r.v_num = 0;
			}
			break;
		}
		switch (op) {
E 2
		case T_OR:
D 2
			v->v_num |= t.v_num;
E 2
I 2
			v->v_num = l.v_num | r.v_num;
E 2
			break;
		case T_XOR:
D 2
			v->v_num ^= t.v_num;
E 2
I 2
			v->v_num = l.v_num ^ r.v_num;
E 2
			break;
		case T_AND:
D 2
			v->v_num &= t.v_num;
E 2
I 2
			v->v_num = l.v_num & r.v_num;
E 2
			break;
		case T_EQ:
D 2
			v->v_num = v->v_num == t.v_num;
E 2
I 2
			v->v_num = l.v_num == r.v_num;
E 2
			break;
		case T_NE:
D 2
			v->v_num = v->v_num != t.v_num;
E 2
I 2
			v->v_num = l.v_num != r.v_num;
E 2
			break;
		case T_LT:
D 2
			v->v_num = v->v_num < t.v_num;
E 2
I 2
			v->v_num = l.v_num < r.v_num;
E 2
			break;
		case T_LE:
D 2
			v->v_num = v->v_num <= t.v_num;
E 2
I 2
			v->v_num = l.v_num <= r.v_num;
E 2
			break;
		case T_GT:
D 2
			v->v_num = v->v_num > t.v_num;
E 2
I 2
			v->v_num = l.v_num > r.v_num;
E 2
			break;
		case T_GE:
D 2
			v->v_num = v->v_num >= t.v_num;
E 2
I 2
			v->v_num = l.v_num >= r.v_num;
E 2
			break;
		case T_LS:
D 2
			v->v_num <<= t.v_num;
E 2
I 2
			if (l.v_type == V_STR) {
				int i;
				if ((i = strlen(l.v_str)) > r.v_num)
					i = r.v_num;
				v->v_str = str_ncpy(l.v_str, i);
				v->v_type = V_STR;
			} else
				v->v_num = l.v_num << r.v_num;
E 2
			break;
		case T_RS:
D 2
			v->v_num >>= t.v_num;
E 2
I 2
			if (l.v_type == V_STR) {
				int i;
				if ((i = strlen(l.v_str)) > r.v_num)
					i -= r.v_num;
				else
					i = 0;
				v->v_str = str_cpy(l.v_str + i);
				v->v_type = V_STR;
			} else
				v->v_num = l.v_num >> r.v_num;
E 2
			break;
		case T_PLUS:
D 2
			v->v_num += t.v_num;
E 2
I 2
			if (l.v_type == V_STR) {
				v->v_str = str_cat(l.v_str, r.v_str);
				v->v_type = V_STR;
			} else
				v->v_num = l.v_num + r.v_num;
E 2
			break;
		case T_MINUS:
D 2
			v->v_num -= t.v_num;
E 2
I 2
			v->v_num = l.v_num - r.v_num;
E 2
			break;
		case T_MUL:
D 2
			v->v_num *= t.v_num;
E 2
I 2
			v->v_num = l.v_num * r.v_num;
E 2
			break;
		case T_DIV:
D 2
			v->v_num /= t.v_num;
E 2
I 2
			v->v_num = l.v_num / r.v_num;
E 2
			break;
		case T_MOD:
D 2
			v->v_num %= t.v_num;
E 2
I 2
			v->v_num = l.v_num % r.v_num;
E 2
			break;
		}
I 2
		val_free(l);
		val_free(r);
E 2
	}
	/*NOTREACHED*/
}
E 1

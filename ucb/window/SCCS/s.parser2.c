h01918
s 00010/00005/00202
d D 3.12 88/06/29 21:36:19 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00194
d D 3.11 88/02/21 13:37:17 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00195
d D 3.10 85/04/24 16:21:17 edward 11 10
c copyright messages
e
s 00015/00004/00180
d D 3.9 85/04/03 21:20:03 edward 10 8
c removed compatibility with old window, and some clean up
e
s 00015/00004/00180
d R 3.9 85/04/03 20:39:21 edward 9 8
c removed some compatibility with old window, and some clean up
e
s 00033/00027/00151
d D 3.8 84/07/12 13:38:52 edward 8 7
c new ARG_LIST flag for commands
e
s 00008/00002/00170
d D 3.7 84/06/02 18:04:36 edward 7 6
c catch recursive aliases
e
s 00001/00001/00171
d D 3.6 84/05/23 02:00:24 edward 6 5
c new sccs id
e
s 00056/00051/00116
d D 3.5 84/05/06 17:55:35 edward 5 4
c alias macros
e
s 00019/00021/00148
d D 3.4 84/04/06 21:35:18 edward 4 3
c "C" removed, varargs added for "write" and "close"
e
s 00014/00010/00155
d D 3.3 84/03/23 18:17:27 edward 3 2
c compile with -R
e
s 00002/00000/00163
d D 3.2 84/01/13 12:07:53 edward 2 1
c include var.h and lcmd.c only in some of the parser?.c
e
s 00163/00000/00000
d D 3.1 84/01/12 12:42:58 edward 1 0
c date and time created 84/01/12 12:42:58 by edward
e
u
U
t
T
I 1
D 12
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 12
I 11
/*
D 12
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 12
I 12
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */
I 12

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 12

E 11
#include "parser.h"
I 2
#include "var.h"
#include "lcmd.h"
I 5
#include "alias.h"
E 5
E 2

/*
 * name == 0 means we don't have a function name but
 * want to parse the arguments anyway.  flag == 0 in this case.
 */
p_function(name, v, flag)
char *name;
register struct value *v;
{
	struct value t;
D 5
	register struct lcmd_tab *c;
E 5
I 5
	register struct lcmd_tab *c = 0;
	register struct alias *a = 0;
E 5
D 8
	register struct lcmd_arg *ap;
E 8
I 8
	register struct lcmd_arg *ap;		/* this arg */
	struct lcmd_arg *lp = 0;		/* list arg */
E 8
	register i;
I 3
D 4
	struct value av[LCMD_NARG];
E 4
I 4
	struct value av[LCMD_NARG + 1];
E 4
	register struct value *vp;
E 3

D 5
	if (name != 0) {
		if ((c = lcmd_lookup(name)) == 0) {
			p_error("%s: No such command.", name);
E 5
I 5
	if (name != 0)
		if (c = lcmd_lookup(name))
			name = c->lc_name;
		else if (a = alias_lookup(name))
			name = a->a_name;
		else {
			p_error("%s: No such command or alias.", name);
E 5
			flag = 0;
		}
D 5
	} else
		c = 0;
E 5

D 5
	if (c != 0)
D 3
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
			ap->arg_val.v_type = V_ERR;
E 3
I 3
D 4
		for (vp = av; vp < &av[LCMD_NARG]; vp++)
E 4
I 4
		for (vp = av; vp < &av[LCMD_NARG + 1]; vp++)
E 4
			vp->v_type = V_ERR;
E 5
I 5
	for (vp = av; vp < &av[LCMD_NARG + 1]; vp++)
		vp->v_type = V_ERR;
E 5
E 3

D 8
	for (i = 0;;) {
		ap = 0;
I 5
		vp = 0;
E 5
		if (p_expr0(&t, flag) < 0)
			if (!p_synerred() && token == T_MUL) {
				if (c != 0)
					if (c->lc_arg[i].arg_name == 0)
D 5
						p_error("%s: Too many arguments.", c->lc_name);
E 5
I 5
						p_error("%s: Too many arguments.", name);
E 5
					else
						i++;
				(void) s_gettok();
				continue;
			} else
				break;
E 8
I 8
D 10
	for (i = 0; p_expr0(&t, flag) >= 0;) {
E 8
		if (t.v_type == V_ERR)
			flag = 0;
E 10
I 10
	if (token == T_LP)
		(void) s_gettok();
	i = 0;
	for (;;) {
E 10
I 8
		ap = 0;
		vp = 0;
I 10
		if (token == T_COMMA)		/* null argument */
			t.v_type = V_ERR;
		else {
			if (p_expr0(&t, flag) < 0)
				break;
			if (t.v_type == V_ERR)
				flag = 0;
		}
E 10
E 8
		if (token != T_ASSIGN) {
D 4
			if (c != 0) {
				ap = &c->lc_arg[i];
I 3
				vp = &av[i];
E 3
				if (ap->arg_name == 0) {
E 4
I 4
D 5
			if (c != 0)
				if (i >= LCMD_NARG || c->lc_arg != 0
				    && (ap = c->lc_arg + i)->arg_name == 0) {
E 4
					p_error("%s: Too many arguments.",
						c->lc_name);
D 4
					val_free(t);
E 4
					ap = 0;
I 4
					vp = 0;
E 4
					flag = 0;
				} else
D 4
					i++;
			}
E 4
I 4
					vp = &av[i++];
E 5
I 5
D 8
			if (i >= LCMD_NARG || c != 0 && c->lc_arg != 0
			    && (ap = c->lc_arg + i)->arg_name == 0) {
E 8
I 8
			if (i >= LCMD_NARG ||
			    c != 0 && (ap = lp) == 0 &&
			    (ap = c->lc_arg + i)->arg_name == 0) {
E 8
				p_error("%s: Too many arguments.", name);
				flag = 0;
			} else
				vp = &av[i++];
E 5
E 4
		} else {
			char *tmp;
D 5
			switch (t.v_type) {
			case V_ERR:
				tmp = 0;
				break;
			case V_NUM:
D 4
				if ((tmp = str_itoa(t.v_num)) == 0) {
					p_memerror();
E 4
I 4
				if (p_convstr(&t) < 0)
E 4
					goto abort;
D 4
				}
				break;
E 4
			case V_STR:
				tmp = t.v_str;
				break;
			}
E 5
I 5
			if (p_convstr(&t) < 0)
				goto abort;
			tmp = t.v_type == V_STR ? t.v_str : 0;
E 5
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
D 5
				/* we know c != 0 */
D 3
				for (ap = c->lc_arg; ap->arg_name != 0; ap++)
E 3
I 3
				for (ap = c->lc_arg, vp = av;
D 4
				     ap->arg_name != 0; ap++, vp++)
E 4
I 4
				     ap != 0 && ap->arg_name != 0; ap++, vp++)
E 4
E 3
					if (str_match(tmp, ap->arg_name,
							ap->arg_minlen))
						break;
D 4
				if (ap->arg_name == 0) {
E 4
I 4
				if (ap == 0 || ap->arg_name == 0) {
E 4
					p_error("%s: Unknown argument \"%s\".",
						c->lc_name, tmp);
E 5
I 5
				if (c == 0) {
					/* an aliase */
					p_error("%s: Bad alias syntax.", name);
E 5
D 4
					val_free(t);
E 4
					flag = 0;
D 5
					ap = 0;
I 4
					vp = 0;
E 5
I 5
				} else {
					for (ap = c->lc_arg, vp = av;
					     ap != 0 && ap->arg_name != 0 &&
D 8
						!str_match(tmp, ap->arg_name,
							ap->arg_minlen);
E 8
I 8
					     (*ap->arg_name == '\0' ||
					      !str_match(tmp, ap->arg_name,
							ap->arg_minlen));
E 8
					     ap++, vp++)
						;
					if (ap == 0 || ap->arg_name == 0) {
						p_error("%s: Unknown argument \"%s\".",
							name, tmp);
						flag = 0;
						ap = 0;
						vp = 0;
					}
E 5
E 4
				}
				str_free(tmp);
			}
		}
		if (ap != 0) {
I 8
			if (ap->arg_flags & ARG_LIST) {
				i = vp - av + 1;
				lp = ap;
			}
E 8
D 3
			if (ap->arg_val.v_type != V_ERR) {
E 3
I 3
			if (vp->v_type != V_ERR) {
E 3
D 8
				p_error("%s: Argument %d (%s) duplicated.",
D 5
					c->lc_name, ap - c->lc_arg + 1,
E 5
I 5
					name, ap - c->lc_arg + 1,
E 5
					ap->arg_name);
E 8
I 8
				if (*ap->arg_name)
					p_error("%s: Argument %d (%s) duplicated.",
						name, vp - av + 1,
						ap->arg_name);
				else
					p_error("%s: Argument %d duplicated.",
						name, vp - av + 1);
E 8
D 4
				val_free(t);
E 4
				flag = 0;
I 4
				vp = 0;
E 4
			} else if (t.v_type == V_ERR) {
				/* do nothing */
D 8
			} else if (ap->arg_type == ARG_NUM && t.v_type != V_NUM
			    || ap->arg_type == ARG_STR && t.v_type != V_STR) {
				p_error("%s: Argument %d (%s) type mismatch.",
D 5
					c->lc_name, ap - c->lc_arg + 1,
E 5
I 5
					name, ap - c->lc_arg + 1,
E 5
					ap->arg_name);
E 8
I 8
			} else if ((ap->arg_flags&ARG_TYPE) == ARG_NUM &&
				   t.v_type != V_NUM ||
				   (ap->arg_flags&ARG_TYPE) == ARG_STR &&
				   t.v_type != V_STR) {
				if (*ap->arg_name)
					p_error("%s: Argument %d (%s) type mismatch.",
						name, vp - av + 1,
						ap->arg_name);
				else
					p_error("%s: Argument %d type mismatch.",
						name, vp - av + 1);
E 8
D 4
				val_free(t);
E 4
				flag = 0;
D 4
			} else
D 3
				ap->arg_val = t;
E 3
I 3
				*vp = t;
E 4
I 4
				vp = 0;
			}
E 4
E 3
		}
I 4
		if (vp != 0)
			*vp = t;
		else
			val_free(t);
E 4
		if (token == T_COMMA)
			(void) s_gettok();
	}

	if (p_erred())
		flag = 0;
D 10
	if (token != T_RP && token != T_EOL && token != T_EOF)
E 10
I 10
	if (token == T_RP)
		(void) s_gettok();
	else if (token != T_EOL && token != T_EOF)
E 10
D 4
		flag = 0;		/* look ahead a bit */
E 4
I 4
		flag = 0;		/* look for legal follow set */
E 4
	v->v_type = V_ERR;
	if (flag)
D 3
		(*c->lc_func)(v);
E 3
I 3
D 5
		(*c->lc_func)(v, av);
E 3
	if (c != 0)
D 3
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
			val_free(ap->arg_val);
E 3
I 3
		for (vp = av; vp < &av[LCMD_NARG]; vp++)
			val_free(*vp);
E 5
I 5
		if (c != 0)
			(*c->lc_func)(v, av);
		else
D 7
			if (dolongcmd(a->a_buf, av, i) < 0)
				p_memerror();
E 7
I 7
			if (a->a_flags & A_INUSE)
				p_error("%s: Recursive alias.", a->a_name);
			else {
				a->a_flags |= A_INUSE;
				if (dolongcmd(a->a_buf, av, i) < 0)
					p_memerror();
				a->a_flags &= ~A_INUSE;
			}
E 7
	if (p_abort()) {
		val_free(*v);
		v->v_type = V_ERR;
		goto abort;
	}
	for (vp = av; vp < &av[LCMD_NARG]; vp++)
		val_free(*vp);
E 5
E 3
	return 0;
abort:
D 5
	if (c != 0)
D 3
		for (ap = c->lc_arg; ap->arg_name != 0; ap++)
			val_free(ap->arg_val);
E 3
I 3
		for (vp = av; vp < &av[LCMD_NARG]; vp++)
			val_free(*vp);
E 5
I 5
	for (vp = av; vp < &av[LCMD_NARG]; vp++)
		val_free(*vp);
E 5
E 3
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
			val_free(*v);
			return -1;
		}
		break;
	}
	return 0;
}
E 1

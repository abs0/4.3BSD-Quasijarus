h26790
s 00010/00005/00346
d D 3.15 88/06/29 21:36:06 bostic 16 15
c install approved copyright notice
e
s 00013/00007/00338
d D 3.14 88/02/21 13:37:03 bostic 15 14
c written by Edward Wang; attach Berkeley specific copyright
e
s 00005/00005/00340
d D 3.13 87/10/02 19:36:58 edward 14 13
c changes from mips!dce, most compatibility stuff
e
s 00001/00001/00344
d D 3.12 87/05/18 12:20:37 edward 13 12
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00339
d D 3.11 85/04/24 16:23:20 edward 12 11
c copyright messages
e
s 00002/00002/00337
d D 3.10 85/04/03 20:39:32 edward 11 10
c removed some compatibility with old window, and some clean up
e
s 00003/00002/00336
d D 3.9 84/11/20 23:18:16 edward 10 8
c lint
e
s 00001/00001/00337
d R 3.9 84/11/20 23:03:12 edward 9 8
c lint
e
s 00028/00000/00310
d D 3.8 84/07/19 17:34:55 edward 8 7
c the echo command
e
s 00039/00015/00271
d D 3.7 84/07/12 13:38:59 edward 7 6
c new ARG_LIST flag for commands
e
s 00001/00001/00285
d D 3.6 84/06/02 18:16:45 edward 6 5
c spelling
e
s 00001/00001/00285
d D 3.5 84/05/23 02:00:58 edward 5 4
c new sccs id
e
s 00063/00001/00223
d D 3.4 84/05/06 17:56:17 edward 4 3
c alias macros
e
s 00035/00001/00189
d D 3.3 84/04/08 19:23:47 edward 3 2
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00073/00005/00117
d D 3.2 84/04/07 00:02:25 edward 2 1
c l_variable and l_list added
e
s 00122/00000/00000
d D 3.1 84/04/05 17:34:40 edward 1 0
c date and time created 84/04/05 17:34:40 by edward
e
u
U
t
T
I 1
D 15
#ifndef lint
D 5
static	char *sccsid = "%W% %E%";
E 5
I 5
static char sccsid[] = "%W% %G%";
E 5
#endif

E 15
I 12
/*
D 15
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 15
I 15
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 16
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 16
I 16
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
E 16
E 15
 */
I 15

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 15

E 12
#include "defs.h"
#include "string.h"
#include "value.h"
I 2
#include "var.h"
E 2
#include "lcmd.h"
#include <sys/resource.h>
I 4
#include "alias.h"
E 4

D 2
struct lcmd_arg arg_iostat[] = {
	0
};

E 2
I 2
/*ARGSUSED*/
E 2
l_iostat(v, a)
struct value *v, *a;
{
	register struct ww *w;

	if ((w = openiwin(14, "IO Statistics")) == 0) {
		error("Can't open statistics window: %s.", wwerror());
		return;
	}
	wwprintf(w, "ttflush\twrite\terror\tzero\tchar\n");
	wwprintf(w, "%d\t%d\t%d\t%d\t%d\n",
		wwnflush, wwnwr, wwnwre, wwnwrz, wwnwrc);
D 6
	wwprintf(w, "wwwrite\tattmpt\tchar\n");
E 6
I 6
	wwprintf(w, "wwwrite\tattempt\tchar\n");
E 6
	wwprintf(w, "%d\t%d\t%d\n",
		wwnwwr, wwnwwra, wwnwwrc);
	wwprintf(w, "wwupdat\tline\tmiss\tmajor\tmiss\n");
	wwprintf(w, "%d\t%d\t%d\t%d\t%d\n",
		wwnupdate, wwnupdline, wwnupdmiss, wwnmajline, wwnmajmiss);
	wwprintf(w, "select\terror\tzero\n");
	wwprintf(w, "%d\t%d\t%d\n",
		wwnselect, wwnselecte, wwnselectz);
	wwprintf(w, "read\terror\tzero\tchar\n");
	wwprintf(w, "%d\t%d\t%d\t%d\n",
		wwnread, wwnreade, wwnreadz, wwnreadc);
	wwprintf(w, "ptyread\terror\tzero\tcontrol\tdata\tchar\n");
	wwprintf(w, "%d\t%d\t%d\t%d\t%d\t%d\n",
		wwnwread, wwnwreade, wwnwreadz,
		wwnwreadp, wwnwreadd, wwnwreadc);
	waitnl(w);
	closeiwin(w);
}

struct lcmd_arg arg_time[] = {
D 3
	{ "who",	1,	V_STR },
E 3
I 3
	{ "who",	1,	ARG_STR },
E 3
	0
};

I 2
/*ARGSUSED*/
E 2
l_time(v, a)
struct value *v;
register struct value *a;
{
	register struct ww *w;
	struct rusage rusage;
	struct timeval timeval;
D 2
	int flag;
E 2
	char *strtime();

	if ((w = openiwin(6, "Timing and Resource Usage")) == 0) {
		error("Can't open time window: %s.", wwerror());
		return;
	}

	(void) gettimeofday(&timeval, (struct timezone *)0);
	timeval.tv_sec -= starttime.tv_sec;
	if ((timeval.tv_usec -= starttime.tv_usec) < 0) {
		timeval.tv_sec--;
		timeval.tv_usec += 1000000;
	}
	(void) getrusage(a->v_type == V_STR
			&& str_match(a->v_str, "children", 1)
		? RUSAGE_CHILDREN : RUSAGE_SELF, &rusage);

	wwprintf(w, "time\t\tutime\t\tstime\t\tmaxrss\tixrss\tidrss\tisrss\n");
	wwprintf(w, "%-16s", strtime(&timeval));
	wwprintf(w, "%-16s", strtime(&rusage.ru_utime));
	wwprintf(w, "%-16s", strtime(&rusage.ru_stime));
D 14
	wwprintf(w, "%D\t%D\t%D\t%D\n",
E 14
I 14
	wwprintf(w, "%ld\t%ld\t%ld\t%ld\n",
E 14
		rusage.ru_maxrss, rusage.ru_ixrss,
		rusage.ru_idrss, rusage.ru_isrss);
	wwprintf(w, "minflt\tmajflt\tnswap\tinblk\toublk\tmsgsnd\tmsgrcv\tnsigs\tnvcsw\tnivcsw\n");
D 14
	wwprintf(w, "%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\t%D\n",
E 14
I 14
	wwprintf(w, "%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n",
E 14
		rusage.ru_minflt, rusage.ru_majflt, rusage.ru_nswap,
		rusage.ru_inblock, rusage.ru_oublock,
		rusage.ru_msgsnd, rusage.ru_msgrcv, rusage.ru_nsignals,
		rusage.ru_nvcsw, rusage.ru_nivcsw);

	waitnl(w);
	closeiwin(w);
}

char *
strtime(t)
register struct timeval *t;
{
	char fill = 0;
	static char buf[20];
	register char *p = buf;

	if (t->tv_sec > 60*60) {
D 14
		(void) sprintf(p, "%D:", t->tv_sec / (60*60));
E 14
I 14
		(void) sprintf(p, "%ld:", t->tv_sec / (60*60));
E 14
		while (*p++)
			;
		p--;
		t->tv_sec %= 60*60;
		fill++;
	}
	if (t->tv_sec > 60) {
D 14
		(void) sprintf(p, fill ? "%02D:" : "%D:", t->tv_sec / 60);
E 14
I 14
		(void) sprintf(p, fill ? "%02ld:" : "%ld:", t->tv_sec / 60);
E 14
		while (*p++)
			;
		p--;
		t->tv_sec %= 60;
		fill++;
	}
D 14
	(void) sprintf(p, fill ? "%02D.%02d" : "%D.%02D",
E 14
I 14
	(void) sprintf(p, fill ? "%02ld.%02d" : "%ld.%02ld",
E 14
		t->tv_sec, t->tv_usec / 10000);
	return buf;
I 2
}

/*ARGSUSED*/
l_list(v, a)
struct value *v, *a;
{
	register struct ww *w, *wp;
	register i;
	int n;

	for (n = 0, i = 0; i < NWINDOW; i++)
		if (window[i] != 0)
			n++;
	if (n == 0) {
		error("No windows.");
		return;
	}
	if ((w = openiwin(n + 2, "Windows")) == 0) {
		error("Can't open listing window: %s.", wwerror());
		return;
	}
	for (i = 0; i < NWINDOW; i++) {
		if ((wp = window[i]) == 0)
			continue;
		wwprintf(w, "%c %c %-13s %-.*s\n",
D 13
			wp == selwin ? '*' : ' ',
E 13
I 13
			wp == selwin ? '+' : (wp == lastselwin ? '-' : ' '),
E 13
			i + '1',
			wp->ww_state == WWS_HASPROC ? "" : "(No process)",
			wwncol - 20,
			wp->ww_label ? wp->ww_label : "(No label)");
	}
	waitnl(w);
	closeiwin(w);
}

/*ARGSUSED*/
l_variable(v, a)
struct value *v, *a;
{
	register struct ww *w;
	int printvar();

	if ((w = openiwin(wwnrow - 3, "Variables")) == 0) {
		error("Can't open variable window: %s.", wwerror());
		return;
	}
	if (var_walk(printvar, (int)w) >= 0)
		waitnl(w);
	closeiwin(w);
}

printvar(w, r)
register struct ww *w;
register struct var *r;
{
	if (more(w, 0) == 2)
		return -1;
D 4
	wwprintf(w, "%16s\t", r->r_name);
E 4
I 4
	wwprintf(w, "%16s    ", r->r_name);
E 4
	switch (r->r_val.v_type) {
	case V_STR:
		wwprintf(w, "%s\n", r->r_val.v_str);
		break;
	case V_NUM:
		wwprintf(w, "%d\n", r->r_val.v_num);
		break;
	case V_ERR:
		wwprintf(w, "ERROR\n");
		break;
	}
	return 0;
I 3
}

struct lcmd_arg arg_shell[] = {
D 7
	{ "shell",	1,	ARG_STR },
E 7
I 7
	{ "",	0,		ARG_ANY|ARG_LIST },
E 7
	0
};

l_shell(v, a)
D 7
struct value *v, *a;
E 7
I 7
	struct value *v, *a;
E 7
{
D 7
	register char **pp;
E 7
I 7
D 10
	register char **pp, *p;
E 10
I 10
	register char **pp;
E 10
	register struct value *vp;
E 7

	if (a->v_type == V_ERR) {
		if ((v->v_str = str_cpy(shellfile)) != 0)
			v->v_type = V_STR;
		return;
	}
	if (v->v_str = shellfile) {
		v->v_type = V_STR;
D 7
		for (pp = shell + 1; *pp; pp++)
E 7
I 7
		for (pp = shell + 1; *pp; pp++) {
E 7
			str_free(*pp);
I 7
			*pp = 0;
		}
E 7
	}
D 7
	if (mkargv(a->v_str, shell, sizeof shell / sizeof *shell) < 0)
		*shell = 0;
	for (pp = shell; *pp; pp++)
		if ((*pp = str_cpy(*pp)) == 0) {
E 7
I 7
	for (pp = shell, vp = a;
	     vp->v_type != V_ERR && pp < &shell[sizeof shell/sizeof *shell-1];
	     pp++, vp++)
		if ((*pp = vp->v_type == V_STR ?
		     str_cpy(vp->v_str) : str_itoa(vp->v_num)) == 0) {
E 7
			/* just leave shell[] the way it is */
			p_memerror();
I 7
			break;
E 7
		}
	if (shellfile = *shell)
		if (*shell = rindex(shellfile, '/'))
			(*shell)++;
		else
			*shell = shellfile;
I 4
}

struct lcmd_arg arg_alias[] = {
D 7
	{ "name",	1,	ARG_STR },
	{ "string",	1,	ARG_STR },
E 7
I 7
	{ "",	0,		ARG_STR },
	{ "",	0,		ARG_STR|ARG_LIST },
E 7
	0
};

l_alias(v, a)
D 7
struct value *v, *a;
E 7
I 7
	struct value *v, *a;
E 7
{
	if (a->v_type == V_ERR) {
		register struct ww *w;
		int printalias();

		if ((w = openiwin(wwnrow - 3, "Aliases")) == 0) {
			error("Can't open alias window: %s.", wwerror());
			return;
		}
		if (alias_walk(printalias, (int)w) >= 0)
			waitnl(w);
		closeiwin(w);
	} else {
		register struct alias *ap = 0;

		if (ap = alias_lookup(a->v_str)) {
			if ((v->v_str = str_cpy(ap->a_buf)) == 0) {
				p_memerror();
				return;
			}
			v->v_type = V_STR;
		}
D 7
		if (a[1].v_type == V_STR &&
		    alias_set(a[0].v_str, a[1].v_str) == 0) {
			p_memerror();
			return;
E 7
I 7
		if (a[1].v_type == V_STR) {
			register struct value *vp;
			register char *p, *q;
			char *str;
			register n;

			for (n = 0, vp = a + 1; vp->v_type != V_ERR; vp++, n++)
				for (p = vp->v_str; *p; p++, n++)
					;
			if ((str = str_alloc(n)) == 0) {
				p_memerror();
				return;
			}
			for (q = str, vp = a + 1; vp->v_type != V_ERR;
			     vp++, q[-1] = ' ')
				for (p = vp->v_str; *q++ = *p++;)
					;
			q[-1] = 0;
D 10
			if ((ap = alias_set(a[0].v_str, 0)) == 0) {
E 10
I 10
			if ((ap = alias_set(a[0].v_str, (char *)0)) == 0) {
E 10
				p_memerror();
I 10
				str_free(str);
E 10
				return;
			}
			ap->a_buf = str;
E 7
		}
	}
}

printalias(w, a)
register struct ww *w;
register struct alias *a;
{
	if (more(w, 0) == 2)
		return -1;
	wwprintf(w, "%16s    %s\n", a->a_name, a->a_buf);
	return 0;
}

struct lcmd_arg arg_unalias[] = {
D 11
	{ "name",	1,	ARG_STR },
E 11
I 11
	{ "alias",	1,	ARG_STR },
E 11
	0
};

l_unalias(v, a)
struct value *v, *a;
{
	if (a->v_type == ARG_STR)
		v->v_num = alias_unset(a->v_str);
	v->v_type = V_NUM;
E 4
E 3
E 2
}
I 8

struct lcmd_arg arg_echo[] = {
	{ "window",	1,	ARG_NUM },
	{ "",		0,	ARG_ANY|ARG_LIST },
	0
};

/*ARGSUSED*/
l_echo(v, a)
struct value *v;
register struct value *a;
{
	char buf[20];
	struct ww *w;

D 11
	if ((w = vtowin(a++)) == 0)
E 11
I 11
	if ((w = vtowin(a++, selwin)) == 0)
E 11
		return;
	while (a->v_type != V_ERR) {
		if (a->v_type == V_NUM) {
			(void) sprintf(buf, "%d", a->v_num);
			(void) wwwrite(w, buf, strlen(buf));
		} else
			(void) wwwrite(w, a->v_str, strlen(a->v_str));
		if ((++a)->v_type != V_ERR)
			(void) wwwrite(w, " ", 1);
	}
	(void) wwwrite(w, "\r\n", 2);
}
E 8
E 1

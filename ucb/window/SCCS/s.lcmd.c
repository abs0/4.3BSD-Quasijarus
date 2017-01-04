h37878
s 00010/00005/00120
d D 3.28 88/06/29 21:35:59 bostic 28 27
c install approved copyright notice
e
s 00013/00007/00112
d D 3.27 88/02/21 13:36:57 bostic 27 26
c written by Edward Wang; attach Berkeley specific copyright
e
s 00019/00019/00100
d D 3.26 87/10/02 19:36:57 edward 26 25
c changes from mips!dce, most compatibility stuff
e
s 00003/00000/00116
d D 3.25 87/05/18 12:20:30 edward 25 24
c added keepopen and smooth flags, added + and - window selections
e
s 00006/00000/00110
d D 3.24 85/04/24 16:15:22 edward 24 23
c copyright messages
e
s 00000/00002/00110
d D 3.23 85/04/03 20:38:51 edward 23 22
c removed some compatibility with old window, and some clean up
e
s 00004/00001/00108
d D 3.22 84/07/19 17:34:48 edward 22 21
c the echo command
e
s 00004/00002/00105
d D 3.21 84/07/12 13:38:38 edward 21 20
c new ARG_LIST flag for commands
e
s 00001/00001/00106
d D 3.20 84/05/23 01:58:15 edward 20 19
c new sccs id
e
s 00011/00003/00096
d D 3.19 84/05/06 17:53:50 edward 19 18
c alias macros
e
s 00003/00000/00096
d D 3.18 84/04/08 19:23:20 edward 18 17
c new options to "window": shell, pty, frame
c and stuff to support them
e
s 00007/00003/00089
d D 3.17 84/04/07 00:02:20 edward 17 16
c l_variable and l_list added
e
s 00006/00007/00086
d D 3.16 84/04/06 21:35:08 edward 16 15
c "C" removed, varargs added for "write" and "close"
e
s 00007/00001/00086
d D 3.15 84/04/05 17:33:20 edward 15 14
c "s," "t," and "T" moved to long commands (iostat, time).
c "S" removed.
e
s 00000/00003/00087
d D 3.14 84/04/05 00:56:46 edward 14 13
c no more background windows.
e
s 00008/00002/00082
d D 3.13 84/03/29 00:03:05 edward 13 12
c foreground and background windows
e
s 00000/00000/00084
d D 3.12 84/03/23 18:16:46 edward 12 11
c compile with -R
e
s 00002/00002/00082
d D 3.11 84/01/13 11:08:25 edward 11 10
c context cleanup
e
s 00003/00000/00081
d D 3.10 84/01/12 11:45:51 edward 10 9
c l_unset() added
e
s 00003/00000/00078
d D 3.9 84/01/11 17:28:35 edward 9 8
c l_debug() added
e
s 00004/00001/00074
d D 3.8 83/12/06 12:56:01 edward 8 7
c 'cursormodes' command added
e
s 00051/00119/00024
d D 3.7 83/11/22 19:57:43 edward 7 6
c new parser
e
s 00003/00001/00140
d D 3.6 83/08/25 17:57:12 edward 6 5
c added user setable buffer size.
e
s 00001/00001/00140
d D 3.5 83/08/22 15:41:06 edward 5 4
c now we can quote or escape #
e
s 00001/00001/00140
d D 3.4 83/08/22 14:42:04 edward 4 3
c close all special case added to l_close()
e
s 00010/00008/00131
d D 3.3 83/08/12 11:47:00 edward 3 2
c close command
e
s 00000/00000/00139
d D 3.2 83/08/11 17:23:20 edward 2 1
i
c last few day's work
e
s 00139/00000/00000
d D 3.1 83/08/09 18:37:43 edward 1 0
c date and time created 83/08/09 18:37:43 by edward
e
u
U
t
T
I 1
D 27
#ifndef lint
D 20
static	char *sccsid = "%W% %E%";
E 20
I 20
static char sccsid[] = "%W% %G%";
E 20
#endif

E 27
I 24
/*
D 27
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 27
I 27
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 28
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 28
I 28
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
E 28
E 27
 */
I 27

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 27

E 24
#include "defs.h"
I 7
#include "value.h"
#include "lcmd.h"
E 7

I 19
int l_alias();
E 19
I 13
D 14
int l_background();
E 14
E 13
I 6
D 16
int l_buffer();
E 16
E 6
D 7
int l_window();
int l_select();
E 7
I 7
int l_close();
I 8
int l_cursormodes();
I 9
int l_debug();
I 22
int l_echo();
E 22
E 9
E 8
E 7
int l_escape();
I 13
int l_foreground();
I 15
int l_iostat();
E 15
E 13
int l_label();
I 17
int l_list();
E 17
I 16
int l_nline();
E 16
D 7
int l_terse();
E 7
I 7
int l_select();
I 18
int l_shell();
I 25
int l_smooth();
E 25
E 18
E 7
int l_source();
I 7
int l_terse();
I 15
int l_time();
I 19
int l_unalias();
E 19
E 15
I 10
int l_unset();
I 17
int l_variable();
E 17
E 10
int l_window();
E 7
int l_write();
I 3
D 7
int l_close();
E 7
E 3

I 19
D 26
struct lcmd_arg arg_alias[];
E 19
I 13
D 14
struct lcmd_arg arg_background[];
E 14
E 13
D 7
struct lcmd {
	char *l_name;			/* name of command */
	int l_lmin;			/* minimum length to check */
	int l_lmax;			/* maximum length to check */
	int l_amin;			/* minimum argument */
	int l_amax;			/* maximum argument */
	int (*l_func)();		/* the function */
E 7
I 7
D 16
struct lcmd_arg arg_buffer[];
struct lcmd_arg arg_close[];
E 16
I 8
struct lcmd_arg arg_cursormodes[];
I 9
struct lcmd_arg arg_debug[];
I 22
struct lcmd_arg arg_echo[];
E 22
E 9
E 8
struct lcmd_arg arg_escape[];
I 13
struct lcmd_arg arg_foreground[];
I 15
D 17
struct lcmd_arg arg_iostat[];
E 17
E 15
E 13
struct lcmd_arg arg_label[];
I 16
struct lcmd_arg arg_nline[];
I 21
struct lcmd_arg arg_close[];
E 21
E 16
struct lcmd_arg arg_select[];
I 18
struct lcmd_arg arg_shell[];
I 25
struct lcmd_arg arg_smooth[];
E 25
E 18
struct lcmd_arg arg_source[];
struct lcmd_arg arg_terse[];
I 15
struct lcmd_arg arg_time[];
I 19
struct lcmd_arg arg_unalias[];
E 19
E 15
I 10
struct lcmd_arg arg_unset[];
E 10
struct lcmd_arg arg_window[];
I 21
struct lcmd_arg arg_write[];
E 26
I 26
extern struct lcmd_arg arg_alias[];
extern struct lcmd_arg arg_cursormodes[];
extern struct lcmd_arg arg_debug[];
extern struct lcmd_arg arg_echo[];
extern struct lcmd_arg arg_escape[];
extern struct lcmd_arg arg_foreground[];
extern struct lcmd_arg arg_label[];
extern struct lcmd_arg arg_nline[];
extern struct lcmd_arg arg_close[];
extern struct lcmd_arg arg_select[];
extern struct lcmd_arg arg_shell[];
extern struct lcmd_arg arg_smooth[];
extern struct lcmd_arg arg_source[];
extern struct lcmd_arg arg_terse[];
extern struct lcmd_arg arg_time[];
extern struct lcmd_arg arg_unalias[];
extern struct lcmd_arg arg_unset[];
extern struct lcmd_arg arg_window[];
extern struct lcmd_arg arg_write[];
E 26
E 21
I 17
struct lcmd_arg arg_null[] = 0;
E 17
D 16
struct lcmd_arg arg_write[];
E 16

struct lcmd_tab lcmd_tab[] = {
D 23
	"%",		1,	l_select,	arg_select,
E 23
I 19
	"alias",	1,	l_alias,	arg_alias,
E 19
D 13
	"buffer",	1,	l_buffer,	arg_buffer,
E 13
I 13
D 14
	"background",	2,	l_background,	arg_background,
E 14
D 16
	"buffer",	2,	l_buffer,	arg_buffer,
E 13
D 8
	"close",	1,	l_close,	arg_close,
E 8
I 8
	"close",	2,	l_close,	arg_close,
E 16
I 16
D 23
	"buffer",	2,	l_nline,	arg_nline,
E 23
D 21
	"close",	2,	l_close,	0,
E 21
I 21
	"close",	2,	l_close,	arg_close,
E 21
E 16
	"cursormodes",	2,	l_cursormodes,	arg_cursormodes,
I 9
	"debug",	1,	l_debug,	arg_debug,
E 9
E 8
D 22
	"escape",	1,	l_escape,	arg_escape,
E 22
I 22
	"echo",		2,	l_echo,		arg_echo,
	"escape",	2,	l_escape,	arg_escape,
E 22
I 13
	"foreground",	1,	l_foreground,	arg_foreground,
I 15
D 17
	"iostat",	1,	l_iostat,	arg_iostat,
E 15
E 13
	"label",	1,	l_label,	arg_label,
E 17
I 17
	"iostat",	1,	l_iostat,	arg_null,
	"label",	2,	l_label,	arg_label,
	"list",		2,	l_list,		arg_null,
E 17
I 16
	"nlines",	1,	l_nline,	arg_nline,
E 16
	"select",	2,	l_select,	arg_select,
I 18
	"shell",	2,	l_shell,	arg_shell,
I 25
	"smooth",	2,	l_smooth,	arg_smooth,
E 25
E 18
	"source",	2,	l_source,	arg_source,
D 15
	"terse",	1,	l_terse,	arg_terse,
E 15
I 15
	"terse",	2,	l_terse,	arg_terse,
	"time",		2,	l_time,		arg_time,
E 15
I 10
D 19
	"unset",	1,	l_unset,	arg_unset,
E 19
I 19
	"unalias",	3,	l_unalias,	arg_unalias,
	"unset",	3,	l_unset,	arg_unset,
E 19
I 17
	"variable",	1,	l_variable,	arg_null,
E 17
E 10
	"window",	2,	l_window,	arg_window,
D 16
	"write",	2,	l_write,	arg_write,
E 16
I 16
D 21
	"write",	2,	l_write,	0,
E 21
I 21
	"write",	2,	l_write,	arg_write,
E 21
E 16
D 13
	0,		0,	0,		0,
E 13
I 13
	0
E 13
E 7
};
D 7
static struct lcmd lcmd[] = {
D 3
	"%",		1, 1, 0, 0, l_select,
	"escape",	1, 0, 1, 1, l_escape,
	"label",	1, 0, 2, 2, l_label,
	"source",	1, 0, 1, 1, l_source,
	"terse",	1, 0, 0, 1, l_terse,
	"window",	1, 0, 4, 4, l_window,
	"write",	2, 0, 2, 2, l_write,
E 3
I 3
	"%",		1, 1, 0,  0, l_select,
I 6
	"buffer",	1, 0, 1,  1, l_buffer,
E 6
D 4
	"close",	1, 0, 1, -1, l_close,
E 4
I 4
	"close",	1, 0, 0, -1, l_close,
E 4
	"escape",	1, 0, 1,  1, l_escape,
	"label",	1, 0, 2,  2, l_label,
	"source",	1, 0, 1,  1, l_source,
	"terse",	1, 0, 0,  1, l_terse,
D 6
	"window",	1, 0, 4,  4, l_window,
E 6
I 6
	"window",	1, 0, 4,  5, l_window,
E 6
	"write",	2, 0, 2,  2, l_write,
E 3
	0
};
E 7

D 7
dosource(filename)
char *filename;
E 7
I 7
struct lcmd_tab *
lcmd_lookup(name)
char *name;
E 7
{
D 7
	register FILE *f;
	char buf[BUFSIZ];
E 7
I 7
	register struct lcmd_tab *p;
E 7

D 7
	if ((f = fopen(filename, "r")) == 0)
		return -1;
	insource++;
	beginerror(filename);
	for (lineno = 1; fgets(buf, sizeof buf, f) != 0; lineno++)
		dolongcmd(buf);
	enderror();
	insource = 0;
E 7
I 7
	for (p = lcmd_tab; p->lc_name != 0; p++)
		if (str_match(name, p->lc_name, p->lc_minlen))
			return p;
E 7
	return 0;
}

D 7
dolongcmd(line)
char *line;
E 7
I 7
dosource(filename)
char *filename;
E 7
{
D 7
	register struct lcmd *lp;
	register len;

	makeargv(line);
	if (argc == 0)
		return;
	for (lp = lcmd; lp->l_name; lp++) {
		len = strlen(*argv);
		if (len < lp->l_lmin)
			continue;
		if (!strncmp(*argv, lp->l_name, lp->l_lmax ? lp->l_lmax : len))
			break;
	}
	if (lp->l_name) {
		if (lp->l_amin > argc - 1)
			error("Too few arguments.");
D 3
		else if (lp->l_amax < argc - 1)
E 3
I 3
		else if (lp->l_amax >= 0 && lp->l_amax < argc - 1)
E 3
			error("Too many arguments.");
		else
			(*lp->l_func)();
	} else
		error("%s: Unknown command.", *argv);
E 7
I 7
D 11
	if (cx_setfile(filename) < 0)
E 11
I 11
	if (cx_beginfile(filename) < 0)
E 11
		return -1;
	p_start();
	err_end();
	cx_end();
	return 0;
E 7
}

D 7
makeargv(p)
register char *p;
E 7
I 7
D 19
dolongcmd(buffer)
E 19
I 19
dolongcmd(buffer, arg, narg)
E 19
char *buffer;
I 19
struct value *arg;
int narg;
E 19
E 7
{
D 7
	static char buf[BUFSIZ];
	register char *q = buf, **pp = argv;
	char quote = 0, escape = 0;
	int i;

	for (; *p == ' ' || *p == '\t'; p++)
		;
D 5
	while (*p && *p != '\n' && *p != '#'
E 5
I 5
	while (*p && *p != '\n' && (*p != '#' || escape || quote)
E 5
	       && pp < &argv[sizeof argv/sizeof *argv - 1]) {
		*pp++ = q;
		while (*p && *p != '\n') {
			if (escape) {
				switch (*p) {
				case 'n':
					*q++ = '\n';
					p++;
					break;
				case 'r':
					*q++ = '\r';
					p++;
					break;
				case '0': case '1': case '2': case '3':
				case '4': case '5': case '6': case '7':
					*q = 0;
					for (i = 3; --i >= 0
					     && *p >= '0' && *p <= '9';)
						*q = *q << 3 | *p++ - '0';
					q++;
					break;
				default:
					*q++ = *p++;
					break;
				}
				escape = 0;
			} else if (*p == '\\') {
				escape = 1;
				p++;
			} else if (quote) {
				if (*p == quote) {
					quote = 0;
					p++;
				} else
					*q++ = *p++;
			} else {
				if (*p == '"' || *p == '\'')
					quote = *p++;
				else if (*p == ' ' || *p == '\t')
					break;
				else
					*q++ = *p++;
			}
		}
		*q++ = 0;
		for (; *p == ' ' || *p == '\t'; p++)
			;
	}
	*pp = 0;
	argc = pp - argv;
E 7
I 7
D 11
	if (cx_setbuf(buffer) < 0)
E 11
I 11
D 19
	if (cx_beginbuf(buffer) < 0)
E 19
I 19
	if (cx_beginbuf(buffer, arg, narg) < 0)
E 19
E 11
		return -1;
	p_start();
	err_end();
	cx_end();
	return 0;
E 7
}
E 1

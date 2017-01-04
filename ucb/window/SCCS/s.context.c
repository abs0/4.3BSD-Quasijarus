h46451
s 00010/00005/00101
d D 3.9 88/06/29 21:35:51 bostic 9 8
c install approved copyright notice
e
s 00013/00007/00093
d D 3.8 88/02/21 13:36:50 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00094
d D 3.7 85/04/24 16:20:05 edward 7 6
c copyright messages
e
s 00001/00001/00093
d D 3.6 84/05/23 02:00:06 edward 6 5
c new sccs id
e
s 00005/00001/00089
d D 3.5 84/05/06 17:55:11 edward 5 4
c alias macros
e
s 00003/00003/00087
d D 3.4 84/01/13 11:08:18 edward 4 3
c context cleanup
e
s 00001/00001/00089
d D 3.3 83/12/07 14:14:19 edward 3 2
c error window cleanup
e
s 00007/00004/00083
d D 3.2 83/11/22 19:57:11 edward 2 1
c misc bugs, malloc & free
e
s 00087/00000/00000
d D 3.1 83/11/22 12:47:57 edward 1 0
c date and time created 83/11/22 12:47:57 by edward
e
u
U
t
T
I 1
D 8
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 8
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */
I 8

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 8

E 7
#include <stdio.h>
#include "value.h"
I 2
#include "string.h"
E 2
#include "context.h"

/*
 * Context push/pop for nested command files.
 */

char *malloc();

cx_alloc()
{
	register struct context *xp;

	if (cx.x_type != 0) {
		xp = (struct context *)
D 2
			malloc(1, (unsigned) sizeof (struct context));
E 2
I 2
			malloc((unsigned) sizeof (struct context));
E 2
		if (xp == 0)
			return -1;
		*xp = cx;
		cx.x_link = xp;
		cx.x_type = 0;
	}
	cx.x_erred = 0;
	cx.x_synerred = 0;
	cx.x_abort = 0;
	return 0;
}

cx_free()
{
D 2
	if (cx.x_link != 0) {
		free(cx.x_link);
		cx = *cx.x_link;
E 2
I 2
	struct context *xp;

	if ((xp = cx.x_link) != 0) {
		cx = *xp;
		free((char *)xp);
E 2
	} else
		cx.x_type = 0;
}

D 4
cx_setfile(filename)
E 4
I 4
cx_beginfile(filename)
E 4
char *filename;
{
	if (cx_alloc() < 0)
		return -1;
	cx.x_type = X_FILE;
	if ((cx.x_filename = str_cpy(filename)) == 0)
		goto bad;
	cx.x_fp = fopen(filename, "r");
	if (cx.x_fp == 0)
		goto bad;
	cx.x_bol = 1;
	cx.x_lineno = 0;
	cx.x_errwin = 0;
D 3
	cx.x_baderr = 0;
E 3
I 3
D 4
	cx.x_noerrwin = 0;
E 4
I 4
	cx.x_noerr = 0;
E 4
E 3
	return 0;
bad:
	if (cx.x_filename != 0)
		str_free(cx.x_filename);
	cx_free();
	return -1;
}

D 4
cx_setbuf(buf)
E 4
I 4
D 5
cx_beginbuf(buf)
E 5
I 5
cx_beginbuf(buf, arg, narg)
E 5
E 4
char *buf;
I 5
struct value *arg;
int narg;
E 5
{
	if (cx_alloc() < 0)
		return -1;
	cx.x_type = X_BUF;
	cx.x_bufp = cx.x_buf = buf;
I 5
	cx.x_arg = arg;
	cx.x_narg = narg;
E 5
	return 0;
}

cx_end()
{
	switch (cx.x_type) {
	case X_BUF:
		break;
	case X_FILE:
		(void) fclose(cx.x_fp);
		str_free(cx.x_filename);
		break;
	}
	cx_free();
}
E 1

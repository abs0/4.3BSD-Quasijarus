h22389
s 00010/00005/00054
d D 3.9 88/06/29 21:35:53 bostic 9 8
c install approved copyright notice
e
s 00011/00007/00048
d D 3.8 88/02/21 13:36:51 bostic 8 7
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00049
d D 3.7 85/04/24 16:21:03 edward 7 6
c copyright messages
e
s 00001/00001/00048
d D 3.6 84/05/23 02:00:18 edward 6 5
c new sccs id
e
s 00004/00000/00045
d D 3.5 84/05/06 17:55:19 edward 5 4
c alias macros
e
s 00002/00000/00043
d D 3.4 84/03/03 22:47:51 edward 4 3
c interrupt driven input
e
s 00024/00023/00019
d D 3.3 84/01/13 11:08:22 edward 3 2
c context cleanup
e
s 00003/00005/00039
d D 3.2 83/12/07 14:14:24 edward 2 1
c error window cleanup
e
s 00044/00000/00000
d D 3.1 83/11/22 12:48:06 edward 1 0
c date and time created 83/11/22 12:48:06 by edward
e
u
U
t
T
I 1
/*
D 6
 *	%W% %E%
E 6
I 6
D 8
 * %W% %G%
E 6
 */

I 7
/*
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
 *
 *	%W% (Berkeley) %G%
E 8
 */

E 7
I 4
#include <stdio.h>

E 4
struct context {
	struct context *x_link;		/* nested contexts */
D 3
	char x_type;
	union {				/* input info */
		struct {
			char *X_filename;
			FILE *X_fp;
I 2
			short X_lineno;
E 2
			char X_bol;
D 2
			int X_lineno;
			int X_errlineno;
E 2
I 2
			char X_noerrwin;
E 2
			struct ww *X_errwin;
E 3
I 3
	char x_type;			/* tag for union */
	union {
		struct {	/* input is a file */
			char *X_filename;	/* input file name */
			FILE *X_fp;		/* input stream */
			short X_lineno;		/* current line number */
			char X_bol;		/* at beginning of line */
			char X_noerr;		/* don't report errors */
			struct ww *X_errwin;	/* error window */
E 3
D 2
			char X_baderr;
E 2
		} x_f;
D 3
		struct {
			char *X_buf;
			char *X_bufp;
E 3
I 3
		struct {	/* input is a buffer */
			char *X_buf;		/* input buffer */
			char *X_bufp;		/* current position in buf */
I 5
			struct value *X_arg;	/* argument for alias */
			int X_narg;		/* number of arguments */
E 5
E 3
		} x_b;
	} x_un;
D 3
	int x_token;			/* holding place for token */
	struct value x_val;
	unsigned x_erred :1;		/* parser error flags */
	unsigned x_synerred :1;
	unsigned x_abort :1;
E 3
I 3
		/* holding place for current token */
	int x_token;			/* the token */
	struct value x_val;		/* values associated with token */
		/* parser error flags */
	unsigned x_erred :1;		/* had an error */
	unsigned x_synerred :1;		/* had syntax error */
	unsigned x_abort :1;		/* fatal error */
E 3
};
#define x_buf		x_un.x_b.X_buf
#define x_bufp		x_un.x_b.X_bufp
I 5
#define x_arg		x_un.x_b.X_arg
#define x_narg		x_un.x_b.X_narg
E 5
#define x_filename	x_un.x_f.X_filename
#define x_fp		x_un.x_f.X_fp
#define x_lineno	x_un.x_f.X_lineno
D 2
#define x_errlineno	x_un.x_f.X_errlineno
E 2
#define x_bol		x_un.x_f.X_bol
#define x_errwin	x_un.x_f.X_errwin
D 2
#define x_baderr	x_un.x_f.X_baderr
E 2
I 2
D 3
#define x_noerrwin	x_un.x_f.X_noerrwin
E 3
I 3
#define x_noerr		x_un.x_f.X_noerr
E 3
E 2

D 3
#define X_FILE		1
#define X_BUF		2
E 3
I 3
	/* x_type values, 0 is reserved */
#define X_FILE		1		/* input is a file */
#define X_BUF		2		/* input is a buffer */
E 3

D 3
struct context cx;

struct context *x_alloc();
E 3
I 3
struct context cx;			/* the current context */
E 3
E 1

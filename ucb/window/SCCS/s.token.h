h03106
s 00010/00005/00054
d D 3.7 88/06/29 21:36:34 bostic 7 6
c install approved copyright notice
e
s 00011/00007/00048
d D 3.6 88/02/21 13:37:29 bostic 6 5
c written by Edward Wang; attach Berkeley specific copyright
e
s 00032/00029/00023
d D 3.5 87/05/18 12:22:26 edward 5 4
c added [ and ] tokens for vectors, haven't done the real work yet.
e
s 00006/00000/00046
d D 3.4 85/04/24 16:21:59 edward 4 3
c copyright messages
e
s 00001/00001/00045
d D 3.3 84/07/13 23:57:08 edward 3 2
c $? added
e
s 00001/00001/00045
d D 3.2 84/05/23 02:00:33 edward 2 1
c new sccs id
e
s 00046/00000/00000
d D 3.1 83/11/22 12:48:10 edward 1 0
c date and time created 83/11/22 12:48:10 by edward
e
u
U
t
T
I 1
/*
D 2
 *	%W% %E%
E 2
I 2
D 6
 * %W% %G%
E 2
 */

I 4
/*
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
 *
 *	%W% (Berkeley) %G%
E 6
 */

E 4
#define token		(cx.x_token)
#define token_num	(cx.x_val.v_num)
#define token_str	(cx.x_val.v_str)

#define T_EOL		1
#define T_EOF		2
#define T_COMP		3
#define T_PLUS		4
#define T_MINUS		5
#define T_MUL		6
#define T_DIV		7
#define T_LP		8
#define T_RP		9
D 5
#define T_DOLLAR	10
#define T_COMMA		11
#define T_QUEST		12
#define T_COLON		13
#define T_CHAR		14
#define T_STR		15
#define T_NUM		16
#define T_MOD		17
#define T_XOR		18
D 3
/* 19 */
E 3
I 3
#define T_DQ		19		/* $? */
E 3
#define T_GE		20
#define T_RS		21
#define T_GT		22
#define T_LE		23
#define T_LS		24
#define T_LT		25
#define T_EQ		26
#define T_ASSIGN	27
#define T_NE		28
#define T_NOT		29
#define T_ANDAND	30
#define T_AND		31
#define T_OROR		32
#define T_OR		33
#define T_IF		34
#define T_THEN		35
#define T_ELSIF		36
#define T_ELSE		37
#define T_ENDIF		38
E 5
I 5
#define T_LB		10
#define T_RB		11
#define T_DOLLAR	12
#define T_COMMA		13
#define T_QUEST		14
#define T_COLON		15
#define T_CHAR		16
#define T_STR		17
#define T_NUM		18
#define T_MOD		19
#define T_XOR		20
#define T_DQ		21		/* $? */
#define T_GE		22
#define T_RS		23
#define T_GT		24
#define T_LE		25
#define T_LS		26
#define T_LT		27
#define T_EQ		28
#define T_ASSIGN	29
#define T_NE		30
#define T_NOT		31
#define T_ANDAND	32
#define T_AND		33
#define T_OROR		34
#define T_OR		35

#define T_IF		40
#define T_THEN		41
#define T_ELSIF		42
#define T_ELSE		43
#define T_ENDIF		44
E 5
E 1

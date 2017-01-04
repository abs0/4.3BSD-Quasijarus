h00739
s 00011/00006/00058
d D 5.5 88/06/29 19:40:37 bostic 7 6
c install approved copyright notice
e
s 00010/00011/00054
d D 5.4 88/03/22 17:31:32 bostic 6 5
c add Berkeley and University of Illinois specific copyright
e
s 00000/00000/00065
d D 5.3 85/09/08 15:41:07 mckusick 5 4
c update on Sun stuff by Chris Torek
e
s 00000/00000/00065
d D 5.2 85/08/28 13:47:04 mckusick 4 3
c kernel normal form (from sun!shannon)
e
s 00007/00001/00058
d D 5.1 85/06/04 13:38:12 dist 3 2
c Add copyright
e
s 00001/00001/00058
d D 4.2 83/08/11 22:38:18 sam 2 1
c standardize sccs keyword lines
e
s 00059/00000/00000
d D 4.1 82/10/21 23:58:14 mckusick 1 0
c date and time created 82/10/21 23:58:14 by mckusick
e
u
U
t
T
I 1
D 2
/*	%W%	(Berkeley)	%G%	*/
E 2
I 2
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * Copyright (c) 1976 Board of Trustees of the University of Illinois.
 * All rights reserved.
E 6
 *
I 6
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley and the University of
 * Illinois at Urbana.  The name of either University may not be used
 * to endorse or promote products derived from this software without
 * specific prior written permission. This software is provided
 * ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley and the University
 * of Illinois, Urbana.  The name of either
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
 *
E 6
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
D 6

			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois

			 All rights reserved

E 6
FILE NAME:
	indent_codes.h

PURPOSE:
	This include file contains defines for codes used within indent.  They
	are here so that codes passed between and within routines can be
	referenced symbolically.

GLOBALS:
	No global variables, just a bunch of defines

FUNCTIONS:
	None
*/

#define newline		1
#define lparen		2
#define rparen		3
#define unary_op	4
#define binary_op	5
#define postop		6
#define question	7
#define casestmt	8
#define colon		9
#define semicolon	10
#define lbrace		11
#define rbrace		12
#define ident		13
#define comma		14
#define comment		15
#define swstmt		16
#define preesc		17
#define form_feed	18
#define decl		19
#define sp_paren	20
#define sp_nparen	21
#define ifstmt		22
#define whilestmt	23
#define forstmt		24
#define stmt		25
#define stmtl		26
#define elselit		27
#define dolit		28
#define dohead		29
#define ifhead		30
#define elsehead	31
#define period		32
E 1

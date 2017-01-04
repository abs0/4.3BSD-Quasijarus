h60015
s 00001/00000/00061
d D 5.3 85/06/07 20:20:05 mckusick 4 3
c missing definition
e
s 00002/00004/00059
d D 5.2 85/06/07 20:10:23 mckusick 3 2
c cleanup copyright
e
s 00008/00003/00055
d D 5.1 85/06/07 19:52:09 mckusick 2 1
c Add copyright
e
s 00058/00000/00000
d D 1.1 82/01/18 19:20:09 linton 1 0
c date and time created 82/01/18 19:20:09 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
I 3
 *
 *	%W% (Berkeley) %G%
E 3
 */
E 2
D 3

D 2
static char sccsid[] = "%Z%%M% %I% %G%";

E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
E 2

typedef union  {
	SYM *y_sym;
	NODE *y_node;
	int y_int;
	OP y_op;
	long y_long;
	double y_real;
	char *y_string;
	BOOLEAN y_bool;
} YYSTYPE;
extern YYSTYPE yylval;
# define ALIAS 257
# define ASSIGN 258
# define CALL 259
# define CHFILE 260
# define CONT 261
# define DUMP 262
# define EDIT 263
# define HELP 264
# define LIST 265
# define NEXT 266
# define QUIT 267
# define REMAKE 268
# define PRINT 269
# define RUN 270
# define SH 271
# define SOURCE 272
# define STATUS 273
# define STEP 274
# define STOP 275
# define STOPI 276
# define TRACE 277
# define TRACEI 278
# define DELETE 279
# define WHATIS 280
# define WHICH 281
# define WHERE 282
# define XI 283
# define XD 284
# define AT 285
# define IN 286
# define IF 287
# define FILENAME 288
# define INT 289
# define REAL 290
# define NAME 291
# define STRING 292
# define DIV 293
# define MOD 294
# define AND 295
# define OR 296
# define NOT 297
# define UNARYSIGN 298
I 4
# define GRIPE 299
E 4
E 1

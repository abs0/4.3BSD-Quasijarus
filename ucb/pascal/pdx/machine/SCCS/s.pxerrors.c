h33736
s 00008/00002/00048
d D 5.1 85/06/06 08:19:37 dist 3 2
c Add copyright
e
s 00001/00001/00049
d D 1.2 82/01/25 13:43:32 mckusic 2 1
c fix FPE error message to cover all cases
e
s 00050/00000/00000
d D 1.1 82/01/18 19:20:25 linton 1 0
c date and time created 82/01/18 19:20:25 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
 * px error messages
 */

char *pxerrmsg[] ={
	"not an error!",
	"argument to chr out of range",
	"div (integer divide) by zero",
	"real divide by zero",
	"call to procedure halt",
	"reference through a nil pointer",
	"tried to read past end-of-file",
	"negative parameter to sqrt",
	"pi/px error: stack not empty",
	"subscript out of range",
	"reference to an inactive file",
	"pi/px error: write failed",
	"pi/px error: create failed",
	"non-positive argument to ln",
	"pi/px error: bad op",
	"bad data on integer read",
	"pi/px error: active frame not found in goto",
	"label not found in case",
	"pi/px error: seek failed",
	"pi/px error: bad parameter to alloc",
	"out of memory",
	"constructed set parameter exceeds set bounds",
	"too many digits in number",
	"mod (integer remainder) by 0",
	"bad data on real read",
	"pi/px error: remove failed",
	"pi/px error: close failed",
	"pi/px error: open failed",
	"parameter to argv out of range",
	"bad i to pack(a, i, z)",
	"bad i to unpack(z, a, i)",
	"value out of range",
	"assertion failed",
	"tried to read, but open for writing",
	"tried to write, but open for reading",
	"integer number too large",
	"statement limit exceeded",
	"runtime stack overflow",
	"interrupt",
D 2
	"overflow in arithmetic operation",
E 2
I 2
	"overflow, underflow, or divide by zero in arithmetic operation",
E 2
};
E 1

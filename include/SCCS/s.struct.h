h29697
s 00009/00000/00000
d D 4.1 83/05/03 13:48:20 sam 1 0
c date and time created 83/05/03 13:48:20 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * access to information relating to the fields of a structure
 */

#define	fldoff(str, fld)	((int)&(((struct str *)0)->fld))
#define	fldsiz(str, fld)	(sizeof(((struct str *)0)->fld))
#define	strbase(str, ptr, fld)	((struct str *)((char *)(ptr)-fldoff(str, fld)))
E 1

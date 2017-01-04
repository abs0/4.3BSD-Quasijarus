h57380
s 00029/00000/00000
d D 5.1 85/08/05 21:21:47 kre 1 0
c date and time created 85/08/05 21:21:47 by kre
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %E%
 */

#include <strings.h>

/*
 * these next few are obsolete trash
 */

extern char *strcpyn();
extern char *strcatn();
extern int strcmpn();

/*
 * and the rest are Sys5 functions supported just so
 * Sys5 progs will compile easily.
 */

extern char *strchr();
extern char *strrchr();
extern char *strpbrk();
extern int strspn();
extern int strcspn();
extern char *strtok();
E 1

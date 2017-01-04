h00195
s 00002/00000/00032
d D 1.2 87/09/28 16:22:28 bostic 2 1
c include config.h for FLEXNAMES; bug report 4.3BSD/usr.bin/83
e
s 00032/00000/00000
d D 1.1 83/03/29 11:50:08 edward 1 0
c date and time created 83/03/29 11:50:08 by edward
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif lint

I 2
#include "config.h"

E 2
/*
 * Hash function.  Used for pass 2 symbol table and string table,
 * and structure/union name passing between passes.
 * The hash function is a modular hash of
 * the sum of the characters with the sum
 * rotated before each successive character
 * is added.
 * Only 15 bits are used.
 */
#ifdef FLEXNAMES
hashstr(s)
#else
hashstr(s, n)
register n;
#endif
register char *s;
{
	register i;

	i = 0;
#ifdef FLEXNAMES
	while (*s)
#else
	while (n-- > 0 && *s)
#endif
		i = (i << 3 | i >> 12 & 0x07) + *s++;
	return i & 0x7fff;
}
E 1

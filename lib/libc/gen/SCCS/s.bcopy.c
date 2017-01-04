h17754
s 00045/00000/00000
d D 5.1 87/01/27 16:02:46 mckusick 1 0
c new addition for portability
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
#endif LIBC_SCCS and not lint

/*
 * bcopy -- vax movc3 instruction
 */
bcopy(src, dst, length)
	register char *src, *dst;
	register int length;
{
	if (length && src != dst)
		if ((u_int)dst < (u_int)src)
			if (((int)src | (int)dst | length) & 3)
				do	/* copy by bytes */
					*dst++ = *src++;
				while (--length);
			else {
				length >>= 2;
				do	/* copy by longs */
					*((long *)dst)++ = *((long *)src)++;
				while (--length);
			}
		else {			/* copy backwards */
			src += length;
			dst += length;
			if (((int)src | (int)dst | length) & 3)
				do	/* copy by bytes */
					*--dst = *--src;
				while (--length);
			else {
				length >>= 2;
				do	/* copy by shorts */
					*--((long *)dst) = *--((long *)src);
				while (--length);
			}
		}
	return(0);
}
E 1

h30920
s 00017/00000/00000
d D 5.1 86/11/03 20:00:10 mckusick 1 0
c from CCI
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

/*
 *	@(#)no_lg.c	1.2
 *
 *	ld -lg ...
 * then /usr/lib/libg.a is loaded and defines _dbsubc as non-zero.
 * Otherwise, this is loaded defining it as zero.
 * in main.c, f77_abort() uses this to decide whether or not to call
 * abort to terminate.
 */

char id_no_lg[] = "@(#)no_lg.c	5.2";

int _dbsubc = 0;
E 1

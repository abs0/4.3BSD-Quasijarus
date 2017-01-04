h09041
s 00001/00001/00027
d D 7.1 86/06/04 23:19:52 mckusick 3 2
c 4.3BSD release version
e
s 00007/00001/00021
d D 6.2 85/06/08 14:54:17 mckusick 2 1
c Add copyright
e
s 00022/00000/00000
d D 6.1 83/07/31 21:23:47 sam 1 0
c date and time created 83/07/31 21:23:47 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * Macro definition of bk.c/netinput().
 * This is used to replace a call to
 *		(*linesw[tp->t_line].l_rint)(c,tp);
 * with
 *
 *		if (tp->t_line == NETLDISC)
 *			BKINPUT(c, tp);
 *		else
 *			(*linesw[tp->t_line].l_rint)(c,tp);
 */
#define	BKINPUT(c, tp) { \
	if ((tp)->t_rec == 0) { \
		*(tp)->t_cp++ = c; \
		if (++(tp)->t_inbuf == 1024 || (c) == '\n') { \
			(tp)->t_rec = 1; \
			wakeup((caddr_t)&(tp)->t_rawq); \
		} \
	} \
}
E 1

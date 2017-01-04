h64424
s 00029/00000/00000
d D 5.1 87/01/27 16:07:57 mckusick 1 0
c add to portability library
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
 * insque -- vax insque instruction
 *
 * NOTE: this implementation is non-atomic!!
 */

struct vaxque {		/* queue format expected by VAX queue instructions */
	struct vaxque	*vq_next;
	struct vaxque	*vq_prev;
};

insque(e, prev)
	register struct vaxque *e, *prev;
{
	e->vq_prev = prev;
	e->vq_next = prev->vq_next;
	prev->vq_next->vq_prev = e;
	prev->vq_next = e;
}
E 1

h02349
s 00008/00000/00020
d D 1.2 2011/07/18 05:15:51 msokolov 2 1
c timesched mechanism implemented
e
s 00020/00000/00000
d D 1.1 11/07/11 08:04:08 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
 * MSDNS is basically one giant select loop.  Various system components
 * set bits in the select_for_* sets for the descriptors of interest
 * to them and fill out the select_desc array, telling the main select
 * loop what to do when that descriptor is ready.
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__SELECTLOOP_H
#define	__SELECTLOOP_H

struct selectloop_desc {
	void	(*sel_read)();
	void	(*sel_write)();
	void	(*sel_except)();
	caddr_t	sel_opaque;
};

I 2
struct timesched {
	time_t	tim_time;
	void	(*tim_func)();
	caddr_t	tim_arg;
	struct	timesched *tim_next;
	struct	timesched **tim_backptr;
};

E 2
#endif	/* include guard */
E 1

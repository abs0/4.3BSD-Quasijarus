/*
 * MSDNS is basically one giant select loop.  Various system components
 * set bits in the select_for_* sets for the descriptors of interest
 * to them and fill out the select_desc array, telling the main select
 * loop what to do when that descriptor is ready.
 *
 *	@(#)selectloop.h	1.2 (IFCTF) 2011/07/18
 */

#ifndef	__SELECTLOOP_H
#define	__SELECTLOOP_H

struct selectloop_desc {
	void	(*sel_read)();
	void	(*sel_write)();
	void	(*sel_except)();
	caddr_t	sel_opaque;
};

struct timesched {
	time_t	tim_time;
	void	(*tim_func)();
	caddr_t	tim_arg;
	struct	timesched *tim_next;
	struct	timesched **tim_backptr;
};

#endif	/* include guard */

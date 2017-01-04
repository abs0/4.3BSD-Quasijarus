/*
 * This is a 4.3BSD-Quasijarus kernel header file.
 *
 *	@(#)gre.h	7.1 (Berkeley) 5/18/07
 */

/*
 * Definitions for Generic Routing Encapsulation (GRE).
 * Per RFC 1701, October 1994.
 */

/*
 * The GRE header defined in RFC 1701 would be very difficult to describe
 * with a struct because it has variable length and consists of a sequence
 * of optional fields, most of which we don't support.  So instead we treat
 * it as an array of shorts.
 */

/* Flag bit definitions for the first short */
#define	GREFLAGS_C	0x8000
#define	GREFLAGS_R	0x4000
#define	GREFLAGS_K	0x2000
#define	GREFLAGS_S	0x1000
#define	GREFLAGS_s	0x0800

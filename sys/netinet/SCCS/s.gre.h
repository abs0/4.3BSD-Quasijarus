h56999
s 00024/00000/00000
d D 7.1 07/05/18 19:48:02 msokolov 1 0
c date and time created 07/05/18 19:48:02 by msokolov
e
u
U
t
T
I 1
/*
 * This is a 4.3BSD-Quasijarus kernel header file.
 *
 *	%W% (Berkeley) %G%
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
E 1

h16452
s 00002/00003/00013
d D 1.3 2013/01/19 21:39:19 msokolov 3 2
c changes for calend_long
e
s 00002/00009/00014
d D 1.2 2012/06/22 04:33:09 msokolov 2 1
c struct calendar_date factored out into <caldate.h>
e
s 00023/00000/00000
d D 1.1 05/07/28 05:18:06 msokolov 1 0
c started SCCS
e
u
U
t
T
I 1
/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Public interface definitions and declarations for calendar functions
 *
 *	%W% (IFCTF) %E%
 */

D 2
/*
 * Whatever numbers they use, virtually all human calendars have years,
 * months and days.  The following structure reflects this.
 */
struct calendar_date {
	int	year;
	int	month;
	int	day;
};
E 2
I 2
/* struct calendar_date has moved into a new header file: */
#include <caldate.h>
E 2

/* declarations for functions returning something other than int */
D 3
extern long gregtomjd();
extern long juliantomjd();
extern long linearize_julian_date();
E 3
I 3
extern calend_long gregtomjd();
extern calend_long juliantomjd();
E 3
E 1

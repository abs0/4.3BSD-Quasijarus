h29864
s 00015/00000/00000
d D 1.1 2012/06/23 05:21:50 msokolov 1 0
c date and time created 2012/06/23 05:21:50 by msokolov
e
u
U
t
T
I 1
/*
 * Offset-DOY to {month,day} conversion LUT used by the
 * mjdtogreg() and mjdtojulian() public functions.
 *
 *	%W% (IFCTF) %E%
 */

#define	MAR_THRU_DEC	(365 - 31 - 28)

struct mon_day {
	u_char	month;
	u_char	day;
};

extern struct mon_day __roman_doy_lut[366];
E 1

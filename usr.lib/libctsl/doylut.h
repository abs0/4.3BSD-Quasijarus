/*
 * Offset-DOY to {month,day} conversion LUT used by the
 * mjdtogreg() and mjdtojulian() public functions.
 *
 *	@(#)doylut.h	1.1 (IFCTF) 2012/06/23
 */

#define	MAR_THRU_DEC	(365 - 31 - 28)

struct mon_day {
	u_char	month;
	u_char	day;
};

extern struct mon_day __roman_doy_lut[366];

/*
 * Converting an MJD to a day-of-week using bit shifts and table lookups
 * instead of a division operation: a time vs. space trade-off.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)mjd2weekday.c	5.1 (IFCTF) 2012/06/20";
#endif LIBC_SCCS and not lint

#include <sys/types.h>

static u_char tab9[512] = {
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,
	0,1,2,3,4,5,6,0,1,2,3,4,5,6,0,1,2,3,4,5,6,0 };

static u_char hitab[32] = {
	3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4,
	1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2 };

/*
 * The MJD argument is actually signed, but thanks to K&R C
 * we can declare it as either signed or unsigned internally -
 * the actual signed interpretation of the MJD resides in the way
 * the hitab array is filled above.
 *
 * Whether signed or unsigned is better for the bit-shifts
 * will depend on your machine.
 */

#define	USE_UNSIGNED	0

mjd2weekday(mjd)
#if USE_UNSIGNED
	register u_long mjd;
#else
	register long mjd;
#endif
{
	register int accum;

	accum = tab9[mjd & 0x1FF];
	mjd >>= 9;
	accum += tab9[mjd & 0x1FF];
	mjd >>= 9;
	accum += tab9[mjd & 0x1FF];
	mjd >>= 9;
#if USE_UNSIGNED
	accum += hitab[mjd];
#else
	accum += hitab[mjd & 0x1F];
#endif
	return tab9[accum];
}

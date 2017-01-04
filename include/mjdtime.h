/*
 * MJD + fraction-of-day representation of time
 * Implemented and adopted as a personal standard
 * by Michael Spacefalcon.
 *
 *	@(#)mjdtime.h	1.6 (IFCTF) 2013/01/19
 *
 * The semantics of the calend_long integer data type are:
 * we want it to be a long on Classic platforms such as PDP-11
 * and MC68000, but when we port our software to "modern"
 * perverted systems where long means 64 bits, we'll change
 * calend_long to a plain int (32 bits) on those platforms.
 *
 * On the VAX and similar platforms int and long mean exactly
 * the same thing (32 bits, which is what we want); we use
 * "long" in the VAX version as a political statement as to
 * what the long C type *should* mean.
 */

#ifndef calend_long
#define	calend_long	long
#endif

struct mjdtime {
	calend_long	mjd;
	calend_long	fract;
};

#define	normalize_mjdtime(tv)	{		\
	if ((tv).fract < 0) {			\
		(tv).fract += 86400;		\
		(tv).mjd--;			\
	} else if ((tv).fract >= 86400) {	\
		(tv).fract -= 86400;		\
		(tv).mjd++;			\
	}					\
}

#define	mjdtime_gtr(tv1,tv2)	((tv1).mjd > (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract > (tv2).fract))
#define	mjdtime_geq(tv1,tv2)	((tv1).mjd > (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract >= (tv2).fract))
#define	mjdtime_leq(tv1,tv2)	((tv1).mjd < (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract <= (tv2).fract))
#define	mjdtime_lss(tv1,tv2)	((tv1).mjd < (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract < (tv2).fract))

extern void unix2mjdtime();
extern time_t mjd2unixtime();

/*
 * Further division of fract into HH:MM:SS
 * The reverse order of structure fields is unfortunate,
 * but it matches struct tm, allowing sexatime to be used
 * to fill the latter.
 */
struct sexatime {
	int	ss;
	int	mm;
	int	hh;
};

extern void sexatime();

/*
 * Turning struct sexatime back into a flat integer
 * in the [0,86399] range is a trivial inline expression,
 * but we have some muck dealing with the calend_long type,
 * as the output range doesn't fit into a 16-bit int.
 * Hence we've made a macro that hides the mess.
 */

#define	sexatime_mult(s)	((calend_long)(s)->hh * 3600 + \
					((s)->mm * 60 + (s)->ss))

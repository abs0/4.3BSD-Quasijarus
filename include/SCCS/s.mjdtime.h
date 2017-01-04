h52362
s 00042/00014/00032
d D 1.6 2013/01/19 21:39:20 msokolov 6 5
c changes for calend_long
e
s 00012/00000/00034
d D 1.5 2012/06/20 01:55:07 msokolov 5 4
c struct sexatime definition added
e
s 00003/00000/00031
d D 1.4 2012/06/19 02:00:09 msokolov 4 3
c added extern declarations for the conversion functions
e
s 00021/00022/00010
d D 1.3 2012/06/14 23:42:49 msokolov 3 2
c tvalue => mjdtime
e
s 00019/00000/00013
d D 1.2 05/08/22 03:14:23 msokolov 2 1
c added macros for comparing and normalizing tvalues
e
s 00013/00000/00000
d D 1.1 05/08/21 18:39:55 msokolov 1 0
c initial version checked into SCCS
e
u
U
t
T
I 1
/*
D 3
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
E 3
I 3
 * MJD + fraction-of-day representation of time
 * Implemented and adopted as a personal standard
 * by Michael Spacefalcon.
E 3
 *
D 3
 * Public interface definitions and declarations for time functions
 *
E 3
 *	%W% (IFCTF) %E%
I 6
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
E 6
 */

I 6
#ifndef calend_long
#define	calend_long	long
#endif

E 6
D 3
struct tvalue {
	long	tv_mjd;
	long	tv_time;
E 3
I 3
struct mjdtime {
D 6
	long	mjd;
	long	fract;
E 6
I 6
	calend_long	mjd;
	calend_long	fract;
E 6
E 3
};
I 2

I 5
D 6
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

E 6
E 5
D 3
#define	normalize_tvalue(tv)	{		\
	if ((tv).tv_time < 0) {			\
		(tv).tv_time += 86400;		\
		(tv).tv_mjd--;			\
	} else if ((tv).tv_time >= 86400) {	\
		(tv).tv_time -= 86400;		\
		(tv).tv_mjd++;			\
E 3
I 3
#define	normalize_mjdtime(tv)	{		\
	if ((tv).fract < 0) {			\
		(tv).fract += 86400;		\
		(tv).mjd--;			\
	} else if ((tv).fract >= 86400) {	\
		(tv).fract -= 86400;		\
		(tv).mjd++;			\
E 3
	}					\
}

D 3
#define	tvalue_gtr(tv1,tv2)	((tv1).tv_mjd > (tv2).tv_mjd || \
	((tv1).tv_mjd == (tv2).tv_mjd && (tv1).tv_time > (tv2).tv_time))
#define	tvalue_geq(tv1,tv2)	((tv1).tv_mjd > (tv2).tv_mjd || \
	((tv1).tv_mjd == (tv2).tv_mjd && (tv1).tv_time >= (tv2).tv_time))
#define	tvalue_leq(tv1,tv2)	((tv1).tv_mjd < (tv2).tv_mjd || \
	((tv1).tv_mjd == (tv2).tv_mjd && (tv1).tv_time <= (tv2).tv_time))
#define	tvalue_lss(tv1,tv2)	((tv1).tv_mjd < (tv2).tv_mjd || \
	((tv1).tv_mjd == (tv2).tv_mjd && (tv1).tv_time < (tv2).tv_time))
E 3
I 3
#define	mjdtime_gtr(tv1,tv2)	((tv1).mjd > (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract > (tv2).fract))
#define	mjdtime_geq(tv1,tv2)	((tv1).mjd > (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract >= (tv2).fract))
#define	mjdtime_leq(tv1,tv2)	((tv1).mjd < (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract <= (tv2).fract))
#define	mjdtime_lss(tv1,tv2)	((tv1).mjd < (tv2).mjd || \
	((tv1).mjd == (tv2).mjd && (tv1).fract < (tv2).fract))
I 4

extern void unix2mjdtime();
extern time_t mjd2unixtime();
I 6

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
E 6
E 4
E 3
E 2
E 1

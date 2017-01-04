/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Some interesting calendrical constants
 *
 *	@(#)calendardefs.h	1.4 (IFCTF) 2012/06/23
 */

/* MJDs of interesting historical dates */
#define	GREG_START_MJD	-100840	/* Gregorian calendar start 1582-10-15 */
#define	NTP_EPOCH_MJD	15020	/* Gregorian 1900-01-01 */
#define	TAI_START_MJD	36204	/* Gregorian 1958-01-01 */
#define	UTC1_START_MJD	37300	/* Gregorian 1961-01-01, first version of UTC */
#define	UNIX_EPOCH_MJD	40587	/* Gregorian 1970-01-01 */
#define	UTC_START_MJD	41317	/* Gregorian 1972-01-01, start of modern UTC */

/* calendrical cycles */
#define	JULIAN_CYCLE	1461	/* 3 common years + 1 leap year */
#define	JULIAN_CENTURY	36525	/* 365.25 * 100 */
#define	GREG400Y	146097	/* days in a Gregorian 400 y cycle */

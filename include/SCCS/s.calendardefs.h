h27521
s 00004/00002/00017
d D 1.4 2012/06/23 06:03:34 msokolov 4 3
c better calendrical cycles section
e
s 00001/00000/00018
d D 1.3 2012/06/14 23:26:48 msokolov 3 2
c NTP_EPOCH_MJD added
e
s 00002/00001/00016
d D 1.2 05/08/26 16:39:19 msokolov 2 1
c added UTC1_START_MJD
e
s 00017/00000/00000
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
 * Some interesting calendrical constants
 *
 *	%W% (IFCTF) %E%
 */

/* MJDs of interesting historical dates */
#define	GREG_START_MJD	-100840	/* Gregorian calendar start 1582-10-15 */
I 3
#define	NTP_EPOCH_MJD	15020	/* Gregorian 1900-01-01 */
E 3
#define	TAI_START_MJD	36204	/* Gregorian 1958-01-01 */
I 2
#define	UTC1_START_MJD	37300	/* Gregorian 1961-01-01, first version of UTC */
E 2
#define	UNIX_EPOCH_MJD	40587	/* Gregorian 1970-01-01 */
D 2
#define	UTC_START_MJD	41317	/* Gregorian 1972-01-01 */
E 2
I 2
#define	UTC_START_MJD	41317	/* Gregorian 1972-01-01, start of modern UTC */
E 2

D 4
#define	GREG400Y	146097	/* days in a Gregorian 400 y period */
#define	JCLD_MJD_OFFSET	678943
E 4
I 4
/* calendrical cycles */
#define	JULIAN_CYCLE	1461	/* 3 common years + 1 leap year */
#define	JULIAN_CENTURY	36525	/* 365.25 * 100 */
#define	GREG400Y	146097	/* days in a Gregorian 400 y cycle */
E 4
E 1

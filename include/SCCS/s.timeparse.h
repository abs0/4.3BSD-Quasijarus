h31211
s 00038/00000/00000
d D 1.1 2012/06/23 08:22:12 msokolov 1 0
c date and time created 2012/06/23 08:22:12 by msokolov
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
 * Public interface definitions and declarations for
 * date and time parsing functions.
 *
 *	%W% (IFCTF) %E%
 */

/*
 * The following date and time parsing functions are provided.  Each takes
 * a pointer to the string to be parsed, a pointer to the structure to be
 * filled, and a word of flags which are defined below.  All functions
 * returns char pointers; if the parse was successful, the return value
 * is the pointer to the next char after the last one parsed; if the parse
 * failed, the return value is NULL.
 */

extern char *parse_iso_date();
extern char *parse_hms_time();
extern char *parse_mjdtime();

/* option flag bit definitions */

#define	PARSE_REQ_TERM		0x8000

#define	DATE_ALLOW_NOSEP	0x4000
#define	DATE_ALLOW_ALTSEP	0x2000
#define	DATE_ALLOW_EXPYEAR	0x1000

#define	TIME_ALLOW_NOSEP	0x0800
#define	TIME_ALLOW_NOSEC	0x0400
#define	TIME_ALLOW_LEAPSEC	0x0200
#define	TIME_ALLOW_LEAPHOUR	0x0100

#define	MJDTIME_ALLOW_ISO8601	0x0020
#define	MJDTIME_ALLOW_CTSL	0x0010
E 1

/*
 * IFCTF Calendar and Time Systems Library
 * International Free Computing Task Force
 *
 * Public interface definitions and declarations for calendar functions
 *
 *	@(#)ctslcal.h	1.3 (IFCTF) 2013/01/19
 */

/* struct calendar_date has moved into a new header file: */
#include <caldate.h>

/* declarations for functions returning something other than int */
extern calend_long gregtomjd();
extern calend_long juliantomjd();

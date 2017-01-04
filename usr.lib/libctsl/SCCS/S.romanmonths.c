h59346
s 00004/00003/00010
d D 1.2 05/08/26 19:19:56 msokolov 2 1
c constdata.c => romanmonths.c
e
s 00013/00000/00000
d D 1.1 05/07/28 05:20:37 msokolov 1 0
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
D 2
 * Constant data that needs to be allocated in memory
E 2
I 2
 * Table of Roman month lengths used by several modules supporting
 * Gregorian and Julian calendars.
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 2
int roman_months_com[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int roman_months_bis[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
E 2
I 2
int __roman_months_com[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int __roman_months_bis[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
E 2
E 1

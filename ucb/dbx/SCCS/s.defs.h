h13325
s 00007/00000/00079
d D 5.2 88/01/12 00:26:02 donn 7 6
c merge in latest Linton version
e
s 00007/00001/00072
d D 5.1 85/05/31 11:27:01 dist 6 5
c Add copyright
e
s 00000/00001/00073
d D 1.4 85/03/01 20:21:14 linton 5 4
c update to version 3.0
e
s 00001/00000/00073
d D 1.3 84/08/12 15:09:44 sam 4 3
c add strneq definition
e
s 00002/00000/00071
d D 1.2 84/06/23 11:40:07 sam 3 1
i 2
c merge linton branch delta trail
e
s 00003/00002/00068
d D 1.1.1.1 84/06/23 10:45:34 sam 2 1
c branch delta of linton changes from net.sources
e
s 00070/00000/00000
d D 1.1 83/08/13 15:42:22 sam 1 0
c date and time created 83/08/13 15:42:22 by sam
e
u
U
f b 
t
T
I 3
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6

E 3
I 1
D 2
/*	%M%	%I%	%E%	*/

E 2
/*
 * Public definitions, common to all.
 */

#include <stdio.h>

I 7
#ifdef sgi
#   define double long float
#   define atof _latof
#   define IRIS
#   define mc68000
#endif

E 7
#define new(type)           ((type) malloc(sizeof(struct type)))
#define newarr(type, n)     ((type *) malloc((unsigned) (n) * sizeof(type)))
#define dispose(ptr)        { free((char *) ptr); ptr = 0; }

#define public
#define private static

#define ord(enumcon) ((unsigned int) enumcon)
#define nil 0
#define and &&
#define or ||
#define not !
#define div /
#define mod %
#define max(a, b)    ((a) > (b) ? (a) : (b))
#define min(a, b)    ((a) < (b) ? (a) : (b))

#define assert(b) { \
    if (not(b)) { \
	panic("assertion failed at line %d in file %s", __LINE__, __FILE__); \
    } \
}

#define badcaseval(v) { \
    panic("unexpected value %d at line %d in file %s", v, __LINE__, __FILE__); \
}

#define checkref(p) { \
    if (p == nil) { \
	panic("reference through nil pointer at line %d in file %s", \
	    __LINE__, __FILE__); \
    } \
}

typedef int Integer;
I 2
typedef int integer;
E 2
typedef char Char;
typedef double Real;
I 2
typedef double real;
E 2
typedef enum { false, true } Boolean;
I 2
typedef Boolean boolean;
E 2
typedef char *String;

#define strdup(s)       strcpy(malloc((unsigned) strlen(s) + 1), s)
#define streq(s1, s2)   (strcmp(s1, s2) == 0)
I 4
D 5
#define strneq(s1, s2, n)   (strncmp(s1, s2, n) == 0)
E 5
E 4

typedef FILE *File;
typedef int Fileid;
typedef String Filename;

#define get(f, var) fread((char *) &(var), sizeof(var), 1, f)
#define put(f, var) fwrite((char *) &(var), sizeof(var), 1, f)

#undef FILE

extern long atol();
extern double atof();
extern char *malloc();
extern String strcpy(), index(), rindex();
extern int strlen();

extern String cmdname;
extern String errfilename;
extern short errlineno;
extern int debug_flag[];
E 1

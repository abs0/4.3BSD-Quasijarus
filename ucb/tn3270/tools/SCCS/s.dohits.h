h58811
s 00010/00001/00025
d D 3.2 88/03/28 12:08:10 bostic 5 4
c add Berkeley specific headers
e
s 00000/00000/00026
d D 3.1 87/08/11 10:20:43 minshall 4 3
c New version numbering.
e
s 00005/00000/00021
d D 1.3 87/07/17 10:06:05 minshall 3 2
c Install sccs headers and copyright notices.
e
s 00001/00001/00020
d D 1.2 86/11/12 16:44:58 minshall 2 1
c This version of these things seems to work.
e
s 00021/00000/00000
d D 1.1 86/11/11 09:42:15 minshall 1 0
c date and time created 86/11/11 09:42:15 by minshall
e
u
U
t
T
I 3
/*
I 5
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 5
 *
D 5
 * %W% (Berkeley) %G%
E 5
I 5
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 5
 */

E 3
I 1
#define	numberof(x)	(sizeof x/sizeof x[0])
#define	highestof(x)	(numberof(x)-1)

#define	firstentry(x)	(table[dohash(0, (x))%highestof(table)])

D 2
extern struct Hits {
E 2
I 2
struct Hits {
E 2
    struct hits hits;
    char *name[4];
};

struct thing {
    struct thing *next;
    struct Hits *hits;
    unsigned char value;
    char name[100];
};

extern struct Hits Hits[256];		/* one for each of 0x00-0xff */
extern struct thing *table[100];

extern unsigned int dohash();
E 1

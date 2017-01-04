h33077
s 00014/00000/00017
d D 1.2 88/03/08 10:31:23 bostic 2 1
c add Berkeley specific copyright
e
s 00017/00000/00000
d D 1.1 87/09/11 15:40:35 minshall 1 0
c date and time created 87/09/11 15:40:35 by minshall
e
u
U
t
T
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
 */

E 2
I 1
typedef struct {
    char *modedescriptions;
    char modetype;
} Modelist;

extern Modelist modelist[];

typedef struct {
    int
	system,			/* what the current time is */
	echotoggle,		/* last time user entered echo character */
	modenegotiated,		/* last time operating mode negotiated */
	didnetreceive,		/* last time we read data from network */
	gotDM;			/* when did we last see a data mark */
} Clocks;

extern Clocks clocks;
E 1

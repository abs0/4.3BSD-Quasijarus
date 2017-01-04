h25396
s 00001/00001/00028
d D 7.1 86/06/05 01:05:16 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00022
d D 6.2 85/06/08 14:13:19 mckusick 4 3
c Add copyright
e
s 00000/00000/00023
d D 6.1 83/07/29 07:26:55 sam 3 2
c 4.2 distribution
e
s 00004/00002/00019
d D 4.2 82/08/01 19:19:58 sam 2 1
c new ioctl's
e
s 00021/00000/00000
d D 4.1 82/06/26 14:04:57 sam 1 0
c date and time created 82/06/26 14:04:57 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

struct addevice {
	short int ad_csr;			/* Control status register */
	short int ad_data;			/* Data buffer */
};

D 2
#define AD_CHAN		(('a'<<8)|0)
#define AD_READ		(('a'<<8)|1)
E 2
I 2
#define AD_CHAN		ADIOSCHAN
#define AD_READ		ADIOGETW
#define	ADIOSCHAN	_IOW(a, 0, int)		/* set channel */
#define	ADIOGETW	_IOR(a, 1, int)		/* read one word */
E 2

/*
 * Unibus CSR register bits
 */

#define AD_START		01
#define AD_SCHMITT		020
#define AD_CLOCK		040
#define AD_IENABLE		0100
#define AD_DONE 		0200
#define AD_INCENABLE		040000
#define AD_ERROR		0100000
E 1

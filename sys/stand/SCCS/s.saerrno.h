h39817
s 00010/00005/00028
d D 7.2 88/06/29 18:19:19 bostic 2 1
c install approved copyright notice
e
s 00033/00000/00000
d D 7.1 88/03/02 12:09:49 bostic 1 0
c split out from saio.h
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 2
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 2
I 2
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 2
 *
 *	%W% (Berkeley) %G%
 */

extern	int errno;	/* just like unix */

/* error codes */
#define	EADAPT	1	/* bad adaptor */
#define	ECTLR	2	/* bad controller */
#define	EUNIT	3	/* bad drive */
#define	EPART	4	/* bad partition */
#define	ERDLAB	5	/* can't read disk label */
#define	EUNLAB	6	/* unlabeled disk */
#define	ENXIO	7	/* bad device specification */
#define	EBADF	8	/* bad file descriptor */
#define	EOFFSET	9	/* relative seek not supported */
#define	ESRCH	10	/* directory search for file failed */
#define	EIO	11	/* generic error */
#define	ECMD	12	/* undefined driver command */
#define	EBSE	13	/* bad sector error */
#define	EWCK	14	/* write check error */
#define	EECC	15	/* uncorrectable ecc error */
#define	EHER	16	/* hard error */
E 1

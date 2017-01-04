h52956
s 00010/00005/00031
d D 7.4 88/06/29 17:06:24 bostic 9 8
c install approved copyright notice
e
s 00008/00002/00028
d D 7.3 87/12/07 17:45:01 bostic 8 7
c use Berkeley specific header
e
s 00002/00002/00028
d D 7.2 87/01/13 14:11:05 karels 7 6
c use the same definition for array dimension and sensibility checks
e
s 00001/00001/00029
d D 7.1 86/06/05 00:24:11 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00023
d D 6.3 85/06/08 12:36:09 mckusick 5 4
c Add copyright
e
s 00001/00000/00023
d D 6.2 83/09/19 14:21:24 mckusick 4 3
c clean-ups from wnj
e
s 00000/00000/00023
d D 6.1 83/07/29 07:10:55 sam 3 2
c 4.2 distribution
e
s 00001/00001/00022
d D 4.2 83/03/10 21:10:35 sam 2 1
c typo
e
s 00023/00000/00000
d D 4.1 83/03/10 21:04:57 sam 1 0
c date and time created 83/03/10 21:04:57 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Variables related to this implementation
 * of the internet control message protocol.
 */
struct	icmpstat {
/* statistics related to icmp packets generated */
	int	icps_error;		/* # of calls to icmp_error */
	int	icps_oldshort;		/* no error 'cuz old ip too short */
	int	icps_oldicmp;		/* no error 'cuz old was icmp */
D 7
	int	icps_outhist[ICMP_IREQREPLY + 1];
E 7
I 7
	int	icps_outhist[ICMP_MAXTYPE + 1];
E 7
/* statistics related to input messages processed */
I 4
 	int	icps_badcode;		/* icmp_code out of range */
E 4
	int	icps_tooshort;		/* packet < ICMP_MINLEN */
	int	icps_checksum;		/* bad checksum */
	int	icps_badlen;		/* calculated bound mismatch */
	int	icps_reflect;		/* number of responses */
D 7
	int	icps_inhist[ICMP_IREQREPLY + 1];
E 7
I 7
	int	icps_inhist[ICMP_MAXTYPE + 1];
E 7
};

#ifdef KERNEL
D 2
struct	impcstat icmpstat;
E 2
I 2
struct	icmpstat icmpstat;
E 2
#endif
E 1

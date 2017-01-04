h03849
s 00012/00007/00062
d D 7.4 88/06/29 17:13:20 bostic 9 8
c install approved copyright notice
e
s 00004/00005/00065
d D 7.3 88/01/28 21:00:19 sklower 8 6
c Allow for new error codes to be logged dynamically without overruning tables
e
s 00003/00004/00066
d R 7.3 88/01/28 20:45:54 sklower 7 6
c avoid table overruns logging unknown errors
e
s 00010/00004/00060
d D 7.2 88/01/20 15:15:14 sklower 6 5
c Change licensing/use notice.
e
s 00001/00001/00063
d D 7.1 86/06/05 00:47:51 mckusick 5 3
c 4.3BSD release version
e
s 00000/00000/00064
d R 7.1 86/06/05 00:36:36 mckusick 4 3
c 4.3BSD release version
e
s 00001/00001/00063
d D 6.3 86/02/03 17:40:35 sklower 3 2
c Correct erroneous copyright information.
e
s 00007/00001/00057
d D 6.2 85/06/08 12:50:08 mckusick 2 1
c Add copyright
e
s 00058/00000/00000
d D 6.1 85/05/30 19:10:54 sklower 1 0
c date and time created 85/05/30 19:10:54 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
D 5
 * Copyright (c) 1984, 1985  Regents of the University of California.
E 5
I 5
D 6
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 5
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
D 8
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
E 8
I 8
D 9
 * Copyright (c) 1984, 1988  Regents of the University of California.
E 9
I 9
 * Copyright (c) 1984, 1988 Regents of the University of California.
E 9
E 8
 * All rights reserved.
E 6
 *
D 6
 *	%W% (Berkeley) %G%
E 6
I 6
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
 *
D 9
 *      %W% (Berkeley) %G%
E 9
I 9
 *	%W% (Berkeley) %G%
E 9
E 6
 */
E 2

/*
 * Xerox NS error messages
 */

struct ns_errp {
	u_short		ns_err_num;		/* Error Number */
	u_short		ns_err_param;		/* Error Parameter */
	struct idp	ns_err_idp;		/* Initial segment of offending
						   packet */
	u_char		ns_err_lev2[12];	/* at least this much higher
						   level protocol */
};
struct  ns_epidp {
	struct idp ns_ep_idp;
	struct ns_errp ns_ep_errp;
};

#define	NS_ERR_UNSPEC	0	/* Unspecified Error detected at dest. */
#define	NS_ERR_BADSUM	1	/* Bad Checksum detected at dest */
#define	NS_ERR_NOSOCK	2	/* Specified socket does not exist at dest*/
#define	NS_ERR_FULLUP	3	/* Dest. refuses packet due to resource lim.*/
#define	NS_ERR_UNSPEC_T	0x200	/* Unspec. Error occured before reaching dest*/
#define	NS_ERR_BADSUM_T	0x201	/* Bad Checksum detected in transit */
#define	NS_ERR_UNREACH_HOST	0x202	/* Dest cannot be reached from here*/
#define	NS_ERR_TOO_OLD	0x203	/* Packet x'd 15 routers without delivery*/
#define	NS_ERR_TOO_BIG	0x204	/* Packet too large to be forwarded through
				   some intermediate gateway.  The error
				   parameter field contains the max packet
				   size that can be accommodated */
D 8
#define NS_ERR_ATHOST	4
#define NS_ERR_ENROUTE	5
#define NS_ERR_MAX (NS_ERR_ATHOST + NS_ERR_ENROUTE + 1)
#define ns_err_x(c) (((c)&0x200) ? ((c) - 0x200 + NS_ERR_ATHOST) : c )
E 8
I 8
#define NS_ERR_MAX 20
E 8

/*
 * Variables related to this implementation
 * of the network systems error message protocol.
 */
struct	ns_errstat {
/* statistics related to ns_err packets generated */
	int	ns_es_error;		/* # of calls to ns_error */
	int	ns_es_oldshort;		/* no error 'cuz old ip too short */
	int	ns_es_oldns_err;	/* no error 'cuz old was ns_err */
	int	ns_es_outhist[NS_ERR_MAX];
/* statistics related to input messages processed */
	int	ns_es_badcode;		/* ns_err_code out of range */
	int	ns_es_tooshort;		/* packet < IDP_MINLEN */
	int	ns_es_checksum;		/* bad checksum */
	int	ns_es_badlen;		/* calculated bound mismatch */
	int	ns_es_reflect;		/* number of responses */
	int	ns_es_inhist[NS_ERR_MAX];
I 8
	u_short	ns_es_codes[NS_ERR_MAX];/* which error code for outhist
					   since we might not know all */
E 8
};

#ifdef KERNEL
struct	ns_errstat ns_errstat;
#endif
E 1

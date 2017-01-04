h61945
s 00025/00000/00000
d D 1.1 2011/12/02 05:47:41 msokolov 1 0
c date and time created 2011/12/02 05:47:41 by msokolov
e
u
U
t
T
I 1
/*
 * The structure defined here represents the parsed form of an RR,
 * either read from a binary zone file or extracted from a foreign
 * name server's response.  It must support all RR types which we
 * handle in any way.
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__MSGPARSE_H
#define	__MSGPARSE_H

#include "dname.h"

struct parsedrr {
	struct	dname prr_owner;
	struct	rrfixed prr_fix;
	u_char	*prr_rdata;
	/* currently known RR types have at most 2 <domain-name>s in RDATA */
	struct	dname prr_rdata_dn[2];
	/* the last one is currently used for the trailing fixed part of SOA */
	u_char	*prr_rdata_misc;
};

#endif	/* include guard */
E 1

/*
 * The structure defined here represents the parsed form of an RR,
 * either read from a binary zone file or extracted from a foreign
 * name server's response.  It must support all RR types which we
 * handle in any way.
 *
 *	@(#)msgparse.h	1.1 (IFCTF) 2011/12/02
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

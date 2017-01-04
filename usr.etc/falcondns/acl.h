/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * ACL structure definitions, used for controlling access
 * to udpserv and tcpserv functions.
 *
 *	@(#)acl.h	1.3 (IFCTF) 2013/01/06
 */

#ifndef __ACL_H
#define	__ACL_H

struct aclentry {
	u_long	acl_ipbase;
	u_long	acl_ipmask;
	int	acl_perm;
};

#define	ACL_ALLOW_IDLE		8
#define	ACL_ALLOW_QUERY		4
#define	ACL_ALLOW_RECURSE	2
#define	ACL_ALLOW_AXFR		1

extern struct aclentry tcpserv_acl[];
extern struct aclentry udpserv_acl[];

#endif	/* include guard */

h65163
s 00001/00001/00026
d D 1.3 2013/01/06 07:04:02 msokolov 3 2
c MSDNS => FalconDNS
e
s 00001/00000/00026
d D 1.2 2011/12/13 22:56:14 msokolov 2 1
c idle permission for tcpserv
e
s 00026/00000/00000
d D 1.1 2011/11/01 02:27:22 msokolov 1 0
c date and time created 2011/11/01 02:27:22 by msokolov
e
u
U
t
T
I 1
/*
D 3
 * Michael Sokolov's Domain Name Server (MSDNS)
E 3
I 3
 * FalconDNS daemon by Michael Spacefalcon
E 3
 *
 * ACL structure definitions, used for controlling access
 * to udpserv and tcpserv functions.
 *
 *	%W% (IFCTF) %E%
 */

#ifndef __ACL_H
#define	__ACL_H

struct aclentry {
	u_long	acl_ipbase;
	u_long	acl_ipmask;
	int	acl_perm;
};

I 2
#define	ACL_ALLOW_IDLE		8
E 2
#define	ACL_ALLOW_QUERY		4
#define	ACL_ALLOW_RECURSE	2
#define	ACL_ALLOW_AXFR		1

extern struct aclentry tcpserv_acl[];
extern struct aclentry udpserv_acl[];

#endif	/* include guard */
E 1

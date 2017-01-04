h60590
s 00001/00001/00021
d D 1.4 2013/01/06 07:04:04 msokolov 4 3
c MSDNS => FalconDNS
e
s 00002/00000/00020
d D 1.3 2011/11/02 01:20:20 msokolov 3 2
c query length fields added
e
s 00001/00000/00019
d D 1.2 2011/11/01 23:31:19 msokolov 2 1
c uo_userinfo field added
e
s 00019/00000/00000
d D 1.1 2011/11/01 21:59:24 msokolov 1 0
c started
e
u
U
t
T
I 1
/*
D 4
 * Michael Sokolov's Domain Name Server (MSDNS)
E 4
I 4
 * FalconDNS daemon by Michael Spacefalcon
E 4
 *
 * Data structures for the outbound UDP service
 *
 *	%W% (IFCTF) %E%
 */

#ifndef __UDPOUT_H
#define	__UDPOUT_H

struct udpout {
	int	uo_socket;		/* file descriptor for sendto */
	struct	udpout **uo_slotptr;
	void	(*uo_recv)();
I 3
	u_short	uo_querylen;
	u_short	uo_tcplen;
E 3
	u_char	uo_query[PACKETSZ];
I 2
	caddr_t	uo_userinfo;
E 2
};

#endif	/* include guard */
E 1

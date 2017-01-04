/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Data structures for the outbound UDP service
 *
 *	@(#)udpout.h	1.4 (IFCTF) 2013/01/06
 */

#ifndef __UDPOUT_H
#define	__UDPOUT_H

struct udpout {
	int	uo_socket;		/* file descriptor for sendto */
	struct	udpout **uo_slotptr;
	void	(*uo_recv)();
	u_short	uo_querylen;
	u_short	uo_tcplen;
	u_char	uo_query[PACKETSZ];
	caddr_t	uo_userinfo;
};

#endif	/* include guard */

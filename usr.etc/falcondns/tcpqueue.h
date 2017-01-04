/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Data structures for the outbound TCP service
 *
 *	@(#)tcpqueue.h	1.3 (IFCTF) 2013/01/06
 */

#ifndef __TCPQUEUE_H
#define	__TCPQUEUE_H

struct tcpquery {
	struct	sockaddr_in tq_sin;
	u_char	*tq_query;
	int	tq_querylen;
	caddr_t	tq_userinfo;
	void	(*tq_response_callbk)();
	void	(*tq_error_callbk)();
	struct	tcpquery *tq_next;
};

struct tcpqueue {
	struct	sockaddr_in tqu_sin;
	int	tqu_socket;
	u_char	*tqu_rspbuf;
	int	tqu_rsplen;
	u_char	*tqu_io_ptr;
	int	tqu_io_left;
	struct	timesched *tqu_timeout;
	struct	tcpqueue *tqu_next;
	struct	tcpquery *tqu_queryhead;
	struct	tcpquery **tqu_querytail;
};

#endif	/* include guard */

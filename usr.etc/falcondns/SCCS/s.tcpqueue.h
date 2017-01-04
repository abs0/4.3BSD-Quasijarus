h32087
s 00001/00001/00034
d D 1.3 2013/01/06 07:04:15 msokolov 3 2
c MSDNS => FalconDNS
e
s 00015/00008/00020
d D 1.2 2011/12/17 06:38:04 msokolov 2 1
c tcpqueue revamped
e
s 00028/00000/00000
d D 1.1 2011/12/14 22:33:36 msokolov 1 0
c date and time created 2011/12/14 22:33:36 by msokolov
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
 * Data structures for the outbound TCP service
 *
 *	%W% (IFCTF) %E%
 */

#ifndef __TCPQUEUE_H
#define	__TCPQUEUE_H

D 2
struct tcpqueue {
E 2
I 2
struct tcpquery {
E 2
	struct	sockaddr_in tq_sin;
D 2
	int	tq_socket;
E 2
	u_char	*tq_query;
	int	tq_querylen;
D 2
	u_char	*tq_rspbuf;
	int	tq_rsplen;
	u_char	*tq_io_ptr;
	int	tq_io_left;
	struct	timesched *tq_timeout;
E 2
	caddr_t	tq_userinfo;
	void	(*tq_response_callbk)();
	void	(*tq_error_callbk)();
D 2
	struct	tcpqueue *tq_next;
E 2
I 2
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
E 2
};

#endif	/* include guard */
E 1

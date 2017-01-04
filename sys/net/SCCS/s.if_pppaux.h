h20546
s 00009/00000/00031
d D 7.2 08/04/05 08:26:30 msokolov 2 1
c authentication hooks implemented
e
s 00031/00000/00000
d D 7.1 08/02/18 04:15:04 msokolov 1 0
c date and time created 08/02/18 04:15:04 by msokolov
e
u
U
t
T
I 1
/*
 * 4.3BSD-Quasijarus kernel network subsystem
 *
 * Definitions for the pppaux module
 *
 *	%W% (Berkeley) %G%
 */

/*
 * The pppaux character device provides an auxiliary access channel
 * to a ppp interface for functions like authentication.
 */

#define	PPPAUX_MAXPROTO		8
#define	PPPAUX_RXQ_MAXLEN	10

I 2
#ifdef KERNEL
E 2
struct pppaux_softc {
	struct	ifqueue ppaux_rxq;	/* interlocked at splnet, not splimp */
	u_short	ppaux_protolist[PPPAUX_MAXPROTO];
	short	ppaux_nproto;
	short	ppaux_flags;
	struct	proc *ppaux_rsel;
};

#define	PPPAUX_FLAGS_NBIO	0x0001
#define	PPPAUX_FLAGS_RCOLL	0x0002
I 2
#endif
E 2

struct pppaux_ioctl {
	caddr_t	pauioc_buf;
	u_int	pauioc_count;
I 2
};

struct pppaux_stat_ioctl {
	short	paus_state;
	short	paus_flags;
	struct	ppp_authproto paus_authself;
	struct	ppp_authproto paus_authpeer;
E 2
};
E 1

/*
 * 4.3BSD-Quasijarus kernel network subsystem
 *
 * Definitions for the pppaux module
 *
 *	@(#)if_pppaux.h	7.2 (Berkeley) 4/5/08
 */

/*
 * The pppaux character device provides an auxiliary access channel
 * to a ppp interface for functions like authentication.
 */

#define	PPPAUX_MAXPROTO		8
#define	PPPAUX_RXQ_MAXLEN	10

#ifdef KERNEL
struct pppaux_softc {
	struct	ifqueue ppaux_rxq;	/* interlocked at splnet, not splimp */
	u_short	ppaux_protolist[PPPAUX_MAXPROTO];
	short	ppaux_nproto;
	short	ppaux_flags;
	struct	proc *ppaux_rsel;
};

#define	PPPAUX_FLAGS_NBIO	0x0001
#define	PPPAUX_FLAGS_RCOLL	0x0002
#endif

struct pppaux_ioctl {
	caddr_t	pauioc_buf;
	u_int	pauioc_count;
};

struct pppaux_stat_ioctl {
	short	paus_state;
	short	paus_flags;
	struct	ppp_authproto paus_authself;
	struct	ppp_authproto paus_authpeer;
};

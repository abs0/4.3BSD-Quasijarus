# 1 "../netinet/ip_gre.c"







# 1 "../h/param.h"











































# 46 "../h/param.h"



# 1 "../h/types.h"























typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
typedef	unsigned short	ushort;		


typedef	struct	_physadr { int r[1]; } *physadr;
typedef	struct	label_t	{
	int	val[14];
} label_t;

typedef	struct	_quad { long val[2]; } quad;
typedef	long	daddr_t;
typedef	char *	caddr_t;
typedef	long *	qaddr_t;	
typedef	u_long	ino_t;
typedef	long	swblk_t;
typedef	long	size_t;
typedef	long	time_t;
typedef	short	dev_t;
typedef	long	off_t;
typedef	u_short	uid_t;
typedef	u_short	gid_t;












typedef long	fd_mask;





typedef	struct fd_set {
	fd_mask	fds_bits[	(((256)+(( (sizeof(fd_mask) * 8		)	)-1))/( (sizeof(fd_mask) * 8		)	))];
} fd_set;







# 49 "../h/param.h"








# 1 "../h/signal.h"














# 1 "../h/../machine/trap.h"













































# 15 "../h/signal.h"
# 17 "../h/signal.h"





































# 56 "../h/signal.h"





struct	sigvec {
	int	(*sv_handler)();	
	int	sv_mask;		
	int	sv_flags;		
};







struct	sigstack {
	char	*ss_sp;			
	int	ss_onstack;		
};








struct	sigcontext {
	int	sc_onstack;		
	int	sc_mask;		
	int	sc_sp;			
	int	sc_fp;			
	int	sc_ap;			
	int	sc_pc;			
	int	sc_ps;			
};

















# 57 "../h/param.h"
# 59 "../h/param.h"











# 1 "../h/../machine/machparam.h"















# 1 "./machine/endian.h"
































# 38 "./machine/endian.h"

unsigned short	ntohs(), htons();
unsigned long	ntohl(), htonl();

# 16 "../h/../machine/machparam.h"















































































int	cpuspeed;



# 101 "../h/../machine/machparam.h"

# 70 "../h/param.h"
# 72 "../h/param.h"





















# 96 "../h/param.h"


















































































# 180 "../h/param.h"



# 8 "../netinet/ip_gre.c"

# 1 "../h/mbuf.h"



















# 24 "../h/mbuf.h"












# 38 "../h/mbuf.h"

















struct mbuf {
	struct	mbuf *m_next;		
	u_long	m_off;			
	short	m_len;			
	short	m_type;			
	u_char	m_dat[	(	128			-	12			-	4)	];		
	struct	mbuf *m_act;		
};































































































struct mbstat {
	u_long	m_mbufs;	
	u_long	m_clusters;	
	u_long	m_spare;	
	u_long	m_clfree;	
	u_long	m_drops;	
	u_long	m_wait;		
	u_long	m_drain;	
	u_short	m_mtypes[256];	
};


extern	struct mbuf mbutl[];		
extern	struct pte Mbmap[];		
struct	mbstat mbstat;
int	nmbclusters;
struct	mbuf *mfree, *mclfree;
char	mclrefcnt[512 + 1];
int	m_want;
struct	mbuf *m_get(),*m_getclr(),*m_free(),*m_more(),*m_copy(),*m_pullup();
caddr_t	m_clalloc();

# 9 "../netinet/ip_gre.c"

# 1 "../h/protosw.h"









































struct protosw {
	short	pr_type;		
	struct	domain *pr_domain;	
	short	pr_protocol;		
	short	pr_flags;		

	int	(*pr_input)();		
	int	(*pr_output)();		
	int	(*pr_ctlinput)();	
	int	(*pr_ctloutput)();	

	int	(*pr_usrreq)();		

	int	(*pr_init)();		
	int	(*pr_fasttimo)();	
	int	(*pr_slowtimo)();	
	int	(*pr_drain)();		
};




















































# 121 "../h/protosw.h"




































# 166 "../h/protosw.h"




















# 190 "../h/protosw.h"



extern	struct protosw *pffindproto(), *pffindtype();

# 10 "../netinet/ip_gre.c"

# 1 "../h/socket.h"




























































struct	linger {
	int	l_onoff;		
	int	l_linger;		
};

































struct sockaddr {
	u_short	sa_family;		
	char	sa_data[14];		
};





struct sockproto {
	u_short	sp_family;		
	u_short	sp_protocol;		
};
































struct msghdr {
	caddr_t	msg_name;		
	int	msg_namelen;		
	struct	iovec *msg_iov;		
	int	msg_iovlen;		
	caddr_t	msg_accrights;		
	int	msg_accrightslen;
};






# 11 "../netinet/ip_gre.c"

# 1 "../h/socketvar.h"

























struct socket {
	short	so_type;		
	short	so_options;		
	short	so_linger;		
	short	so_state;		
	caddr_t	so_pcb;			
	struct	protosw *so_proto;	











	struct	socket *so_head;	
	struct	socket *so_q0;		
	struct	socket *so_q;		
	short	so_q0len;		
	short	so_qlen;		
	short	so_qlimit;		
	short	so_timeo;		
	u_short	so_error;		
	short	so_pgrp;		
	u_long	so_oobmark;		



	struct	sockbuf {
		u_long	sb_cc;		
		u_long	sb_hiwat;	
		u_long	sb_mbcnt;	
		u_long	sb_mbmax;	
		u_long	sb_lowat;	
		struct	mbuf *sb_mb;	
		struct	proc *sb_sel;	
		short	sb_timeo;	
		short	sb_flags;	
	} so_rcv, so_snd;






};

















































































struct	socket *sonewconn();

# 12 "../netinet/ip_gre.c"

# 1 "../h/errno.h"

























































	













	













	












# 13 "../netinet/ip_gre.c"

# 1 "../h/syslog.h"
































	





















































# 14 "../netinet/ip_gre.c"


# 1 "../netinet/../net/if.h"

















































struct ifnet {
	char	*if_name;		
	short	if_unit;		
	short	if_mtu;			
	short	if_flags;		
	short	if_timer;		
	int	if_metric;		
	struct	ifaddr *if_addrlist;	
	struct	ifqueue {
		struct	mbuf *ifq_head;
		struct	mbuf *ifq_tail;
		int	ifq_len;
		int	ifq_maxlen;
		int	ifq_drops;
	} if_snd;			

	int	(*if_init)();		
	int	(*if_output)();		
	int	(*if_ioctl)();		
	int	(*if_reset)();		
	int	(*if_watchdog)();	

	int	if_ipackets;		
	int	if_ierrors;		
	int	if_opackets;		
	int	if_oerrors;		
	int	if_collisions;		

	struct	ifnet *if_next;
};






















































































struct ifaddr {
	struct	sockaddr ifa_addr;	
	union {
		struct	sockaddr ifu_broadaddr;
		struct	sockaddr ifu_dstaddr;
	} ifa_ifu;


	struct	ifnet *ifa_ifp;		
	struct	ifaddr *ifa_next;	
};







struct	ifreq {

	char	ifr_name[16];		
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
		struct	sockaddr ifru_broadaddr;
		short	ifru_flags;
		int	ifru_metric;
		short	ifru_mtu;
		caddr_t	ifru_data;
	} ifr_ifru;







};







struct	ifconf {
	int	ifc_len;		
	union {
		caddr_t	ifcu_buf;
		struct	ifreq *ifcu_req;
	} ifc_ifcu;


};



# 1 "../netinet/../net/../net/if_arp.h"





























struct	arphdr {
	u_short	ar_hrd;		

	u_short	ar_pro;		
	u_char	ar_hln;		
	u_char	ar_pln;		
	u_short	ar_op;		










};




struct arpreq {
	struct	sockaddr arp_pa;		
	struct	sockaddr arp_ha;		
	int	arp_flags;			
};






# 223 "../netinet/../net/if.h"
struct	ifqueue rawintrq;		
struct	ifnet *ifnet;
struct	ifaddr *ifa_ifwithaddr(), *ifa_ifwithnet();
struct	ifaddr *ifa_ifwithdstaddr();
struct	ifnet *ifunit();
# 230 "../netinet/../net/if.h"

# 16 "../netinet/ip_gre.c"


# 1 "../netinet/in.h"




























































struct in_addr {
	u_long s_addr;
};































# 97 "../netinet/in.h"







struct sockaddr_in {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};







extern	struct domain inetdomain;
extern	struct protosw inetsw[];
struct	in_addr in_makeaddr();
u_long	in_netof(), in_lnaof();

# 18 "../netinet/ip_gre.c"

# 1 "../netinet/if_ether.h"






















struct	ether_header {
	u_char	ether_dhost[6];
	u_char	ether_shost[6];
	u_short	ether_type;
};























struct	ether_arp {
	struct	arphdr ea_hdr;	
	u_char	arp_sha[6];	
	u_char	arp_spa[4];	
	u_char	arp_tha[6];	
	u_char	arp_tpa[4];	
};












struct	arpcom {
	struct 	ifnet ac_if;		
	u_char	ac_enaddr[6];		
	struct in_addr ac_ipaddr;	
};




struct	arptab {
	struct	in_addr at_iaddr;	
	u_char	at_enaddr[6];		
	u_char	at_timer;		
	u_char	at_flags;		
	struct	mbuf *at_hold;		
};


u_char etherbroadcastaddr[6];
struct	arptab *arptnew();
char *ether_sprintf();

# 19 "../netinet/ip_gre.c"

# 1 "../netinet/in_var.h"

























struct in_ifaddr {
	struct	ifaddr ia_ifa;		




	u_long	ia_net;			
	u_long	ia_netmask;		
	u_long	ia_subnet;		
	u_long	ia_subnetmask;		
	struct	in_addr ia_netbroadcast; 
	int	ia_flags;
	struct	in_ifaddr *ia_next;	
};











struct	in_ifaddr *in_ifaddr;
struct	in_ifaddr *in_iaonnetof();
struct	ifqueue	ipintrq;		

# 20 "../netinet/ip_gre.c"

# 1 "../netinet/ip.h"
































struct ip {

	u_char	ip_hl:4,		
		ip_v:4;			

# 41 "../netinet/ip.h"

	u_char	ip_tos;			
	short	ip_len;			
	u_short	ip_id;			
	short	ip_off;			


	u_char	ip_ttl;			
	u_char	ip_p;			
	u_short	ip_sum;			
	struct	in_addr ip_src,ip_dst;	
};




































struct	ip_timestamp {
	u_char	ipt_code;		
	u_char	ipt_len;		
	u_char	ipt_ptr;		

	u_char	ipt_flg:4,		
		ipt_oflw:4;		

# 100 "../netinet/ip.h"

	union ipt_timestamp {
		n_long	ipt_time[1];
		struct	ipt_ta {
			struct in_addr ipt_addr;
			n_long ipt_time;
		} ipt_ta[1];
	} ipt_timestamp;
};























# 21 "../netinet/ip_gre.c"

# 1 "../netinet/gre.h"
























# 22 "../netinet/ip_gre.c"









int greterm_debug = 0;

gre_input(m, ifp)
	register struct mbuf *m;
	struct ifnet *ifp;
{
	register struct ip *ip;
	register u_short *gre;
	int grelen, grehlen;
	u_short flags;
	register struct mbuf *n;
	int s;

	
	ip = 	(( struct ip *)((int)(m) + (m)->m_off));
	grelen = ip->ip_len;		
	m_adj(m, ip->ip_hl << 2);
	




	if (m->m_off > 	(	128			-	4)		 || m->m_len < 4) {
		m = m_pullup(m, 4);
		if (!m) {
			if (greterm_debug)
				log(7	,
				"greterm: packet too short for GRE header\n");
			return;
		}
	}
	gre = 	(( u_short *)((int)(m) + (m)->m_off));
	
	grehlen = 4;
	flags = ntohs(gre[0]);
	if (flags & 0x8000) {
		grehlen += 4;
		if (in_cksum(m, grelen)) {
			if (greterm_debug)
				log(7	, "greterm: bad checksum\n");
			m_freem(m);
			return;
		}
	}
	if (flags & 0x4000) {
		if (greterm_debug)
			log(7	, "greterm: GRE routing not supported\n");
		m_freem(m);
		return;
	}
	
	if (flags & 0x2000)
		grehlen += 4;
	if (flags & 0x1000)
		grehlen += 4;
	
	if (ntohs(gre[1]) != 0x0800		) {
		if (greterm_debug)
			log(7	,
				"greterm: payload protocol %x is not IP\n",
				ntohs(gre[1]));
		m_freem(m);
		return;
	}
	




	if (grehlen != sizeof(struct ifnet *)) {
		m_adj(m, grehlen);
		n = m_get(0, 2	);
		if (n == 0) {
			m_freem(m);
			return;
		}
		n->m_next = m;
		n->m_off = 	12			;
		n->m_len = sizeof (struct ifnet *);
		m = n;
	}
	*	(( struct ifnet **)((int)(m) + (m)->m_off)) = ifp;
	
	s = splimp();
	 { 	( m)->m_act = 0; 	if ((&ipintrq)->ifq_tail == 0) 		(&ipintrq)->ifq_head =  m; 	else 		(&ipintrq)->ifq_tail->m_act =  m; 	(&ipintrq)->ifq_tail =  m; 	(&ipintrq)->ifq_len++; };
	splx(s);
	




}


# 1 "../net/if_fcs16.c"

























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













































# 14 "../h/signal.h"
# 16 "../h/signal.h"



































# 53 "../h/signal.h"





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



# 26 "../net/if_fcs16.c"

# 1 "../h/mbuf.h"



















# 24 "../h/mbuf.h"










# 36 "../h/mbuf.h"



















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
char	mclrefcnt[256 + 1];
int	m_want;
struct	mbuf *m_get(),*m_getclr(),*m_free(),*m_more(),*m_copy(),*m_pullup();
caddr_t	m_clalloc();

# 27 "../net/if_fcs16.c"

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






# 28 "../net/if_fcs16.c"

# 1 "../h/errno.h"

























































	













	













	












# 29 "../net/if_fcs16.c"


# 1 "../net/if.h"

















































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



# 1 "../net/../net/if_arp.h"





























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






# 223 "../net/if.h"
struct	ifqueue rawintrq;		
struct	ifnet *ifnet;
struct	ifaddr *ifa_ifwithaddr(), *ifa_ifwithnet();
struct	ifaddr *ifa_ifwithdstaddr();
# 229 "../net/if.h"

# 31 "../net/if_fcs16.c"

# 1 "../net/if_fcs16.h"



























extern u_short ccitt_fcs16tab[256];

# 32 "../net/if_fcs16.c"

u_short ccitt_fcs16tab[256] = {
      0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
      0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
      0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
      0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
      0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
      0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
      0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
      0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
      0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
      0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
      0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
      0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
      0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
      0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
      0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
      0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
      0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
      0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
      0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
      0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
      0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
      0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
      0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
      0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
      0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
      0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
      0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
      0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
      0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
      0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
      0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
      0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};


ccitt_addfcs16(m)
	register struct mbuf *m;		
{
	register u_long fcs;			
	register char *cp;			
	register int len;			
	register u_short *table;		

	
	fcs = 0xffff		;
	table = ccitt_fcs16tab;
	while (1) {
		if (len = m->m_len) {
			cp = 	(( char *)((int)(m) + (m)->m_off));

			asm("\n\
			clrl	r0\n\
0:			xorb3	(r9)+,r10,r0\n\
			ashl	$-8,r10,r10\n\
			xorw2	(r7)[r0],r10\n\
			sobgtr	r8,0b");
# 93 "../net/if_fcs16.c"

		}
		if (m->m_next == 0)
			break;
		m = m->m_next;
	}
	
	fcs = fcs ^ 0xFFFF;
	
	if (m->m_off + m->m_len > 	128			 - 2) {
		struct mbuf *n;

		 	{ int ms = splimp(); 	  if ((n)=mfree) 		{ if ((n)->m_type != 	0	) panic("mget"); (n)->m_type =  2	; 		  mbstat.m_mtypes[	0	]--; mbstat.m_mtypes[ 2	]++; 		  mfree = (n)->m_next; (n)->m_next = 0; 		  (n)->m_off = 	12			; } 	  else 		(n) = m_more( 0,  2	); 	  splx(ms); };		
		if (n == 0)
			return(	55		);
		m->m_next = n;
		m = n;
		m->m_len = 0;
	}
	cp = 	(( char *)((int)(m) + (m)->m_off));
	*cp++ = fcs & 0xFF;
	*cp++ = fcs >> 8;
	m->m_len += 2;
	return(0);
}


ccitt_fcs16check(buf, len)
	register char *buf;			
	register int len;			
{
	register u_long fcs;			
	register u_short *table;		

	
	fcs = 0xffff		;
	table = ccitt_fcs16tab;

	asm("\n\
	clrl	r0\n\
0:	xorb3	(r11)+,r9,r0\n\
	ashl	$-8,r9,r9\n\
	xorw2	(r8)[r0],r9\n\
	sobgtr	r8,0b");
# 140 "../net/if_fcs16.c"

	
	if (fcs == 0xf0b8		)
		return(0);
	else
		return(-1);
}

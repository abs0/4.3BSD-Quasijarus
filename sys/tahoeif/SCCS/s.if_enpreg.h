h63572
s 00000/00000/00218
d D 7.1 88/05/31 08:42:54 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00009/00003/00209
d D 1.5 88/05/26 09:42:47 karels 6 4
c lint
e
s 00005/00003/00209
d R 7.1 88/05/21 18:31:07 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00002/00002/00210
d D 1.4 87/12/22 12:24:11 bostic 4 3
c ANSI C compatibility
e
s 00004/00007/00208
d D 1.3 86/12/15 20:26:07 sam 3 2
c lint
e
s 00090/00187/00125
d D 1.2 86/11/29 13:45:39 sam 2 1
c massive rewrites; must debug when hardware shows up
e
s 00312/00000/00000
d D 1.1 86/07/20 11:25:41 sam 1 0
c date and time created 86/07/20 11:25:41 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 *	%W% (Berkeley) %G%
 */
E 6

/*	Copyright (c) 1984 by Communication Machinery Corporation
 *
 *	This file contains material which is proprietary to
 *	Communication Machinery Corporation (CMC) and which
 *	may not be divulged without the written permission
 *	of CMC.
 *
 *	ENP-10 Ram Definition
 *
 *	3/15/85 Jon Phares
 *	Update 7/10/85 S. Holmgren
 *	ENP-10 update 7/21/85 J. Mullen
 *	ENP-20 update 8/11/85 J. Mullen
 *	Mods for CCI TAHOE system 8/14/85 J. Mullen
D 2
 * 
E 2
 */

#define K		*1024

D 2
#define ENPSIZE		(124 K)		/* VME bus space allocated to enp */
#define MINPKTSIZE	60		/* minimum ethernet packet size */

/* Note: paged window (4 K) is identity mapped by ENP kernel to provide
 * 124 K contiguous RAM (as reflected in RAM_SIZE)
 */

#define RAM_WINDOW	(128 K)
#define IOACCESS_WINDOW (512)
#define FIXED_WINDOW	(RAM_WINDOW - IOACCESS_WINDOW)
#define RAMROM_SWAP	(4 K)
#define RAM_SIZE	(FIXED_WINDOW - RAMROM_SWAP)

#define HOST_RAMSIZE	(48 K)
#define ENP_RAMSIZE	(20 K)

/* ...top of 4K local i/o space for ENP */

#ifdef notdef
typedef struct iow10 {
	char	pad1[0x81];
/* written to: causes an interrupt on the host at the vector written
   read from : returns the most significant 8 bits of the slave address */
	char	vector;
	char	pad2[0x1F];
	char	csrarr[0x1E];
	char	pad3[2];
	char	ier;		/* intr. enable reg., 0x80 == enable,0 == off*/
	char	pad4[1];
	char	tir;		/* transmit intr. (Level 4 INP autovector) */
	char	pad5[1];
	char	rir;		/* receive intr. (Level 5 INP autovector) */
	char	pad6[1];
	char	uir;		/* utility intr. (Level 1 INP autovector) */
	char	pad7[7];
	char	mapfirst4k;	/* bit 7 set means ram, clear means rom */
	char	pad8[0x11];
	char	exr;		/* exception register, see bit defines above */
	char	pad9[0xD1F];
	char	hst2enp_interrupt;	/* R or W interrupts ENP */
	char	pad10[0xFF];
	char	hst2enp_reset;	/* R or W resets ENP */
} iow10;
#endif notdef

typedef struct iow20
{
	char	pad0;	
	char	hst2enp_interrupt;
	char	pad1[510];
} iow20;


#ifdef notdef
typedef struct iow30 
{
	char	pad0;
	char	impucsr;
	char 	pad1[0x1d];
	short 	bus2mpu_interrupt;
	short	bs2enp_wsctl;
	short	bs2enp_rsctl;
	short	enp2hst_clear_intr;  /* 0x27 */
	short 	enp_rcv_intr;
	short 	enp_xmit_intr;
	short	hst2enp_interrupt;   /* 0x2d */
	short  	pad2;
	char 	pad3[0xf];
	short	bus_page;	/* Bus page register */	
	char 	pad4[0x1d];
	short	lock_ctrl;
	char 	pad5[0x1d];
	short	duart[0x10];	/* 16 duart regs */
	char 	pad6[0x1f];
	short	bus_window;
} iow30; 
#endif notdef

struct ether_addr
{
E 2
I 2
struct ether_addr {
E 2
	u_char ea_addr[6];
};

D 2
#define ETHADDR		struct ether_addr
#define ETHADDR_SIZE	6		/* size of ethernet address	*/

typedef
struct ethlist
{
E 2
I 2
typedef struct ethlist {
E 2
	int	e_listsize;		/* active addr entries */
D 2
	ETHADDR	e_baseaddr;		/* addr lance is working with */
	ETHADDR e_addrs[ 16 ];		/* possible addresses */
E 2
I 2
	struct	ether_addr e_baseaddr;	/* addr lance is working with */
	struct	ether_addr e_addrs[16];	/* possible addresses */
E 2
} ETHLIST;

D 2
typedef
struct enpstat
{
	unsigned long e_xmit_successful;	/* Successful transmissions */
	unsigned long e_mult_retry;		/* multiple retries on xmit */
	unsigned long e_one_retry;		/* single retries */
	unsigned long e_fail_retry;		/* too many retries */
	unsigned long e_deferrals;		/* transmission delayed due
						   to active medium */
	unsigned long e_xmit_buff_err;		/* xmit data chaining failed --
E 2
I 2
typedef struct {
	u_long	e_xmit_successful;	/* Successful transmissions */
	u_long	e_mult_retry;		/* multiple retries on xmit */
	u_long	e_one_retry;		/* single retries */
	u_long	e_fail_retry;		/* too many retries */
	u_long	e_deferrals;		/* xmit delayed 'cuz cable busy */
	u_long	e_xmit_buff_err;	/* xmit data chaining failed --
E 2
						   "can't happen" */
D 2
	unsigned long e_silo_underrun;		/* transmit data fetch failed */
	unsigned long e_late_coll;		/* collision after xmit */
	unsigned long e_lost_carrier;
	unsigned long e_babble;			/* xmit length > 1518 */
	unsigned long e_collision;
	unsigned long e_xmit_mem_err;
	unsigned long e_rcv_successful;		/* good receptions */
	unsigned long e_rcv_missed;		/* no recv buff available */
	unsigned long e_crc_err;		/* checksum failed */
	unsigned long e_frame_err;		/* crc error AND
						   data length != 0 mod 8 */
	unsigned long e_rcv_buff_err;		/* rcv data chain failure --
E 2
I 2
	u_long	e_silo_underrun;	/* transmit data fetch failed */
	u_long	e_late_coll;		/* collision after xmit */
	u_long	e_lost_carrier;
	u_long	e_babble;		/* xmit length > 1518 */
	u_long	e_collision;
	u_long	e_xmit_mem_err;
	u_long	e_rcv_successful;	/* good receptions */
	u_long	e_rcv_missed;		/* no recv buff available */
	u_long	e_crc_err;		/* checksum failed */
	u_long	e_frame_err;		/* crc error & data length != 0 mod 8 */
	u_long	e_rcv_buff_err;		/* rcv data chain failure --
E 2
						   "can't happen" */
D 2
	unsigned long e_silo_overrun;		/* receive data store failed */
	unsigned long e_rcv_mem_err;
E 2
I 2
	u_long	e_silo_overrun;		/* receive data store failed */
	u_long	e_rcv_mem_err;
E 2
} ENPSTAT;

D 2
typedef struct RING
{
E 2
I 2
typedef struct RING {
E 2
	short	r_rdidx;
	short	r_wrtidx;
	short	r_size;
	short	r_pad;
	int	r_slot[1];
} RING;

D 2
typedef struct RING32
{
E 2
I 2
typedef struct RING32 {
E 2
	short	r_rdidx;
	short	r_wrtidx;
	short	r_size;
	short	r_pad;			/* to make VAXen happy */
D 2
	int	r_slot[ 32 ];
E 2
I 2
	int	r_slot[32];
E 2
} RING32;

/*
D 2
 * 	ENP Ram data layout
 *
 *	If you don't put it here - it isn't there
 *
E 2
I 2
 * ENP Ram data layout
E 2
 */

D 2
typedef struct enpdevice {
E 2
I 2
/*
 * Note: paged window (4 K) is identity mapped by ENP kernel to provide
 * 124 K contiguous RAM (as reflected in RAM_SIZE)
 */
#define RAM_WINDOW	(128 K)
#define IOACCESS_WINDOW (512)
#define FIXED_WINDOW	(RAM_WINDOW - IOACCESS_WINDOW)
#define RAMROM_SWAP	(4 K)
#define RAM_SIZE	(FIXED_WINDOW - RAMROM_SWAP)

#define HOST_RAMSIZE	(48 K)
#define ENP_RAMSIZE	(20 K)

typedef	struct iow20 {
	char	pad0;	
	char	hst2enp_interrupt;
	char	pad1[510];
} iow20;

struct enpdevice {
E 2
#ifdef notdef
	char	enp_ram_rom[4 K];
#endif notdef
	union {
		char	all_ram[RAM_SIZE];
		struct {
D 2
			unsigned int	t_go;
			unsigned int	t_pstart;
E 2
I 2
			u_int	t_go;
			u_int	t_pstart;
E 2
		} t;
		struct {
			char	nram[RAM_SIZE - (HOST_RAMSIZE + ENP_RAMSIZE)];
			char	hram[HOST_RAMSIZE];
			char	kram[ENP_RAMSIZE];
		} u_ram;
D 2
		struct
		{
			char	pad7[ 0x100 ];	/* starts 0x1100 - 0x2000 */
E 2
I 2
		struct {
			char	pad7[0x100];	/* starts 0x1100 - 0x2000 */
E 2
			short	e_enpstate;	/* 1102 */
			short	e_enpmode;	/* 1104 */
			int	e_enpbase;	/* 1104 */
			int	e_enprun;	/* 1108 */
D 2
			unsigned short	e_intrvec;
			unsigned short	e_dummy[3];

E 2
I 2
			u_short	e_intrvec;
			u_short	e_dummy[3];
E 2
			RING32	h_toenp;	/* 110C */
			RING32	h_hostfree;		
			RING32	e_tohost;		
			RING32 	e_enpfree;		
D 2

E 2
			ENPSTAT	e_stat;
			ETHLIST	e_netaddr;		
		} iface;
	} enp_u;
	iow20	enp_iow;
D 2
} ENPDEVICE;
E 2
I 2
};
E 2

#define	enp_ram		enp_u.all_ram
#define	enp_nram	enp_u.u_ram.nram
#define	enp_hram	enp_u.u_ram.hram
#define	enp_kram	enp_u.u_ram.kram
#define	enp_go		enp_u.t.t_go
#define	enp_prog_start	enp_u.t.t_pstart
#define	enp_intrvec	enp_u.iface.e_intrvec
#define enp_state	enp_u.iface.e_enpstate
#define enp_mode	enp_u.iface.e_enpmode
#define enp_base	enp_u.iface.e_enpbase
#define enp_enprun	enp_u.iface.e_enprun
#define enp_toenp	enp_u.iface.h_toenp
#define enp_hostfree	enp_u.iface.h_hostfree
#define enp_tohost	enp_u.iface.e_tohost
#define enp_enpfree	enp_u.iface.e_enpfree
#define enp_freembuf	enp_u.iface.h_freembuf
#define enp_stat	enp_u.iface.e_stat
#define enp_addr	enp_u.iface.e_netaddr

D 2
#define ENPVAL		0xff	/* value to poke in enp_iow.hst2enp_interrupt */
#define RESETVAL	0x00	/* value to poke in enp_iow.enp2hst_clear_intr */
E 2
I 2
#define ENPVAL		0xff	/* enp_iow.hst2enp_interrupt poke value */
#define RESETVAL	0x00	/* enp_iow.enp2hst_clear_intr poke value */
E 2

D 2
#define INTR_ENP(addr)		addr->enp_iow.hst2enp_interrupt = ENPVAL
E 2
I 2
#define INTR_ENP(addr)		(addr->enp_iow.hst2enp_interrupt = ENPVAL)
E 2

#if ENP == 30
D 2
#define ACK_ENP_INTR(addr)	addr->enp_iow.enp2hst_clear_intr = RESETVAL
E 2
I 2
#define ACK_ENP_INTR(addr)	(addr->enp_iow.enp2hst_clear_intr = RESETVAL)
E 2
#define IS_ENP_INTR(addr)	(addr->enp_iow.enp2hst_clear_intr&0x80)
D 2
# else
E 2
I 2
D 3
#else
E 2
#define ACK_ENP_INTR(addr)
D 2
#define IS_ENP_INTR(addr)	( 1 )
E 2
I 2
#define IS_ENP_INTR(addr)	(1)
E 2
#endif ENP == 30
E 3
I 3
#endif
E 3

#ifdef notdef
D 2
#define RESET_ENP(addr)		addr->enp_iow.hst2enp_reset = 01
# else
E 2
I 2
#define RESET_ENP(addr)		(addr->enp_iow.hst2enp_reset = 01)
#else
I 6
#ifdef lint
#define RESET_ENP(addr)		((addr) = (addr))
#else
E 6
E 2
#define RESET_ENP(addr)
I 6
#endif lint
E 6
#endif notdef

D 6
#ifdef TAHOE
E 6
I 6
#ifdef tahoe
E 6
D 2
#define ENP_GO( addr,start )	{int v; v = start; \
			enpcopy(&v, &addr->enp_prog_start, sizeof(v) ); \
			v = 0x80800000; \
			enpcopy( &v, &addr->enp_go, sizeof(v) ); }
E 2
I 2
#define ENP_GO(addr,start) { \
	int v = start; \
D 3
	enpcopy(&v, &addr->enp_prog_start, sizeof(v) ); \
E 3
I 3
	enpcopy((u_char *)&v, (u_char *)&addr->enp_prog_start, sizeof(v) ); \
E 3
	v = 0x80800000; \
D 3
	enpcopy( &v, &addr->enp_go, sizeof(v) ); \
E 3
I 3
	enpcopy((u_char *)&v, (u_char *)&addr->enp_go, sizeof(v) ); \
E 3
}
E 2
#else
D 2
#define ENP_GO( addr,start,intvec ) { addr->enp_prog_start = (unsigned int)(start); \
				addr->enp_intrvec = (unsigned short) intvec; \
				addr->enp_go = 0x80800000; }
E 2
I 2
#define ENP_GO(addr,start,intvec ) { \
	addr->enp_prog_start = (u_int)(start); \
	addr->enp_intrvec = (u_short) intvec; \
	addr->enp_go = 0x80800000; \
}
E 2
D 6
#endif TAHOE
E 6
I 6
#endif tahoe
E 6

D 2
#define SPL_ENP			spl4


E 2
/*
D 2
 * state bits
E 2
I 2
 * State bits
E 2
 */
D 2

E 2
#define S_ENPRESET	01		/* enp is in reset state */
#define S_ENPRUN	02		/* enp is in run state */

/*
D 2
 * mode bits
E 2
I 2
 * Mode bits
E 2
 */
I 2
#define E_SWAP16	0x1		/* swap two octets within 16 */
#define E_SWAP32	0x2		/* swap 16s within 32 */
#define E_SWAPRD	0x4		/* swap on read */
#define E_SWAPWRT	0x8		/* swap on write */
#define E_DMA		0x10		/* enp does data moving */
E 2

D 2
#define E_SWAP16		0x1		/* swap two octets within 16 */
#define E_SWAP32		0x2		/* swap 16s within 32 */
#define E_SWAPRD		0x4		/* swap on read */
#define E_SWAPWRT		0x8		/* swap on write */
#define E_DMA			0x10		/* enp does data moving */
E 2
I 2
#define E_EXAM_LIST	0x80000000	/* enp should examine addrlist */
#define E_ADDR_SUPP	0x40000000	/* enp should use supplied addr */
E 2

D 2
#define E_EXAM_LIST		0x80000000	/*enp should examine addrlist */
#define E_ADDR_SUPP		0x40000000	/*enp should use supplied addr*/


E 2
/*
D 2
 * 	Download ioctl definitions
E 2
I 2
 * Download ioctl definitions
E 2
 */
I 2
D 4
#define ENPIOGO		_IO(S,1)		/* start the enp */
#define ENPIORESET	_IO(S,2)		/* reset the enp */
E 4
I 4
#define ENPIOGO		_IO('S',1)		/* start the enp */
#define ENPIORESET	_IO('S',2)		/* reset the enp */
E 4
E 2

D 2
#define mkioctl(type,value) (0x20000000|('type'<<8)|value)

#define ENPIOGO		mkioctl( S,1 )		/* start the enp */
#define ENPIORESET	mkioctl( S,2 )		/* reset the enp */

E 2
/*
D 2
 * 	The ENP Data Buffer Structure
E 2
I 2
 * The ENP Data Buffer Structure
E 2
 */
D 2

typedef struct BCB
{
	struct BCB *b_link;
E 2
I 2
typedef struct BCB {
	struct	BCB *b_link;
E 2
	short	 b_stat;
	short	 b_len;
D 3
	char	*b_addr;
E 3
I 3
	u_char	*b_addr;
E 3
	short	 b_msglen;
	short	 b_reserved;
D 2
}BCB;

struct  enp_softc 
{
	struct  arpcom es_ac;           /* common ethernet structures */
	struct	ether_addr es_boardaddr;/* board ethernet address */
}; 

#define es_if           es_ac.ac_if     /* network-visible interface */
#define es_enaddr       es_ac.ac_enaddr /* hardware ethernet address */

#define	ENP_OPEN	1		/* device enpram opened	*/
#define ENP_CLOSE	2		/* device enpram closed	*/
E 2
I 2
} BCB;
E 2
E 1

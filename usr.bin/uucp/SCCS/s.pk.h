h33252
s 00003/00016/00109
d D 5.6 88/04/05 12:07:26 rick 7 6
c remove dead code
e
s 00004/00007/00121
d D 5.5 88/02/24 20:00:20 rick 6 5
c increase WINDOWS for better throughput. remove TAILSIZE(stupid)
e
s 00007/00011/00121
d D 5.4 86/01/06 15:02:08 bloom 5 4
c more fixes from rick adams
e
s 00005/00000/00127
d D 5.3 85/04/10 15:20:08 ralph 4 3
c more changes from rick adams.
e
s 00006/00008/00121
d D 5.2 85/01/22 14:28:27 ralph 3 1
c bug fixes & changes from Rick Adams
e
s 00009/00009/00120
d R 5.2 85/01/22 14:09:37 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00129/00000/00000
d D 5.1 83/07/02 17:56:12 sam 1 0
c date and time created 83/07/02 17:56:12 by sam
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
D 7
/*	%W%	%G%	*/
E 7
I 7
/*	%W%	(Berkeley)	%G%	*/
E 7
E 6

struct header {
	char	sync;
	char	ksize;
	unsigned short sum;
	char	cntl;
	char	ccntl;
};
I 3

E 3
D 5
#define	HDRSIZ	6
I 3
#define	PACKSIZE	64
#define WINDOWS	3
E 5
I 5
#define	HDRSIZ		6	/* Packet header size */
#define	PACKSIZE	64	/* Standard packet size */
D 6
#define WINDOWS		3
E 6
I 6
D 7
#define WINDOWS		7
E 7
I 7
#define WINDOWS		7	/* number of outstanding un-ack'd packets */
E 7
E 6
E 5
E 3

I 5
D 6
#define TAILSIZE	2	/* Number of trailing nulls after packet    */
E 6
I 6
D 7
#define TAILSIZE	0	/* Number of trailing nulls after packet    */
E 6

E 7
E 5
struct pack {
	short	p_state;	/* line state */
	short	p_bits;		/* mask for getepack */
	short	p_rsize;	/* input packet size */
	short	p_xsize;	/* output packet size */
	struct	header p_ihbuf;	/* input header */
	struct	header p_ohbuf; /* output header */
	char	*p_rptr;
D 6
	char	p_mode;
E 6
	char	**p_ipool;
	char	p_xcount;	/* # active output buffers */
	char	p_rcount;
D 6
	char	p_nout,p_tout;
E 6
	char	p_lpsize;	/* log(psize/32) */
D 6
	char	p_timer;
	char	p_obusy;
E 6
I 6
	char	p_obusy;	/* output busy? for reentrant pkoutput() */
E 6
	char	p_srxmit;
	char	p_rwindow;	/* window size */
	char	p_swindow;
	char	p_msg;		/* control msg */
	char	p_rmsg;		/* repeated control msg */
	char	p_ps,p_pr;	/* last packet sent, recv'd */
	char	p_rpr;
	char	p_nxtps;	/* next output seq number */
	char	p_imap;		/* bit map of input buffers */
	char	p_pscopy;	/* newest output packet */
	char	*p_ob[8];	/* output buffers */
	char	*p_ib[8];	/* input buffers */
	char	p_os[8];	/* output buffer status */
	char	p_is[8];	/* input buffer status */
	short	p_osum[8];	/* output checksums */
	short	p_isum[8];	/* input checksums */
D 3
	DSYSTEM;
E 3
I 3
	int p_ifn, p_ofn;
E 3
};
I 3

E 3
#define	CHECK	0125252
#define	SYN	020
#define	MOD8	7
I 3
D 5
#define	PKASSERT(e, s1, s2, i1) if (!(e)) {assert(s1, s2, i1);pkfail();} else
E 5
E 3
#define	ISCNTL(a)	((a & 0300)==0)
/* MIN may have been defined in <sys/param.h> */
#undef	MIN
#define	MIN(a,b)	((a<b)? a:b)

extern char	next[8];
extern char	mask[8];
D 5
extern int	npbits;
extern int	pkactive;
E 5

/*
 * driver state
 */
#define	DEAD	0
#define	INITa	1
#define	INITb	2
#define	INITab	3
#define	LIVE	010
#define	RXMIT	020
#define	RREJ	040
#define PDEBUG	0200
#define	DRAINO	0400
#define	WAITO	01000
#define	DOWN	02000
#define	RCLOSE	04000
#define	BADFRAME 020000

/*
 * io buffer states
 */
#define	B_NULL	0
#define	B_READY	1
#define	B_SENT	2
#define	B_RESID	010
#define	B_COPY	020
#define	B_MARK	040
#define	B_SHORT	0100

I 4
/* read or write */

#define B_WRITE	0
#define B_READ	1

E 4
/*
 * control messages
 */
#define	CLOSE	1
#define	RJ	2
#define	SRJ	3
#define	RR	4
#define	INITC	5
#define	INITB	6
#define	INITA	7

D 5
#define	M_RJ	4
E 5
I 5
#define	M_CLOSE	002
#define	M_RJ	004
E 5
#define	M_SRJ	010
#define	M_RR	020
#define	M_INITC	040
D 5
#define	M_CLOSE	2
E 5
#define	M_INITA	0200
#define	M_INITB	0100

D 3


E 3
D 5
#define	PKOPRI	31
#define	PKIPRI	30
E 5
D 3

/*
 * allegra.1402, allegra!honey, Peter Honeyman. Increase PKLINES
 * to avoid PKSTART FAILEDs.  (This is a kludge.)
 */
E 3
D 7
#define	NPLINES	20

/*
 * packet ioctl buf
 */
struct	piocb {
	unsigned t;
	short	psize;
	short	mode;
	short	state;
	char	window;
};
E 7
I 7
#define	NPLINES	2
E 7

D 5
extern int pkdebug;
E 5
extern int pksizes[];
E 1

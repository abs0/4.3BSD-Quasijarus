h07806
s 00003/00000/00209
d D 4.4 83/07/03 17:35:31 sam 7 6
c quiet cpp
e
s 00002/00002/00207
d D 4.3 83/07/02 22:33:42 sam 6 5
c include fixes
e
s 00006/00006/00203
d D 4.2 81/04/13 20:05:17 eric 5 4
c fix SZLNAM botch
e
s 00004/00004/00205
d D 4.1 81/04/13 19:53:45 eric 4 2
c know about size of login name
e
s 00002/00002/00207
d R 1.3 81/04/13 19:50:18 eric 3 2
c use SZLNAM internally
e
s 00003/00002/00206
d D 1.2 81/04/13 16:09:08 eric 2 1
c know about 8-char login names
e
s 00208/00000/00000
d D 1.1 81/04/13 16:00:27 eric 1 0
c date and time created 81/04/13 16:00:27 by eric
e
u
U
t
T
I 1
D 6
# include	"stdio.h"
E 6
I 6
# include	<stdio.h>
# include	<sys/time.h>
E 6
# include	"../hdr/macros.h"
# include	"../hdr/fatal.h"
D 6
# include	"time.h"
E 6

/*
 *	defines.h 2.3 of 5/18/78
I 2
 *	%M% %I% of %G%
E 2
 */

# define CTLSTR		"%c%c\n"

# define CTLCHAR	1
# define HEAD		'h'

# define STATS		's'

# define BDELTAB	'd'
# define INCLUDE	'i'
# define EXCLUDE	'x'
# define IGNORE		'g'
# define MRNUM		'm'
# define COMMENTS	'c'
# define EDELTAB	'e'

# define BUSERNAM	'u'
# define EUSERNAM	'U'

# define NFLAGS	26

# define FLAG		'f'
# define NULLFLAG	'n'
# define DEFTFLAG	'd'
# define TYPEFLAG	't'
# define VALFLAG	'v'
# define BRCHFLAG	'b'
# define IDFLAG		'i'
# define MODFLAG	'm'
# define FLORFLAG	'f'
# define CEILFLAG	'c'

# define BUSERTXT	't'
# define EUSERTXT	'T'

# define INS		'I'
# define DEL		'D'
# define END		'E'

# define FILESIZE	510
I 7
#ifdef MAX
#undef MAX
#endif
E 7
# define MAX		9999
# define DELIVER	'*'

/*
	Declares for external subroutines and/or functions
*/

extern	char	*sname();
extern	char	*cat();
extern	char	*dname();
extern	char	*repeat();
extern	char	*satoi();
extern	char	*strend();
extern	char	*substr();
extern	char	*trnslat();
extern	char	*zero();
extern	char	*zeropad();

/*
I 5
	size of login name
*/
# define SZLNAM	9	/* size of login name */
# define LNLNAM	8	/* length of login name */

/*
E 5
	SCCS Internal Structures.
*/

struct apply {
	char	a_inline;	/* in the line of normally applied deltas */
	char	a_code;		/* APPLY, NOAPPLY or EMPTY */
	int	a_reason;
};
#define APPLY	  (1)
#define NOAPPLY  (-1)
#define EMPTY	  (0)

# define IGNR		0100
# define USER		040
# define INCL		1
# define EXCL		2
# define CUTOFF		4
# define INCLUSER	(USER | INCL)
# define EXCLUSER	(USER | EXCL)
# define IGNRUSER	(USER | IGNR)


struct queue {
	struct queue *q_next;
	int    q_sernum;	/* serial number */
	char    q_keep;		/* keep switch setting */
	char	q_iord;		/* INS or DEL */
	char	q_ixmsg;	/* caused inex msg */
	char	q_user;		/* inex'ed by user */
};
#define YES	 (1)
#define NO	(-1)


struct	sid {
	int	s_rel;
	int	s_lev;
	int	s_br;
	int	s_seq;
};


struct	deltab {
	struct	sid	d_sid;
	int	d_serial;
	int	d_pred;
	long	d_datetime;
D 4
	char	d_pgmr[8];
E 4
I 4
	char	d_pgmr[SZLNAM];
E 4
	char	d_type;
};

struct	ixg {
	struct	ixg	*i_next;
	char	i_type;
	char	i_cnt;
	int	i_ser[1];
};


struct	idel {
	struct	sid	i_sid;
	struct	ixg	*i_ixg;
	int	i_pred;
	long	i_datetime;
};


# define maxser(pkt)	((pkt)->p_idel->i_pred)
# define sccsfile(f)	imatch("s.", sname(f))

struct packet {
	char	p_file[FILESIZE];	/* file name containing module */
	struct	sid	p_reqsid;	/* requested SID, then new SID */
	struct	sid	p_gotsid;	/* gotten SID */
	struct	sid	p_inssid;	/* SID which inserted current line */
	char	p_verbose;	/* verbose flags (see #define's below) */
	char	p_upd;		/* update flag (!0 = update mode) */
	long	p_cutoff;	/* specified cutoff date-time */
	int	p_ihash;	/* initial (input) hash */
	int	p_chash;	/* current (input) hash */
	int	p_nhash;	/* new (output) hash */
	int	p_glnno;	/* line number of current gfile line */
	int	p_slnno;	/* line number of current input line */
	char	p_wrttn;		/* written flag (!0 = written) */
	char	p_keep;		/* keep switch for readmod() */
	struct	apply	*p_apply;	/* ptr to apply array */
	struct	queue	*p_q;	/* ptr to control queue */
	FILE	*p_iop;		/* input file */
	char	p_buf[BUFSIZ];	/* input file buffer */
	char	p_line[BUFSIZ];	/* buffer for getline() */
	long	p_cdt;		/* date/time of newest applied delta */
	char	*p_lfile;	/* 0 = no l-file; else ptr to l arg */
	struct	idel	*p_idel;	/* ptr to internal delta table */
	FILE	*p_stdout;	/* standard output for warnings and messages */
	FILE	*p_gout;	/* g-file output file */
	char	p_user;		/* !0 = user on user list */
	char	p_chkeof;	/* 0 = eof generates error */
	int	p_maxr;		/* largest release number */
	int	p_ixmsg;	/* inex msg counter */
	int	p_reopen;	/* reopen flag used by getline on eof */
	int	p_ixuser;	/* HADI | HADX (in get) */
	int	do_chksum;	/* for getline(), 1 = do check sum */
};
/*
	Masks for p_verbose
*/

# define RLACCESS	(1)
# define NLINES		(2)
# define DOLIST		(4)
# define UNACK		(8)
# define NEWRL		(16)
# define WARNING	(32)
D 5

/*
	size of login name
*/
D 2
# define SZLNAM	(8)	/* size of login name */
# define LNLNAM	(7)	/* length of login name */
E 2
I 2
D 4
# define SZLNAM	(9)	/* size of login name */
# define LNLNAM	(8)	/* length of login name */
E 4
I 4
# define SZLNAM	9	/* size of login name */
# define LNLNAM	8	/* length of login name */
E 5
E 4
E 2


struct	stats {
	int	s_ins;
	int	s_del;
	int	s_unc;
};


struct	pfile	{
	struct	sid	pf_gsid;
	struct	sid	pf_nsid;
D 4
	char	pf_user[8];
E 4
I 4
	char	pf_user[SZLNAM];
E 4
	long	pf_date;
	char	*pf_ilist;
	char	*pf_elist;
};


# define RESPSIZE	512
# define NVARGS	64
# define VSTART 3
E 1

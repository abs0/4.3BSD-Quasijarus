h58712
s 00036/00045/00386
d D 5.11 88/04/05 12:08:38 rick 12 11
c use syslog for errors, fix ancient bug with packets > 128 (free speedup in the process)
e
s 00002/00001/00429
d D 5.10 88/02/24 20:01:19 rick 11 10
c fix stupid error in protocol handling introduced in 4.3bsd
e
s 00004/00003/00426
d D 5.9 86/05/30 10:29:15 bloom 10 9
c use proper sequence number, use variable retry rates
e
s 00005/00001/00424
d D 5.8 86/03/24 08:46:17 bloom 9 8
c fix loss of input buffers
e
s 00040/00042/00385
d D 5.7 86/01/06 15:02:21 bloom 8 7
c more fixes from rick adams
e
s 00009/00006/00418
d D 5.6 85/10/09 16:14:57 bloom 7 6
c change parameters (from rick@seismo)
e
s 00006/00009/00418
d D 5.5 85/06/24 10:25:09 bloom 6 4
c more fixes from rick adams
e
s 00006/00009/00418
d R 5.5 85/06/24 10:24:07 bloom 5 4
c mroe fixes from rick adams
e
s 00004/00003/00423
d D 5.4 85/06/20 10:11:42 bloom 4 3
c fixes from rick adams
e
s 00030/00038/00396
d D 5.3 85/04/10 15:20:37 ralph 3 2
c more changes from rick adams.
e
s 00143/00105/00291
d D 5.2 85/01/22 14:10:28 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00396/00000/00000
d D 5.1 83/07/02 17:57:22 sam 1 0
c date and time created 83/07/02 17:57:22 by sam
e
u
U
t
T
I 1
#ifndef lint
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char sccsid[] = "%W%	(Berkeley) %G%";
E 12
#endif

I 4
#include <signal.h>
E 4
D 2
extern	char	*malloc();

#define USER	1
#include <stdio.h>
#ifdef SYSIII
E 2
I 2
D 3
#ifdef USG
E 2
#include <sys/types.h>
D 2
#endif
#include "pk.p"
E 2
I 2
#endif USG
E 2
#include <sys/param.h>
#include "pk.h"
E 3
I 2
#include "uucp.h"
E 2
D 3
#include <sys/buf.h>
E 3
I 3
#include "pk.h"
E 3
#include <setjmp.h>
D 4
#include <signal.h>
E 4
I 2
#ifdef BSD4_2
#include <sys/time.h>
D 12
#endif BSD4_2
E 12
I 12
#include <sys/uio.h>
#else /* !BSD4_2 */
struct iovec {
	caddr_t iov_base;
	int iov_len;
}
#endif /* !BSD4_2 */
E 12
E 2

I 2
#ifdef VMS
#include <eunice/eunice.h>
#include <vms/iodef.h>
#include <vms/ssdef.h>
int iomask[2];
#endif VMS
E 2

#define PKMAXSTMSG 40
D 6
#define	PKTIME	25
E 6
I 6
D 7
#define	PKTIME 5
E 7
I 7
D 8
#define	PKTIME	25
E 8
I 8
#define	MAXPKTIME 32	/* was 16 */
E 8
E 7
E 6
I 2
#define CONNODATA 10
D 6
#define NTIMEOUT 10
E 6
I 6
D 7
#define NTIMEOUT 30
E 7
I 7
D 8
#define NTIMEOUT 10
E 8
I 8
#define MAXTIMEOUT 32
E 8
E 7
E 6

E 2
D 4
extern int Errorrate;
E 4
I 2
extern int errno;
I 4
extern int Retries;
E 4
extern char *sys_errlist[];
extern jmp_buf Sjbuf;
extern	char *malloc();

E 2
int Connodata = 0;
int Ntimeout = 0;
I 8
int pktimeout = 4;
I 10
int pktimeskew = 2;
E 10
E 8
D 2
#define CONNODATA 10
#define NTIMEOUT 50
E 2
/*
 * packet driver support routines
 *
 */

D 4
struct pack *pklines[NPLINES];
E 4
I 4
extern struct pack *pklines[];
E 4

/*
 * start initial synchronization.
 */

struct pack *
pkopen(ifn, ofn)
int ifn, ofn;
{
	register struct pack *pk;
	register char **bp;
	register int i;

D 8
	if (++pkactive >= NPLINES)
D 2
		return(NULL);
E 2
I 2
		return NULL;
E 8
E 2
	if ((pk = (struct pack *) malloc(sizeof (struct pack))) == NULL)
D 2
		return(NULL);
	pkzero((caddr_t) pk, sizeof (struct pack));
E 2
I 2
		return NULL;
	bzero((caddr_t) pk, sizeof (struct pack));
E 2
	pk->p_ifn = ifn;
	pk->p_ofn = ofn;
	pk->p_xsize = pk->p_rsize = PACKSIZE;
	pk->p_rwindow = pk->p_swindow = WINDOWS;
	/*  allocate input windows */
	for (i = 0; i < pk->p_rwindow; i++) {
D 2
		if ((bp = (char **) GETEPACK) == NULL)
E 2
I 2
		if ((bp = (char **) malloc((unsigned)pk->p_xsize)) == NULL)
E 2
			break;
		*bp = (char *) pk->p_ipool;
		pk->p_ipool = bp;
	}
D 8
	if (i == 0)
E 8
I 8
	if (i == 0) {
		DEBUG(1, "pkopen: can't malloc i = 0\n", CNULL);
E 8
D 2
		return(NULL);
E 2
I 2
		return NULL;
I 8
	}
E 8
E 2
	pk->p_rwindow = i;

	/* start synchronization */
	pk->p_msg = pk->p_rmsg = M_INITA;
	for (i = 0; i < NPLINES; i++) {
		if (pklines[i] == NULL) {
			pklines[i] = pk;
			break;
		}
	}
D 8
	if (i >= NPLINES)
E 8
I 8
	if (i >= NPLINES) {
		DEBUG(1,"pkopen: i>=NPLINES\n", CNULL);
E 8
D 2
		return(NULL);
E 2
I 2
		return NULL;
I 8
	}
E 8
E 2
	pkoutput(pk);

	for (i = 0; i < PKMAXSTMSG; i++) {
D 2
		PKGETPKT(pk);
E 2
I 2
		pkgetpack(pk);
E 2
		if ((pk->p_state & LIVE) != 0)
			break;
	}
D 8
	if (i >= PKMAXSTMSG)
E 8
I 8
	if (i >= PKMAXSTMSG) {
		DEBUG(1, "pkopen: i>= PKMAXSTMSG\n", CNULL);
E 8
D 2
		return(NULL);
E 2
I 2
		return NULL;
I 8
	}
E 8
E 2

	pkreset(pk);
D 2
	return(pk);
E 2
I 2
	return pk;
E 2
}


/*
 * input framing and block checking.
 * frame layout for most devices is:
D 2
 *	
E 2
I 2
 *
E 2
 *	S|K|X|Y|C|Z|  ... data ... |
 *
 *	where 	S	== initial synch byte
 *		K	== encoded frame size (indexes pksizes[])
 *		X, Y	== block check bytes
 *		C	== control byte
 *		Z	== XOR of header (K^X^Y^C)
 *		data	== 0 or more data bytes
 *
 */

int pksizes[] = {
	1, 32, 64, 128, 256, 512, 1024, 2048, 4096, 1
};

D 6
#define GETRIES 5
E 6
I 6
D 7
#define GETRIES 10
E 7
I 7
D 8
#define GETRIES 5
E 8
I 8
#define GETRIES 10
E 8
E 7
E 6
/*
 * Pseudo-dma byte collection.
 */

D 8
pkgetpack(ipk)
struct pack *ipk;
E 8
I 8
pkgetpack(pk)
register struct pack *pk;
E 8
{
D 2
	int ret, k, tries;
E 2
I 2
	int k, tries, noise;
E 2
	register char *p;
D 8
	register struct pack *pk;
E 8
	register struct header *h;
	unsigned short sum;
	int ifn;
	char **bp;
	char hdchk;

D 2
	pk = PADDR;
	if ((pk->p_state & DOWN) ||
	  Connodata > CONNODATA /* || Ntimeout > NTIMEOUT */)
E 2
I 2
D 8
	pk = ipk;
	if ((pk->p_state & DOWN) || Connodata > CONNODATA || Ntimeout > NTIMEOUT)
E 8
I 8
	if ((pk->p_state & DOWN) || Connodata > CONNODATA || Ntimeout > MAXTIMEOUT)
E 8
E 2
		pkfail();
	ifn = pk->p_ifn;

	/* find HEADER */
D 2
	for (tries = 0; tries < GETRIES; ) {
E 2
I 2
	for (tries = 0, noise = 0; tries < GETRIES; ) {
E 2
		p = (caddr_t) &pk->p_ihbuf;
D 2
		if ((ret = pkcget(ifn, p, 1)) < 0) {
			/* set up retransmit or REJ */
			tries++;
			pk->p_msg |= pk->p_rmsg;
			if (pk->p_msg == 0)
				pk->p_msg |= M_RR;
			if ((pk->p_state & LIVE) == LIVE)
				pk->p_state |= RXMIT;
			pkoutput(pk);
			continue;
E 2
I 2
		if (pkcget(ifn, p, 1) == SUCCESS) {
			if (*p++ == SYN) {
				if (pkcget(ifn, p, HDRSIZ-1) == SUCCESS)
					break;
D 8
			} else
				if (noise++ < (3*pk->p_rsize))
E 8
I 8
			} else {
				if (noise++ < 10 || noise < (3*pk->p_rsize))
E 8
					continue;
D 8
			DEBUG(4, "Noisy line - set up RXMIT", "");
E 8
I 8
			}
			DEBUG(4, "Noisy line - set up RXMIT\n", CNULL);
E 8
			noise = 0;
E 2
		}
I 2
		/* set up retransmit or REJ */
		tries++;
I 4
		Retries++;
E 4
		pk->p_msg |= pk->p_rmsg;
		if (pk->p_msg == 0)
			pk->p_msg |= M_RR;
		if ((pk->p_state & LIVE) == LIVE)
			pk->p_state |= RXMIT;
		pkoutput(pk);
D 8

E 2
		if (*p != SYN)
			continue;
		p++;
D 2
		ret = pkcget(ifn, p, HDRSIZ - 1);
		if (ret == -1)
			continue;
		break;
E 2
I 2
		if (pkcget(ifn, p, HDRSIZ - 1) == SUCCESS)
			break;
E 8
E 2
	}
	if (tries >= GETRIES) {
D 2
		PKDEBUG(4, "tries = %d\n", tries);
E 2
I 2
		DEBUG(4, "tries = %d\n", tries);
E 2
		pkfail();
	}

	Connodata++;
D 8
	h = (struct header * ) &pk->p_ihbuf;
E 8
I 8
	h = (struct header *) &pk->p_ihbuf;
E 8
	p = (caddr_t) h;
	hdchk = p[1] ^ p[2] ^ p[3] ^ p[4];
	p += 2;
	sum = (unsigned) *p++ & 0377;
	sum |= (unsigned) *p << 8;
	h->sum = sum;
D 2
	PKDEBUG(7, "rec h->cntl %o\n", (unsigned) h->cntl);
E 2
I 2
	DEBUG(7, "rec h->cntl 0%o\n", h->cntl&0xff);
E 2
	k = h->ksize;
	if (hdchk != h->ccntl) {
		/* bad header */
D 2
		PKDEBUG(7, "bad header %o,", hdchk);
		PKDEBUG(7, "h->ccntl %o\n", h->ccntl);
E 2
I 2
		DEBUG(7, "bad header 0%o,", hdchk&0xff);
		DEBUG(7, "h->ccntl 0%o\n", h->ccntl&0xff);
E 2
		return;
	}
	if (k == 9) {
		if (((h->sum + h->cntl) & 0xffff) == CHECK) {
			pkcntl(h->cntl, pk);
D 2
			PKDEBUG(7, "state - %o\n", pk->p_state);
		}
		else {
E 2
I 2
			DEBUG(7, "state - 0%o\n", pk->p_state);
		} else {
E 2
			/*  bad header */
D 2
			PKDEBUG(7, "bad header (k==9) %o\n", h->cntl);
E 2
			pk->p_state |= BADFRAME;
I 2
			DEBUG(7, "bad header (k==9) 0%o\n", h->cntl&0xff);
E 2
		}
		return;
	}
	if (k && pksizes[k] == pk->p_rsize) {
D 10
		pk->p_rpr = h->cntl & MOD8;
E 10
I 10
D 11
		pk->p_rpr = (h->cntl >> 3) & MOD8;
E 11
I 11
		pk->p_rpr = h->cntl & MOD8;
		DEBUG(7, "end pksack 0%o\n", pk->p_rpr);
E 11
E 10
		pksack(pk);
D 8
		Connodata = 0;
E 8
		bp = pk->p_ipool;
D 2
		pk->p_ipool = (char **) *bp;
E 2
		if (bp == NULL) {
D 2
			PKDEBUG(7, "bp NULL %s\n", "");
		return;
E 2
I 2
			DEBUG(7, "bp NULL %s\n", "");
			return;
E 2
		}
D 2
	}
	else {
E 2
I 2
		pk->p_ipool = (char **) *bp;
D 8
	} else {
E 8
I 8
		Connodata = 0;
	} else
E 8
E 2
		return;
D 8
	}
E 8
I 8

E 8
D 2
	ret = pkcget(pk->p_ifn, (char *) bp, pk->p_rsize);
	if (ret == 0)
E 2
I 2
D 9
	if (pkcget(pk->p_ifn, (char *) bp, pk->p_rsize) == SUCCESS)
E 9
I 9
	if (pkcget(pk->p_ifn, (char *) bp, pk->p_rsize) == SUCCESS) {
E 9
E 2
		pkdata(h->cntl, h->sum, pk, (char **) bp);
I 9
	} else {
		*bp = (char *)pk->p_ipool;
		pk->p_ipool = bp;
	}
E 9
D 2
	return;
E 2
I 2
D 8
	Ntimeout = 0;
E 8
E 2
}

D 2

E 2
pkdata(c, sum, pk, bp)
char c;
unsigned short sum;
register struct pack *pk;
char **bp;
{
D 2
register x;
int t;
char m;
E 2
I 2
	register x;
D 12
	int t;
	char m;
E 12
I 12
	register int t;
E 12
E 2

	if (pk->p_state & DRAINO || !(pk->p_state & LIVE)) {
		pk->p_msg |= pk->p_rmsg;
		pkoutput(pk);
		goto drop;
	}
	t = next[pk->p_pr];
D 12
	for(x=pk->p_pr; x!=t; x = (x-1)&7) {
		if (pk->p_is[x] == 0)
			goto slot;
E 12
I 12
	for(x = pk->p_pr; x != t; x = (x-1)&7) {
		if (pk->p_is[x] == 0) {
			pk->p_imap |= mask[x];
			pk->p_is[x] = c;
			pk->p_isum[x] = sum;
			pk->p_ib[x] = (char *)bp;
			return;
		}
E 12
	}
drop:
	*bp = (char *)pk->p_ipool;
	pk->p_ipool = bp;
D 12
	return;

slot:
	m = mask[x];
	pk->p_imap |= m;
	pk->p_is[x] = c;
	pk->p_isum[x] = sum;
	pk->p_ib[x] = (char *)bp;
E 12
D 2
	return;
E 2
}

D 8


E 8
/*
 * setup input transfers
D 12
 */
D 2
pkrstart(pk)
{}

E 2
#define PKMAXBUF 128
/*
E 12
I 12
 *
E 12
 * Start transmission on output device associated with pk.
 * For asynch devices (t_line==1) framing is
 * imposed.  For devices with framing and crc
 * in the driver (t_line==2) the transfer is
 * passed on to the driver.
 */
pkxstart(pk, cntl, x)
register struct pack *pk;
char cntl;
register x;
{
	register char *p;
D 2
	int ret;
E 2
	short checkword;
	char hdchk;

	p = (caddr_t) &pk->p_ohbuf;
	*p++ = SYN;
	if (x < 0) {
		*p++ = hdchk = 9;
		checkword = cntl;
D 8
	}
	else {
E 8
I 8
	} else {
E 8
		*p++ = hdchk = pk->p_lpsize;
		checkword = pk->p_osum[x] ^ (unsigned)(cntl & 0377);
	}
	checkword = CHECK - checkword;
	*p = checkword;
	hdchk ^= *p++;
	*p = checkword>>8;
	hdchk ^= *p++;
	*p = cntl;
	hdchk ^= *p++;
	*p = hdchk;
D 2
 /*  writes  */
PKDEBUG(7, "send %o\n", (unsigned) cntl);
E 2
I 2
	/*  writes  */
	DEBUG(7, "send 0%o\n", cntl&0xff);
E 2
	p = (caddr_t) & pk->p_ohbuf;
	if (x < 0) {
D 2
#ifdef PROTODEBUG
		GENERROR(p, HDRSIZ);
#endif
		ret = write(pk->p_ofn, p, HDRSIZ);
		PKASSERT(ret == HDRSIZ, "PKXSTART ret", "", ret);
E 2
I 2
		if(write(pk->p_ofn, p, HDRSIZ) != HDRSIZ) {
			alarm(0);
			logent("PKXSTART write failed", sys_errlist[errno]);
			longjmp(Sjbuf, 4);
		}
E 2
D 8
	}
	else {
		char buf[PKMAXBUF + HDRSIZ], *b;
E 8
I 8
	} else {
D 12
		char buf[PKMAXBUF + HDRSIZ + TAILSIZE], *b;
E 12
I 12
		struct iovec iov[2];

		iov[0].iov_base = p;
		iov[0].iov_len = HDRSIZ;
		iov[1].iov_base = pk->p_ob[x];
		iov[1].iov_len = pk->p_xsize;

		if (writev(pk->p_ofn, iov, 2) < 0) {
			alarm(0);
			logent("PKXSTART write failed", sys_errlist[errno]);
			longjmp(Sjbuf, 5);
		}
#ifdef 0
		char buf[PKMAXBUF + HDRSIZ], *b;
E 12
E 8
		int i;
D 2
		for (i = 0, b = buf; i < HDRSIZ; i++) 
E 2
I 2
		for (i = 0, b = buf; i < HDRSIZ; i++)
E 2
			*b++ = *p++;
		for (i = 0, p = pk->p_ob[x]; i < pk->p_xsize; i++)
			*b++ = *p++;
D 2
#ifdef PROTODEBUG
		GENERROR(buf, pk->p_xsize + HDRSIZ);
#endif
		ret = write(pk->p_ofn, buf, pk->p_xsize + HDRSIZ);
		PKASSERT(ret == pk->p_xsize + HDRSIZ,
		  "PKXSTART ret", "", ret);
E 2
I 2
D 8
		if (write(pk->p_ofn, buf, pk->p_xsize + HDRSIZ) != (HDRSIZ + pk->p_xsize)) {
E 8
I 8
D 12
#if TAILSIZE != 0
		for (i = 0; i < TAILSIZE; i++)
			*b++ = '\0';
#endif TAILSIZE
		if (write(pk->p_ofn, buf, pk->p_xsize + HDRSIZ + TAILSIZE)
		    != (HDRSIZ + TAILSIZE + pk->p_xsize)) {
E 12
I 12

		if (write(pk->p_ofn, buf, pk->p_xsize + HDRSIZ)
		    != (HDRSIZ + pk->p_xsize)) {
E 12
E 8
			alarm(0);
			logent("PKXSTART write failed", sys_errlist[errno]);
			longjmp(Sjbuf, 5);
		}
I 12
#endif 0
E 12
E 2
		Connodata = 0;
	}
	if (pk->p_msg)
		pkoutput(pk);
D 2
	return;
E 2
}
D 12


pkmove(p1, p2, count, flag)
char *p1, *p2;
int count, flag;
{
	register char *s, *d;
	register int i;

	if (flag == B_WRITE) {
		s = p2;
		d = p1;
D 3
	}
	else {
E 3
I 3
	} else {
E 3
		s = p1;
		d = p2;
	}
	for (i = 0; i < count; i++)
		*d++ = *s++;
D 2
	return;
E 2
}

E 12

D 6
/***
 *	pkcget(fn, b, n)	get n characters from input
 *	char *b;		- buffer for characters
 *	int fn;			- file descriptor
 *	int n;			- requested number of characters
E 6
I 6
D 7
/*
 *	get n characters from input
E 7
I 7
D 8
/***
 *	pkcget(fn, b, n)	get n characters from input
 *	char *b;		- buffer for characters
 *	int fn;			- file descriptor
 *	int n;			- requested number of characters
E 8
I 8
/*
 *	get n characters from input
E 8
E 7
E 6
 *
 *	return codes:
 *		n - number of characters returned
 *		0 - end of file
 */

jmp_buf Getjbuf;
D 2
cgalarm() { longjmp(Getjbuf, 1); }
E 2
I 2
cgalarm()
{
	longjmp(Getjbuf, 1);
}
E 2

pkcget(fn, b, n)
D 3
int fn, n;
E 3
I 3
int fn;
D 6
register int n;
E 6
E 3
D 7
register char *b;
E 7
I 6
D 8
register int n;
E 8
I 7
register char *b;
I 8
register int n;
E 8
E 7
E 6
{
D 3
	register int nchars, ret;
E 3
I 3
	register int ret;
E 3
I 2
	extern int linebaudrate;
#ifdef BSD4_2
D 3
	long r, itime = 0;
E 3
I 3
	long r, itime = 100000L; /* guess it's been 1/10th second since we
				    last read the line */
E 3
	struct timeval tv;
#endif BSD4_2
#ifdef VMS
	short iosb[4];
	int SYS$QioW();	/* use this for long reads on vms */
#endif VMS
E 2

	if (setjmp(Getjbuf)) {
		Ntimeout++;
I 8
D 10
		pktimeout += 2;
E 10
I 10
		DEBUG(4, "pkcget: alarm %d\n", pktimeout * 1000 + Ntimeout);
		pktimeout += pktimeskew;
E 10
		if (pktimeout > MAXPKTIME)
			pktimeout = MAXPKTIME;
E 8
D 2
		PKDEBUG(4, "alarm %d\n", Ntimeout);
		return(-1);
E 2
I 2
D 10
		DEBUG(4, "pkcget: alarm %d\n", Ntimeout);
E 10
		return FAIL;
E 2
	}
	signal(SIGALRM, cgalarm);

D 8
	alarm(PKTIME);
E 8
I 8
	alarm(pktimeout);
E 8
D 2
	for (nchars = 0; nchars < n; nchars += ret) {
E 2
I 2
D 3
	for (nchars = 0; nchars < n; ) {
E 3
I 3
	while (n > 0) {
#ifdef BSD4_2
		if (linebaudrate > 0) {
			r = n  * 100000L;
			r = r / linebaudrate;
			r = (r * 100) - itime;
			itime = 0;
			/* we predict that more than 1/50th of a
			   second will go by before the read will
			   give back all that we want. */
			if (r > 20000) {
				tv.tv_sec = r / 1000000L;
				tv.tv_usec = r % 1000000L;
				DEBUG(11, "PKCGET stall for %d", tv.tv_sec);
				DEBUG(11, ".%06d sec\n", tv.tv_usec);
				(void) select (0, (int *)0, (int *)0, (int *)0, &tv);
			}
		}
#endif BSD4_2
E 3
#ifndef VMS
E 2
D 3
		ret = read(fn, b, n - nchars);
E 3
I 3
		ret = read(fn, b, n);
E 3
I 2
#else VMS
		_$Cancel_IO_On_Signal = FD_FAB_Pointer[fn];
		ret = SYS$QioW(_$EFN,(FD_FAB_Pointer[fn]->fab).fab$l_stv,
				IO$_READVBLK|IO$M_NOFILTR|IO$M_NOECHO,
D 3
				iosb,0,0,b,n-nchars,0,
E 3
I 3
				iosb,0,0,b,n,0,
E 3
				iomask,0,0);
		_$Cancel_IO_On_Signal = 0;
		if (ret == SS$_NORMAL)
			ret = iosb[1]+iosb[3];   /* get length of transfer */
		else
			ret = 0;
#endif VMS
E 2
		if (ret == 0) {
			alarm(0);
D 2
			return(-1);
E 2
I 2
			return FAIL;
E 2
		}
D 2
		PKASSERT(ret > 0, "PKCGET READ", "", ret);
		b += ret;
E 2
I 2
		if (ret <= 0) {
			alarm(0);
D 3
			logent("PKCGET read failed", sys_errlist[errno]);
E 3
I 3
			logent(sys_errlist[errno],"FAILED pkcget Read");
E 3
			longjmp(Sjbuf, 6);
		}
 		b += ret;
D 3
		nchars += ret;
		if (nchars < n)
#ifndef BSD4_2
			if (linebaudrate > 0 && linebaudrate < 4800)
				sleep(1);
#else BSD4_2
			if (linebaudrate > 0) {
				r = (n - nchars) * 100000;
				r = r / linebaudrate;
				r = (r * 100) - itime;
				itime = 0;
				/* we predict that more than 1/50th of a
				   second will go by before the read will
				   give back all that we want. */
			 	if (r > 20000) {
					tv.tv_sec = r / 1000000L;
					tv.tv_usec = r % 1000000L;
					DEBUG(11, "PKCGET stall for %d", tv.tv_sec);
					DEBUG(11, ".%06d sec\n", tv.tv_usec);
					(void) select (fn, (int *)0, (int *)0, (int *)0, &tv);
			    	}
		    	}
#endif BSD4_2
E 3
I 3
		n -= ret;
E 3
E 2
	}
	alarm(0);
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}
D 2


#ifdef PROTODEBUG
generror(p, s)
char *p;
int s;
{
	int r;
	if (Errorrate != 0 && (rand() % Errorrate) == 0) {
		r = rand() % s;
fprintf(stderr, "gen err at %o, (%o), ", r, (unsigned) *(p + r));
		*(p + r) += 1;
	}
	return;
}


#endif
E 2
E 1

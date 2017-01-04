h19794
s 00005/00007/00561
d D 5.9 88/04/05 12:07:55 rick 9 8
c use syslog for errors, use bcopy instead of pkmove
e
s 00001/00006/00567
d D 5.8 88/02/24 20:00:57 rick 8 7
c remove dead code
e
s 00026/00005/00547
d D 5.7 86/05/30 10:27:33 bloom 7 6
c use variable retry timeouts for sending and receiving, if receive too many
c reacks, request retransmission
e
s 00004/00001/00548
d D 5.6 86/03/24 08:44:28 bloom 6 5
c improve error printout
e
s 00007/00001/00542
d D 5.5 86/01/06 15:02:11 bloom 5 4
c more fixes from rick adams
e
s 00007/00030/00536
d D 5.4 85/06/20 10:09:00 bloom 4 3
c fixes from rick adams
e
s 00003/00011/00563
d D 5.3 85/04/10 15:20:13 ralph 3 2
c more changes from rick adams.
e
s 00107/00203/00467
d D 5.2 85/01/22 14:09:48 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00670/00000/00000
d D 5.1 83/07/02 17:57:19 sam 1 0
c date and time created 83/07/02 17:57:19 by sam
e
u
U
t
T
I 1
#ifndef lint
D 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
static char sccsid[] = "%W%	(Berkeley) %G%";
E 9
#endif

D 3
extern	char	*malloc();

D 2
#define USER	1
E 2
#include <stdio.h>
D 2
#ifdef	SYSIII
E 2
I 2
#ifdef	USG
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
E 3
I 3
#include "uucp.h"
E 3
#include "pk.h"
D 3
#include <sys/buf.h>
E 3

D 2

E 2
/*
 * packet driver
 */

D 2
char next[8]	={ 1,2,3,4,5,6,7,0};	/* packet sequence numbers */
char mask[8]	={ 1,2,4,010,020,040,0100,0200 };
E 2
I 2
char next[8] = { 1, 2, 3, 4, 5, 6, 7, 0};	/* packet sequence numbers */
char mask[8] = { 1, 2, 4, 010, 020, 040, 0100, 0200 };
E 2

struct pack *pklines[NPLINES];
D 2

/*
 * Here are a couple of strange variables (rti!trt).
 * pkactive is only incremented in pkopen.
 * perhaps it should be decremented in pkclose?
 * And pkdebug is set in gio.c but never used.
 */
E 2
D 5
int	pkactive;
E 5
D 2
int	pkdebug;
E 2
I 2
D 4
long chksum();
E 4
E 2

I 5
D 7
#define PKTIME 4
extern int pktimeout, Ntimeout;
E 7
I 7
int Reacks;
E 7

I 7
#define PKRTIME 4
#define PKWTIME 4
#define PKRSKEW 3
#define PKWSKEW 2
extern int pktimeout, pktimeskew, Ntimeout;

E 7
E 5
/*
 * receive control messages
 */
pkcntl(c, pk)
register struct pack *pk;
{
D 2
register cntl, val;
E 2
I 2
	register cntl, val;
E 2

	val = c & MOD8;
	cntl = (c>>3) & MOD8;

D 2
	if ( ! ISCNTL(c) ) {
		fprintf(stderr, "not cntl\n");
E 2
I 2
	if (!ISCNTL(c)) {
		logent("PK0", "not cntl");
E 2
		return;
	}

D 2
	if (pk->p_mode & 02)
		fprintf(stderr, "%o ",c);
E 2
	switch(cntl) {
D 2

E 2
	case INITB:
		val++;
		pk->p_xsize = pksizes[val];
		pk->p_lpsize = val;
D 2
		pk->p_bits = DTOM(pk->p_xsize);
E 2
I 2
		pk->p_bits = 1;
E 2
		if (pk->p_state & LIVE) {
			pk->p_msg |= M_INITC;
			break;
		}
		pk->p_state |= INITb;
		if ((pk->p_state & INITa)==0) {
			break;
		}
		pk->p_rmsg &= ~M_INITA;
		pk->p_msg |= M_INITC;
		break;

	case INITC:
		if ((pk->p_state&INITab)==INITab) {
			pk->p_state = LIVE;
D 2
			WAKEUP(&pk->p_state);
E 2
			pk->p_rmsg &= ~M_INITB;
		} else
			pk->p_msg |= M_INITB;
		if (val)
			pk->p_swindow = val;
		break;
	case INITA:
D 2
		if (val==0 && pk->p_state&LIVE) {
			fprintf(stderr, "alloc change not implemented\n");
E 2
I 2
		if (val == 0 && pk->p_state&LIVE) {
			logent("PK0", "alloc change not implemented");
E 2
			break;
		}
		if (val) {
			pk->p_state |= INITa;
			pk->p_msg |= M_INITB;
			pk->p_rmsg |= M_INITB;
			pk->p_swindow = val;
		}
		break;
	case RJ:
		pk->p_state |= RXMIT;
		pk->p_msg |= M_RR;
D 7
	case RR:
E 7
		pk->p_rpr = val;
D 2
		if (pksack(pk)==0) {
			WAKEUP(&pk->p_ps);
		}
E 2
I 2
		(void) pksack(pk);
E 2
		break;
I 7
	case RR:
		pk->p_rpr = val;
		if (pk->p_rpr == pk->p_ps) {
			DEBUG(9, "Reack count is %d\n", ++Reacks);
			if (Reacks >= 4) {
				DEBUG(6, "Reack overflow on %d\n", val);
				pk->p_state |= RXMIT;
				pk->p_msg |= M_RR;
				Reacks = 0;
			}
		} else {
			Reacks = 0;
			(void) pksack(pk);
		}
		break;
E 7
	case SRJ:
D 2
		fprintf(stderr, "srj not implemented\n");
E 2
I 2
		logent("PK0", "srj not implemented");
E 2
		break;
	case CLOSE:
		pk->p_state = DOWN+RCLOSE;
D 2
		SIGNAL;
		WAKEUP(&pk->p_pr);
		WAKEUP(&pk->p_ps);
		WAKEUP(&pk->p_state);
E 2
		return;
	}
D 2
out:
E 2
	if (pk->p_msg)
		pkoutput(pk);
}

D 2


E 2
pkaccept(pk)
register struct pack *pk;
{
D 2
register x,seq;
char m, cntl, *p, imask, **bp;
int bad,accept,skip,s,t,h,cc;
unsigned short sum;
E 2
I 2
	register x, seq;
	char m, cntl, *p, imask, **bp;
	int bad, accept, skip, t,  cc;
	unsigned short sum;
E 2

D 2

E 2
	bad = accept = skip = 0;
	/*
	 * wait for input
	 */
D 2
	LOCK;
E 2
	x = next[pk->p_pr];
D 2
	while ((imask=pk->p_imap) == 0 && pk->p_rcount==0) {
		PKGETPKT(pk);
		SLEEP(&pk->p_pr, PKIPRI);
E 2
I 2
	while ((imask=pk->p_imap) == 0 && pk->p_rcount == 0) {
		pkgetpack(pk);
E 2
	}
	pk->p_imap = 0;
D 2
	UNLOCK;
E 2

D 2

E 2
	/*
	 * determine input window in m.
	 */
	t = (~(-1<<(int)(pk->p_rwindow))) <<x;
	m = t;
	m |= t>>8;

D 2

E 2
	/*
	 * mark newly accepted input buffers
	 */
	for(x=0; x<8; x++) {
D 2

E 2
		if ((imask & mask[x]) == 0)
			continue;

D 2
		if (((cntl=pk->p_is[x])&0200)==0) {
E 2
I 2
		if (((cntl=pk->p_is[x])&0200) == 0) {
E 2
			bad++;
free:
			bp = (char **)pk->p_ib[x];
D 2
			LOCK;
E 2
			*bp = (char *)pk->p_ipool;
			pk->p_ipool = bp;
			pk->p_is[x] = 0;
D 2
			UNLOCK;
E 2
			continue;
		}

		pk->p_is[x] = ~(B_COPY+B_MARK);
		sum = (unsigned)chksum(pk->p_ib[x], pk->p_rsize) ^ (unsigned)(cntl&0377);
		sum += pk->p_isum[x];
		if (sum == CHECK) {
			seq = (cntl>>3) & MOD8;
			if (m & mask[seq]) {
				if (pk->p_is[seq] & (B_COPY | B_MARK)) {
				dup:
					pk->p_msg |= M_RR;
					skip++;
					goto free;
				}
				if (x != seq) {
D 2
					LOCK;
E 2
					p = pk->p_ib[x];
					pk->p_ib[x] = pk->p_ib[seq];
					pk->p_is[x] = pk->p_is[seq];
					pk->p_ib[seq] = p;
D 2
					UNLOCK;
E 2
				}
				pk->p_is[seq] = B_MARK;
				accept++;
				cc = 0;
				if (cntl&B_SHORT) {
					pk->p_is[seq] = B_MARK+B_SHORT;
					p = pk->p_ib[seq];
					cc = (unsigned)*p++ & 0377;
					if (cc & 0200) {
						cc &= 0177;
						cc |= *p << 7;
					}
				}
				pk->p_isum[seq] = pk->p_rsize - cc;
			} else {
				goto dup;
			}
		} else {
			bad++;
			goto free;
		}
	}

	/*
	 * scan window again turning marked buffers into
	 * COPY buffers and looking for missing sequence
	 * numbers.
	 */
	accept = 0;
D 2
	for(x=next[pk->p_pr],t=h= -1; m & mask[x]; x = next[x]) {
E 2
I 2
	t = -1;
	for(x=next[pk->p_pr]; m & mask[x]; x = next[x]) {
E 2
		if (pk->p_is[x] & B_MARK)
			pk->p_is[x] |= B_COPY;
D 2
	/*  hole code 
E 2
I 2

E 2
		if (pk->p_is[x] & B_COPY) {
D 2
			if (h<0 && t>=0)
				h = x;
		} else {
			if (t<0)
				t = x;
		}
	*/
		if (pk->p_is[x] & B_COPY) {
E 2
			if (t >= 0) {
				bp = (char **)pk->p_ib[x];
D 2
				LOCK;
E 2
				*bp = (char *)pk->p_ipool;
				pk->p_ipool = bp;
				pk->p_is[x] = 0;
D 2
				UNLOCK;
E 2
				skip++;
D 2
			} else 
E 2
I 2
			} else
E 2
				accept++;
		} else {
			if (t<0)
				t = x;
		}
	}

	if (bad) {
		pk->p_msg |= M_RJ;
	}

	if (skip) {
		pk->p_msg |= M_RR;
	}

	pk->p_rcount = accept;
D 2
	return(accept);
E 2
I 2
	return accept;
E 2
}

D 2

pkread(S)
SDEF;
E 2
I 2
/*ARGSUSED*/
D 4
pkread(ipk, ibuf, icount)
int icount;
E 4
I 4
pkread(pk, ibuf, icount)
register struct pack *pk;
E 4
char *ibuf;
D 4
struct pack *ipk;
E 4
I 4
int icount;
E 4
E 2
{
D 2
register struct pack *pk;
register x,s;
int is,cc,xfr,count;
char *cp, **bp;
E 2
I 2
D 4
	register struct pack *pk;
E 4
	register x;
	int is, cc, xfr, count;
	char *cp, **bp;
E 2

D 2
	pk = PADDR;
E 2
I 2
D 4
	pk = ipk;
E 4
E 2
	xfr = 0;
	count = 0;
I 5
D 7
	pktimeout = PKTIME;
E 7
I 7
	pktimeout = PKRTIME;
	pktimeskew = PKRSKEW;
E 7
	Ntimeout = 0;
E 5
D 2
	while (pkaccept(pk)==0);
E 2
I 2
	while (pkaccept(pk) == 0)
		;
E 2

D 2

	while (UCOUNT) {

E 2
I 2
	while (icount) {
E 2
		x = next[pk->p_pr];
		is = pk->p_is[x];

		if (is & B_COPY) {
D 2
			cc = MIN(pk->p_isum[x], UCOUNT);
E 2
I 2
			cc = MIN(pk->p_isum[x], icount);
E 2
			if (cc==0 && xfr) {
				break;
			}
			if (is & B_RESID)
				cp = pk->p_rptr;
			else {
				cp = pk->p_ib[x];
				if (is & B_SHORT) {
					if (*cp++ & 0200)
						cp++;
				}
			}
D 2
			IOMOVE(cp,cc,B_READ);
E 2
I 2
D 9
			pkmove(cp, ibuf, cc, B_READ);
E 9
I 9
			bcopy(cp, ibuf, cc);
E 9
			ibuf += cc;
			icount -= cc;
E 2
			count += cc;
			xfr++;
			pk->p_isum[x] -= cc;
			if (pk->p_isum[x] == 0) {
				pk->p_pr = x;
				bp = (char **)pk->p_ib[x];
D 2
				LOCK;
E 2
				*bp = (char *)pk->p_ipool;
				pk->p_ipool = bp;
				pk->p_is[x] = 0;
				pk->p_rcount--;
D 2
				UNLOCK;
E 2
				pk->p_msg |= M_RR;
			} else {
				pk->p_rptr = cp+cc;
				pk->p_is[x] |= B_RESID;
			}
			if (cc==0)
				break;
		} else
			break;
	}
	pkoutput(pk);
D 2
	return(count);
E 2
I 2
	return count;
E 2
}

D 2



pkwrite(S)
SDEF;
E 2
I 2
/*ARGSUSED*/
D 4
pkwrite(ipk, ibuf, icount)
struct pack *ipk;
E 4
I 4
pkwrite(pk, ibuf, icount)
register struct pack *pk;
E 4
char *ibuf;
int icount;
E 2
{
D 2
register struct pack *pk;
register x;
int partial;
caddr_t cp;
int cc, s, fc, count;
E 2
I 2
D 4
	register struct pack *pk;
E 4
	register x;
	int partial;
	caddr_t cp;
	int cc, fc, count;
E 2

D 2
	pk = PADDR;
E 2
I 2
D 4
	pk = ipk;
E 4
E 2
	if (pk->p_state&DOWN || !pk->p_state&LIVE) {
D 2
		SETERROR;
		return(-1);
E 2
I 2
		return -1;
E 2
	}

I 5
D 7
	pktimeout = PKTIME;
E 7
I 7
	pktimeout = PKWTIME;
	pktimeskew = PKWSKEW;
E 7
	Ntimeout = 0;
E 5
D 2
	count = UCOUNT;
E 2
I 2
	count = icount;
E 2
	do {
D 2
		LOCK;
E 2
		while (pk->p_xcount>=pk->p_swindow)  {
			pkoutput(pk);
D 2
			PKGETPKT(pk);
			SLEEP(&pk->p_ps,PKOPRI);
E 2
I 2
			pkgetpack(pk);
E 2
		}
		x = next[pk->p_pscopy];
		while (pk->p_os[x]!=B_NULL)  {
D 2
			PKGETPKT(pk);
			SLEEP(&pk->p_ps,PKOPRI);
E 2
I 2
			pkgetpack(pk);
E 2
		}
		pk->p_os[x] = B_MARK;
		pk->p_pscopy = x;
		pk->p_xcount++;
D 2
		UNLOCK;
E 2

D 2
		cp = pk->p_ob[x] = GETEPACK;
E 2
I 2
		cp = pk->p_ob[x] = malloc((unsigned)pk->p_xsize);
E 2
		partial = 0;
D 2
		if ((int)UCOUNT < pk->p_xsize) {
			cc = UCOUNT;
E 2
I 2
		if ((int)icount < pk->p_xsize) {
			cc = icount;
E 2
			fc = pk->p_xsize - cc;
			*cp = fc&0177;
			if (fc > 127) {
				*cp++ |= 0200;
				*cp++ = fc>>7;
			} else
				cp++;
			partial = B_SHORT;
		} else
			cc = pk->p_xsize;
D 2
		IOMOVE(cp,cc,B_WRITE);
E 2
I 2
D 9
		pkmove(cp, ibuf, cc, B_WRITE);
E 9
I 9
		bcopy(ibuf, cp, cc);
E 9
		ibuf += cc;
		icount -= cc;
E 2
		pk->p_osum[x] = chksum(pk->p_ob[x], pk->p_xsize);
		pk->p_os[x] = B_READY+partial;
		pkoutput(pk);
D 2
	} while (UCOUNT);
E 2
I 2
	} while (icount);
E 2

D 2
	return(count);
E 2
I 2
	return count;
E 2
}

pksack(pk)
register struct pack *pk;
{
D 2
register x, i;
E 2
I 2
	register x, i;
E 2

	i = 0;
	for(x=pk->p_ps; x!=pk->p_rpr; ) {
		x = next[x];
		if (pk->p_os[x]&B_SENT) {
			i++;
			pk->p_os[x] = B_NULL;
			pk->p_state &= ~WAITO;
			pk->p_xcount--;
D 2
			FREEPACK(pk->p_ob[x], pk->p_bits);
E 2
I 2
			free((char *)pk->p_ob[x]);
E 2
			pk->p_ps = x;
D 2
			WAKEUP(&pk->p_ps);
E 2
		}
	}
D 2
	return(i);
E 2
I 2
	return i;
E 2
}

D 4


E 4
pkoutput(pk)
register struct pack *pk;
{
D 2
register x,rx;
int s;
char bstate;
int i;
SDEF;
int flag;
E 2
I 2
	register x;
	int i;
	char bstate;
E 2

D 2
	flag = 0;
	ISYSTEM;
	LOCK;
	if (pk->p_obusy++ || OBUSY) {
E 2
I 2
	if (pk->p_obusy++) {
E 2
		pk->p_obusy--;
D 2
		UNLOCK;
E 2
		return;
	}
D 2
	UNLOCK;
E 2

D 2

E 2
	/*
	 * find seq number and buffer state
	 * of next output packet
	 */
	if (pk->p_state&RXMIT)  {
		pk->p_nxtps = next[pk->p_rpr];
D 2
		flag++;
E 2
	}
	x = pk->p_nxtps;
	bstate = pk->p_os[x];

D 2

E 2
	/*
	 * Send control packet if indicated
	 */
	if (pk->p_msg) {
		if (pk->p_msg & ~M_RR || !(bstate&B_READY) ) {
			x = pk->p_msg;
D 2
			for(i=0; i<8; i++) 
E 2
I 2
			for(i=0; i<8; i++)
E 2
				if (x&1)
D 2
					break; else
				x >>= 1;
E 2
I 2
					break;
				else
					x >>= 1;
E 2
			x = i;
			x <<= 3;
			switch(i) {
			case CLOSE:
				break;
			case RJ:
			case RR:
				x += pk->p_pr;
				break;
			case SRJ:
				break;
			case INITB:
				x += pksize(pk->p_rsize);
				break;
			case INITC:
				x += pk->p_rwindow;
				break;
			case INITA:
				x += pk->p_rwindow;
				break;
			}

			pk->p_msg &= ~mask[i];
			pkxstart(pk, x, -1);
			goto out;
		}
	}


	/*
	 * Don't send data packets if line is marked dead.
	 */
	if (pk->p_state&DOWN) {
D 2
		WAKEUP(&pk->p_ps);
E 2
		goto out;
	}
	/*
	 * Start transmission (or retransmission) of data packets.
	 */
	if (bstate & (B_READY|B_SENT)) {
		char seq;

		bstate |= B_SENT;
		seq = x;
		pk->p_nxtps = next[x];

		x = 0200+pk->p_pr+(seq<<3);
		if (bstate & B_SHORT)
			x |= 0100;
		pkxstart(pk, x, seq);
		pk->p_os[seq] = bstate;
		pk->p_state &= ~RXMIT;
D 8
		pk->p_nout++;
E 8
		goto out;
	}
	/*
	 * enable timeout if there's nothing to send
	 * and transmission buffers are languishing
	 */
	if (pk->p_xcount) {
D 8
		pk->p_timer = 2;
E 8
		pk->p_state |= WAITO;
	} else
		pk->p_state &= ~WAITO;
D 2
	WAKEUP(&pk->p_ps);
E 2
out:
	pk->p_obusy = 0;
}

D 2

E 2
/*
 * shut down line by
 *	ignoring new input
 *	letting output drain
 *	releasing space and turning off line discipline
 */
D 2
pkclose(S)
SDEF;
E 2
I 2
/*ARGSUSED*/
D 4
pkclose(ipk, ibuf, icount)
struct pack *ipk;
char *ibuf;
int icount;
E 4
I 4
pkclose(pk)
register struct pack *pk;
E 4
E 2
{
D 2
register struct pack *pk;
register i,s,rbits;
char **bp;
int rcheck;
char *p;
E 2
I 2
D 4
	register struct pack *pk;
E 4
D 3
	register i, rbits;
E 3
I 3
	register i;
E 3
	char **bp;
D 3
	int rcheck;
E 3
I 3
	int rcheck = 0;
E 3
E 2

D 2

	pk = PADDR;
E 2
I 2
D 4
	pk = ipk;
E 4
E 2
	pk->p_state |= DRAINO;

D 2

E 2
	/*
	 * try to flush output
	 */
	i = 0;
D 2
	LOCK;
E 2
D 8
	pk->p_timer = 2;
E 8
	while (pk->p_xcount && pk->p_state&LIVE) {
		if (pk->p_state&(RCLOSE+DOWN) || ++i > 2)
			break;
		pkoutput(pk);
D 2
		SLEEP(&pk->p_ps,PKOPRI);
E 2
	}
D 8
	pk->p_timer = 0;
E 8
	pk->p_state |= DOWN;
D 2
	UNLOCK;
E 2

D 2

E 2
	/*
	 * try to exchange CLOSE messages
	 */
	i = 0;
	while ((pk->p_state&RCLOSE)==0 && i<2) {
		pk->p_msg = M_CLOSE;
D 8
		pk->p_timer = 2;
E 8
		pkoutput(pk);
D 2
		SLEEP(&pk->p_ps, PKOPRI);
E 2
		i++;
	}

D 2

E 2
	for(i=0;i<NPLINES;i++)
		if (pklines[i]==pk)  {
			pklines[i] = NULL;
		}
D 2
	TURNOFF;
E 2

D 2

E 2
	/*
	 * free space
	 */
D 2
	rbits = DTOM(pk->p_rsize);
E 2
I 2
D 3
	rbits = 1;
E 3
E 2
	rcheck = 0;
	for (i=0;i<8;i++) {
D 2
		if (pk->p_os[i]!=B_NULL) {
			FREEPACK(pk->p_ob[i],pk->p_bits);
E 2
I 2
		if (pk->p_os[i] != B_NULL) {
			free((char *)pk->p_ob[i]);
E 2
			pk->p_xcount--;
		}
D 2
		if (pk->p_is[i]!=B_NULL)  {
			FREEPACK(pk->p_ib[i],rbits);
E 2
I 2
		if (pk->p_is[i] != B_NULL)  {
			free((char *)pk->p_ib[i]);
E 2
			rcheck++;
		}
	}
D 2
	LOCK;
E 2
	while (pk->p_ipool != NULL) {
		bp = pk->p_ipool;
		pk->p_ipool = (char **)*bp;
		rcheck++;
D 2
		FREEPACK(bp, rbits);
E 2
I 2
		free((char *)bp);
E 2
	}
D 2
	UNLOCK;
	if (rcheck  != pk->p_rwindow) {
		fprintf(stderr, "r short %d want %d\n",rcheck,pk->p_rwindow);
		fprintf(stderr, "rcount = %d\n",pk->p_rcount);
		fprintf(stderr, "xcount = %d\n",pk->p_xcount);
E 2
I 2
	if (rcheck != pk->p_rwindow) {
D 6
		logent("PK0", "pkclose rcheck != p_rwindow");
E 6
I 6
D 9
		char buf[256];

		sprintf(buf, "PK0: rc %d rw %d", rcheck, pk->p_rwindow);
D 8
		logent(buf, "pkclose rcheck != p_rwindow");
E 8
I 8
		assert(buf, Rmtname, 0);
E 9
I 9
		syslog(LOG_WARNING, "%s: pk0: rc %d rw %d", Rmtname, rcheck,
			pk->p_rwindow);
E 9
E 8
E 6
E 2
	}
D 2
	FREEPACK((caddr_t)pk, npbits);
E 2
I 2
	free((char *)pk);
E 2
}

D 2


E 2
pkreset(pk)
register struct pack *pk;
{

	pk->p_ps = pk->p_pr =  pk->p_rpr = 0;
	pk->p_nxtps = 1;
D 4
}

D 2
chksum(s,n)
register char *s;
register n;
{
	register unsigned sum, t;
	register x;

	sum = -1;
	x = 0;

	do {
		if (sum&0x8000) {
			sum <<= 1;
			sum++;
		} else
			sum <<= 1;
		t = sum;
		sum += (unsigned)*s++ & 0377;
		x += sum^n;
		if ((sum&0xffff) <= (t&0xffff)) {
			sum ^= x;
		}
	} while (--n > 0);

	return(sum & 0xffff);
}

E 2
pkline(pk)
register struct pack *pk;
{
D 2
register i;
E 2
I 2
	register i;

E 2
	for(i=0;i<NPLINES;i++) {
		if (pklines[i]==pk)
D 2
			return(i);
E 2
I 2
			return i;
E 2
	}
D 2
	return(-i);
E 2
I 2
	return -i;
E 4
E 2
}

D 2
pkzero(s,n)
E 2
I 2
#ifndef BSD4_2
bzero(s,n)
E 2
register char *s;
register n;
{
	while (n--)
		*s++ = 0;
}
I 2
#endif !BSD4_2
E 2

pksize(n)
register n;
{
D 2
register k;
E 2
I 2
	register k;
E 2

	n >>= 5;
D 2
	for(k=0; n >>= 1; k++);
	return(k);
E 2
I 2
	for(k=0; n >>= 1; k++)
		;
	return k;
E 2
}
E 1

h46950
s 00017/00012/00558
d D 5.5 88/04/05 12:28:54 rick 5 4
c use syslog for errors, use TCSETAF instead of TCSETA
e
s 00031/00010/00539
d D 5.4 88/02/24 19:54:24 rick 4 3
c speedups from pyramid ;log bps rate
e
s 00002/00002/00547
d D 5.3 85/10/09 17:12:49 bloom 3 2
c accounting fix (rick@seismo again)
e
s 00151/00112/00398
d D 5.2 85/10/09 15:49:15 bloom 2 1
c still more fixes from rick@seismo
e
s 00510/00000/00000
d D 5.1 85/06/19 19:04:03 bloom 1 0
c date and time created 85/06/19 19:04:03 by bloom
e
u
U
t
T
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W%	(Berkeley) %G%";
E 5
#endif

/*
 * flow control protocol.
 *
 * This protocol relies on flow control of the data stream.
 * It is meant for working over links that can (almost) be
 * guaranteed to be errorfree, specifically X.25/PAD links.
 * A sumcheck is carried out over a whole file only. If a
 * transport fails the receiver can request retransmission(s).
 * This protocol uses a 7-bit datapath only, so it can be
 * used on links that are not 8-bit transparent.
 *
 * When using this protocol with an X.25 PAD:
 * Although this protocol uses no control chars except CR,
 * control chars NULL and ^P are used before this protocol
 * is started; since ^P is the default char for accessing
 * PAD X.28 command mode, be sure to disable that access
 * (PAD par 1). Also make sure both flow control pars
 * (5 and 12) are set. The CR used in this proto is meant
 * to trigger packet transmission, hence par 3 should be 
 * set to 2; a good value for the Idle Timer (par 4) is 10.
 * All other pars should be set to 0.
I 2
 *
E 2
 * Normally a calling site will take care of setting the
 * local PAD pars via an X.28 command and those of the remote
 * PAD via an X.29 command, unless the remote site has a
 * special channel assigned for this protocol with the proper
 * par settings.
 *
D 2
 * Author: Piet Beertema, CWI, Amsterdam, Sep 1984
E 2
I 2
 * Additional comments for hosts with direct X.25 access:
 * - the global variable IsTcpIp, when set, excludes the ioctl's,
 *   so the same binary can run on X.25 and non-X.25 hosts;
 * - reads are done in small chunks, which can be smaller than
 *   the packet size; your X.25 driver must support that.
 *
 *
 * Author:
 *	Piet Beertema, CWI, Amsterdam, Sep 1984
 * Modified for X.25 hosts:
 *	Robert Elz, Melbourne Univ, Mar 1985
E 2
 */

D 2
#include <signal.h>
E 2
#include "uucp.h"
I 2
#include <signal.h>
E 2
#ifdef USG
#include <termio.h>
#else !USG
#include <sgtty.h>
#endif !USG
#include <setjmp.h>

D 2
#define FBUFSIZ		256
E 2
I 2
D 4
#define FIBUFSIZ	256	/* for X.25 interfaces: set equal to packet size,
E 4
I 4
#define FIBUFSIZ	4096	/* for X.25 interfaces: set equal to packet size,
E 4
				 * but see comment above
				 */
E 2

I 2
D 4
#define FOBUFSIZ	256	/* for X.25 interfaces: set equal to packet size;
E 4
I 4
#define FOBUFSIZ	4096	/* for X.25 interfaces: set equal to packet size;
E 4
				 * otherwise make as large as feasible to reduce
				 * number of write system calls 
				 */

E 2
#ifndef MAXMSGLEN
#define MAXMSGLEN	BUFSIZ
#endif MAXMSGLEN

static int fchksum;
static jmp_buf Ffailbuf;

I 4
extern long Bytes_Sent, Bytes_Received;

E 4
static
falarm()
{
	signal(SIGALRM, falarm);
	longjmp(Ffailbuf, 1);
}

static int (*fsig)();

#ifndef USG
#define TCGETA	TIOCGETP
D 5
#define TCSETA	TIOCSETP
E 5
I 5
#define TCSETAF	TIOCSETP
E 5
#define termio	sgttyb
#endif USG
I 4
static struct	termio ttbuf;
E 4

fturnon()
{
D 5
	int ret;
E 5
D 4
	struct termio ttbuf;
E 4
I 4
	int ttbuf_flags;
E 4

D 2
	ioctl(Ifn, TCGETA, &ttbuf);
E 2
I 2
	if (!IsTcpIp) {
		ioctl(Ifn, TCGETA, &ttbuf);
E 2
#ifdef USG
I 4
		ttbuf_flags = ttbuf.c_iflag;
E 4
D 2
	ttbuf.c_iflag = IXOFF|IXON|ISTRIP;
	ttbuf.c_cc[VMIN] = FBUFSIZ > 64 ? 64 : FBUFSIZ;
	ttbuf.c_cc[VTIME] = 5;
#else
	ttbuf.sg_flags = ANYP|CBREAK|TANDEM;
E 2
I 2
		ttbuf.c_iflag = IXOFF|IXON|ISTRIP;
		ttbuf.c_cc[VMIN] = FIBUFSIZ > 64 ? 64 : FIBUFSIZ;
		ttbuf.c_cc[VTIME] = 5;
I 4
D 5
		ret = ioctl(Ifn, TCSETA, &ttbuf);
		ASSERT(ret >= 0, "STTY FAILED", "", ret);
E 5
I 5
		if (ioctl(Ifn, TCSETAF, &ttbuf) < 0) {
			syslog(LOG_ERR, "ioctl(TCSETAF) failed: %m");
			cleanup(FAIL);
		}
E 5
		ttbuf.c_iflag = ttbuf_flags;
E 4
#else !USG
D 4
		ttbuf.sg_flags = ANYP|CBREAK|TANDEM;
E 2
#endif USG
E 4
I 4
		ttbuf_flags = ttbuf.sg_flags;
		ttbuf.sg_flags = ANYP|CBREAK;
E 4
D 2
	ret = ioctl(Ifn, TCSETA, &ttbuf);
	ASSERT(ret >= 0, "STTY FAILED", "", ret);
E 2
I 2
D 5
		ret = ioctl(Ifn, TCSETA, &ttbuf);
		ASSERT(ret >= 0, "STTY FAILED", "", ret);
E 5
I 5
		if (ioctl(Ifn, TCSETAF, &ttbuf) < 0) {
			syslog(LOG_ERR, "ioctl(TCSETAF) failed: %m");
			cleanup(FAIL);
		}
E 5
I 4
		/* this is two seperate ioctls to set the x.29 params */
		ttbuf.sg_flags |= TANDEM;
D 5
		ret = ioctl(Ifn, TCSETA, &ttbuf);
		ASSERT(ret >= 0, "STTY FAILED", "", ret);
E 5
I 5
		if (ioctl(Ifn, TCSETAF, &ttbuf) < 0) {
			syslog(LOG_ERR, "ioctl(TCSETAF) failed: %m");
			cleanup(FAIL);
		}
E 5
		ttbuf.sg_flags = ttbuf_flags;
#endif USG
E 4
	}
E 2
	fsig = signal(SIGALRM, falarm);
	/* give the other side time to perform its ioctl;
	 * otherwise it may flush out the first data this
	 * side is about to send.
	 */
	sleep(2);
	return SUCCESS;
}

fturnoff()
{
I 4
	if (!IsTcpIp)
D 5
		ioctl(Ifn, TCSETA, &ttbuf);
E 5
I 5
		ioctl(Ifn, TCSETAF, &ttbuf);
E 5
E 4
	(void) signal(SIGALRM, fsig);
I 4
	sleep(2);
E 4
	return SUCCESS;
}

fwrmsg(type, str, fn)
register char *str;
int fn;
char type;
{
	register char *s;
	char bufr[MAXMSGLEN];

	s = bufr;
	*s++ = type;
	while (*str)
		*s++ = *str++;
	if (*(s-1) == '\n')
		s--;
	*s++ = '\r';
I 2
	*s = 0;
E 2
	(void) write(fn, bufr, s - bufr);
	return SUCCESS;
}

frdmsg(str, fn)
register char *str;
register int fn;
{
	register char *smax;

	if (setjmp(Ffailbuf))
		return FAIL;
	smax = str + MAXMSGLEN - 1;
	(void) alarm(2*MAXMSGTIME);
	for (;;) {
		if (read(fn, str, 1) <= 0)
			goto msgerr;
I 2
		*str &= 0177;
E 2
		if (*str == '\r')
			break;
D 2
		if (*str < ' ')
E 2
I 2
		if (*str < ' ') {
E 2
			continue;
I 2
		}
E 2
		if (str++ >= smax)
			goto msgerr;
	}
	*str = '\0';
	(void) alarm(0);
	return SUCCESS;
msgerr:
	(void) alarm(0);
	return FAIL;
}

fwrdata(fp1, fn)
FILE *fp1;
int fn;
{
D 2
	register int flen, alen, ret;
	char ibuf[FBUFSIZ];
	char ack;
E 2
I 2
	register int alen, ret;
D 4
	register char *obp;
E 4
	char ack, ibuf[MAXMSGLEN];
	int flen, mil, retries = 0;
E 2
	long abytes, fbytes;
	struct timeb t1, t2;
I 4
	float ft;
E 4
D 2
	int mil, retries = 0;
E 2

	ret = FAIL;
retry:
	fchksum = 0xffff;
	abytes = fbytes = 0L;
	ack = '\0';
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
	ftime(&t1);
#endif !USG
D 2
	while ((flen = fread(ibuf, sizeof (char), FBUFSIZ, fp1)) > 0) {
		alen = fwrblk(fn, ibuf, flen);
		abytes += alen >= 0 ? alen : -alen;
		if (alen <= 0)
			goto acct;
E 2
I 2
	do {
		alen = fwrblk(fn, fp1, &flen);
E 2
		fbytes += flen;
D 2
	}
	sprintf(ibuf, "\176\176%04x\r", fchksum);
	abytes += alen = strlen(ibuf);
	if (write(fn, ibuf, alen) == alen) {
		DEBUG(8, "%d\n", alen);
		DEBUG(8, "checksum: %04x\n", fchksum);
		if (frdmsg(ibuf, fn) != FAIL) {
			if ((ack = ibuf[0]) == 'G')
				ret = 0;
			DEBUG(4, "ack - '%c'\n", ack);
E 2
I 2
		if (alen <= 0) {
			abytes -= alen;
			goto acct;
E 2
		}
I 2
		abytes += alen;
	} while (!feof(fp1) && !ferror(fp1));
	DEBUG(8, "\nchecksum: %04x\n", fchksum);
	if (frdmsg(ibuf, fn) != FAIL) {
		if ((ack = ibuf[0]) == 'G')
			ret = SUCCESS;
		DEBUG(4, "ack - '%c'\n", ack);
E 2
	}
acct:
D 2
	if (ack == 'R') {
		DEBUG(4, "RETRY:\n", 0);
		fseek(fp1, 0L, 0);
		retries++;
		goto retry;
	}
E 2
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
	ftime(&t2);
#endif !USG
	Now = t2;
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 4
	sprintf(ibuf, "sent data %ld bytes %ld.%02d secs",
D 2
				fbytes, (long)t2.time, mil/10);
E 2
I 2
		fbytes, (long)t2.time, mil / 10);
E 4
I 4
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(ibuf, "sent data %ld bytes %.2f secs %ld bps",
		fbytes, ft, (long)((float)fbytes*8./ft));
E 4
E 2
D 3
	sysacct(abytes, t2.time - t1.time);
E 3
I 3
	sysacct(abytes, t2.time);
I 4
	Bytes_Sent += fbytes;
E 4
E 3
D 2
	if (retries > 0) 
		sprintf((char *)ibuf+strlen(ibuf)," %d retries", retries);
E 2
I 2
	if (retries > 0)
		sprintf(&ibuf[strlen(ibuf)], ", %d retries", retries);
E 2
	DEBUG(1, "%s\n", ibuf);
D 5
	syslog(ibuf);
E 5
I 5
	log_xferstats(ibuf);
E 5
I 2
	if (ack == 'R') {
		DEBUG(4, "RETRY:\n", 0);
		fseek(fp1, 0L, 0);
		retries++;
		goto retry;
	}
E 2
#ifdef SYSACCT
D 2
	if (ret)
E 2
I 2
	if (ret == FAIL)
E 2
		sysaccf(NULL);		/* force accounting */
#endif SYSACCT
	return ret;
}

/* max. attempts to retransmit a file: */
#define MAXRETRIES	(fbytes < 10000L ? 2 : 1)

frddata(fn, fp2)
register int fn;
register FILE *fp2;
{
	register int flen;
	register char eof;
D 2
	char ibuf[FBUFSIZ];
	int ret, retries = 0;
E 2
I 2
	char ibuf[FIBUFSIZ];
	int ret, mil, retries = 0;
E 2
	long alen, abytes, fbytes;
	struct timeb t1, t2;
I 4
	float ft;
E 4
D 2
	int mil;
E 2

	ret = FAIL;
retry:
	fchksum = 0xffff;
	abytes = fbytes = 0L;
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
	ftime(&t1);
#endif !USG
	do {
		flen = frdblk(ibuf, fn, &alen);
		abytes += alen;
		if (flen < 0)
			goto acct;
D 2
		if (eof = flen > FBUFSIZ)
			flen -= FBUFSIZ + 1;
E 2
I 2
		if (eof = flen > FIBUFSIZ)
			flen -= FIBUFSIZ + 1;
E 2
		fbytes += flen;
		if (fwrite(ibuf, sizeof (char), flen, fp2) != flen)
			goto acct;
	} while (!eof);
D 2
	ret = 0;
E 2
I 2
	ret = SUCCESS;
E 2
acct:
D 2
	if (ret) {
		if (retries++ < MAXRETRIES) {
			DEBUG(8, "send ack: 'R'\n", 0);
			fwrmsg('R', "", fn);
			fseek(fp2, 0L, 0);
			DEBUG(4, "RETRY:\n", 0);
			goto retry;
		}
		DEBUG(8, "send ack: 'Q'\n", 0);
		fwrmsg('Q', "", fn);
#ifdef SYSACCT
		sysaccf(NULL);		/* force accounting */
#endif SYSACCT
	} else {
		DEBUG(8, "send ack: 'G'\n", 0);
		fwrmsg('G', "", fn);
	}
E 2
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
	ftime(&t2);
#endif !USG
	Now = t2;
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 4
	sprintf(ibuf, "received data %ld bytes %ld.%02d secs",
D 2
				fbytes, (long)t2.time, mil/10);
	sysacct(abytes, t2.time - t1.time);
E 2
I 2
		fbytes, (long)t2.time, mil/10);
E 4
I 4
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(ibuf, "received data %ld bytes %.2f secs %ld bps",
		fbytes, ft, (long)((float)fbytes*8./ft));
E 4
E 2
	if (retries > 0) 
D 2
		sprintf((char *)ibuf+strlen(ibuf)," %d retries", retries);
E 2
I 2
		sprintf(&ibuf[strlen(ibuf)]," %d retries", retries);
D 3
	sysacct(abytes, t2.time - t1.time);
E 3
I 3
	sysacct(abytes, t2.time);
I 4
	Bytes_Received += fbytes;
E 4
E 3
E 2
	DEBUG(1, "%s\n", ibuf);
D 5
	syslog(ibuf);
E 5
I 5
	log_xferstats(ibuf);
E 5
I 2
	if (ret == FAIL) {
		if (retries++ < MAXRETRIES) {
			DEBUG(8, "send ack: 'R'\n", 0);
			fwrmsg('R', "", fn);
			fseek(fp2, 0L, 0);
			DEBUG(4, "RETRY:\n", 0);
			goto retry;
		}
		DEBUG(8, "send ack: 'Q'\n", 0);
		fwrmsg('Q', "", fn);
#ifdef SYSACCT
		sysaccf(NULL);		/* force accounting */
#endif SYSACCT
	}
	else {
		DEBUG(8, "send ack: 'G'\n", 0);
		fwrmsg('G', "", fn);
	}
E 2
	return ret;
}

static
frdbuf(blk, len, fn)
register char *blk;
register int len;
register int fn;
{
D 2
	static int ret = FBUFSIZ / 2;
#ifndef Not080
	extern int linebaudrate;
#endif Not080
E 2
I 2
	static int ret = FIBUFSIZ / 2;
E 2

	if (setjmp(Ffailbuf))
		return FAIL;
D 2
#ifndef Not080
	if (len == FBUFSIZ && ret < FBUFSIZ / 2 &&
	    linebaudrate > 0 && linebaudrate < 4800)
		sleep(1);
#endif Not080
E 2
	(void) alarm(MAXMSGTIME);
	ret = read(fn, blk, len);
	alarm(0);
	return ret <= 0 ? FAIL : ret;
}

I 2
#if !defined(BSD4_2) && !defined(USG)
E 2
/* call ultouch every TC calls to either frdblk or fwrblk  */
I 2
#define TC	20
static int tc = TC;
#endif !defined(BSD4_2) && !defined(USG)
E 2

D 2
#define	TC	20
static	int tc = TC;

E 2
/* Byte conversion:
 *
D 2
 *   from        pre       to
 * 000-037       172     100-137
 * 040-171               040-171
 * 172-177       173     072-077
 * 200-237       174     100-137
 * 240-371       175     040-171
 * 372-377       176     072-077
E 2
I 2
 *   from	 pre	   to
 * 000-037	 172	 100-137
 * 040-171		 040-171
 * 172-177	 173	 072-077
 * 200-237	 174	 100-137
 * 240-371	 175	 040-171
 * 372-377	 176	 072-077
E 2
 */

static
D 2
fwrblk(fn, ip, len)
E 2
I 2
fwrblk(fn, fp, lenp)
E 2
int fn;
D 2
register char *ip;
register int len;
E 2
I 2
register FILE *fp;
int *lenp;
E 2
{
	register char *op;
D 2
	register int sum, nl;
E 2
I 2
	register int c, sum, nl, len;
	char obuf[FOBUFSIZ + 8];
E 2
	int ret;
D 2
	char obuf[FBUFSIZ * 2];
E 2

I 2
#if !defined(BSD4_2) && !defined(USG)
E 2
	/* call ultouch occasionally */
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
D 2
	DEBUG(8, "%d/", len);
E 2
I 2
#endif !defined(BSD4_2) && !defined(USG)
E 2
	op = obuf;
	nl = 0;
I 2
	len = 0;
E 2
	sum = fchksum;
D 2
	do {
E 2
I 2
	while ((c = getc(fp)) != EOF) {
		len++;
E 2
		if (sum & 0x8000) {
			sum <<= 1;
			sum++;
		} else
			sum <<= 1;
D 2
		sum += *ip & 0377;
E 2
I 2
		sum += c;
E 2
		sum &= 0xffff;
D 2
		if (*ip & 0200) {
			*ip &= 0177;
			if (*ip < 040) {
E 2
I 2
		if (c & 0200) {
			c &= 0177;
			if (c < 040) {
E 2
				*op++ = '\174';
D 2
				*op++ = *ip++ + 0100;
E 2
I 2
				*op++ = c + 0100;
E 2
			} else
D 2
			if (*ip <= 0171) {
E 2
I 2
			if (c <= 0171) {
E 2
				*op++ = '\175';
D 2
				*op++ = *ip++;
E 2
I 2
				*op++ = c;
E 2
			}
			else {
				*op++ = '\176';
D 2
				*op++ = *ip++ - 0100;
E 2
I 2
				*op++ = c - 0100;
E 2
			}
			nl += 2;
		} else {
D 2
			if (*ip < 040) {
E 2
I 2
			if (c < 040) {
E 2
				*op++ = '\172';
D 2
				*op++ = *ip++ + 0100;
E 2
I 2
				*op++ = c + 0100;
E 2
				nl += 2;
			} else
D 2
			if (*ip <= 0171) {
				*op++ = *ip++;
E 2
I 2
			if (c <= 0171) {
				*op++ = c;
E 2
				nl++;
			} else {
				*op++ = '\173';
D 2
				*op++ = *ip++ - 0100;
E 2
I 2
				*op++ = c - 0100;
E 2
				nl += 2;
			}
		}
D 2
	} while (--len);
E 2
I 2
		if (nl >= FOBUFSIZ - 1) {
			/*
			 * peek at next char, see if it will fit
			 */
			c = getc(fp);
			if (c == EOF)
				break;
			(void) ungetc(c, fp);
			if (nl >= FOBUFSIZ || c < 040 || c > 0171)
				goto writeit;
		}
	}
	/*
	 * At EOF - append checksum, there is space for it...
	 */
	sprintf(op, "\176\176%04x\r", sum);
	nl += strlen(op);
writeit:
	*lenp = len;
E 2
	fchksum = sum;
I 2
	DEBUG(8, "%d/", len);
E 2
	DEBUG(8, "%d,", nl);
	ret = write(fn, obuf, nl);
	return ret == nl ? nl : ret < 0 ? 0 : -ret;
}

static
frdblk(ip, fn, rlen)
register char *ip;
int fn;
long *rlen;
{
	register char *op, c;
	register int sum, len, nl;
	char buf[5], *erbp = ip;
	int i;
	static char special = 0;

I 2
#if !defined(BSD4_2) && !defined(USG)
E 2
	/* call ultouch occasionally */
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
D 2

	if ((len = frdbuf(ip, FBUFSIZ, fn)) == FAIL) {
E 2
I 2
#endif !defined(BSD4_2) && !defined(USG)
	if ((len = frdbuf(ip, FIBUFSIZ, fn)) == FAIL) {
E 2
		*rlen = 0;
		goto dcorr;
	}
	*rlen = len;
	DEBUG(8, "%d/", len);
	op = ip;
	nl = 0;
	sum = fchksum;
	do {
		if ((*ip &= 0177) >= '\172') {
			if (special) {
				DEBUG(8, "%d", nl);
				special = 0;
				op = buf;
				if (*ip++ != '\176' || (i = --len) > 5)
					goto dcorr;
				while (i--)
D 2
					*op++ = *ip++;
E 2
I 2
					*op++ = *ip++ & 0177;
E 2
				while (len < 5) {
					i = frdbuf(&buf[len], 5 - len, fn);
					if (i == FAIL) {
						len = FAIL;
						goto dcorr;
					}
					DEBUG(8, ",%d", i);
					len += i;
					*rlen += i;
I 2
					while (i--)
						*op++ &= 0177;
E 2
				}
				if (buf[4] != '\r')
					goto dcorr;
				sscanf(buf, "%4x", &fchksum);
				DEBUG(8, "\nchecksum: %04x\n", sum);
				if (fchksum == sum)
D 2
					return FBUFSIZ + 1 + nl;
E 2
I 2
					return FIBUFSIZ + 1 + nl;
E 2
				else {
					DEBUG(8, "\n", 0);
					DEBUG(4, "Bad checksum\n", 0);
					return FAIL;
				}
			}
			special = *ip++;
		} else {
			if (*ip < '\040') {
				/* error: shouldn't get control chars */
				goto dcorr;
			}
			switch (special) {
			case 0:
				c = *ip++;
				break;
			case '\172':
				c = *ip++ - 0100;
				break;
			case '\173':
				c = *ip++ + 0100;
				break;
			case '\174':
				c = *ip++ + 0100;
				break;
			case '\175':
				c = *ip++ + 0200;
				break;
			case '\176':
				c = *ip++ + 0300;
				break;
			}
			*op++ = c;
			if (sum & 0x8000) {
				sum <<= 1;
				sum++;
			} else
				sum <<= 1;
			sum += c & 0377;
			sum &= 0xffff;
			special = 0;
			nl++;
		}
	} while (--len);
	fchksum = sum;
	DEBUG(8, "%d,", nl);
	return nl;
dcorr:
	DEBUG(8, "\n", 0);
	DEBUG(4, "Data corrupted\n", 0);
	while (len != FAIL) {
D 2
		if ((len = frdbuf(erbp, FBUFSIZ, fn)) != FAIL)
E 2
I 2
		if ((len = frdbuf(erbp, FIBUFSIZ, fn)) != FAIL)
E 2
			*rlen += len;
	}
	return FAIL;
}
I 2

E 2
E 1

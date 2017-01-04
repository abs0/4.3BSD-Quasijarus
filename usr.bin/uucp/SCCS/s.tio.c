h56928
s 00001/00000/00268
d D 4.9 88/05/04 13:53:27 rick 9 8
c include machparam.h to pull in defs of ntohl, etc
e
s 00004/00006/00264
d D 4.8 88/04/05 12:29:12 rick 8 7
c use syslog for errors
e
s 00019/00011/00251
d D 4.7 88/02/24 20:01:53 rick 7 6
c increase timeouts. log bps and bytes sent/rec
e
s 00005/00006/00257
d D 4.6 86/01/24 13:20:01 bloom 6 5
c still more fixes and changes from rick@seismo
e
s 00001/00001/00262
d D 4.5 85/10/09 17:15:03 bloom 5 4
c accounting fix (rick@seismo again)
e
s 00007/00003/00256
d D 4.4 85/10/09 16:16:45 bloom 4 3
c more conditionals (from rick@seismo)
e
s 00005/00011/00254
d D 4.3 85/06/23 13:09:49 bloom 3 2
c fixes from rick adams
e
s 00027/00030/00238
d D 4.2 85/04/10 15:20:58 ralph 2 1
c more changes from rick adams.
e
s 00268/00000/00000
d D 4.1 85/01/22 13:49:28 ralph 1 0
c date and time created 85/01/22 13:49:28 by ralph
e
u
U
t
T
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char sccsid[] = "%W%	(Berkeley) %G%";
E 8
#endif

I 3
#include <signal.h>
E 3
D 2
#include <sys/types.h>
#include <setjmp.h>
E 2
#include "uucp.h"
I 2
#include <setjmp.h>
E 2
D 3
#include <signal.h>
E 3
#include <sys/stat.h>
I 9
#include <machine/machparam.h>
E 9
D 2
#ifdef USG
#define ftime time
#else V7
#include <sys/timeb.h>
#endif V7
E 2

extern int pkfail();
D 3
extern	time_t	time();
E 3
#define TPACKSIZE	512
#define TBUFSIZE	1024
#define min(a,b)	(((a)<(b))?(a):(b))

/*
 *	htonl is a function that converts a long from host
 *		order to network order
 *	ntohl is a function that converts a long from network
 *		order to host order
 *
 *	network order is 		0 1 2 3 (bytes in a long)
 *	host order on a vax is		3 2 1 0
 *	host order on a pdp11 is	1 0 3 2
 *	host order on a 68000 is	0 1 2 3
 *	most other machines are		0 1 2 3
 */

struct tbuf {
	long t_nbytes;
	char t_data[TBUFSIZE];
};

D 3
jmp_buf Failbuf;
E 3
I 3
extern jmp_buf Failbuf;
E 3

I 7
extern long Bytes_Sent, Bytes_Received;

E 7
D 3
tnullf()
{
	return SUCCESS;
}

E 3
twrmsg(type, str, fn)
char type;
register char *str;
{
	char bufr[TBUFSIZE];
	register char *s;
	int len, i;

	if(setjmp(Failbuf))
		return FAIL;
	signal(SIGALRM, pkfail);
D 7
	alarm(MAXMSGTIME);
E 7
I 7
	alarm(MAXMSGTIME*5);
E 7
	bufr[0] = type;
	s = &bufr[1];
	while (*str)
		*s++ = *str++;
	*s = '\0';
	if (*(--s) == '\n')
		*s = '\0';
	len = strlen(bufr) + 1;
	if ((i = len % TPACKSIZE)) {
		len = len + TPACKSIZE - i;
		bufr[len - 1] = '\0';
	}
	twrblk(bufr, len, fn);
	alarm(0);
	return SUCCESS;
}

trdmsg(str, fn)
register char *str;
{
	int len, cnt = 0;

	if(setjmp(Failbuf))
		return FAIL;
	signal(SIGALRM, pkfail);
D 7
	alarm(MAXMSGTIME);
E 7
I 7
	alarm(MAXMSGTIME*5);
E 7
	for (;;) {
		len = read(fn, str, TPACKSIZE);
D 8
		if (len == 0)
			continue;
		if (len < 0) {
E 8
I 8
		if (len <= 0) {
E 8
			alarm(0);
			return FAIL;
		}
		str += len;
		cnt += len;
		if (*(str - 1) == '\0' && (cnt % TPACKSIZE) == 0)
			break;
	}
	alarm(0);
	return SUCCESS;
}

twrdata(fp1, fn)
FILE *fp1;
{
	struct tbuf bufr;
	register int len;
	int ret, mil;
D 2
#ifdef USG
	time_t t1, t2;
#else v7
E 2
	struct timeb t1, t2;
D 2
#endif v7
E 2
	long bytes;
	char text[TBUFSIZE];
I 7
	float ft;
E 7

	if(setjmp(Failbuf))
		return FAIL;
	signal(SIGALRM, pkfail);
	bytes = 0L;
I 2
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
E 2
	ftime(&t1);
I 2
#endif !USG
E 2
	while ((len = read(fileno(fp1), bufr.t_data, TBUFSIZE)) > 0) {
		bytes += len;
D 6
#if defined(vax) || defined(pdp11)
E 6
I 6
#if defined(vax) || defined(pdp11) || defined(ns32000)
E 6
		bufr.t_nbytes = htonl((long)len);
D 6
#else !vax and !pdp11
E 6
I 6
#else !vax and !pdp11 and !ns32000
E 6
		bufr.t_nbytes = len;
D 6
#endif !vax and !pdp11
E 6
I 6
#endif !vax and !pdp11 and !ns32000
E 6
		DEBUG(8,"twrdata sending %d bytes\n",len);
		len += sizeof(long);
D 7
		alarm(MAXMSGTIME);
E 7
I 7
		alarm(MAXMSGTIME*5);
E 7
D 3
		ret = twrblk(&bufr, len, fn);
E 3
I 3
		ret = twrblk((char *)&bufr, len, fn);
E 3
		alarm(0);
		if (ret != len)
			return FAIL;
		if (len != TBUFSIZE+sizeof(long))
			break;
	}
	bufr.t_nbytes = 0;
	len = sizeof(long);
D 7
	alarm(MAXMSGTIME);
E 7
I 7
	alarm(MAXMSGTIME*5);
E 7
D 3
	ret = twrblk(&bufr, len, fn);
E 3
I 3
	ret = twrblk((char *)&bufr, len, fn);
E 3
	alarm(0);
	if (ret != len)
		return FAIL;
I 2
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
E 2
	ftime(&t2);
D 2
#ifndef USG
E 2
I 2
#endif !USG
	Now = t2;
E 2
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 2
	sprintf(text, "sent data %ld bytes %ld.%03d secs",
				bytes, (long)t2.time, mil);
E 2
I 2
D 7
	sprintf(text, "sent data %ld bytes %ld.%02d secs",
				bytes, (long)t2.time, mil/10);
E 7
I 7
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(text, "sent data %ld bytes %.2f secs %ld bps",
		bytes, ft, (long)((float)bytes*8./ft));
E 7
E 2
D 5
	sysacct(bytes, t2.time - t1.time);
E 5
I 5
	sysacct(bytes, t2.time);
I 7
	Bytes_Sent += bytes;
E 7
E 5
D 2
#else USG
	sprintf(text, "sent data %ld bytes %ld secs", bytes, t2 - t1);
	sysacct(bytes, t2 - t1);
#endif USG
E 2
	DEBUG(1, "%s\n", text);
D 8
	syslog(text);
E 8
I 8
	log_xferstats(text);
E 8
	return SUCCESS;
}

D 6

E 6
trddata(fn, fp2)
FILE *fp2;
{
	register int len, nread;
	char bufr[TBUFSIZE];
D 2
#ifdef USG
	time_t t1, t2;
#else V7
E 2
	struct timeb t1, t2;
	int mil;
D 2
#endif V7
E 2
	long bytes, Nbytes;
I 7
	float ft;
E 7

	if(setjmp(Failbuf))
		return FAIL;
	signal(SIGALRM, pkfail);
I 2
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
E 2
	ftime(&t1);
I 2
#endif !USG
E 2
	bytes = 0L;
	for (;;) {
D 7
		alarm(MAXMSGTIME);
E 7
I 7
		alarm(MAXMSGTIME*5);
E 7
D 3
		len = trdblk(&Nbytes,sizeof Nbytes,fn);
E 3
I 3
		len = trdblk((char *)&Nbytes,sizeof Nbytes,fn);
E 3
		alarm(0);
		if (len != sizeof Nbytes)
			return FAIL;
D 6
#if defined(vax) || defined(pdp11)
E 6
I 6
#if defined(vax) || defined(pdp11) || defined(ns32000)
E 6
		Nbytes = ntohl(Nbytes);
D 6
#endif vax or pdp11
E 6
I 6
#endif vax or pdp11 or ns32000
E 6
		DEBUG(8,"trddata expecting %ld bytes\n",Nbytes);
		nread = Nbytes;
		if (nread == 0)
			break;
D 7
		alarm(MAXMSGTIME);
E 7
I 7
		alarm(MAXMSGTIME*5);
E 7
		len = trdblk(bufr, nread, fn);
		alarm(0);
		if (len < 0) {
			return FAIL;
		}
		bytes += len;
		DEBUG(11,"trddata got %ld\n",bytes);
		if (write(fileno(fp2), bufr, len) != len) {
			alarm(0);
			return FAIL;
		}
	}
I 2
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
E 2
	ftime(&t2);
D 2
#ifndef USG
E 2
I 2
#endif !USG
	Now = t2;
E 2
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 2
	sprintf(bufr, "received data %ld bytes %ld.%03d secs",
				bytes, (long)t2.time, mil);
E 2
I 2
D 7
	sprintf(bufr, "received data %ld bytes %ld.%02d secs",
				bytes, (long)t2.time, mil/10);
E 2
	sysacct(bytes, t2.time - t1.time);
E 7
I 7
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(bufr, "received data %ld bytes %.2f secs %ld bps",
		bytes, ft, (long)((float)bytes*8./ft));
	sysacct(bytes, t2.time);
	Bytes_Received += bytes;
E 7
D 2
#else USG
	sprintf(bufr, "received data %ld bytes %ld secs", bytes, t2 - t1);
	sysacct(bytes, t2 - t1);
#endif USG
E 2
	DEBUG(1, "%s\n", bufr);
D 8
	syslog(bufr);
E 8
I 8
	log_xferstats(bufr);
E 8
	return SUCCESS;
}
D 2

E 2

I 4
#if !defined(BSD4_2) && !defined(USG)
E 4
#define	TC	1024
static	int tc = TC;
I 4
#endif !BSD4_2 && !USG
E 4

trdblk(blk, len,  fn)
register int len;
char *blk;
{
	register int i, ret;

I 4
#if !defined(BSD4_2) && !defined(USG)
E 4
	/* call ultouch occasionally */
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
I 4
#endif !BSD4_2 && !USG
E 4
	for (i = 0; i < len; i += ret) {
		ret = read(fn, blk, len - i);
		if (ret < 0)
			return FAIL;
		blk += ret;
		if (ret == 0)
			return i;
	}
	return i;
}


twrblk(blk, len, fn)
register char *blk;
{
D 4
	register int ret;
E 4
I 4
#if !defined(BSD4_2) && !defined(USG)
E 4
	/* call ultouch occasionally */
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
D 4
	ret = write(fn, blk, len);
	return ret;
E 4
I 4
#endif !BSD4_2 && !USG
	return write(fn, blk, len);
E 4
}
E 1

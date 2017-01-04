h48452
s 00003/00003/00241
d D 5.9 88/04/05 12:05:41 rick 9 8
c use syslog for errors
e
s 00001/00001/00243
d D 5.8 88/02/24 20:08:50 rick 8 7
c add missing sccsid
e
s 00013/00005/00231
d D 5.7 88/02/24 19:56:10 rick 7 6
c log bps and bytes sent/rec
e
s 00002/00002/00234
d D 5.6 85/10/09 17:14:57 bloom 6 5
c accounting fix (rick@seismo again)
e
s 00009/00006/00227
d D 5.5 85/10/09 16:06:50 bloom 5 4
c still more fixes from rick@seismo
e
s 00007/00002/00226
d D 5.4 85/06/20 09:34:36 bloom 4 3
c fixes from rick adams
e
s 00027/00031/00201
d D 5.3 85/04/10 15:19:49 ralph 3 2
c more changes from rick adams.
e
s 00076/00065/00156
d D 5.2 85/01/22 14:08:40 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00221/00000/00000
d D 5.1 83/07/02 17:56:58 sam 1 0
c date and time created 83/07/02 17:56:58 by sam
e
u
U
t
T
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
D 8
static char sccsid[] = "@(#)gio.c	5.6 (Berkeley) 10/9/85";
E 8
I 8
D 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
static char sccsid[] = "%W%	(Berkeley) %G%";
E 9
E 8
E 7
#endif

D 2
#define USER 1
#include "pk.p"
E 2
D 3
#include <sys/types.h>
E 3
I 3
#include "uucp.h"
E 3
#include "pk.h"
#include <setjmp.h>
D 3
#include "uucp.h"
I 2
#ifdef USG
#define ftime time
#else V7
#include <sys/timeb.h>
#endif V7
E 3
E 2

D 4
extern	time_t	time();

E 4
D 2

E 2
jmp_buf Failbuf;

I 4
int Retries = 0;
E 4
struct pack *Pk;

I 7
extern long Bytes_Sent, Bytes_Received;

E 7
pkfail()
{
	longjmp(Failbuf, 1);
}

gturnon()
{
D 2
	int ret;
E 2
	struct pack *pkopen();
I 2

E 2
	if (setjmp(Failbuf))
D 2
		return(FAIL);
	if (Pkdrvon) {
		ret = pkon(Ofn, PACKSIZE);
		DEBUG(4, "pkon - %d ", ret);
		DEBUG(4, "Ofn - %d\n", Ofn);
		if (ret <= 0)
			return(FAIL);
	}
	else {
		if (Debug > 4)
			pkdebug = 1;
		Pk = pkopen(Ifn, Ofn);
		if ((int) Pk == NULL)
			return(FAIL);
	}
	return(0);
E 2
I 2
		return FAIL;
	Pk = pkopen(Ifn, Ofn);
	if (Pk == NULL)
		return FAIL;
	return SUCCESS;
E 2
}

D 2

E 2
gturnoff()
{
	if(setjmp(Failbuf))
		return(FAIL);
D 2
	if (Pkdrvon)
		pkoff(Ofn);
	else
		pkclose(Pk);
	return(0);
E 2
I 2
	pkclose(Pk);
	return SUCCESS;
E 2
}


gwrmsg(type, str, fn)
char type;
register char *str;
{
	char bufr[BUFSIZ];
	register char *s;
	int len, i;

	if(setjmp(Failbuf))
		return(FAIL);
	bufr[0] = type;
	s = &bufr[1];
	while (*str)
		*s++ = *str++;
	*s = '\0';
	if (*(--s) == '\n')
		*s = '\0';
	len = strlen(bufr) + 1;
	if ((i = len % PACKSIZE)) {
		len = len + PACKSIZE - i;
		bufr[len - 1] = '\0';
	}
	gwrblk(bufr, len, fn);
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}

D 2

E 2
I 2
/*ARGSUSED*/
E 2
grdmsg(str, fn)
register char *str;
{
	unsigned len;

	if(setjmp(Failbuf))
D 2
		return(FAIL);
E 2
I 2
		return FAIL;
E 2
	for (;;) {
D 2
		if (Pkdrvon)
			len = read(fn, str, PACKSIZE);
		else
			len = pkread(Pk, str, PACKSIZE);
E 2
I 2
		len = pkread(Pk, str, PACKSIZE);
E 2
		if (len == 0)
			continue;
		str += len;
		if (*(str - 1) == '\0')
			break;
	}
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}


gwrdata(fp1, fn)
FILE *fp1;
{
	char bufr[BUFSIZ];
	register int len;
D 2
	int ret;
E 2
I 2
	int ret, mil;
D 3
#ifdef USG
E 2
	time_t t1, t2;
I 2
#else v7
E 3
	struct timeb t1, t2;
D 3
#endif v7
E 3
E 2
	long bytes;
	char text[BUFSIZ];
I 7
	float ft;
E 7

	if(setjmp(Failbuf))
D 2
		return(FAIL);
E 2
I 2
		return FAIL;
E 2
	bytes = 0L;
I 4
	Retries = 0;
E 4
I 3
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
E 3
D 2
	time(&t1);
	while ((len = fread(bufr, sizeof (char), BUFSIZ, fp1)) > 0) {
E 2
I 2
	ftime(&t1);
I 3
#endif !USG
E 3
	while ((len = read(fileno(fp1), bufr, BUFSIZ)) > 0) {
E 2
		bytes += len;
		ret = gwrblk(bufr, len, fn);
		if (ret != len) {
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if (len != BUFSIZ)
			break;
	}
	ret = gwrblk(bufr, 0, fn);
I 3
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
E 3
D 2
	time(&t2);
E 2
I 2
	ftime(&t2);
D 3
#ifndef USG
E 3
I 3
#endif !USG
	Now = t2;
E 3
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 3
	sprintf(text, "sent data %ld bytes %ld.%03d secs",
				bytes, (long)t2.time, mil);
E 3
I 3
D 7
	sprintf(text, "sent data %ld bytes %ld.%02d secs",
				bytes, (long)t2.time, mil/10);
E 7
I 7
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(text, "sent data %ld bytes %.2f secs %ld bps",
		bytes, ft, (long)((float)bytes*8./ft));
E 7
E 3
D 6
	sysacct(bytes, t2.time - t1.time);
E 6
I 6
	sysacct(bytes, t2.time);
I 7
	Bytes_Sent += bytes;
E 7
E 6
I 4
	if (Retries > 0) 
		sprintf((char *)text+strlen(text)," %d retries", Retries);
E 4
D 3
#else USG
E 2
	sprintf(text, "sent data %ld bytes %ld secs", bytes, t2 - t1);
I 2
	sysacct(bytes, t2 - t1);
#endif USG
E 3
E 2
	DEBUG(1, "%s\n", text);
D 9
	syslog(text);
E 9
I 9
	log_xferstats(text);
E 9
D 2
	sysacct(bytes, t2 - t1);
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}

D 3

E 3
grddata(fn, fp2)
FILE *fp2;
{
	register int len;
	char bufr[BUFSIZ];
I 2
D 3
#ifdef USG
E 2
	time_t t1, t2;
I 2
#else v7
E 3
	struct timeb t1, t2;
	int mil;
D 3
#endif v7
E 3
E 2
	long bytes;
	char text[BUFSIZ];
I 7
	float ft;
E 7

	if(setjmp(Failbuf))
D 2
		return(FAIL);
E 2
I 2
		return FAIL;
E 2
	bytes = 0L;
I 4
	Retries = 0;
E 4
I 3
#ifdef USG
	time(&t1.time);
	t1.millitm = 0;
#else !USG
E 3
D 2
	time(&t1);
E 2
I 2
	ftime(&t1);
I 3
#endif !USG
E 3
E 2
	for (;;) {
		len = grdblk(bufr, BUFSIZ, fn);
		if (len < 0) {
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		bytes += len;
D 2
		/* ittvax!swatt: check return value of fwrite */
		if (fwrite(bufr, sizeof (char), len, fp2) != len)
			return(FAIL);
E 2
I 2
		if (write(fileno(fp2), bufr, len) != len)
			return FAIL;
E 2
		if (len < BUFSIZ)
			break;
	}
I 3
#ifdef USG
	time(&t2.time);
	t2.millitm = 0;
#else !USG
E 3
D 2
	time(&t2);
E 2
I 2
	ftime(&t2);
D 3
#ifndef USG
E 3
I 3
#endif !USG
	Now = t2;
E 3
	t2.time -= t1.time;
	mil = t2.millitm - t1.millitm;
	if (mil < 0) {
		--t2.time;
		mil += 1000;
	}
D 3
	sprintf(text, "received data %ld bytes %ld.%03d secs",
				bytes, (long)t2.time, mil);
E 3
I 3
D 7
	sprintf(text, "received data %ld bytes %ld.%02d secs",
				bytes, (long)t2.time, mil/10);
E 7
I 7
	ft = (float)t2.time + (float)mil/1000.;
	sprintf(text, "received data %ld bytes %.2f secs %ld bps",
		bytes, ft, (long)((float)bytes*8./ft));
E 7
E 3
D 6
	sysacct(bytes, t2.time - t1.time);
E 6
I 6
	sysacct(bytes, t2.time);
I 7
	Bytes_Received += bytes;
E 7
E 6
I 4
	if (Retries > 0) 
		sprintf((char *)text+strlen(text)," %d retries", Retries);
E 4
D 3
#else USG
E 2
	sprintf(text, "received data %ld bytes %ld secs", bytes, t2 - t1);
I 2
	sysacct(bytes, t2 - t1);
#endif USG
E 3
E 2
	DEBUG(1, "%s\n", text);
D 9
	syslog(text);
E 9
I 9
	log_xferstats(text);
E 9
D 2
	sysacct(bytes, t2 - t1);
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}
D 3

E 3

D 5
/* call ultouch every TC calls to either grdblk or gwrblk -- rti!trt */
E 5
I 5
#if !defined(BSD4_2) && !defined(USG)
/* call ultouch every TC calls to either grdblk or gwrblk */
E 5
#define	TC	20
static	int tc = TC;
I 5
#endif !BSD4_2 && !USG
E 5

I 2
/*ARGSUSED*/
E 2
grdblk(blk, len,  fn)
register int len;
char *blk;
{
	register int i, ret;

I 5
#if !defined(BSD4_2) && !defined(USG)
E 5
D 2
	/* call ultouch occasionally -- rti!trt */
E 2
I 2
	/* call ultouch occasionally */
E 2
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
I 5
#endif !BSD4_2 && !USG
E 5
	for (i = 0; i < len; i += ret) {
D 2
		if (Pkdrvon)
			ret = read(fn, blk, len - i);
		else
			ret = pkread(Pk, blk, len - i);
E 2
I 2
		ret = pkread(Pk, blk, len - i);
E 2
		if (ret < 0)
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		blk += ret;
		if (ret == 0)
D 2
			return(i);
E 2
I 2
			return i;
E 2
	}
D 2
	return(i);
E 2
I 2
	return i;
E 2
}

D 2

E 2
I 2
/*ARGSUSED*/
E 2
gwrblk(blk, len, fn)
register char *blk;
{
D 5
	register int ret;

	/* call ultouch occasionally -- rti!trt */
E 5
I 5
#if !defined(BSD4_2) && !defined(USG)
	/* call ultouch occasionally */
E 5
	if (--tc < 0) {
		tc = TC;
		ultouch();
	}
D 2
	if (Pkdrvon)
		ret = write(fn, blk, len);
	else
		ret = pkwrite(Pk, blk, len);
	return(ret);
E 2
I 2
D 5
	ret = pkwrite(Pk, blk, len);
	return ret;
E 5
I 5
#endif !BSD4_2 && !USG
	return  pkwrite(Pk, blk, len);
E 5
E 2
}
E 1

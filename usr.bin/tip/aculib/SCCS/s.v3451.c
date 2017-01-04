h59676
s 00007/00001/00175
d D 5.1 85/04/30 12:54:32 dist 5 4
c Add copyright
e
s 00000/00002/00176
d D 4.4 83/06/25 02:10:08 sam 4 3
c remove #if's, now in a library
e
s 00008/00008/00170
d D 4.3 83/06/25 01:15:00 sam 3 2
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00072/00136/00106
d D 4.2 83/06/24 21:23:38 sam 2 1
c cleanup
e
s 00242/00000/00000
d D 4.1 83/06/15 12:05:42 ralph 1 0
c date and time created 83/06/15 12:05:42 by ralph
e
u
U
t
T
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif
E 5
I 5
#endif not lint
E 5
E 3

D 3
#if VADIC
E 3
I 3
D 4
#ifdef V3451
E 4
E 3
/*
 * Routines for calling up on a Vadic 3451 Modem
 */
#include "tip.h"
D 3
#include <setjmp.h>
#include <errno.h>
#include <signal.h>
E 3

D 2
static char *sccsid = "%W% %G%";
E 2
I 2
static	jmp_buf Sjbuf;
E 2

D 2
int	va_delay;
static	int	fudge=0;	/* for sleep in vawrite */
jmp_buf Sjbuf;

E 2
D 3
vadic_dialer(num, acu)
E 3
I 3
v3451_dialer(num, acu)
E 3
	register char *num;
	char *acu;
{
D 2
	int lt;
	int ok;
E 2
I 2
	int ok, (*func)();
	int slow = number(value(BAUDRATE)) < 1200, rw = 2;
E 2
	char phone[50];
#ifdef ACULOG
	char line[80];
#endif
D 2
	int (*func) ();
E 2

D 2
	if(number(value(BAUDRATE)) < 1200)
		fudge = 1;
E 2
	/*
	 * Get in synch
	 */
D 2
	lt = strlen(num);
	va_delay = 15 + 3*lt;
	vawrite("I\r",1);
	vawrite("I\r",1);
	vawrite("I\r",1);
	vawrite("\005\r",2);
	ok = expect("READY");

	if ( ok ) {
E 2
I 2
	vawrite("I\r", 1 + slow);
	vawrite("I\r", 1 + slow);
	vawrite("I\r", 1 + slow);
	vawrite("\005\r", 2 + slow);
	if (!expect("READY")) {
E 2
		printf("can't synchronize with vadic 3451\n");
#ifdef ACULOG
		logent(value(HOST), num, "vadic", "can't synch up");
#endif
		return (0);
	}
	ioctl(FD, TIOCHPCL, 0);
	sleep(1);
D 2
	vawrite("D\r",2);
	ok = expect("NUMBER?");
	if ( ok ) {
E 2
I 2
	vawrite("D\r", 2 + slow);
	if (!expect("NUMBER?")) {
E 2
		printf("Vadic will not accept dial command\n");
#ifdef ACULOG
		logent(value(HOST), num, "vadic", "will not accept dial");
#endif
		return (0);
	}
D 2
	strcpy(phone,num);
	strcat(phone,"\r");
	vawrite(phone,1);
	ok = expect(phone);
	if ( ok ) {
E 2
I 2
	strcpy(phone, num);
	strcat(phone, "\r");
	vawrite(phone, 1 + slow);
	if (!expect(phone)) {
E 2
		printf("Vadic will not accept phone number\n");
#ifdef ACULOG
		logent(value(HOST), num, "vadic", "will not accept number");
#endif
		return (0);
	}
	func = signal(SIGINT,SIG_IGN);
D 2
	/* You cannot interrupt the Vadic when its dialing */
	/* Even dropping DTR does not work /*
	/* Definitely a Brain Damaged Design */
	vawrite("\r",1);
	vawrite("\r",1);
	ok = expect("DIALING:");
	if ( ok ) {
E 2
I 2
	/*
	 * You cannot interrupt the Vadic when its dialing;
	 * even dropping DTR does not work (definitely a
	 * brain damaged design).
	 */
	vawrite("\r", 1 + slow);
	vawrite("\r", 1 + slow);
	if (!expect("DIALING:")) {
E 2
		printf("Vadic failed to dial\n");
#ifdef ACULOG
		logent(value(HOST), num, "vadic", "failed to dial");
#endif
		return (0);
D 2
	} else
		printf("dialing...\n");
E 2
I 2
	}
	if (boolean(value(VERBOSE)))
		printf("\ndialing...");
E 2
	ok = expect("ON LINE");
D 2
	signal(SIGINT,func);
	if ( ok ) {
E 2
I 2
	signal(SIGINT, func);
	if (!ok) {
E 2
		printf("call failed\n");
#ifdef ACULOG
		logent(value(HOST), num, "vadic", "call failed");
#endif
		return (0);
	}
D 2
	ioctl(FD, TIOCFLUSH);
E 2
I 2
	ioctl(FD, TIOCFLUSH, &rw);
E 2
	return (1);
}

D 3
vadic_disconnect()
E 3
I 3
v3451_disconnect()
E 3
{
D 2
	char string[100];
E 2
I 2

E 2
	close(FD);
D 2
	sleep(5); /* insure that the phone line is dropped */
	sprintf(string,"/usr/lib/uucp/enable %s\n",rindex(DV,'/')+1);
	system(string);
E 2
}

D 3
vadic_abort()
E 3
I 3
v3451_abort()
E 3
{
D 2
	vadic_disconnect();
E 2
I 2

	close(FD);
E 2
}

D 2
vawrite(str,delay)
char *str;
int delay;
E 2
I 2
static
vawrite(cp, delay)
	register char *cp;
	int delay;
E 2
{
D 2
	while(*str)
	{
		write(FD,str,1);
		sleep(delay+fudge);
		str++;
	}
	return;
E 2
I 2

	for (; *cp; sleep(delay), cp++)
		write(FD, cp, 1);
E 2
}

D 2

#define MR 300

int Error = 0;

/***
 *	expect(str)	look for expected string
 *	char *str;
 *
 *	return codes:
 *		0  -  found
 *		FAIL  -  lost line or too many characters read
 *		some character  -  timed out
 */

expect(str)
char *str;
E 2
I 2
static
expect(cp)
	register char *cp;
E 2
{
D 2
	static char rdvec[MR];
	extern alarmtr();
	char *rp = rdvec;
	int nextch = 0, kr;
	int alarm_tm;
	int expect_online = 0;
E 2
I 2
	char buf[300];
	register char *rp = buf;
	int alarmtr(), timeout = 30, online = 0;
E 2

D 2
	if (strcmp(str, "\"\"") == 0)
		return(0);
E 2
I 2
	if (strcmp(cp, "\"\"") == 0)
		return (1);
E 2
	*rp = 0;
	/*
	 * If we are waiting for the Vadic to complete
	 * dialing and get a connection, allow more time
	 * Unfortunately, the Vadic times out 24 seconds after
	 * the last digit is dialed
	 */
D 2
	if(strcmp(str, "ON LINE") == 0){
		alarm_tm = number(value(DIALTIMEOUT));
		expect_online++;
	}
	else
		alarm_tm = 30;
	if (setjmp(Sjbuf)) {
		return(1);
	}
E 2
I 2
	online = strcmp(cp, "ON LINE") == 0;
	if (online)
		timeout = number(value(DIALTIMEOUT));
E 2
	signal(SIGALRM, alarmtr);
D 2
	alarm(alarm_tm);
	while (notin(str, rdvec)) {
		if(expect_online)
			if(notin("FAILED CALL", rdvec) == 0)
				return(1);
		kr = read(FD, &nextch, 1);
		if (kr <= 0) {
E 2
I 2
	if (setjmp(Sjbuf))
		return (0);
	alarm(timeout);
	while (notin(cp, buf) && rp < buf + sizeof (buf) - 1) {
		if (online && notin("FAILED CALL", buf) == 0)
			return (0);
		if (read(FD, rp, 1) < 0) {
E 2
			alarm(0);
D 2
			return(1);
E 2
I 2
			return (0);
E 2
		}
D 2
		{
		int c;
		c = nextch & 0177;
		}
		if ((*rp = nextch & 0177) != '\0')
E 2
I 2
		if (*rp &= 0177)
E 2
			rp++;
		*rp = '\0';
D 2
		if (rp >= rdvec + MR)
			return(1);
E 2
	}
	alarm(0);
D 2
	return(0);
E 2
I 2
	return (1);
E 2
}

D 2
/***
 *	alarmtr()  -  catch alarm routine for "expect".
 */

E 2
I 2
static
E 2
alarmtr()
{
I 2

E 2
	longjmp(Sjbuf, 1);
}

D 2
/***
 *	notin(sh, lg)	check for occurrence of substring "sh"
 *	char *sh, *lg;
 *
 *	return codes:
 *		0  -  found the string
 *		1  -  not in the string
 */

E 2
I 2
static
E 2
notin(sh, lg)
D 2
char *sh, *lg;
E 2
I 2
	char *sh, *lg;
E 2
{
D 2
	while (*lg != '\0') {
E 2
I 2

	for (; *lg; lg++)
E 2
		if (prefix(sh, lg))
D 2
			return(0);
		else
			lg++;
	}
	return(1);
E 2
I 2
			return (0);
	return (1);
E 2
}

D 2
/*******
 *	prefix(s1, s2)	check s2 for prefix s1
 *	char *s1, *s2;
 *
 *	return 0 - !=
 *	return 1 - == 
 */

E 2
I 2
static
E 2
prefix(s1, s2)
D 2
char *s1, *s2;
E 2
I 2
	register char *s1, *s2;
E 2
{
D 2
	char c;
E 2
I 2
	register char c;
E 2

	while ((c = *s1++) == *s2++)
		if (c == '\0')
D 2
			return(1);
	return(c == '\0');
E 2
I 2
			return (1);
	return (c == '\0');
E 2
}
I 3
D 4
#endif
E 4
E 3
E 1

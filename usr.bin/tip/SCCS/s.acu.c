h13876
s 00004/00001/00161
d D 5.5 87/12/04 20:11:44 marc 17 16
c Log connections to hardwired ports
e
s 00001/00002/00161
d D 5.4 87/02/09 12:08:26 karels 16 15
c formalize uid swapping and force everywhere
e
s 00003/00002/00160
d D 5.3 86/04/03 16:57:48 donn 15 14
c Phone numbers in the phones file end in ',' or '\n'.
e
s 00002/00002/00160
d D 5.2 85/11/29 18:55:07 donn 14 13
c Fixed a bug that caused the phone number to be written in place of
c the connection message; also made the phone number format more liberal
c (anything goes except commas -- '%' and '&' work for VenTels, etc.).
e
s 00007/00001/00155
d D 5.1 85/06/06 09:47:59 dist 13 12
c Add copyright
e
s 00001/00001/00155
d D 4.12 83/10/15 20:35:24 sam 12 11
c correct action of disconnect 
e
s 00009/00005/00147
d D 4.11 83/10/08 13:57:45 sam 11 10
c recognize and handle carrier loss
e
s 00003/00003/00149
d D 4.10 83/07/16 18:37:32 sam 10 9
c better message?
e
s 00004/00003/00148
d D 4.9 83/06/25 01:13:00 sam 9 8
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00006/00003/00145
d D 4.8 83/06/15 13:51:18 ralph 8 7
c changes for local info, parity, vadic auto dialers
e
s 00002/00002/00146
d D 4.7 82/07/29 15:23:11 shannon 7 6
c Ventel fixes - allow %, $ in phone number
e
s 00002/00001/00146
d D 4.6 82/02/02 13:11:35 shannon 6 5
c fix bug when tip is given phone number
e
s 00010/00010/00137
d D 4.5 81/11/29 22:48:46 sam 5 4
c reformatting
e
s 00001/00001/00146
d D 4.4 81/11/20 10:44:06 sam 4 3
c cosmetics
e
s 00001/00001/00146
d D 4.3 81/11/16 16:03:16 sam 3 2
c missing param to longjmp
e
s 00001/00001/00146
d D 4.2 81/10/02 23:00:28 sam 2 1
c missing parameter to acu_dialer
e
s 00147/00000/00000
d D 4.1 81/05/09 16:45:06 root 1 0
c date and time created 81/05/09 16:45:06 by root
e
u
U
t
T
I 13
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 13
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif
E 13
I 13
#endif not lint
E 13

E 9
#include "tip.h"
D 9
#include <setjmp.h>
E 9

I 8
D 9
static char *sccsid = "%W% %G%";
E 9
E 8
static acu_t *acu = NOACU;
static int conflag;
static int acuabort();
static acu_t *acutype();
static jmp_buf jmpbuf;
/*
 * Establish connection for tip
 *
 * If DU is true, we should dial an ACU whose type is AT.
 * The phone numbers are in PN, and the call unit is in CU.
 *
 * If the PN is an '@', then we consult the PHONES file for
 *   the phone numbers.  This file is /etc/phones, unless overriden
 *   by an exported shell variable.
 *
 * The data base files must be in the format:
 *	host-name[ \t]*phone-number
 *   with the possibility of multiple phone numbers
 *   for a single host acting as a rotary (in the order
 *   found in the file).
 */
char *
connect()
{
	register char *cp = PN;
	char *phnum, string[256];
	FILE *fd;
	int tried = 0;

	if (!DU) {		/* regular connect message */
		if (CM != NOSTR)
D 8
			write(FD, cp, size(CM));
E 8
I 8
D 14
			pwrite(FD, cp, size(CM));
E 14
I 14
			pwrite(FD, CM, size(CM));
I 17
		logent(value(HOST), "", DV, "call completed");
E 17
E 14
E 8
D 5
		return(NOSTR);
E 5
I 5
		return (NOSTR);
E 5
	}
	/*
	 * @ =>'s use data base in PHONES environment variable
	 *        otherwise, use /etc/phones
	 */
	signal(SIGINT, acuabort);
	signal(SIGQUIT, acuabort);
	if (setjmp(jmpbuf)) {
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		printf("\ncall aborted\n");
		logent(value(HOST), "", "", "call aborted");
		if (acu != NOACU) {
			boolean(value(VERBOSE)) = FALSE;
			if (conflag)
D 11
				disconnect();
E 11
I 11
				disconnect(NOSTR);
E 11
			else
				(*acu->acu_abort)();
		}
D 16
		delock(uucplock);
		exit(1);
E 16
I 16
		return ("interrupt");
E 16
	}
	if ((acu = acutype(AT)) == NOACU)
D 5
		return("unknown ACU type");
E 5
I 5
		return ("unknown ACU type");
E 5
	if (*cp != '@') {
		while (*cp) {
D 7
			for (phnum = cp; any(*cp, "0123456789-*="); cp++)
E 7
I 7
D 8
			for (phnum = cp; any(*cp, "0123456789-*=&%"); cp++)
E 8
I 8
D 14
			for (phnum = cp; any(*cp, "0123456789-*=K"); cp++)
E 14
I 14
			for (phnum = cp; *cp && *cp != ','; cp++)
E 14
E 8
E 7
				;
D 6
			*cp++ = '\0';
E 6
I 6
			if (*cp)
				*cp++ = '\0';
E 6
			
			if (conflag = (*acu->acu_dialer)(phnum, CU)) {
				logent(value(HOST), phnum, acu->acu_name,
					"call completed");
D 5
				return(NOSTR);
E 5
I 5
				return (NOSTR);
E 5
			} else
				logent(value(HOST), phnum, acu->acu_name,
D 10
					"no answer");
E 10
I 10
					"call failed");
E 10
			tried++;
		}
	} else {
		if ((fd = fopen(PH, "r")) == NOFILE) {
			printf("%s: ", PH);
D 5
			return("can't open phone number file");
E 5
I 5
			return ("can't open phone number file");
E 5
		}
		while (fgets(string, sizeof(string), fd) != NOSTR) {
			for (cp = string; !any(*cp, " \t\n"); cp++)
				;
			if (*cp == '\n') {
				fclose(fd);
D 5
				return("unrecognizable host name");
E 5
I 5
				return ("unrecognizable host name");
E 5
			}
			*cp++ = '\0';
			if (strcmp(string, value(HOST)))
				continue;
			while (any(*cp, " \t"))
				cp++;
			if (*cp == '\n') {
				fclose(fd);
D 5
				return("missing phone number");
E 5
I 5
				return ("missing phone number");
E 5
			}
D 7
			for (phnum = cp; any(*cp, "0123456789-*="); cp++)
E 7
I 7
D 8
			for (phnum = cp; any(*cp, "0123456789-*=&%"); cp++)
E 8
I 8
D 15
			for (phnum = cp; any(*cp, "0123456789-*="); cp++)
E 15
I 15
			for (phnum = cp; *cp && *cp != ',' && *cp != '\n'; cp++)
E 15
E 8
E 7
				;
D 15
			*cp = '\0';
E 15
I 15
			if (*cp)
				*cp++ = '\0';
E 15
			
D 2
			if (conflag = (*acu->acu_dialer)(phnum)) {
E 2
I 2
			if (conflag = (*acu->acu_dialer)(phnum, CU)) {
E 2
				fclose(fd);
				logent(value(HOST), phnum, acu->acu_name,
					"call completed");
D 5
				return(NOSTR);
E 5
I 5
				return (NOSTR);
E 5
			} else
				logent(value(HOST), phnum, acu->acu_name,
D 10
					"no answer");
E 10
I 10
					"call failed");
E 10
			tried++;
		}
		fclose(fd);
	}
	if (!tried)
		logent(value(HOST), "", acu->acu_name, "missing phone number");
I 8
	else
		(*acu->acu_abort)();
E 8
D 5
	return(tried ? "no answer" : "missing phone number");
E 5
I 5
D 10
	return (tried ? "no answer" : "missing phone number");
E 10
I 10
	return (tried ? "call failed" : "missing phone number");
E 10
E 5
}

D 11
disconnect()
E 11
I 11
disconnect(reason)
	char *reason;
E 11
{
D 17
	if (!conflag)
E 17
I 17
	if (!conflag) {
		logent(value(HOST), "", DV, "call terminated");
E 17
		return;
I 17
	}
E 17
D 11
	logent(value(HOST), "", acu->acu_name, "call terminated");
	if (boolean(value(VERBOSE)))
		printf("\r\ndisconnecting...");
E 11
I 11
D 12
	if (reason != NOSTR) {
E 12
I 12
	if (reason == NOSTR) {
E 12
		logent(value(HOST), "", acu->acu_name, "call terminated");
		if (boolean(value(VERBOSE)))
			printf("\r\ndisconnecting...");
	} else 
		logent(value(HOST), "", acu->acu_name, reason);
E 11
	(*acu->acu_disconnect)();
}

static int
acuabort(s)
{
	signal(s, SIG_IGN);
D 3
	longjmp(jmpbuf);
E 3
I 3
	longjmp(jmpbuf, 1);
E 3
}

static acu_t *
acutype(s)
D 4
register char *s;
E 4
I 4
	register char *s;
E 4
{
	register acu_t *p;
	extern acu_t acutable[];

	for (p = acutable; p->acu_name != '\0'; p++)
		if (!strcmp(s, p->acu_name))
D 5
			return(p);
	return(NOACU);
E 5
I 5
			return (p);
	return (NOACU);
E 5
}
E 1

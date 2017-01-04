h60063
s 00011/00009/00061
d D 5.5 88/06/30 14:59:57 bostic 18 17
c install approved copyright notice
e
s 00023/00027/00047
d D 5.4 88/04/01 15:35:50 bostic 17 16
c add CONFIG error, #78, for local configuration botches
e
s 00016/00010/00058
d D 5.3 88/03/13 19:53:26 bostic 16 15
c add Berkeley specific header
e
s 00000/00002/00068
d D 5.2 85/06/07 22:20:14 miriam 15 14
m 
c Resolve duplicate SccsId
e
s 00014/00000/00056
d D 5.1 85/06/07 15:17:03 dist 14 13
m 
c Add copyright
e
s 00028/00000/00028
d D 4.3 85/05/24 10:54:49 eric 13 12
m 
c Changes from Bill Nowicki <sun!rose!nowicki> and Jay Lepreau <lepreau@utah-cs>:
c Fix "bad file number" problem; improve error reporting; try to keep messages
c closer to their original order.  Also, drop "safe" mode in readcf since we
c never run setuid when -C is specified.
e
s 00001/00000/00027
d D 4.2 83/07/31 10:46:19 eric 12 11
m 
c Add EX_NOPERM to sysexits.h for kre
e
s 00000/00000/00027
d D 4.1 83/07/25 19:43:10 eric 11 10
m 
c 4.2 release version
e
s 00001/00001/00026
d D 3.6 83/01/04 13:10:01 eric 10 9
m 
c change format of deferred message to be consistent with other messages
e
s 00013/00013/00014
d D 3.5 82/08/31 10:06:08 eric 9 8
c clean up reply code processing some more; in particular, give more
c detail in many messages.  process connection failures correctly.
e
s 00013/00012/00014
d D 3.4 82/08/29 17:32:57 eric 8 7
c fix serious botch in SMTP reply code delta; change a bunch of
c "Internal error" codes to a new "Remote protocol error" -- so that
c I don't get blamed for things that other systems do.
e
s 00002/00001/00024
d D 3.3 81/12/06 12:38:57 eric 7 6
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00001/00000/00024
d D 3.2 81/10/15 20:38:07 eric 6 5
c add EX_TEMPFAIL
e
s 00000/00000/00024
d D 3.1 81/03/07 14:27:08 eric 5 4
c ----- delivermail ==> postbox -----
e
s 00000/00000/00024
d D 2.1 80/11/05 11:00:08 eric 4 3
c release 2
e
s 00003/00000/00021
d D 1.3 80/08/02 13:50:02 eric 3 2
c cleaned up comments
e
s 00002/00000/00019
d D 1.2 80/07/25 22:04:26 eric 2 1
c add ID keywords
e
s 00019/00000/00000
d D 1.1 80/06/23 08:24:42 eric 1 0
e
u
U
f b 
f i 
t
T
I 14
/*
I 18
 * Copyright (c) 1983 Eric P. Allman
E 18
D 16
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 16
I 16
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 18
I 18
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 18
 */
E 16

#ifndef lint
D 16
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 16
I 16
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 16

E 14
I 1
D 17
# include <sysexits.h>
I 7
# include "useful.h"
E 17
I 17
#include <sysexits.h>
E 17
E 7

I 2
D 7
static char	SccsId[] = "%W%	%G%";
E 7
I 7
D 15
SCCSID(%W%	%Y%	%G%);
E 7
E 2

E 15
I 3
/*
D 17
**  SYSEXITS.C -- error messages corresponding to sysexits.h
*/
E 3
I 2

E 2
char	*SysExMsg[] =
{
E 17
I 17
 *  SYSEXITS.C -- error messages corresponding to sysexits.h
 */
char *SysExMsg[] = {
E 17
D 8
	/* 64 */	"Bad usage",
	/* 65 */	"Data format error",
	/* 66 */	"Cannot open input",
	/* 67 */	"User unknown",
	/* 68 */	"Host unknown",
	/* 69 */	"Service unavailable",
	/* 70 */	"Internal error",
	/* 71 */	"Operating system error",
	/* 72 */	"System file missing",
	/* 73 */	"Can't create output",
	/* 74 */	"I/O error",
I 6
	/* 75 */	"Temporary failure",
E 8
I 8
D 9
	/* 64 USAGE */		"Bad usage",
	/* 65 DATAERR */	"Data format error",
	/* 66 NOINPUT */	"Cannot open input",
	/* 67 NOUSER */		"User unknown",
	/* 68 NOHOST */		"Host unknown",
	/* 69 UNAVAILABLE */	"Service unavailable",
	/* 70 SOFTWARE */	"Internal error",
	/* 71 OSERR */		"Operating system error",
	/* 72 OSFILE */		"System file missing",
	/* 73 CANTCREAT */	"Can't create output",
	/* 74 IOERR */		"I/O error",
	/* 75 TEMPFAIL */	"Temporary failure",
	/* 76 PROTOCOL */	"Remote protocol error",
E 9
I 9
	/* 64 USAGE */		"500 Bad usage",
	/* 65 DATAERR */	"501 Data format error",
	/* 66 NOINPUT */	"550 Cannot open input",
	/* 67 NOUSER */		"550 User unknown",
	/* 68 NOHOST */		"550 Host unknown",
	/* 69 UNAVAILABLE */	"554 Service unavailable",
	/* 70 SOFTWARE */	"554 Internal error",
	/* 71 OSERR */		"451 Operating system error",
	/* 72 OSFILE */		"554 System file missing",
	/* 73 CANTCREAT */	"550 Can't create output",
	/* 74 IOERR */		"451 I/O error",
D 10
	/* 75 TEMPFAIL */	"250 Temporary failure",
E 10
I 10
	/* 75 TEMPFAIL */	"250 Deferred",
E 10
	/* 76 PROTOCOL */	"554 Remote protocol error",
I 12
	/* 77 NOPERM */		"550 Insufficient permission",
I 17
	/* 78 CONFIG */		"554 Local configuration error",
E 17
E 12
E 9
E 8
E 6
};

D 17
int	N_SysEx = sizeof SysExMsg / sizeof SysExMsg[0];
I 13
/*
**  STATSTRING -- return string corresponding to an error status
**
**	Parameters:
**		stat -- the status to decode.
**
**	Returns:
**		The string corresponding to that status
**
**	Side Effects:
**		none.
*/
E 17
I 17
int N_SysEx = sizeof(SysExMsg) / sizeof(SysExMsg[0]);
E 17

I 17
/*
 *  STATSTRING -- return string corresponding to an error status
 *
 *	Parameters:
 *		stat -- the status to decode.
 *
 *	Returns:
 *		The string corresponding to that status
 *
 *	Side Effects:
 *		none.
 */
E 17
char *
statstring(stat)
	int stat;
{
D 17
	static char ebuf[100];
E 17
I 17
	static char ebuf[50];
E 17

	stat -= EX__BASE;
D 17
	if (stat < 0 || stat >= N_SysEx)
	{
		(void) sprintf(ebuf, "554 Unknown status %d", stat + EX__BASE);
		return (ebuf);
E 17
I 17
	if (stat < 0 || stat >= N_SysEx) {
		(void)sprintf(ebuf, "554 Unknown status %d", stat + EX__BASE);
		return(ebuf);
E 17
	}
D 17

	return (SysExMsg[stat]);
E 17
I 17
	return(SysExMsg[stat]);
E 17
}
E 13
E 1

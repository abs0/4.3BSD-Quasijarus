h23553
s 00010/00005/00060
d D 5.6 88/06/18 14:10:40 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00056
d D 5.5 88/05/20 11:53:29 bostic 8 7
c add Berkeley specific header
e
s 00003/00003/00056
d D 5.4 87/10/22 11:18:56 bostic 7 6
c ANSI C; sprintf now returns an int.
e
s 00001/00000/00058
d D 5.3 87/09/04 17:07:10 mckusick 6 5
c need <sys/param.h> to get hton funcs (4.3BSD/etc/88)
e
s 00037/00017/00021
d D 5.2 86/03/13 17:12:57 mckusick 5 4
c new version from sam@monet.berkeley.edu
e
s 00008/00002/00030
d D 5.1 85/06/06 09:19:27 dist 4 3
c Add copyright
e
s 00014/00009/00018
d D 1.3 84/05/11 14:18:49 layer 3 2
c use debugout as the FILE * to print debug msgs
e
s 00014/00012/00013
d D 1.2 84/04/11 15:14:39 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00025/00000/00000
d D 1.1 84/04/11 15:03:06 karels 1 0
c date and time created 84/04/11 15:03:06 by karels
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

E 4
I 1
D 2
/* $Header: print.c 1.4 83/03/28 00:34:25 moore Exp $ */
E 2
I 2
#ifndef lint
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
I 3
D 4
static char sccsid[] = "@(#)print.c	1.2 (Berkeley) 4/11/84";
E 3
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 4
E 2

/* debug print routines */

#include <stdio.h>
D 5
#include "ctl.h"
E 5
I 5
#include <syslog.h>
I 6
#include <sys/param.h>
E 6
E 5

D 5
print_request(request)
D 2
CTL_MSG *request;
E 2
I 2
	CTL_MSG *request;
E 5
I 5
#include <protocols/talkd.h>

static	char *types[] =
    { "leave_invite", "look_up", "delete", "announce" };
#define	NTYPES	(sizeof (types) / sizeof (types[0]))
static	char *answers[] = 
    { "success", "not_here", "failed", "machine_unknown", "permission_denied",
      "unknown_request", "badversion", "badaddr", "badctladdr" };
#define	NANSWERS	(sizeof (answers) / sizeof (answers[0]))

print_request(cp, mp)
	char *cp;
	register CTL_MSG *mp;
E 5
E 2
{
I 3
D 5
    	extern FILE *debugout;
E 5
I 5
	char tbuf[80], *tp;
E 5
E 3
D 2
    
    printf("type is %d, l_user %s, r_user %s, r_tty %s\n",
	    request->type, request->l_name, request->r_name,
	    request->r_tty);
    printf("        id = %d\n", request->id_num);
    fflush(stdout);
E 2
I 2
	
D 3
	printf("type is %d, l_user %s, r_user %s, r_tty %s\n",
		request->type, request->l_name, request->r_name,
		request->r_tty);
	printf("		id = %d\n", request->id_num);
	fflush(stdout);
E 3
I 3
D 5
	fprintf(debugout
		, "type is %d, l_user %s, r_user %s, r_tty %s\n"
		, request->type, request->l_name, request->r_name
		, request->r_tty);
	fprintf(debugout, "		id = %d\n", request->id_num);
	fflush(debugout);
E 5
I 5
	if (mp->type > NTYPES) {
D 7
		sprintf(tbuf, "type %d", mp->type);
E 7
I 7
		(void)sprintf(tbuf, "type %d", mp->type);
E 7
		tp = tbuf;
	} else
		tp = types[mp->type];
	syslog(LOG_DEBUG, "%s: %s: id %d, l_user %s, r_user %s, r_tty %s",
	    cp, tp, mp->id_num, mp->l_name, mp->r_name, mp->r_tty);
E 5
E 3
E 2
}

D 5
print_response(response)
D 2
CTL_RESPONSE *response;
E 2
I 2
	CTL_RESPONSE *response;
E 5
I 5
print_response(cp, rp)
	char *cp;
	register CTL_RESPONSE *rp;
E 5
E 2
{
D 2
    printf("type is %d, answer is %d, id = %d\n\n", response->type, 
	    response->answer, response->id_num);
    fflush(stdout);
E 2
I 2
D 3
	printf("type is %d, answer is %d, id = %d\n\n", response->type, 
		response->answer, response->id_num);
	fflush(stdout);
E 3
I 3
D 5
    	extern FILE *debugout;
E 5
I 5
	char tbuf[80], *tp, abuf[80], *ap;
E 5
	
D 5
	printf(debugout
		, "type is %d, answer is %d, id = %d\n\n", response->type
		, response->answer, response->id_num);
	fflush(debugout);
E 5
I 5
	if (rp->type > NTYPES) {
D 7
		sprintf(tbuf, "type %d", rp->type);
E 7
I 7
		(void)sprintf(tbuf, "type %d", rp->type);
E 7
		tp = tbuf;
	} else
		tp = types[rp->type];
	if (rp->answer > NANSWERS) {
D 7
		sprintf(abuf, "answer %d", rp->answer);
E 7
I 7
		(void)sprintf(abuf, "answer %d", rp->answer);
E 7
		ap = abuf;
	} else
		ap = answers[rp->answer];
	syslog(LOG_DEBUG, "%s: %s: %s, id %d", cp, tp, ap, ntohl(rp->id_num));
E 5
E 3
E 2
}
E 1

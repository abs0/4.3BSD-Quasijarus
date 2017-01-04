h61123
s 00010/00005/00073
d D 7.4 88/06/27 18:59:25 bostic 19 18
c install approved copyright notice
e
s 00008/00002/00070
d D 7.3 87/12/30 11:57:20 bostic 18 17
c add Berkeley header
e
s 00001/00001/00071
d D 7.2 86/10/28 22:22:05 karels 17 16
c correct initialization of netmatch
e
s 00001/00001/00071
d D 7.1 86/06/04 23:38:26 mckusick 16 15
c 4.3BSD release version
e
s 00013/00002/00059
d D 6.8 86/05/29 18:27:55 karels 15 14
c zap those null function pointers
e
s 00002/00009/00059
d D 6.7 86/03/30 21:40:46 karels 14 13
c expunge PUP; fill in AFNULL entries up to AF_MAX again
e
s 00001/00001/00067
d D 6.6 85/12/19 16:12:42 karels 13 12
c rm bbnnet; rm PUP
e
s 00001/00001/00067
d D 6.5 85/09/16 21:13:19 karels 12 11
c INET || BBNNET
e
s 00007/00001/00061
d D 6.4 85/06/08 12:25:29 mckusick 11 10
c Add copyright
e
s 00009/00001/00053
d D 6.3 85/04/27 12:03:33 sklower 10 9
c add entries for NS protocol routines
e
s 00006/00006/00048
d D 6.2 84/08/28 17:13:09 bloom 9 8
c Change include paths.  No more ../h.
e
s 00000/00000/00054
d D 6.1 83/07/29 07:08:29 sam 8 7
c 4.2 distribution
e
s 00004/00001/00050
d D 4.7 82/10/17 22:16:15 root 7 6
c lint
e
s 00015/00045/00036
d D 4.6 82/06/13 22:59:38 sam 6 5
c add class a/b/c net #'s and purge logical host kludge code
e
s 00018/00017/00063
d D 4.5 82/06/06 20:23:17 sam 5 4
c insure hash values are non-negative
e
s 00001/00001/00079
d D 4.4 82/05/04 20:26:29 sam 4 3
c bounds check on afswitch array
e
s 00019/00027/00061
d D 4.3 82/03/30 11:31:05 sam 3 2
c with routing, but not forwarding
e
s 00009/00007/00079
d D 4.2 82/03/28 14:20:39 sam 2 1
c convert interfaces to sockaddr's and add hooks for routing
e
s 00086/00000/00000
d D 4.1 82/03/27 22:57:35 sam 1 0
c date and time created 82/03/27 22:57:35 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 15
 * Copyright (c) 1980 Regents of the University of California.
E 15
I 15
D 16
 * Copyright (c) 1983 Regents of the University of California.
E 16
I 16
 * Copyright (c) 1983, 1986 Regents of the University of California.
E 16
E 15
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 18
 *
 *	%W% (Berkeley) %G%
 */
E 11

D 9
#include "../h/param.h"
#include "../h/mbuf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
D 6
#include "../net/in.h"
#include "../net/in_systm.h"
#include "../net/pup.h"
E 6
#include "../net/af.h"
E 9
I 9
#include "param.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "af.h"
E 9

/*
 * Address family support routines
 */
int	null_hash(), null_netmatch();
I 5
#define	AFNULL \
	{ null_hash,	null_netmatch }
E 5
D 2
int	inet_hash(), inet_netmatch()(;
E 2
I 2
D 6
int	inet_hash(), inet_netmatch();
E 6
I 6

D 12
#ifdef INET
E 12
I 12
D 13
#if defined(INET) || defined(BBNNET)
E 13
I 13
#ifdef INET
E 13
E 12
extern int inet_hash(), inet_netmatch();
E 6
I 5
#define	AFINET \
	{ inet_hash,	inet_netmatch }
E 5
E 2
D 6
int	pup_hash(), pup_netmatch();
E 6
I 6
#else
#define	AFINET	AFNULL
#endif

I 10
#ifdef NS
extern int ns_hash(), ns_netmatch();
#define	AFNS \
	{ ns_hash,	ns_netmatch }
#else
#define	AFNS	AFNULL
#endif

E 10
D 14
#ifdef PUP
extern int pup_hash(), pup_netmatch();
E 6
I 5
#define	AFPUP \
	{ pup_hash,	pup_netmatch }
I 6
#else
#define	AFPUP	AFNULL
#endif
E 6
E 5

E 14
D 4
struct afswitch afswitch[] = {
E 4
I 4
struct afswitch afswitch[AF_MAX] = {
E 4
D 5
	{ null_hash,	null_netmatch },	/* AF_UNSPEC */
	{ null_hash,	null_netmatch },	/* AF_UNIX */
	{ inet_hash,	inet_netmatch },	/* AF_INET */
	{ inet_hash,	inet_netmatch },	/* AF_IMPLINK */
	{ pup_hash,	pup_netmatch },		/* AF_PUP */
	{ null_hash,	null_netmatch },	/* AF_CHAOS */
	{ null_hash,	null_netmatch },	/* AF_OISCP */
	{ null_hash,	null_netmatch },	/* AF_NBS */
	{ null_hash,	null_netmatch },	/* AF_ECMA */
	{ null_hash,	null_netmatch },	/* AF_DATAKIT */
	{ null_hash,	null_netmatch },	/* AF_CCITT */
E 5
I 5
D 6
	AFNULL,	AFNULL,	AFINET,	AFINET,	AFPUP,	AFNULL,	AFNULL,	AFNULL,	AFNULL,
	AFNULL, AFNULL
E 6
I 6
D 14
	AFNULL,	AFNULL,	AFINET,	AFINET,	AFPUP,
E 14
I 14
	AFNULL,	AFNULL,	AFINET,	AFINET,	AFNULL,
E 14
D 7
	AFNULL,	AFNULL,	AFNULL,	AFNULL, AFNULL,
E 7
I 7
D 10
	AFNULL,	AFNULL,	AFNULL,	AFNULL,	AFNULL,
E 10
I 10
	AFNULL,	AFNS,	AFNULL,	AFNULL,	AFNULL,
I 14
	AFNULL, AFNULL, AFNULL, AFNULL, AFNULL,
E 14
E 10
E 7
D 15
	AFNULL
E 15
I 15
	AFNULL, AFNULL,					/* through 16 */
E 15
E 6
E 5
};
I 15

null_init()
{
	register struct afswitch *af;

	for (af = afswitch; af < &afswitch[AF_MAX]; af++)
		if (af->af_hash == (int (*)())NULL) {
			af->af_hash = null_hash;
D 17
			af->af_hash = null_hash;
E 17
I 17
			af->af_netmatch = null_netmatch;
E 17
		}
}
E 15

I 7
/*ARGSUSED*/
E 7
D 3
inet_hash(addr, hp)
	struct sockaddr *addr;
E 3
I 3
D 6
inet_hash(sin, hp)
	register struct sockaddr_in *sin;
E 3
	struct afhash *hp;
{
D 3
	register struct sockaddr_in *sin = (struct sockaddr_in *)addr;
E 3
D 5

E 5
I 5
COUNT(INET_HASH);
E 5
D 3
	hp->afh_nethash = hp->afh_netkey = sin->sin_addr.s_net;
	hp->afh_netkey <<= AFSHIFT;
	hp->afh_hostkey = ntohl(sin->sin_addr.s_addr) & AFMASK;
	/* make imp prominent */
	hp->afh_hosthash = ntohs((u_short)hp->afh_hostkey);
E 3
I 3
	hp->afh_nethash = sin->sin_addr.s_net;
	hp->afh_hosthash = ntohl(sin->sin_addr.s_addr);
I 5
	if (hp->afh_hosthash < 0)
		hp->afh_hosthash = -hp->afh_hosthash;
E 5
E 3
}

D 3
inet_netmatch(a1, a2)
	struct sockaddr *a1, *a2;
E 3
I 3
inet_netmatch(sin1, sin2)
	struct sockaddr_in *sin1, *sin2;
E 3
{
D 2
	return ((struct sockaddr_in *a1)->sin_addr.s_net ==
		(struct sockaddr_in *a2)->sin_addr.s_net);
E 2
I 2
D 3
	return (((struct sockaddr_in *)a1)->sin_addr.s_net ==
		((struct sockaddr_in *)a2)->sin_addr.s_net);
E 3
I 3
D 5

E 5
I 5
COUNT(INET_NETMATCH);
E 5
	return (sin1->sin_addr.s_net == sin2->sin_addr.s_net);
E 3
E 2
}

D 3
pup_hash(addr, hp)
	struct sockaddr *addr;
E 3
I 3
pup_hash(spup, hp)
	struct sockaddr_pup *spup;
E 3
	struct afhash *hp;
{
D 3
	register struct sockaddr_pup *spup = (struct sockaddr_pup *)addr;
E 3
D 5

E 5
I 5
COUNT(PUP_HASH);
E 5
D 3
	hp->afh_nethash = hp->afh_netkey = spup->spup_addr.pp_net;
	hp->afh_netkey <<= AFSHIFT;
D 2
	hp->afh_hostash = hp->afh_hostkey = spup->spup_addr.pp_host;
E 2
I 2
	hp->afh_hosthash = hp->afh_hostkey = spup->spup_addr.pp_host;
E 3
I 3
	hp->afh_nethash = spup->spup_addr.pp_net;
	hp->afh_hosthash = spup->spup_addr.pp_host;
I 5
	if (hp->afh_hosthash < 0)
		hp->afh_hosthash = -hp->afh_hosthash;
E 5
E 3
E 2
}

D 3
pup_netmatch(a1, a2)
	struct sockaddr *a1, *a2;
E 3
I 3
pup_netmatch(spup1, spup2)
	struct sockaddr_pup *spup1, *spup2;
E 3
{
D 2
	return ((struct sockaddr_pup *)a1->spup_addr.pp_net ==
		(struct sockaddr_pup *)a2->spup_addr.pp_net);
E 2
I 2
D 3
	return (((struct sockaddr_pup *)a1)->spup_addr.pp_net ==
		((struct sockaddr_pup *)a2)->spup_addr.pp_net);
E 3
I 3
D 5

E 5
I 5
COUNT(PUP_NETMATCH);
E 5
	return (spup1->spup_addr.pp_net == spup2->spup_addr.pp_net);
E 3
E 2
}

E 6
null_hash(addr, hp)
	struct sockaddr *addr;
	struct afhash *hp;
{
I 7

E 7
D 2
	hp->afh_net = hp->afh_host = addr->sa_family;
E 2
I 2
D 3
	hp->afh_netkey = hp->afh_hostkey = addr->sa_family;
E 3
I 3
D 5

E 5
I 5
D 6
COUNT(NULL_HASH);
E 6
E 5
E 3
	hp->afh_nethash = hp->afh_hosthash = 0;
D 3
	hp->afh_netkey <<= AFSHIFT;
E 3
E 2
}

I 3
/*ARGSUSED*/
E 3
null_netmatch(a1, a2)
	struct sockaddr *a1, *a2;
{
I 7

E 7
D 3
#ifdef lint
	a1->sa_family = a2->sa_family;
#endif
E 3
I 3
D 5

E 5
I 5
D 6
COUNT(NULL_NETMATCH);
E 6
E 5
E 3
	return (0);
}
E 1

h20871
s 00070/00009/00516
d D 4.24 02/07/22 21:12:59 msokolov 27 26
c add support for some PPP controls
e
s 00003/00000/00522
d D 4.23 02/07/12 19:57:07 msokolov 26 25
c support IFF_NOFCS flag
e
s 00019/00001/00503
d D 4.22 02/07/08 00:15:33 msokolov 25 24
c add support for displaying and changing the MTU
e
s 00015/00004/00489
d D 4.21 88/07/01 08:36:50 bostic 24 23
c written by Sam Leffler; add Berkeley specific copyright
e
s 00001/00001/00492
d D 4.20 87/04/06 11:34:30 bostic 23 22
c fprintf format/argument mismatch
e
s 00001/00001/00492
d D 4.19 87/03/29 16:14:37 mckusick 22 21
c fix errorneous error message from ifconfig (tef@cgl.ucsf.edu (Tom Ferrin))
e
s 00032/00024/00461
d D 4.18 86/05/22 16:07:01 karels 21 20
c cleanup status for uninitialized interfaces
e
s 00009/00010/00476
d D 4.17 86/04/12 22:04:15 karels 20 19
c logic error; zero netmask when setting new addr
e
s 00001/00001/00485
d D 4.16 86/02/27 00:40:05 karels 19 16
c off by one
e
s 00011/00005/00481
d R 4.16 86/02/26 17:10:05 karels 18 16
c kernel now wants dstaddr set after local addr
e
s 00009/00003/00483
d R 4.16 86/02/26 16:14:22 karels 17 16
c kernel now wants dstaddr set after local addr
e
s 00035/00019/00451
d D 4.15 86/02/16 21:08:45 karels 16 15
c add if metric, rm local, separate af-dependent and -independent
e
s 00015/00054/00455
d D 4.14 86/02/07 10:25:08 sklower 15 14
c a.) list other end of pt to pt xns interfaces. 
c b.) use standard routines to print and convert xns addresses. (from libc)
e
s 00004/00004/00505
d D 4.13 85/08/10 14:11:52 sklower 14 12
c Fix two bugs: 1.) wrong sizeof for name 2.) if ns not configured 
c Don't barf when asked to report status.
e
s 00001/00002/00507
d R 4.13 85/07/13 12:05:52 sklower 13 12
c fix bug introduced last rev that limited if names to 4 chars.
e
s 00208/00041/00301
d D 4.12 85/06/06 11:00:12 sklower 12 11
c Include Maryland XNS changes
e
s 00111/00026/00231
d D 4.11 85/06/03 09:32:53 karels 11 10
c netmask stuff
e
s 00002/00000/00255
d D 4.10 84/10/17 13:00:46 tef 10 9
c must save and restore flags when dest addr is set.
e
s 00024/00002/00231
d D 4.9 84/09/26 09:35:42 tef 9 8
c allow dest addr to be set on point-to-point interfaces; 
c report dest addr during status printout
e
s 00001/00001/00232
d D 4.8 84/08/02 00:30:38 lepreau 8 7
c missing arg to an fprintf
e
s 00020/00019/00213
d D 4.7 84/04/10 21:46:16 karels 7 6
c add `local' option; set address last always
e
s 00010/00000/00222
d D 4.6 83/11/07 14:01:54 karels 6 5
c need to reread flags after setting address (interface may add new flags)
e
s 00006/00005/00216
d D 4.5 83/11/02 09:51:21 karels 5 4
c correct sense of arp; report state of arp; handle multiple flags
c (from Tom Lyons)
e
s 00002/00000/00219
d D 4.4 83/10/23 23:51:02 leres 4 3
c Add support for changing the IFF_DEBUG bit
e
s 00005/00000/00214
d D 4.3 83/09/16 18:39:22 sam 3 2
c show stanford how to add swabip crap
e
s 00003/00003/00211
d D 4.2 83/08/28 02:01:35 sam 2 1
c oops
e
s 00214/00000/00000
d D 4.1 83/08/28 00:37:35 sam 1 0
c date and time created 83/08/28 00:37:35 by sam
e
u
U
t
T
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
D 24
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 24
I 24
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 24
 */

E 11
I 1
#ifndef lint
I 11
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 24
#endif not lint
E 24
I 24
#endif /* not lint */
E 24

#ifndef lint
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif
E 11
I 11
D 24
#endif not lint
E 24
I 24
#endif /* not lint */
E 24
E 11

I 11
D 14

E 14
E 11
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

D 12
#include <netinet/in.h>
E 12
#include <net/if.h>
I 27
#include <net/if_pppvar.h>
E 27
I 12
#include <netinet/in.h>
E 12

I 12
#define	NSIP
#include <netns/ns.h>
#include <netns/ns_if.h>

E 12
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <netdb.h>

I 12
extern int errno;
E 12
struct	ifreq ifr;
struct	sockaddr_in sin = { AF_INET };
I 11
struct	sockaddr_in broadaddr;
struct	sockaddr_in netmask = { AF_INET };
I 12
struct	sockaddr_in ipdst = { AF_INET };
E 12
E 11
char	name[30];
I 11
int	flags;
I 25
int	mtu;
E 25
I 16
int	metric;
E 16
E 11
D 7
int	flags;
E 7
I 7
int	setaddr;
I 11
int	setmask;
int	setbroadaddr;
I 12
int	setipdst;
E 12
E 11
E 7
int	s;
I 11
extern	int errno;
E 11

D 9
int	setifflags(), setifaddr();
E 9
I 9
D 11
int	setifflags(), setifaddr(), setifdstaddr();
E 11
I 11
int	setifflags(), setifaddr(), setifdstaddr(), setifnetmask();
D 12
int	setifbroadaddr();
E 12
I 12
D 16
int	setifbroadaddr(), setifipdst();
E 16
I 16
D 25
int	setifmetric(), setifbroadaddr(), setifipdst();
E 25
I 25
int	setifmtu(), setifmetric(), setifbroadaddr(), setifipdst();
I 27
int	pppreset(), pppsetrecov();
E 27
E 25
E 16
E 12
E 11
E 9

I 11
#define	NEXTARG		0xffffff

E 11
struct	cmd {
	char	*c_name;
D 11
	int	c_parameter;
E 11
I 11
	int	c_parameter;		/* NEXTARG means next argv */
E 11
	int	(*c_func)();
} cmds[] = {
	{ "up",		IFF_UP,		setifflags } ,
	{ "down",	-IFF_UP,	setifflags },
	{ "trailers",	-IFF_NOTRAILERS,setifflags },
	{ "-trailers",	IFF_NOTRAILERS,	setifflags },
D 5
	{ "arp",	IFF_NOARP,	setifflags },
	{ "-arp",	-IFF_NOARP,	setifflags },
E 5
I 5
	{ "arp",	-IFF_NOARP,	setifflags },
	{ "-arp",	IFF_NOARP,	setifflags },
I 26
	{ "fcs",	-IFF_NOFCS,	setifflags },
	{ "-fcs",	IFF_NOFCS,	setifflags },
E 26
I 11
D 16
#ifdef IFF_LOCAL
E 11
I 7
	{ "local",	IFF_LOCAL,	setifflags },
	{ "-local",	-IFF_LOCAL,	setifflags },
I 11
#endif
E 16
E 11
E 7
E 5
I 4
	{ "debug",	IFF_DEBUG,	setifflags },
	{ "-debug",	-IFF_DEBUG,	setifflags },
E 4
I 3
#ifdef notdef
D 11
#define	EN_SWABIPS	0x100
E 11
I 11
#define	EN_SWABIPS	0x1000
E 11
	{ "swabips",	EN_SWABIPS,	setifflags },
	{ "-swabips",	-EN_SWABIPS,	setifflags },
#endif
I 11
	{ "netmask",	NEXTARG,	setifnetmask },
I 25
	{ "mtu",	NEXTARG,	setifmtu },
E 25
I 16
	{ "metric",	NEXTARG,	setifmetric },
E 16
	{ "broadcast",	NEXTARG,	setifbroadaddr },
I 12
	{ "ipdst",	NEXTARG,	setifipdst },
I 27
	{ "pppreset",	0,		pppreset },
	{ "ppprecov",	NEXTARG,	pppsetrecov },
E 27
E 12
E 11
E 3
	{ 0,		0,		setifaddr },
I 9
	{ 0,		0,		setifdstaddr },
E 9
};

I 12
/*
 * XNS support liberally adapted from
 * code written at the University of Maryland
 * principally by James O'Toole and Chris Torek.
 */

int	in_status(), in_getaddr();
int	xns_status(), xns_getaddr();

/* Known address families */
struct afswtch {
	char *af_name;
	short af_af;
	int (*af_status)();
	int (*af_getaddr)();
} afs[] = {
	{ "inet",	AF_INET,	in_status,	in_getaddr },
	{ "ns",		AF_NS,		xns_status,	xns_getaddr },
	{ 0,		0,		0,		0 }
};

struct afswtch *afp;	/*the address family being set or asked about*/

E 12
main(argc, argv)
	int argc;
	char *argv[];
{
D 12

E 12
I 12
	int af = AF_INET;
I 20

E 20
E 12
	if (argc < 2) {
D 12
		fprintf(stderr, "usage: ifconfig interface %s %s %s\n",
E 12
I 12
D 16
		fprintf(stderr, "usage: ifconfig interface [ af %s %s %s %s\n",
E 12
D 9
		    "[ address ] [ up ] [ down ]",
E 9
I 9
		    "[ address [ dest_addr ] ] [ up ] [ down ]",
I 11
D 12
		    "[ netmask mask ]",
E 12
I 12
		    "[ netmask mask ] ]",
E 12
E 11
E 9
		    "[ trailers | -trailers ]",
D 12
		    "[ arp | -arp ]");
E 12
I 12
		    "[ arp | -arp ] ]");
E 16
I 16
D 23
		fprintf(stderr, "usage: ifconfig interface\n%s%s%s%s",
E 23
I 23
		fprintf(stderr, "usage: ifconfig interface\n%s%s%s%s%s",
E 23
		    "\t[ af [ address [ dest_addr ] ] [ up ] [ down ]",
			    "[ netmask mask ] ]\n",
I 25
		    "\t[ mtu n ]\n",
E 25
		    "\t[ metric n ]\n",
		    "\t[ trailers | -trailers ]\n",
		    "\t[ arp | -arp ]\n");
E 16
E 12
		exit(1);
	}
D 12
	s = socket(AF_INET, SOCK_DGRAM, 0);
E 12
I 12
	argc--, argv++;
D 14
	strncpy(name, *argv, sizeof(name - 1));
	name[sizeof name - 1] = 0;
E 14
I 14
	strncpy(name, *argv, sizeof(name));
E 14
	strncpy(ifr.ifr_name, name, sizeof(ifr.ifr_name));
	argc--, argv++;
	if (argc > 0) {
		struct afswtch *myafp;
		
		for (myafp = afp = afs; myafp->af_name; myafp++)
			if (strcmp(myafp->af_name, *argv) == 0) {
				afp = myafp; argc--; argv++;
				break;
			}
		af = ifr.ifr_addr.sa_family = afp->af_af;
	}
	s = socket(af, SOCK_DGRAM, 0);
E 12
	if (s < 0) {
		perror("ifconfig: socket");
		exit(1);
	}
D 12
	argc--, argv++;
	strcpy(name, *argv);
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
	if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr) < 0) {
		Perror("ioctl (SIOCGIFFLAGS)");
		exit(1);
	}
I 12
	strncpy(ifr.ifr_name, name, sizeof ifr.ifr_name);
E 12
I 11
	flags = ifr.ifr_flags;
I 25
	if (ioctl(s, SIOCGIFMTU, (caddr_t)&ifr) < 0)
D 27
		perror("ioctl (SIOCGIFMTU)");
E 27
I 27
		Perror("ioctl (SIOCGIFMTU)");
E 27
	else
		mtu = ifr.ifr_mtu;
E 25
I 16
	if (ioctl(s, SIOCGIFMETRIC, (caddr_t)&ifr) < 0)
D 27
		perror("ioctl (SIOCGIFMETRIC)");
E 27
I 27
		Perror("ioctl (SIOCGIFMETRIC)");
E 27
	else
		metric = ifr.ifr_metric;
E 16
D 12
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
	if (ioctl(s, SIOCGIFNETMASK, (caddr_t)&ifr) < 0) {
		if (errno != EADDRNOTAVAIL)
			Perror("ioctl (SIOCGIFNETMASK)");
	} else
		netmask.sin_addr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
E 11
D 7
	flags = ifr.ifr_flags;
E 7
	argc--, argv++;
E 12
I 12
D 20
	if (af == AF_INET) {
		if (ioctl(s, SIOCGIFNETMASK, (caddr_t)&ifr) < 0) {
			if (errno != EADDRNOTAVAIL)
				Perror("ioctl (SIOCGIFNETMASK)");
		} else
			netmask.sin_addr =
			      ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
		strncpy(ifr.ifr_name, name, sizeof ifr.ifr_name);
	}
E 20
E 12
	if (argc == 0) {
		status();
		exit(0);
	}
	while (argc > 0) {
		register struct cmd *p;

		for (p = cmds; p->c_name; p++)
			if (strcmp(*argv, p->c_name) == 0)
				break;
I 9
		if (p->c_name == 0 && setaddr)
			p++;	/* got src, do dst */
E 9
D 11
		if (p->c_func)
			(*p->c_func)(*argv, p->c_parameter);
E 11
I 11
		if (p->c_func) {
			if (p->c_parameter == NEXTARG) {
				(*p->c_func)(argv[1]);
				argc--, argv++;
			} else
				(*p->c_func)(*argv, p->c_parameter);
		}
E 11
		argc--, argv++;
	}
I 11
D 12
	if (setmask || setaddr) {
E 12
I 12
D 20
	if ((setmask || setaddr) && (af == AF_INET)){
E 20
I 20
	if ((setmask || setaddr) && (af == AF_INET)) {
E 20
E 12
		/*
		 * If setting the address and not the mask,
		 * clear any existing mask and the kernel will then
		 * assign the default.  If setting both,
		 * set the mask first, so the address will be
		 * interpreted correctly.
		 */
D 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
		ifr.ifr_addr = *(struct sockaddr *)&netmask;
		if (ioctl(s, SIOCSIFNETMASK, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCSIFNETMASK)");
	}
I 12
	if (setipdst && af==AF_NS) {
		struct nsip_req rq;
		int size = sizeof(rq);

		rq.rq_ns = *(struct sockaddr *) &sin;
		rq.rq_ip = *(struct sockaddr *) &ipdst;

		if (setsockopt(s, 0, SO_NSIP_ROUTE, &rq, size) < 0)
			Perror("Encapsulation Routing");
		setaddr = 0;
	}
E 12
E 11
I 7
	if (setaddr) {
D 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
		ifr.ifr_addr = *(struct sockaddr *) &sin;
		if (ioctl(s, SIOCSIFADDR, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCSIFADDR)");
	}
I 11
	if (setbroadaddr) {
D 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
		ifr.ifr_addr = *(struct sockaddr *)&broadaddr;
		if (ioctl(s, SIOCSIFBRDADDR, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCSIFBRDADDR)");
	}
E 11
E 7
	exit(0);
}

/*ARGSUSED*/
setifaddr(addr, param)
	char *addr;
D 12
	int param;
E 12
I 12
	short param;
E 12
{
D 12

D 7
	getaddr(addr, (struct sockaddr_in *)&ifr.ifr_addr);
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
	if (ioctl(s, SIOCSIFADDR, (caddr_t)&ifr) < 0)
		Perror("ioctl (SIOCSIFADDR)");
I 6
	/* 
	 * SIFADDR ioctl above can change the flags value if it is
	 * the first time the address has been set.  Must get the
	 * new flags so that we don't store outdated ones later on.
E 7
I 7
	getaddr(addr, &sin);
E 12
	/*
	 * Delay the ioctl to set the interface addr until flags are all set.
	 * The address interpretation may depend on the flags,
	 * and the flags may change when the address is set.
E 7
	 */
D 7
	if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr) < 0) {
		Perror("ioctl (SIOCGIFFLAGS) 2");
		exit(1);
	}
	flags = ifr.ifr_flags;
E 7
I 7
	setaddr++;
I 12
	(*afp->af_getaddr)(addr, &sin);
E 12
E 7
E 6
}

I 11
setifnetmask(addr)
	char *addr;
{
D 12

	getaddr(addr, &netmask);
E 12
I 12
	in_getaddr(addr, &netmask);
E 12
	setmask++;
}

setifbroadaddr(addr)
	char *addr;
{
D 12
	getaddr(addr, &broadaddr);
E 12
I 12
	(*afp->af_getaddr)(addr, &broadaddr);
E 12
	setbroadaddr++;
}

I 12
setifipdst(addr)
	char *addr;
{
	in_getaddr(addr, &ipdst);
	setipdst++;
}

E 12
E 11
I 9
/*ARGSUSED*/
setifdstaddr(addr, param)
	char *addr;
	int param;
{
I 10
D 11
	int flags = ifr.ifr_flags;
E 11
E 10

D 12
	getaddr(addr, (struct sockaddr_in *)&ifr.ifr_dstaddr);
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
I 12
	(*afp->af_getaddr)(addr, &ifr.ifr_addr);
E 12
	if (ioctl(s, SIOCSIFDSTADDR, (caddr_t)&ifr) < 0)
		Perror("ioctl (SIOCSIFDSTADDR)");
I 10
D 11
	ifr.ifr_flags = flags;
E 11
E 10
}

E 9
D 2
setifflags(name, value)
	char *name;
E 2
I 2
setifflags(vname, value)
	char *vname;
E 2
D 12
	int value;
E 12
I 12
	short value;
E 12
{
I 12
 	if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr) < 0) {
 		Perror("ioctl (SIOCGIFFLAGS)");
 		exit(1);
 	}
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
 	flags = ifr.ifr_flags;
E 12

	if (value < 0) {
		value = -value;
D 5
		ifr.ifr_flags = (flags &~ value);
E 5
I 5
D 7
		flags &= ~value;
E 7
I 7
D 11
		ifr.ifr_flags &= ~value;
E 11
I 11
		flags &= ~value;
E 11
E 7
E 5
	} else
D 5
		ifr.ifr_flags |= value;
E 5
I 5
D 7
		flags |= value;
	ifr.ifr_flags = flags;
E 7
I 7
D 11
		ifr.ifr_flags |= value;
E 11
I 11
		flags |= value;
E 11
E 7
E 5
D 12
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
I 11
	ifr.ifr_flags = flags;
E 11
	if (ioctl(s, SIOCSIFFLAGS, (caddr_t)&ifr) < 0)
D 2
		Perror(name);
E 2
I 2
		Perror(vname);
E 2
}

I 25
setifmtu(val)
	char *val;
{
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
	ifr.ifr_mtu = atoi(val);
	if (ioctl(s, SIOCSIFMTU, (caddr_t)&ifr) < 0)
D 27
		perror("ioctl (set MTU)");
E 27
I 27
		Perror("ioctl (set MTU)");
E 27
}

E 25
I 16
setifmetric(val)
	char *val;
{
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
	ifr.ifr_metric = atoi(val);
	if (ioctl(s, SIOCSIFMETRIC, (caddr_t)&ifr) < 0)
D 27
		perror("ioctl (set metric)");
E 27
I 27
		Perror("ioctl (set metric)");
E 27
}

I 27
pppreset()
{
	ifr.ifr_data = (caddr_t) PPPACT_RESET;
	if (ioctl(s, SIOCPPPSPECACT, (caddr_t)&ifr) < 0)
		Perror("ioctl (SIOCPPPSPECACT PPPACT_RESET)");
}

pppsetrecov(val)
	char *val;
{
	if (val && !strcmp(val, "persist")) {
		ifr.ifr_data = (caddr_t) PPPACT_RECOVPERSIST;
		if (ioctl(s, SIOCPPPSPECACT, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCPPPSPECACT PPPACT_RECOVPERSIST)");
	} else if (val && !strcmp(val, "passive")) {
		ifr.ifr_data = (caddr_t) PPPACT_RECOVPASSIVE;
		if (ioctl(s, SIOCPPPSPECACT, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCPPPSPECACT PPPACT_RECOVPASSIVE)");
	} else {
		ifr.ifr_data = (caddr_t) PPPACT_RECOVDEFAULT;
		if (ioctl(s, SIOCPPPSPECACT, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCPPPSPECACT PPPACT_RECOVDEFAULT)");
	}
}

E 27
#define	IFFBITS \
"\020\1UP\2BROADCAST\3DEBUG\4LOOPBACK\5POINTOPOINT\6NOTRAILERS\7RUNNING\10NOARP\
I 26
\13NOFCS\
E 26
"

I 27
char *ppp_states[] = {
	"INITIAL",
	"STARTING",
	"CLOSED",
	"STOPPED",
	"CLOSING",
	"STOPPING",
	"REQSENT",
	"ACKRCVD",
	"ACKSENT",
	"OPENED"
};

E 27
E 16
I 12
/*
 * Print the status of the interface.  If an address family was
 * specified, show it and it only; otherwise, show them all.
 */
E 12
status()
{
I 12
	register struct afswtch *p = afp;
	short af = ifr.ifr_addr.sa_family;
I 27
	int i;
E 27

I 16
	printf("%s: ", name);
	printb("flags", flags, IFFBITS);
I 25
	if (mtu)
		printf(" MTU %d", mtu);
E 25
	if (metric)
		printf(" metric %d", metric);
I 27
	if (!strncmp(name, "ppp", 3)) {
		if (ioctl(s, SIOCPPPGETSTATE, (caddr_t)&ifr) >= 0)
			i = (int) ifr.ifr_data;
		else
			i = -1;
		if (i >= 0 && i < sizeof(ppp_states)/sizeof(char *))
			printf(" %s", ppp_states[i]);
		else
			printf(" (unknown state)");
		if (ioctl(s, SIOCPPPGETFLAGS, (caddr_t)&ifr) >= 0)
			i = (int) ifr.ifr_data;
		else
			i = 0;
		if (i & PPP_FLAGS_PERSIST)
			printf(",PERSIST");
		if (i & PPP_FLAGS_PASSIVE)
			printf(",PASSIVE");
	}
E 27
	putchar('\n');
E 16
	if ((p = afp) != NULL) {
D 21
		(*p->af_status)();
		return;
	}
	for (p = afs; p->af_name; p++) {
E 21
I 21
		(*p->af_status)(1);
	} else for (p = afs; p->af_name; p++) {
E 21
		ifr.ifr_addr.sa_family = p->af_af;
D 21
		(*p->af_status)();
E 21
I 21
		(*p->af_status)(0);
E 21
	}
}

D 16
#define	IFFBITS \
"\020\1UP\2BROADCAST\3DEBUG\4ROUTE\5POINTOPOINT\6NOTRAILERS\7RUNNING\10NOARP\
\11LOCAL"

E 16
D 21
in_status()
E 21
I 21
in_status(force)
	int force;
E 21
{
E 12
	struct sockaddr_in *sin;
I 12
	char *inet_ntoa();
E 12
I 7
D 11
	int flags = ifr.ifr_flags;
E 11
E 7

I 20
D 21
	if (ioctl(s, SIOCGIFNETMASK, (caddr_t)&ifr) < 0) {
		if (errno != EADDRNOTAVAIL)
			Perror("ioctl (SIOCGIFNETMASK)");
	} else
		netmask.sin_addr =
		    ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
E 21
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 20
D 12
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
D 11
	if (ioctl(s, SIOCGIFADDR, (caddr_t)&ifr) < 0)
		Perror("ioctl (SIOCGIFADDR)");
E 11
I 11
	if (ioctl(s, SIOCGIFADDR, (caddr_t)&ifr) < 0) {
D 21
		if (errno == EADDRNOTAVAIL)
E 21
I 21
		if (errno == EADDRNOTAVAIL || errno == EAFNOSUPPORT) {
			if (!force)
				return;
E 21
			bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
D 21
		else
			Perror("ioctl (SIOCGIFADDR)");
E 21
I 21
		} else
D 27
			perror("ioctl (SIOCGIFADDR)");
E 27
I 27
			Perror("ioctl (SIOCGIFADDR)");
E 27
E 21
	}
I 12
D 21
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 21
E 12
E 11
	sin = (struct sockaddr_in *)&ifr.ifr_addr;
D 16
	printf("%s: %s ", name, inet_ntoa(sin->sin_addr));
E 16
I 16
D 19
	printf("\tinet %s ", name, inet_ntoa(sin->sin_addr));
E 19
I 19
	printf("\tinet %s ", inet_ntoa(sin->sin_addr));
I 21
	strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
	if (ioctl(s, SIOCGIFNETMASK, (caddr_t)&ifr) < 0) {
		if (errno != EADDRNOTAVAIL)
D 27
			perror("ioctl (SIOCGIFNETMASK)");
E 27
I 27
			Perror("ioctl (SIOCGIFNETMASK)");
E 27
		bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
	} else
		netmask.sin_addr =
		    ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;
E 21
E 19
E 16
I 9
	if (flags & IFF_POINTOPOINT) {
D 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
D 11
		if (ioctl(s, SIOCGIFDSTADDR, (caddr_t)&ifr) < 0)
			Perror("ioctl (SIOCGIFDSTADDR)");
E 11
I 11
		if (ioctl(s, SIOCGIFDSTADDR, (caddr_t)&ifr) < 0) {
			if (errno == EADDRNOTAVAIL)
			    bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
			else
D 21
			    Perror("ioctl (SIOCGIFDSTADDR)");
E 21
I 21
D 27
			    perror("ioctl (SIOCGIFDSTADDR)");
E 27
I 27
			    Perror("ioctl (SIOCGIFDSTADDR)");
E 27
E 21
		}
I 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
E 11
		sin = (struct sockaddr_in *)&ifr.ifr_dstaddr;
		printf("--> %s ", inet_ntoa(sin->sin_addr));
	}
I 11
	printf("netmask %x ", ntohl(netmask.sin_addr.s_addr));
E 11
E 9
D 12
#define	IFFBITS \
D 5
"\020\1UP\2BROADCAST\3DEBUG\4ROUTE\5POINTOPOINT\6NOTRAILERS\7RUNNING"
E 5
I 5
D 7
"\020\1UP\2BROADCAST\3DEBUG\4ROUTE\5POINTOPOINT\6NOTRAILERS\7RUNNING\10NOARP"
E 7
I 7
"\020\1UP\2BROADCAST\3DEBUG\4ROUTE\5POINTOPOINT\6NOTRAILERS\7RUNNING\10NOARP\
\11LOCAL"
E 12
E 7
E 5
D 16
	printb("flags", flags, IFFBITS); putchar('\n');
E 16
I 11
	if (flags & IFF_BROADCAST) {
D 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
		if (ioctl(s, SIOCGIFBRDADDR, (caddr_t)&ifr) < 0) {
			if (errno == EADDRNOTAVAIL)
D 21
				return;
			Perror("ioctl (SIOCGIFADDR)");
E 21
I 21
			    bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
			else
D 27
			    perror("ioctl (SIOCGIFADDR)");
E 27
I 27
			    Perror("ioctl (SIOCGIFADDR)");
E 27
E 21
		}
I 12
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
E 12
		sin = (struct sockaddr_in *)&ifr.ifr_addr;
D 16
		printf("broadcast: %s\n", inet_ntoa(sin->sin_addr));
E 16
I 16
D 21
		printf("broadcast %s", inet_ntoa(sin->sin_addr));
E 21
I 21
		if (sin->sin_addr.s_addr != 0)
			printf("broadcast %s", inet_ntoa(sin->sin_addr));
E 21
E 16
	}
I 16
	putchar('\n');
E 16
E 11
}

I 12

D 21
xns_status()
E 21
I 21
xns_status(force)
	int force;
E 21
{
	struct sockaddr_ns *sns;
D 15
	char *xns_ntoa();
E 15

	close(s);
	s = socket(AF_NS, SOCK_DGRAM, 0);
	if (s < 0) {
I 14
D 22
		if (errno == EAFNOSUPPORT)
E 22
I 22
		if (errno == EPROTONOSUPPORT)
E 22
			return;
E 14
		perror("ifconfig: socket");
		exit(1);
	}
	if (ioctl(s, SIOCGIFADDR, (caddr_t)&ifr) < 0) {
D 14
		if (errno == EAFNOSUPPORT)
E 14
I 14
D 21
		if (errno == EADDRNOTAVAIL || errno==EAFNOSUPPORT)
E 14
			return;
		Perror("ioctl (SIOCGIFADDR)");
E 21
I 21
		if (errno == EADDRNOTAVAIL || errno == EAFNOSUPPORT) {
			if (!force)
				return;
			bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
		} else
D 27
			perror("ioctl (SIOCGIFADDR)");
E 27
I 27
			Perror("ioctl (SIOCGIFADDR)");
E 27
E 21
	}
	strncpy(ifr.ifr_name, name, sizeof ifr.ifr_name);
	sns = (struct sockaddr_ns *)&ifr.ifr_addr;
D 15
	printf("%s: xns %s ", name, xns_ntoa(sns));
E 15
I 15
D 16
	printf("%s: ns:%s ", name, ns_ntoa(sns->sns_addr));
E 16
I 16
	printf("\tns %s ", ns_ntoa(sns->sns_addr));
E 16
	if (flags & IFF_POINTOPOINT) { /* by W. Nesheim@Cornell */
		if (ioctl(s, SIOCGIFDSTADDR, (caddr_t)&ifr) < 0) {
			if (errno == EADDRNOTAVAIL)
			    bzero((char *)&ifr.ifr_addr, sizeof(ifr.ifr_addr));
			else
			    Perror("ioctl (SIOCGIFDSTADDR)");
		}
		strncpy(ifr.ifr_name, name, sizeof (ifr.ifr_name));
		sns = (struct sockaddr_ns *)&ifr.ifr_dstaddr;
		printf("--> %s ", ns_ntoa(sns->sns_addr));
	}
E 15
D 16
	printb("flags", flags, IFFBITS);
E 16
	putchar('\n');
}

E 12
Perror(cmd)
	char *cmd;
{
	extern int errno;

	fprintf(stderr, "ifconfig: ");
	switch (errno) {

	case ENXIO:
D 12
		fprintf(stderr, "%s: ", cmd);
		fprintf(stderr, "no such interface\n");
E 12
I 12
		fprintf(stderr, "%s: no such interface\n", cmd);
E 12
		break;

	case EPERM:
D 8
		fprintf(stderr, "%s: permission denied\n");
E 8
I 8
		fprintf(stderr, "%s: permission denied\n", cmd);
E 8
		break;

	default:
		perror(cmd);
	}
	exit(1);
}

struct	in_addr inet_makeaddr();

D 12
getaddr(s, sin)
E 12
I 12
in_getaddr(s, saddr)
E 12
	char *s;
D 12
	struct sockaddr_in *sin;
E 12
I 12
	struct sockaddr *saddr;
E 12
{
I 12
	register struct sockaddr_in *sin = (struct sockaddr_in *)saddr;
E 12
	struct hostent *hp;
	struct netent *np;
	int val;

I 11
	sin->sin_family = AF_INET;
	val = inet_addr(s);
	if (val != -1) {
		sin->sin_addr.s_addr = val;
		return;
	}
E 11
	hp = gethostbyname(s);
	if (hp) {
		sin->sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, (char *)&sin->sin_addr, hp->h_length);
		return;
	}
	np = getnetbyname(s);
	if (np) {
		sin->sin_family = np->n_addrtype;
		sin->sin_addr = inet_makeaddr(np->n_net, INADDR_ANY);
D 11
		return;
	}
	sin->sin_family = AF_INET;
	val = inet_addr(s);
	if (val != -1) {
		sin->sin_addr.s_addr = val;
		return;
	}
	val = inet_network(s);
	if (val != -1) {
		sin->sin_addr = inet_makeaddr(val, INADDR_ANY);
E 11
		return;
	}
	fprintf(stderr, "%s: bad value\n", s);
	exit(1);
}

/*
 * Print a value a la the %b format of the kernel's printf
 */
printb(s, v, bits)
	char *s;
	register char *bits;
	register unsigned short v;
{
	register int i, any = 0;
	register char c;

	if (bits && *bits == 8)
		printf("%s=%o", s, v);
	else
		printf("%s=%x", s, v);
	bits++;
	if (bits) {
		putchar('<');
		while (i = *bits++) {
			if (v & (1 << (i-1))) {
				if (any)
					putchar(',');
				any = 1;
				for (; (c = *bits) > 32; bits++)
					putchar(c);
			} else
				for (; *bits > 32; bits++)
					;
		}
		putchar('>');
	}
I 12
}

D 15
#define setxnnet(a,b) {a = * (union ns_net *) &(b);}

E 15
xns_getaddr(addr, saddr)
char *addr;
struct sockaddr *saddr;
{
D 15
	register struct sockaddr_ns *sns = (struct sockaddr_ns *)saddr;
	u_long netnum;
	char *index();
	register char *s = index(addr, ':');
	register int i;

	if (s!=NULL) *s = 0;
	netnum = atoi(addr);
	netnum = htonl(netnum);
	setxnnet(sns->sns_addr.x_net, netnum);
E 15
I 15
	struct sockaddr_ns *sns = (struct sockaddr_ns *)saddr;
	struct ns_addr ns_addr();
E 15
	sns->sns_family = AF_NS;
D 15

	for (i = 0; i < 6; i++) {
		if (s == NULL || *++s == 0) 
			break;
		sns->sns_addr.x_host.c_host[i] = xtoi(s);
		s = index(s, '.');
	}

}

char *
xns_ntoa(sns)
register struct sockaddr_ns *sns;
{
	static char buf[30];

	sprintf (buf, "%d:%x.%x.%x.%x.%x.%x",
	    ntohl(ns_netof(sns->sns_addr)),
	    sns->sns_addr.x_host.c_host[0], sns->sns_addr.x_host.c_host[1],
	    sns->sns_addr.x_host.c_host[2], sns->sns_addr.x_host.c_host[3],
	    sns->sns_addr.x_host.c_host[4], sns->sns_addr.x_host.c_host[5]);
	return (buf);
}

int xtoi(s)
register char *s;
{
	register int res = 0, delta;
	register char *cp;
	static char base[] = "0123456789ABCDEFabcdef";

	for(; *s; s++) {
		cp = index(base, *s);	
		if (cp==NULL)
			break;
		if ((delta = cp - base) > 15)
			delta -= 6;
		res = (res << 4) + delta;
	}
	return(res);
E 15
I 15
	sns->sns_addr = ns_addr(addr);
E 15
E 12
}
E 1

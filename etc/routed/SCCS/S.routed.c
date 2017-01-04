h49702
s 00002/00002/00901
d D 4.25 82/10/08 13:52:31 sam 27 26
c extra word in /etc/gateways
e
s 00034/00077/00869
d D 4.24 82/10/07 19:30:08 sam 26 25
c convert to new data base format
e
s 00009/00004/00937
d D 4.23 82/10/06 14:34:07 sam 25 24
c convert to new library
e
s 00043/00002/00898
d D 4.22 82/08/19 14:10:36 sam 24 22
c class B & C net #'s weren't handled correctly
e
s 00044/00003/00897
d R 4.22 82/08/19 14:09:05 sam 23 22
c class B & C net #'s weren't handled correctly
e
s 00012/00005/00888
d D 4.21 82/08/18 12:30:13 sam 22 21
c allow symbolic names and x.y.z.q in address specifications
e
s 00006/00003/00887
d D 4.20 82/06/21 16:18:36 sam 21 20
c wasn't scanning for down interfaces properly
e
s 00000/00002/00890
d D 4.19 82/06/20 23:29:02 sam 20 19
c respond to requests even if not supplier
e
s 00084/00011/00808
d D 4.18 82/06/20 17:23:45 sam 19 18
c make notion of supplier valid; also don't time out route for 
c only interface on a machine; add comments in expectation of others reading code
e
s 00004/00004/00815
d D 4.17 82/06/17 10:58:34 sam 18 17
c add class b & c net #'s
e
s 00153/00159/00666
d D 4.16 82/06/10 20:13:25 sam 17 16
c keep separate interface list so we just delete routes when they expire
e
s 00143/00109/00682
d D 4.15 82/06/09 22:15:36 sam 16 15
c much too much to say here
e
s 00242/00446/00549
d D 4.14 82/06/09 00:45:06 wnj 15 14
c wnj changes
e
s 00115/00110/00880
d D 4.13 82/06/08 21:50:14 wnj 14 13
c changes per sam
e
s 00062/00009/00928
d D 4.12 82/06/05 16:53:40 sam 13 12
c add tracing and redo startup code to fork once
e
s 00042/00004/00895
d D 4.11 82/05/31 19:10:12 sam 12 11
c must match entries entirely on lookup
e
s 00006/00006/00893
d D 4.10 82/05/31 16:51:36 sam 11 10
c SILENT->HIDDEN (more mnemonic?)
e
s 00001/00001/00898
d D 4.9 82/05/27 15:37:21 sam 10 9
c install is default
e
s 00003/00002/00896
d D 4.8 82/05/27 15:31:49 sam 9 7
c never reseting lookforinterfaces
e
s 00003/00002/00896
d R 4.8 82/05/26 14:35:56 sam 8 7
c lookforinterfaces wasn't being reset
e
s 00049/00032/00849
d D 4.7 82/05/26 14:33:07 sam 7 6
c split state and flags; cleanup a bit more 
e
s 00057/00031/00824
d D 4.6 82/05/25 18:55:49 sam 6 5
c cleanup 
e
s 00002/00003/00853
d D 4.5 82/05/25 18:11:38 sam 5 4
c "silent" routes weren't installed
e
s 00000/00002/00856
d D 4.4 82/05/24 19:37:09 sam 4 3
c TIOCNOTTY
e
s 00266/00252/00592
d D 4.3 82/05/24 19:27:22 sam 3 2
c it's just all different!!!!
e
s 00002/00001/00842
d D 4.2 82/05/23 19:20:51 sam 2 1
c add SIGTERM catch so we can dump profiling buffer
e
s 00843/00000/00000
d D 4.1 82/05/22 22:26:20 sam 1 0
c date and time created 82/05/22 22:26:20 by sam
e
u
U
t
T
I 1
#ifndef lint
D 15
static char sccsid[] = "%W% %G%";
E 15
I 15
D 22
static char sccsid[] = "%W% %E%";
E 22
I 22
static char sccsid[] = "%W% %G%";
E 22
E 15
#endif

D 6
#include <sys/param.h>
#include <sys/protosw.h>
E 6
I 6
/*
 * Routing Table Management Daemon
 */
#include <sys/types.h>
E 6
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/in.h>
D 6
#define	KERNEL
#include <net/route.h>
E 6
#include <net/if.h>
#include <errno.h>
#include <stdio.h>
#include <nlist.h>
#include <signal.h>
I 13
#include <time.h>
I 25
#include <netdb.h>
E 25
I 16
#define	RIPCMDS
E 16
E 13
#include "rip.h"
#include "router.h"

#define	LOOPBACKNET	0177
/* casts to keep lint happy */
#define	insque(q,p)	_insque((caddr_t)q,(caddr_t)p)
#define	remque(q)	_remque((caddr_t)q)
#define equal(a1, a2) \
	(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
I 3
#define	min(a,b)	((a)>(b)?(b):(a))
E 3

struct nlist nl[] = {
#define	N_IFNET		0
	{ "_ifnet" },
	0,
};

D 16
struct	sockaddr_in myaddr = { AF_INET, IPPORT_ROUTESERVER };
E 16
I 16
D 26
struct	sockaddr_in routingaddr = { AF_INET, IPPORT_ROUTESERVER };
struct	sockaddr_in noroutingaddr = { AF_INET, IPPORT_ROUTESERVER+1 };
E 26
I 26
struct	sockaddr_in routingaddr = { AF_INET };
struct	sockaddr_in noroutingaddr = { AF_INET };
E 26
E 16

int	s;
I 14
int	snoroute;		/* socket with no routing */
E 14
D 3
int	kmem;
E 3
I 3
int	kmem = -1;
E 3
D 15
int	supplier;		/* process should supply updates */
E 15
I 15
int	supplier = -1;		/* process should supply updates */
E 15
D 14
int	initializing;		/* stem off broadcast() calls */
E 14
D 10
int	install = 0;		/* if 1 call kernel */
E 10
I 10
int	install = 1;		/* if 1 call kernel */
I 17
int	lookforinterfaces = 1;
int	performnlist = 1;
I 19
int	externalinterfaces = 0;	/* # of remote and local interfaces */
E 19
E 17
E 10
I 3
D 15
int	lookforinterfaces = 1;
int	performnlist = 1;
E 3
int	timeval;
E 15
I 15
int	timeval = -TIMER_RATE;
E 15
int	timer();
int	cleanup();
I 15

#define tprintf if (trace) printf
E 15
int	trace = 0;
I 13
FILE	*ftrace;
E 13

D 15
char	packet[MAXPACKETSIZE];
E 15
I 15
char	packet[MAXPACKETSIZE+1];
struct	rip *msg = (struct rip *)packet;
E 15

I 6
D 26
struct in_addr if_makeaddr();
E 26
I 26
struct in_addr inet_makeaddr();
E 26
D 17
struct ifnet *if_ifwithaddr(), *if_ifwithnet();
E 6
extern char *malloc();
E 17
I 17
struct interface *if_ifwithaddr(), *if_ifwithnet();
extern char *malloc(), *sys_errlist[];
E 17
D 2
extern int errno;
E 2
I 2
extern int errno, exit();
I 15
char	**argv0;
E 15
E 2

I 15
D 16
int	sndmsg(), supply();
E 16
I 16
int	sendmsg(), supply();
E 16

E 15
main(argc, argv)
	int argc;
	char *argv[];
{
	int cc;
	struct sockaddr from;
I 26
	struct servent *sp;
E 26
	
I 15
	argv0 = argv;
E 15
I 3
D 4
#ifdef notdef
E 4
E 3
D 13
	{   int t = open("/dev/tty", 2);
	    if (t >= 0) {
		ioctl(t, TIOCNOTTY, 0);
		close(t);
	    }
E 13
I 13
#ifndef DEBUG
	if (fork())
		exit(0);
	for (cc = 0; cc < 10; cc++)
		(void) close(cc);
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int t = open("/dev/tty", 2);
	  if (t >= 0) {
		ioctl(t, TIOCNOTTY, (char *)0);
		(void) close(t);
	  }
E 13
	}
I 13
#endif
E 13
I 3
D 4
#endif
E 4
E 3
	if (trace) {
D 3
		(void) fclose(stdout);
		(void) fclose(stderr);
		(void) fopen("trace", "a");
		(void) dup(fileno(stdout));
E 3
I 3
D 13
		(void) freopen("/etc/routerlog", "a", stdout);
		(void) dup2(fileno(stdout), 2);
E 3
		setbuf(stdout, NULL);
E 13
I 13
		ftrace = fopen("/etc/routerlog", "w");
		dup2(fileno(ftrace), 1);
		dup2(fileno(ftrace), 2);
E 13
D 3

E 3
	}
I 19

	/*
	 * We use two sockets.  One for which outgoing
	 * packets are routed and for which they're not.
	 * The latter allows us to delete routing table
	 * entries in the kernel for network interfaces
	 * attached to our host which we believe are down
	 * while still polling it to see when/if it comes
	 * back up.  With the new ipc interface we'll be
	 * able to specify ``don't route'' as an option
	 * to send, but until then we utilize a second port.
	 */
E 19
D 7
#ifdef vax
E 7
I 7
D 26
#ifdef vax || pdp11
E 7
D 16
	myaddr.sin_port = htons(myaddr.sin_port);
E 16
I 16
	routingaddr.sin_port = htons(routingaddr.sin_port);
	noroutingaddr.sin_port = htons(noroutingaddr.sin_port);
E 16
#endif
E 26
I 26
	sp = getservbyname("router", "udp");
	if (sp == 0) {
		fprintf(stderr, "routed: udp/router: unknown service\n");
		exit(1);
	}
	routingaddr.sin_port = htons(sp->s_port);
	noroutingaddr.sin_port = htons(sp->s_port + 1);
E 26
again:
D 16
	s = socket(SOCK_DGRAM, 0, &myaddr, 0);
E 16
I 16
	s = socket(SOCK_DGRAM, 0, &routingaddr, 0);
E 16
	if (s < 0) {
		perror("socket");
		sleep(30);
		goto again;
	}
I 14
again2:
D 16
	snoroute = socket(SOCK_DGRAM, 0, 0, SO_DONTROUTE);
E 16
I 16
	snoroute = socket(SOCK_DGRAM, 0, &noroutingaddr, SO_DONTROUTE);
E 16
	if (snoroute < 0) {
		perror("socket");
		sleep(30);
		goto again2;
	}
E 14
D 15
	rtinit();
D 14
	getothers();
I 3
	initializing = 1;
E 14
E 3
	getinterfaces();
I 3
D 14
	initializing = 0;
E 14
E 3
	request();

E 15
	argv++, argc--;
D 15
	while (argc > 0) {
		if (strcmp(*argv, "-s") == 0)
E 15
I 15
	while (argc > 0 && **argv == '-') {
		if (!strcmp(*argv, "-s") == 0) {
E 15
D 3
			supplier++;
E 3
I 3
			supplier = 1;
E 3
D 15
		else if (strcmp(*argv, "-q") == 0)
E 15
I 15
			argv++, argc--;
			continue;
		}
		if (!strcmp(*argv, "-q") == 0) {
E 15
			supplier = 0;
D 15
		argv++, argc--;
E 15
I 15
			argv++, argc--;
			continue;
		}
		goto usage;
E 15
	}
I 15
	if (argc > 0) {
usage:
D 17
		fprintf(stderr, "usage: routed [ -s ]\n");
E 17
I 17
		fprintf(stderr, "usage: routed [ -sq ]\n");
E 17
		exit(1);
	}
I 19
	/*
	 * Collect an initial view of the world by
	 * snooping in the kernel and the gateway kludge
	 * file.  Then, send a request packet on all
	 * directly connected networks to find out what
	 * everyone else thinks.
	 */
E 19
	rtinit();
I 19
	gwkludge();
E 19
	ifinit();
	if (supplier < 0)
		supplier = 0;
D 19
	gwkludge();
E 19
	msg->rip_cmd = RIPCMD_REQUEST;
	msg->rip_nets[0].rip_dst.sa_family = AF_UNSPEC;
	msg->rip_nets[0].rip_metric = HOPCNT_INFINITY;
	toall(sendmsg);
E 15
I 2
D 3
	sigset(SIGTERM, exit);
E 3
E 2
	sigset(SIGALRM, timer);
D 3
	alarm(TIMER_RATE);
E 3
I 3
	timer();
E 3

D 15
	/*
	 * Listen for routing packets
	 */
E 15
	for (;;) {
		cc = receive(s, &from, packet, sizeof (packet));
		if (cc <= 0) {
			if (cc < 0 && errno != EINTR)
				perror("receive");
			continue;
		}
		sighold(SIGALRM);
		rip_input(&from, cc);
		sigrelse(SIGALRM);
	}
}

D 15
/*
D 14
 * Look in a file for any gateways we should configure
 * outside the directly connected ones.  This is a kludge,
 * but until we can find out about gateways on the "other side"
 * of the ARPANET using GGP, it's a must.
 *
 * We don't really know the distance to the gateway, so we
 * assume it's a neighbor.
 */
getothers()
{
	struct sockaddr_in dst, gate;
	FILE *fp = fopen("/etc/gateways", "r");
	struct rt_entry *rt;

	if (fp == NULL)
		return;
	bzero((char *)&dst, sizeof (dst));
	bzero((char *)&gate, sizeof (gate));
	dst.sin_family = AF_INET;
	gate.sin_family = AF_INET;
	while (fscanf(fp, "%x %x", &dst.sin_addr.s_addr, 
	   &gate.sin_addr.s_addr) != EOF) {
		rtadd((struct sockaddr *)&dst, (struct sockaddr *)&gate, 1);
		rt = rtlookup((struct sockaddr *)&dst);
		if (rt)
D 7
			rt->rt_flags |= RTF_SILENT;
E 7
I 7
D 11
			rt->rt_state |= RTS_SILENT;
E 11
I 11
			rt->rt_state |= RTS_HIDDEN;
E 11
E 7
	}
	fclose(fp);
}

D 3
struct ifnet *
if_ifwithaddr(addr)
	struct sockaddr *addr;
E 3
I 3
/*
E 14
 * Timer routine:
 *
 * o handle timers on table entries,
 * o invalidate entries which haven't been updated in a while,
 * o delete entries which are too old,
D 14
 * o retry ioctl's which weren't successful the first
 *   time due to the kernel entry being busy
E 14
 * o if we're an internetwork router, supply routing updates
 *   periodically
 */
timer()
E 15
I 15
rtinit()
E 15
E 3
{
D 3
	register struct ifnet *ifp;
E 3
I 3
D 6
	register struct rt_hash *rh;
E 6
I 6
	register struct rthash *rh;
E 6
D 15
	register struct rt_entry *rt;
D 6
	struct rt_hash *base = hosthash;
E 6
I 6
	struct rthash *base = hosthash;
E 6
	int doinghost = 1;
E 15
E 3

D 3
#define	same(a1, a2) \
	(bcmp((caddr_t)((a1)->sa_data), (caddr_t)((a2)->sa_data), 14) == 0)
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != addr->sa_family)
			continue;
		if (same(&ifp->if_addr, addr))
			break;
		if ((ifp->if_flags & IFF_BROADCAST) &&
		    same(&ifp->if_broadaddr, addr))
			break;
	}
	return (ifp);
#undef same
}
E 3
I 3
D 15
	if (trace)
		printf(">>> time %d >>>\n", timeval);
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
		rt = rh->rt_forw;
		for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
E 3

D 3
struct ifnet *
if_ifwithnet(addr)
	register struct sockaddr *addr;
{
	register struct ifnet *ifp;
	register int af = addr->sa_family;
	register int (*netmatch)();
E 3
I 3
			/*
			 * If the host is indicated to be
D 11
			 * "silent" (i.e. it's one we got
E 11
I 11
			 * "hidden" (i.e. it's one we got
E 11
			 * from the initialization file),
			 * don't time out it's entry.
			 */
D 5
			if (rt->rt_flags & RTF_SILENT)
				continue;
E 5
I 5
D 7
			if ((rt->rt_flags & RTF_SILENT) == 0)
E 7
I 7
D 11
			if ((rt->rt_state & RTS_SILENT) == 0)
E 11
I 11
D 14
			if ((rt->rt_state & RTS_HIDDEN) == 0)
E 14
I 14
			if ((rt->rt_state & RTS_PASSIVE) == 0)
E 14
E 11
E 7
				rt->rt_timer += TIMER_RATE;
E 5
			log("", rt);
D 5
			rt->rt_timer += TIMER_RATE;
E 5
E 3

D 3
	if (af >= AF_MAX)
		return (0);
	netmatch = afswitch[af].af_netmatch;
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (af != ifp->if_addr.sa_family)
			continue;
		if ((*netmatch)(addr, &ifp->if_addr))
			break;
	}
	return (ifp);
}
E 3
I 3
			/*
			 * If the entry should be deleted
			 * attempt to do so and reclaim space.
			 */
			if (rt->rt_timer >= GARBAGE_TIME ||
D 7
			  (rt->rt_flags & RTF_DELRT)) {
				rt = rt->rt_forw;
				rtdelete(rt->rt_back);
E 7
I 7
			  (rt->rt_state & RTS_DELRT)) {
E 7
				rt = rt->rt_back;
I 7
				rtdelete(rt->rt_forw);
E 7
				continue;
			}
E 3

D 3
struct in_addr
if_makeaddr(net, host)
	int net, host;
{
	u_long addr;
E 3
I 3
			/*
			 * If we haven't heard from the router
			 * in a long time indicate the route is
			 * hard to reach.
			 */
			if (rt->rt_timer >= EXPIRE_TIME)
				rt->rt_metric = HOPCNT_INFINITY;
D 7
			if (rt->rt_flags & RTF_CHGRT)
E 7
I 7
D 14
			if (rt->rt_state & RTS_CHGRT)
E 7
D 6
				if (!ioctl(s, SIOCCHGRT,(char *)&rt->rt_hash) ||
E 6
I 6
				if (!ioctl(s, SIOCCHGRT,(char *)&rt->rt_rt) ||
E 6
				  --rt->rt_retry == 0)
D 7
					rt->rt_flags &= ~RTF_CHGRT;
E 7
I 7
					rt->rt_state &= ~RTS_CHGRT;
E 14
E 7
E 3

D 3
	if (net < 128)
		addr = (net << 24) | host;
	else if (net < 65536)
		addr = (net << 16) | host;
	else
		addr = (net << 8) | host;
#ifdef vax
	addr = htonl(addr);
#endif
	return (*(struct in_addr *)&addr);
E 3
I 3
			/*
D 14
			 * Try to add the route to the kernel tables.
			 * If this fails because the entry already exists
			 * (perhaps because someone manually added it)
			 * change the add to a change.  If the operation
			 * fails otherwise (likely because the entry is
			 * in use), retry the operation a few more times.
E 14
I 14
			 * If a change or addition is to be made
			 * and this isn't time to broadcast an
			 * update, then broadcast the change.
E 14
			 */
I 14
			if ((rt->rt_state & (RTS_CHGRT|RTS_ADDRT)) &&
			    supplier &&
			    (timeval + TIMER_RATE) % SUPPLY_INTERVAL)
				broadcast(rt);

			if (rt->rt_state & RTS_CHGRT) {
				struct rtentry oldroute;

				oldroute = rt->rt_rt;
				rt->rt_router = rt->rt_newrouter;
				if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
					perror("SIOCADDRT");
				if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
					perror("SIOCDELRT");
				rt->rt_state &= ~RTS_CHGRT;
			}
E 14
D 7
			if (rt->rt_flags & RTF_ADDRT) {
E 7
I 7
			if (rt->rt_state & RTS_ADDRT) {
E 7
D 6
				if (!ioctl(s, SIOCADDRT,(char *)&rt->rt_hash)) {
E 6
I 6
D 14
				if (!ioctl(s, SIOCADDRT,(char *)&rt->rt_rt)) {
E 6
					if (errno == EEXIST) {
D 7
						rt->rt_flags &= ~RTF_ADDRT;
						rt->rt_flags |= RTF_CHGRT;
E 7
I 7
						rt->rt_state &= ~RTS_ADDRT;
						rt->rt_state |= RTS_CHGRT;
E 7
						rt->rt_retry =
						    (EXPIRE_TIME/TIMER_RATE);
						continue;
					}
					if (--rt->rt_retry)
						continue;
				}
E 14
I 14
				if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
					perror("SIOCADDRT");
E 14
D 7
				rt->rt_flags &= ~RTF_ADDRT;
E 7
I 7
				rt->rt_state &= ~RTS_ADDRT;
E 7
			}
		}
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
	timeval += TIMER_RATE;
	if (lookforinterfaces && (timeval % CHECK_INTERVAL) == 0)
		getinterfaces();
	if (supplier && (timeval % SUPPLY_INTERVAL) == 0)
		supplyall();
	if (trace)
		printf("<<< time %d <<<\n", timeval);
	alarm(TIMER_RATE);
E 15
I 15
	for (rh = nethash; rh < &nethash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
	for (rh = hosthash; rh < &hosthash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
E 15
E 3
}

I 6
D 17
struct	ifnet *ifnet;
E 17
I 17
struct	interface *ifnet;
E 17
E 6
D 15
/*
 * Find the network interfaces attached to this machine.
D 3
 * The info is used to::
E 3
I 3
 * The info is used to:
E 3
 *
 * (1) initialize the routing tables, as done by the kernel.
 * (2) ignore incoming packets we send.
 * (3) figure out broadcast capability and addresses.
 * (4) figure out if we're an internetwork gateway.
 *
 * We don't handle anything but Internet addresses.
I 6
 *
 * Note: this routine may be called periodically to
 * scan for new interfaces.  In fact, the timer routine
 * does so based on the flag lookforinterfaces.  The
 * flag performnlist is set whenever something odd occurs
 * while scanning the kernel; this is likely to occur
 * if /vmunix isn't up to date (e.g. someone booted /ovmunix).
E 6
 */
getinterfaces()
E 15
I 15

I 19
/*
 * Probe the kernel through /dev/kmem to find the network
 * interfaces which have configured themselves.  If the
 * interface is present but not yet up (for example an
 * ARPANET IMP), set the lookforinterfaces flag so we'll
 * come back later and look again.
 */
E 19
ifinit()
E 15
{
D 3
	register struct ifnet **pifp, *ifp;
E 3
I 3
D 15
	struct ifnet *ifp;
	struct ifnet ifstruct, *next;
E 3
	struct sockaddr_in net;
E 15
I 15
D 17
	struct ifnet *ifp, *next;
E 15
D 3
	struct in_addr logicaladdr;
E 3
I 3
D 16
	register struct sockaddr *dst;
E 16
E 3
D 15
	int nets;
E 15
I 15
	int uniquemultihostinterfaces = 0;
E 17
I 17
	struct interface *ifp;
	struct ifnet ifs, *next;
D 19
	int externalinterfaces = 0;
E 19
E 17
E 15

D 3
	nlist("/vmunix", nl);
	if (nl[N_IFNET].n_value == 0) {
		printf("ifnet: symbol not in namelist\n");
		exit(1);
E 3
I 3
D 15
	if (performnlist) {
		nlist("/vmunix", nl);
		if (nl[N_IFNET].n_value == 0) {
			performnlist++;
			printf("ifnet: not in namelist\n");
			return;
		}
		performnlist = 0;
E 15
I 15
D 17
	nlist("/vmunix", nl);
	if (nl[N_IFNET].n_value == 0) {
		printf("ifnet: not in namelist\n");
		goto bad;
E 17
I 17
	if (performnlist) {
		nlist("/vmunix", nl);
		if (nl[N_IFNET].n_value == 0) {
			printf("ifnet: not in namelist\n");
			goto bad;
		}
		performnlist = 0;
E 17
E 15
E 3
	}
I 15
D 17
	kmem = open("/dev/kmem", 0);
E 17
E 15
D 3
	kmem = open("/dev/kmem", 0);
E 3
	if (kmem < 0) {
D 3
		perror("/dev/kmem");
		exit(1);
E 3
I 3
D 15
		kmem = open("/dev/kmem", 0);
		if (kmem < 0) {
			perror("/dev/kmem");
			return;
		}
E 15
I 15
D 17
		perror("/dev/kmem");
		goto bad;
E 17
I 17
		kmem = open("/dev/kmem", 0);
		if (kmem < 0) {
			perror("/dev/kmem");
			goto bad;
		}
E 17
E 15
E 3
	}
D 3
	(void) lseek(kmem, (long)nl[N_IFNET].n_value, 0);
	(void) read(kmem, (char *)&ifnet, sizeof (ifnet));
E 3
I 3
	if (lseek(kmem, (long)nl[N_IFNET].n_value, 0) == -1 ||
D 15
	    read(kmem, (char *)&ifp, sizeof (ifp)) != sizeof (ifp)) {
		performnlist = 1;
		return;
E 15
I 15
	    read(kmem, (char *)&next, sizeof (next)) != sizeof (next)) {
		printf("ifnet: error reading kmem\n");
		goto bad;
E 15
	}
I 17
	lookforinterfaces = 0;
E 17
E 3
D 15
	bzero((char *)&net, sizeof (net));
	net.sin_family = AF_INET;
I 9
	lookforinterfaces = 0;
E 9
D 3
	logicaladdr.s_addr = 0;
E 3
	nets = 0;
D 3
	pifp = &ifnet;
	initializing = 1;
	while (*pifp) {
		struct sockaddr_in *sin;

		(void) lseek(kmem, (long)*pifp, 0);
		ifp = *pifp = (struct ifnet *)malloc(sizeof (struct ifnet));
		if (ifp == 0) {
			printf("routed: out of memory\n");
			break;
		}
		if (read(kmem, (char *)ifp, sizeof (*ifp)) != sizeof (*ifp)) {
E 3
I 3
	while (ifp) {
		if (lseek(kmem, (long)ifp, 0) == -1 ||
		  read(kmem, (char *)&ifstruct, sizeof (ifstruct)) !=
		  sizeof (ifstruct)) {
E 3
			perror("read");
I 3
D 9
			performnlist = 1;
E 9
I 9
			lookforinterfaces = performnlist = 1;
E 9
E 3
			break;
		}
I 3
		ifp = &ifstruct;
		if ((ifp->if_flags & IFF_UP) == 0) {
D 9
			lookforinterfaces++;
E 9
I 9
			lookforinterfaces = 1;
E 9
	skip:
			ifp = ifp->if_next;
			continue;
		}
		if (ifp->if_addr.sa_family != AF_INET)
			goto skip;
		/* ignore software loopback networks. */
E 3
		if (ifp->if_net == LOOPBACKNET)
			goto skip;
D 3
		nets++;
		if ((ifp->if_flags & IFF_UP) == 0)
E 3
I 3
		/* check if we already know about this one */
		if (if_ifwithaddr(&ifstruct.if_addr)) {
			nets++;
E 3
			goto skip;
D 3

		/*
		 * Kludge: don't treat logical host pseudo-interface
		 *	   as a net route, instead fabricate route
		 *	   to get packets back from the gateway.
		 */
		sin = (struct sockaddr_in *)&ifp->if_addr;
		if (sin->sin_family == AF_INET && ifp->if_net == 10 &&
		    sin->sin_addr.s_lh) {
			logicaladdr = sin->sin_addr;
			goto skip;
E 3
		}
E 15
I 15
	while (next) {
E 15
I 3
D 17
		ifp = (struct ifnet *)malloc(sizeof (struct ifnet));
		if (ifp == 0) {
			printf("routed: out of memory\n");
			break;
		}
E 17
D 15
		bcopy((char *)&ifstruct, (char *)ifp, sizeof (struct ifnet));
E 3

		/*
D 3
		 * Before we can handle point-point links, the interface
		 * structure will have to include an indicator to allow
		 * us to distinguish entries from "network" entries.
E 3
I 3
		 * Count the # of directly connected networks
		 * and point to point links which aren't looped
		 * back to ourself.  This is used below to
		 * decide if we should be a routing "supplier".
E 3
		 */
D 3
		net.sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
		rtadd((struct sockaddr *)&net, (struct sockaddr *)sin, 0);
	skip:
		pifp = &ifp->if_next;
	}
	if (logicaladdr.s_addr) {
		struct rt_entry *rt;
E 3
I 3
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifp->if_dstaddr) == 0)
			nets++;
E 3

D 3
		net.sin_addr = logicaladdr;
		if (ifnet)
			rtadd((struct sockaddr *)&net, &ifnet->if_addr, 0);
		/* yech...yet another logical host kludge */
		rt = rtlookup((struct sockaddr *)&net);
		if (rt)
			rt->rt_flags |= RTF_SILENT;
E 3
I 3
		if (ifp->if_flags & IFF_POINTOPOINT)
			dst = &ifp->if_dstaddr;
		else {
			net.sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
			dst = (struct sockaddr *)&net;
E 15
I 15
		if (lseek(kmem, (long)next, 0) == -1 ||
D 17
		    read(kmem, (char *)ifp, sizeof (*ifp)) != sizeof (*ifp)) {
E 17
I 17
		    read(kmem, (char *)&ifs, sizeof (ifs)) != sizeof (ifs)) {
E 17
			perror("read");
			goto bad;
E 15
		}
D 17
		next = ifp->if_next;
I 15
		if (ifp->if_addr.sa_family != AF_INET)
E 17
I 17
		next = ifs.if_next;
		if ((ifs.if_flags & IFF_UP) == 0) {
			lookforinterfaces = 1;
E 17
			continue;
D 17
		if (ifp->if_net == LOOPBACKNET)
E 17
I 17
		}
I 19
		/* already known to us? */
E 19
		if (if_ifwithaddr(&ifs.if_addr))
E 17
			continue;
I 19
		/* argh, this'll have to change sometime */
E 19
D 17
		if ((ifp->if_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifp->if_dstaddr) == 0)
			uniquemultihostinterfaces++;
E 15
		ifp->if_next = ifnet;
E 17
I 17
		if (ifs.if_addr.sa_family != AF_INET)
			continue;
I 19
		/* no one cares about software loopback interfaces */
E 19
		if (ifs.if_net == LOOPBACKNET)
			continue;
		ifp = (struct interface *)malloc(sizeof (struct interface));
		if (ifp == 0) {
			printf("routed: out of memory\n");
			break;
		}
		/*
		 * Count the # of directly connected networks
		 * and point to point links which aren't looped
		 * back to ourself.  This is used below to
D 19
		 * decide if we should be a routing "supplier".
E 19
I 19
		 * decide if we should be a routing ``supplier''.
E 19
		 */
		if ((ifs.if_flags & IFF_POINTOPOINT) == 0 ||
		    if_ifwithaddr(&ifs.if_dstaddr) == 0)
			externalinterfaces++;
		ifp->int_addr = ifs.if_addr;
		ifp->int_flags = ifs.if_flags | IFF_INTERFACE;
		/* this works because broadaddr overlaps dstaddr */
		ifp->int_broadaddr = ifs.if_broadaddr;
		ifp->int_net = ifs.if_net;
		ifp->int_metric = 0;
		ifp->int_next = ifnet;
E 17
		ifnet = ifp;
D 14
		if (rtlookup(dst) == 0)
E 14
I 14
D 15
		if (rtlookup(dst) == 0) {
			struct rt_entry *rt;
E 15
I 15
		addrouteforif(ifp);
	}
D 17
	if (uniquemultihostinterfaces > 1 && supplier < 0)
E 17
I 17
	if (externalinterfaces > 1 && supplier < 0)
E 17
		supplier = 1;
	return;
bad:
	sleep(60);
I 17
	close(kmem), close(s), close(snoroute);
E 17
	execv("/etc/routed", argv0);
	_exit(0177);
}
E 15

E 14
D 15
			rtadd(dst, &ifp->if_addr, 0);
I 14
			rt = rtlookup(dst);
			if (rt)
				rt->rt_state |= RTS_INTERFACE;
		}
E 14
		ifp = next;
E 15
I 15
addrouteforif(ifp)
D 17
	struct ifnet *ifp;
E 17
I 17
	struct interface *ifp;
E 17
{
	struct sockaddr_in net;
	struct sockaddr *dst;
I 17
	int state, metric;
I 21
	struct rt_entry *rt;
E 21
E 17

D 17
	if (ifp->if_flags & IFF_POINTOPOINT)
		dst = &ifp->if_dstaddr;
E 17
I 17
	if (ifp->int_flags & IFF_POINTOPOINT)
		dst = &ifp->int_dstaddr;
E 17
	else {
		bzero((char *)&net, sizeof (net));
		net.sin_family = AF_INET;
D 17
		net.sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
E 17
I 17
D 26
		net.sin_addr = if_makeaddr(ifp->int_net, INADDR_ANY);
E 26
I 26
		net.sin_addr = inet_makeaddr(ifp->int_net, INADDR_ANY);
E 26
E 17
		dst = (struct sockaddr *)&net;
E 15
E 3
	}
D 3
	(void) close(kmem);
	initializing = 0;
E 3
D 15
	supplier = nets > 1;
I 14
	getothers();
E 15
I 15
D 16
	rtadd(dst, &ifp->if_addr, 0, RTS_INTERFACE);
E 16
I 16
D 17
	rtadd(dst, &ifp->if_addr, 0, RTS_DONTDELETE|RTS_DONTROUTE);
E 17
I 17
D 19
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 19
I 19
D 21
	if (rtlookup(dst) == 0)
		rtadd(dst, &ifp->int_addr, ifp->int_metric,
		  ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
E 21
I 21
	rt = rtlookup(dst);
	rtadd(dst, &ifp->int_addr, ifp->int_metric,
		ifp->int_flags & (IFF_INTERFACE|IFF_PASSIVE|IFF_REMOTE));
	if (rt)
		rtdelete(rt);
E 21
E 19
E 17
E 16
E 15
E 14
}

I 19
/*
 * As a concession to the ARPANET we read a list of gateways
 * from /etc/gateways and add them to our tables.  This file
 * exists at each ARPANET gateway and indicates a set of ``remote''
 * gateways (i.e. a gateway which we can't immediately determine
 * if it's present or not as we can do for those directly connected
 * at the hardware level).  If a gateway is marked ``passive''
 * in the file, then we assume it doesn't have a routing process
 * of our design and simply assume it's always present.  Those
 * not marked passive are treated as if they were directly
 * connected -- they're added into the interface list so we'll
 * send them routing updates.
 */
E 19
D 15
/*
I 14
 * Look in a file for any gateways we should configure
 * outside the directly connected ones.  This is a kludge,
 * but until we can find out about gateways on the "other side"
 * of the ARPANET using GGP, it's a must.
 *
 * File format is one entry per line, 
 *	destination gateway flags	(all hex #'s)
 *
 * We don't really know the distance to the gateway, so we
 * assume it's a neighbor.
 */
getothers()
E 15
I 15
gwkludge()
E 15
{
	struct sockaddr_in dst, gate;
	FILE *fp;
D 16
	struct rt_entry *rt;
D 15
	char flags[132];
E 15
I 15
	char flags[BUFSIZ];
E 16
I 16
D 22
	char buf[BUFSIZ];
E 22
I 22
D 26
	char *dname, *gname, *qual, buf[BUFSIZ];
E 26
I 26
	char *type, *dname, *gname, *qual, buf[BUFSIZ];
E 26
E 22
I 17
	struct interface *ifp;
	int metric;
E 17
E 16
E 15

	fp = fopen("/etc/gateways", "r");
	if (fp == NULL)
		return;
I 22
D 26
	qual = buf; dname = buf + 64; gname = buf + ((BUFSIZ - 64) / 2);
E 26
I 26
	qual = buf;
	dname = buf + 64;
	gname = buf + ((BUFSIZ - 64) / 3);
	type = buf + (((BUFSIZ - 64) * 2) / 3);
E 26
E 22
	bzero((char *)&dst, sizeof (dst));
	bzero((char *)&gate, sizeof (gate));
D 17
	dst.sin_family = AF_INET;
	gate.sin_family = AF_INET;
E 17
I 17
	dst.sin_family = gate.sin_family = AF_INET;
D 26
	/* format: dst XX gateway XX metric DD [passive]\n */
E 26
I 26
D 27
	/* format: dst {net | host} XX gateway XX metric DD [passive]\n */
E 27
I 27
	/* format: {net | host} XX gateway XX metric DD [passive]\n */
E 27
E 26
#define	readentry(fp) \
D 22
	fscanf((fp), "dst %x gateway %x metric %d %s\n", \
	&dst.sin_addr.s_addr, &gate.sin_addr.s_addr, &metric, buf)
E 22
I 22
D 26
	fscanf((fp), "dst %s gateway %s metric %d %s\n", \
		dname, gname, &metric, qual)
E 26
I 26
D 27
	fscanf((fp), "dst %s %s gateway %s metric %d %s\n", \
E 27
I 27
	fscanf((fp), "%s %s gateway %s metric %d %s\n", \
E 27
		type, dname, gname, &metric, qual)
E 26
E 22
E 17
D 15
	flags[0] = '\0';
	while (fscanf(fp, "dst %x gateway %x %s\n", &dst.sin_addr.s_addr, 
	   &gate.sin_addr.s_addr, flags) != EOF) {
		if (rt = rtlookup((struct sockaddr *)&dst)) {
			flags[0] = '\0';
			continue;
		}
		rtadd((struct sockaddr *)&dst,(struct sockaddr *)&gate,1);
		rt = rtlookup(&dst);
		if (strcmp(flags, "passive") == 0)
			rt->rt_state |= RTS_PASSIVE;
		flags[0] = '\0';
E 15
I 15
	for (;;) {
I 25
		struct hostent *host;
I 26
		struct netent *net;
E 26

E 25
D 16
		if (fscanf(fp, "dst %x gateway %x\n", &dst.sin_addr.s_addr, 
		   &gate.sin_addr.s_addr, flags) == EOF)
E 16
I 16
D 17
		buf[0] = '\0';
		/* format is: dst XX gateway XX [passive]\n */
		if (fscanf(fp, "dst %x gateway %x %s\n", &dst.sin_addr.s_addr, 
		   &gate.sin_addr.s_addr, buf) == EOF)
E 17
I 17
		if (readentry(fp) == EOF)
E 17
E 16
			break;
I 22
D 25
		dst.sin_addr.s_addr = rhost(&dname);
		if (dst.sin_addr.s_addr == -1)
E 25
I 25
D 26
		host = gethostbyname(dname);
		if (host == 0)
E 26
I 26
		if (strcmp(type, "net") == 0) {
			net = getnetbyname(dname);
			if (net == 0 || net->n_addrtype != AF_INET)
				continue;
			dst.sin_addr = inet_makeaddr(net->n_net, INADDR_ANY);
		} else if (strcmp(type, "host") == 0) {
			host = gethostbyname(dname);
			if (host == 0)
				continue;
			bcopy(host->h_addr, &dst.sin_addr, host->h_length);
		} else
E 26
E 25
			continue;
D 25
		gate.sin_addr.s_addr = rhost(&gname);
		if (gate.sin_addr.s_addr == -1)
E 25
I 25
D 26
		bcopy(host->h_addr, &dst.sin_addr, host->h_length);
E 26
		host = gethostbyname(gname);
		if (host == 0)
E 25
			continue;
I 25
		bcopy(host->h_addr, &gate.sin_addr, host->h_length);
E 25
E 22
D 17
		rtadd((struct sockaddr *)&dst, (struct sockaddr *)&gate, 1,
D 16
		    RTS_GLOBAL|(!strcmp(flags, "passive") ? RTS_PASSIVE : 0));
E 16
I 16
		   strcmp(buf, "passive") == 0 ? RTS_PASSIVE : RTS_DONTDELETE);
E 17
I 17
		ifp = (struct interface *)malloc(sizeof (*ifp));
		bzero((char *)ifp, sizeof (*ifp));
		ifp->int_flags = IFF_REMOTE;
		/* can't identify broadcast capability */
I 18
D 24
		ifp->int_net = IN_NETOF(dst.sin_addr);
E 24
I 24
D 26
		ifp->int_net = in_netof(dst.sin_addr);
E 24
E 18
		if ((*afswitch[dst.sin_family].af_checkhost)(&dst)) {
E 26
I 26
		ifp->int_net = inet_netof(dst.sin_addr);
		if (strcmp(type, "host") == 0) {
E 26
			ifp->int_flags |= IFF_POINTOPOINT;
D 18
			ifp->int_net = dst.sin_addr.s_net;	/* XXX */
E 18
			ifp->int_dstaddr = *((struct sockaddr *)&dst);
D 18
		} else
			ifp->int_net = dst.sin_addr.s_addr;	/* XXX */
E 18
I 18
		}
E 18
D 22
		if (strcmp(buf, "passive") == 0)
E 22
I 22
		if (strcmp(qual, "passive") == 0)
E 22
			ifp->int_flags |= IFF_PASSIVE;
I 19
		else
			/* assume no duplicate entries */
			externalinterfaces++;
E 19
		ifp->int_addr = *((struct sockaddr *)&gate);
		ifp->int_metric = metric;
		ifp->int_next = ifnet;
		ifnet = ifp;
		addrouteforif(ifp);
E 17
E 16
E 15
	}
	fclose(fp);
}

I 19
/*
 * Timer routine.  Performs routing information supply
 * duties and manages timers on routing table entries.
 */
E 19
D 15
/*
E 14
 * Send a request message to all directly
 * connected hosts and networks.
 */
request()
E 15
I 15
timer()
E 15
{
D 3
	register struct rt_entry *rt;
	register struct rt_hash *rh;
	struct rt_hash *base = hosthash;
	int doinghost = 1;
E 3
I 3
D 15
	register struct rip *msg = (struct rip *)packet;
E 3

D 3
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++)
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		if ((rt->rt_flags & RTF_SILENT) || rt->rt_metric > 0)
			continue;
		getall(rt);
	}
	if (doinghost) {
		base = nethash;
		doinghost = 0;
		goto again;
	}
E 3
I 3
	msg->rip_cmd = RIPCMD_REQUEST;
	msg->rip_nets[0].rip_dst.sa_family = AF_UNSPEC;
	msg->rip_nets[0].rip_metric = HOPCNT_INFINITY;
	sendall();
E 3
}

/*
 * Broadcast a new, or modified, routing table entry
 * to all directly connected hosts and networks.
 */
broadcast(entry)
	struct rt_entry *entry;
{
I 3
	struct rip *msg = (struct rip *)packet;

	log("broadcast", entry);
	msg->rip_cmd = RIPCMD_RESPONSE;
	msg->rip_nets[0].rip_dst = entry->rt_dst;
	msg->rip_nets[0].rip_metric = min(entry->rt_metric+1, HOPCNT_INFINITY);
	sendall();
}

I 6
/*
 * Send "packet" to all neighbors.
 */
E 6
sendall()
{
E 15
E 3
D 6
	register struct rt_hash *rh;
E 6
I 6
	register struct rthash *rh;
E 6
	register struct rt_entry *rt;
D 15
	register struct sockaddr *dst;
E 15
D 6
	struct rt_hash *base = hosthash;
E 6
I 6
	struct rthash *base = hosthash;
E 6
D 15
	int doinghost = 1;
E 15
I 15
D 17
	int doinghost = 1, state;
E 17
I 17
D 19
	int doinghost = 1, supplyeverything;
E 19
I 19
	int doinghost = 1, timetobroadcast;
E 19
E 17
E 15
D 3
	struct rip *msg = (struct rip *)packet;
E 3

I 15
	timeval += TIMER_RATE;
I 17
	if (lookforinterfaces && (timeval % CHECK_INTERVAL) == 0)
		ifinit();
D 19
	supplyeverything = supplier && (timeval % SUPPLY_INTERVAL) == 0;
E 19
I 19
	timetobroadcast = supplier && (timeval % SUPPLY_INTERVAL) == 0;
E 19
E 17
	tprintf(">>> time %d >>>\n", timeval);
E 15
D 3
	if (trace)
		log("broadcast", entry);
	msg->rip_cmd = RIPCMD_RESPONSE;
	msg->rip_nets[0].rip_dst = entry->rt_dst;
	msg->rip_nets[0].rip_metric = entry->rt_metric + 1;

E 3
again:
D 15
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++)
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
D 7
		if ((rt->rt_flags & RTF_SILENT) || rt->rt_metric > 0)
E 7
I 7
D 11
		if ((rt->rt_state & RTS_SILENT) || rt->rt_metric > 0)
E 11
I 11
D 14
		if ((rt->rt_state & RTS_HIDDEN) || rt->rt_metric > 0)
E 14
I 14
		if ((rt->rt_state&RTS_PASSIVE) || rt->rt_metric > 0)
E 14
E 11
E 7
			continue;
		if (rt->rt_ifp && (rt->rt_ifp->if_flags & IFF_BROADCAST))
			dst = &rt->rt_ifp->if_broadaddr;
		else
D 14
			dst = &rt->rt_gateway;
		(*afswitch[dst->sa_family].af_output)(dst, sizeof (struct rip));
E 14
I 14
			dst = &rt->rt_router;
		(*afswitch[dst->sa_family].af_output)
			(s, dst, sizeof (struct rip));
E 15
I 15
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
		rt = rh->rt_forw;
		for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
D 16
			if (!(rt->rt_state & RTS_GLOBAL))
E 16
I 16
D 17
			if (!(rt->rt_state & RTS_PASSIVE)) {
E 17
I 17
D 19
			if (!(rt->rt_state & RTS_PASSIVE))
E 19
I 19
			/*
			 * We don't advance time on a routing entry for
			 * a passive gateway or that for our only interface. 
			 * The latter is excused because we don't act as
			 * a routing information supplier and hence would
			 * time it out.  This is fair as if it's down
			 * we're cut off from the world anyway and it's
			 * not likely we'll grow any new hardware in
			 * the mean time.
			 */
			if (!(rt->rt_state & RTS_PASSIVE) &&
			    (supplier || !(rt->rt_state & RTS_INTERFACE)))
E 19
E 17
E 16
				rt->rt_timer += TIMER_RATE;
I 16
D 17
				if (rt->rt_timer > 9999)
					rt->rt_timer = 9999;
			}
E 16
			log("", rt);
I 16
			if (rt->rt_state & RTS_HIDDEN)
				continue;
E 17
E 16
			if (rt->rt_timer >= EXPIRE_TIME)
				rt->rt_metric = HOPCNT_INFINITY;
D 17
			if ((rt->rt_state & RTS_DELRT) ||
			    rt->rt_timer >= GARBAGE_TIME) {
E 17
I 17
			log("", rt);
			if (rt->rt_timer >= GARBAGE_TIME) {
E 17
D 16
				if (rt->rt_state&(RTS_INTERFACE|RTS_GLOBAL)) {
					if (rt->rt_timer > 9999)
						rt->rt_timer = 9999;
					continue;
				}
E 16
				rt = rt->rt_back;
				rtdelete(rt->rt_forw);
				continue;
			}
D 17
			state = rt->rt_state;
			if (rt->rt_state & RTS_ADDRT) {
				if (ioctl(s, SIOCADDRT,(char *)&rt->rt_rt) < 0)
					perror("SIOCADDRT");
				rt->rt_state &= ~RTS_ADDRT;
			}
			if (rt->rt_state & RTS_CHGRT) {
				struct rtentry oldroute;

				oldroute = rt->rt_rt;
D 16
				rt->rt_router = rt->rt_newrouter;
				if (ioctl(s, SIOCADDRT,(char *)&rt->rt_rt) < 0)
E 16
I 16
				oldroute.rt_gateway = rt->rt_oldrouter;
				if (install &&
				    ioctl(s, SIOCADDRT,(char *)&rt->rt_rt) < 0)
E 16
					perror("SIOCADDRT");
D 16
				if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
E 16
I 16
				if (install &&
				    ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
E 16
					perror("SIOCDELRT");
				rt->rt_state &= ~RTS_CHGRT;
			}
			if (supplier && (state & (RTS_CHGRT|RTS_ADDRT))) {
E 17
I 17
			if (rt->rt_state & RTS_CHANGED) {
				rt->rt_state &= ~RTS_CHANGED;
				/* don't send extraneous packets */
D 19
				if (supplyeverything)
E 19
I 19
				if (!supplier || timetobroadcast)
E 19
					continue;
E 17
				log("broadcast", rt);
				msg->rip_cmd = RIPCMD_RESPONSE;
				msg->rip_nets[0].rip_dst = rt->rt_dst;
				msg->rip_nets[0].rip_metric =
				    min(rt->rt_metric+1, HOPCNT_INFINITY);
D 16
				sendmsgtoall();
E 16
I 16
				toall(sendmsg);
E 16
			}
		}
E 15
E 14
	}
	if (doinghost) {
D 3
		doinghost = 0;
E 3
D 15
		base = nethash;
E 15
I 3
		doinghost = 0;
I 15
		base = nethash;
E 15
E 3
		goto again;
	}
I 15
D 17
	if (supplier && (timeval % SUPPLY_INTERVAL) == 0)
E 17
I 17
D 19
	if (supplyeverything)
E 19
I 19
	if (timetobroadcast)
E 19
E 17
		toall(supply);
	tprintf("<<< time %d <<<\n", timeval);
	alarm(TIMER_RATE);
E 15
}

D 15
/*
 * Supply all directly connected neighbors with the
 * current state of the routing tables.
 */
supplyall()
E 15
I 15
toall(f)
	int (*f)();
E 15
{
D 15
	register struct rt_entry *rt;
E 15
D 6
	register struct rt_hash *rh;
E 6
I 6
D 17
	register struct rthash *rh;
I 15
	register struct rt_entry *rt;
E 17
I 17
	register struct interface *ifp;
E 17
E 15
E 6
	register struct sockaddr *dst;
D 6
	struct rt_hash *base = hosthash;
E 6
I 6
D 17
	struct rthash *base = hosthash;
E 6
	int doinghost = 1;
E 17

D 17
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++)
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
D 7
		if ((rt->rt_flags & RTF_SILENT) || rt->rt_metric > 0)
E 7
I 7
D 11
		if ((rt->rt_state & RTS_SILENT) || rt->rt_metric > 0)
E 11
I 11
D 14
		if ((rt->rt_state & RTS_HIDDEN) || rt->rt_metric > 0)
E 14
I 14
D 15
		if ((rt->rt_state&RTS_PASSIVE) ||
		    (!(rt->rt_state&RTS_INTERFACE) && rt->rt_metric > 0))
E 15
I 15
D 16
		if ((rt->rt_state&RTS_PASSIVE) || rt->rt_metric > 0)
E 16
I 16
		if ((rt->rt_state & RTS_PASSIVE) || rt->rt_metric > 0)
E 17
I 17
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_PASSIVE)
E 17
E 16
E 15
E 14
E 11
E 7
			continue;
D 17
		if (rt->rt_ifp && (rt->rt_ifp->if_flags & IFF_BROADCAST))
			dst = &rt->rt_ifp->if_broadaddr;
		else
D 14
			dst = &rt->rt_gateway;
E 14
I 14
			dst = &rt->rt_router;
E 14
D 3
		if (trace)
			log("supply", rt);
E 3
I 3
D 15
		log("supply", rt);
E 3
D 14
		supply(dst);
E 14
I 14
		supply(rt->rt_state&RTS_INTERFACE ? snoroute : s, dst);
E 15
I 15
D 16
		(*f)(rt, dst);
E 16
I 16
		(*f)(dst, rt->rt_state & RTS_DONTROUTE);
E 17
I 17
		dst = ifp->int_flags & IFF_BROADCAST ? &ifp->int_broadaddr :
		      ifp->int_flags & IFF_POINTOPOINT ? &ifp->int_dstaddr :
		      &ifp->int_addr;
		(*f)(dst, ifp->int_flags & IFF_INTERFACE);
E 17
E 16
E 15
E 14
	}
D 17
	if (doinghost) {
		base = nethash;
		doinghost = 0;
		goto again;
	}
E 17
}

D 15
/*
 * Supply routing information to target "sa".
 */
D 14
supply(sa)
E 14
I 14
supply(s, sa)
	int s;
E 15
I 15
D 16
sendmsg(rt, dst)
	register struct rt_entry *rt;
E 16
I 16
/*ARGSUSED*/
sendmsg(dst, dontroute)
E 16
	struct sockaddr *dst;
I 16
	int dontroute;
E 16
{
D 16

E 16
	(*afswitch[dst->sa_family].af_output)(s, dst, sizeof (struct rip));
}

I 19
/*
 * Supply dst with the contents of the routing tables.
 * If this won't fit in one packet, chop it up into several.
 */
E 19
D 16
supply(rt, sa)
	register struct rt_entry *rt;
E 15
E 14
	struct sockaddr *sa;
E 16
I 16
supply(dst, dontroute)
	struct sockaddr *dst;
	int dontroute;
E 16
{
I 16
	register struct rt_entry *rt;
E 16
D 15
	struct rip *msg = (struct rip *)packet;
E 15
	struct netinfo *n = msg->rip_nets;
D 6
	register struct rt_hash *rh;
E 6
I 6
	register struct rthash *rh;
E 6
D 15
	register struct rt_entry *rt;
E 15
D 6
	struct rt_hash *base = hosthash;
E 6
I 6
	struct rthash *base = hosthash;
E 6
D 3
	int space = MAXPACKETSIZE - sizeof (int), doinghost = 1;
E 3
I 3
	int doinghost = 1, size;
E 3
D 16
	int (*output)() = afswitch[sa->sa_family].af_output;
I 15
	int sto = (rt->rt_state&RTS_INTERFACE) ? snoroute : s;
E 16
I 16
	int (*output)() = afswitch[dst->sa_family].af_output;
	int sto = dontroute ? snoroute : s;
E 16
E 15

I 18
	msg->rip_cmd = RIPCMD_RESPONSE;
E 18
I 15
D 16
	log("supply", rt);
E 15
	msg->rip_cmd = RIPCMD_RESPONSE;
E 16
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++)
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
I 16
D 17
		if (rt->rt_state & RTS_HIDDEN)
			continue;
E 17
E 16
D 15

		/*
		 * Flush packet out if not enough room for
		 * another routing table entry.
		 */
E 15
D 3
		if (space < sizeof (struct netinfo)) {
			(*output)(sa, MAXPACKETSIZE - space);
			space = MAXPACKETSIZE - sizeof (int);
E 3
I 3
		size = (char *)n - packet;
		if (size > MAXPACKETSIZE - sizeof (struct netinfo)) {
D 14
			(*output)(sa, size);
E 14
I 14
D 15
			(*output)(s, sa, size);
E 15
I 15
D 16
			(*output)(sto, sa, size);
E 16
I 16
			(*output)(sto, dst, size);
E 16
E 15
E 14
E 3
			n = msg->rip_nets;
		}
		n->rip_dst = rt->rt_dst;
D 3
		n->rip_metric = rt->rt_metric + 1;
		n++, space -= sizeof (struct netinfo);
E 3
I 3
		n->rip_metric = min(rt->rt_metric + 1, HOPCNT_INFINITY);
		n++;
E 3
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
D 3

	if (space < MAXPACKETSIZE - sizeof (int))
		(*output)(sa, MAXPACKETSIZE - space);
E 3
I 3
	if (n != msg->rip_nets)
D 14
		(*output)(sa, (char *)n - packet);
E 14
I 14
D 15
		(*output)(s, sa, (char *)n - packet);
E 15
I 15
D 16
		(*output)(sto, sa, (char *)n - packet);
E 16
I 16
		(*output)(sto, dst, (char *)n - packet);
E 16
E 15
E 14
E 3
}

D 3
getall(rt)
	struct rt_entry *rt;
{
	register struct rip *msg = (struct rip *)packet;
	struct sockaddr *dst;

	msg->rip_cmd = RIPCMD_REQUEST;
	msg->rip_nets[0].rip_dst.sa_family = AF_UNSPEC;
	msg->rip_nets[0].rip_metric = HOPCNT_INFINITY;
	if (rt->rt_ifp && (rt->rt_ifp->if_flags & IFF_BROADCAST))
		dst = &rt->rt_ifp->if_broadaddr;
	else
		dst = &rt->rt_gateway;
	(*afswitch[dst->sa_family].af_output)(dst, sizeof (struct rip));
}

E 3
/*
D 16
 * Respond to a routing info request.
 */
rip_respond(from, size)
	struct sockaddr *from;
	int size;
{
D 15
	register struct rip *msg = (struct rip *)packet;
E 15
	struct netinfo *np = msg->rip_nets;
	struct rt_entry *rt;
	int newsize = 0;
	
D 3
	size -= sizeof (int);
E 3
I 3
	size -= 4 * sizeof (char);
E 3
	while (size > 0) {
		if (size < sizeof (struct netinfo))
			break;
		size -= sizeof (struct netinfo);
		if (np->rip_dst.sa_family == AF_UNSPEC &&
		    np->rip_metric == HOPCNT_INFINITY && size == 0) {
D 14
			supply(from);
E 14
I 14
			supply(s, from);
E 14
			return;
		}
		rt = rtlookup(&np->rip_dst);
D 3
		np->rip_metric = rt == 0 ? HOPCNT_INFINITY : rt->rt_metric + 1;
E 3
I 3
		np->rip_metric = rt == 0 ?
			HOPCNT_INFINITY : min(rt->rt_metric+1, HOPCNT_INFINITY);
E 3
		np++, newsize += sizeof (struct netinfo);
	}
	if (newsize > 0) {
		msg->rip_cmd = RIPCMD_RESPONSE;
		newsize += sizeof (int);
D 14
		(*afswitch[from->sa_family].af_output)(from, newsize);
E 14
I 14
		(*afswitch[from->sa_family].af_output)(s, from, newsize);
E 14
	}
}

/*
E 16
 * Handle an incoming routing packet.
 */
rip_input(from, size)
	struct sockaddr *from;
	int size;
{
D 15
	register struct rip *msg = (struct rip *)packet;
E 15
	struct rt_entry *rt;
	struct netinfo *n;
I 15
D 17
	struct ifnet *ifp;
E 17
I 17
	struct interface *ifp;
E 17
	time_t t;
I 16
	int newsize;
	struct afswitch *afp;
E 16
E 15

I 16
	if (trace) {
		if (msg->rip_cmd < RIPCMD_MAX)
			printf("%s from %x\n", ripcmds[msg->rip_cmd], 
			    ((struct sockaddr_in *)from)->sin_addr);
		else
			printf("%x from %x\n", msg->rip_cmd,
			    ((struct sockaddr_in *)from)->sin_addr);
	}
	if (from->sa_family >= AF_MAX)
		return;
	afp = &afswitch[from->sa_family];
E 16
D 7
	if (msg->rip_cmd != RIPCMD_RESPONSE &&
	    msg->rip_cmd != RIPCMD_REQUEST)
		return;
E 7
I 7
	switch (msg->rip_cmd) {
E 7

D 3
	/*
	 * The router port is in the lower 1K of the UDP port space,
	 * and so is priviledged.  Hence we can "authenticate" incoming
	 * updates simply by checking the source port.
	 */
E 3
D 7
	if (msg->rip_cmd == RIPCMD_RESPONSE &&
	    (*afswitch[from->sa_family].af_portmatch)(from) == 0)
E 7
I 7
D 16
	default:
E 7
		return;
D 7
	if (msg->rip_cmd == RIPCMD_REQUEST) {
E 7
I 7

E 16
	case RIPCMD_REQUEST:
I 19
D 20
		if (!supplier)
			return;
E 20
E 19
E 7
D 16
		rip_respond(from, size);
E 16
I 16
		newsize = 0;
		size -= 4 * sizeof (char);
		n = msg->rip_nets;
		while (size > 0) {
			if (size < sizeof (struct netinfo))
				break;
			size -= sizeof (struct netinfo);

			/* 
			 * A single entry with sa_family == AF_UNSPEC and
			 * metric ``infinity'' means ``all routes''.
			 */
			if (n->rip_dst.sa_family == AF_UNSPEC &&
			    n->rip_metric == HOPCNT_INFINITY && size == 0) {
D 18
				supply(from, 0);	/* don't route */
E 18
I 18
				supply(from, 0);
E 18
				return;
			}
			rt = rtlookup(&n->rip_dst);
			n->rip_metric = rt == 0 ? HOPCNT_INFINITY :
				min(rt->rt_metric+1, HOPCNT_INFINITY);
			n++, newsize += sizeof (struct netinfo);
		}
		if (newsize > 0) {
			msg->rip_cmd = RIPCMD_RESPONSE;
			newsize += sizeof (int);
			(*afp->af_output)(s, from, newsize);
		}
E 16
		return;
I 7

D 13
	case RIPCMD_RESPONSE:
E 13
I 13
	case RIPCMD_TRACEON:
D 15
	case RIPCMD_TRACEOFF:
E 13
		/* verify message came from a priviledged port */
E 15
I 13
D 16
		if ((*afswitch[from->sa_family].af_portcheck)(from) == 0)
E 16
I 16
		if ((*afp->af_portcheck)(from) == 0)
E 16
			return;
D 15
		tracecmd(msg->rip_cmd, msg, size);
		return;

	case RIPCMD_RESPONSE:
		/* verify message came from a router */
E 13
		if ((*afswitch[from->sa_family].af_portmatch)(from) == 0)
E 15
I 15
		if (trace)
E 15
			return;
D 15
		break;
E 7
	}

	/*
	 * Process updates.
	 * Extraneous information like Internet ports
	 * must first be purged from the sender's address for
	 * pattern matching below.
	 */
	(*afswitch[from->sa_family].af_canon)(from);
	if (trace)
D 6
		printf("input from %x\n", from->sin_addr);
E 6
I 6
		printf("input from %x\n",
			((struct sockaddr_in *)from)->sin_addr);
E 6
	/*
	 * If response packet is from ourselves, use it only
	 * to reset timer on entry.  Otherwise, we'd believe
	 * it as gospel (since it comes from the router) and
	 * unknowingly update the metric to show the outgoing
	 * cost (higher than our real cost).  I guess the protocol
	 * spec doesn't address this because Xerox Ethernets
	 * don't hear their own broadcasts?
	 */
	if (if_ifwithaddr(from)) {
D 12
		rt = rtlookup(from);
E 12
I 12
		rt = rtfind(from);
E 12
		if (rt)
			rt->rt_timer = 0;
E 15
I 15
		packet[size] = '\0';
		ftrace = fopen(msg->rip_tracefile, "a");
		if (ftrace == NULL)
			return;
		(void) dup2(fileno(ftrace), 1);
		(void) dup2(fileno(ftrace), 2);
		trace = 1;
		t = time(0);
		printf("*** Tracing turned on at %.24s ***\n", ctime(&t));
E 15
		return;
D 15
	}
D 3
	size -= sizeof (int);
E 3
I 3
	size -= 4 * sizeof (char);
E 3
	n = msg->rip_nets;
	for (; size > 0; size -= sizeof (struct netinfo), n++) {
		if (size < sizeof (struct netinfo))
			break;
		if (trace)
D 6
			printf("dst %x hc %d...", n->rip_dst.sin_addr,
E 6
I 6
			printf("dst %x hc %d...",
				((struct sockaddr_in *)&n->rip_dst)->sin_addr,
E 6
				n->rip_metric);
		rt = rtlookup(&n->rip_dst);
E 15

D 15
		/*
		 * Unknown entry, add it to the tables only if
		 * its interesting.
		 */
		if (rt == 0) {
			if (n->rip_metric < HOPCNT_INFINITY)
				rtadd(&n->rip_dst, from, n->rip_metric);
			if (trace)
				printf("new\n");
			continue;
		}

		if (trace)
			printf("ours: gate %x hc %d timer %d\n",
D 6
			rt->rt_gateway.sin_addr,
			rt->rt_metric, rt->rt_timer);
E 6
I 6
D 14
			  ((struct sockaddr_in *)&rt->rt_gateway)->sin_addr,
E 14
I 14
			  ((struct sockaddr_in *)&rt->rt_router)->sin_addr,
E 14
			  rt->rt_metric, rt->rt_timer);
E 6
		/*
		 * Update the entry if one of the following is true:
		 *
		 * (1) The update came directly from the gateway.
		 * (2) A shorter path is provided.
		 * (3) The entry hasn't been updated in a while
D 3
		 *     and a path of equivalent cost is offered.
E 3
I 3
		 *     and a path of equivalent cost is offered
		 *     (with the cost finite).
E 3
		 */
D 14
		if (equal(from, &rt->rt_gateway) ||
E 14
I 14
		if (equal(from, &rt->rt_router) ||
E 14
		    rt->rt_metric > n->rip_metric ||
		    (rt->rt_timer > (EXPIRE_TIME/2) &&
D 3
		    rt->rt_metric == n->rip_metric)) {
E 3
I 3
		    rt->rt_metric == n->rip_metric &&
		    rt->rt_metric < HOPCNT_INFINITY)) {
E 3
			rtchange(rt, from, n->rip_metric);
			rt->rt_timer = 0;
		}
	}
I 13
}

/*
 * Handle tracing requests.
 */
tracecmd(cmd, msg, size)
	int cmd, size;
	struct rip *msg;
{
	time_t t;

	if (cmd == RIPCMD_TRACEOFF) {
E 15
I 15
	case RIPCMD_TRACEOFF:
		/* verify message came from a priviledged port */
D 16
		if ((*afswitch[from->sa_family].af_portcheck)(from) == 0)
E 16
I 16
		if ((*afp->af_portcheck)(from) == 0)
E 16
			return;
E 15
		if (!trace)
			return;
		t = time(0);
		printf("*** Tracing turned off at %.24s ***\n", ctime(&t));
		fflush(stdout), fflush(stderr);
		if (ftrace)
			fclose(ftrace);
		(void) close(1), (void) close(2);
		trace = 0;
		return;
D 15
	}
	if (trace)
E 15
I 15

	case RIPCMD_RESPONSE:
		/* verify message came from a router */
D 16
		if ((*afswitch[from->sa_family].af_portmatch)(from) == 0)
E 16
I 16
		if ((*afp->af_portmatch)(from) == 0)
E 16
			return;
D 16
		(*afswitch[from->sa_family].af_canon)(from);
		tprintf("input from %x\n",
		    ((struct sockaddr_in *)from)->sin_addr);
E 16
I 16
		(*afp->af_canon)(from);
E 16
		/* are we talking to ourselves? */
		ifp = if_ifwithaddr(from);
		if (ifp) {
D 16
			rt = rtfind(from);
			if (rt)
				rt->rt_timer = 0;
			else
E 16
I 16
D 17
			rt = rtfind(from, 0);
			if (rt == 0) {
E 17
I 17
			rt = rtfind(from);
			if (rt == 0)
E 17
E 16
				addrouteforif(ifp);
I 16
D 17
				return;
			}
			/* interface previously thought down? */
			if (rt->rt_metric > 0) {
				struct rt_entry *downrt = rtfind(from, 1);
				if (downrt) {
					/* unhide old route and delete other */
					downrt->rt_state &= ~RTS_HIDDEN;
					downrt->rt_state |= RTS_ADDRT;
					rt->rt_state |= RTS_DELRT;
					log("unhide", downrt);
				}
			}
			rt->rt_timer = 0;
E 17
I 17
			else
				rt->rt_timer = 0;
E 17
E 16
			return;
		}
		size -= 4 * sizeof (char);
		n = msg->rip_nets;
		for (; size > 0; size -= sizeof (struct netinfo), n++) {
			if (size < sizeof (struct netinfo))
				break;
			if (n->rip_metric >= HOPCNT_INFINITY)
				continue;
			tprintf("dst %x hc %d...",
			    ((struct sockaddr_in *)&n->rip_dst)->sin_addr,
			    n->rip_metric);
			rt = rtlookup(&n->rip_dst);
			if (rt == 0) {
				rtadd(&n->rip_dst, from, n->rip_metric, 0);
D 16
				tprintf("new\n");
E 16
				continue;
			}
			tprintf("ours: gate %x hc %d timer %d\n",
			  ((struct sockaddr_in *)&rt->rt_router)->sin_addr,
			  rt->rt_metric, rt->rt_timer);
I 16

E 16
			/*
D 16
			 * update if from gateway, shorter, or getting stale
			 * and equivalent.
E 16
I 16
D 19
			 * update if from gateway, shorter, or getting
E 19
I 19
			 * Update if from gateway, shorter, or getting
E 19
			 * stale and equivalent.
E 16
			 */
			if (equal(from, &rt->rt_router) ||
			    n->rip_metric < rt->rt_metric ||
			    (rt->rt_timer > (EXPIRE_TIME/2) &&
			    rt->rt_metric == n->rip_metric)) {
				rtchange(rt, from, n->rip_metric);
				rt->rt_timer = 0;
			}
		}
E 15
		return;
D 15
	packet[size] = '\0';
	ftrace = fopen(msg->rip_tracefile, "a");
	if (ftrace == NULL)
		return;
	(void) dup2(fileno(ftrace), 1);
	(void) dup2(fileno(ftrace), 2);
	trace = 1;
	t = time(0);
	printf("*** Tracing turned on at %.24s ***\n", ctime(&t));
E 15
I 15
	}
I 16
D 17
	printf("bad packet, cmd=%x\n", msg->rip_cmd);
E 17
I 17
	tprintf("bad packet, cmd=%x\n", msg->rip_cmd);
E 17
E 16
E 15
E 13
}

I 19
/*
 * Lookup dst in the tables for an exact match.
 */
E 19
I 6
D 15
rtinit()
{
	register struct rthash *rh;

	for (rh = nethash; rh < &nethash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
	for (rh = hosthash; rh < &hosthash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
}

E 6
/*
 * Lookup an entry to the appropriate dstination.
 */
E 15
struct rt_entry *
rtlookup(dst)
	struct sockaddr *dst;
{
	register struct rt_entry *rt;
D 6
	register struct rt_hash *rh;
E 6
I 6
	register struct rthash *rh;
E 6
D 12
	register int hash, (*match)();
E 12
I 12
	register int hash;
E 12
	struct afhash h;
D 12
	int af = dst->sa_family, doinghost = 1;
E 12
I 12
	int doinghost = 1;
E 12

I 12
	if (dst->sa_family >= AF_MAX)
		return (0);
	(*afswitch[dst->sa_family].af_hash)(dst, &h);
	hash = h.afh_hosthash;
	rh = &hosthash[hash % ROUTEHASHSIZ];
again:
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
D 16
		if (rt->rt_hash != hash)
E 16
I 16
D 17
		if (rt->rt_hash != hash || (rt->rt_state & RTS_HIDDEN))
E 17
I 17
		if (rt->rt_hash != hash)
E 17
E 16
			continue;
		if (equal(&rt->rt_dst, dst))
			return (rt);
	}
	if (doinghost) {
		doinghost = 0;
		hash = h.afh_nethash;
		rh = &nethash[hash % ROUTEHASHSIZ];
		goto again;
	}
	return (0);
}

I 19
/*
 * Find a route to dst as the kernel would.
 */
E 19
D 15
/*
 * Find an entry based on address "dst", as the kernel
 * does in selecting routes.  This means we look first
 * for a point to point link, settling for a route to
 * the destination network if the former fails.
 */
E 15
struct rt_entry *
D 16
rtfind(dst)
E 16
I 16
D 17
rtfind(dst, lookfordownif)
E 17
I 17
rtfind(dst)
E 17
E 16
	struct sockaddr *dst;
I 16
D 17
	int lookfordownif;
E 17
E 16
{
	register struct rt_entry *rt;
	register struct rthash *rh;
	register int hash;
	struct afhash h;
	int af = dst->sa_family;
	int doinghost = 1, (*match)();

E 12
	if (af >= AF_MAX)
		return (0);
	(*afswitch[af].af_hash)(dst, &h);
	hash = h.afh_hosthash;
	rh = &hosthash[hash % ROUTEHASHSIZ];

again:
	for (rt = rh->rt_forw; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {
		if (rt->rt_hash != hash)
			continue;
I 16
D 17
		if (lookfordownif ^ (rt->rt_state & RTS_HIDDEN))
			continue;
E 17
E 16
		if (doinghost) {
			if (equal(&rt->rt_dst, dst))
				return (rt);
		} else {
			if (rt->rt_dst.sa_family == af &&
			    (*match)(&rt->rt_dst, dst))
				return (rt);
		}
	}
	if (doinghost) {
		doinghost = 0;
		hash = h.afh_nethash;
D 12
		match = afswitch[af].af_netmatch;
E 12
		rh = &nethash[hash % ROUTEHASHSIZ];
I 12
		match = afswitch[af].af_netmatch;
E 12
		goto again;
	}
	return (0);
}

D 6
rtinit()
{
	register struct rt_hash *rh;

	for (rh = nethash; rh < &nethash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
	for (rh = hosthash; rh < &hosthash[ROUTEHASHSIZ]; rh++)
		rh->rt_forw = rh->rt_back = (struct rt_entry *)rh;
}

E 6
D 15
/*
 * Add a new entry.
 */
rtadd(dst, gate, metric)
E 15
I 15
D 16
rtadd(dst, gate, metric, iflags)
E 16
I 16
rtadd(dst, gate, metric, state)
E 16
E 15
	struct sockaddr *dst, *gate;
D 15
	short metric;
E 15
I 15
D 16
	int metric, iflags;
E 16
I 16
	int metric, state;
E 16
E 15
{
	struct afhash h;
	register struct rt_entry *rt;
D 6
	struct rt_hash *rh;
E 6
I 6
	struct rthash *rh;
E 6
	int af = dst->sa_family, flags, hash;

	if (af >= AF_MAX)
		return;
	(*afswitch[af].af_hash)(dst, &h);
	flags = (*afswitch[af].af_checkhost)(dst) ? RTF_HOST : 0;
	if (flags & RTF_HOST) {
		hash = h.afh_hosthash;
		rh = &hosthash[hash % ROUTEHASHSIZ];
	} else {
		hash = h.afh_nethash;
		rh = &nethash[hash % ROUTEHASHSIZ];
	}
	rt = (struct rt_entry *)malloc(sizeof (*rt));
	if (rt == 0)
		return;
	rt->rt_hash = hash;
	rt->rt_dst = *dst;
D 14
	rt->rt_gateway = *gate;
E 14
I 14
	rt->rt_router = *gate;
E 14
	rt->rt_metric = metric;
	rt->rt_timer = 0;
D 15
	rt->rt_flags = RTF_UP | flags;
E 15
I 15
D 16
	rt->rt_flags = RTF_UP | flags | iflags;
E 15
I 7
	rt->rt_state = 0;
E 16
I 16
	rt->rt_flags = RTF_UP | flags;
D 17
	rt->rt_state = state;
E 17
I 17
	rt->rt_state = state | RTS_CHANGED;
E 17
E 16
E 7
D 14
	rt->rt_ifp = if_ifwithnet(&rt->rt_gateway);
	if (metric == 0)
		rt->rt_flags |= RTF_DIRECT;
E 14
I 14
	rt->rt_ifp = if_ifwithnet(&rt->rt_router);
	if (metric)
		rt->rt_flags |= RTF_GATEWAY;
E 14
	insque(rt, rh);
D 3
	if (trace)
		log("add", rt);
E 3
I 3
	log("add", rt);
E 3
D 14
	if (initializing)
		return;
	if (supplier)
		broadcast(rt);
	if (install) {
E 14
I 14
D 17
	if (install)
E 14
D 7
		rt->rt_flags |= RTF_ADDRT;
E 7
I 7
		rt->rt_state |= RTS_ADDRT;
E 17
I 17
	if (install && ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
		tprintf("SIOCADDRT: %s\n", sys_errlist[errno]);
E 17
E 7
D 14
		rt->rt_retry = EXPIRE_TIME/TIMER_RATE;
	}
E 14
}

D 15
/*
 * Look to see if a change to an existing entry
 * is warranted; if so, make it.
 */
E 15
rtchange(rt, gate, metric)
	struct rt_entry *rt;
	struct sockaddr *gate;
	short metric;
{
D 16
	int change = 0;
E 16
I 16
	int doioctl = 0, metricchanged = 0;
I 17
	struct rtentry oldroute;
E 17
E 16

D 14
	if (!equal(&rt->rt_gateway, gate)) {
		rt->rt_gateway = *gate;
E 14
I 14
D 17
	if (!equal(&rt->rt_router, gate)) {
D 16
		rt->rt_newrouter = *gate;
E 14
		change++;
E 16
I 16
		if (rt->rt_state & RTS_DONTDELETE) {
			rtadd(&rt->rt_dst, gate, metric,
			   rt->rt_state &~ (RTS_DONTDELETE|RTS_DONTROUTE));
			rt->rt_state |= RTS_DELRT;
			return;
		}
E 17
I 17
	if (!equal(&rt->rt_router, gate))
E 17
		doioctl++;
E 16
D 17
	}
E 17
D 14

	/*
	 * If the hop count has changed, adjust
	 * the flags in the routing table entry accordingly.
	 */
E 14
	if (metric != rt->rt_metric) {
D 14
		if (rt->rt_metric == 0)
			rt->rt_flags &= ~RTF_DIRECT;
E 14
I 14
D 16
		if (metric == 0)
			rt->rt_flags |= RTF_GATEWAY;
E 16
I 16
		metricchanged++;
E 16
E 14
		rt->rt_metric = metric;
D 14
		if (metric >= HOPCNT_INFINITY)
			rt->rt_flags &= ~RTF_UP;
		else
			rt->rt_flags |= RTF_UP;
E 14
D 16
		change++;
E 16
	}
I 17
	if (doioctl || metricchanged) {
		log("change", rt);
		rt->rt_state |= RTS_CHANGED;
	}
E 17
D 14

E 14
D 16
	if (!change)
		return;
D 14
	if (supplier)
		broadcast(rt);
E 14
D 3
	if (trace)
		log("change", rt);
E 3
I 3
	log("change", rt);
E 3
D 14
	if (install) {
E 14
I 14
	if (install)
E 16
I 16
	if (doioctl) {
D 17
		if ((rt->rt_state & RTS_CHGRT) == 0)
			rt->rt_oldrouter = rt->rt_router;
E 17
I 17
		oldroute = rt->rt_rt;
E 17
		rt->rt_router = *gate;
E 16
E 14
D 7
		rt->rt_flags |= RTF_CHGRT;
E 7
I 7
D 17
		rt->rt_state |= RTS_CHGRT;
E 17
I 17
		if (install) {
			if (ioctl(s, SIOCADDRT, (char *)&rt->rt_rt) < 0)
				tprintf("SIOCADDRT: %s\n", sys_errlist[errno]);
			if (ioctl(s, SIOCDELRT, (char *)&oldroute) < 0)
				tprintf("SIOCDELRT: %s\n", sys_errlist[errno]);
		}
E 17
I 16
	}
D 17
	if (doioctl || metricchanged)
		log("change", rt);
E 17
E 16
E 7
D 14
		rt->rt_retry = EXPIRE_TIME/TIMER_RATE;
	}
E 14
}

D 15
/*
 * Delete a routing table entry.
 */
E 15
rtdelete(rt)
	struct rt_entry *rt;
{
I 15
D 17

E 17
E 15
D 3
	if (trace)
		log("delete", rt);
E 3
I 3
	log("delete", rt);
E 3
D 14
	if (install)
D 6
		if (ioctl(s, SIOCDELRT, (char *)&rt->rt_hash) &&
E 6
I 6
		if (ioctl(s, SIOCDELRT, (char *)&rt->rt_rt) &&
E 6
		  errno == EBUSY)
D 7
			rt->rt_flags |= RTF_DELRT;
E 7
I 7
			rt->rt_state |= RTS_DELRT;
E 14
I 14
	if (install && ioctl(s, SIOCDELRT, (char *)&rt->rt_rt))
D 17
		perror("SIOCDELRT");
D 16
	/* don't delete interface entries so we can poll them later */
	if (rt->rt_state & RTS_INTERFACE)
E 16
I 16
	if (rt->rt_state & RTS_DONTDELETE) {
		rt->rt_state |= RTS_HIDDEN;
E 16
		return;
I 16
	}
E 17
I 17
		tprintf("SIOCDELRT: %s\n", sys_errlist[errno]);
E 17
E 16
E 14
E 7
	remque(rt);
	free((char *)rt);
}

D 3
/*
 * Timer routine:
 *
 * o handle timers on table entries,
 * o invalidate entries which haven't been updated in a while,
 * o delete entries which are too old,
 * o retry ioctl's which weren't successful the first
 *   time due to the kernel entry being busy
 * o if we're an internetwork router, supply routing updates
 *   periodically
 */
timer()
{
	register struct rt_hash *rh;
	register struct rt_entry *rt;
	struct rt_hash *base = hosthash;
	int doinghost = 1;

	if (trace)
		printf(">>> time %d >>>\n", timeval);
again:
	for (rh = base; rh < &base[ROUTEHASHSIZ]; rh++) {
		rt = rh->rt_forw;
		for (; rt != (struct rt_entry *)rh; rt = rt->rt_forw) {

			/*
			 * If the host is indicated to be
			 * "silent" (i.e. it's a logical host,
			 * or one we got from the initialization
			 * file), don't time out it's entry.
			 */
			if (rt->rt_flags & RTF_SILENT)
				continue;
			if (trace)
				log("", rt);
			rt->rt_timer += TIMER_RATE;
			if (rt->rt_timer >= GARBAGE_TIME ||
			  (rt->rt_flags & RTF_DELRT)) {
				rt = rt->rt_forw;
				rtdelete(rt->rt_back);
				rt = rt->rt_back;
				continue;
			}
			if (rt->rt_timer >= EXPIRE_TIME)
				rt->rt_metric = HOPCNT_INFINITY;
			if (rt->rt_flags & RTF_CHGRT)
				if (!ioctl(s, SIOCCHGRT,(char *)&rt->rt_hash) ||
				  --rt->rt_retry == 0)
					rt->rt_flags &= ~RTF_CHGRT;
			if (rt->rt_flags & RTF_ADDRT)
				if (!ioctl(s, SIOCADDRT,(char *)&rt->rt_hash) ||
				  --rt->rt_retry == 0)
					rt->rt_flags &= ~RTF_ADDRT;
		}
	}
	if (doinghost) {
		doinghost = 0;
		base = nethash;
		goto again;
	}
	timeval += TIMER_RATE;
	if (supplier && (timeval % SUPPLY_INTERVAL) == 0)
		supplyall();
	if (trace)
		printf("<<< time %d <<<\n", timeval);
	alarm(TIMER_RATE);
}

E 3
log(operation, rt)
	char *operation;
	struct rt_entry *rt;
{
D 16
	time_t t = time(0);
E 16
	struct sockaddr_in *dst, *gate;
D 7
	static struct flagbits {
E 7
I 7
	static struct bits {
E 7
		int	t_bits;
		char	*t_name;
D 7
	} bits[] = {
E 7
I 7
	} flagbits[] = {
E 7
		{ RTF_UP,	"UP" },
D 14
		{ RTF_DIRECT,	"DIRECT" },
E 14
I 14
		{ RTF_GATEWAY,	"GATEWAY" },
E 14
		{ RTF_HOST,	"HOST" },
D 7
		{ RTF_DELRT,	"DELETE" },
		{ RTF_CHGRT,	"CHANGE" },
		{ RTF_SILENT,	"SILENT" },
E 7
		{ 0 }
I 7
	}, statebits[] = {
I 16
D 17
		{ RTS_ADDRT,	"ADD" },
E 16
		{ RTS_DELRT,	"DELETE" },
		{ RTS_CHGRT,	"CHANGE" },
E 17
D 11
		{ RTS_SILENT,	"SILENT" },
E 11
I 11
D 14
		{ RTS_HIDDEN,	"HIDDEN" },
E 14
I 14
		{ RTS_PASSIVE,	"PASSIVE" },
D 16
		{ RTS_INTERFACE,"INTERFACE" },
I 15
		{ RTS_GLOBAL,	"GLOBAL" },
E 16
I 16
D 17
		{ RTS_DONTDELETE,"DONTDELETE" },
		{ RTS_DONTROUTE,"DONTROUTE" },
		{ RTS_HIDDEN,	"HIDDEN" },
E 17
I 17
		{ RTS_REMOTE,	"REMOTE" },
		{ RTS_INTERFACE,"INTERFACE" },
		{ RTS_CHANGED,	"CHANGED" },
E 17
E 16
E 15
E 14
E 11
		{ 0 }
E 7
	};
D 7
	register struct flagbits *p;
E 7
I 7
	register struct bits *p;
E 7
	register int first;
	char *cp;

I 3
	if (trace == 0)
		return;
E 3
	printf("%s ", operation);
	dst = (struct sockaddr_in *)&rt->rt_dst;
D 14
	gate = (struct sockaddr_in *)&rt->rt_gateway;
E 14
I 14
	gate = (struct sockaddr_in *)&rt->rt_router;
E 14
D 7
	printf("dst %x, router %x, metric %d, flags ",
E 7
I 7
D 16
	printf("dst %x, router %x, metric %d, flags",
E 7
		dst->sin_addr, gate->sin_addr, rt->rt_metric);
E 16
I 16
D 17
	printf("dst %x, router %x", dst->sin_addr, gate->sin_addr);
	if (rt->rt_state & RTS_CHGRT)
		printf(" (old %x)",
			((struct sockaddr_in *)&rt->rt_oldrouter)->sin_addr);
	printf(", metric %d, flags", rt->rt_metric);
E 17
I 17
	printf("dst %x, router %x, metric %d, flags", dst->sin_addr,
		gate->sin_addr, rt->rt_metric);
E 17
E 16
D 7
	cp = "%s";
	for (first = 1, p = bits; p->t_bits > 0; p++) {
E 7
I 7
	cp = " %s";
	for (first = 1, p = flagbits; p->t_bits > 0; p++) {
E 7
		if ((rt->rt_flags & p->t_bits) == 0)
I 7
			continue;
		printf(cp, p->t_name);
		if (first) {
			cp = "|%s";
			first = 0;
		}
	}
	printf(" state");
	cp = " %s";
	for (first = 1, p = statebits; p->t_bits > 0; p++) {
		if ((rt->rt_state & p->t_bits) == 0)
E 7
			continue;
		printf(cp, p->t_name);
		if (first) {
			cp = "|%s";
			first = 0;
		}
	}
	putchar('\n');
I 3
}

I 6
D 15
/*
 * Find the interface with address "addr".
 */
E 15
E 6
D 17
struct ifnet *
E 17
I 17
struct interface *
E 17
if_ifwithaddr(addr)
	struct sockaddr *addr;
{
D 17
	register struct ifnet *ifp;
E 17
I 17
	register struct interface *ifp;
E 17

#define	same(a1, a2) \
	(bcmp((caddr_t)((a1)->sa_data), (caddr_t)((a2)->sa_data), 14) == 0)
D 17
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != addr->sa_family)
E 17
I 17
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_REMOTE)
E 17
			continue;
D 17
		if (same(&ifp->if_addr, addr))
E 17
I 17
		if (ifp->int_addr.sa_family != addr->sa_family)
			continue;
		if (same(&ifp->int_addr, addr))
E 17
			break;
D 17
		if ((ifp->if_flags & IFF_BROADCAST) &&
		    same(&ifp->if_broadaddr, addr))
E 17
I 17
		if ((ifp->int_flags & IFF_BROADCAST) &&
		    same(&ifp->int_broadaddr, addr))
E 17
			break;
	}
	return (ifp);
#undef same
}

I 6
D 15
/*
 * Find the interface with network imbedded in
 * the sockaddr "addr".  Must use per-af routine
 * look for match.
 */
E 15
E 6
D 17
struct ifnet *
E 17
I 17
struct interface *
E 17
if_ifwithnet(addr)
	register struct sockaddr *addr;
{
D 17
	register struct ifnet *ifp;
E 17
I 17
	register struct interface *ifp;
E 17
	register int af = addr->sa_family;
	register int (*netmatch)();

	if (af >= AF_MAX)
		return (0);
	netmatch = afswitch[af].af_netmatch;
D 17
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (af != ifp->if_addr.sa_family)
E 17
I 17
	for (ifp = ifnet; ifp; ifp = ifp->int_next) {
		if (ifp->int_flags & IFF_REMOTE)
E 17
			continue;
D 17
		if ((*netmatch)(addr, &ifp->if_addr))
E 17
I 17
		if (af != ifp->int_addr.sa_family)
			continue;
		if ((*netmatch)(addr, &ifp->int_addr))
E 17
			break;
	}
	return (ifp);
D 26
}

I 6
D 15
/*
 * Formulate an Internet address.
 */
E 15
E 6
struct in_addr
if_makeaddr(net, host)
	int net, host;
{
	u_long addr;

	if (net < 128)
		addr = (net << 24) | host;
	else if (net < 65536)
		addr = (net << 16) | host;
	else
		addr = (net << 8) | host;
D 24
#ifdef vax
E 24
I 24
#if vax || pdp11
E 24
	addr = htonl(addr);
#endif
	return (*(struct in_addr *)&addr);
I 24
}

/*
 * Return the network number from an internet
 * address; handles class a/b/c network #'s.
 */
in_netof(in)
	struct in_addr in;
{
#if vax || pdp11
	register u_long net;

	if ((in.s_addr&IN_CLASSA) == 0)
		return (in.s_addr & IN_CLASSA_NET);
	if ((in.s_addr&IN_CLASSB) == 0)
		return ((int)htons((u_short)(in.s_addr & IN_CLASSB_NET)));
	net = htonl((u_long)(in.s_addr & IN_CLASSC_NET));
	net >>= 8;
	return ((int)net);
#else
	return (IN_NETOF(in));
#endif
}

/*
 * Return the local network address portion of an
 * internet address; handles class a/b/c network
 * number formats.
 */
in_lnaof(in)
	struct in_addr in;
{
#if vax || pdp11
#define	IN_LNAOF(in) \
	(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_LNA : \
		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_LNA : \
			(in).s_addr&IN_CLASSC_LNA)
	return ((int)htonl((u_long)IN_LNAOF(in)));
#else
	return (IN_LNAOF(in));
#endif
E 26
E 24
E 3
}
E 1

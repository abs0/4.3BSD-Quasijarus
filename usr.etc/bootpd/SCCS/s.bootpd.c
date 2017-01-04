h02877
s 00011/00002/01246
d D 5.6 06/02/08 10:08:05 msokolov 6 5
c send all IP numbers in RFC 1048 vendor information in network byte order!
e
s 00001/00001/01247
d D 5.5 05/04/17 06:00:33 msokolov 5 4
c enlarge path[] buffer in request()
c I'm not happy with this, but this is the best I can do without changing
c the whole design philosophy.
e
s 00001/00001/01247
d D 5.4 05/04/17 05:19:28 msokolov 4 3
c d'oh!
e
s 00018/00001/01230
d D 5.3 05/04/17 04:52:50 msokolov 3 2
c security: added some anti-bogon guards
e
s 00016/00102/01215
d D 5.2 05/04/17 04:26:55 msokolov 2 1
c always use syslog
e
s 01317/00000/00000
d D 5.1 05/04/17 04:17:06 msokolov 1 0
c bootpd 2.0 imported into 4.3BSD-Quasijarus
e
u
U
t
T
I 1

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
/* based on bootp.c	1.1 (Stanford) 1/22/86 */
/* based on $Header: bootpd.c,v 1.13 88/11/15 23:49:32 ddp Exp $ */
#endif


/*
 * BOOTP (bootstrap protocol) server daemon.
 *
 * Answers BOOTP request packets from booting client machines.
 * See [SRI-NIC]<RFC>RFC951.TXT for a description of the protocol.
 * See [SRI-NIC]<RFC>RFC1048.TXT for vendor-information extensions.
 * See accompanying man page -- bootpd.8
 *
 *
 * Copyright 1988 by Carnegie Mellon.
 *
 * Permission to use, copy, modify, and distribute this program for any
 * purpose and without fee is hereby granted, provided that this copyright
 * and permission notice appear on all copies and supporting documentation,
 * the name of Carnegie Mellon not be used in advertising or publicity
 * pertaining to distribution of the program without specific prior
 * permission, and notice be given in supporting documentation that copying
 * and distribution is by permission of Carnegie Mellon and Stanford
 * University.  Carnegie Mellon makes no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 *
 * HISTORY
 *
 * 01/22/86	Bill Croft at Stanford University
 *		    Created.
 *
 * 07/30/86     David Kovar at Carnegie Mellon University
 *		    Modified to work at CMU.
 *
 * 07/24/87	Drew D. Perkins at Carnegie Mellon University
 *		    Modified to use syslog instead of Kovar's
 *		    routines.  Add debugging dumps.  Many other fixups.
 *
 * 07/15/88	Walter L. Wimer at Carnegie Mellon University
 *		    Added vendor information to conform to RFC1048.
 *		    Adopted termcap-like file format to support above.
 *		    Added hash table lookup instead of linear search.
 *		    Other cleanups.
 *
 *
 * BUGS
 *
 * Currently mallocs memory in a very haphazard manner.  As such, most of
 * the program ends up core-resident all the time just to follow all the
 * stupid pointers around. . . .
 *
 */




#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/time.h>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include <ctype.h>
#include <netdb.h>
D 2
#ifdef SYSLOG
E 2
#include <syslog.h>
D 2
#endif
E 2
#include "bootp.h"
#include "hash.h"
#include "bootpd.h"

#define HASHTABLESIZE		257	/* Hash table size (prime) */
#define DEFAULT_TIMEOUT		 15L	/* Default timeout in minutes */
#define CONFIG_FILE		"/etc/bootptab"
#define DUMP_FILE		"/etc/bootpd.dump"



/*
 * Externals, forward declarations, and global variables
 */

extern char Version[];
extern char *sys_errlist[];
extern int  errno, sys_nerr;

void usage();
void insert_u_long();
I 6
void insert_net_long();
E 6
void dump_host();
void list_ipaddresses();
void dovend_cmu();
void dovend_rfc1048();
boolean hwlookcmp();
boolean iplookcmp();
void insert_ip();
int timeout_handle();
int dumptab();


/*
 * IP port numbers for client and server obtained from /etc/services
 */

u_short bootps_port, bootpc_port;


/*
 * Internet socket and interface config structures
 */

struct sockaddr_in sin;
struct sockaddr_in from;	/* Packet source */
struct ifreq ifreq[10];		/* Holds interface configuration */
struct ifconf ifconf;		/* Int. config ioctl block (pnts to ifreq) */
struct arpreq arpreq;		/* Arp request ioctl block */


/*
 * General
 */

int debug = 0;			    /* Debugging flag */
int s;				    /* Socket file descriptor */
byte buf[1024];			    /* Receive packet buffer */
int timeoutflag = FALSE;	    /* TRUE if a timeout has occurred */
struct timezone tzp;		    /* Time zone offset for clients */
struct timeval tp;		    /* Time (extra baggage) */
long secondswest;		    /* Time zone offset in seconds */

/*
 * Globals below are associated with the bootp database file (bootptab).
 */

char *bootptab = NULL;
#ifdef DEBUG
char *bootpd_dump = NULL;
#endif



/*
 * Vendor magic cookies for CMU and RFC1048
 */

unsigned char vm_cmu[4]	    = VM_CMU;
unsigned char vm_rfc1048[4] = VM_RFC1048;


/*
 * Hardware address lengths (in bytes) based on hardware type code.
 * List in order specified by Assigned Numbers RFC; Array index is
 * hardware type code.  Entries marked as zero are unknown to the author
 * at this time. . . .
 */

unsigned maphaddrlen[MAXHTYPES + 1] = {
     0,	    /* Type 0:	Reserved (don't use this)   */
     6,	    /* Type 1:  10Mb Ethernet (48 bits)	    */
     1,	    /* Type 2:   3Mb Ethernet (8 bits)	    */
     0,	    /* Type 3:  Amateur Radio AX.25	    */
     1,	    /* Type 4:  Proteon ProNET Token Ring   */
     0,	    /* Type 5:  Chaos			    */
     6,	    /* Type 6:  IEEE 802 Networks	    */
     0	    /* Type 7:  ARCNET			    */
};


/*
 * Main hash tables
 */

hash_tbl *hwhashtable;
hash_tbl *iphashtable;
hash_tbl *nmhashtable;




/*
 * Initialization such as command-line processing is done and then the main
 * server loop is started.
 */

main(argc, argv)
    int argc;
    char **argv;
{
    struct itimerval timeout;
    struct bootp *bp = (struct bootp *) buf;
    struct servent *servp;
    char *stmp;
    int n, tolen, fromlen;
    int standalone;
I 3
    int forwardreplies;
E 3

    stmp = NULL;
    standalone = FALSE;
I 3
    forwardreplies = FALSE;
E 3
    timeout.it_interval.tv_usec = 0L;
    timeout.it_interval.tv_sec  = 0L;
    timeout.it_value.tv_usec = 0L;
    timeout.it_value.tv_sec  = 60 * DEFAULT_TIMEOUT;

    /*
     * Read switches.
     */
    for (argc--, argv++; argc > 0; argc--, argv++) {
	if (argv[0][0] == '-') {
	    switch (argv[0][1]) {
		case 't':
		    if (argv[0][2]) {
			stmp = &(argv[0][2]);
		    } else {
			argc--;
			argv++;
			stmp = argv[0];
		    }
		    if (!stmp || (sscanf(stmp, "%d", &n) != 1) || (n < 0)) {
			fprintf(stderr,
				"bootpd: invalid timeout specification\n");
			break;
		    }
		    timeout.it_value.tv_sec = (long) (60 * n);
		    break;
		case 'd':
		    debug++;
		    break;
		case 's':
		    standalone = TRUE;
		    break;
I 3
		case 'f':
		    forwardreplies = TRUE;
		    break;
E 3
		default:
		    fprintf(stderr,
			    "bootpd: unknown switch: -%c\n",
			    argv[0][1]);
		    usage();
		    break;
	    }
	} else {
	    if (!bootptab) {
		bootptab = argv[0];
#ifdef DEBUG
	    } else if (!bootpd_dump) {
		bootpd_dump = argv[0];
#endif
	    } else {
		fprintf(stderr, "bootpd: unknown argument: %s\n", argv[0]);
		usage();
	    }
	}
    }

    /*
     * Set default file names if not specified on command line
     */
    if (!bootptab) {
	bootptab = CONFIG_FILE;
    }
#ifdef DEBUG
    if (!bootpd_dump) {
	bootpd_dump = DUMP_FILE;
    }
#endif

    /*
     * Get our timezone offset so we can give it to clients if the
     * configuration file doesn't specify one.
     */
    if (gettimeofday(&tp, &tzp) < 0) {
	secondswest = 0L;	/* Assume GMT for lack of anything better */
D 2
	report(LOG_ERR, "gettimeofday: %m\n");
E 2
I 2
	syslog(LOG_ERR, "gettimeofday: %m\n");
E 2
    } else {
	secondswest = 60L * tzp.tz_minuteswest;	    /* Convert to seconds */
    }

    /*
     * Allocate hash tables for hardware address, ip address, and hostname
     */
    hwhashtable = hash_Init(HASHTABLESIZE);
    iphashtable = hash_Init(HASHTABLESIZE);
    nmhashtable = hash_Init(HASHTABLESIZE);
    if (!(hwhashtable && iphashtable && nmhashtable)) {
	fprintf(stderr, "Unable to allocate hash tables.\n");
	exit(1);
    }

    if (standalone) {
	/*
	 * Go into background and disassociate from controlling terminal.
	 */
	if (debug < 3) {
		if (fork())
			exit(0);
		for (n = 0; n < 10; n++)
			(void) close(n);
		(void) open("/", O_RDONLY);
		(void) dup2(0, 1);
		(void) dup2(0, 2);
		n = open("/dev/tty", O_RDWR);
		if (n >= 0) {
			ioctl(n, TIOCNOTTY, (char *) 0);
			(void) close(n);
		}
	}
    }


D 2
#ifdef SYSLOG
E 2
    /*
     * Initialize logging.
     */
D 2
#ifndef LOG_CONS
#define LOG_CONS	0	/* Don't bother if not defined... */
#endif
#ifndef LOG_DAEMON
#define LOG_DAEMON	0
#endif
    openlog("bootpd", LOG_PID | LOG_CONS, LOG_DAEMON);
E 2
I 2
    openlog("bootpd", LOG_PID, LOG_DAEMON);
E 2
    syslog(LOG_INFO, "%s", Version);
D 2
#endif
E 2

    if (standalone) {
	/*
	 * Get us a socket.
	 */
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
D 2
	    report(LOG_ERR, "socket: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "socket: %m\n");
E 2
	    exit(1);
	}

	/*
	 * Get server's listening port number
	 */
	servp = getservbyname("bootps", "udp");
	if (servp) {
	    bootps_port = ntohs((u_short) servp->s_port);
	} else {
D 2
	    report(LOG_ERR,
E 2
I 2
	    syslog(LOG_ERR,
E 2
		   "udp/bootps: unknown service -- assuming port %d\n",
		   IPPORT_BOOTPS);
	    bootps_port = (u_short) IPPORT_BOOTPS;
	}

	/*
	 * Bind socket to BOOTPS port.
	 */
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(bootps_port);
	if (bind(s, &sin, sizeof(sin)) < 0) {
D 2
	    report(LOG_ERR, "bind: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "bind: %m\n");
E 2
	    exit(1);
	}
    } else {
	/*
	 * Assume socket was passed to us from inetd
	 */
	s = 0;
	tolen = sizeof(sin);
	bzero((char *) &sin, tolen);
	if (getsockname(s, &sin, &tolen) < 0) {
D 2
	    report(LOG_ERR, "getsockname: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "getsockname: %m\n");
E 2
	    exit(1);
	}
	bootps_port = ntohs(sin.sin_port);
    }

    /*
     * Get destination port number so we can reply to client
     */
    servp = getservbyname("bootpc", "udp");
    if (servp) {
	bootpc_port = ntohs(servp->s_port);
    } else {
D 2
	report(LOG_ERR,
E 2
I 2
	syslog(LOG_ERR,
E 2
	       "udp/bootpc: unknown service -- assuming port %d\n",
		IPPORT_BOOTPC);
	bootpc_port = (u_short) IPPORT_BOOTPC;
    }


    /*
     * Determine network configuration.
     */
    ifconf.ifc_len = sizeof(ifreq);
    ifconf.ifc_req = ifreq;
    if ((ioctl(s, SIOCGIFCONF, (caddr_t) &ifconf) < 0) ||
	(ifconf.ifc_len <= 0)) {
D 2
	    report(LOG_ERR, "ioctl: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "ioctl: %m\n");
E 2
	    exit(1);
    }

    /*
     * Read the bootptab file once immediately upon startup.
     */
    readtab();

    /*
     * Set up signals for timeout and to read or dump the table.
     */
    if ((int) signal(SIGALRM, timeout_handle) < 0) {
D 2
	report(LOG_ERR, "signal: %m\n");
E 2
I 2
	syslog(LOG_ERR, "signal: %m\n");
E 2
	exit(1);
    }
    if ((int) signal(SIGHUP, readtab) < 0) {
D 2
	report(LOG_ERR, "signal: %m\n");
E 2
I 2
	syslog(LOG_ERR, "signal: %m\n");
E 2
	exit(1);
    }
#ifdef DEBUG
    if ((int) signal(SIGUSR1, dumptab) < 0) {
D 2
	report(LOG_ERR, "signal: %m\n");
E 2
I 2
	syslog(LOG_ERR, "signal: %m\n");
E 2
	exit(1);
    }
#endif

    /*
     * Process incoming requests.
     */
    for (;;) {
	fromlen = sizeof(from);
	n = recvfrom(s, buf, sizeof(buf), 0, &from, &fromlen);
	if (n <= 0) {
	    if (errno == EINTR && timeoutflag) {
D 2
		report(LOG_INFO, "exiting after %ld minutes of inactivity",
E 2
I 2
		syslog(LOG_INFO, "exiting after %ld minutes of inactivity",
E 2
			timeout.it_value.tv_sec / 60);
		exit(0);
	    }
	    continue;
	}

	if (n < sizeof(struct bootp)) {
	    if (debug) {
D 2
#ifdef SYSLOG
E 2
		syslog(LOG_INFO, "received short packet");
D 2
#endif
E 2
	    }
	    continue;
	}

	readtab();	/* maybe re-read bootptab */
	switch (bp->bp_op) {
	    case BOOTREQUEST:
		request();
		break;

	    case BOOTREPLY:
D 3
		reply();
E 3
I 3
		if (forwardreplies)
			reply();
E 3
		break;
	}

	/*
	 * Reset timeout value if we're running from inetd
	 */
	if (!standalone &&
	    (timeout.it_value.tv_sec != 0L) &&
	    setitimer(ITIMER_REAL, &timeout, NULL) < 0) {
D 2
	    report(LOG_ERR, "setitimer: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "setitimer: %m\n");
E 2
	}
    }
}



/*
 * Signal handler for SIGALARM.
 */

int timeout_handle()
{
    timeoutflag = TRUE;
}




/*
 * Print "usage" message and exit
 */

void usage()
{
    fprintf(stderr,
	   "usage:  bootpd [-d] [-s] [-t timeout] [configfile [dumpfile]]\n");
    fprintf(stderr, "\t -d\tincrease debug verbosity\n");
    fprintf(stderr, "\t -s\trun standalone (without inetd)\n");
    fprintf(stderr, "\t -t n\tset inetd exit timeout to n minutes\n");
    exit(1);
}



/*
 * Process BOOTREQUEST packet.
 *
 * (Note, this version of the bootpd.c server never forwards 
 * the request to another server.  In our environment the 
 * stand-alone gateways perform that function.)
 *
 * (Also this version does not interpret the hostname field of
 * the request packet;  it COULD do a name->address lookup and
 * forward the request there.)
 */
request()
{
    register struct bootp *bp = (struct bootp *) buf;
    register struct host *hp;
    register n;
D 5
    char path[64], *file;
E 5
I 5
    char path[256], *file;
E 5
    struct host dummyhost;
    unsigned hlen, hashcode;

    bp->bp_op = BOOTREPLY;
    if (bp->bp_ciaddr.s_addr == 0) { 
	/*
	 * client doesnt know his IP address, 
	 * search by hardware address.
	 */
I 3
	if (bp->bp_htype > MAXHTYPES) {
	    syslog(LOG_ERR, "received request with unknown hw addr type %d",
			bp->bp_htype);
	    return;
	}
E 3
	if (debug) {
D 2
#ifdef SYSLOG
E 2
	    syslog(LOG_INFO, "request from hardware address %s",
		    haddrtoa(bp->bp_chaddr, bp->bp_htype));
D 2
#endif
E 2
	}

	dummyhost.htype = bp->bp_htype;
	hlen = haddrlength(bp->bp_htype);
I 3
D 4
	if (hlen != bp->bp_htype) {
E 4
I 4
	if (hlen != bp->bp_hlen) {
E 4
	    syslog(LOG_ERR,
		"hw addr length does not match hw addr type in request");
	    return;
	}
E 3
	bcopy(bp->bp_chaddr, dummyhost.haddr, hlen);
	hashcode = hash_HashFunction(bp->bp_chaddr, hlen);
	hp = (struct host *) hash_Lookup(hwhashtable, hashcode, hwlookcmp,
					 &dummyhost);
	if (hp == NULL) {
D 2
#ifdef SYSLOG
E 2
	    syslog(LOG_NOTICE, "hardware address not found: %s",
		    haddrtoa(bp->bp_chaddr, bp->bp_htype));
D 2
#endif
E 2
	    return;	/* not found */
	}
	if (debug) {
D 2
#ifdef SYSLOG
E 2
	    syslog(LOG_INFO, "found %s %s", inet_ntoa(hp->iaddr.s_addr),
		    hp->hostname->string);
D 2
#endif
E 2
	}
	(bp->bp_yiaddr).s_addr = hp->iaddr.s_addr;
    } else {

	/*
	 * search by IP address.
	 */
	if (debug) {
D 2
#ifdef SYSLOG
E 2
	    syslog(LOG_INFO, "request from IP addr %s",
		    inet_ntoa(bp->bp_ciaddr));
D 2
#endif
E 2
	}
	dummyhost.iaddr.s_addr = bp->bp_ciaddr.s_addr;
	hashcode = hash_HashFunction(bp->bp_ciaddr.s_addr, 4);
	hp = (struct host *) hash_Lookup(iphashtable, hashcode, iplookcmp,
					 &dummyhost);
	if (hp == NULL) {
D 2
#ifdef SYSLOG
E 2
	    syslog(LOG_NOTICE,
		    "IP address not found: %s", inet_ntoa(bp->bp_ciaddr));
D 2
#endif
E 2
	    return;
	}
    }

    /*
     * Fill in the client's proper bootfile.
     */
I 3
    bp->bp_file[127] = 0;	/* guard against attacks */
E 3
    if (strcmp(bp->bp_file, "sunboot14") == 0)
	bp->bp_file[0] = 0;	/* pretend it's null */

    /*
     * If client specified a bootfile, use it; otherwise use the
     * default file we have listed for him.
     */
    file = (bp->bp_file[0]) ? (char *) bp->bp_file : hp->bootfile->string;

    if (file[0] == '/')	/* if absolute pathname */
	strcpy(path, file);
    else {
	strcpy(path, hp->homedir->string);
	strcat(path, "/");
	strcat(path, file);
    }

    /* try first to find the file with a ".host" suffix */
    n = strlen(path);
    strcat(path, ".");
    strcat(path, hp->hostname->string);
    if (access(path, R_OK) < 0) {
	path[n] = 0;	/* try it without the suffix */
	if (access(path, R_OK) < 0) {
	    if (bp->bp_file[0]) {
		/*
		 * Client wanted specific file
		 * and we didn't have it.
		 */
D 2
#ifdef SYSLOG
E 2
		syslog(LOG_NOTICE, "requested file not found: %s", path);
D 2
#endif
E 2
		return;
	    }
	}
    }
    strcpy(bp->bp_file, path);

    /*
     * Zero the vendor information area, except for the magic cookie.
     */
    bzero((bp->bp_vend) + 4, (sizeof(bp->bp_vend)) - 4);

D 2
#ifdef SYSLOG
E 2
    if (debug > 1) {
	syslog(LOG_INFO, "vendor magic field is %d.%d.%d.%d",
		(int) ((bp->bp_vend)[0]),
		(int) ((bp->bp_vend)[1]),
		(int) ((bp->bp_vend)[2]),
		(int) ((bp->bp_vend)[3]));
    }
D 2
#endif
E 2

    /*
     * If this host isn't set for automatic vendor info then copy the
     * specific cookie into the bootp packet, thus forcing a certain
     * reply format.
     */
    if (!hp->flags.vm_auto) {
	bcopy(hp->vm_cookie, bp->bp_vend, 4);
    }

    /*
     * Figure out the format for the vendor-specific info.
     */
    if (bcmp(bp->bp_vend, vm_rfc1048, 4)) {
	/* Not an RFC1048 bootp client */
#ifdef VEND_CMU
	dovend_cmu(bp, hp);
#else
	dovend_rfc1048(bp, hp);
#endif
    } else {
	/* RFC1048 conformant bootp client */
	dovend_rfc1048(bp, hp);
    }
    sendreply(0);
}



/*
 * Process BOOTREPLY packet (something is using us as a gateway).
 */

reply()
{
	if (debug) {
D 2
#ifdef SYSLOG
E 2
		syslog(LOG_INFO, "processing boot reply");
D 2
#endif
E 2
	}
	sendreply(1);
}


/*
 * Send a reply packet to the client.  'forward' flag is set if we are
 * not the originator of this reply packet.
 */
sendreply(forward)
    int forward;
{
	register struct bootp *bp = (struct bootp *) buf;
	struct in_addr dst;
	struct sockaddr_in to;

	to = sin;

	to.sin_port = htons(bootpc_port);
	/*
	 * If the client IP address is specified, use that
	 * else if gateway IP address is specified, use that
	 * else make a temporary arp cache entry for the client's NEW 
	 * IP/hardware address and use that.
	 */
	if (bp->bp_ciaddr.s_addr) {
		dst = bp->bp_ciaddr;
	} else if (bp->bp_giaddr.s_addr && forward == 0) {
		dst = bp->bp_giaddr;
		to.sin_port = htons(bootps_port);
	} else {
		dst = bp->bp_yiaddr;
		setarp(&dst, bp->bp_chaddr, bp->bp_hlen);
	}

	if (forward == 0) {
		/*
		 * If we are originating this reply, we
		 * need to find our own interface address to
		 * put in the bp_siaddr field of the reply.
		 * If this server is multi-homed, pick the
		 * 'best' interface (the one on the same net
		 * as the client).
		 */
		int maxmatch = 0;
		int len, m;
		register struct ifreq *ifrq, *ifrmax;

		ifrmax = ifrq = &ifreq[0];
		len = ifconf.ifc_len;
		for (; len > 0; len -= sizeof(ifreq[0]), ifrq++) {
			m = nmatch(&dst, &((struct sockaddr_in *)
					  (&ifrq->ifr_addr))->sin_addr);
			if (m > maxmatch) {
				maxmatch = m;
				ifrmax = ifrq;
			}
		}
		if (bp->bp_giaddr.s_addr == 0) {
			if (maxmatch == 0) {
				return;
			}
			bp->bp_giaddr = ((struct sockaddr_in *)
				(&ifrmax->ifr_addr))->sin_addr;
		}
		bp->bp_siaddr = ((struct sockaddr_in *)
			(&ifrmax->ifr_addr))->sin_addr;
	}

	to.sin_addr = dst; 
	if (sendto(s, bp, sizeof(struct bootp), 0, &to, sizeof(to)) < 0) {
D 2
	    report(LOG_ERR, "sendto: %m\n");
E 2
I 2
	    syslog(LOG_ERR, "sendto: %m\n");
E 2
	}
}



/*
 * Return the number of leading bytes matching in the
 * internet addresses supplied.
 */
nmatch(ca,cb)
    register char *ca, *cb;
{
    register n,m;

    for (m = n = 0 ; n < 4 ; n++) {
	if (*ca++ != *cb++)
	    return(m);
	m++;
    }
    return(m);
}



/*
 * Setup the arp cache so that IP address 'ia' will be temporarily
 * bound to hardware address 'ha' of length 'len'.
 */
setarp(ia, ha, len)
	struct in_addr *ia;
	byte *ha;
	int len;
{
	struct sockaddr_in *si;
	
	bzero((caddr_t)&arpreq, sizeof(arpreq));
	
	arpreq.arp_pa.sa_family = AF_INET;
	si = (struct sockaddr_in *) &arpreq.arp_pa;
	si->sin_addr = *ia;

	arpreq.arp_flags = ATF_INUSE | ATF_COM;
	
	bcopy(ha, arpreq.arp_ha.sa_data, len);

	if (ioctl(s, SIOCSARP, (caddr_t)&arpreq) < 0) {
D 2
	    report(LOG_ERR, "ioctl(SIOCSARP): %m\n");
E 2
I 2
	    syslog(LOG_ERR, "ioctl(SIOCSARP): %m\n");
E 2
	}
}



#ifdef DEBUG

/*
 * Dump the internal memory database to bootpd_dump.
 */

dumptab()
{
    register int n;
    register struct host *hp;
    register FILE *fp;
    long t;

    /*
     * Open bootpd.dump file.
     */
    if ((fp = fopen(bootpd_dump, "w")) == NULL) {
D 2
	report(LOG_ERR, "error opening %s: %m\n", bootpd_dump);
E 2
I 2
	syslog(LOG_ERR, "error opening %s: %m\n", bootpd_dump);
E 2
	exit(1);
    }

    t = time(NULL);
    fprintf(fp, "\n# %s: dump of bootp server database.\n", bootpd_dump);
    fprintf(fp, "#\n# Dump taken %s", ctime(&t));
    fprintf(fp, "#\n#\n# Legend:\n");
    fprintf(fp, "#\thd -- home directory\n");
    fprintf(fp, "#\tbf -- bootfile\n");
    fprintf(fp, "#\tcs -- cookie servers\n");
    fprintf(fp, "#\tds -- domain name servers\n");
    fprintf(fp, "#\tgw -- gateways\n");
    fprintf(fp, "#\tha -- hardware address\n");
    fprintf(fp, "#\tht -- hardware type\n");
    fprintf(fp, "#\tim -- impress servers\n");
    fprintf(fp, "#\tip -- host IP address\n");
    fprintf(fp, "#\tlg -- log servers\n");
    fprintf(fp, "#\tlp -- LPR servers\n");
    fprintf(fp, "#\tns -- IEN-116 name servers\n");
    fprintf(fp, "#\trl -- resource location protocol servers\n");
    fprintf(fp, "#\tsm -- subnet mask\n");
    fprintf(fp, "#\tto -- time offset (seconds)\n");
    fprintf(fp, "#\tts -- time servers\n\n\n");

    n = 0;
    for (hp = (struct host *) hash_FirstEntry(hwhashtable); hp != NULL;
	 hp = (struct host *) hash_NextEntry(hwhashtable)) {
	    dump_host(fp, hp);
	    fprintf(fp, "\n");
	    n++;
    }
    fclose(fp);

D 2
#ifdef SYSLOG
E 2
    syslog(LOG_INFO, "dumped %d entries to %s", n, bootpd_dump);
D 2
#endif
E 2
}



/*
 * Dump all the available information on the host pointed to by "hp".
 * The output is sent to the file pointed to by "fp".
 */

void dump_host(fp, hp)
FILE *fp;
struct host *hp;
{
    if (hp) {
	if (hp->hostname) {
	    fprintf(fp, "%s:", hp->hostname->string);
	}
	if (hp->flags.iaddr) {
	    fprintf(fp, "ip=%s:", inet_ntoa(hp->iaddr.s_addr));
	}
	if (hp->flags.htype) {
	    fprintf(fp, "ht=%u:", (unsigned) hp->htype);
	    if (hp->flags.haddr) {
		fprintf(fp, "ha=%s:", haddrtoa(hp->haddr, hp->htype));
	    }
	}
	if (hp->flags.subnet_mask) {
	    fprintf(fp, "sm=%s:", inet_ntoa(hp->subnet_mask.s_addr));
	}
	if (hp->flags.cookie_server) {
	    fprintf(fp, "cs=");
	    list_ipaddresses(fp, hp->cookie_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.domain_server) {
	    fprintf(fp, "ds=");
	    list_ipaddresses(fp, hp->domain_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.gateway) {
	    fprintf(fp, "gw=");
	    list_ipaddresses(fp, hp->gateway);
	    fprintf(fp, ":");
	}
	if (hp->flags.impress_server) {
	    fprintf(fp, "im=");
	    list_ipaddresses(fp, hp->impress_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.log_server) {
	    fprintf(fp, "lg=");
	    list_ipaddresses(fp, hp->log_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.lpr_server) {
	    fprintf(fp, "lp=");
	    list_ipaddresses(fp, hp->lpr_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.name_server) {
	    fprintf(fp, "ns=");
	    list_ipaddresses(fp, hp->name_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.rlp_server) {
	    fprintf(fp, "rl=");
	    list_ipaddresses(fp, hp->rlp_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.time_server) {
	    fprintf(fp, "ts=");
	    list_ipaddresses(fp, hp->time_server);
	    fprintf(fp, ":");
	}
	if (hp->flags.time_offset) {
	    if (hp->flags.timeoff_auto) {
		fprintf(fp, "to=auto:");
	    } else {
		fprintf(fp, "to=%ld:", hp->time_offset);
	    }
	}
	if (hp->flags.homedir) {
	    fprintf(fp, "hd=%s:", hp->homedir->string);
	}
	if (hp->flags.bootfile) {
	    fprintf(fp, "bf=%s:", hp->bootfile->string);
	}
	if (hp->flags.vendor_magic) {
	    fprintf(fp, "vm=");
	    if (hp->flags.vm_auto) {
		fprintf(fp, "auto:");
	    } else if (!bcmp(hp->vm_cookie, vm_cmu, 4)) {
		fprintf(fp, "cmu:");
	    } else if (!bcmp(hp->vm_cookie, vm_rfc1048, 4)) {
		fprintf(fp, "rfc1048");
	    } else {
		fprintf(fp, "%d.%d.%d.%d:",
			    (int) ((hp->vm_cookie)[0]),
			    (int) ((hp->vm_cookie)[1]),
			    (int) ((hp->vm_cookie)[2]),
			    (int) ((hp->vm_cookie)[3]));
	    }
	}
    }
}



/*
 * Dump an entire struct in_addr_list of IP addresses to the indicated file.
 *
 * The addresses are printed in standard ASCII "dot" notation and separated
 * from one another by a single space.  A single leading space is also
 * printed before the first adddress.
 *
 * Null lists produce no output (and no error).
 */

void list_ipaddresses(fp, ipptr)
    FILE *fp;
    struct in_addr_list *ipptr;
{
    register unsigned count;
    register struct in_addr *addrptr;

    if (ipptr) {
	count = ipptr->addrcount;
	addrptr = ipptr->addr;
	if (count-- > 0) {
	    fprintf(fp, "%s", inet_ntoa(*addrptr++));
	    while (count-- > 0) {
		fprintf(fp, " %s", inet_ntoa(*addrptr++));
	    }
	}
    }
}
#endif		/* DEBUG */



/*
 * Insert the CMU "vendor" data for the host pointed to by "hp" into the
 * bootp packet pointed to by "bp".
 */

void dovend_cmu(bp, hp)
    register struct bootp *bp;
    register struct host *hp;
{
    struct cmu_vend *vendp;
    register struct in_addr_list *taddr;

    /* Fill in vendor information. Subnet mask, default gateway,
	domain name server, ien name server, time server */
    vendp = (struct cmu_vend *) bp->bp_vend;
    if (hp->flags.subnet_mask) {
	(vendp->v_smask).s_addr = hp->subnet_mask.s_addr;
	(vendp->v_flags) |= VF_SMASK;
	if (hp->flags.gateway) {
	    (vendp->v_dgate).s_addr = hp->gateway->addr->s_addr;
	}
    }
    if (hp->flags.domain_server) {
	taddr = hp->domain_server;
	if (taddr->addrcount > 0) {
	    (vendp->v_dns1).s_addr = (taddr->addr)[0].s_addr;
	    if (taddr->addrcount > 1) {
		(vendp->v_dns2).s_addr = (taddr->addr)[1].s_addr;
	    }
	}
    }
    if (hp->flags.name_server) {
	taddr = hp->name_server;
	if (taddr->addrcount > 0) {
	    (vendp->v_ins1).s_addr = (taddr->addr)[0].s_addr;
	    if (taddr->addrcount > 1) {
		(vendp->v_ins2).s_addr = (taddr->addr)[1].s_addr;
	    }
	}
    }
    if (hp->flags.time_server) {
	taddr = hp->time_server;
	if (taddr->addrcount > 0) {
	    (vendp->v_ts1).s_addr = (taddr->addr)[0].s_addr;
	    if (taddr->addrcount > 1) {
		(vendp->v_ts2).s_addr = (taddr->addr)[1].s_addr;
	    }
	}
    }
    strcpy(vendp->v_magic, vm_cmu);	

D 2
#ifdef SYSLOG
E 2
    if (debug > 1) {
	syslog(LOG_INFO, "sending CMU-style reply");
    }
D 2
#endif
E 2
}



/*
 * Insert the RFC1048 vendor data for the host pointed to by "hp" into the
 * bootp packet pointed by "bp".
 */

void dovend_rfc1048(bp, hp)
    register struct bootp *bp;
    register struct host *hp;
{
    int bytesleft, len;
    byte *vp;
    char *tmpstr;

    vp = bp->bp_vend;
    bytesleft = sizeof(bp->bp_vend);	/* Initial vendor area size */
    bcopy(vm_rfc1048, vp, 4);		/* Copy in the magic cookie */
    vp += 4;
    bytesleft -= 4;

    if (hp->flags.time_offset) {
	*vp++ = TAG_TIME_OFFSET;			/* -1 byte  */
	*vp++ = 4;					/* -1 byte  */
	if (hp->flags.timeoff_auto) {
	    insert_u_long(htonl(secondswest), &vp);
	} else {
	    insert_u_long(htonl(hp->time_offset), &vp);		/* -4 bytes */
	}
	bytesleft -= 6;
    }
    if (hp->flags.subnet_mask) {
	*vp++ = TAG_SUBNET_MASK;			/* -1 byte  */
	*vp++ = 4;					/* -1 byte  */
D 6
	insert_u_long(hp->subnet_mask.s_addr, &vp);	/* -4 bytes */
E 6
I 6
	insert_net_long(hp->subnet_mask.s_addr, &vp);	/* -4 bytes */
E 6
	bytesleft -= 6;					/* Fix real count */
	if (hp->flags.gateway) {
	    insert_ip(TAG_GATEWAY, hp->gateway, &vp, &bytesleft);
	}
    }

    if (hp->flags.cookie_server) {
	insert_ip(TAG_COOKIE_SERVER, hp->cookie_server, &vp, &bytesleft);
    }
    if (hp->flags.domain_server) {
	insert_ip(TAG_DOMAIN_SERVER, hp->domain_server, &vp, &bytesleft);
    }
    if (hp->flags.impress_server) {
	insert_ip(TAG_IMPRESS_SERVER, hp->impress_server, &vp, &bytesleft);
    }
    if (hp->flags.log_server) {
	insert_ip(TAG_LOG_SERVER, hp->log_server, &vp, &bytesleft);
    }
    if (hp->flags.lpr_server) {
	insert_ip(TAG_LPR_SERVER, hp->lpr_server, &vp, &bytesleft);
    }
    if (hp->flags.name_server) {
	insert_ip(TAG_NAME_SERVER, hp->name_server, &vp, &bytesleft);
    }
    if (hp->flags.rlp_server) {
	insert_ip(TAG_RLP_SERVER, hp->rlp_server, &vp, &bytesleft);
    }
    if (hp->flags.time_server) {
	insert_ip(TAG_TIME_SERVER, hp->time_server, &vp, &bytesleft);
    }

    if (hp->flags.name_switch && hp->flags.send_name) {
	/*
	 * Check for room for hostname.  Add 3 to account for
	 * TAG_HOSTNAME, size, and TAG_END.
	 */
	len = strlen(hp->hostname->string);
	if ((len + 3) > bytesleft) {
	    /*
	     * Not enough room for full (domain-qualified) hostname, try
	     * stripping it down to just the first field (host).
	     */
	    tmpstr = hp->hostname->string;
	    len = 0;
	    while (*tmpstr && (*tmpstr != '.')) {
		tmpstr++;
		len++;
	    }
	}
	if ((len + 3) <= bytesleft) {
	    *vp++ = TAG_HOSTNAME;
	    *vp++ = (byte) (len & 0xFF);
	    bcopy(hp->hostname->string, vp, len);
	    vp += len;
	}
    }
    *vp = TAG_END;
    

D 2
#ifdef SYSLOG
E 2
    if (debug > 1) {
	syslog(LOG_INFO, "sending RFC1048-style reply");
    }
D 2
#endif
E 2
}



/*
 * Compare function to determine whether two hardware addresses are
 * equivalent.  Returns TRUE if "host1" and "host2" are equivalent, FALSE
 * otherwise.
 *
 * This function is used when retrieving elements from the hardware address
 * hash table.
 */

boolean hwlookcmp(host1, host2)
    struct host *host1, *host2;
{
    if (host1->htype != host2->htype) {
	return FALSE;
    }
    if (bcmp(host1->haddr, host2->haddr, haddrlength(host1->htype))) {
	return FALSE;
    }
    return TRUE;
}




/*
 * Compare function for doing IP address hash table lookup.
 */

boolean iplookcmp(host1, host2)
    struct host *host1, *host2;
{
    return (host1->iaddr.s_addr == host2->iaddr.s_addr);
}



/*
 * Insert a tag value, a length value, and a list of IP addresses into the
 * memory buffer indirectly pointed to by "dest", without going past "stop".
 * "ipst_prt" is a pointer to an ipaddr_t (i.e. a structure containing a
 * pointer to a linked list of IP addresses and a linkcount specifying how
 * many hosts are using this list).
 *
 * This is used to fill the vendor-specific area of a bootp packet in
 * conformance to RFC1048.
 */

void insert_ip(tag, iplist, dest, bytesleft)
    byte tag;
    struct in_addr_list *iplist;
    byte **dest;
    int *bytesleft;
{
    register struct in_addr *addrptr;
    register unsigned addrcount;
    byte *d;

    if (iplist) {
	d = *dest;				/* Save pointer for later */
	**dest = tag;
	(*dest) += 2;
	(*bytesleft) -= 2;		    /* Account for tag and length */
	addrptr = iplist->addr;
	addrcount = iplist->addrcount;
	while ((*bytesleft >= 4) && (addrcount > 0)) {
D 6
	    insert_u_long(addrptr->s_addr, dest);
E 6
I 6
	    insert_net_long(addrptr->s_addr, dest);
E 6
	    addrptr++;
	    addrcount--;
	    (*bytesleft) -= 4;			/* Four bytes per address */
	}
	d[1] = (byte) ((*dest - d - 2) & 0xFF);
    }
}



/*
 * Convert a hardware address to an ASCII string.
 */

char *haddrtoa(haddr, htype)
    register byte *haddr;
    byte htype;
{
    static char haddrbuf[2 * MAXHADDRLEN + 1];
    register char *bufptr;
    register unsigned count;

    bufptr = haddrbuf;
    for (count = haddrlength(htype); count > 0; count--) {
	sprintf(bufptr, "%02X",	(unsigned) (*haddr++ & 0xFF));
	bufptr += 2;
    }
    return (haddrbuf);
}



/*
 * Insert the unsigned long "value" into memory starting at the byte
 * pointed to by the byte pointer (*dest).  (*dest) is updated to
 * point to the next available byte.
 */

void insert_u_long(value, dest)
    unsigned long value;
    byte **dest;
{
    register byte *temp;
    register int n;

    temp = (*dest += 4);
    for (n = 4; n > 0; n--) {
	*--temp = (byte) (value & 0xFF);
	value >>= 8;
    }
I 6
}

void insert_net_long(value, dest)
    unsigned long value;
    byte **dest;
{
    bcopy(&value, *dest, 4);
    *dest += 4;
E 6
D 2
}



/*
 * This routine reports errors and such via stderr and syslog() if
 * appopriate.  It just helps avoid a lot of "#ifdef SYSLOG" constructs
 * from being scattered throughout the code.
 *
 * The syntax is identical to syslog(3).
 */

/*VARARGS2*/
void report(priority, fmt, p0, p1, p2, p3, p4)
    int priority;
    char *fmt;
{
    char buf[MAXSTRINGLEN];
    char c, *fmtptr, *bufptr;

    /*
     * Replace %m with current error message like syslog()
     */
    bufptr = buf;
    fmtptr = fmt;
    while ((c = *fmtptr++) && bufptr < &buf[MAXSTRINGLEN]) {
	if (c != '%') {
	    *bufptr++ = c;
	    continue;
	}
	c = *fmtptr++;
	if (c != 'm') {
	    *bufptr++ = '%';
	    *bufptr++ = c;
	    continue;
	}
	if (errno > sys_nerr) {
	    sprintf(bufptr, "error %d", errno);
	} else {
	    strcpy(bufptr, sys_errlist[errno]);
	}
	bufptr += strlen(bufptr);
    }

    /*
     * Print the message
     */
    fprintf(stderr, "bootpd: ");
    fprintf(stderr, buf, p0, p1, p2, p3, p4);
#ifdef SYSLOG
    syslog(priority, fmt, p0, p1, p2, p3, p4);
#endif
E 2
}
E 1

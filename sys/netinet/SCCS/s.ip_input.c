h47755
s 00010/00005/00979
d D 7.10 88/06/29 17:06:53 bostic 109 108
c install approved copyright notice
e
s 00043/00033/00941
d D 7.9 88/03/15 21:11:39 karels 108 107
c don't bother searching fragment queues when nonfragmented packet
c is received
e
s 00008/00002/00966
d D 7.8 87/12/07 17:45:42 bostic 107 106
c use Berkeley specific header
e
s 00004/00001/00964
d D 7.7 87/10/31 23:46:20 karels 106 103
c try not to send net unreachables for subnets
e
s 00001/00001/00960
d D 7.6.1.2 87/09/14 14:59:00 karels 105 104
c make version usable with 4.3
e
s 00000/00004/00961
d D 7.6.1.1 87/09/09 11:33:09 karels 104 103
c branch to diff against for sending bug report
e
s 00001/00001/00964
d D 7.6 87/09/09 11:27:02 karels 103 102
c wrong icmp code when record-route dest. is unreachable
e
s 00006/00002/00959
d D 7.5 87/06/04 21:49:40 karels 102 101
c fix record route; don't forward funny stuff; drop if ttl reaches 0
e
s 00004/00002/00957
d D 7.4 87/05/24 22:21:18 karels 101 100
c don't M_WAIT from interrupt level
e
s 00010/00010/00949
d D 7.3 87/04/18 15:50:15 karels 100 98
c fix ip TS options with addresses (bump pointers correctly)
e
s 00011/00011/00948
d R 7.3 87/04/18 15:48:55 karels 99 98
c fix ip TS options with addresses
e
s 00005/00000/00954
d D 7.2 87/02/03 16:47:05 karels 98 97
c don't redirect if outgoing route is default or from redirect
e
s 00001/00001/00953
d D 7.1 86/06/05 00:27:47 mckusick 97 96
c 4.3BSD release version
e
s 00001/00001/00953
d D 6.23 86/06/02 14:30:23 karels 96 95
c lint
e
s 00004/00005/00950
d D 6.22 86/04/17 16:19:42 karels 95 94
c use host redirects rather than net if dest is on a subnet
e
s 00005/00002/00950
d D 6.21 86/03/31 16:40:49 karels 94 93
c if configured as gateway, send ICMP's when not forwarding
e
s 00009/00009/00943
d D 6.20 86/02/23 23:24:03 karels 93 92
c lint
e
s 00008/00003/00944
d D 6.19 86/02/21 11:22:20 karels 92 91
c don't send icmp's in response if we're not forwarding
e
s 00001/00001/00946
d D 6.18 86/02/19 19:23:56 karels 91 90
c from Sam; how did lint miss this?
e
s 00004/00004/00943
d D 6.17 86/02/19 16:56:56 karels 90 89
c lint
e
s 00006/00005/00941
d D 6.16 86/02/02 18:25:00 karels 89 88
c add arg to icmp_error (incoming interface of offending packet;
c to make source address of redirects correct)
e
s 00006/00000/00940
d D 6.15 86/01/30 13:35:54 karels 88 87
c avoid receiving before any IP addresses are set
e
s 00001/00000/00939
d D 6.14 86/01/20 12:53:40 karels 87 86
c maintain ip input count
e
s 00022/00010/00917
d D 6.13 85/10/14 17:20:08 karels 86 85
c recognize other attempts to broadcast
e
s 00326/00063/00601
d D 6.12 85/09/16 23:09:58 karels 85 84
c fix up src routing updates, save for protocols; receive packets
c addressed to all 0's or all 1's; keep track of incoming interface
c for errors, etc; correct mbuf adjustment for IP options in ipreass;
c correct ICMP to unix error translation; add conditional ability to send
c redirects when forwarding packet using incoming interface; one-element
c route cache in ipforward; more statistics
e
s 00007/00001/00657
d D 6.11 85/06/08 12:40:25 mckusick 84 83
c Add copyright
e
s 00004/00030/00654
d D 6.10 85/05/27 22:29:33 karels 83 82
c plug another mbuf leak; keep statistics on forwarding;
c remove ip_ctlinput (higher level always does the work)
e
s 00037/00033/00647
d D 6.9 85/03/18 15:48:01 karels 82 81
c move net addresses from interface to protocol layer;
c move ip_id swapping to ip_forward; don't strip ip options before forwarding
e
s 00003/00003/00677
d D 6.8 84/12/20 15:36:34 karels 81 80
c correct bounds check; don't fall off IP header if optlen is bogus
e
s 00000/00014/00680
d D 6.7 84/11/15 11:09:55 karels 80 79
c toss ND crap
e
s 00010/00004/00684
d D 6.6 84/11/14 10:14:55 karels 79 78
c generalize in_pcbnotify, use it to cause reallocation of routes
c after receipt of a redirect
e
s 00016/00016/00672
d D 6.5 84/08/29 15:36:22 bloom 78 76
c Include file changes.  No more ../h
e
s 00001/00001/00687
d R 6.5 84/08/22 18:56:24 mckusick 77 76
c use IMIN macro to save call overhead
e
s 00001/00001/00687
d D 6.4 84/08/21 10:23:03 karels 76 75
c change protocol family number in protosw to pointer to domain
e
s 00001/00001/00687
d D 6.3 84/05/25 14:24:17 karels 75 74
c copy ip options into the right mbuf
e
s 00004/00001/00684
d D 6.2 84/04/14 10:51:06 sam 74 73
c check ip option lengths (from rws@mit-bold)
e
s 00000/00000/00685
d D 6.1 83/08/16 23:16:38 sam 73 72
c 4.2 distribution
e
s 00004/00004/00681
d D 1.69 83/08/16 23:15:32 sam 72 70
c cause of sendmail headaches...mapping table not full size; 
c still must think through what to do with these error codes
e
s 00000/00000/00685
d R 6.1 83/07/29 07:11:37 sam 71 70
c 4.2 distribution
e
s 00001/00001/00684
d D 1.68 83/05/15 17:15:41 sam 70 69
c from sun
e
s 00001/00002/00684
d D 1.67 83/05/12 15:03:42 sam 69 68
c fix ip packet forwarding to not stomp on headers when fragmented;
e
s 00004/00001/00682
d D 1.66 83/03/12 14:16:48 sam 68 67
c don't generate icmp message without a copy of the original ip
e
s 00013/00005/00670
d D 1.65 83/02/23 00:27:16 sam 67 66
c collect more statistics; add sanity check to avoid bad icmp packets
e
s 00003/00002/00672
d D 1.64 83/02/10 22:11:13 sam 66 65
c remove /usr/include dependencies
e
s 00015/00016/00659
d D 1.63 83/02/05 17:08:41 sam 65 64
c ip_freef is now void; throw away frag q's properly
e
s 00014/00000/00661
d D 1.62 83/01/17 16:06:52 sam 64 63
c hack for network disk stuff
e
s 00001/00001/00660
d D 1.61 83/01/04 23:18:02 sam 63 62
c clean some stuff up and purge some crud
e
s 00000/00001/00661
d D 1.60 83/01/03 18:25:42 sam 62 61
c delete printf -- we "know" things work
e
s 00002/00002/00660
d D 1.59 82/12/14 17:15:07 sam 61 60
c typed mbufs
e
s 00006/00004/00656
d D 1.58 82/11/03 01:08:30 root 60 59
c misc 4.1c fixes
e
s 00000/00002/00660
d D 1.57 82/10/30 13:03:10 root 59 58
c get rid of conditional htons/ntohs etc
e
s 00001/00001/00661
d D 1.56 82/10/23 10:27:47 root 58 57
c move include of kernel.h
e
s 00007/00009/00655
d D 1.55 82/10/21 21:05:39 root 57 56
c lint
e
s 00011/00009/00653
d D 1.54 82/10/20 01:22:35 root 56 55
c lint
e
s 00005/00003/00657
d D 1.53 82/10/17 22:47:25 root 55 54
c lint
e
s 00004/00002/00656
d D 1.52 82/10/17 14:55:04 root 54 53
c fix lint
e
s 00006/00006/00652
d D 1.51 82/10/09 05:45:40 wnj 53 52
c localize header files
e
s 00000/00001/00658
d D 1.50 82/10/05 18:49:28 root 52 51
c m_get inits m_off; remove TCPTRUEOOB
e
s 00003/00002/00656
d D 1.49 82/09/12 03:21:35 root 51 50
c time now a structure
e
s 00001/00001/00657
d D 1.48 82/08/22 21:21:08 root 50 49
c lint
e
s 00000/00000/00658
d D 1.47 82/07/24 18:18:01 root 49 48
c restore sccs ids
e
s 00001/00000/00657
d D 1.46 82/07/24 18:13:08 root 48 47
c 
e
s 00000/00010/00657
d D 1.45 82/06/20 00:54:14 sam 47 46
c purge COUNT stuff now that we can use gprof
e
s 00001/00001/00666
d D 1.44 82/06/13 23:01:39 sam 46 45
c add class a/b/c net #'s and purge logical host kludge code
e
s 00037/00022/00630
d D 1.43 82/05/02 17:05:16 sam 45 44
c clean up some icmp stuff; add EHOSTDOWN & EHOSTUNREACH
e
s 00005/00005/00647
d D 1.42 82/04/25 18:35:39 sam 44 43
c icmp works with tcp and friends
e
s 00106/00027/00546
d D 1.41 82/04/24 20:38:18 sam 43 42
c icmp and ctlinput working -- missing protocol specific ctlinput's
e
s 00001/00000/00572
d D 1.40 82/04/07 11:48:18 sam 42 41
c not special casing broadcast address -- this just speeds things up
e
s 00012/00007/00560
d D 1.39 82/04/04 13:47:04 root 41 40
c drop small numbers of bytes from ends of packets quickly
e
s 00005/00002/00562
d D 1.38 82/03/31 20:36:35 sam 40 39
c routing tried and working, add logical host stuff
e
s 00001/00006/00563
d D 1.37 82/03/30 11:32:28 sam 39 38
c with routing, but not forwarding
e
s 00006/00014/00563
d D 1.36 82/03/29 11:32:30 sam 38 37
c first cut (incomplete) at routing
e
s 00050/00014/00527
d D 1.35 82/03/28 14:22:39 sam 37 36
c convert interfaces to sockaddr's and add hooks for routing
e
s 00006/00002/00535
d D 1.34 82/03/23 15:52:02 wnj 36 35
c fix to calling of m_cat in reassembly
e
s 00001/00000/00536
d D 1.33 82/03/19 00:13:36 root 35 34
c missing q->ip_off += i in overlap code (by analogy with tcp_reass)
e
s 00010/00005/00526
d D 1.32 82/03/15 04:44:05 wnj 34 33
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00006/00001/00525
d D 1.31 82/03/09 17:39:41 root 33 32
c handle broadcast packets
e
s 00002/00002/00524
d D 1.30 82/02/15 11:33:30 root 32 31
c clean up 1's and 0's in mbuf calls
e
s 00005/00005/00521
d D 1.29 81/12/23 14:02:33 root 31 30
c use m_pullup which returns m
e
s 00001/00000/00525
d D 1.28 81/12/22 23:13:59 root 30 29
c print something on strange packets (kludge)
e
s 00000/00001/00525
d D 1.27 81/12/12 18:04:39 root 29 28
c clean out printf
e
s 00007/00002/00519
d D 1.26 81/12/12 12:58:22 root 28 27
c with crud (first working version)
e
s 00001/00000/00520
d D 1.25 81/12/11 22:14:32 root 27 26
c printf on bad packets
e
s 00002/00013/00518
d D 1.24 81/12/09 20:43:12 wnj 26 25
c cleanup
e
s 00029/00009/00502
d D 1.23 81/12/09 20:41:06 wnj 25 24
c with debugging crud
e
s 00001/00001/00510
d D 1.22 81/12/03 17:29:49 wnj 24 23
c cleanup
e
s 00016/00011/00495
d D 1.21 81/12/02 16:58:34 wnj 23 22
c yet more lint
e
s 00001/00001/00505
d D 1.20 81/11/29 21:59:49 wnj 22 21
c lint and interface cleanups
e
s 00025/00018/00481
d D 1.19 81/11/26 11:56:33 wnj 21 20
c before carry to ARPAVAX
e
s 00007/00013/00492
d D 1.18 81/11/23 00:05:30 wnj 20 19
c drop crud
e
s 00010/00003/00495
d D 1.17 81/11/23 00:02:31 wnj 19 18
c first working version (with crud) for dg's
e
s 00072/00033/00426
d D 1.16 81/11/20 00:46:41 wnj 18 17
c linted
e
s 00014/00014/00445
d D 1.15 81/11/18 15:37:16 wnj 17 16
c more cleanup
e
s 00009/00014/00450
d D 1.14 81/11/16 14:16:50 wnj 16 15
c more lint
e
s 00054/00066/00410
d D 1.13 81/11/15 12:59:36 wnj 15 14
c listing
e
s 00044/00059/00432
d D 1.12 81/11/08 16:24:33 wnj 14 13
c first listing
e
s 00001/00001/00490
d D 1.11 81/11/01 22:31:57 wnj 13 12
c minor fixups
e
s 00007/00015/00484
d D 1.10 81/10/31 13:09:49 wnj 12 11
c first worker with new inline cksum
e
s 00003/00003/00496
d D 1.9 81/10/29 20:26:46 wnj 11 10
c cleanup of header files
e
s 00001/00001/00498
d D 1.8 81/10/28 19:39:07 wnj 10 9
c bug in iptimeout processing (termination condition)
e
s 00406/00298/00093
d D 1.7 81/10/28 16:37:31 wnj 9 6
c first compiled halfbrid... not working yet
e
s 00067/00061/00278
d R 1.8 81/10/27 02:51:55 wnj 8 7
c much closer to working
e
s 00242/00294/00097
d R 1.7 81/10/26 02:09:21 wnj 7 6
c first compile of major cleanup
e
s 00001/00001/00390
d D 1.6 81/10/23 11:43:48 wnj 6 5
c working with snd_copy incr ref cnt
e
s 00002/00000/00389
d D 1.5 81/10/21 19:06:31 wnj 5 4
c cleanup the headers
e
s 00164/00188/00225
d D 1.4 81/10/18 11:51:48 wnj 4 3
c first speedups (tcp_input, ip_input, t_cancel inline, no ip_opt, ip_findf)
e
s 00005/00001/00408
d D 1.3 81/10/16 16:24:29 wnj 3 2
c first working version with software interrupts
e
s 00000/00009/00409
d D 1.2 81/10/14 19:12:16 wnj 2 1
c new version: macros and fast cksum
e
s 00418/00000/00000
d D 1.1 81/10/14 09:56:55 wnj 1 0
c date and time created 81/10/14 09:56:55 by wnj
e
u
U
f b 
t
T
I 1
D 32
/* %M% %I% %E% */
E 32
I 32
D 84
/*	%M%	%I%	%E%	*/
E 84
I 84
/*
D 97
 * Copyright (c) 1982 Regents of the University of California.
E 97
I 97
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 97
D 107
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 107
I 107
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 109
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 109
I 109
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
E 109
E 107
 *
 *	%W% (Berkeley) %G%
 */
E 84
E 32
I 5

E 5
D 78
#include "../h/param.h"
D 9
#include "../bbnnet/net.h"
I 5
#include "../bbnnet/mbuf.h"
E 5
#include "../bbnnet/tcp.h"
#include "../bbnnet/ip.h"
#include "../bbnnet/ucb.h"
E 9
I 4
#include "../h/systm.h"
I 9
D 51
#include "../h/clock.h"
E 51
#include "../h/mbuf.h"
I 60
#include "../h/domain.h"
E 60
I 15
D 17
#include "../h/protocol.h"
E 17
#include "../h/protosw.h"
E 15
I 12
D 13
#include "../inet/cksum.h"
E 13
I 13
D 14
#include "../inet/inet_cksum.h"
E 13
E 12
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/ip.h"			/* belongs before inet.h */
#include "../inet/ip_icmp.h"
#include "../inet/tcp.h"
E 14
I 14
D 17
#include "../net/inet_cksum.h"
E 17
I 17
#include "../h/socket.h"
I 56
D 57
#include <time.h>
E 57
D 58
#include "../h/kernel.h"
E 58
D 66
#include <errno.h>
I 57
#include <time.h>
E 66
I 66
#include "../h/errno.h"
#include "../h/time.h"
E 66
I 58
#include "../h/kernel.h"
E 78
I 78
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "domain.h"
#include "protosw.h"
#include "socket.h"
#include "errno.h"
#include "time.h"
#include "kernel.h"
E 78
E 58
E 57

#include "../net/if.h"
#include "../net/route.h"
I 66

E 66
E 56
E 17
D 21
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 21
I 21
D 53
#include "../net/in.h"
#include "../net/in_systm.h"
E 53
I 53
D 78
#include "../netinet/in.h"
I 54
#include "../netinet/in_pcb.h"
E 54
#include "../netinet/in_systm.h"
E 53
E 21
I 18
D 56
#include "../net/if.h"
E 18
D 21
#include "../net/imp.h"
#include "../net/ip.h"			/* belongs before inet.h */
E 21
I 21
D 53
#include "../net/ip.h"			/* belongs before in.h */
E 21
I 15
#include "../net/ip_var.h"
E 15
#include "../net/ip_icmp.h"
#include "../net/tcp.h"
E 53
I 53
#include "../netinet/ip.h"			/* belongs before in.h */
E 56
I 56
#include "../netinet/ip.h"
E 56
#include "../netinet/ip_var.h"
#include "../netinet/ip_icmp.h"
#include "../netinet/tcp.h"
E 78
I 78
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
I 82
#include "in_var.h"
E 82
#include "ip.h"
#include "ip_var.h"
#include "ip_icmp.h"
#include "tcp.h"
E 78
E 53
I 51
D 56
#include <time.h>
#include "../h/kernel.h"
E 51
I 43
#include <errno.h>
E 56
E 43
I 37
D 39
#include "../net/route.h"
E 39
E 37
E 14
E 9
E 4

I 37
D 39
#define	IPTTLDEC	5		/* doesn't belong here */

E 39
E 37
I 15
u_char	ip_protox[IPPROTO_MAX];
I 34
int	ipqmaxlen = IFQ_MAXLEN;
I 37
D 82
struct	ifnet *ifinet;			/* first inet interface */
E 82
I 82
struct	in_ifaddr *in_ifaddr;			/* first inet address */
E 82
E 37
E 34

E 15
D 4
/*****************************************************************************
*                                                                            *
*         ip level input routine: called from 1822 level upon receipt        *
*         of an internet datagram or fragment.  this routine does            *
*         fragment reassembly, if necessary, and passes completed            *
*         datagrams to higher level protocol processing routines on          *
*         the basis of the ip header protocol field.  it is passed a         *
*         pointer to an mbuf chain containing the datagram/fragment.         *
*         the mbuf offset/length are set to point at the ip header.          *
*                                                                            *
*****************************************************************************/

E 4
D 9
int nosum = 0;
E 9
I 9
D 14
int	nosum = 0;
E 14
I 14
/*
I 85
 * We need to save the IP options in case a protocol wants to respond
 * to an incoming packet over the same route if the packet got here
 * using IP source routing.  This allows connection establishment and
 * maintenance when the remote end is on a network that is not known
 * to us.
 */
int	ip_nhops = 0;
static	struct ip_srcrt {
	char	nop;				/* one NOP to align */
	char	srcopt[IPOPT_OFFSET + 1];	/* OPTVAL, OLEN and OFFSET */
	struct	in_addr route[MAX_IPOPTLEN];
} ip_srcrt;

/*
E 85
D 23
 * Ip initialization.
E 23
I 23
D 24
 * Ip initialization: fill in IP protocol switch table.
E 24
I 24
 * IP initialization: fill in IP protocol switch table.
E 24
 * All protocols not implemented in kernel go to raw IP protocol handler.
E 23
 */
ip_init()
{
I 15
	register struct protosw *pr;
	register int i;
D 16
	int raw;
E 16
E 15
E 14
E 9

I 18
D 47
COUNT(IP_INIT);
E 47
E 18
I 15
D 85
	pr = pffindproto(PF_INET, IPPROTO_RAW);
E 85
I 85
	pr = pffindproto(PF_INET, IPPROTO_RAW, SOCK_RAW);
E 85
	if (pr == 0)
		panic("ip_init");
	for (i = 0; i < IPPROTO_MAX; i++)
D 60
		ip_protox[i] = pr - protosw;
	for (pr = protosw; pr <= protoswLAST; pr++)
E 60
I 60
		ip_protox[i] = pr - inetsw;
	for (pr = inetdomain.dom_protosw;
D 81
	    pr <= inetdomain.dom_protoswNPROTOSW; pr++)
E 81
I 81
	    pr < inetdomain.dom_protoswNPROTOSW; pr++)
E 81
E 60
D 76
		if (pr->pr_family == PF_INET &&
E 76
I 76
		if (pr->pr_domain->dom_family == PF_INET &&
E 76
		    pr->pr_protocol && pr->pr_protocol != IPPROTO_RAW)
D 60
			ip_protox[pr->pr_protocol] = pr - protosw;
E 60
I 60
			ip_protox[pr->pr_protocol] = pr - inetsw;
E 60
E 15
I 14
	ipq.next = ipq.prev = &ipq;
D 51
	ip_id = time & 0xffff;
E 51
I 51
	ip_id = time.tv_sec & 0xffff;
E 51
I 34
	ipintrq.ifq_maxlen = ipqmaxlen;
I 37
D 82
	ifinet = if_ifwithaf(AF_INET);
E 82
E 37
E 34
}

D 15
int	ipcksum = 1;

E 15
I 15
u_char	ipcksum = 1;
E 15
E 14
D 9
ip_input(mp)
struct mbuf *mp;
E 9
I 9
struct	ip *ip_reass();
I 37
D 40
int	ipforwarding = 0;
E 40
I 40
D 43
int	ipforwarding = 1;
int	ipprintfs = 0;
E 43
E 40
struct	sockaddr_in ipaddr = { AF_INET };
I 85
struct	route ipforward_rt;
E 85
E 37

/*
D 23
 * Ip input routines.
 */

/*
E 23
 * Ip input routine.  Checksum and byte swap header.  If fragmented
 * try to reassamble.  If complete and fragment queue exists, discard.
 * Process options.  Pass to next level.
 */
D 21
ip_input(m0)
	struct mbuf *m0;
E 21
I 21
ipintr()
E 21
E 9
{
I 12
D 17
	register struct ip *ip;		/* known to be r11 in CKSUM below */
E 17
I 17
	register struct ip *ip;
E 17
D 21
	register struct mbuf *m = m0;
E 21
I 21
	register struct mbuf *m;
D 25
	struct mbuf *m0;
E 25
I 25
D 54
	struct mbuf *m0, *mopt;
E 54
I 54
	struct mbuf *m0;
E 54
E 25
E 21
E 12
I 9
	register int i;
E 9
D 12
	register struct ip *ip, *q;
E 12
I 12
D 16
	register struct ipq *q;
E 16
E 12
	register struct ipq *fp;
I 82
	register struct in_ifaddr *ia;
I 85
	struct ifnet *ifp;
E 85
E 82
D 9
	register struct mbuf *m;
	register i;
	struct mbuf *n;
E 9
I 9
D 12
	register struct mbuf *m = m0;
E 12
E 9
D 21
	int hlen;
E 21
I 21
	int hlen, s;
E 21
D 9
	struct ip *p, *savq;
	struct ipq *ip_findf();
E 9

I 25
D 26
printf("ipintr\n");
E 26
E 25
D 21
COUNT(IP_INPUT);
E 21
I 21
D 47
COUNT(IPINTR);
E 47
next:
E 21
D 9
	ip = (struct ip *)((int)mp + mp->m_off);        /* ->ip hdr */

	/* make sure header does not overflow mbuf */

	if ((hlen = ip->ip_hl << 2) > mp->m_len) {
		printf("ip header overflow\n");
		m_freem(mp);
E 9
I 9
	/*
D 21
	 * Check header and byteswap.
E 21
I 21
	 * Get next datagram off input queue and get IP header
	 * in first mbuf.
E 21
	 */
I 21
	s = splimp();
D 85
	IF_DEQUEUE(&ipintrq, m);
E 85
I 85
	IF_DEQUEUEIF(&ipintrq, m, ifp);
E 85
	splx(s);
D 25
	if (m == 0)
E 25
I 25
D 26
	if (m == 0) {
printf("ipintr returns\n");
E 26
I 26
	if (m == 0)
E 26
E 25
		return;
I 88
	/*
	 * If no IP addresses have been set yet but the interfaces
	 * are receiving, can't do anything with incoming packets yet.
	 */
	if (in_ifaddr == NULL)
		goto bad;
E 88
I 87
	ipstat.ips_total++;
E 87
I 25
D 26
	}
printf("ipintr dequeued %x\n", m);
E 26
E 25
E 21
I 19
D 20
	printf("ip_input\n");
E 20
I 20
D 31
	if (m->m_len < sizeof (struct ip) &&
D 25
	    m_pullup(m, sizeof (struct ip)) == 0)
E 25
I 25
D 26
	    m_pullup(m, sizeof (struct ip)) == 0) {
printf("ipintr pullup drop\n");
E 26
I 26
	    m_pullup(m, sizeof (struct ip)) == 0)
E 26
E 25
		goto bad;
E 31
I 31
	if ((m->m_off > MMAXOFF || m->m_len < sizeof (struct ip)) &&
D 67
	    (m = m_pullup(m, sizeof (struct ip))) == 0)
		return;
E 67
I 67
	    (m = m_pullup(m, sizeof (struct ip))) == 0) {
		ipstat.ips_toosmall++;
		goto next;
	}
E 67
E 31
I 25
D 26
	}
E 26
E 25
E 20
E 19
	ip = mtod(m, struct ip *);
I 25
D 26
printf("ipintr ip->ip_hl %d\n", ip->ip_hl);
E 26
E 25
D 20
	if ((hlen = ip->ip_hl << 2) > m->m_len) {
		printf("ip hdr ovflo\n");
E 20
I 20
D 23
	if ((hlen = ip->ip_hl << 2) > m->m_len &&
	    m_pullup(m, hlen) == 0)
E 20
D 18
		m_freem(m);
E 9
		return;
E 18
I 18
		goto bad;
E 23
I 23
D 82
	if ((hlen = ip->ip_hl << 2) > m->m_len) {
E 82
I 82
	hlen = ip->ip_hl << 2;
D 85
	if (hlen < 10) {	/* minimum header length */
E 85
I 85
	if (hlen < sizeof(struct ip)) {	/* minimum header length */
E 85
		ipstat.ips_badhlen++;
D 83
		goto next;
E 83
I 83
		goto bad;
E 83
	}
	if (hlen > m->m_len) {
E 82
D 31
		if (m_pullup(m, hlen) == 0)
			goto bad;
E 31
I 31
D 67
		if ((m = m_pullup(m, hlen)) == 0)
			return;
E 67
I 67
		if ((m = m_pullup(m, hlen)) == 0) {
			ipstat.ips_badhlen++;
			goto next;
		}
E 67
E 31
		ip = mtod(m, struct ip *);
	}
E 23
E 18
D 20
	}
E 20
D 9

	i = (unsigned short)ip->ip_sum;
E 9
I 9
D 12
	i = ip->ip_sum;
E 9
	ip->ip_sum = 0;
D 9

	if (i != (unsigned short)cksum(mp, hlen)) {     /* verify checksum */
E 9
I 9
#ifdef vax
	if (hlen == sizeof (struct ip)) {
		asm("movl r10,r0; movl (r0)+,r1; addl2 (r0)+,r1");
		asm("adwc (r0)+,r1; adwc (r0)+,r1; adwc (r0)+,r1");
		asm("adwc $0,r1; ashl $-16,r1,r0; addw2 r0,r1");
		asm("adwc $0,r1");		/* ### */
		asm("mcoml r1,r1; movzwl r1,r1; subl2 r1,r11");
	} else
#endif
		i -= cksum(m, hlen);
	if (i) {
E 12
I 12
D 17
	CKSUM_IPCHK(m, ip, r11, hlen);
E 17
I 17
D 18
	ip->ip_sum = inet_cksum(m, hlen);
E 17
	if (ip->ip_sum) {
		printf("ip_sum %x\n", ip->ip_sum);
E 12
E 9
D 17
		netstat.ip_badsum++;
E 17
I 17
		ipstat.ips_badsum++;
E 17
D 14
		if (!nosum) {
E 14
I 14
		if (ipcksum) {
E 14
D 9
        	  	m_freem(mp);
        		return;
E 9
I 9
			m_freem(m);
			return;
E 18
I 18
	if (ipcksum)
D 19
		if (ip->ip_sum = inet_cksum(m, hlen)) {
E 19
I 19
D 21
		if ((ip->ip_sum = inet_cksum(m, hlen)) != 0xffff) {
E 21
I 21
D 25
		if ((ip->ip_sum = in_cksum(m, hlen)) != 0xffff) {
E 25
I 25
		if (ip->ip_sum = in_cksum(m, hlen)) {
E 25
E 21
E 19
D 23
			printf("ip_sum %x\n", ip->ip_sum);
E 23
I 23
D 62
			printf("ip_sum %x\n", ip->ip_sum);	/* XXX */
E 62
E 23
			ipstat.ips_badsum++;
			goto bad;
E 18
E 9
		}
I 25
D 26
printf("cksum passed\n");
E 26
E 25
D 18
	}
E 18
I 18

I 25
D 54
#if vax
E 54
I 54
D 59
#if vax || pdp11 || ns16032
E 59
E 54
E 25
	/*
	 * Convert fields to host representation.
	 */
E 18
I 4
D 9
	ip_bswap(ip);
	fp = netcb.n_ip_head ? ip_findf(ip) : 0;
E 9
I 9
D 16
	ip->ip_len = ntohs(ip->ip_len);
E 16
I 16
	ip->ip_len = ntohs((u_short)ip->ip_len);
I 67
	if (ip->ip_len < hlen) {
		ipstat.ips_badlen++;
		goto bad;
	}
E 67
E 16
	ip->ip_id = ntohs(ip->ip_id);
D 18
	ip->ip_off = ntohs(ip->ip_off);
E 18
I 18
	ip->ip_off = ntohs((u_short)ip->ip_off);
I 25
D 59
#endif
E 59
E 25
E 18
E 9
E 4

D 4
	ip_bswap(ip);                   /* byte-swap header */

	netcb.n_ip_lock++;      /* lock frag reass.q */
	fp = ip_findf(ip);      /* look for chain on reass.q with this hdr */

	/* adjust message length to remove any padding */

E 4
I 4
	/*
D 9
	 * adjust message length to remove any padding
E 9
I 9
	 * Check that the amount of data in the buffers
	 * is as at least much as the IP header would have us expect.
	 * Trim mbufs if longer than we expect.
	 * Drop packet if shorter than we expect.
E 9
	 */
I 19
D 20
	printf("ip_input: %d:", ip->ip_len);
E 20
E 19
E 4
D 9
	for (i=0, m=mp; m != NULL; m = m->m_next) {
E 9
I 9
D 41
	i = 0;
E 41
I 41
D 85
	i = -ip->ip_len;
E 85
I 85
	i = -(u_short)ip->ip_len;
E 85
E 41
D 19
	for (; m != NULL; m = m->m_next)
E 19
I 19
D 20
	for (; m != NULL; m = m->m_next) {
E 20
I 20
D 21
	for (; m != NULL; m = m->m_next)
E 21
I 21
D 23
	for (m0 = m; m != NULL; m = m->m_next)
E 23
I 23
	m0 = m;
D 33
	for (; m != NULL; m = m->m_next)
E 33
I 33
D 41
	for (; m != NULL; m = m->m_next) {
		if (m->m_free) panic("ipinput already free");
E 41
I 41
	for (;;) {
E 41
E 33
E 23
E 21
E 20
E 19
E 9
		i += m->m_len;
I 41
		if (m->m_next == 0)
			break;
		m = m->m_next;
E 41
I 33
	}
E 33
I 19
D 20
		printf(" %d", m->m_len);
	}
	printf("\n");
E 20
E 19
D 9
		n = m;
	}
	i -= ip->ip_len;

D 4
	if (i != 0) 
E 4
I 4
	if (i != 0)
E 4
        	if (i > (int)n->m_len)
        		m_adj(mp, -i);
        	else
        		n->m_len -= i;

	ip->ip_len -= hlen;     /* length of data */
D 4
  	ip->ip_mff = ((ip->ip_off & ip_mf) ? TRUE : FALSE);                
	ip->ip_off <<= 3;                                                 
	if (!ip->ip_mff && ip->ip_off == 0) {    /* not fragmented */
E 4
I 4
  	ip->ip_mff = ((ip->ip_off & ip_mf) ? TRUE : FALSE);
	ip->ip_off <<= 3;
	if (ip->ip_mff || ip->ip_off)
		goto fragged;
	if (fp != NULL) {
		q = fp->iqx.ip_next;
		while (q != (struct ip *)fp) {
			m_freem(dtom(q));
			q = q->ip_next;
E 9
I 9
D 41
	m = m0;
I 25
D 26
printf("ip->ip_len %d, i %d\n", ip->ip_len , i);
E 26
E 25
	if (i != ip->ip_len) {
D 20
		if (i < ip->ip_len) {
			printf("ip_input: short packet\n");
E 20
I 20
D 23
		if (i < ip->ip_len)
E 23
I 23
		if (i < ip->ip_len) {
E 41
I 41
	if (i != 0) {
		if (i < 0) {
E 41
			ipstat.ips_tooshort++;
I 79
			m = m0;
E 79
E 23
E 20
D 18
			m_freem(m);
			return;
E 18
I 18
			goto bad;
I 23
		}
E 23
E 18
E 9
D 20
		}
I 19
		printf("m_adj %d\n", ip->ip_len - i);
E 20
E 19
D 9
		ip_freef(fp);           /* free header */
E 9
I 9
D 41
		m_adj(m, ip->ip_len - i);
E 41
I 41
		if (i <= m->m_len)
			m->m_len -= i;
		else
			m_adj(m0, -i);
E 41
E 9
	}
I 41
	m = m0;
E 41
D 9
	if (hlen > sizeof (struct ip))
		ip_opt(ip, hlen);
	switch (ip->ip_p) {
E 9
E 4

D 4
		if (fp != NULL) {               /* free existing reass.q chain */
		        
			q = fp->iqx.ip_next;    /* free mbufs assoc. w/chain */
			while (q != (struct ip *)fp) {
				m_freem(dtom(q));
				q = q->ip_next;
			}
			ip_freef(fp);           /* free header */
		} 
		netcb.n_ip_lock = 0;
E 4
I 4
D 9
	case TCPROTO:
		tcp_input(mp);
		break;
E 4

D 4
		ip_opt(ip, hlen);               /* option processing */
		i = ip->ip_p;
E 4
I 4
	default:
		raw_input(mp, ip->ip_p, UIP);
		break;
	}
	return;
E 4

D 4
		/* pass to next level */
E 4
I 4
fragged:
	/* -> msg buf beyond ip hdr if not first fragment */
E 4

D 4
		if (i == TCPROTO)
			tcp_input(mp);
		else
			raw_input(mp, i, UIP);
E 4
I 4
	if (ip->ip_off != 0) {
		mp->m_off += hlen;
		mp->m_len -= hlen;
	}
E 4

D 4
	} else {                                /* fragmented */
E 4
I 4
	if (fp == NULL) {               /* first fragment of datagram in */
E 4

D 4
        	/* -> msg buf beyond ip hdr if not first fragment */
E 4
I 4
	/* set up reass.q header: enq it, set up as head of frag
	   chain, set a timer value, and move in ip header */
E 4

D 4
		if (ip->ip_off != 0) {
                	mp->m_off += hlen;
                	mp->m_len -= hlen;
E 4
I 4
		if ((m = m_get(1)) == NULL) {   /* allocate an mbuf */
			m_freem(mp);
E 9
I 9
	/*
	 * Process options and, if not destined for us,
D 43
	 * ship it on.
E 43
I 43
	 * ship it on.  ip_dooptions returns 1 when an
	 * error was detected (causing an icmp message
D 83
	 * to be sent).
E 83
I 83
	 * to be sent and the original packet to be freed).
E 83
E 43
	 */
I 85
	ip_nhops = 0;		/* for source routed packets */
E 85
I 25
D 26
printf("ipintr at option code\n");
E 26
E 25
D 43
	if (hlen > sizeof (struct ip))
D 16
		ip_dooptions(ip, hlen);
E 16
I 16
		ip_dooptions(ip);
E 43
I 43
D 89
	if (hlen > sizeof (struct ip) && ip_dooptions(ip))
E 89
I 89
	if (hlen > sizeof (struct ip) && ip_dooptions(ip, ifp))
E 89
		goto next;
E 43
E 16
D 19
	if (ip->ip_dst.s_addr != n_lhost.s_addr) {
E 19
I 19
D 21
	if (ip->ip_dst.s_addr != n_lhost.s_addr &&
E 21
I 21
D 37
	if (ifnet && ip->ip_dst.s_addr != ifnet->if_addr.s_addr &&
I 33
D 34
	    ip->ip_dst.s_addr != ifnet->if_broadaddr.s_addr &&
E 34
E 33
E 21
	    if_ifwithaddr(ip->ip_dst) == 0) {
E 37
I 30
D 34
printf("ip->ip_dst %x ip->ip_ttl %x\n", ip->ip_dst, ip->ip_ttl);
I 33
		if (1)
			goto bad;
E 34
I 34

D 37
		goto bad;
#ifdef notdef
		printf("ip->ip_dst %x ip->ip_ttl %x\n",
		    ip->ip_dst, ip->ip_ttl);
E 34
E 33
E 30
E 19
		if (--ip->ip_ttl == 0) {
E 37
I 37
	/*
D 38
	 * Fast check on the first interface in the list.
E 38
I 38
D 82
	 * Fast check on the first internet
	 * interface in the list.
E 82
I 82
	 * Check our list of addresses, to see if the packet is for us.
E 82
E 38
	 */
D 82
	if (ifinet) {
		struct sockaddr_in *sin;
E 82
I 82
	for (ia = in_ifaddr; ia; ia = ia->ia_next) {
#define	satosin(sa)	((struct sockaddr_in *)(sa))
E 82

D 82
		sin = (struct sockaddr_in *)&ifinet->if_addr;
		if (sin->sin_addr.s_addr == ip->ip_dst.s_addr)
			goto ours;
I 42
		sin = (struct sockaddr_in *)&ifinet->if_broadaddr;
E 42
I 38
		if ((ifinet->if_flags & IFF_BROADCAST) &&
		    sin->sin_addr.s_addr == ip->ip_dst.s_addr)
			goto ours;
E 82
I 82
		if (IA_SIN(ia)->sin_addr.s_addr == ip->ip_dst.s_addr)
D 85
			break;
E 85
I 85
			goto ours;
E 85
D 86
		if ((ia->ia_ifp->if_flags & IFF_BROADCAST) &&
		    satosin(&ia->ia_broadaddr)->sin_addr.s_addr ==
			ip->ip_dst.s_addr)
D 85
			    break;
E 85
I 85
			    goto ours;
E 85
		/*
		 * Look for all-0's host part (old broadcast addr).
		 */
		if ((ia->ia_ifp->if_flags & IFF_BROADCAST) &&
		    ia->ia_subnet == ntohl(ip->ip_dst.s_addr))
D 85
			break;
E 85
I 85
			goto ours;
E 86
I 86
		if (
#ifdef	DIRECTED_BROADCAST
		    ia->ia_ifp == ifp &&
#endif
		    (ia->ia_ifp->if_flags & IFF_BROADCAST)) {
D 90
			u_long i;
E 90
I 90
			u_long t;
E 90

			if (satosin(&ia->ia_broadaddr)->sin_addr.s_addr ==
			    ip->ip_dst.s_addr)
				goto ours;
			if (ip->ip_dst.s_addr == ia->ia_netbroadcast.s_addr)
				goto ours;
			/*
			 * Look for all-0's host part (old broadcast addr),
			 * either for subnet or net.
			 */
D 90
			i = ntohl(ip->ip_dst.s_addr);
			if (i == ia->ia_subnet)
E 90
I 90
			t = ntohl(ip->ip_dst.s_addr);
			if (t == ia->ia_subnet)
E 90
				goto ours;
D 90
			if (i == ia->ia_net)
E 90
I 90
			if (t == ia->ia_net)
E 90
				goto ours;
		}
E 86
E 85
E 82
E 38
	}
I 64
D 80
/* BEGIN GROT */
#include "nd.h"
#if NND > 0
	/*
	 * Diskless machines don't initially know
	 * their address, so take packets from them
	 * if we're acting as a network disk server.
	 */
D 70
	if (ip->ip_dst.s_addr == INADDR_ANY &&
E 70
I 70
	if (in_netof(ip->ip_dst) == INADDR_ANY &&
E 70
	    (in_netof(ip->ip_src) == INADDR_ANY &&
	     in_lnaof(ip->ip_src) != INADDR_ANY))
		goto ours;
#endif
/* END GROT */
E 80
E 64
D 82
	ipaddr.sin_addr = ip->ip_dst;
	if (if_ifwithaddr((struct sockaddr *)&ipaddr) == 0) {
E 82
I 82
D 85
	if (ia == (struct in_ifaddr *)0) {
E 82
D 39
		register struct rtentry *rt;

printf("forward: dst %x ttl %x\n", ip->ip_dst, ip->ip_ttl);
E 39
I 39
D 40
printf("forward: src %x dst %x ttl %x\n", ip->ip_src, ip->ip_dst, ip->ip_ttl);
E 40
I 40
D 43
		if (ipprintfs)
			printf("forward: src %x dst %x ttl %x\n", ip->ip_src,
				ip->ip_dst, ip->ip_ttl);
E 40
E 39
		if (ipforwarding == 0)
			goto bad;
		if (ip->ip_ttl < IPTTLDEC) {
E 37
D 16
			icmp_error(ip, ICMP_TIMXCEED);
E 16
I 16
			icmp_error(ip, ICMP_TIMXCEED, 0);
E 16
E 9
D 21
			return;
E 21
I 21
			goto next;
E 21
E 4
		}
I 37
		ip->ip_ttl -= IPTTLDEC;
E 37
D 9

D 4
		if (fp == NULL) {               /* first fragment of datagram in */
E 4
I 4
D 6
		fp = (struct ipq *)((int)m + MHEAD);
E 6
I 6
		fp = (struct ipq *)((int)m + MMINOFF);
E 6
		fp->iqx.ip_next = fp->iqx.ip_prev = (struct ip *)fp;
		bcopy(ip, &fp->iqh, min(MLEN-28, hlen));
		fp->iqh.ip_ttl = MAXTTL;
		fp->iq_next = NULL;
		fp->iq_prev = netcb.n_ip_tail;
		if (netcb.n_ip_head != NULL)
			netcb.n_ip_tail->iq_next = fp;
		else
			netcb.n_ip_head = fp;
		netcb.n_ip_tail = fp;
E 9
I 9
D 21
		ip_output(dtom(ip));
		return;
E 21
I 21
D 22
		ip_output(dtom(ip), (struct mbuf *)0);
E 22
I 22
D 25
		(void) ip_output(dtom(ip), (struct mbuf *)0);
E 25
I 25
		mopt = m_get(M_DONTWAIT);
		if (mopt == 0)
			goto bad;
		ip_stripoptions(ip, mopt);
I 37

D 38
		/*
		 * Check the routing table in case we should
		 * munge the src address before it gets passed on.
		 */
		ipaddr.sin_addr = ip->ip_src;
		rt = reroute(&ipaddr);
		if (rt && (rt->rt_flags & RTF_MUNGE)) {
			struct sockaddr_in *sin;

			sin = (struct sockaddr_in *)&rt->rt_dst;
			ip->ip_src = sin->sin_addr;
		}
E 37
D 34
		(void) ip_output(m0, mopt);
E 34
I 34
		/* 0 here means no directed broadcast */
E 38
I 38
		/* last 0 here means no directed broadcast */
E 38
D 37
		(void) ip_output(m0, mopt, 0);
E 37
I 37
		(void) ip_output(m0, mopt, 0, 0);
E 43
I 43
		ip_forward(ip);
E 43
E 37
E 34
E 25
E 22
		goto next;
I 34
D 37
#endif
E 37
E 34
E 21
E 9
	}
E 85
I 85
	if (ip->ip_dst.s_addr == (u_long)INADDR_BROADCAST)
		goto ours;
	if (ip->ip_dst.s_addr == INADDR_ANY)
		goto ours;
E 85
E 4

I 37
D 82
ours:
E 82
E 37
D 4
		/* set up reass.q header: enq it, set up as head of frag
		   chain, set a timer value, and move in ip header */
E 4
I 4
D 9
	/***********************************************************
	*                                                          *
	*              merge fragment into reass.q                 *
	*    algorithm:   match  start  and  end  bytes  of new    *
	*    fragment  with  fragments  on  the  queue.   if   no  *
	*    overlaps  are  found,  add  new  frag. to the queue.  *
	*    otherwise, adjust start and end of new frag.  so  no  *
	*    overlap   and   add  remainder  to  queue.   if  any  *
	*    fragments are completely covered by the new one,  or  *
	*    if  the  new  one is completely duplicated, free the  *
	*    fragments.                                            *
	*                                                          *
	***********************************************************/
E 9
I 9
	/*
I 85
	 * Not for us; forward if possible and desirable.
	 */
	ip_forward(ip, ifp);
	goto next;

ours:
	/*
E 85
D 108
	 * Look for queue of fragments
	 * of this datagram.
E 108
I 108
	 * If offset or IP_MF are set, must reassemble.
	 * Otherwise, nothing need be done.
	 * (We could look in the reassembly queue to see
	 * if the packet was previously fragmented,
	 * but it's not worth the time; just let them time out.)
E 108
	 */
D 108
	for (fp = ipq.next; fp != &ipq; fp = fp->next)
		if (ip->ip_id == fp->ipq_id &&
		    ip->ip_src.s_addr == fp->ipq_src.s_addr &&
		    ip->ip_dst.s_addr == fp->ipq_dst.s_addr &&
		    ip->ip_p == fp->ipq_p)
			goto found;
	fp = 0;
E 108
I 108
	if (ip->ip_off &~ IP_DF) {
		/*
		 * Look for queue of fragments
		 * of this datagram.
		 */
		for (fp = ipq.next; fp != &ipq; fp = fp->next)
			if (ip->ip_id == fp->ipq_id &&
			    ip->ip_src.s_addr == fp->ipq_src.s_addr &&
			    ip->ip_dst.s_addr == fp->ipq_dst.s_addr &&
			    ip->ip_p == fp->ipq_p)
				goto found;
		fp = 0;
E 108
found:
E 9
E 4

D 4
			if ((m = m_get(1)) == NULL) {   /* allocate an mbuf */
				m_freem(mp);
				return;
			}
E 4
I 4
D 9
	q = fp->iqx.ip_next;    /* -> top of reass. chain */
	ip->ip_end = ip->ip_off + ip->ip_len - 1;
E 9
I 9
D 108
	/*
	 * Adjust ip_len to not reflect header,
	 * set ip_mff if more fragments are expected,
	 * convert offset of this to bytes.
	 */
	ip->ip_len -= hlen;
D 15
	ip->ip_mff = 0;
E 15
I 15
	((struct ipasfrag *)ip)->ipf_mff = 0;
E 15
	if (ip->ip_off & IP_MF)
D 15
		ip->ip_mff = 1;
E 15
I 15
		((struct ipasfrag *)ip)->ipf_mff = 1;
E 15
	ip->ip_off <<= 3;
E 108
I 108
		/*
		 * Adjust ip_len to not reflect header,
		 * set ip_mff if more fragments are expected,
		 * convert offset of this to bytes.
		 */
		ip->ip_len -= hlen;
		((struct ipasfrag *)ip)->ipf_mff = 0;
		if (ip->ip_off & IP_MF)
			((struct ipasfrag *)ip)->ipf_mff = 1;
		ip->ip_off <<= 3;
E 108
E 9
E 4

D 4
			fp = (struct ipq *)((int)m + MHEAD);
			fp->iqx.ip_next = fp->iqx.ip_prev = (struct ip *)fp; 
			bcopy(ip, &fp->iqh, min(MLEN-28, hlen));
			fp->iqh.ip_ttl = MAXTTL;
			fp->iq_next = NULL;                   
			fp->iq_prev = netcb.n_ip_tail;
			if (netcb.n_ip_head != NULL) 
				netcb.n_ip_tail->iq_next = fp;
			else 
				netcb.n_ip_head = fp;
			netcb.n_ip_tail = fp;
		} 
E 4
I 4
D 9
	/* skip frags which new doesn't overlap at end */
E 9
I 9
D 108
	/*
	 * If datagram marked as having more fragments
	 * or if this is not the first fragment,
	 * attempt reassembly; if it succeeds, proceed.
	 */
D 15
	if (ip->ip_mff || ip->ip_off) {
		ip = ip_reass(ip, fp);
E 15
I 15
	if (((struct ipasfrag *)ip)->ipf_mff || ip->ip_off) {
I 85
		ipstat.ips_fragments++;
E 85
		ip = ip_reass((struct ipasfrag *)ip, fp);
E 15
		if (ip == 0)
D 21
			return;
E 21
I 21
			goto next;
E 21
D 85
		hlen = ip->ip_hl << 2;
E 85
		m = dtom(ip);
	} else
		if (fp)
D 65
			(void) ip_freef(fp);
E 65
I 65
			ip_freef(fp);
E 108
I 108
		/*
		 * If datagram marked as having more fragments
		 * or if this is not the first fragment,
		 * attempt reassembly; if it succeeds, proceed.
		 */
		if (((struct ipasfrag *)ip)->ipf_mff || ip->ip_off) {
			ipstat.ips_fragments++;
			ip = ip_reass((struct ipasfrag *)ip, fp);
			if (ip == 0)
				goto next;
			m = dtom(ip);
		} else
			if (fp)
				ip_freef(fp);
	} else
		ip->ip_len -= hlen;
E 108
E 65
I 18

	/*
	 * Switch out to protocol's input routine.
	 */
I 25
D 26
printf("ipintr switching out to protocol %d\n", ip->ip_p);
E 26
E 25
E 18
E 9
E 4
D 15

D 4
                /***********************************************************
                *                                                          *
                *              merge fragment into reass.q                 *
                *    algorithm:   match  start  and  end  bytes  of new    *
                *    fragment  with  fragments  on  the  queue.   if   no  *
                *    overlaps  are  found,  add  new  frag. to the queue.  *
                *    otherwise, adjust start and end of new frag.  so  no  *
                *    overlap   and   add  remainder  to  queue.   if  any  *
                *    fragments are completely covered by the new one,  or  *
                *    if  the  new  one is completely duplicated, free the  *
                *    fragments.                                            *
                *                                                          *
                ***********************************************************/   
E 4
I 4
D 9
	while ((q != (struct ip *)fp) && (ip->ip_off > q->ip_end))
		q = q->ip_next;
E 9
I 9
	/*
	 * Switch out to protocol specific routine.
	 * SHOULD GO THROUGH PROTOCOL SWITCH TABLE
	 */
	switch (ip->ip_p) {
E 9
E 4

D 4
	        q = fp->iqx.ip_next;    /* -> top of reass. chain */
		ip->ip_end = ip->ip_off + ip->ip_len - 1;
E 4
I 4
D 9
	if (q == (struct ip *)fp)               /* frag at end of chain */
		ip_enq(ip, fp->iqx.ip_prev);
	
	else {
		if (ip->ip_end < q->ip_off)     /* frag doesn't overlap any on chain */
			ip_enq(ip, q->ip_prev);
E 9
I 9
	case IPPROTO_ICMP:
		icmp_input(m);
		break;
E 9
E 4

D 4
		/* skip frags which new doesn't overlap at end */
E 4
I 4
D 9
		/* new overlaps beginning of next frag only */
E 9
I 9
	case IPPROTO_TCP:
		if (hlen > sizeof (struct ip))
			ip_stripoptions(ip, hlen);
		tcp_input(m);
		break;
E 9
E 4

D 4
		while ((q != (struct ip *)fp) && (ip->ip_off > q->ip_end))
			q = q->ip_next;

		if (q == (struct ip *)fp)               /* frag at end of chain */
			ip_enq(ip, fp->iqx.ip_prev);
		
		else {  
			if (ip->ip_end < q->ip_off)     /* frag doesn't overlap any on chain */
E 4
I 4
D 9
		else if (ip->ip_end < q->ip_end) {
			if ((i = ip->ip_end - q->ip_off + 1) < ip->ip_len) {
				ip->ip_len -= i;
				ip->ip_end -= i;
				m_adj(mp, -i);
E 4
				ip_enq(ip, q->ip_prev);
I 4
			} else
				m_freem(mp);
E 9
I 9
	case IPPROTO_UDP:
		if (hlen > sizeof (struct ip))
			ip_stripoptions(ip, hlen);
		udp_input(m);
		break;
E 9
E 4

D 4
			/* new overlaps beginning of next frag only */
E 4
I 4
D 9
		/* new overlaps end of previous frag */
E 9
I 9
	default:
D 14
		raw_input(m);
E 14
I 14
		ri_input(m);
E 14
		break;
	}
E 15
I 15
D 60
	(*protosw[ip_protox[ip->ip_p]].pr_input)(m);
E 60
I 60
D 85
	(*inetsw[ip_protox[ip->ip_p]].pr_input)(m);
E 85
I 85
	(*inetsw[ip_protox[ip->ip_p]].pr_input)(m, ifp);
E 85
E 60
I 18
D 21
	return;
E 21
I 21
	goto next;
E 21
bad:
I 27
D 29
printf("ip_input bad!\n");
E 29
E 27
	m_freem(m);
I 21
	goto next;
E 21
E 18
E 15
}
E 9
E 4

D 4
			else if (ip->ip_end < q->ip_end) {
				if ((i = ip->ip_end - q->ip_off + 1) < ip->ip_len) {
        				ip->ip_len -= i;
        				ip->ip_end -= i;
					m_adj(mp, -i);
					ip_enq(ip, q->ip_prev);
E 4
I 4
D 9
		} else {
E 9
I 9
/*
 * Take incoming datagram fragment and try to
D 18
 * reassamble it into whole datagram.  If a chain for
E 18
I 18
 * reassemble it into whole datagram.  If a chain for
E 18
 * reassembly of this datagram already exists, then it
 * is given as fp; otherwise have to make a chain.
 */
struct ip *
ip_reass(ip, fp)
D 15
	register struct ip *ip;
E 15
I 15
	register struct ipasfrag *ip;
E 15
	register struct ipq *fp;
{
	register struct mbuf *m = dtom(ip);
D 15
	register struct ip *q;
E 15
I 15
	register struct ipasfrag *q;
E 15
	struct mbuf *t;
	int hlen = ip->ip_hl << 2;
	int i, next;
I 18
D 47
COUNT(IP_REASS);
E 47
E 18
E 9

D 9
			savq = q;
			if (ip->ip_off <= q->ip_off) {  /* complete cover */
				savq = q->ip_prev;
				ip_deq(q);
				m_freem(dtom(q));
			
			} else {                        /* overlap */
				if ((i = q->ip_end - ip->ip_off + 1) < ip->ip_len) {
					ip->ip_off += i;
					ip->ip_len -= i;
					m_adj(mp, i);
E 4
				} else
D 4
					m_freem(mp);
E 4
I 4
					ip->ip_len = 0;
			}
E 9
I 9
	/*
	 * Presence of header sizes in mbufs
	 * would confuse code below.
	 */
	m->m_off += hlen;
	m->m_len -= hlen;
E 9
E 4

D 4
			/* new overlaps end of previous frag */
E 4
I 4
D 9
		/* new overlaps at beginning of successor frags */
E 9
I 9
	/*
	 * If first fragment to arrive, create a reassembly queue.
	 */
	if (fp == 0) {
D 32
		if ((t = m_get(1)) == NULL)
E 32
I 32
D 61
		if ((t = m_get(M_WAIT)) == NULL)
E 61
I 61
D 101
		if ((t = m_get(M_WAIT, MT_FTABLE)) == NULL)
E 101
I 101
		if ((t = m_get(M_DONTWAIT, MT_FTABLE)) == NULL)
E 101
E 61
E 32
			goto dropfrag;
D 52
		t->m_off = MMINOFF;
E 52
		fp = mtod(t, struct ipq *);
		insque(fp, &ipq);
		fp->ipq_ttl = IPFRAGTTL;
		fp->ipq_p = ip->ip_p;
		fp->ipq_id = ip->ip_id;
D 15
		fp->ipq_next = fp->ipq_prev = (struct ip *)fp;
		fp->ipq_src = ip->ip_src;
		fp->ipq_dst = ip->ip_dst;
E 15
I 15
		fp->ipq_next = fp->ipq_prev = (struct ipasfrag *)fp;
		fp->ipq_src = ((struct ip *)ip)->ip_src;
		fp->ipq_dst = ((struct ip *)ip)->ip_dst;
I 23
		q = (struct ipasfrag *)fp;
		goto insert;
E 23
E 15
	}
E 9
E 4

D 4
			} else {
E 4
I 4
D 9
			q = savq->ip_next;
			while ((q != (struct ip *)fp) && (ip->ip_len != 0) &&
				(q->ip_off < ip->ip_end))
E 9
I 9
	/*
	 * Find a segment which begins after this one does.
	 */
D 15
	for (q = fp->ipq_next; q != (struct ip *)fp; q = q->ip_next)
E 15
I 15
	for (q = fp->ipq_next; q != (struct ipasfrag *)fp; q = q->ipf_next)
E 15
		if (q->ip_off > ip->ip_off)
			break;
E 9
E 4

D 4
				savq = q;
				if (ip->ip_off <= q->ip_off) {  /* complete cover */
					savq = q->ip_prev;
E 4
I 4
D 9
				/* complete cover */
E 9
I 9
	/*
	 * If there is a preceding segment, it may provide some of
	 * our data already.  If so, drop the data from the incoming
	 * segment.  If it provides all of our data, drop us.
	 */
D 15
	if (q->ip_prev != (struct ip *)fp) {
		i = q->ip_prev->ip_off + q->ip_prev->ip_len - ip->ip_off;
E 15
I 15
	if (q->ipf_prev != (struct ipasfrag *)fp) {
		i = q->ipf_prev->ip_off + q->ipf_prev->ip_len - ip->ip_off;
E 15
		if (i > 0) {
			if (i >= ip->ip_len)
				goto dropfrag;
			m_adj(dtom(ip), i);
			ip->ip_off += i;
			ip->ip_len -= i;
		}
	}
E 9

D 9
				if (q->ip_end <= ip->ip_end) {
					p = q->ip_next;
E 4
					ip_deq(q);
					m_freem(dtom(q));
D 4
				  
				} else {                        /* overlap */
					if ((i = q->ip_end - ip->ip_off + 1) < ip->ip_len) {
        					ip->ip_off += i;  
        					ip->ip_len -= i;  
        					m_adj(mp, i);
E 4
I 4
					q = p;

				} else {        /* overlap */

					if ((i = ip->ip_end - q->ip_off + 1) < ip->ip_len) {
						ip->ip_len -= i;
						ip->ip_end -= i;
						m_adj(mp, -i);
E 4
					} else
						ip->ip_len = 0;
I 4
					break;
E 4
				}

D 4
			/* new overlaps at beginning of successor frags */
E 4
I 4
		/* enqueue whatever is left of new before successors */
E 4

D 4
				q = savq->ip_next;
				while ((q != (struct ip *)fp) && (ip->ip_len != 0) && 
					(q->ip_off < ip->ip_end)) 

					/* complete cover */

					if (q->ip_end <= ip->ip_end) {
						p = q->ip_next;
						ip_deq(q);
						m_freem(dtom(q));
						q = p;

					} else {        /* overlap */

						if ((i = ip->ip_end - q->ip_off + 1) < ip->ip_len) {
        						ip->ip_len -= i;
        						ip->ip_end -= i;
        						m_adj(mp, -i);
						} else
							ip->ip_len = 0;
						break;
					}

			/* enqueue whatever is left of new before successors */

				if (ip->ip_len != 0)
					ip_enq(ip, savq);
				else
					m_freem(mp);
			}
E 4
I 4
			if (ip->ip_len != 0)
				ip_enq(ip, savq);
			else
				m_freem(mp);
E 9
I 9
	/*
	 * While we overlap succeeding segments trim them or,
	 * if they are completely covered, dequeue them.
	 */
D 15
	while (q != (struct ip *)fp && ip->ip_off + ip->ip_len > q->ip_off) {
E 15
I 15
	while (q != (struct ipasfrag *)fp && ip->ip_off + ip->ip_len > q->ip_off) {
E 15
		i = (ip->ip_off + ip->ip_len) - q->ip_off;
		if (i < q->ip_len) {
			q->ip_len -= i;
I 35
			q->ip_off += i;
E 35
			m_adj(dtom(q), i);
			break;
E 9
E 4
		}
I 9
D 15
		q = q->ip_next;
		m_freem(dtom(q->ip_prev));
		ip_deq(q->ip_prev);
E 15
I 15
		q = q->ipf_next;
		m_freem(dtom(q->ipf_prev));
		ip_deq(q->ipf_prev);
E 15
E 9
I 4
	}
E 4

I 23
insert:
E 23
D 4
		/* check for completed fragment reassembly */
E 4
I 4
D 9
	/* check for completed fragment reassembly */
E 9
I 9
	/*
	 * Stick new segment in its place;
	 * check for complete reassembly.
	 */
D 15
	ip_enq(ip, q->ip_prev);
E 15
I 15
	ip_enq(ip, q->ipf_prev);
E 15
	next = 0;
D 15
	for (q = fp->ipq_next; q != (struct ip *)fp; q = q->ip_next) {
E 15
I 15
	for (q = fp->ipq_next; q != (struct ipasfrag *)fp; q = q->ipf_next) {
E 15
		if (q->ip_off != next)
			return (0);
		next += q->ip_len;
	}
D 15
	if (q->ip_prev->ip_mff)
E 15
I 15
	if (q->ipf_prev->ipf_mff)
E 15
		return (0);
E 9
E 4

D 4
		if ((i = ip_done(fp)) > 0) {
E 4
I 4
D 9
	if ((i = ip_done(fp)) == 0)
		return;
E 9
I 9
	/*
	 * Reassembly is complete; concatenate fragments.
	 */
	q = fp->ipq_next;
	m = dtom(q);
	t = m->m_next;
	m->m_next = 0;
	m_cat(m, t);
D 15
	while ((q = q->ip_next) != (struct ip *)fp)
E 15
I 15
D 36
	while ((q = q->ipf_next) != (struct ipasfrag *)fp)
E 15
		m_cat(m, dtom(q));
E 36
I 36
	q = q->ipf_next;
	while (q != (struct ipasfrag *)fp) {
		t = dtom(q);
		q = q->ipf_next;
		m_cat(m, t);
	}
E 36
E 9
E 4

D 4
			p = fp->iqx.ip_next;            /* -> top mbuf */
			m = dtom(p);
			p->ip_len = i;                  /* total data length */
			ip_opt(p, p->ip_hl << 2);       /* option processing */
			ip_mergef(fp);                  /* cleanup frag chain */
E 4
I 4
D 9
	p = fp->iqx.ip_next;            /* -> top mbuf */
	m = dtom(p);
	p->ip_len = i;                  /* total data length */
	ip_opt(p, p->ip_hl << 2);       /* option processing */
	ip_mergef(fp);                  /* cleanup frag chain */
E 9
I 9
	/*
	 * Create header for new ip packet by
	 * modifying header of first packet;
	 * dequeue and discard fragment reassembly header.
	 * Make header visible.
	 */
	ip = fp->ipq_next;
	ip->ip_len = next;
D 15
	ip->ip_src = fp->ipq_src;
	ip->ip_dst = fp->ipq_dst;
E 15
I 15
	((struct ip *)ip)->ip_src = fp->ipq_src;
	((struct ip *)ip)->ip_dst = fp->ipq_dst;
E 15
	remque(fp);
D 16
	m_free(dtom(fp));
E 16
I 16
	(void) m_free(dtom(fp));
E 16
	m = dtom(ip);
D 15
	m->m_len += sizeof (struct ip);
	m->m_off -= sizeof (struct ip);
	return (ip);
E 15
I 15
D 85
	m->m_len += sizeof (struct ipasfrag);
	m->m_off -= sizeof (struct ipasfrag);
E 85
I 85
	m->m_len += (ip->ip_hl << 2);
	m->m_off -= (ip->ip_hl << 2);
E 85
	return ((struct ip *)ip);
E 15
E 9
E 4

D 4
			/* copy src/dst internet address to header mbuf */
E 4
I 4
D 9
	/* copy src/dst internet address to header mbuf */
E 4

D 4
			bcopy(&fp->iqh.ip_src, &p->ip_src, 2*sizeof(struct socket));
			ip_freef(fp);                   /* dequeue header */
			netcb.n_ip_lock = 0;

			/* call next level with completed datagram */

			i = p->ip_p;
			if (i == TCPROTO)
				tcp_input(m);
        		else
				raw_input(m, i, UIP);
		} else
			netcb.n_ip_lock = 0;
	}
E 4
I 4
	bcopy(&fp->iqh.ip_src, &p->ip_src, 2*sizeof(struct socket));
	ip_freef(fp);                   /* dequeue header */
	i = p->ip_p;
	if (i == TCPROTO)
		tcp_input(m);
	else
		raw_input(m, i, UIP);
E 9
I 9
dropfrag:
I 85
	ipstat.ips_fragdropped++;
E 85
	m_freem(m);
	return (0);
E 9
E 4
}

D 4

ip_done(p)      /* check to see if fragment reassembly is complete */
register struct ip *p;
E 4
I 4
D 9
ip_done(p)
	register struct ip *p;
E 9
I 9
/*
 * Free a fragment reassembly header and all
 * associated datagrams.
 */
D 65
struct ipq *
E 65
ip_freef(fp)
	struct ipq *fp;
E 9
E 4
{
D 15
	register struct ip *q;
E 15
I 15
D 65
	register struct ipasfrag *q;
E 15
D 9
	register next;
E 9
I 9
	struct mbuf *m;
E 65
I 65
	register struct ipasfrag *q, *p;
E 65
I 18
D 47
COUNT(IP_FREEF);
E 47
E 18
E 9

D 9
COUNT(IP_DONE);
D 4
	q = p->ip_next;                       
E 4
I 4
	q = p->ip_next;
E 4

	if (q->ip_off != 0)
		return(0);
	do {
		next = q->ip_end + 1;
		q = q->ip_next;
	} while ((q != p) && (q->ip_off == next));

	if ((q == p) && !(q->ip_prev->ip_mff))        /* all fragments in */
		return(next);                         /* total data length */
	else
		return(0);
E 9
I 9
D 15
	for (q = fp->ipq_next; q != (struct ip *)fp; q = q->ip_next)
E 15
I 15
D 65
	for (q = fp->ipq_next; q != (struct ipasfrag *)fp; q = q->ipf_next)
E 65
I 65
	for (q = fp->ipq_next; q != (struct ipasfrag *)fp; q = p) {
		p = q->ipf_next;
		ip_deq(q);
E 65
E 15
		m_freem(dtom(q));
D 65
	m = dtom(fp);
	fp = fp->next;
	remque(fp->prev);
D 16
	m_free(m);
E 16
I 16
	(void) m_free(m);
E 16
	return (fp);
E 65
I 65
	}
	remque(fp);
	(void) m_free(dtom(fp));
E 65
E 9
}

D 9
ip_mergef(p)    /* merge mbufs of fragments of completed datagram */
register struct ip *p;
E 9
I 9
/*
 * Put an ip fragment on a reassembly chain.
 * Like insque, but pointers in middle of structure.
 */
ip_enq(p, prev)
D 15
	register struct ip *p;
	register struct ip *prev;
E 15
I 15
	register struct ipasfrag *p, *prev;
E 15
E 9
{
D 9
	register struct mbuf *m, *n;
	register struct ip *q;
	int dummy;
E 9
I 9
D 18
COUNT(IP_ENQ);
E 18
E 9

I 18
D 47
COUNT(IP_ENQ);
E 47
E 18
D 9
COUNT(IP_MERGEF);
	q = p->ip_next;                         /* -> bottom of reass chain */
	n = (struct mbuf *)&dummy;              /* dummy for init assignment */

	while (q != p) {        /* through chain */

	        n->m_next = m = dtom(q);
D 4
		while (m != NULL) 
E 4
I 4
		while (m != NULL)
E 4
			if (m->m_len != 0) {
				n = m;
				m = m->m_next;
			} else                  /* free null mbufs */
				n->m_next = m = m_free(m);
		q = q->ip_next;
	}
E 9
I 9
D 15
	p->ip_prev = prev;
	p->ip_next = prev->ip_next;
	prev->ip_next->ip_prev = p;
	prev->ip_next = p;
E 15
I 15
	p->ipf_prev = prev;
	p->ipf_next = prev->ipf_next;
	prev->ipf_next->ipf_prev = p;
	prev->ipf_next = p;
E 15
E 9
}

D 9

D 4
ip_freef(fp)	        /* deq and free reass.q header */           
E 4
I 4
ip_freef(fp)	        /* deq and free reass.q header */
E 4
register struct ipq *fp;
E 9
I 9
/*
 * To ip_enq as remque is to insque.
 */
ip_deq(p)
D 15
	register struct ip *p;
E 15
I 15
	register struct ipasfrag *p;
E 15
E 9
{
D 9
COUNT(IP_FREEF);
D 4
	if (fp->iq_prev != NULL)                               
		(fp->iq_prev)->iq_next = fp->iq_next;  
	else                                           
		netcb.n_ip_head = fp->iq_next;         
	if (fp->iq_next != NULL)                               
		(fp->iq_next)->iq_prev = fp->iq_prev;  
E 4
I 4
	if (fp->iq_prev != NULL)
		(fp->iq_prev)->iq_next = fp->iq_next;
E 4
	else
I 4
		netcb.n_ip_head = fp->iq_next;
	if (fp->iq_next != NULL)
		(fp->iq_next)->iq_prev = fp->iq_prev;
	else
E 4
		netcb.n_ip_tail = fp->iq_prev;
	m_free(dtom(fp));
E 9
I 9
D 18
COUNT(IP_DEQ);
E 18

I 18
D 47
COUNT(IP_DEQ);
E 47
E 18
D 15
	p->ip_prev->ip_next = p->ip_next;
	p->ip_next->ip_prev = p->ip_prev;
E 15
I 15
	p->ipf_prev->ipf_next = p->ipf_next;
	p->ipf_next->ipf_prev = p->ipf_prev;
E 15
E 9
}

D 4
struct ipq *ip_findf(p)         /* does fragment reass chain w/this hdr exist? */
E 4
I 4
D 9
struct ipq *
ip_findf(p)         /* does fragment reass chain w/this hdr exist? */
E 4
register struct ip *p;
E 9
I 9
/*
 * IP timer processing;
 * if a timer expires on a reassembly
 * queue, discard it.
 */
D 14
ip_timeo()
E 14
I 14
ip_slowtimo()
E 14
E 9
{
I 9
D 15
	register struct ip *q;
E 15
E 9
	register struct ipq *fp;
I 9
	int s = splnet();
D 14
COUNT(IP_TIMEO);
E 14
I 14
D 18
COUNT(IP_SLOWTIMO);
E 18
E 14
E 9

I 18
D 47
COUNT(IP_SLOWTIMO);
E 47
E 18
D 9
COUNT(IP_FINDF);
	for (fp = netcb.n_ip_head; (fp != NULL && (
			p->ip_src.s_addr != fp->iqh.ip_src.s_addr ||
			p->ip_dst.s_addr != fp->iqh.ip_dst.s_addr ||
			p->ip_id != fp->iqh.ip_id ||
			p->ip_p != fp->iqh.ip_p)); fp = fp->iq_next);
	return(fp);
E 9
I 9
D 10
	for (fp = &ipq; fp; )
E 10
I 10
D 28
	for (fp = ipq.next; fp != &ipq; )
E 28
I 28
	fp = ipq.next;
	if (fp == 0) {
		splx(s);
		return;
	}
D 65
	while (fp != &ipq)
E 28
E 10
		if (--fp->ipq_ttl == 0)
			fp = ip_freef(fp);
		else
			fp = fp->next;
E 65
I 65
	while (fp != &ipq) {
		--fp->ipq_ttl;
		fp = fp->next;
D 85
		if (fp->prev->ipq_ttl == 0)
E 85
I 85
		if (fp->prev->ipq_ttl == 0) {
			ipstat.ips_fragtimeout++;
E 85
			ip_freef(fp->prev);
I 85
		}
E 85
	}
E 65
D 14
	timeout(ip_timeo, 0, hz);
E 14
	splx(s);
E 9
}

I 18
/*
 * Drain off all datagram fragments.
 */
E 18
I 14
ip_drain()
{

I 18
D 47
COUNT(IP_DRAIN);
E 47
D 85
	while (ipq.next != &ipq)
E 85
I 85
	while (ipq.next != &ipq) {
		ipstat.ips_fragdropped++;
E 85
D 65
		(void) ip_freef(ipq.next);
E 65
I 65
		ip_freef(ipq.next);
I 85
	}
E 85
E 65
E 18
}
I 17

I 100
extern struct in_ifaddr *ifptoia();
E 100
I 85
struct in_ifaddr *ip_rtaddr();

E 85
E 17
E 14
D 9
ip_opt(ip, hlen)        /* process ip options */
struct ip *ip;
int hlen;
E 9
I 9
/*
 * Do option processing on a datagram,
 * possibly discarding it if bad options
 * are encountered.
 */
D 89
ip_dooptions(ip)
	struct ip *ip;
E 89
I 89
ip_dooptions(ip, ifp)
	register struct ip *ip;
	struct ifnet *ifp;
E 89
E 9
{
D 9
	register char *p, *q;
	register i, len;
	register struct mbuf *m;
E 9
I 9
	register u_char *cp;
D 16
	int opt, optlen, cnt, s;
E 16
I 16
D 43
	int opt, optlen, cnt;
E 43
I 43
D 85
	int opt, optlen, cnt, code, type;
E 43
E 16
D 11
	struct inet_addr *sp;
E 11
I 11
D 14
	struct socket *sp;
E 14
I 14
D 17
	struct ip_addr *sp;
E 17
I 17
	struct in_addr *sin;
E 85
I 85
	int opt, optlen, cnt, off, code, type = ICMP_PARAMPROB;
E 85
E 17
	register struct ip_timestamp *ipt;
I 18
D 82
	register struct ifnet *ifp;
E 82
I 82
D 85
	register struct ifaddr *ifa;
E 82
	struct in_addr t;
E 85
I 85
	register struct in_ifaddr *ia;
	struct in_addr *sin;
	n_time ntime;
E 85
E 18
D 16
	int x;
E 16
E 14
E 11
E 9

I 18
D 47
COUNT(IP_DOOPTIONS);
E 47
E 18
D 9
COUNT(IP_OPT);
	p = q = (char *)((int)ip + sizeof(struct ip));  /* -> at options */
	
	if ((i = hlen - sizeof(struct ip)) > 0) {       /* any options */
E 9
I 9
	cp = (u_char *)(ip + 1);
	cnt = (ip->ip_hl << 2) - sizeof (struct ip);
	for (; cnt > 0; cnt -= optlen, cp += optlen) {
D 85
		opt = cp[0];
E 85
I 85
		opt = cp[IPOPT_OPTVAL];
E 85
		if (opt == IPOPT_EOL)
			break;
		if (opt == IPOPT_NOP)
			optlen = 1;
D 74
		else
E 74
I 74
		else {
E 74
D 85
			optlen = cp[1];
I 74
D 81
			if (optlen <= 0)
				break;
E 81
I 81
			if (optlen <= 0 || optlen >= cnt)
E 85
I 85
			optlen = cp[IPOPT_OLEN];
			if (optlen <= 0 || optlen > cnt) {
				code = &cp[IPOPT_OLEN] - (u_char *)ip;
E 85
				goto bad;
I 85
			}
E 85
E 81
		}
E 74
		switch (opt) {
E 9

D 9
/*      *** IP OPTION PROCESSING ***
E 9
I 9
		default:
			break;
E 9

I 18
		/*
		 * Source routing with record.
		 * Find interface with current destination address.
		 * If none on this machine then drop if strictly routed,
		 * or do nothing if loosely routed.
		 * Record interface address and bring up next address
		 * component.  If strictly routed make sure next
		 * address on directly accessible net.
		 */
E 18
D 9
		while (i > 0)
E 9
I 9
		case IPOPT_LSRR:
I 48
		case IPOPT_SSRR:
E 48
D 18
		case IPOPT_SSRR:
E 18
D 14
			if (cp[2] < 4 || cp[2] > optlen - 3)
E 14
I 14
D 85
			if (cp[2] < 4 || cp[2] > optlen - (sizeof (long) - 1))
E 14
				break;
D 11
			sp = (struct inet_addr *)(cp+cp[2]);
E 11
I 11
D 14
			sp = (struct socket *)(cp+cp[2]);
E 14
I 14
D 17
			sp = (struct ip_addr *)(cp + cp[2]);
E 14
E 11
			if (n_lhost.s_addr == *(u_long *)sp) {
E 17
I 17
			sin = (struct in_addr *)(cp + cp[2]);
D 18
			if (n_lhost.s_addr == *(u_long *)sin) {
E 17
				if (opt == IPOPT_SSRR) {
D 14
					/* make sure *sp directly accessible*/
E 14
I 14
					/* MAKE SURE *SP DIRECTLY ACCESSIBLE */
E 14
				}
D 17
				ip->ip_dst = *sp;
				*sp = n_lhost;
E 17
I 17
				ip->ip_dst = *sin;
				*sin = n_lhost;
E 17
				cp[2] += 4;
E 18
I 18
D 37
			ifp = if_ifwithaddr(*sin);
E 37
I 37
			ipaddr.sin_addr = *sin;
D 82
			ifp = if_ifwithaddr((struct sockaddr *)&ipaddr);
E 82
I 82
			ifa = ifa_ifwithaddr((struct sockaddr *)&ipaddr);
E 82
I 43
			type = ICMP_UNREACH, code = ICMP_UNREACH_SRCFAIL;
E 43
E 37
D 82
			if (ifp == 0) {
E 82
I 82
			if (ifa == 0) {
E 82
				if (opt == IPOPT_SSRR)
E 85
I 85
			if ((off = cp[IPOPT_OFFSET]) < IPOPT_MINOFF) {
				code = &cp[IPOPT_OFFSET] - (u_char *)ip;
				goto bad;
			}
			ipaddr.sin_addr = ip->ip_dst;
			ia = (struct in_ifaddr *)
				ifa_ifwithaddr((struct sockaddr *)&ipaddr);
			if (ia == 0) {
				if (opt == IPOPT_SSRR) {
					type = ICMP_UNREACH;
					code = ICMP_UNREACH_SRCFAIL;
E 85
					goto bad;
I 85
				}
				/*
				 * Loose routing, and not at next destination
				 * yet; nothing to do except forward.
				 */
E 85
				break;
E 18
			}
I 18
D 85
			t = ip->ip_dst; ip->ip_dst = *sin; *sin = t;
			cp[2] += 4;
			if (cp[2] > optlen - (sizeof (long) - 1))
E 85
I 85
			off--;			/* 0 origin */
			if (off > optlen - sizeof(struct in_addr)) {
				/*
				 * End of source route.  Should be for us.
				 */
				save_rte(cp, ip->ip_src);
E 85
				break;
D 85
			ip->ip_dst = sin[1];
D 37
			if (opt == IPOPT_SSRR && if_ifonnetof(ip->ip_dst)==0)
E 37
I 37
			if (opt == IPOPT_SSRR &&
D 46
			    if_ifonnetof(ip->ip_dst.s_net) == 0)
E 46
I 46
D 82
			    if_ifonnetof(in_netof(ip->ip_dst)) == 0)
E 82
I 82
			    in_iaonnetof(in_netof(ip->ip_dst)) == 0)
E 85
I 85
			}
			/*
			 * locate outgoing interface
			 */
D 93
			bcopy(cp + off, (caddr_t)&ipaddr.sin_addr,
E 93
I 93
			bcopy((caddr_t)(cp + off), (caddr_t)&ipaddr.sin_addr,
E 93
			    sizeof(ipaddr.sin_addr));
			if ((opt == IPOPT_SSRR &&
			    in_iaonnetof(in_netof(ipaddr.sin_addr)) == 0) ||
			    (ia = ip_rtaddr(ipaddr.sin_addr)) == 0) {
				type = ICMP_UNREACH;
				code = ICMP_UNREACH_SRCFAIL;
E 85
E 82
E 46
E 37
				goto bad;
I 85
			}
			ip->ip_dst = ipaddr.sin_addr;
D 93
			bcopy(&(IA_SIN(ia)->sin_addr), cp + off,
				sizeof(struct in_addr));
E 93
I 93
			bcopy((caddr_t)&(IA_SIN(ia)->sin_addr),
			    (caddr_t)(cp + off), sizeof(struct in_addr));
E 93
			cp[IPOPT_OFFSET] += sizeof(struct in_addr);
E 85
E 18
			break;
E 9

I 85
		case IPOPT_RR:
			if ((off = cp[IPOPT_OFFSET]) < IPOPT_MINOFF) {
				code = &cp[IPOPT_OFFSET] - (u_char *)ip;
				goto bad;
			}
			/*
			 * If no space remains, ignore.
			 */
			off--;			/* 0 origin */
			if (off > optlen - sizeof(struct in_addr))
				break;
D 91
			bcopy(cp + off, (caddr_t)ipaddr.sin_addr,
E 91
I 91
D 93
			bcopy(cp + off, (caddr_t)&ipaddr.sin_addr,
E 93
I 93
D 102
			bcopy((caddr_t)(cp + off), (caddr_t)&ipaddr.sin_addr,
E 102
I 102
			bcopy((caddr_t)(&ip->ip_dst), (caddr_t)&ipaddr.sin_addr,
E 102
E 93
E 91
			    sizeof(ipaddr.sin_addr));
			/*
			 * locate outgoing interface
			 */
			if ((ia = ip_rtaddr(ipaddr.sin_addr)) == 0) {
				type = ICMP_UNREACH;
D 103
				code = ICMP_UNREACH_SRCFAIL;
E 103
I 103
				code = ICMP_UNREACH_HOST;
E 103
				goto bad;
			}
D 93
			bcopy(&(IA_SIN(ia)->sin_addr), cp + off,
				sizeof(struct in_addr));
E 93
I 93
			bcopy((caddr_t)&(IA_SIN(ia)->sin_addr),
			    (caddr_t)(cp + off), sizeof(struct in_addr));
E 93
			cp[IPOPT_OFFSET] += sizeof(struct in_addr);
			break;

E 85
D 9
  			switch (*q++) {
D 4
			case 0:                 
			case 1:                 
E 4
I 4
			case 0:
			case 1:
E 4
				i--;
E 9
I 9
		case IPOPT_TS:
I 43
			code = cp - (u_char *)ip;
D 85
			type = ICMP_PARAMPROB;
E 85
E 43
D 14
			if (cp[2] < 5)
E 14
I 14
			ipt = (struct ip_timestamp *)cp;
			if (ipt->ipt_len < 5)
E 14
				goto bad;
D 14
			if (cp[2] > cp[1] - 3) {
				if ((cp[3] & 0xf0) == 0xf0)
E 14
I 14
			if (ipt->ipt_ptr > ipt->ipt_len - sizeof (long)) {
				if (++ipt->ipt_oflw == 0)
E 14
					goto bad;
D 14
				cp[3] += 0x10;
E 14
E 9
				break;
I 9
			}
D 11
			sp = (struct inet_addr *)(cp+cp[2]);
E 11
I 11
D 14
			sp = (struct socket *)(cp+cp[2]);
E 11
			switch (cp[3] & 0xf) {
E 14
I 14
D 17
			sp = (struct ip_addr *)(cp+cp[2]);
E 17
I 17
D 85
			sin = (struct in_addr *)(cp+cp[2]);
E 85
I 85
D 100
			sin = (struct in_addr *)(cp+cp[IPOPT_OFFSET]-1);
E 100
I 100
			sin = (struct in_addr *)(cp + ipt->ipt_ptr - 1);
E 100
E 85
E 17
			switch (ipt->ipt_flg) {
E 14
E 9

I 9
			case IPOPT_TS_TSONLY:
				break;

			case IPOPT_TS_TSANDADDR:
D 14
				if (cp[2] > cp[1] - 7)
E 14
I 14
D 85
				if (ipt->ipt_ptr + 8 > ipt->ipt_len)
E 85
I 85
				if (ipt->ipt_ptr + sizeof(n_time) +
				    sizeof(struct in_addr) > ipt->ipt_len)
E 85
E 14
					goto bad;
I 14
D 17
				*(struct ip_addr *)sp++ = n_lhost;
E 17
I 17
D 18
				*(struct in_addr *)sin++ = n_lhost;
E 18
I 18
D 37
				/* stamp with ``first'' interface address */
				*sin++ = ifnet->if_addr;
E 37
I 37
D 82
				if (ifinet == 0)
E 82
I 82
D 100
				if (in_ifaddr == 0)
E 82
					goto bad;	/* ??? */
D 82
				*sin++ = ((struct sockaddr_in *)&ifinet->if_addr)->sin_addr;
E 82
I 82
D 85
				*sin++ = IA_SIN(in_ifaddr)->sin_addr;
E 85
I 85
				bcopy((caddr_t)&IA_SIN(in_ifaddr)->sin_addr,
E 100
I 100
				ia = ifptoia(ifp);
				bcopy((caddr_t)&IA_SIN(ia)->sin_addr,
E 100
				    (caddr_t)sin, sizeof(struct in_addr));
D 100
				sin++;
E 100
I 100
				ipt->ipt_ptr += sizeof(struct in_addr);
E 100
E 85
E 82
E 37
E 18
E 17
E 14
				break;

			case IPOPT_TS_PRESPEC:
I 100
				if (ipt->ipt_ptr + sizeof(n_time) +
				    sizeof(struct in_addr) > ipt->ipt_len)
					goto bad;
E 100
D 17
				if (*(u_long *)sp != n_lhost.s_addr)
E 17
I 17
D 18
				if (*(u_long *)sin != n_lhost.s_addr)
E 17
					break;
E 18
I 18
D 37
				if (if_ifwithaddr(*sin) == 0)
E 37
I 37
D 85
				ipaddr.sin_addr = *sin;
E 85
I 85
				bcopy((caddr_t)sin, (caddr_t)&ipaddr.sin_addr,
				    sizeof(struct in_addr));
E 85
D 43
				if (if_ifwithaddr((struct sockaddr *)&ipaddr) == 0)
E 43
I 43
D 63
				if (!if_ifwithaddr((struct sockaddr *)&ipaddr))
E 63
I 63
D 82
				if (if_ifwithaddr((struct sockaddr *)&ipaddr) == 0)
E 82
I 82
				if (ifa_ifwithaddr((struct sockaddr *)&ipaddr) == 0)
E 82
E 63
E 43
E 37
					continue;
E 18
D 14
				if (cp[2] > cp[1] - 7)
E 14
I 14
D 85
				if (ipt->ipt_ptr + 8 > ipt->ipt_len)
E 85
I 85
D 100
				if (ipt->ipt_ptr + sizeof(n_time) +
				    sizeof(struct in_addr) > ipt->ipt_len)
E 85
E 14
					goto bad;
E 100
D 14
				cp[1] += 4;
E 14
I 14
D 85
				ipt->ipt_ptr += 4;
E 85
I 85
				ipt->ipt_ptr += sizeof(struct in_addr);
E 85
E 14
				break;

E 9
			default:
D 9
				i -= *q;
				q += *q;
E 9
I 9
				goto bad;
E 9
			}
D 9
*/              q += i;
		m = dtom(q);
		len = (int)m + m->m_off + m->m_len - (int)q;
		bcopy((caddr_t)q, (caddr_t)p, len);    /* remove options */
		m->m_len -= i;
E 9
I 9
D 14
			s = spl6();
			*(int *)sp = (time % SECDAY) * 1000 + (lbolt*1000/hz);
			splx(s);
			cp[1] += 4;
E 14
I 14
D 17
			*(n_time *)sp = ip_time();
E 17
I 17
D 85
			*(n_time *)sin = iptime();
E 17
			ipt->ipt_ptr += 4;
E 85
I 85
			ntime = iptime();
D 100
			bcopy((caddr_t)&ntime, (caddr_t)sin, sizeof(n_time));
E 100
I 100
			bcopy((caddr_t)&ntime, (caddr_t)cp + ipt->ipt_ptr - 1,
			    sizeof(n_time));
E 100
			ipt->ipt_ptr += sizeof(n_time);
E 85
E 14
		}
E 9
	}
I 9
D 16
	return (0);
E 16
I 16
D 43
	return;
E 43
I 43
	return (0);
E 43
E 16
bad:
D 43
	/* SHOULD FORCE ICMP MESSAGE */
D 16
	return (-1);
E 16
I 16
	return;
E 43
I 43
D 89
	icmp_error(ip, type, code);
E 89
I 89
	icmp_error(ip, type, code, ifp);
E 89
	return (1);
E 43
E 16
E 9
}

D 9
ip_enq(p, prev)
register struct ip *p;
register struct ip *prev;
E 9
I 9
/*
I 85
 * Given address of next destination (final or next hop),
 * return internet address info of interface to be used to get there.
 */
struct in_ifaddr *
ip_rtaddr(dst)
	 struct in_addr dst;
{
	register struct sockaddr_in *sin;
	register struct in_ifaddr *ia;

	sin = (struct sockaddr_in *) &ipforward_rt.ro_dst;

	if (ipforward_rt.ro_rt == 0 || dst.s_addr != sin->sin_addr.s_addr) {
		if (ipforward_rt.ro_rt) {
			RTFREE(ipforward_rt.ro_rt);
			ipforward_rt.ro_rt = 0;
		}
		sin->sin_family = AF_INET;
		sin->sin_addr = dst;

		rtalloc(&ipforward_rt);
	}
	if (ipforward_rt.ro_rt == 0)
		return ((struct in_ifaddr *)0);
	/*
	 * Find address associated with outgoing interface.
	 */
	for (ia = in_ifaddr; ia; ia = ia->ia_next)
		if (ia->ia_ifp == ipforward_rt.ro_rt->rt_ifp)
			break;
	return (ia);
}

/*
 * Save incoming source route for use in replies,
 * to be picked up later by ip_srcroute if the receiver is interested.
 */
save_rte(option, dst)
D 93
	caddr_t option;
E 93
I 93
	u_char *option;
E 93
	struct in_addr dst;
{
D 93
	int olen;
E 93
I 93
	unsigned olen;
E 93
	extern ipprintfs;

	olen = option[IPOPT_OLEN];
	if (olen > sizeof(ip_srcrt) - 1) {
		if (ipprintfs)
			printf("save_rte: olen %d\n", olen);
		return;
	}
D 93
	bcopy(option, (caddr_t)ip_srcrt.srcopt, olen);
E 93
I 93
	bcopy((caddr_t)option, (caddr_t)ip_srcrt.srcopt, olen);
E 93
	ip_nhops = (olen - IPOPT_OFFSET - 1) / sizeof(struct in_addr);
	ip_srcrt.route[ip_nhops++] = dst;
}

/*
 * Retrieve incoming source route for use in replies,
 * in the same form used by setsockopt.
 * The first hop is placed before the options, will be removed later.
 */
struct mbuf *
ip_srcroute()
{
	register struct in_addr *p, *q;
	register struct mbuf *m;

	if (ip_nhops == 0)
		return ((struct mbuf *)0);
D 101
	m = m_get(M_WAIT, MT_SOOPTS);
E 101
I 101
	m = m_get(M_DONTWAIT, MT_SOOPTS);
	if (m == 0)
		return ((struct mbuf *)0);
E 101
	m->m_len = ip_nhops * sizeof(struct in_addr) + IPOPT_OFFSET + 1 + 1;

	/*
	 * First save first hop for return route
	 */
	p = &ip_srcrt.route[ip_nhops - 1];
	*(mtod(m, struct in_addr *)) = *p--;

	/*
	 * Copy option fields and padding (nop) to mbuf.
	 */
	ip_srcrt.nop = IPOPT_NOP;
	bcopy((caddr_t)&ip_srcrt, mtod(m, caddr_t) + sizeof(struct in_addr),
	    IPOPT_OFFSET + 1 + 1);
	q = (struct in_addr *)(mtod(m, caddr_t) +
	    sizeof(struct in_addr) + IPOPT_OFFSET + 1 + 1);
	/*
	 * Record return path as an IP source route,
	 * reversing the path (pointers are now aligned).
	 */
	while (p >= ip_srcrt.route)
		*q++ = *p--;
	return (m);
}

/*
E 85
D 18
 * Strip out IP options, e.g. before passing
 * to higher level protocol in the kernel.
E 18
I 18
 * Strip out IP options, at higher
 * level protocol in the kernel.
 * Second argument is buffer to which options
 * will be moved, and return value is their length.
E 18
 */
D 18
ip_stripoptions(ip)
E 18
I 18
D 25
ip_stripoptions(ip, cp)
E 25
I 25
ip_stripoptions(ip, mopt)
E 25
E 18
	struct ip *ip;
I 18
D 25
	char *cp;
E 25
I 25
	struct mbuf *mopt;
E 25
E 18
E 9
{
D 9
COUNT(IP_ENQ);
	p->ip_prev = prev;
	p->ip_next = prev->ip_next;
	prev->ip_next->ip_prev = p;
	prev->ip_next = p;
E 9
I 9
	register int i;
	register struct mbuf *m;
I 85
	register caddr_t opts;
E 85
D 16
	char *op;
E 16
	int olen;
D 18
COUNT(IP_OPT);
E 18
I 18
D 47
COUNT(IP_STRIPOPTIONS);
E 47
E 18

	olen = (ip->ip_hl<<2) - sizeof (struct ip);
D 16
	op = (caddr_t)ip + olen;
E 16
D 18
	m = dtom(++ip);
E 18
I 18
	m = dtom(ip);
D 85
	ip++;
E 85
I 85
	opts = (caddr_t)(ip + 1);
E 85
D 25
	if (cp)
		bcopy((caddr_t)ip, cp, (unsigned)olen);
E 25
I 25
	if (mopt) {
		mopt->m_len = olen;
		mopt->m_off = MMINOFF;
D 75
		bcopy((caddr_t)ip, mtod(m, caddr_t), (unsigned)olen);
E 75
I 75
D 85
		bcopy((caddr_t)ip, mtod(mopt, caddr_t), (unsigned)olen);
E 85
I 85
		bcopy(opts, mtod(mopt, caddr_t), (unsigned)olen);
E 85
E 75
	}
E 25
E 18
	i = m->m_len - (sizeof (struct ip) + olen);
D 16
	bcopy((caddr_t)ip+olen, (caddr_t)ip, i);
E 16
I 16
D 85
	bcopy((caddr_t)ip+olen, (caddr_t)ip, (unsigned)i);
E 85
I 85
	bcopy(opts  + olen, opts, (unsigned)i);
E 85
E 16
D 28
	m->m_len -= i;
E 28
I 28
	m->m_len -= olen;
I 85
	ip->ip_hl = sizeof(struct ip) >> 2;
E 85
I 43
}

D 44
static u_char ctlerrmap[] = {
E 44
I 44
D 72
u_char inetctlerrmap[] = {
E 72
I 72
u_char inetctlerrmap[PRC_NCMDS] = {
E 72
E 44
D 85
	ECONNABORTED,	ECONNABORTED,	0,		0,
E 85
I 85
	0,		0,		0,		0,
E 85
D 45
	0,
#ifdef notdef
	EHOSTUNREACH,	EHOSTDOWN,	ENETUNREACH,	EHOSTUNREACH,
#else
	ENETUNREACH,	ENETUNREACH,	ENETUNREACH,	ENETUNREACH,
#endif
E 45
I 45
D 72
	0,		0,
	EHOSTDOWN,	EHOSTUNREACH,	ENETUNREACH,	EHOSTUNREACH,
E 45
	ECONNREFUSED,	ECONNREFUSED,	EMSGSIZE,	0,
E 72
I 72
	0,		0,		EHOSTDOWN,	EHOSTUNREACH,
	ENETUNREACH,	EHOSTUNREACH,	ECONNREFUSED,	ECONNREFUSED,
D 85
	EMSGSIZE,	0,		0,		0,
E 72
	0,		0,		0,		0
E 85
I 85
	EMSGSIZE,	EHOSTUNREACH,	0,		0,
	0,		0,		0,		0,
	ENOPROTOOPT
E 85
};

I 85
#ifndef	IPFORWARDING
#define	IPFORWARDING	1
#endif
#ifndef	IPSENDREDIRECTS
#define	IPSENDREDIRECTS	1
#endif
E 85
D 83
ip_ctlinput(cmd, arg)
	int cmd;
	caddr_t arg;
{
D 57
	struct in_addr *sin;
E 57
I 57
	struct in_addr *in;
E 57
D 44
	extern int tcp_abort(), udp_abort();
E 44
I 44
D 79
	int tcp_abort(), udp_abort();
E 79
I 79
	int in_rtchange(), tcp_abort(), udp_abort();
E 79
E 44
	extern struct inpcb tcb, udb;

	if (cmd < 0 || cmd > PRC_NCMDS)
		return;
D 44
	if (ctlerrmap[cmd] == 0)
E 44
I 44
	if (inetctlerrmap[cmd] == 0)
E 44
		return;		/* XXX */
	if (cmd == PRC_IFDOWN)
D 57
		sin = &((struct sockaddr_in *)arg)->sin_addr;
E 57
I 57
		in = &((struct sockaddr_in *)arg)->sin_addr;
E 57
	else if (cmd == PRC_HOSTDEAD || cmd == PRC_HOSTUNREACH)
D 57
		sin = (struct in_addr *)arg;
E 57
I 57
		in = (struct in_addr *)arg;
E 57
	else
D 57
		sin = &((struct icmp *)arg)->icmp_ip.ip_dst;
E 57
I 57
		in = &((struct icmp *)arg)->icmp_ip.ip_dst;
E 57
I 54
D 79
/* THIS IS VERY QUESTIONABLE, SHOULD HIT ALL PROTOCOLS */
E 54
D 44
	in_pcbnotify(&tcb, sin, ctlerrmap[cmd], tcp_abort);
	in_pcbnotify(&udb, sin, ctlerrmap[cmd], udp_abort);
E 44
I 44
D 55
	in_pcbnotify(&tcb, sin, inetctlerrmap[cmd], tcp_abort);
	in_pcbnotify(&udb, sin, inetctlerrmap[cmd], udp_abort);
E 55
I 55
D 56
	in_pcbnotify(&tcb, (struct sockaddr *)sin,
	    inetctlerrmap[cmd], tcp_abort);
	in_pcbnotify(&udb, (struct sockaddr *)sin,
	    inetctlerrmap[cmd], udp_abort);
E 56
I 56
D 57
	in_pcbnotify(&tcb, (struct in_addr *)&sin->sin_addr,
	    (int)inetctlerrmap[cmd], tcp_abort);
	in_pcbnotify(&udb, (struct in_addr *)&sin->sin_addr,
	    (int)inetctlerrmap[cmd], udp_abort);
E 57
I 57
	in_pcbnotify(&tcb, in, (int)inetctlerrmap[cmd], tcp_abort);
	in_pcbnotify(&udb, in, (int)inetctlerrmap[cmd], udp_abort);
E 79
I 79
	/* THIS IS VERY QUESTIONABLE, SHOULD HIT ALL PROTOCOLS */
	if (cmd == PRC_REDIRECT_NET || cmd == PRC_REDIRECT_HOST) {
		in_pcbnotify(&tcb, in, 0, in_rtchange);
		in_pcbnotify(&udb, in, 0, in_rtchange);
	} else {
		in_pcbnotify(&tcb, in, (int)inetctlerrmap[cmd], tcp_abort);
		in_pcbnotify(&udb, in, (int)inetctlerrmap[cmd], udp_abort);
	}
E 79
E 57
E 56
E 55
E 44
}

E 83
int	ipprintfs = 0;
D 85
int	ipforwarding = 1;
E 85
I 85
int	ipforwarding = IPFORWARDING;
extern	int in_interfaces;
int	ipsendredirects = IPSENDREDIRECTS;

E 85
/*
 * Forward a packet.  If some error occurs return the sender
D 82
 * and icmp packet.  Note we can't always generate a meaningful
E 82
I 82
 * an icmp packet.  Note we can't always generate a meaningful
E 82
D 85
 * icmp message because icmp doesn't have a large enough repetoire
E 85
I 85
 * icmp message because icmp doesn't have a large enough repertoire
E 85
 * of codes and types.
I 92
 *
 * If not forwarding (possibly because we have only a single external
 * network), just drop the packet.  This could be confusing if ipforwarding
 * was zero but some routing protocol was advancing us as a gateway
 * to somewhere.  However, we must let the routing protocol deal with that.
E 92
 */
D 85
ip_forward(ip)
E 85
I 85
ip_forward(ip, ifp)
E 85
	register struct ip *ip;
I 85
	struct ifnet *ifp;
E 85
{
D 85
	register int error, type, code;
E 85
I 85
	register int error, type = 0, code;
	register struct sockaddr_in *sin;
E 85
D 45
	struct mbuf *mopt;
E 45
I 45
D 82
	struct mbuf *mopt, *mcopy;
E 82
I 82
	struct mbuf *mcopy;
I 85
	struct in_addr dest;
E 85
E 82
E 45

I 85
D 94
#ifdef lint
E 94
	dest.s_addr = 0;
D 94
#endif
E 94
E 85
	if (ipprintfs)
		printf("forward: src %x dst %x ttl %x\n", ip->ip_src,
			ip->ip_dst, ip->ip_ttl);
I 82
	ip->ip_id = htons(ip->ip_id);
E 82
D 85
	if (ipforwarding == 0) {
E 85
I 85
	if (ipforwarding == 0 || in_interfaces <= 1) {
E 85
D 92
		/* can't tell difference between net and host */
		type = ICMP_UNREACH, code = ICMP_UNREACH_NET;
		goto sendicmp;
E 92
I 92
		ipstat.ips_cantforward++;
I 94
#ifdef GATEWAY
		type = ICMP_UNREACH, code = ICMP_UNREACH_NET;
		goto sendicmp;
#else
E 94
		m_freem(dtom(ip));
		return;
I 94
#endif
E 94
E 92
	}
D 102
	if (ip->ip_ttl < IPTTLDEC) {
E 102
I 102
D 104
	if (in_canforward(ip->ip_dst) == 0) {
		m_freem(dtom(ip));
		return;
	}
E 104
	if (ip->ip_ttl <= IPTTLDEC) {
E 102
		type = ICMP_TIMXCEED, code = ICMP_TIMXCEED_INTRANS;
		goto sendicmp;
	}
	ip->ip_ttl -= IPTTLDEC;
D 61
	mopt = m_get(M_DONTWAIT);
E 61
I 61
D 82
	mopt = m_get(M_DONTWAIT, MT_DATA);
E 61
D 67
	if (mopt == 0) {
E 67
I 67
	if (mopt == NULL) {
E 67
		m_freem(dtom(ip));
		return;
	}
E 82
I 45

	/*
	 * Save at most 64 bytes of the packet in case
	 * we need to generate an ICMP message to the src.
	 */
D 50
	mcopy = m_copy(dtom(ip), 0, min(ip->ip_len, 64));
E 50
I 50
D 96
	mcopy = m_copy(dtom(ip), 0, imin(ip->ip_len, 64));
E 96
I 96
	mcopy = m_copy(dtom(ip), 0, imin((int)ip->ip_len, 64));
E 96
E 50
E 45
D 82
	ip_stripoptions(ip, mopt);
E 82

D 69
	/* last 0 here means no directed broadcast */
D 45
	if ((error = ip_output(dtom(ip), mopt, 0, 0)) == 0)
E 45
I 45
D 55
	if ((error = ip_output(dtom(ip), mopt, 0, 0)) == 0) {
E 55
I 55
D 68
	if ((error = ip_output(dtom(ip), mopt, (struct route *)0, 0)) == 0) {
E 68
I 68
	error = ip_output(dtom(ip), mopt, (struct route *)0, 0);
E 69
I 69
D 82
	error = ip_output(dtom(ip), mopt, (struct route *)0, IP_FORWARDING);
E 82
I 82
D 85
	error = ip_output(dtom(ip), (struct mbuf *)0, (struct route *)0,
E 85
I 85
	sin = (struct sockaddr_in *)&ipforward_rt.ro_dst;
	if (ipforward_rt.ro_rt == 0 ||
	    ip->ip_dst.s_addr != sin->sin_addr.s_addr) {
		if (ipforward_rt.ro_rt) {
			RTFREE(ipforward_rt.ro_rt);
			ipforward_rt.ro_rt = 0;
		}
		sin->sin_family = AF_INET;
		sin->sin_addr = ip->ip_dst;

		rtalloc(&ipforward_rt);
	}
	/*
	 * If forwarding packet using same interface that it came in on,
	 * perhaps should send a redirect to sender to shortcut a hop.
	 * Only send redirect if source is sending directly to us,
	 * and if packet was not source routed (or has any options).
I 98
	 * Also, don't send redirect if forwarding using a default route
	 * or a route modfied by a redirect.
E 98
	 */
I 98
#define	satosin(sa)	((struct sockaddr_in *)(sa))
E 98
	if (ipforward_rt.ro_rt && ipforward_rt.ro_rt->rt_ifp == ifp &&
I 98
D 105
	    (ipforward_rt.ro_rt->rt_flags & (RTF_DYNAMIC|RTF_MODIFIED)) == 0 &&
E 105
I 105
	    (ipforward_rt.ro_rt->rt_flags & RTF_DYNAMIC) == 0 &&
E 105
	    satosin(&ipforward_rt.ro_rt->rt_dst)->sin_addr.s_addr != 0 &&
E 98
	    ipsendredirects && ip->ip_hl == (sizeof(struct ip) >> 2)) {
		struct in_ifaddr *ia;
D 100
		extern struct in_ifaddr *ifptoia();
E 100
		u_long src = ntohl(ip->ip_src.s_addr);
		u_long dst = ntohl(ip->ip_dst.s_addr);

		if ((ia = ifptoia(ifp)) &&
		   (src & ia->ia_subnetmask) == ia->ia_subnet) {
		    if (ipforward_rt.ro_rt->rt_flags & RTF_GATEWAY)
			dest = satosin(&ipforward_rt.ro_rt->rt_gateway)->sin_addr;
		    else
			dest = ip->ip_dst;
		    /*
		     * If the destination is reached by a route to host,
D 95
		     * is directly on the attached net (!),
		     * or if the destination is on a subnet of a local net
		     * not known to the source net, use host redirect.
E 95
I 95
		     * is on a subnet of a local net, or is directly
		     * on the attached net (!), use host redirect.
E 95
		     * (We may be the correct first hop for other subnets.)
		     */
		    type = ICMP_REDIRECT;
		    code = ICMP_REDIRECT_NET;
		    if ((ipforward_rt.ro_rt->rt_flags & RTF_HOST) ||
		       (ipforward_rt.ro_rt->rt_flags & RTF_GATEWAY) == 0)
			code = ICMP_REDIRECT_HOST;
		    else for (ia = in_ifaddr; ia = ia->ia_next; )
			if ((dst & ia->ia_netmask) == ia->ia_net) {
D 95
			    if ((src & ia->ia_netmask) != ia->ia_net)
				code = ICMP_REDIRECT_HOST;
E 95
I 95
			    if (ia->ia_subnetmask != ia->ia_netmask)
				    code = ICMP_REDIRECT_HOST;
E 95
			    break;
			}
		    if (ipprintfs)
		        printf("redirect (%d) to %x\n", code, dest);
		}
	}

	error = ip_output(dtom(ip), (struct mbuf *)0, &ipforward_rt,
E 85
		IP_FORWARDING);
E 82
E 69
D 85
	if (error == 0) {
E 85
I 85
	if (error)
		ipstat.ips_cantforward++;
	else if (type)
		ipstat.ips_redirectsent++;
	else {
E 85
E 68
E 55
		if (mcopy)
			m_freem(mcopy);
I 83
		ipstat.ips_forward++;
E 83
E 45
		return;
D 45
#ifdef notdef
	/*
	 * Want to generate a message, but lower
	 * layers assume they can free up a message
	 * in the event of an error.  This causes
	 * the call to icmp_error to work on ``freed''
	 * mbuf's, and worse.
	 */
	type = ICMP_UNREACH, code = 0;	/* need ``undefined'' */
	if (error == ENETUNREACH || error == ENETDOWN)
E 45
I 45
	}
I 83
D 85
	ipstat.ips_cantforward++;
E 85
E 83
I 68
	if (mcopy == NULL)
		return;
E 68
	ip = mtod(mcopy, struct ip *);
D 85
	type = ICMP_UNREACH, code = 0;		/* need ``undefined'' */
E 85
I 85
	type = ICMP_UNREACH;
E 85
	switch (error) {

I 85
	case 0:				/* forwarded, but need redirect */
		type = ICMP_REDIRECT;
		/* code set above */
		break;

E 85
	case ENETUNREACH:
	case ENETDOWN:
E 45
D 106
		code = ICMP_UNREACH_NET;
E 106
I 106
		if (in_localaddr(ip->ip_dst))
			code = ICMP_UNREACH_HOST;
		else
			code = ICMP_UNREACH_NET;
E 106
D 45
	else if (error == EMSGSIZE)
E 45
I 45
		break;

	case EMSGSIZE:
E 45
		code = ICMP_UNREACH_NEEDFRAG;
D 45
#else
	return;
#endif
E 45
I 45
		break;

	case EPERM:
		code = ICMP_UNREACH_PORT;
		break;

	case ENOBUFS:
		type = ICMP_SOURCEQUENCH;
		break;

	case EHOSTDOWN:
	case EHOSTUNREACH:
		code = ICMP_UNREACH_HOST;
		break;
	}
E 45
sendicmp:
D 85
	icmp_error(ip, type, code);
E 85
I 85
D 89
	icmp_error(ip, type, code, dest);
E 89
I 89
	icmp_error(ip, type, code, ifp, dest);
E 89
E 85
E 43
E 28
E 9
D 14
}
D 4
 
E 4
I 4

E 4
D 9
ip_deq(p)
register struct ip *p;
E 9
I 9
/* stubs */

icmp_error(ip, error)
E 9
{
D 9
COUNT(IP_DEQ);
	p->ip_prev->ip_next = p->ip_next;
	p->ip_next->ip_prev = p->ip_prev;
E 9
I 9

	m_freem(dtom(ip));
E 9
}

D 2
ip_bswap(p)    /* byte swap ip header */
register struct ip *p;
{
COUNT(IP_BSWAP);
	p->ip_len = ntohs(p->ip_len);
	p->ip_id = ntohs(p->ip_id);
	p->ip_off = ntohs(p->ip_off);
}

E 2
D 9
ip_timeo()      /* frag reass.q timeout routine */
E 9
I 9
icmp_input(m)
	struct mbuf *m;
E 9
{
D 9
	register struct ip *q;
	register struct ipq *fp;
I 3
	int s = splnet();
E 9
E 3

D 9
COUNT(IP_TIMEO);
D 4
	timeout(ip_timeo, 0, 60);       /* reschedule every second */
E 4
I 4
	timeout(ip_timeo, 0, hz);       /* reschedule every second */
E 9
I 9
	printf("icmp_input %x\n", m);
}
E 9
E 4

D 3
	if (netcb.n_ip_lock)    /* reass.q must not be in use */
E 3
I 3
D 4
	if (netcb.n_ip_lock) {    /* reass.q must not be in use */
		splx(s);
E 3
		return;
I 3
	}
E 3

E 4
D 9
	/* search through reass.q */
E 9
I 9
udp_input(m)
	struct mbuf *m;
{
E 9

D 4
	for (fp = netcb.n_ip_head; fp != NULL; fp = fp->iq_next) 
E 4
I 4
D 9
	for (fp = netcb.n_ip_head; fp != NULL; fp = fp->iq_next)
E 9
I 9
	printf("udp_input %x\n", m);
}
E 9
E 4

D 9
		if (--(fp->iqx.ip_ttl) == 0) {  /* time to die */
E 9
I 9
raw_input(m)
	struct mbuf *m;
{
E 9

D 9
			q = fp->iqx.ip_next;    /* free mbufs assoc. w/chain */
D 4
			while (q != (struct ip *)fp) {                         
				m_freem(dtom(q));   
				q = q->ip_next;                                
			}                                                      
			ip_freef(fp);           /* free header */              
E 4
I 4
			while (q != (struct ip *)fp) {
				m_freem(dtom(q));
				q = q->ip_next;
			}
			ip_freef(fp);           /* free header */
E 4
		}
I 3
	splx(s);
E 9
I 9
	printf("raw_input %x\n", m);
E 14
E 9
E 3
}
E 1

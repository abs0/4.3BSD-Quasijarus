h08528
s 00006/00000/00482
d D 7.12 03/08/01 18:16:22 msokolov 110 109
c fix mbuf leak when tcp_usrreq catches and stops an attempt to operate on a
c reset socket (no inpcb), from CSRG's 1995 work
e
s 00009/00002/00473
d D 7.11 03/08/01 18:10:15 msokolov 109 108
c tcp_ctloutput crash fix: catch attempts to operate on reset sockets (no inpcb)
c from 4.4BSD
e
s 00010/00005/00465
d D 7.10 88/06/29 17:07:44 bostic 108 107
c install approved copyright notice
e
s 00007/00005/00463
d D 7.9 88/05/25 18:09:39 karels 107 105
c in attach, don't set sockbuf limits if set (from sonewconn); lint
e
s 00000/00000/00477
d D 7.7.1.2 88/03/16 09:36:28 karels 106 104
i 105
c update branch
e
s 00001/00001/00467
d D 7.8 88/03/16 09:05:25 karels 105 103
c much longer keepalive timer (don't start probes for 2 hr);
c fix input window test again (accept acks from FINS at left edge and responses
c to keepalives, but dropafterack otherwise; also fixes Phil Karn's problem
c with failure to respond to new SYN to left of window); can't use tcp_drop
c after RST, or we'll send RST in response
e
s 00009/00000/00468
d D 7.7.1.1 88/02/07 19:56:45 karels 104 103
c branch for FTP release (#ifdefs for non-4.3)
e
s 00000/00006/00468
d D 7.7 88/02/07 19:27:36 karels 103 102
c simulate quench when ip_output returns ENOBUFS; cleanup ENOBUFS
c error masking
e
s 00008/00002/00466
d D 7.6 87/12/07 17:46:49 bostic 102 101
c use Berkeley specific header
e
s 00002/00001/00466
d D 7.5 87/05/08 10:51:43 sam 101 100
c avoid potential null pointer (from forys@boulder.colorado.edu)
c bug report 4.3BSD/sys/117
e
s 00009/00015/00458
d D 7.4 87/04/15 10:30:07 karels 100 98
c I prefer this fix; don't spl so early, but protect sotoinpcb
e
s 00008/00014/00459
d R 7.4 87/04/10 13:40:35 karels 99 98
c I like this way better (and there was a race!)
e
s 00007/00003/00466
d D 7.3 87/04/09 12:02:19 mckusick 98 97
c reset priority before returning (4.3BSD/sys/109 from nowicki@sun.com)
e
s 00001/00000/00468
d D 7.2 87/02/19 17:01:32 karels 97 96
c new stats
e
s 00001/00001/00467
d D 7.1 86/06/05 00:32:38 mckusick 96 95
c 4.3BSD release version
e
s 00010/00001/00458
d D 6.11 86/04/19 21:16:55 karels 95 93
c all data in SENDOOB is urgent
e
s 00018/00001/00458
d R 6.11 86/04/19 20:44:22 karels 94 93
c allow OOB data to be received in-line
e
s 00001/00001/00458
d D 6.10 86/02/23 23:26:31 karels 93 92
c lint
e
s 00001/00001/00458
d D 6.9 86/02/19 17:00:26 karels 92 91
c lint
e
s 00049/00004/00410
d D 6.8 86/01/13 17:29:19 karels 91 90
c add flag to avoid delay of short packets (Nagle algorithm),
c framework for other TCP-level options
e
s 00017/00002/00397
d D 6.7 85/09/16 23:23:53 karels 90 89
c only read oob data once, unless PEEK; provision for TCP options
e
s 00007/00001/00392
d D 6.6 85/06/08 12:45:30 mckusick 89 88
c Add copyright
e
s 00005/00008/00388
d D 6.5 85/03/18 15:24:03 karels 88 87
c in_control gets PRU_CONTROLS; bigger TCP send/recv buffers,
c bigger UDP recv buffers
e
s 00020/00020/00376
d D 6.4 84/08/29 15:38:15 bloom 87 86
c Include file changes.  No more ../h
e
s 00008/00008/00388
d D 6.3 84/08/28 18:28:36 karels 86 85
c don't let tcp_attach free socket if can't get mbuf for tcpcb
e
s 00004/00003/00392
d D 6.2 84/08/21 10:22:23 karels 85 84
c add sostat
e
s 00000/00000/00395
d D 6.1 83/07/29 07:13:02 sam 84 83
c 4.2 distribution
e
s 00004/00000/00391
d D 1.81 83/07/25 21:55:32 sam 83 82
c getpeer
e
s 00002/00002/00389
d D 1.80 83/06/20 22:43:59 sam 82 81
c can't just drop on close w/o now default linger 'cuz RST is generated
e
s 00007/00000/00384
d D 1.79 83/06/14 22:10:59 sam 81 80
c socketpair
e
s 00012/00004/00372
d D 1.78 83/05/27 13:47:06 sam 80 79
c merge wnj changes plus lint
e
s 00001/00000/00375
d D 1.77 83/05/13 20:24:36 sam 79 78
c fixes problem PRU_SHUTDOWN on a socket in TCPS_CLOSED
e
s 00002/00000/00373
d D 1.76 83/05/12 15:00:54 sam 78 77
c stuttering "fixed" (somehow this got lost in an earlier shuffle)
e
s 00001/00000/00372
d D 1.75 83/02/22 23:48:24 sam 77 76
c unlikely, but would've lost mbuf's
e
s 00002/00001/00370
d D 1.74 83/02/10 22:12:54 sam 76 75
c remove /usr/include dependencies
e
s 00023/00019/00348
d D 1.73 83/01/17 18:04:00 sam 75 74
c stuff from bill to insure no references are kept to free'd cb's
e
s 00001/00002/00366
d D 1.72 83/01/13 18:31:52 sam 74 73
c nor more opt parameter to usrreq
e
s 00001/00001/00367
d D 1.71 83/01/08 16:25:33 sam 73 72
c allow linger to be set
e
s 00001/00001/00367
d D 1.70 82/11/03 01:08:51 root 72 71
c misc 4.1c fixes
e
s 00000/00000/00368
d D 1.69 82/10/30 13:04:43 root 71 70
c get rid of conditional htons/ntohs etc
e
s 00003/00002/00365
d D 1.68 82/10/20 01:23:40 root 70 69
c lint
e
s 00001/00001/00366
d D 1.67 82/10/17 22:48:29 root 69 68
c lint
e
s 00001/00000/00366
d D 1.66 82/10/17 14:56:56 root 68 67
c fix lint
e
s 00012/00012/00354
d D 1.65 82/10/09 05:48:35 wnj 67 66
c localize header files
e
s 00000/00015/00366
d D 1.64 82/10/05 18:51:26 root 66 65
c m_get inits m_off; remove TCPTRUEOOB
e
s 00001/00000/00380
d D 1.63 82/10/05 18:32:50 root 65 64
c set m_len on out-of-band
e
s 00044/00040/00336
d D 1.62 82/09/26 18:30:17 root 64 63
c first working version
e
s 00001/00001/00375
d D 1.61 82/07/24 18:18:52 root 63 62
c restore sccs ids
e
s 00023/00014/00353
d D 1.60 82/07/24 18:14:43 root 62 61
c 
e
s 00000/00001/00367
d D 1.59 82/06/20 00:56:19 sam 61 60
c purge COUNT stuff now that we can use gprof
e
s 00000/00000/00368
d D 1.58 82/06/12 23:20:08 wnj 60 59
c now the routing code might wokr
e
s 00001/00001/00367
d D 1.57 82/04/30 12:19:28 sam 59 58
c patch constants
e
s 00004/00000/00364
d D 1.56 82/04/10 23:42:17 sam 58 57
c purge so_addr from socket structure and start cleaning up raw code
e
s 00013/00011/00351
d D 1.55 82/04/10 18:27:10 sam 57 56
c invert output path to pass back error indications
e
s 00001/00000/00361
d D 1.54 82/03/29 11:34:02 sam 56 55
c first cut (incomplete) at routing
e
s 00010/00001/00351
d D 1.53 82/03/11 23:09:52 wnj 55 54
c minor bug fixes
e
s 00000/00001/00352
d D 1.52 82/02/27 17:47:46 wnj 54 53
c multi-homing and wildcards
e
s 00004/00001/00349
d D 1.51 82/02/25 13:14:58 wnj 53 52
c patchable send and receive space
e
s 00003/00000/00347
d D 1.50 82/02/19 10:29:37 wnj 52 51
c let user close after fin acked
e
s 00016/00031/00331
d D 1.49 82/01/18 19:43:44 wnj 51 50
c out-of-band fixed up
e
s 00039/00004/00323
d D 1.48 82/01/17 21:20:35 wnj 50 49
c more work on out-of-band
e
s 00014/00005/00313
d D 1.47 82/01/17 00:59:31 wnj 49 48
c out of band
e
s 00003/00001/00315
d D 1.46 82/01/13 10:44:04 wnj 48 47
c a number of minor changes
e
s 00154/00044/00162
d D 1.45 81/12/21 11:00:08 root 47 46
c many more comments; cleaner
e
s 00003/00000/00203
d D 1.44 81/12/20 21:40:20 wnj 46 45
c race in if_en.c; no PERSIST before SYN; implement LETDATADRAIN
e
s 00010/00003/00193
d D 1.43 81/12/20 15:23:45 root 45 44
c trace code and startup shutdown fixups
e
s 00000/00001/00196
d D 1.42 81/12/19 12:45:53 wnj 44 43
c no reason to soisconnected in PRU_ACCEPT
e
s 00000/00011/00197
d D 1.41 81/12/12 18:05:35 root 43 42
c clean out printf
e
s 00053/00024/00155
d D 1.40 81/12/12 12:59:26 root 42 41
c with crud (first working version)
e
s 00001/00000/00178
d D 1.39 81/12/03 17:30:31 wnj 41 40
c cleanup
e
s 00005/00004/00173
d D 1.38 81/12/02 17:00:17 wnj 40 39
c yet more lint
e
s 00019/00008/00158
d D 1.37 81/11/29 22:02:45 wnj 39 38
c lint and interface cleanups
e
s 00015/00024/00151
d D 1.36 81/11/26 11:58:16 wnj 38 37
c before carry to ARPAVAX
e
s 00044/00227/00131
d D 1.35 81/11/25 16:10:24 wnj 37 36
c listing
e
s 00032/00237/00326
d D 1.34 81/11/24 17:33:57 wnj 36 35
c start rewrite
e
s 00029/00039/00534
d D 1.33 81/11/24 07:54:08 wnj 35 34
c minor fixups pre tcp<->spec coordination
e
s 00001/00001/00572
d D 1.32 81/11/20 14:41:56 wnj 34 33
c more lint
e
s 00036/00016/00537
d D 1.31 81/11/20 00:47:34 wnj 33 32
c linted
e
s 00004/00008/00549
d D 1.30 81/11/18 15:38:22 wnj 32 31
c more cleanup
e
s 00058/00056/00499
d D 1.29 81/11/16 14:17:58 wnj 31 30
c more lint
e
s 00007/00006/00548
d D 1.28 81/11/15 13:00:38 wnj 30 29
c listing
e
s 00121/00234/00433
d D 1.27 81/11/14 16:40:42 wnj 29 28
c before overlay
e
s 00163/00147/00504
d D 1.26 81/11/08 16:36:55 wnj 28 27
c first listing
e
s 00003/00001/00648
d D 1.25 81/11/04 09:09:45 wnj 27 26
c missing tmp++ in tcp_states.c
e
s 00057/00051/00592
d D 1.24 81/11/04 00:29:41 wnj 26 25
c more cleanups, fields in ucb.h
e
s 00181/00069/00462
d D 1.23 81/11/03 21:54:40 wnj 25 24
c states now w/o fsm matrix; timers accessible by iteration
e
s 00027/00014/00504
d D 1.22 81/10/31 15:54:18 wnj 24 23
c bug fixes and last chksum
e
s 00008/00002/00510
d D 1.21 81/10/31 14:01:45 wnj 23 22
c present data eliminates (tcp_input now gross!!!)
e
s 00111/00072/00401
d D 1.20 81/10/30 21:44:14 wnj 22 21
c more cleanup
e
s 00000/00000/00473
d D 1.19 81/10/30 20:42:37 wnj 21 20
c cleanup
e
s 00005/00005/00468
d D 1.18 81/10/30 20:19:37 wnj 20 19
c further cleanup
e
s 00017/00017/00456
d D 1.17 81/10/30 19:28:05 wnj 19 18
c name changes pre rearrange
e
s 00001/00001/00472
d D 1.16 81/10/30 18:04:49 wnj 18 17
c first 1m baud system
e
s 00037/00003/00436
d D 1.15 81/10/30 15:13:17 wnj 17 16
c insert debugging code
e
s 00026/00021/00413
d D 1.14 81/10/29 20:28:14 wnj 16 15
c cleanup of header files
e
s 00002/00002/00432
d D 1.13 81/10/29 16:02:12 wnj 15 12
c working but losing 1 mbuf per connection
e
s 00113/00072/00362
d R 1.14 81/10/26 02:11:30 wnj 14 13
c first compile of major cleanup
e
s 00000/00000/00434
d R 1.13 81/10/25 16:02:50 wnj 13 12
c add fields for rcv_win rcv_unacnt rcv_usrcnt rcv_seqcnt
e
s 00008/00011/00426
d D 1.12 81/10/25 14:21:35 wnj 12 11
c fixed up debugging
e
s 00003/00002/00434
d D 1.11 81/10/24 23:25:39 wnj 11 10
c working version before using dialup console
e
s 00002/00000/00434
d D 1.10 81/10/23 15:34:14 wnj 10 9
c large packets in receive path
e
s 00004/00004/00430
d D 1.9 81/10/23 11:44:39 wnj 9 8
c working with snd_copy incr ref cnt
e
s 00024/00031/00410
d D 1.8 81/10/23 10:07:56 wnj 8 7
c first working version with page macros and new snd_copy
e
s 00058/00100/00383
d D 1.7 81/10/22 12:35:42 wnj 7 6
c fixup debugging stuff, elim work q once and for all
e
s 00013/00013/00470
d D 1.6 81/10/21 21:37:16 wnj 6 5
c bit fields -> flags
e
s 00002/00002/00481
d D 1.5 81/10/21 19:07:57 wnj 5 4
c cleanup the headers
e
s 00371/00179/00112
d D 1.4 81/10/21 11:20:42 wnj 4 3
c switch in tcp_states.c rather than a bunch of procedures
e
s 00000/00340/00291
d D 1.3 81/10/18 20:04:31 wnj 3 2
c cleaned up tcp_input.c
e
s 00000/00072/00631
d D 1.2 81/10/18 11:52:38 wnj 2 1
c first speedups (tcp_input, ip_input, t_cancel inline, no ip_opt, ip_findf)
e
s 00703/00000/00000
d D 1.1 81/10/14 09:57:14 wnj 1 0
c date and time created 81/10/14 09:57:14 by wnj
e
u
U
f b 
t
T
I 1
D 57
/* %M% %I% %E% */
E 57
I 57
D 62
/*	%M%	%I%	%E%	*/
E 62
I 62
D 63
/*	tcp_usrreq.c	1.60	82/07/21	*/
E 63
I 63
D 89
/*	%M%	%I%	%E%	*/
E 89
I 89
/*
D 96
 * Copyright (c) 1982 Regents of the University of California.
E 96
I 96
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 96
D 102
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 102
I 102
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 108
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 108
I 108
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
E 108
E 102
 *
 *	%W% (Berkeley) %G%
 */
E 89
E 63
E 62
E 57
I 4

E 4
D 87
#include "../h/param.h"
I 4
#include "../h/systm.h"
E 4
D 16
#include "../bbnnet/net.h"
I 5
#include "../bbnnet/mbuf.h"
E 5
#include "../bbnnet/tcp.h"
#include "../bbnnet/ip.h"
#include "../bbnnet/imp.h"
#include "../bbnnet/ucb.h"
E 16
I 16
#include "../h/mbuf.h"
#include "../h/socket.h"
D 28
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/ip.h"
#include "../inet/tcp.h"
E 28
I 28
#include "../h/socketvar.h"
#include "../h/protosw.h"
I 76
#include "../h/errno.h"
I 85
#include "../h/stat.h"
E 87
I 87
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "socket.h"
#include "socketvar.h"
#include "protosw.h"
#include "errno.h"
#include "stat.h"
E 87
E 85
E 76
D 38
#include "../net/inet.h"
I 29
D 33
#include "../net/inet_host.h"
E 33
#include "../net/inet_pcb.h"
E 29
#include "../net/inet_systm.h"
E 38
I 38
D 67
#include "../net/in.h"
E 67
I 67
D 70
#include "../netinet/in.h"
E 70
I 70

#include "../net/if.h"
E 70
E 67
I 56
#include "../net/route.h"
I 76

E 76
I 70
D 87
#include "../netinet/in.h"
E 70
E 56
D 67
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 67
I 67
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
E 67
E 38
I 33
D 70
#include "../net/if.h"
E 70
E 33
D 38
#include "../net/imp.h"
E 38
D 67
#include "../net/ip.h"
I 30
#include "../net/ip_var.h"
E 30
#include "../net/tcp.h"
E 28
E 16
I 4
D 36
#define TCPFSTAB
I 7
#ifdef TCPDEBUG
#define TCPSTATES
#endif
E 36
E 7
E 4
D 16
#include "../bbnnet/fsm.h"
E 16
I 16
D 28
#include "../inet/tcp_fsm.h"
E 28
I 28
#include "../net/tcp_fsm.h"
I 38
#include "../net/tcp_seq.h"
#include "../net/tcp_timer.h"
E 38
#include "../net/tcp_var.h"
I 38
#include "../net/tcpip.h"
I 45
#include "../net/tcp_debug.h"
E 67
I 67
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/tcp.h"
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
#include "../netinet/tcp_debug.h"
E 87
I 87
#include "in.h"
#include "in_pcb.h"
#include "in_systm.h"
#include "ip.h"
#include "ip_var.h"
#include "tcp.h"
#include "tcp_fsm.h"
#include "tcp_seq.h"
#include "tcp_timer.h"
#include "tcp_var.h"
#include "tcpip.h"
#include "tcp_debug.h"
E 87
E 67
E 45
E 38
D 39
#include "/usr/include/errno.h"
E 39
I 39
D 57
#include "../errno.h"
E 57
I 57
D 76
#include <errno.h>
E 76
E 57
E 39
E 28
E 16
D 5
#include "../bbnnet/tcp_pred.h"
E 5

I 42
D 47
extern char *tcpstates[];
E 47
I 47
/*
 * TCP protocol interface to socket abstraction.
 */
extern	char *tcpstates[];
E 47
E 42
I 28
D 29
struct	tcb *tcp_attach();

E 29
E 28
I 26
D 36
/*
I 28
 * Tcp initialization
 */
tcp_init()
{

	tcp_iss = 1;		/* wrong */
D 29
	tcb.tcb_next = tcb.tcb_prev = (struct tcb *)&tcb;
E 29
I 29
	tcb.inp_next = tcb.inp_prev = &tcb;
E 29
}

/*
E 28
 * Tcp finite state machine entries for timer and user generated
 * requests.  These routines raise the ipl to that of the network
 * to prevent reentry.  In particluar, this requires that the software
 * clock interrupt have lower priority than the network so that
 * we can enter the network from timeout routines without improperly
 * nesting the interrupt stack.
 */

/*
D 28
 * Tcp protocol timeout routine called once per second.
E 28
I 28
 * Tcp protocol timeout routine called every 500 ms.
E 28
 * Updates the timers in all active tcb's and
 * causes finite state machine actions if timers expire.
 */
E 26
D 4
lis_cls(wp)             /* passive open (1) */
struct work *wp;
E 4
I 4
D 7
/*
 * This file contains the top level routines for actions
 * called by the user and by the clock routines, while input
 * actions for network data are driven by tcp_input.  The two
 * main entry points here are tcp_timeo, which decrements tcp timers
 * each second and runs timer action routines when the timers go off,
 * and tcp_usrreq, which performs requests generated by or on behalf
 * of user processes.  Both routines raise the ipl to splnet to block
 * off tcp_input processing (triggered by imp's) during the work
 * here.
 */

E 7
D 28
tcp_timeo()
E 28
I 28
tcp_slowtimo()
E 28
E 4
{
D 4
	
COUNT(LIS_CLS);
	t_open(wp->w_tcb, PASSIVE);
E 4
I 4
D 29
	register struct tcb *tp;
E 29
I 29
	register struct inpcb *ip;
	register struct tcpcb *tp;
E 29
	int s = splnet();
I 25
D 28
	register u_char *tmp;
E 28
I 28
	register short *tmp;
E 28
	register int i;
E 25
COUNT(TCP_TIMEO);
E 4

D 4
	return(LISTEN);
E 4
I 4
	/*
	 * Search through tcb's and update active timers.
	 */
D 16
	for (tp = netcb.n_tcb_head; tp != NULL; tp = tp->t_tcb_next) {
E 16
I 16
D 22
	for (tp = tcb_head; tp != NULL; tp = tp->t_tcb_next) {
E 22
I 22
D 28
	for (tp = tcb.tcb_next; tp != (struct tcb *)&tcb; tp = tp->tcb_next) {
E 28
I 28
D 29
	tp = tcb.tcb_next;
	for (; tp != (struct tcb *)&tcb; tp = tp->tcb_hd.tcb_next) {
E 29
I 29
	for (ip = tcb.inp_next; ip != &tcb; ip = ip->inp_next) {
		tp = intotcpcb(ip);
E 29
E 28
E 22
E 16
D 25
		if (tp->t_init != 0 && --tp->t_init == 0)
			tcp_usrreq(ISTIMER, TINIT, tp, 0);
		if (tp->t_rexmt != 0 && --tp->t_rexmt == 0)
			tcp_usrreq(ISTIMER, TREXMT, tp, 0);
		if (tp->t_rexmttl != 0 && --tp->t_rexmttl == 0)
			tcp_usrreq(ISTIMER, TREXMTTL, tp, 0);
		if (tp->t_persist != 0 && --tp->t_persist == 0)
			tcp_usrreq(ISTIMER, TPERSIST, tp, 0);
		if (tp->t_finack != 0 && --tp->t_finack == 0)
			tcp_usrreq(ISTIMER, TFINACK, tp, 0);
E 25
I 25
		tmp = &tp->t_init;
D 27
		for (i = 0; i < TNTIMERS; i++)
E 27
I 27
		for (i = 0; i < TNTIMERS; i++) {
E 27
			if (*tmp && --*tmp == 0)
D 28
				tcp_usrreq(ISTIMER, i, tp, 0);
E 28
I 28
D 29
				tcp_usrreq(tp->t_socket, PRU_SLOWTIMO, 0, i);
E 29
I 29
D 31
				tcp_usrreq(tp->t_inpcb->inp_socket,
				    PRU_SLOWTIMO, 0, i);
E 31
I 31
				(void) tcp_usrreq(tp->t_inpcb->inp_socket,
				    PRU_SLOWTIMO, (struct mbuf *)0,
				    (caddr_t)i);
E 31
E 29
E 28
I 27
			tmp++;
		}
E 27
E 25
		tp->t_xmt++;
	}
D 16
	netcb.n_iss += ISSINCR;		/* increment iss */
E 16
I 16
D 28
	tcp_iss += ISSINCR;		/* increment iss */
E 16
	timeout(tcp_timeo, 0, hz);      /* reschedule every second */
E 28
I 28
	tcp_iss += ISSINCR/2;		/* increment iss */
E 28
	splx(s);
E 4
}

D 4
sys_cls(wp)             /* active open (6) */
register struct work *wp;
E 4
I 4
D 7
tcp_usrreq(input, stype, tp, m)
	int input, stype;
E 7
I 7
D 25
tcp_usrreq(input, timertype, tp, mp)
E 25
I 25
/*
I 26
 * Cancel all timers for tcp tp.
 */
tcp_tcancel(tp)
D 29
	struct tcb *tp;
E 29
I 29
	struct tcpcb *tp;
E 29
{
D 28
	register u_char *tmp = &tp->t_init;
E 28
I 28
	register short *tmp = &tp->t_init;
E 28
	register int i;

	for (i = 0; i < TNTIMERS; i++)
		*tmp++ = 0;
}

E 36
I 33
struct	tcpcb *tcp_newtcpcb();
I 80
D 103
int	tcpsenderrors;
E 103
E 80
I 47

E 47
E 33
/*
E 26
D 47
 * Process a TCP user request for tcp tb.  If this is a send request
E 47
I 47
 * Process a TCP user request for TCP tb.  If this is a send request
E 47
 * then m is the mbuf chain of send data.  If this is a timer expiration
 * (called from the software clock routine), then timertype tells which timer.
 */
I 68
/*ARGSUSED*/
E 68
D 28
tcp_usrreq(input, timertype, tp, m)
E 25
	int input, timertype;
E 7
	register struct tcb *tp;
E 28
I 28
D 64
tcp_usrreq(so, req, m, addr)
E 64
I 64
D 74
tcp_usrreq(so, req, m, nam, opt)
E 74
I 74
D 80
tcp_usrreq(so, req, m, nam)
E 80
I 80
tcp_usrreq(so, req, m, nam, rights)
E 80
E 74
E 64
	struct socket *so;
	int req;
E 28
D 7
	char *m;
E 7
I 7
D 25
	struct mbuf *mp;
E 25
I 25
D 64
	struct mbuf *m;
I 28
	caddr_t addr;
E 64
I 64
D 80
	struct mbuf *m, *nam;
E 80
I 80
	struct mbuf *m, *nam, *rights;
E 80
D 74
	struct socketopt *opt;
E 74
E 64
E 28
E 25
E 7
E 4
{
I 28
D 29
	register struct tcb *tp = (struct tcb *)so->so_pcb;
E 29
I 29
D 100
	register struct inpcb *inp = sotoinpcb(so);
E 100
I 100
	register struct inpcb *inp;
E 100
D 31
	register struct tcpcb *tp = intotcpcb(inp);
E 31
I 31
	register struct tcpcb *tp;
E 31
E 29
E 28
I 4
D 7
	struct work w;
E 7
D 100
	int s = splnet();
E 100
I 100
	int s;
E 100
D 37
	register int nstate;
E 37
D 7
	register struct work *wp = &w;
E 7
I 7
D 36
#ifdef TCPDEBUG
	struct tcp_debug tdb;
#endif
E 36
I 28
	int error = 0;
I 45
	int ostate;
E 45
I 37
D 39
	struct tcpiphdr ti;
E 39
E 37
E 28
E 7
D 61
COUNT(TCP_USRREQ);
E 61
E 4

I 104
#if BSD>=43
E 104
I 88
D 98
	if (req == PRU_CONTROL)
		return (in_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));
E 98
I 98
D 100
	if (req == PRU_CONTROL) {
		error = in_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights);
		(void) splx(s);
		return(error);
	}
E 98
E 88
I 80
	if (rights && rights->m_len) {
		splx(s);
E 100
I 100
	if (req == PRU_CONTROL)
		return (in_control(so, (int)m, (caddr_t)nam,
			(struct ifnet *)rights));
I 104
#else
	if (req == PRU_CONTROL)
		return(EOPNOTSUPP);
#endif
E 104
	if (rights && rights->m_len)
E 100
		return (EINVAL);
D 100
	}
E 100
I 100

	s = splnet();
	inp = sotoinpcb(so);
E 100
E 80
I 29
	/*
D 47
	 * Make sure attached.  If not,
	 * only PRU_ATTACH is valid.
E 47
I 47
	 * When a TCP is attached to a socket, then there will be
	 * a (struct inpcb) pointed at by the socket, and this
	 * structure will point at a subsidary (struct tcpcb).
D 64
	 * The normal sequence of events is:
	 *	PRU_ATTACH		creating these structures
	 *	PRU_CONNECT		connecting to a remote peer
	 *	(PRU_SEND|PRU_RCVD)*	exchanging data
	 *	PRU_DISCONNECT		disconnecting from remote peer
	 *	PRU_DETACH		deleting the structures
	 * With the operations from PRU_CONNECT through PRU_DISCONNECT
	 * possible repeated several times.
	 *
	 * MULTIPLE CONNECTS ARE NOT YET IMPLEMENTED.
E 64
E 47
	 */
I 42
D 43
printf("tcp_usrreq %d so %x inp %x\n", req, so, inp);
E 43
E 42
E 29
D 4
COUNT(SYS_CLS);
	t_open(wp->w_tcb, ACTIVE);
	send_ctl(wp->w_tcb);            /* send SYN */
E 4
I 4
D 7
	wp->w_type = input;
	wp->w_stype = stype;
	wp->w_tcb = tp;
	wp->w_dat = m;
E 7
D 28
	nstate = tp->t_state;
D 6
	tp->net_keep = 0;
E 6
I 6
	tp->tc_flags &= ~TC_NET_KEEP;
E 28
I 28
D 31
	if (tp) {
		nstate = tp->t_state;
		tp->tc_flags &= ~TC_NET_KEEP;
D 29
	} else 
		if (req != PRU_ATTACH)
			return (ENOTCONN);
E 29
I 29
	} else
E 31
I 31
D 36
#ifdef TCPDEBUG
	tdb.td_tod = 0;
#endif
E 36
D 37
	if (inp == 0) {
E 31
		if (req != PRU_ATTACH) {
			splx(s);
			return (EINVAL);
		}
D 31

	/*
	 * Do tracing and accounting.
	 */
E 31
I 31
	} else {
E 37
I 37
D 38
	if (inp == 0 && req != PRU_ATTACH)
E 38
I 38
	if (inp == 0 && req != PRU_ATTACH) {
E 38
		splx(s);
I 110
		/*
		 * The following corrects an mbuf leak under rare
		 * circumstances, but has not been fully tested.
		 */
		if (m && req != PRU_SENSE)
			m_freem(m);
E 110
D 47
		return (EINVAL);
E 47
I 47
		return (EINVAL);		/* XXX */
E 47
	}
	if (inp) {
E 37
		tp = intotcpcb(inp);
I 64
		/* WHAT IF TP IS 0? */
E 64
D 37
		nstate = tp->t_state;
E 37
E 31
E 29
E 28
I 25
#ifdef KPROF
E 25
E 6
D 28
	acounts[nstate][input]++;
E 28
I 28
D 31
	acounts[nstate][req]++;
E 31
I 31
D 37
		tcp_acounts[nstate][req]++;
E 37
I 37
		tcp_acounts[tp->t_state][req]++;
E 37
E 31
E 28
I 25
#endif
I 45
		ostate = tp->t_state;
E 45
E 25
I 7
D 36
#ifdef TCPDEBUG
D 28
	if ((tp->t_ucb->uc_flags & UDEBUG) || tcpconsdebug) {
D 12
		tdb.td_tod = time;
		tdb.td_tcb = tp;
		tdb.td_old = nstate;
		tdb.td_inp = input;
E 12
I 12
		tdb_setup(tp, (struct th *)0, input, &tdb);
E 28
I 28
D 31
	if (tp && ((tp->t_socket->so_options & SO_DEBUG) || tcpconsdebug)) {
D 29
		tdb_setup(tp, (struct th *)0, req, &tdb);
E 29
I 29
		tdb_setup(tp, (struct tcpiphdr *)0, req, &tdb);
E 29
E 28
E 12
		tdb.td_tim = timertype;
	} else
		tdb.td_tod = 0;
E 31
I 31
		if (((tp->t_socket->so_options & SO_DEBUG) || tcpconsdebug)) {
			tdb_setup(tp, (struct tcpiphdr *)0, req, &tdb);
			tdb.td_tim = timertype;
		}
E 31
#endif
I 31
		tp->tc_flags &= ~TC_NET_KEEP;
E 36
D 62
	}
E 62
I 62
	} else
		ostate = 0;
E 62
D 37

E 37
E 31
E 7
D 25
	switch (tcp_fstab[nstate][input]) {
E 25
I 25
D 28
	switch (input) {
E 28
I 28
	switch (req) {
E 28
E 25
E 4

I 47
	/*
	 * TCP attaches to socket via PRU_ATTACH, reserving space,
D 64
	 * and internet and TCP control blocks.
	 * If the socket is to receive connections,
	 * then the LISTEN state is entered.
E 64
I 64
	 * and an internet control block.
E 64
	 */
E 47
D 4
	return(SYN_SENT);
}
E 4
I 4
D 25
	default:
		printf("tcp: bad state: tcb=%x state=%d input=%d\n",
		    tp, tp->t_state, input);
		nstate = EFAILEC;
		break;
E 4

D 4
cls_opn(wp)             /* close request before receiving foreign SYN (10) */
struct work *wp;                           
{
E 4
I 4
	case LIS_CLS:				/* 1 */
E 25
I 25
D 29
	/*
D 28
	 * Passive open.  Create a tcp control block
	 * and enter listen state.
E 28
I 28
	 * Attach a tcp control block to this socket.
	 * TCP is not multicast, so this is possible
	 * only if no connection currently exists.
E 28
	 */
E 29
D 26
	case IUOPENA:				/* 2 */
E 26
I 26
D 28
	case IUOPENA:
E 26
		if (nstate != 0 && nstate != CLOSED)
			goto bad;
E 25
D 19
		t_open(tp, PASSIVE);
E 19
I 19
		tcp_open(tp, PASSIVE);
E 19
		nstate = LISTEN;
E 28
I 28
	case PRU_ATTACH:
D 31
		if (tp)
E 31
I 31
D 33
		if (tp) {
E 33
I 33
		if (inp) {
E 33
E 31
			error = EISCONN;
D 29
		else
			tp = tcp_attach(so, &error);
		nstate = CLOSED;
E 29
I 29
D 31
		else {
			tcp_attach(so);
			tp = sototcpcb(so);
E 31
I 31
			break;
E 31
		}
I 31
D 33
		tcp_attach(so);
		tp = sototcpcb(so);
E 31
		if (so->so_options & SO_ACCEPTCONN) {
D 30
			inp->inp_lhost = h_make(&n_lhost);
E 30
I 30
D 31
			inp->inp_lhost = in_hmake(&n_lhost);
E 30
			in_pcbgenport(&tcb, inp);
E 31
I 31
			inp->inp_lhost = in_hostalloc(&n_lhost);	/*XXX*/
			inp->inp_lport = in_pcbgenport(&tcb);
E 33
I 33
D 35
		tp = tcp_newtcpcb();
		if (tp == 0) {
			error = ENOBUFS;
			break;
		}
E 35
D 40
		error = in_pcballoc(so, &tcb, 2048, 2048, (struct sockaddr_in *)addr);
E 40
I 40
D 47
		error = in_pcbattach(so, &tcb, 2048, 2048, (struct sockaddr_in *)addr);
E 47
I 47
D 64
		error = tcp_attach(so, (struct sockaddr *)addr);
E 64
I 64
D 69
		error = tcp_attach(so, nam);
E 69
I 69
		error = tcp_attach(so);
E 69
E 64
E 47
E 40
D 37
		if (error) {
D 34
			m_free(dtom(tp));
E 34
I 34
			(void) m_free(dtom(tp));
E 37
I 37
		if (error)
E 37
E 34
			break;
I 48
D 73
		if ((so->so_options & SO_DONTLINGER) == 0)
E 73
I 73
D 75
		if (so->so_options & SO_LINGER && so->so_linger == 0)
E 75
I 75
		if ((so->so_options & SO_LINGER) && so->so_linger == 0)
E 75
E 73
			so->so_linger = TCP_LINGERTIME;
E 48
D 37
		}
E 37
D 47
		inp = (struct inpcb *)so->so_pcb;
I 42
		tp = tcp_newtcpcb(inp);
E 42
D 35
		tp->t_inpcb = inp;
		inp->inp_ppcb = (caddr_t)tp;
		if (so->so_options & SO_ACCEPTCONN)
E 35
I 35
		if (so->so_options & SO_ACCEPTCONN) {
D 42
			tp = tcp_newtcpcb(inp);
E 42
			if (tp == 0) {
I 37
D 40
				in_pcbfree(inp);
E 40
I 40
				in_pcbdetach(inp);
E 40
E 37
				error = ENOBUFS;
				break;
			}
E 35
E 33
E 31
D 37
			nstate = LISTEN;
E 37
I 37
			tp->t_state = TCPS_LISTEN;
E 37
D 33
		} else
E 33
I 33
D 35
		else
E 35
I 35
		} else
E 35
E 33
D 37
			nstate = CLOSED;
E 37
I 37
			tp->t_state = TCPS_CLOSED;
E 47
I 47
		tp = sototcpcb(so);
E 47
E 37
E 29
E 28
		break;
E 4

I 47
	/*
	 * PRU_DETACH detaches the TCP protocol from the socket.
	 * If the protocol state is non-embryonic, then can't
	 * do this directly: have to initiate a PRU_DISCONNECT,
	 * which may finish later; embryonic TCB's can just
	 * be discarded here.
	 */
E 47
D 4
COUNT(CLS_OPN);
	t_close(wp->w_tcb, UCLOSED);
E 4
I 4
D 25
	case SYS_CLS:				/* 2 */
E 25
I 25
D 29
	/*
D 28
	 * Active open.  Create a tcp control block,
	 * send a SYN and enter SYN_SENT state.
E 28
I 28
	 * Detach the TCP from this socket.  This
	 * is possible only if a connection currently exists.
E 28
	 */
E 29
D 26
	case IUOPENR:				/* 1 */
E 26
I 26
D 28
	case IUOPENR:
E 28
I 28
	case PRU_DETACH:
I 45
D 47
		if (tp)
			goto disconn;
E 45
I 40
		in_pcbdetach(inp);
E 47
I 47
		if (tp->t_state > TCPS_LISTEN)
D 75
			tcp_disconnect(tp);
		else {
			tcp_close(tp);
			tp = 0;
		}
E 75
I 75
			tp = tcp_disconnect(tp);
		else
			tp = tcp_close(tp);
E 75
E 47
E 40
D 29
		so->so_pcb = 0;
E 29
I 29
D 31
		tcp_detach(so);
E 31
I 31
D 35
		tcp_detach(tp);
E 35
E 31
E 29
		break;

I 47
	/*
I 64
	 * Give the socket an address.
	 */
	case PRU_BIND:
		error = in_pcbbind(inp, nam);
		if (error)
			break;
		break;

	/*
	 * Prepare to accept connections.
	 */
	case PRU_LISTEN:
		if (inp->inp_lport == 0)
			error = in_pcbbind(inp, (struct mbuf *)0);
		if (error == 0)
			tp->t_state = TCPS_LISTEN;
		break;

	/*
E 64
	 * Initiate connection to peer.
	 * Create a template for use in transmissions on this connection.
	 * Enter SYN_SENT state, and mark socket as connecting.
	 * Start keep-alive timer, and seed output sequence space.
	 * Send initial segment on connection.
	 */
E 47
D 29
	/*
	 * Form connection: send a SYN.
	 */
E 29
	case PRU_CONNECT:
E 28
E 26
D 29
		if (nstate != 0 && nstate != CLOSED)
E 29
I 29
D 35
		if (tp->t_state != 0 && tp->t_state != CLOSED)
E 29
			goto bad;
E 35
I 29
D 31
		inp->inp_fhost = in_hmake((struct in_addr *)addr, &error);
E 31
I 31
D 32
		inp->inp_fhost = in_hosteval((struct inaddr *)addr, &error);
E 32
I 32
D 33
		inp->inp_fhost = in_hosteval((struct sockaddr *)addr, &error);
E 32
E 31
		if (inp->inp_fhost == 0)
E 33
I 33
D 40
		error = in_pcbsetpeer(inp, (struct sockaddr_in *)addr);
E 40
I 40
D 64
		error = in_pcbconnect(inp, (struct sockaddr_in *)addr);
E 64
I 64
		if (inp->inp_lport == 0) {
			error = in_pcbbind(inp, (struct mbuf *)0);
			if (error)
				break;
		}
		error = in_pcbconnect(inp, nam);
E 64
E 40
		if (error)
E 33
			break;
I 35
D 45
		tp = tcp_newtcpcb(inp);
D 42
		if (tp == 0) {
D 40
			inp->inp_faddr.s_addr = 0;
E 40
I 40
			in_pcbdisconnect(inp);
E 40
			error = ENOBUFS;
			break;
		}
E 42
I 42
		if (tp == 0)
			goto badcon;
E 45
E 42
I 41
		tp->t_template = tcp_template(tp);
I 42
D 47
		if (tp->t_template == 0)
			goto badcon2;
E 42
E 41
		tp->t_inpcb = inp;
		inp->inp_ppcb = (caddr_t)tp;
E 47
I 47
		if (tp->t_template == 0) {
			in_pcbdisconnect(inp);
			error = ENOBUFS;
			break;
		}
E 47
E 35
E 29
E 25
D 19
		t_open(tp, ACTIVE);
		send_ctl(tp);
E 19
I 19
D 28
		tcp_open(tp, ACTIVE);
E 28
D 31
		tcp_sndctl(tp);
E 31
I 31
D 37
		(void) tcp_sndctl(tp);
E 31
E 19
		nstate = SYN_SENT;
E 37
I 29
		soisconnecting(so);
I 97
		tcpstat.tcps_connattempt++;
E 97
I 37
		tp->t_state = TCPS_SYN_SENT;
I 42
D 105
		tp->t_timer[TCPT_KEEP] = TCPTV_KEEP;
E 105
I 105
		tp->t_timer[TCPT_KEEP] = TCPTV_KEEP_INIT;
E 105
		tp->iss = tcp_iss; tcp_iss += TCP_ISSINCR/2;
		tcp_sendseqinit(tp);
E 42
D 39
		tcp_output(tp);
E 39
I 39
D 57
		(void) tcp_output(tp);
E 57
I 57
		error = tcp_output(tp);
E 57
E 39
E 37
E 29
		break;
E 4

I 42
D 47
badcon2:
		(void) m_free(dtom(tp));
badcon:
		in_pcbdisconnect(inp);
		error = ENOBUFS;
E 47
I 47
	/*
I 81
	 * Create a TCP connection between two sockets.
	 */
	case PRU_CONNECT2:
		error = EOPNOTSUPP;
		break;

	/*
E 81
	 * Initiate disconnect from peer.
	 * If connection never passed embryonic stage, just drop;
	 * else if don't need to let data drain, then can just drop anyways,
	 * else have to begin TCP shutdown process: mark socket disconnecting,
	 * drain unread data, state switch to reflect user close, and
	 * send segment (e.g. FIN) to peer.  Socket will be really disconnected
	 * when peer sends FIN and acks ours.
	 *
	 * SHOULD IMPLEMENT LATER PRU_CONNECT VIA REALLOC TCPCB.
	 */
	case PRU_DISCONNECT:
D 75
		tcp_disconnect(tp);
E 75
I 75
		tp = tcp_disconnect(tp);
E 75
E 47
		break;

I 47
	/*
	 * Accept a connection.  Essentially all the work is
	 * done at higher levels; just return the address
	 * of the peer, storing through addr.
	 */
E 47
E 42
I 32
D 55
	case PRU_ACCEPT:
E 55
I 55
	case PRU_ACCEPT: {
D 64
		struct sockaddr_in *sin = (struct sockaddr_in *)addr;
E 64
I 64
		struct sockaddr_in *sin = mtod(nam, struct sockaddr_in *);
E 64

D 64
		if (sin) {
			bzero((caddr_t)sin, sizeof (*sin));
			sin->sin_family = AF_INET;
			sin->sin_port = inp->inp_fport;
			sin->sin_addr = inp->inp_faddr;
		}
		}
E 64
I 64
		nam->m_len = sizeof (struct sockaddr_in);
		sin->sin_family = AF_INET;
		sin->sin_port = inp->inp_fport;
		sin->sin_addr = inp->inp_faddr;
E 64
E 55
I 45
D 47
		*(struct sockaddr *)addr = so->so_addr;
E 47
I 47
D 54
		in_pcbconnaddr(inp, (struct sockaddr *)addr);
E 54
E 47
E 45
D 33
		return (EOPNOTSUPP);		/* XXX */
E 33
I 33
D 44
		soisconnected(so);
E 44
		break;
I 64
		}
E 64
E 33

E 32
I 28
D 47
	case PRU_DISCONNECT:
I 45
disconn:
E 45
D 29
		so->so_pcb = 0;
		tcp_destroy(tp);
E 29
I 29
D 35
		if ((tp->tc_flags & TC_FIN_RCVD) == 0)
			goto abort;
E 35
D 37
		if (nstate < ESTAB)
D 31
			tcp_disconnect(so);
E 31
I 31
			tcp_disconnect(tp);
E 37
I 37
		if (tp->t_state < TCPS_ESTABLISHED)
			tcp_close(tp);
I 46
		else if ((so->so_state & SO_LETDATADRAIN) == 0)
			tcp_drop(tp, 0);
E 46
E 37
E 31
		else {
D 37
			tp->tc_flags |= TC_SND_FIN;
D 31
			tcp_sendctl(tp);
E 31
I 31
			(void) tcp_sndctl(tp);
E 37
E 31
D 35
			tp->tc_flags |= TC_USR_CLOSED;
E 35
			soisdisconnecting(so);
I 46
			sbflush(&so->so_rcv);
E 46
I 42
			tcp_usrclosed(tp);
E 42
I 37
D 39
			tcp_output(tp);
E 39
I 39
			(void) tcp_output(tp);
E 39
E 37
		}
E 29
		break;

E 47
I 47
	/*
	 * Mark the connection as being incapable of further output.
	 */
E 47
I 31
D 32
	case PRU_FLUSH:
		error = EOPNOTSUPP;
		break;

E 32
E 31
E 28
D 4
	return(CLOSED);
}
E 4
I 4
D 25
	case CLS_OPN:				/* 10 */
D 19
		t_close(tp, UCLOSED);
E 19
I 19
		tcp_close(tp, UCLOSED);
E 19
		nstate = CLOSED;
		break;
E 25
I 25
D 29
	/*
D 28
	 * Tcp close call.  Can be generated by a user ioctl (half-close),
E 28
I 28
	 * Declare no further transmissions.
	 * Can be generated by a user ioctl (half-close),
E 28
	 * or when higher level close occurs, if a close hasn't happened
	 * already.
	 */
E 29
D 28
	case IUCLOSE:
E 28
I 28
	case PRU_SHUTDOWN:
E 28
D 37
		switch (nstate) {
E 37
I 37
D 38
		socantsndmore(so);
E 38
I 38
		socantsendmore(so);
E 38
D 42
		switch (tp->t_state) {
E 37
E 25
E 4

D 4
cl2_clw(wp)             /* close request after receiving foreign FIN (13) */
struct work *wp;
{
	register struct tcb *tp;
E 4
I 4
D 25
	case CL2_CLW:				/* 10 */
D 6
		tp->snd_fin = 1;
E 6
I 6
		tp->tc_flags |= TC_SND_FIN;
E 6
D 19
		send_ctl(tp);
E 19
I 19
		tcp_sndctl(tp);
E 19
D 6
		tp->usr_closed = 1;
E 6
I 6
		tp->tc_flags |= TC_USR_CLOSED;
E 6
		nstate = CLOSING2;
E 25
I 25
D 29
		/*
		 * If we are aborting out of a listener or a active
		 * connection which has not yet completed we can just
		 * delete the tcb.
		 */
E 29
D 36
		case LISTEN:
D 26
		case SYN_SENT:			/* 10 */
E 26
I 26
		case SYN_SENT:
E 26
D 28
			tcp_close(tp, UCLOSED);
E 28
			nstate = CLOSED;
E 36
I 36
		case TCPS_LISTEN:
		case TCPS_SYN_SENT:
D 37
			nstate = TCPS_CLOSED;
E 37
I 37
			tp->t_state = TCPS_CLOSED;
E 37
E 36
			break;

D 29
		/*
		 * If we have gotten as far as receiving a syn from
		 * our foreign peer, we must be sure to send a FIN.
		 * If we have gotten a FIN from the foreign peer already
		 * (CLOSE_WAIT state), then all that remains is to wait
		 * for his ack of the FIN (LAST_ACK state).  If we have
		 * not gotten a FIN from the foreign peer then we need
		 * to either:
		 *	1. rcv ack of our FIN (to FIN_W2) and then
		 *	   send an ACK (to TIME_WAIT) and timeout at 2*MSL.
		 * or	2. receive hist FIN (to CLOSING), send an ACK
		 *	   (to TIME_WAIT), and then timeout.
		 * In any case this starts with a transition to FIN_W1 here.
		 */
E 29
D 26
		case SYN_RCVD:			/* 24,25 */
E 26
I 26
D 36
		case SYN_RCVD:
E 26
		case L_SYN_RCVD:
		case ESTAB:	
D 26
		case CLOSE_WAIT:		/* 10 */
E 26
I 26
		case CLOSE_WAIT:
E 36
I 36
D 38
		case TCPS_SYN_RCVD:
D 37
		case TCPS_ESTABLISHED:
		case TCPS_CLOSE_WAIT:
E 36
E 26
			tp->tc_flags |= TC_SND_FIN;
D 31
			tcp_sndctl(tp);
E 31
I 31
			(void) tcp_sndctl(tp);
E 31
D 35
			tp->tc_flags |= TC_USR_CLOSED;
E 35
			nstate = nstate != CLOSE_WAIT ? FIN_W1 : LAST_ACK;
E 37
I 37
		case TCPS_ESTAB:
E 38
I 38
		case TCPS_SYN_RECEIVED:
		case TCPS_ESTABLISHED:
E 38
			tp->t_state = TCPS_FIN_WAIT_1;
D 39
			tcp_output(tp);
E 39
I 39
			(void) tcp_output(tp);
E 39
E 37
			break;
D 37
			
D 29
		/*
		 * In these states the user has already closed;
		 * trying to close again is an error.
		 */
E 29
D 36
		case FIN_W1:
		case FIN_W2:
		case TIME_WAIT:
		case CLOSING:
		case LAST_ACK:
		case RCV_WAIT:
E 36
I 36
		case TCPS_FIN_W1:
		case TCPS_FIN_W2:
		case TCPS_TIME_WAIT:
		case TCPS_CLOSING:
		case TCPS_LAST_ACK:
		case TCPS_RCV_WAIT:
E 36
D 28
			to_user(tp->t_ucb, UCLSERR);
E 28
			break;
E 37

D 37
		default:
			goto bad;
E 37
I 37
		case TCPS_CLOSE_WAIT:
			tp->t_state = TCPS_LAST_ACK;
D 39
			tcp_output(tp);
E 39
I 39
			(void) tcp_output(tp);
E 39
			break;
E 37
		}
E 42
I 42
D 75
		tcp_usrclosed(tp);
D 57
		(void) tcp_output(tp);
E 57
I 57
		error = tcp_output(tp);
E 75
I 75
		tp = tcp_usrclosed(tp);
		if (tp)
			error = tcp_output(tp);
E 75
E 57
E 42
E 25
		break;
E 4

I 47
	/*
	 * After a receive, possibly send window update to peer.
	 */
E 47
D 4
COUNT(CL2_CLW);
	tp = wp->w_tcb;
E 4
I 4
D 25
	case TIMERS:				/* 14,17,34,35,36,37,38 */
D 7
		nstate = tcp_timers(wp);
E 7
I 7
		nstate = tcp_timers(tp, timertype);
E 25
I 25
D 29
	/*
D 28
	 * TCP Timer processing.
	 * Timers should expire only on open connections
	 * not in LISTEN state.
	 */
D 26
	case ISTIMER:				/* 14,17,34,35,36,37,38 */
E 26
I 26
	case ISTIMER:
E 26
		switch (nstate) {

		case 0:
		case CLOSED:
		case LISTEN:
			goto bad;

		default:
			nstate = tcp_timers(tp, timertype);
		}
E 25
E 7
		break;
E 4

D 4
	tp->snd_fin = TRUE;             /* send our own FIN */
	send_ctl(tp);                   
	tp->usr_closed = TRUE;
E 4
I 4
D 25
	case CLS_RWT:				/* 20 */
E 25
I 25
	/*
E 28
	 * User notification of more window availability after
	 * reading out data.  This should not happen before a connection
	 * is established or after it is closed.
	 * If the foreign peer has closed and the local entity
	 * has not, inform him of the FIN (give end of file).
	 * If the local entity is in RCV_WAIT state (draining data
	 * out of the TCP buffers after foreign close) and there
	 * is no more data, institute a close.
	 */
E 29
D 26
	case IURECV:				/* 42 */
E 26
I 26
D 28
	case IURECV:
E 28
I 28
	case PRU_RCVD:
E 28
E 26
D 36
		if (nstate < ESTAB || nstate == CLOSED)
E 36
I 36
D 37
		if (nstate < TCPS_ESTAB)
E 36
			goto bad;
D 26
		tcp_sndwin(tp);		/* send new window */
E 26
I 26
		tcp_sndwin(tp);
E 26
E 25
D 23
		present_data(tp);
E 23
I 23
D 35
		if ((tp->tc_flags&TC_FIN_RCVD) &&
		    (tp->tc_flags&TC_USR_CLOSED) == 0 &&
		    rcv_empty(tp))
D 28
			to_user(tp, UCLOSED);
E 23
D 25
		if (rcv_empty(tp)) {
E 25
I 25
		if (nstate == RCV_WAIT && rcv_empty(tp)) {
E 25
D 19
			t_close(tp, UCLOSED);
E 19
I 19
			tcp_close(tp, UCLOSED);
E 28
I 28
D 29
			tcp_error(tp, ESHUTDOWN);
E 29
I 29
			error = ESHUTDOWN;
E 35
E 29
D 36
		if (nstate == RCV_WAIT && rcv_empty(tp))
E 28
E 19
			nstate = CLOSED;
E 36
I 36
		if (nstate == TCPS_RCV_WAIT && rcv_empty(tp))
			nstate = TCPS_CLOSED;
E 37
I 37
D 38
		if (tp->t_state < TCPS_ESTABLISHED) {
			error = ENOTCONN;
			break;
		}
E 38
D 39
		tcp_output(tp);
E 39
I 39
		(void) tcp_output(tp);
E 39
E 37
E 36
D 25
		} else
			nstate = RCV_WAIT;
E 25
I 25
D 28
		}
E 28
E 25
		break;
E 4

I 47
	/*
	 * Do a send by putting data in output queue and updating urgent
	 * marker if URG set.  Possibly send more data.
	 */
E 47
D 4
	return(CLOSING2);
E 4
I 4
D 25
	case FW1_SYR:				/* 24,25 */
D 6
		tp->snd_fin = 1;
E 6
I 6
		tp->tc_flags |= TC_SND_FIN;
E 6
D 19
		send_ctl(tp);
E 19
I 19
		tcp_sndctl(tp);
E 19
D 6
		tp->usr_closed = 1;
E 6
I 6
		tp->tc_flags |= TC_USR_CLOSED;
E 6
		nstate = FIN_W1;
		break;
E 25
I 25
D 29
	/*
	 * Send request on open connection.
	 * Should not happen if the connection is not yet established.
	 * Allowed only on ESTAB connection and after FIN from
	 * foreign peer.
	 */
E 29
D 26
	case IUSEND:				/* 40,41 */
E 26
I 26
D 28
	case IUSEND:
E 28
I 28
	case PRU_SEND:
E 28
E 26
D 37
		switch (nstate) {
E 25

D 25
	case SSS_SND:				/* 40,41 */
D 7
		nstate = sss_snd(wp);
E 7
I 7
D 11
		nstate = sss_snd(tp, mp);
E 11
I 11
D 20
		nstate = sss_send(tp, mp);
E 20
I 20
		nstate = tcp_usrsend(tp, mp);
E 25
I 25
		case ESTAB:
		case CLOSE_WAIT:
D 29
			nstate = tcp_usrsend(tp, m);
E 29
I 29
			tcp_usrsend(tp, m);
E 37
I 37
D 38
		if (tp->t_state < TCPS_ESTABLISHED) {
			error = ENOTCONN;
E 37
E 29
			break;
D 37
		
		default:
			if (nstate < ESTAB)
				goto bad;
E 37
I 37
		}
		if (tp->t_state > TCPS_CLOSE_WAIT) {
			error = EISDISCONN;
E 37
D 28
			to_user(tp, UCLSERR);
E 28
I 28
			m_freem(m);
D 29
			/* tcp_user(tp, UCLSERR); */
E 29
I 29
D 37
			error = ENOTCONN;
E 37
E 29
E 28
			break;
		}
E 38
I 37
		sbappend(&so->so_snd, m);
D 38
		if (tp->t_options & TO_EOL)
E 38
I 38
D 57
/*
E 57
I 57
D 100
#ifdef notdef
E 57
		if (tp->t_flags & TF_PUSH)
E 38
			tp->snd_end = tp->snd_una + so->so_snd.sb_cc;
D 38
		if (tp->t_options & TO_URG)
			tp->snd_urp = tp->snd_una + so->so_snd.sb_cc + 1;
E 38
I 38
D 57
 */
D 49
		if (tp->t_flags & TF_URG)
			tp->snd_up = tp->snd_una + so->so_snd.sb_cc + 1;
E 49
E 38
D 39
		tcp_output(tp);
E 39
I 39
		(void) tcp_output(tp);
E 57
I 57
#endif
E 100
		error = tcp_output(tp);
I 78
D 80
		if (error == ENOBUFS)		/* XXX */
			error = 0;		/* XXX */
E 80
I 80
D 103
		if (error) {		/* XXX fix to use other path */
			if (error == ENOBUFS)		/* XXX */
				error = 0;		/* XXX */
			tcpsenderrors++;
		}
E 103
E 80
E 78
E 57
E 39
E 37
E 25
E 20
E 11
E 7
		break;

I 47
	/*
	 * Abort the TCP.
	 */
E 47
D 25
	case SSS_RCV:				/* 42 */
D 18
		send_ctl(tp);		/* send new window */
E 18
I 18
D 19
		send_win(tp);		/* send new window */
E 19
I 19
		tcp_sndwin(tp);		/* send new window */
E 19
E 18
D 23
		present_data(tp);
E 23
I 23
		if ((tp->tc_flags&TC_FIN_RCVD) &&
		    (tp->tc_flags&TC_USR_CLOSED) == 0 &&
		    rcv_empty(tp))
			to_user(tp, UCLOSED);
E 23
		break;
E 25
I 25
D 29
	/*
	 * User abort of connection.
	 * If a SYN has been received, but we have not exchanged FINs
	 * then we need to send an RST.  In any case we then 
	 * enter closed state.
	 */
E 29
I 29
D 35
abort:
E 35
E 29
D 26
	case IUABORT:				/* 44,45 */
E 26
I 26
D 28
	case IUABORT:
E 28
I 28
	case PRU_ABORT:
E 28
E 26
D 29
		if (nstate == 0 || nstate == CLOSED)
			break;
		switch (nstate) {
E 25

D 25
	case CLS_NSY:				/* 44 */
D 19
		t_close(tp, UABORT);
E 19
I 19
		tcp_close(tp, UABORT);
E 19
		nstate = CLOSED;
		break;
E 25
I 25
		case 0:
		case CLOSED:
			break;
E 25

D 25
	case CLS_SYN:				/* 45 */
D 6
		tp->snd_rst = 1;
E 6
I 6
		tp->tc_flags |= TC_SND_RST;
E 6
D 19
		send_null(tp);
		t_close(tp, UABORT);
E 19
I 19
		tcp_sndnull(tp);
		tcp_close(tp, UABORT);
E 19
		nstate = CLOSED;
E 25
I 25
		case SYN_RCVD:
		case ESTAB:
		case FIN_W1:
		case FIN_W2:
		case CLOSE_WAIT:
			tp->tc_flags |= TC_SND_RST;
			tcp_sndnull(tp);
			/* fall into ... */

		default:
D 28
			tcp_close(tp, UABORT);
E 28
			nstate = CLOSED;
		}
E 25
		break;

D 25
	case CLS_ACT:				/* 47 */
E 25
I 25
	/*
	 * Network down entry.  Discard the tcb and force
	 * the state to be closed, ungracefully.
	 */
D 26
	case INCLEAR:				/* 47 */
E 26
I 26
D 28
	case INCLEAR:
E 28
I 28
	case PRU_CLEAR:
E 28
E 26
		if (nstate == 0 || nstate == CLOSED)
			break;
E 29
I 29
D 37
		tcp_abort(tp);
E 29
E 25
D 19
		t_close(tp, UNETDWN);
E 19
I 19
D 28
		tcp_close(tp, UNETDWN);
E 28
E 19
		nstate = CLOSED;
E 37
I 37
D 75
		tcp_drop(tp, ECONNABORTED);
E 75
I 75
		tp = tcp_drop(tp, ECONNABORTED);
E 75
E 37
		break;

I 47
D 88
/* SOME AS YET UNIMPLEMENTED HOOKS */
E 47
I 28
D 29
	/*
	 * Ioctl on protocols.
	 */
E 29
	case PRU_CONTROL:
I 39
		error = EOPNOTSUPP;
		break;
I 85
/* END UNIMPLEMENTED HOOKS */
E 85

E 88
	case PRU_SENSE:
D 85
		error = EOPNOTSUPP;
		break;
I 49
/* END UNIMPLEMENTED HOOKS */
E 85
I 85
		((struct stat *) m)->st_blksize = so->so_snd.sb_hiwat;
I 98
		(void) splx(s);
E 98
		return (0);
E 85
E 49

	case PRU_RCVOOB:
D 49
		error = EOPNOTSUPP;
E 49
I 49
D 50
		if (tp->t_haveoob == 0) {
E 50
I 50
D 51
#if TCPTRUEOOB
		if (tp->t_flags & TF_DOOOB) {
			if ((tp->t_oobflags & TCPOOB_HAVEDATA) == 0) {
				error = EWOULDBLOCK;
				break;
			}
			*mtod(m, caddr_t) = tp->t_iobc;
			tp->t_oobflags &= ~TCPOOB_HAVEDATA;
			break;
		}
#endif
E 51
D 90
		if (so->so_oobmark == 0 &&
		    (so->so_state & SS_RCVATMARK) == 0) {
E 90
I 90
		if ((so->so_oobmark == 0 &&
		    (so->so_state & SS_RCVATMARK) == 0) ||
I 104
#ifdef SO_OOBINLINE
E 104
I 95
		    so->so_options & SO_OOBINLINE ||
I 104
#endif
E 104
E 95
		    tp->t_oobflags & TCPOOB_HADDATA) {
E 90
E 50
			error = EINVAL;
			break;
		}
D 50
		*mtod(m, caddr_t) = tp->t_oobc;
		tp->t_haveoob = 0;
E 50
I 50
D 51
		if (so->so_rcv.sb_cc < so->so_oobmark) {
E 51
I 51
		if ((tp->t_oobflags & TCPOOB_HAVEDATA) == 0) {
E 51
			error = EWOULDBLOCK;
D 51
			return;
E 51
I 51
			break;
E 51
		}
I 65
		m->m_len = 1;
E 65
D 51
		{ struct mbuf *n = so->so_rcv.sb_mb;
		  int cnt = so->so_oobmark;
		  while (cnt > n->m_len) {
			cnt -= n->m_len;
			n = n->m_next;
		  }
		  *mtod(m, caddr_t) = *(mtod(n, caddr_t) + cnt);
		}
		tp->t_oobflags &= ~TCPOOB_HAVEDATA;
E 51
I 51
		*mtod(m, caddr_t) = tp->t_iobc;
I 90
		if (((int)nam & MSG_PEEK) == 0)
			tp->t_oobflags ^= (TCPOOB_HAVEDATA | TCPOOB_HADDATA);
E 90
E 51
E 50
E 49
		break;

	case PRU_SENDOOB:
I 51
D 66
#ifdef TCPTRUEOOB
		if (tp->t_flags & TF_DOOOB) {
			tp->t_oobseq++;
			tp->t_oobc = *mtod(m, caddr_t);
			tp->t_oobmark = tp->snd_una + so->so_snd.sb_cc;
D 62
printf("sendoob seq now %x oobc %x\n", tp->t_oobseq, tp->t_oobc);
E 62
			tp->t_oobflags |= TCPOOB_NEEDACK;
D 57
			(void) tcp_output(tp);
E 57
I 57
			/* what to do ...? */
			if (error = tcp_output(tp))
				break;
E 57
		}
#endif
E 66
E 51
I 50
		if (sbspace(&so->so_snd) < -512) {
I 77
			m_freem(m);
E 77
			error = ENOBUFS;
			break;
		}
E 50
E 39
I 29
D 49
		error = EOPNOTSUPP;
E 49
I 49
D 95
		tp->snd_up = tp->snd_una + so->so_snd.sb_cc + 1;
E 95
I 95
		/*
		 * According to RFC961 (Assigned Protocols),
		 * the urgent pointer points to the last octet
		 * of urgent data.  We continue, however,
		 * to consider it to indicate the first octet
		 * of data past the urgent section.
		 * Otherwise, snd_up should be one lower.
		 */
E 95
		sbappend(&so->so_snd, m);
I 95
		tp->snd_up = tp->snd_una + so->so_snd.sb_cc;
E 95
D 57
/*
E 57
I 57
D 66
#ifdef notdef
E 57
		if (tp->t_flags & TF_PUSH)
			tp->snd_end = tp->snd_una + so->so_snd.sb_cc;
D 57
 */
E 57
I 57
#endif
E 66
E 57
D 50
		(void) tcp_output(tp);
E 50
I 50
D 51
#ifdef TCPTRUEOOB
		if (tp->t_flags & TF_DOOOB) {
			tp->t_oobseq++;
			tp->t_oobc = *mtod(m, caddr_t);
printf("sendoob seq now %x oobc %x\n", tp->t_oobseq, tp->t_oobc);
			tp->t_oobflags |= TCPOOB_NEEDACK;
		}
#endif
		tp->t_force = 1; (void) tcp_output(tp); tp->t_force = 0;
E 51
I 51
		tp->t_force = 1;
D 57
		(void) tcp_output(tp);
E 57
I 57
		error = tcp_output(tp);
E 57
		tp->t_force = 0;
E 51
E 50
E 49
E 29
		break;
I 47
D 49
/* END UNIMPLEMENTED HOOKS */
E 49
E 47

I 58
	case PRU_SOCKADDR:
D 64
		in_setsockaddr((struct sockaddr_in *)addr, inp);
E 64
I 64
		in_setsockaddr(inp, nam);
E 64
		break;

I 83
	case PRU_PEERADDR:
		in_setpeeraddr(inp, nam);
		break;

E 83
E 58
I 47
	/*
	 * TCP slow timer went off; going through this
	 * routine for tracing's sake.
	 */
E 47
D 29
	/*
	 * TCP Timer processing.
	 * Timers should expire only on open connections
	 * not in LISTEN state.
	 */
E 29
	case PRU_SLOWTIMO:
D 37
		switch (nstate) {

		case 0:
		case CLOSED:
		case LISTEN:
			goto bad;

		default:
			nstate = tcp_timers(tp, (int)addr);
		}
E 37
I 37
D 64
		tcp_timers(tp, (int)addr);
I 45
		req |= (int)addr << 8;		/* for debug's sake */
E 64
I 64
D 75
		tcp_timers(tp, (int)nam);
E 75
I 75
		tp = tcp_timers(tp, (int)nam);
E 75
		req |= (int)nam << 8;		/* for debug's sake */
E 64
E 45
E 37
		break;

E 28
D 25
	case NOP:
E 25
I 25
	default:
		panic("tcp_usrreq");
D 37
	bad:
		printf("tcp: bad state: tcb=%x state=%d input=%d\n",
D 28
		    tp, tp->t_state, input);
E 28
I 28
		    tp, tp->t_state, req);
E 28
		nstate = EFAILEC;
E 25
		break;
E 37
D 25

	case CLS_ERR:
		to_user(tp->t_ucb, UCLSERR);
		break;
E 25
	}
I 45
	if (tp && (so->so_options & SO_DEBUG))
		tcp_trace(TA_USER, ostate, tp, (struct tcpiphdr *)0, req);
E 45
D 7
	if (tp->t_ucb->uc_flags & UDEBUG)
		tcp_debug(tp, wp, input, nstate);
E 7
D 36
#ifdef TCPDEBUG
D 7
	tcp_prt(tp, input, wp->w_stype, nstate);
E 7
I 7
D 12
	if (tdb.td_tod) {
		tdb.td_new = nstate;
		tcp_debug[tdbx++ % TDBSIZE] = tdb;
		if (tcpconsdebug)
			tcp_prt(&tdb);
	}
E 12
I 12
	if (tdb.td_tod)
		tdb_stuff(&tdb, nstate);
E 12
E 7
#endif
E 36
D 29
	/* YECH */
E 29
D 37
	switch (nstate) {

I 7
	case CLOSED:
E 7
	case SAME:
		break;

	case EFAILEC:
D 7
		if (m)
			m_freem(dtom(m));
E 7
I 7
D 25
		if (mp)
			m_freem(dtom(mp));
E 25
I 25
		if (m)
			m_freem(dtom(m));
E 25
E 7
		break;

	default:
		tp->t_state = nstate;
		break;
	}
E 37
	splx(s);
I 29
	return (error);
I 90
}

I 104
#if BSD>=43
E 104
D 91
tcp_ctloutput(op, so, level, optname, m)
E 91
I 91
tcp_ctloutput(op, so, level, optname, mp)
E 91
	int op;
	struct socket *so;
	int level, optname;
D 91
	struct mbuf **m;
E 91
I 91
	struct mbuf **mp;
E 91
{
I 91
	int error = 0;
D 109
	struct inpcb *inp = sotoinpcb(so);
	register struct tcpcb *tp = intotcpcb(inp);
E 109
I 109
	struct inpcb *inp;
	register struct tcpcb *tp;
E 109
	register struct mbuf *m;

I 109
	inp = sotoinpcb(so);
	if (inp == NULL) {
		if (op == PRCO_SETOPT && *mp)
			(void) m_free(*mp);
		return (ECONNRESET);
	}
E 109
E 91
	if (level != IPPROTO_TCP)
D 92
		return (ip_ctloutput(op, so, level, optname, m));
E 92
I 92
		return (ip_ctloutput(op, so, level, optname, mp));
I 109
	tp = intotcpcb(inp);
E 109
E 92
D 91
	/* INCOMPLETE */
	return (0);
E 91
I 91

	switch (op) {

	case PRCO_SETOPT:
		m = *mp;
		switch (optname) {

		case TCP_NODELAY:
			if (m == NULL || m->m_len < sizeof (int))
				error = EINVAL;
			else if (*mtod(m, int *))
				tp->t_flags |= TF_NODELAY;
			else
				tp->t_flags &= ~TF_NODELAY;
			break;

		case TCP_MAXSEG:	/* not yet */
		default:
			error = EINVAL;
			break;
		}
D 93
		m_free(m);
E 93
I 93
D 101
		(void)m_free(m);
E 101
I 101
		if (m)
			(void) m_free(m);
E 101
E 93
		break;

	case PRCO_GETOPT:
		*mp = m = m_get(M_WAIT, MT_SOOPTS);
		m->m_len = sizeof(int);

		switch (optname) {
		case TCP_NODELAY:
			*mtod(m, int *) = tp->t_flags & TF_NODELAY;
			break;
		case TCP_MAXSEG:
			*mtod(m, int *) = tp->t_maxseg;
			break;
		default:
			error = EINVAL;
			break;
		}
		break;
	}
	return (error);
E 91
E 90
I 42
}
I 104
#endif
E 104

I 53
D 88
int	tcp_sendspace = 1024*2;
D 59
int	tcp_recvspace = 1024*3;
E 59
I 59
int	tcp_recvspace = 1024*2;
E 88
I 88
D 107
int	tcp_sendspace = 1024*4;
int	tcp_recvspace = 1024*4;
E 107
I 107
u_long	tcp_sendspace = 1024*4;
u_long	tcp_recvspace = 1024*4;
E 107
E 88
E 59
E 53
I 47
/*
 * Attach TCP protocol to socket, allocating
 * internet protocol control block, tcp control block,
 * bufer space, and entering LISTEN state if to accept connections.
 */
D 64
tcp_attach(so, sa)
E 64
I 64
tcp_attach(so)
E 64
	struct socket *so;
D 64
	struct sockaddr *sa;
E 64
{
	register struct tcpcb *tp;
	struct inpcb *inp;
	int error;

D 53
	error = in_pcbattach(so, &tcb, 2048, 2048, (struct sockaddr_in *)sa);
E 53
I 53
D 62
	error = in_pcbattach(so, &tcb,
	    tcp_sendspace, tcp_recvspace, (struct sockaddr_in *)sa);
E 62
I 62
D 72
	error = in_pcbreserve(so, tcp_sendspace, tcp_recvspace);
E 72
I 72
D 107
	error = soreserve(so, tcp_sendspace, tcp_recvspace);
E 72
E 62
E 53
	if (error)
D 62
		return (error);
E 62
I 62
D 86
		goto bad;
E 86
I 86
		return (error);
E 107
I 107
	if (so->so_snd.sb_hiwat == 0 || so->so_rcv.sb_hiwat == 0) {
		error = soreserve(so, tcp_sendspace, tcp_recvspace);
		if (error)
			return (error);
	}
E 107
E 86
	error = in_pcballoc(so, &tcb);
	if (error)
D 64
		goto bad2;
E 62
	inp = (struct inpcb *)so->so_pcb;
I 62
	if (sa || ((so->so_options & SO_ACCEPTCONN) == 0 && so->so_head == 0)) {
		error = in_pcbbind(inp, sa);
		if (error)
			goto bad2;
	}
E 64
I 64
D 86
		goto bad;
E 86
I 86
		return (error);
E 86
	inp = sotoinpcb(so);
E 64
E 62
	tp = tcp_newtcpcb(inp);
D 62
	if (so->so_options & SO_ACCEPTCONN) {
		if (tp == 0) {
			in_pcbdetach(inp);
			return (ENOBUFS);
		}
		tp->t_state = TCPS_LISTEN;
	} else
		tp->t_state = TCPS_CLOSED;
E 62
I 62
	if (tp == 0) {
D 86
		error = ENOBUFS;
		goto bad2;
E 86
I 86
		int nofd = so->so_state & SS_NOFDREF;	/* XXX */

		so->so_state &= ~SS_NOFDREF;	/* don't free the socket yet */
		in_pcbdetach(inp);
		so->so_state |= nofd;
		return (ENOBUFS);
E 86
	}
D 64
	tp->t_state =
	    (so->so_options & SO_ACCEPTCONN) ? TCPS_LISTEN : TCPS_CLOSED;
E 64
I 64
	tp->t_state = TCPS_CLOSED;
E 64
E 62
	return (0);
I 62
D 86
bad2:
	in_pcbdetach(inp);
bad:
	return (error);
E 86
E 62
}

/*
 * Initiate (or continue) disconnect.
 * If embryonic state, just send reset (once).
D 82
 * If not in ``let data drain'' option, just drop.
E 82
I 82
 * If in ``let data drain'' option and linger null, just drop.
E 82
 * Otherwise (hard), mark socket disconnecting and drop
 * current input data; switch states based on user close, and
 * send segment to peer (with FIN).
 */
I 75
struct tcpcb *
E 75
tcp_disconnect(tp)
D 75
	struct tcpcb *tp;
E 75
I 75
	register struct tcpcb *tp;
E 75
{
	struct socket *so = tp->t_inpcb->inp_socket;

	if (tp->t_state < TCPS_ESTABLISHED)
D 75
		tcp_close(tp);
E 75
I 75
		tp = tcp_close(tp);
E 75
D 48
	else if ((so->so_options & SO_LETDATADRAIN) == 0)
E 48
I 48
D 82
	else if (so->so_linger == 0)
E 82
I 82
	else if ((so->so_options & SO_LINGER) && so->so_linger == 0)
E 82
E 48
D 75
		tcp_drop(tp, 0);
E 75
I 75
		tp = tcp_drop(tp, 0);
E 75
	else {
		soisdisconnecting(so);
		sbflush(&so->so_rcv);
D 75
		tcp_usrclosed(tp);
		(void) tcp_output(tp);
E 75
I 75
		tp = tcp_usrclosed(tp);
		if (tp)
			(void) tcp_output(tp);
E 75
	}
I 75
	return (tp);
E 75
}

/*
 * User issued close, and wish to trail through shutdown states:
 * if never received SYN, just forget it.  If got a SYN from peer,
 * but haven't sent FIN, then go to FIN_WAIT_1 state to send peer a FIN.
 * If already got a FIN from peer, then almost done; go to LAST_ACK
 * state.  In all other cases, have already sent FIN to peer (e.g.
 * after PRU_SHUTDOWN), and just have to play tedious game waiting
 * for peer to send FIN or not respond to keep-alives, etc.
I 52
 * We can let the user exit from the close as soon as the FIN is acked.
E 52
 */
I 75
struct tcpcb *
E 75
E 47
D 43
pseqno(tp)
struct tcpcb *tp;
{
printf("tp %x state %s rcv_nxt %x rcv_wnd %d irs %x\n", tp, tcpstates[tp->t_state],tp->rcv_nxt, tp->rcv_wnd, tp->irs);
printf("snd_una %x snd_nxt %x snd_wnd %d snd_wl1 %x snd_wl2 %x iss %x\n",
tp->snd_una, tp->snd_nxt, tp->snd_wnd, tp->snd_wl1, tp->snd_wl2, tp->iss);
}

E 43
tcp_usrclosed(tp)
D 75
	struct tcpcb *tp;
E 75
I 75
	register struct tcpcb *tp;
E 75
{

D 43
printf("usrclosed in %s\n", tcpstates[tp->t_state]);
E 43
	switch (tp->t_state) {

I 79
	case TCPS_CLOSED:
E 79
	case TCPS_LISTEN:
	case TCPS_SYN_SENT:
		tp->t_state = TCPS_CLOSED;
D 75
		tcp_close(tp);
E 75
I 75
		tp = tcp_close(tp);
E 75
		break;

	case TCPS_SYN_RECEIVED:
	case TCPS_ESTABLISHED:
		tp->t_state = TCPS_FIN_WAIT_1;
		break;

	case TCPS_CLOSE_WAIT:
		tp->t_state = TCPS_LAST_ACK;
		break;
	}
I 52
D 75
	if (tp->t_state >= TCPS_FIN_WAIT_2)
E 75
I 75
	if (tp && tp->t_state >= TCPS_FIN_WAIT_2)
E 75
		soisdisconnected(tp->t_inpcb->inp_socket);
I 75
	return (tp);
E 75
E 52
D 43
printf("after usrclosed state %s\n", tcpstates[tp->t_state]);
E 43
E 42
E 29
E 4
D 37
}

I 28
D 29
tcp_sense()
{

}

E 28
D 4
cls_rwt(wp)             /* rcv request after foreign close (20) */
struct work *wp;
{
E 4
I 4
D 19
t_open(tp, mode)                /* set up a tcb for a connection */
E 19
I 19
D 22
tcp_open(tp, mode)                /* set up a tcb for a connection */
E 22
I 22
/*
 * Open routine, called to initialize newly created tcb fields.
 */
D 28
tcp_open(tp, mode)
E 22
E 19
E 4
	register struct tcb *tp;
I 4
	int mode;
E 28
I 28
struct tcb *
E 29
D 33
tcp_attach(so)
D 31
	register struct socket *so;
E 31
I 31
	struct socket *so;
E 33
I 33
struct tcpcb *
D 35
tcp_newtcpcb()
E 35
I 35
tcp_newtcpcb(inp)
	struct inpcb *inp;
E 35
E 33
E 31
E 28
{
D 22
	register struct ucb *up;
COUNT(T_OPEN);
E 22
I 22
D 28
	register struct ucb *up = tp->t_ucb;
COUNT(TCP_OPEN);
E 28
I 28
D 29
	register struct tcb *tp;
E 29
I 29
D 31
	register struct tcpcb *tp;
E 31
I 31
D 33
	register struct tcpcb *tp = sototcpcb(so);
E 31
E 29
COUNT(TCP_ATTACH);
E 33
I 33
	struct mbuf *m = m_getclr(0);
	register struct tcpcb *tp;
COUNT(TCP_NEWTCPCB);
E 33
E 28
E 22
E 4

I 33
	if (m == 0)
		return (0);
	tp = mtod(m, struct tcpcb *);

E 33
D 4
COUNT(CLS_RWT);
	tp = wp->w_tcb;
E 4
I 4
D 22
	/* enqueue the tcb */
E 22
I 22
	/*
D 29
	 * Link in tcb queue and make
	 * initialize empty reassembly queue.
E 29
I 29
	 * Make empty reassembly queue.
E 29
	 */
D 28
	tp->tcb_next = tcb.tcb_next;
	tcb.tcb_next->tcb_prev = tp;
	tp->tcb_prev = (struct tcb *)&tcb;
E 28
I 28
D 29
	tp->tcb_hd.tcb_next = tcb.tcb_next;
	tcb.tcb_next->tcb_hd.tcb_prev = tp;
	tp->tcb_hd.tcb_prev = (struct tcb *)&tcb;
E 28
	tcb.tcb_next = tp;
D 28
	tp->t_rcv_next = tp->t_rcv_prev = (struct th *)tp;
E 28
I 28
	tp->tcb_hd.seg_next = tp->tcb_hd.seg_prev = (struct th *)tp;
E 29
I 29
	tp->seg_next = tp->seg_prev = (struct tcpiphdr *)tp;
E 29
E 28
E 22
E 4

D 4
	present_data(tp);       /* present any remaining data */
E 4
I 4
D 16
	if (netcb.n_tcb_head == NULL) {
		netcb.n_tcb_head = tp;
		netcb.n_tcb_tail = tp;
E 16
I 16
D 22
	if (tcb_head == NULL) {
		tcb_head = tp;
		tcb_tail = tp;
E 16
	} else {
D 16
		tp->t_tcb_next = netcb.n_tcb_head;
		netcb.n_tcb_head->t_tcb_prev = tp;
		netcb.n_tcb_head = tp;
E 16
I 16
		tp->t_tcb_next = tcb_head;
		tcb_head->t_tcb_prev = tp;
		tcb_head = tp;
E 16
	}
E 4

D 4
	if (rcv_empty(tp)) {
        	t_close(tp, UCLOSED);
         	return(CLOSED);
	} else
		return(RCV_WAIT);
E 4
I 4
	/* initialize non-zero tcb fields */
E 4

I 4
	tp->t_rcv_next = (struct th *)tp;
	tp->t_rcv_prev = (struct th *)tp;
E 22
I 22
	/*
D 29
	 * Initialize sequence numbers and
	 * round trip retransmit timer.
	 * (Other fields were init'd to zero when tcb allocated.)
E 29
I 29
	 * Initialize sequence numbers and round trip retransmit timer.
E 29
	 */
E 22
	tp->t_xmtime = T_REXMT;
D 22
	tp->snd_end = tp->seq_fin = tp->snd_nxt = tp->snd_hi =
D 16
	              tp->snd_una = tp->iss = netcb.n_iss;
E 16
I 16
	              tp->snd_una = tp->iss = tcp_iss;
E 22
I 22
	tp->snd_end = tp->seq_fin = tp->snd_nxt = tp->snd_hi = tp->snd_una =
	    tp->iss = tcp_iss;
E 22
E 16
	tp->snd_off = tp->iss + 1;
D 16
	netcb.n_iss += (ISSINCR >> 1) + 1;
E 16
I 16
	tcp_iss += (ISSINCR >> 1) + 1;
I 35

	/*
	 * Hook to inpcb.
	 */
	tp->t_inpcb = inp;
	inp->inp_ppcb = (caddr_t)tp;
E 35
I 33
	return (tp);
E 33
E 16
D 28

D 22
	/* set timeout for open */

	up = tp->t_ucb;
	tp->t_init = (up->uc_timeo != 0 ? up->uc_timeo :
					(mode == ACTIVE ? T_INIT : 0));
	up->uc_timeo = 0;       /* overlays uc_ssize */
E 22
I 22
	/*
	 * Set timeout for open.
	 * SHOULD THIS BE A HIGHER LEVEL FUNCTION!?! THINK SO.
	 */
	if (up->uc_timeo)
		tp->t_init = up->uc_timeo;
	else if (mode == ACTIVE)
		tp->t_init = T_INIT;
	/* else
		tp->t_init = 0; */
	up->uc_timeo = 0;				/* ### */
E 28
E 22
E 4
}

I 22
D 29
/*
D 28
 * Internal close of a connection, shutting down the tcb.
E 28
I 28
 * Destroy a tcb.
E 28
 */
E 22
D 4
fw1_syr(wp)             /* close request on synced connection (24,25) */
struct work *wp;
{
E 4
I 4
D 19
t_close(tp, state)
E 19
I 19
D 28
tcp_close(tp, state)
E 28
I 28
tcp_detach(tp)
E 28
E 19
E 4
	register struct tcb *tp;
E 29
I 29
D 31
tcp_detach(so)
	register struct socket *so;
E 31
I 31
D 35
tcp_detach(tp)
	struct tcpcb *tp;
E 31
E 29
I 4
D 28
	short state;
E 28
{
D 22
	register struct ucb *up;
E 22
I 22
D 28
	register struct ucb *up = tp->t_ucb;
E 28
I 28
D 29
	register struct socket *so = tp->t_socket;
E 28
E 22
	register struct th *t;
E 29
I 29
D 31
	register struct tcpcb *tp = (struct tcpcb *)so->so_pcb;
	register struct tcpiphdr *t;
E 29
	register struct mbuf *m;
E 31
D 7
	register struct work *w;
E 7
D 22
COUNT(T_CLOSE);
E 22
I 22
D 28
COUNT(TCP_CLOSE);
E 28
I 28
COUNT(TCP_DETACH);
E 28
E 22
E 4

D 4
COUNT(FW1_SYR);
	tp = wp->w_tcb;
E 4
I 4
D 22
	up = tp->t_ucb;
E 4

E 22
I 22
D 29
	/*
D 26
	 * Cancel all timers.
	 * SHOULD LOOP HERE !?!
E 26
I 26
	 * Remove from tcb queue and cancel timers.
E 26
	 */
E 22
D 4
	tp->snd_fin = TRUE;                     /* send FIN */
	send_ctl(tp);
	tp->usr_closed = TRUE;
E 4
I 4
D 26
	tp->t_init = tp->t_rexmt = tp->t_rexmttl = tp->t_persist = 
	    tp->t_finack = 0;
E 4

D 4
	return(FIN_W1);
E 4
I 4
D 22
	/* delete tcb */
E 22
I 22
	/*
	 * Remque the tcb
	 */
E 26
D 28
	tp->tcb_prev->tcb_next = tp->tcb_next;
	tp->tcb_next->tcb_prev = tp->tcb_prev;
E 28
I 28
	tp->tcb_hd.tcb_prev->tcb_hd.tcb_next = tp->tcb_hd.tcb_next;
	tp->tcb_hd.tcb_next->tcb_hd.tcb_prev = tp->tcb_hd.tcb_prev;
E 28
I 26
	tcp_tcancel(tp);
E 29
I 29
D 31
	wmemfree((caddr_t)tp, 1024);
	m_release(so->so_rcv.sb_hiwat + so->so_snd.sb_hiwat + 2 * MSIZE);
E 31
I 31
	in_pcbfree(tp->t_inpcb);
	(void) m_free(dtom(tp));
E 31
}
E 29
E 26
E 22

E 35
D 22
	if (tp->t_tcb_prev == NULL)
D 16
		netcb.n_tcb_head = tp->t_tcb_next;
E 16
I 16
		tcb_head = tp->t_tcb_next;
E 16
	else
		tp->t_tcb_prev->t_tcb_next = tp->t_tcb_next;
	if (tp->t_tcb_next == NULL)
D 16
		netcb.n_tcb_tail = tp->t_tcb_prev;
E 16
I 16
		tcb_tail = tp->t_tcb_prev;
E 16
	else
		tp->t_tcb_next->t_tcb_prev = tp->t_tcb_prev;

	/* free all data on receive and send buffers */

E 22
I 22
D 29
	/*
D 26
	 * Discard all buffers...
	 *
	 * SHOULD COUNT EACH RESOURCE TO 0 AND PANIC IF CONFUSED
E 26
I 26
	 * Discard all buffers.
E 26
	 */
E 22
D 28
	for (t = tp->t_rcv_next; t != (struct th *)tp; t = t->t_next)
E 28
I 28
	for (t = tp->tcb_hd.seg_next; t != (struct th *)tp; t = t->t_next)
E 28
		m_freem(dtom(t));
D 22

E 22
D 26
	if (up->uc_rbuf != NULL) {
E 26
I 26
D 28
	if (up->uc_rbuf) {
E 26
		m_freem(up->uc_rbuf);
		up->uc_rbuf = NULL;
	}
I 10
D 15
	up->uc_rsize = 0;
E 15
I 15
	up->uc_rcc = 0;
E 15
E 10
D 26
	if (up->uc_sbuf != NULL) {
E 26
I 26
	if (up->uc_sbuf) {
E 26
		m_freem(up->uc_sbuf);
		up->uc_sbuf = NULL;
	}
I 10
	up->uc_ssize = 0;
E 10
	for (m = tp->t_rcv_unack; m != NULL; m = m->m_act) {
E 28
I 28
	if (so->so_rcv.sb_mb)
	    { m_freem(so->so_rcv.sb_mb); so->so_rcv.sb_mb = 0; }
	so->so_rcv.sb_cc = 0; so->so_rcv.sb_mbcnt = 0;
	if (so->so_snd.sb_mb)
	    { m_freem(so->so_snd.sb_mb); so->so_rcv.sb_mb = 0; }
	so->so_snd.sb_cc = 0; so->so_snd.sb_mbcnt = 0;
E 29
I 29
tcp_disconnect(tp)
	register struct tcpcb *tp;
{
	register struct tcpiphdr *t;
D 31
	register struct mbuf *m;
	register struct socket *so;
E 31
E 29

I 33
COUNT(TCP_DISCONNECT);
E 33
D 29
	for (m = tp->seg_unack; m; m = m->m_act)
E 28
		m_freem(m);
D 28
		tp->t_rcv_unack = NULL;
E 28
I 28
	tp->seg_unack = 0;

	/*
	 * Free routing table entry.
	 */
	if (tp->t_host) {
		h_free(tp->t_host);
		tp->t_host = 0;
E 28
	}
I 22

	/*
D 26
	 * Free tcp send template.
E 26
I 26
	 * Free tcp send template, the tcb itself,
D 28
	 * the routing table entry, and the space we had reserved
	 * in the meory pool.
E 28
I 28
	 * and the space we had reserved in the meory pool.
E 28
E 26
	 */
E 29
I 29
	tcp_tcancel(tp);
	t = tp->seg_next;
D 30
	for (; t != (struct tcpiphdr *)tp; t = t->t_next)
E 30
I 30
	for (; t != (struct tcpiphdr *)tp; t = (struct tcpiphdr *)t->ti_next)
E 30
		m_freem(dtom(t));
	tcp_drainunack(tp);
E 29
E 22
I 16
D 26
	if (up->uc_template) {
		m_free(dtom(up->uc_template));
		up->uc_template = 0;
E 26
I 26
	if (tp->t_template) {
D 31
		m_free(dtom(tp->t_template));
E 31
I 31
		(void) m_free(dtom(tp->t_template));
E 31
		tp->t_template = 0;
E 26
	}
I 22
D 26

	/*
	 * Free the tcb
	 * WOULD THIS BETTER BE DONE AT USER CLOSE?
	 */
E 26
E 22
E 16
D 8
	m_free(dtom(tp));
E 8
I 8
D 17
	m = dtom(tp);
	m->m_off = 0;
	m_free(m);
E 17
I 17
D 29
	wmemfree((caddr_t)tp, 1024);
E 17
E 8
D 26
	up->uc_tcb = NULL;

D 22
	/* lower buffer allocation and decrement host entry */

E 22
I 22
	/*
	 * Lower buffer allocation.
	 * SHOULD BE A M_ROUTINE CALL.
	 */
E 22
D 15
	netcb.n_lowat -= up->uc_snd + up->uc_rcv + 2;
E 15
I 15
D 16
	netcb.n_lowat -= up->uc_snd + (up->uc_rhiwat/MSIZE) + 2;
E 15
	netcb.n_hiwat = 2 * netcb.n_lowat;
E 16
I 16
	mbstat.m_lowat -= up->uc_snd + (up->uc_rhiwat/MSIZE) + 2;
	mbstat.m_hiwat = 2 * mbstat.m_lowat;
I 22

	/*
	 * Free routing table entry.
	 */
E 22
E 16
	if (up->uc_host != NULL) {
E 26
I 26
D 28
	up->uc_pcb = 0;
	if (up->uc_host) {
E 26
		h_free(up->uc_host);
D 26
		up->uc_host = NULL;
E 26
I 26
		up->uc_host = 0;
E 26
	}
I 26
	m_release(up->uc_snd + (up->uc_rhiwat/MSIZE) + 2);
E 26

D 22
	/* if user has initiated close (via close call), delete ucb
	   entry, otherwise just wakeup so user can issue close call */

E 22
I 22
	/*
	 * If user has initiated close (via close call), delete ucb
	 * entry, otherwise just wakeup so user can issue close call
	 */
E 22
D 6
	if (tp->usr_abort)
E 6
I 6
D 26
	if (tp->tc_flags&TC_USR_ABORT)
E 6
        	up->uc_proc = NULL;
	else
E 26
I 26
	if (tp->tc_flags&TC_USR_ABORT)			/* ### */
        	up->uc_proc = NULL;			/* ### */
	else						/* ### */
E 26
D 22
        	to_user(up, state);
E 22
I 22
        	to_user(up, state);			/* ### */
E 28
I 28
	m_release(so->so_rcv.sb_hiwat + so->so_snd.sb_hiwat + 2 * MSIZE);
E 29
I 29
	in_pcbfree(tp->t_inpcb);
I 35
	(void) m_free(dtom(tp));
E 35
E 29
E 28
E 22
D 7

E 7
E 4
}

I 29
D 31
tcp_abort(so)
	register struct socket *so;
E 31
I 31
tcp_abort(tp)
	register struct tcpcb *tp;
E 31
{
D 31
	register struct tcpcb *tp = sototcpcb(so);
E 31

I 33
COUNT(TCP_ABORT);
E 33
	switch (tp->t_state) {

	case SYN_RCVD:
	case ESTAB:
	case FIN_W1:
	case FIN_W2:
	case CLOSE_WAIT:
		tp->tc_flags |= TC_SND_RST;
		tcp_sndnull(tp);
	}
D 31
	if (so)
		soisdisconnected(so);
E 31
I 31
	soisdisconnected(tp->t_inpcb->inp_socket);
I 35
	tcp_disconnect(tp);
E 35
E 31
}

E 29
I 22
/*
I 31
D 32
/*###366 [cc] warning: struct/union or struct/union pointer required %%%*/
/*###366 [cc] member of structure or union required %%%*/
/*###366 [cc] tp_inpcb undefined %%%*/
E 32
E 31
D 26
 * User routine to send data queue headed by m0 into the protocol.
E 26
I 26
 * Send data queue headed by m0 into the protocol.
E 26
 */
E 22
D 3
sss_syn(wp)             /* incoming seq on open connection (39) */
struct work *wp;
{
	register struct tcb *tp;

COUNT(SSS_SYN);
	tp = wp->w_tcb;

	rcv_data(tp, wp->w_dat);
	present_data(tp);

	return(SAME);
}

E 3
D 4
sss_snd(wp)             /* send request on open connection (40,41) */
struct work *wp;
E 4
I 4
D 7
sss_snd(wp)
	struct work *wp;
E 4
{
E 7
I 7
D 11
sss_snd(tp, m0)
E 11
I 11
D 20
sss_send(tp, m0)
E 20
I 20
tcp_usrsend(tp, m0)
E 20
E 11
E 7
D 29
	register struct tcb *tp;
E 29
I 29
	register struct tcpcb *tp;
E 29
I 7
	struct mbuf *m0;
{
E 7
D 31
	register struct mbuf *m, *n;
E 31
D 7
	register struct ucb *up;
E 7
I 7
D 28
	register struct ucb *up = tp->t_ucb;
E 28
I 28
D 29
	register struct socket *so = tp->t_socket;
E 29
I 29
	register struct socket *so = tp->t_inpcb->inp_socket;
E 29
E 28
E 7
D 31
	register off;
D 5
	sequence last;
E 5
I 5
	seq_t last;
E 31
I 11
D 22
COUNT(SSS_SEND);
E 22
I 22
COUNT(TCP_USRSEND);
E 22
E 11
E 5

D 4
COUNT(SSS_SND);
E 4
D 7
	tp = wp->w_tcb;
	up = tp->t_ucb;

E 7
D 29
	last = tp->snd_off;
D 8

	/* count number of mbufs in send data */

E 8
D 7
	for (m = n = (struct mbuf *)wp->w_dat; m != NULL; m = m->m_next) {
E 7
I 7
	for (m = n = m0; m != NULL; m = m->m_next) {
E 7
D 28
		up->uc_ssize++;
E 28
I 28
		so->so_snd.sb_mbcnt++;
E 28
I 8
D 9
		if (m->m_off > MSIZE)
E 9
I 9
		if (m->m_off > MMAXOFF)
E 9
D 28
			up->uc_ssize += NMBPG;
E 28
I 28
			so->so_snd.sb_mbcnt += NMBPG;
E 28
E 8
		last += m->m_len;
	}
D 8

	/* find end of send buffer and append data */

D 4
	if ((m = up->uc_sbuf) != NULL) {        /* something in send buffer */
		while (m->m_next != NULL) {             /* find the end */
E 4
I 4
	if ((m = up->uc_sbuf) != NULL) {		/* something in send buffer */
		while (m->m_next != NULL) {		/* find the end */
E 8
I 8
D 28
	if ((m = up->uc_sbuf) == NULL)
		up->uc_sbuf = n;
E 28
I 28
	if ((m = so->so_snd.sb_mb) == NULL)
		so->so_snd.sb_mb = n;
E 28
	else {
		while (m->m_next != NULL) {
E 8
E 4
			m = m->m_next;
			last += m->m_len;
		}
D 8
		last += m->m_len;

		/* if there's room in old buffer for new data, consolidate */

		off = m->m_off + m->m_len;
		while (n != NULL && (MSIZE - off) >= n->m_len) {
D 4
			bcopy((caddr_t)((int)n + n->m_off), 
E 4
I 4
			bcopy((caddr_t)((int)n + n->m_off),
E 4
			      (caddr_t)((int)m + off), n->m_len);
			m->m_len += n->m_len;
			off += n->m_len;
			up->uc_ssize--;
			n = m_free(n);
E 8
I 8
D 9
		if (m->m_off <= MSIZE) {
E 9
I 9
		if (m->m_off <= MMAXOFF) {
E 9
			last += m->m_len;
			off = m->m_off + m->m_len;
D 9
			while (n && n->m_off <= MSIZE &&
			    (MSIZE - off) >= n->m_len) {
E 9
I 9
			while (n && n->m_off <= MMAXOFF &&
			    (MMAXOFF - off) >= n->m_len) {
E 9
				bcopy((caddr_t)((int)n + n->m_off),
				      (caddr_t)((int)m + off), n->m_len);
				m->m_len += n->m_len;
				off += n->m_len;
D 28
				up->uc_ssize--;
E 28
I 28
				so->so_snd.sb_mbcnt--;
E 28
				n = m_free(n);
			}
E 8
		}
		m->m_next = n;
D 8

D 4
	} else                                  /* nothing in send buffer */
E 4
I 4
	} else		/* nothing in send buffer */
E 4
		up->uc_sbuf = n;

D 4
	if (up->uc_flags & UEOL) {               /* set EOL */
E 4
I 4
	if (up->uc_flags & UEOL) {		/* set EOL */
E 4
		tp->snd_end = last;
E 8
	}
E 29
I 29
	sbappend(&so->so_snd, m0);
E 29
D 8

D 4
	if (up->uc_flags & UURG) {              /* urgent data */
E 4
I 4
	if (up->uc_flags & UURG) {		/* urgent data */
E 8
I 8
D 28
	if (up->uc_flags & UEOL)
E 28
I 28
	if (tp->t_options & TO_EOL)
E 28
D 29
		tp->snd_end = last;
E 29
I 29
		tp->snd_end = tp->snd_off + so->so_snd.sb_cc;
E 29
D 28
	if (up->uc_flags & UURG) {
E 28
I 28
	if (tp->t_options & TO_URG) {
E 28
E 8
E 4
D 29
		tp->snd_urp = last+1;
E 29
I 29
		tp->snd_urp = tp->snd_off + so->so_snd.sb_cc + 1;
E 29
D 4
		tp->snd_urg = TRUE;
	} 
E 4
I 4
D 6
		tp->snd_urg = 1;
E 6
I 6
		tp->tc_flags |= TC_SND_URG;
E 6
	}
E 4
D 8

E 8
D 20
	send(tp);
E 20
I 20
D 31
	tcp_send(tp);
E 31
I 31
	(void) tcp_send(tp);
E 31
E 20
D 8

E 8
D 4
	return(SAME);
E 4
I 4
D 29
	return (SAME);
E 29
E 4
}

I 22
D 36
/*
 * TCP timer went off processing.
 */
E 22
D 4
sss_rcv(wp)             /* rcv request on open connection (42) */
struct work *wp;
E 4
I 4
D 7
tcp_timers(wp)
	struct work *wp;
E 7
I 7
tcp_timers(tp, timertype)
D 29
	register struct tcb *tp;
E 29
I 29
	register struct tcpcb *tp;
E 29
	int timertype;
E 7
E 4
{
D 4
	register struct tcb *tp;
E 4
I 4
D 7
	register struct tcb *tp = wp->w_tcb;
	register type = wp->w_stype;
E 7
E 4

D 4
COUNT(SSS_RCV);
	tp = wp->w_tcb;
E 4
I 4
COUNT(TCP_TIMERS);
D 7
	switch (type) {
E 7
I 7
	switch (timertype) {
E 7
E 4

D 4
	send_ctl(tp);                   /* send new window */
	present_data(tp);
E 4
I 4
D 29
	case TINIT:		/* initialization timer */
D 6
		if (!tp->syn_acked) {				/* 35 */
E 6
I 6
		if ((tp->tc_flags&TC_SYN_ACKED) == 0) {		/* 35 */
E 6
D 19
			t_close(tp, UINTIMO);
E 19
I 19
D 28
			tcp_close(tp, UINTIMO);
E 28
I 28
/* XXX */		/* tcp_close(tp, UINTIMO); */
E 28
E 19
			return (CLOSED);
		}
		return (SAME);
E 4

E 29
D 4
	return(SAME);
}
E 4
I 4
	case TFINACK:		/* fin-ack timer */
		switch (tp->t_state) {
E 4

D 4
cls_nsy(wp)                  /* abort request on unsynced connection (44) */
struct work *wp;
{
E 4
I 4
		case TIME_WAIT:
			/*
			 * We can be sure our ACK of foreign FIN was rcvd,
			 * and can close if no data left for user.
			 */
			if (rcv_empty(tp)) {
D 19
				t_close(tp, UCLOSED);		/* 14 */
E 19
I 19
D 28
				tcp_close(tp, UCLOSED);		/* 14 */
E 28
I 28
D 29
/* XXX */			/* tcp_close(tp, UCLOSED); */	/* 14 */
E 29
I 29
				tcp_disconnect(tp);
E 29
E 28
E 19
				return (CLOSED);
			}
			return (RCV_WAIT);			/* 17 */
E 4

D 4
COUNT(CLS_NSY);
	t_close(wp->w_tcb, UABORT);
E 4
I 4
D 25
		case CLOSING1:
E 25
I 25
		case CLOSING:
E 25
D 6
			tp->waited_2_ml = 1;
E 6
I 6
			tp->tc_flags |= TC_WAITED_2_ML;
E 6
			return (SAME);
E 4

D 4
	return(CLOSED);
}
E 4
I 4
		default:
			return (SAME);
		}
E 4

D 4
cls_syn(wp)             /* abort request on synced connection (45) */
struct work *wp;
{
	register struct tcb *tp;
E 4
I 4
	case TREXMT:		/* retransmission timer */
		if (tp->t_rexmt_val > tp->snd_una) {	 	/* 34 */
			/*
D 28
			 * Set up for a retransmission, increase rexmt time
E 28
I 28
			 * Set so for a retransmission, increase rexmt time
E 28
			 * in case of multiple retransmissions.
			 */
			tp->snd_nxt = tp->snd_una;
D 6
			tp->rexmt = 1;
E 6
I 6
			tp->tc_flags |= TC_REXMT;
E 6
			tp->t_xmtime = tp->t_xmtime << 1;
			if (tp->t_xmtime > T_REMAX)
				tp->t_xmtime = T_REMAX;
D 20
			send(tp);
E 20
I 20
D 31
			tcp_send(tp);
E 31
I 31
			(void) tcp_send(tp);
E 31
E 20
		}
		return (SAME);
E 4

D 4
COUNT(CLS_SYN);
	tp = wp->w_tcb;
E 4
I 4
	case TREXMTTL:		/* retransmit too long */
D 35
		if (tp->t_rtl_val > tp->snd_una)		/* 36 */
D 28
			to_user(tp->t_ucb, URXTIMO);
E 28
I 28
D 29
/* XXX */		/* to_user(tp->t_socket, URXTIMO); */;
E 29
I 29
D 31
			tcp_error(EIO);		/* URXTIMO !?! */
E 31
I 31
			tcp_error(tp, EIO);		/* URXTIMO !?! */
E 31
E 29
E 28
		/*
		 * If user has already closed, abort the connection.
		 */
D 6
		if (tp->usr_closed) {
E 6
I 6
		if (tp->tc_flags & TC_USR_CLOSED) {
E 6
D 19
			t_close(tp, URXTIMO);
E 19
I 19
D 28
			tcp_close(tp, URXTIMO);
E 28
I 28
D 29
/* XXX */		/* tcp_close(tp, URXTIMO); */
E 29
I 29
			tcp_abort(tp);
E 35
I 35
		if (tp->t_rtl_val > tp->snd_una) {		/* 36 */
			tcp_error(tp, ETIMEDOUT);
E 35
E 29
E 28
E 19
			return (CLOSED);
		}
		return (SAME);
E 4

D 4
	tp->snd_rst = TRUE;            /* send reset */
	send_null(tp);
	t_close(tp, UABORT);

	return(CLOSED);
E 4
I 4
	case TPERSIST:		/* persist timer */
		/*
		 * Force a byte send through closed window.
		 */
D 6
		tp->force_one = 1;				/* 38 */
E 6
I 6
		tp->tc_flags |= TC_FORCE_ONE;
E 6
D 20
		send(tp);
E 20
I 20
D 31
		tcp_send(tp);
E 31
I 31
		(void) tcp_send(tp);
E 31
E 20
		return (SAME);
	}
	panic("tcp_timers");
I 31
	/*NOTREACHED*/
E 31
E 4
}

E 36
I 31
/*ARGSUSED*/
E 31
I 29
tcp_sense(m)
	struct mbuf *m;
{

I 33
COUNT(TCP_SENSE);
E 33
	return (EOPNOTSUPP);
}

E 29
D 4
cls_act(wp)             /* net closing open connection (47) */
struct work *wp;
E 4
I 4
D 7
tcp_debug(tp, wp, input, newstate)   /* write a debugging record */
	register struct tcb *tp;
	register struct work *wp;
	int input, newstate;
E 4
{
I 4
	struct t_debug debuf;
	register struct th *n;
	register off_t siz;
COUNT(TCP_DEBUG);
E 4

D 4
COUNT(CLS_ACT);
	t_close(wp->w_tcb, UNETDWN);
E 4
I 4
	/* look for debugging file inode */
E 4

D 4
	return(CLOSED);
E 4
I 4
	if (netcb.n_debug == 0)
		return;
	debuf.t_tod = time;
	if ((debuf.t_tcb = tp) != NULL)
		debuf.t_old = tp->t_state;
	else
		debuf.t_old = 0;
	debuf.t_inp = input;
	debuf.t_tim = wp->w_stype;
	debuf.t_new = newstate;
	if (input == INRECV) {
		n = (struct th *)wp->w_dat;
		debuf.t_sno = n->t_seq;
		debuf.t_ano = n->t_ackno;
		debuf.t_wno = n->t_win;
		if (debuf.t_new == -1)
			debuf.t_lno = ((struct ip *)n)->ip_len;
		else
			debuf.t_lno = n->t_len;
		debuf.t_flg = *(char *)((int)&n->t_win - 1);
	}
	/* STUFF INTO CIRC BUFFER */
E 4
}

D 4
cls_err(wp)             /* invalid user request in closing states */
struct work *wp;
E 4
I 4
#ifdef TCPDEBUG

tcp_prt(tp, input, timer, newstate)     /* print debugging info on the console */
register struct tcb *tp;
register input, timer, newstate;
E 4
{
D 4
COUNT(CLS_ERR);
	to_user(wp->w_tcb->t_ucb, UCLSERR);
E 4
I 4
	register oldstate;
COUNT(TCP_PRT);
E 4
D 3

	return(SAME);
}

lis_netr(wp)             /* incoming seg in LISTEN (3,4) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(LIS_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	if (!syn_ok(tp, n))             /* must have good SYN */
		return(EFAILEC);

	/* fill in unspecified foreign host address.  get/create entry
	   in foreign host table.  if none available, ignore.  probably
	   should send reset here. */

	if ((tp->t_ucb->uc_host = h_make(&n->t_s)) == NULL)
		return(EFAILEC);

	tp->t_fport = n->t_src;

	rcv_data(tp, n);

	if (!tp->fin_rcvd) {            /* no FIN (4) */

		/* start init timer now that we have foreign host */

		tp->t_init = T_INIT/2;
		return(L_SYN_RCVD);

	} else {                        /* got a FIN, start timer (3) */
        	tp->t_finack = T_2ML;
        	tp->waited_2_ml = FALSE;
		return(CLOSE_WAIT);
	}
}

sys_netr(wp)            /* incoming segment after SYN sent (8,9,11,32) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(SYS_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	if (!syn_ok(tp, n))             /* must have good SYN */
		return(EFAILEC);

	rcv_data(tp, n);

	if (tp->fin_rcvd) {             /* got a FIN */

		/* if good ACK, present any data */

		if (n->t_ack) {

			if (n->t_ackno > tp->iss)       /* 32 */
				present_data(tp);

		} else {                                /* 9 */
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;
		}
		return (CLOSE_WAIT);

	} else                          /* no FIN */

		/* if good ACK, open connection, otherwise wait for one */

		if (n->t_ack) {                         /* 11 */
			present_data(tp);
			return(ESTAB);
		} else
			return(SYN_RCVD);               /* 8 */
}

cl1_netr(wp)            /* incoming seg after we closed (15,18,22,23,30,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(CL1_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	if (ack_fin(tp, n))                     /* got ACK of our FIN */

        	if (n->t_fin) {                 /* got for FIN (23) */
        
        		rcv_ctl(tp, n);
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;
                        return(TIME_WAIT);
        	} else {

			/* if wait done, see if any data left for user */

        		if (tp->waited_2_ml)
        
        			if (rcv_empty(tp)) {    /* 15 */
        
        				t_close(tp, UCLOSED);
        				return(CLOSED);
        			} else
        				return(RCV_WAIT);       /* 18 */
        
        		else
        			return(TIME_WAIT);      /* 22 */
		}

	else                            /* our FIN not ACKed yet */

		if (n->t_fin) {                 /* rcvd for FIN (30) */

			rcv_ctl(tp, n);
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;

		} else {                        /* no FIN, just proc new data (39) */

        		rcv_data(tp, n);
        		present_data(tp);
		}

	return(SAME);
}

cl2_netr(wp)            /* incoming seg after foreign close (16,19,31,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(CL2_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	if (ack_fin(tp, n)) {                   /* this is ACK of our fin */

		/* if no data left for user, close; otherwise wait */

		if (rcv_empty(tp)) {                            /* 16 */
			 
			t_close(tp, UCLOSED);
			return(CLOSED);
		} else                                          /* 19 */
			return(RCV_WAIT);

	} else                                  /* no ACK of our FIN */

		/* duplicate FIN or data */

		if (n->t_fin)                                   /* 31 */
			send_ctl(tp);           /* ACK duplicate FIN */

		else {                                          /* 39 */
			rcv_data(tp, n);                         
			present_data(tp);
		}

	return(SAME);
}

fw1_netr(wp)            /* incoming seg after user close (26,27,28,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(FW1_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	/* process any incoming data, since we closed but they didn't */

	rcv_data(tp, n);
	present_data(tp);

	if (ack_fin(tp, n))                     /* our FIN got ACKed */

		if (tp->fin_rcvd) {                     /* got for FIN (28) */
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;
			return(TIME_WAIT);
		} else                                  /* no FIN, wait (27) */
			return(FIN_W2);

	else                                    /* no ACK of FIN */

		if (tp->fin_rcvd) {                     /* got for FIN (26) */
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;
			return(CLOSING1);
                } 

	return(SAME);                                   /* 39 */
}

syr_netr(wp)             /* incoming seg after SYN rcvd (5,33) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(SYR_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	if (!n->t_ack || (n->t_ack && n->t_ackno <= tp->iss))  /* must have ACK of our SYN */
		return(EFAILEC);

	rcv_data(tp, n);
	present_data(tp);

	/* if no FIN, open connection, otherwise wait for user close */

	if (tp->fin_rcvd)                               /* 33 */
		return(CLOSE_WAIT);
	else                                            /* 5 */
		return(ESTAB);

}

est_netr(wp)            /* incoming seg on open connection (12,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(EST_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	rcv_data(tp, n);
	present_data(tp);

	/* if no FIN, remain open, otherwise wait for user close */

	if (tp->fin_rcvd)                       /* 12 */
		return(CLOSE_WAIT);
	else                                    /* 39 */
        	return(SAME);
}

fw2_netr(wp)            /* incoming seg while waiting for for FIN (12,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(FW2_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	/* process data since we closed, but they may not have */

	rcv_data(tp, n);
	present_data(tp);

	/* if we get the FIN, start the finack timer, else keep waiting */

	if (tp->fin_rcvd) {                     /* got for FIN (29) */
		tp->t_finack = T_2ML;
		tp->waited_2_ml = FALSE;
		return(TIME_WAIT);
	} else                                  /* 39 */
        	return(SAME);
}

cwt_netr(wp)            /* incoming seg after exchange of FINs (30,31,39) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(CWT_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	/* either duplicate FIN or data */

	if (n->t_fin) {

		if (n->t_ack && n->t_ackno <= tp->seq_fin) {    /* dup ACK (30) */

                	rcv_ctl(tp, n);
                	tp->t_finack = T_2ML;
                	tp->waited_2_ml = FALSE;
		} else                                          /* 31 */
			send_ctl(tp);

	} else {                /* duplicate data (39) */

		rcv_data(tp, n);
		present_data(tp);
	}

	return(SAME);
}

rwt_netr(wp)            /* incoming seg while waiting for user rcv (30,21) */
struct work *wp;
{
	register struct tcb *tp;
	register struct th *n;

COUNT(RWT_NETR);
	tp = wp->w_tcb;
	n = (struct th *)wp->w_dat;

	/* handle duplicate ACK of our FIN */

	if (n->t_fin && n->t_ack && n->t_ackno <= tp->seq_fin) {    /* 30 */

        	rcv_ctl(tp, n);
        	tp->t_finack = T_2ML;
        	tp->waited_2_ml = FALSE;
	} 
E 3

D 4
	return(SAME);
E 4
I 4
	oldstate = tp->t_state;
	printf("TCP(%X) %s X %s", tp, tcpstates[oldstate], tcpinputs[input]);
	if (input == ISTIMER)
		printf("(%s)", tcptimers[timer]);
	printf(" --> %s", tcpstates[ (newstate > 0) ? newstate : oldstate ]);
	if (newstate < 0)
		printf(" (FAILED)\n");
	else
		putchar('\n');
E 4
}
I 4
#endif
E 4

E 7
D 4
timers(wp)              /* timer processor (14,17,34,35,36,37,38) */
struct work *wp;
E 4
I 4
D 28
/* THIS ROUTINE IS A CROCK */
to_user(up, state)
	register struct ucb *up;
	register short state;
E 28
I 28
D 31
tcp_error(so, errno)
	struct socket *so;
E 31
I 31
D 35
tcp_error(tp, errno)
E 35
I 35
tcp_drop(tp, errno)
E 35
	struct tcpcb *tp;
E 31
	int errno;
E 28
E 4
{
D 4
	register struct tcb *tp;
	register type;
E 4
I 4
D 31
COUNT(TO_USER);
E 31
I 31
	struct socket *so = tp->t_inpcb->inp_socket;
D 33
COUNT(TCP_ERROR);
E 33
E 31
E 4

I 33
COUNT(TCP_ERROR);
E 33
D 4
COUNT(TIMERS);
	tp = wp->w_tcb;
	type = wp->w_stype;

	switch (type) {

	case TINIT:             /* initialization timer */

		if (!tp->syn_acked) {           /* haven't got ACK of our SYN (35) */

			t_close(tp, UINTIMO);
			return(CLOSED);
		}
		break;

	case TFINACK:           /* fin-ack timer */   

		if (tp->t_state == TIME_WAIT) {

			/* can be sure our ACK of for FIN was rcvd,
			   can close if no data left for user */

			if (rcv_empty(tp)) {            /* 14 */
				t_close(tp, UCLOSED);
				return(CLOSED);
			} else                          /* 17 */
				return(RCV_WAIT);

		} else if (tp->t_state == CLOSING1)     /* 37 */

			/* safe to close */

			tp->waited_2_ml = TRUE;

	        break;

	case TREXMT:            /* retransmission timer */

		/* set up for a retransmission, increase rexmt time
		   in case of multiple retransmissions. */

	        if (tp->t_rexmt_val > tp->snd_una) {   /* 34 */
	        	tp->snd_nxt = tp->snd_una;
	        	tp->rexmt = TRUE;
			tp->t_xmtime = tp->t_xmtime << 1;                  
        		if (tp->t_xmtime > T_REMAX)
        			tp->t_xmtime = T_REMAX;
	        	send(tp);
	        }
		break;

	case TREXMTTL:          /* retransmit too long */

		/* tell user */

        	if (tp->t_rtl_val > tp->snd_una)        /* 36 */
        		to_user(tp->t_ucb, URXTIMO);

		/* if user has already closed, abort the connection */

		if (tp->usr_closed) {
			t_close(tp, URXTIMO);
			return(CLOSED);
		}
		break;

	case TPERSIST:          /* persist timer */

		/* force a byte send through closed window */

        	tp->force_one = TRUE;                   /* 38 */
        	send(tp);
		break;
	}

	return(SAME);
E 4
I 4
D 28
	up->uc_state |= state;
	netwakeup(up);
  	if (state == UURGENT)
		psignal(up->uc_proc, SIGURG);
E 28
I 28
	so->so_error = errno;
D 29
	sowakeup(so);
E 29
I 29
	sorwakeup(so);
	sowwakeup(so);
I 35
	tcp_disconnect(tp);
E 35
E 29
E 28
E 4
}
I 7

D 36
#ifdef TCPDEBUG
D 22
tcp_prt(tdp)
	register struct tcp_debug *tdp;
{
COUNT(TCP_PRT);

D 12
	printf("TCP(%X) %s X %s",
E 12
I 12
	printf("TCP(%x) %s x %s",
E 12
	    tdp->td_tcb, tcpstates[tdp->td_old], tcpinputs[tdp->td_inp]);
	if (tdp->td_inp == ISTIMER)
		printf("(%s)", tcptimers[tdp->td_tim]);
	printf(" --> %s",
	    tcpstates[(tdp->td_new > 0) ? tdp->td_new : tdp->td_old]);
	/* GROSS... DEPENDS ON SIGN EXTENSION OF CHARACTERS */
	if (tdp->td_new < 0)
		printf(" (FAILED)");
I 12
	if (tdp->td_sno) {
		printf(" sno %x ano %x win %d len %d flags %x",
		    tdp->td_sno, tdp->td_ano, tdp->td_wno, tdp->td_lno, tdp->td_flg);
	}
E 12
	printf("\n");
I 17
}
#endif
#ifdef TCPDEBUG
E 22
I 22
/*
 * TCP debugging utility subroutines.
 * THE NAMES OF THE FIELDS USED BY THESE ROUTINES ARE STUPID.
 */
E 22
tdb_setup(tp, n, input, tdp)
D 29
	struct tcb *tp;
	register struct th *n;
E 29
I 29
	struct tcpcb *tp;
	register struct tcpiphdr *n;
E 29
	int input;
	register struct tcp_debug *tdp;
E 36
I 36
tcp_drain()
E 36
{
I 36
	register struct inpcb *ip;
E 36

I 22
D 36
COUNT(TDB_SETUP);
E 22
	tdp->td_tod = time;
	tdp->td_tcb = tp;
	tdp->td_old = tp->t_state;
	tdp->td_inp = input;
	tdp->td_tim = 0;
	tdp->td_new = -1;
	if (n) {
D 30
		tdp->td_sno = n->t_seq;
		tdp->td_ano = n->t_ackno;
E 30
I 30
		tdp->td_sno = n->ti_seq;
		tdp->td_ano = n->ti_ackno;
E 30
		tdp->td_wno = n->t_win;
D 30
		tdp->td_lno = n->t_len;
		tdp->td_flg = n->th_flags;
E 30
I 30
		tdp->td_lno = n->ti_len;
		tdp->td_flg = n->ti_flags;
E 30
	} else
		tdp->td_sno = tdp->td_ano = tdp->td_wno = tdp->td_lno =
		    tdp->td_flg = 0;
E 36
I 36
COUNT(TCP_DRAIN);
	for (ip = tcb.inp_next; ip != &tcb; ip = ip->inp_next)
		tcp_drainunack(intotcpcb(ip));
E 36
}

D 36
tdb_stuff(tdp, nstate)
	struct tcp_debug *tdp;
	int nstate;
E 36
I 36
tcp_drainunack(tp)
	register struct tcpcb *tp;
E 36
{
I 22
D 36
COUNT(TDB_STUFF);
E 36
I 36
	register struct mbuf *m;
E 36
E 22

D 36
	tdp->td_new = nstate;
	tcp_debug[tdbx++ % TDBSIZE] = *tdp;
	if (tcpconsdebug & 2)
		tcp_prt(tdp);
E 36
I 36
COUNT(TCP_DRAINUNACK);
	for (m = tp->seg_unack; m; m = m->m_act)
		m_freem(m);
	tp->seg_unack = 0;
E 36
I 22
}
D 36

D 24
/* BETTER VERSION OF THIS ROUTINE? */
E 24
tcp_prt(tdp)
	register struct tcp_debug *tdp;
E 36
I 36
	
tcp_ctlinput(m)
	struct mbuf *m;
E 36
{
D 36
COUNT(TCP_PRT);
E 36

D 24
	printf("TCP(%x) %s x %s",
	    tdp->td_tcb, tcpstates[tdp->td_old], tcpinputs[tdp->td_inp]);
	if (tdp->td_inp == ISTIMER)
		printf("(%s)", tcptimers[tdp->td_tim]);
	printf(" --> %s",
	    tcpstates[(tdp->td_new > 0) ? tdp->td_new : tdp->td_old]);
	/* GROSS... DEPENDS ON SIGN EXTENSION OF CHARACTERS */
	if (tdp->td_new < 0)
		printf(" (FAILED)");
	if (tdp->td_sno) {
		printf(" sno %x ano %x win %d len %d flags %x",
		    tdp->td_sno, tdp->td_ano, tdp->td_wno,
		    tdp->td_lno, tdp->td_flg);
E 24
I 24
D 36
	printf("%x ", ((int)tdp->td_tcb)&0xffffff);
	if (tdp->td_inp == INSEND) {
		printf("SEND #%x", tdp->td_sno);
		tdp->td_lno = ntohs(tdp->td_lno);
		tdp->td_wno = ntohs(tdp->td_wno);
	} else {
		if (tdp->td_inp == INRECV)
			printf("RCV #%x ", tdp->td_sno);
		printf("%s.%s",
		    tcpstates[tdp->td_old], tcpinputs[tdp->td_inp]);
		if (tdp->td_inp == ISTIMER)
			printf("(%s)", tcptimers[tdp->td_tim]);
		printf(" -> %s",
		    tcpstates[(tdp->td_new > 0) ? tdp->td_new : tdp->td_old]);
		if (tdp->td_new == -1)
			printf(" (FAILED)");
E 24
	}
I 24
	/* GROSS... DEPENDS ON SIGN EXTENSION OF CHARACTERS */
	if (tdp->td_lno)
		printf(" len=%d", tdp->td_lno);
	if (tdp->td_wno)
		printf(" win=%d", tdp->td_wno);
	if (tdp->td_flg & TH_FIN) printf(" FIN");
	if (tdp->td_flg & TH_SYN) printf(" SYN");
	if (tdp->td_flg & TH_RST) printf(" RST");
	if (tdp->td_flg & TH_EOL) printf(" EOL");
	if (tdp->td_flg & TH_ACK)  printf(" ACK %x", tdp->td_ano);
	if (tdp->td_flg & TH_URG) printf(" URG");
E 24
	printf("\n");
E 36
I 36
COUNT(TCP_CTLINPUT);
	m_freem(m);
E 37
E 36
E 22
E 17
}
D 36
#endif
E 36
E 7
D 2

netprepr(tp, n)         /* network preproc (66,67,68,69,70,71,72,73,74,75,76) */
register struct tcb *tp;
register struct th *n;
{

COUNT(NETPREPR);
	switch (tp->t_state) {

	case LISTEN:

		if (n->t_ack || !syn_ok(tp, n))
			send_rst(tp, n);
		else if (!n->t_rst)
			return(0);
		break;

	case SYN_SENT:

		if (!ack_ok(tp, n) || !syn_ok(tp, n))

			send_rst(tp, n);        /* 71,72,75 */

		else if (n->t_rst) {

			t_close(tp, URESET);            /* 70 */
			return(CLOSED);
		} else
			return(0);
		break;

	default:

        	if (n->t_rst) {         /* any resets? */
        
        		if (n->t_seq >= tp->rcv_nxt) {  /* good reset */
        
        			if (tp->t_state == L_SYN_RCVD) {

        				if (ack_ok(tp, n)) {    /* 67 */
						t_cancel(tp, TREXMT);
						t_cancel(tp, TREXMTTL);
						t_cancel(tp, TPERSIST);
						h_free(tp->t_ucb->uc_host);
        					return(LISTEN);
					}
        			} else {                        /* 66 */
                        		t_close(tp, URESET);
                			return(CLOSED);
        			}
        		}                               /* else 69 */
        		break;
        	}

	case SYN_RCVD:

		if (ack_ok(tp, n))              /* acceptable ack */

			if (syn_ok(tp, n) && n->t_seq != tp->irs)      

				/* bad syn (73,75,76) */

				send_null(tp);  
			else
				return(0);      /* acceptable segment */
		else
			send_rst(tp, n);        /* bad ack (74) */

	}

	return(-1);     /* tell caller to eat segment (unacceptable) */
}
E 2
E 1

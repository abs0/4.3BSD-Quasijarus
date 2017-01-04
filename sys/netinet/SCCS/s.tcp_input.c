h08677
s 00010/00005/01260
d D 7.19 88/06/29 17:07:20 bostic 141 140
c install approved copyright notice
e
s 00006/00006/01259
d D 7.18 88/05/14 11:22:00 karels 140 138
c ack immediately when segment is received out of order;
c remove tcpnodelack
e
s 00000/00000/01321
d D 7.15.1.2 88/03/16 09:32:07 karels 139 136
i 138 137
c update branch
e
s 00032/00022/01233
d D 7.17 88/03/16 09:04:56 karels 138 137
c much longer keepalive timer (don't start probes for 2 hr);
c fix input window test again (accept acks from FINS at left edge and responses
c to keepalives, but dropafterack otherwise; also fixes Phil Karn's problem
c with failure to respond to new SYN to left of window); can't use tcp_drop
c after RST, or we'll send RST in response
e
s 00001/00001/01254
d D 7.16 88/02/27 12:20:19 karels 137 135
c 65535 => IP_MAXPACKET (still XXX)
e
s 00058/00002/01253
d D 7.15.1.1 88/02/07 19:56:29 karels 136 135
c branch for FTP release (#ifdefs for non-4.3)
e
s 00035/00053/01220
d D 7.15 88/02/07 19:20:16 karels 135 134
c ack pure window probes; process URG, etc. even if window is closed;
c squish out common code for window open/closed cases
e
s 00008/00002/01265
d D 7.14 87/12/07 17:46:11 bostic 134 133
c use Berkeley specific header
e
s 00011/00009/01256
d D 7.13 87/11/13 15:45:36 karels 133 132
c window isn't necessarily zero when user is gone, don't accept new data
e
s 00020/00010/01245
d D 7.12 87/10/09 18:23:57 karels 132 131
c slow down more when doing fast retransmission
e
s 00078/00024/01177
d D 7.11 87/09/04 09:37:19 karels 131 130
c two-phase slow start; fast retransmit on repetitive ack;
c drop packet for TCP socket between socket() and listen(); get the rtt
c on SYN
e
s 00040/00014/01161
d D 7.10 87/08/10 20:53:25 karels 130 129
c Phil Karn's retransmit algorithm, using t_rxtcur for current rexmt value;
c slow start from beginning if connection not local; get rtt estimate on SYN
e
s 00001/00002/01174
d D 7.9 87/07/02 16:26:54 karels 129 128
c free those mbufs! (and skip redundant trace)
e
s 00008/00006/01168
d D 7.8 87/07/01 15:29:06 karels 128 127
c we go to LAST_ACK even if data is outstanding, so watch for window
c updates and acks in LAST_ACK
e
s 00010/00000/01164
d D 7.7 87/06/30 23:34:14 karels 127 126
c respond to those resets the keepalives produce
e
s 00050/00015/01114
d D 7.6 87/06/30 23:15:26 karels 126 125
c redo retransmit calculations as srtt + 2*smoothed variance
c (from Van Jacobson)
e
s 00006/00010/01123
d D 7.5 87/06/30 21:15:36 karels 125 124
c cleanups: correct snd_una and timer handling when SYN acked
c from SYN_RCVD state, so rtt is collected; use tcp_output instead of tcp_respond
c to ack (may need to send FIN, etc); clarify obscure code (ourfinisacked)
e
s 00004/00003/01129
d D 7.4 87/06/06 20:20:30 karels 124 123
c slow-start changes from van
e
s 00006/00004/01126
d D 7.3 87/04/29 10:55:24 karels 123 122
c don't assume ACK on received SYN when in SYN_SENT
c (and don't loop when a socket is connected to itself)
e
s 00117/00053/01013
d D 7.2 87/02/19 17:00:46 karels 122 121
c new stats; rearrange to trim data from front before noting
c that data is received after user is gone (don't reset because of dup data!);
c quick connection reuse
e
s 00001/00001/01065
d D 7.1 86/06/05 00:30:23 mckusick 121 120
c 4.3BSD release version
e
s 00009/00001/01057
d D 6.23 86/04/19 20:43:51 karels 120 119
c allow OOB data to be received in-line
e
s 00013/00007/01045
d D 6.22 86/03/12 11:03:30 karels 119 118
c watch out for persist state: don't set REXMT if persisting,
c need to call output if we receive ack for all data (may need to persist then).
e
s 00002/00002/01050
d D 6.21 86/02/23 23:25:12 karels 118 117
c lint
e
s 00002/00005/01050
d D 6.20 86/02/03 20:09:29 karels 117 116
c half-open connection correction: ack SYN's not in the window;
c turn on the "notyet" delay of tcp_output call if not needed
e
s 00036/00021/01019
d D 6.19 86/01/22 09:14:23 karels 116 115
c careful with sequence number arithmetic vs. window sizes
c (u_long vs. int vs. u_short); don't lose mbufs on failure part thru new
c connection setup from LISTEN; use tiflags consistently; add missing ACKNOW
c in LISTEN input case; don't use window if no ACK, as TAC's send garbage;
c make input urgent pointer sensible so it compares right on first URG,
c accounting for seq-number wraparound.
e
s 00003/00004/01037
d D 6.18 86/01/07 14:40:20 mckusick 115 114
c tcp packet with options corrupts mbufs (from lcc.richard@locus.ucla.edu)
e
s 00001/00001/01040
d D 6.17 85/12/19 16:47:29 karels 114 113
c synchronize grot
e
s 00010/00000/01031
d D 6.16 85/10/23 18:21:15 karels 113 112
c maintain estimates of peer's send and receive buffer sizes;
c don't wait for bigger window if he hasn't got one
e
s 00005/00001/01026
d D 6.15 85/10/14 17:39:49 karels 112 111
c don't respond to broadcasts
e
s 00002/00001/01025
d D 6.14 85/10/14 17:38:20 karels 111 110
c re-fix shrinking window problem, watching out for short vs. long
c and rcv_adv not being initialized
e
s 00139/00122/00887
d D 6.13 85/09/16 23:18:47 karels 110 109
c do common case of tcpreass with macro, avoiding ins/dequeing;
c avoid unnecessary pullups; reuse src routing on incoming SYN's;
c don't poke in inpcb after freeing; don't retract offered window due
c to mbuf limit; fix timer for FIN_WAIT_2 blockage; only read oob data once
e
s 00006/00005/01003
d D 6.12 85/07/19 18:26:41 karels 109 108
c minor cleanups
e
s 00007/00001/01001
d D 6.11 85/06/08 12:42:36 mckusick 108 107
c Add copyright
e
s 00002/00003/01000
d D 6.10 85/05/27 22:30:50 karels 107 106
c back out FIN_WAIT_2 timer hack; don't clear persist timer here
e
s 00003/00005/01000
d D 6.9 85/02/12 10:38:40 karels 106 105
c remove fix for acking window probes: don't ack acks!
e
s 00011/00004/00994
d D 6.8 84/11/14 10:18:36 karels 105 104
c add snd_cwndw to decrease outstanding data after a source quench;
c accept a bit more urgent data; acknowledge window probes
e
s 00003/00002/00995
d D 6.7 84/11/01 13:42:30 karels 104 103
c put TCP_MSS in header
e
s 00063/00004/00934
d D 6.6 84/10/19 15:03:12 karels 103 102
c bind local address according to routing (caching the route);
c pick maximum seg sizes (offered and accepted) based on interface mtu,
c with default if not local
e
s 00007/00002/00931
d D 6.5 84/10/18 11:08:57 karels 102 101
c fix round-trip timing: rexmt timer shouldn't screw rtt up,
c but careful when retransmitting timed segment
e
s 00019/00019/00914
d D 6.4 84/08/29 15:37:04 bloom 101 100
c Include file changes.  No more ../h
e
s 00010/00010/00923
d D 6.3 84/03/22 15:13:47 karels 100 99
c rearrange to cause reset if data arrives and user is gone
e
s 00001/00001/00932
d D 6.2 83/11/04 20:42:51 sam 99 98
c sbdrop decrements sb_cc, so must use val before call
e
s 00000/00000/00933
d D 6.1 83/07/29 07:12:15 sam 98 97
c 4.2 distribution
e
s 00006/00007/00927
d D 1.95 83/06/14 22:23:36 sam 97 96
c don't be so offensive
e
s 00014/00000/00920
d D 1.94 83/05/14 15:05:07 sam 96 95
c kludge for bug in BBN TCP
e
s 00004/00001/00916
d D 1.93 83/05/01 19:17:45 sam 95 94
c avoid infinite loops
e
s 00004/00000/00913
d D 1.92 83/04/03 15:14:31 sam 94 93
c add debugging stuff 
e
s 00003/00001/00910
d D 1.91 83/03/27 12:32:09 sam 93 92
c avoid duplicate free
e
s 00003/00003/00908
d D 1.90 83/03/27 09:49:55 sam 92 90
c going to drop'll free free mbuf; be sure and discard tcp options
e
s 00003/00003/00908
d R 1.90 83/03/25 11:42:38 sam 91 90
c going to drop'll free free mbuf; be sure and discard tcp options
e
s 00005/00003/00906
d D 1.89 83/02/10 22:11:53 sam 90 89
c remove /usr/include dependencies
e
s 00020/00000/00889
d D 1.88 83/02/08 23:02:12 sam 89 88
c catch lost socket structures
e
s 00010/00019/00879
d D 1.87 83/01/17 18:00:08 sam 88 87
c stuff from bill to insure no references are kept to free'd cb's
e
s 00002/00001/00896
d D 1.86 83/01/08 19:05:34 sam 87 86
c just wrong
e
s 00007/00010/00890
d D 1.85 83/01/04 23:20:32 sam 86 85
c clean up some stuff; fix problem with lost mbufs
e
s 00002/00002/00898
d D 1.84 82/12/30 12:58:07 sam 85 84
c was sending RST's when in FIN_WAIT states (and later)
e
s 00002/00002/00898
d D 1.83 82/12/14 17:15:44 sam 84 83
c typed mbufs
e
s 00000/00006/00900
d D 1.82 82/10/30 13:03:46 root 83 82
c get rid of conditional htons/ntohs etc
e
s 00002/00002/00904
d D 1.81 82/10/20 02:43:38 root 82 81
c lint
e
s 00000/00001/00906
d D 1.80 82/10/20 01:23:02 root 81 80
c lint
e
s 00000/00000/00907
d D 1.79 82/10/17 22:47:53 root 80 79
c lint
e
s 00011/00011/00896
d D 1.78 82/10/17 14:55:52 root 79 78
c fix lint
e
s 00004/00001/00903
d D 1.77 82/10/16 17:44:21 root 78 77
c insert SBCHECK calls looking for panic:receive problem
e
s 00012/00012/00892
d D 1.76 82/10/09 05:46:56 wnj 77 76
c localize header files
e
s 00001/00058/00903
d D 1.75 82/10/05 18:49:53 root 76 75
c m_get inits m_off; remove TCPTRUEOOB
e
s 00018/00007/00943
d D 1.74 82/09/26 18:29:44 root 75 74
c first working version
e
s 00001/00001/00949
d D 1.73 82/07/24 18:18:17 root 74 73
c restore sccs ids
e
s 00013/00021/00937
d D 1.72 82/07/24 18:13:35 root 73 72
c 
e
s 00001/00001/00957
d D 1.71 82/06/30 21:34:01 wnj 72 71
c nasty little bug in packet reassembly
e
s 00001/00001/00957
d D 1.70 82/06/26 22:02:46 sam 71 70
c use <errno.h>
e
s 00002/00001/00956
d D 1.69 82/06/24 21:39:27 wnj 70 69
c fixed bug in handling of tcp urgent 
e
s 00000/00002/00957
d D 1.68 82/06/20 00:55:19 sam 69 68
c purge COUNT stuff now that we can use gprof
e
s 00000/00001/00959
d D 1.67 82/04/10 23:41:50 sam 68 67
c purge so_addr from socket structure and start cleaning up raw code
e
s 00001/00001/00959
d D 1.66 82/04/01 18:37:40 wnj 67 66
c sowwakeup when so->so_snd.sb_sel
e
s 00001/00000/00959
d D 1.65 82/03/29 11:33:05 sam 66 65
c first cut (incomplete) at routing
e
s 00015/00006/00944
d D 1.64 82/03/26 21:30:19 wnj 65 64
c #if vax --> #if vax || pdp11; also tp = 0 before goto drop's
e
s 00004/00000/00946
d D 1.63 82/03/24 21:56:08 root 64 63
c fix keep alives and timeouts: checksum problem and doing keeps
c on all connections by mistake (still needs more work to do keeps more 
c persistantly!)
e
s 00002/00000/00944
d D 1.62 82/03/19 01:51:36 wnj 63 62
c clear tp before going to send a reset after tcp_close
e
s 00014/00011/00930
d D 1.61 82/03/15 04:44:37 wnj 62 61
c interfac queueing, restrictions on packets, tcp keep alives done 
c properly, bug fix to raw
e
s 00014/00011/00927
d D 1.60 82/03/13 12:52:48 sam 61 60
c lint
e
s 00001/00001/00937
d D 1.59 82/03/11 23:09:25 wnj 60 59
c minor bug fixes
e
s 00007/00002/00931
d D 1.58 82/03/10 11:22:45 root 59 58
c fix bug that scrogged buffer offsets
e
s 00001/00002/00932
d D 1.57 82/03/09 20:01:03 wnj 58 57
c fix bug in tcp_input using m->m_off -= instead of m_drop
e
s 00014/00002/00920
d D 1.56 82/03/03 11:06:54 root 57 56
c wildcard addresses
e
s 00003/00002/00919
d D 1.55 82/02/27 17:47:18 wnj 56 55
c multi-homing and wildcards
e
s 00026/00018/00895
d D 1.54 82/02/25 13:12:33 wnj 55 54
c fix rexmt timeouts
e
s 00008/00001/00905
d D 1.53 82/02/19 00:36:10 wnj 54 53
c let closing user proceed with disconnect when fin is acked.
e
s 00013/00012/00893
d D 1.52 82/02/03 19:32:37 wnj 53 52
c bug fixes (but PERSIST still screwy)
e
s 00002/00001/00903
d D 1.51 82/01/25 18:41:16 wnj 52 51
c fix race condition
e
s 00071/00021/00833
d D 1.50 82/01/18 19:43:11 wnj 51 50
c out-of-band fixed up
e
s 00116/00040/00738
d D 1.49 82/01/17 21:19:38 wnj 50 49
c more work on out-of-band
e
s 00045/00008/00733
d D 1.48 82/01/17 01:01:44 wnj 49 48
c attempt at out of band
e
s 00012/00007/00729
d D 1.47 82/01/13 10:43:24 wnj 48 47
c a number of minor changes
e
s 00006/00000/00730
d D 1.46 82/01/07 22:11:49 root 47 46
c pull snd_nxt along when increasing snd_una
e
s 00013/00014/00717
d D 1.45 81/12/23 14:04:03 root 46 45
c new m_pullup (returning m) fix to way REXMT timers are cancelled
e
s 00020/00032/00711
d D 1.44 81/12/22 23:25:41 root 45 44
c a number of fixes
e
s 00039/00015/00704
d D 1.43 81/12/21 12:00:54 root 44 43
c a number of fixes and still prints in exceptional cases
e
s 00019/00007/00700
d D 1.42 81/12/20 15:21:23 root 43 42
c numerous fixes
e
s 00027/00018/00680
d D 1.41 81/12/19 12:47:13 wnj 42 41
c a number of minor bugs
e
s 00001/00035/00697
d D 1.40 81/12/12 18:04:51 root 41 40
c clean out printf
e
s 00117/00057/00615
d D 1.39 81/12/12 12:58:37 root 40 39
c with crud (first working version)
e
s 00024/00028/00648
d D 1.38 81/12/09 21:19:10 wnj 39 38
c brushu
e
s 00006/00002/00670
d D 1.37 81/12/09 20:49:59 wnj 38 37
c minor bugs
e
s 00001/00002/00671
d D 1.36 81/12/07 22:17:22 wnj 37 36
c stripoptions takes mbuf *; lint
e
s 00000/00000/00673
d D 1.35 81/12/03 17:30:12 wnj 36 35
c cleanup
e
s 00030/00039/00643
d D 1.34 81/12/02 16:59:04 wnj 35 34
c yet more lint
e
s 00006/00009/00676
d D 1.33 81/11/29 22:00:36 wnj 34 33
c lint and interface cleanups
e
s 00198/00120/00487
d D 1.32 81/11/26 11:57:04 wnj 33 32
c before carry to ARPAVAX
e
s 00011/00006/00596
d D 1.31 81/11/25 16:09:45 wnj 32 31
c listing
e
s 00436/00494/00166
d D 1.30 81/11/24 17:33:24 wnj 31 30
c start rewrite
e
s 00005/00017/00655
d D 1.29 81/11/24 07:53:50 wnj 30 29
c minor fixups pre tcp<->spec coordination
e
s 00002/00006/00670
d D 1.28 81/11/23 00:07:48 wnj 29 28
c no address flipping; cksum to ffff; caller to ip_output sets ttl
e
s 00003/00003/00673
d D 1.27 81/11/22 15:00:40 root 28 27
c pullup before stripoptions
e
s 00014/00011/00662
d D 1.26 81/11/20 00:47:06 wnj 27 26
c linted
e
s 00189/00173/00484
d D 1.25 81/11/18 15:37:53 wnj 26 25
c more cleanup
e
s 00019/00019/00638
d D 1.24 81/11/16 14:17:24 wnj 25 24
c more lint
e
s 00081/00077/00576
d D 1.23 81/11/15 13:00:11 wnj 24 23
c listing
e
s 00179/00233/00474
d D 1.22 81/11/14 16:40:04 wnj 23 22
c before overlay
e
s 00134/00116/00573
d D 1.21 81/11/08 16:25:12 wnj 22 21
c first listing
e
s 00002/00000/00687
d D 1.20 81/11/07 12:16:50 wnj 21 20
c acounts only if kprof
e
s 00001/00001/00686
d D 1.19 81/11/04 00:29:23 wnj 20 19
c more cleanups, fields in ucb.h
e
s 00003/00003/00684
d D 1.18 81/11/03 21:54:28 wnj 19 18
c states now w/o fsm matrix; timers accessible by iteration
e
s 00004/00004/00683
d D 1.17 81/11/01 22:32:13 wnj 18 17
c minor fixups
e
s 00004/00014/00683
d D 1.16 81/10/31 15:53:57 wnj 17 16
c bug fixes and last chksum
e
s 00004/00004/00693
d D 1.15 81/10/31 14:15:48 wnj 16 15
c return early in tcp_send, avoiding tcp_sndcopy; use MAX, MFREE in tcp_input
e
s 00021/00030/00676
d D 1.14 81/10/31 14:01:32 wnj 15 14
c present data eliminates (tcp_input now gross!!!)
e
s 00002/00002/00704
d D 1.13 81/10/30 21:44:02 wnj 14 13
c more cleanup
e
s 00106/00116/00600
d D 1.12 81/10/30 20:42:16 wnj 13 12
c cleanup
e
s 00001/00001/00715
d D 1.11 81/10/30 20:19:19 wnj 12 11
c further cleanup
e
s 00020/00020/00696
d D 1.10 81/10/30 19:27:34 wnj 11 10
c name changes pre rearrange
e
s 00015/00003/00701
d D 1.9 81/10/30 18:42:47 wnj 10 9
c inline expand cksum
e
s 00009/00004/00695
d D 1.8 81/10/30 18:04:18 wnj 9 8
c first 1m baud system
e
s 00012/00014/00687
d D 1.7 81/10/29 20:27:38 wnj 8 7
c cleanup of header files
e
s 00021/00062/00680
d D 1.6 81/10/29 16:01:52 wnj 7 6
c working but losing 1 mbuf per connection
e
s 00012/00008/00730
d D 1.5 81/10/28 23:00:12 wnj 6 5
c first working new rcv_text
e
s 00092/00169/00646
d D 1.4 81/10/28 22:07:02 wnj 5 3
c first version test with _tcp_seq
e
s 00157/00275/00540
d R 1.4 81/10/26 02:10:44 wnj 4 3
c first compile of major cleanup
e
s 00040/00016/00775
d D 1.3 81/10/25 14:21:14 wnj 3 2
c fixed up debugging
e
s 00001/00000/00790
d D 1.2 81/10/25 04:34:48 root 2 1
c working version with template
e
s 00790/00000/00000
d D 1.1 81/10/24 23:24:27 wnj 1 0
c date and time created 81/10/24 23:24:27 by wnj
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
D 73
/*	%M%	%I%	%E%	*/
E 73
I 73
D 74
/*	tcp_input.c	1.72	82/07/21	*/
E 74
I 74
D 108
/*	%M%	%I%	%E%	*/
E 108
I 108
/*
D 121
 * Copyright (c) 1982 Regents of the University of California.
E 121
I 121
D 138
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 138
I 138
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 138
E 121
D 134
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 134
I 134
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 141
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 141
I 141
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
E 141
E 134
 *
 *	%W% (Berkeley) %G%
 */
E 108
E 74
E 73
E 32

D 101
#include "../h/param.h"
#include "../h/systm.h"
D 8
#include "../bbnnet/net.h"
#include "../bbnnet/mbuf.h"
#include "../bbnnet/host.h"
#include "../bbnnet/imp.h"
#include "../bbnnet/ucb.h"
#include "../bbnnet/tcp.h"
#include "../bbnnet/ip.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
#include "../bbnnet/fsm.h"
E 8
I 8
#include "../h/mbuf.h"
I 33
#include "../h/protosw.h"
E 33
#include "../h/socket.h"
I 17
D 18
#include "../inet/cksum.h"
E 18
I 18
D 22
#include "../inet/inet_cksum.h"
E 18
E 17
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/imp.h"
#include "../inet/inet_host.h"
#include "../inet/ip.h"
#include "../inet/tcp.h"
#include "../inet/tcp_fsm.h"
E 22
I 22
#include "../h/socketvar.h"
D 26
#include "../net/inet_cksum.h"
E 26
D 33
#include "../net/inet.h"
I 23
#include "../net/inet_pcb.h"
E 23
#include "../net/inet_systm.h"
#include "../net/imp.h"
E 33
I 33
D 77
#include "../net/in.h"
E 77
I 77
D 90
#include "../netinet/in.h"
E 90
I 90
#include "../h/errno.h"
E 101
I 101
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
#include "errno.h"
E 101

#include "../net/if.h"
E 90
E 77
I 66
#include "../net/route.h"
I 90

D 101
#include "../netinet/in.h"
E 90
E 66
D 77
#include "../net/in_pcb.h"
#include "../net/in_systm.h"
E 77
I 77
#include "../netinet/in_pcb.h"
#include "../netinet/in_systm.h"
E 77
D 90
#include "../net/if.h"
E 90
E 33
D 27
#include "../net/inet_host.h"
E 27
D 77
#include "../net/ip.h"
I 24
#include "../net/ip_var.h"
E 24
#include "../net/tcp.h"
I 40
D 43
#define TCPSTATES
E 43
E 40
#include "../net/tcp_fsm.h"
I 33
#include "../net/tcp_seq.h"
#include "../net/tcp_timer.h"
E 33
#include "../net/tcp_var.h"
I 33
#include "../net/tcpip.h"
I 43
#include "../net/tcp_debug.h"
E 77
I 77
#include "../netinet/ip.h"
#include "../netinet/ip_var.h"
#include "../netinet/tcp.h"
#include "../netinet/tcp_fsm.h"
#include "../netinet/tcp_seq.h"
#include "../netinet/tcp_timer.h"
#include "../netinet/tcp_var.h"
#include "../netinet/tcpip.h"
#include "../netinet/tcp_debug.h"
E 101
I 101
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
E 101
E 77
E 43
E 33
D 34
#include "/usr/include/errno.h"
E 34
I 34
D 71
#include "../errno.h"
E 71
I 71
D 90
#include <errno.h>
E 90
E 71
E 34
E 22
E 8

I 61
D 62
#ifdef notdef
E 62
E 61
I 45
int	tcpprintfs = 0;
I 61
D 62
#endif
E 62
E 61
E 45
D 13
extern int nosum;
E 13
I 13
int	tcpcksum = 1;
I 131
int	tcprexmtthresh = 3;
E 131
I 40
D 75
struct	sockaddr_in tcp_in = { AF_INET };
E 75
I 75
D 81
struct	mbuf tcp_mb;
E 81
E 75
I 43
struct	tcpiphdr tcp_saveti;
I 50
D 140
extern	tcpnodelack;
E 140
E 50
E 43
E 40
E 13

I 43
struct	tcpcb *tcp_newtcpcb();
I 110

E 110
E 43
I 22
D 23
tcp_advise(mp)
	struct mbuf *mp;
E 23
I 23
D 31
tcp_drain()
E 23
{
I 23
	register struct inpcb *ip;
E 23

I 27
COUNT(TCP_DRAIN);
E 27
I 23
	for (ip = tcb.inp_next; ip != &tcb; ip = ip->inp_next)
		tcp_drainunack(intotcpcb(ip));
E 23
}

I 23
tcp_drainunack(tp)
	register struct tcpcb *tp;
{
	register struct mbuf *m;

I 27
COUNT(TCP_DRAINUNACK);
E 27
	for (m = tp->seg_unack; m; m = m->m_act)
		m_freem(m);
	tp->seg_unack = 0;
}
	
tcp_ctlinput(m)
	struct mbuf *m;
{

I 27
COUNT(TCP_CTLINPUT);
E 27
	m_freem(m);
}

E 31
I 27
D 34
struct	sockaddr_in tcp_sockaddr = { AF_INET };

E 34
I 31
/*
I 110
 * Insert segment ti into reassembly queue of tcp with
 * control block tp.  Return TH_FIN if reassembly now includes
 * a segment with FIN.  The macro form does the common case inline
 * (segment is the next to be received on an established connection,
 * and the queue is empty), avoiding linkage into and removal
 * from the queue and repetition of various conversions.
I 140
 * Set DELACK for segments received in order, but ack immediately
 * when segments are out of order (so fast retransmit can work).
E 140
 */
#define	TCP_REASS(tp, ti, m, so, flags) { \
	if ((ti)->ti_seq == (tp)->rcv_nxt && \
	    (tp)->seg_next == (struct tcpiphdr *)(tp) && \
	    (tp)->t_state == TCPS_ESTABLISHED) { \
I 140
		tp->t_flags |= TF_DELACK; \
E 140
		(tp)->rcv_nxt += (ti)->ti_len; \
		flags = (ti)->ti_flags & TH_FIN; \
I 122
		tcpstat.tcps_rcvpack++;\
		tcpstat.tcps_rcvbyte += (ti)->ti_len;\
E 122
		sbappend(&(so)->so_rcv, (m)); \
		sorwakeup(so); \
D 140
	} else \
E 140
I 140
	} else { \
E 140
		(flags) = tcp_reass((tp), (ti)); \
I 140
		tp->t_flags |= TF_ACKNOW; \
	} \
E 140
}

tcp_reass(tp, ti)
	register struct tcpcb *tp;
	register struct tcpiphdr *ti;
{
	register struct tcpiphdr *q;
	struct socket *so = tp->t_inpcb->inp_socket;
	struct mbuf *m;
	int flags;

	/*
	 * Call with ti==0 after become established to
	 * force pre-ESTABLISHED data up to user socket.
	 */
	if (ti == 0)
		goto present;

	/*
	 * Find a segment which begins after this one does.
	 */
	for (q = tp->seg_next; q != (struct tcpiphdr *)tp;
	    q = (struct tcpiphdr *)q->ti_next)
		if (SEQ_GT(q->ti_seq, ti->ti_seq))
			break;

	/*
	 * If there is a preceding segment, it may provide some of
	 * our data already.  If so, drop the data from the incoming
	 * segment.  If it provides all of our data, drop us.
	 */
	if ((struct tcpiphdr *)q->ti_prev != (struct tcpiphdr *)tp) {
		register int i;
		q = (struct tcpiphdr *)q->ti_prev;
		/* conversion to int (in i) handles seq wraparound */
		i = q->ti_seq + q->ti_len - ti->ti_seq;
		if (i > 0) {
D 122
			if (i >= ti->ti_len)
E 122
I 122
			if (i >= ti->ti_len) {
				tcpstat.tcps_rcvduppack++;
				tcpstat.tcps_rcvdupbyte += ti->ti_len;
E 122
				goto drop;
I 122
			}
E 122
			m_adj(dtom(ti), i);
			ti->ti_len -= i;
			ti->ti_seq += i;
		}
		q = (struct tcpiphdr *)(q->ti_next);
	}
I 122
	tcpstat.tcps_rcvoopack++;
	tcpstat.tcps_rcvoobyte += ti->ti_len;
E 122

	/*
	 * While we overlap succeeding segments trim them or,
	 * if they are completely covered, dequeue them.
	 */
	while (q != (struct tcpiphdr *)tp) {
		register int i = (ti->ti_seq + ti->ti_len) - q->ti_seq;
		if (i <= 0)
			break;
		if (i < q->ti_len) {
			q->ti_seq += i;
			q->ti_len -= i;
			m_adj(dtom(q), i);
			break;
		}
		q = (struct tcpiphdr *)q->ti_next;
		m = dtom(q->ti_prev);
		remque(q->ti_prev);
		m_freem(m);
	}

	/*
	 * Stick new segment in its place.
	 */
	insque(ti, q->ti_prev);

present:
	/*
	 * Present data to user, advancing rcv_nxt through
	 * completed sequence space.
	 */
	if (TCPS_HAVERCVDSYN(tp->t_state) == 0)
		return (0);
	ti = tp->seg_next;
	if (ti == (struct tcpiphdr *)tp || ti->ti_seq != tp->rcv_nxt)
		return (0);
	if (tp->t_state == TCPS_SYN_RECEIVED && ti->ti_len)
		return (0);
	do {
		tp->rcv_nxt += ti->ti_len;
		flags = ti->ti_flags & TH_FIN;
		remque(ti);
		m = dtom(ti);
		ti = (struct tcpiphdr *)ti->ti_next;
		if (so->so_state & SS_CANTRCVMORE)
			m_freem(m);
		else
			sbappend(&so->so_rcv, m);
	} while (ti != (struct tcpiphdr *)tp && ti->ti_seq == tp->rcv_nxt);
	sorwakeup(so);
	return (flags);
drop:
	m_freem(dtom(ti));
	return (0);
}

/*
E 110
 * TCP input routine, follows pages 65-76 of the
 * protocol specification dated September, 1981 very closely.
 */
E 31
E 27
E 23
E 22
D 26
tcp_input(mp)
	register struct mbuf *mp;
E 26
I 26
tcp_input(m0)
	struct mbuf *m0;
E 26
{
I 10
D 23
	register struct th *n;		/* known to be r10 */
E 23
I 23
D 26
	register struct tcpiphdr *n;		/* known to be r10 */
E 23
D 17
	register int j;			/* known to be r9 */
E 17
I 17
	register int j;
E 17
E 10
D 23
	register struct tcb *tp;
E 23
I 23
	register struct tcpcb *tp;
E 26
I 26
	register struct tcpiphdr *ti;
E 26
	struct inpcb *inp;
E 23
I 22
D 26
	register int thflags;
E 26
I 26
	register struct mbuf *m;
I 50
	struct mbuf *om = 0;
E 50
	int len, tlen, off;
D 31

E 31
D 48
	register struct tcpcb *tp;
E 48
I 48
	register struct tcpcb *tp = 0;
E 48
D 31
	register int j;
E 31
	register int tiflags;
E 26
E 22
D 10
	register struct th *n;
E 10
D 31
	int nstate;
E 31
D 26
	struct mbuf *m;
E 26
D 22
	struct ucb *up;
E 22
I 22
	struct socket *so;
E 22
D 10
	int hlen, tlen, j;
E 10
I 10
D 25
	int hlen, tlen;
E 10
	u_short lport, fport;
E 25
I 25
D 26
	int hlen;
	u_short tlen, lport, fport;
E 26
E 25
D 31
#ifdef TCPDEBUG
	struct tcp_debug tdb;
#endif
E 31
I 31
D 33
	seq_t segend;
E 33
D 34
	int acceptable;
I 33
	tcp_seq todrop, acked;
E 34
I 34
D 116
	int todrop, acked;
E 116
I 116
D 119
	int todrop, acked, newwin;
E 119
I 119
D 125
	int todrop, acked, needoutput = 0;
E 125
I 125
	int todrop, acked, ourfinisacked, needoutput = 0;
E 125
E 119
E 116
I 43
	short ostate;
I 57
	struct in_addr laddr;
I 89
	int dropsocket = 0;
I 122
	int iss = 0;
E 122
E 89
E 57
E 43
E 34
E 33
E 31
D 26
COUNT(TCP_INPUT);
E 26

I 122
	tcpstat.tcps_rcvtotal++;
E 122
I 26
D 69
COUNT(TCP_INPUT);
E 69
E 26
	/*
D 26
	 * Build extended tcp header
E 26
I 26
D 40
	 * Get ip and tcp header together in first mbuf.
I 38
	 * Note: ip leaves ip header in first mbuf.
E 40
I 40
	 * Get IP and TCP header together in first mbuf.
	 * Note: IP leaves IP header in first mbuf.
E 40
E 38
E 26
	 */
D 22
	n = (struct th *)((int)mp + mp->m_off);
E 22
I 22
D 23
	n = mtod(mp, struct th *);
E 23
I 23
D 26
	n = mtod(mp, struct tcpiphdr *);
E 23
D 24
	thflags = n->th_flags;
E 24
I 24
	thflags = n->ti_flags;
E 24
E 22
	tlen = ((struct ip *)n)->ip_len;
D 24
	n->t_len = htons(tlen);
	n->t_next = NULL;
	n->t_prev = NULL;
	n->t_x1 = 0;
	lport = ntohs(n->t_dst);
	fport = ntohs(n->t_src);
E 24
I 24
	n->ti_len = htons(tlen);
	n->ti_next = NULL;
	n->ti_prev = NULL;
	n->ti_x1 = 0;
D 25
	lport = ntohs(n->ti_dst);
	fport = ntohs(n->ti_src);
E 25
I 25
	lport = ntohs(n->ti_dport);
	fport = ntohs(n->ti_sport);
E 26
I 26
	m = m0;
D 28
	ti = mtod(m, struct tcpiphdr *);
	if (ti->ti_len > sizeof (struct ip))
D 27
		ip_stripoptions((struct ip *)ti);
E 27
I 27
		ip_stripoptions((struct ip *)ti, (char *)0);
E 28
E 27
D 33
	if (m->m_len < sizeof (struct tcpiphdr) &&
	    m_pullup(m, sizeof (struct tcpiphdr)) == 0) {
		tcpstat.tcps_hdrops++;
		goto bad;
	}
E 33
I 28
	ti = mtod(m, struct tcpiphdr *);
D 38
	if (ti->ti_len > sizeof (struct ip))
E 38
I 38
D 40
	if (((struct ip *)ti)->ip_len > sizeof (struct ip))
E 40
I 40
	if (((struct ip *)ti)->ip_hl > (sizeof (struct ip) >> 2))
E 40
E 38
D 37
		ip_stripoptions((struct ip *)ti, (char *)0);
E 37
I 37
		ip_stripoptions((struct ip *)ti, (struct mbuf *)0);
E 37
I 33
D 46
	if (m->m_len < sizeof (struct tcpiphdr)) {
I 40
D 41
printf("m->m_len %d\n", m->m_len);
E 41
E 40
		if (m_pullup(m, sizeof (struct tcpiphdr)) == 0) {
E 46
I 46
	if (m->m_off > MMAXOFF || m->m_len < sizeof (struct tcpiphdr)) {
		if ((m = m_pullup(m, sizeof (struct tcpiphdr))) == 0) {
E 46
I 40
D 41
printf("tcp_input: header drop\n");
E 41
E 40
D 122
			tcpstat.tcps_hdrops++;
E 122
I 122
			tcpstat.tcps_rcvshort++;
E 122
D 46
			goto drop;
E 46
I 46
			return;
E 46
		}
		ti = mtod(m, struct tcpiphdr *);
	}
E 33
E 28
E 26
E 25
E 24

D 26
	/* WONT BE POSSIBLE WHEN MBUFS ARE 256 BYTES */
D 24
	if ((hlen = n->t_off << 2) > mp->m_len)
E 24
I 24
	if ((hlen = n->ti_off << 2) > mp->m_len)
E 24
		{ printf("tcp header overflow\n"); m_freem(mp); return; }

E 26
I 26
	/*
D 40
	 * Checksum extended tcp header and data.
E 40
I 40
	 * Checksum extended TCP header and data.
E 40
	 */
	tlen = ((struct ip *)ti)->ip_len;
	len = sizeof (struct ip) + tlen;
E 26
D 13
	/*
	 * Checksum extended header and data
	 */
	j = n->t_sum; n->t_sum = 0;
E 13
I 13
	if (tcpcksum) {
D 26
		/*
		 * Checksum extended header and data
		 */
D 17
		j = n->t_sum; n->t_sum = 0;
E 13
D 10
	if (j != cksum(mp, sizeof (struct ip) + tlen)) {
E 10
I 10
#ifdef vax
D 13
	if (tlen == 20) {
		asm("addl3 $8,r10,r0; movl (r0)+,r1; addl2 (r0)+,r1");
		asm("adwc (r0)+,r1; adwc (r0)+,r1; adwc (r0)+,r1");
		asm("adwc (r0)+,r1; adwc (r0)+,r1; adwc (r0)+,r1");
		asm("adwc $0,r1; ashl $-16,r1,r0; addw2 r0,r1");
		asm("adwc $0,r1");		/* ### */
		asm("mcoml r1,r1; movzwl r1,r1; subl2 r1,r9");
	} else
E 13
I 13
		if (tlen == 20) {
			asm("addl3 $8,r10,r0; movl (r0)+,r1; addl2 (r0)+,r1");
			asm("adwc (r0)+,r1; adwc (r0)+,r1; adwc (r0)+,r1");
			asm("adwc (r0)+,r1; adwc (r0)+,r1; adwc (r0)+,r1");
			asm("adwc $0,r1; ashl $-16,r1,r0; addw2 r0,r1");
			asm("adwc $0,r1");		/* ### */
			asm("mcoml r1,r1; movzwl r1,r1; subl2 r1,r9");
		} else
E 13
#endif
D 13
		j -= cksum(mp, sizeof (struct ip) + tlen);
	if (j != 0) {
E 10
		netstat.t_badsum++;
		if (nosum == 0) {
E 13
I 13
			j -= cksum(mp, sizeof (struct ip) + tlen);
		if (j != 0) {
E 17
I 17
D 18
		CKSUM_TCPGET(mp, n, r10, sizeof (struct ip) + tlen);
		if (n->t_cksum != 0) {
E 18
I 18
		CKSUM_TCPCHK(mp, n, r10, sizeof (struct ip) + tlen);
D 24
		if (n->t_sum != 0) {
E 24
I 24
		if (n->ti_sum != 0) {
E 24
E 18
E 17
			netstat.t_badsum++;
E 13
			m_freem(mp);
			return;
E 26
I 26
		ti->ti_next = ti->ti_prev = 0;
		ti->ti_x1 = 0;
D 27
		ti->ti_len = htons(tlen);
E 27
I 27
D 38
		ti->ti_len = htons((u_short)tlen);
E 38
I 38
		ti->ti_len = (u_short)tlen;
D 65
#if vax
E 65
I 65
D 79
#if vax || pdp11
E 79
I 79
D 83
#if vax || pdp11 || ns16032
E 83
E 79
E 65
D 61
		ti->ti_len = htons(ti->ti_len);
E 61
I 61
		ti->ti_len = htons((u_short)ti->ti_len);
E 61
D 83
#endif
E 83
E 38
E 27
D 29
		if (ti->ti_sum = inet_cksum(m, len)) {
E 29
I 29
D 33
		if ((ti->ti_sum = inet_cksum(m, len)) != 0xffff) {
E 33
I 33
D 39
		if ((ti->ti_sum = in_cksum(m, len)) != 0xffff) {
E 39
I 39
		if (ti->ti_sum = in_cksum(m, len)) {
I 94
			if (tcpprintfs)
				printf("tcp sum: src %x\n", ti->ti_src);
E 94
E 39
E 33
E 29
D 122
			tcpstat.tcps_badsum++;
E 122
I 122
			tcpstat.tcps_rcvbadsum++;
E 122
D 31
			printf("tcp cksum %x\ti", ti->ti_sum);
E 31
I 31
D 62
			printf("tcp cksum %x\n", ti->ti_sum);
E 62
I 62
D 92
			if (tcpprintfs)
				printf("tcp cksum %x\n", ti->ti_sum);
E 92
E 62
E 31
D 33
			goto bad;
E 33
I 33
			goto drop;
E 33
E 26
		}
	}

	/*
D 23
	 * Find tcb for message (SHOULDN'T USE LINEAR SEARCH!)
E 23
I 23
D 26
	 * Find tcb for message.
E 26
I 26
D 40
	 * Check that tcp offset makes sense,
	 * process tcp options and adjust length.
E 40
I 40
	 * Check that TCP offset makes sense,
D 50
	 * process TCP options and adjust length.
E 50
I 50
	 * pull out TCP options and adjust length.
E 50
E 40
E 26
E 23
	 */
D 8
	for (tp = netcb.n_tcb_head; tp != 0; tp = tp->t_tcb_next)
E 8
I 8
D 14
	for (tp = tcb_head; tp != 0; tp = tp->t_tcb_next)
E 14
I 14
D 22
	for (tp = tcb.tcb_next; tp != (struct tcb *)&tcb; tp = tp->tcb_next)
E 22
I 22
D 23
	tp = tcb.tcb_next;
	for (; tp != (struct tcb *)&tcb; tp = tp->tcb_hd.tcb_next)
E 22
E 14
E 8
		if (tp->t_lport == lport && tp->t_fport == fport &&
D 22
		    tp->t_ucb->uc_host->h_addr.s_addr == n->t_s.s_addr)
E 22
I 22
		    tp->t_host->h_addr.s_addr == n->t_s.s_addr)
E 22
			goto found;
D 8
	for (tp = netcb.n_tcb_head; tp != 0; tp = tp->t_tcb_next)
E 8
I 8
D 14
	for (tp = tcb_head; tp != 0; tp = tp->t_tcb_next)
E 14
I 14
D 22
	for (tp = tcb.tcb_next; tp != (struct tcb *)&tcb; tp = tp->tcb_next)
E 22
I 22
	tp = tcb.tcb_next;
	for (; tp != (struct tcb *)&tcb; tp = tp->tcb_hd.tcb_next)
E 22
E 14
E 8
		if (tp->t_lport == lport &&
		    (tp->t_fport==fport || tp->t_fport==0) &&
D 22
		    (tp->t_ucb->uc_host->h_addr.s_addr == n->t_s.s_addr ||
		     tp->t_ucb->uc_host->h_addr.s_addr == 0))
E 22
I 22
		    (tp->t_host->h_addr.s_addr == n->t_s.s_addr ||
		     tp->t_host->h_addr.s_addr == 0))
E 22
			goto found;
	goto notwanted;
found:
E 23
I 23
D 24
	inp = in_pcblookup(&tcb, &n->t_s, fport, &n_lhost, lport);
E 24
I 24
D 25
	inp = inpcb_lookup(&tcb, &n->ti_src, fport, &n_lhost, lport);
E 25
I 25
D 26
	inp = in_pcblookup(&tcb, &n->ti_src, fport, &n_lhost, lport);
E 26
I 26
	off = ti->ti_off << 2;
D 39
	if (off < sizeof (struct tcphdr) || off > ti->ti_len) {
E 39
I 39
	if (off < sizeof (struct tcphdr) || off > tlen) {
I 94
		if (tcpprintfs)
			printf("tcp off: src %x off %d\n", ti->ti_src, off);
E 94
I 40
D 41
printf("tcp_input: bad offset\n");
E 41
E 40
E 39
D 122
		tcpstat.tcps_badoff++;
E 122
I 122
		tcpstat.tcps_rcvbadoff++;
E 122
D 33
		goto bad;
E 33
I 33
		goto drop;
E 33
	}
D 62
	ti->ti_len = tlen - off;
E 62
I 62
	tlen -= off;
	ti->ti_len = tlen;
E 62
D 33
	/* PROCESS OPTIONS */
E 33
I 33
D 50
#if 0
D 39
	if (off > sizeof (struct tcphdr) >> 2)
E 39
I 39
	if (off > sizeof (struct tcphdr))
E 39
		tcp_options(ti);
#endif
E 50
I 50
	if (off > sizeof (struct tcphdr)) {
D 110
		if ((m = m_pullup(m, sizeof (struct ip) + off)) == 0) {
			tcpstat.tcps_hdrops++;
D 92
			goto drop;
E 92
I 92
			return;
E 110
I 110
		if (m->m_len < sizeof(struct ip) + off) {
			if ((m = m_pullup(m, sizeof (struct ip) + off)) == 0) {
D 122
				tcpstat.tcps_hdrops++;
E 122
I 122
				tcpstat.tcps_rcvshort++;
E 122
				return;
			}
			ti = mtod(m, struct tcpiphdr *);
E 110
E 92
		}
D 110
		ti = mtod(m, struct tcpiphdr *);
E 110
D 84
		om = m_get(M_DONTWAIT);
E 84
I 84
		om = m_get(M_DONTWAIT, MT_DATA);
E 84
		if (om == 0)
			goto drop;
D 76
		om->m_off = MMINOFF;
E 76
		om->m_len = off - sizeof (struct tcphdr);
		{ caddr_t op = mtod(m, caddr_t) + sizeof (struct tcpiphdr);
D 61
		  bcopy(op, mtod(om, caddr_t), om->m_len);
E 61
I 61
		  bcopy(op, mtod(om, caddr_t), (unsigned)om->m_len);
E 61
		  m->m_len -= om->m_len;
D 61
		  bcopy(op+om->m_len, op, m->m_len-sizeof (struct tcpiphdr));
E 61
I 61
		  bcopy(op+om->m_len, op,
		   (unsigned)(m->m_len-sizeof (struct tcpiphdr)));
E 61
		}
	}
E 50
E 33
I 31
	tiflags = ti->ti_flags;
E 31

I 59
	/*
D 62
	 * drop IP header
E 62
I 62
D 115
	 * Drop TCP and IP headers.
E 115
I 115
	 * Drop TCP and IP headers; TCP options were dropped above.
E 115
E 62
	 */
D 115
	off += sizeof (struct ip);
	m->m_off += off;
	m->m_len -= off;
E 115
I 115
	m->m_off += sizeof(struct tcpiphdr);
	m->m_len -= sizeof(struct tcpiphdr);
E 115

E 59
I 39
D 65
#if vax
E 65
I 65
D 79
#if vax || pdp11
E 79
I 79
D 83
#if vax || pdp11 || ns16032
E 83
E 79
E 65
E 39
	/*
I 33
D 40
	 * Convert tcp protocol specific fields to host format.
E 40
I 40
	 * Convert TCP protocol specific fields to host format.
E 40
	 */
	ti->ti_seq = ntohl(ti->ti_seq);
	ti->ti_ack = ntohl(ti->ti_ack);
	ti->ti_win = ntohs(ti->ti_win);
	ti->ti_urp = ntohs(ti->ti_urp);
I 39
D 83
#endif
E 83
E 39

	/*
E 33
D 29
	 * Convert addresses and ports to host format.
E 29
D 56
	 * Locate pcb for segment.
E 56
I 56
D 75
	 * Locate pcb for segment.  On match, update the local
	 * address stored in the block to reflect anchoring.
E 75
I 75
	 * Locate pcb for segment.
E 75
E 56
	 */
I 122
findpcb:
E 122
D 29
	ti->ti_src.s_addr = ntohl(ti->ti_src.s_addr);
	ti->ti_dst.s_addr = ntohl(ti->ti_dst.s_addr);
	ti->ti_sport = ntohs(ti->ti_sport);
	ti->ti_dport = ntohs(ti->ti_dport);
E 29
D 27
	inp = in_pcblookup(&tcb, &ti->ti_src, ti->ti_sport, &ti->ti_dst, ti->ti_dport);
E 27
I 27
D 31
	inp = in_pcblookup(&tcb, ti->ti_src, ti->ti_sport, ti->ti_dst, ti->ti_dport);
E 31
I 31
	inp = in_pcblookup
D 56
		(&tcb, ti->ti_src, ti->ti_sport, ti->ti_dst, ti->ti_dport);
E 56
I 56
D 57
		(&tcb, ti->ti_src, ti->ti_sport, ti->ti_dst, ti->ti_dport, 1);
E 57
I 57
		(&tcb, ti->ti_src, ti->ti_sport, ti->ti_dst, ti->ti_dport,
		INPLOOKUP_WILDCARD);
E 57
E 56

	/*
	 * If the state is CLOSED (i.e., TCB does not exist) then
D 40
	 * all data in the incoming segment is discarded.  (p. 65).
E 40
I 40
	 * all data in the incoming segment is discarded.
I 131
	 * If the TCB exists but is in CLOSED state, it is embryonic,
	 * but should either do a listen or a connect soon.
E 131
E 40
	 */
E 31
E 27
E 26
E 25
E 24
D 44
	if (inp == 0)
E 44
I 44
D 45
	if (inp == 0) {
printf("cant find inp\n");
E 45
I 45
	if (inp == 0)
E 45
E 44
D 31
		goto notwanted;
I 25
D 26
	tp = intotcpcb(inp);
	if (tp == 0)
		goto notwanted;
E 26
I 26
	tp = intotcpcb(inp);		/* ??? */
	if (tp == 0)			/* ??? */
		goto notwanted;		/* ??? */
E 31
I 31
D 33
		goto sendreset;
E 33
I 33
		goto dropwithreset;
I 44
D 45
	}
E 45
E 44
E 33
	tp = intotcpcb(inp);
D 44
	if (tp == 0)
E 44
I 44
D 45
	if (tp == 0) {
printf("tp is 0\n");
E 45
I 45
	if (tp == 0)
E 45
E 44
D 33
		goto sendreset;
E 33
I 33
		goto dropwithreset;
I 131
	if (tp->t_state == TCPS_CLOSED)
		goto drop;
E 131
I 44
D 45
	}
E 45
E 44
I 40
D 41
printf("tcp_input: segment seq %x ack %x win %x inp %x flags",
ti->ti_seq, ti->ti_ack, ti->ti_win, inp);
if (ti->ti_flags & TH_FIN) printf(" FIN");
if (ti->ti_flags & TH_SYN) printf(" SYN");
if (ti->ti_flags & TH_RST) printf(" RST");
if (ti->ti_flags & TH_PUSH) printf(" PUSH");
if (ti->ti_flags & TH_ACK) printf(" ACK");
if (ti->ti_flags & TH_URG) printf(" URG");
printf("\n");
printf("tcp_input: "); pseqno(tp);
E 41
E 40
I 34
	so = inp->inp_socket;
I 43
	if (so->so_options & SO_DEBUG) {
		ostate = tp->t_state;
		tcp_saveti = *ti;
	}
I 73
	if (so->so_options & SO_ACCEPTCONN) {
		so = sonewconn(so);
		if (so == 0)
			goto drop;
I 89
		/*
		 * This is ugly, but ....
		 *
		 * Mark socket as temporary until we're
		 * committed to keeping it.  The code at
		 * ``drop'' and ``dropwithreset'' check the
		 * flag dropsocket to see if the temporary
		 * socket created here should be discarded.
		 * We mark the socket as discardable until
		 * we're committed to it below in TCPS_LISTEN.
		 */
		dropsocket++;
E 89
		inp = (struct inpcb *)so->so_pcb;
		inp->inp_laddr = ti->ti_dst;
		inp->inp_lport = ti->ti_dport;
I 136
#if BSD>=43
E 136
I 110
		inp->inp_options = ip_srcroute();
I 136
#endif
E 136
E 110
		tp = intotcpcb(inp);
		tp->t_state = TCPS_LISTEN;
	}
E 73
D 44
		
E 44
E 43
E 34
E 33
E 31
E 26
E 25
E 23

	/*
I 35
	 * Segment received on connection.
	 * Reset idle time and keep-alive timer.
	 */
	tp->t_idle = 0;
D 138
	tp->t_timer[TCPT_KEEP] = TCPTV_KEEP;
E 138
I 138
	tp->t_timer[TCPT_KEEP] = tcp_keepidle;
E 138

	/*
I 50
D 103
	 * Process options.
E 103
I 103
	 * Process options if not in LISTEN state,
	 * else do it below (after getting remote address).
E 103
	 */
D 103
	if (om) {
		tcp_dooptions(tp, om);
E 103
I 103
	if (om && tp->t_state != TCPS_LISTEN) {
		tcp_dooptions(tp, om, ti);
E 103
		om = 0;
	}

	/*
E 50
E 35
D 26
	 * Byte swap header
E 26
I 26
D 33
	 * Convert tcp protocol specific fields to host format.
E 33
I 33
	 * Calculate amount of space in receive window,
	 * and then do TCP input processing.
I 110
	 * Receive window is amount of space in rcv queue,
	 * but not less than advertised window.
E 110
E 33
E 26
	 */
D 24
	n->t_len = tlen - hlen;
	n->t_src = fport;
	n->t_dst = lport;
	n->t_seq = ntohl(n->t_seq);
	n->t_ackno = ntohl(n->t_ackno);
	n->t_win = ntohs(n->t_win);
	n->t_urp = ntohs(n->t_urp);
E 24
I 24
D 26
	n->ti_len = tlen - hlen;
	n->ti_sport = fport;
	n->ti_dport = lport;
	n->ti_seq = ntohl(n->ti_seq);
D 25
	n->ti_ackno = ntohl(n->ti_ackno);
E 25
I 25
	n->ti_ackno = ntohl((n_long)n->ti_ackno);
E 25
	n->ti_win = ntohs(n->ti_win);
	n->ti_urp = ntohs(n->ti_urp);
E 26
I 26
D 33
	ti->ti_seq = ntohl(ti->ti_seq);
	ti->ti_ackno = ntohl((n_long)ti->ti_ackno);
	ti->ti_win = ntohs(ti->ti_win);
	ti->ti_urp = ntohs(ti->ti_urp);
E 33
I 33
D 110
	tp->rcv_wnd = sbspace(&so->so_rcv);
E 110
I 110
D 111
	tp->rcv_wnd = MAX(sbspace(&so->so_rcv), tp->rcv_adv - tp->rcv_nxt);
E 111
I 111
D 116
	tp->rcv_wnd = sbspace(&so->so_rcv);
E 111
E 110
I 39
	if (tp->rcv_wnd < 0)
		tp->rcv_wnd = 0;
I 111
	tp->rcv_wnd = MAX(tp->rcv_wnd, (short)(tp->rcv_adv - tp->rcv_nxt));
E 116
I 116
	{ int win;
E 116
E 111
E 39
E 33
E 26
E 24

I 116
	win = sbspace(&so->so_rcv);
	if (win < 0)
		win = 0;
	tp->rcv_wnd = MAX(win, (int)(tp->rcv_adv - tp->rcv_nxt));
	}

E 116
D 33
	/*
D 31
	 * Check segment seq # and do rst processing
E 31
I 31
	 * Discard ip header, and do tcp input processing.
E 31
	 */
I 26
D 31
	tiflags = ti->ti_flags;
E 31
I 31
	off += sizeof (struct ip);
	m->m_off += off;
	m->m_len -= off;

E 33
E 31
E 26
	switch (tp->t_state) {

D 31
	case LISTEN:
D 22
		if ((n->th_flags&TH_ACK) || !syn_ok(tp, n)) {
E 22
I 22
D 26
		if ((thflags&TH_ACK) || !syn_ok(tp, n)) {
E 22
D 11
			send_rst(tp, n);
E 11
I 11
			tcp_sndrst(tp, n);
E 11
			goto badseg;
E 26
I 26
		if ((tiflags&TH_ACK) || (tiflags&TH_SYN) == 0) {
			tcp_sndrst(tp, ti);
			goto bad;
E 31
I 31
	/*
	 * If the state is LISTEN then ignore segment if it contains an RST.
	 * If the segment contains an ACK then it is bad and send a RST.
	 * If it does not contain a SYN then it is not interesting; drop it.
I 112
	 * Don't bother responding if the destination was a broadcast.
E 112
D 33
	 * Otherwise initialize tp->rcv_next, and tp->irs, select an initial
E 33
I 33
	 * Otherwise initialize tp->rcv_nxt, and tp->irs, select an initial
E 33
	 * tp->iss, and send a segment:
D 33
	 *     <SEQ=ISS><ACK=RCV>NXT><CTL=SYN,ACK>
E 33
I 33
	 *     <SEQ=ISS><ACK=RCV_NXT><CTL=SYN,ACK>
E 33
	 * Also initialize tp->snd_nxt to tp->iss+1 and tp->snd_una to tp->iss.
	 * Fill in remote peer address fields if not previously specified.
	 * Enter SYN_RECEIVED state, and process any other fields of this
D 40
	 * segment in this state.  (p. 65)
E 40
I 40
	 * segment in this state.
E 40
	 */
D 75
	case TCPS_LISTEN:
E 75
I 75
	case TCPS_LISTEN: {
D 79
		struct mbuf *m = m_get(M_DONTWAIT);
E 79
I 79
D 84
		struct mbuf *am = m_get(M_DONTWAIT);
E 84
I 84
D 86
		struct mbuf *am = m_get(M_DONTWAIT, MT_SONAME);
E 86
I 86
		struct mbuf *am;
E 86
E 84
E 79
		register struct sockaddr_in *sin;

D 79
		if (m == 0)
E 79
I 79
D 86
		if (am == 0)
E 79
			goto drop;
D 76
		m->m_off = MMINOFF;
E 76
D 79
		m->m_len = sizeof (struct sockaddr_in);
E 79
I 79
		am->m_len = sizeof (struct sockaddr_in);
E 86
E 79
E 75
		if (tiflags & TH_RST)
			goto drop;
D 44
		if (tiflags & TH_ACK)
E 44
I 44
D 45
		if (tiflags & TH_ACK) {
printf("contains ACK\n");
E 45
I 45
		if (tiflags & TH_ACK)
E 45
E 44
D 33
			goto sendrst;
E 33
I 33
			goto dropwithreset;
E 33
D 44
		if ((tiflags & TH_SYN) == 0)
E 44
I 44
D 45
}
		if ((tiflags & TH_SYN) == 0) {
printf("no syn\n");
E 45
I 45
		if ((tiflags & TH_SYN) == 0)
E 45
E 44
			goto drop;
I 112
		if (in_broadcast(ti->ti_dst))
			goto drop;
E 112
I 86
		am = m_get(M_DONTWAIT, MT_SONAME);
		if (am == NULL)
			goto drop;
		am->m_len = sizeof (struct sockaddr_in);
E 86
I 44
D 45
}
E 45
E 44
I 40
D 75
		tcp_in.sin_addr = ti->ti_src;
		tcp_in.sin_port = ti->ti_sport;
E 75
I 75
D 79
		sin = mtod(m, struct sockaddr_in *);
E 79
I 79
		sin = mtod(am, struct sockaddr_in *);
E 79
		sin->sin_family = AF_INET;
		sin->sin_addr = ti->ti_src;
		sin->sin_port = ti->ti_sport;
E 75
D 44
		if (in_pcbconnect(inp, (struct sockaddr *)&tcp_in))
E 44
I 44
D 45
		if (in_pcbconnect(inp, (struct sockaddr *)&tcp_in)) {
printf("pcb cant connect\n");
E 45
I 45
D 57
		if (in_pcbconnect(inp, (struct sockaddr *)&tcp_in))
E 57
I 57
		laddr = inp->inp_laddr;
D 86
		if (inp->inp_laddr.s_addr == 0)
E 86
I 86
		if (inp->inp_laddr.s_addr == INADDR_ANY)
E 86
			inp->inp_laddr = ti->ti_dst;
D 61
		if (in_pcbconnect(inp, (struct sockaddr *)&tcp_in)) {
E 61
I 61
D 75
		if (in_pcbconnect(inp, (struct sockaddr_in *)&tcp_in)) {
E 75
I 75
D 79
		if (in_pcbconnect(inp, m)) {
E 79
I 79
		if (in_pcbconnect(inp, am)) {
E 79
E 75
E 61
			inp->inp_laddr = laddr;
I 75
D 79
			m_free(m);
E 79
I 79
D 82
			m_free(am);
E 82
I 82
			(void) m_free(am);
E 82
E 79
E 75
E 57
E 45
E 44
			goto drop;
I 57
		}
I 75
D 79
		m_free(m);
E 79
I 79
D 82
		m_free(am);
E 82
I 82
		(void) m_free(am);
E 82
E 79
E 75
E 57
I 44
D 45
}
E 45
E 44
		tp->t_template = tcp_template(tp);
		if (tp->t_template == 0) {
I 44
D 45
printf("can't get template\n");
E 45
E 44
D 116
			in_pcbdisconnect(inp);
E 116
I 116
D 118
			tp = tcp_drop(tp);
E 118
I 118
			tp = tcp_drop(tp, ENOBUFS);
E 118
E 116
I 102
			dropsocket = 0;		/* socket is already gone */
E 102
I 57
D 110
			inp->inp_laddr = laddr;
E 110
I 65
D 116
			tp = 0;
E 116
E 65
E 57
			goto drop;
		}
I 103
		if (om) {
			tcp_dooptions(tp, om, ti);
			om = 0;
		}
E 103
I 57
D 68
		in_setsockaddr(inp);
E 68
E 57
E 40
D 33
		tp->rcv_nxt = ti->ti_seq + 1;
E 33
I 33
D 122
		tp->iss = tcp_iss; tcp_iss += TCP_ISSINCR/2;
E 122
I 122
		if (iss)
			tp->iss = iss;
		else
			tp->iss = tcp_iss;
		tcp_iss += TCP_ISSINCR/2;
E 122
E 33
		tp->irs = ti->ti_seq;
D 33
		tp->iss = tcp_selectiss();
		tcp_reflect(ti, tp->iss, tp->rcv_next, TH_SYN|TH_ACK);
E 33
I 33
		tcp_sendseqinit(tp);
		tcp_rcvseqinit(tp);
I 116
		tp->t_flags |= TF_ACKNOW;
E 116
E 33
		tp->t_state = TCPS_SYN_RECEIVED;
D 33
		tiflags &= ~TH_SYN; tiflags |= TH_RST;
E 33
D 39
		if (inp->inp_faddr.s_addr == 0) {
			inp->inp_faddr = ti->ti_src;
			inp->inp_fport = ti->ti_sport;
E 31
E 26
		}
E 39
I 39
D 40
		in_pcbconnect(inp, ti->ti_src, ti->ti_sport);
E 40
I 40
D 138
		tp->t_timer[TCPT_KEEP] = TCPTV_KEEP;
E 138
I 138
		tp->t_timer[TCPT_KEEP] = TCPTV_KEEP_INIT;
E 138
I 89
		dropsocket = 0;		/* committed to socket */
I 122
		tcpstat.tcps_accepts++;
E 122
E 89
D 41
printf("tcp_input: out of LISTEN: ");
E 41
E 40
E 39
D 22
		if (n->th_flags&TH_RST)
E 22
I 22
D 26
		if (thflags&TH_RST)
E 22
			goto badseg;
		goto goodseg;
E 26
I 26
D 31
		if (tiflags&TH_RST)
			goto bad;
		goto good;
E 31
I 31
D 33
		break;
E 33
I 33
		goto trimthenstep6;
I 75
		}
E 75
E 33
E 31
E 26

D 31
	case SYN_SENT:
D 26
		if (!ack_ok(tp, n) || !syn_ok(tp, n)) {
D 11
			send_rst(tp, n);			/* 71,72,75 */
E 11
I 11
			tcp_sndrst(tp, n);			/* 71,72,75 */
E 11
			goto badseg;
E 26
I 26
		if (!ack_ok(tp, ti) || (tiflags&TH_SYN) == 0) {
			tcp_sndrst(tp, ti);			/* 71,72,75 */
			goto bad;
E 31
I 31
	/*
	 * If the state is SYN_SENT:
	 *	if seg contains an ACK, but not for our SYN, drop the input.
	 *	if seg contains a RST, then drop the connection.
	 *	if seg does not contain SYN, then drop it.
	 * Otherwise this is an acceptable SYN segment
	 *	initialize tp->rcv_nxt and tp->irs
	 *	if seg contains ack then advance tp->snd_una
	 *	if SYN has been acked change to ESTABLISHED else SYN_RCVD state
	 *	arrange for segment to be acked (eventually)
	 *	continue processing rest of data/controls, beginning with URG
	 */
	case TCPS_SYN_SENT:
		if ((tiflags & TH_ACK) &&
D 45
		    (SEQ_LEQ(ti->ti_ack, tp->iss) ||
E 45
I 45
D 110
/* this should be SEQ_LT; is SEQ_LEQ for BBN vax TCP only */
		    (SEQ_LT(ti->ti_ack, tp->iss) ||
E 110
I 110
		    (SEQ_LEQ(ti->ti_ack, tp->iss) ||
E 110
E 45
D 33
		     SEQ_GT(ti->ti_ack, tp->snd.nxt))) {
			tcp_reflect(ti, ti->ti_ack, 0, TH_RST);
			goto drop;
E 31
E 26
		}
E 33
I 33
D 39
		     SEQ_GT(ti->ti_ack, tp->snd_nxt)))
E 39
I 39
		     SEQ_GT(ti->ti_ack, tp->snd_max)))
E 39
			goto dropwithreset;
E 33
D 22
		if (n->th_flags&TH_RST) {
D 11
			t_close(tp, URESET);			/* 70 */
E 11
I 11
			tcp_close(tp, URESET);			/* 70 */
E 22
I 22
D 26
		if (thflags&TH_RST) {
E 26
I 26
D 31
		if (tiflags&TH_RST) {
E 26
D 30
			tcp_error(tp, ENETRESET);
			tcp_detach(tp);				/* 70 */
E 22
E 11
			tp->t_state = CLOSED;
E 30
I 30
			tcp_drop(tp, ENETRESET);
E 30
D 26
			goto badseg;
E 26
I 26
			goto bad;
E 31
I 31
		if (tiflags & TH_RST) {
D 65
			if (tiflags & TH_ACK)
E 65
I 65
D 88
			if (tiflags & TH_ACK) {
E 65
D 33
				tcp_drop(tp, ENETRESET);
E 33
I 33
D 43
				tcp_drop(tp, ECONNRESET);
E 43
I 43
				tcp_drop(tp, ECONNREFUSED);
I 65
				tp = 0;
			}
E 88
I 88
			if (tiflags & TH_ACK)
				tp = tcp_drop(tp, ECONNREFUSED);
E 88
E 65
E 43
E 33
			goto drop;
E 31
E 26
		}
D 26
		goto goodseg;
E 26
I 26
D 31
		goto good;
E 31
I 31
		if ((tiflags & TH_SYN) == 0)
			goto drop;
D 33
		tp->rcv_nxt = ti->ti_seq + 1;
E 33
I 33
D 39
		tp->iss = ti->ti_ack;
		tcp_sendseqinit(tp);
E 39
I 39
D 123
		tp->snd_una = ti->ti_ack;
I 47
		if (SEQ_LT(tp->snd_nxt, tp->snd_una))
			tp->snd_nxt = tp->snd_una;
E 123
I 123
		if (tiflags & TH_ACK) {
			tp->snd_una = ti->ti_ack;
			if (SEQ_LT(tp->snd_nxt, tp->snd_una))
				tp->snd_nxt = tp->snd_una;
		}
E 123
E 47
I 40
		tp->t_timer[TCPT_REXMT] = 0;
I 130
D 131
		/*
		 * If we didn't have to retransmit,
		 * set the initial estimate of srtt.
		 * Set the variance to half the rtt
		 * (so our first retransmit happens at 2*rtt).
		 */
		if (tp->t_rtt) {
			tp->t_srtt = tp->t_rtt << 3;
			tp->t_rttvar = tp->t_rtt << 1;
			tp->t_rtt = 0;
			tp->t_rxtshift = 0;
			TCPT_RANGESET(tp->t_rxtcur, 
			    ((tp->t_srtt >> 2) + tp->t_rttvar) >> 1,
			    TCPTV_MIN, TCPTV_REXMTMAX);
		}
E 131
E 130
E 40
E 39
E 33
		tp->irs = ti->ti_seq;
D 33
		tp->snd_una = ti->ti_seq;
		if (SEQ_GT(tp->snd_una, tp->iss)) {
E 33
I 33
		tcp_rcvseqinit(tp);
		tp->t_flags |= TF_ACKNOW;
D 35
		if (SEQ_GT(tp->snd_una, tp->iss))
E 35
I 35
D 123
		if (SEQ_GT(tp->snd_una, tp->iss)) {
E 123
I 123
		if (tiflags & TH_ACK && SEQ_GT(tp->snd_una, tp->iss)) {
E 123
I 122
			tcpstat.tcps_connects++;
E 122
I 42
D 48
			so->so_state |= SS_CONNAWAITING;
E 48
I 48
D 73
			if (so->so_options & SO_ACCEPTCONN)
				so->so_state |= SS_CONNAWAITING;
E 73
E 48
E 42
I 40
			soisconnected(so);
E 40
E 35
E 33
			tp->t_state = TCPS_ESTABLISHED;
I 103
			tp->t_maxseg = MIN(tp->t_maxseg, tcp_mss(tp));
E 103
D 33
			tp->t_flags |= TF_OWEACK;
			goto step6;
E 33
I 33
D 35
		else
E 35
I 35
			(void) tcp_reass(tp, (struct tcpiphdr *)0);
I 131
			/*
			 * if we didn't have to retransmit the SYN,
			 * use its rtt as our initial srtt & rtt var.
			 */
			if (tp->t_rtt) {
				tp->t_srtt = tp->t_rtt << 3;
				tp->t_rttvar = tp->t_rtt << 1;
				TCPT_RANGESET(tp->t_rxtcur, 
				    ((tp->t_srtt >> 2) + tp->t_rttvar) >> 1,
				    TCPTV_MIN, TCPTV_REXMTMAX);
				tp->t_rtt = 0;
			}
E 131
I 39
D 42
			tp->snd_wl1 = ti->ti_seq;
E 42
E 39
		} else
E 35
			tp->t_state = TCPS_SYN_RECEIVED;
I 40
D 41
printf("tcp_input: out of SYN_SENT: ");
E 41
E 40
D 122
		goto trimthenstep6;
E 122

trimthenstep6:
		/*
D 39
		 * If had syn, advance ti->ti_seq to correspond
		 * to first data byte.
		 */
		if (tiflags & TH_SYN)
			ti->ti_seq++;

		/*
E 39
I 39
		 * Advance ti->ti_seq to correspond to first data byte.
E 39
		 * If data, trim to stay within window,
		 * dropping FIN if necessary.
		 */
I 39
		ti->ti_seq++;
E 39
		if (ti->ti_len > tp->rcv_wnd) {
			todrop = ti->ti_len - tp->rcv_wnd;
I 136
#if BSD>=43
E 136
			m_adj(m, -todrop);
I 136
#else
			/* XXX work around 4.2 m_adj bug */
			if (m->m_len) {
				m_adj(m, -todrop);
			} else {
				/* skip tcp/ip header in first mbuf */
				m_adj(m->m_next, -todrop);
			}
#endif
E 136
			ti->ti_len = tp->rcv_wnd;
D 116
			ti->ti_flags &= ~TH_FIN;
E 116
I 116
			tiflags &= ~TH_FIN;
I 122
			tcpstat.tcps_rcvpackafterwin++;
			tcpstat.tcps_rcvbyteafterwin += todrop;
E 122
E 116
E 33
		}
I 42
		tp->snd_wl1 = ti->ti_seq - 1;
I 116
		tp->rcv_up = ti->ti_seq;
E 116
E 42
I 40
D 41
printf("ti->ti_len %d\n", ti->ti_len);
pseqno(tp);
E 41
E 40
D 33
		tp->t_state = TCPS_SYN_RECEIVED;
		tcp_reflect(ti, tp->iss, tp->rcv_nxt, TH_SYN|TH_ACK);
		break;
E 33
I 33
		goto step6;
E 33
	}
E 31
E 26

D 31
	default:
D 22
        	if ((n->th_flags&TH_RST) == 0)
E 22
I 22
D 26
        	if ((thflags&TH_RST) == 0)
E 26
I 26
        	if ((tiflags&TH_RST) == 0)
E 26
E 22
			goto common;
D 24
		if (n->t_seq < tp->rcv_nxt)		/* bad rst */
E 24
I 24
D 26
		if (n->ti_seq < tp->rcv_nxt)		/* bad rst */
E 24
			goto badseg;				/* 69 */
E 26
I 26
		if (ti->ti_seq < tp->rcv_nxt)		/* bad rst */
			goto bad;				/* 69 */
E 26
		switch (tp->t_state) {
E 31
I 31
	/*
I 100
D 122
	 * If data is received on a connection after the
	 * user processes are gone, then RST the other end.
	 */
	if ((so->so_state & SS_NOFDREF) && tp->t_state > TCPS_CLOSE_WAIT &&
	    ti->ti_len) {
		tp = tcp_close(tp);
		goto dropwithreset;
	}

	/*
E 122
E 100
	 * States other than LISTEN or SYN_SENT.
	 * First check that at least some bytes of segment are within 
D 122
	 * receive window.
E 122
I 122
	 * receive window.  If segment begins before rcv_nxt,
	 * drop leading data (and SYN); if nothing left, just ack.
E 122
	 */
I 122
	todrop = tp->rcv_nxt - ti->ti_seq;
	if (todrop > 0) {
		if (tiflags & TH_SYN) {
			tiflags &= ~TH_SYN;
			ti->ti_seq++;
			if (ti->ti_urp > 1) 
				ti->ti_urp--;
			else
				tiflags &= ~TH_URG;
			todrop--;
		}
		if (todrop > ti->ti_len ||
		    todrop == ti->ti_len && (tiflags&TH_FIN) == 0) {
I 127
D 138
#ifdef TCP_COMPAT_42
E 138
I 138
			tcpstat.tcps_rcvduppack++;
			tcpstat.tcps_rcvdupbyte += ti->ti_len;
E 138
			/*
D 138
			 * Don't toss RST in response to 4.2-style keepalive.
E 138
I 138
			 * If segment is just one to the left of the window,
			 * check two special cases:
			 * 1. Don't toss RST in response to 4.2-style keepalive.
			 * 2. If the only thing to drop is a FIN, we can drop
			 *    it, but check the ACK or we will get into FIN
			 *    wars if our FINs crossed (both CLOSING).
			 * In either case, send ACK to resynchronize,
			 * but keep on processing for RST or ACK.
E 138
			 */
D 138
			if (ti->ti_seq == tp->rcv_nxt - 1 && tiflags & TH_RST)
				goto do_rst;
E 138
I 138
			if ((tiflags & TH_FIN && todrop == ti->ti_len + 1)
#ifdef TCP_COMPAT_42
			  || (tiflags & TH_RST && ti->ti_seq == tp->rcv_nxt - 1)
E 138
#endif
E 127
D 138
			tcpstat.tcps_rcvduppack++;
			tcpstat.tcps_rcvdupbyte += ti->ti_len;
D 130
			goto dropafterack;
E 130
I 130
			todrop = ti->ti_len;
I 131
			tiflags &= ~TH_FIN;
E 131
			tp->t_flags |= TF_ACKNOW;
E 138
I 138
			   ) {
				todrop = ti->ti_len;
				tiflags &= ~TH_FIN;
				tp->t_flags |= TF_ACKNOW;
			} else
				goto dropafterack;
E 138
		} else {
			tcpstat.tcps_rcvpartduppack++;
			tcpstat.tcps_rcvpartdupbyte += todrop;
E 130
		}
D 130
		tcpstat.tcps_rcvpartduppack++;
		tcpstat.tcps_rcvpartdupbyte += todrop;
E 130
		m_adj(m, todrop);
		ti->ti_seq += todrop;
		ti->ti_len -= todrop;
		if (ti->ti_urp > todrop)
			ti->ti_urp -= todrop;
		else {
			tiflags &= ~TH_URG;
			ti->ti_urp = 0;
		}
	}

I 133
	/*
D 138
	 * If new data is received on a connection after the
E 138
I 138
	 * If new data are received on a connection after the
E 138
	 * user processes are gone, then RST the other end.
	 */
	if ((so->so_state & SS_NOFDREF) &&
	    tp->t_state > TCPS_CLOSE_WAIT && ti->ti_len) {
		tp = tcp_close(tp);
		tcpstat.tcps_rcvafterclose++;
		goto dropwithreset;
	}

E 133
E 122
D 135
	if (tp->rcv_wnd == 0) {
		/*
		 * If window is closed can only take segments at
D 39
		 * window edge, and have to drop data and EOL from
E 39
I 39
		 * window edge, and have to drop data and PUSH from
E 39
		 * incoming segments.
I 122
D 133
		 *
		 * If new data is received on a connection after the
		 * user processes are gone, then RST the other end.
E 133
E 122
		 */
D 44
		if (tp->rcv_nxt != ti->ti_seq)
E 44
I 44
D 45
		if (tp->rcv_nxt != ti->ti_seq) {
printf("wnd closed, not at edge\n");
E 45
I 45
D 122
		if (tp->rcv_nxt != ti->ti_seq)
E 122
I 122
D 133
		if ((so->so_state & SS_NOFDREF) &&
		    tp->t_state > TCPS_CLOSE_WAIT && ti->ti_len) {
			tp = tcp_close(tp);
			tcpstat.tcps_rcvafterclose++;
			goto dropwithreset;
		}
E 133
		if (tp->rcv_nxt != ti->ti_seq) {
			tcpstat.tcps_rcvpackafterwin++;
E 135
I 135
	/*
	 * If segment ends after window, drop trailing data
	 * (and PUSH and FIN); if nothing left, just ACK.
	 */
	todrop = (ti->ti_seq+ti->ti_len) - (tp->rcv_nxt+tp->rcv_wnd);
	if (todrop > 0) {
		tcpstat.tcps_rcvpackafterwin++;
		if (todrop >= ti->ti_len) {
E 135
			tcpstat.tcps_rcvbyteafterwin += ti->ti_len;
E 122
E 45
E 44
D 135
			goto dropafterack;
I 122
		}
E 122
I 44
D 45
		}
E 45
E 44
D 33
		if (tp->ti_len > 0) {
			tp->ti_len = 0;
			tp->ti_flags &= ~(TH_EOL|TH_FIN);
E 33
I 33
		if (ti->ti_len > 0) {
I 122
			if (ti->ti_len == 1) 
				tcpstat.tcps_rcvwinprobe++;
			else {
				tcpstat.tcps_rcvpackafterwin++;
				tcpstat.tcps_rcvbyteafterwin += ti->ti_len;
E 135
I 135
			/*
			 * If a new connection request is received
			 * while in TIME_WAIT, drop the old connection
			 * and start over if the sequence numbers
			 * are above the previous ones.
			 */
			if (tiflags & TH_SYN &&
			    tp->t_state == TCPS_TIME_WAIT &&
			    SEQ_GT(ti->ti_seq, tp->rcv_nxt)) {
				iss = tp->rcv_nxt + TCP_ISSINCR;
				(void) tcp_close(tp);
				goto findpcb;
E 135
			}
E 122
I 53
D 135
			m_adj(m, ti->ti_len);
E 53
			ti->ti_len = 0;
D 116
			ti->ti_flags &= ~(TH_PUSH|TH_FIN);
E 116
I 116
			tiflags &= ~(TH_PUSH|TH_FIN);
E 116
E 33
		}
I 40
D 41
printf("tcp_input %x: window 0, drop text and FIN\n", tp);
E 41
E 40
	} else {
		/*
D 39
		 * If segment begins before rcv_next, drop leading
E 39
I 39
D 122
		 * If segment begins before rcv_nxt, drop leading
E 39
		 * data (and SYN); if nothing left, just ack.
		 */
D 53
		if (SEQ_GT(tp->rcv_nxt, ti->ti_seq)) {
D 33
			tcpseq_t todrop = tp->rcv_nxt - ti->ti_seq;
E 33
I 33
			todrop = tp->rcv_nxt - ti->ti_seq;
E 53
I 53
		todrop = tp->rcv_nxt - ti->ti_seq;
		if (todrop > 0) {
E 53
I 40
D 41
printf("tcp_input %x: drop %d dup bytes\n", tp, todrop);
E 41
E 40
			if (tiflags & TH_SYN) {
I 45
				tiflags &= ~TH_SYN;
I 53
D 116
				ti->ti_flags &= ~TH_SYN;
E 116
E 53
E 45
				ti->ti_seq++;
				if (ti->ti_urp > 1) 
					ti->ti_urp--;
				else
					tiflags &= ~TH_URG;
				todrop--;
			}
E 33
D 44
			if (todrop > ti->ti_len)
E 44
I 44
D 45
			if (todrop > ti->ti_len) {
printf("window open but outside\n");
E 45
I 45
D 62
			if (todrop > ti->ti_len)
E 62
I 62
			if (todrop > ti->ti_len ||
			    todrop == ti->ti_len && (tiflags&TH_FIN) == 0)
E 62
E 45
E 44
				goto dropafterack;
I 44
D 45
}
E 45
E 44
			m_adj(m, todrop);
			ti->ti_seq += todrop;
			ti->ti_len -= todrop;
D 33
			ti->ti_flags &= ~TH_SYN;
E 33
I 33
			if (ti->ti_urp > todrop)
				ti->ti_urp -= todrop;
			else {
				tiflags &= ~TH_URG;
D 53
				/* ti->ti_flags &= ~TH_URG; */
				/* ti->ti_urp = 0; */
E 53
I 53
D 116
				ti->ti_flags &= ~TH_URG;
E 116
				ti->ti_urp = 0;
E 53
			}
D 53
			/* tiflags &= ~TH_SYN; */
			/* ti->ti_flags &= ~TH_SYN; */
E 53
E 33
		}
		/*
E 122
		 * If segment ends after window, drop trailing data
D 33
		 * (and EOL and FIN); if there would be nothing left, just ack.
E 33
I 33
		 * (and PUSH and FIN); if nothing left, just ACK.
E 33
		 */
D 53
		if (SEQ_GT(ti->ti_seq+ti->ti_len, tp->rcv_nxt+tp->rcv_wnd)) {
D 33
			tcpseq_t todrop =
E 33
I 33
			todrop =
E 33
			     ti->ti_seq+ti->ti_len - (tp->rcv_nxt+tp->rcv_wnd);
E 53
I 53
		todrop = (ti->ti_seq+ti->ti_len) - (tp->rcv_nxt+tp->rcv_wnd);
		if (todrop > 0) {
E 53
D 44
			if (todrop > ti->ti_len)
E 44
I 44
D 45
			if (todrop > ti->ti_len) {
printf("segment outside window\n");
E 45
I 45
D 62
			if (todrop > ti->ti_len)
E 62
I 62
D 122
			if (todrop >= ti->ti_len)
E 122
I 122
			if (todrop >= ti->ti_len) {
				/*
				 * If a new connection request is received
				 * while in TIME_WAIT, drop the old connection
				 * and start over if the sequence numbers
				 * are above the previous ones.
				 */
				if (tiflags & TH_SYN &&
				    tp->t_state == TCPS_TIME_WAIT &&
				    SEQ_GT(ti->ti_seq, tp->rcv_nxt)) {
					iss = tp->rcv_nxt + TCP_ISSINCR;
					(void) tcp_close(tp);
					goto findpcb;
				}
				if (todrop == 1) 
					tcpstat.tcps_rcvwinprobe++;
				else {
					tcpstat.tcps_rcvpackafterwin++;
D 124
					tcpstat.tcps_rcvbyteafterwin += todrop;
E 124
I 124
					tcpstat.tcps_rcvbyteafterwin += ti->ti_len;
E 124
				}
E 135
I 135
			/*
			 * If window is closed can only take segments at
			 * window edge, and have to drop data and PUSH from
			 * incoming segments.  Continue processing, but
			 * remember to ack.  Otherwise, drop segment
			 * and ack.
			 */
			if (tp->rcv_wnd == 0 && ti->ti_seq == tp->rcv_nxt) {
				tp->t_flags |= TF_ACKNOW;
				tcpstat.tcps_rcvwinprobe++;
			} else
E 135
E 122
E 62
E 45
E 44
				goto dropafterack;
I 122
D 135
			}
			tcpstat.tcps_rcvpackafterwin++;
E 135
I 135
		} else
E 135
			tcpstat.tcps_rcvbyteafterwin += todrop;
I 136
#if BSD>=43
E 136
E 122
I 44
D 45
}
E 45
E 44
D 135
			m_adj(m, -todrop);
			ti->ti_len -= todrop;
D 33
			ti->ti_flags &= ~(TH_EOL|TH_FIN);
E 33
I 33
D 116
			ti->ti_flags &= ~(TH_PUSH|TH_FIN);
E 116
I 116
			tiflags &= ~(TH_PUSH|TH_FIN);
E 116
E 33
		}
E 135
I 135
		m_adj(m, -todrop);
I 136
#else
		/* XXX work around m_adj bug */
		if (m->m_len) {
			m_adj(m, -todrop);
		} else {
			/* skip tcp/ip header in first mbuf */
			m_adj(m->m_next, -todrop);
		}
#endif
E 136
		ti->ti_len -= todrop;
		tiflags &= ~(TH_PUSH|TH_FIN);
E 135
D 100
	}
E 31

D 31
		case L_SYN_RCVD:
D 26
			if (ack_ok(tp, n) == 0)
				goto badseg;			/* 69 */
E 26
I 26
			if (ack_ok(tp, ti) == 0)
				goto bad;			/* 69 */
E 26
			tp->t_rexmt = 0;
			tp->t_rexmttl = 0;
			tp->t_persist = 0;
D 22
			h_free(tp->t_ucb->uc_host);
E 22
I 22
D 23
			h_free(tp->t_host);
			tp->t_host = 0;
E 23
I 23
D 25
			h_free(inp->inp_fhost);
E 25
I 25
D 27
			in_hostfree(inp->inp_fhost);
E 25
			inp->inp_fhost = 0;
E 27
I 27
			inp->inp_faddr.s_addr = 0;
E 31
I 31
	/*
I 55
D 85
	 * If a segment is received on a connection after the
E 85
I 85
	 * If data is received on a connection after the
E 85
	 * user processes are gone, then RST the other end.
	 */
D 73
	if (so->so_state & SS_USERGONE) {
E 73
I 73
D 85
	if (so->so_state & SS_NOFDREF) {
E 85
I 85
D 87
	if ((so->so_state & SS_NOFDREF) && ti->ti_len) {
E 87
I 87
D 88
	if (so->so_state & SS_NOFDREF && tp->t_state > TCPS_CLOSE_WAIT &&
E 88
I 88
	if ((so->so_state & SS_NOFDREF) && tp->t_state > TCPS_CLOSE_WAIT &&
E 88
	    ti->ti_len) {
E 87
E 85
E 73
D 88
		tcp_close(tp);
I 63
		tp = 0;
E 88
I 88
		tp = tcp_close(tp);
E 88
E 63
		goto dropwithreset;
E 100
	}

I 127
D 138
#ifdef TCP_COMPAT_42
do_rst:
#endif
E 138
E 127
	/*
E 55
	 * If the RST bit is set examine the state:
	 *    SYN_RECEIVED STATE:
	 *	If passive open, return to LISTEN state.
	 *	If active open, inform user that connection was refused.
	 *    ESTABLISHED, FIN_WAIT_1, FIN_WAIT2, CLOSE_WAIT STATES:
	 *	Inform user that connection was reset, and close tcb.
	 *    CLOSING, LAST_ACK, TIME_WAIT STATES
	 *	Close the tcb.
	 */
	if (tiflags&TH_RST) switch (tp->t_state) {
D 43
		
E 43
I 43

E 43
	case TCPS_SYN_RECEIVED:
D 73
		if (inp->inp_socket->so_options & SO_ACCEPTCONN) {
E 31
E 27
E 23
E 22
D 33
			tp->t_state = LISTEN;
D 26
			goto badseg;
E 26
I 26
D 31
			goto bad;
E 26

		default:
D 11
			t_close(tp, URESET);			/* 66 */
E 11
I 11
D 22
			tcp_close(tp, URESET);			/* 66 */
E 22
I 22
D 30
			tcp_error(tp, ENETRESET);
			tcp_detach(tp);				/* 66 */
E 22
E 11
			tp->t_state = CLOSED;
E 30
I 30
			tcp_drop(tp, ENETRESET);
E 30
D 26
			goto badseg;
E 26
I 26
			goto bad;
E 31
I 31
			inp->inp_fhost->s_addr = 0;
E 33
I 33
D 43
			tp->t_state = TCPS_LISTEN;
I 40
			tp->t_timer[TCPT_KEEP] = 0;
E 43
I 43
			/* a miniature tcp_close, but invisible to user */
E 43
			(void) m_free(dtom(tp->t_template));
D 43
			tp->t_template = 0;
E 40
D 39
			inp->inp_faddr.s_addr = 0;
E 39
I 39
			in_pcbdisconnect(inp);
E 43
I 43
			(void) m_free(dtom(tp));
			inp->inp_ppcb = 0;
			tp = tcp_newtcpcb(inp);
			tp->t_state = TCPS_LISTEN;
I 57
			inp->inp_faddr.s_addr = 0;
			inp->inp_fport = 0;
			inp->inp_laddr.s_addr = 0;	/* not quite right */
I 65
			tp = 0;
E 65
E 57
E 43
E 39
E 33
			goto drop;
E 31
E 26
		}
E 73
D 31
		/*NOTREACHED*/
E 31
I 31
D 33
		tcp_drop(tp, EREFUSED);
E 33
I 33
D 88
		tcp_drop(tp, ECONNREFUSED);
I 65
		tp = 0;
E 88
I 88
D 138
		tp = tcp_drop(tp, ECONNREFUSED);
E 88
E 65
E 33
		goto drop;
E 138
I 138
		so->so_error = ECONNREFUSED;
		goto close;
E 138
E 31

D 31
	case SYN_RCVD:
common:
D 26
		if (ack_ok(tp, n) == 0) {
D 11
			send_rst(tp, n);			/* 74 */
E 11
I 11
			tcp_sndrst(tp, n);			/* 74 */
E 11
			goto badseg;
E 26
I 26
		if (ack_ok(tp, ti) == 0) {
			tcp_sndrst(tp, ti);			/* 74 */
			goto bad;
E 26
		}
D 24
		if (syn_ok(tp, n) && n->t_seq != tp->irs) {
E 24
I 24
D 26
		if (syn_ok(tp, n) && n->ti_seq != tp->irs) {
E 26
I 26
		if ((tiflags&TH_SYN) == 0 && ti->ti_seq != tp->irs) {
E 26
E 24
D 11
			send_null(tp);				/* 74 */
E 11
I 11
D 13
			tcp_sndnull(tp);				/* 74 */
E 13
I 13
			tcp_sndnull(tp);			/* 74 */
E 13
E 11
D 26
			goto badseg;
E 26
I 26
			goto bad;
E 26
		}
D 26
		goto goodseg;
E 26
I 26
		goto good;
E 31
I 31
	case TCPS_ESTABLISHED:
	case TCPS_FIN_WAIT_1:
	case TCPS_FIN_WAIT_2:
	case TCPS_CLOSE_WAIT:
D 88
		tcp_drop(tp, ECONNRESET);
I 65
		tp = 0;
E 88
I 88
D 138
		tp = tcp_drop(tp, ECONNRESET);
E 138
I 138
		so->so_error = ECONNRESET;
	close:
		tp->t_state = TCPS_CLOSED;
		tcpstat.tcps_drops++;
		tp = tcp_close(tp);
E 138
E 88
E 65
		goto drop;

	case TCPS_CLOSING:
	case TCPS_LAST_ACK:
	case TCPS_TIME_WAIT:
D 88
		tcp_close(tp);
I 65
		tp = 0;
E 88
I 88
		tp = tcp_close(tp);
E 88
E 65
		goto drop;
E 31
E 26
	}
D 26
badseg:
	m_freem(mp);
E 26
I 26
D 31
bad:
	m_freem(m);
E 26
	return;
E 31

D 26
goodseg:
E 26
I 26
D 31
good:
E 31
E 26
D 22
#ifdef notdef
I 13
	/* DO SOMETHING ABOUT UNACK!!! */
E 22
E 13
	/*
D 31
	 * Defer processing if no buffer space for this connection.
E 31
I 31
	 * If a SYN is in the window, then this is an
	 * error and we send an RST and drop the connection.
E 31
	 */
D 22
	up = tp->t_ucb;
D 7
	if ((int)up->uc_rcv - (int)up->uc_rsize <= 0
E 7
I 7
	if (up->uc_rcc > up->uc_rhiwat && 
E 7
D 8
	     && n->t_len != 0 && netcb.n_bufs < netcb.n_lowat) {
E 8
I 8
	     && n->t_len != 0 && mbstat.m_bufs < mbstat.m_lowat) {
E 22
I 22
D 23
	so = tp->t_socket;
E 23
I 23
D 31
	so = inp->inp_socket;
E 23
	if (so->so_rcv.sb_cc >= so->so_rcv.sb_hiwat &&
D 24
	     n->t_len != 0 && mbstat.m_bufs < mbstat.m_lowat) {
E 24
I 24
D 26
	     n->ti_len != 0 && mbstat.m_bufs < mbstat.m_lowat) {
E 26
I 26
	     ti->ti_len != 0 && mbstat.m_bufs < mbstat.m_lowat) {
E 26
E 24
/*
E 22
E 8
D 26
		mp->m_act = (struct mbuf *)0;
E 26
I 26
		m->m_act = (struct mbuf *)0;
E 26
D 22
		if ((m = tp->t_rcv_unack) != NULL) {
E 22
I 22
		if ((m = tp->seg_unack) != NULL) {
E 22
			while (m->m_act != NULL)
				m = m->m_act;
D 26
			m->m_act = mp;
E 26
I 26
			m->m_act = m0;
E 26
		} else
D 22
			tp->t_rcv_unack = mp;
E 22
I 22
D 26
			tp->seg_unack = mp;
E 26
I 26
			tp->seg_unack = m0;
E 26
*/
D 26
		m_freem(mp);
E 26
I 26
		m_freem(m0);
E 26
E 22
D 7

E 7
		return;
E 31
I 31
	if (tiflags & TH_SYN) {
D 33
		tcp_drop(tp, ECONNRESET);
		goto sendreset;
E 33
I 33
D 39
		tcp_drop(tp, ECONNABORTED);
E 39
I 39
D 88
		tcp_drop(tp, ECONNRESET);
I 63
		tp = 0;
E 88
I 88
		tp = tcp_drop(tp, ECONNRESET);
E 88
E 63
E 39
		goto dropwithreset;
E 33
E 31
	}
D 22
#endif
E 22

	/*
D 31
	 * Discard ip header, and do tcp input processing.
E 31
I 31
	 * If the ACK bit is off we drop the segment and return.
E 31
	 */
D 26
	hlen += sizeof(struct ip);
	mp->m_off += hlen;
	mp->m_len -= hlen;
E 26
I 26
D 31
	off += sizeof (struct ip);
	m->m_off += off;
	m->m_len -= off;
E 26
	nstate = tp->t_state;
	tp->tc_flags &= ~TC_NET_KEEP;
I 21
#ifdef KPROF
E 21
	acounts[tp->t_state][INRECV]++;
I 21
#endif
E 21
#ifdef TCPDEBUG
D 22
	if ((tp->t_ucb->uc_flags & UDEBUG) || tcpconsdebug) {
E 22
I 22
	if ((tp->t_socket->so_options & SO_DEBUG) || tcpconsdebug) {
E 22
D 3
		tdb.td_tod = time;
		tdb.td_tcb = tp;
		tdb.td_old = nstate;
		tdb.td_inp = INRECV;
		tdb.td_tim = 0;
		tdb.td_sno = n->t_seq;
		tdb.td_ano = n->t_ackno;
		tdb.td_wno = n->t_win;
		tdb.td_lno = n->t_len;
		tdb.td_flg = n->th_flags;
E 3
I 3
D 26
		tdb_setup(tp, n, INRECV, &tdb);
E 26
I 26
		tdb_setup(tp, ti, INRECV, &tdb);
E 26
E 3
	} else
		tdb.td_tod = 0;
#endif
E 31
I 31
D 33
	if ((tiflags & TI_ACK) == 0)
E 33
I 33
	if ((tiflags & TH_ACK) == 0)
E 33
		goto drop;
	
	/*
	 * Ack processing.
	 */
E 31
	switch (tp->t_state) {

D 31
	case LISTEN:
D 26
		if (!syn_ok(tp, n) ||
D 22
		    ((tp->t_ucb->uc_host = h_make(&n->t_s)) == 0)) {
E 22
I 22
D 23
		    ((tp->t_host = h_make(&n->t_s)) == 0)) {
E 23
I 23
D 24
		    ((inp->inp_lhost = in_hmake(&n->t_s)) == 0)) {
E 24
I 24
D 25
		    ((inp->inp_lhost = in_hmake(&n->ti_src)) == 0)) {
E 25
I 25
		    ((inp->inp_lhost = in_hostalloc(&n->ti_src)) == 0)) {
E 26
I 26
D 27
		if ((tiflags&TH_SYN) == 0 ||
		    ((inp->inp_lhost = in_hostalloc(&ti->ti_src)) == 0)) {
E 27
I 27
		tcp_sockaddr.sin_addr = ti->ti_src;
		tcp_sockaddr.sin_port = ti->ti_sport;
		if ((tiflags&TH_SYN) == 0 || in_pcbsetpeer(inp, &tcp_sockaddr)) {
E 27
E 26
E 25
E 24
E 23
E 22
			nstate = EFAILEC;
			goto done;
		}
D 23
		tp->t_fport = n->t_src;
E 23
I 23
D 24
		inp->inp_fport = n->t_src;
E 24
I 24
D 26
		inp->inp_fport = n->ti_sport;
E 26
I 26
D 27
		inp->inp_fport = ti->ti_sport;
E 27
E 26
E 24
E 23
I 2
D 20
		tp->t_ucb->uc_template = tcp_template(tp);
E 20
I 20
		tp->t_template = tcp_template(tp);
E 20
E 2
D 11
		rcv_ctldat(tp, n, 1);
E 11
I 11
D 26
		tcp_ctldat(tp, n, 1);
E 26
I 26
		tcp_ctldat(tp, ti, 1);
E 26
E 11
		if (tp->tc_flags&TC_FIN_RCVD) {
			tp->t_finack = T_2ML;			/* 3 */
D 30
			tp->tc_flags &= ~TC_WAITED_2_ML;
E 30
			nstate = CLOSE_WAIT;
		} else {
D 22
			tp->t_init = T_INIT / 2;		/* 4 */
E 22
I 22
D 23
/* XXX */		/* tp->t_init = T_INIT / 2; */		/* 4 */
E 23
I 23
			tp->t_init = T_INIT / 2;		/* 4 */
E 23
E 22
			nstate = L_SYN_RCVD;
		}
		goto done;
E 31
I 31
	/*
	 * In SYN_RECEIVED state if the ack ACKs our SYN then enter
D 125
	 * ESTABLISHED state and continue processing, othewise
E 125
I 125
	 * ESTABLISHED state and continue processing, otherwise
E 125
	 * send an RST.
	 */
	case TCPS_SYN_RECEIVED:
D 33
		if (SEQ_LEQ(tp->snd_una, ti->ti_ack) &&
		    SEQ_LEQ(ti->ti_ack, tp->snd_nxt))
			tp->t_state = TCPS_ESTABLISHED;
		else
			goto sendreset;
		/* fall into next case, below... */
E 33
I 33
		if (SEQ_GT(tp->snd_una, ti->ti_ack) ||
D 39
		    SEQ_GT(ti->ti_ack, tp->snd_nxt))
E 39
I 39
		    SEQ_GT(ti->ti_ack, tp->snd_max))
E 39
			goto dropwithreset;
I 40
D 125
		tp->snd_una++;			/* SYN acked */
I 47
		if (SEQ_LT(tp->snd_nxt, tp->snd_una))
			tp->snd_nxt = tp->snd_una;
E 47
		tp->t_timer[TCPT_REXMT] = 0;
E 125
I 122
		tcpstat.tcps_connects++;
E 122
I 42
D 48
		so->so_state |= SS_CONNAWAITING;
E 48
I 48
D 73
		if (so->so_options & SO_ACCEPTCONN)
			so->so_state |= SS_CONNAWAITING;
E 73
E 48
E 42
E 40
		soisconnected(so);
		tp->t_state = TCPS_ESTABLISHED;
I 103
		tp->t_maxseg = MIN(tp->t_maxseg, tcp_mss(tp));
E 103
I 35
		(void) tcp_reass(tp, (struct tcpiphdr *)0);
I 39
D 40
		tp->snd_wl1 = tp->ti_seq - 1;
E 40
I 40
		tp->snd_wl1 = ti->ti_seq - 1;
D 41
printf("tcp_input: to ESTAB:\n"); pseqno(tp);
E 41
E 40
E 39
E 35
		/* fall into ... */
E 33
E 31

D 31
	case SYN_SENT:
D 26
		if (!syn_ok(tp, n)) {
E 26
I 26
		if (!syn_ok(tp, ti)) {
E 26
			nstate = EFAILEC;
			goto done;
E 31
I 31
	/*
	 * In ESTABLISHED state: drop duplicate ACKs; ACK out of range
	 * ACKs.  If the ack is in the range
D 39
	 *	tp->snd_una < ti->ti_ack <= tp->snd_nxt
E 39
I 39
	 *	tp->snd_una < ti->ti_ack <= tp->snd_max
E 39
	 * then advance tp->snd_una to ti->ti_ack and drop
	 * data from the retransmission queue.  If this ACK reflects
	 * more up to date window information we update our window information.
	 */
	case TCPS_ESTABLISHED:
	case TCPS_FIN_WAIT_1:
	case TCPS_FIN_WAIT_2:
	case TCPS_CLOSE_WAIT:
	case TCPS_CLOSING:
I 40
	case TCPS_LAST_ACK:
	case TCPS_TIME_WAIT:
E 40
I 33
D 122
#define	ourfinisacked	(acked > 0)
E 122

E 33
D 40
		if (SEQ_LT(ti->ti_ack, tp->snd_una))
E 40
I 40
D 122
		if (SEQ_LEQ(ti->ti_ack, tp->snd_una))
E 122
I 122
		if (SEQ_LEQ(ti->ti_ack, tp->snd_una)) {
D 131
			if (ti->ti_len == 0)
E 131
I 131
			if (ti->ti_len == 0 && ti->ti_win == tp->snd_wnd) {
E 131
				tcpstat.tcps_rcvdupack++;
I 131
				/*
				 * If we have outstanding data (not a
				 * window probe), this is a completely
				 * duplicate ack (ie, window info didn't
				 * change), the ack is the biggest we've
				 * seen and we've seen exactly our rexmt
				 * threshhold of them, assume a packet
				 * has been dropped and retransmit it.
				 * Kludge snd_nxt & the congestion
				 * window so we send only this one
D 132
				 * packet.  Close the congestion
				 * window to half its current size
				 * to prevent a restart burst if this
				 * packet fills all the holes in the
				 * receiver's sequence space and she
				 * advertises a fully open window on
				 * the next real ack.
E 132
I 132
				 * packet.  If this packet fills the
				 * only hole in the receiver's seq.
				 * space, the next real ack will fully
				 * open our window.  This means we
				 * have to do the usual slow-start to
				 * not overwhelm an intermediate gateway
				 * with a burst of packets.  Leave
				 * here with the congestion window set
				 * to allow 2 packets on the next real
				 * ack and the exp-to-linear thresh
				 * set for half the current window
				 * size (since we know we're losing at
				 * the current window size).
E 132
				 */
				if (tp->t_timer[TCPT_REXMT] == 0 ||
				    ti->ti_ack != tp->snd_una)
					tp->t_dupacks = 0;
				else if (++tp->t_dupacks == tcprexmtthresh) {
					tcp_seq onxt = tp->snd_nxt;
D 132
					u_short cwnd = tp->snd_cwnd;
E 132
I 132
					u_int win =
					    MIN(tp->snd_wnd, tp->snd_cwnd) / 2 /
						tp->t_maxseg;
E 132

I 132
					if (win < 2)
						win = 2;
					tp->snd_ssthresh = win * tp->t_maxseg;

E 132
					tp->t_timer[TCPT_REXMT] = 0;
					tp->t_rtt = 0;
					tp->snd_nxt = ti->ti_ack;
					tp->snd_cwnd = tp->t_maxseg;
					(void) tcp_output(tp);

D 132
					if (cwnd >= 4 * tp->t_maxseg)
						tp->snd_cwnd = cwnd / 2;
E 132
					if (SEQ_GT(onxt, tp->snd_nxt))
						tp->snd_nxt = onxt;
					goto drop;
				}
			} else
				tp->t_dupacks = 0;
E 131
E 122
E 40
			break;
D 39
		if (SEQ_GT(ti->ti_ack, tp->snd_nxt))
E 39
I 39
D 44
		if (SEQ_GT(ti->ti_ack, tp->snd_max))
E 44
I 44
D 45
		if (SEQ_GT(ti->ti_ack, tp->snd_max)) {
printf("ack > snd_max\n");
E 45
I 45
D 122
		if (SEQ_GT(ti->ti_ack, tp->snd_max))
E 122
I 122
		}
I 131
		tp->t_dupacks = 0;
E 131
		if (SEQ_GT(ti->ti_ack, tp->snd_max)) {
			tcpstat.tcps_rcvacktoomuch++;
E 122
E 45
E 44
E 39
			goto dropafterack;
I 122
		}
E 122
I 44
D 45
}
E 45
E 44
D 33
		sbdrop(&so->so_snd, ti->ti_ack - tp->snd_una);
E 33
I 33
		acked = ti->ti_ack - tp->snd_una;
I 122
		tcpstat.tcps_rcvackpack++;
		tcpstat.tcps_rcvackbyte += acked;
E 122
I 55

		/*
		 * If transmit timer is running and timed sequence
		 * number was acked, update smoothed round trip time.
I 130
		 * Since we now have an rtt measurement, cancel the
		 * timer backoff (cf., Phil Karn's retransmit alg.).
		 * Recompute the initial retransmit timer.
E 130
		 */
		if (tp->t_rtt && SEQ_GT(ti->ti_ack, tp->t_rtseq)) {
I 122
			tcpstat.tcps_rttupdated++;
E 122
D 126
			if (tp->t_srtt == 0)
				tp->t_srtt = tp->t_rtt;
			else
				tp->t_srtt =
				    tcp_alpha * tp->t_srtt +
				    (1 - tcp_alpha) * tp->t_rtt;
E 126
I 126
			if (tp->t_srtt != 0) {
				register short delta;

				/*
				 * srtt is stored as fixed point with 3 bits
				 * after the binary point (i.e., scaled by 8).
				 * The following magic is equivalent
				 * to the smoothing algorithm in rfc793
				 * with an alpha of .875
				 * (srtt = rtt/8 + srtt*7/8 in fixed point).
I 131
				 * Adjust t_rtt to origin 0.
E 131
				 */
I 131
D 138
				tp->t_rtt--;
E 131
				delta = tp->t_rtt - (tp->t_srtt >> 3);
E 138
I 138
				delta = tp->t_rtt - 1 - (tp->t_srtt >> 3);
E 138
				if ((tp->t_srtt += delta) <= 0)
					tp->t_srtt = 1;
				/*
D 130
				 * We accumulate a smoothed rtt variance,
E 130
I 130
				 * We accumulate a smoothed rtt variance
				 * (actually, a smoothed mean difference),
E 130
				 * then set the retransmit timer to smoothed
				 * rtt + 2 times the smoothed variance.
D 131
				 * rttvar is strored as fixed point
E 131
I 131
				 * rttvar is stored as fixed point
E 131
				 * with 2 bits after the binary point
				 * (scaled by 4).  The following is equivalent
				 * to rfc793 smoothing with an alpha of .75
				 * (rttvar = rttvar*3/4 + |delta| / 4).
				 * This replaces rfc793's wired-in beta.
				 */
				if (delta < 0)
					delta = -delta;
				delta -= (tp->t_rttvar >> 2);
				if ((tp->t_rttvar += delta) <= 0)
					tp->t_rttvar = 1;
			} else {
				/* 
				 * No rtt measurement yet - use the
				 * unsmoothed rtt.  Set the variance
				 * to half the rtt (so our first
				 * retransmit happens at 2*rtt)
				 */
				tp->t_srtt = tp->t_rtt << 3;
				tp->t_rttvar = tp->t_rtt << 1;
			}
E 126
D 86
/* printf("rtt %d srtt*100 now %d\n", tp->t_rtt, (int)(tp->t_srtt*100)); */
E 86
			tp->t_rtt = 0;
I 130
			tp->t_rxtshift = 0;
			TCPT_RANGESET(tp->t_rxtcur, 
			    ((tp->t_srtt >> 2) + tp->t_rttvar) >> 1,
			    TCPTV_MIN, TCPTV_REXMTMAX);
E 130
		}

E 55
D 40
		if (acked > so->so_snd.sb_cc) {
			sbflush(&so->so_snd);
E 40
I 40
D 41
printf("tcp_input: got ack of %d bytes\n", acked);
E 41
D 46
		if (acked >= so->so_snd.sb_cc) {
E 40
			acked -= so->so_snd.sb_cc;
I 44
			tp->snd_wnd -= so->so_snd.sb_cc;
E 44
I 35
D 40
			/* if acked our FIN is acked */
E 40
I 40
			/* if acked > 0 our FIN is acked */
I 42
D 44
if (so->so_snd.sb_cc)
E 44
E 42
			sbdrop(&so->so_snd, so->so_snd.sb_cc);
E 46
I 46
D 119
		if (ti->ti_ack == tp->snd_max)
E 119
I 119
		/*
		 * If all outstanding data is acked, stop retransmit
		 * timer and remember to restart (more output or persist).
		 * If there is more data to be acked, restart retransmit
D 126
		 * timer.
E 126
I 126
D 130
		 * timer; set to smoothed rtt + 2*rttvar.
E 130
I 130
		 * timer, using current (possibly backed-off) value.
E 130
E 126
		 */
		if (ti->ti_ack == tp->snd_max) {
E 119
E 46
			tp->t_timer[TCPT_REXMT] = 0;
E 40
E 35
D 46
		} else {
I 42
D 44
if (acked)
E 42
			sbdrop(&so->so_snd, acked);
			acked = 0;
E 44
I 44
			if (acked) {
				sbdrop(&so->so_snd, acked);
				tp->snd_wnd -= acked;
				acked = 0;
			}
E 46
I 46
D 119
		else {
E 119
I 119
			needoutput = 1;
D 130
		} else if (tp->t_timer[TCPT_PERSIST] == 0) {
E 119
E 46
E 44
I 40
			TCPT_RANGESET(tp->t_timer[TCPT_REXMT],
D 126
			    tcp_beta * tp->t_srtt, TCPTV_MIN, TCPTV_MAX);
E 126
I 126
			    ((tp->t_srtt >> 2) + tp->t_rttvar) >> 1,
			    TCPTV_MIN, TCPTV_REXMTMAX);
E 126
I 45
D 55
			tp->t_rtt = 0;
E 55
I 55
D 102
			tp->t_rtt = 1;
E 102
E 55
			tp->t_rxtshift = 0;
I 46
		}
E 130
I 130
		} else if (tp->t_timer[TCPT_PERSIST] == 0)
			tp->t_timer[TCPT_REXMT] = tp->t_rxtcur;
E 130
I 105
		/*
D 124
		 * When new data is acked, open the congestion window a bit.
E 124
I 124
D 131
		 * When new data is acked, open the congestion window
D 130
		 * by one max sized segment.
E 130
I 130
		 * by one max-sized segment.
E 131
I 131
		 * When new data is acked, open the congestion window.
		 * If the window gives us less than ssthresh packets
		 * in flight, open exponentially (maxseg per packet).
		 * Otherwise open linearly (maxseg per window,
		 * or maxseg^2 / cwnd per packet).
E 131
E 130
E 124
		 */
D 122
		if (acked > 0)
			tp->snd_cwnd = MIN(11 * tp->snd_cwnd / 10, 65535);
E 122
I 122
D 124
		tp->snd_cwnd = MIN(11 * tp->snd_cwnd / 10, 65535);
E 124
I 124
D 131
		tp->snd_cwnd = MIN(tp->snd_cwnd + tp->t_maxseg, 65535);
E 131
I 131
		{
		u_int incr = tp->t_maxseg;

		if (tp->snd_cwnd > tp->snd_ssthresh)
			incr = MAX(incr * incr / tp->snd_cwnd, 1);

D 137
		tp->snd_cwnd = MIN(tp->snd_cwnd + incr, 65535); /* XXX */
E 137
I 137
		tp->snd_cwnd = MIN(tp->snd_cwnd + incr, IP_MAXPACKET); /* XXX */
E 137
		}
E 131
E 124
E 122
E 105
		if (acked > so->so_snd.sb_cc) {
D 99
			sbdrop(&so->so_snd, so->so_snd.sb_cc);
E 99
			tp->snd_wnd -= so->so_snd.sb_cc;
I 99
D 118
			sbdrop(&so->so_snd, so->so_snd.sb_cc);
E 118
I 118
			sbdrop(&so->so_snd, (int)so->so_snd.sb_cc);
I 122
D 125
#define	ourfinisacked	(acked > 0)
E 125
I 125
			ourfinisacked = 1;
E 125
E 122
E 118
E 99
		} else {
D 61
			sbdrop(&so->so_snd.sb_cc, acked);
E 61
I 61
			sbdrop(&so->so_snd, acked);
E 61
			tp->snd_wnd -= acked;
D 125
			acked = 0;
E 125
I 125
			ourfinisacked = 0;
E 125
E 46
E 45
E 40
		}
I 45
D 67
		if (so->so_snd.sb_flags & SB_WAIT)
E 67
I 67
		if ((so->so_snd.sb_flags & SB_WAIT) || so->so_snd.sb_sel)
E 67
			sowwakeup(so);
E 45
I 39
		tp->snd_una = ti->ti_ack;
I 47
		if (SEQ_LT(tp->snd_nxt, tp->snd_una))
			tp->snd_nxt = tp->snd_una;
E 47
E 39
D 35
		/* if acked our FIN is acked */
E 35
I 35

D 55
		/*
		 * If transmit timer is running and timed sequence
		 * number was acked, update smoothed round trip time.
		 */
		if (tp->t_rtt && SEQ_GT(ti->ti_ack, tp->t_rtseq)) {
D 40
			tp->t_srtt =
			    tcp_beta * tp->t_srtt +
			    (1 - tcp_beta) * tp->t_rtt;
E 40
I 40
			if (tp->t_srtt == 0)
				tp->t_srtt = tp->t_rtt;
			else
				tp->t_srtt =
				    tcp_alpha * tp->t_srtt +
				    (1 - tcp_alpha) * tp->t_rtt;
D 41
printf("tcp_input: rtt sampled %d, srtt now %d\n", tp->t_rtt, (int)(100* tp->t_srtt));
E 41
E 40
			tp->t_rtt = 0;
		}

E 55
E 35
E 33
D 39
		tp->snd_una = ti->ti_ack;
I 33

E 39
D 40
		/*
		 * Update window information.
		 */
E 33
		if (SEQ_LT(tp->snd_wl1, ti->ti_seq) ||
D 33
		    tp->snd_wl1==ti-ti_seq && SEQ_LEQ(tp->snd_wl2,ti->ti_seq)) {
E 33
I 33
		    tp->snd_wl1==ti->ti_seq && SEQ_LEQ(tp->snd_wl2,ti->ti_seq)) {
E 33
			tp->snd_wnd = ti->ti_win;
			tp->snd_wl1 = ti->ti_seq;
			tp->snd_wl2 = ti->ti_ack;
E 31
		}
D 11
		rcv_ctldat(tp, n, 1);
E 11
I 11
D 26
		tcp_ctldat(tp, n, 1);
E 26
I 26
D 31
		tcp_ctldat(tp, ti, 1);
E 26
E 11
		if (tp->tc_flags&TC_FIN_RCVD) {
D 15
			if (n->th_flags&TH_ACK) {
				if (n->t_ackno > tp->iss)
					present_data(tp);	/* 32 */
			} else {
E 15
I 15
D 22
			if ((n->th_flags&TH_ACK) == 0) {
E 22
I 22
D 26
			if ((thflags&TH_ACK) == 0) {
E 26
I 26
D 30
			if ((tiflags&TH_ACK) == 0) {
E 30
I 30
			if ((tiflags&TH_ACK) == 0)
E 30
E 26
E 22
E 15
				tp->t_finack = T_2ML;		/* 9 */
D 30
				tp->tc_flags &= ~TC_WAITED_2_ML;
			}
E 30
			nstate = CLOSE_WAIT;
			goto done;
		}
D 15
		if (n->th_flags&TH_ACK) {
			present_data(tp);			/* 11 */
			nstate = ESTAB;
		} else
			nstate = SYN_RCVD;			/* 8 */
E 15
I 15
D 22
		nstate = (n->th_flags&TH_ACK) ? ESTAB : SYN_RCVD; /* 11:8 */
E 22
I 22
D 26
		nstate = (thflags&TH_ACK) ? ESTAB : SYN_RCVD; /* 11:8 */
E 26
I 26
		nstate = (tiflags&TH_ACK) ? ESTAB : SYN_RCVD; /* 11:8 */
E 26
E 22
E 15
		goto done;
E 31

E 40
D 31
	case SYN_RCVD:
	case L_SYN_RCVD:
D 22
		if ((n->th_flags&TH_ACK) == 0 ||
		    (n->th_flags&TH_ACK) && n->t_ackno <= tp->iss) {
E 22
I 22
D 26
		if ((thflags&TH_ACK) == 0 ||
D 24
		    (thflags&TH_ACK) && n->t_ackno <= tp->iss) {
E 24
I 24
		    (thflags&TH_ACK) && n->ti_ackno <= tp->iss) {
E 26
I 26
		if ((tiflags&TH_ACK) == 0 ||
		    (tiflags&TH_ACK) && ti->ti_ackno <= tp->iss) {
E 26
E 24
E 22
			nstate = EFAILEC;
			goto done;
		}
		goto input;

	case ESTAB:
	case FIN_W1:
	case FIN_W2:
	case TIME_WAIT:
input:
D 11
		rcv_ctldat(tp, n, 1);				/* 39 */
E 11
I 11
D 26
		tcp_ctldat(tp, n, 1);				/* 39 */
E 26
I 26
		tcp_ctldat(tp, ti, 1);				/* 39 */
E 31
E 26
E 11
D 15
		present_data(tp);
E 15
		switch (tp->t_state) {

D 31
		case ESTAB:
			if (tp->tc_flags&TC_FIN_RCVD)
				nstate = CLOSE_WAIT;
			break;
E 31
I 31
		/*
		 * In FIN_WAIT_1 STATE in addition to the processing
		 * for the ESTABLISHED state if our FIN is now acknowledged
D 33
		 * then enter FIN_WAIT_2 and continue processing in that state.
E 33
I 33
		 * then enter FIN_WAIT_2.
E 33
		 */
		case TCPS_FIN_WAIT_1:
D 33
			if (tcp_finisacked(tp) == 0)
				break;
			tp->t_state = TCPS_FIN_WAIT_2;
			/* fall into ... */
E 31

D 31
		case SYN_RCVD:
		case L_SYN_RCVD:
			nstate = (tp->tc_flags&TC_FIN_RCVD) ?
			    CLOSE_WAIT : ESTAB;			 /* 33:5 */
E 31
I 31
	 	/*
		 * In FIN_WAIT_2 STATE in addition to the processing for
		 * the ESTABLISHED state allow the user to close when
		 * the data has drained.
		 */
		case TCPS_FIN_WAIT_2:
			tcp_usrcanclose(tp);
E 33
I 33
D 54
			if (ourfinisacked)
E 54
I 54
			if (ourfinisacked) {
				/*
				 * If we can't receive any more
				 * data, then closing user can proceed.
I 110
				 * Starting the timer is contrary to the
				 * specification, but if we don't get a FIN
				 * we'll hang forever.
E 110
				 */
D 110
				if (so->so_state & SS_CANTRCVMORE)
E 110
I 110
				if (so->so_state & SS_CANTRCVMORE) {
E 110
					soisdisconnected(so);
I 110
D 138
					tp->t_timer[TCPT_2MSL] = TCPTV_MAXIDLE;
E 138
I 138
					tp->t_timer[TCPT_2MSL] = tcp_maxidle;
E 138
				}
E 110
E 54
				tp->t_state = TCPS_FIN_WAIT_2;
I 102
D 110
				/*
				 * This is contrary to the specification,
				 * but if we haven't gotten our FIN in 
				 * 5 minutes, it's not forthcoming.
D 107
				 */
E 107
I 104
				tp->t_timer[TCPT_2MSL] = 5 * 60 * PR_SLOWHZ;
I 107
				 * MUST WORRY ABOUT ONE-WAY CONNECTIONS.
				 */
E 110
E 107
E 104
E 102
I 54
			}
E 54
E 33
E 31
			break;

D 31
		case FIN_W1:
D 26
			j = ack_fin(tp, n);
E 26
I 26
			j = ack_fin(tp, ti);
E 26
			if ((tp->tc_flags & TC_FIN_RCVD) == 0) {
				if (j)
					nstate = FIN_W2;	/* 27 */
				break;
			}
			tp->t_finack = T_2ML;
D 30
			tp->tc_flags &= ~TC_WAITED_2_ML;
E 30
D 19
			nstate = j ? TIME_WAIT : CLOSING1;	/* 28:26 */
E 19
I 19
			nstate = j ? TIME_WAIT : CLOSING;	/* 28:26 */
E 31
I 31
	 	/*
		 * In CLOSING STATE in addition to the processing for
		 * the ESTABLISHED state if the ACK acknowledges our FIN
		 * then enter the TIME-WAIT state, otherwise ignore
		 * the segment.
		 */
		case TCPS_CLOSING:
D 33
			if (tcp_finisacked(tp))
E 33
I 33
D 40
			if (ourfinisacked)
E 40
I 40
			if (ourfinisacked) {
E 40
E 33
				tp->t_state = TCPS_TIME_WAIT;
E 31
E 19
D 33
			break;
E 33
I 33
D 40
			goto drop;
E 40
I 40
				tcp_canceltimers(tp);
				tp->t_timer[TCPT_2MSL] = 2 * TCPTV_MSL;
				soisdisconnected(so);
			}
			break;
E 40
E 33

D 31
		case FIN_W2:
			if (tp->tc_flags&TC_FIN_RCVD) {
				tp->t_finack = T_2ML;		/* 29 */
D 30
				tp->tc_flags &= ~TC_WAITED_2_ML;
E 30
				nstate = TIME_WAIT;
				break;
			}
			break;
		}
		goto done;
E 31
I 31
		/*
D 33
		 * In LAST_ACK state if our FIN is now acknowledged
		 * then enter the TIME_WAIT state, otherwise ignore the
		 * segment.
E 33
I 33
D 128
		 * The only thing that can arrive in  LAST_ACK state
		 * is an acknowledgment of our FIN.  If our FIN is now
		 * acknowledged, delete the TCB, enter the closed state
		 * and return.
E 128
I 128
		 * In LAST_ACK, we may still be waiting for data to drain
		 * and/or to be acked, as well as for the ack of our FIN.
		 * If our FIN is now acknowledged, delete the TCB,
		 * enter the closed state and return.
E 128
E 33
		 */
		case TCPS_LAST_ACK:
D 33
			if (tcp_finisacked(tp))
E 33
I 33
D 40
			if (ourfinisacked)
E 40
I 40
D 41
			if (ourfinisacked) {
printf("tcp_input: LAST ACK close\n");
E 41
I 41
D 65
			if (ourfinisacked)
E 65
I 65
D 88
			if (ourfinisacked) {
E 65
E 41
E 40
E 33
				tcp_close(tp);
I 65
				tp = 0;
			}
E 88
I 88
D 128
			if (ourfinisacked)
E 128
I 128
			if (ourfinisacked) {
E 128
				tp = tcp_close(tp);
E 88
E 65
I 40
D 41
			}
E 41
E 40
D 128
			goto drop;
E 128
I 128
				goto drop;
			}
			break;
E 128
E 31

D 31
	case CLOSE_WAIT:
D 22
		if (n->th_flags&TH_FIN) {
			if ((n->th_flags&TH_ACK) &&
E 22
I 22
D 26
		if (thflags&TH_FIN) {
			if ((thflags&TH_ACK) &&
E 22
D 24
			    n->t_ackno <= tp->seq_fin) {
E 24
I 24
			    n->ti_ackno <= tp->seq_fin) {
E 24
D 11
				rcv_ctldat(tp, n, 0);		/* 30 */
E 11
I 11
				tcp_ctldat(tp, n, 0);		/* 30 */
E 26
I 26
		if (tiflags&TH_FIN) {
			if ((tiflags&TH_ACK) &&
			    ti->ti_ackno <= tp->seq_fin) {
				tcp_ctldat(tp, ti, 0);		/* 30 */
E 26
E 11
				tp->t_finack = T_2ML;
D 30
				tp->tc_flags &= ~TC_WAITED_2_ML;
E 30
			} else
D 11
				send_ctl(tp);			/* 31 */
E 11
I 11
D 25
				tcp_sndctl(tp);			/* 31 */
E 25
I 25
				(void) tcp_sndctl(tp);		/* 31 */
E 25
E 11
			goto done;
E 31
I 31
		/*
		 * In TIME_WAIT state the only thing that should arrive
		 * is a retransmission of the remote FIN.  Acknowledge
		 * it and restart the finack timer.
		 */
		case TCPS_TIME_WAIT:
I 40
D 41
printf("tcp_input: TIME_WAIT restart timer\n");
E 41
E 40
D 33
			tp->t_finack = 2 * TCP_MSL;
E 33
I 33
D 35
			tp->t_timer[TCPT_2MSL] = 2 * TCPSC_MSL;
E 35
I 35
			tp->t_timer[TCPT_2MSL] = 2 * TCPTV_MSL;
E 35
E 33
			goto dropafterack;
E 31
		}
I 33
D 125
#undef ourfinisacked
E 125
	}
E 33
D 31
		goto input;
E 31

D 19
	case CLOSING1:
E 19
I 19
D 31
	case CLOSING:
E 19
D 26
		j = ack_fin(tp, n);
D 22
		if (n->th_flags&TH_FIN) {
E 22
I 22
		if (thflags&TH_FIN) {
E 22
D 11
			rcv_ctldat(tp, n, 0);
E 11
I 11
			tcp_ctldat(tp, n, 0);
E 26
I 26
		j = ack_fin(tp, ti);
		if (tiflags&TH_FIN) {
			tcp_ctldat(tp, ti, 0);
E 26
E 11
			tp->t_finack = T_2ML;
D 30
			tp->tc_flags &= ~TC_WAITED_2_ML;
E 30
			if (j)
				nstate = TIME_WAIT;		/* 23 */
			goto done;
E 31
I 31
step6:
	/*
I 40
	 * Update window information.
I 116
	 * Don't look at window if no ACK: TAC's send garbage on first SYN.
E 116
	 */
D 41
printf("update win wl1 %x ti->ti_seq %x wl2 %x?", tp->snd_wl1, ti->ti_seq, tp->snd_wl2);
E 41
D 45
	if (SEQ_LT(tp->snd_wl1, ti->ti_seq) ||
D 44
	    tp->snd_wl1==ti->ti_seq && SEQ_LEQ(tp->snd_wl2,ti->ti_seq)) {
E 44
I 44
	    tp->snd_wl1==ti->ti_seq && SEQ_LEQ(tp->snd_wl2,ti->ti_ack)) {
E 45
I 45
D 116
	if (SEQ_LT(tp->snd_wl1, ti->ti_seq) || tp->snd_wl1 == ti->ti_seq &&
E 116
I 116
	if ((tiflags & TH_ACK) &&
	    (SEQ_LT(tp->snd_wl1, ti->ti_seq) || tp->snd_wl1 == ti->ti_seq &&
E 116
D 48
	    (SEQ_LEQ(tp->snd_wl2, ti->ti_ack) ||
E 48
I 48
	    (SEQ_LT(tp->snd_wl2, ti->ti_ack) ||
E 48
D 116
	     tp->snd_wl2 == ti->ti_ack && ti->ti_win > tp->snd_wnd)) {
E 116
I 116
	     tp->snd_wl2 == ti->ti_ack && ti->ti_win > tp->snd_wnd))) {
I 122
		/* keep track of pure window updates */
		if (ti->ti_len == 0 &&
D 131
		    tp->snd_wl2 == ti->ti_ack && ti->ti_win > tp->snd_wnd) {
E 131
I 131
		    tp->snd_wl2 == ti->ti_ack && ti->ti_win > tp->snd_wnd)
E 131
			tcpstat.tcps_rcvwinupd++;
D 131
			tcpstat.tcps_rcvdupack--;
		}
E 131
E 122
E 116
I 48
D 55
/*
printf("wl1 %x seq %x wl2 %x ack %x win %x wnd %x\n", tp->snd_wl1, ti->ti_seq, tp->snd_wl2, ti->ti_ack, ti->ti_win, tp->snd_wnd);
*/
E 55
E 48
E 45
E 44
D 41
printf("yes\n");
E 41
		tp->snd_wnd = ti->ti_win;
		tp->snd_wl1 = ti->ti_seq;
		tp->snd_wl2 = ti->ti_ack;
I 113
		if (tp->snd_wnd > tp->max_sndwnd)
			tp->max_sndwnd = tp->snd_wnd;
E 113
D 79
		if (tp->snd_wnd > 0)
E 79
I 79
D 107
		if (tp->snd_wnd != 0)
E 79
			tp->t_timer[TCPT_PERSIST] = 0;
E 107
D 116
	}
E 116
I 116
D 119
		newwin = 1;
	} else
		newwin = 0;
E 119
I 119
		needoutput = 1;
	}
E 119
E 116
D 41
else printf("no\n");
E 41

	/*
E 40
D 49
	 * If an URG bit is set in the segment and is greater than the
E 49
I 49
D 51
	 * If an URG bit is set and in the segment and is greater than the
E 49
D 50
	 * current known urgent pointer, then signal the user that the
D 40
	 * remote side has urgent data.  This should not happen
E 40
I 40
	 * remote side has out of band data.  This should not happen
E 50
I 50
	 * current known urgent pointer, then mark the data stream.
	 * If the TCP is not doing out-of-band data, then indicate
	 * urgent to the user.  This should not happen
E 50
E 40
	 * in CLOSE_WAIT, CLOSING, LAST-ACK or TIME_WAIT STATES since
	 * a FIN has been received from the remote side.  In these states
	 * we ignore the URG.
E 51
I 51
	 * Process segments with URG.
E 51
	 */
D 33
	if ((tiflags & TH_URG) == 0 && (TCPS_RCVDFIN(tp->t_state) == 0) {
		if (SEQ_GT(ti->ti_urp, tp->rcv_up) {
E 33
I 33
D 49
	if ((tiflags & TH_URG) == 0 && TCPS_HAVERCVDFIN(tp->t_state) == 0)
		if (SEQ_GT(ti->ti_urp, tp->rcv_up)) {
E 33
			tp->rcv_up = ti->ti_urp;
I 33
#if 0
E 33
D 40
			soisurgendata(so);		/* XXX */
E 40
I 40
			sohasoutofband(so);		/* XXX */
E 40
I 33
#endif
E 33
E 31
		}
E 49
I 49
D 51
	if ((tiflags & TH_URG) && TCPS_HAVERCVDFIN(tp->t_state) == 0 &&
D 50
	    ti->ti_urp <= ti->ti_len &&
E 50
	    SEQ_GT(ti->ti_seq+ti->ti_urp, tp->rcv_up)) {
		tp->rcv_up = ti->ti_seq + ti->ti_urp;
		so->so_oobmark = so->so_rcv.sb_cc +
		    (tp->rcv_up - tp->rcv_nxt) - 1;
		if (so->so_oobmark == 0)
			so->so_state |= SS_RCVATMARK;
E 51
I 51
D 70
	if ((tiflags & TH_URG) && TCPS_HAVERCVDFIN(tp->t_state) == 0) {
E 70
I 70
	if ((tiflags & TH_URG) && ti->ti_urp &&
	    TCPS_HAVERCVDFIN(tp->t_state) == 0) {
E 70
		/*
I 96
D 97
		 * This is a kludge, but the BBN C70 TCP
		 * randomly sends packets with the urgent flag
		 * set and random ti_urp values.  This crashes
		 * the system because so_oobmark ends up being
		 * interpreted as a negative number in soreceive.
E 97
I 97
D 116
		 * This is a kludge, but if we receive accept
E 116
I 116
		 * This is a kludge, but if we receive and accept
E 116
		 * random urgent pointers, we'll crash in
		 * soreceive.  It's hard to imagine someone
		 * actually wanting to send this much urgent data.
E 97
		 */
D 102
		if (ti->ti_urp > tp->t_maxseg) {	/* XXX */
E 102
I 102
D 105
		if (ti->ti_urp > tp->rcv_wnd + 1) {	/* XXX */
E 105
I 105
D 114
		if (ti->ti_urp + (unsigned) so->so_rcv.sb_cc > 32767) {
E 114
I 114
		if (ti->ti_urp + so->so_rcv.sb_cc > SB_MAX) {
E 114
E 105
E 102
			ti->ti_urp = 0;			/* XXX */
			tiflags &= ~TH_URG;		/* XXX */
D 116
			ti->ti_flags &= ~TH_URG;	/* XXX */
D 97
			goto bbnurp;			/* XXX */
E 97
I 97
			goto badurp;			/* XXX */
E 116
I 116
			goto dodata;			/* XXX */
E 116
E 97
		}
		/*
E 96
		 * If this segment advances the known urgent pointer,
		 * then mark the data stream.  This should not happen
		 * in CLOSE_WAIT, CLOSING, LAST_ACK or TIME_WAIT STATES since
		 * a FIN has been received from the remote side. 
		 * In these states we ignore the URG.
I 120
		 *
		 * According to RFC961 (Assigned Protocols),
		 * the urgent pointer points to the last octet
		 * of urgent data.  We continue, however,
		 * to consider it to indicate the first octet
		 * of data past the urgent section
		 * as the original spec states.
E 120
		 */
		if (SEQ_GT(ti->ti_seq+ti->ti_urp, tp->rcv_up)) {
			tp->rcv_up = ti->ti_seq + ti->ti_urp;
			so->so_oobmark = so->so_rcv.sb_cc +
			    (tp->rcv_up - tp->rcv_nxt) - 1;
			if (so->so_oobmark == 0)
				so->so_state |= SS_RCVATMARK;
E 51
D 50
		tcp_pulloutofband(so, ti);
		sohasoutofband(so);
E 50
I 50
D 76
#ifdef TCPTRUEOOB
D 51
		if ((tp->t_flags & TF_DOOOB) == 0)
E 51
I 51
			if ((tp->t_flags & TF_DOOOB) == 0)
E 51
#endif
D 51
		{
			sohasoutofband(so);
			tp->t_oobflags |= TCPOOB_HAVEDATA;
E 51
I 51
				sohasoutofband(so);
E 76
I 76
			sohasoutofband(so);
E 76
D 110
			tp->t_oobflags &= ~TCPOOB_HAVEDATA;
E 110
I 110
			tp->t_oobflags &= ~(TCPOOB_HAVEDATA | TCPOOB_HADDATA);
E 110
E 51
		}
D 51

E 51
I 51
		/*
		 * Remove out of band data so doesn't get presented to user.
		 * This can happen independent of advancing the URG pointer,
		 * but if two URG's are pending at once, some out-of-band
		 * data may creep in... ick.
		 */
D 73
		if (ti->ti_urp <= ti->ti_len) {
E 73
I 73
D 120
		if (ti->ti_urp <= ti->ti_len)
E 120
I 120
D 136
		if (ti->ti_urp <= ti->ti_len &&
		    (so->so_options & SO_OOBINLINE) == 0)
E 136
I 136
		if (ti->ti_urp <= ti->ti_len
#ifdef SO_OOBINLINE
		     && (so->so_options & SO_OOBINLINE) == 0
#endif
							   )
E 136
E 120
E 73
			tcp_pulloutofband(so, ti);
D 73
		}
E 73
E 51
E 50
D 116
	}
I 96
D 97
bbnurp:							/* XXX */
E 97
I 97
badurp:							/* XXX */
E 116
I 116
	} else
		/*
		 * If no out of band data is expected,
		 * pull receive urgent pointer along
		 * with the receive window.
		 */
		if (SEQ_GT(tp->rcv_nxt, tp->rcv_up))
			tp->rcv_up = tp->rcv_nxt;
dodata:							/* XXX */
E 116
E 97
E 96
E 49
D 31
		if (j) {
D 30
			if (tp->tc_flags&TC_WAITED_2_ML)
E 30
I 30
			if (tp->t_finack == 0)
E 30
				if (rcv_empty(tp)) {
D 11
					t_close(tp, UCLOSED);	/* 15 */
E 11
I 11
D 22
					tcp_close(tp, UCLOSED);	/* 15 */
E 11
					nstate = CLOSED;
E 22
I 22
D 23
					sowakeup(tp->t_socket); /* ### */
E 23
I 23
					sorwakeup(inp->inp_socket);
E 23
					nstate = CLOSED;	/* 15 */
E 22
				} else
					nstate = RCV_WAIT;	/* 18 */
			else
				nstate = TIME_WAIT;
			goto done;
		}
		goto input;

D 19
	case CLOSING2:
E 19
I 19
	case LAST_ACK:
E 19
D 26
		if (ack_fin(tp, n)) {
E 26
I 26
		if (ack_fin(tp, ti)) {
E 26
D 23
			if (rcv_empty(tp)) {			/* 16 */
D 11
				t_close(tp, UCLOSED);
E 11
I 11
D 22
				tcp_close(tp, UCLOSED);
E 22
I 22
				sowakeup(tp->t_socket); /* ### */
/* XXX */			/* tcp_close(tp, UCLOSED); */
E 23
I 23
			if (rcv_empty(tp)) {		/* 16 */
				sorwakeup(inp->inp_socket);
E 23
E 22
E 11
				nstate = CLOSED;
			} else
				nstate = RCV_WAIT;		/* 19 */
			goto done;
		}
D 22
		if (n->th_flags&TH_FIN) {
E 22
I 22
D 26
		if (thflags&TH_FIN) {
E 26
I 26
		if (tiflags&TH_FIN) {
E 26
E 22
D 11
			send_ctl(tp);				/* 31 */
E 11
I 11
D 25
			tcp_sndctl(tp);				/* 31 */
E 25
I 25
			(void) tcp_sndctl(tp);			/* 31 */
E 25
E 11
			goto done;
		}
		goto input;

	case RCV_WAIT:
D 22
		if ((n->th_flags&TH_FIN) && (n->th_flags&TH_ACK) &&
E 22
I 22
D 26
		if ((thflags&TH_FIN) && (thflags&TH_ACK) &&
E 22
D 24
		    n->t_ackno <= tp->seq_fin) {
E 24
I 24
		    n->ti_ackno <= tp->seq_fin) {
E 24
D 11
			rcv_ctldat(tp, n, 0);
E 11
I 11
			tcp_ctldat(tp, n, 0);
E 26
I 26
		if ((tiflags&TH_FIN) && (tiflags&TH_ACK) &&
		    ti->ti_ackno <= tp->seq_fin) {
			tcp_ctldat(tp, ti, 0);
E 26
E 11
D 30
			tp->t_finack = T_2ML;
			tp->tc_flags &= ~TC_WAITED_2_ML;	/* 30 */
E 30
I 30
			tp->t_finack = T_2ML;			/* 30 */
E 30
		}
		goto done;
E 31
D 33
	}
E 33
D 31
	panic("tcp_input");
done:
E 31

	/*
D 31
	 * Done with state*input specific processing.
	 * Form trace records, free input if not needed,
	 * and enter new state.
E 31
I 31
	 * Process the segment text, merging it into the TCP sequencing queue,
	 * and arranging for acknowledgment of receipt if necessary.
	 * This process logically involves adjusting tp->rcv_wnd as data
	 * is presented to the user (this happens in tcp_usrreq.c,
	 * case PRU_RCVD).  If a FIN has already been received on this
	 * connection then we just ignore the text.
E 31
	 */
D 31
#ifdef TCPDEBUG
D 3
	if (tdb.td_tod) {
		tdb.td_new = nstate;
		tcp_debug[tdbx++ % TDBSIZE] = tdb;
		if (tcpconsdebug)
			tcp_prt(&tdb);
	}
E 3
I 3
	if (tdb.td_tod)
		tdb_stuff(&tdb, nstate);
E 3
#endif
	switch (nstate) {

	case EFAILEC:
E 31
I 31
D 40
	if (ti->ti_len) {
D 33
		if (TCPS_RCVDFIN(tp->t_state))
E 33
I 33
		if (TCPS_HAVERCVDFIN(tp->t_state))
E 33
			goto drop;
E 40
I 40
D 42
	if (ti->ti_len && TCPS_HAVERCVDFIN(tp->t_state) == 0) {
E 42
I 42
D 105
	if ((ti->ti_len || (tiflags&TH_FIN)) &&
	    TCPS_HAVERCVDFIN(tp->t_state) == 0) {
E 42
E 40
I 33
D 59
		off += sizeof (struct ip);		/* drop IP header */
D 58
		m->m_off += off;
		m->m_len -= off;
E 58
I 58
		m_drop(m, off);
E 59
E 58
E 33
		tiflags = tcp_reass(tp, ti);
E 105
I 105
D 106
	if (TCPS_HAVERCVDFIN(tp->t_state) == 0) {
		if (ti->ti_len || (tiflags&TH_FIN))
			tiflags = tcp_reass(tp, ti);
		else
			m_freem(m);
E 106
I 106
	if ((ti->ti_len || (tiflags&TH_FIN)) &&
	    TCPS_HAVERCVDFIN(tp->t_state) == 0) {
D 110
		tiflags = tcp_reass(tp, ti);
E 110
I 110
		TCP_REASS(tp, ti, m, so, tiflags);
E 110
E 106
E 105
I 44
D 50
{ extern tcpdelack; 
if (tcpdelack) tp->t_flags |= TF_DELACK; else
E 44
D 33
	else
E 33
I 33
		tp->t_flags |= TF_ACKNOW;		/* XXX TF_DELACK */
I 44
}
E 50
I 50
D 140
		if (tcpnodelack == 0)
			tp->t_flags |= TF_DELACK;
		else
			tp->t_flags |= TF_ACKNOW;
E 140
I 113
		/*
		 * Note the amount of data that peer has sent into
		 * our window, in order to estimate the sender's
		 * buffer size.
		 */
D 130
		len = so->so_rcv.sb_hiwat - (tp->rcv_nxt - tp->rcv_adv);
E 130
I 130
D 131
		len = tp->rcv_nxt - tp->rcv_adv;
E 131
I 131
		len = so->so_rcv.sb_hiwat - (tp->rcv_adv - tp->rcv_nxt);
E 131
E 130
		if (len > tp->max_rcvd)
			tp->max_rcvd = len;
E 113
E 50
E 44
D 40
	} else
E 40
I 40
	} else {
E 40
E 33
E 31
D 26
		m_freem(mp);
E 26
I 26
		m_freem(m);
I 42
		tiflags &= ~TH_FIN;
E 42
I 40
	}
E 40
E 26
D 31
		return;
E 31

D 31
	default:
		tp->t_state = nstate;
		/* fall into ... */

	case CLOSED:
		/* IF CLOSED CANT LOOK AT tc_flags */
D 26
		if ((tp->tc_flags&TC_NET_KEEP) == 0)
E 26
I 26
		if ((tp->tc_flags&TC_NET_KEEP) == 0) {
			register struct mbuf *n;
E 26
D 15
			m_freem(mp);
E 15
I 15
			/* inline expansion of m_freem */
D 26
			while (mp) {
				MFREE(mp, m);
				mp = m;
E 26
I 26
			while (m) {
D 27
				MFREE(n, m);
E 27
I 27
				MFREE(m, n);
E 27
				m = n;
E 26
			}
I 26
		}
E 26
E 15
		return;
	}
	/* NOTREACHED */

E 31
	/*
D 31
	 * Unwanted packed; free everything
	 * but the header and return an rst.
E 31
I 31
D 42
	 * If FIN is received then if we haven't received SYN and
	 * therefore can't validate drop the segment.  Otherwise ACK
	 * the FIN and let the user know that the connection is closing.
E 42
I 42
	 * If FIN is received ACK the FIN and let the user know
	 * that the connection is closing.
E 42
E 31
	 */
D 31
notwanted:
D 26
	m_freem(mp->m_next);
	mp->m_next = NULL;
D 23
	mp->m_len = sizeof(struct th);
E 23
I 23
	mp->m_len = sizeof(struct tcpiphdr);
E 26
I 26
	m_freem(m->m_next);
	m->m_next = NULL;
	m->m_len = sizeof(struct tcpiphdr);
E 26
E 23
#define xchg(a,b) j=a; a=b; b=j
D 24
	xchg(n->t_d.s_addr, n->t_s.s_addr); xchg(n->t_dst, n->t_src);
E 24
I 24
D 26
	xchg(n->ti_dst.s_addr, n->ti_src.s_addr);
	xchg(n->ti_dport, n->ti_sport);
E 26
I 26
	xchg(ti->ti_dst.s_addr, ti->ti_src.s_addr);
	xchg(ti->ti_dport, ti->ti_sport);
E 26
E 24
#undef xchg
D 22
	if (n->th_flags&TH_ACK)
E 22
I 22
D 26
	if (thflags&TH_ACK)
E 22
D 24
		n->t_seq = n->t_ackno;
E 24
I 24
		n->ti_seq = n->ti_ackno;
E 26
I 26
	if (tiflags&TH_ACK)
		ti->ti_seq = ti->ti_ackno;
E 26
E 24
	else {
D 24
		n->t_ackno = htonl(ntohl(n->t_seq) + tlen - hlen);
		n->t_seq = 0;
E 24
I 24
D 25
		n->ti_ackno = htonl(ntohl(n->ti_seq) + tlen - hlen);
E 25
I 25
D 26
		n->ti_ackno = htonl((unsigned)(ntohl(n->ti_seq) + tlen-hlen));
E 25
		n->ti_seq = 0;
E 26
I 26
D 27
		ti->ti_ackno = htonl(ntohl(ti->ti_seq) + ti->ti_len);
E 27
I 27
		ti->ti_ackno = htonl((unsigned)(ntohl(ti->ti_seq) + ti->ti_len));
E 27
		ti->ti_seq = 0;
E 26
E 24
	}
D 22
	n->th_flags = TH_RST; /* not TH_FIN, TH_SYN */
	n->th_flags ^= TH_ACK;
E 22
I 22
D 24
	n->th_flags = ((thflags & TH_ACK) ? 0 : TH_ACK) | TH_RST;
E 22
	n->t_len = htons(TCPSIZE);
	n->t_off = 5;
D 18
	n->t_sum = cksum(mp, sizeof(struct th));
E 18
I 18
D 23
	n->t_sum = inet_cksum(mp, sizeof(struct th));
E 18
	((struct ip *)n)->ip_len = sizeof(struct th);
E 23
I 23
	n->t_sum = inet_cksum(mp, sizeof(struct tcpiphdr));
E 24
I 24
D 26
	n->ti_flags = ((thflags & TH_ACK) ? 0 : TH_ACK) | TH_RST;
	n->ti_len = htons(TCPSIZE);
	n->ti_off = 5;
	n->ti_sum = inet_cksum(mp, sizeof(struct tcpiphdr));
E 24
	((struct ip *)n)->ip_len = sizeof(struct tcpiphdr);
E 23
	ip_output(mp);
	netstat.t_badsegs++;
E 26
I 26
	ti->ti_flags = ((tiflags & TH_ACK) ? 0 : TH_ACK) | TH_RST;
	ti->ti_len = htons(TCPSIZE);
	ti->ti_off = 5;
	ti->ti_sum = inet_cksum(m, sizeof(struct tcpiphdr));
	((struct ip *)ti)->ip_len = sizeof(struct tcpiphdr);
I 29
	((struct ip *)ti)->ip_ttl = MAXTTL;
E 29
	ip_output(m);
	tcpstat.tcps_badsegs++;
E 26
}
E 31
I 31
D 32
	if ((tiflags & TH_FIN) && TCPS_HAVERCVDSYN(tp->t_state)) {
		tcp_usrclosing(tp);
E 32
I 32
D 33
	if (tiflags & TH_FIN) {
E 33
I 33
D 42
	if ((tiflags & TH_FIN)) {
E 33
		if (TCPS_HAVERCVDSYN(tp->t_state) == 0)
			goto drop;
E 42
I 42
	if (tiflags & TH_FIN) {
E 42
D 40
		socantrcvmore(so);
E 32
		tp->t_flags |= TF_ACKNOW;
		tp->rcv_nxt++;
E 40
I 40
		if (TCPS_HAVERCVDFIN(tp->t_state) == 0) {
			socantrcvmore(so);
			tp->t_flags |= TF_ACKNOW;
			tp->rcv_nxt++;
		}
D 41
printf("tcp_input: %x got FIN\n", tp);
E 41
E 40
		switch (tp->t_state) {
E 31

D 11
rcv_ctldat(tp, n, dataok)
E 11
I 11
D 23
tcp_ctldat(tp, n, dataok)
E 11
	register struct tcb *tp;
	register struct th *n;
E 23
I 23
D 31
tcp_ctldat(tp, n0, dataok)
	register struct tcpcb *tp;
	struct tcpiphdr *n0;
	int dataok;
E 23
{
D 13
	register sent;
	register struct ucb *up;
	register struct mbuf *m, *mn;
	register len;
COUNT(RCV_CTLDAT);
E 13
I 13
D 25
	register struct mbuf *m;
E 25
I 23
D 26
	register struct tcpiphdr *n = n0;
E 23
I 22
D 24
	register int thflags = n->th_flags;
E 24
I 24
	register int thflags = n->ti_flags;
E 26
I 26
	register struct tcpiphdr *ti = n0;
	register int tiflags = ti->ti_flags;
E 26
E 24
I 23
	struct socket *so = tp->t_inpcb->inp_socket;
D 24
	seq_t past = n->t_seq + n->t_len;
E 24
I 24
D 26
	seq_t past = n->ti_seq + n->ti_len;
E 26
I 26
	seq_t past = ti->ti_seq + ti->ti_len;
E 26
E 24
	seq_t urgent;
E 23
E 22
	int sent;
COUNT(TCP_CTLDAT);
E 13

D 23
	tp->tc_flags &= ~(TC_DROPPED_TXT|TC_ACK_DUE|TC_NEW_WINDOW);
E 23
I 23
D 26
	if (thflags & TH_URG)
D 24
		urgent = n->t_seq + n->t_urp;
E 24
I 24
		urgent = n->ti_seq + n->ti_urp;
E 26
I 26
	if (tiflags & TH_URG)
		urgent = ti->ti_seq + ti->ti_urp;
E 26
E 24
	tp->tc_flags &= ~(TC_ACK_DUE|TC_NEW_WINDOW);
E 23
/* syn */
D 22
	if ((tp->tc_flags&TC_SYN_RCVD) == 0 && (n->th_flags&TH_SYN)) {
E 22
I 22
D 26
	if ((tp->tc_flags&TC_SYN_RCVD) == 0 && (thflags&TH_SYN)) {
E 22
D 24
		tp->irs = n->t_seq;
		tp->rcv_nxt = n->t_seq + 1;
E 24
I 24
		tp->irs = n->ti_seq;
		tp->rcv_nxt = n->ti_seq + 1;
E 26
I 26
	if ((tp->tc_flags&TC_SYN_RCVD) == 0 && (tiflags&TH_SYN)) {
		tp->irs = ti->ti_seq;
		tp->rcv_nxt = ti->ti_seq + 1;
E 26
E 24
		tp->snd_wl = tp->rcv_urp = tp->irs;
		tp->tc_flags |= (TC_SYN_RCVD|TC_ACK_DUE);
	}
/* ack */
D 22
	if ((n->th_flags&TH_ACK) && (tp->tc_flags&TC_SYN_RCVD) &&
E 22
I 22
D 26
	if ((thflags&TH_ACK) && (tp->tc_flags&TC_SYN_RCVD) &&
E 22
D 24
	    n->t_ackno > tp->snd_una) {
E 24
I 24
	    n->ti_ackno > tp->snd_una) {
E 26
I 26
	if ((tiflags&TH_ACK) && (tp->tc_flags&TC_SYN_RCVD) &&
	    ti->ti_ackno > tp->snd_una) {
E 26
E 24
I 13
D 25
		register struct mbuf *mn;
D 22
		register struct ucb *up;
E 22
I 22
D 23
		register struct socket *so;
E 22
D 15
		register int len;
E 15
I 15
		int len;
E 23
E 15

E 25
E 13
D 22
		up = tp->t_ucb;
E 22
I 22
D 23
		so = tp->t_socket;
E 22

		/* update snd_una and snd_nxt */
E 23
I 23
		/*
		 * Reflect newly acknowledged data.
E 31
I 31
	 	/*
		 * In SYN_RECEIVED and ESTABLISHED STATES
		 * enter the CLOSE_WAIT state.
E 31
		 */
E 23
D 24
		tp->snd_una = n->t_ackno;
E 24
I 24
D 26
		tp->snd_una = n->ti_ackno;
E 26
I 26
D 31
		tp->snd_una = ti->ti_ackno;
E 26
E 24
		if (tp->snd_una > tp->snd_nxt)
			tp->snd_nxt = tp->snd_una;
E 31
I 31
		case TCPS_SYN_RECEIVED:
		case TCPS_ESTABLISHED:
			tp->t_state = TCPS_CLOSE_WAIT;
			break;
E 31
D 15

E 15
D 23
		/* if timed msg acked, set retrans time value */
E 23
I 23

D 31
		/*
		 * If timed msg acked, update retransmit time value.
E 31
I 31
	 	/*
D 33
		 * In FIN_WAIT_1 STATE if our FIN has been acked then
		 * enter TIME_WAIT state, starting the associated timer
		 * and turning off all other standard timers.
	 	 * If FIN has not been acked enter the CLOSING state.
E 33
I 33
		 * If still in FIN_WAIT_1 STATE FIN has not been acked so
		 * enter the CLOSING state.
E 33
E 31
		 */
E 23
D 31
		if ((tp->tc_flags&TC_SYN_ACKED) &&
		    tp->snd_una > tp->t_xmt_val) {
I 23
			/* NEED SMOOTHING HERE */
E 23
			tp->t_xmtime = (tp->t_xmt != 0 ? tp->t_xmt : T_REXMT);
			if (tp->t_xmtime > T_REMAX)
				tp->t_xmtime = T_REMAX;
E 31
I 31
		case TCPS_FIN_WAIT_1:
D 33
			if (tcp_finisacked(tp)) {
				tp->t_state = TCPS_TIME_WAIT;
				tcp_canceltimers(tp, 0);
				tp->t_timer[TCPT_FINACK] = TCPSC_2MSL;
			} else
				tp->t_state = TCPS_CLOSING;
E 33
I 33
			tp->t_state = TCPS_CLOSING;
E 33
			break;
E 31
D 33
		}
E 33

I 31
	 	/*
		 * In FIN_WAIT_2 state enter the TIME_WAIT state,
		 * starting the time-wait timer, turning off the other 
		 * standard timers.
		 */
		case TCPS_FIN_WAIT_2:
D 33
			tp->t_state = TCPS_FIN_WAIT_2;
E 33
I 33
D 40
			tp->t_state = TCPS_TIME_WAIT;;
E 40
I 40
			tp->t_state = TCPS_TIME_WAIT;
E 40
E 33
D 32
			tcp_canceltimers(tp, 0);
E 32
I 32
			tcp_canceltimers(tp);
E 32
D 33
			tp->t_timer[TCPT_FINACK] = TCPSC_2MSL;
E 33
I 33
D 35
			tp->t_timer[TCPT_2MSL] = TCPSC_2MSL;
E 35
I 35
			tp->t_timer[TCPT_2MSL] = 2 * TCPTV_MSL;
I 40
			soisdisconnected(so);
E 40
E 35
E 33
			break;

E 31
D 23
		/* remove acked data from send buf */
		len = tp->snd_una - tp->snd_off;
D 22
		m = up->uc_sbuf;
E 22
I 22
		m = so->so_snd.sb_mb;
E 22
		while (len > 0 && m != NULL)
			if (m->m_len <= len) {
				len -= m->m_len;
				if (m->m_off > MMAXOFF)
D 22
					up->uc_ssize -= NMBPG;
E 22
I 22
					so->so_snd.sb_mbcnt -= NMBPG;
E 22
				MFREE(m, mn);
				m = mn;
D 22
				up->uc_ssize--;
E 22
I 22
				so->so_snd.sb_mbcnt--;
				if (so->so_snd.sb_mbcnt <= 0)
					panic("tcp_ctldat");
E 22
			} else {
				m->m_len -= len;
				m->m_off += len;
				break;
			}
D 22
		up->uc_sbuf = m;
E 22
I 22
		so->so_snd.sb_mb = m;
E 23
I 23
		/*
D 31
		 * Remove acked data from send buf
E 31
I 31
		 * In TIME_WAIT state restart the 2 MSL time_wait timer.
E 31
		 */
D 25
		sbdrop(&so->so_snd, tp->snd_una - tp->snd_off);
E 25
I 25
D 31
		sbdrop(&so->so_snd, (int)(tp->snd_una - tp->snd_off));
E 25
E 23
E 22
		tp->snd_off = tp->snd_una;
		if ((tp->tc_flags&TC_SYN_ACKED) == 0 &&
		    (tp->snd_una > tp->iss)) {
			tp->tc_flags |= TC_SYN_ACKED;
			tp->t_init = 0;
		}
		if (tp->seq_fin != tp->iss && tp->snd_una > tp->seq_fin)
			tp->tc_flags &= ~TC_SND_FIN;
		tp->t_rexmt = 0;
		tp->t_rexmttl = 0;
		tp->tc_flags |= TC_CANCELLED;
D 22
		netwakeup(tp->t_ucb);		/* wasteful */
E 22
I 22
D 23
		sowakeup(tp->t_socket);		/* wasteful */
E 23
I 23
		sowwakeup(tp->t_inpcb->inp_socket);
E 31
I 31
		case TCPS_TIME_WAIT:
D 33
			tp->t_timer[TCPT_FINACK] = TCPSC_2MSL;
E 33
I 33
D 35
			tp->t_timer[TCPT_2MSL] = TCPSC_2MSL;
E 35
I 35
			tp->t_timer[TCPT_2MSL] = 2 * TCPTV_MSL;
E 35
E 33
			break;
I 33
		}
E 33
E 31
E 23
E 22
	}
I 43
	if (so->so_options & SO_DEBUG)
		tcp_trace(TA_INPUT, ostate, tp, &tcp_saveti, 0);
E 43
I 33

	/*
	 * Return any desired output.
	 */
D 61
	tcp_output(tp);
E 61
I 61
D 116
	(void) tcp_output(tp);
E 116
I 116
D 117
#ifdef notyet
	if (newwin || tp->t_flags & TF_ACKNOW)
#endif
E 117
I 117
D 119
	if (newwin || (tp->t_flags & TF_ACKNOW))
E 119
I 119
	if (needoutput || (tp->t_flags & TF_ACKNOW))
E 119
E 117
		(void) tcp_output(tp);
E 116
E 61
E 33
D 31
/* win */
D 24
	if ((tp->tc_flags & TC_SYN_RCVD) && n->t_seq >= tp->snd_wl) {
		tp->snd_wl = n->t_seq;
		tp->snd_wnd = n->t_win;
E 24
I 24
D 26
	if ((tp->tc_flags & TC_SYN_RCVD) && n->ti_seq >= tp->snd_wl) {
		tp->snd_wl = n->ti_seq;
		tp->snd_wnd = n->ti_win;
E 26
I 26
	if ((tp->tc_flags & TC_SYN_RCVD) && ti->ti_seq >= tp->snd_wl) {
		tp->snd_wl = ti->ti_seq;
		tp->snd_wnd = ti->ti_win;
E 26
E 24
		tp->tc_flags |= TC_NEW_WINDOW;
		tp->t_persist = 0;
E 31
I 31
	return;
I 33

E 33
dropafterack:
D 33
	if ((tiflags & TH_RST) == 0)
		tcp_reflect(ti, tp->rcv_nxt, tp->snd_nxt, TH_ACK);
E 33
I 33
	/*
D 40
	 * Generate an ACK, then drop incoming segment.
E 40
I 40
D 62
	 * Generate an ACK dropping incoming segment.
E 40
	 * Make ACK reflect our state.
E 62
I 62
	 * Generate an ACK dropping incoming segment if it occupies
	 * sequence space, where the ACK reflects our state.
E 62
	 */
I 40
D 41
printf("tcp_input: dropafterack\n");
E 41
E 40
D 62
	if (tiflags & TH_RST)
E 62
I 62
D 117
	if ((tiflags&TH_RST) ||
	    tlen == 0 && (tiflags&(TH_SYN|TH_FIN)) == 0)
E 117
I 117
	if (tiflags & TH_RST)
E 117
E 62
		goto drop;
I 64
D 129
	if (tp->t_inpcb->inp_socket->so_options & SO_DEBUG)
		tcp_trace(TA_RESPOND, ostate, tp, &tcp_saveti, 0);
E 129
I 129
	m_freem(m);
E 129
E 64
D 48
	tcp_respond(ti, tp->rcv_nxt, tp->snd_nxt, TH_ACK);
E 48
I 48
D 125
	tcp_respond(tp, ti, tp->rcv_nxt, tp->snd_nxt, TH_ACK);
E 125
I 125
	tp->t_flags |= TF_ACKNOW;
	(void) tcp_output(tp);
E 125
E 48
D 39
	goto drop;
E 39
I 39
	return;
E 39

dropwithreset:
I 50
D 93
	if (om)
E 93
I 93
	if (om) {
E 93
D 61
		m_free(om);
E 61
I 61
		(void) m_free(om);
I 93
		om = 0;
	}
E 93
E 61
E 50
I 40
D 41
printf("tcp_input: dropwithreset\n");
E 41
E 40
	/*
D 40
	 * Generate a RST, then drop incoming segment.
E 40
I 40
	 * Generate a RST, dropping incoming segment.
E 40
	 * Make ACK acceptable to originator of segment.
I 112
	 * Don't bother to respond if destination was broadcast.
E 112
	 */
D 112
	if (tiflags & TH_RST)
E 112
I 112
	if ((tiflags & TH_RST) || in_broadcast(ti->ti_dst))
E 112
		goto drop;
	if (tiflags & TH_ACK)
D 34
		tcp_respond(ti, 0, ti->ti_ack, TH_RST);
E 34
I 34
D 48
		tcp_respond(ti, (tcp_seq)0, ti->ti_ack, TH_RST);
E 48
I 48
		tcp_respond(tp, ti, (tcp_seq)0, ti->ti_ack, TH_RST);
E 48
E 34
	else {
		if (tiflags & TH_SYN)
			ti->ti_len++;
D 34
		tcp_respond(ti, ti->ti_seq+ti->ti_len, 0, TH_RST|TH_ACK);
E 34
I 34
D 48
		tcp_respond(ti, ti->ti_seq+ti->ti_len, (tcp_seq)0, TH_RST|TH_ACK);
E 48
I 48
D 62
		tcp_respond(tp, ti, ti->ti_seq+ti->ti_len, (tcp_seq)0, TH_RST|TH_ACK);
E 62
I 62
		tcp_respond(tp, ti, ti->ti_seq+ti->ti_len, (tcp_seq)0,
		    TH_RST|TH_ACK);
E 62
E 48
E 34
	}
I 89
	/* destroy temporarily created socket */
	if (dropsocket)
		(void) soabort(so);
E 89
D 39
	goto drop;
E 39
I 39
	return;
E 39

E 33
drop:
I 92
	if (om)
		(void) m_free(om);
E 92
I 44
D 45
printf("drop\n");
E 45
E 44
I 40
D 41
printf("tcp_input: drop\n");
E 41
E 40
I 33
	/*
	 * Drop space held by incoming segment and return.
	 */
I 64
	if (tp && (tp->t_inpcb->inp_socket->so_options & SO_DEBUG))
		tcp_trace(TA_DROP, ostate, tp, &tcp_saveti, 0);
E 64
E 33
	m_freem(m);
I 89
	/* destroy temporarily created socket */
	if (dropsocket)
		(void) soabort(so);
E 89
I 43
	return;
I 49
}

D 50
/*
 * Pull the character before the urgent pointer into
 * the TCP control block for presentation as out-of-band data.
 * We leave ti->ti_len reflecting the out-of-band data,
 * so that sequencing will continue to work.
 */
tcp_pulloutofband(so, ti)
	struct socket *so;
	struct tcpiphdr *ti;
E 50
I 50
D 103
tcp_dooptions(tp, om)
E 103
I 103
tcp_dooptions(tp, om, ti)
E 103
	struct tcpcb *tp;
	struct mbuf *om;
I 103
	struct tcpiphdr *ti;
E 103
E 50
{
D 50
	register struct mbuf *m;
	int cnt = sizeof (struct tcpiphdr) + ti->ti_urp - 1;
	
	m = dtom(ti);
	while (cnt >= 0) {
		if (m->m_len > cnt) {
			char *cp = mtod(m, caddr_t) + cnt;
			struct tcpcb *tp = sototcpcb(so);
E 50
I 50
	register u_char *cp;
	int opt, optlen, cnt;
E 50

D 50
			tp->t_oobc = *cp;
			tp->t_haveoob = 1;
			bcopy(cp+1, cp, m->m_len - cnt - 1);
			m->m_len--;
			return;
E 50
I 50
	cp = mtod(om, u_char *);
	cnt = om->m_len;
	for (; cnt > 0; cnt -= optlen, cp += optlen) {
		opt = cp[0];
		if (opt == TCPOPT_EOL)
			break;
		if (opt == TCPOPT_NOP)
			optlen = 1;
D 95
		else
E 95
I 95
		else {
E 95
			optlen = cp[1];
I 95
			if (optlen <= 0)
				break;
		}
E 95
		switch (opt) {

		default:
			break;

		case TCPOPT_MAXSEG:
			if (optlen != 4)
				continue;
I 103
			if (!(ti->ti_flags & TH_SYN))
				continue;
E 103
			tp->t_maxseg = *(u_short *)(cp + 2);
D 65
#if vax
E 65
I 65
D 79
#if vax || pdp11
E 79
I 79
D 83
#if vax || pdp11 || ns16032
E 83
E 79
E 65
D 61
			tp->t_maxseg = ntohs(tp->t_maxseg);
E 61
I 61
			tp->t_maxseg = ntohs((u_short)tp->t_maxseg);
I 103
			tp->t_maxseg = MIN(tp->t_maxseg, tcp_mss(tp));
E 103
E 61
D 83
#endif
E 83
			break;
D 76
			
#ifdef TCPTRUEOOB
		case TCPOPT_WILLOOB:
			tp->t_flags |= TF_DOOOB;
printf("tp %x dooob\n", tp);
			break;

		case TCPOPT_OOBDATA: {
			int seq;
I 51
			register struct socket *so = tp->t_inpcb->inp_socket;
			tcp_seq mark;
E 51

D 51
			if (optlen != 4)
E 51
I 51
			if (optlen != 8)
E 51
				continue;
			seq = cp[2];
			if (seq < tp->t_iobseq)
				seq += 256;
printf("oobdata cp[2] %d iobseq %d seq %d\n", cp[2], tp->t_iobseq, seq);
			if (seq - tp->t_iobseq > 128) {
printf("bad seq\n");
				tp->t_oobflags |= TCPOOB_OWEACK;
				break;
			}
			tp->t_iobseq = cp[2];
			tp->t_iobc = cp[3];
I 51
			mark = *(tcp_seq *)(cp + 4);
D 65
#if vax
E 65
I 65
#if vax || pdp11
E 65
			mark = ntohl(mark);
#endif
			so->so_oobmark = so->so_rcv.sb_cc + (mark-tp->rcv_nxt);
			if (so->so_oobmark == 0)
				so->so_state |= SS_RCVATMARK;
E 51
printf("take oob data %x input iobseq now %x\n", tp->t_iobc, tp->t_iobseq);
D 51
			sohasoutofband(tp->t_inpcb->inp_socket);
E 51
I 51
			sohasoutofband(so);
E 51
			break;
E 50
		}
D 50
		cnt -= m->m_len;
		m = m->m_next;
		if (m == 0)
E 50
I 50

		case TCPOPT_OOBACK: {
			int seq;

			if (optlen != 4)
				continue;
			if (tp->t_oobseq != cp[2]) {
printf("wrong ack\n");
				break;
			}
printf("take oob ack %x and cancel rexmt\n", cp[2]);
			tp->t_oobflags &= ~TCPOOB_NEEDACK;
			tp->t_timer[TCPT_OOBREXMT] = 0;
E 50
			break;
I 50
		}
#endif TCPTRUEOOB
E 76
		}
E 50
	}
D 50
	panic("tcp_pulloutofband");
E 50
I 50
D 61
	m_free(om);
E 61
I 61
	(void) m_free(om);
E 61
I 51
}

/*
 * Pull out of band byte out of a segment so
 * it doesn't appear in the user's data queue.
 * It is still reflected in the segment length for
 * sequencing purposes.
 */
tcp_pulloutofband(so, ti)
	struct socket *so;
	struct tcpiphdr *ti;
{
	register struct mbuf *m;
D 60
	int cnt = sizeof (struct tcpiphdr) + ti->ti_urp - 1;
E 60
I 60
	int cnt = ti->ti_urp - 1;
E 60
	
	m = dtom(ti);
	while (cnt >= 0) {
		if (m->m_len > cnt) {
			char *cp = mtod(m, caddr_t) + cnt;
			struct tcpcb *tp = sototcpcb(so);

			tp->t_iobc = *cp;
			tp->t_oobflags |= TCPOOB_HAVEDATA;
D 61
			bcopy(cp+1, cp, m->m_len - cnt - 1);
E 61
I 61
			bcopy(cp+1, cp, (unsigned)(m->m_len - cnt - 1));
E 61
			m->m_len--;
			return;
		}
		cnt -= m->m_len;
		m = m->m_next;
		if (m == 0)
			break;
	}
	panic("tcp_pulloutofband");
E 51
E 50
E 49
E 43
D 33
	return;
E 33
D 110
}

/*
 * Insert segment ti into reassembly queue of tcp with
 * control block tp.  Return TH_FIN if reassembly now includes
 * a segment with FIN.
 */
D 34
tcp_reass(tp, ti, endp)
E 34
I 34
tcp_reass(tp, ti)
E 34
	register struct tcpcb *tp;
	register struct tcpiphdr *ti;
D 34
	int *endp;
E 34
{
	register struct tcpiphdr *q;
I 33
	struct socket *so = tp->t_inpcb->inp_socket;
E 33
D 42
	int flags = 0;		/* no FIN */
E 42
I 42
	struct mbuf *m;
	int flags;
E 42
D 37
	int overage;
E 37
I 33
D 69
COUNT(TCP_REASS);
E 69
E 33

	/*
D 35
	 * If no data in this segment may want
	 * to move data up to socket structure (if
	 * connection is now established).
E 35
I 35
	 * Call with ti==0 after become established to
	 * force pre-ESTABLISHED data up to user socket.
E 35
	 */
D 35
	if (ti->ti_len == 0) {
		m_freem(dtom(ti));
E 35
I 35
	if (ti == 0)
E 35
		goto present;
E 31
D 35
	}
E 35
D 13
	if (dataok) {
E 13
I 13
D 23
	if (dataok == 0)
		goto ctlonly;
E 23
E 13
D 31
/* text */
D 13
		if (n->t_len != 0)
D 11
			rcv_text(tp, n);
E 11
I 11
			tcp_text(tp, n);
E 11
/* urg */
		if (n->th_flags&TH_URG) {
			unsigned urgent;
E 13
I 13
D 23
	if (n->t_len == 0)
		goto notext;
	{ register int i;
	  register struct th *p, *q;
	  register struct mbuf *m;
	  int overage;
E 23
I 23
D 24
	if (dataok && n->t_len) {
E 24
I 24
D 26
	if (dataok && n->ti_len) {
E 26
I 26
	if (dataok && ti->ti_len) {
E 26
E 24
D 25
		register struct tcpiphdr *p, *q;
E 25
I 25
		register struct tcpiphdr *q;
E 25
		int overage;
E 31
E 23
E 13

D 13
			urgent = n->t_urp + n->t_seq;
			if (tp->rcv_nxt < urgent) {
				if (tp->rcv_urp <= tp->rcv_nxt)
					to_user(tp->t_ucb, UURGENT);
				tp->rcv_urp = urgent;
			}
		}
/* eol */
		if ((n->th_flags&TH_EOL) &&
		    (tp->tc_flags&TC_DROPPED_TXT) == 0 &&
		    tp->t_rcv_prev != (struct th *)tp) {
			/* mark last mbuf */
			m = dtom(tp->t_rcv_prev);
			if (m != NULL) {
				while (m->m_next != NULL)
					m = m->m_next;
				m->m_act =
				    (struct mbuf *)(m->m_off + m->m_len - 1);
			}
		}
	}
/* fin */
	if ((n->th_flags&TH_FIN) && (tp->tc_flags&TC_DROPPED_TXT) == 0) {
		int last;

		if ((tp->tc_flags&TC_FIN_RCVD) == 0) {
			/* do we really have fin ? */
			last = firstempty(tp);
			if (tp->t_rcv_prev == (struct th *)tp ||
			    last == t_end(tp->t_rcv_prev)) {
				tp->tc_flags |= TC_FIN_RCVD;
				netwakeup(tp->t_ucb);		/* poke */
			}
			if ((tp->tc_flags&TC_FIN_RCVD) &&
			    tp->rcv_nxt >= last) {
				tp->rcv_nxt = last + 1;		/* fin seq */
				tp->tc_flags |= TC_ACK_DUE;
			}
		} else
			tp->tc_flags |= TC_ACK_DUE;
	}

/* respond */
I 9
	sent = 0;
E 9
	if (tp->tc_flags&TC_ACK_DUE)
D 11
		sent = send_ctl(tp);
E 11
I 11
		sent = tcp_sndctl(tp);
E 11
D 9
	else if (tp->tc_flags&TC_NEW_WINDOW)
		sent = send(tp);
	else
		sent = 0;
E 9
I 9
	else if (tp->tc_flags&TC_NEW_WINDOW) {
		seq_t last = tp->snd_off;
		up = tp->t_ucb;
		for (m = up->uc_sbuf; m != NULL; m = m->m_next)
			last += m->m_len;
		if (tp->snd_nxt <= last || (tp->tc_flags&TC_SND_FIN))
D 12
			sent = send(tp);
E 12
I 12
			sent = tcp_send(tp);
E 12
	}
E 9

/* set for retrans */
	if (!sent && tp->snd_una < tp->snd_nxt &&
	    (tp->tc_flags&TC_CANCELLED)) {
		tp->t_rexmt = tp->t_xmtime;
		tp->t_rexmttl = T_REXMTTL;
		tp->t_rexmt_val = tp->t_rtl_val = tp->snd_lst;
		tp->tc_flags &= ~TC_CANCELLED;
	}
}

D 5
rcv_text(tp, t)
E 5
I 5
D 11
rcv_text(tp, n)
E 11
I 11
tcp_text(tp, n)
E 11
E 5
	register struct tcb *tp;
D 5
	register struct th *t;
E 5
I 5
	register struct th *n;
E 5
{
D 5
	register i;
E 5
I 5
	register int i;
E 5
	register struct th *p, *q;
D 5
	register struct mbuf *m, *n;
	struct th *savq;
	int last, j, k;
E 5
I 5
	register struct mbuf *m;
	int overage;
E 5
COUNT(RCV_TEXT);

E 13
D 5
	/* throw away any data we have already received */
	if ((i = tp->rcv_nxt - t->t_seq) > 0)  {
		if (i >= t->t_len)
			return;
		t->t_seq += i;
		t->t_len -= i;
		m_adj(dtom(t), i);
E 5
I 5
D 23
	/*
	 * Discard duplicate data already passed to user.
	 */
D 6
	if (n->t_seq < tp->rcv_nxt){
E 6
I 6
	if (SEQ_LT(n->t_seq, tp->rcv_nxt)) {
E 6
		i = tp->rcv_nxt - n->t_seq;
		if (i >= n->t_len)
D 13
			goto dropseg;
E 13
I 13
			goto notext;
E 13
		n->t_seq += i;
		n->t_len -= i;
		m_adj(dtom(n), i);
E 5
	}
E 23
I 23
D 31
/* eol */
D 26
		if ((thflags&TH_EOL)) {
E 26
I 26
		if ((tiflags&TH_EOL)) {
E 26
			register struct mbuf *m;
D 26
			for (m = dtom(n); m->m_next; m = m->m_next)
E 26
I 26
			for (m = dtom(ti); m->m_next; m = m->m_next)
E 26
				;
			m->m_act = (struct mbuf *)(mtod(m, caddr_t) - 1);
		}
E 31
I 31
	/*
	 * Find a segment which begins after this one does.
	 */
	for (q = tp->seg_next; q != (struct tcpiphdr *)tp;
	    q = (struct tcpiphdr *)q->ti_next)
		if (SEQ_GT(q->ti_seq, ti->ti_seq))
			break;
E 31
E 23

D 5
	last = t_end(t);                /* last seq # in incoming seg */
	i = rcv_resource(tp);           /* # buffers available to con */
E 5
I 5
D 23
	/*
	 * Find a segment which begins after this one does.
	 */
D 22
	for (q = tp->t_rcv_next; q != (struct th *)tp; q = q->t_next)
E 22
I 22
	for (q = tp->tcb_hd.seg_next; q != (struct th *)tp; q = q->t_next)
E 22
D 6
		if (q->t_seq > n->t_seq)
E 6
I 6
		if (SEQ_GT(q->t_seq, n->t_seq))
E 6
			break;
E 5

D 5
	/* count buffers in segment */

	for (m = dtom(t), j = 0; m != NULL; m = m->m_next)
		if (m->m_len != 0) {
        		j++;
			if (m->m_off > MMAXOFF)
				j += NMBPG;
E 5
I 5
	/*
	 * If there is a preceding segment, it may provide some of
	 * our data already.  If so, drop the data from the incoming
	 * segment.  If it provides all of our data, drop us.
	 */
	if (q->t_prev != (struct th *)tp) {
I 6
		/* conversion to int (in i) handles seq wraparound */
E 6
		i = q->t_prev->t_seq + q->t_prev->t_len - n->t_seq;
		if (i > 0) {
E 23
I 23
D 31
/* text */
		/*
		 * Discard duplicate data already passed to user.
		 */
D 24
		if (SEQ_LT(n->t_seq, tp->rcv_nxt)) {
			register int i = tp->rcv_nxt - n->t_seq;
E 23
			if (i >= n->t_len)
E 24
I 24
D 26
		if (SEQ_LT(n->ti_seq, tp->rcv_nxt)) {
			register int i = tp->rcv_nxt - n->ti_seq;
			if (i >= n->ti_len)
E 26
I 26
		if (SEQ_LT(ti->ti_seq, tp->rcv_nxt)) {
			register int i = tp->rcv_nxt - ti->ti_seq;
E 31
I 31
	/*
	 * If there is a preceding segment, it may provide some of
	 * our data already.  If so, drop the data from the incoming
	 * segment.  If it provides all of our data, drop us.
	 */
	if ((struct tcpiphdr *)q->ti_prev != (struct tcpiphdr *)tp) {
		register int i;
D 53
		q = (struct tcpiphdr *)(q->ti_prev);
E 53
I 53
		q = (struct tcpiphdr *)q->ti_prev;
E 53
		/* conversion to int (in i) handles seq wraparound */
		i = q->ti_seq + q->ti_len - ti->ti_seq;
		if (i > 0) {
E 31
			if (i >= ti->ti_len)
E 26
E 24
D 13
				goto dropseg;
E 13
I 13
D 23
				goto notext;	/* w/o setting TC_NET_KEEP */
E 13
			m_adj(dtom(tp), i);
			n->t_len -= i;
E 23
I 23
D 31
				goto notext;
E 23
D 24
			n->t_seq += i;
I 23
			n->t_len -= i;
E 24
I 24
D 26
			n->ti_seq += i;
			n->ti_len -= i;
E 24
			m_adj(dtom(n), i);
E 26
I 26
			ti->ti_seq += i;
E 31
I 31
				goto drop;
D 72
			m_adj(dtom(tp), i);
E 72
I 72
			m_adj(dtom(ti), i);
E 72
E 31
			ti->ti_len -= i;
D 31
			m_adj(dtom(ti), i);
E 31
I 31
			ti->ti_seq += i;
E 31
E 26
E 23
E 5
		}
I 31
		q = (struct tcpiphdr *)(q->ti_next);
	}
E 31
D 5

	/* not enough resources to process segment */

	if (j > i && netcb.n_bufs < netcb.n_lowat) {

		/* if segment preceeds top of seqeuncing queue, try to take
		   buffers from bottom of queue */

                q = tp->t_rcv_next;
		if (q != (struct th *)tp && tp->rcv_nxt < q->t_seq &&
		    t->t_seq < q->t_seq)

			for (k=j-i, p = tp->t_rcv_prev; k > 0 &&
			     p != (struct th *)tp; k--) {
				savq = p->t_prev;
				tcp_deq(p);
				i += m_freem(dtom(p));
				p = savq;
			}

		/* if still not enough room, drop text from end of segment */

		if (j > i) {

			for (m = dtom(t); i > 0 && m != NULL; i--)
				m = m->m_next;

        		while (m != NULL) {
        			t->t_len -= m->m_len;
        			last -= m->m_len;
        			m->m_len = 0;
        			m = m->m_next;
        		}
        		tp->tc_flags |= TC_DROPPED_TXT;
        		if (last < t->t_seq)
        			return;
        	}
E 5
D 23
	}
E 23

D 5
	/* merge incoming data into the sequence queue */

        q = tp->t_rcv_next;             /* -> top of sequencing queue */

        /* skip frags which new doesn't overlap at end */

        while ((q != (struct th *)tp) && (t->t_seq > t_end(q)))
        	q = q->t_next;

        if (q == (struct th *)tp) {     /* frag at end of chain */

		if (last >= tp->rcv_nxt) {
		        tp->tc_flags |= TC_NET_KEEP;
        	        tcp_enq(t, tp->t_rcv_prev);
E 5
I 5
D 23
	/*
	 * While we overlap succeeding segments trim them or,
	 * if they are completely covered, dequeue them.
	 */
D 6
	while (q != (struct th *)tp && n->t_seq + n->t_len > q->t_seq) {
E 6
I 6
	while (q != (struct th *)tp && SEQ_GT(n->t_seq + n->t_len, q->t_seq)) {
E 6
		i = (n->t_seq + n->t_len) - q->t_seq;
		if (i < q->t_len) {
			q->t_len -= i;
			m_adj(dtom(q), i);
			break;
E 23
I 23
D 31
		/*
		 * Find a segment which begins after this one does.
		 */
		for (q = tp->seg_next; q != (struct tcpiphdr *)tp;
D 24
		    q = q->t_next)
			if (SEQ_GT(q->t_seq, n->t_seq))
E 24
I 24
		    q = (struct tcpiphdr *)q->ti_next)
D 26
			if (SEQ_GT(q->ti_seq, n->ti_seq))
E 26
I 26
			if (SEQ_GT(q->ti_seq, ti->ti_seq))
E 26
E 24
				break;

		/*
		 * If there is a preceding segment, it may provide some of
		 * our data already.  If so, drop the data from the incoming
		 * segment.  If it provides all of our data, drop us.
		 */
D 24
		if (q->t_prev != (struct tcpiphdr *)tp) {
E 24
I 24
		if ((struct tcpiphdr *)q->ti_prev != (struct tcpiphdr *)tp) {
			register int i;
			q = (struct tcpiphdr *)(q->ti_prev);
E 24
			/* conversion to int (in i) handles seq wraparound */
D 24
			register int i =
			    q->t_prev->t_seq + q->t_prev->t_len - n->t_seq;
E 24
I 24
D 25
			i = q->ti_seq + q->ti_len - n->th_seq;
E 25
I 25
D 26
			i = q->ti_seq + q->ti_len - n->ti_seq;
E 26
I 26
			i = q->ti_seq + q->ti_len - ti->ti_seq;
E 26
E 25
E 24
			if (i > 0) {
D 24
				if (i >= n->t_len)
E 24
I 24
D 26
				if (i >= n->ti_len)
E 26
I 26
				if (i >= ti->ti_len)
E 26
E 24
					goto notext;
						/* w/o setting TC_NET_KEEP */
				m_adj(dtom(tp), i);
D 24
				n->t_len -= i;
				n->t_seq += i;
E 24
I 24
D 26
				n->ti_len -= i;
				n->ti_seq += i;
E 26
I 26
				ti->ti_len -= i;
				ti->ti_seq += i;
E 26
E 24
			}
I 24
			q = (struct tcpiphdr *)(q->ti_next);
E 31
I 31
	/*
	 * While we overlap succeeding segments trim them or,
	 * if they are completely covered, dequeue them.
	 */
D 53
	while (q != (struct tcpiphdr *)tp &&
	    SEQ_GT(ti->ti_seq + ti->ti_len, q->ti_seq)) {
E 53
I 53
	while (q != (struct tcpiphdr *)tp) {
E 53
		register int i = (ti->ti_seq + ti->ti_len) - q->ti_seq;
I 53
		if (i <= 0)
			break;
E 53
		if (i < q->ti_len) {
I 53
			q->ti_seq += i;
E 53
			q->ti_len -= i;
			m_adj(dtom(q), i);
			break;
E 31
E 24
E 23
E 5
		}
I 31
		q = (struct tcpiphdr *)q->ti_next;
D 52
		m_freem(dtom(q->ti_prev));
E 52
I 52
		m = dtom(q->ti_prev);
E 52
		remque(q->ti_prev);
I 52
		m_freem(m);
E 52
	}
E 31
I 5
D 23
		q = q->t_next;
		m_freem(dtom(q->t_prev));
		remque(q->t_prev);
	}
E 23
E 5

D 5
        } else {
E 5
I 5
D 23
	/*
	 * Stick new segment in its place.
	 */
	insque(n, q->t_prev);
D 7
/*
	tp->rcv_seqcnt += n->t_len;
*/
E 7
I 7
	tp->seqcnt += n->t_len;
E 7
E 5

D 5
		/* frag doesn't overlap any on chain */

        	if (last < q->t_seq) {
			tp->tc_flags |= TC_NET_KEEP;
        		tcp_enq(t, q->t_prev);

        	/* new overlaps beginning of next frag only */

        	} else if (last < t_end(q)) {
        		if ((i = last - q->t_seq + 1) < t->t_len) {
                		t->t_len -= i;
        			m_adj(dtom(t), -i);
				tp->tc_flags |= TC_NET_KEEP;
        			tcp_enq(t, q->t_prev);
        		}

        	/* new overlaps end of previous frag */

        	} else {
        		savq = q;
        		if (t->t_seq <= q->t_seq) {     /* complete cover */
        			savq = q->t_prev;
        			tcp_deq(q);
        			m_freem(dtom(q));

        		} else {                        /* overlap */
        			if ((i = t_end(q) - t->t_seq + 1) < t->t_len) {
                			t->t_seq += i;
                			t->t_len -= i;
                			m_adj(dtom(t), i);
				} else
					t->t_len = 0;
        		}

        	/* new overlaps at beginning of successor frags */

        		q = savq->t_next;
        		while ((q != (struct th *)tp) && (t->t_len != 0) &&
        			(q->t_seq < last))

        			/* complete cover */

        			if (t_end(q) <= last) {
        				p = q->t_next;
        				tcp_deq(q);
        				m_freem(dtom(q));
        				q = p;

        			} else {        /* overlap */

        				if ((i = last - q->t_seq + 1) < t->t_len) {
                				t->t_len -= i;
                				m_adj(dtom(t), -i);
					} else
						t->t_len = 0;
        				break;
        			}

        	/* enqueue whatever is left of new before successors */

        		if (t->t_len != 0) {
				tp->tc_flags |= TC_NET_KEEP;
        			tcp_enq(t, savq);
			}
        	}
        }

	/* set to ack completed data (no gaps) */

	tp->rcv_nxt = firstempty(tp);
	tp->tc_flags |= TC_ACK_DUE;

E 5
D 22
#ifdef notdef
E 22
D 5
	/* THIS CODE CANT POSSIBLY WORK */
	/* if any room remaining in rcv buf, take any unprocessed
	   messages and schedule for later processing */
E 5
I 5
	/*
	 * Calculate available space and discard segments for
	 * which there is too much.
	 */
D 22
	q = tp->t_rcv_prev;
E 22
I 22
	q = tp->tcb_hd.seg_prev;
E 22
D 6
	overage = (tp->t_socket->uc_rcc + tp->rcv_seqcnt) - tp->t_socket->uc_rhiwat;
E 6
I 6
	overage = 
D 13
	    (tp->t_socket->uc_rcc + tp->rcv_seqcnt) - tp->t_socket->uc_rhiwat;
E 13
I 13
D 22
	    (tp->t_ucb->uc_rcc + tp->rcv_seqcnt) - tp->t_ucb->uc_rhiwat;
E 22
I 22
	    (tp->t_socket->so_rcv.sb_cc /* + tp->rcv_seqcnt XXX */) -
		tp->t_socket->so_rcv.sb_hiwat;
E 22
E 13
E 6
	if (overage > 0)
		for (;;) {
			i = MIN(q->t_len, overage);
			overage -= i;
			q->t_len -= i;
			m_adj(q, -i);
			if (q == n)
				tp->tc_flags |= TC_DROPPED_TXT;
			if (q->t_len)
E 23
I 23
D 31
		/*
		 * While we overlap succeeding segments trim them or,
		 * if they are completely covered, dequeue them.
		 */
		while (q != (struct tcpiphdr *)tp &&
D 24
		    SEQ_GT(n->t_seq + n->t_len, q->t_seq)) {
			register int i = (n->t_seq + n->t_len) - q->t_seq;
			if (i < q->t_len) {
				q->t_len -= i;
E 24
I 24
D 26
		    SEQ_GT(n->ti_seq + n->ti_len, q->ti_seq)) {
			register int i = (n->ti_seq + n->ti_len) - q->ti_seq;
E 26
I 26
		    SEQ_GT(ti->ti_seq + ti->ti_len, q->ti_seq)) {
			register int i = (ti->ti_seq + ti->ti_len) - q->ti_seq;
E 26
			if (i < q->ti_len) {
				q->ti_len -= i;
E 24
				m_adj(dtom(q), i);
E 23
				break;
D 23
			if (q == n)
D 6
				printf("tcp_text dropall\n");
E 6
I 6
				panic("tcp_text dropall");
E 6
			q = q->t_prev;
			remque(q->t_next);
E 23
I 23
			}
D 24
			q = q->t_next;
			m_freem(dtom(q->t_prev));
			remque(q->t_prev);
E 24
I 24
			q = (struct tcpiphdr *)q->ti_next;
			m_freem(dtom(q->ti_prev));
			remque(q->ti_prev);
E 24
E 23
		}
E 31
I 31
	/*
	 * Stick new segment in its place.
	 */
	insque(ti, q->ti_prev);
D 33
	tp->seqcnt += ti->ti_len;
E 33
I 33
D 35
	tp->t_seqcnt += ti->ti_len;
E 35
E 33
E 31
D 22
#endif
E 22
E 5

D 5
	i = rcv_resource(tp);

	while ((m = tp->t_rcv_unack) != NULL && i > 0) {

		/* schedule work request */

		t = (struct th *)((int)m + m->m_off);
		j = (t->t_off << 2) + sizeof(struct ip);
		m->m_off += j;
		m->m_len -= j;
		tp->t_rcv_unack = m->m_act;
		m->m_act = (struct mbuf *)0;
		netstat.t_unack++;
		tcp_work(INRECV, 0, tp, t);

		/* remaining buffer space */

		for (n = m; n != NULL; n = n->m_next)
			i--;
E 5
I 5
D 23
	/*
D 6
	 * Advance rcv_next through newly
	 * completed sequence space and force ACK.
E 6
I 6
	 * Advance rcv_next through
	 * newly completed sequence space
	 * and return forcing an ack.
E 6
	 */
	while (n->t_seq == tp->rcv_nxt) {
I 6
		/* present data belongs here */
E 6
		tp->rcv_nxt += n->t_len;
		n = n->t_next;
		if (n == (struct th *)tp)
			break;
E 5
	}
D 5
#endif
E 5
I 5
	tp->tc_flags |= (TC_ACK_DUE|TC_NET_KEEP);
D 13
	return;
E 13
I 13
	}
notext:
I 15
D 22
urgeolfin:
E 22
E 15
/* urg */
E 23
I 23
D 31
		/*
		 * Stick new segment in its place.
		 */
D 24
		insque(n, q->t_prev);
		tp->seqcnt += n->t_len;
E 24
I 24
D 26
		insque(n, q->ti_prev);
		tp->seqcnt += n->ti_len;
E 26
I 26
		insque(ti, q->ti_prev);
		tp->seqcnt += ti->ti_len;
E 26
E 24
E 23
D 22
	if (n->th_flags&TH_URG) {
		unsigned urgent;
E 22
E 13

D 13
dropseg:
D 6
	/* don't set TC_NET_KEEP */
E 6
I 6
	/* don't set TC_NET_KEEP, so that mbuf's will get dropped */
E 6
	return;
E 5
}
E 13
I 13
D 22
		urgent = n->t_urp + n->t_seq;
		if (tp->rcv_nxt < urgent) {
			if (tp->rcv_urp <= tp->rcv_nxt)
				to_user(tp->t_ucb, UURGENT);
			tp->rcv_urp = urgent;
E 22
I 22
D 23
	if (thflags & (TH_URG|TH_EOL|TH_FIN)) {
		if (thflags&TH_URG) {
			unsigned urgent;

			urgent = n->t_urp + n->t_seq;
			if (tp->rcv_nxt < urgent) {
				if (tp->rcv_urp <= tp->rcv_nxt) {
					/* DO SOMETHING WITH URGENT!!! ### */
				}
				tp->rcv_urp = urgent;
E 23
I 23
		/*
		 * Calculate available space and discard segments for
		 * which there is too much.
		 */
		overage = 
		    (so->so_rcv.sb_cc /*XXX+tp->rcv_seqcnt*/) - so->so_rcv.sb_hiwat;
		if (overage > 0) {
			q = tp->seg_prev;
			for (;;) {
D 24
				register int i = MIN(q->t_len, overage);
E 24
I 24
				register int i = MIN(q->ti_len, overage);
E 24
				overage -= i;
D 24
				q->t_len -= i;
E 24
I 24
				q->ti_len -= i;
E 24
D 25
				m_adj(q, -i);
E 25
I 25
				m_adj(dtom(q), -i);
E 25
D 24
				if (q->t_len)
E 24
I 24
				if (q->ti_len)
E 24
					break;
D 26
				if (q == n)
E 26
I 26
				if (q == ti)
E 26
					panic("tcp_text dropall");
D 24
				q = q->t_prev;
				remque(q->t_next);
E 24
I 24
				q = (struct tcpiphdr *)q->ti_prev;
				remque(q->ti_next);
E 24
E 23
			}
E 22
		}
D 22
	}
E 22
D 23
/* eol */
D 22
	if ((n->th_flags&TH_EOL) &&
	    (tp->tc_flags&TC_DROPPED_TXT) == 0 &&
	    tp->t_rcv_prev != (struct th *)tp) {
		/* mark last mbuf */
		m = dtom(tp->t_rcv_prev);
		if (m != NULL) {
			while (m->m_next != NULL)
				m = m->m_next;
			m->m_act =
			    (struct mbuf *)(m->m_off + m->m_len - 1);
E 22
I 22
		if ((thflags&TH_EOL) &&
		    (tp->tc_flags&TC_DROPPED_TXT) == 0 &&
		    tp->tcb_hd.seg_prev != (struct th *)tp) {
			/* mark last mbuf */
			m = dtom(tp->tcb_hd.seg_prev);
			if (m != NULL) {
				while (m->m_next != NULL)
					m = m->m_next;
				m->m_act =
				    (struct mbuf *)(m->m_off + m->m_len - 1);
			}
E 23
I 23

		/*
		 * Advance rcv_next through newly completed sequence space.
		 */
D 24
		while (n->t_seq == tp->rcv_nxt) {
			tp->rcv_nxt += n->t_len;
			n = n->t_next;
E 24
I 24
D 26
		while (n->ti_seq == tp->rcv_nxt) {
			tp->rcv_nxt += n->ti_len;
			n = (struct tcpiphdr *)n->ti_next;
E 24
			if (n == (struct tcpiphdr *)tp)
E 26
I 26
		while (ti->ti_seq == tp->rcv_nxt) {
			tp->rcv_nxt += ti->ti_len;
			ti = (struct tcpiphdr *)ti->ti_next;
			if (ti == (struct tcpiphdr *)tp)
E 31
I 31
D 40
	/*
D 35
	 * Calculate available space and discard segments for
	 * which there is too much.
	 */
	overage = 
D 33
	    (so->so_rcv.sb_cc + tp->seqcnt) - so->so_rcv.sb_hiwat;
E 33
I 33
	    (so->so_rcv.sb_cc + tp->t_seqcnt) - so->so_rcv.sb_hiwat;
E 33
	if (overage > 0) {
		q = tp->seg_prev;
		for (;;) {
			register int i = MIN(q->ti_len, overage);
			overage -= i;
D 33
			tp->seqcnt -= i;
E 33
I 33
			tp->t_seqcnt -= i;
E 33
			q->ti_len -= i;
			m_adj(dtom(q), -i);
			if (q->ti_len)
E 31
E 26
				break;
I 31
			if (q == ti)
D 32
				panic("tcp_text dropall");
E 32
I 32
				panic("tcp_reass dropall");
E 32
			q = (struct tcpiphdr *)q->ti_prev;
			remque(q->ti_next);
E 31
E 23
E 22
		}
D 22
	}
E 22
D 23
ctlonly:
E 23
I 23
D 31
/* urg */
D 26
		if (thflags&TH_URG) {
E 26
I 26
		if (tiflags&TH_URG) {
E 26
			/* ... */
			if (SEQ_GT(urgent, tp->rcv_urp))
				tp->rcv_urp = urgent;
		}
		tp->tc_flags |= (TC_ACK_DUE|TC_NET_KEEP);
E 31
	}
D 31
notext:
E 23
/* fin */
D 22
	if ((n->th_flags&TH_FIN) && (tp->tc_flags&TC_DROPPED_TXT) == 0) {
		seq_t last;
E 22
I 22
D 23
		if ((thflags&TH_FIN) &&
		    (tp->tc_flags&TC_DROPPED_TXT) == 0) {
			seq_t last;
E 22
E 13

I 7
D 13
#define	socket		ucb			/* ### */
#define	t_socket	t_ucb			/* ### */
E 13
I 13
D 22
		if ((tp->tc_flags&TC_FIN_RCVD) == 0) {
			/* do we really have fin ? */
			last = firstempty(tp);
			if (tp->t_rcv_prev == (struct th *)tp ||
			    last == t_end(tp->t_rcv_prev)) {
				tp->tc_flags |= TC_FIN_RCVD;
				netwakeup(tp->t_ucb);		/* poke */
			}
			if ((tp->tc_flags&TC_FIN_RCVD) &&
			    tp->rcv_nxt >= last) {
				tp->rcv_nxt = last + 1;		/* fin seq */
E 22
I 22
			if ((tp->tc_flags&TC_FIN_RCVD) == 0) {
				/* do we really have fin ? */
				last = firstempty(tp);
				if (tp->tcb_hd.seg_prev == (struct th *)tp ||
				    last == t_end(tp->tcb_hd.seg_prev)) {
					tp->tc_flags |= TC_FIN_RCVD;
					sowakeup(tp->t_socket); /* ### */
				}
				if ((tp->tc_flags&TC_FIN_RCVD) &&
				    tp->rcv_nxt >= last) {
					tp->rcv_nxt = last + 1;
					tp->tc_flags |= TC_ACK_DUE;
				}
			} else
E 22
				tp->tc_flags |= TC_ACK_DUE;
E 23
I 23
D 26
	if ((thflags&TH_FIN) && past == tp->rcv_nxt) {
E 26
I 26
	if ((tiflags&TH_FIN) && past == tp->rcv_nxt) {
E 26
		if ((tp->tc_flags&TC_FIN_RCVD) == 0) {
			tp->tc_flags |= TC_FIN_RCVD;
			sorwakeup(so);
			tp->rcv_nxt++;
E 23
D 22
			}
		} else
			tp->tc_flags |= TC_ACK_DUE;
E 22
I 22
		}
I 23
		tp->tc_flags |= TC_ACK_DUE;
E 23
E 22
	}
E 13
D 22

E 22
I 13
/* respond */
	sent = 0;
	if (tp->tc_flags&TC_ACK_DUE)
		sent = tcp_sndctl(tp);
D 22
	else if (tp->tc_flags&TC_NEW_WINDOW) {
		seq_t last = tp->snd_off;
		for (m = tp->t_ucb->uc_sbuf; m != NULL; m = m->m_next)	/*###*/
			last += m->m_len;				/*###*/
		if (tp->snd_nxt <= last || (tp->tc_flags&TC_SND_FIN))
E 22
I 22
	else if ((tp->tc_flags&TC_NEW_WINDOW))
D 23
		if (tp->snd_nxt <= tp->snd_off + tp->t_socket->so_snd.sb_cc ||
E 23
I 23
		if (tp->snd_nxt <= tp->snd_off + so->so_snd.sb_cc ||
E 23
		    (tp->tc_flags&TC_SND_FIN))
E 22
			sent = tcp_send(tp);
E 31
D 22
	}
E 22

D 31
/* set for retrans */
	if (!sent && tp->snd_una < tp->snd_nxt &&
	    (tp->tc_flags&TC_CANCELLED)) {
		tp->t_rexmt = tp->t_xmtime;
		tp->t_rexmttl = T_REXMTTL;
		tp->t_rexmt_val = tp->t_rtl_val = tp->snd_lst;
		tp->tc_flags &= ~TC_CANCELLED;
E 31
I 31
	/*
E 35
	 * Advance rcv_next through newly completed sequence space.
	 */
	while (ti->ti_seq == tp->rcv_nxt) {
		tp->rcv_nxt += ti->ti_len;
		flags = ti->ti_flags & TH_FIN;
		ti = (struct tcpiphdr *)ti->ti_next;
		if (ti == (struct tcpiphdr *)tp)
			break;
E 31
	}
D 15
}
E 15
I 15
D 31
/* present data to user */
D 23
	{ register struct mbuf **mp;
D 22
	  register struct ucb *up = tp->t_ucb;
E 22
I 22
	  register struct socket *so = tp->t_socket;
E 22
	  seq_t ready;
E 15

E 13
E 7
D 15
present_data(tp)
	register struct tcb *tp;
{
	register struct th *t;
D 7
	register struct ucb *up;
E 7
I 7
D 13
	register struct socket *up;
E 13
I 13
	register struct ucb *up;
E 13
E 7
	register struct mbuf *m, **mp;
	seq_t ready;
COUNT(PRESENT_DATA);

E 15
	/* connection must be synced and data available for user */
E 23
D 7
	if (((tp->tc_flags&TC_SYN_ACKED) == 0) ||
	    (t = tp->t_rcv_next) == (struct th *)tp)
E 7
I 7
	if ((tp->tc_flags&TC_SYN_ACKED) == 0)
E 7
		return;
E 31
I 31

E 40
present:
	/*
D 40
	 * Present data to user.
E 40
I 40
	 * Present data to user, advancing rcv_nxt through
	 * completed sequence space.
E 40
	 */
D 33
	if (tp->t_state < ESTAB)
E 33
I 33
D 42
	if (tp->t_state < TCPS_ESTABLISHED)
E 42
I 42
	if (TCPS_HAVERCVDSYN(tp->t_state) == 0)
E 42
E 33
D 40
		return (flags);
E 40
I 40
		return (0);
E 40
E 31
D 7
	up = tp->t_ucb;
	ready = firstempty(tp);     /* seq # of last complete datum */
E 7
I 7
D 13
	up = tp->t_socket;
E 13
I 13
D 22
	up = tp->t_ucb;
E 13
E 7
	mp = &up->uc_rbuf;
E 22
I 22
D 23
	so = tp->t_socket;
	mp = &so->so_rcv.sb_mb;
E 22
	while (*mp)
		mp = &(*mp)->m_next;
D 7
	while (up->uc_rsize < up->uc_rcv && t != (struct th *) tp &&
	    t_end(t) < ready) {
		tcp_deq(t);
E 7
I 7
D 15
	t = tp->t_rcv_next;
E 15
I 15
D 22
	n = tp->t_rcv_next;
E 22
I 22
	n = tp->tcb_hd.seg_next;
E 22
E 15
	/* SHOULD PACK DATA IN HERE */
D 15
	while (t != (struct th *)tp && t->t_seq < tp->rcv_nxt) {
		remque(t);
E 7
		m = dtom(t);
I 7
		up->uc_rcc += t->t_len;
		tp->seqcnt -= t->t_len;
E 15
I 15
	while (n != (struct th *)tp && n->t_seq < tp->rcv_nxt) {
E 23
I 23
D 26
	n = tp->seg_next;
D 24
	while (n != (struct tcpiphdr *)tp && n->t_seq < tp->rcv_nxt) {
E 24
I 24
	while (n != (struct tcpiphdr *)tp && n->ti_seq < tp->rcv_nxt) {
E 24
E 23
		remque(n);
D 23
		m = dtom(n);
D 22
		up->uc_rcc += n->t_len;
E 22
I 22
		so->so_rcv.sb_cc += n->t_len;
E 23
I 23
D 25
		sbappend(so->so_rcv, dtom(n));
E 25
I 25
		sbappend(&so->so_rcv, dtom(n));
E 25
E 23
E 22
D 24
		tp->seqcnt -= n->t_len;
E 24
I 24
		tp->seqcnt -= n->ti_len;
E 26
I 26
	ti = tp->seg_next;
D 40
	while (ti != (struct tcpiphdr *)tp && ti->ti_seq < tp->rcv_nxt) {
E 40
I 40
D 42
	while (ti != (struct tcpiphdr *)tp && ti->ti_seq == tp->rcv_nxt) {
E 42
I 42
	if (ti == (struct tcpiphdr *)tp || ti->ti_seq != tp->rcv_nxt)
		return (0);
	if (tp->t_state == TCPS_SYN_RECEIVED && ti->ti_len)
		return (0);
	do {
E 42
		tp->rcv_nxt += ti->ti_len;
		flags = ti->ti_flags & TH_FIN;
D 41
printf("move %d bytes to user; rcv_nxt now %x\n", ti->ti_len, tp->rcv_nxt);
E 41
E 40
		remque(ti);
D 42
		sbappend(&so->so_rcv, dtom(ti));
E 42
I 42
		m = dtom(ti);
E 42
D 33
		tp->seqcnt -= ti->ti_len;
E 26
E 24
E 15
D 23
		if (tp->seqcnt < 0) panic("present_data");
E 23
I 23
		if (tp->seqcnt < 0)
E 33
I 33
D 35
		tp->t_seqcnt -= ti->ti_len;
		if (tp->t_seqcnt < 0)
E 33
D 31
			panic("tcp_input present");
E 31
I 31
			panic("tcp_reass");
E 35
E 31
E 23
E 7
D 15
		t = t->t_next;
E 15
I 15
D 24
		n = n->t_next;
E 24
I 24
D 26
		n = (struct tcpiphdr *)n->ti_next;
E 26
I 26
		ti = (struct tcpiphdr *)ti->ti_next;
E 26
E 24
E 15
D 23
		while (m) {
			if (m->m_len == 0) {
D 16
				m = m_free(m);
				continue;
E 16
I 16
				MFREE(m, *mp);
			} else {
				*mp = m;
				mp = &m->m_next;
E 16
			}
D 7
			up->uc_rsize++;
			if (m->m_off > MMAXOFF)
				up->uc_rsize += NMBPG;
			if (*mp == 0)
				*mp = m;
E 7
I 7
D 16
			*mp = m;
E 7
			mp = &m->m_next;
E 16
			m = *mp;
		}
E 23
D 42
	}
D 7
	if (up->uc_rsize != 0)
E 7
I 7
D 22
	if (up->uc_rcc != 0)
E 7
		netwakeup(up);
D 7
	/*
	 * Let user know about foreign tcp close if no more data.
	 */
	if ((tp->tc_flags&TC_FIN_RCVD) && (tp->tc_flags&TC_USR_CLOSED) == 0 &&
	    rcv_empty(tp))
		to_user(up, UCLOSED);
E 7
I 7
	if ((tp->tc_flags&TC_FIN_RCVD) &&			/* ### */
	    (tp->tc_flags&TC_USR_CLOSED) == 0 &&		/* ### */
	    rcv_empty(tp))					/* ### */
		to_user(up, UCLOSED);				/* ### */
E 22
I 22
D 23
	sowakeup(so);		/* should be macro/conditional */
E 22
I 15
	}
I 22
}

tcp_drain()
{

E 23
I 23
D 32
	sorwakeup(so);
E 32
I 32
	if (so->so_state & SS_CANTRCVMORE)
		sbflush(&so->so_rcv);
	else
		sorwakeup(so);
E 42
I 42
		if (so->so_state & SS_CANTRCVMORE)
D 61
			(void) m_freem(m);
E 61
I 61
			m_freem(m);
E 61
D 78
		else
E 78
I 78
D 86
		else {
SBCHECK(&so->so_rcv, "tcp_input before");
E 86
I 86
		else
E 86
E 78
			sbappend(&so->so_rcv, m);
I 78
D 86
SBCHECK(&so->so_rcv, "tcp_input after");
		}
E 86
E 78
	} while (ti != (struct tcpiphdr *)tp && ti->ti_seq == tp->rcv_nxt);
	sorwakeup(so);
E 42
E 32
I 31
	return (flags);
drop:
I 40
D 41
printf("tcp_reass drop\n");
E 41
E 40
	m_freem(dtom(ti));
D 42
	return (flags);
E 42
I 42
	return (0);
E 110
I 103
}

/*
 *  Determine a reasonable value for maxseg size.
 *  If the route is known, use one that can be handled
 *  on the given interface without forcing IP to fragment.
D 109
 *  If bigger than a page (CLSIZE), round down to nearest pagesize
E 109
I 109
D 126
 *  If bigger than a page (CLBYTES), round down to nearest pagesize
E 109
 *  to utilize pagesize mbufs.
E 126
I 126
 *  If bigger than an mbuf cluster (MCLBYTES), round down to nearest size
 *  to utilize large mbufs.
E 126
 *  If interface pointer is unavailable, or the destination isn't local,
D 109
 *  use a conservative size (512 or the default IP max size),
E 109
I 109
 *  use a conservative size (512 or the default IP max size, but no more
 *  than the mtu of the interface through which we route),
E 109
 *  as we can't discover anything about intervening gateways or networks.
I 130
 *  We also initialize the congestion/slow start window to be a single
 *  segment if the destination isn't local; this information should
 *  probably all be saved with the routing entry at the transport level.
E 130
 *
 *  This is ugly, and doesn't belong at this level, but has to happen somehow.
 */
tcp_mss(tp)
D 109
register struct tcpcb *tp;
E 109
I 109
	register struct tcpcb *tp;
E 109
{
	struct route *ro;
	struct ifnet *ifp;
	int mss;
	struct inpcb *inp;

	inp = tp->t_inpcb;
	ro = &inp->inp_route;
	if ((ro->ro_rt == (struct rtentry *)0) ||
	    (ifp = ro->ro_rt->rt_ifp) == (struct ifnet *)0) {
		/* No route yet, so try to acquire one */
		if (inp->inp_faddr.s_addr != INADDR_ANY) {
			ro->ro_dst.sa_family = AF_INET;
			((struct sockaddr_in *) &ro->ro_dst)->sin_addr =
				inp->inp_faddr;
			rtalloc(ro);
		}
		if ((ro->ro_rt == 0) || (ifp = ro->ro_rt->rt_ifp) == 0)
D 104
			return (MIN(IP_MSS - sizeof(struct tcpiphdr), 512));
E 104
I 104
			return (TCP_MSS);
E 104
	}

	mss = ifp->if_mtu - sizeof(struct tcpiphdr);
D 126
#if	(CLBYTES & (CLBYTES - 1)) == 0
	if (mss > CLBYTES)
		mss &= ~(CLBYTES-1);
E 126
I 126
#if	(MCLBYTES & (MCLBYTES - 1)) == 0
	if (mss > MCLBYTES)
		mss &= ~(MCLBYTES-1);
E 126
#else
D 126
	if (mss > CLBYTES)
		mss = mss / CLBYTES * CLBYTES;
E 126
I 126
	if (mss > MCLBYTES)
		mss = mss / MCLBYTES * MCLBYTES;
E 126
#endif
D 109
	if (in_localaddr(tp->t_inpcb->inp_faddr))
		return(mss);
E 109
I 109
	if (in_localaddr(inp->inp_faddr))
		return (mss);
I 131

E 131
E 109
D 104
	return (MIN(mss, MIN(IP_MSS - sizeof(struct tcpiphdr), 512)));
E 104
I 104
D 130
	return (MIN(mss, TCP_MSS));
E 130
I 130
	mss = MIN(mss, TCP_MSS);
	tp->snd_cwnd = mss;
	return (mss);
E 130
E 104
E 103
E 42
E 31
E 23
E 22
E 15
E 7
}
I 136

#if BSD<43
/* XXX this belongs in netinet/in.c */
in_localaddr(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
	register u_long mask;

	if (IN_CLASSA(i))
		mask = IN_CLASSA_NET;
	else if (IN_CLASSB(i))
		mask = IN_CLASSB_NET;
	else if (IN_CLASSC(i))
		mask = IN_CLASSC_NET;
	else
		return (0);

	i &= mask;
	for (ifp = ifnet; ifp; ifp = ifp->if_next) {
		if (ifp->if_addr.sa_family != AF_INET)
			continue;
		sin = (struct sockaddr_in *)&ifp->if_addr;
		if ((sin->sin_addr.s_addr & mask) == i)
			return (1);
	}
	return (0);
}
#endif
E 136
I 3
D 7

#ifdef TCPDEBUG
tdb_setup(tp, n, input, tdp)
	struct tcb *tp;
	register struct th *n;
	int input;
	register struct tcp_debug *tdp;
{

	tdp->td_tod = time;
	tdp->td_tcb = tp;
	tdp->td_old = tp->t_state;
	tdp->td_inp = input;
	tdp->td_tim = 0;
	tdp->td_new = -1;
	if (n) {
		tdp->td_sno = n->t_seq;
		tdp->td_ano = n->t_ackno;
		tdp->td_wno = n->t_win;
		tdp->td_lno = n->t_len;
		tdp->td_flg = n->th_flags;
	} else
		tdp->td_sno = tdp->td_ano = tdp->td_wno = tdp->td_lno =
		    tdp->td_flg = 0;
}

tdb_stuff(tdp, nstate)
	struct tcp_debug *tdp;
	int nstate;
{

	tdp->td_new = nstate;
	tcp_debug[tdbx++ % TDBSIZE] = *tdp;
	if (tcpconsdebug & 2)
		tcp_prt(tdp);
}
#endif
E 7
E 3
E 1

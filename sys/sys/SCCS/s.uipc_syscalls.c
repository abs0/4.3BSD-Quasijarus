h27807
s 00010/00005/00831
d D 7.5 88/06/29 17:18:16 bostic 71 70
c install approved copyright notice
e
s 00001/00001/00835
d D 7.4 88/01/20 15:32:01 bostic 70 69
c check all values of namelen against MLEN
e
s 00008/00002/00828
d D 7.3 88/01/07 13:29:08 bostic 69 68
c add Berkeley header
e
s 00000/00004/00830
d D 7.2 87/07/29 17:31:42 mckusick 68 67
c delete unneeded header files
e
s 00001/00001/00833
d D 7.1 86/06/05 00:17:34 mckusick 67 66
c 4.3BSD release version
e
s 00007/00001/00827
d D 6.17 86/05/19 16:39:13 karels 66 65
c make errors on non-blocking connect agree with doc
e
s 00005/00005/00823
d D 6.16 86/05/10 22:54:50 karels 65 64
c don't retry connect (or disconnect) if still in progress
e
s 00004/00004/00824
d D 6.15 86/02/23 23:12:53 karels 64 63
c lint
e
s 00001/00001/00827
d D 6.14 86/02/20 16:04:04 karels 63 62
c remove unused sonam arg to unp_connect2
e
s 00002/00009/00826
d D 6.13 85/12/09 15:48:32 karels 62 61
c logic errors
e
s 00005/00009/00830
d D 6.12 85/11/08 19:05:35 karels 61 60
c correct previous fix to failed connect; let's really free those
c sockets after failed socketpair/pipe
e
s 00001/00000/00838
d D 6.11 85/10/30 18:07:01 karels 60 59
c unsuccessful attempt to connect leaves socket disconnect{ed,ing}
e
s 00001/00000/00837
d D 6.10 85/09/16 20:48:17 karels 59 58
c only report errors on listening socket once
e
s 00007/00001/00830
d D 6.9 85/06/08 15:06:43 mckusick 58 57
c Add copyright
e
s 00008/00007/00823
d D 6.8 85/06/02 23:24:25 karels 57 56
c rights must be MT_RIGHTS (confuses soreceive otherwise!)
e
s 00003/00001/00827
d D 6.7 85/05/27 20:02:53 karels 56 55
c pipe usese connect2 now
e
s 00009/00000/00819
d D 6.6 84/11/27 17:08:00 karels 55 54
c socketpair needs to connect datagram sockets both ways, returns 0
e
s 00008/00013/00811
d D 6.5 84/09/04 21:46:17 sam 54 53
c revise socket option interface so options at SOL_SOCKET take value 
c parameter indicating if option is on/off
e
s 00013/00013/00811
d D 6.4 84/08/29 20:28:38 bloom 53 52
c Change to includes.  no more ../h
e
s 00002/00002/00822
d D 6.3 84/07/08 22:30:40 mckusick 52 51
c use proper definition of UIO flags
e
s 00004/00000/00820
d D 6.2 83/09/25 17:32:38 karels 51 50
c sendit and recvit skip over 0-length vectors
e
s 00000/00000/00820
d D 6.1 83/07/29 06:49:05 sam 50 49
c 4.2 distribution
e
s 00044/00000/00776
d D 4.48 83/07/25 21:53:36 sam 49 48
c getpeer
e
s 00052/00001/00724
d D 4.47 83/06/14 20:40:35 sam 48 47
c socketpair
e
s 00276/00188/00449
d D 4.46 83/05/27 12:51:09 sam 47 46
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00007/00001/00630
d D 4.45 83/03/23 15:02:51 sam 46 45
c if M_WAIT worked, these wouldn't be needed
e
s 00015/00007/00616
d D 4.44 83/03/19 14:10:24 sam 45 44
c replace socketaddr with getsockname
e
s 00001/00002/00622
d D 4.43 83/03/04 16:16:39 sam 44 43
c freeing free mbuf
e
s 00036/00031/00588
d D 4.42 83/01/13 19:02:38 sam 43 42
c allow nil pointers for option values
e
s 00096/00095/00523
d D 4.41 83/01/13 18:35:25 sam 42 41
c mv socket options into set and get socket options sys calls
e
s 00032/00003/00586
d D 4.40 83/01/08 20:53:43 sam 41 40
c fill out shutdown stub; add socket option consistency checking
e
s 00027/00024/00562
d D 4.39 82/12/28 23:48:08 sam 40 39
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00004/00004/00582
d D 4.38 82/12/14 17:09:54 sam 39 38
c typed mbufs
e
s 00003/00001/00583
d D 4.37 82/11/15 01:13:06 sam 38 37
c treat domain as AF_*; return residuals on send and sendto
e
s 00005/00003/00579
d D 4.36 82/11/13 22:51:23 sam 37 36
c merge of 4.1b and 4.1c
e
s 00004/00004/00578
d D 4.35 82/10/21 20:58:21 root 36 35
c lint
e
s 00001/00001/00581
d D 4.34 82/10/20 02:41:31 root 35 34
c lint
e
s 00001/00001/00581
d D 4.33 82/10/20 01:09:54 root 34 33
c lint
e
s 00019/00017/00563
d D 4.32 82/10/17 21:50:00 root 33 32
c more lint
e
s 00000/00001/00580
d D 4.31 82/10/17 14:05:00 root 32 31
c fix lint
e
s 00000/00002/00581
d D 4.30 82/10/09 05:38:16 wnj 31 30
c fix up header file dependencies 
e
s 00006/00008/00577
d D 4.29 82/10/05 21:57:36 root 30 29
c send(... SOF_OOB) and receive(... SOF_PREVIEW)
e
s 00004/00004/00581
d D 4.28 82/10/05 10:30:06 root 29 27
c bug in sockopt() error handling in accept
e
s 00388/00216/00197
d R 4.28 82/10/03 23:47:07 root 28 27
c minor bug
e
s 00386/00214/00199
d D 4.27 82/10/03 23:39:09 root 27 26
c overhaul
e
s 00001/00009/00412
d D 4.26 82/09/06 22:54:34 root 26 25
c  
e
s 00024/00032/00397
d D 4.25 82/09/04 09:18:58 root 25 24
c ipc call skeletons
e
s 00025/00006/00404
d D 4.24 82/08/22 20:39:41 root 24 23
c uio'ing
e
s 00011/00004/00399
d D 4.23 82/08/14 18:54:39 root 23 22
c no more readi()
e
s 00001/00001/00402
d D 4.22 82/08/08 18:12:22 sam 22 21
c bug fix for invalid parameters
e
s 00109/00017/00294
d D 4.21 82/07/24 18:11:06 root 21 20
c merge with calder
e
s 00000/00007/00311
d D 4.20 82/06/20 12:21:32 sam 20 19
c purge COUNT crap now that we have gprof
e
s 00001/00001/00317
d D 4.19 82/06/14 22:16:48 wnj 19 18
c get rid of m_release stuff
e
s 00006/00001/00312
d D 4.18 82/06/12 23:09:53 wnj 18 17
c fix to race in accept
e
s 00008/00004/00305
d D 4.17 82/04/10 23:43:24 sam 17 16
c redo socketaddr system call
e
s 00000/00084/00309
d D 4.16 82/03/19 14:22:02 sam 16 15
c purge extraneous stuff
e
s 00003/00003/00390
d D 4.15 82/03/15 04:47:05 wnj 15 14
c shutdown; clear suid; get/set hostname; nbio in state not options fixes
e
s 00006/00001/00387
d D 4.14 82/02/25 12:49:29 wnj 14 13
c race in accept
e
s 00003/00003/00385
d D 4.13 82/01/13 10:31:33 root 13 12
c spelling changes
e
s 00004/00000/00384
d D 4.12 81/12/20 15:24:41 root 12 11
c sleep for connection in accept; return address in accept
e
s 00004/00000/00380
d D 4.11 81/12/09 20:52:08 wnj 11 10
c set u.u_base
e
s 00002/00002/00378
d D 4.10 81/12/02 17:26:14 wnj 10 9
c more cleanup
e
s 00002/00002/00378
d D 4.9 81/11/26 11:57:23 wnj 9 8
c before carry to arpavax
e
s 00001/00001/00379
d D 4.8 81/11/21 15:12:44 wnj 8 7
c args to piconnect backwards
e
s 00006/00001/00374
d D 4.7 81/11/20 14:42:54 wnj 7 6
c more lint
e
s 00021/00000/00354
d D 4.6 81/11/20 01:19:22 wnj 6 5
c ssocketaddr
e
s 00002/00002/00352
d D 4.5 81/11/20 00:45:49 wnj 5 4
c linted
e
s 00095/00036/00259
d D 4.4 81/11/18 15:44:50 wnj 4 3
c more cleanup
e
s 00011/00137/00284
d D 4.3 81/11/16 14:20:30 wnj 3 2
c lint
e
s 00153/00109/00268
d D 4.2 81/11/14 16:42:55 wnj 2 1
c before header overlay
e
s 00377/00000/00000
d D 4.1 81/11/10 16:03:21 wnj 1 0
c date and time created 81/11/10 16:03:21 by wnj
e
u
U
f b 
t
T
I 1
D 58
/*	%M%	%I%	%E%	*/
E 58
I 58
/*
D 67
 * Copyright (c) 1982 Regents of the University of California.
E 67
I 67
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 67
D 69
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 69
I 69
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 71
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 71
I 71
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
E 71
E 69
 *
 *	%W% (Berkeley) %G%
 */
E 58

D 53
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/file.h"
#include "../h/inode.h"
#include "../h/buf.h"
#include "../h/mbuf.h"
D 4
#include "../h/protocol.h"
E 4
#include "../h/protosw.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
D 4
#include "../h/inaddr.h"
E 4
D 9
#include "../net/inet.h"
#include "../net/inet_systm.h"
E 9
I 9
D 31
#include "../net/in.h"
#include "../net/in_systm.h"
E 31
I 21
D 47
#include "../h/descrip.h"
E 47
I 23
#include "../h/uio.h"
E 53
I 53
#include "param.h"
D 68
#include "systm.h"
E 68
#include "dir.h"
#include "user.h"
D 68
#include "proc.h"
E 68
#include "file.h"
D 68
#include "inode.h"
E 68
#include "buf.h"
#include "mbuf.h"
#include "protosw.h"
#include "socket.h"
#include "socketvar.h"
D 68
#include "uio.h"
E 68
E 53
E 23
E 21
E 9

I 21
D 25
ssocreate()
I 24
/*###21 [lint] ssocreate defined( sys_socket.c(21) ), but never used%%%*/
E 25
I 25
D 27
socket()
E 25
E 24
{

}

D 25
ssobind()
I 24
/*###26 [lint] ssobind defined( sys_socket.c(26) ), but never used%%%*/
E 25
I 25
bind()
E 25
E 24
{

}

D 25
ssolisten()
I 24
/*###31 [lint] ssolisten defined( sys_socket.c(31) ), but never used%%%*/
E 25
I 25
listen()
E 25
E 24
{

}

D 25
ssoaccept()
I 24
/*###36 [lint] ssoaccept defined( sys_socket.c(36) ), but never used%%%*/
E 25
I 25
accept()
E 25
E 24
{

}

D 25
ssoconnect()
I 24
/*###41 [lint] ssoconnect defined( sys_socket.c(41) ), but never used%%%*/
E 25
I 25
connect()
E 25
E 24
{

}

D 25
ssocreatepair()
I 24
/*###46 [lint] ssocreatepair defined( sys_socket.c(46) ), but never used%%%*/
E 25
I 25
socketpair()
E 25
E 24
{

}

D 25
ssosendto()
I 24
/*###51 [lint] ssosendto defined( sys_socket.c(51) ), but never used%%%*/
E 25
I 25
D 26
spipe()
E 25
E 24
{

}

E 26
D 25
ssosend()
I 24
/*###56 [lint] ssosend defined( sys_socket.c(56) ), but never used%%%*/
E 25
I 25
sendto()
E 25
E 24
{

}

D 25
ssorecvfrom()
I 24
/*###61 [lint] ssorecvfrom defined( sys_socket.c(61) ), but never used%%%*/
E 25
I 25
send()
E 25
E 24
{

}

D 25
ssorecv()
I 24
/*###66 [lint] ssorecv defined( sys_socket.c(66) ), but never used%%%*/
E 25
I 25
recvfrom()
E 25
E 24
{

}

D 25
ssosendm()
I 24
/*###71 [lint] ssosendm defined( sys_socket.c(71) ), but never used%%%*/
E 25
I 25
recv()
E 25
E 24
{

}

D 25
ssorecvm()
I 24
/*###76 [lint] ssorecvm defined( sys_socket.c(76) ), but never used%%%*/
E 25
I 25
sendmsg()
E 25
E 24
{

}

D 25
ssoshutdown()
I 24
/*###81 [lint] ssoshutdown defined( sys_socket.c(81) ), but never used%%%*/
E 25
I 25
recvmsg()
E 25
E 24
{

}

I 25
shutdown()
{

}

E 27
E 25
E 21
/*
D 27
 * Socket system call interface.
 *
 * These routines interface the socket routines to UNIX,
 * isolating the system interface from the socket-protocol interface.
 *
D 2
 * DO SPLICE STUFF
 * DO PIPE STUFF
 * DO PORTALS
 * DO ASSOCIATIONS
 * DO NEWFD STUFF
E 2
I 2
 * TODO:
D 4
 *	SO_NEWFDONCONN
E 4
 *	SO_INTNOTIFY
E 27
I 27
 * System call interface to the socket abstraction.
E 27
E 2
 */

I 47
struct	file *getsock();
extern	struct fileops socketops;

E 47
I 2
D 4
static	struct in_addr localaddr = { PF_LOCAL };
E 4
I 4
D 10
static	struct sockproto localproto = { PF_LOCAL, 0 };
E 10
I 10
D 27
static	struct sockproto localproto = { PF_UNIX, 0 };
E 10
E 4
E 2
D 26
/*
D 2
 * Socket system call interface.  Copy in arguments
 * set up file descriptor and call internal socket
 * creation routine.
E 2
I 2
 * Pipe system call interface.
E 2
 */
D 2
ssocket()
E 2
I 2
D 25
spipe()
E 25
I 25
opipe()
E 26
I 26
pipe()
E 27
I 27
socket()
E 27
E 26
E 25
E 2
{
D 2
	register struct a {
		int	type;
		struct	in_addr *ain;
		int	options;
	} *uap = (struct a *)u.u_ap;
	struct in_addr in;
	struct socket *so0;
	register struct socket *so;
	register struct file *fp;

	if ((fp = falloc()) == NULL)
E 2
I 2
D 27
	register struct file *rf, *wf;
	struct socket *rso, *wso;
	int r;
I 4
D 20
COUNT(SPIPE);
E 20
E 4
D 3
	struct in_addr waddr;
E 3
	
D 4
	u.u_error = socket(&rso, SOCK_STREAM, &localaddr, SO_ACCEPTCONN);
E 4
I 4
	u.u_error = socreate(&rso, SOCK_STREAM,
	    &localproto, (struct sockaddr *)0, 0);
E 4
	if (u.u_error)
E 2
		return;
D 2
	fp->f_flag = FSOCKET|FREAD|FWRITE;
	if (copyin((caddr_t)uap->ain, &in, sizeof (in))) {
		u.u_error = EFAULT;
		return;
	}
	u.u_error = socket(&so0, uap->type, &in, uap->options);
E 2
I 2
D 4
	u.u_error = socket(&wso, SOCK_STREAM, &localaddr, 0);
E 4
I 4
	u.u_error = socreate(&wso, SOCK_STREAM,
	    &localproto, (struct sockaddr *)0, 0);
E 4
E 2
	if (u.u_error)
D 2
		goto bad;
	fp->f_socket = so;
E 2
I 2
		goto free;
	rf = falloc();
	if (rf == NULL)
		goto free2;
	r = u.u_r.r_val1;
D 21
	rf->f_flag = FREAD|FSOCKET;
E 21
I 21
	rf->f_flag = FREAD;
	rf->f_type = DTYPE_SOCKET;
E 21
	rf->f_socket = rso;
	wf = falloc();
	if (wf == NULL)
		goto free3;
D 21
	wf->f_flag = FWRITE|FSOCKET;
E 21
I 21
	wf->f_flag = FWRITE;
	wf->f_type = DTYPE_SOCKET;
E 21
	wf->f_socket = wso;
	u.u_r.r_val2 = u.u_r.r_val1;
	u.u_r.r_val1 = r;
D 4
	if (pi_connect(rso, wso) == 0)
E 4
I 4
D 8
	if (piconnect(rso, wso) == 0)
E 8
I 8
	if (piconnect(wso, rso) == 0)
E 8
E 4
		goto free4;
I 4
D 5
	rso->so_isfilerefd = wso->so_isfilerefd = 1;
E 5
E 4
E 2
	return;
D 2
bad:
E 2
I 2
free4:
	wf->f_count = 0;
E 2
D 19
	u.u_ofile[u.u_r.r_val1] = 0;
E 19
I 19
	u.u_ofile[u.u_r.r_val2] = 0;
E 19
D 2
	fp->f_count = 0;
E 2
I 2
free3:
	rf->f_count = 0;
	u.u_ofile[r] = 0;
free2:
I 5
D 21
	wso->so_state |= SS_USERGONE;
E 21
I 21
	wso->so_state |= SS_NOFDREF;
E 21
E 5
	sofree(wso);
free:
I 5
D 21
	rso->so_state |= SS_USERGONE;
E 21
I 21
	rso->so_state |= SS_NOFDREF;
E 21
E 5
	sofree(rso);
E 2
}

/*
D 2
 * Pipe system call interface.
 */
spipe()
{

}

static	struct in_addr portalproto = { PF_PORTAL, /* rest don't care */ };
/*
E 2
D 3
 * Portal system call interface.
 *
 * This call creates a portal.
 * All the difficulty here is in dealing with errors.
 * A long sequence of steps is necessary:
 *	1. a socket must be allocated
 *	2. the server name length must be determined
D 2
 *	3. the protal must be entered into the file system
E 2
I 2
 *	3. the portal must be entered into the file system
E 2
 *	4. the portal type and server must be entered into the portals' file
 *	5. a file descriptor referencing the socket+inode must be returned
 * If any errors occur in this process we must back it all out.
 */
sportal()
{
	register struct a {
		caddr_t	name;
		int	mode;
		caddr_t server;
		int	kind;
	} *ap = (struct a *)u.u_ap;
	struct socket *so;
	struct inode *ip;
	struct file *fp;
	int err, len;
	char ch;

	/*
	 * Allocate the socket for the portal.
	 */
D 2
	u.u_error = socket(&so, SOCK_STREAM, &portalproto, SO_NEWFDONCONN);
E 2
I 2
	u.u_error = socket(&so, SOCK_STREAM, &localaddr, SO_NEWFDONCONN);
E 2
	if (u.u_error)
		return;

	/*
	 * Check that server name fis in a file system buffer.
	 * This to simplify the creation of the portal service process.
	 */
	if (ap->server) {
		u.u_dirp = ap->server;
		for (len = 0; len < BSIZE-2; len++) {
			register c = uchar();
			if (c < 0)
				goto bad;
			if (c == 0)
				break;
		}
		if (len == BSIZE - 2) {
			u.u_error = EINVAL;
			goto bad;
		}
	}

	/*
	 * Make sure that nothing with the portal's name exists.
	 */
	u.u_dirp = ap->name;
	ip = namei(uchar, 1);
	if (ip != NULL) {
		iput(ip);
		u.u_error = EEXIST;
	}
	if (u.u_error)
		goto bad;

	/*
	 * Make a node in the file system for the portal.
	 */
	ip = maknode((ap->mode & 0x7777) | IFPORTAL);
	if (ip == NULL)
		goto bad;

	/*
	 * Make the first character of the contents of the
	 * portal be the portal type and the rest of the portal be
	 * the pathname of the server (if one was given).
	 */
	ch = (char)ap->kind;
	u.u_base = (caddr_t)&ch;
	u.u_count = 1;
	u.u_offset = 0;
	u.u_segflg = 1;
	writei(ip);
	if (ap->server) {
		u.u_base = ap->server;
		u.u_count = len;
		u.u_segflg = 0;
		writei(ip);
	}
	if (u.u_error)
		goto bad2;
	
	/*
	 * Allocate a file descriptor and make it reference both
	 * the inode representing the portal and the call director
	 * socket for the portal.
	 */
	fp = falloc();
	if (fp == NULL)
		goto bad2;
D 2
	fp->f_flags = FPORTAL|FSOCKET;
E 2
I 2
	fp->f_flag = FPORTAL|FSOCKET;
E 2
	fp->f_inode = ip;
D 2
	fp->f_socket = s;
E 2
I 2
	fp->f_socket = so;
E 2

	/*
	 * Make the in-core inode reference the socket.
	 */
D 2
	ip->i_socket = s;
	prele(ip);
E 2
I 2
	ip->i_un.i_socket = so;
	irele(ip);
E 2
	return;
bad2:
	err = u.u_error;
	iput(ip);
	u.u_dirp = ap->name;
	unlink();
	u.u_error = err;
bad:
D 2
	sofree(s);
E 2
I 2
	sofree(so);
E 2
}

/*
E 3
D 2
 * Close a socket on last file table reference removal.
 * Initiate disconnect if connected.
 * Free socket when disconnect complete.
E 2
I 2
D 16
 * Splice system call interface.
E 2
 */
D 2
skclose(so)
	register struct socket *so;
E 2
I 2
ssplice()
E 2
{
D 2
	int s = splnet();		/* conservative */
E 2
I 2
	register struct a {
		int	fd1;
		int	fd2;
	} *ap = (struct a *)u.u_ap;
	struct file *f1, *f2;
I 4
COUNT(SSPLICE);
E 4
D 3
	struct socket *pso, *pso2;
E 3
E 2

D 2
	if (so->so_pcb == 0)
		goto discard;
	if (so->so_state & SS_ISCONNECTED) {
		u.u_error = disconnect(so, 0);
		if (u.u_error) {
			splx(s);
			return;
		}
		if ((so->so_state & SS_ISDISCONNECTING) &&
		    (so->so_options & SO_NBIO)) {
			u.u_error = EINPROGRESS;
			splx(s);
			return;
		}
		while (so->so_state & SS_ISCONNECTED)
			sleep((caddr_t)&so->so_timeo, PZERO+1);
E 2
I 2
	f1 = getf(ap->fd1);
	if (f1 == NULL)
		return;
	f2 = getf(ap->fd2);
	if (f2 == NULL)
		return;
I 4
	if (f1 == f2) {
		u.u_error = EINVAL;
		return;
	}
E 4
	if ((f1->f_flag & FSOCKET) == 0 || (f2->f_flag & FSOCKET) == 0) {
		u.u_error = ENOTSOCK;
		return;
E 2
	}
D 2
	u.u_error = (*so->so_proto->pr_usrreq)(so, PRU_DETACH, 0, 0);
discard:
	sofree(so);
	splx(s);
E 2
I 2
	if (f1->f_count > 1 || f2->f_count > 1) {
		u.u_error = ETOOMANYREFS;
		return;
	}
D 4
	u.u_error = pi_splice(f1->f_socket, f2->f_socket);
E 4
I 4
	u.u_error = sosplice(f1->f_socket, f2->f_socket);
E 4
	if (u.u_error)
		return;
	u.u_ofile[ap->fd1] = 0;
	u.u_ofile[ap->fd2] = 0;
	f1->f_count = 0;
	f2->f_count = 0;
E 2
}

/*
E 16
D 2
 * Select a socket.
E 2
I 2
D 4
 * Socket system call interface.  Copy in arguments
E 4
I 4
 * Socket system call interface.  Copy sa arguments
E 4
 * set up file descriptor and call internal socket
 * creation routine.
E 2
 */
D 2
soselect(so, flag)
	register struct socket *so;
	int flag;
E 2
I 2
D 25
ssocket()
E 25
I 25
osocket()
E 25
E 2
{
E 27
D 2
	register struct proc *p;
E 2
I 2
	register struct a {
I 27
		int	domain;
E 27
		int	type;
D 4
		struct	in_addr *ain;
E 4
I 4
D 27
		struct	sockproto *asp;
		struct	sockaddr *asa;
E 4
		int	options;
E 27
I 27
		int	protocol;
D 42
		struct	socketopt *opt;
E 42
E 27
	} *uap = (struct a *)u.u_ap;
D 4
	struct in_addr in;
	struct socket *so0;
E 4
I 4
D 27
	struct sockproto sp;
	struct sockaddr sa;
E 27
	struct socket *so;
E 4
	register struct file *fp;
I 27
D 42
	struct socketopt aopt;
E 42
E 27
I 4
D 20
COUNT(SSOCKET);
E 20
E 4
E 2

D 2
	if (soreadable(so))
		return (1);
	if ((p = so->so_rcv.sb_sel) && p->p_wchan == (caddr_t)select)
		so->so_rcv.sb_flags |= SB_COLL;
	else
		so->so_rcv.sb_sel = u.u_procp;
	return (0);
}

/*
 * Wakeup read sleep/select'ers.
 */
sowakeup(so)
	struct socket *so;
{

	if (so->so_rcv.sb_sel && soreadable(so)) {
		selwakeup(so->so_rcv.sb_sel, so->so_rcv.sb_flags & SB_COLL);
		so->so_rcv.sb_sel = 0;
		so->so_rcv.sb_flags &= ~SB_COLL;
E 2
I 2
D 29
	if ((fp = falloc()) == NULL)
E 29
I 29
D 33
	u.u_error = sockopt(&aopt, uap->opt);
E 33
I 33
D 42
	u.u_error = sockopt(&aopt, (caddr_t)uap->opt);
E 33
	if (u.u_error)
E 29
		return;
E 42
I 29
	if ((fp = falloc()) == NULL)
D 42
		goto freeopt;
E 42
I 42
		return;
E 42
E 29
D 21
	fp->f_flag = FSOCKET|FREAD|FWRITE;
E 21
I 21
	fp->f_flag = FREAD|FWRITE;
	fp->f_type = DTYPE_SOCKET;
I 47
	fp->f_ops = &socketops;
E 47
E 21
D 3
	if (copyin((caddr_t)uap->ain, &in, sizeof (in))) {
E 3
I 3
D 4
	if (copyin((caddr_t)uap->ain, (caddr_t)&in, sizeof (in))) {
E 4
I 4
D 27
	if (uap->asp && copyin((caddr_t)uap->asp, (caddr_t)&sp, sizeof (sp)) ||
	    uap->asa && copyin((caddr_t)uap->asa, (caddr_t)&sa, sizeof (sa))) {
E 4
E 3
		u.u_error = EFAULT;
E 27
I 27
D 29
	u.u_error = sockopt(&aopt, uap->opt);
	if (u.u_error)
E 27
D 22
		return;
E 22
I 22
		goto bad;
E 29
E 22
E 2
D 27
	}
D 2
	if (so->so_rcv.sb_flags & SB_WAIT) {
		so->so_rcv.sb_flags &= ~SB_WAIT;
		wakeup((caddr_t)&so->so_rcv.sb_cc);
	}
E 2
I 2
D 4
	u.u_error = socket(&so0, uap->type, &in, uap->options);
E 4
I 4
	u.u_error = socreate(&so, uap->type,
	    uap->asp ? &sp : 0, uap->asa ? &sa : 0, uap->options);
E 27
I 27
D 37
	u.u_error = socreate(0, &so, uap->type, uap->protocol, &aopt);
E 37
I 37
D 38
	u.u_error = socreate(AF_UNSPEC, &so, uap->type, uap->protocol, &aopt);
E 38
I 38
D 42
	u.u_error = socreate(uap->domain, &so, uap->type, uap->protocol, &aopt);
E 42
I 42
	u.u_error = socreate(uap->domain, &so, uap->type, uap->protocol);
E 42
E 38
E 37
E 27
E 4
	if (u.u_error)
		goto bad;
D 4
	fp->f_socket = so0;
E 4
I 4
D 47
	fp->f_socket = so;
E 47
I 47
	fp->f_data = (caddr_t)so;
E 47
I 27
D 42
freeopt:
	if (uap->opt)
D 36
		m_free(dtom(aopt.so_optdata));
E 36
I 36
		(void) m_free(dtom(aopt.so_optdata));
E 42
E 36
E 27
D 5
	so->so_isfilerefd = 1;
E 5
E 4
	return;
bad:
	u.u_ofile[u.u_r.r_val1] = 0;
	fp->f_count = 0;
I 27
D 42
	goto freeopt;
E 42
E 27
E 2
}
I 3

I 4
D 27
/*
 * Accept system call interface.
 */
E 4
D 25
saccept()
E 25
I 25
oaccept()
E 27
I 27
bind()
E 27
E 25
{
I 4
	register struct a {
D 27
		int	fdes;
		struct	sockaddr *asa;
E 27
I 27
		int	s;
		caddr_t	name;
		int	namelen;
D 42
		struct	socketopt *opt;
E 42
E 27
	} *uap = (struct a *)u.u_ap;
D 27
	struct sockaddr sa;
E 27
	register struct file *fp;
D 27
	struct socket *so;
	int s;
E 27
I 27
	struct mbuf *nam;
D 42
	struct socketopt aopt;
E 42
E 27
D 20
COUNT(SACCEPT);
E 20
E 4

I 4
D 27
	if (uap->asa && useracc((caddr_t)uap->asa, sizeof (sa), B_WRITE)==0) {
		u.u_error = EFAULT;
E 27
I 27
D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
	if (fp == 0)
E 27
		return;
I 27
D 47
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
E 27
	}
D 27
	fp = getf(uap->fdes);
E 27
I 27
	u.u_error = sockname(&nam, uap->name, uap->namelen);
E 47
I 47
D 57
	u.u_error = sockargs(&nam, uap->name, uap->namelen);
E 57
I 57
	u.u_error = sockargs(&nam, uap->name, uap->namelen, MT_SONAME);
E 57
E 47
	if (u.u_error)
		return;
D 33
	u.u_error = sockopt(&aopt, uap->opt);
E 33
I 33
D 42
	u.u_error = sockopt(&aopt, (caddr_t)uap->opt);
E 33
	if (u.u_error) {
		m_freem(nam);
D 30
		return;
E 30
I 30
		goto freeopt;
E 30
	}
	u.u_error = sobind(fp->f_socket, nam, &aopt);
E 42
I 42
D 47
	u.u_error = sobind(fp->f_socket, nam);
E 47
I 47
	u.u_error = sobind((struct socket *)fp->f_data, nam);
E 47
E 42
	m_freem(nam);
I 30
D 42
freeopt:
E 30
	if (uap->opt)
D 36
		m_free(dtom(aopt.so_optdata));
E 36
I 36
		(void) m_free(dtom(aopt.so_optdata));
E 42
E 36
}

listen()
{
	register struct a {
		int	s;
		int	backlog;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;

D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
E 27
	if (fp == 0)
		return;
D 21
	if ((fp->f_flag & FSOCKET) == 0) {
E 21
I 21
D 47
	if (fp->f_type != DTYPE_SOCKET) {
E 21
		u.u_error = ENOTSOCK;
		return;
	}
I 27
	u.u_error = solisten(fp->f_socket, uap->backlog);
E 47
I 47
	u.u_error = solisten((struct socket *)fp->f_data, uap->backlog);
E 47
}

accept()
{
	register struct a {
		int	s;
		caddr_t	name;
		int	*anamelen;
D 42
		struct	socketopt *opt;
E 42
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
	struct mbuf *nam;
D 42
	struct socketopt aopt;
E 42
	int namelen;
	int s;
	register struct socket *so;

	if (uap->name == 0)
		goto noname;
D 40
	if (copyin((caddr_t)uap->anamelen, (caddr_t)&namelen, sizeof (namelen))) {
		u.u_error = EFAULT;
E 40
I 40
	u.u_error = copyin((caddr_t)uap->anamelen, (caddr_t)&namelen,
		sizeof (namelen));
	if (u.u_error)
E 40
		return;
D 40
	}
E 40
D 33
	if (useracc((caddr_t)uap->name, namelen, B_WRITE) == 0) {
E 33
I 33
	if (useracc((caddr_t)uap->name, (u_int)namelen, B_WRITE) == 0) {
E 33
		u.u_error = EFAULT;
		return;
	}
noname:
D 33
	u.u_error = sockopt(&aopt, uap->opt);
E 33
I 33
D 42
	u.u_error = sockopt(&aopt, (caddr_t)uap->opt);
E 33
	if (u.u_error)
		return;
E 42
D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
	if (fp == 0)
D 42
		goto bad;
E 42
I 42
		return;
E 42
D 47
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
D 42
		goto bad;
E 42
I 42
		return;
E 42
	}
E 47
E 27
	s = splnet();
D 47
	so = fp->f_socket;
E 47
I 47
	so = (struct socket *)fp->f_data;
E 47
D 13
	if ((so->so_options & SO_NBIO) &&
E 13
I 13
D 15
	if ((so->so_options & SO_NONBLOCKING) &&
E 15
I 15
D 21
	if ((so->so_state & SS_NBIO) &&
E 15
E 13
	    (so->so_state & SS_CONNAWAITING) == 0) {
E 21
I 21
	if ((so->so_options & SO_ACCEPTCONN) == 0) {
		u.u_error = EINVAL;
		splx(s);
D 27
		return;
E 27
I 27
D 42
		goto bad;
E 42
I 42
		return;
E 42
E 27
	}
	if ((so->so_state & SS_NBIO) && so->so_qlen == 0) {
E 21
		u.u_error = EWOULDBLOCK;
		splx(s);
D 27
		return;
E 27
I 27
D 42
		goto bad;
E 42
I 42
		return;
E 42
E 27
	}
I 12
D 14
	while ((so->so_state & SS_CONNAWAITING) == 0)
E 14
I 14
D 18
	while ((so->so_state & SS_CONNAWAITING) == 0 && so->so_error == 0)
E 18
I 18
D 21
	while ((so->so_state & SS_CONNAWAITING) == 0 && so->so_error == 0) {
E 21
I 21
	while (so->so_qlen == 0 && so->so_error == 0) {
E 21
		if (so->so_state & SS_CANTRCVMORE) {
			so->so_error = ECONNABORTED;
			break;
		}
E 18
E 14
		sleep((caddr_t)&so->so_timeo, PZERO+1);
I 18
	}
E 18
I 14
	if (so->so_error) {
		u.u_error = so->so_error;
I 59
		so->so_error = 0;
E 59
		splx(s);
D 27
		return;
E 27
I 27
D 42
		goto bad;
E 42
I 42
		return;
E 42
E 27
	}
E 14
E 12
D 21
	u.u_error = soaccept(so, &sa);
	if (u.u_error) {
E 21
I 21
D 47
	if ((so->so_options & SO_NEWFDONCONN) == 0) {
		struct socket *nso = so->so_q;
		(void) soqremque(nso, 1);
D 34
		soclose(so, 1);
E 34
I 34
		u.u_error = soclose(so, 1);
E 34
		fp->f_socket = nso;
		nso->so_q = 0;
		so = nso;
		goto ret;
	}
	if (ufalloc() < 0) {
E 47
I 47
	if (ufalloc(0) < 0) {
E 47
E 21
		splx(s);
D 27
		return;
E 27
I 27
D 42
		goto bad;
E 42
I 42
		return;
E 42
E 27
	}
I 21
	fp = falloc();
	if (fp == 0) {
		u.u_ofile[u.u_r.r_val1] = 0;
		splx(s);
D 27
		return;
E 27
I 27
D 42
		goto bad;
E 42
I 42
		return;
E 42
E 27
	}
I 27
	{ struct socket *aso = so->so_q;
	  if (soqremque(aso, 1) == 0)
		panic("accept");
	  so = aso;
	}
E 27
	fp->f_type = DTYPE_SOCKET;
	fp->f_flag = FREAD|FWRITE;
D 27
	fp->f_socket = so->so_q;
	so->so_q = so->so_q->so_q;
	so->so_qlen--;
E 27
I 27
D 47
	fp->f_socket = so;
E 27
ret:
E 47
I 47
	fp->f_ops = &socketops;
	fp->f_data = (caddr_t)so;
E 47
D 27
	soaccept(so, &sa);
E 21
I 12
	if (uap->asa)
		(void) copyout((caddr_t)&sa, (caddr_t)uap->asa, sizeof (sa));
E 27
I 27
D 39
	nam = m_get(M_WAIT);
E 39
I 39
	nam = m_get(M_WAIT, MT_SONAME);
E 39
D 30
	nam->m_off = MMINOFF;
E 30
D 35
	soaccept(so, nam, &aopt);
E 35
I 35
D 42
	(void) soaccept(so, nam, &aopt);
E 42
I 42
	(void) soaccept(so, nam);
E 42
E 35
	if (uap->name) {
		if (namelen > nam->m_len)
			namelen = nam->m_len;
		/* SHOULD COPY OUT A CHAIN HERE */
D 33
		(void) copyout(mtod(nam, caddr_t), uap->name, namelen);
		(void) copyout((caddr_t)&namelen, uap->anamelen,
E 33
I 33
		(void) copyout(mtod(nam, caddr_t), (caddr_t)uap->name,
		    (u_int)namelen);
		(void) copyout((caddr_t)&namelen, (caddr_t)uap->anamelen,
E 33
		    sizeof (*uap->anamelen));
	}
	m_freem(nam);
E 27
E 12
D 21
	/* deal with new file descriptor case */
	/* u.u_r.r_val1 = ... */
E 21
	splx(s);
I 27
D 42
bad:
	if (uap->opt)
D 36
		m_free(dtom(aopt.so_optdata));
E 36
I 36
		(void) m_free(dtom(aopt.so_optdata));
E 42
E 36
E 27
E 4
}

E 3
D 2

E 2
D 27
/*
 * Connect socket to foreign peer; system call
D 4
 * interface.  Copy in arguments and call internal routine.
E 4
I 4
 * interface.  Copy sa arguments and call internal routine.
E 4
 */
D 25
sconnect()
E 25
I 25
oconnect()
E 27
I 27
connect()
E 27
E 25
{
	register struct a {
D 4
		int fdes;
		struct in_addr *a;
E 4
I 4
D 27
		int	fdes;
		struct	sockaddr *a;
E 27
I 27
		int	s;
		caddr_t	name;
		int	namelen;
D 42
		struct	socketopt *opt;
E 42
E 27
E 4
	} *uap = (struct a *)u.u_ap;
D 4
	in_addr in;
E 4
I 4
D 27
	struct sockaddr sa;
E 27
E 4
	register struct file *fp;
	register struct socket *so;
I 27
	struct mbuf *nam;
D 42
	struct socketopt aopt;
E 42
E 27
	int s;
I 4
D 20
COUNT(SCONNECT);
E 20
E 4

D 3
	if (copyin((caddr_t)uap->a, &in, sizeof (in))) {
E 3
I 3
D 4
	if (copyin((caddr_t)uap->a, (caddr_t)&in, sizeof (in))) {
E 4
I 4
D 27
	if (copyin((caddr_t)uap->a, (caddr_t)&sa, sizeof (sa))) {
E 4
E 3
		u.u_error = EFAULT;
		return;
	}
	fp = getf(uap->fdes);
E 27
I 27
D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
E 27
	if (fp == 0)
		return;
D 21
	if ((fp->f_flag & FSOCKET) == 0) {
E 21
I 21
D 47
	if (fp->f_type != DTYPE_SOCKET) {
E 21
		u.u_error = ENOTSOCK;
		return;
	}
	so = fp->f_socket;
D 4
	u.u_error = connect(so, &in);
E 4
I 4
D 27
	u.u_error = soconnect(so, &sa);
E 27
I 27
	u.u_error = sockname(&nam, uap->name, uap->namelen);
E 47
I 47
	so = (struct socket *)fp->f_data;
I 65
	if ((so->so_state & SS_NBIO) &&
	    (so->so_state & SS_ISCONNECTING)) {
D 66
		u.u_error = EINPROGRESS;
E 66
I 66
		u.u_error = EALREADY;
E 66
		return;
	}
E 65
D 57
	u.u_error = sockargs(&nam, uap->name, uap->namelen);
E 57
I 57
	u.u_error = sockargs(&nam, uap->name, uap->namelen, MT_SONAME);
E 57
E 47
E 27
E 4
	if (u.u_error)
		return;
I 27
D 33
	u.u_error = sockopt(&aopt, uap->opt);
E 33
I 33
D 42
	u.u_error = sockopt(&aopt, (caddr_t)uap->opt);
E 33
	if (u.u_error) {
		m_freem(nam);
		return;
	}
	u.u_error = soconnect(so, nam, &aopt);
E 42
I 42
	u.u_error = soconnect(so, nam);
E 42
	if (u.u_error)
		goto bad;
I 66
	if ((so->so_state & SS_NBIO) &&
	    (so->so_state & SS_ISCONNECTING)) {
		u.u_error = EINPROGRESS;
		m_freem(nam);
		return;
	}
E 66
E 27
	s = splnet();
D 2
	if ((so->so_options & SO_NBIO) && (so->so_state & SS_ISCONN) == 0) {
E 2
I 2
D 13
	if ((so->so_options & SO_NBIO) &&
E 13
I 13
D 15
	if ((so->so_options & SO_NONBLOCKING) &&
E 15
I 15
D 65
	if ((so->so_state & SS_NBIO) &&
E 15
E 13
	    (so->so_state & SS_ISCONNECTING)) {
E 2
		u.u_error = EINPROGRESS;
I 2
D 47
		splx(s);
E 2
D 27
		return;
E 27
I 27
		goto bad;
E 47
I 47
		goto bad2;
E 47
E 27
	}
E 65
I 47
	if (setjmp(&u.u_qsave)) {
		if (u.u_error == 0)
			u.u_error = EINTR;
		goto bad2;
	}
E 47
D 2
	while ((so->so_state & (SS_ISCONN|SS_ISCONNING)) == SS_ISCONNING)
E 2
I 2
	while ((so->so_state & SS_ISCONNECTING) && so->so_error == 0)
E 2
D 16
		sleep((caddr_t)&so->so_timeo, PZERO+1);
	u.u_error = so->so_error;
I 2
	so->so_error = 0;
	splx(s);
E 2
}

/*
 * Disconnect socket from foreign peer; system call
D 4
 * interface.  Copy in arguments and call internal routine.
E 4
I 4
 * interface.  Copy sa arguments and call internal routine.
E 4
 */
sdisconnect()
{
	register struct a {
		int	fdes;
D 4
		in_addr	 *addr;
E 4
I 4
		struct	sockaddr *asa;
E 4
	} *uap = (struct a *)u.u_ap;
D 4
	in_addr in;
E 4
I 4
	struct sockaddr sa;
E 4
	register struct file *fp;
I 2
	register struct socket *so;
E 2
	int s;
I 4
COUNT(SDISCONNECT);
E 4

D 4
	if (uap->addr &&
	    copyin((caddr_t)uap->addr, (caddr_t)&in, sizeof (in))) {
E 4
I 4
	if (uap->asa &&
	    copyin((caddr_t)uap->asa, (caddr_t)&sa, sizeof (sa))) {
E 4
		u.u_error = EFAULT;
		return;
	}
	fp = getf(uap->fdes);
	if (fp == 0)
		return;
	if ((fp->f_flag & FSOCKET) == 0) {
		u.u_error = ENOTSOCK;
		return;
	}
D 2
	u.u_error = disconnect(fp->f_socket, uap->addr ? &in : 0);
E 2
I 2
	so = fp->f_socket;
D 4
	u.u_error = disconnect(so, uap->addr ? &in : 0);
E 4
I 4
	u.u_error = sodisconnect(so, uap->asa ? &sa : 0);
E 4
E 2
	if (u.u_error)
		return;
	s = splnet();
D 2
	if ((so->so_options&SO_NBIO) && (so->so_state&SS_ISCONNECTED))
		return (EINPROGRESS);
	while ((so)->so_state & (SS_ISCONNECTED|SS_ISDISCONNECTING) == SS_ISDISCONNECTING)
E 2
I 2
D 13
	if ((so->so_options&SO_NBIO) && (so->so_state&SS_ISDISCONNECTING)) {
E 13
I 13
D 15
	if ((so->so_options&SO_NONBLOCKING) && (so->so_state&SS_ISDISCONNECTING)) {
E 15
I 15
	if ((so->so_state&SS_NBIO) && (so->so_state&SS_ISDISCONNECTING)) {
E 15
E 13
		u.u_error = EINPROGRESS;
		splx(s);
		return;
	}
D 10
	while (so->so_state & SS_ISDISCONNECTING)
E 10
I 10
	while ((so->so_state & SS_ISDISCONNECTING) && so->so_error == 0)
E 16
E 10
E 2
		sleep((caddr_t)&so->so_timeo, PZERO+1);
	u.u_error = so->so_error;
I 2
	so->so_error = 0;
I 60
D 61
	so->so_state &= ~SS_ISCONNECTING;
E 61
E 60
I 47
bad2:
E 47
	splx(s);
I 27
bad:
I 61
	so->so_state &= ~SS_ISCONNECTING;
E 61
	m_freem(nam);
D 42
	if (uap->opt)
D 36
		m_free(dtom(aopt.so_optdata));
E 36
I 36
		(void) m_free(dtom(aopt.so_optdata));
E 36
	return;
E 42
E 27
E 2
}

D 27
/*
 * Send data on socket.
 */
D 25
ssend()
E 25
I 25
osend()
E 27
I 27
socketpair()
E 27
E 25
{
I 48
	register struct a {
		int	domain;
		int	type;
		int	protocol;
		int	*rsv;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp1, *fp2;
	struct socket *so1, *so2;
	int sv[2];
E 48
I 27

D 48
	u.u_error = ENOENT;
E 48
I 48
	if (useracc((caddr_t)uap->rsv, 2 * sizeof (int), B_WRITE) == 0) {
		u.u_error = EFAULT;
		return;
	}
	u.u_error = socreate(uap->domain, &so1, uap->type, uap->protocol);
	if (u.u_error)
		return;
	u.u_error = socreate(uap->domain, &so2, uap->type, uap->protocol);
	if (u.u_error)
		goto free;
	fp1 = falloc();
	if (fp1 == NULL)
		goto free2;
	sv[0] = u.u_r.r_val1;
	fp1->f_flag = FREAD|FWRITE;
	fp1->f_type = DTYPE_SOCKET;
	fp1->f_ops = &socketops;
	fp1->f_data = (caddr_t)so1;
	fp2 = falloc();
	if (fp2 == NULL)
		goto free3;
	fp2->f_flag = FREAD|FWRITE;
	fp2->f_type = DTYPE_SOCKET;
	fp2->f_ops = &socketops;
	fp2->f_data = (caddr_t)so2;
	sv[1] = u.u_r.r_val1;
	u.u_error = soconnect2(so1, so2);
	if (u.u_error)
		goto free4;
I 55
	if (uap->type == SOCK_DGRAM) {
		/*
		 * Datagram socket connection is asymmetric.
		 */
		 u.u_error = soconnect2(so2, so1);
		 if (u.u_error)
			goto free4;
	}
	u.u_r.r_val1 = 0;
E 55
	(void) copyout((caddr_t)sv, (caddr_t)uap->rsv, 2 * sizeof (int));
	return;
free4:
	fp2->f_count = 0;
	u.u_ofile[sv[1]] = 0;
free3:
	fp1->f_count = 0;
	u.u_ofile[sv[0]] = 0;
free2:
D 61
	so2->so_state |= SS_NOFDREF;
	sofree(so2);
E 61
I 61
D 64
	soclose(so2);
E 64
I 64
	(void)soclose(so2);
E 64
E 61
free:
D 61
	so1->so_state |= SS_NOFDREF;
	sofree(so1);
E 61
I 61
D 64
	soclose(so1);
E 64
I 64
	(void)soclose(so1);
E 64
E 61
E 48
}

sendto()
{
E 27
	register struct a {
D 27
		int	fdes;
D 4
		in_addr	*ain;
E 4
I 4
		struct	sockaddr *asa;
E 4
		caddr_t	cbuf;
D 3
		int	count;
E 3
I 3
D 4
		u_int	count;
E 4
I 4
		unsigned count;
E 27
I 27
		int	s;
		caddr_t	buf;
		int	len;
		int	flags;
		caddr_t	to;
		int	tolen;
E 27
E 4
E 3
	} *uap = (struct a *)u.u_ap;
D 47
	register struct file *fp;
D 4
	struct in_addr in;
E 4
I 4
D 27
	struct sockaddr sa;
E 27
I 24
	struct uio auio;
E 47
I 47
	struct msghdr msg;
E 47
	struct iovec aiov;
I 27
D 47
	struct mbuf *to;
E 47
E 27
E 24
D 20
COUNT(SSEND);
E 20
E 4

D 27
	fp = getf(uap->fdes);
E 27
I 27
D 47
	fp = getf(uap->s);
E 27
	if (fp == 0)
		return;
D 21
	if ((fp->f_flag & FSOCKET) == 0) {
E 21
I 21
	if (fp->f_type != DTYPE_SOCKET) {
E 21
		u.u_error = ENOTSOCK;
		return;
	}
I 11
D 24
	u.u_base = uap->cbuf;
E 11
D 3
	if (uap->count < 0) {
		u.u_error = EINVAL;
		return;
	}
	u.u_base = uap->cbuf;
E 3
	u.u_count = uap->count;
	u.u_segflg = 0;
E 24
I 24
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
E 47
I 47
	msg.msg_name = uap->to;
	msg.msg_namelen = uap->tolen;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
E 47
D 27
	aiov.iov_base = uap->cbuf;
	aiov.iov_len = uap->count;
	auio.uio_resid = uap->count;
E 27
I 27
	aiov.iov_base = uap->buf;
	aiov.iov_len = uap->len;
D 47
	auio.uio_resid = uap->len;
E 27
	auio.uio_segflg = 0;
	auio.uio_offset = 0;	/* XXX */
E 24
D 2
	if (useracc(u.u_base, u.u_count, B_READ) == 0 ||
E 2
I 2
D 27
	if (useracc(uap->cbuf, uap->count, B_READ) == 0 ||
E 2
D 4
	    uap->ain && copyin((caddr_t)uap->ain, (caddr_t)&in, sizeof (in))) {
E 4
I 4
	    uap->asa && copyin((caddr_t)uap->asa, (caddr_t)&sa, sizeof (sa))) {
E 27
I 27
D 33
	if (useracc(uap->buf, uap->len, B_READ) == 0) {
E 33
I 33
	if (useracc(uap->buf, (u_int)uap->len, B_READ) == 0) {
E 33
E 27
E 4
		u.u_error = EFAULT;
		return;
	}
D 4
	u.u_error = send(fp->f_socket, uap->ain ? &in : 0);
E 4
I 4
D 24
	u.u_error = sosend(fp->f_socket, uap->asa ? &sa : 0);
I 11
	u.u_r.r_val1 = uap->count - u.u_count;
E 24
I 24
D 27
	u.u_error = sosend(fp->f_socket, uap->asa ? &sa : 0, &auio);
	u.u_r.r_val1 = uap->count - auio.uio_resid;
E 27
I 27
	u.u_error = sockname(&to, uap->to, uap->tolen);
	if (u.u_error)
D 44
		goto bad;
E 44
I 44
		return;
E 44
D 30
	u.u_error = sosend(fp->f_socket, to, &auio);
E 30
I 30
	u.u_error = sosend(fp->f_socket, to, &auio, uap->flags);
I 38
	u.u_r.r_val1 = uap->len - auio.uio_resid;
E 38
E 30
D 44
bad:
E 44
	m_freem(to);
E 47
I 47
	msg.msg_accrights = 0;
	msg.msg_accrightslen = 0;
	sendit(uap->s, &msg, uap->flags);
E 47
E 27
E 24
E 11
E 4
}

I 2
D 27
/*
 * Receive data on socket.
 */
D 25
sreceive()
E 25
I 25
oreceive()
E 27
I 27
send()
E 27
E 25
{
	register struct a {
D 27
		int	fdes;
D 4
		in_addr	*ain;
E 4
I 4
		struct	sockaddr *asa;
E 4
		caddr_t	cbuf;
D 3
		int	count;
E 3
I 3
		u_int	count;
E 27
I 27
		int	s;
		caddr_t	buf;
		int	len;
		int	flags;
E 27
E 3
	} *uap = (struct a *)u.u_ap;
D 47
	register struct file *fp;
D 3
	struct in_addr *in;
E 3
I 3
D 4
	struct in_addr in;
E 4
I 4
D 27
	struct sockaddr sa;
E 27
I 23
	struct uio auio;
E 47
I 47
	struct msghdr msg;
E 47
	struct iovec aiov;
I 27
D 32
	struct mbuf *nam;
E 32
E 27
E 23
D 20
COUNT(SRECEIVE);
E 20
E 4
E 3

D 27
	fp = getf(uap->fdes);
E 27
I 27
D 47
	fp = getf(uap->s);
E 27
	if (fp == 0)
		return;
D 21
	if ((fp->f_flag & FSOCKET) == 0) {
E 21
I 21
	if (fp->f_type != DTYPE_SOCKET) {
E 21
		u.u_error = ENOTSOCK;
		return;
	}
I 11
D 23
	u.u_base = uap->cbuf;
E 11
D 3
	if (uap->count < 0) {
		u.u_error = EINVAL;
		return;
	}
	u.u_base = uap->cbuf;
E 3
	u.u_count = uap->count;
	u.u_segflg = 0;
E 23
I 23
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
E 47
I 47
	msg.msg_name = 0;
	msg.msg_namelen = 0;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
E 47
D 27
	aiov.iov_base = uap->cbuf;
	aiov.iov_len = uap->count;
	auio.uio_resid = uap->count;
E 27
I 27
	aiov.iov_base = uap->buf;
	aiov.iov_len = uap->len;
D 47
	auio.uio_resid = uap->len;
E 27
	auio.uio_segflg = 0;
	auio.uio_offset = 0;	/* XXX */
E 23
D 27
	if (useracc(uap->cbuf, uap->count, B_WRITE) == 0 ||
D 4
	    uap->ain && copyin((caddr_t)uap->ain, (caddr_t)&in, sizeof (in))) {
E 4
I 4
	    uap->asa && copyin((caddr_t)uap->asa, (caddr_t)&sa, sizeof (sa))) {
E 27
I 27
D 33
	if (useracc(uap->buf, uap->len, B_READ) == 0) {
E 33
I 33
	if (useracc(uap->buf, (u_int)uap->len, B_READ) == 0) {
E 33
E 27
E 4
		u.u_error = EFAULT;
E 47
I 47
	msg.msg_accrights = 0;
	msg.msg_accrightslen = 0;
	sendit(uap->s, &msg, uap->flags);
}

sendmsg()
{
	register struct a {
		int	s;
		caddr_t	msg;
		int	flags;
	} *uap = (struct a *)u.u_ap;
	struct msghdr msg;
	struct iovec aiov[MSG_MAXIOVLEN];

	u.u_error = copyin(uap->msg, (caddr_t)&msg, sizeof (msg));
	if (u.u_error)
E 47
		return;
I 47
	if ((u_int)msg.msg_iovlen >= sizeof (aiov) / sizeof (aiov[0])) {
		u.u_error = EMSGSIZE;
		return;
E 47
	}
I 47
	u.u_error =
	    copyin((caddr_t)msg.msg_iov, (caddr_t)aiov,
		(unsigned)(msg.msg_iovlen * sizeof (aiov[0])));
E 47
D 4
	receive(fp->f_socket, uap->ain ? &in : 0);
E 4
I 4
D 23
	u.u_error = soreceive(fp->f_socket, uap->asa ? &sa : 0);
E 23
I 23
D 27
	u.u_error = soreceive(fp->f_socket, uap->asa ? &sa : 0, &auio);
E 27
E 23
	if (u.u_error)
		return;
D 27
	if (uap->asa)
		(void) copyout((caddr_t)&sa, (caddr_t)uap->asa, sizeof (sa));
I 11
D 24
	u.u_r.r_val1 = uap->count - u.u_count;
E 24
I 24
	u.u_r.r_val1 = uap->count - auio.uio_resid;
E 27
I 27
D 30
	u.u_error = sosend(fp->f_socket, (struct mbuf *)0, &auio);
E 30
I 30
D 47
	u.u_error = sosend(fp->f_socket, (struct mbuf *)0, &auio, uap->flags);
I 38
	u.u_r.r_val1 = uap->len - auio.uio_resid;
E 47
I 47
	msg.msg_iov = aiov;
D 62
#ifdef notdef
printf("sendmsg name %x namelen %d iov %x iovlen %d accrights %x &len %d\n",
msg.msg_name, msg.msg_namelen, msg.msg_iov, msg.msg_iovlen,
msg.msg_accrights, msg.msg_accrightslen);
#endif
E 62
	sendit(uap->s, &msg, uap->flags);
E 47
E 38
E 30
E 27
E 24
E 11
E 4
}
I 6

I 47
sendit(s, mp, flags)
	int s;
	register struct msghdr *mp;
	int flags;
{
	register struct file *fp;
	struct uio auio;
	register struct iovec *iov;
	register int i;
	struct mbuf *to, *rights;
	int len;
	
	fp = getsock(s);
	if (fp == 0)
		return;
	auio.uio_iov = mp->msg_iov;
	auio.uio_iovcnt = mp->msg_iovlen;
D 52
	auio.uio_segflg = 0;
E 52
I 52
	auio.uio_segflg = UIO_USERSPACE;
E 52
	auio.uio_offset = 0;			/* XXX */
	auio.uio_resid = 0;
	iov = mp->msg_iov;
D 62
	for (i = 0; i < mp->msg_iovlen; i++) {
E 62
I 62
	for (i = 0; i < mp->msg_iovlen; i++, iov++) {
E 62
		if (iov->iov_len < 0) {
			u.u_error = EINVAL;
			return;
		}
I 51
		if (iov->iov_len == 0)
			continue;
E 51
		if (useracc(iov->iov_base, (u_int)iov->iov_len, B_READ) == 0) {
			u.u_error = EFAULT;
			return;
		}
		auio.uio_resid += iov->iov_len;
D 62
		iov++;
E 62
	}
	if (mp->msg_name) {
		u.u_error =
D 57
		    sockargs(&to, mp->msg_name, mp->msg_namelen);
E 57
I 57
		    sockargs(&to, mp->msg_name, mp->msg_namelen, MT_SONAME);
E 57
		if (u.u_error)
			return;
	} else
		to = 0;
	if (mp->msg_accrights) {
		u.u_error =
D 57
		    sockargs(&rights, mp->msg_accrights, mp->msg_accrightslen);
E 57
I 57
		    sockargs(&rights, mp->msg_accrights, mp->msg_accrightslen,
		    MT_RIGHTS);
E 57
		if (u.u_error)
			goto bad;
	} else
		rights = 0;
	len = auio.uio_resid;
	u.u_error =
	    sosend((struct socket *)fp->f_data, to, &auio, flags, rights);
	u.u_r.r_val1 = len - auio.uio_resid;
	if (rights)
		m_freem(rights);
bad:
	if (to)
		m_freem(to);
}

E 47
I 27
recvfrom()
{
	register struct a {
		int	s;
		caddr_t	buf;
		int	len;
		int	flags;
		caddr_t	from;
		int	*fromlenaddr;
	} *uap = (struct a *)u.u_ap;
D 47
	register struct file *fp;
	struct uio auio;
E 47
I 47
	struct msghdr msg;
E 47
	struct iovec aiov;
D 47
	struct mbuf *from;
	int fromlen;
E 47
I 47
	int len;
E 47

D 40
	if (copyin((caddr_t)uap->fromlenaddr, (caddr_t)&fromlen, sizeof (fromlen))) {
		u.u_error = EFAULT;
E 40
I 40
D 47
	u.u_error = copyin((caddr_t)uap->fromlenaddr, (caddr_t)&fromlen,
		sizeof (fromlen));
E 47
I 47
	u.u_error = copyin((caddr_t)uap->fromlenaddr, (caddr_t)&len,
	   sizeof (len));
E 47
	if (u.u_error)
E 40
		return;
D 40
	}
E 40
D 47
	fp = getf(uap->s);
	if (fp == 0)
		return;
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
	}
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
E 47
I 47
	msg.msg_name = uap->from;
	msg.msg_namelen = len;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
E 47
	aiov.iov_base = uap->buf;
	aiov.iov_len = uap->len;
D 47
	auio.uio_resid = uap->len;
	auio.uio_segflg = 0;
	auio.uio_offset = 0;	/* XXX */
D 33
	if (useracc(uap->buf, uap->len, B_WRITE) == 0)  {
E 33
I 33
	if (useracc(uap->buf, (u_int)uap->len, B_WRITE) == 0)  {
E 33
		u.u_error = EFAULT;
		return;
	}
	from = 0;
D 30
	u.u_error = soreceive(fp->f_socket, &from, &auio);
E 30
I 30
	u.u_error = soreceive(fp->f_socket, &from, &auio, uap->flags);
E 30
	if (u.u_error)
		goto bad;
	if (from == 0)
		fromlen = 0;
	else {
		if (fromlen > from->m_len)
			fromlen = from->m_len;
D 33
		if (copyout(mtod(from, caddr_t), uap->from, fromlen)) {
E 33
I 33
D 40
		if (copyout(mtod(from, caddr_t), uap->from, (u_int)fromlen)) {
E 33
			u.u_error = EFAULT;
E 40
I 40
		u.u_error = copyout(mtod(from, caddr_t), uap->from,
			(u_int)fromlen);
		if (u.u_error)
E 40
			goto bad;
D 40
		}
E 40
	}
D 40
	if (copyout((caddr_t)&fromlen, (caddr_t)uap->fromlenaddr,
	    sizeof (fromlen))) {
		u.u_error = EFAULT;
E 40
I 40
	u.u_error = copyout((caddr_t)&fromlen, (caddr_t)uap->fromlenaddr,
	    sizeof (fromlen));
	if (u.u_error)
E 40
		goto bad;
D 40
	}
E 40
	u.u_r.r_val1 = uap->len - auio.uio_resid;
bad:
	if (from)
		m_freem(from);
E 47
I 47
	msg.msg_accrights = 0;
	msg.msg_accrightslen = 0;
	recvit(uap->s, &msg, uap->flags, (caddr_t)uap->fromlenaddr, (caddr_t)0);
E 47
D 42
	return;
E 42
}

recv()
{
	register struct a {
		int	s;
		caddr_t	buf;
		int	len;
		int	flags;
	} *uap = (struct a *)u.u_ap;
D 47
	register struct file *fp;
	struct uio auio;
E 47
I 47
	struct msghdr msg;
E 47
	struct iovec aiov;

D 47
	fp = getf(uap->s);
	if (fp == 0)
		return;
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
	}
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
E 47
I 47
	msg.msg_name = 0;
	msg.msg_namelen = 0;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
E 47
	aiov.iov_base = uap->buf;
	aiov.iov_len = uap->len;
D 47
	auio.uio_resid = uap->len;
	auio.uio_segflg = 0;
	auio.uio_offset = 0;	/* XXX */
D 33
	if (useracc(uap->buf, uap->len, B_WRITE) == 0)  {
E 33
I 33
	if (useracc(uap->buf, (u_int)uap->len, B_WRITE) == 0)  {
E 33
		u.u_error = EFAULT;
		return;
	}
D 30
	u.u_error = soreceive(fp->f_socket, (struct mbuf *)0, &auio);
E 30
I 30
D 33
	u.u_error = soreceive(fp->f_socket, (struct mbuf *)0, &auio, uap->flags);
E 33
I 33
	u.u_error =
	    soreceive(fp->f_socket, (struct mbuf **)0, &auio, uap->flags);
E 33
E 30
	u.u_r.r_val1 = uap->len - auio.uio_resid;
E 47
I 47
	msg.msg_accrights = 0;
	msg.msg_accrightslen = 0;
	recvit(uap->s, &msg, uap->flags, (caddr_t)0, (caddr_t)0);
E 47
}

D 47
sendmsg()
E 47
I 47
recvmsg()
E 47
{
I 47
	register struct a {
		int	s;
		struct	msghdr *msg;
		int	flags;
	} *uap = (struct a *)u.u_ap;
	struct msghdr msg;
	struct iovec aiov[MSG_MAXIOVLEN];
E 47

D 47
	u.u_error = EINVAL;
E 47
I 47
	u.u_error = copyin((caddr_t)uap->msg, (caddr_t)&msg, sizeof (msg));
	if (u.u_error)
		return;
	if ((u_int)msg.msg_iovlen >= sizeof (aiov) / sizeof (aiov[0])) {
		u.u_error = EMSGSIZE;
		return;
	}
	u.u_error =
	    copyin((caddr_t)msg.msg_iov, (caddr_t)aiov,
		(unsigned)(msg.msg_iovlen * sizeof (aiov[0])));
	if (u.u_error)
		return;
	msg.msg_iov = aiov;
	if (msg.msg_accrights)
		if (useracc((caddr_t)msg.msg_accrights,
		    (unsigned)msg.msg_accrightslen, B_WRITE) == 0) {
			u.u_error = EFAULT;
			return;
		}
	recvit(uap->s, &msg, uap->flags,
	    (caddr_t)&uap->msg->msg_namelen,
	    (caddr_t)&uap->msg->msg_accrightslen);
E 47
}

D 47
recvmsg()
E 47
I 47
recvit(s, mp, flags, namelenp, rightslenp)
	int s;
	register struct msghdr *mp;
	int flags;
	caddr_t namelenp, rightslenp;
E 47
{
D 47

	u.u_error = EINVAL;
E 47
I 47
	register struct file *fp;
	struct uio auio;
	register struct iovec *iov;
	register int i;
	struct mbuf *from, *rights;
	int len;
	
	fp = getsock(s);
	if (fp == 0)
		return;
	auio.uio_iov = mp->msg_iov;
	auio.uio_iovcnt = mp->msg_iovlen;
D 52
	auio.uio_segflg = 0;
E 52
I 52
	auio.uio_segflg = UIO_USERSPACE;
E 52
	auio.uio_offset = 0;			/* XXX */
	auio.uio_resid = 0;
	iov = mp->msg_iov;
D 62
	for (i = 0; i < mp->msg_iovlen; i++) {
E 62
I 62
	for (i = 0; i < mp->msg_iovlen; i++, iov++) {
E 62
		if (iov->iov_len < 0) {
			u.u_error = EINVAL;
			return;
		}
I 51
		if (iov->iov_len == 0)
			continue;
E 51
		if (useracc(iov->iov_base, (u_int)iov->iov_len, B_WRITE) == 0) {
			u.u_error = EFAULT;
			return;
		}
		auio.uio_resid += iov->iov_len;
D 62
		iov++;
E 62
	}
	len = auio.uio_resid;
	u.u_error =
	    soreceive((struct socket *)fp->f_data, &from, &auio,
		flags, &rights);
	u.u_r.r_val1 = len - auio.uio_resid;
	if (mp->msg_name) {
		len = mp->msg_namelen;
		if (len <= 0 || from == 0)
			len = 0;
		else {
			if (len > from->m_len)
				len = from->m_len;
			(void) copyout((caddr_t)mtod(from, caddr_t),
			    (caddr_t)mp->msg_name, (unsigned)len);
		}
		(void) copyout((caddr_t)&len, namelenp, sizeof (int));
	}
	if (mp->msg_accrights) {
		len = mp->msg_accrightslen;
		if (len <= 0 || rights == 0)
			len = 0;
		else {
			if (len > rights->m_len)
				len = rights->m_len;
			(void) copyout((caddr_t)mtod(rights, caddr_t),
			    (caddr_t)mp->msg_accrights, (unsigned)len);
		}
		(void) copyout((caddr_t)&len, rightslenp, sizeof (int));
	}
	if (rights)
		m_freem(rights);
	if (from)
		m_freem(from);
E 47
}

shutdown()
{
I 41
	struct a {
		int	s;
		int	how;
	} *uap = (struct a *)u.u_ap;
	struct file *fp;
E 41

D 41
	u.u_error = EINVAL;
E 41
I 41
D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
	if (fp == 0)
		return;
D 47
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
	}
	u.u_error = soshutdown(fp->f_socket, uap->how);
E 47
I 47
	u.u_error = soshutdown((struct socket *)fp->f_data, uap->how);
E 47
E 41
}

I 42
setsockopt()
{
	struct a {
		int	s;
		int	level;
		int	name;
		caddr_t	val;
		int	valsize;
	} *uap = (struct a *)u.u_ap;
	struct file *fp;
D 43
	struct mbuf *m;
E 43
I 43
	struct mbuf *m = NULL;
E 43

D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
	if (fp == 0)
		return;
D 47
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
	}
E 47
	if (uap->valsize > MLEN) {
		u.u_error = EINVAL;
		return;
	}
D 43
	m = m_get(M_WAIT, MT_SOOPTS);
	if (m == 0) {
		u.u_error = ENOBUFS;
		return;
E 43
I 43
	if (uap->val) {
		m = m_get(M_WAIT, MT_SOOPTS);
D 46
		if (m == 0) {
E 46
I 46
		if (m == NULL) {
E 46
			u.u_error = ENOBUFS;
			return;
		}
D 47
		u.u_error = copyin(uap->val, mtod(m, caddr_t),
		  (u_int)uap->valsize);
E 47
I 47
		u.u_error =
		    copyin(uap->val, mtod(m, caddr_t), (u_int)uap->valsize);
E 47
D 54
		if (u.u_error)
			goto bad;
E 54
I 54
		if (u.u_error) {
			(void) m_free(m);
			return;
		}
E 54
		m->m_len = uap->valsize;
E 43
	}
D 43
	u.u_error = copyin(uap->val, mtod(m, caddr_t), (u_int)uap->valsize);
	if (u.u_error)
		goto bad;
	m->m_len = uap->valsize;
E 43
D 47
	u.u_error = sosetopt(fp->f_socket, uap->level, uap->name, m);
E 47
I 47
	u.u_error =
	    sosetopt((struct socket *)fp->f_data, uap->level, uap->name, m);
E 47
D 54
bad:
D 43
	(void) m_free(m);
E 43
I 43
	if (m != NULL)
		(void) m_free(m);
E 54
E 43
}

getsockopt()
{
	struct a {
		int	s;
		int	level;
		int	name;
		caddr_t	val;
		int	*avalsize;
	} *uap = (struct a *)u.u_ap;
	struct file *fp;
D 43
	struct mbuf *m;
E 43
I 43
	struct mbuf *m = NULL;
E 43
	int valsize;

D 47
	fp = getf(uap->s);
E 47
I 47
	fp = getsock(uap->s);
E 47
	if (fp == 0)
		return;
D 47
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return;
	}
E 47
D 43
	u.u_error = copyin((caddr_t)uap->avalsize, (caddr_t)&valsize,
		sizeof (valsize));
	if (u.u_error)
		return;
	if (useracc((caddr_t)uap->val, (u_int)valsize, B_WRITE) == 0) {
		u.u_error = EFAULT;
		return;
E 43
I 43
	if (uap->val) {
		u.u_error = copyin((caddr_t)uap->avalsize, (caddr_t)&valsize,
			sizeof (valsize));
		if (u.u_error)
			return;
D 54
		m = m_get(M_WAIT, MT_SOOPTS);
		if (m == NULL) {
			u.u_error = ENOBUFS;
			return;
		}
E 43
	}
E 54
I 54
	} else
		valsize = 0;
E 54
D 43
	m = m_get(M_WAIT, MT_SOOPTS);
	if (m == 0) {
		u.u_error = ENOBUFS;
		return;
	}
E 43
D 47
	u.u_error = sogetopt(fp->f_socket, uap->level, uap->name, m);
E 47
I 47
	u.u_error =
D 54
	    sogetopt((struct socket *)fp->f_data, uap->level, uap->name, m);
E 54
I 54
	    sogetopt((struct socket *)fp->f_data, uap->level, uap->name, &m);
E 54
E 47
	if (u.u_error)
		goto bad;
D 43
	if (valsize > m->m_len)
		valsize = m->m_len;
	u.u_error = copyout(mtod(m, caddr_t), uap->val, (u_int)valsize);
	if (u.u_error)
		goto bad;
	u.u_error = copyout((caddr_t)&valsize, (caddr_t)uap->avalsize,
	    sizeof (valsize));
E 43
I 43
D 54
	if (uap->val) {
E 54
I 54
	if (uap->val && valsize && m != NULL) {
E 54
		if (valsize > m->m_len)
			valsize = m->m_len;
		u.u_error = copyout(mtod(m, caddr_t), uap->val, (u_int)valsize);
		if (u.u_error)
			goto bad;
		u.u_error = copyout((caddr_t)&valsize, (caddr_t)uap->avalsize,
		    sizeof (valsize));
	}
E 43
bad:
D 43
	(void) m_free(m);
E 43
I 43
	if (m != NULL)
		(void) m_free(m);
E 43
}

E 42
pipe()
{
	register struct file *rf, *wf;
	struct socket *rso, *wso;
	int r;

D 33
	u.u_error = socreate(1, &rso, SOCK_STREAM, 0, 0);
E 33
I 33
D 37
	u.u_error = socreate(1, &rso, SOCK_STREAM, 0, (struct socketopt *)0);
E 37
I 37
D 47
	u.u_error = socreate(AF_UNIX, &rso, SOCK_STREAM, 0,
		(struct socketopt *)0);
E 47
I 47
	u.u_error = socreate(AF_UNIX, &rso, SOCK_STREAM, 0);
E 47
E 37
E 33
	if (u.u_error)
		return;
D 33
	u.u_error = socreate(1, &wso, SOCK_STREAM, 0, 0);
E 33
I 33
D 37
	u.u_error = socreate(1, &wso, SOCK_STREAM, 0, (struct socketopt *)0);
E 37
I 37
D 47
	u.u_error = socreate(AF_UNIX, &wso, SOCK_STREAM, 0,
		(struct socketopt *)0);
E 47
I 47
	u.u_error = socreate(AF_UNIX, &wso, SOCK_STREAM, 0);
E 47
E 37
E 33
	if (u.u_error)
		goto free;
	rf = falloc();
	if (rf == NULL)
		goto free2;
	r = u.u_r.r_val1;
	rf->f_flag = FREAD;
	rf->f_type = DTYPE_SOCKET;
D 47
	rf->f_socket = rso;
E 47
I 47
	rf->f_ops = &socketops;
	rf->f_data = (caddr_t)rso;
E 47
	wf = falloc();
	if (wf == NULL)
		goto free3;
	wf->f_flag = FWRITE;
	wf->f_type = DTYPE_SOCKET;
D 47
	wf->f_socket = wso;
E 47
I 47
	wf->f_ops = &socketops;
	wf->f_data = (caddr_t)wso;
E 47
	u.u_r.r_val2 = u.u_r.r_val1;
	u.u_r.r_val1 = r;
D 56
	if (piconnect(wso, rso) == 0)
E 56
I 56
D 63
	if (u.u_error = unp_connect2(wso, (struct mbuf *)0, rso))
E 63
I 63
	if (u.u_error = unp_connect2(wso, rso))
E 63
E 56
		goto free4;
I 56
	wso->so_state |= SS_CANTRCVMORE;
	rso->so_state |= SS_CANTSENDMORE;
E 56
	return;
free4:
	wf->f_count = 0;
	u.u_ofile[u.u_r.r_val2] = 0;
free3:
	rf->f_count = 0;
	u.u_ofile[r] = 0;
free2:
D 61
	wso->so_state |= SS_NOFDREF;
	sofree(wso);
E 61
I 61
D 64
	soclose(wso);
E 64
I 64
	(void)soclose(wso);
E 64
E 61
free:
D 61
	rso->so_state |= SS_NOFDREF;
	sofree(rso);
E 61
I 61
D 64
	soclose(rso);
E 64
I 64
	(void)soclose(rso);
E 64
E 61
}

E 27
/*
D 45
 * Get socket address.
E 45
I 45
 * Get socket name.
E 45
 */
D 45
ssocketaddr()
E 45
I 45
getsockname()
E 45
{
	register struct a {
		int	fdes;
D 45
		struct	sockaddr *asa;
E 45
I 45
		caddr_t	asa;
		int	*alen;
E 45
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
I 17
	register struct socket *so;
D 27
	struct sockaddr addr;
E 27
I 27
	struct mbuf *m;
I 45
	int len;
E 45
E 27
E 17
D 20
COUNT(SSOCKETADDR);
E 20

D 47
	fp = getf(uap->fdes);
E 47
I 47
	fp = getsock(uap->fdes);
E 47
	if (fp == 0)
		return;
D 21
	if ((fp->f_flag & FSOCKET) == 0) {
E 21
I 21
D 47
	if (fp->f_type != DTYPE_SOCKET) {
E 21
		u.u_error = ENOTSOCK;
		return;
	}
E 47
I 45
	u.u_error = copyin((caddr_t)uap->alen, (caddr_t)&len, sizeof (len));
	if (u.u_error)
		return;
E 45
D 7
	copyout(fp->f_socket->f_
E 7
I 7
D 17
	if (copyout((caddr_t)&fp->f_socket->so_addr, (caddr_t)uap->asa, 
	    sizeof (struct sockaddr))) {
		u.u_error = EFAULT;
E 17
I 17
D 47
	so = fp->f_socket;
E 47
I 47
	so = (struct socket *)fp->f_data;
E 47
I 27
D 39
	m = m_getclr(M_WAIT);
E 39
I 39
	m = m_getclr(M_WAIT, MT_SONAME);
I 46
	if (m == NULL) {
		u.u_error = ENOBUFS;
		return;
	}
E 46
E 39
E 27
D 45
	u.u_error =
D 27
		(*so->so_proto->pr_usrreq)(so, PRU_SOCKADDR, 0, (caddr_t)&addr);
E 27
I 27
		(*so->so_proto->pr_usrreq)(so, PRU_SOCKADDR, 0, m, 0);
E 45
I 45
	u.u_error = (*so->so_proto->pr_usrreq)(so, PRU_SOCKADDR, 0, m, 0);
E 45
E 27
	if (u.u_error)
E 17
D 27
		return;
D 17
	}
E 17
I 17
	if (copyout((caddr_t)&addr, (caddr_t)uap->asa, sizeof (addr)))
E 27
I 27
		goto bad;
D 40
	if (copyout(mtod(m, caddr_t), (caddr_t)uap->asa, sizeof (struct sockaddr)))
E 27
		u.u_error = EFAULT;
E 40
I 40
D 45
	u.u_error = copyout(mtod(m, caddr_t), (caddr_t)uap->asa,
		sizeof (struct sockaddr));
E 45
I 45
	if (len > m->m_len)
		len = m->m_len;
	u.u_error = copyout(mtod(m, caddr_t), (caddr_t)uap->asa, (u_int)len);
	if (u.u_error)
		goto bad;
	u.u_error = copyout((caddr_t)&len, (caddr_t)uap->alen, sizeof (len));
E 45
E 40
I 27
bad:
	m_freem(m);
}

I 49
/*
 * Get name of peer for connected socket.
 */
getpeername()
{
	register struct a {
		int	fdes;
		caddr_t	asa;
		int	*alen;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
	register struct socket *so;
	struct mbuf *m;
	int len;

	fp = getsock(uap->fdes);
	if (fp == 0)
		return;
	so = (struct socket *)fp->f_data;
	if ((so->so_state & SS_ISCONNECTED) == 0) {
		u.u_error = ENOTCONN;
		return;
	}
	m = m_getclr(M_WAIT, MT_SONAME);
	if (m == NULL) {
		u.u_error = ENOBUFS;
		return;
	}
	u.u_error = copyin((caddr_t)uap->alen, (caddr_t)&len, sizeof (len));
	if (u.u_error)
		return;
	u.u_error = (*so->so_proto->pr_usrreq)(so, PRU_PEERADDR, 0, m, 0);
	if (u.u_error)
		goto bad;
	if (len > m->m_len)
		len = m->m_len;
	u.u_error = copyout(mtod(m, caddr_t), (caddr_t)uap->asa, (u_int)len);
	if (u.u_error)
		goto bad;
	u.u_error = copyout((caddr_t)&len, (caddr_t)uap->alen, sizeof (len));
bad:
	m_freem(m);
}

E 49
D 47
sockname(aname, name, namelen)
E 47
I 47
D 57
sockargs(aname, name, namelen)
E 57
I 57
sockargs(aname, name, namelen, type)
E 57
E 47
	struct mbuf **aname;
	caddr_t name;
D 57
	int namelen;
E 57
I 57
	int namelen, type;
E 57
{
	register struct mbuf *m;
I 40
	int error;
E 40

D 70
	if (namelen > MLEN)
E 70
I 70
	if ((u_int)namelen > MLEN)
E 70
		return (EINVAL);
D 39
	m = m_get(M_WAIT);
E 39
I 39
D 57
	m = m_get(M_WAIT, MT_SONAME);
E 57
I 57
	m = m_get(M_WAIT, type);
E 57
I 46
	if (m == NULL)
		return (ENOBUFS);
E 46
E 39
D 30
	m->m_off = MMINOFF;
E 30
	m->m_len = namelen;
D 33
	if (copyin(name, mtod(m, caddr_t), namelen)) {
E 33
I 33
D 40
	if (copyin(name, mtod(m, caddr_t), (u_int)namelen)) {
E 40
I 40
	error = copyin(name, mtod(m, caddr_t), (u_int)namelen);
	if (error)
E 40
E 33
		(void) m_free(m);
D 40
		return (EFAULT);
	}
	*aname = m;
	return (0);
E 40
I 40
	else
		*aname = m;
	return (error);
I 47
}

struct file *
getsock(fdes)
	int fdes;
{
	register struct file *fp;

	fp = getf(fdes);
	if (fp == NULL)
		return (0);
	if (fp->f_type != DTYPE_SOCKET) {
		u.u_error = ENOTSOCK;
		return (0);
	}
	return (fp);
E 47
E 40
D 42
}

sockopt(so, opt)
	register struct socketopt *so;
	caddr_t opt;
{
	register struct mbuf *m;
I 40
D 41
	int error;
E 41
I 41
	register caddr_t cp;
	int error, len;
E 41
E 40

	if (opt == 0) {
		so->so_optlen = 0;
		so->so_optdata = 0;
		return (0);
	}
D 40
	if (copyin((caddr_t)opt, (caddr_t)so, sizeof (struct socketopt)))
		return (EFAULT);
E 40
I 40
	error = copyin((caddr_t)opt, (caddr_t)so, sizeof (struct socketopt));
	if (error)
		return (error);
E 40
	if (so->so_optlen < 0 || so->so_optlen > MLEN)
		return (EINVAL);
D 39
	m = m_get(M_WAIT);
E 39
I 39
	m = m_get(M_WAIT, MT_SOOPTS);
E 39
D 30
	m->m_off = MMINOFF;
E 30
	m->m_len = so->so_optlen;
D 33
	if (copyin(so->so_optdata, mtod(m, caddr_t), m->m_len)) {
E 33
I 33
D 40
	if (copyin(so->so_optdata, mtod(m, caddr_t), (u_int)m->m_len)) {
E 40
I 40
	error = copyin(so->so_optdata, mtod(m, caddr_t), (u_int)m->m_len);
	if (error) {
E 40
E 33
		(void) m_free(m);
D 40
		return (EFAULT);
E 40
I 40
		return (error);
E 40
	}
D 41
	so->so_optdata = mtod(m, caddr_t);
E 41
I 41
	so->so_optdata = mtod(m, struct sotemplate *);
	/*
	 * Verify data structure consistency.
	 */
	cp = (caddr_t)so->so_optdata;
	len = so->so_optlen;
	while (len > 0 && cp < (caddr_t)so->so_optdata + m->m_len) {
		struct sotemplate *tp;

		if (len < sizeof (struct sotemplate))
			break;
		tp = (struct sotemplate *)cp;
		len -= tp->opt_size + sizeof (int);
		cp += tp->opt_size + sizeof (int);
	}
	if (len != 0 || cp != (caddr_t)so->so_optdata + m->m_len)
		return (EINVAL);
E 41
	return (0);
E 42
E 27
E 17
}
E 7
E 6
E 2
E 1

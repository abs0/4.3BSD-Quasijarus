h23516
s 00004/00000/00045
d D 4.14 82/05/04 13:36:36 sam 20 19
c CAD kludges
e
s 00003/00000/00042
d D 4.13 82/03/15 04:49:02 wnj 19 18
c name changes; get/sethostname
e
s 00001/00000/00041
d D 4.12 82/02/15 13:29:04 wnj 18 17
c new group stuff
e
s 00000/00001/00041
d D 4.11 81/11/20 14:39:49 wnj 17 16
c more lint
e
s 00001/00000/00041
d D 4.10 81/11/20 01:11:26 wnj 16 15
c add socketaddr()
e
s 00000/00000/00041
d D 4.9 81/11/18 15:47:14 wnj 15 14
c more cleanup
e
s 00016/00005/00025
d D 4.8 81/11/16 14:25:00 wnj 14 13
c more lint
e
s 00003/00006/00027
d D 4.7 81/11/08 16:46:04 wnj 13 12
c remove port, portid, bind, send, datagram, receive and add
c ssocket, ssend and sreceive
e
s 00000/00002/00033
d D 4.6 81/10/17 16:14:48 wnj 12 11
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00007/00000/00028
d D 4.5 81/04/28 03:03:35 root 11 10
c new calls for port stuff
e
s 00003/00000/00025
d D 4.4 81/03/03 12:40:03 wnj 10 9
c add vtrace()
e
s 00001/00001/00024
d D 4.3 81/02/19 21:43:37 wnj 9 8
c %G%->%E%
e
s 00003/00000/00022
d D 4.2 81/02/08 01:32:35 wnj 8 7
c misc
e
s 00000/00000/00022
d D 4.1 80/11/09 17:02:10 bill 7 6
c stamp for 4bsd
e
s 00011/00016/00011
d D 3.6 80/09/16 17:27:05 bill 6 5
c routine cleanup
e
s 00001/00000/00026
d D 3.5 80/07/12 16:50:31 bill 5 4
c add vlimit()
e
s 00004/00003/00022
d D 3.4 80/07/01 08:17:29 bill 4 3
c various minor fixups pre-split to dev dir
e
s 00001/00001/00024
d D 3.3 80/06/07 03:02:40 bill 3 2
c %H%->%G%
e
s 00001/00000/00024
d D 3.2 80/05/08 10:15:55 bill 2 1
c additions for vhangup()
e
s 00024/00000/00000
d D 3.1 80/04/09 16:26:14 bill 1 0
c date and time created 80/04/09 16:26:14 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
/*	%M%	%I%	%E%	*/
E 9
I 4

E 4
E 3
/*
D 4
 * Definitions of functions defined in vmsysent.c,
 * to be included by vmsysent.h.
E 4
I 4
 * Externals for functions defined in vmsys.c.
E 4
 */

int	nosys();
D 17
int	nullsys();
E 17
D 6
int	vfork();
int	vread();
int	vwrite();
int	vshare();
int	vunbind();
D 4
int	vwait();
E 4
I 4
int	vwait();		/* deprecated */
E 4
int	vadvise();
int	vrelease();
int	vzero();
int	vclose();
I 2
int	vhangup();
E 6
I 6

I 14
/*
 * Random.
 */
E 14
int	vfork();		/* later, just fork? */
D 12
int	vread();		/* deprecated */
int	vwrite();		/* deprecated */
E 12
int	vadvise();		/* later, segadvise */
D 14

E 14
I 14
int	resuba();
int	futz();
E 14
int	vhangup();		/* should just do in exit() */
E 6
I 5
int	vlimit();
E 5
I 4
int	vswapon();
E 4
E 2
int	vtimes();
D 6
int	futz();
int	setef();
int	clref();
int	waitef();
int	readef();
E 6
I 6
D 14

E 14
I 10
#ifdef TRACE
int	vtrace();
#endif
I 18
int	setgrp();
E 18
I 14

I 19
int	gethostname();
int	sethostname();

I 20
#ifdef CAD
int	chfile();
#endif

E 20
E 19
/*
 * Segmentation.
 */
E 14
E 10
int	segalloc();		/* not in yet */
int	segfree();		/* not in yet */
int	segsync();		/* not in yet */
I 8

I 14
/*
 * IPC/Networking.
 */
int	ssplice();
E 14
I 11
D 13
int	sport();
int	portid();
int	bind();			/* not in yet */
int	send();			/* not in yet */
int	datagram();
int	receive();		/* not in yet */
E 13
I 13
int	ssocket();
I 14
int	sconnect();
int	saccept();
int	sdisconnect();
E 14
int	ssend();
int	sreceive();
I 16
int	ssocketaddr();
E 16
E 13
D 14

E 11
int	resuba();
int	futz();
E 14
E 8
E 6
E 1

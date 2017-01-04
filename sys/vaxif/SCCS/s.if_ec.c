h57481
s 00013/00002/00954
d D 7.3 88/08/04 15:16:43 bostic 60 59
c add Berkeley specific copyright
e
s 00001/00001/00955
d D 7.2 87/10/23 11:11:36 bostic 59 58
c move ubamem routine down one; (Chris Torek)
e
s 00001/00001/00955
d D 7.1 86/06/05 17:03:55 mckusick 58 57
c 4.3BSD release version
e
s 00002/00002/00954
d D 6.18 86/02/23 23:28:18 karels 57 56
c lint
e
s 00003/00008/00953
d D 6.17 86/02/18 16:28:00 karels 56 55
c clean up cluster allocation
e
s 00009/00023/00952
d D 6.16 86/01/24 18:33:16 karels 55 54
c use per-host trailer option from ARP
e
s 00000/00003/00975
d D 6.15 85/12/19 15:42:56 karels 54 53
c rm bbnnet
e
s 00050/00048/00928
d D 6.14 85/11/08 19:17:46 karels 53 52
c ifconfig down resets interface, ifconfig up reinitializes;
c return error when attempting to send to down interface
e
s 00002/00000/00974
d D 6.13 85/10/24 10:06:16 bloom 52 51
c add "#if N?? > 0" 
e
s 00024/00006/00950
d D 6.12 85/09/16 22:18:04 karels 51 50
c prepend ifp to input packets ala if_ubaget
e
s 00071/00015/00885
d D 6.11 85/08/09 11:38:32 sklower 50 49
c Latest fixes from Nesheim@cornell
e
s 00007/00000/00893
d D 6.10 85/07/02 22:39:29 sklower 49 48
c Helpful Fixes from Bill Nesheim@Cornell.
e
s 00096/00001/00797
d D 6.9 85/06/19 09:06:49 sklower 48 47
c check in for 4.3 beta -- known problems with 2nd xns interfaces.
e
s 00002/00000/00796
d D 6.8 85/05/04 22:55:11 bloom 47 46
c ifdef PUP include files
e
s 00034/00044/00762
d D 6.7 85/05/01 09:08:16 karels 46 45
c move interface addresses into protocols; remove struct ether_addr again
e
s 00064/00071/00742
d D 6.6 85/02/15 17:25:38 karels 45 44
c add uba mem configuration entry, get mem addr from flags
e
s 00011/00011/00802
d D 6.5 84/08/29 20:42:53 bloom 44 43
c change ot includes.  no more ../h
e
s 00041/00006/00772
d D 6.4 84/07/23 13:27:53 bloom 43 42
c Added support for more than one board on a system
e
s 00007/00009/00771
d D 6.3 84/03/22 15:09:06 karels 42 41
c new address resolution protocol; struct ether_addr
e
s 00003/00000/00777
d D 6.2 84/03/20 14:52:15 karels 41 40
c don't lose mbuf copies if q full; reinitialize all after uba reset
e
s 00000/00000/00777
d D 6.1 83/07/29 07:37:23 sam 40 39
c 4.2 distribution
e
s 00001/00001/00776
d D 4.38 83/07/19 00:38:10 sam 39 38
c how did these ever work before?
e
s 00001/00001/00776
d D 4.37 83/06/13 22:45:42 sam 38 37
c lint
e
s 00015/00008/00762
d D 4.36 83/06/13 00:00:09 sam 37 36
c someday I'll get all this correct (sigh)
e
s 00054/00020/00716
d D 4.35 83/06/12 23:13:20 sam 36 35
c ioctls and trailers
e
s 00006/00020/00730
d D 4.34 83/05/27 13:49:59 sam 35 34
c lint
e
s 00049/00039/00701
d D 4.33 83/03/15 18:21:08 sam 34 33
c ARP ARP
e
s 00001/00001/00739
d D 4.32 82/12/17 12:13:26 sam 33 32
c sun merge
e
s 00040/00052/00700
d D 4.31 82/12/16 15:40:01 sam 32 31
c fix byte swapping problems in header
e
s 00002/00002/00750
d D 4.30 82/12/14 17:21:18 sam 31 30
c typed mbufs
e
s 00007/00001/00745
d D 4.29 82/11/13 23:04:35 sam 30 29
c merge 4.1b with 4.1c
e
s 00001/00001/00745
d D 4.28 82/10/31 15:04:53 root 29 27
c ubareset routines now just if_reset!
e
s 00001/00001/00745
d R 4.28 82/10/24 14:38:10 wnj 28 27
c create netif directory
e
s 00001/00001/00745
d D 4.27 82/10/23 16:51:04 root 27 26
c lint
e
s 00001/00001/00745
d D 4.26 82/10/22 01:14:09 root 26 25
c lint
e
s 00015/00016/00731
d D 4.25 82/10/21 21:03:44 root 25 24
c lint
e
s 00013/00010/00734
d D 4.24 82/10/10 16:58:43 root 24 23
c move vax headers into vax directories
e
s 00007/00007/00737
d D 4.23 82/10/09 06:09:42 wnj 23 22
c fix includes
e
s 00032/00009/00712
d D 4.22 82/07/21 09:41:29 feldman 22 21
c 3com updates for 780 (from Bill Reeves)
e
s 00003/00002/00718
d D 4.21 82/06/30 21:32:27 wnj 21 20
c handle multiple uba's
e
s 00044/00040/00676
d D 4.20 82/06/23 21:09:29 sam 20 19
c recoded copy code to/from unibus for speed
e
s 00000/00011/00716
d D 4.19 82/06/20 00:52:03 sam 19 18
c purge COUNT stuff now that we can use gprof
e
s 00005/00004/00722
d D 4.18 82/06/17 22:02:40 feldman 18 17
c don't call ecxint at startup
e
s 00091/00106/00635
d D 4.17 82/06/17 20:46:53 sam 17 16
c ecput wasn't doing word transfers correctly
e
s 00001/00048/00740
d D 4.16 82/06/13 23:00:00 sam 16 15
c add class a/b/c net #'s and purge logical host kludge code
e
s 00002/00003/00786
d D 4.15 82/06/12 23:17:55 wnj 15 14
c now the routing code might wokr
e
s 00001/00001/00788
d D 4.14 82/06/05 21:19:26 wnj 14 13
c restore keywords
e
s 00022/00002/00767
d D 4.13 82/06/05 21:18:22 wnj 13 12
c use shorts to move data
e
s 00002/00001/00767
d D 4.12 82/05/27 12:43:25 sam 12 11
c try one more time to do it right
e
s 00001/00001/00767
d D 4.11 82/05/25 16:14:07 sam 11 10
c logical host route needs RTF_HOST
e
s 00009/00018/00759
d D 4.10 82/05/24 17:15:38 wnj 10 9
c pt-pt, loopback can transmit, fixed en bug that bugged sam
e
s 00013/00013/00764
d D 4.9 82/05/21 15:54:03 feldman 9 8
c understand interlan addresses
e
s 00003/00067/00774
d D 4.8 82/05/20 15:14:32 sam 8 7
c don't need kludgey delays and pup code will never work right
e
s 00001/00001/00840
d D 4.7 82/05/07 23:48:20 feldman 7 6
c fix collision handling bug (from Bill Reeves)
e
s 00006/00000/00835
d D 4.6 82/05/07 14:02:04 feldman 6 5
c Make sure memory turned on before accessing
e
s 00050/00014/00785
d D 4.5 82/04/14 15:00:12 feldman 5 4
c fixed collisions, kludge local send and broadcast
e
s 00001/00001/00798
d D 4.4 82/04/12 13:53:35 feldman 4 3
c fixed packet length check bug
e
s 00002/00002/00797
d D 4.3 82/04/11 15:16:58 sam 3 2
c reverse src and dst to raw_input
e
s 00001/00001/00798
d D 4.2 82/04/11 12:03:19 feldman 2 1
c fixed broadcast bug
e
s 00799/00000/00000
d D 4.1 82/04/11 01:35:06 feldman 1 0
c date and time created 82/04/11 01:35:06 by feldman
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
D 14
/*	if_ec.c	4.12	82/05/27	*/
E 14
I 14
D 48
/*	%M%	%I%	%E%	*/
E 48
I 48
/*
D 58
 * Copyright (c) 1982 Regents of the University of California.
E 58
I 58
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 58
D 60
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 60
I 60
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
E 60
 *
 *	%W% (Berkeley) %G%
 */
E 48
E 14
E 13

#include "ec.h"
I 52
#if NEC > 0
E 52
D 16
#include "imp.h"
I 5
#include "loop.h"
E 16
E 5

/*
 * 3Com Ethernet Controller interface
 */
I 33
#include "../machine/pte.h"
E 33

D 44
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/mbuf.h"
D 33
#include "../h/pte.h"
E 33
#include "../h/buf.h"
#include "../h/protosw.h"
#include "../h/socket.h"
D 24
#include "../h/ubareg.h"
#include "../h/ubavar.h"
#include "../h/ecreg.h"
#include "../h/cpu.h"
#include "../h/mtpr.h"
E 24
#include "../h/vmmac.h"
I 24
D 36
#include <errno.h>
E 36
I 36
#include "../h/ioctl.h"
#include "../h/errno.h"
E 44
I 44
#include "param.h"
#include "systm.h"
#include "mbuf.h"
#include "buf.h"
#include "protosw.h"
#include "socket.h"
I 53
#include "syslog.h"
E 53
#include "vmmac.h"
#include "ioctl.h"
#include "errno.h"
E 44
E 36

#include "../net/if.h"
#include "../net/netisr.h"
#include "../net/route.h"
I 48

I 51
D 54
#ifdef	BBNNET
#define	INET
#endif
E 54
E 51
#ifdef INET
E 48
E 24
D 23
#include "../net/in.h"
#include "../net/in_systm.h"
E 23
I 23
#include "../netinet/in.h"
#include "../netinet/in_systm.h"
I 46
#include "../netinet/in_var.h"
E 46
E 23
D 24
#include "../net/if.h"
D 23
#include "../net/if_ec.h"
#include "../net/if_uba.h"
#include "../net/ip.h"
#include "../net/ip_var.h"
#include "../net/pup.h"
E 23
I 23
#include "../vaxif/if_ec.h"
#include "../vaxif/if_uba.h"
E 24
#include "../netinet/ip.h"
D 51
#include "../netinet/ip_var.h"
E 51
I 34
#include "../netinet/if_ether.h"
I 48
#endif

E 48
I 47
D 53
#ifdef PUP
E 47
E 34
#include "../netpup/pup.h"
I 48
#endif PUP

E 53
#ifdef NS
#include "../netns/ns.h"
#include "../netns/ns_if.h"
E 48
I 47
#endif
E 47
E 23
D 24
#include "../net/route.h"
#include <errno.h>
E 24
I 24

#include "../vax/cpu.h"
#include "../vax/mtpr.h"
D 32
#include "../vaxif/if_ec.h"
E 32
I 32
D 34
#include "../vaxif/if_ether.h"
E 34
E 32
D 44
#include "../vaxif/if_ecreg.h"
#include "../vaxif/if_uba.h"
E 44
I 44
#include "if_ecreg.h"
#include "if_uba.h"
E 44
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 24

D 32
#define	ECMTU	1500
I 30
#define	ECMIN	(60-14)
E 32
E 30
I 22
D 43
#define	ECMEM	0000000
E 43
I 43
D 45
/*
 * The memory address must be consecutive.  Any allocations 
 * not in order will cause problems on a VAX 780.
 */
E 43
E 22

I 43
int ecmem[] = {
#if NEC > 0
	0000000,
E 45
I 45
#if CLSIZE == 2
#define ECBUFSIZE	32		/* on-board memory, clusters */
E 45
#endif
D 45
#if NEC > 1
	0100000,
#endif
#if NEC > 2
	0200000,
#endif
#if NEC > 3
	0300000,
#endif
#if NEC > 4
	0400000,
#endif
#if NEC > 5
	0500000,
#endif
#if NEC > 6
	0600000,
#endif
#if NEC > 7
	0700000,
#endif
	};
E 45

D 45
int necmem = 0;			/* count of current memory number for ecprobe */

E 43
int	ecprobe(), ecattach(), ecrint(), ecxint(), eccollide();
E 45
I 45
int	ecubamem(), ecprobe(), ecattach(), ecrint(), ecxint(), eccollide();
E 45
struct	uba_device *ecinfo[NEC];
u_short ecstd[] = { 0 };
struct	uba_driver ecdriver =
D 45
	{ ecprobe, 0, ecattach, 0, ecstd, "ec", ecinfo };
I 9
D 34
u_char	ec_iltop[3] = { 0x02, 0x07, 0x01 };
I 32
u_char	ecbroadcastaddr[6] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
E 34
E 32
E 9
#define	ECUNIT(x)	minor(x)
E 45
I 45
D 59
	{ ecprobe, 0, ecattach, 0, ecstd, "ec", ecinfo, 0, 0, 0, ecubamem };
E 59
I 59
	{ ecprobe, 0, ecattach, 0, ecstd, "ec", ecinfo, 0, 0, 0, 0, ecubamem };
E 59
E 45

D 36
int	ecinit(),ecoutput(),ecreset();
E 36
I 36
int	ecinit(),ecioctl(),ecoutput(),ecreset();
E 36
D 25
struct mbuf *ecget();
E 25
I 25
struct	mbuf *ecget();
E 25

I 5
extern struct ifnet loif;

E 5
/*
 * Ethernet software status per interface.
 *
 * Each interface is referenced by a network interface structure,
 * es_if, which the routing code uses to locate the interface.
 * This structure contains the output queue for the interface, its address, ...
 * We also have, for each interface, a UBA interface structure, which
 * contains information about the UNIBUS resources held by the interface:
 * map registers, buffered data paths, etc.  Information is cached in this
 * structure for use by the if_uba.c routines in running the interface
 * efficiently.
 */
struct	ec_softc {
D 34
	struct	ifnet es_if;		/* network-visible interface */
E 34
I 34
	struct	arpcom es_ac;		/* common Ethernet structures */
#define	es_if	es_ac.ac_if		/* network-visible interface */
#define	es_addr	es_ac.ac_enaddr		/* hardware Ethernet address */
E 34
	struct	ifuba es_ifuba;		/* UNIBUS resources */
D 5
	short	es_delay;		/* current output delay */
E 5
	short	es_mask;		/* mask for current output delay */
D 8
#ifdef notdef
I 5
	short	es_delay;		/* current output delay */
E 5
	long	es_lastx;		/* host last transmitted to */
#endif
E 8
	short	es_oactive;		/* is output active? */
D 25
	caddr_t	es_buf[16];		/* virtual addresses of buffers */
E 25
I 25
	u_char	*es_buf[16];		/* virtual addresses of buffers */
E 25
D 34
	u_char	es_enaddr[6];		/* board's ethernet address */
E 34
} ec_softc[NEC];

I 50
D 55
#ifdef DEBUG
ether_addr(s)
char *s;
{

	printf("%x:%x:%x:%x:%x:%x\n",
		s[0]&0xff, s[1]&0xff, s[2]&0xff,
		s[3]&0xff, s[4]&0xff, s[5]&0xff);
}
#endif

E 55
E 50
/*
D 45
 * Do output DMA to determine interface presence and
 * interrupt vector.  DMA is too short to disturb other hosts.
E 45
I 45
 * Configure on-board memory for an interface.
 * Called from autoconfig and after a uba reset.
 * The address of the memory on the uba is supplied in the device flags.
E 45
 */
D 45
ecprobe(reg)
	caddr_t reg;
E 45
I 45
ecubamem(ui, uban)
	register struct uba_device *ui;
E 45
{
D 45
	register int br, cvec;		/* r11, r10 value-result */
	register struct ecdevice *addr = (struct ecdevice *)reg;
D 21
	register caddr_t ecbuf = (caddr_t) &umem[0][0600000];
E 21
I 21
D 22
	register caddr_t ecbuf = (caddr_t) &umem[numuba][0600000];
E 22
I 22
D 43
	register caddr_t ecbuf = (caddr_t) &umem[numuba][ECMEM];
E 43
I 43
	register caddr_t ecbuf = (caddr_t) &umem[numuba][ecmem[necmem]];
E 45
I 45
	register caddr_t ecbuf = (caddr_t) &umem[uban][ui->ui_flags];
	register struct ecdevice *addr = (struct ecdevice *)ui->ui_addr;
E 45
E 43
E 22
E 21

D 19
COUNT(ECPROBE);
E 19
D 45
#ifdef lint
	br = 0; cvec = br; br = cvec;
	ecrint(0); ecxint(0); eccollide(0);
E 45
I 45
	/*
	 * Make sure csr is there (we run before ecprobe).
	 */
	if (badaddr((caddr_t)addr, 2))
		return (-1);
#if VAX780
	if (cpu == VAX_780 && uba_hd[uban].uh_uba->uba_sr) {
		uba_hd[uban].uh_uba->uba_sr = uba_hd[uban].uh_uba->uba_sr;
		return (-1);
	}
E 45
#endif
	/*
I 6
	 * Make sure memory is turned on
	 */
	addr->ec_rcr = EC_AROM;
	/*
I 22
D 45
	 * Disable map registers for ec unibus space,
	 * but don't allocate yet.
E 45
I 45
	 * Tell the system that the board has memory here, so it won't
	 * attempt to allocate the addresses later.
E 45
	 */
D 25
	ubamem(numuba, ECMEM, 32*2, 0);
E 25
I 25
D 43
	(void) ubamem(numuba, ECMEM, 32*2, 0);
E 43
I 43
D 45
	(void) ubamem(numuba, ecmem[necmem], 32*2, 0);
E 45
I 45
	if (ubamem(uban, ui->ui_flags, ECBUFSIZE*CLSIZE, 1) == 0) {
		printf("ec%d: cannot reserve uba addresses\n", ui->ui_unit);
		addr->ec_rcr = EC_MDISAB;	/* disable memory */
		return (-1);
	}
E 45
E 43
E 25
	/*
E 22
E 6
	 * Check for existence of buffers on Unibus.
D 22
	 * This won't work on a 780 until more work is done.
E 22
	 */
D 25
	if (badaddr((caddr_t) ecbuf, 2)) {
E 25
I 25
	if (badaddr((caddr_t)ecbuf, 2)) {
E 25
D 22
		printf("ec: buffer mem not found");
E 22
I 22
D 45
	bad1:
		printf("ec: buffer mem not found\n");
	bad2:
D 25
		ubamem(numuba, 0, 0, 0);	/* reenable map (780 only) */
E 25
I 25
		(void) ubamem(numuba, 0, 0, 0);	/* reenable map (780 only) */
E 45
I 45
bad:
		printf("ec%d: buffer mem not found\n", ui->ui_unit);
		(void) ubamem(uban, ui->ui_flags, ECBUFSIZE*2, 0);
E 45
E 25
		addr->ec_rcr = EC_MDISAB;	/* disable memory */
I 43
D 45
		necmem++;
E 43
E 22
		return (0);
E 45
I 45
		return (-1);
E 45
	}
I 22
#if VAX780
D 45
	if (cpu == VAX_780 && uba_hd[numuba].uh_uba->uba_sr) {
		uba_hd[numuba].uh_uba->uba_sr = uba_hd[numuba].uh_uba->uba_sr;
		goto bad1;
E 45
I 45
	if (cpu == VAX_780 && uba_hd[uban].uh_uba->uba_sr) {
		uba_hd[uban].uh_uba->uba_sr = uba_hd[uban].uh_uba->uba_sr;
		goto bad;
E 45
	}
#endif
I 45
	if (ui->ui_alive == 0)		/* Only printf from autoconfig */
		printf("ec%d: mem %x-%x\n", ui->ui_unit,
			ui->ui_flags, ui->ui_flags + ECBUFSIZE*CLBYTES - 1);
	ui->ui_type = 1;		/* Memory on, allocated */
	return (0);
}
E 45
E 22

I 45
/*
 * Do output DMA to determine interface presence and
 * interrupt vector.  DMA is too short to disturb other hosts.
 */
ecprobe(reg, ui)
	caddr_t reg;
	struct uba_device *ui;
{
	register int br, cvec;		/* r11, r10 value-result */
	register struct ecdevice *addr = (struct ecdevice *)reg;
	register caddr_t ecbuf = (caddr_t) &umem[ui->ui_ubanum][ui->ui_flags];

#ifdef lint
	br = 0; cvec = br; br = cvec;
	ecrint(0); ecxint(0); eccollide(0);
#endif

E 45
	/*
D 45
	 * Tell the system that the board has memory here, so it won't
	 * attempt to allocate the addresses later.
E 45
I 45
	 * Check that buffer memory was found and enabled.
E 45
	 */
D 21
	ubamem(0, 0600000, 32*2);
E 21
I 21
D 22
	ubamem(numuba, 0600000, 32*2);
E 22
I 22
D 43
	if (ubamem(numuba, ECMEM, 32*2, 1) == 0) {
E 43
I 43
D 45
	if (ubamem(numuba, ecmem[necmem], 32*2, 1) == 0) {
E 43
		printf("ecprobe: cannot reserve uba addresses\n");
		goto bad2;
	}
E 22
E 21

E 45
I 45
	if (ui->ui_type == 0)
		return(0);
E 45
	/*
	 * Make a one byte packet in what should be buffer #0.
D 45
	 * Submit it for sending.  This whould cause an xmit interrupt.
E 45
I 45
	 * Submit it for sending.  This should cause an xmit interrupt.
E 45
	 * The xmit interrupt vector is 8 bytes after the receive vector,
	 * so adjust for this before returning.
	 */
	*(u_short *)ecbuf = (u_short) 03777;
	ecbuf[03777] = '\0';
	addr->ec_xcr = EC_XINTEN|EC_XWBN;
	DELAY(100000);
	addr->ec_xcr = EC_XCLR;
I 21
D 22
	/* will this work if there's a collision? */
E 22
E 21
D 17
	if (cvec > 0 && cvec != 0x200)
E 17
I 17
	if (cvec > 0 && cvec != 0x200) {
E 17
D 22
		cvec -= 010;
D 17
		br += 2;
E 17
I 17
		br += 2;		/* rcv is xmit + 2 */
E 22
I 22
		if (cvec & 04) {	/* collision interrupt */
			cvec -= 04;
			br += 1;		/* rcv is collision + 1 */
		} else {		/* xmit interrupt */
			cvec -= 010;
			br += 2;		/* rcv is xmit + 2 */
		}
E 22
	}
I 43
D 45
	necmem++;
E 45
E 43
E 17
	return (1);
}

/*
 * Interface exists: make available by filling in network interface
 * record.  System will initialize the interface when it is ready
 * to accept packets.
 */
ecattach(ui)
	struct uba_device *ui;
{
D 17
	register struct ec_softc *es = &ec_softc[ui->ui_unit];
	register struct sockaddr_in *sin;
E 17
I 17
	struct ec_softc *es = &ec_softc[ui->ui_unit];
	register struct ifnet *ifp = &es->es_if;
E 17
	register struct ecdevice *addr = (struct ecdevice *)ui->ui_addr;
D 17
	register int i, j;
	register u_char *cp;
E 17
I 17
D 46
	struct sockaddr_in *sin;
E 46
	int i, j;
	u_char *cp;
E 17
D 19
COUNT(ECATTACH);
E 19

D 17
	es->es_if.if_unit = ui->ui_unit;
	es->es_if.if_name = "ec";
	es->es_if.if_mtu = ECMTU;
D 16
	es->es_if.if_net = ui->ui_flags & 0xff;
E 16
I 16
	es->es_if.if_net = ui->ui_flags;
E 17
I 17
	ifp->if_unit = ui->ui_unit;
	ifp->if_name = "ec";
D 32
	ifp->if_mtu = ECMTU;
E 32
I 32
	ifp->if_mtu = ETHERMTU;
E 32
D 34
	ifp->if_net = ui->ui_flags;
E 34
E 17
E 16

	/*
D 17
	 * Read the ethernet address off the board,
	 * one nibble at a time!
E 17
I 17
	 * Read the ethernet address off the board, one nibble at a time.
E 17
	 */
D 50
	addr->ec_xcr = EC_UECLR;
E 50
I 50
	addr->ec_xcr = EC_UECLR; /* zero address pointer */
E 50
	addr->ec_rcr = EC_AROM;
D 34
	cp = es->es_enaddr;
E 34
I 34
D 42
	cp = es->es_addr;
E 42
I 42
D 46
	cp = (u_char *) &es->es_addr;
E 46
I 46
	cp = es->es_addr;
E 46
E 42
E 34
I 17
#define	NEXTBIT	addr->ec_rcr = EC_AROM|EC_ASTEP; addr->ec_rcr = EC_AROM
E 17
D 42
	for (i=0; i<6; i++) {
E 42
I 42
	for (i=0; i < sizeof (es->es_addr); i++) {
E 42
		*cp = 0;
		for (j=0; j<=4; j+=4) {
			*cp |= ((addr->ec_rcr >> 8) & 0xf) << j;
D 17
			addr->ec_rcr = EC_AROM|EC_ASTEP;
			addr->ec_rcr = EC_AROM;
			addr->ec_rcr = EC_AROM|EC_ASTEP;
			addr->ec_rcr = EC_AROM;
			addr->ec_rcr = EC_AROM|EC_ASTEP;
			addr->ec_rcr = EC_AROM;
			addr->ec_rcr = EC_AROM|EC_ASTEP;
			addr->ec_rcr = EC_AROM;
E 17
I 17
			NEXTBIT; NEXTBIT; NEXTBIT; NEXTBIT;
E 17
		}
		cp++;
	}
I 49
D 50
	/*
	 * Now write it into the address recognition ROM so we can
	 * always use the same EC_READ bits (referencing ROM),
	 * in case we change the address sometime
	 */
	ec_setaddr(es->es_addr, ui->ui_unit);

E 50
I 50
D 55
#ifdef DEBUG
	printf("ecattach %d: addr=",ui->ui_unit);
	ether_addr(es->es_addr);
#endif
E 55
I 55
	printf("ec%d: hardware address %s\n", ui->ui_unit,
		ether_sprintf(es->es_addr));
E 55
E 50
E 49
I 17
D 35
#ifdef notdef
E 17
I 8
D 9
#ifdef notdef
E 9
E 8
	printf("ec%d: addr=%x:%x:%x:%x:%x:%x\n", ui->ui_unit,
D 34
		es->es_enaddr[0]&0xff, es->es_enaddr[1]&0xff,
		es->es_enaddr[2]&0xff, es->es_enaddr[3]&0xff,
		es->es_enaddr[4]&0xff, es->es_enaddr[5]&0xff);
E 34
I 34
		es->es_addr[0]&0xff, es->es_addr[1]&0xff,
		es->es_addr[2]&0xff, es->es_addr[3]&0xff,
		es->es_addr[4]&0xff, es->es_addr[5]&0xff);
E 34
I 8
D 9
#endif
E 9
E 8
D 17
	es->es_if.if_host[0] = ((es->es_enaddr[3]&0xff)<<16) |
E 17
I 17
#endif
E 35
D 34
	ifp->if_host[0] = ((es->es_enaddr[3]&0xff)<<16) |
E 17
	    ((es->es_enaddr[4]&0xff)<<8) | (es->es_enaddr[5]&0xff);
E 34
D 46
	sin = (struct sockaddr_in *)&es->es_if.if_addr;
	sin->sin_family = AF_INET;
E 46
D 17
	sin->sin_addr = if_makeaddr(es->es_if.if_net, es->es_if.if_host[0]);
E 17
I 17
D 34
	sin->sin_addr = if_makeaddr(ifp->if_net, ifp->if_host[0]);
E 17

D 17
	sin = (struct sockaddr_in *)&es->es_if.if_broadaddr;
E 17
I 17
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
E 17
	sin->sin_family = AF_INET;
D 17
	sin->sin_addr = if_makeaddr(es->es_if.if_net, 0);
	es->es_if.if_flags = IFF_BROADCAST;
E 17
I 17
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags = IFF_BROADCAST;
E 17

E 34
I 34
D 35
	if (ui->ui_flags) {
		i = ((es->es_addr[3]&0xff)<<16) |
		    ((es->es_addr[4]&0xff)<<8) |
		    (es->es_addr[5]&0xff);
		sin->sin_addr = if_makeaddr(ui->ui_flags, i);
	} else
		sin->sin_addr = arpmyaddr();
E 35
I 35
D 42
	sin->sin_addr = arpmyaddr((struct arpcom *)0);
E 42
E 35
E 34
D 17
	es->es_if.if_init = ecinit;
	es->es_if.if_output = ecoutput;
	es->es_if.if_ubareset = ecreset;
E 17
I 17
	ifp->if_init = ecinit;
I 36
	ifp->if_ioctl = ecioctl;
E 36
	ifp->if_output = ecoutput;
D 29
	ifp->if_ubareset = ecreset;
E 29
I 29
	ifp->if_reset = ecreset;
I 46
	ifp->if_flags = IFF_BROADCAST;
E 46
E 29
E 17
	for (i=0; i<16; i++)
D 22
		es->es_buf[i] = &umem[ui->ui_ubanum][0600000+2048*i];
E 22
I 22
D 25
		es->es_buf[i] = &umem[ui->ui_ubanum][ECMEM+2048*i];
E 25
I 25
D 43
		es->es_buf[i] = (u_char *)&umem[ui->ui_ubanum][ECMEM+2048*i];
E 43
I 43
		es->es_buf[i] 
D 45
		    = (u_char *)&umem[ui->ui_ubanum][ecmem[ifp->if_unit]+2048*i];
E 45
I 45
		    = (u_char *)&umem[ui->ui_ubanum][ui->ui_flags + 2048*i];
E 45
E 43
E 25
E 22
D 17
	if_attach(&es->es_if);
E 17
I 17
	if_attach(ifp);
E 17
D 16
#if NIMP == 0
	/* here's one for you john baby.... */
	if (ui->ui_flags &~ 0xff)
D 10
		eclhinit((ui->ui_flags &~ 0xff) | 0x0a);
E 10
I 10
		eclhinit(&es->es_if, (ui->ui_flags &~ 0xff) | 0x0a);
E 10
#endif
E 16
}

/*
 * Reset of interface after UNIBUS reset.
 * If interface is on specified uba, reset its state.
 */
ecreset(unit, uban)
	int unit, uban;
{
	register struct uba_device *ui;
D 19
COUNT(ECRESET);
E 19

	if (unit >= NEC || (ui = ecinfo[unit]) == 0 || ui->ui_alive == 0 ||
	    ui->ui_ubanum != uban)
		return;
	printf(" ec%d", unit);
I 22
D 25
	ubamem(uban, ECMEM, 32*2, 0);	/* map register disable (no alloc) */
E 25
I 25
D 43
	(void) ubamem(uban, ECMEM, 32*2, 0);	/* mr disable (no alloc) */
E 43
I 43
D 45
	(void) ubamem(uban, ecmem[unit], 32*2, 0);	/* mr disable (no alloc) */
E 45
E 43
I 41
	ec_softc[unit].es_if.if_flags &= ~IFF_RUNNING;
E 41
E 25
E 22
	ecinit(unit);
}

/*
 * Initialization of interface; clear recorded pending
 * operations, and reinitialize UNIBUS usage.
 */
ecinit(unit)
	int unit;
{
D 17
	register struct ec_softc *es = &ec_softc[unit];
	register struct uba_device *ui = ecinfo[unit];
	register struct ecdevice *addr;
	register i;
	int s;
E 17
I 17
	struct ec_softc *es = &ec_softc[unit];
	struct ecdevice *addr;
D 36
	int i, s;
E 36
I 34
	register struct ifnet *ifp = &es->es_if;
D 38
	register struct sockaddr_in *sin, *sinb;
E 38
I 38
D 46
	register struct sockaddr_in *sin;
E 46
E 38
I 36
	int i, s;
E 36
E 34
E 17

I 34
D 46
	sin = (struct sockaddr_in *)&ifp->if_addr;
D 36
	if (sin->sin_addr.s_addr == 0)	/* if address still unknown */
E 36
I 36
	if (sin->sin_addr.s_addr == 0)		/* address still unknown */
E 46
I 46
	/* not yet, if address still unknown */
	if (ifp->if_addrlist == (struct ifaddr *)0)
E 46
E 36
		return;
D 36
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sinb = (struct sockaddr_in *)&ifp->if_broadaddr;
	sinb->sin_family = AF_INET;
	sinb->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags = IFF_BROADCAST;
E 36

E 34
D 8
#ifdef notdef
	if (if_ubainit(&es->es_ifuba, ui->ui_ubanum,
	    sizeof (struct ec_header), (int)btoc(ECMTU)) == 0) { 
		printf("ec%d: can't initialize\n", unit);
		es->es_if.if_flags &= ~IFF_UP;
		return;
	}
#endif
E 8
D 17
	addr = (struct ecdevice *)ui->ui_addr;

E 17
	/*
D 18
	 * Hang receive buffers and start any pending
	 * writes by faking a transmit complete.
E 18
I 18
	 * Hang receive buffers and start any pending writes.
E 18
I 6
	 * Writing into the rcr also makes sure the memory
	 * is turned on.
E 6
	 */
I 17
D 36
	addr = (struct ecdevice *)ecinfo[unit]->ui_addr;
E 17
	s = splimp();
	for (i=ECRHBF; i>=ECRLBF; i--)
		addr->ec_rcr = EC_READ|i;
D 18
	es->es_oactive = 1;
E 18
I 18
	es->es_oactive = 0;
	es->es_mask = ~0;
E 18
	es->es_if.if_flags |= IFF_UP;
D 18
	ecxint(unit);
E 18
I 18
	if (es->es_if.if_snd.ifq_head)
		ecstart(unit);
E 18
	splx(s);
E 36
I 36
D 46
	if ((es->es_if.if_flags & IFF_RUNNING) == 0) {
E 46
I 46
	if ((ifp->if_flags & IFF_RUNNING) == 0) {
E 46
		addr = (struct ecdevice *)ecinfo[unit]->ui_addr;
		s = splimp();
I 50
		/*
		 * write our ethernet address into the address recognition ROM 
		 * so we can always use the same EC_READ bits (referencing ROM),
		 * in case we change the address sometime.
D 53
		 * Note that this is safe here as the reciever is NOT armed.
E 53
I 53
		 * Note that this is safe here as the receiver is NOT armed.
E 53
		 */
		ec_setaddr(es->es_addr, unit);
		/*
D 53
		 * Arm the reciever
E 53
I 53
		 * Arm the receiver
E 53
		 */
E 50
		for (i = ECRHBF; i >= ECRLBF; i--)
			addr->ec_rcr = EC_READ | i;
		es->es_oactive = 0;
		es->es_mask = ~0;
D 46
		es->es_if.if_flags |= IFF_UP|IFF_RUNNING;
E 46
I 46
		es->es_if.if_flags |= IFF_RUNNING;
E 46
		if (es->es_if.if_snd.ifq_head)
			ecstart(unit);
		splx(s);
	}
E 36
D 15
	if_rtinit(&es->es_if, RTF_DIRECT|RTF_UP);
E 15
I 15
D 46
	if_rtinit(&es->es_if, RTF_UP);
I 34
D 42
	arpattach(&es->es_ac);
E 42
	arpwhohas(&es->es_ac, &sin->sin_addr);
E 46
E 34
E 15
}

D 8
#ifdef notdef
int	enalldelay = 0;
int	eclastdel = 25;
int	enlastmask = (~0) << 5;
#endif

E 8
/*
D 53
 * Start or restart output on interface.
 * If interface is already active, then this is a retransmit
D 5
 * after a collision, and just restuff registers and delay.
E 5
I 5
 * after a collision, and just restuff registers.
E 5
 * If interface is not already active, get another datagram
 * to send off of the interface queue, and map it to the interface
E 53
I 53
 * Start output on interface.  Get another datagram to send
 * off of the interface queue, and copy it to the interface
E 53
 * before starting the output.
 */
D 45
ecstart(dev)
	dev_t dev;
E 45
I 45
ecstart(unit)
E 45
{
D 17
        int unit = ECUNIT(dev);
	struct uba_device *ui = ecinfo[unit];
	register struct ec_softc *es = &ec_softc[unit];
	register struct ecdevice *addr;
E 17
I 17
D 25
        int unit = ECUNIT(dev), dest;
E 25
I 25
D 45
        int unit = ECUNIT(dev);
E 45
E 25
D 53
	struct ec_softc *es = &ec_softc[unit];
E 53
I 53
	register struct ec_softc *es = &ec_softc[unit];
E 53
	struct ecdevice *addr;
E 17
	struct mbuf *m;
D 25
	caddr_t ecbuf;
E 25
D 17
	int dest;
E 17
D 19
COUNT(ECSTART);
E 19

D 53
	if (es->es_oactive)
		goto restart;

E 53
I 53
	if ((es->es_if.if_flags & IFF_RUNNING) == 0)
		return;
E 53
D 17
	/*
	 * Not already active: dequeue another request
	 * and copy it into the buffer.  If no more requests,
	 * just return.
	 */
E 17
	IF_DEQUEUE(&es->es_if.if_snd, m);
D 53
	if (m == 0) {
		es->es_oactive = 0;
E 53
I 53
	if (m == 0)
E 53
		return;
D 53
	}
E 53
D 9
#ifdef notdef
	dest = mtod(m, struct ec_header *)->ec_dhost; /* wrong! */
#endif
E 9
	ecput(es->es_buf[ECTBF], m);
D 53

D 8
#ifdef notdef
	/*
	 * Ethernet cannot take back-to-back packets (no
	 * buffering in interface).  To avoid overrunning
	 * receivers, enforce a small delay (about 1ms) in interface:
	 *	* between all packets when ecalldelay
	 *	* whenever last packet was broadcast
	 *	* whenever this packet is to same host as last packet
	 */
	if (enalldelay || es->es_lastx == 0 || es->es_lastx == dest) {
		es->es_delay = eclastdel;
		es->es_mask = eclastmask;
	}
	es->es_lastx = dest;
#endif

E 8
restart:
E 53
D 17
	/*
	 * Start the output.
	 */
	addr = (struct ecdevice *)ui->ui_addr;
E 17
I 17
	addr = (struct ecdevice *)ecinfo[unit]->ui_addr;
E 17
	addr->ec_xcr = EC_WRITE|ECTBF;
	es->es_oactive = 1;
}

/*
 * Ethernet interface transmitter interrupt.
 * Start another output if more data to send.
 */
ecxint(unit)
	int unit;
{
D 17
	register struct uba_device *ui = ecinfo[unit];
E 17
	register struct ec_softc *es = &ec_softc[unit];
D 17
	register struct ecdevice *addr = (struct ecdevice *)ui->ui_addr;
E 17
I 17
	register struct ecdevice *addr =
		(struct ecdevice *)ecinfo[unit]->ui_addr;
E 17
D 19
COUNT(ECXINT);
E 19

	if (es->es_oactive == 0)
		return;
D 17
	if (addr->ec_xcr&EC_XDONE == 0 || addr->ec_xcr&EC_XBN != ECTBF)
		printf("ec%d: strange xmit interrupt!\n", unit);
E 17
I 17
	if ((addr->ec_xcr&EC_XDONE) == 0 || (addr->ec_xcr&EC_XBN) != ECTBF) {
		printf("ec%d: stray xmit interrupt, xcr=%b\n", unit,
			addr->ec_xcr, EC_XBITS);
		es->es_oactive = 0;
		addr->ec_xcr = EC_XCLR;
		return;
	}
E 17
	es->es_if.if_opackets++;
	es->es_oactive = 0;
D 5
	es->es_delay = 0;
E 5
	es->es_mask = ~0;
	addr->ec_xcr = EC_XCLR;
D 20
	/*
	 * There shouldn't ever be any mbuf's to free, but just in case...
	 */
	if (es->es_ifuba.ifu_xtofree) {
		m_freem(es->es_ifuba.ifu_xtofree);
		es->es_ifuba.ifu_xtofree = 0;
	}
E 20
D 8
	if (es->es_if.if_snd.ifq_head == 0) {
#ifdef notdef
		es->es_lastx = 0; /* ? */
#endif
E 8
I 8
D 9
	if (es->es_if.if_snd.ifq_head == 0)
E 9
I 9
D 17
	if (es->es_if.if_snd.ifq_head == 0) {
E 9
E 8
		return;
I 9
	}
E 9
D 8
	}
E 8
	ecstart(unit);
E 17
I 17
	if (es->es_if.if_snd.ifq_head)
		ecstart(unit);
E 17
}

/*
 * Collision on ethernet interface.  Do exponential
 * backoff, and retransmit.  If have backed off all
 * the way print warning diagnostic, and drop packet.
 */
eccollide(unit)
	int unit;
{
D 53
	struct ec_softc *es = &ec_softc[unit];
D 19
COUNT(ECCOLLIDE);
E 19

D 5
	printf("ec%d: eccollide\n", unit);
E 5
I 5
D 20
	printf("ec%d: collision\n", unit);
E 20
E 5
	es->es_if.if_collisions++;
D 17
	if (es->es_oactive == 0)
		return;
	ecdocoll(unit);
E 17
I 17
	if (es->es_oactive)
		ecdocoll(unit);
E 17
}

ecdocoll(unit)
	int unit;
{
E 53
	register struct ec_softc *es = &ec_softc[unit];
I 5
	register struct ecdevice *addr =
	    (struct ecdevice *)ecinfo[unit]->ui_addr;
	register i;
	int delay;
E 5

I 53
	es->es_if.if_collisions++;
	if (es->es_oactive == 0)
		return;

E 53
	/*
	 * Es_mask is a 16 bit number with n low zero bits, with
	 * n the number of backoffs.  When es_mask is 0 we have
	 * backed off 16 times, and give up.
	 */
	if (es->es_mask == 0) {
I 5
		es->es_if.if_oerrors++;
E 5
D 53
		printf("ec%d: send error\n", unit);
E 53
I 53
		log(LOG_ERR, "ec%d: send error\n", unit);
E 53
		/*
D 5
		 * this makes enxint wrong.  fix later.
E 5
I 5
		 * Reset interface, then requeue rcv buffers.
		 * Some incoming packets may be lost, but that
		 * can't be helped.
E 5
		 */
D 5
		ecxint(unit);
E 5
I 5
		addr->ec_xcr = EC_UECLR;
		for (i=ECRHBF; i>=ECRLBF; i--)
			addr->ec_rcr = EC_READ|i;
		/*
		 * Reset and transmit next packet (if any).
		 */
		es->es_oactive = 0;
		es->es_mask = ~0;
		if (es->es_if.if_snd.ifq_head)
			ecstart(unit);
E 5
		return;
	}
	/*
D 5
	 * Another backoff.  Restart with delay based on n low bits
	 * of the interval timer.
E 5
I 5
	 * Do exponential backoff.  Compute delay based on low bits
D 53
	 * of the interval timer.  Then delay for that number of
E 53
I 53
	 * of the interval timer (1 bit for each transmission attempt,
	 * but at most 5 bits).  Then delay for that number of
E 53
	 * slot times.  A slot time is 51.2 microseconds (rounded to 51).
	 * This does not take into account the time already used to
	 * process the interrupt.
E 5
	 */
	es->es_mask <<= 1;
D 5
	es->es_delay = mfpr(ICR) &~ es->es_mask;
E 5
I 5
D 53
	delay = mfpr(ICR) &~ es->es_mask;
E 53
I 53
	delay = mfpr(ICR) & 0x1f &~ es->es_mask;
E 53
	DELAY(delay * 51);
E 5
	/*
D 5
	 * This should do some sort of delay before calling ecstart.
	 * I'll figure this out later.
E 5
I 5
	 * Clear the controller's collision flag, thus enabling retransmit.
E 5
	 */
D 5
	ecstart(unit);
E 5
I 5
D 7
	addr->ec_xcr = EC_JCLR;
E 7
I 7
D 22
	addr->ec_xcr = EC_JINTEN|EC_XINTEN|EC_JCLR;
E 22
I 22
	addr->ec_xcr = EC_CLEAR;
E 22
E 7
E 5
}

D 8
#ifdef notdef
struct	sockaddr_pup pupsrc = { AF_PUP };
struct	sockaddr_pup pupdst = { AF_PUP };
struct	sockproto pupproto = { PF_PUP };
#endif
E 8
/*
 * Ethernet interface receiver interrupt.
 * If input error just drop packet.
D 50
 * Otherwise purge input buffered data path and examine 
E 50
I 50
 * Otherwise examine 
E 50
 * packet to determine type.  If can't determine length
 * from type, then have to drop packet.  Othewise decapsulate
 * packet based on type and pass to type specific higher-level
 * input routine.
 */
ecrint(unit)
	int unit;
{
	struct ecdevice *addr = (struct ecdevice *)ecinfo[unit]->ui_addr;
D 19
COUNT(ECRINT);
E 19

D 9
#ifdef notdef
	printf("ec%d: ecrint:%d\n", unit, addr->ec_rcr & 0xf);
#endif
E 9
	while (addr->ec_rcr & EC_RDONE)
		ecread(unit);
}

ecread(unit)
	int unit;
{
	register struct ec_softc *es = &ec_softc[unit];
	struct ecdevice *addr = (struct ecdevice *)ecinfo[unit]->ui_addr;
D 32
	register struct ec_header *ec;
E 32
I 32
	register struct ether_header *ec;
E 32
    	struct mbuf *m;
D 17
	int len, off, resid;
E 17
I 17
D 25
	int len, off, resid, ecoff, buf;
E 25
I 25
	int len, off, resid, ecoff, rbuf;
E 25
E 17
	register struct ifqueue *inq;
D 25
	caddr_t ecbuf;
E 25
I 25
	u_char *ecbuf;
E 25
D 17
	int ecoff;
	int buf;
E 17
D 19
COUNT(ECREAD);
E 19

	es->es_if.if_ipackets++;
D 25
	buf = addr->ec_rcr & EC_RBN;
	if (buf < ECRLBF || buf > ECRHBF)
E 25
I 25
	rbuf = addr->ec_rcr & EC_RBN;
	if (rbuf < ECRLBF || rbuf > ECRHBF)
E 25
		panic("ecrint");
D 25
	ecbuf = es->es_buf[buf];
E 25
I 25
	ecbuf = es->es_buf[rbuf];
E 25
	ecoff = *(short *)ecbuf;
D 4
	if (ecoff < ECRDOFF || ecoff >= ECMTU+ECRDOFF) {
E 4
I 4
D 5
	if (ecoff <= ECRDOFF || ecoff > ECMTU+ECRDOFF) {
E 5
I 5
	if (ecoff <= ECRDOFF || ecoff > 2046) {
E 5
E 4
		es->es_if.if_ierrors++;
#ifdef notdef
		if (es->es_if.if_ierrors % 100 == 0)
			printf("ec%d: += 100 input errors\n", unit);
#endif
D 20
		printf("ec%d: input error (offset=%d)\n", unit, ecoff);
E 20
		goto setup;
	}

	/*
	 * Get input data length.
	 * Get pointer to ethernet header (in input buffer).
D 46
	 * Deal with trailer protocol: if type is PUP trailer
E 46
I 46
	 * Deal with trailer protocol: if type is trailer type
E 46
	 * get true type from first 16-bit word past data.
	 * Remember that type was trailer by setting off.
	 */
D 32
	len = ecoff - ECRDOFF - sizeof (struct ec_header);
	ec = (struct ec_header *)(ecbuf + ECRDOFF);
E 32
I 32
	len = ecoff - ECRDOFF - sizeof (struct ether_header);
	ec = (struct ether_header *)(ecbuf + ECRDOFF);
	ec->ether_type = ntohs((u_short)ec->ether_type);
E 32
#define	ecdataaddr(ec, off, type)	((type)(((caddr_t)((ec)+1)+(off))))
D 32
	if (ec->ec_type >= ECPUP_TRAIL &&
	    ec->ec_type < ECPUP_TRAIL+ECPUP_NTRAILER) {
		off = (ec->ec_type - ECPUP_TRAIL) * 512;
		if (off >= ECMTU)
E 32
I 32
D 46
	if (ec->ether_type >= ETHERPUP_TRAIL &&
	    ec->ether_type < ETHERPUP_TRAIL+ETHERPUP_NTRAILER) {
		off = (ec->ether_type - ETHERPUP_TRAIL) * 512;
E 46
I 46
	if (ec->ether_type >= ETHERTYPE_TRAIL &&
	    ec->ether_type < ETHERTYPE_TRAIL+ETHERTYPE_NTRAILER) {
		off = (ec->ether_type - ETHERTYPE_TRAIL) * 512;
E 46
		if (off >= ETHERMTU)
E 32
			goto setup;		/* sanity */
D 32
		ec->ec_type = *ecdataaddr(ec, off, u_short *);
		resid = *(ecdataaddr(ec, off+2, u_short *));
E 32
I 32
		ec->ether_type = ntohs(*ecdataaddr(ec, off, u_short *));
		resid = ntohs(*(ecdataaddr(ec, off+2, u_short *)));
E 32
		if (off + resid > len)
			goto setup;		/* sanity */
		len = off + resid;
	} else
		off = 0;
	if (len == 0)
		goto setup;

	/*
	 * Pull packet off interface.  Off is nonzero if packet
	 * has trailing header; ecget will then force this header
	 * information to be at the front, but we still have to drop
	 * the type and length which are at the front of any trailer data.
	 */
D 51
	m = ecget(ecbuf, len, off);
E 51
I 51
	m = ecget(ecbuf, len, off, &es->es_if);
E 51
	if (m == 0)
		goto setup;
	if (off) {
I 51
		struct ifnet *ifp;

		ifp = *(mtod(m, struct ifnet **));
E 51
		m->m_off += 2 * sizeof (u_short);
		m->m_len -= 2 * sizeof (u_short);
I 51
		*(mtod(m, struct ifnet **)) = ifp;
E 51
	}
D 32
	switch (ec->ec_type) {
E 32
I 32
	switch (ec->ether_type) {
E 32

#ifdef INET
D 32
	case ECPUP_IPTYPE:
E 32
I 32
D 46
	case ETHERPUP_IPTYPE:
E 46
I 46
	case ETHERTYPE_IP:
E 46
E 32
		schednetisr(NETISR_IP);
		inq = &ipintrq;
		break;
I 34

D 46
	case ETHERPUP_ARPTYPE:
E 46
I 46
	case ETHERTYPE_ARP:
E 46
		arpinput(&es->es_ac, m);
D 39
		return;
E 39
I 39
		goto setup;
E 39
E 34
#endif
I 48
#ifdef NS
	case ETHERTYPE_NS:
		schednetisr(NETISR_NS);
		inq = &nsintrq;
		break;

#endif
E 48
D 8
#ifdef notdef
#ifdef PUP
	case ECPUP_PUPTYPE: {
		struct pup_header *pup = mtod(m, struct pup_header *);

		pupproto.sp_protocol = pup->pup_type;
		pupdst.spup_addr = pup->pup_dport;
		pupsrc.spup_addr = pup->pup_sport;
D 3
		raw_input(m, &pupproto, (struct sockaddr *)&pupdst,
		  (struct sockaddr *)&pupsrc);
E 3
I 3
		raw_input(m, &pupproto, (struct sockaddr *)&pupsrc,
		  (struct sockaddr *)&pupdst);
E 3
		goto setup;
	}
#endif
#endif
E 8
	default:
		m_freem(m);
		goto setup;
	}

	if (IF_QFULL(inq)) {
		IF_DROP(inq);
		m_freem(m);
D 17
	} else
		IF_ENQUEUE(inq, m);
E 17
I 17
		goto setup;
	}
	IF_ENQUEUE(inq, m);
E 17

setup:
	/*
	 * Reset for next packet.
	 */
D 25
	addr->ec_rcr = EC_READ|EC_RCLR|buf;
E 25
I 25
	addr->ec_rcr = EC_READ|EC_RCLR|rbuf;
E 25
}

/*
 * Ethernet output routine.
 * Encapsulate a packet of type family for the local net.
 * Use trailer local net encapsulation if enough data in first
 * packet leaves a multiple of 512 bytes of data in remainder.
I 5
 * If destination is this address or broadcast, send packet to
 * loop device to kludge around the fact that 3com interfaces can't
 * talk to themselves.
E 5
 */
ecoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
D 34
	int type, dest, s, error;
E 34
I 34
	int type, s, error;
D 42
	u_char edst[6];
E 42
I 42
D 46
	struct ether_addr edst;
E 46
I 46
 	u_char edst[6];
E 46
E 42
	struct in_addr idst;
E 34
	register struct ec_softc *es = &ec_softc[ifp->if_unit];
	register struct mbuf *m = m0;
D 32
	register struct ec_header *ec;
E 32
I 32
	register struct ether_header *ec;
E 32
D 17
	register int off;
	register int i;
E 17
I 17
D 35
	register int off, i;
E 35
I 35
	register int off;
E 35
E 17
I 5
D 34
	struct mbuf *mcopy = (struct mbuf *) 0;		/* Null */
E 34
I 34
	struct mbuf *mcopy = (struct mbuf *)0;
I 55
	int usetrailers;
E 55
E 34
E 5

I 53
	if ((ifp->if_flags & (IFF_UP|IFF_RUNNING)) != (IFF_UP|IFF_RUNNING)) {
		error = ENETDOWN;
		goto bad;
	}
E 53
D 19
COUNT(ECOUTPUT);
E 19
	switch (dst->sa_family) {

#ifdef INET
	case AF_INET:
D 34
		dest = ((struct sockaddr_in *)dst)->sin_addr.s_addr;
I 5
		if ((dest &~ 0xff) == 0)
E 34
I 34
		idst = ((struct sockaddr_in *)dst)->sin_addr;
D 42
		if (!arpresolve(&es->es_ac, m, &idst, edst))
E 42
I 42
D 46
		if (!arpresolve(&es->es_ac, m, &idst, &edst))
E 46
I 46
D 55
		if (!arpresolve(&es->es_ac, m, &idst, edst))
E 55
I 55
		if (!arpresolve(&es->es_ac, m, &idst, edst, &usetrailers))
E 55
E 46
E 42
			return (0);	/* if not yet resolved */
D 46
		if (in_lnaof(idst) == INADDR_ANY)
E 46
I 46
		if (!bcmp((caddr_t)edst, (caddr_t)etherbroadcastaddr,
		    sizeof(edst)))
E 46
E 34
D 25
			mcopy = m_copy(m, 0, M_COPYALL);
E 25
I 25
D 26
			mcopy = m_copy(m, 0, (long)M_COPYALL);
E 26
I 26
D 27
			mcopy = m_copy(m, 0, M_COPYALL);
E 27
I 27
			mcopy = m_copy(m, 0, (int)M_COPYALL);
E 27
E 26
E 25
D 34
		else if (dest == ((struct sockaddr_in *)&es->es_if.if_addr)->
		    sin_addr.s_addr) {
			mcopy = m;
			goto gotlocal;
		}
E 34
E 5
		off = ntohs((u_short)mtod(m, struct ip *)->ip_len) - m->m_len;
I 36
		/* need per host negotiation */
D 55
		if ((ifp->if_flags & IFF_NOTRAILERS) == 0)
E 36
		if (off > 0 && (off & 0x1ff) == 0 &&
E 55
I 55
		if (usetrailers && off > 0 && (off & 0x1ff) == 0 &&
E 55
		    m->m_off >= MMINOFF + 2 * sizeof (u_short)) {
D 32
			type = ECPUP_TRAIL + (off>>9);
E 32
I 32
D 46
			type = ETHERPUP_TRAIL + (off>>9);
E 46
I 46
			type = ETHERTYPE_TRAIL + (off>>9);
E 46
E 32
			m->m_off -= 2 * sizeof (u_short);
			m->m_len += 2 * sizeof (u_short);
D 32
			*mtod(m, u_short *) = ECPUP_IPTYPE;
			*(mtod(m, u_short *) + 1) = m->m_len;
E 32
I 32
D 46
			*mtod(m, u_short *) = ntohs((u_short)ETHERPUP_IPTYPE);
E 46
I 46
			*mtod(m, u_short *) = ntohs((u_short)ETHERTYPE_IP);
E 46
			*(mtod(m, u_short *) + 1) = ntohs((u_short)m->m_len);
E 32
			goto gottrailertype;
		}
D 32
		type = ECPUP_IPTYPE;
E 32
I 32
D 46
		type = ETHERPUP_IPTYPE;
E 46
I 46
		type = ETHERTYPE_IP;
E 46
E 32
		off = 0;
		goto gottype;
D 8
#endif
#ifdef notdef
#ifdef PUP
	case AF_PUP:
		dest = ((struct sockaddr_pup *)dst)->spup_addr.pp_host;
		type = ECPUP_PUPTYPE;
		off = 0;
		goto gottype;
#endif
E 8
#endif
I 48
#ifdef NS
	case AF_NS:
 		bcopy((caddr_t)&(((struct sockaddr_ns *)dst)->sns_addr.x_host),
		    (caddr_t)edst, sizeof (edst));
E 48

I 48
		if (!bcmp((caddr_t)edst, (caddr_t)&ns_broadhost,
			sizeof(edst))) {

				mcopy = m_copy(m, 0, (int)M_COPYALL);
		} else if (!bcmp((caddr_t)edst, (caddr_t)&ns_thishost,
			sizeof(edst))) {

				return(looutput(&loif, m, dst));
		}
		type = ETHERTYPE_NS;
		off = 0;
		goto gottype;
#endif

E 48
I 34
	case AF_UNSPEC:
		ec = (struct ether_header *)dst->sa_data;
D 35
		bcopy(ec->ether_dhost, edst, sizeof edst);
E 35
I 35
D 42
		bcopy((caddr_t)ec->ether_dhost, (caddr_t)edst, sizeof (edst));
E 42
I 42
D 46
		edst = ec->ether_dhost;
E 46
I 46
 		bcopy((caddr_t)ec->ether_dhost, (caddr_t)edst, sizeof (edst));
E 46
E 42
E 35
		type = ec->ether_type;
		goto gottype;

E 34
	default:
		printf("ec%d: can't handle af%d\n", ifp->if_unit,
			dst->sa_family);
		error = EAFNOSUPPORT;
		goto bad;
	}

gottrailertype:
	/*
	 * Packet to be sent as trailer: move first packet
	 * (control information) to end of chain.
	 */
	while (m->m_next)
		m = m->m_next;
	m->m_next = m0;
	m = m0->m_next;
	m0->m_next = 0;
	m0 = m;

gottype:
	/*
	 * Add local net header.  If no space in first mbuf,
	 * allocate another.
	 */
	if (m->m_off > MMAXOFF ||
D 32
	    MMINOFF + sizeof (struct ec_header) > m->m_off) {
E 32
I 32
	    MMINOFF + sizeof (struct ether_header) > m->m_off) {
E 32
D 31
		m = m_get(M_DONTWAIT);
E 31
I 31
		m = m_get(M_DONTWAIT, MT_HEADER);
E 31
		if (m == 0) {
			error = ENOBUFS;
			goto bad;
		}
		m->m_next = m0;
		m->m_off = MMINOFF;
D 32
		m->m_len = sizeof (struct ec_header);
E 32
I 32
		m->m_len = sizeof (struct ether_header);
E 32
	} else {
D 32
		m->m_off -= sizeof (struct ec_header);
		m->m_len += sizeof (struct ec_header);
E 32
I 32
		m->m_off -= sizeof (struct ether_header);
		m->m_len += sizeof (struct ether_header);
E 32
	}
D 32
	ec = mtod(m, struct ec_header *);
	for (i=0; i<6; i++)
		ec->ec_shost[i] = es->es_enaddr[i];
E 32
I 32
	ec = mtod(m, struct ether_header *);
D 34
	bcopy((caddr_t)es->es_enaddr, (caddr_t)ec->ether_shost, 6);
E 32
D 2
	if (dest & 0xffffff00 == 0)
E 2
I 2
	if ((dest &~ 0xff) == 0)
I 17
D 32
		/* broadcast address */
E 17
E 2
		for (i=0; i<6; i++)
			ec->ec_dhost[i] = 0xff;
E 32
I 32
		bcopy((caddr_t)ecbroadcastaddr, (caddr_t)ec->ether_dhost, 6);
E 32
	else {
D 9
		ec->ec_dhost[0] = es->es_enaddr[0];
		ec->ec_dhost[1] = es->es_enaddr[1];
		ec->ec_dhost[2] = es->es_enaddr[2];
		ec->ec_dhost[3] = (dest>>8) & 0xff;
E 9
I 9
D 32
		if (dest & 0x8000) {
			ec->ec_dhost[0] = ec_iltop[0];
			ec->ec_dhost[1] = ec_iltop[1];
			ec->ec_dhost[2] = ec_iltop[2];
		} else {
			ec->ec_dhost[0] = es->es_enaddr[0];
			ec->ec_dhost[1] = es->es_enaddr[1];
			ec->ec_dhost[2] = es->es_enaddr[2];
		}
		ec->ec_dhost[3] = (dest>>8) & 0x7f;
E 9
		ec->ec_dhost[4] = (dest>>16) & 0xff;
		ec->ec_dhost[5] = (dest>>24) & 0xff;
E 32
I 32
		u_char *to = dest & 0x8000 ? ec_iltop : es->es_enaddr;

		bcopy((caddr_t)to, (caddr_t)ec->ether_dhost, 3);
		ec->ether_dhost[3] = (dest>>8) & 0x7f;
		ec->ether_dhost[4] = (dest>>16) & 0xff;
		ec->ether_dhost[5] = (dest>>24) & 0xff;
E 32
	}
E 34
I 34
D 35
	bcopy(edst, ec->ether_dhost, sizeof (edst));
E 35
I 35
D 42
	bcopy((caddr_t)edst, (caddr_t)ec->ether_dhost, sizeof (edst));
E 42
I 42
D 46
	ec->ether_dhost = edst;
	ec->ether_shost = es->es_addr;
E 46
I 46
 	bcopy((caddr_t)edst, (caddr_t)ec->ether_dhost, sizeof (edst));
	bcopy((caddr_t)es->es_addr, (caddr_t)ec->ether_shost,
	    sizeof(ec->ether_shost));
E 46
E 42
E 35
E 34
D 32
	ec->ec_type = type;
E 32
I 32
	ec->ether_type = htons((u_short)type);
I 34
D 42
	bcopy((caddr_t)es->es_addr, (caddr_t)ec->ether_shost, 6);
E 42
E 34
E 32

	/*
	 * Queue message on interface, and start output if interface
	 * not yet active.
	 */
	s = splimp();
	if (IF_QFULL(&ifp->if_snd)) {
		IF_DROP(&ifp->if_snd);
		error = ENOBUFS;
		goto qfull;
	}
	IF_ENQUEUE(&ifp->if_snd, m);
	if (es->es_oactive == 0)
		ecstart(ifp->if_unit);
	splx(s);
I 35
	return (mcopy ? looutput(&loif, mcopy, dst) : 0);
E 35
I 17

E 17
D 5
	return (0);
E 5
I 5
D 35
gotlocal:
D 17
	if (mcopy)				/* Kludge, but it works! */
		return(looutput(&loif, mcopy, dst));
	else
		return (0);
E 17
I 17
	return(mcopy ? looutput(&loif, mcopy, dst) : 0);

E 35
E 17
E 5
qfull:
	m0 = m;
	splx(s);
bad:
	m_freem(m0);
I 41
	if (mcopy)
		m_freem(mcopy);
E 41
D 35
	return(error);
E 35
I 35
	return (error);
E 35
}

/*
D 17
 * Routine to copy from mbufs to UNIBUS memory.
 * Similar in spirit to if_wubaput.
E 17
I 17
D 30
 * Routine to copy from mbuf chain to transmitter
E 30
I 30
 * Routine to copy from mbuf chain to transmit
E 30
 * buffer in UNIBUS memory.
I 30
 * If packet size is less than the minimum legal size,
 * the buffer is expanded.  We probably should zero out the extra
 * bytes for security, but that would slow things down.
E 30
E 17
 */
ecput(ecbuf, m)
D 17
	char *ecbuf;
E 17
I 17
	u_char *ecbuf;
E 17
	struct mbuf *m;
{
D 17
	register int len;
E 17
	register struct mbuf *mp;
D 17
	register char *bp, *mcp;
	register int i;
E 17
I 17
D 20
	register u_char *bp;
E 20
	register int off;
I 20
	u_char *bp;
E 20
E 17

D 19
COUNT(ECPUT);
E 19
D 17
	len = 0;
	for (mp=m; mp; mp=mp->m_next)
		len += mp->m_len;
	*(u_short *)ecbuf = 2048 - len;
	bp = ecbuf + 2048 - len;
	mp = m;
	while (mp) {
		mcp = mtod(mp, char *);
I 13
		i = 0;
		if ((int)bp&1) {
E 17
I 17
	for (off = 2048, mp = m; mp; mp = mp->m_next)
		off -= mp->m_len;
I 30
D 32
	if (2048 - off < ECMIN + sizeof (struct ec_header))
		off = 2048 - ECMIN - sizeof (struct ec_header);
E 32
I 32
	if (2048 - off < ETHERMIN + sizeof (struct ether_header))
		off = 2048 - ETHERMIN - sizeof (struct ether_header);
E 32
E 30
	*(u_short *)ecbuf = off;
	bp = (u_char *)(ecbuf + off);
D 20
	for (mp = m; mp; mp = m_free(mp)) {
		register unsigned len;
		register u_char *mcp;
E 20
I 20
	for (mp = m; mp; mp = mp->m_next) {
		register unsigned len = mp->m_len;
		u_char *mcp;
E 20

D 20
		len = mp->m_len;
E 20
		if (len == 0)
			continue;
		mcp = mtod(mp, u_char *);
		if ((unsigned)bp & 01) {
E 17
			*bp++ = *mcp++;
D 17
			i++;
E 17
I 17
			len--;
E 17
		}
E 13
D 15
		for (i=0; i<mp->m_len; i++)
E 15
I 13
D 17
		while (i < mp->m_len) {
			*(short *)bp = *(short *)mcp;
			bp += 2;
			mcp += 2;
			i += 2;
E 17
I 17
D 20
		for (; len > 1; len -= sizeof (u_short)) {
			*(u_short *)bp = *(u_short *)mcp;
			bp += sizeof (u_short);
			mcp += sizeof (u_short);
E 20
I 20
		if (off = (len >> 1)) {
			register u_short *to, *from;

			to = (u_short *)bp;
			from = (u_short *)mcp;
			do
				*to++ = *from++;
			while (--off > 0);
			bp = (u_char *)to,
			mcp = (u_char *)from;
E 20
E 17
		}
D 17
		if (mp->m_len&1)
E 17
I 17
D 20
		if (len)
E 20
I 20
		if (len & 01)
E 20
E 17
E 13
			*bp++ = *mcp++;
D 17
		mp = m_free(mp);
E 17
	}
D 17
	if (bp != ecbuf+2048)
		printf("ec: bad ecput!\n");
E 17
I 17
D 32
#ifdef notdef
	if (bp - ecbuf != 2048)
		printf("ec: bad ecput, diff=%d\n", bp-ecbuf);
#endif
E 32
I 20
	m_freem(m);
E 20
E 17
}

/*
 * Routine to copy from UNIBUS memory into mbufs.
 * Similar in spirit to if_rubaget.
I 13
 *
 * Warning: This makes the fairly safe assumption that
 * mbufs have even lengths.
E 13
 */
struct mbuf *
D 51
ecget(ecbuf, totlen, off0)
E 51
I 51
ecget(ecbuf, totlen, off0, ifp)
E 51
D 20
	char *ecbuf;
E 20
I 20
	u_char *ecbuf;
E 20
	int totlen, off0;
I 51
	struct ifnet *ifp;
E 51
{
D 20
	struct mbuf *top, **mp, *m;
D 17
	int off = off0;
	int len;
	register char *cp = ecbuf + ECRDOFF + sizeof (struct ec_header);
	register char *mcp;
E 17
I 17
	int off = off0, len;
	register char *cp, *mcp;
E 17
	register int i;
E 20
I 20
	register struct mbuf *m;
	struct mbuf *top = 0, **mp = &top;
	register int off = off0, len;
	u_char *cp;
E 20

D 19
COUNT(ECGET);
E 19
D 20
	top = 0;
	mp = &top;
E 20
I 17
D 32
	cp = ecbuf + ECRDOFF + sizeof (struct ec_header);
E 32
I 32
	cp = ecbuf + ECRDOFF + sizeof (struct ether_header);
E 32
E 17
	while (totlen > 0) {
I 20
		register int words;
		u_char *mcp;

E 20
D 31
		MGET(m, 0);
E 31
I 31
		MGET(m, M_DONTWAIT, MT_DATA);
E 31
		if (m == 0)
			goto bad;
		if (off) {
			len = totlen - off;
D 32
			cp = ecbuf + ECRDOFF + sizeof (struct ec_header) + off;
E 32
I 32
			cp = ecbuf + ECRDOFF +
				sizeof (struct ether_header) + off;
E 32
		} else
			len = totlen;
D 51
		if (len >= CLBYTES) {
E 51
I 51
		if (ifp)
			len += sizeof(ifp);
		if (len >= NBPG) {
E 51
D 56
			struct mbuf *p;

			MCLGET(p, 1);
			if (p != 0) {
E 56
I 56
			MCLGET(m);
			if (m->m_len == CLBYTES)
E 56
D 51
				m->m_len = len = CLBYTES;
E 51
I 51
				m->m_len = len = MIN(len, CLBYTES);
E 51
D 56
				m->m_off = (int)p - (int)m;
			} else {
E 56
I 56
			else
E 56
				m->m_len = len = MIN(MLEN, len);
D 56
				m->m_off = MMINOFF;
			}
E 56
		} else {
			m->m_len = len = MIN(MLEN, len);
			m->m_off = MMINOFF;
		}
D 20
		mcp = mtod(m, char *);
D 13
		for (i=0; i<len; i++)
E 13
I 13
D 17
		for (i=0; i<len; i+=2) {
E 17
I 17
		for (i = 0; i < len; i += sizeof (short)) {
E 17
			*(short *)mcp = *(short *)cp;
D 17
			mcp += 2;
			cp += 2;
E 17
I 17
			mcp += sizeof (short);
			cp += sizeof (short);
E 20
I 20
		mcp = mtod(m, u_char *);
I 51
		if (ifp) {
			/*
			 * Prepend interface pointer to first mbuf.
			 */
			*(mtod(m, struct ifnet **)) = ifp;
			mcp += sizeof(ifp);
			len -= sizeof(ifp);
			ifp = (struct ifnet *)0;
		}
E 51
		if (words = (len >> 1)) {
			register u_short *to, *from;

			to = (u_short *)mcp;
			from = (u_short *)cp;
			do
				*to++ = *from++;
			while (--words > 0);
			mcp = (u_char *)to;
			cp = (u_char *)from;
E 20
E 17
		}
D 17
		if (len&1)
E 17
I 17
		if (len & 01)
E 17
E 13
			*mcp++ = *cp++;
		*mp = m;
		mp = &m->m_next;
D 20
		if (off) {
			off += len;
			if (off == totlen) {
				cp = ecbuf + ECRDOFF +
				    sizeof (struct ec_header);
				off = 0;
				totlen = off0;
			}
		} else
E 20
I 20
		if (off == 0) {
E 20
			totlen -= len;
I 20
			continue;
		}
		off += len;
		if (off == totlen) {
D 32
			cp = ecbuf + ECRDOFF + sizeof (struct ec_header);
E 32
I 32
			cp = ecbuf + ECRDOFF + sizeof (struct ether_header);
E 32
			off = 0;
			totlen = off0;
		}
E 20
	}
	return (top);
bad:
	m_freem(top);
	return (0);
I 36
}

/*
 * Process an ioctl request.
 */
ecioctl(ifp, cmd, data)
	register struct ifnet *ifp;
	int cmd;
	caddr_t data;
{
D 46
	register struct ifreq *ifr = (struct ifreq *)data;
E 46
I 46
	register struct ifaddr *ifa = (struct ifaddr *)data;
I 53
	struct ec_softc *es = &ec_softc[ifp->if_unit];
	struct ecdevice *addr;
E 53
E 46
D 37
	register struct sockaddr_in *sin;
E 37
	int s = splimp(), error = 0;

I 53
	addr = (struct ecdevice *)(ecinfo[ifp->if_unit]->ui_addr);

E 53
	switch (cmd) {

	case SIOCSIFADDR:
D 46
		if (ifp->if_flags & IFF_RUNNING)
			if_rtinit(ifp, -1);	/* delete previous route */
D 37
		ifp->if_addr = ifr->ifr_addr;
		ifp->if_net = in_netof(ifr->ifr_addr);
		ifp->if_host[0] = in_lnaof(ifr->ifr_addr);
		sin = (struct sockaddr_in *)&ifp->if_broadaddr;
		sin->sin_family = AF_INET;
		sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
		ifp->if_flags |= IFF_BROADCAST;
E 37
I 37
		ecsetaddr(ifp, (struct sockaddr_in *)&ifr->ifr_addr);
E 46
I 46
		ifp->if_flags |= IFF_UP;
E 46
E 37
D 50
		ecinit(ifp->if_unit);
E 50
I 46

		switch (ifa->ifa_addr.sa_family) {
I 48
#ifdef INET
E 48
		case AF_INET:
I 50
D 53
			ecinit(ifp->if_unit); /* before, so we can send the ARP packet */
E 53
I 53
			ecinit(ifp->if_unit);	/* before arpwhohas */
E 53
E 50
			((struct arpcom *)ifp)->ac_ipaddr =
				IA_SIN(ifa)->sin_addr;
			arpwhohas((struct arpcom *)ifp, &IA_SIN(ifa)->sin_addr);
			break;
I 48
#endif
#ifdef NS
		case AF_NS:
		    {
			register struct ns_addr *ina = &(IA_SNS(ifa)->sns_addr);

D 53
			if (ns_nullhost(*ina)) {
				ina->x_host = * (union ns_host *) 
				     (ec_softc[ifp->if_unit].es_addr);
			} else {
E 53
I 53
			if (ns_nullhost(*ina))
				ina->x_host = *(union ns_host *)(es->es_addr);
			else {
E 53
D 50
				ec_setaddr(ina->x_host.c_host,ifp->if_unit);
E 50
I 50
				/* 
				 * The manual says we can't change the address 
D 53
				 * while the reciever is armed so reset everything
E 53
I 53
				 * while the receiver is armed,
				 * so reset everything
E 53
				 */
D 53
				struct ec_softc *es = &ec_softc[ifp->if_unit];
				struct uba_device *ui = ecinfo[ifp->if_unit];
				struct ecdevice *addr = (struct ecdevice *)ui->ui_addr;
				
				es->es_if.if_flags &= ~IFF_RUNNING; 
				bcopy(ina->x_host.c_host, es->es_addr, sizeof(es->es_addr));
E 53
I 53
				ifp->if_flags &= ~IFF_RUNNING; 
D 57
				bcopy(ina->x_host.c_host, es->es_addr,
					sizeof(es->es_addr));
E 57
I 57
				bcopy((caddr_t)ina->x_host.c_host,
				    (caddr_t)es->es_addr, sizeof(es->es_addr));
E 57
E 53
E 50
			}
I 50
			ecinit(ifp->if_unit); /* does ec_setaddr() */
E 50
			break;
		    }
#endif
I 53
		default:
			ecinit(ifp->if_unit);
			break;
E 53
E 48
		}
E 46
		break;

I 53
	case SIOCSIFFLAGS:
		if ((ifp->if_flags & IFF_UP) == 0 &&
		    ifp->if_flags & IFF_RUNNING) {
			addr->ec_xcr = EC_UECLR;
			ifp->if_flags &= ~IFF_RUNNING;
		} else if (ifp->if_flags & IFF_UP &&
		    (ifp->if_flags & IFF_RUNNING) == 0)
			ecinit(ifp->if_unit);
		break;

E 53
	default:
		error = EINVAL;
	}
	splx(s);
	return (error);
I 48
}

ec_setaddr(physaddr,unit)
D 53
u_char *physaddr;
int unit;
E 53
I 53
	u_char *physaddr;
	int unit;
E 53
{
	struct ec_softc *es = &ec_softc[unit];
	struct uba_device *ui = ecinfo[unit];
	register struct ecdevice *addr = (struct ecdevice *)ui->ui_addr;
	register char nibble;
	register int i, j;
I 50
D 51
	char *cp;
E 51
I 51

E 51
E 50
	/*
	 * Use the ethernet address supplied
D 50
	 * Routine Courtesy Bill Nesheim, Cornell University.
E 50
I 50
D 53
	 * NOte that we do a UECLR here, so the recieve buffers
E 53
I 53
	 * Note that we do a UECLR here, so the receive buffers
E 53
	 * must be requeued.
E 50
	 */
	
I 50
#ifdef DEBUG
D 55
	printf("ec_setaddr: setting address for unit %d = ",
		unit);
	ether_addr(physaddr); 
E 55
I 55
	printf("ec_setaddr: setting address for unit %d = %s",
		unit, ether_sprintf(physaddr));
E 55
#endif
	addr->ec_xcr = EC_UECLR;
E 50
	addr->ec_rcr = 0;
D 50
	/* load address of first controller */
E 50
I 50
	/* load requested address */
E 50
	for (i = 0; i < 6; i++) { /* 6 bytes of address */
	    es->es_addr[i] = physaddr[i];
	    nibble = physaddr[i] & 0xf; /* lower nibble */
	    addr->ec_rcr = (nibble << 8);
D 50
	    addr->ec_rcr = (nibble << 8) + EC_ASTEP; /* latch nibble */
E 50
I 50
	    addr->ec_rcr = (nibble << 8) + EC_AWCLK; /* latch nibble */
E 50
	    addr->ec_rcr = (nibble << 8);
	    for (j=0; j < 4; j++) {
		addr->ec_rcr = 0;
		addr->ec_rcr = EC_ASTEP; /* step counter */
		addr->ec_rcr = 0;
	    }
	    nibble = (physaddr[i] >> 4) & 0xf; /* upper nibble */
	    addr->ec_rcr = (nibble << 8);
D 50
	    addr->ec_rcr = (nibble << 8) + EC_ASTEP; /* latch nibble */
E 50
I 50
	    addr->ec_rcr = (nibble << 8) + EC_AWCLK; /* latch nibble */
E 50
	    addr->ec_rcr = (nibble << 8);
	    for (j=0; j < 4; j++) {
		addr->ec_rcr = 0;
		addr->ec_rcr = EC_ASTEP; /* step counter */
		addr->ec_rcr = 0;
	    }
	}
I 50
#ifdef DEBUG
	/*
	 * Read the ethernet address off the board, one nibble at a time.
	 */
	addr->ec_xcr = EC_UECLR;
	addr->ec_rcr = 0; /* read RAM */
	cp = es->es_addr;
#undef NEXTBIT
#define	NEXTBIT	addr->ec_rcr = EC_ASTEP; addr->ec_rcr = 0
	for (i=0; i < sizeof (es->es_addr); i++) {
		*cp = 0;
		for (j=0; j<=4; j+=4) {
			*cp |= ((addr->ec_rcr >> 8) & 0xf) << j;
			NEXTBIT; NEXTBIT; NEXTBIT; NEXTBIT;
		}
		cp++;
	}
D 55
	printf("ec_setaddr %d: ROM addr=",ui->ui_unit);
	ether_addr(es->es_addr);
E 55
I 55
	printf("ec_setaddr: RAM address for unit %d = %s",
		unit, ether_sprintf(physaddr));
E 55
#endif
E 50
E 48
I 37
D 46
}

ecsetaddr(ifp, sin)
	register struct ifnet *ifp;
	register struct sockaddr_in *sin;
{

	ifp->if_addr = *(struct sockaddr *)sin;
	ifp->if_net = in_netof(sin->sin_addr);
	ifp->if_host[0] = in_lnaof(sin->sin_addr);
	sin = (struct sockaddr_in *)&ifp->if_broadaddr;
	sin->sin_family = AF_INET;
	sin->sin_addr = if_makeaddr(ifp->if_net, INADDR_ANY);
	ifp->if_flags |= IFF_BROADCAST;
E 46
E 37
E 36
}
I 52
#endif
E 52
D 16

#if NIMP == 0 && NEC > 0
/*
 * Logical host interface driver.
 * Allows host to appear as an ARPAnet
 * logical host.  Must also have routing
 * table entry set up to forward packets
 * to appropriate gateway on localnet.
 */

struct	ifnet eclhif;
D 10
int	eclhoutput();
E 10
I 10
int	looutput();
E 10

/*
 * Called by localnet interface to allow logical
D 10
 * host interface to "attach".  Nothing should ever
 * be sent locally to this interface, it's purpose
E 10
I 10
 * host interface to "attach", it's purpose
E 10
 * is simply to establish the host's arpanet address.
 */
D 10
eclhinit(addr)
E 10
I 10
eclhinit(ecifp, addr)
	struct ifnet *ecifp;
E 10
	int addr;
{
	register struct ifnet *ifp = &eclhif;
	register struct sockaddr_in *sin;

COUNT(ECLHINIT);
	ifp->if_name = "lh";
	ifp->if_mtu = ECMTU;
	sin = (struct sockaddr_in *)&ifp->if_addr;
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = addr;
I 12
	sin->sin_addr.s_lh = ecifp->if_host[0];
E 12
	ifp->if_net = sin->sin_addr.s_net;
D 10
	ifp->if_flags = IFF_UP;
	ifp->if_output = eclhoutput;	/* should never be used */
E 10
I 10
D 12
	ifp->if_dstaddr = ecifp->if_addr;
E 12
I 12
	ifp->if_dstaddr = ifp->if_addr;
E 12
	ifp->if_flags = IFF_UP|IFF_POINTOPOINT;
	ifp->if_output = looutput;
E 10
	if_attach(ifp);
D 10
}

eclhoutput(ifp, m0, dst)
	struct ifnet *ifp;
	struct mbuf *m0;
	struct sockaddr *dst;
{
COUNT(ECLHOUTPUT);
	ifp->if_oerrors++;
	m_freem(m0);
	return (0);
E 10
I 10
D 11
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT);
E 11
I 11
D 15
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_DIRECT|RTF_HOST);
E 15
I 15
	rtinit(&ifp->if_addr, &ifp->if_addr, RTF_UP|RTF_HOST);
E 15
E 11
E 10
}
#endif
E 16
E 1
